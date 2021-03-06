/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"
using namespace El;

// Typedef our real and complex types to 'Real' and 'C' for convenience
typedef double Real;
typedef Complex<Real> C;

int
main( int argc, char* argv[] )
{
    Environment env( argc, argv );

    try 
    {
        const Int n = Input("--size","size of Hermitian matrix",100);
        const bool colPiv = Input("--colPiv","QR with col pivoting?",false);
        ProcessInput();
        PrintInputReport();

        DistMatrix<C> A, Q, P;
        HermitianUniformSpectrum( A, n, 1, 2 );
        const Real frobA = FrobeniusNorm( A );

        // Compute the polar decomp of A using a QR-based Dynamically Weighted
        // Halley (QDWH) iteration
        Q = A;
        PolarCtrl ctrl;
        ctrl.qdwh = true;
        ctrl.colPiv = colPiv;
        Timer timer;
        if( mpi::Rank() == 0 )
            timer.Start();
        HermitianPolar( LOWER, Q, ctrl );
        if( mpi::Rank() == 0 )
            timer.Stop();
        Zeros( P, n, n );
        Gemm( ADJOINT, NORMAL, C(1), Q, A, C(0), P );

        // Check and report overall and orthogonality error
        DistMatrix<C> B( A );
        Gemm( NORMAL, NORMAL, C(-1), Q, P, C(1), B );
        const Real frobQDWH = FrobeniusNorm( B );
        Identity( B, n, n );
        Herk( LOWER, NORMAL, Real(1), Q, Real(-1), B );
        const Real frobQDWHOrthog = HermitianFrobeniusNorm( LOWER, B );
        if( mpi::Rank() == 0 )
        {
            Output("HermitianQDWH time: ",timer.Total()," secs");
            Output
            (ctrl.numIts," iterations of QDWH\n",
             "||A - QP||_F / ||A||_F = ",frobQDWH/frobA,"\n",
             "||I - QQ^H||_F / ||A||_F = ",frobQDWHOrthog/frobA,"\n");
        }
    }
    catch( exception& e ) { ReportException(e); }

    return 0;
}

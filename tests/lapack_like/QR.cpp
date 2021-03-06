/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"
using namespace El;

template<typename F>
void TestCorrectness
( const DistMatrix<F>& A,
  const DistMatrix<F,MD,STAR>& t,
  const DistMatrix<Base<F>,MD,STAR>& d,
        DistMatrix<F>& AOrig )
{
    typedef Base<F> Real;
    const Grid& g = A.Grid();
    const Int m = A.Height();
    const Int n = A.Width();
    const Int minDim = std::min(m,n);

    if( g.Rank() == 0 )
        Output("  Testing orthogonality of Q");

    // Form Z := Q^H Q as an approximation to identity
    DistMatrix<F> Z(g);
    Identity( Z, m, n );
    qr::ApplyQ( LEFT, NORMAL, A, t, d, Z );
    qr::ApplyQ( LEFT, ADJOINT, A, t, d, Z );
    auto ZUpper = View( Z, 0, 0, minDim, minDim );

    // Form X := I - Q^H Q
    DistMatrix<F> X(g);
    Identity( X, minDim, minDim );
    X -= ZUpper;

    Real oneNormError = OneNorm( X );
    Real infNormError = InfinityNorm( X );
    Real frobNormError = FrobeniusNorm( X );
    if( g.Rank() == 0 )
    {
        Output("    ||Q^H Q - I||_1  = ",oneNormError);
        Output("    ||Q^H Q - I||_oo = ",infNormError);
        Output("    ||Q^H Q - I||_F  = ",frobNormError);
    }

    if( g.Rank() == 0 )
        Output("  Testing if A = QR");

    // Form Q R
    auto U( A );
    MakeTrapezoidal( UPPER, U );
    qr::ApplyQ( LEFT, NORMAL, A, t, d, U );

    // Form Q R - A
    U -= AOrig;
    
    const Real oneNormA = OneNorm( AOrig );
    const Real infNormA = InfinityNorm( AOrig );
    const Real frobNormA = FrobeniusNorm( AOrig );
    oneNormError = OneNorm( U );
    infNormError = InfinityNorm( U );
    frobNormError = FrobeniusNorm( U );
    if( g.Rank() == 0 )
    {
        Output("    ||A||_1       = ",oneNormA);
        Output("    ||A||_oo      = ",infNormA);
        Output("    ||A||_F       = ",frobNormA);
        Output("    ||A - QR||_1  = ",oneNormError);
        Output("    ||A - QR||_oo = ",infNormError);
        Output("    ||A - QR||_F  = ",frobNormError);
    }
}

template<typename F,typename=EnableIf<IsBlasScalar<F>>>
void TestQR
( const Grid& g,
  Int m,
  Int n,
  bool testCorrectness,
  bool print,
  bool scalapack )
{
    if( g.Rank() == 0 )
        Output("Testing with ",TypeName<F>());
    DistMatrix<F> A(g), AOrig(g);
    DistMatrix<F,MD,STAR> t(g);
    DistMatrix<Base<F>,MD,STAR> d(g);

    Uniform( A, m, n );
    if( testCorrectness )
        AOrig = A;
    if( print )
        Print( A, "A" );
    const double mD = double(m);
    const double nD = double(n);

    if( scalapack )
    {
        DistMatrix<F,MC,MR,BLOCK> ABlock( A );
        DistMatrix<F,MR,STAR,BLOCK> tBlock(g);
        mpi::Barrier( g.Comm() );
        const double startTime = mpi::Time();
        QR( ABlock, tBlock ); 
        const double runTime = mpi::Time() - startTime;
        const double realGFlops = (2.*mD*nD*nD - 2./3.*nD*nD*nD)/(1.e9*runTime);
        const double gFlops =
          ( IsComplex<F>::value ? 4*realGFlops : realGFlops );
        if( g.Rank() == 0 )
            Output("  ScaLAPACK: ",runTime," seconds. GFlops = ",gFlops);
    }

    if( g.Rank() == 0 )
        Output("  Starting QR factorization...");
    mpi::Barrier( g.Comm() );
    const double startTime = mpi::Time();
    QR( A, t, d );
    mpi::Barrier( g.Comm() );
    const double runTime = mpi::Time() - startTime;
    const double realGFlops = (2.*mD*nD*nD - 2./3.*nD*nD*nD)/(1.e9*runTime);
    const double gFlops = ( IsComplex<F>::value ? 4*realGFlops : realGFlops );
    if( g.Rank() == 0 )
        Output("  Elemental: ",runTime," seconds. GFlops = ",gFlops);
    if( print )
    {
        Print( A, "A after factorization" );
        Print( t, "phases" );
        Print( d, "diagonal" );
    }
    if( testCorrectness )
        TestCorrectness( A, t, d, AOrig );
}

template<typename F,typename=DisableIf<IsBlasScalar<F>>,typename=void>
void TestQR
( const Grid& g,
  Int m,
  Int n,
  bool testCorrectness,
  bool print )
{
    if( g.Rank() == 0 )
        Output("Testing with ",TypeName<F>());
    DistMatrix<F> A(g), AOrig(g);
    DistMatrix<F,MD,STAR> t(g);
    DistMatrix<Base<F>,MD,STAR> d(g);

    Uniform( A, m, n );
    if( testCorrectness )
        AOrig = A;
    if( print )
        Print( A, "A" );
    const double mD = double(m);
    const double nD = double(n);

    if( g.Rank() == 0 )
        Output("  Starting QR factorization...");
    mpi::Barrier( g.Comm() );
    const double startTime = mpi::Time();
    QR( A, t, d );
    mpi::Barrier( g.Comm() );
    const double runTime = mpi::Time() - startTime;
    const double realGFlops = (2.*mD*nD*nD - 2./3.*nD*nD*nD)/(1.e9*runTime);
    const double gFlops = ( IsComplex<F>::value ? 4*realGFlops : realGFlops );
    if( g.Rank() == 0 )
        Output("  Elemental: ",runTime," seconds. GFlops = ",gFlops);
    if( print )
    {
        Print( A, "A after factorization" );
        Print( t, "phases" );
        Print( d, "diagonal" );
    }
    if( testCorrectness )
        TestCorrectness( A, t, d, AOrig );
}

int 
main( int argc, char* argv[] )
{
    Environment env( argc, argv );
    mpi::Comm comm = mpi::COMM_WORLD;
    const int commSize = mpi::Size( comm );

    try
    {
        Int r = Input("--gridHeight","height of process grid",0);
        const bool colMajor = Input("--colMajor","column-major ordering?",true);
        const Int m = Input("--height","height of matrix",400);
        const Int n = Input("--width","width of matrix",400);
        const Int nb = Input("--nb","algorithmic blocksize",64);
        const bool testCorrectness = Input
            ("--correctness","test correctness?",true);
#ifdef EL_HAVE_SCALAPACK
        const bool scalapack = Input("--scalapack","test ScaLAPACK?",true);
#else
        const bool scalapack = false;
#endif
#ifdef EL_HAVE_MPC
        const mpfr_prec_t prec = Input("--prec","MPFR precision",256);
#endif
        const bool print = Input("--print","print matrices?",false);
        ProcessInput();
        PrintInputReport();

#ifdef EL_HAVE_MPC
        mpc::SetPrecision( prec );
#endif

        if( r == 0 )
            r = Grid::FindFactor( commSize );
        const GridOrder order = ( colMajor ? COLUMN_MAJOR : ROW_MAJOR );
        const Grid g( comm, r, order );
        SetBlocksize( nb );
        ComplainIfDebug();

        TestQR<float>( g, m, n, testCorrectness, print, scalapack );
        TestQR<Complex<float>>( g, m, n, testCorrectness, print, scalapack );

        TestQR<double>( g, m, n, testCorrectness, print, scalapack );
        TestQR<Complex<double>>( g, m, n, testCorrectness, print, scalapack );

#ifdef EL_HAVE_QD
        TestQR<DoubleDouble>( g, m, n, testCorrectness, print );
        TestQR<QuadDouble>( g, m, n, testCorrectness, print );
#endif

#ifdef EL_HAVE_QUAD
        TestQR<Quad>( g, m, n, testCorrectness, print );
        TestQR<Complex<Quad>>( g, m, n, testCorrectness, print );
#endif

#ifdef EL_HAVE_MPC
        TestQR<BigFloat>( g, m, n, testCorrectness, print );
#endif
    }
    catch( exception& e ) { ReportException(e); }

    return 0;
}

/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"
using namespace El;

template<typename T>
void TestTrmm
( LeftOrRight side,
  UpperOrLower uplo, 
  Orientation orientation,
  UnitOrNonUnit diag,
  Int m,
  Int n,
  T alpha,
  const Grid& g,
  bool print )
{
    if( g.Rank() == 0 )
        Output("Testing with ",TypeName<T>());
    DistMatrix<T> A(g), X(g);

    if( side == LEFT )
        Uniform( A, m, m );
    else
        Uniform( A, n, n );
    Uniform( X, m, n );
    auto XCopy( X );
    
    // Form an explicit triangular copy to apply with Gemm
    auto S( A );
    MakeTrapezoidal( uplo, S );

    if( print )
    {
        Print( A, "A" );
        Print( S, "S" );
        Print( X, "X" );
    }
    if( g.Rank() == 0 )
        Output("  Starting Trmm");
    mpi::Barrier( g.Comm() );
    const double startTime = mpi::Time();
    Trmm( side, uplo, orientation, diag, alpha, A, X );
    mpi::Barrier( g.Comm() );
    const double runTime = mpi::Time() - startTime;
    const double realGFlops = 
      ( side==LEFT ? double(m)*double(m)*double(n)
                   : double(m)*double(n)*double(n) ) /(1.e9*runTime);
    const double gFlops = ( IsComplex<T>::value ? 4*realGFlops : realGFlops );
    if( g.Rank() == 0 )
        Output("  Finished in ",runTime," seconds (",gFlops," GFlop/s)");
    if( print )
        Print( X, "X after multiply" );
    if( side == LEFT )
        Gemm( orientation, NORMAL, -alpha, S, XCopy, T(1), X );
    else
        Gemm( NORMAL, orientation, -alpha, XCopy, S, T(1), X );
    const auto XFrob = FrobeniusNorm( XCopy );
    const auto SFrob = FrobeniusNorm( S );
    const auto EFrob = FrobeniusNorm( X );
    if( print )
        Print( X, "error relative to Gemm" );
    if( g.Rank() == 0 )
    {
        Output("  || X ||_F = ",XFrob);
        Output("  || S ||_F = ",SFrob);
        Output("  || E ||_F = ",EFrob);
    }
}

int 
main( int argc, char* argv[] )
{
    Environment env( argc, argv );
    mpi::Comm comm = mpi::COMM_WORLD;
    const Int commRank = mpi::Rank( comm );
    const Int commSize = mpi::Size( comm );

    try
    {
        Int r = Input("--r","height of process grid",0);
        const bool colMajor = Input("--colMajor","column-major ordering?",true);
        const char sideChar = Input("--side","side to apply from: L/R",'L');
        const char uploChar = Input("--uplo","lower or upper storage: L/U",'L');
        const char transChar = Input
          ("--trans","orientation of matrix: N/T/C",'N');
        const char diagChar = Input("--diag","(non-)unit diagonal: N/U",'N');
        const Int m = Input("--m","height of result",100);
        const Int n = Input("--n","width of result",100);
        const Int nb = Input("--nb","algorithmic blocksize",96);
        const bool print = Input("--print","print matrices?",false);
        ProcessInput();
        PrintInputReport();

        if( r == 0 )
            r = Grid::FindFactor( commSize );
        const GridOrder order = ( colMajor ? COLUMN_MAJOR : ROW_MAJOR );
        const Grid g( comm, r, order );
        const LeftOrRight side = CharToLeftOrRight( sideChar );
        const UpperOrLower uplo = CharToUpperOrLower( uploChar );
        const Orientation orientation = CharToOrientation( transChar );
        const UnitOrNonUnit diag = CharToUnitOrNonUnit( diagChar );
        SetBlocksize( nb );

        ComplainIfDebug();
        if( commRank == 0 )
            Output("Will test Trmm ",sideChar,uploChar,transChar,diagChar);

        TestTrmm<float>
        ( side, uplo, orientation, diag,
          m, n,
          float(3),
          g, print );
        TestTrmm<Complex<float>>
        ( side, uplo, orientation, diag,
          m, n,
          Complex<float>(3),
          g, print );

        TestTrmm<double>
        ( side, uplo, orientation, diag,
          m, n,
          double(3),
          g, print );
        TestTrmm<Complex<double>>
        ( side, uplo, orientation, diag,
          m, n,
          Complex<double>(3),
          g, print );

#ifdef EL_HAVE_QD
        TestTrmm<DoubleDouble>
        ( side, uplo, orientation, diag,
          m, n,
          DoubleDouble(3),
          g, print );
        TestTrmm<QuadDouble>
        ( side, uplo, orientation, diag,
          m, n,
          QuadDouble(3),
          g, print );
#endif

#ifdef EL_HAVE_QUAD
        TestTrmm<Quad>
        ( side, uplo, orientation, diag,
          m, n,
          Quad(3),
          g, print );
        TestTrmm<Complex<Quad>>
        ( side, uplo, orientation, diag,
          m, n,
          Complex<Quad>(3),
          g, print );
#endif

#ifdef EL_HAVE_MPC
        TestTrmm<BigFloat>
        ( side, uplo, orientation, diag,
          m, n,
          BigFloat(3),
          g, print );
#endif
    }
    catch( exception& e ) { ReportException(e); }

    return 0;
}

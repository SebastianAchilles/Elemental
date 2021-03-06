/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_TRR2K_TNNN_HPP
#define EL_TRR2K_TNNN_HPP

#include "./NNTN.hpp"

namespace El {
namespace trr2k {

// E := alpha A' B + beta C D + E
template<typename T>
void Trr2kTNNN
( UpperOrLower uplo, Orientation orientA,
  T alpha, const ElementalMatrix<T>& A, const ElementalMatrix<T>& B,
  T beta,  const ElementalMatrix<T>& C, const ElementalMatrix<T>& D,
                 ElementalMatrix<T>& E )
{
    DEBUG_ONLY(CSE cse("trr2k::Trr2kTNNN"))
    Trr2kNNTN( uplo, orientA, beta, C, D, alpha, A, B, E );
}

} // namespace trr2k
} // namespace El

#endif // ifndef EL_TRR2K_TNNN_HPP

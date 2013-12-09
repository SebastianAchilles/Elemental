/*
   Copyright (c) 2009-2013, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#pragma once
#ifndef ELEM_BLAS_COPY_HPP
#define ELEM_BLAS_COPY_HPP

namespace elem {

template<typename T>
inline void
Copy( const Matrix<T>& A, Matrix<T>& B )
{
    DEBUG_ONLY(CallStackEntry cse("Copy"))
    B = A;
}

template<typename T,Distribution U,Distribution V,
                    Distribution W,Distribution Z>
inline void
Copy( const DistMatrix<T,U,V>& A, DistMatrix<T,W,Z>& B )
{
    DEBUG_ONLY(CallStackEntry cse("Copy"))
    B = A;
}

} // namespace elem

#endif // ifndef ELEM_BLAS_COPY_HPP

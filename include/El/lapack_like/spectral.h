/*
   Copyright (c) 2009-2016, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#ifndef EL_LAPACK_SPECTRAL_C_H
#define EL_LAPACK_SPECTRAL_C_H

#include "El/lapack_like/funcs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Hermitian tridiagonal eigensolvers
   ================================== */
/* HermitianEigSubset */
typedef struct {
  bool indexSubset;
  ElInt lowerIndex, upperIndex;

  bool rangeSubset;
  float lowerBound, upperBound;
} ElHermitianEigSubset_s;
EL_EXPORT ElError ElHermitianEigSubsetDefault_s( ElHermitianEigSubset_s* subset );

typedef struct {
  bool indexSubset;
  ElInt lowerIndex, upperIndex;

  bool rangeSubset;
  double lowerBound, upperBound;
} ElHermitianEigSubset_d;
EL_EXPORT ElError ElHermitianEigSubsetDefault_d( ElHermitianEigSubset_d* subset );

/* Compute all eigenvalues
   ----------------------- */
EL_EXPORT ElError ElHermitianTridiagEig_s
( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEig_d
( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEig_c
( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEig_z
( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElSortType sort );

EL_EXPORT ElError ElHermitianTridiagEigDist_s
( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, 
  ElDistMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigDist_d
( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, 
  ElDistMatrix_d w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigDist_c
( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, 
  ElDistMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigDist_z
( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, 
  ElDistMatrix_d w, ElSortType sort );

/* TODO: Expert version */

/* Compute all eigenpairs
   ---------------------- */
EL_EXPORT ElError ElHermitianTridiagEigPair_s
( ElMatrix_s d, ElMatrix_s dSub, ElMatrix_s w, ElMatrix_s Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPair_d
( ElMatrix_d d, ElMatrix_d dSub, ElMatrix_d w, ElMatrix_d Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPair_c
( ElMatrix_s d, ElMatrix_c dSub, ElMatrix_s w, ElMatrix_c Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPair_z
( ElMatrix_d d, ElMatrix_z dSub, ElMatrix_d w, ElMatrix_z Z, ElSortType sort );

EL_EXPORT ElError ElHermitianTridiagEigPairDist_s
( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, 
  ElDistMatrix_s w, ElDistMatrix_s Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPairDist_d
( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, 
  ElDistMatrix_d w, ElDistMatrix_d Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPairDist_c
( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, 
  ElDistMatrix_s w, ElDistMatrix_c Z, ElSortType sort );
EL_EXPORT ElError ElHermitianTridiagEigPairDist_z
( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, 
  ElDistMatrix_d w, ElDistMatrix_z Z, ElSortType sort );

/* TODO: Expert version */

/* Compute a subset of eigenvalues
   ------------------------------- */
EL_EXPORT ElError ElHermitianTridiagEigPartial_s
( ElMatrix_s d, ElMatrix_s dSub, 
  ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPartial_d
( ElMatrix_d d, ElMatrix_d dSub, 
  ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianTridiagEigPartial_c
( ElMatrix_s d, ElMatrix_c dSub, 
  ElMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPartial_z
( ElMatrix_d d, ElMatrix_z dSub, 
  ElMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianTridiagEigPartialDist_s
( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, 
  ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPartialDist_d
( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, 
  ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianTridiagEigPartialDist_c
( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, 
  ElDistMatrix_s w, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPartialDist_z
( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, 
  ElDistMatrix_d w, ElSortType sort, ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Compute a subset of eigenpairs
   ------------------------------ */
EL_EXPORT ElError ElHermitianTridiagEigPairPartial_s
( ElMatrix_s d, ElMatrix_s dSub, 
  ElMatrix_s w,  ElMatrix_s Z, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartial_d
( ElMatrix_d d, ElMatrix_d dSub, 
  ElMatrix_d w, ElMatrix_d Z, ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartial_c
( ElMatrix_s d, ElMatrix_c dSub, 
  ElMatrix_s w, ElMatrix_c Z, ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartial_z
( ElMatrix_d d, ElMatrix_z dSub, 
  ElMatrix_d w, ElMatrix_z Z, ElSortType sort, ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianTridiagEigPairPartialDist_s
( ElConstDistMatrix_s d, ElConstDistMatrix_s dSub, 
  ElDistMatrix_s w, ElDistMatrix_s Z, 
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartialDist_d
( ElConstDistMatrix_d d, ElConstDistMatrix_d dSub, 
  ElDistMatrix_d w, ElDistMatrix_d Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartialDist_c
( ElConstDistMatrix_s d, ElConstDistMatrix_c dSub, 
  ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianTridiagEigPairPartialDist_z
( ElConstDistMatrix_d d, ElConstDistMatrix_z dSub, 
  ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Hermitian eigensolvers
   ====================== */
/* HermitianSDCCtrl */
typedef struct {
  ElInt cutoff;
  ElInt maxInnerIts, maxOuterIts;
  float tol;
  float spreadFactor;
  bool progress;
} ElHermitianSDCCtrl_s;
EL_EXPORT ElError ElHermitianSDCCtrlDefault_s( ElHermitianSDCCtrl_s* ctrl );

typedef struct {
  ElInt cutoff;
  ElInt maxInnerIts, maxOuterIts;
  double tol;
  double spreadFactor;
  bool progress;
} ElHermitianSDCCtrl_d;
EL_EXPORT ElError ElHermitianSDCCtrlDefault_d( ElHermitianSDCCtrl_d* ctrl );

/* HermitianEigCtrl */
typedef struct {
  ElHermitianTridiagCtrl tridiagCtrl;
  ElHermitianSDCCtrl_s sdcCtrl;
  bool useSDC;
} ElHermitianEigCtrl_s;
EL_EXPORT ElError ElHermitianEigCtrlDefault_s( ElHermitianEigCtrl_s* ctrl );

typedef struct {
  ElHermitianTridiagCtrl tridiagCtrl;
  ElHermitianSDCCtrl_d sdcCtrl;
  bool useSDC;
} ElHermitianEigCtrl_d;
EL_EXPORT ElError ElHermitianEigCtrlDefault_d( ElHermitianEigCtrl_d* ctrl );

typedef struct {
  ElHermitianTridiagCtrl tridiagCtrl;
  ElHermitianSDCCtrl_s sdcCtrl;
  bool useSDC;
} ElHermitianEigCtrl_c;
EL_EXPORT ElError ElHermitianEigCtrlDefault_c( ElHermitianEigCtrl_c* ctrl );

typedef struct {
  ElHermitianTridiagCtrl tridiagCtrl;
  ElHermitianSDCCtrl_d sdcCtrl;
  bool useSDC;
} ElHermitianEigCtrl_z;
EL_EXPORT ElError ElHermitianEigCtrlDefault_z( ElHermitianEigCtrl_z* ctrl );

/* Compute all eigenvalues
   ----------------------- */
EL_EXPORT ElError ElHermitianEig_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianEig_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort );
EL_EXPORT ElError ElHermitianEig_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianEig_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort );

EL_EXPORT ElError ElHermitianEigDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, 
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w,
  ElSortType sort );

/* TODO: Expert version */

/* Compute the entire eigenvalue decomposition 
   ------------------------------------------- */
EL_EXPORT ElError ElHermitianEigPair_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_s Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPair_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_d Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPair_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPair_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort );

EL_EXPORT ElError ElHermitianEigPairDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_s Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPairDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_d Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPairDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianEigPairDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort );

/* TODO: Expert version */

/* Compute a partial set of eigenvalues
   ------------------------------------ */
EL_EXPORT ElError ElHermitianEigPartial_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPartial_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianEigPartial_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPartial_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianEigPartialDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPartialDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianEigPartialDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPartialDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Compute a partial set of eigenpairs
   ----------------------------------- */
EL_EXPORT ElError ElHermitianEigPairPartial_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_s Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPairPartial_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_d Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianEigPairPartial_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPairPartial_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianEigPairPartialDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_s Z, 
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPairPartialDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_d Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianEigPairPartialDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianEigPairPartialDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Skew-Hermitian eigensolvers
   =========================== */

/* Compute all eigenvalues
   ----------------------- */
EL_EXPORT ElError ElSkewHermitianEig_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEig_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEig_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEig_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort );

EL_EXPORT ElError ElSkewHermitianEigDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, 
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w,
  ElSortType sort );

/* TODO: Expert version */

/* Compute the entire eigenvalue decomposition 
   ------------------------------------------- */
EL_EXPORT ElError ElSkewHermitianEigPair_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPair_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPair_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPair_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort );

EL_EXPORT ElError ElSkewHermitianEigPairDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPairDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPairDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElSkewHermitianEigPairDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort );

/* TODO: Expert version */

/* Compute a partial set of eigenvalues
   ------------------------------------ */
EL_EXPORT ElError ElSkewHermitianEigPartial_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPartial_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElSkewHermitianEigPartial_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPartial_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElSkewHermitianEigPartialDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPartialDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElSkewHermitianEigPartialDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPartialDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Compute a partial set of eigenpairs
   ----------------------------------- */
EL_EXPORT ElError ElSkewHermitianEigPairPartial_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartial_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartial_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartial_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElSkewHermitianEigPairPartialDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s w, ElDistMatrix_c Z, 
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartialDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartialDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElSkewHermitianEigPairPartialDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Hermitian generalized-definite eigensolvers
   =========================================== */
/* Pencil */
typedef enum {
  EL_AXBX=1,
  EL_ABX=2, 
  EL_BAX=3
} ElPencil;

/* Compute all of the eigenvalues
   ------------------------------ */
EL_EXPORT ElError ElHermitianGenDefEig_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEig_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEig_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEig_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElSortType sort );

EL_EXPORT ElError ElHermitianGenDefEigDist_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, 
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigDist_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigDist_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigDist_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w,
  ElSortType sort );

/* TODO: Expert version */

/* Compute the entire eigenvalue decomposition 
   ------------------------------------------- */
EL_EXPORT ElError ElHermitianGenDefEigPair_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElMatrix_s Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPair_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElMatrix_d Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPair_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPair_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElMatrix_z Z,
  ElSortType sort );

EL_EXPORT ElError ElHermitianGenDefEigPairDist_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElDistMatrix_s Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPairDist_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElDistMatrix_d Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPairDist_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort );
EL_EXPORT ElError ElHermitianGenDefEigPairDist_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort );

/* TODO: Expert version */

/* Compute a partial set of eigenvalues
   ------------------------------------ */
EL_EXPORT ElError ElHermitianGenDefEigPartial_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPartial_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianGenDefEigPartial_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPartial_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianGenDefEigPartialDist_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPartialDist_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianGenDefEigPartialDist_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPartialDist_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElSortType sort,
  ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Compute a partial set of eigenpairs
   ----------------------------------- */
EL_EXPORT ElError ElHermitianGenDefEigPairPartial_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_s A, ElMatrix_s B, ElMatrix_s w, ElMatrix_s Z, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartial_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_d A, ElMatrix_d B, ElMatrix_d w, ElMatrix_d Z, ElSortType sort,
  ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartial_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_c A, ElMatrix_c B, ElMatrix_s w, ElMatrix_c Z, ElSortType sort,
  ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartial_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElMatrix_z A, ElMatrix_z B, ElMatrix_d w, ElMatrix_z Z, ElSortType sort,
  ElHermitianEigSubset_d subset );

EL_EXPORT ElError ElHermitianGenDefEigPairPartialDist_s
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s w, ElDistMatrix_s Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartialDist_d
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d w, ElDistMatrix_d Z,
  ElSortType sort, ElHermitianEigSubset_d subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartialDist_c
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_s w, ElDistMatrix_c Z,
  ElSortType sort, ElHermitianEigSubset_s subset );
EL_EXPORT ElError ElHermitianGenDefEigPairPartialDist_z
( ElPencil pencil, ElUpperOrLower uplo, 
  ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_d w, ElDistMatrix_z Z,
  ElSortType sort, ElHermitianEigSubset_d subset );

/* TODO: Expert version */

/* Hermitian SVD
   ============= */

/* Compute the singular values
   --------------------------- */
EL_EXPORT ElError ElHermitianSingularValues_s
( ElUpperOrLower uplo, ElConstMatrix_s A, ElMatrix_s s );
EL_EXPORT ElError ElHermitianSingularValues_d
( ElUpperOrLower uplo, ElConstMatrix_d A, ElMatrix_d s );
EL_EXPORT ElError ElHermitianSingularValues_c
( ElUpperOrLower uplo, ElConstMatrix_c A, ElMatrix_s s );
EL_EXPORT ElError ElHermitianSingularValues_z
( ElUpperOrLower uplo, ElConstMatrix_z A, ElMatrix_d s );
EL_EXPORT ElError ElHermitianSingularValuesDist_s
( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElDistMatrix_s s );
EL_EXPORT ElError ElHermitianSingularValuesDist_d
( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElDistMatrix_d s );
EL_EXPORT ElError ElHermitianSingularValuesDist_c
( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElDistMatrix_s s );
EL_EXPORT ElError ElHermitianSingularValuesDist_z
( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElDistMatrix_d s );

/* TODO: Expert versions */

/* Compute the full SVD
   -------------------- */
EL_EXPORT ElError ElHermitianSVD_s
( ElUpperOrLower uplo,
  ElConstMatrix_s A,
  ElMatrix_s U,
  ElMatrix_s s,
  ElMatrix_s V );
EL_EXPORT ElError ElHermitianSVD_d
( ElUpperOrLower uplo,
  ElConstMatrix_d A,
  ElMatrix_d U,
  ElMatrix_d s,
  ElMatrix_d V );
EL_EXPORT ElError ElHermitianSVD_c
( ElUpperOrLower uplo,
  ElConstMatrix_c A,
  ElMatrix_c U,
  ElMatrix_s s,
  ElMatrix_c V );
EL_EXPORT ElError ElHermitianSVD_z
( ElUpperOrLower uplo,
  ElConstMatrix_z A,
  ElMatrix_z U,
  ElMatrix_d s,
  ElMatrix_z V );
EL_EXPORT ElError ElHermitianSVDDist_s
( ElUpperOrLower uplo,
  ElConstDistMatrix_s A,
  ElDistMatrix_s U,
  ElDistMatrix_s s, 
  ElDistMatrix_s V );
EL_EXPORT ElError ElHermitianSVDDist_d
( ElUpperOrLower uplo,
  ElConstDistMatrix_d A,
  ElDistMatrix_d U,
  ElDistMatrix_d s, 
  ElDistMatrix_d V );
EL_EXPORT ElError ElHermitianSVDDist_c
( ElUpperOrLower uplo,
  ElConstDistMatrix_c A,
  ElDistMatrix_c U,
  ElDistMatrix_s s, 
  ElDistMatrix_c V );
EL_EXPORT ElError ElHermitianSVDDist_z
( ElUpperOrLower uplo,
  ElConstDistMatrix_z A,
  ElDistMatrix_z U,
  ElDistMatrix_d s, 
  ElDistMatrix_z V );

/* TODO: Expert versions */

/* Polar decomposition
   =================== */
/* PolarCtrl */
typedef struct {
  bool qdwh;
  bool colPiv;
  ElInt maxIts;
  ElInt numIts;
} ElPolarCtrl;
EL_EXPORT ElError ElPolarCtrlDefault( ElPolarCtrl* ctrl );

/* Compute just the polar factor
   ----------------------------- */
EL_EXPORT ElError ElPolar_s( ElMatrix_s A );
EL_EXPORT ElError ElPolar_d( ElMatrix_d A );
EL_EXPORT ElError ElPolar_c( ElMatrix_c A );
EL_EXPORT ElError ElPolar_z( ElMatrix_z A );

EL_EXPORT ElError ElPolarDist_s( ElDistMatrix_s A );
EL_EXPORT ElError ElPolarDist_d( ElDistMatrix_d A );
EL_EXPORT ElError ElPolarDist_c( ElDistMatrix_c A );
EL_EXPORT ElError ElPolarDist_z( ElDistMatrix_z A );

EL_EXPORT ElError ElHermitianPolar_s( ElUpperOrLower uplo, ElMatrix_s A );
EL_EXPORT ElError ElHermitianPolar_d( ElUpperOrLower uplo, ElMatrix_d A );
EL_EXPORT ElError ElHermitianPolar_c( ElUpperOrLower uplo, ElMatrix_c A );
EL_EXPORT ElError ElHermitianPolar_z( ElUpperOrLower uplo, ElMatrix_z A );

EL_EXPORT ElError ElHermitianPolarDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A );
EL_EXPORT ElError ElHermitianPolarDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A );
EL_EXPORT ElError ElHermitianPolarDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A );
EL_EXPORT ElError ElHermitianPolarDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A );

/* Compute the entire polar decomposition
   -------------------------------------- */
EL_EXPORT ElError ElPolarDecomp_s( ElMatrix_s A, ElMatrix_s P );
EL_EXPORT ElError ElPolarDecomp_d( ElMatrix_d A, ElMatrix_d P );
EL_EXPORT ElError ElPolarDecomp_c( ElMatrix_c A, ElMatrix_c P );
EL_EXPORT ElError ElPolarDecomp_z( ElMatrix_z A, ElMatrix_z P );

EL_EXPORT ElError ElPolarDecompDist_s( ElDistMatrix_s A, ElDistMatrix_s P );
EL_EXPORT ElError ElPolarDecompDist_d( ElDistMatrix_d A, ElDistMatrix_d P );
EL_EXPORT ElError ElPolarDecompDist_c( ElDistMatrix_c A, ElDistMatrix_c P );
EL_EXPORT ElError ElPolarDecompDist_z( ElDistMatrix_z A, ElDistMatrix_z P );

EL_EXPORT ElError ElHermitianPolarDecomp_s
( ElUpperOrLower uplo, ElMatrix_s A, ElMatrix_s P );
EL_EXPORT ElError ElHermitianPolarDecomp_d
( ElUpperOrLower uplo, ElMatrix_d A, ElMatrix_d P );
EL_EXPORT ElError ElHermitianPolarDecomp_c
( ElUpperOrLower uplo, ElMatrix_c A, ElMatrix_c P );
EL_EXPORT ElError ElHermitianPolarDecomp_z
( ElUpperOrLower uplo, ElMatrix_z A, ElMatrix_z P );

EL_EXPORT ElError ElHermitianPolarDecompDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElDistMatrix_s P );
EL_EXPORT ElError ElHermitianPolarDecompDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElDistMatrix_d P );
EL_EXPORT ElError ElHermitianPolarDecompDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElDistMatrix_c P );
EL_EXPORT ElError ElHermitianPolarDecompDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElDistMatrix_z P );

/* TODO: Expert versions */

/* Schur decomposition
   =================== */
/* HessQRCtrl */
typedef struct {
  bool distAED;
  ElInt blockHeight, blockWidth;
} ElHessQRCtrl;
EL_EXPORT ElError ElHessQRCtrlDefault( ElHessQRCtrl* ctrl );

/* SDCCtrl */
typedef struct {
  ElInt cutoff;
  ElInt maxInnerIts, maxOuterIts;
  float tol;
  float spreadFactor;
  bool random;
  bool progress;
  ElSignCtrl_s signCtrl;
} ElSDCCtrl_s;
EL_EXPORT ElError ElSDCCtrlDefault_s( ElSDCCtrl_s* ctrl );

typedef struct {
  ElInt cutoff;
  ElInt maxInnerIts, maxOuterIts;
  double tol;
  double spreadFactor;
  bool random;
  bool progress;
  ElSignCtrl_d signCtrl;
} ElSDCCtrl_d;
EL_EXPORT ElError ElSDCCtrlDefault_d( ElSDCCtrl_d* ctrl );

/* SchurCtrl */
typedef struct {
  bool useSDC;
  ElHessQRCtrl qrCtrl;
  ElSDCCtrl_s sdcCtrl;
} ElSchurCtrl_s;
EL_EXPORT ElError ElSchurCtrlDefault_s( ElSchurCtrl_s* ctrl );

typedef struct {
  bool useSDC;
  ElHessQRCtrl qrCtrl;
  ElSDCCtrl_d sdcCtrl;
} ElSchurCtrl_d;
EL_EXPORT ElError ElSchurCtrlDefault_d( ElSchurCtrl_d* ctrl );

/* Compute just the eigenvalues (and perhaps the Schur factor)
   ----------------------------------------------------------- */
EL_EXPORT ElError ElSchur_s( ElMatrix_s A, ElMatrix_c w, bool fullTriangle );
EL_EXPORT ElError ElSchur_d( ElMatrix_d A, ElMatrix_z w, bool fullTriangle );
EL_EXPORT ElError ElSchur_c( ElMatrix_c A, ElMatrix_c w, bool fullTriangle );
EL_EXPORT ElError ElSchur_z( ElMatrix_z A, ElMatrix_z w, bool fullTriangle );

EL_EXPORT ElError ElSchurDist_s
( ElDistMatrix_s A, ElDistMatrix_c w, bool fullTriangle );
EL_EXPORT ElError ElSchurDist_d
( ElDistMatrix_d A, ElDistMatrix_z w, bool fullTriangle );
EL_EXPORT ElError ElSchurDist_c
( ElDistMatrix_c A, ElDistMatrix_c w, bool fullTriangle );
EL_EXPORT ElError ElSchurDist_z
( ElDistMatrix_z A, ElDistMatrix_z w, bool fullTriangle );

/* Compute the eigvalues and Schur vectors (and possibly Schur factor)
   ------------------------------------------------------------------- */
EL_EXPORT ElError ElSchurDecomp_s
( ElMatrix_s A, ElMatrix_c w, ElMatrix_s Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecomp_d
( ElMatrix_d A, ElMatrix_z w, ElMatrix_d Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecomp_c
( ElMatrix_c A, ElMatrix_c w, ElMatrix_c Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecomp_z
( ElMatrix_z A, ElMatrix_z w, ElMatrix_z Q, bool fullTriangle );

EL_EXPORT ElError ElSchurDecompDist_s
( ElDistMatrix_s A, ElDistMatrix_c w, ElDistMatrix_s Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecompDist_d
( ElDistMatrix_d A, ElDistMatrix_z w, ElDistMatrix_d Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecompDist_c
( ElDistMatrix_c A, ElDistMatrix_c w, ElDistMatrix_c Q, bool fullTriangle );
EL_EXPORT ElError ElSchurDecompDist_z
( ElDistMatrix_z A, ElDistMatrix_z w, ElDistMatrix_z Q, bool fullTriangle );

/* TODO: Expert versions */
/* TODO: CheckRealSchur, and RealToComplex */

/* Triangular eigenvectors
   ======================= */
EL_EXPORT ElError ElTriangEig_s( ElMatrix_s U, ElMatrix_s X );
EL_EXPORT ElError ElTriangEig_d( ElMatrix_d U, ElMatrix_d X );
EL_EXPORT ElError ElTriangEig_c( ElMatrix_c U, ElMatrix_c X );
EL_EXPORT ElError ElTriangEig_z( ElMatrix_z U, ElMatrix_z X );

EL_EXPORT ElError ElTriangEigDist_s( ElConstDistMatrix_s U, ElDistMatrix_s X );
EL_EXPORT ElError ElTriangEigDist_d( ElConstDistMatrix_d U, ElDistMatrix_d X );
EL_EXPORT ElError ElTriangEigDist_c( ElConstDistMatrix_c U, ElDistMatrix_c X );
EL_EXPORT ElError ElTriangEigDist_z( ElConstDistMatrix_z U, ElDistMatrix_z X );

/* Eigenvalue decomposition
   ======================== */
EL_EXPORT ElError ElEig_s( ElMatrix_s A, ElMatrix_c w, ElMatrix_c X );
EL_EXPORT ElError ElEig_d( ElMatrix_d A, ElMatrix_z w, ElMatrix_z X );
EL_EXPORT ElError ElEig_c( ElMatrix_c A, ElMatrix_c w, ElMatrix_c X );
EL_EXPORT ElError ElEig_z( ElMatrix_z A, ElMatrix_z w, ElMatrix_z X );

EL_EXPORT ElError ElEigDist_s
( ElDistMatrix_s A, ElDistMatrix_c w, ElDistMatrix_c X );
EL_EXPORT ElError ElEigDist_d
( ElDistMatrix_d A, ElDistMatrix_z w, ElDistMatrix_z X );
EL_EXPORT ElError ElEigDist_c
( ElDistMatrix_c A, ElDistMatrix_c w, ElDistMatrix_c X );
EL_EXPORT ElError ElEigDist_z
( ElDistMatrix_z A, ElDistMatrix_z w, ElDistMatrix_z X );

/* Singular Value Decomposition (SVD)
   ================================== */
typedef enum {
  EL_THIN_SVD,
  EL_COMPACT_SVD,
  EL_FULL_SVD,
  EL_PRODUCT_SVD
} ElSVDApproach;

/* SVDCtrl */
typedef struct {
  ElSVDApproach approach;
  bool overwrite;
  bool avoidComputingU;
  bool avoidComputingV;
  bool time;
  bool avoidLibflame;

  bool seqQR;
  double valChanRatio;
  double fullChanRatio;
  bool relative;
  float tol;
} ElSVDCtrl_s;
EL_EXPORT ElError ElSVDCtrlDefault_s( ElSVDCtrl_s* ctrl );

typedef struct {
  ElSVDApproach approach;
  bool overwrite;
  bool avoidComputingU;
  bool avoidComputingV;
  bool time;
  bool avoidLibflame;

  bool seqQR;
  double valChanRatio;
  double fullChanRatio;
  bool relative;
  double tol;
} ElSVDCtrl_d;
EL_EXPORT ElError ElSVDCtrlDefault_d( ElSVDCtrl_d* ctrl );

/* Compute the singular values
   --------------------------- */
EL_EXPORT ElError ElSingularValues_s( ElConstMatrix_s A, ElMatrix_s s );
EL_EXPORT ElError ElSingularValues_d( ElConstMatrix_d A, ElMatrix_d s );
EL_EXPORT ElError ElSingularValues_c( ElConstMatrix_c A, ElMatrix_s s );
EL_EXPORT ElError ElSingularValues_z( ElConstMatrix_z A, ElMatrix_d s );

EL_EXPORT ElError ElSingularValuesDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s s );
EL_EXPORT ElError ElSingularValuesDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d s );
EL_EXPORT ElError ElSingularValuesDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s s );
EL_EXPORT ElError ElSingularValuesDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d s );

/* Expert versions
   ^^^^^^^^^^^^^^^ */
EL_EXPORT ElError ElSingularValuesXDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s s, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSingularValuesXDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d s, ElSVDCtrl_d ctrl );
EL_EXPORT ElError ElSingularValuesXDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s s, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSingularValuesXDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d s, ElSVDCtrl_d ctrl );

EL_EXPORT ElError ElTSQRSingularValues_s
( ElConstDistMatrix_s A, ElDistMatrix_s s );
EL_EXPORT ElError ElTSQRSingularValues_d
( ElConstDistMatrix_d A, ElDistMatrix_d s );
EL_EXPORT ElError ElTSQRSingularValues_c
( ElConstDistMatrix_c A, ElDistMatrix_s s );
EL_EXPORT ElError ElTSQRSingularValues_z
( ElConstDistMatrix_z A, ElDistMatrix_d s );

/* Compute the full SVD
   -------------------- */
EL_EXPORT ElError ElSVD_s
( ElConstMatrix_s A, ElMatrix_s U, ElMatrix_s s, ElMatrix_s V );
EL_EXPORT ElError ElSVD_d
( ElConstMatrix_d A, ElMatrix_d U, ElMatrix_d s, ElMatrix_d V );
EL_EXPORT ElError ElSVD_c
( ElConstMatrix_c A, ElMatrix_c U, ElMatrix_s s, ElMatrix_c V );
EL_EXPORT ElError ElSVD_z
( ElConstMatrix_z A, ElMatrix_z U, ElMatrix_d s, ElMatrix_z V );

EL_EXPORT ElError ElSVDDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s U, ElDistMatrix_s s, ElDistMatrix_s V );
EL_EXPORT ElError ElSVDDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d U, ElDistMatrix_d s, ElDistMatrix_d V );
EL_EXPORT ElError ElSVDDist_c
( ElConstDistMatrix_c A, ElDistMatrix_c U, ElDistMatrix_s s, ElDistMatrix_c V );
EL_EXPORT ElError ElSVDDist_z
( ElConstDistMatrix_z A, ElDistMatrix_z U, ElDistMatrix_d s, ElDistMatrix_z V );

/* Expert versions
   ^^^^^^^^^^^^^^^ */
EL_EXPORT ElError ElSVDX_s
( ElConstMatrix_s A,
  ElMatrix_s U, ElMatrix_s s, ElMatrix_s V, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSVDX_d
( ElConstMatrix_d A,
  ElMatrix_d U, ElMatrix_d s, ElMatrix_d V, ElSVDCtrl_d ctrl );
EL_EXPORT ElError ElSVDX_c
( ElConstMatrix_c A,
  ElMatrix_c U, ElMatrix_s s, ElMatrix_c V, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSVDX_z
( ElConstMatrix_z A,
  ElMatrix_z U, ElMatrix_d s, ElMatrix_z V, ElSVDCtrl_d ctrl );

EL_EXPORT ElError ElSVDXDist_s
( ElConstDistMatrix_s A,
  ElDistMatrix_s U, ElDistMatrix_s s, ElDistMatrix_s V, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSVDXDist_d
( ElConstDistMatrix_d A,
  ElDistMatrix_d U, ElDistMatrix_d s, ElDistMatrix_d V, ElSVDCtrl_d ctrl );
EL_EXPORT ElError ElSVDXDist_c
( ElConstDistMatrix_c A,
  ElDistMatrix_c U, ElDistMatrix_s s, ElDistMatrix_c V, ElSVDCtrl_s ctrl );
EL_EXPORT ElError ElSVDXDist_z
( ElConstDistMatrix_z A,
  ElDistMatrix_z U, ElDistMatrix_d s, ElDistMatrix_z V, ElSVDCtrl_d ctrl );

EL_EXPORT ElError ElTSQRSVD_s
( ElConstDistMatrix_s A,
  ElDistMatrix_s U, ElDistMatrix_s s, ElDistMatrix_s V );
EL_EXPORT ElError ElTSQRSVD_d
( ElConstDistMatrix_d A,
  ElDistMatrix_d U, ElDistMatrix_d s, ElDistMatrix_d V );
EL_EXPORT ElError ElTSQRSVD_c
( ElConstDistMatrix_c A,
  ElDistMatrix_c U, ElDistMatrix_s s, ElDistMatrix_c V );
EL_EXPORT ElError ElTSQRSVD_z
( ElConstDistMatrix_z A,
  ElDistMatrix_z U, ElDistMatrix_d s, ElDistMatrix_z V );

/* Product Lanczos
   =============== */
EL_EXPORT ElError ElProductLanczosSparse_s
( ElConstSparseMatrix_s A, ElMatrix_s T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosSparse_d
( ElConstSparseMatrix_d A, ElMatrix_d T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosSparse_c
( ElConstSparseMatrix_c A, ElMatrix_s T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosSparse_z
( ElConstSparseMatrix_z A, ElMatrix_d T, ElInt basisSize );

EL_EXPORT ElError ElProductLanczosDistSparse_s
( ElConstDistSparseMatrix_s A, ElDistMatrix_s T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDistSparse_d
( ElConstDistSparseMatrix_d A, ElDistMatrix_d T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDistSparse_c
( ElConstDistSparseMatrix_c A, ElDistMatrix_s T, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDistSparse_z
( ElConstDistSparseMatrix_z A, ElDistMatrix_d T, ElInt basisSize );

EL_EXPORT ElError ElProductLanczosDecompSparse_s
( ElConstSparseMatrix_s A, ElMatrix_s V,
  ElMatrix_s T,            ElMatrix_s v, 
  float* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompSparse_d
( ElConstSparseMatrix_d A, ElMatrix_d V,
  ElMatrix_d T,            ElMatrix_d v, 
  double* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompSparse_c
( ElConstSparseMatrix_c A, ElMatrix_c V,
  ElMatrix_s T,            ElMatrix_c v, 
  float* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompSparse_z
( ElConstSparseMatrix_z A, ElMatrix_z V,
  ElMatrix_d T,            ElMatrix_z v, 
  double* beta, ElInt basisSize );

EL_EXPORT ElError ElProductLanczosDecompDistSparse_s
( ElConstDistSparseMatrix_s A, ElDistMultiVec_s V,
  ElDistMatrix_s T,            ElDistMultiVec_s v, 
  float* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompDistSparse_d
( ElConstDistSparseMatrix_d A, ElDistMultiVec_d V,
  ElDistMatrix_d T,            ElDistMultiVec_d v, 
  double* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompDistSparse_c
( ElConstDistSparseMatrix_c A, ElDistMultiVec_c V,
  ElDistMatrix_s T,            ElDistMultiVec_c v, 
  float* beta, ElInt basisSize );
EL_EXPORT ElError ElProductLanczosDecompDistSparse_z
( ElConstDistSparseMatrix_z A, ElDistMultiVec_z V,
  ElDistMatrix_d T,            ElDistMultiVec_z v, 
  double* beta, ElInt basisSize );

/* Extremal singular value estimation
   ================================== */
EL_EXPORT ElError ElExtremalSingValEstSparse_s
( ElConstSparseMatrix_s A, ElInt basisSize, 
  float* sigMin, float* sigMax );
EL_EXPORT ElError ElExtremalSingValEstSparse_d
( ElConstSparseMatrix_d A, ElInt basisSize, 
  double* sigMin, double* sigMax );
EL_EXPORT ElError ElExtremalSingValEstSparse_c
( ElConstSparseMatrix_c A, ElInt basisSize, 
  float* sigMin, float* sigMax );
EL_EXPORT ElError ElExtremalSingValEstSparse_z
( ElConstSparseMatrix_z A, ElInt basisSize, 
  double* sigMin, double* sigMax );

EL_EXPORT ElError ElExtremalSingValEstDistSparse_s
( ElConstDistSparseMatrix_s A, ElInt basisSize, 
  float* sigMin, float* sigMax );
EL_EXPORT ElError ElExtremalSingValEstDistSparse_d
( ElConstDistSparseMatrix_d A, ElInt basisSize, 
  double* sigMin, double* sigMax );
EL_EXPORT ElError ElExtremalSingValEstDistSparse_c
( ElConstDistSparseMatrix_c A, ElInt basisSize, 
  float* sigMin, float* sigMax );
EL_EXPORT ElError ElExtremalSingValEstDistSparse_z
( ElConstDistSparseMatrix_z A, ElInt basisSize, 
  double* sigMin, double* sigMax );

/* Pseudospectra
   ============= */
typedef enum {
  EL_PS_TWO_NORM,
  EL_PS_ONE_NORM
} ElPseudospecNorm;

typedef struct {
  ElInt realSize, imagSize;

  ElInt imgSaveFreq, numSaveFreq, imgDispFreq;
  ElInt imgSaveCount, numSaveCount, imgDispCount;
  const char *imgBase, *numBase;
  ElFileFormat imgFormat, numFormat;
  bool itCounts;
} ElSnapshotCtrl;
EL_EXPORT ElError ElSnapshotCtrlDefault( ElSnapshotCtrl* ctrl );
/* NOTE: Since conversion from SnapshotCtrl involves deep copies of char* */
EL_EXPORT ElError ElSnapshotCtrlDestroy( const ElSnapshotCtrl* ctrl );

typedef struct {
  ElPseudospecNorm norm;
  ElInt blockWidth;

  bool schur;
  bool forceComplexSchur;
  bool forceComplexPs;
  ElSchurCtrl_s schurCtrl;

  ElInt maxIts;
  float tol;
  bool deflate;

  bool arnoldi;
  ElInt basisSize;
  bool reorthog;

  bool progress;

  ElSnapshotCtrl snapCtrl;
} ElPseudospecCtrl_s;
EL_EXPORT ElError ElPseudospecCtrlDefault_s( ElPseudospecCtrl_s* ctrl );
/* NOTE: Since conversion from SnapshotCtrl involves deep copies of char* */
EL_EXPORT ElError ElPseudospecCtrlDestroy_s( const ElPseudospecCtrl_s* ctrl );

typedef struct {
  ElPseudospecNorm norm;
  ElInt blockWidth;

  bool schur;
  bool forceComplexSchur;
  bool forceComplexPs;
  ElSchurCtrl_d schurCtrl;

  ElInt maxIts;
  double tol;
  bool deflate;

  bool arnoldi;
  ElInt basisSize;
  bool reorthog;

  bool progress;

  ElSnapshotCtrl snapCtrl;

  complex_double center;
  double realWidth, imagWidth;
} ElPseudospecCtrl_d;
EL_EXPORT ElError ElPseudospecCtrlDefault_d( ElPseudospecCtrl_d* ctrl );
/* NOTE: Since conversion from SnapshotCtrl involves deep copies of char* */
EL_EXPORT ElError ElPseudospecCtrlDestroy_d( const ElPseudospecCtrl_d* ctrl );

typedef struct {
  complex_float center;
  float realWidth, imagWidth;
} ElSpectralBox_s;
typedef struct {
  complex_double center;
  double realWidth, imagWidth;
} ElSpectralBox_d;

/* (Pseudo-)Spectral portrait
   -------------------------- */ 
EL_EXPORT ElError ElSpectralPortrait_s
( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_s* box );
EL_EXPORT ElError ElSpectralPortrait_d
( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_d* box );
EL_EXPORT ElError ElSpectralPortrait_c
( ElConstMatrix_c A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_s* box );
EL_EXPORT ElError ElSpectralPortrait_z
( ElConstMatrix_z A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_d* box );

EL_EXPORT ElError ElSpectralPortraitDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap,
  ElInt realSize, ElInt imagSize, ElSpectralBox_s* box );
EL_EXPORT ElError ElSpectralPortraitDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap,
  ElInt realSize, ElInt imagSize, ElSpectralBox_d* box );
EL_EXPORT ElError ElSpectralPortraitDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s invNormMap,
  ElInt realSize, ElInt imagSize, ElSpectralBox_s* box );
EL_EXPORT ElError ElSpectralPortraitDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d invNormMap,
  ElInt realSize, ElInt imagSize, ElSpectralBox_d* box );

/* Expert version
   ^^^^^^^^^^^^^^ */
EL_EXPORT ElError ElSpectralPortraitX_s
( ElConstMatrix_s A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_s* box, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralPortraitX_d
( ElConstMatrix_d A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_d* box, ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralPortraitX_c
( ElConstMatrix_c A, ElMatrix_s invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_s* box, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralPortraitX_z
( ElConstMatrix_z A, ElMatrix_d invNormMap, ElInt realSize, ElInt imagSize,
  ElSpectralBox_d* box, ElPseudospecCtrl_d ctrl );

EL_EXPORT ElError ElSpectralPortraitXDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap,
  ElInt realSize, ElInt imagSize, 
  ElSpectralBox_s* box, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralPortraitXDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap,
  ElInt realSize, ElInt imagSize, 
  ElSpectralBox_d* box, ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralPortraitXDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s invNormMap,
  ElInt realSize, ElInt imagSize, 
  ElSpectralBox_s* box, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralPortraitXDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d invNormMap,
  ElInt realSize, ElInt imagSize, 
  ElSpectralBox_d* box, ElPseudospecCtrl_d ctrl );

/* (Pseudo-)Spectral window
   ------------------------ */
EL_EXPORT ElError ElSpectralWindow_s
( ElConstMatrix_s A, ElMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindow_d
( ElConstMatrix_d A, ElMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindow_c
( ElConstMatrix_c A, ElMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindow_z
( ElConstMatrix_z A, ElMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize );

EL_EXPORT ElError ElSpectralWindowDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindowDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindowDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize );
EL_EXPORT ElError ElSpectralWindowDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize );

/* Expert version
   ^^^^^^^^^^^^^^ */
EL_EXPORT ElError ElSpectralWindowX_s
( ElConstMatrix_s A, ElMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralWindowX_d
( ElConstMatrix_d A, ElMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralWindowX_c
( ElConstMatrix_c A, ElMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralWindowX_z
( ElConstMatrix_z A, ElMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl );

EL_EXPORT ElError ElSpectralWindowXDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralWindowXDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralWindowXDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s invNormMap,
  complex_float center, float realWidth, float imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralWindowXDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d invNormMap,
  complex_double center, double realWidth, double imagWidth,
  ElInt realSize, ElInt imagSize, ElPseudospecCtrl_d ctrl );

/* (Pseudo-)Spectral cloud
   ----------------------- */
EL_EXPORT ElError ElSpectralCloud_s
( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap );
EL_EXPORT ElError ElSpectralCloud_d
( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap );
EL_EXPORT ElError ElSpectralCloud_c
( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap );
EL_EXPORT ElError ElSpectralCloud_z
( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap );

EL_EXPORT ElError ElSpectralCloudDist_s
( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts,
  ElDistMatrix_s invNormMap );
EL_EXPORT ElError ElSpectralCloudDist_d
( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts,
  ElDistMatrix_d invNormMap );
EL_EXPORT ElError ElSpectralCloudDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts,
  ElDistMatrix_s invNormMap );
EL_EXPORT ElError ElSpectralCloudDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts,
  ElDistMatrix_d invNormMap );

/* Expert version
   ^^^^^^^^^^^^^^ */
EL_EXPORT ElError ElSpectralCloudX_s
( ElConstMatrix_s A, ElConstMatrix_c shifts, ElMatrix_s invNormMap,
  ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralCloudX_d
( ElConstMatrix_d A, ElConstMatrix_z shifts, ElMatrix_d invNormMap,
  ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralCloudX_c
( ElConstMatrix_c A, ElConstMatrix_c shifts, ElMatrix_s invNormMap,
  ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralCloudX_z
( ElConstMatrix_z A, ElConstMatrix_z shifts, ElMatrix_d invNormMap,
  ElPseudospecCtrl_d ctrl );

EL_EXPORT ElError ElSpectralCloudXDist_s
( ElConstDistMatrix_s A, ElConstDistMatrix_c shifts,
  ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralCloudXDist_d
( ElConstDistMatrix_d A, ElConstDistMatrix_z shifts,
  ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl );
EL_EXPORT ElError ElSpectralCloudXDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c shifts,
  ElDistMatrix_s invNormMap, ElPseudospecCtrl_s ctrl );
EL_EXPORT ElError ElSpectralCloudXDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z shifts,
  ElDistMatrix_d invNormMap, ElPseudospecCtrl_d ctrl );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* ifndef EL_LAPACK_SPECTRAL_C_H */

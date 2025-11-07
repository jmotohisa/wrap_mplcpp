/*
 *  test1.c - Time-stamp: <Fri Nov 07 21:04:20 JST 2025>
 *
 *   Copyright (c) 2025  jmotohisa (Junichi Motohisa)  <motohisa@ist.hokudai.ac.jp>
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  $Id: test1.c 2025-11-07 18:23:06 jmotohisa $
 */

/*! 
  @file test1.c 
  @brief 
  @author J. Motohisa
  @date
*/

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <tgmath.h>

/* #define GLOBAL_VALUE_DEFINE */
/* #include "test1.h" */

/*!
  @brief
  @param[in]
  @param[out]
  @param[in,out]
  @return
*/

#include "wrap_matplotlibcpp.h"

#define PROGRAM_NAME "test"
#define CHECK(cond, msg) { if (!(cond)) { fprintf(stderr, "%s error: %s\n", PROGRAM_NAME,msg); exit(EXIT_FAILURE); } }
#define CHK_MALLOC(p, t, n) CHECK(p = (t *) malloc(sizeof(t) * (n)), "out of memory")
#define MAT2(A,i,j,nx,ny) (*(A+(i)+(j)*(nx)))

int main(void )
{
  int nx,ny;
  double *x,*y,*z,*y0;
  int i,j;
  nx=50;
  ny=100;
  CHK_MALLOC(x,double,nx);
  CHK_MALLOC(y0,double,nx);
  CHK_MALLOC(y,double,ny);
  CHK_MALLOC(z,double,nx*ny);

  for(i=0;i<nx;i++) {
    *(x+i)=((double )i)/nx;
  }

  for(i=0;i<nx;i++) {
    *(y0+i)=sin(M_PI*(*(x+i)));
  }
  plot_xy(x,y0, nx);
  
  for(j=0;j<ny;j++) {
    *(y+j)=2*((double) j)/ny;
  }
  for(j=0;j<ny;j++) {
    for(i=0;i<nx;i++) {
      MAT2(z,i,j,nx,ny)=sin(*(x+i)*M_PI)*sin(*(y+j)*M_PI);
    }
  }
  
  plot_xyz_surface(x,y,z,nx,ny);

  free(x);
  free(y);
  free(z);
  return 0;
}

/*
 *  wrap_matplotlibcpp.cpp - Time-stamp: <Fri Nov 07 21:01:48 JST 2025>
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
 *  $Id: wrap_matplotlibcpp.cpp 2025-11-07 14:49:48 jmotohisa $
 */

/*! 
  @file wrap_matplotlibcpp.cpp 
  @brief 
  @author J. Motohisa
  @date
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <complex.h>
// #include <tgmath.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <string>
#include <vector>

#include <Python.h>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

#define GLOBAL_VALUE_DEFINE
#include "wrap_matplotlibcpp.h"

/*!
  @brief
  @param[in]
  @param[out]
  @param[in,out]
  @return
*/

#define MAT2(A,i,j,nx,ny) (*(A+(i)+(j)*(nx)))

extern "C" {
int plot_xy(double *x0, double *y0, int n)
{
  std::vector<double> x(n),y(n);
  for(int i = 0; i<n ;i++)
    {
      x[i] = *(x0+i);
      y[i] = *(y0+i);
    }
	
  plt::named_plot("Results", x, y, "b");
  plt::show();

  return 0;
}
}

extern "C" {
int plot_xyz_surface(double *x0, double *y0, double *z0,int nx, int ny)
{
  // Create a 2D grid for x and y
  std::vector<std::vector<double>> X_grid(nx, std::vector<double>(ny));
  std::vector<std::vector<double>> Y_grid(nx, std::vector<double>(ny));
  std::vector<std::vector<double>> Z_grid(nx, std::vector<double>(ny));
  
  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < ny; ++j) {
      X_grid[i][j] = *(x0+i);
      Y_grid[i][j] = *(y0+j);
    }
  }

  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < ny; ++j) {
      Z_grid[i][j] = MAT2(z0,i,j,nx,ny);
    }
  }

  // Create the 3D surface plot
  plt::plot_surface(X_grid, Y_grid, Z_grid);
  
  // Set labels and title
  plt::xlabel("X-axis");
  plt::ylabel("Y-axis");
  plt::set_zlabel("Z-axis"); // Note: use set_zlabel for 3D plots
  
  plt::title("3D Surface Plot");
  plt::show();
  
  return 0;
}

}

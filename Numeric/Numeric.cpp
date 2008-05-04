// $Id: Numeric.cpp,v 1.41 2008-05-04 08:31:16 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Message.h"
#include "Numeric.h"

// Check GSL version. We need at least 1.2, since all versions <=
// 1.1.1 have a buggy SVD routine (infinite loop fixed on Sun Jun 16
// 11:45:29 2002 in GSL's cvs tree). We check this at run time since
// Gmsh could be distributed with the gsl dynamically linked.

#if defined(HAVE_GSL)

#include <gsl/gsl_version.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>

void new_handler(const char *reason, const char *file, int line,
                 int gsl_errno)
{
  Msg::Error("GSL: %s (%s, line %d)", reason, file, line);
}

int check_gsl()
{
  // check version
  int major, minor;
  if(!sscanf(gsl_version, "%d.%d", &major, &minor)){
    Msg::Fatal("Cannot retreive GSL version");
    return 0;
  }
  if(major < 1 || (major == 1 && minor < 2)) {
    Msg::Error("Your GSL version (%d.%d.X) has a bug in the singular value",
        major, minor);
    Msg::Error("decomposition code. Please upgrade to version 1.2 or above.");
    Msg::Fatal("You can download the GSL from http://sources.redhat.com/gsl/");
    return 0;
  }
  // set new error handler
  gsl_set_error_handler(&new_handler);

  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

#else

#define NRANSI
#include "nrutil.h"
void dsvdcmp(double **a, int m, int n, double w[], double **v);
int check_gsl()
{
  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

#endif

void invert_singular_matrix3x3(double MM[3][3], double II[3][3])
{
  int i, j, k, n = 3;
  double TT[3][3];

  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      II[i - 1][j - 1] = 0.0;
      TT[i - 1][j - 1] = 0.0;
    }
  }

#if defined(HAVE_GSL)
  gsl_matrix *M = gsl_matrix_alloc(3, 3);
  gsl_matrix *V = gsl_matrix_alloc(3, 3);
  gsl_vector *W = gsl_vector_alloc(3);
  gsl_vector *TMPVEC = gsl_vector_alloc(3);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      gsl_matrix_set(M, i - 1, j - 1, MM[i - 1][j - 1]);
    }
  }
  gsl_linalg_SV_decomp(M, V, W, TMPVEC);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      double ww = gsl_vector_get(W, i - 1);
      if(fabs(ww) > 1.e-16) {   //singular value precision
        TT[i - 1][j - 1] += gsl_matrix_get(M, j - 1, i - 1) / ww;
      }
    }
  }
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      for(k = 1; k <= n; k++) {
        II[i - 1][j - 1] +=
          gsl_matrix_get(V, i - 1, k - 1) * TT[k - 1][j - 1];
      }
    }
  }
  gsl_matrix_free(M);
  gsl_matrix_free(V);
  gsl_vector_free(W);
  gsl_vector_free(TMPVEC);
#else
  double **M = dmatrix(1, 3, 1, 3);
  double **V = dmatrix(1, 3, 1, 3);
  double *W = dvector(1, 3);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      M[i][j] = MM[i - 1][j - 1];
    }
  }
  dsvdcmp(M, n, n, W, V);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      if(fabs(W[i]) > 1.e-16) { //singular value precision
        TT[i - 1][j - 1] += M[j][i] / W[i];
      }
    }
  }
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      for(k = 1; k <= n; k++) {
        II[i - 1][j - 1] += V[i][k] * TT[k - 1][j - 1];
      }
    }
  }
  free_dmatrix(M, 1, n, 1, n);
  free_dmatrix(V, 1, n, 1, n);
  free_dvector(W, 1, n);
#endif
}

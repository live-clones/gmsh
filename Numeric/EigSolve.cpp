// $Id: EigSolve.cpp,v 1.4 2004-12-22 17:49:26 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
//   Laurent Stainier

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PREC  1.e-16

// Solve eigenproblem for a real general matrix (based on a C++
// reimplementation of lapack routines from Laurent Stainier)
//
// IMPORTANT! How to use the output of EigSolve():
//
// 1) If the i-th eigenvalue is real, the i-th COLUMN of the
// eigenvector Matrix contains the corresponding eigenvector.
//
// 2) If the i-th eigenvalue is complex with positive imaginary part,
// COLUMNS i and (i + 1) contain the real and imaginary parts of the
// corresponding eigenvector. The conjugate of this vector is the
// eigenvector for the conjugate eigenvalue.
//
// Note the return value. If it does not equal 1, some eigenvalues and
// all eigenvectors are meaningless.

static void swap(double *a,int inca,double *b,int incb,int n)
{
  double tmp;
  for (int i=0; i < n; i++, a+=inca, b+=incb) {
    tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
  }
}

static void cdiv(double ar,double ai,double br,double bi,double& cr,double& ci) 
{
  double s = fabs(br)+fabs(bi);
  double si = 1.e0/s;
  double ars,ais,brs,bis;
  ars = ar*si;
  ais = ai*si;
  brs = br*si;
  bis = bi*si;
  s = brs*brs+bis*bis;
  cr = (ars*brs+ais*bis)/s;
  ci = (ais*brs-ars*bis)/s;
}

// Balancing operations

static void balanc(int nm,int n,double *A,int& low,int& high,double *scale) 
{
  static const double RADIX = 16.e0;

  double b2 = RADIX*RADIX;
  int i,j,ij,ji,k=0,l=n-1;
  bool last = false;
  
  // search for rows isolating an eigenvalue and push them down
 ROWS:
    // check rows
    for (i=l; i >= 0; i--) {
      for (j=0, ij=i*nm; j <= l; j++, ij++) {
        if (i == j) continue;
        if (A[ij] != 0.e0) break;
      }
      if (j > l) {
        scale[l] = i;
        if (i != l) { // exchange columns and rows
          swap(A+i,nm,A+l,nm,l+1);
          swap(A+i*nm+k,1,A+l*nm+k,1,n-k);
        }
        if (l == 0) goto END;
        l--;
        goto ROWS;
      }
    }

  // search for columns isolating an eigenvalue and push them left
 COLUMNS:
    // check column
    for (j=k; j <= l; j++) {
      for (i=k, ij=k*nm+j; i <= l; i++, ij+=nm) {
        if (i == j) continue;
        if (A[ij] != 0.e0) break;
      }
      if (i > l) { // exchange columns and rows
        scale[k] = j;
        if (j != k) {
          swap(A+j,nm,A+k,nm,l+1);
          swap(A+j*nm+k,1,A+k*nm+k,1,n-k);
        }
        k++;
        goto COLUMNS;
      }
    }

  // balance the submatrix in rows/columns k to l
  for (i=k; i <= l; i++) scale[i] = 1.e0;

  // iterative loop for norm reduction
  while (!last) {
    last = true;

    for (i=k; i <= l; i++) {

      // calculate row and column norm
      double c=0.e0,r=0.e0;
      for (j=k, ij=i*nm+k, ji=k*nm+i; j <=l ; j++, ij++, ji+=nm) {
        if (i == j) continue;
        c += fabs(A[ji]);
        r += fabs(A[ij]);
      }

      // if both are non-zero
      double g,f,s;
      if ((c > PREC) && (r > PREC)) {

        g = r/RADIX;
        f = 1.e0;
        s = c+r;
        while (c < g) {
          f *= RADIX;
          c *= b2;
        }

        g = r*RADIX;
        while (c > g) {
          f /= RADIX;
          c /= b2;
        }

        // balance
        if ((c+r)/f < 0.95*s) {
          g = 1.e0/f;
          scale[i] *= f;
          last = false;

          // apply similarity transformation
          for (j=k, ij=i*nm+k; j < n; j++, ij++) A[ij] *= g;
          for (j=0, ji=i  ; j <= l; j++, ji+=nm) A[ji] *= f;
        }
      }
    }
  }

 END:
   low = k;
   high = l;
}

static void balbak(int nm,int n,int low,int high,double scale[],int m,double *v) 
{
  int i,j,k,ii,ij;

  // quick return
  if (m == 0) return;

  // step 1
  if (low != high) {
    for (i=low; i <= high; i++) {
      double s = scale[i];
      for (j=0,ij=i; j < m; j++, ij+=nm) v[ij] *= s;
    }
  }

  // step 2
  for (ii=0; ii < n; ii++) {
    if (ii >= low && ii <= high) continue;
    if (ii < low)
      i = low-ii;
    else
      i = ii;

    k = (int) scale[i];
    if (k == i) continue;
    swap(v+i,nm,v+k,nm,m);
  }
}

// Transformation of a general matrix to upper Hessenberg form

static void elmhes(int nm,int n,int low,int high,double *A,int work[]) 
{
  int i,j,k,l,m,ij,ji,im1,jm1,jm,mj;

  k = low+1;
  l = high-1;
  if (l < k) return;

  for (m=k; m <= l; m++) {
    int m1 = m-1;
    double x = 0.e0;

    // find the pivot
    i = m;
    for (j=m, jm1=m*nm+m-1; j <= high; j++, jm1+=nm) {
      if (fabs(A[jm1]) < fabs(x)) continue;
      x = A[jm1];
      i = j;
    }
    work[m] = i;

    // interchange rows and columns
    if (i != m) {
      swap(A+i*nm+m1,1,A+m*nm+m1,1,n-m1);
      swap(A+i,nm,A+m,nm,high+1);
    }

    // carry out elimination
    if (fabs(x) > PREC) {
      for (i=m+1, im1=(m+1)*nm+m-1; i <= high; i++, im1+=nm) {
        double y = A[im1];
        if (y != 0.e0) {
          y /= x;
          A[im1] = y;
          for (j=m, ij=i*nm+m, mj=m*nm+m; j < n; j++, ij++, mj++) A[ij] -= y*A[mj];
          for (j=0, ji=i, jm=m; j <= high; j++, ji+=nm, jm+=nm)   A[jm] += y*A[ji];
        }
      }
    }
  }
}

static void eltran(int nm,int n,int low,int high,double *A,int work[],double *v) 
{
  int i,j,m,ij,im,im1,mj;

  // initialize v to identity matrix
  for (j=0; j < n; j++) {
    for (i=0, ij=j*nm; i < n; i++, ij++) v[ij] = 0.e0;
    v[j+j*nm] = 1.e0;
  }

  // loop from high-1 to low+1
  for (m=high-1; m > low; m--) {
    int m1 = m+1;
    for (i=m1, im=m1*nm+m, im1=m1+m*nm; i <= high; i++, im+=nm, im1++) 
      v[im1] = A[im-1];

    i = work[m];
    if (i == m) continue;

    for (j=m, mj=m+m*nm, ij=i+m*nm; j <= high; j++, mj+=nm, ij+=nm) {
      v[mj] = v[ij];
      v[ij] = 0.e0;
    }

    v[i+m*nm] = 1.e0;
  }
}

// Find eigenvalues of a real upper Hessenberg matrix by the QR method

static int hqr(int nm,int n,int low,int high,double *H,double wr[],double wi[],double *vv)
{
  int i,j,k,l,m,ij,ij1,ik,ik1,ik2,in,in1,jn,jn1,kj,kj1,kj2,nj,nj1,mmin;
  double p=0.0e0,q=0.0e0,r=0.0e0,s=0.0e0,x,y,z=0.0e0,u,v,w;

  // store roots isolated by balanc, and compute matrix norm
  k=0;
  double norm = 0.e0;
  for (i=0; i < n; i++) {
    for (j=k, ij=i*nm+k; j < n; j++, ij++) norm += fabs(H[ij]);

    k = i;
    if (i >= low && i <= high) continue;
    wr[i] = H[i*nm+i];
    wi[i] = 0.e0;
  }

  // search for next eigenvalues
  int nn=high,nn1;
  double t=0.e0;
  while (nn >= low) {

    int iter=0;
    do {

      // look for single small subdiagonal element
      for (l=nn; l > low; l--) {
        s = fabs(H[(l-1)*(nm+1)])+fabs(H[l*(nm+1)]);
        if (s == 0.e0) s = norm;
        if ((fabs(H[l*nm+l-1])+s) == s) break;
      }

      // form shift
      x = H[nn*nm+nn];
      if (l == nn) { // ... one root found
        wr[nn] = x+t;
        wi[nn] = 0.e0;
        H[nn*nm+nn] = wr[nn];
        nn--;
      }
      else {
        nn1 = nn-1;
        y = H[nn1*nm+nn1];
        w = H[nn*nm+nn1]*H[nn1*nm+nn];
        if (l == nn1) { // ... two roots found
          p = 0.5*(y-x);
          q = p*p+w;
          z = sqrt(fabs(q));
          H[nn*nm+nn] = x+t;
          x += t;
          H[nn1*nm+nn1] = y+t;
          if (q >= 0.e0) { // ... a real pair
            z = p+((p > 0.e0)?(z):(-z));
            wr[nn1] = wr[nn] = x+z;
            if (fabs(z) > PREC) wr[nn] = x-w/z;
            wi[nn1] = wi[nn] = 0.e0;

            x = H[nn*nm+nn1];
            s = fabs(x)+fabs(z);
            p = x/s;
            q = z/s;
            r = sqrt(p*p+q*q);
            p /= r;
            q /= r;
            // row modification
            for (j=nn1, nj=nn*nm+nn1, nj1=nn1*nm+nn1; j < n; j++, nj++, nj1++) {
              z = H[nj1];
              H[nj1] = q*z+p*H[nj];
              H[nj]  = q*H[nj]-p*z;
            }
            // column modification
            for (i=0, in=nn, in1=nn1; i <= nn; i++, in+=nm, in1+=nm) {
              z = H[in1];
              H[in1] = q*z+p*H[in];
              H[in]  = q*H[in]-p*z;
            }
            // accumulate transformations
            for (i=low, in=low+nn*nm, in1=low+nn1*nm; i <= high; i++, in++, in1++) {
              z = vv[in1];
              vv[in1] = q*z+p*vv[in];
              vv[in]  = q*vv[in]-p*z;
            }
          }
          else {           // ... a complex pair
            wr[nn1] = wr[nn] = x+p;
            wi[nn1] = z;
            wi[nn] = -z;
          }
          nn -= 2;
        }
        else {          // ... no roots found. Continue iterations.
          if (iter == 30) return nn+1;
          if (iter == 10 || iter == 20) { // form exceptional shift
            t += x;
            for (i=low; i <=nn; i++) H[i*nm+i] -= x;
            s = fabs(H[nn*nm+nn1])+fabs(H[nn1*nm+nn1-1]);
            y = x = 0.75*s;
            w = -0.4375*s*s;
          }
          iter++;

          // look for two consecutive small sub-diagonal elements
          for (m=nn-2; m >= l; m--) {
            z = H[m*nm+m];
            r = x-z;
            s = y-z;
            p = (r*s-w)/H[(m+1)*nm+m]+H[m*nm+m+1];
            q = H[(m+1)*(nm+1)]-z-r-s;
            r = H[(m+2)*nm+m+1];
            s = fabs(p)+fabs(q)+fabs(r);
            p /= s;
            q /= s;
            r /= s;
            if (m == l) break;
            u = fabs(p)*(fabs(H[(m-1)*(nm+1)])
                              +fabs(z)+fabs(H[(m+1)*(nm+1)]));
            v = u+fabs(H[m*nm+m-1])*(fabs(q)+fabs(r));
            if (u == v) break;
          }
          for (i=m+2; i <= nn; i++) {
            H[i*nm+i-2] = 0.e0;
            if (i != (m+2)) H[i*nm+i-3] = 0.e0;
          }

          // double QR step on rows l to nn and columns m to nn
          for (k=m; k <= nn1; k++) {

            if (k != m) { // begin setup of Householder vector
              p = H[k*nm+k-1];
              q = H[(k+1)*nm+k-1];
              r = 0.e0;
              if (k != nn1) r = H[(k+2)*nm+k-1];
              x = fabs(p)+fabs(q)+fabs(r);
              if (x < PREC) continue;
              // scale to prevent underflow or overflow
              p /= x;
              q /= x;
              r /= x;
            }

            s = sqrt(p*p+q*q+r*r);
            if (p < 0.e0) s = -s;
            if (k == m) {
              if (l != m) H[k*nm+k-1] = -H[k*nm+k-1];
            }
            else 
              H[k*nm+k-1] = -s*x;
            p += s;
            x = p/s;
            y = q/s;
            z = r/s;
            q /= p;
            r /= p;

            // row modification
            kj = k*nm+k; kj1 = kj+nm; kj2 = kj1+nm;
            for (j=k; j <= nn; j++, kj++, kj1++,kj2++) {
              p = H[kj]+q*H[kj1];
              if (k != nn1) {
                p += r*H[kj2];
                H[kj2] -= p*z;
              }
              H[kj1] -= p*y;
              H[kj]  -= p*x;
            }

            // column modification
            mmin = (nn < k+3) ? nn : k+3;
            ik = l*nm+k; ik1 = ik+1; ik2 = ik1+1;
            for (i=l; i <= mmin; i++, ik+=nm, ik1+=nm, ik2+=nm) {
              p = x*H[ik]+y*H[ik1];
              if (k != nn1) {
                p += z*H[ik2];
                H[ik2] -= p*r;
              }
              H[ik1] -= p*q;
              H[ik]  -= p;
            }

            // accumulate transformations
            ik = low+k*nm; ik1 = ik+nm; ik2 = ik1+nm;
            for (i=low; i <= high; i++, ik++, ik1++, ik2++) {
              p = x*vv[ik]+y*vv[ik1];
              if (k != nn1) {
                p += z*vv[ik2];
                vv[ik2] -= p*r;
              }
              vv[ik1] -= p*q;
              vv[ik]  -= p;
            }
          }
        }
      }

    } while (l < nn-1);
  }

  // Backsubstitute to find vectors of upper triangular form
  for (nn=n-1; nn >= 0; nn--) {
    p = wr[nn];
    q = wi[nn];
    nn1 = nn-1;
    if (q == 0.e0) { // real vector
      m = nn;
      H[nn*nm+nn] = 1.e0;
      for (i=nn1; i >= 0; i--) {
        in  = i*nm+nn;
        in1 = i*nm+nn1;
        w = H[i*nm+i]-p;

        r = 0.e0;
        for (j=m, ij=i*nm+m, jn=m*nm+nn; j <= nn; j++, ij++, jn+=nm) 
          r += H[ij]*H[jn];

        if (wi[i] < 0.e0) {
          z = w;
          s = r;
          continue;
        }

        m = i;
        if (wi[i] == 0.e0) {
          t = w;
          if (t == 0.e0) {
            u = norm;
            t = u;
            do {
              t *= 0.01;
              v = norm+t;
            } while (v > u);
          }
          H[in] = -r/t;
        }
        else { // solve real equation
          x = H[i*nm+i+1];
          y = H[(i+1)*nm+i];
          q = (wr[i]-p)*(wr[i]-p)+wi[i]*wi[i];
          t = (x*s-z*r)/q;
          H[i*nm+nn] = t;
          if (fabs(x) <= fabs(z))
            H[in+nm] = (-s-y*t)/z;
          else
            H[in+nm] = (-r-w*t)/x;
        }

        // overflow control
        t = fabs(H[in]);
        if (t != 0.e0) {
          u = t;
          v = t+1.e0/t;
          if (u >= v)
            for (j=i, jn=in; j <= nn; j++, jn+=nm) H[jn] /= t;
        }
      }
    }
    else if (q < 0.e0) { // complex vector
      m = nn1;

      // last vector component chosen imaginary, so that eigenvector matrix is triangular
      if (fabs(H[nn*nm+nn1]) <= fabs(H[nn1*nm+nn]))
        cdiv(0.e0,-H[nn1*nm+nn],H[nn1*nm+nn1]-p,q,H[nn1*nm+nn1],H[nn1*nm+nn]);
      else {
        H[nn1*nm+nn1] = q/H[nn*nm+nn1];
        H[nn1*nm+nn] = -(H[nn*nm+nn]-p)/H[nn*nm+nn1];
      }

      for (i=nn-2; i >= 0; i--) {
        in  = i*nm+nn;
        in1 = i*nm+nn1;
        w = H[i*nm+i]-p;

        double ra = 0.e0;
        double sa = 0.e0;
        for (j=m, ij=i*nm+m, jn=m*nm+nn, jn1=m*nm+nn1; j <= nn; 
             j++, ij++, jn+=nm, jn1+=nm) {
          ra += H[ij]*H[jn1];
          sa += H[ij]*H[jn];
        }

        if (wi[i] < 0.e0) {
          z = w;
          r = ra;
          s = sa;
          continue;
        }

        m = i;
        if (wi[i] == 0.e0) {
          cdiv(-ra,-sa,w,q,H[in1],H[in]);
        }
        else { // solve complex equations
          x = H[i*nm+i+1];
          y = H[(i+1)*nm+i];
          double vr = (wr[i]-p)*(wr[i]-p)+wi[i]*wi[i]-q*q;
          double vi = 2*(wr[i]-p)*q;
          if (vr == 0.e0 && vi == 0.e0) {
            u = norm*(fabs(w)+fabs(q)+fabs(x)
                      +fabs(y)+fabs(z));
            vr = u;
            do {
              vr *= 0.01;
              v = u+vr;
            } while (v > u);
          }
          cdiv(x*r-z*ra+q*sa,x*s-z*sa-q*ra,vr,vi,H[in1],H[in]);
          if (fabs(x) <= (fabs(z)+fabs(q)))
            cdiv(-r-y*H[in1],-s-y*H[in],z,q,
                 H[in1+nm],H[in+nm]);
          else {
            H[in1+nm] = (-ra-w*H[in1]+q*H[in])/x;
            H[in+nm]  = (-sa-w*H[in]-q*H[in1])/x;
          }
        }

        // overflow control
        u = fabs(H[in1]); v = fabs(H[in]);
        t = (u > v) ? u:v;
        if (t != 0.e0) {
          u = t;
          v = t+1.e0/t;
          if (u >= v) {
            for (j=i, jn=in, jn1=in1; j < nn; j++, jn+=nm, jn1+=nm) {
              H[jn1] /= t;
              H[jn]  /= t;
            }
          }
        }
      }
    }
  }

  // vectors of isolated roots
  for (i=0; i < n; i++) {
    if (i >= low && i <= high) continue;
    for (j=0, ij=i, ij1=i*nm; j < n; j++, ij+=nm, ij1++) 
      vv[ij] = H[ij1];
  }

  // multiply by transformation matrix to give evctors of original full matrix
  for (j=n-1; j >= 0; j--) {
    m = (j < high) ? j:high;
    for (i=low, ij=low+j*nm; i <= high; i++, ij++) {
      z = 0.e0;
      for (k=low, ik=i+low*nm, kj=low*nm+j; k <= m; k++, ik+=nm, kj+=nm) 
        z += vv[ik]*H[kj];
      vv[ij] = z;
    }
  }

  return 0;
}

// Normalizes the eigenvectors. This subroutine is based on the
// LINPACK routine SNRM2, written 25 October 1982, modified on 14
// October 1993 by Sven Hammarling of Nag Ltd.

static void normvec(int n, double *Z, double *wi)
{
  for (int j = 0; j < n; j++){ // Go through the columns of the array
    double scale = 0.0;
    double ssq = 1.0;
    
    for (int i = 0; i < n; i++){
      double absxi = fabs(Z[j*n+i]);
      if (absxi > PREC){
	double dummy = scale/absxi;
	if (scale < absxi){
	  ssq = 1.0 + ssq*dummy*dummy;
	  scale = absxi;
	}
	else
	  ssq += 1.0/dummy/dummy;
      }
    }
    
    if (fabs(wi[j]) > PREC){ 
      // If complex eigenvalue, take into account imaginary part of
      // eigenvector
      for (int i = 0; i < n; i++){
	double absxi = fabs(Z[(j + 1)*n+i]);
	if (absxi > PREC){
	  double dummy = scale/absxi;
	  if (scale < absxi){
	    ssq = 1.0 + ssq*dummy*dummy;
	    scale = absxi;
	  }
	  else
	    ssq += 1.0/dummy/dummy;
	}
      }
    }
    
    // this is norm of the (possibly complex) vector
    double norm = scale*sqrt(ssq); 
    
    for (int i = 0; i < n; i++)
      Z[j*n+i] /= norm;
    
    if (fabs(wi[j]) > PREC){
      // If complex eigenvalue, also scale imaginary part of
      // eigenvector
      j++;
      for (int i = 0; i < n; i++)
	Z[j*n+i] /= norm;
    }
  }
}

int EigSolve(int nm,int n,double *A,double *wr,double *wi,
	     double *v,int *work1,double *work2) 
{
  int is1,is2,ierr;

  balanc(nm,n,A,is1,is2,work2);
  elmhes(nm,n,is1,is2,A,work1);
  eltran(nm,n,is1,is2,A,work1,v);
  ierr = hqr(nm,nm,is1,is2,A,wr,wi,v);
  if (ierr) return 0;
  balbak(nm,n,is1,is2,work2,n,v);
  normvec(n,v,wi);
  return 1;
}

// Solve eigen problem for a real, symmetric matrix using the Jacobi
// algorithm (based on a routine from Laurent Stainier)

int EigSolveSym(int n,int nm,double *A,double *d,double *V,
		double *b,double *z)
{
  static const int NSWMAX = 50;

  int i,j,k,ii,ij,ki=0,kj=0,kki,kkj,ival,jval;
  int nrot,nsweep;
  double c,g,h,s,t,tau,theta,tresh,sum;

  // initialize eigenvectors
  for (j=0,jval=0; j < n; j++,jval+=nm) {
    for (i=0; i < n; i++) V[jval+i] = 0.e0;
    V[jval+j] = 1.e0;
  }

  // initialize b and d to the diagonal of A
  for (i=0, ii=0; i < n; i++, ii+=(i+1)) {
    b[i] = d[i] = A[ii];
    z[i] = 0.e0;
  }

  // begin sweeping process
  nrot = 0;
  for (nsweep=0; nsweep < NSWMAX; nsweep++) {

    // Sum off-diagonal elements
    sum = 0.e0;
    for (i=0, ij=0; i < n; i++, ij++)
      for (j=0; j < i; j++, ij++)
        sum += fabs(A[ij]);

    if (sum < PREC) break;

    // compute a treshold on the first 3 sweeps
    if (nsweep < 4)
      tresh = 0.2*sum/(n*n);
    else
      tresh = 0.e0;

    // browse the matrix
    for (i=0, ij=0, ival=0; i < n; i++, ij++, ival+=i)
      for (j=0, jval=0; j < i; j++, ij++, jval+=j) {

        // test off-diagonal element
        g = 100.*fabs(A[ij]);
        if ((nsweep > 4) 
            && (fabs(d[i]+g) == fabs(d[i])) 
            && (fabs(d[j]+g) == fabs(d[j]))) {

          A[ij] = 0.e0;
        }
        else if (fabs(A[ij]) > tresh) {

          // compute the rotation
          h = d[j]-d[i];
          if ((fabs(h)+g) == fabs(h))
            t = A[ij]/h;
          else {
            theta = 0.5*h/A[ij];
            t = 1.e0/(fabs(theta)+sqrt(1.0+theta*theta));
            if (theta < 0.e0) t = -t;
          }
          c = 1.e0/sqrt(1.+t*t);
          s = t*c;
          tau = s/(1.e0+c);

          // rotate rows i and j
          h = t*A[ij];
          z[i] -= h;
          z[j] += h;
          d[i] -= h;
          d[j] += h;
          A[ij]  = 0.e0;

          for (k=0,kki=i*nm,kkj=j*nm; k < n; k++, kki++, kkj++) {

            g = V[kki];
            h = V[kkj];
            V[kki] = g-s*(h+g*tau);
            V[kkj] = h+s*(g-h*tau);

            ki = (k<=i)?(ival+k):(ki+k);
            kj = (k<=j)?(jval+k):(kj+k);
            if (k == i || k == j) continue;

            g = A[ki];
            h = A[kj];
            A[ki] = g-s*(h+g*tau);
            A[kj] = h+s*(g-h*tau);
          }

          nrot++;
        }
      }

    // update d and reinitialize z
    for (i=0; i < n; i++) {
      b[i] += z[i];
      d[i] = b[i];
      z[i] = 0.e0;
    }
  }

  if(nsweep >= NSWMAX)
    return 0;
  else
    return nrot+1;
}

// Sort the eigenvalues/vectors in ascending order according to their
// real part. Warning: this will screw up the ordering of complex
// eigenvectors.

void EigSort(int n, double *wr, double *wi, double *B)
{
  for (int i = 0; i < n - 1; i++){
    int k = i;
    double ek = wr[i];
    // search for something to swap
    for (int j = i + 1; j < n; j++){
      const double ej = wr[j];
      if(ej < ek){
	k = j;
	ek = ej;
      }
    }
    if (k != i){
      swap(&wr[i], 1, &wr[k], 1, 1);
      swap(&wi[i], 1, &wi[k], 1, 1);
      swap(&B[n*i], 1, &B[n*k], 1, n);
    }
  }
}

// Small driver for 3x3 matrices, that does not modify the input
// matrix

int EigSolve3x3(const double A[9], double wr[3], double wi[3], double v[9]) 
{
  int ierr;
  if(fabs(A[1]-A[3]) < PREC &&
     fabs(A[2]-A[6]) < PREC &&
     fabs(A[5]-A[7]) < PREC){
    double work1[3], work2[3], S[6] = { A[0], 
					A[1], A[4], 
					A[2], A[5], A[8]};
    ierr = EigSolveSym(3, 3, S, wr, v, work1, work2);
    wi[0] = wi[1] = wi[2] = 0.0;
  }
  else{
    int work1[3];
    double work2[3], M[9] = { A[0], A[1], A[2], 
			      A[3], A[4], A[5],
			      A[6], A[7], A[8]};
    ierr = EigSolve(3, 3, M, wr, wi, v, work1, work2);
  }
  EigSort(3, wr, wi, v);
  return ierr;
}

# if 0
int main ()
{
  //double A[9] = {-0.00299043,-8.67362e-19,0, 
  //	 -8.67362e-19,-0.00299043,-1.73472e-18, 
  //	 0,-1.73472e-18,0.01};
  double A[9] = {1, 2, 3,   2, 4, 5,   3, 5, 6};
  //double A[9] = {1, 2, 3,   1, 4, 5,   3, 5, 6};
  double wr[3], wi[3], B[9];

  for(int i = 0; i < 1; i++) // perf test
    if(!EigSolve3x3(A, wr, wi, B))
      printf("EigSolve did not converge!\n");

  if(wi[0] != 0.0 || wi[1] != 0.0 || wi[2] != 0.0)
    printf("imaginary eigenvalues\n");

  printf ("real= %g %g %g \n", wr[0], wr[1], wr[2]);
  printf ("imag= %.16g %.16g %.16g \n", wi[0], wi[1], wi[2]);
  printf ("eigvec1 = %g %g %g \n", B[0], B[1], B[2]);
  printf ("eigvec2 = %g %g %g \n", B[3], B[4], B[5]);
  printf ("eigvec3 = %g %g %g \n", B[6], B[7], B[8]);
}
#endif

// $Id: EigSolve.cpp,v 1.2 2004-12-08 16:44:33 geuzaine Exp $
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

// This file contains a routine that numerically finds the eigenvalues
// and eigenvectors of a N X N Real Matrix. It is a C++ translation of
// a Javascript translation of Fortran routines from EISPACK. The
// Javascript implementation comes from http://www.akiti.ca/Eig3Solv.html
//
// References:
//
// Smith, B.T.; J.M. Boyle; J.J. Dongarra; B.S. Garbow; Y. Ikebe;
// V.C. Klema; and C.B. Moler.
//           "Matrix Eigensystem Routines--(EISPACK) Guide"
//           Springer-Verlag, Berlin.
//           1976
//
// Garbow, B.S.; J.M. Boyle; J.J. Dongarra; and C.B. Moler.
//           "Matrix Eigensystem Routines--(EISPACK) Guide Extension"
//           Springer-Verlag, Berlin.
//           1977
//
// IMPORTANT! How to use the output:
//
// If the i-th eigenvalue is real, the i-th COLUMN of the eigenvector
// Matrix contains the corresponding eigenvector.
//
// If the i-th eigenvalue is complex with positive imaginary part,
// COLUMNS i and (i + 1) contain the real and imaginary parts of the
// corresponding eigenvector. The conjugate of this vector is the
// eigenvector for the conjugate eigenvalue.
//
// Note the Error Code. If it does not equal -1, some eigenvalues and
// all eigenvectors are meaningless.

#include "Gmsh.h"
#include "Numeric.h"

static void cdivA(int N, double ar, double ai, double br, double bi, 
		  double **A, int in1, int in2, int in3)
{
  // Division routine for dividing one complex number into another:
  // This routine does (ar + ai)/(br + bi) and returns the results in
  // the specified elements of the A matrix.
  
  double s, ars, ais, brs, bis;
  
  s = fabs(br) + fabs(bi);
  ars = ar/s;
  ais = ai/s;
  brs = br/s;
  bis = bi/s;
  s = brs*brs + bis*bis;
  A[in1][in2] = (ars*brs + ais*bis)/s;
  A[in1][in3] = (-(ars*bis) + ais*brs)/s;
  return;
} // End cdivA

static void hqr2(int N, double **A, double **B, int low, int igh, 
		 double *wi, double *wr, int ierr)
{
  // Computes the eigenvalues and eigenvectors of a real
  // upper-Hessenberg Matrix using the QR method.
  
  double norm = 0.0, p = 0.0, q = 0.0, ra, s = 0.0, sa, t = 0.0;
  double tst1, tst2, vi, vr, w, x, y, zz = 0.0, r = 0.0;
  int k = 0, l = 0, m, mp2, en = igh, incrFlag = 1, its = 0;
  int itn = 30*N, enm2 = 0, na = 0, notlas;
  
  for (int i = 0; i < N; i++){ // Store eigenvalues already isolated
			       // and compute matrix norm.
    for (int j = k; j < N; j++)
      norm += fabs(A[i][j]);
    k = i;
    if ((i < low) || (i > igh)){
      wi[i] = 0.0;
      wr[i] = A[i][i];
    } //End if (i < low or i > igh)
  }  // End for i

  // Search next eigenvalues
  while (en >= low){

    if (incrFlag) { // Skip this part if incrFlag is set to 0 at very
		    // end of while loop
      its = 0;
      na = en - 1;
      enm2 = na - 1;
    } //End if (incrFlag)
    else
      incrFlag = 1;
    
    // Look for single small sub-diagonal element for l = en step -1
    // until low
    
    for (int i = low; i <= en; i++){
      l = en + low - i;
      if (l == low)
	break;
      s = fabs(A[l - 1][l - 1]) + fabs(A[l][l]);
      if (s == 0.0)
	s = norm;
      tst1 = s;
      tst2 = tst1 + fabs(A[l][l - 1]);
      if (tst2 == tst1)
	break;
    } //End for i
    
    x = A[en][en];
    
    if (l == en){  //One root found
      wr[en] = A[en][en] = x + t;
      wi[en] = 0.0;
      en--;
      continue;
    } //End if (l == en)
    
    y = A[na][na];
    w = A[en][na]*A[na][en];
    
    if (l == na){  //Two roots found
      p = (-x + y)/2;
      q = p*p + w;
      zz = sqrt(fabs(q));
      x = A[en][en] = x + t;
      A[na][na] = y + t;
      if (q >= 0.0){//Real Pair
	zz = ((p < 0.0) ? (-zz + p) : (p + zz));
	wr[en] = wr[na] = x + zz;
	if (zz != 0.0)
	  wr[en] = -(w/zz) + x;
	wi[en] = wi[na] = 0.0;
	x = A[en][na];
	s = fabs(x) + fabs(zz);
	p = x/s;
	q = zz/s;
	r = sqrt(p*p + q*q);
	p /= r;
	q /= r;
	for (int j = na; j < N; j++){ //Row modification
	  zz = A[na][j];
	  A[na][j] = q*zz + p*A[en][j];
	  A[en][j] = -(p*zz) + q*A[en][j];
	}//End for j
	for (int j = 0; j <= en; j++){ // Column modification
	  zz = A[j][na];
	  A[j][na] = q*zz + p*A[j][en];
	  A[j][en] = -(p*zz) + q*A[j][en] ;
	}//End for j
	for (int j = low; j <= igh; j++){//Accumulate transformations
	  zz = B[j][na];
	  B[j][na] = q*zz + p*B[j][en];
	  B[j][en] = -(p*zz) + q*B[j][en];
	}//End for j
      } //End if (q >= 0.0)
      else {//else q < 0.0
	wr[en] = wr[na] = x + p;
	wi[na] = zz;
	wi[en] = -zz;
      } //End else
      en--;
      en--;
      continue;
    }//End if (l == na)
    
    if (itn == 0){ //Set error; all eigenvalues have not converged
		   //after 30 iterations.
      ierr = en + 1;
      return;
    }//End if (itn == 0)
    
    if ((its == 10) || (its == 20)){ //Form exceptional shift
      t += x;
      for (int i = low; i <= en; i++)
	A[i][i] += -x;
      s = fabs(A[en][na]) + fabs(A[na][enm2]);
      y = x = 0.75*s;
      w = -(0.4375*s*s);
    } //End if (its equals 10 or 20)
    
    its++;
    itn--;
    
    // Look for two consecutive small sub-diagonal elements. Do m = en
    // - 2 to l in increments of -1
    
    for (m = enm2; m >= l; m--){
      zz = A[m][m];
      r = -zz + x;
      s = -zz + y;
      p = (-w + r*s)/A[m + 1][m] + A[m][m + 1];
      q = -(zz + r + s) + A[m + 1][m + 1];
      r = A[m + 2][m + 1];
      s = fabs(p) + fabs(q) + fabs(r);
      p /= s;
      q /= s;
      r /= s;
      if (m == l)
	break;
      tst1 = fabs(p) * (fabs(A[m - 1][m - 1]) + fabs(zz) + fabs(A[m + 1][m + 1]));
      tst2 = tst1 + fabs(A[m][m - 1]) * (fabs(q) + fabs(r));
      if (tst1 == tst2)
	break;
    }//End for m
    
    mp2 = m + 2;
    
    for (int i = mp2; i <= en; i++){
      A[i][i - 2] = 0.0;
      if (i == mp2)
	continue;
      A[i][i - 3] = 0.0;
    }//End for i
    
    // Double qr step involving rows l to en and columns m to en.
    
    for (int i = m; i <= na; i++){
      notlas = ((i != na) ? 1 : 0);
      if (i != m){
	p = A[i][i - 1];
	q = A[i + 1][i - 1];
	r = ((notlas) ? A[i + 2][i - 1] : 0.0);
	x = fabs(p) + fabs(q) + fabs(r);
	if (x == 0.0)      //Drop through rest of for i loop
	  continue;
	p /= x;
	q /= x;
	r /= x;
      } //End if (i != m)
      
      s = sqrt(p*p + q*q + r*r);
      if (p < 0.0)
	s = -s;
      
      if (i != m)
	A[i][i - 1] = -(s*x);
      else {
	if (l != m)
	  A[i][i - 1] = -A[i][i - 1];
      }
      
      p += s;
      x = p/s;
      y = q/s;
      zz = r/s;
      q /= p;
      r /= p;
      k = ((i + 3 < en) ? i + 3 : en);
      
      if (notlas){ //Do row modification
	for (int j = i; j < N; j++) {
	  p = A[i][j] + q*A[i + 1][j] + r*A[i + 2][j];
	  A[i][j] += -(p*x);
	  A[i + 1][j] += -(p*y);
	  A[i + 2][j] += -(p*zz);
	}//End for j
	
	for (int j = 0; j <= k; j++) {//Do column modification
	  p = x*A[j][i] + y*A[j][i + 1] + zz*A[j][i + 2];
	  A[j][i] += -p;
	  A[j][i + 1] += -(p*q);
	  A[j][i + 2] += -(p*r);
	}//End for j
	
	for (int j = low; j <= igh; j++) {//Accumulate transformations
	  p = x*B[j][i] + y*B[j][i + 1] + zz*B[j][i + 2];
	  B[j][i] += -p;
	  B[j][i + 1] += -(p*q);
	  B[j][i + 2] += -(p*r);
	} // End for j
      }//End if notlas
      
      else {
	for (int j = i; j < N; j++) {//Row modification
	  p = A[i][j] + q*A[i + 1][j];
	  A[i][j] += -(p*x);
	  A[i + 1][j] += -(p*y);
	}//End for j
	
	for (int j = 0; j <= k; j++){//Column modification
	  p = x*A[j][i] + y*A[j][i +1];
	  A[j][i] += -p;
	  A[j][i + 1] += -(p*q);
	}//End for j
	
	for (int j = low; j <= igh; j++){//Accumulate transformations
	  p = x*B[j][i] + y*B[j][i +1];
	  B[j][i] += -p;
	  B[j][i + 1] += -(p*q);
	}//End for j
	
      } //End else if notlas
    }//End for i
    incrFlag = 0;
  }//End while (en >= low)

  if (norm == 0.0)
    return;
  
  //Step from (N - 1) to 0 in steps of -1
  
  for (en = (N - 1); en >= 0; en--){
    p = wr[en];
    q = wi[en];
    na = en - 1;
    
    if (q > 0.0)
      continue;
    
    if (q == 0.0){//Real vector
      m = en;
      A[en][en] = 1.0;
      
      for (int j = na; j >= 0; j--){
	w = -p + A[j][j];
	r = 0.0;
	for (int ii = m; ii <= en; ii++)
	  r += A[j][ii]*A[ii][en];
	
	if (wi[j] < 0.0){
	  zz = w;
	  s = r;
	}//End wi[j] < 0.0
	else {//wi[j] >= 0.0
	  m = j;
	  if (wi[j] == 0.0){
	    t = w;
	    if (t == 0.0){
	      t = tst1 = norm;
	      do {
		t *= 0.01;
		tst2 = norm + t;
	      } while (tst2 > tst1);
	    } //End if t == 0.0
	    A[j][en] = -(r/t);
	  }//End if wi[j] == 0.0
	  else { //wi[j] > 0.0; Solve real equations
	    x = A[j][j + 1];
	    y = A[j + 1][j];
	    q = (-p + wr[j])*(-p + wr[j]) + wi[j]*wi[j];
	    A[j][en] = t = (-(zz*r) + x*s)/q;
	    A[j + 1][en] = ((fabs(x) > fabs(zz)) ? -(r + w*t)/x : -(s + y*t)/zz);
	  }//End  else wi[j] > 0.0
	  
	  // Overflow control
	  t = fabs(A[j][en]);
	  if (t == 0.0)
	    continue; //go up to top of for j loop
	  tst1 = t;
	  tst2 = tst1 + 1.0/tst1;
	  if (tst2 > tst1)
	    continue; //go up to top of for j loop
	  for (int ii = j; ii <= en; ii++)
	    A[ii][en] /= t;
	  
	}//End else wi[j] >= 0.0
	
      }//End for j
      
    }      //End q == 0.0
    
    else {//else q < 0.0, complex vector
      //Last vector component chosen imaginary so that eigenvector
      //matrix is triangular
      m = na;
      
      if (fabs(A[en][na]) <= fabs(A[na][en]))
	cdivA(N, 0.0, -A[na][en], -p + A[na][na], q, A, na, na, en);
      else {
	A[na][na] = q/A[en][na];
	A[na][en] = -(-p + A[en][en])/A[en][na];
      } //End else (fabs(A[en][na] > fabs(A[na][en])
      
      A[en][na] = 0.0;
      A[en][en] = 1.0;
      
      for (int j = (na - 1); j >= 0; j--) {
	w = -p + A[j][j];
	sa = ra = 0.0;
	
	for (int ii = m; ii <= en; ii++) {
	  ra += A[j][ii]*A[ii][na];
	  sa += A[j][ii]*A[ii][en];
	} //End for ii
	
	if (wi[j] < 0.0){
	  zz = w;
	  r = ra;
	  s = sa;
	  continue;
	} //End if (wi[j] < 0.0)
	
	//else wi[j] >= 0.0
	m = j;
	if (wi[j] == 0.0)
	  cdivA(N, -ra, -sa, w, q, A, j, na, en);
	else {//wi[j] > 0.0; solve complex equations
	  x = A[j][j + 1];
	  y = A[j + 1][j];
	  vr = -(q*q) + (-p + wr[j])*(-p + wr[j]) + wi[j]*wi[j];
	  vi = (-p + wr[j])*2.0*q;
	  if ((vr == 0.0) && (vi == 0.0)){
	    tst1 = norm*(fabs(w) + fabs(q) + fabs(x) + fabs(y) + fabs(zz));
	    vr = tst1;
	    do {
	      vr *= 0.01;
	      tst2 = tst1 + vr;
	    } while (tst2 > tst1);
	  } //End if vr and vi == 0.0
	  cdivA(N, -(zz*ra) + x*r + q*sa, -(zz*sa + q*ra) + x*s, vr, vi, A, j, na, en);
	  
	  if (fabs(x) > (fabs(zz) + fabs(q))){
	    A[j + 1][na] = (-(ra + w*A[j][na]) + q*A[j][en])/x;
	    A[j + 1][en] = -(sa + w*A[j][en] + q*A[j][na])/x;
	  }//End if
	  else
	    cdivA(N, -(r + y*A[j][na]), -(s + y*A[j][en]), zz, q, A, j + 1, na, en);
	  
	}//End else wi[j] > 0.0
	
	t = ((fabs(A[j][na]) >= fabs(A[j][en])) ? fabs(A[j][na]) : fabs(A[j][en]));
	
	if (t == 0.0) continue; // go to top of for j loop
	
	tst1 = t;
	tst2 = tst1 + 1.0/tst1;
	if (tst2 > tst1) continue; //go to top of for j loop
	
	for (int ii = j; ii <= en; ii++){
	  A[ii][na] /= t;
	  A[ii][en] /= t;
	} //End for ii loop
	
      } // End for j
      
    }//End else q < 0.0
    
  }//End for en

  //End back substitution. Vectors of isolated roots.

  for (int i = 0; i < N; i++){
    if ((i < low) || (i > igh)) {
    for (int j = i; j < N; j++)
      B[i][j] = A[i][j];
    }//End if i
  }//End for i

  // Multiply by transformation matrix to give vectors of original
  // full matrix.
  
  //Step from (N - 1) to low in steps of -1.

  for (int i = (N - 1); i >= low; i--){
    
    m = ((i < igh) ? i : igh);
    
    for (int ii = low; ii <= igh; ii++){
      zz = 0.0;
      for (int jj = low; jj <= m; jj++)
	zz += B[ii][jj]*A[jj][i];
      B[ii][i] = zz;
    }//End for ii
  }//End of for i loop

  return;
} //End of function hqr2

static void norVecC(int N, double **Z, double *wi)
{
  // Normalizes the eigenvectors

  // This subroutine is based on the LINPACK routine SNRM2, written 25
  // October 1982, modified on 14 October 1993 by Sven Hammarling of
  // Nag Ltd.  I have further modified it for use in this Javascript
  // routine, for use with a column of an array rather than a column
  // vector.
  //
  // Z - eigenvector Matrix
  // wi - eigenvalue vector
  
  double scale, ssq, absxi, dummy, norm;
  
  for (int j = 0; j < N; j++){ //Go through the columns of the vector
			       //array
    scale = 0.0;
    ssq = 1.0;
    
    for (int i = 0; i < N; i++){
      if (Z[i][j] != 0){
	absxi = fabs(Z[i][j]);
	dummy = scale/absxi;
	if (scale < absxi){
	  ssq = 1.0 + ssq*dummy*dummy;
	  scale = absxi;
	}//End if (scale < absxi)
	else
	  ssq += 1.0/dummy/dummy;
      }//End if (Z[i][j] != 0)
    } //End for i
    
    if (wi[j] != 0){// If complex eigenvalue, take into account
		    // imaginary part of eigenvector
      for (int i = 0; i < N; i++){
	if (Z[i][j + 1] != 0){
	  absxi = fabs(Z[i][j + 1]);
	  dummy = scale/absxi;
	  if (scale < absxi){
	    ssq = 1.0 + ssq*dummy*dummy;
	    scale = absxi;
	  }//End if (scale < absxi)
	  else
	    ssq += 1.0/dummy/dummy;
	}//End if (Z[i][j + 1] != 0)
      } //End for i
    }//End if (wi[j] != 0)
    
    norm = scale*sqrt(ssq); //This is the norm of the (possibly
			    //complex) vector
    
    for (int i = 0; i < N; i++)
      Z[i][j] /= norm;
    
    if (wi[j] != 0){// If complex eigenvalue, also scale imaginary
		    // part of eigenvector
      j++;
      for (int i = 0; i < N; i++)
	Z[i][j] /= norm;
    }//End if (wi[j] != 0)
    
  }// End for j
  
  return;
} // End norVecC

static void swap_elements(int N, double *v, int i, int k)
{
  double tmp = v[k];
  v[k] = v[i];
  v[i] = tmp;
}

static void swap_columns(int N, double **v, int i, int k)
{
  for(int n = 0; n < N; n++){
    double tmp = v[n][k];
    v[n][k] = v[n][i];
    v[n][i] = tmp;
  }
}

void EigSort(int N, double *wr, double *wi, double **B)
{
  // Sorts the eigenvalues/vectors in ascending order according to
  // their real part. Warning: this might screw up the ordering of
  // complex eigenvectors --- VERIFY THIS

  for (int i = 0; i < N - 1; i++){
    int k = i;
    double ek = wr[i];
    // search for something to swap
    for (int j = i + 1; j < N; j++){
      const double ej = wr[j];
      if(ej < ek){
	k = j;
	ek = ej;
      }
    }
    if (k != i){
      swap_elements(N, wr, i, k);
      swap_elements(N, wi, i, k);
      swap_columns(N, B, i, k);
    }
  }
}

int EigSolve(int N, double **A, double *wr, double *wi, double **B,
	     int *itmp, double *dtmp)
{
  // Computes the N eigenvalues of the square, real matrix A. All
  // vectors have dimension N and all matrices have dimension
  // NxN. Warning: the matrix A gets modified during the
  // computation.

  // Balance the matrix to improve accuracy of
  // eigenvalues. (Introduces no rounding errors, since it scales A by
  // powers of the radix.)

  double *scale = dtmp; //Contains information about transformations.
  int *trace = itmp; //Records row and column interchanges

  double radix = 2; //Base of machine floating point representation.
  double c, f, g, r, s, b2 = radix*radix;
  int ierr = -1, igh, low, k = 0, l = N - 1, noconv;
  
  //Search through rows, isolating eigenvalues and pushing them down.
  
  noconv = l;
  
  while (noconv >= 0){
    r = 0;
    
    for (int j = 0; j <= l; j++) {
      if (j == noconv) continue;
      if (A[noconv][j] != 0.0){
	r = 1;
	break;
      }
    } //End for j
    
    if (r == 0){
      scale[l] = noconv;
      
      if (noconv != l){
	for (int i = 0; i <= l; i++){
	  f = A[i][noconv];
	  A[i][noconv] = A[i][l];
	  A[i][l] = f;
	}//End for i
	for (int i = 0; i < N; i++){
	  f = A[noconv][i];
	  A[noconv][i] = A[l][i];
	  A[l][i] = f;
	}//End for i
      }//End if (noconv != l)
      
      if (l == 0)
	break;  //break out of while loop
      
      noconv = --l;
      
    }//End if (r == 0)
    
    else //else (r != 0)
      noconv--;
    
  }//End while noconv
  
  if (l > 0) {  //Search through columns, isolating eigenvalues and
		//pushing them left.
    
    noconv = 0;
    
    while (noconv <= l){  
      c = 0;
      
      for (int i = k; i <= l; i++){
	if (i == noconv) continue;
	if (A[i][noconv] != 0.0){
	  c = 1;
	  break;
	}
      }//End for i
      
      if (c == 0){
	scale[k] = noconv;
	
	if (noconv != k){
	  for (int i = 0; i <= l; i++){
	    f = A[i][noconv];
	    A[i][noconv] = A[i][k];
	    A[i][k] = f;
	  }//End for i
	  for (int i = k; i < N; i++){
	    f = A[noconv][i];
	    A[noconv][i] = A[k][i];
	    A[k][i] = f;
	  }//End for i
	  
	}//End if (noconv != k)
	
	noconv = ++k;
      }//End if (c == 0)
      
      else  //else (c != 0)
	noconv++;
      
    }//End while noconv
    
    //Balance the submatrix in rows k through l.
    
    for (int i = k; i <= l; i++)
      scale[i] = 1.0;
    
    //Iterative loop for norm reduction
    do {
      noconv = 0;
      for (int i = k; i <= l; i++) {
	c = r = 0.0;
	for (int j = k; j <= l; j++){
	  if (j == i) continue;
	  c += fabs(A[j][i]);
	  r += fabs(A[i][j]);
	} // End for j
	//guard against zero c or r due to underflow:
	if ((c == 0.0) || (r == 0.0)) continue; 
	g = r/radix;
	f = 1.0;
	s = c + r;
	while (c < g) {
	  f *= radix;
	  c *= b2;
	} // End while (c < g)
	g = r*radix;
	while (c >= g) {
	  f /= radix;
	  c /= b2;
	} // End while (c >= g)
	
	//Now balance
	if ((c + r)/f < 0.95*s) {
	  g = 1.0/f;
	  scale[i] *= f;
	  noconv = 1;
	  for (int j = k; j < N; j++)
	    A[i][j] *= g;
	  for (int j = 0; j <= l; j++)
	    A[j][i] *= f;
	} //End if ((c + r)/f < 0.95*s)
      } // End for i
    } while (noconv);  // End of do-while loop.
    
  } //End if (l > 0)
  
  low = k;
  igh = l;
  
  //End of balanc
  
  // Now reduce the real general Matrix to upper-Hessenberg form using
  // stabilized elementary similarity transformations.

  for (int i = (low + 1); i < igh; i++){
    k = i;
    c = 0.0;
    
    for (int j = i; j <= igh; j++){
      if (fabs(A[j][i - 1]) > fabs(c)){
	c = A[j][i - 1];
	k = j;
      }//End if
    }//End for j
    
    trace[i] = k;
    
    if (k != i){
      for (int j = (i - 1); j < N; j++){
	r = A[k][j];
	A[k][j] = A[i][j];
	A[i][j] = r;
      }//End for j
      
      for (int j = 0; j <= igh; j++){
	r = A[j][k];
	A[j][k] = A[j][i];
	A[j][i] = r;
      }//End for j
    }//End if (k != i)
    
    if (c != 0.0){
      for (int m = (i + 1); m <= igh; m++){
	r = A[m][i - 1];
	
	if (r != 0.0){
	  r = A[m][i - 1] = r/c;
	  for (int j = i; j < N; j++)
	    A[m][j] += -(r*A[i][j]);
	  for (int j = 0; j <= igh; j++)
	    A[j][i] += r*A[j][m];
	}//End if (r != 0.0)
      }//End for m
    }//End if (c != 0)
  }  //End for i.
  
  // Accumulate the stabilized elementary similarity transformations
  // used in the reduction of A to upper-Hessenberg form. Introduces
  // no rounding errors since it only transfers the multipliers used
  // in the reduction process into the eigenvector matrix.
  
  for (int i = 0; i < N; i++){ //Initialize B to the identity Matrix.
    for (int j = 0; j < N; j++)
      B[i][j] = 0.0;
    B[i][i] = 1.0;
  } //End for i
  
  for (int i = (igh - 1); i >= (low + 1); i--){
    k = trace[i];
    for (int j = (i + 1); j <= igh; j++)
      B[j][i] = A[j][i - 1];
    
    if (i == k)
      continue;
    
    for (int j = i; j <= igh; j++){
      B[i][j] = B[k][j];
      B[k][j] = 0.0;
    } //End for j
    
    B[k][i] = 1.0; 
    
  } // End for i
  
  hqr2(N, A, B, low, igh, wi, wr, ierr);
  
  if (ierr == -1){
    
    if (low != igh){
      for (int i = low; i <= igh; i++){
	s = scale[i];
	for (int j = 0; j < N; j++)
	  B[i][j] *= s;
      }//End for i
    }//End if (low != igh)
    
    for (int i = (low - 1); i >= 0; i--){
      k = (int)scale[i];//FIXME: I added the cast
      if (k != i){
	for (int j = 0; j < N; j++){
	  s = B[i][j];
	  B[i][j] = B[k][j];
	  B[k][j] = s;
	}//End for j
      }//End if k != i
    }//End for i
    
    for (int i = (igh + 1); i < N; i++){
      k = (int)scale[i];//FIXME: Iadded the casr
      if (k != i){
	for (int j = 0; j < N; j++){
	  s = B[i][j];
	  B[i][j] = B[k][j];
	  B[k][j] = s;
	}//End for j
      }//End if k != i
    }//End for i
    
    norVecC(N, B, wi);  //Normalize the eigenvectors
    
  }//End if ierr = -1

  return ierr;
}  //End of Eig3Solve

# if 0
int main()
{
  const int N = 3;
  double *wr = new double[N];
  double *wi = new double[N];
  double **A = new double*[N];
  double **B = new double*[N];
  for(int i = 0; i < N; i++){
    A[i] = new double[N];
    B[i] = new double[N];
  }
  double *dtmp = new double[N];
  int *itmp = new int[N];

  for(int i = 0; i < 1000000; i++){ // perf test
    A[0][0] = 1.; A[0][1] = 2.; A[0][2] = 3.;
    A[1][0] = 2.; A[1][1] = 4.; A[1][2] = 5.;
    A[2][0] = 3.; A[2][1] = 5.; A[2][2] = 6.;
    EigSolve(3, A, wr, wi, B, itmp, dtmp);
  }
  /*
  printf("%g %g %g\n", A[0][0], A[0][1], A[0][2]);
  printf("%g %g %g\n", A[1][0], A[1][1], A[1][2]);
  printf("%g %g %g\n", A[2][0], A[2][1], A[2][2]);
  */
  printf("real= %g %g %g \n", wr[0], wr[1], wr[2]);
  printf("imag= %g %g %g \n", wi[0], wi[1], wi[2]);
  printf("eigvec1 = %g %g %g \n", B[0][0], B[1][0], B[2][0]);
  printf("eigvec2 = %g %g %g \n", B[0][1], B[1][1], B[2][1]);
  printf("eigvec3 = %g %g %g \n", B[0][2], B[1][2], B[2][2]);
}
#endif

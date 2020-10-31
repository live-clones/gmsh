// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tools.h"

//!\ this function does not return the aspect ratio 'r'. It returns 'r^2/24'
double hxtTetAspectFastRatio (double a[3],  double b[3], double c[3], double d[3], void* userData) {
  HXT_UNUSED(userData);
  
  double ab[3], ac[3], ad[3], bc[3], cd[3], db[3];
  for (int i=0; i<3; i++) {
    ab[i] = b[i] - a[i]; // AB
    ac[i] = c[i] - a[i]; // AC
    ad[i] = d[i] - a[i]; // AD
  }
 
  double acxad0 = ac[1]*ad[2] - ac[2]*ad[1];
  double adxab0 = ad[1]*ab[2] - ad[2]*ab[1];
  double abxac0 = ab[1]*ac[2] - ab[2]*ac[1];
  double volume6 = ab[0]*acxad0 + ac[0]*adxab0 + ad[0]*abxac0;
 
   // abort as early as possible
  if(volume6<=0.0)
    return 0.0;
 
  double acxad1 = ac[2]*ad[0] - ac[0]*ad[2];
  double acxad2 = ac[0]*ad[1] - ac[1]*ad[0];
 
  double adxab1 = ad[2]*ab[0] - ad[0]*ab[2];
  double adxab2 = ad[0]*ab[1] - ad[1]*ab[0];
 
  double abxac1 = ab[2]*ac[0] - ab[0]*ac[2];
  double abxac2 = ab[0]*ac[1] - ab[1]*ac[0];

  for (int i=0; i<3; i++) {
    db[i] = b[i] - d[i]; // DB = B-D = AB-AD
    bc[i] = c[i] - b[i]; // BC = C-B = AC-AB
    cd[i] = d[i] - c[i]; // CD = D-c = AD-AC
  }
 
  double bcxcd0 = bc[1]*cd[2] - bc[2]*cd[1]; // = acxad0+abxac0+adxab0;
  double bcxcd1 = bc[2]*cd[0] - bc[0]*cd[2]; // = acxad1+abxac1+adxab1;
  double bcxcd2 = bc[0]*cd[1] - bc[1]*cd[0]; // = acxad2+abxac2+adxab2;

  double areaSum = sqrt(acxad0*acxad0 + acxad1*acxad1 + acxad2*acxad2)
                 + sqrt(adxab0*adxab0 + adxab1*adxab1 + adxab2*adxab2)
                 + sqrt(abxac0*abxac0 + abxac1*abxac1 + abxac2*abxac2)
                 + sqrt(bcxcd0*bcxcd0 + bcxcd1*bcxcd1 + bcxcd2*bcxcd2);

  double l = ab[0]*ab[0] + ab[1]*ab[1] + ab[2]*ab[2]; // |AB|²
  double l2 = ac[0]*ac[0] + ac[1]*ac[1] + ac[2]*ac[2]; // |AC|²
  double l3 = ad[0]*ad[0] + ad[1]*ad[1] + ad[2]*ad[2]; // |AD|²
  double l4 = bc[0]*bc[0] + bc[1]*bc[1] + bc[2]*bc[2]; // |BC|²
  double l5 = cd[0]*cd[0] + cd[1]*cd[1] + cd[2]*cd[2]; // |CD|²
  double l6 = db[0]*db[0] + db[1]*db[1] + db[2]*db[2]; // |DB|²

  if(l2>l) l=l2;
  if(l3>l) l=l3;
  if(l4>l) l=l4;
  if(l5>l) l=l5;
  if(l6>l) l=l6;

  return volume6*volume6/(l*areaSum*areaSum);
}
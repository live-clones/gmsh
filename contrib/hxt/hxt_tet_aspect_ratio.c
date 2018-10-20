#include <math.h>
#include "predicates.h"

void hxt_cross_prod(double a[3], double b[3], double c[3])
{
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

double hxt_distance2(double p0[3], double p1[3]){
  double a = p0[0]-p1[0];
  double b = p0[1]-p1[1];
  double c = p0[2]-p1[2];
  return a*a+b*b+c*c;
}

double hxt_triangle_area(double p0[3], double p1[3], double p2[3])
{
  double a[3], b[3], c[3];

  a[0] = p2[0] - p1[0];
  a[1] = p2[1] - p1[1];
  a[2] = p2[2] - p1[2];

  b[0] = p0[0] - p1[0];
  b[1] = p0[1] - p1[1];
  b[2] = p0[2] - p1[2];

  hxt_cross_prod(a, b, c);
  return 0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double hxtTetAspectRatio (double p0[3],  double p1[3], double p2[3], double p3[3]) {
  double volume = orient3d (p0,p1,p2,p3) / 6.0;

  double s1 = fabs(hxt_triangle_area(p0, p1, p2));
  double s2 = fabs(hxt_triangle_area(p0, p2, p3));
  double s3 = fabs(hxt_triangle_area(p0, p1, p3));
  double s4 = fabs(hxt_triangle_area(p1, p2, p3));

  double rhoin = 3. * volume / (s1 + s2 + s3 + s4);
  double l  = hxt_distance2 (p0,p1);
  double l2 = hxt_distance2 (p0,p2);
  double l3 = hxt_distance2 (p0,p3);
  double l4 = hxt_distance2 (p1,p2);
  double l5 = hxt_distance2 (p1,p3);
  double l6 = hxt_distance2 (p2,p3);

  l = l2 > l ? l2:l;
  l = l3 > l ? l3:l;
  l = l4 > l ? l4:l;
  l = l5 > l ? l5:l;
  l = l6 > l ? l6:l;
  
  return sqrt(24./l) * rhoin ;
}



//!\ this function does not return the aspect ratio 'r'. It returns 'r^2/24'
double hxtTetAspectFastRatio (double a[3],  double b[3], double c[3], double d[3]) {
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


// for a pair of tetrahedra: (abcd) and (abec)
// void hxtTetAspectFastRatioPair (double a[3],  double b[3], double c[3], double d[3], double e[3], double* quality1, double quality2) {
//   double ab[3], ac[3], ad[3], bc[3], cd[3], db[3];
//   for (int i=0; i<3; i++) {
//     ab[i] = b[i] - a[i]; // AB
//     ac[i] = c[i] - a[i]; // AC
//     ad[i] = d[i] - a[i]; // AD
//     ae[i] = e[i] - a[i]; // AE
//   }
 
//   double adxac0 = ad[1]*ac[2] - ad[2]*ac[1];
//   double abxad0 = ab[1]*ad[2] - ab[2]*ad[1];
//   double acxab0 = ac[1]*ab[2] - ac[2]*ab[1];
//   double acxae0 = ac[1]*ae[2] - ac[2]*ae[1];
//   double aexab0 = ae[1]*ab[2] - ae[2]*ab[1];
//   double volume1 = ab[0]*adxac0 + ac[0]*abxad0 + ad[0]*acxab0;
//   double volume2 = ab[0]*acxae0 - ae[0]*acxab0 + ac[0]*aexab0;
 
//    // abort as early as possible
//   if(volume1<=0.0 || volume2<=0.0){
//     *quality1 = 0.0;
//     *quality2 = 0.0;
//     return;
//   }
 
//   double adxac1 = ad[2]*ac[0] - ad[0]*ac[2];
//   double adxac2 = ad[0]*ac[1] - ad[1]*ac[0];
 
//   double abxad1 = ab[2]*ad[0] - ab[0]*ad[2];
//   double abxad2 = ab[0]*ad[1] - ab[1]*ad[0];
 
//   double acxab1 = ac[2]*ab[0] - ac[0]*ab[2];
//   double acxab2 = ac[0]*ab[1] - ac[1]*ab[0];

//   double acxae1 = ac[2]*ae[0] - ac[0]*ae[2];
//   double acxae2 = ac[0]*ae[1] - ac[1]*ae[0];

//   double aexab1 = ae[2]*ab[0] - ae[0]*ab[2];
//   double aexab2 = ae[0]*ab[1] - ae[1]*ab[0];

//   for (int i=0; i<3; i++) {
//     db[i] = b[i] - d[i]; // DB = B-D = AB-AD
//     bc[i] = c[i] - b[i]; // BC = C-B = AC-AB
//     cd[i] = d[i] - c[i]; // CD = D-c = AD-AC

//   }
 
//   double cdxbc0 = cd[1]*bc[2] - cd[2]*bc[1]; // = adxac0+acxab0+abxad0;
//   double cdxbc1 = cd[2]*bc[0] - cd[0]*bc[2]; // = adxac1+acxab1+abxad1;
//   double cdxbc2 = cd[0]*bc[1] - cd[1]*bc[0]; // = adxac2+acxab2+abxad2;

//   double commonArea = sqrt(acxab0*acxab0 + acxab1*acxab1 + acxab2*acxab2);

//   double areaSum1 = commonArea
//                   + sqrt(adxac0*adxac0 + adxac1*adxac1 + adxac2*adxac2)
//                   + sqrt(abxad0*abxad0 + abxad1*abxad1 + abxad2*abxad2)
//                   + sqrt(cdxbc0*cdxbc0 + cdxbc1*cdxbc1 + cdxbc2*cdxbc2);

//   double l = ab[0]*ab[0] + ab[1]*ab[1] + ab[2]*ab[2]; // |AB|²
//   double l2 = ac[0]*ac[0] + ac[1]*ac[1] + ac[2]*ac[2]; // |AC|²
//   double l3 = ad[0]*ad[0] + ad[1]*ad[1] + ad[2]*ad[2]; // |AD|²
//   double l4 = bc[0]*bc[0] + bc[1]*bc[1] + bc[2]*bc[2]; // |BC|²
//   double l5 = cd[0]*cd[0] + cd[1]*cd[1] + cd[2]*cd[2]; // |CD|²
//   double l6 = db[0]*db[0] + db[1]*db[1] + db[2]*db[2]; // |DB|²

//   if(l2>l) l=l2;
//   if(l3>l) l=l3;
//   if(l4>l) l=l4;
//   if(l5>l) l=l5;
//   if(l6>l) l=l6;

//   *quality1 = volume1*volume1/(l*areaSum1*areaSum1);
// }
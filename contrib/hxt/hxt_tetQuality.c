#include <math.h>
#include <float.h>
#include "predicates.h"

static inline void hxt_cross_prod(double a[3], double b[3], double c[3])
{
  c[0] = a[1] * b[2] - a[2] * b[1];
  c[1] = a[2] * b[0] - a[0] * b[2];
  c[2] = a[0] * b[1] - a[1] * b[0];
}

static inline double hxt_distance2(double p0[3], double p1[3]){
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

double hxtTetDeterminantInexact(double a[3],  double b[3], double c[3], double d[3], void* userData) {
HXT_UNUSED(userData);
  
  double ab[3], ac[3], ad[3];
  for (int i=0; i<3; i++) {
    ab[i] = b[i] - a[i]; // AB
    ac[i] = c[i] - a[i]; // AC
    ad[i] = d[i] - a[i]; // AD
  }
 
  double acxad0 = ac[1]*ad[2] - ac[2]*ad[1];
  double adxab0 = ad[1]*ab[2] - ad[2]*ab[1];
  double abxac0 = ab[1]*ac[2] - ab[2]*ac[1];
  double volume6 = ab[0]*acxad0 + ac[0]*adxab0 + ad[0]*abxac0;
 
  return volume6;
}


double hxtTetAspectRatio (double p0[3],  double p1[3], double p2[3], double p3[3], void* userData) {
  HXT_UNUSED(userData);

  double volume = -orient3d (p0,p1,p2,p3) / 6.0;

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




// static inline double vec_dot(double a[3], double b[3]) {
//   return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
// }

// static inline double vec_norm(double v[3]) {
//   return vec_dot(v,v);
// }

// double myOwnAspectRatio(double a[3],  double b[3], double c[3], double d[3]) {
//   double edges[6][4];
//   for (int i=0; i<3; i++) {
//     edges[0][i] = b[i] - a[i];
//     edges[1][i] = c[i] - b[i];
//     edges[2][i] = d[i] - c[i];
//     edges[3][i] = a[i] - d[i];
//     edges[4][i] = c[i] - a[i];
//     edges[5][i] = d[i] - b[i];
//   }

//   double normal[4][4];
//   const unsigned ci[4] = {1,2,0,1};

//   for (unsigned j=0; j<3; j++) {
//     for (unsigned i=0; i<4; i++) {
//       normal[i][j] = edges[(i+1)&3][ci[j]]*edges[(i+2)&3][ci[j+1]] - edges[(i+2)&3][ci[j]]*edges[(i+1)&3][ci[j+1]];
//     }
//   }

//    // abort as early as possible
//   if(edges[0][0]*normal[1][0] < edges[4][0]*normal[2][0] + edges[3][0]*normal[3][0])
//     return -1.0;

//   double maxEdge = 0.0;
//   for (int i=0; i<6; i++) {
//     double l = vec_norm(edges[i]);
//     if(l>maxEdge)
//       maxEdge = l;
//   }

//   double minHeight = DBL_MAX; 
//   for (int i=0; i<4; i++) {
//     double h = vec_dot(edges[i], normal[i]);
//     h = h*h/vec_norm(normal[i]);
//     if(h<minHeight)
//       minHeight = h;
//   }

//   return minHeight/maxEdge*1.5;
// }


// double myOwnAspectRatio(double a[3],  double b[3], double c[3], double d[3]) {
//   double x[8], y[8], z[8];

//   x[0] = b[0] - a[0];
//   x[1] = c[0] - b[0];
//   x[2] = d[0] - c[0];
//   x[3] = a[0] - d[0];
//   x[4] = c[0] - a[0];
//   x[5] = d[0] - b[0];

//   y[0] = b[1] - a[1];
//   y[1] = c[1] - b[1];
//   y[2] = d[1] - c[1];
//   y[3] = a[1] - d[1];
//   y[4] = c[1] - a[1];
//   y[5] = d[1] - b[1];

//   z[0] = b[2] - a[2];
//   z[1] = c[2] - b[2];
//   z[2] = d[2] - c[2];
//   z[3] = a[2] - d[2];
//   z[4] = c[2] - a[2];
//   z[5] = d[2] - b[2];

//   double normal_x[4], normal_y[4], normal_z[4];
//   for (unsigned k=0; k<4; k++) {
//     unsigned i = (k+1)&3;
//     unsigned j = (k+2)&3;

//     normal_x[k] = y[i]*z[j] - y[j]*z[i];
//     normal_y[k] = z[i]*x[j] - z[j]*x[i];
//     normal_z[k] = x[i]*y[j] - x[j]*y[i];
//   }

//   if(x[0]*normal_x[1] < x[4]*normal_x[2] + x[3]*normal_x[3])
//     return -1.0;

//   double maxEdge = 0.0;
//   for (int i=0; i<6; i++) {
//     double l = x[i]*x[i]+y[i]*y[i]+z[i]*z[i];
//     if(l>maxEdge)
//       maxEdge = l;
//   }

//   double minHeight = DBL_MAX; 
//   for (int i=0; i<4; i++) {
//     double h = x[i]*normal_x[i] + y[i]*normal_y[i] + z[i]*normal_z[i];
//     double n = normal_x[i]*normal_x[i] + normal_y[i]*normal_y[i] + normal_z[i]*normal_z[i];
//     h = h*h/n;
//     if(h<minHeight)
//       minHeight = h;
//   }

//   double r = minHeight/maxEdge;

//   return r < (1./9.) ? r*4.5 : r*0.9 + 0.4;
// }
// #endif
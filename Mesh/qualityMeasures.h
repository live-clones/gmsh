#ifndef _QUALITY_MEASURES_H_
#define _QUALITY_MEASURES_H_

class BDS_Point;
class BDS_Face;
class MVertex;
class MTriangle;
enum gmshQualityMeasure4Triangle {QMTRI_RHO};

double qmTriangle ( MTriangle *f,  const gmshQualityMeasure4Triangle &cr); 
double qmTriangle ( BDS_Face *f,  const gmshQualityMeasure4Triangle &cr); 
double qmTriangle ( const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3, const gmshQualityMeasure4Triangle &cr); 
double qmTriangle ( const MVertex   *v1, const MVertex   *v2, const MVertex   *v3, const gmshQualityMeasure4Triangle &cr);
double qmTriangle ( const double    *d1, const double    *d2, const double    *d3, const gmshQualityMeasure4Triangle &cr);
double qmTriangle ( const double    &x1, const double    &y1, const double    &z1, 
		    const double    &x2, const double    &y2, const double    &z2, 
		    const double    &x3, const double    &y3, const double    &z3, 
		    const gmshQualityMeasure4Triangle    &cr);

#endif

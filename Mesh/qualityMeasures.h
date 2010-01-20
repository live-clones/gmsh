// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _QUALITY_MEASURES_H_
#define _QUALITY_MEASURES_H_

class BDS_Point;
class BDS_Face;
class MVertex;
class MTriangle;
class MQuadrangle;
class MTetrahedron;
class MElement;

enum qualityMeasure4Triangle {QMTRI_RHO, QMTRI_COND};
enum qualityMeasure4Tet{QMTET_1, QMTET_2, QMTET_3, QMTET_ONE, QMTET_COND};

double qmDistorsionOfMapping (MQuadrangle *e);
double qmDistorsionOfMapping (MTriangle *e);
double qmDistorsionOfMapping (MTetrahedron *e);

double qmTriangleAngles (MTriangle *e);
double qmQuadrangleAngles (MQuadrangle *e);

double qmTriangle(MTriangle *f, const qualityMeasure4Triangle &cr); 
double qmTriangle(BDS_Face *f, const qualityMeasure4Triangle &cr); 
double qmTriangle(const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3, 
                  const qualityMeasure4Triangle &cr); 
double qmTriangle(const MVertex *v1, const MVertex *v2, const MVertex *v3, 
                  const qualityMeasure4Triangle &cr);
double qmTriangle(const double *d1, const double *d2, const double *d3, 
                  const qualityMeasure4Triangle &cr);
double qmTriangle(const double &x1, const double &y1, const double &z1, 
                  const double &x2, const double &y2, const double &z2, 
                  const double &x3, const double &y3, const double &z3, 
                  const qualityMeasure4Triangle &cr);
double qmTet(MTetrahedron *t, const qualityMeasure4Tet &cr, double *volume = 0);
double qmTet(const MVertex *v1, const MVertex *v2, const MVertex *v3, 
             const MVertex *v4, const qualityMeasure4Tet &cr, double *volume = 0);
double qmTet(const double &x1, const double &y1, const double &z1, 
             const double &x2, const double &y2, const double &z2, 
             const double &x3, const double &y3, const double &z3, 
             const double &x4, const double &y4, const double &z4, 
             const qualityMeasure4Tet &cr, double *volume = 0);

#endif

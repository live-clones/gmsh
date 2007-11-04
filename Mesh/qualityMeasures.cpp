#include "qualityMeasures.h"
#include "BDS.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"


double qmTriangle ( const BDS_Point *p1, const BDS_Point *p2, const BDS_Point *p3, const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle (p1->X,p1->Y,p1->Z,p2->X,p2->Y,p2->Z,p3->X,p3->Y,p3->Z,cr);
}

double qmTriangle ( BDS_Face *t, const gmshQualityMeasure4Triangle &cr)
{
  BDS_Point *n[4];
  t->getNodes(n);
  return qmTriangle (n[0],n[1],n[2],cr);
}

double qmTriangle ( MTriangle*t, const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle (t->getVertex(0),t->getVertex(1),t->getVertex(2),cr);
}

double qmTriangle ( const MVertex   *v1, const MVertex   *v2, const MVertex   *v3, const gmshQualityMeasure4Triangle &cr)
{
  return qmTriangle (v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z(),v3->x(),v3->y(),v3->z(),cr);
}

// Triangle abc
// quality is between 0 and 1

double qmTriangle ( const double    &xa, const double    &ya, const double    &za, 
		    const double    &xb, const double    &yb, const double    &zb, 
		    const double    &xc, const double    &yc, const double    &zc, 
		    const gmshQualityMeasure4Triangle    &cr)
{
  double quality;
  switch(cr)
    {
    case QMTRI_RHO:
      {
	// quality = rho / R = 2 * inscribed radius / circumradius
	
	double a [3] = {xc-xb,yc-yb,zc-zb};
	double b [3] = {xa-xc,ya-yc,za-zc};
	double c [3] = {xb-xa,yb-ya,zb-za};

	const double la = norme (a); 
	const double lb = norme (b); 
	const double lc = norme (c); 

	double pva [3]; prodve (b,c,pva); const double sina = norm3 (pva); 
	double pvb [3]; prodve (c,a,pvb); const double sinb = norm3 (pvb);
	double pvc [3]; prodve (a,b,pvc); const double sinc = norm3 (pvc);

	if (sina == 0.0 && sinb == 0.0 && sinc == 0.0) quality = 0.0;
	else quality = 2 * (2*sina*sinb*sinc/(sina + sinb + sinc) );
      }
      break;
    default:
      throw;
    }  
  return quality;
}


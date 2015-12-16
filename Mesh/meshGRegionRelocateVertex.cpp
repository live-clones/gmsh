#include "GModel.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "Context.h"
#include "meshGFaceOptimize.h"
static double objective_function (double xi, MVertex *ver, 
				  double xTarget, double yTarget, double zTarget,
				  const std::vector<MElement*> &lt){
  double x = ver->x();
  double y = ver->y();
  double z = ver->z();
  ver->x() = (1.-xi) * ver->x() + xi * xTarget;
  ver->y() = (1.-xi) * ver->y() + xi * yTarget;
  ver->z() = (1.-xi) * ver->z() + xi * zTarget;
  double minQual = 1.0;
  for(unsigned int i = 0; i < lt.size(); i++){
    if (lt[i]->getNumVertices () == 4)
      minQual = std::min((lt[i]->minSICNShapeMeasure()), minQual);
    else
      minQual = std::min(fabs(lt[i]->minSICNShapeMeasure()), minQual);
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}


#define sqrt5 2.236067977499789696

static int Stopping_Rule(double x0, double x1) 
{
  double tolerance = 1.e-2;
  return ( fabs( x1 - x0 ) < tolerance ) ? 1 : 0;
}

double Maximize_Quality_Golden_Section( MVertex *ver, 
					double xTarget, double yTarget, double zTarget,
					const std::vector<MElement*> &lt )
{
  
  static const double lambda = 0.5 * (sqrt5 - 1.0);
  static const double mu = 0.5 * (3.0 - sqrt5);         // = 1 - lambda
  double a = 0.0;
  double b = 2.0;
  
  double x1 = b - lambda * (b - a);                            
  double x2 = a + lambda * (b - a);                         
  double fx1 = objective_function (x1, ver, xTarget, yTarget, zTarget , lt );
  double fx2 = objective_function (x2, ver, xTarget, yTarget, zTarget , lt );

  while ( ! Stopping_Rule( a, b ) ) {
    //    printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if (fx1 < fx2) {
      a = x1;
      if ( Stopping_Rule( a, b ) ) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function (x2, ver, xTarget, yTarget, zTarget , lt );
    } else {
      b = x2;
      if ( Stopping_Rule( a, b ) ) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function (x1, ver, xTarget, yTarget, zTarget , lt );
    }
  }
  //  printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  return a;
}

static void _relocateVertex(MVertex *ver,
			    const std::vector<MElement*> &lt)
{
  if(ver->onWhat()->dim() != 3) return;
  double x = 0, y=0, z=0;
  int N = 0;
  for(unsigned int i = 0; i < lt.size(); i++){
    double XCG=0,YCG=0,ZCG=0;
    for (int j=0;j<lt[i]->getNumVertices();j++){
      XCG += lt[i]->getVertex(j)->x();
      YCG += lt[i]->getVertex(j)->y();
      ZCG += lt[i]->getVertex(j)->z();
    }
    x += XCG;
    y += YCG;
    z += ZCG;
    N += lt[i]->getNumVertices();
  }

  double xi = Maximize_Quality_Golden_Section( ver, x/N, y/N, z/N, lt );
  ver->x() = (1.-xi) * ver->x() + xi * x/N;
  ver->y() = (1.-xi) * ver->y() + xi * y/N;
  ver->z() = (1.-xi) * ver->z() + xi * z/N;
}

void RelocateVertices (std::vector<GRegion*> &regions) {
  for(unsigned int k = 0; k < regions.size(); k++){
    v2t_cont adj;
    buildVertexToElement(regions[k]->tetrahedra, adj);
    buildVertexToElement(regions[k]->pyramids, adj);
    buildVertexToElement(regions[k]->prisms, adj);
    buildVertexToElement(regions[k]->hexahedra, adj);
    v2t_cont::iterator it = adj.begin();
    while (it != adj.end()){
      _relocateVertex( it->first, it->second);
      ++it;
    }
  }
}


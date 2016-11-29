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
#include "meshGRegionRelocateVertex.h"

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
      //  minQual = std::min((lt[i]->specialQuality()), minQual);
      minQual = std::min(fabs(lt[i]->minSICNShapeMeasure())*.2, minQual);
//    minQual = std::min(lt[i]->minAnisotropyMeasure(), minQual);
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}

static double objective_function (double xi, MVertex *ver, GFace *gf,
                                  SPoint2 &p1, SPoint2 &p2,
                                  const std::vector<MElement*> &lt){
  double x = ver->x();
  double y = ver->y();
  double z = ver->z();
  SPoint2 p = p1 * (1.-xi) + p2 * xi;
  GPoint pp = gf->point(p);
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  double minQual = 1.0;
  for(unsigned int i = 0; i < lt.size(); i++){
    if (lt[i]->getNumVertices () == 4)
      minQual = std::min((lt[i]->etaShapeMeasure()), minQual);
    else
      minQual = std::min(fabs(lt[i]->gammaShapeMeasure()), minQual);
  }
  ver->x() = x;
  ver->y() = y;
  ver->z() = z;
  return minQual;
}




#define sqrt5 2.236067977499789696

static int Stopping_Rule(double x0, double x1, double tol) 
{
  return ( fabs( x1 - x0 ) < tol) ? 1 : 0;
}

double Maximize_Quality_Golden_Section( MVertex *ver, 
                                        double xTarget, double yTarget, double zTarget,
                                        const std::vector<MElement*> &lt ,
					double tol, double &q)
{
  
  static const double lambda = 0.5 * (sqrt5 - 1.0);
  static const double mu = 0.5 * (3.0 - sqrt5);         // = 1 - lambda
  double a = 0.0;
  double b = 2.0;
  
  double x1 = b - lambda * (b - a);                            
  double x2 = a + lambda * (b - a);                         
  double fx1 = objective_function (x1, ver, xTarget, yTarget, zTarget , lt );
  double fx2 = objective_function (x2, ver, xTarget, yTarget, zTarget , lt );

  if (tol < 0.0)return fx1 > fx2 ? x1 : x2;

  while ( ! Stopping_Rule( a, b , tol) ) {
    //    printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if (fx1 < fx2) {
      a = x1;
      if ( Stopping_Rule( a, b , tol) ) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function (x2, ver, xTarget, yTarget, zTarget , lt );
    } else {
      b = x2;
      if ( Stopping_Rule( a, b , tol) ) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function (x1, ver, xTarget, yTarget, zTarget , lt );
    }
  }
  //  printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  q = std::min(fx1,fx2);
  return a;
}


double Maximize_Quality_Golden_Section( MVertex *ver, GFace *gf, 
                                        SPoint2 &p1, SPoint2 &p2,
                                        const std::vector<MElement*> &lt ,
                                        double tol, double &worst)
{
  
  static const double lambda = 0.5 * (sqrt5 - 1.0);
  static const double mu = 0.5 * (3.0 - sqrt5);         // = 1 - lambda
  double a = 0.0;
  double b = 1.0;

  worst = objective_function (0.0, ver, gf, p1, p2, lt );
  
  if (worst > 0.5) return 0.0;
  
  double x1 = b - lambda * (b - a);                            
  double x2 = a + lambda * (b - a);                         
  double fx1 = objective_function (x1, ver, gf, p1, p2, lt );  
  double fx2 = objective_function (x2, ver, gf, p1, p2, lt );

  if (tol < 0.0)return fx1 > fx2 ? x1 : x2;

  while ( ! Stopping_Rule( a, b , tol) ) {
    //    printf("GOLDEN : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
    if (fx1 < fx2) {
      a = x1;
      if ( Stopping_Rule( a, b , tol) ) break;
      x1 = x2;
      fx1 = fx2;
      x2 = b - mu * (b - a);
      fx2 = objective_function (x2, ver, gf, p1, p2, lt );
    } else {
      b = x2;
      if ( Stopping_Rule( a, b , tol) ) break;
      x2 = x1;
      fx2 = fx1;
      x1 = a + mu * (b - a);
      fx1 = objective_function (x1, ver, gf, p1, p2, lt );
    }
  }
  double final = objective_function (a, ver, gf, p1, p2, lt );
  if (final < worst) return 0.0;
  worst = final;
  //  printf("finally : %g %g (%12.5E,%12.5E)\n",a,b,fa,fb);
  return a;
}

void _relocateVertexGolden(MVertex *ver,
			   const std::vector<MElement*> &lt, double relax , double tol)
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

  double q;
  double xi = relax * Maximize_Quality_Golden_Section( ver, x/N, y/N, z/N, lt , tol, q);
  ver->x() = (1.-xi) * ver->x() + xi * x/N;
  ver->y() = (1.-xi) * ver->y() + xi * y/N;
  ver->z() = (1.-xi) * ver->z() + xi * z/N;
}

static double _relocateVertex(GFace* gf, MVertex *ver,
		       const std::vector<MElement*> &lt,
		       double tol) {
  if(ver->onWhat()->dim() != 2) return 2.0;
  
  SPoint2 p1(0,0);
  SPoint2 p2;
  ver->getParameter(0,p2[0]);
  ver->getParameter(1,p2[1]);
  
  int counter=0;
  for(unsigned int i = 0; i < lt.size(); i++){
    for (int j=0;j<lt[i]->getNumVertices();j++){
      MVertex* v = lt[i]->getVertex(j);
      SPoint2 pp;
      reparamMeshVertexOnFace(v, gf, pp);
      counter++;
      if (v->onWhat()->dim() == 1) {
        GEdge *ge = dynamic_cast<GEdge*> (v->onWhat());
        // do not take any chance
        if (ge->isSeam(gf))return 2.0;
      }
      p1 += pp;
    }
  }
  p1 *= 1./(double)counter;
  double worst;
  double xi = Maximize_Quality_Golden_Section( ver, gf, p1, p2, lt , tol, worst);
  //  if (xi != 0)printf("xi = %g\n",xi);
  SPoint2 p = p1*(1-xi) + p2*xi;
  GPoint pp = gf->point(p);
  if (!pp.succeeded())return 2.0;
  ver->x() = pp.x();
  ver->y() = pp.y();
  ver->z() = pp.z();
  ver->setParameter(0,pp.u());
  ver->setParameter(1,pp.v());
  return worst;
}


void getAllBoundaryLayerVertices (GFace *gf, std::set<MVertex*> &vs);

void RelocateVertices (GFace* gf, int niter, double tol) {
  std::set<MVertex*> vs;
  getAllBoundaryLayerVertices (gf, vs);

  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  for (int i=0;i<niter;i++){
    v2t_cont::iterator it = adj.begin();
    while (it != adj.end()){
      if (vs.find(it->first) == vs.end()){
	_relocateVertex( gf, it->first, it->second, tol);
      }
      ++it;
    }  
  }
}


void RelocateVertices (GRegion* region, int niter, double tol) {
  v2t_cont adj;
  buildVertexToElement(region->tetrahedra, adj);
  buildVertexToElement(region->pyramids, adj);
  buildVertexToElement(region->prisms, adj);
  buildVertexToElement(region->hexahedra, adj);
  for (int i=0;i<niter+2;i++){
    v2t_cont::iterator it = adj.begin();
    double relax = std::min((double)(i+1)/niter, 1.0);
    while (it != adj.end()){
      _relocateVertexGolden( it->first, it->second, relax, tol);
      ++it;
    }
  }
}

void RelocateVertices (std::vector<GRegion*> &regions, int niter, double tol) {
  for(unsigned int k = 0; k < regions.size(); k++){
    RelocateVertices (regions[k], niter, tol);
  }
}


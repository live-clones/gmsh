// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "gmshSmoothHighOrder.h"
#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshElasticity.h"
#include "gmshLinearSystemGmm.h"
#include "GFace.h"
#include "GRegion.h"
#include "Context.h"
#include "Numeric.h"

#define SQU(a)      ((a)*(a))

int optimalLocationPN_ (GFace *gf, const MEdge &me, MTriangle *t1, MTriangle *t2,gmshHighOrderSmoother *s);
static int _gmshSwapHighOrderTriangles(GFace *gf);
static int _gmshSwapHighOrderTriangles(GFace *gf,edgeContainer&,faceContainer&, gmshHighOrderSmoother *s);
static int _gmshFindOptimalLocationsP2(GFace *gf, gmshHighOrderSmoother *s);
static int _gmshFindOptimalLocationsPN(GFace *gf,gmshHighOrderSmoother *s);

static double shapeMeasure (MElement *e) {
  const double d1 = e->distoShapeMeasure();
  const double d2 = e->gammaShapeMeasure();
  return d1;
}

void gmshHighOrderSmoother::moveTo (MVertex *v,  const std::map<MVertex*,SVector3> &m) const
{
  std::map<MVertex*,SVector3>::const_iterator it = m.find(v);
  if (it != m.end()){
    v->x() = it->second.x();
    v->y() = it->second.y();
    v->z() = it->second.z();
  }
} 

void gmshHighOrderSmoother::moveToStraightSidedLocation (MVertex *v) const
{
  moveTo ( v, _straightSidedLocation);
}

void gmshHighOrderSmoother::moveToTargetLocation (MVertex *v) const
{
  moveTo ( v, _targetLocation);
}

void gmshHighOrderSmoother::moveToStraightSidedLocation (MElement *e) const
{
  for (int i=0;i<e->getNumVertices();i++)
    moveToStraightSidedLocation(e->getVertex(i));
}

void gmshHighOrderSmoother::moveToTargetLocation (MElement *e) const
{
  for (int i=0;i<e->getNumVertices();i++)
    moveToTargetLocation(e->getVertex(i));
}

void gmshHighOrderSmoother::updateTargetLocation (MVertex*v, const SPoint3 &p3, const SPoint2 &p2)
{
  v->x() = p3.x();
  v->y() = p3.y();
  v->z() = p3.z();
  v->setParameter(0,p2.x());
  v->setParameter(1,p2.y());
  _targetLocation[v] = SVector3(p3.x(),p3.y(),p3.z());
}


struct p2data{
  GFace *gf;
  MTriangle *t1,*t2;
  MVertex *n12;
  gmshMatrix<double> *m1,*m2;
  gmshHighOrderSmoother *s;
  p2data (GFace *_gf,MTriangle *_t1,MTriangle *_t2,MVertex *_n12,gmshHighOrderSmoother *_s)
    : gf(_gf),t1(_t1),t2(_t2),n12(_n12),s(_s){
    gmshElasticityTerm el(0,1.e3,.3333);
    s->moveToStraightSidedLocation(t1);
    s->moveToStraightSidedLocation(t2);
    m1 = new  gmshMatrix<double>(3*t1->getNumVertices(),
				 3*t1->getNumVertices());
    m2 = new  gmshMatrix<double>(3*t2->getNumVertices(),
				 3*t2->getNumVertices()); 
    el.elementMatrix(t1,*m1);
    el.elementMatrix(t2,*m2);
    s->moveToTargetLocation(t1);
    s->moveToTargetLocation(t2);
  }
  ~p2data(){
    delete m1;
    delete m2;
  }
};

struct pNdata{
  GFace *gf;
  MTriangle *t1,*t2;
  const std::vector<MVertex*> &n;
  gmshMatrix<double> *m1,*m2;
  gmshHighOrderSmoother *s;
  pNdata (GFace *_gf,MTriangle *_t1,MTriangle *_t2,const std::vector<MVertex*> &_n,gmshHighOrderSmoother *_s)
    : gf(_gf),t1(_t1),t2(_t2),n(_n),s(_s)
  {
    gmshElasticityTerm el(0,1.e3,.3333);
    s->moveToStraightSidedLocation(t1);
    s->moveToStraightSidedLocation(t2);
    m1 = new  gmshMatrix<double>(3*t1->getNumVertices(),
				 3*t1->getNumVertices());
    m2 = new  gmshMatrix<double>(3*t2->getNumVertices(),
				 3*t2->getNumVertices()); 
    el.elementMatrix(t1,*m1);
    el.elementMatrix(t2,*m2);
    s->moveToTargetLocation(t1);
    s->moveToTargetLocation(t2);
  }
  ~pNdata(){
    delete m1;
    delete m2;
  }
};


static double _DeformationEnergy (MElement *e, 
				  gmshMatrix<double> *K,
				  gmshHighOrderSmoother *s){

  int N = e->getNumVertices();
  gmshVector<double> Kdx(N*3),dx(N*3);

  dx.scale(0.0);
  Kdx.scale(0.0);
  int C = 0;
  for (int i=0;i<N;i++){
    SVector3 disp = s->getDisplacement(e->getVertex(i));
    SVector3 str  = s->getSSL(e->getVertex(i));
    dx(i)      = disp.x();
    dx(i+N)    = disp.y();
    dx(i+2*N)  = disp.z();
    if (0 && (fabs(disp.x())>1.e-12 ||fabs(disp.y())>1.e-12))
            printf("%6d (%12.5E %12.5E %12.5E -- %12.5E %12.5E %12.5E -- %12.5E %12.5E %12.5E)\n",
	       e->getVertex(i)->getNum(),
	       disp.x(),disp.y(),disp.z(),
	       str.x(),str.y(),str.z(),e->getVertex(i)->x(),e->getVertex(i)->y(),
	       e->getVertex(i)->z());
  }  

  K->mult(dx,Kdx);
  const double E = Kdx * dx;
  return E;
}

static double _DeformationEnergy (p2data *p){
  
  //  printf("DEFEN \n");

  return 
    _DeformationEnergy (p->t1,p->m1,p->s) + 
    _DeformationEnergy (p->t2,p->m2,p->s);
}

static double _DeformationEnergy (pNdata *p){

  return _DeformationEnergy (p->t1,p->m1,p->s) + 
    _DeformationEnergy (p->t2,p->m2,p->s);
}


static double _function_p2tB (gmshVector<double> &x, void *data){
  p2data *p = (p2data*)data;
  GPoint gp12 = p->gf->point(SPoint2(x(0),x(1)));
  double xx = p->n12->x();
  double yy = p->n12->y();
  double zz = p->n12->z();
  p->n12->x() = gp12.x();
  p->n12->y() = gp12.y();
  p->n12->z() = gp12.z();

  double E = _DeformationEnergy(p);
  //  printf("%12.5E %12.5E -- %12.5E %12.5E => %12.5E %12.5E E %12.5E\n",x(0),x(1),xx,yy,gp12.x(),gp12.y(),E);

  p->n12->x() = xx;
  p->n12->y() = yy;
  p->n12->z() = zz;  
  return E;
}



static double _function_p2t (gmshVector<double> &x, void *data){
  p2data *p = (p2data*)data;
  GPoint gp12 = p->gf->point(SPoint2(x(0),x(1)));
  //  printf("%g %g = %g %g\n",x(0),x(1),gp12.x(),gp12.y());
  double xx = p->n12->x();
  double yy = p->n12->y();
  double zz = p->n12->z();
  p->n12->x() = gp12.x();
  p->n12->y() = gp12.y();
  p->n12->z() = gp12.z();
  double q = std::min(shapeMeasure(p->t1),shapeMeasure(p->t2));      
  p->n12->x() = xx;
  p->n12->y() = yy;
  p->n12->z() = zz;  
  return -q;
}

static double _function_pNt (gmshVector<double> &x, void *data){
  pNdata *p = (pNdata*)data;
  static double xx[256];
  static double yy[256];
  static double zz[256];
  for (int i=0;i<p->n.size();i++){
    GPoint gp12 = p->gf->point(SPoint2(x(2*i),x(2*i+1)));
    //  printf("%g %g = %g %g\n",x(0),x(1),gp12.x(),gp12.y());
    xx[i] = p->n[i]->x();
    yy[i] = p->n[i]->y();
    zz[i] = p->n[i]->z();
    p->n[i]->x() = gp12.x();
    p->n[i]->y() = gp12.y();
    p->n[i]->z() = gp12.z();
  }
  double q = std::min(shapeMeasure(p->t1),shapeMeasure(p->t2));      
  for (int i=0;i<p->n.size();i++){
    p->n[i]->x() = xx[i];
    p->n[i]->y() = yy[i];
    p->n[i]->z() = zz[i];
  }  
  return -q;
}

static double _function_pNtB (gmshVector<double> &x, void *data){
  pNdata *p = (pNdata*)data;
  static double xx[256];
  static double yy[256];
  static double zz[256];
  for (int i=0;i<p->n.size();i++){
    GPoint gp12 = p->gf->point(SPoint2(x(2*i),x(2*i+1)));
    //  printf("%g %g = %g %g\n",x(0),x(1),gp12.x(),gp12.y());
    xx[i] = p->n[i]->x();
    yy[i] = p->n[i]->y();
    zz[i] = p->n[i]->z();
    p->n[i]->x() = gp12.x();
    p->n[i]->y() = gp12.y();
    p->n[i]->z() = gp12.z();
  }
  double E = _DeformationEnergy(p);
  for (int i=0;i<p->n.size();i++){
    p->n[i]->x() = xx[i];
    p->n[i]->y() = yy[i];
    p->n[i]->z() = zz[i];
  }  
  //  printf("E(%g,%g) = %g\n",x(0),x(1),E);
  return E;
}


void getDistordedElements(const std::vector<MElement*>  & v, 
                          const double & threshold,
                          std::vector<MElement*>  & d,
                          double &minD)
{
  d.clear();
  minD = 1;
  for (unsigned int i = 0; i < v.size(); i++){
    const double disto = v[i]->distoShapeMeasure();
    if (disto < threshold)
      d.push_back(v[i]);
    minD = std::min(minD, disto);
  }
}

void addOneLayer(const std::vector<MElement*>  & v, 
                 std::vector<MElement*>  & d ,
                 std::vector<MElement*>  & layer )
{
  std::set<MVertex*> all;
  for (unsigned int i = 0; i < d.size(); i++){
    MElement *e = d[i];
    int n = e->getNumPrimaryVertices();
    for (int j = 0; j < n; j++){
      all.insert(e->getVertex(j));
    }
  }

  layer.clear();

  std::sort(d.begin(), d.end());

  for (unsigned int i = 0; i < v.size(); i++){
    MElement *e = v[i];
    bool found = std::binary_search(d.begin(), d.end(), e);
    // element is not yet there
    if (!found){
      int n = e->getNumPrimaryVertices();
      for (int j = 0; j < n; j++){
	MVertex *vert = e->getVertex(j);
	if (all.find(vert) != all.end()){
	  layer.push_back(e);
	  j = n;
	}
      }
    }
  }
}

void gmshHighOrderSmoother::smooth(GFace *gf, bool metric)
{
  std::vector<MElement*> v;

  v.insert(v.begin(), gf->triangles.begin(),gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(),gf->quadrangles.end());
  Msg::Info("Smoothing high order mesh : model face %d (%d elements)", gf->tag(),
	    v.size());
  if (metric)smooth_metric(v,gf);
  else smooth(v);
}

void gmshHighOrderSmoother::smooth(GRegion *gr)
{
  std::vector<MElement*> v;
  v.insert(v.begin(), gr->tetrahedra.begin(),gr->tetrahedra.end());
  v.insert(v.begin(), gr->hexahedra.begin(),gr->hexahedra.end());
  v.insert(v.begin(), gr->prisms.begin(),gr->prisms.end());
  Msg::Info("Smoothing high order mesh : model region %d (%d elements)", gr->tag(),
	    v.size());
  smooth(v);
}

// Use elastic solver to move the nodes

// compute the stiffness matrix of an element
// that correspond to the deformation of a
// straight sided element to a curvilinear one





void gmshHighOrderSmoother::optimize(GFace * gf, 
				     edgeContainer &edgeVertices,
				     faceContainer &faceVertices){

  //  if (gf->geomType() != GEntity::Plane)return;

  while (1) {
    // relocate the vertices using elliptic smoother
    //    smooth(gf);
    //    for (int i=0;i<20;i++){
    //    _gmshFindOptimalLocationsPN(gf,this);
      //      _gmshFindOptimalLocationsPN(gf,this);
      //    }
    // then try to swap for better configurations  

    smooth(gf,true);
    int nbSwap = _gmshSwapHighOrderTriangles(gf,edgeVertices,faceVertices,this);
    //smooth(gf,true);
    //    smooth(gf,true);
    //    smooth(gf,true);
    //    smooth(gf,true);
    break;

    //    printf("%d %g\n",nbSwap,_MIDDLE);
    // if the smoothing procedure has been able to
    // move the nodes to their right location, break !
    //    break;
    if (_MIDDLE == 1.0) break;
    //    if (!nbSwap){
    //      printf("Cannot move thet nodes to their optimal location, splits have to be added\n");
    //      break;
    //    }
  }
}


void gmshHighOrderSmoother::computeMetricVector (GFace *gf, 
						 MElement *e, 
						 gmshMatrix<double> &J,
						 gmshMatrix<double> &JT,
						 gmshVector<double> &D){
  int nbNodes = e->getNumVertices();
  for (int j = 0; j < nbNodes; j++){
    SPoint2 param;
    reparamMeshVertexOnFace(e->getVertex(j), gf, param);  
    Pair<SVector3,SVector3> der = gf->firstDer(param);    
    int XJ = j;
    int YJ = j+nbNodes;
    int ZJ = j+2*nbNodes;
    int UJ = j;
    int VJ = j+nbNodes;
    J(XJ,UJ) = der.first().x();
    J(YJ,UJ) = der.first().y();
    J(ZJ,UJ) = der.first().z();
    J(XJ,VJ) = der.second().x();
    J(YJ,VJ) = der.second().y();
    J(ZJ,VJ) = der.second().z();
    
    JT(UJ,XJ) = der.first().x();
    JT(UJ,YJ) = der.first().y();
    JT(UJ,ZJ) = der.first().z();
    JT(VJ,XJ) = der.second().x();
    JT(VJ,YJ) = der.second().y();
    JT(VJ,ZJ) = der.second().z();

    GPoint gp = gf->point(param);    
    SVector3 ss = getSSL(e->getVertex(j));
    D(XJ) = gp.x() - ss.x();
    D(YJ) = gp.y() - ss.y();
    D(ZJ) = gp.z() - ss.z();
  } 
}


void gmshHighOrderSmoother::smooth_metric ( std::vector<MElement*>  & all, GFace *gf)
{
  gmshLinearSystemGmm<double> *lsys = new gmshLinearSystemGmm<double>;
  //  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(1.e-7);
  gmshAssembler<double> myAssembler(lsys);
  gmshElasticityTerm El(0, 1.0, .333, getTag());
  
  std::vector<MElement*> layer,v;

  double minD;

  getDistordedElements ( all, .6, v,minD);

  Msg::Debug("%d elements / %d distorted  min Disto = %g",all.size(),v.size(), minD);

  if (!v.size()) return;

  const int nbLayers = 2;
  for (int i=0;i<nbLayers;i++){
    addOneLayer ( all, v, layer);
    v.insert(v.end(),layer.begin(),layer.end());
  }

  // 3 -> .4
  Msg::Debug("%d elements after adding %d layers", (int)v.size(), nbLayers);

  addOneLayer(all, v, layer);

  //  printf("%d elements in the next layer\n",layer.size());

  std::set<MVertex*>::iterator it;
  std::map<MVertex*,SVector3>::iterator its;
  std::map<MVertex*,SVector3>::iterator itpresent;
  std::map<MVertex*,SVector3>::iterator ittarget;
  std::set<MVertex*> verticesToMove;


  for (unsigned int i = 0; i < layer.size(); i++){
    for (int j = 0; j < layer[i]->getNumVertices(); j++){
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex(vert, 0, getTag(), 0);
      myAssembler.fixVertex(vert, 1, getTag(), 0);
    }
  }

  //  printf("%d vertices \n", _displ.size());

  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      //      printf("%d %d %d v\n",i,j,v[i]->getNumVertices());
      its = _straightSidedLocation.find(vert);
      if (its == _straightSidedLocation.end()){
	_straightSidedLocation[vert] = 
	  SVector3(vert->x(),vert->y(),vert->z());     
	_targetLocation[vert] = 
	  SVector3(vert->x(),vert->y(),vert->z());     
      }
      else{
	vert->x() = its->second.x();
	vert->y() = its->second.y();
	vert->z() = its->second.z();
	if (vert->onWhat()->dim() < _dim){
	  myAssembler.fixVertex ( vert , 0 , getTag() , 0);
	  myAssembler.fixVertex ( vert , 1 , getTag() , 0);
	}
      }
    }
  }
  
  // number the other DOFs
  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex(vert, 0, getTag());
      myAssembler.numberVertex(vert, 1, getTag());
      verticesToMove.insert(vert);
    } 
  }

  
  double dx0 = smooth_metric_ ( v, gf, myAssembler, verticesToMove,El);
  double dx = dx0;
  //  printf(" dx0 = %12.5E\n",dx0);
  int iter = 0;
  while(1){
    double dx2 = smooth_metric_ ( v,gf, myAssembler, verticesToMove,El);
    //    printf(" dx2  = %12.5E\n",dx2);
    if (fabs(dx2-dx) < 1.e-4 * dx0)break;
    if (iter++ > 10)break;
    dx = dx2;
  }

  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    SPoint2 param;
    reparamMeshVertexOnFace(*it, gf, param);  
    GPoint gp = gf->point(param);    
    if ((*it)->onWhat()->dim() == 2){
      (*it)->x() = gp.x();
      (*it)->y() = gp.y();
      (*it)->z() = gp.z();
      _targetLocation[*it] = SVector3(gp.x(),gp.y(),gp.z());
    }
    else{
      SVector3 p =  _targetLocation[(*it)];
      (*it)->x() = p.x();
      (*it)->y() = p.y();
      (*it)->z() = p.z();      
    }
  }
  delete lsys;
}


double gmshHighOrderSmoother::smooth_metric_ ( std::vector<MElement*>  & v, 
					       GFace *gf, 
					       gmshAssembler<double> &myAssembler,
					       std::set<MVertex*> &verticesToMove,
					       gmshElasticityTerm &El)
{
  //  Msg::Info("%d vertices FIXED %d NUMBERED", myAssembler.sizeOfF()
  //	    , myAssembler.sizeOfR());

  std::set<MVertex*>::iterator it;

  if (myAssembler.sizeOfR()){

    for (int i=0;i<v.size();i++){
      MElement *e = v[i];            
      int nbNodes = e->getNumVertices();
      const int n2 = 2*nbNodes;
      const int n3 = 3*nbNodes;

      gmshMatrix<double> K33 (n3,n3);
      gmshMatrix<double> K22 (n2,n2);
      gmshMatrix<double> J32 (n3,n2);
      gmshMatrix<double> J23 (n2,n3);
      gmshVector<double> D3  (n3);
      gmshVector<double> R2  (n2);
      gmshMatrix<double> J23K33 (n2,n3);
      K33.set_all(0.0);
      El.elementMatrix(e,K33);
      computeMetricVector (gf,e,J32,J23,D3);
      J23K33.gemm(J23,K33,1,0);      
      K22.gemm(J23K33,J32,1,0);      
      J23K33.mult(D3,R2);
      for (int j = 0; j < n2; j++){
	MVertex *vR;
	int iCompR, iFieldR;
	El.getLocalDofR(e, j, &vR, &iCompR, &iFieldR);
	myAssembler.assemble(vR, iCompR, iFieldR,-R2(j));
	for (int k = 0; k < n2; k++){
	  MVertex *vC;
	  int iCompC, iFieldC;
	  El.getLocalDofC(e, k, &vC, &iCompC, &iFieldC);
	  myAssembler.assemble(vR, iCompR, iFieldR, 
			 vC, iCompC, iFieldC, 
			 K22(j, k));
	}
      }
    }
    // solve the system
    myAssembler.systemSolve();
  }
  

  double dx = 0.0;
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    if ((*it)->onWhat()->dim() == 2){
      SPoint2 param;
      reparamMeshVertexOnFace((*it), gf, param);  
      SPoint2 dparam (myAssembler.getDofValue ((*it), 0 ,getTag()),
		      myAssembler.getDofValue ((*it), 1 ,getTag()));
      SPoint2 newp = param+dparam;
      dx += newp.x()*newp.x()+newp.y()*newp.y();
      (*it)->setParameter(0,newp.x());
      (*it)->setParameter(1,newp.y());
    }
  }
  
  myAssembler.systemClear();
  
  return dx;
}


void gmshHighOrderSmoother::smooth ( std::vector<MElement*>  & all)
{
  gmshLinearSystemGmm<double> *lsys = new gmshLinearSystemGmm<double>;
  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(1.e-5);
  gmshAssembler<double> myAssembler(lsys);
  gmshElasticityTerm El(0, 1.0, .333, getTag());
  
  std::vector<MElement*> layer,v;

  double minD;

  getDistordedElements ( all, .5, v,minD);

  Msg::Debug("%d elements / %d distorted  min Disto = %g\n",all.size(),v.size(), minD);

  if (!v.size()) return;

  const int nbLayers = 2;
  for (int i=0;i<nbLayers;i++){
    addOneLayer ( all, v, layer);
    v.insert(v.end(),layer.begin(),layer.end());
  }

  // 3 -> .4
  Msg::Debug("%d elements after adding %d layers\n", (int)v.size(), nbLayers);

  addOneLayer(all, v, layer);

  //  printf("%d elements in the next layer\n",layer.size());

  for (unsigned int i = 0; i < layer.size(); i++){
    for (int j = 0; j < layer[i]->getNumVertices(); j++){
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex(vert, 0, getTag(), 0);
      myAssembler.fixVertex(vert, 1, getTag(), 0);
      myAssembler.fixVertex(vert, 2, getTag(), 0);
    }
  }

  std::map<MVertex*,SVector3>::iterator it;
  std::map<MVertex*,SVector3>::iterator its;
  std::map<MVertex*,SVector3>::iterator itt;
  std::map<MVertex*,SVector3> verticesToMove;

  //  printf("%d vertices \n", _displ.size());

  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      //      printf("%d %d %d v\n",i,j,v[i]->getNumVertices());
      its = _straightSidedLocation.find(vert);
      itt = _targetLocation.find(vert);
      if (its != _straightSidedLocation.end() && vert->onWhat()->dim() < _dim){
	myAssembler.fixVertex ( vert , 0 , getTag() , vert->x()-its->second.x());
	myAssembler.fixVertex ( vert , 1 , getTag() , vert->y()-its->second.y());
	myAssembler.fixVertex ( vert , 2 , getTag() , vert->z()-its->second.z());
      }
      // ensure we do not touch any vertex that is on the boundary
      else if (vert->onWhat()->dim() < _dim){
	myAssembler.fixVertex ( vert , 0 , getTag() , 0);
	myAssembler.fixVertex ( vert , 1 , getTag() , 0);
	myAssembler.fixVertex ( vert , 2 , getTag() , 0);
      }
    }
  }

  for (unsigned int i = 0; i < v.size(); i++)
    moveToStraightSidedLocation (v[i]);    
  
  // number the other DOFs
  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex(vert, 0, getTag());
      myAssembler.numberVertex(vert, 1, getTag());
      myAssembler.numberVertex(vert, 2, getTag());
      // gather all vertices that are supposed to move
      verticesToMove[vert] = SVector3(0.0,0.0,0.0);
    } 
  }

  //  Msg::Info("%d vertices FIXED %d NUMBERED", myAssembler.sizeOfF()
  //	    , myAssembler.sizeOfR());

  if (myAssembler.sizeOfR()){

    // assembly of the elasticity term on the
    // set of elements
    El.addToMatrix(myAssembler,v); 
    
    // solve the system
    lsys->systemSolve();
  }
  
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() += myAssembler.getDofValue (it->first, 0 ,getTag());  
    it->first->y() += myAssembler.getDofValue (it->first, 1 ,getTag());  
    it->first->z() += myAssembler.getDofValue (it->first, 2 ,getTag());  
  }

  // delete matrices and vectors
  
  delete lsys;
}

/*
  n3    n23     n2
  x-----x-------x
  |            /|
  |    t1    /  |
  |        /    |
  x n13  x n12  x n24
  |    /        |
  |  /    t2    |
  |/            |
  x------x------x
  n1    n14     n4
*/

/*
  n34 is the new vertex, we'd like to put it at the 
  best place i.e. at a place where it maximizes the 
  minimal smoothness of the neighboring elements.

  One can actually maximize this value or one can use
  a standard interpolation scheme (transfinite or elliptic)
  to place the point.
*/


static void getNodesP2 (const MEdge &me, MTriangle *t1, MTriangle *t2,
			MVertex * &n1,MVertex * &n2,MVertex * &n3,MVertex * &n4,
			MVertex * &n12,MVertex * &n14,MVertex * &n24,MVertex * &n23,MVertex * &n13){

  n1 = me.getVertex(0);
  n2 = me.getVertex(1);    
  
  if (t1->getVertex(0) != n1 && t1->getVertex(0) != n2) n3 = t1->getVertex(0);
  else if (t1->getVertex(1) != n1 && t1->getVertex(1) != n2) n3 = t1->getVertex(1);
  else if (t1->getVertex(2) != n1 && t1->getVertex(2) != n2) n3 = t1->getVertex(2);
  int iStart = 0;
  for (;iStart<3;iStart++)
    if (t1->getVertex(iStart) == n1)
      break;
  if (n2 == t1->getVertex((iStart+1)%3)){
    n12 = t1->getVertex((iStart+0)%3 + 3);
    n23 = t1->getVertex((iStart+1)%3 + 3);
    n13 = t1->getVertex((iStart+2)%3 + 3);
  }
  else{
    n13 = t1->getVertex((iStart+0)%3 + 3);
    n23 = t1->getVertex((iStart+1)%3 + 3);
    n12 = t1->getVertex((iStart+2)%3 + 3);
  }
  
  if (t2->getVertex(0) != n1 && t2->getVertex(0) != n2) n4 = t2->getVertex(0);
  else if (t2->getVertex(1) != n1 && t2->getVertex(1) != n2) n4 = t2->getVertex(1);
  else if (t2->getVertex(2) != n1 && t2->getVertex(2) != n2) n4 = t2->getVertex(2);
  iStart = 0;
  for (;iStart<3;iStart++)
    if (t2->getVertex(iStart) == n1)
      break;
  if (n2 == t2->getVertex((iStart+1)%3)){
    n24 = t2->getVertex((iStart+1)%3 + 3);
    n14 = t2->getVertex((iStart+2)%3 + 3);
  }
  else{
    n14 = t2->getVertex((iStart+0)%3 + 3);
    n24 = t2->getVertex((iStart+1)%3 + 3);
  }
}

static void getNodesPN (const MEdge &me, MTriangle *t1, MTriangle *t2,
			MVertex * &n1,MVertex * &n2,MVertex * &n3,MVertex * &n4,
			std::vector<MVertex *> &n12,
			std::vector<MVertex *> &n14,
			std::vector<MVertex *> &n24,
			std::vector<MVertex *> &n23,
			std::vector<MVertex *> &n13){

  n1 = me.getVertex(0);
  n2 = me.getVertex(1);    
  
  int order = t1->getPolynomialOrder();

  if (t1->getVertex(0) != n1 && t1->getVertex(0) != n2) n3 = t1->getVertex(0);
  else if (t1->getVertex(1) != n1 && t1->getVertex(1) != n2) n3 = t1->getVertex(1);
  else if (t1->getVertex(2) != n1 && t1->getVertex(2) != n2) n3 = t1->getVertex(2);
  int iStart = 0;
  for (;iStart<3;iStart++)
    if (t1->getVertex(iStart) == n1)
      break;
  if (n2 == t1->getVertex((iStart+1)%3)){
    int start12 = 3 + ((iStart+0)%3) * (order-1);
    for (int i=0;i<order-1;i++)n12.push_back(t1->getVertex(start12+i));
    int start23 = 3 + ((iStart+1)%3) * (order-1);
    for (int i=0;i<order-1;i++)n23.push_back(t1->getVertex(start23+i));
    int start13 = 3 + ((iStart+2)%3) * (order-1);
    for (int i=0;i<order-1;i++)n13.push_back(t1->getVertex(start13+i));
  }
  else{
    int start13 = 3 + ((iStart+0)%3) * (order-1);
    for (int i=order-2;i>=0;i--)n13.push_back(t1->getVertex(start13+i));
    int start23 = 3 + ((iStart+1)%3) * (order-1);
    for (int i=order-2;i>=0;i--)n23.push_back(t1->getVertex(start23+i));
    int start12 = 3 + ((iStart+2)%3) * (order-1);
    for (int i=order-2;i>=0;i--)n12.push_back(t1->getVertex(start12+i));
  }
  
  if (t2->getVertex(0) != n1 && t2->getVertex(0) != n2) n4 = t2->getVertex(0);
  else if (t2->getVertex(1) != n1 && t2->getVertex(1) != n2) n4 = t2->getVertex(1);
  else if (t2->getVertex(2) != n1 && t2->getVertex(2) != n2) n4 = t2->getVertex(2);
  iStart = 0;
  for (;iStart<3;iStart++)
    if (t2->getVertex(iStart) == n1)
      break;

  if (n2 == t2->getVertex((iStart+1)%3)){
    int start24 = 3 + ((iStart+1)%3) * (order-1);
    for (int i=0;i<order-1;i++)n24.push_back(t2->getVertex(start24+i));
    int start14 = 3 + ((iStart+2)%3) * (order-1);
    for (int i=0;i<order-1;i++)n14.push_back(t2->getVertex(start14+i));
  }
  else{
    int start14 = 3 + ((iStart+0)%3) * (order-1);
    for (int i=order-2;i>=0;i--)n14.push_back(t1->getVertex(start14+i));
    int start24 = 3 + ((iStart+1)%3) * (order-1);
    for (int i=order-2;i>=0;i--)n24.push_back(t1->getVertex(start24+i));
  }
}



static double surfaceTriangleUV(SPoint2 &v1, SPoint2 &v2, SPoint2 &v3)           
{
  const double v12[2] = {v2.x() - v1.x(),v2.y() - v1.y()};
  const double v13[2] = {v3.x() - v1.x(),v3.y() - v1.y()};
  return 0.5 * fabs (v12[0] * v13[1] - v12[1] * v13[0]);
}

struct swap_triangles_p2
{
  MTriangle *t1, *t2;
  MTriangle *t3, *t4;
  double quality_old;
  double quality_new;
  double s_before,s_after;
  MVertex *n1, *n2, *n3, *n4;
  MVertex *n12, *n13, *n23, *n14, *n24;
  MVertex *n34;


  double evalConfiguration (GFace *gf, SPoint2 & p) const {
    GPoint gp34 = gf->point(p);
    MFaceVertex _test (gp34.x(),gp34.y(),gp34.z(),gf,p.x(),p.y());        
    std::vector<MVertex *>vv;
    vv.push_back(n13);vv.push_back(&_test);vv.push_back(n14);
    MTriangleN t3_test (n1,n3,n4,vv,2,t1->getNum(),t1->getPartition());
    vv.clear();
    vv.push_back(&_test);vv.push_back(n23);vv.push_back(n24);
    MTriangleN t4_test (n4,n3,n2,vv,2,t2->getNum(),t2->getPartition());
    const double q3 = shapeMeasure(&t3_test);
    const double q4 = shapeMeasure(&t4_test);
    return std::min(q3,q4);
  }

  MVertex *optimalLocation (GFace *gf, 
			    SPoint2 &p3,
			    SPoint2 &p4) const {
    SPoint2 p34_linear = (p3+p4)*.5;
    
    
    GPoint gp34 = gf->point(p34_linear);
    MFaceVertex *_test = new MFaceVertex (gp34.x(),gp34.y(),gp34.z(),
					  gf,p34_linear.x(),p34_linear.y());        
    std::vector<MVertex *>vv;
    vv.push_back(n13);vv.push_back(_test);vv.push_back(n14);
    MTriangleN t3_test (n1,n3,n4,vv,2,t1->getNum(),t1->getPartition());
    vv.clear();
    vv.push_back(_test);vv.push_back(n23);vv.push_back(n24);
    MTriangleN t4_test (n4,n3,n2,vv,2,t2->getNum(),t2->getPartition());
    p2data data(gf,&t3_test,&t4_test,_test,0);
    gmshVector<double> pp(2);
    pp(0) = p34_linear.x();
    pp(1) = p34_linear.y();
    double opti = minimize_grad_fd (_function_p2tB, pp, &data);
    return _test;
  }


  swap_triangles_p2(const MEdge &me, MTriangle *_t1, MTriangle *_t2, GFace *gf)
    : t1(_t1), t2(_t2),n1(0),n2(0),n3(0),n12(0),n13(0), n23(0), n14(0), n24(0),n34(0)
  {
    
    const double qold1 = shapeMeasure(t1);
    const double qold2 = shapeMeasure(t2);

    //printf("%p %p %p %p %p %p %p %p %p\n",n1,n2,n3,n4,n12,n23,n13,n24,n14);
    getNodesP2 (me,t1,t2,n1,n2,n3,n4,n12,n14,n24,n23,n13);
    SPoint2 p1,p2,p3,p4,p13,p24,p23,p14;
    reparamMeshEdgeOnFace(n1,n2,gf,p1,p2);
    reparamMeshEdgeOnFace(n3,n4,gf,p3,p4);
    reparamMeshEdgeOnFace(n13,n24,gf,p13,p24);
    reparamMeshEdgeOnFace(n23,n14,gf,p23,p14);

    s_before = surfaceTriangleUV(p1,p2,p4) + surfaceTriangleUV(p1,p2,p3);
    s_after =  surfaceTriangleUV(p3,p4,p1) + surfaceTriangleUV(p3,p4,p2);

    n34 = optimalLocation (gf,p3,p4);


    std::vector<MVertex *>vv;
    vv.push_back(n13);vv.push_back(n34);vv.push_back(n14);
    t3 = new MTriangleN (n1,n3,n4,vv,2,t1->getNum(),t1->getPartition());
    vv.clear();
    vv.push_back(n34);vv.push_back(n23);vv.push_back(n24);
    t4 = new MTriangleN (n4,n3,n2,vv,2,t2->getNum(),t2->getPartition());

    const double qnew1 = shapeMeasure(t3);
    const double qnew2 = shapeMeasure(t4);


    quality_new = std::min(qnew1,qnew2);
    quality_old = std::min(qold1,qold2);
    //    printf("old %g linear %g transfinite %g\n",quality_old,quality_new_linear,quality_new_transfinite);
  }
  bool operator < (const swap_triangles_p2 &other) const
  {
    return  other.quality_new - other.quality_old < quality_new - quality_old;
  }
  void print() const{
    printf("%g <--- %g\n",quality_new,quality_old);
    printf("%d %d %d %d %d %d\n",t1->getVertex(0)->getNum(),t1->getVertex(1)->getNum(),t1->getVertex(2)->getNum(),
	   t1->getVertex(3)->getNum(),t1->getVertex(4)->getNum(),t1->getVertex(5)->getNum());
    printf("%d %d %d %d %d %d\n",t2->getVertex(0)->getNum(),t2->getVertex(1)->getNum(),t2->getVertex(2)->getNum(),
	   t2->getVertex(3)->getNum(),t2->getVertex(4)->getNum(),t2->getVertex(5)->getNum());
    printf("%d %d %d %d %d %d\n",t3->getVertex(0)->getNum(),t3->getVertex(1)->getNum(),t3->getVertex(2)->getNum(),
	   t3->getVertex(3)->getNum(),t3->getVertex(4)->getNum(),t3->getVertex(5)->getNum());
    printf("%d %d %d %d %d %d\n",t4->getVertex(0)->getNum(),t4->getVertex(1)->getNum(),t4->getVertex(2)->getNum(),
	   t4->getVertex(3)->getNum(),t4->getVertex(4)->getNum(),t4->getVertex(5)->getNum());
    printf("%d %d %d %d %d %d %d %d %d\n",n1->getNum(),
    	   n2->getNum(),n3->getNum(),n4->getNum(),
	   n12->getNum(),n23->getNum(),n13->getNum(),n24->getNum(),n14->getNum());
  }
  
};

struct swap_triangles_pN
{
  MTriangle *t1, *t2;
  MTriangle *t3, *t4;
  double quality_old;
  double quality_new;
  double s_before,s_after;
  MVertex *n1, *n2, *n3, *n4;
  std::vector<MVertex*> n12, n13, n23, n14, n24, n34;
  std::vector<MVertex*> n123, n124, n134, n234;
  edgeContainer &edgeVertices;
  faceContainer &faceVertices;
  gmshHighOrderSmoother *s;

  swap_triangles_pN(const MEdge &me, MTriangle *_t1, MTriangle *_t2, GFace *gf,
		    edgeContainer &_edgeVertices,
		    faceContainer &_faceVertices,
		    gmshHighOrderSmoother *_s)
    : t1(_t1), t2(_t2),edgeVertices(_edgeVertices),faceVertices(_faceVertices),s(_s)
  {

    const double qold1 = shapeMeasure(t1);
    const double qold2 = shapeMeasure(t2);

    getNodesPN (me,t1,t2,n1,n2,n3,n4,n12,n14,n24,n23,n13);
    SPoint2 p1,p2,p3,p4,p13,p24,p23,p14;
    reparamMeshEdgeOnFace(n1,n2,gf,p1,p2);
    reparamMeshEdgeOnFace(n3,n4,gf,p3,p4);

    s_before = surfaceTriangleUV(p1,p2,p4) + surfaceTriangleUV(p1,p2,p3);
    s_after =  surfaceTriangleUV(p3,p4,p1) + surfaceTriangleUV(p3,p4,p2);

    MTriangle t3lin(n3,n4,n1);
    MTriangle t4lin(n4,n3,n2);

    t3 =  setHighOrder(&t3lin,gf,edgeVertices,faceVertices,false,
		       !t1->getNumFaceVertices(),
		       t1->getPolynomialOrder()-1,s);
    t4 =  setHighOrder(&t4lin,gf,edgeVertices,faceVertices,false,
		       !t1->getNumFaceVertices(),
		       t1->getPolynomialOrder()-1,s);
    
    optimalLocationPN_ (gf,me, t3, t4,s);
      
    const double qnew1 = shapeMeasure(t3);
    const double qnew2 = shapeMeasure(t4);

    quality_new = std::min(qnew1,qnew2);
    quality_old = std::min(qold1,qold2);

    //    if (quality_old < quality_new)
      printf("QUALITY GOING FROM %12.5E TO %12.5E\n",quality_old,quality_new);

  }
  bool operator < (const swap_triangles_pN &other) const
  {
    return  other.quality_new - other.quality_old < quality_new - quality_old;
  }
};



static int optimalLocationP2_ (GFace *gf, 
			       const MEdge &me,
			       MTriangle *t1, MTriangle *t2, 
			       gmshHighOrderSmoother *s){

  double qini = std::min(shapeMeasure(t1),shapeMeasure(t2));

  if (qini > 0.6) return 0;
  
  MVertex *n1,*n2,*n3,*n4,*n12,*n14,*n24,*n23,*n13;
  getNodesP2 (me,t1,t2,n1,n2,n3,n4,n12,n14,n24,n23,n13);
  SPoint2 p1,p2,p3,p4,p12;
  reparamMeshVertexOnFace(n12,gf,p12);
  reparamMeshEdgeOnFace(n3,n4,gf,p3,p4);
  reparamMeshEdgeOnFace(n3,n4,gf,p3,p4);
  SPoint2 p34_linear = (p1+p2)*.5;
  SPoint2 dirt = p4-p3;
  SPoint2 dirn = (-dirt.y(), dirt.x());

  gmshVector<double> pp(2);
  pp(0) = p12.x();
  pp(1) = p12.y();
  p2data data(gf,t1,t2,n12,s);

  double init = _DeformationEnergy (&data);
  double opti = minimize_grad_fd (_function_p2tB, pp, &data);

  printf("opti %g init %g\n",opti,init);

  if (init-opti < 1.e-5*(init))return 0;

  double u0 = gf->parBounds(0).low();
  double u1 = gf->parBounds(0).high();
  double v0 = gf->parBounds(1).low();
  double v1 = gf->parBounds(1).high();
  if (pp(0) < u0 || pp(0) > u1 || pp(1) < v0 || pp(1) > v1)return 0;   
  
  GPoint gp12 = gf->point(SPoint2(pp(0),pp(1)));
  n12->x() = gp12.x();
  n12->y() = gp12.y();
  n12->z() = gp12.z();
  n12->setParameter(0,pp(0));
  n12->setParameter(1,pp(1));      
  return 1;
}

int optimalLocationPN_ (GFace *gf, const MEdge &me, MTriangle *t1, MTriangle *t2,gmshHighOrderSmoother *s){
  // if quality is sufficient, do nothing (this is an expensive
  //  optimization process)
  double qopt = std::min(shapeMeasure(t1),shapeMeasure(t2));
  if (qopt > 0.6) return 0;
  // get the 2 end vertex of the edge
  MVertex *n1 = me.getVertex(0);
  MVertex *n2 = me.getVertex(1);
  // get all the other nodes that are on the edge
  int N = t1->getNumVertices();
  int NF = t1->getNumFaceVertices();
  int NE = t1->getNumEdgeVertices();
  std::vector<MVertex*> toOptimize;
  for (int i=3;i<3+NE;i++){
    MVertex *v1 = t1->getVertex(i);
    for (int j=3;j<3+NE;j++){
      MVertex *v2 = t2->getVertex(j);
      if (v1 == v2 && v1 != n1 && v1 != n2){
	toOptimize.push_back(v1);
	break;
      }
    }
  }
  

  for (int i=3+NE;i<N;i++){
    toOptimize.push_back(t1->getVertex(i));
    toOptimize.push_back(t2->getVertex(i));
  }

  gmshVector<double> pp(2*toOptimize.size());
  for (int i=0;i<toOptimize.size();i++){
    SPoint2 pt;
    reparamMeshVertexOnFace(toOptimize[i],gf,pt);
    pp(2*i)   = pt[0];
    pp(2*i+1) = pt[1];
  }

  pNdata data(gf,t1,t2,toOptimize,s);
  double init = _DeformationEnergy (&data);
  double opti = minimize_grad_fd (_function_pNtB, pp, &data);
  ///double opti = minimize_grad_fd (_function_pNt, pp, &data);
  if (init-opti < 1.e-5*(init))return 0;
  printf("Optimization has reduced the deformation energy %g -> %g\n",
	 init,opti);
  for (int i=0;i<toOptimize.size();i++){
    GPoint gp12 = gf->point(SPoint2(pp(2*i),pp(2*i+1)));
    toOptimize[i]->x() = gp12.x();
    toOptimize[i]->y() = gp12.y();
    toOptimize[i]->z() = gp12.z();
    toOptimize[i]->setParameter(0,pp(2*i));
    toOptimize[i]->setParameter(1,pp(2*i+1));
  }
  return 1;
}


static int _gmshFindOptimalLocationsP2(GFace *gf, gmshHighOrderSmoother *s)
{
  e2t_cont adj;
  buildEdgeToTriangle(gf->triangles, adj);
  int N=0;
  for (e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if (it->second.second)
      N += optimalLocationP2_(gf,it->first, dynamic_cast<MTriangle*>(it->second.first),
			      dynamic_cast<MTriangle*>(it->second.second),s);
  }
  return N;
}

static int _gmshFindOptimalLocationsPN(GFace *gf,gmshHighOrderSmoother *s)
{
  printf("coucou1\n");
  e2t_cont adj;
  buildEdgeToTriangle(gf->triangles, adj);
  int N=0;
  printf("coucou2\n");
  
  for (e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if (it->second.second)
      N += optimalLocationPN_(gf,it->first, dynamic_cast<MTriangle*>(it->second.first),
			      dynamic_cast<MTriangle*>(it->second.second),s);
  }
  printf("coucou3\n");
  return N;
}

static int _gmshSwapHighOrderTriangles(GFace *gf, 
				       edgeContainer &edgeVertices,
				       faceContainer &faceVertices,
				       gmshHighOrderSmoother *s)
{
  e2t_cont adj;
  buildEdgeToTriangle(gf->triangles, adj);

  std::set<swap_triangles_pN> pairs;

  for (e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if (it->second.second){
      MTriangle *t1 = dynamic_cast<MTriangle*>(it->second.first);
      MTriangle *t2 = dynamic_cast<MTriangle*>(it->second.second);
      const double qold1 = shapeMeasure(t1);
      const double qold2 = shapeMeasure(t2);

      //      printf("swap : %g %g\n",qold1,qold2);

      if (qold1 < 0.6 || qold2 < 0.6)
	pairs.insert(swap_triangles_pN(it->first,t1,t2,gf,
				       edgeVertices,faceVertices,s));
    }
  }
  std::set<swap_triangles_pN>::iterator itp = pairs.begin();

  int nbSwap = 0;

  std::set<MTriangle*> t_removed;
  std::set<MVertex*> v_removed;

  std::vector<MTriangle*> triangles2;
  std::vector<MVertex*> mesh_vertices2;

  itp = pairs.begin();
  while(itp != pairs.end()){
    double diff = fabs(itp->s_before - itp->s_after);
    if ( t_removed.find(itp->t1) == t_removed.end() &&
	 t_removed.find(itp->t2) == t_removed.end() &&
	 itp->quality_new > itp->quality_old &&
	 diff < 1.e-9){
      //      itp->print();
      t_removed.insert(itp->t1);
      t_removed.insert(itp->t2);
      triangles2.push_back(itp->t3);
      triangles2.push_back(itp->t4);
      //      if (itp->n34 != itp->n12){
	//	v_removed.insert(itp->n12);
	//	mesh_vertices2.push_back(itp->n34);
      //      }
      nbSwap++;
    }
    else{
      delete itp->t3;
      delete itp->t4;
      //      if (itp->n34 != itp->n12) delete itp->n34;
    }
    ++itp;
  }
  
  for (unsigned int i = 0; i < gf->triangles.size(); i++){
    if (t_removed.find(gf->triangles[i]) == t_removed.end()){
      triangles2.push_back(gf->triangles[i]);
    }
    else {
      delete gf->triangles[i];
    }    
  }
  //  printf("replacing %d by %d\n",gf->triangles.size(),triangles2.size());
  gf->triangles = triangles2;
  return nbSwap;
}

static int _gmshSwapHighOrderTriangles(GFace *gf)
{
  e2t_cont adj;
  buildEdgeToTriangle(gf->triangles, adj);

  std::set<swap_triangles_p2> pairs;

  for (e2t_cont::iterator it = adj.begin(); it!= adj.end(); ++it){
    if (it->second.second){
      MTriangle *t1 = dynamic_cast<MTriangle*>(it->second.first);
      MTriangle *t2 = dynamic_cast<MTriangle*>(it->second.second);
      const double qold1 = shapeMeasure(t1);
      const double qold2 = shapeMeasure(t2);
      if (qold1 < 0.6 || qold2 < 0.6)
	pairs.insert(swap_triangles_p2(it->first,t1,t2,gf));
    }
  }
  std::set<swap_triangles_p2>::iterator itp = pairs.begin();

  int nbSwap = 0;

  std::set<MTriangle*> t_removed;
  std::set<MVertex*> v_removed;

  std::vector<MTriangle*> triangles2;
  std::vector<MVertex*> mesh_vertices2;

  itp = pairs.begin();
  while(itp != pairs.end()){
    double diff = fabs(itp->s_before - itp->s_after);
    if ( t_removed.find(itp->t1) == t_removed.end() &&
	 t_removed.find(itp->t2) == t_removed.end() &&
	 itp->quality_new > itp->quality_old &&
	 diff < 1.e-9){
      //      itp->print();
      t_removed.insert(itp->t1);
      t_removed.insert(itp->t2);
      triangles2.push_back(itp->t3);
      triangles2.push_back(itp->t4);
      if (itp->n34 != itp->n12){
	v_removed.insert(itp->n12);
	mesh_vertices2.push_back(itp->n34);
      }
      nbSwap++;
    }
    else{
      delete itp->t3;
      delete itp->t4;
      if (itp->n34 != itp->n12) delete itp->n34;
    }
    ++itp;
  }
  
  
  for (unsigned int i = 0; i < gf->mesh_vertices.size(); i++){
    if (v_removed.find(gf->mesh_vertices[i]) == v_removed.end()){
      mesh_vertices2.push_back(gf->mesh_vertices[i]);
    }
    else {
      delete gf->mesh_vertices[i];
    }    
  }
  gf->mesh_vertices = mesh_vertices2;

  for (unsigned int i = 0; i < gf->triangles.size(); i++){
    if (t_removed.find(gf->triangles[i]) == t_removed.end()){
      triangles2.push_back(gf->triangles[i]);
    }
    else {
      delete gf->triangles[i];
    }    
  }
  //  printf("replacing %d by %d\n",gf->triangles.size(),triangles2.size());
  gf->triangles = triangles2;
  return nbSwap;
}

void  gmshHighOrderSmoother::swap(GFace *gf, 
				  edgeContainer &edgeVertices,
				  faceContainer &faceVertices){
  //  _gmshSwapHighOrderTriangles(gf);
  _gmshSwapHighOrderTriangles(gf,edgeVertices,faceVertices,this);
  //_gmshSwapHighOrderTriangles(gf);
  //_gmshSwapHighOrderTriangles(gf);
  //  _gmshSwapHighOrderTriangles(gf);
}

void  gmshHighOrderSmoother::smooth_p2point(GFace *gf){
  _gmshFindOptimalLocationsP2(gf,this);
  //_gmshFindOptimalLocationsP2(gf);
  //_gmshFindOptimalLocationsP2(gf);
}
void  gmshHighOrderSmoother::smooth_pNpoint(GFace *gf){
  _gmshFindOptimalLocationsPN(gf,this);
}


////////////////////////////////////////////////////////////////////////////////
// OLD STUFF : STILL USED ?
////////////////////////////////////////////////////////////////////////////////

bool straightLine(std::vector<MVertex*> &l, MVertex *n1, MVertex *n2)
{
  // x = a * t + b
  // x1 = b
  // x2 = a + b
  for(unsigned int i = 0; i < l.size(); i++){
    MVertex *v = l[i];
    double b = n1->x();
    double a = n2->x() - b;
    double t = (v->x() - b) / a;
    double by = n1->y();
    double ay = n2->y() - by;
    double y = ay * t + by;
    if(fabs(y-v->y()) > 1.e-07 * CTX::instance()->lc){
      return false;      
    }
  }
  return true;
}

void getMinMaxJac (MTriangle *t, double &minJ, double &maxJ)
{
  double mat[2][3];  
  int n = 3;
  t->getPrimaryJacobian(0, 0, 0, mat);
   //t->getJacobian(0, 0, 0, mat);
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3], normal[3];
  prodve(v1, v2, normal1);
  double nn = sqrt(SQU(normal1[0]) + SQU(normal1[1]) + SQU(normal1[2]));
  for(int i = 0; i < n; i++){
    for(int k = 0; k < n - i; k++){
      t->getJacobian((double)i / (n - 1), (double)k / (n - 1), 0, mat);
      double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
      double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
      prodve(v1b, v2b, normal);
      double sign; 
      prosca(normal1, normal, &sign);
      double det = norm3(normal) * (sign > 0 ? 1. : -1.) / nn;
      minJ = std::min(1. / det, std::min(det, minJ));
      maxJ = std::max(det, maxJ);
    }
  }
}

struct smoothVertexDataHO{
  MVertex *v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

struct smoothVertexDataHON{
  std::vector<MVertex*> v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

double smoothing_objective_function_HighOrder(double U, double V, MVertex *v, 
                                              std::vector<MTriangle*> &ts, GFace *gf)
{
  GPoint gp = gf->point(U, V);
  const double oldX = v->x();
  const double oldY = v->y();
  const double oldZ = v->z();

  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();

  double minJ =  1.e22;
  double maxJ = -1.e22;
  for (unsigned int i = 0; i < ts.size(); i++){
    getMinMaxJac (ts[i], minJ, maxJ);
  }
  v->x() = oldX;
  v->y() = oldY;
  v->z() = oldZ;
  
  return -minJ;
}


void deriv_smoothing_objective_function_HighOrder(double U, double V, 
                                                  double &F, double &dFdU,
                                                  double &dFdV, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  MVertex *v = svd->v;
  const double LARGE = -1.e5;
  const double SMALL = 1./LARGE;
  F   = smoothing_objective_function_HighOrder(U, V, v, svd->ts, svd->gf);
  double F_U = smoothing_objective_function_HighOrder(U + SMALL, V, v, svd->ts, svd->gf);
  double F_V = smoothing_objective_function_HighOrder(U, V + SMALL, v, svd->ts, svd->gf);
  dFdU = (F_U - F) * LARGE;
  dFdV = (F_V - F) * LARGE;
}

double smooth_obj_HighOrder(double U, double V, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  return  smoothing_objective_function_HighOrder(U, V, svd->v, svd->ts, svd->gf); 
}

double smooth_obj_HighOrderN(double *uv, void *data)
{
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  double oldX[10],oldY[10],oldZ[10];
  for (unsigned int i = 0; i < svd->v.size(); i++){
    GPoint gp = svd->gf->point(uv[2 * i], uv[2 * i + 1]);
    oldX[i] = svd->v[i]->x();
    oldY[i] = svd->v[i]->y();
    oldZ[i] = svd->v[i]->z();
    svd->v[i]->x() = gp.x();
    svd->v[i]->y() = gp.y();
    svd->v[i]->z() = gp.z();
  }
  double minJ =  1.e22;
  double maxJ = -1.e22;
  for(unsigned int i = 0; i < svd->ts.size(); i++){
    getMinMaxJac (svd->ts[i], minJ, maxJ);
  }
  for(unsigned int i = 0; i < svd->v.size(); i++){
    svd->v[i]->x() = oldX[i];
    svd->v[i]->y() = oldY[i];
    svd->v[i]->z() = oldZ[i];
  }
  return -minJ;
}

void deriv_smoothing_objective_function_HighOrderN(double *uv, double *dF, 
                                                   double &F, void *data)
{
  const double LARGE = -1.e2;
  const double SMALL = 1. / LARGE;
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  F = smooth_obj_HighOrderN(uv, data);
  for (unsigned int i = 0; i < svd->v.size(); i++){
    uv[i] += SMALL;
    dF[i] = (smooth_obj_HighOrderN(uv, data) - F) * LARGE;
    uv[i] -= SMALL;
  }
}

void optimizeNodeLocations(GFace *gf, smoothVertexDataHON &vdN, double eps = .2)
{
  if(!vdN.v.size()) return;
  double uv[20];
  for (unsigned int i = 0; i < vdN.v.size(); i++){
    if (!vdN.v[i]->getParameter(0, uv[2 * i])){
      Msg::Error("Node location optimization failed");
      return;
    }
    if (!vdN.v[i]->getParameter(1, uv[2 * i + 1])){
      Msg::Error("Node location optimization failed");
      return;
    }
  }

  double F = -smooth_obj_HighOrderN(uv, &vdN);
  if (F < eps){
    double val = 0.;
    Msg::Error("Fletcher-Reeves minimizer routine must be reimplemented");
    //minimize_N(2 * vdN.v.size(), smooth_obj_HighOrderN, 
    //          deriv_smoothing_objective_function_HighOrderN, 
    //          &vdN, 1, uv, val);
    double Fafter = -smooth_obj_HighOrderN(uv, &vdN);
    printf("%12.5E %12.5E\n", F, Fafter);
    if (F < Fafter){
      for (unsigned int i = 0; i < vdN.v.size(); i++){
        vdN.v[i]->setParameter(0, uv[2 * i]);
        vdN.v[i]->setParameter(1, uv[2 * i + 1]);
        GPoint gp = gf->point(uv[2 * i], uv[2 * i + 1]);
        vdN.v[i]->x() = gp.x();
        vdN.v[i]->y() = gp.y();
        vdN.v[i]->z() = gp.z();
      }
    }     
  }
}

double angle3Points(MVertex *p1, MVertex *p2, MVertex *p3)
{
  SVector3 a(p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z());
  SVector3 b(p3->x() - p2->x(), p3->y() - p2->y(), p3->z() - p2->z());
  SVector3 c = crossprod(a, b);
  double sinA = c.norm();
  double cosA = dot(a, b);
  //  printf("%d %d %d -> %g %g\n",p1->iD,p2->iD,p3->iD,cosA,sinA);
  return atan2 (sinA, cosA);  
}

// A curvilinear edge smooth and swap

typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;

void localHarmonicMapping(GModel *gm, 
			  MTriangle *t1 , 
			  MTriangle *t2,
			  MVertex *n1,
			  MVertex *n2,
			  MVertex *n3,
			  MVertex *n4,
// 			  SPoint2 &np1,
// 			  SPoint2 &np2,
// 			  SPoint2 &np3,
// 			  SPoint2 &np4,
			  std::vector<MVertex*> &e1,
			  std::vector<MVertex*> &e2,
			  std::vector<MVertex*> &e3,
			  std::vector<MVertex*> &e4,
// 			  std::vector<SPoint2> &ep1,
// 			  std::vector<SPoint2> &ep2,
// 			  std::vector<SPoint2> &ep3,
// 			  std::vector<SPoint2> &ep4
			  std::vector<MVertex*> &e) {
  
  gmshLinearSystemGmm<double> *lsys = new gmshLinearSystemGmm<double>;
  gmshAssembler<double> myAssembler(lsys);
  gmshFunction<double> f(1.0);
  gmshLaplaceTerm Laplace(gm, &f, 0);
  
  myAssembler.fixVertex ( n1 , 0 , 0 , -1.0);
  myAssembler.fixVertex ( n2 , 0 , 0 , -1.0);
  myAssembler.fixVertex ( n3 , 0 , 0 ,  1.0);
  myAssembler.fixVertex ( n4 , 0 , 0 ,  1.0);
  for (unsigned int i = 0; i < e1.size(); i++) myAssembler.fixVertex(e1[i], 0, 0, -1.0);
  for (unsigned int i = 0; i < e3.size(); i++) myAssembler.fixVertex(e3[i], 0, 0,  1.0);
  Laplace.addToMatrix(myAssembler,t1); 
  Laplace.addToMatrix(myAssembler,t2);   
  lsys->systemSolve();

  gmshLinearSystemGmm<double> *lsys1 = new gmshLinearSystemGmm<double>;
  gmshAssembler<double> myAssembler1(lsys1);
  gmshLaplaceTerm Laplace1(gm, &f, 1);
  
  myAssembler1.fixVertex ( n2 , 0 , 1 , -1.0);
  myAssembler1.fixVertex ( n3 , 0 , 1 , -1.0);
  myAssembler1.fixVertex ( n4 , 0 , 1 ,  1.0);
  myAssembler1.fixVertex ( n1 , 0 , 1 ,  1.0);
  for (unsigned int i = 0; i < e2.size(); i++) myAssembler1.fixVertex(e2[i], 0, 1, -1.0);
  for (unsigned int i = 0; i < e4.size(); i++) myAssembler1.fixVertex(e4[i], 0, 1,  1.0);  
  Laplace1.addToMatrix(myAssembler1,t1); 
  Laplace1.addToMatrix(myAssembler1,t2);   
  lsys1->systemSolve();

  // now we have the stable high order harmonic mapping 
  // we have to find points locations of vertices in e
  // that have coordinates (\xi, \xi) 

  // this can be done by evaluating the 

  for (unsigned int i = 0; i < e.size();  i++){
    MVertex *v = e[i];
    const double U =  myAssembler.getDofValue  (v, 0 ,0);
    const double V =  myAssembler1.getDofValue (v, 0 ,1);
    printf("point %g %g -> %g %g\n",v->x(),v->y(),U,V);
    // we are in t1
    if (U >= V){
      const double ut = U;
    }
  }


  delete lsys ;  
  delete lsys1;  
}

void optimizeHighOrderMeshInternalNodes(GFace *gf)
{
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    smoothVertexDataHON vdN;
    int start = t->getNumVertices() - t->getNumFaceVertices();
    for (int j=start;j<t->getNumVertices();j++)
      vdN.v.push_back(t->getVertex(j));
    vdN.gf = gf;
    vdN.ts.push_back(t);
    optimizeNodeLocations(gf, vdN, .9);
  }
}

bool optimizeHighOrderMesh(GFace *gf, edgeContainer &edgeVertices)
{
  v2t_cont adjv;
  buildVertexToTriangle(gf->triangles, adjv);

  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      if(n2 < n4)
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n4)];
      else
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n2)];

      if (e.size() < 5){
        smoothVertexDataHON vdN;
        vdN.v = e;
        vdN.gf = gf;
        vdN.ts.clear();
        vdN.ts.push_back(t1);
        vdN.ts.push_back(t2);   
        optimizeNodeLocations(gf, vdN);
      }
    }
  }

  return true;
}

static void parametricCoordinates(MVertex *v, GFace *gf, double &uu, double &vv)
{
  SPoint2 param;
  reparamMeshVertexOnFace(v, gf, param);
  uu = param[0];
  vv = param[1];
}

static void getParametricCoordnates ( GFace *gf, 
                                      std::vector<MVertex*> &e,
                                      std::vector<SPoint2> &param)
{
  param.clear();
  for (unsigned int i = 0; i < e.size(); i++){
    double U,V;
    parametricCoordinates(e[i] , gf, U, V); 
    param.push_back(SPoint2(U,V));
  }
}

static void curvilinearEdgeSwap (GFace *gf, 
				 //				 int nPts,
				 edgeContainer &edgeVertices,
				 edge2tris::iterator &it,
				 edge2tris &e2t)
{
  std::pair<MVertex*, MVertex*> edge = it->first;
  std::vector<MElement*> triangles   = it->second;
  if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      std::vector<MVertex*> e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n1, n2),std::max(n1, n2))];
      std::vector<MVertex*> e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n2, n3),std::max(n2, n3))];
      std::vector<MVertex*> e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n3, n4),std::max(n3, n4))];
      std::vector<MVertex*> e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n4, n1),std::max(n4, n1))];
      std::vector<MVertex*> e  = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n2, n4),std::max(n2, n4))];
      //      std::vector<MVertex*> enew; 
      //      MLine temp (n1,n3);
      // should not add the nodes n the GFace here
      //      getEdgeVertices(gf,&temp, enew, false, nPts);
      // get the parametric coordinates of the 
      std::vector<SPoint2> ep1;  getParametricCoordnates (gf,e1,ep1);
      std::vector<SPoint2> ep2;  getParametricCoordnates (gf,e2,ep2);
      std::vector<SPoint2> ep3;  getParametricCoordnates (gf,e3,ep3);
      std::vector<SPoint2> ep4;  getParametricCoordnates (gf,e4,ep4);
      std::vector<SPoint2> ep;  getParametricCoordnates (gf,e ,ep );
      //      std::vector<SPoint2> epnew;  getParametricCoordnates (gf,enew,epnew);      
      localHarmonicMapping(gf->model(),t1,t2,n1,n2,n3,n4,e1,e2,e3,e4,e); 
  }
}

bool smoothInternalEdgesb(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    curvilinearEdgeSwap (gf,edgeVertices,it,e2t);
  }
  return true;
}

bool smoothInternalEdges(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  bool success = false;

  const int NBST = 10;

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e1, e2, e3, e4, e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      
      double ang1 = angle3Points(n1,n2,n3);
      double ang2 = angle3Points(n2,n3,n4);
      double ang3 = angle3Points(n3,n4,n1);
      double ang4 = angle3Points(n4,n1,n2);
      const double angleLimit = 3*M_PI/4.;

      if (ang1 < angleLimit && ang2 < angleLimit && ang3 < angleLimit && ang4 < angleLimit){
	if(n1 < n2)
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n2)];
	else
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n1)];
	if(n2 < n3)
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n3)];
	else
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n2)];
	if(n3 < n4)
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n4)];
	else
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n3)];
	if(n4 < n1)
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n1)];
	else
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n4)];
	if(n2 < n4)
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n4)];
	else
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n2)];
	
	if((!straightLine(e1, n1, n2) || !straightLine(e2, n2, n3) ||
	    !straightLine(e3, n3, n4) || !straightLine(e4, n4, n1))){
	  
	  double Unew[NBST][10],Vnew[NBST][10];
	  double Xold[10],Yold[10],Zold[10];
	  
	  for(unsigned int i = 0; i < e.size(); i++){
	    Xold[i] = e[i]->x();
	    Yold[i] = e[i]->y();
	    Zold[i] = e[i]->z();
	  }
	  
	  double minJ = 1.e22;
	  double maxJ = -1.e22;       
	  getMinMaxJac (t1, minJ, maxJ);
	  getMinMaxJac (t2, minJ, maxJ);
	  int kopt = -1; 
	  for (int k=0;k<NBST;k++){
	    double relax = (k+1)/(double)NBST;
	    for(unsigned int i = 0; i < e.size(); i++){
	      double v = (double)(i + 1) / (e.size() + 1);
	      double u = 1. - v;
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      MVertex *vert1 = (n1 < n2) ? e1[e1.size() - i - 1] : e1[i];
	      MVertex *vert3 = (n3 < n4) ? e3[i] : e3[e3.size() - i - 1];
	      MVertex *vert4 = (n4 < n1) ? e4[e4.size() - i - 1] : e4[i];
	      MVertex *vert2 = (n2 < n3) ? e2[i] : e2[e2.size() - i - 1];	    
	      double U1,V1,U2,V2,U3,V3,U4,V4,U,V,nU1,nV1,nU2,nV2,nU3,nV3,nU4,nV4;
	      parametricCoordinates(vert , gf, U, V);
	      parametricCoordinates(vert1, gf, U1, V1);
	      parametricCoordinates(vert2, gf, U2, V2);
	      parametricCoordinates(vert3, gf, U3, V3);
	      parametricCoordinates(vert4, gf, U4, V4);
	      parametricCoordinates(n1, gf, nU1, nV1);
	      parametricCoordinates(n2, gf, nU2, nV2);
	      parametricCoordinates(n3, gf, nU3, nV3);
	      parametricCoordinates(n4, gf, nU4, nV4);
	      
	      Unew[k][i] = U + relax * ((1.-u) * U4 + u * U2 +
					(1.-v) * U1 + v * U3 -
					((1.-u)*(1.-v) * nU1 
					 + u * (1.-v) * nU2 
					 + u * v * nU3 
					 + (1.-u) * v * nU4) - U);
	      Vnew[k][i] = V + relax * ((1.-u) * V4 + u * V2 +
					(1.-v) * V1 + v * V3 -
					((1.-u)*(1.-v) * nV1 
					 + u * (1.-v) * nV2 
					 + u * v * nV3 
					 + (1.-u) * v * nV4) - V);
	      GPoint gp = gf->point(Unew[k][i],Vnew[k][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }
	    double minJloc = 1.e22;
	    double maxJloc = -1.e22;          
	    getMinMaxJac(t1, minJloc, maxJloc);
	    getMinMaxJac(t2, minJloc, maxJloc);
	    //	  printf("relax = %g min %g max %g\n",relax,minJloc,maxJloc);
	    
	    if (minJloc > minJ){
	      kopt = k;
	      minJ = minJloc;
	    }
	  }
	  //	kopt = 1;
	  if (kopt == -1){
	    for(unsigned int i = 0; i < e.size(); i++){
	      e[i]->x() = Xold[i];
	      e[i]->y() = Yold[i];
	      e[i]->z() = Zold[i];
	    }      
	  }
	  else{
	    success = true;
	    for(unsigned int i = 0; i < e.size(); i++){
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      vert->setParameter(0,Unew[kopt][i]);
	      vert->setParameter(1,Vnew[kopt][i]);
	      GPoint gp = gf->point(Unew[kopt][i],Vnew[kopt][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }      
	  }
	}
      }
    }
  }    
  return success;
}

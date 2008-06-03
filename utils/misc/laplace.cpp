#include <stdio.h>
#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/GmshMatrix.h>
class gLevelset;
#ifdef HAVE_GLEVELSETS
#include <Levelset.h>
#include <Integration3D.h>
#endif

// My First test with Gmsh's API
// A Laplace Equation (booh)
// Vector ort scalar, in any dimension and with 
// any polynomial order

// This code will quantify the gain of assembling matrices 
// either in reference coordinate system, or in the real one

typedef Double_Matrix gmshSmallMatrix ;
#ifdef HAVE_SPARSKIT
#include "CSR_Matrix.h"
#include "CSR_Vector.h"
typedef CSR_Matrix gmshMatrix ;
typedef CSR_Vector gmshVector ; 
inline double getMatrix ( int i, int j, gmshMatrix &m){
  return m.GetMatrix(i+1,j+1);
}
inline void addMatrix ( int i, int j, double val, gmshMatrix &m){
  if (val != 0.0)m.AddMatrix(i+1,j+1,val);
}
inline void addVector ( int i, double val, gmshVector &v){
  if (val != 0.0)v.AddVal(i+1,val);
}
inline void zeroVector ( gmshVector &v){
  v.ZeroArray();
}
inline double getVector ( int i, gmshVector &v){
  return v.GetVal(i+1);
}
inline void SystemSolve ( gmshMatrix &a, gmshVector &x, gmshVector &b){
  a.EndOfAssembly();
  SPARSKIT_LINEAR_SOLVER_ ( "rcmk","ilut","gmres",a,b,x);
}
#else
typedef Double_Matrix gmshMatrix ;
typedef Double_Vector gmshVector ; 
inline double getMatrix ( int i, int j, gmshMatrix &m){
  return m(i,j);
}
inline void addMatrix ( int i, int j, double val, gmshMatrix &m){
  m(i,j) += val;
}
inline void addVector ( int i, double val, gmshVector &v){
  v(i) += val;
}
inline double getVector ( int i, gmshVector &v){
  return v(i);
}
inline void SystemSolve ( gmshMatrix &a, gmshVector &x, gmshVector &b){
  a.lu_solve (b,x);
}
inline void zeroVector ( gmshVector &v){
  v.set_all(0.0);
}

#endif

extern double inv3x3 (double a[3][3], double a[3][3]);

// An ad hoc structure to store the triangulation 
// issued of a levelset cut 
// num is the new vertex
// num1 and num2 are vertices of the cut edge in the initial mesh
class gmshTopoVertex 
{
  static double tol;
  int num;
  double x,y,z;
  MVertex *v;
public:
  gmshTopoVertex (double _x, double _y, double _z):
    num(-1),x(_x),y(_y),z(_z)
  {
  }
  void setMVertex(MVertex *_v){v=_v;}
  MVertex* getMVertex()const {return v;}
  void setNum(int n){num=n;}
  int  getNum()const {return num;}
  bool operator < (const gmshTopoVertex & other) const{
    if (x - other.x < -tol) return true;
    if (x - other.x >  tol) return false;
    if (y - other.y < -tol) return true;
    if (y - other.y >  tol) return false;
    if (z - other.z < -tol) return true;
    return false;
  }
  double X() const {return x;}; 
  double Y() const {return y;}; 
  double Z() const {return z;}; 
};

double gmshTopoVertex::tol = 1.e-9;

// try to add a "poisson" term INSIDE the elements
#ifdef HAVE_GLEVELSETS
void IntegrationPoints (MElement*e, 
			gLevelset*ls,
			int integrationOrder,
			std::vector<IntegrationPoint>&ipV ,
			std::vector<IntegrationPoint>&ipS )
{
  switch ( e->getTypeForMSH()){
  case MSH_TET_4 :
    {
      vector<CuttingPoint> cp; 
      vector<Tetra> subTetras; 
      vector<Quad> surfQuads; 
      vector<Triangle> surfTriangles;
      Tetra T (e->getVertex(0)->x(),
	       e->getVertex(0)->y(),
	       e->getVertex(0)->z(),
	       e->getVertex(1)->x(),
	       e->getVertex(1)->y(),
	       e->getVertex(1)->z(),
	       e->getVertex(2)->x(),
	       e->getVertex(2)->y(),
	       e->getVertex(2)->z(),
	       e->getVertex(3)->x(),
	       e->getVertex(3)->y(),
	       e->getVertex(3)->z());
      T.cut (*ls, ipV, ipS, cp, integrationOrder,integrationOrder,integrationOrder, subTetras, surfQuads, surfTriangles);
    }
    break;
    
  default :
    throw;
  }
}
void gmshCutMesh (MElement*e, 
		  gLevelset*ls,
		  std::set<gmshTopoVertex> &tVerts,		  
		  std::multimap<MElement*,MElement*> &cut)
{
  switch ( e->getTypeForMSH()){
  case MSH_TET_4 :
    {
      vector<CuttingPoint> cp; 
      vector<Tetra> subTetras; 
      vector<Quad> surfQuads; 
      vector<Triangle> surfTriangles;
      int integrationOrder = 1;
      std::vector<IntegrationPoint> ipV;
      std::vector<IntegrationPoint> ipS;

      Tetra T (e->getVertex(0)->x(),
	       e->getVertex(0)->y(),
	       e->getVertex(0)->z(),
	       e->getVertex(1)->x(),
	       e->getVertex(1)->y(),
	       e->getVertex(1)->z(),
	       e->getVertex(2)->x(),
	       e->getVertex(2)->y(),
	       e->getVertex(2)->z(),
	       e->getVertex(3)->x(),
	       e->getVertex(3)->y(),
	       e->getVertex(3)->z());
      T.cut (*ls, ipV, ipS, cp, integrationOrder,integrationOrder,integrationOrder, subTetras, surfQuads, surfTriangles);
      for (int i=0;i<surfTriangles.size();i++){
	 gmshTopoVertex v0 ( surfTriangles[i].x(0),surfTriangles[i].y(0),surfTriangles[i].z(0));	
	 gmshTopoVertex v1 ( surfTriangles[i].x(1),surfTriangles[i].y(1),surfTriangles[i].z(1));	
	 gmshTopoVertex v2 ( surfTriangles[i].x(2),surfTriangles[i].y(2),surfTriangles[i].z(2));	
	 std::set<gmshTopoVertex>::const_iterator it0 =  tVerts.find(v0);
	 std::set<gmshTopoVertex>::iterator it1 =  tVerts.find(v1);
	 std::set<gmshTopoVertex>::iterator it2 =  tVerts.find(v2);
	 MVertex *mv0,*mv1,*mv2;
	 if (it0 == tVerts.end()){
	   v0.setNum(tVerts.size());
	   mv0 = new MVertex (v0.X(),v0.Y(),v0.Z(),0,v0.getNum());
	   v0.setMVertex (mv0);
	   tVerts.insert(v0);	   
	 }
	 else mv0 = it0->getMVertex();
	 if (it1 == tVerts.end()){
	   v1.setNum(tVerts.size());
	   mv1 = new MVertex (v1.X(),v1.Y(),v1.Z(),0,v1.getNum());
	   v1.setMVertex (mv1);
	   tVerts.insert(v1);	   
	 }
	 else mv1 = it1->getMVertex();
	 if (it2 == tVerts.end()){
	   v2.setNum(tVerts.size());
	   mv2 = new MVertex (v2.X(),v2.Y(),v2.Z(),0,v2.getNum());
	   v2.setMVertex (mv2);
	   tVerts.insert(v2);	   
	 }
	 else mv2 = it2->getMVertex();

	 MTriangle *tri = new MTriangle(mv0,mv1,mv2);
	 cut.insert(std::make_pair(e,tri));
      }
    }
    break;
    
  default :
    throw;
  }
}


void gmshBuildSurfaceMesh(GModel *_gm, 
			  gLevelset *ls, 
			  std::set<gmshTopoVertex> &tVerts,		  
			  std::multimap<MElement*,MElement*> &cut) {
  if (_gm->getNumRegions()){
    for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
      for (int i = 0;i<(*it)->getNumMeshElements();i++){
	MElement *e = (*it)->getMeshElement(i);       
	gmshCutMesh (e,ls,tVerts,cut); 
      }
    }
  }
  else throw;
}

#endif


class gmshVertexEvaluator
{
  double _val;
 public :
  gmshVertexEvaluator(double val = 0):_val(val){}
  virtual double operator () (MVertex *) const {return _val;}
  virtual double operator () (double x, double y, double z) const {return _val;}
};

class gmshTermOfFormulation {  
protected:
  GModel *_gm;
public:
  gmshTermOfFormulation (GModel *gm) : _gm(gm){}
  virtual void addToRightHandSide (gmshVector &r) const = 0;
  virtual void addToJacobian (gmshMatrix &J) const = 0;
};

class gmshNodalFemTerm : public gmshTermOfFormulation {
protected:
  virtual int sizeOfC(MElement*) const = 0;
  virtual int sizeOfR(MElement*) const = 0;
  virtual int localToGlobalR (MElement *e, int iVertex, int icomp) const = 0;
  virtual int localToGlobalR (MElement *e, int i) const = 0;
  virtual int localToGlobalC (MElement *e, int j) const = 0;
  std::map<std::pair<int,int>, double> dirichlet;
  gLevelset *_ls;
public:
  virtual void elementMatrix ( MElement *e, gmshSmallMatrix & m) const = 0;
  virtual void elementVector ( MElement *e, gmshVector & m)      const = 0;
  void addToJacobian (gmshMatrix &J, GEntity *ge) const;
  void addToRightHandSide (gmshVector &J, GEntity *ge) const;
  gmshNodalFemTerm (GModel *gm) : gmshTermOfFormulation(gm),_ls(0){}
  void addToRightHandSide (gmshVector &r) const;
  void addToJacobian (gmshMatrix &J) const;
  void addToJacobian (gmshMatrix &Jac, gmshSmallMatrix &localMatrix, MElement *e) const;
  void uglyDirichlet (gmshMatrix &J,gmshVector &r) const;
  void addDirichlet (int physical, int dim, int comp, const gmshVertexEvaluator & e);
  void addNeumann (int physical, int dim, int icomp, const gmshVertexEvaluator & e, gmshVector &r);
  void setLevelset(gLevelset *ls) {_ls = ls;}
  virtual int sizeOfR () const = 0;
  virtual int sizeOfC () const = 0;
  virtual void getComponents (int iVertex, int *components) const = 0;
};

void gmshNodalFemTerm::addDirichlet(int physical, int dim, int comp, const gmshVertexEvaluator & e) {
  std::vector<MVertex *> v;
  _gm->getMeshVertices (physical, dim,v);
  for (int i=0;i<v.size();i++)
    dirichlet[std::make_pair(v[i]->getNum(),comp)] = e(v[i]);  
}

void gmshNodalFemTerm::addNeumann(int physical, int dim, int comp, const gmshVertexEvaluator & fct, gmshVector &r) {
  std::map<int, std::vector<GEntity*> > groups[4];
  _gm->getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].find(physical);  
  if (it == groups[dim].end())return;
  double jac[3][3];

  for (int i=0;i<it->second.size();++i){
    GEntity *ge = it->second[i];
    for (int j=0; j<ge->getNumMeshElements();j++){
      MElement *e = ge->getMeshElement(j);
      int integrationOrder = 2*e->getPolynomialOrder();
      int nbNodes = e->getNumVertices();
      int npts;
      IntPt *GP;
      e->getIntegrationPoints(integrationOrder, &npts, &GP);  
      for (int ip=0;ip<npts;ip++){
	const double u      = GP[ip].pt[0];
	const double v      = GP[ip].pt[1];
	const double w      = GP[ip].pt[2];
	const double weight = GP[ip].weight;
	const double detJ = e->getJacobian (u,v,w,jac);   
	double x = 0;
	double y = 0;
	double z = 0;
	for (int k=0;k<nbNodes;k++){
	  double sf;
	  e->getShapeFunction (k,u,v,w,sf);	  
	  x += e->getVertex(k)->x() * sf;
	  y += e->getVertex(k)->y() * sf;
	  z += e->getVertex(k)->z() * sf;
	}
	const double FCT = fct (x,y,z);
	for (int k=0;k<nbNodes;k++){
	  double sf;
	  e->getShapeFunction (k,u,v,w,sf);	  
	  //	  printf("l2g (%d,%d) = %d (%d)\n", k,comp,localToGlobalR(e,k,comp),r.size());
	  addVector(localToGlobalR(e,k,comp),detJ * weight * sf * FCT,r);
	}
      }
    }
  }    
}

void gmshNodalFemTerm::uglyDirichlet (gmshMatrix &J,gmshVector &r) const{  
  std::map<std::pair<int,int>, double>::const_iterator it = dirichlet.begin();
  int C[256];
  for ( ; it != dirichlet.end() ; ++it){
    getComponents (it->first.first,C);
    double val  = it->second;
    int row  = C[it->first.second];
    //    printf("vertex %d comp %d iRow = %d\n",it->first.first,it->first.second,row);
    const double BIG = getMatrix(row,row,J) * 1.e8;
    addMatrix(row,row,BIG,J);
    addVector(row,BIG * val,r);
  }
}

// first symmetric implementation, will be better next
void gmshNodalFemTerm::addToJacobian (gmshMatrix &J) const {
  if (_gm->getNumRegions()){
    for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
      addToJacobian(J,*it);
    }
  }
  else if(_gm->getNumFaces()){
    for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it){
      addToJacobian(J,*it);
    }
  }  
}

// first symmetric implementation, will be better next
void gmshNodalFemTerm::addToRightHandSide (gmshVector &RHS) const {
  if (_gm->getNumRegions()){
    for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
      addToRightHandSide(RHS,*it);
    }
  }
  else if(_gm->getNumFaces()){
    for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it){
      addToRightHandSide(RHS,*it);
    }
  }  
}

void gmshNodalFemTerm::addToRightHandSide (gmshVector &RHS, GEntity *ge) const {
  for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){
    MElement *e = ge->getMeshElement (i);
    int nbR = sizeOfR(e);
    gmshVector V (nbR);
    elementVector (e, V);
    // assembly
    for (int j=0;j<nbR;j++){
      addVector(localToGlobalR (e,j),getVector(j,V),RHS);
    }
  }
}

void gmshNodalFemTerm::addToJacobian (gmshMatrix &Jac, gmshSmallMatrix &localMatrix, MElement *e) const {
  const int nbR = sizeOfR(e);
  const int nbC = sizeOfC(e);
  for (int j=0;j<nbR;j++){
    int J = localToGlobalR (e,j);
    for (int k=0;k<nbC;k++){
      int K = localToGlobalC (e,k);
      addMatrix(J,K,localMatrix (j,k),Jac);
    }
  }
}

void gmshNodalFemTerm::addToJacobian (gmshMatrix &Jac, GEntity *ge) const {
  for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){
    MElement *e = ge->getMeshElement (i);
    const int nbR = sizeOfR(e);
    const int nbC = sizeOfC(e);
    gmshSmallMatrix localMatrix (nbR,nbC);
    elementMatrix (e,localMatrix);
    // assembly
    for (int j=0;j<nbR;j++){
      int J = localToGlobalR (e,j);
      for (int k=0;k<nbC;k++){
	int K = localToGlobalC (e,k);
	addMatrix(J,K,localMatrix (j,k),Jac);
      }
    }
  }
}
// LAPLACE 
class gmshLaplaceTerm : public gmshNodalFemTerm {
  const double _diffusivity;
protected:
  virtual int sizeOfR (MElement *e) const {return e->getNumVertices();}
  virtual int sizeOfC (MElement *e) const {return e->getNumVertices();}
  virtual int localToGlobalR (MElement *e, int i) const {return e->getVertex(i)->getNum()-1;}
  virtual int localToGlobalC (MElement *e, int j) const {return e->getVertex(j)->getNum()-1;}
  virtual int localToGlobalR (MElement *e, int iVertex, int icomp) const {return localToGlobalR (e, iVertex);}
public:
  gmshLaplaceTerm (GModel *gm, double diffusivity = 1.0) : gmshNodalFemTerm(gm),_diffusivity (diffusivity){}
  void elementMatrix ( MElement *e, gmshSmallMatrix & m) const;
  void elementVector ( MElement *e, gmshVector & v) const;
  virtual int sizeOfR () const {return _gm->getNumMeshVertices();}
  virtual int sizeOfC () const {return _gm->getNumMeshVertices();}
  virtual void getComponents (int iVertex, int *components) const {components[0] = iVertex - 1;};
};


void gmshLaplaceTerm:: elementMatrix ( MElement *e, gmshSmallMatrix & m) const{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2*(e->getPolynomialOrder()-1);
  int npts;
  IntPt *GP;
  double jac    [3][3];
  double invjac [3][3];
  double Grads[256][3],grad[3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  
  m.set_all(0.0);

  for (int i=0;i<npts;i++){
    const double u      = GP[i].pt[0];
    const double v      = GP[i].pt[1];
    const double w      = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian (u,v,w,jac);   
    inv3x3 ( jac, invjac) ;
    for (int j=0;j<nbNodes;j++){
      e->getGradShapeFunction (j,u,v,w,grad);
      Grads[j][0] = invjac[0][0] * grad[0] + invjac[0][1] * grad[1] + invjac[0][2] * grad[2];
      Grads[j][1] = invjac[1][0] * grad[0] + invjac[1][1] * grad[1] + invjac[1][2] * grad[2];
      Grads[j][2] = invjac[2][0] * grad[0] + invjac[2][1] * grad[1] + invjac[2][2] * grad[2];
    }
    for (int j=0;j<nbNodes;j++){
      for (int k=0;k<=j;k++){
	m(j,k) += (Grads[j][0]*Grads[k][0]+
		   Grads[j][1]*Grads[k][1]+
		   Grads[j][2]*Grads[k][2]) * weight * detJ * _diffusivity;
      }
    }
  }
  for (int j=0;j<nbNodes;j++)
    for (int k=0;k<j;k++)
      m(k,j) = m(j,k);
} 



void gmshLaplaceTerm:: elementVector ( MElement *e, gmshVector & m) const{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2*(e->getPolynomialOrder()-1);
  double jac    [3][3];  
  zeroVector(m);
#ifdef HAVE_GLEVELSETS
  std::vector<IntegrationPoint> ipV,ipS;
  IntegrationPoints (e,_ls,integrationOrder,ipV,ipS);
  for (int i=0;i<ipS.size();i++){
    const double u      = ipS[i].xl();
    const double v      = ipS[i].yl();
    const double w      = ipS[i].zl();
    const double weight = ipS[i].weight();
    //    const double detJ = e->getJacobian (u,v,w,jac);   
    for (int j=0;j<nbNodes;j++){
      double sf ; e->getShapeFunction (j,u,v,w,sf);
      addVector(j,weight*sf,m);
    }
  }  
#else
  int npts;
  IntPt *GP;
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  for (int i=0;i<npts;i++){
    const double u      = GP[i].pt[0];
    const double v      = GP[i].pt[1];
    const double w      = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian (u,v,w,jac);   
    for (int j=0;j<nbNodes;j++){
      double sf ; e->getShapeFunction (j,u,v,w,sf);      
      addVector(j,weight*detJ*sf,m);
    }
  }
#endif
} 

// LAPLACE 
class gmshLaplaceVectorTerm : public gmshNodalFemTerm {
  double _E,_nu;
protected:
  virtual int sizeOfR (MElement *e) const {return 3*e->getNumVertices();}
  virtual int sizeOfC (MElement *e) const {return 3*e->getNumVertices();}
  virtual int localToGlobalR (MElement *e, int i) const {
    int iComp = i/e->getNumVertices();
    int ithLocalVertex = i%e->getNumVertices();
    //    printf("%d -> %d %d\n",i,ithLocalVertex,iComp);
    return 3*(e->getVertex(ithLocalVertex)->getNum()-1)+iComp;
  }
  virtual int localToGlobalR (MElement *e, int iVertex, int icomp) const {
    return localToGlobalR (e, icomp*e->getNumVertices()+iVertex);
  }
  virtual int localToGlobalC (MElement *e, int j) const {return localToGlobalR (e,j);}
public:
  gmshLaplaceVectorTerm (GModel *gm, double E, double nu) : gmshNodalFemTerm(gm),_E(E),_nu(nu){}
  void elementMatrix ( MElement *e, gmshSmallMatrix & m) const;
  void elementVector ( MElement *e, gmshVector & v) const;
  virtual int sizeOfR () const {return 3*_gm->getNumMeshVertices();}
  virtual int sizeOfC () const {return 3*_gm->getNumMeshVertices();}
  virtual void getComponents (int iVertex, int *components) const {
    components[0] = 3*(iVertex - 1) + 0;
    components[1] = 3*(iVertex - 1) + 1;
    components[2] = 3*(iVertex - 1) + 2;
  }
};


void gmshLaplaceVectorTerm:: elementMatrix ( MElement *e, gmshSmallMatrix & m) const{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2*(e->getPolynomialOrder()-1);
  int npts;
  IntPt *GP;
  double jac    [3][3];
  double invjac [3][3];
  double Grads[256][3],grad[3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  
  m.set_all(0.0);

  double FACT = _E / (1 + _nu);
  double C11 = FACT * (1 - _nu) / (1 - 2 * _nu);
  double C12 = FACT * _nu / (1 - 2 * _nu);
  double C44 = (C11 - C12) / 2;
  const double C[6][6] =
    { {C11, C12, C12,    0,   0,   0}, 
      {C12, C11, C12,    0,   0,   0}, 
      {C12, C12, C11,    0,   0,   0}, 
      {  0,   0,   0,  C44,   0,   0},
      {  0,   0,   0,    0, C44,   0}, 
      {  0,   0,   0,    0,   0, C44} };

  gmshSmallMatrix H(6,6);
  gmshSmallMatrix B   (6,3*nbNodes);
  gmshSmallMatrix BTH (3*nbNodes,6);
  gmshSmallMatrix BT  (3*nbNodes,6);
  for (int i=0;i<6;i++)
    for (int j=0;j<6;j++)
      H(i,j) = C[i][j];

  for (int i=0;i<npts;i++){
    const double u      = GP[i].pt[0];
    const double v      = GP[i].pt[1];
    const double w      = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian (u,v,w,jac);   
    inv3x3 ( jac, invjac) ;
    B.set_all(0.0);
    BT.set_all(0.0);
    for (int j=0;j<nbNodes;j++){
      e->getGradShapeFunction (j,u,v,w,grad);
      Grads[j][0] = invjac[0][0] * grad[0] + invjac[0][1] * grad[1] + invjac[0][2] * grad[2];
      Grads[j][1] = invjac[1][0] * grad[0] + invjac[1][1] * grad[1] + invjac[1][2] * grad[2];
      Grads[j][2] = invjac[2][0] * grad[0] + invjac[2][1] * grad[1] + invjac[2][2] * grad[2];      
      BT(j,0) = B(0,j) = Grads[j][0];
      BT(j,3) = B(3,j) = Grads[j][1];
      BT(j,4) = B(4,j) = Grads[j][2];

      BT(j+nbNodes,1) = B(1,j+nbNodes) = Grads[j][1];
      BT(j+nbNodes,3) = B(3,j+nbNodes) = Grads[j][0];
      BT(j+nbNodes,5) = B(5,j+nbNodes) = Grads[j][2];

      BT(j+2*nbNodes,2) = B(2,j+2*nbNodes) = Grads[j][2];
      BT(j+2*nbNodes,4) = B(4,j+2*nbNodes) = Grads[j][0];
      BT(j+2*nbNodes,5) = B(5,j+2*nbNodes) = Grads[j][1];
    }
    BTH.set_all(0.0);
    BTH.blas_dgemm (BT,H); 
    m.blas_dgemm (BTH,B,weight*detJ,1.0);
  } 
//   for (int i=0;i<12;i++){
//     for (int j=0;j<12;j++){
//       printf("%12.5E ",m(i,j));
//     }
//     printf("\n");
//   }
//   printf("\n");
}

void gmshLaplaceVectorTerm:: elementVector ( MElement *e, gmshVector & m) const{
}

/*
Tentative to smooth the mesh according to the levelset
*/

#ifdef HAVE_GLEVELSETS
void buildLagrangeMulipliersTerms (std::multimap<MElement*,MElement*> &cut, 
				   gmshSmallMatrix &C, 
				   gmshSmallMatrix &K){

  std::multimap<MElement*,MElement*>::iterator it2 =  cut.begin();
  double jac[3][3];

  for ( ; it2 != cut.end() ; ++it2){
    MElement *e     = it2->second;
    MElement *e_vol = it2->first;
    
    const double h = e->minEdge();

    int integrationOrder = 2*e->getPolynomialOrder();
    // Stabilization
    gmshSmallMatrix kloc(e->getNumVertices(),e->getNumVertices());
    gmshLaplaceTerm Laplace(0,.02*h*h);   
    Laplace.elementMatrix (e,kloc);

    // Lagrange multipliers
    int nbNodes     = e->getNumVertices();
    int nbNodes_vol = e_vol->getNumVertices();
    gmshSmallMatrix cloc(nbNodes,nbNodes_vol);
    int npts;
    IntPt *GP;
    e->getIntegrationPoints(integrationOrder, &npts, &GP);  
    for (int i=0;i<npts;i++){
      const double u      = GP[i].pt[0];
      const double v      = GP[i].pt[1];
      const double w      = GP[i].pt[2];
      const double weight = GP[i].weight;
      const double detJ = e->getJacobian (u,v,w,jac);   
      double xyz[3] = {0,0,0};
      double uvw[3];
      for (int k=0;k<nbNodes;k++){
	double sf;
	e->getShapeFunction (k,u,v,w,sf);	  
	xyz[0] += e->getVertex(k)->x() * sf;
	xyz[1] += e->getVertex(k)->y() * sf;
	xyz[2] += e->getVertex(k)->z() * sf;
      }
      e_vol->xyz2uvw(xyz,uvw);
      for (int j=0;j<nbNodes;j++){
	double sf    ;e->getShapeFunction(j,u,v,w,sf);
	for (int k=0;k<nbNodes_vol;k++){
	  double sf_vol;e_vol->getShapeFunction(k,uvw[0],uvw[1],uvw[2],sf_vol);
// 	  printf("k = %d : uvw (%g %g %g) %g %g %g %g\n",k,
// 		 uvw[0],uvw[1],uvw[2],
// 		 detJ,sf_vol,sf,weight);
	  cloc(j,k) += detJ * weight * sf * sf_vol;
	}
      }
    }

    for (int j=0;j<nbNodes;j++){
      for (int k=0;k<nbNodes_vol;k++){
	C(e->getVertex(j)->getNum()-1,e_vol->getVertex(k)->getNum()-1)+=cloc(j,k);
      }
      for (int k=0;k<nbNodes;k++){
	K(e->getVertex(j)->getNum()-1,e->getVertex(k)->getNum()-1)+=kloc(j,k);
      }
    }
  }
}
#endif


// solve a pb with lagrange multipliers

int main(int argc, char **argv)
{
  // globals are still present in Gmsh
  GmshInitialize(argc, argv);
  
  // Creation of a geometric model
  GModel *m = new GModel();
  // a Mesh is read
  m->readMSH(argv[1]);
  int nbNodes = m->getNumMeshVertices();
  int dim = m->getNumRegions() ? 3 : 2;

  gmshLaplaceTerm Laplace(m);   
  int sP = Laplace.sizeOfR();
  
#ifdef HAVE_GLEVELSETS
  //gLevelset *ls  = new gLevelsetPlane  (1,0,0,.5);
  gLevelset *ls1 = new gLevelsetSphere (-.7,.5,.5,.12);
  gLevelset *ls2 = new gLevelsetSphere (-.3,.5,.5,.12);
  //  gLevelset *ls = new gLevelsetSphere (-.35,.5,.5,.2);
  std::vector<const gLevelset*> vls;
  vls.push_back(ls1);
  vls.push_back(ls2);
  gLevelsetUnion *ls = new gLevelsetUnion (vls);
  Laplace.setLevelset (ls);
  std::set<gmshTopoVertex> tVerts;		  
  std::multimap<MElement*,MElement*> cut;
  gmshBuildSurfaceMesh(m,ls,tVerts,cut); 
  printf("%d noeuds %d triangles\n",tVerts.size(),cut.size());
  {
    FILE *fp = fopen ("cut.msh","w");
    fprintf(fp, "$MeshFormat\n2 0 8\n$EndMeshFormat\n");
    fprintf(fp, "$Nodes\n");
    fprintf(fp, "%d\n",tVerts.size());
    std::set<gmshTopoVertex>::iterator it =  tVerts.begin();
    int K=1;
    for ( ; it != tVerts.end() ; ++it){
      it->getMVertex()->setNum(K);
      it->getMVertex()->setIndex (K++);
      it->getMVertex()->writeMSH(fp);
    }
    fprintf(fp, "$EndNodes\n");
    fprintf(fp, "$Elements\n");
    fprintf(fp, "%d\n",cut.size());
    std::multimap<MElement*,MElement*>::iterator it2 =  cut.begin();
    for ( ; it2 != cut.end() ; ++it2){
      it2->second->writeMSH(fp,2.0);
    }
    fprintf(fp, "$EndElements\n");
    fclose(fp); 
  }
  gmshSmallMatrix kstab (tVerts.size(),tVerts.size());
  gmshSmallMatrix C     (tVerts.size(),m->getNumMeshVertices());
  printf("assembling lagrange terms\n");
  buildLagrangeMulipliersTerms (cut,C,kstab); 
  printf("lagrange terms assembled\n");

  int sP1 = sP;
  sP += tVerts.size();
#endif
  Laplace.addDirichlet (300,dim-1,0,gmshVertexEvaluator(1.0));
  Laplace.addDirichlet (200,dim-1,0,gmshVertexEvaluator(1.0));
  Laplace.addDirichlet (100,dim-1,0,gmshVertexEvaluator(1.0));
  
#ifdef HAVE_SPARSKIT
  gmshMatrix k (sP);
#else
  gmshMatrix k (sP,sP);
#endif

  gmshVector x (sP);
  gmshVector b (sP);

  clock_t t1 = clock();
  Laplace.addToJacobian(k);  
  Laplace.uglyDirichlet (k,b);  

  printf("classical part assembled\n");

#ifdef HAVE_GLEVELSETS
  for (int i=0;i<tVerts.size();i++)
    for (int j=0;j<tVerts.size();j++)
      addMatrix(sP1 + i,sP1 + j,kstab(i,j),k);
  
  for (int i=0;i<tVerts.size();i++){// tverts
    for (int j=0;j<sP1;j++){//totalnumv
      addMatrix(i+sP1,j,C(i,j),k);
      addMatrix(j,i+sP1,C(i,j),k);
    }
  }
#endif


  clock_t t2 = clock();
  printf("%lf seconds for assembling the operator\n",(double)(t2-t1)/CLOCKS_PER_SEC);  
  SystemSolve(k,x,b);
  clock_t t3 = clock();
  printf("%lf seconds for solving the system (%d unknowns)\n",
	 (double)(t3-t2)/CLOCKS_PER_SEC,sP);  
  {
    FILE *fp = fopen("res.msh","w");
    fprintf(fp, "$MeshFormat\n2 0 8\n$EndMeshFormat\n");
    fprintf(fp, "$NodeData\n");
    fprintf(fp, "1\n\"%s\"\n", "toto");
    fprintf(fp, "1\n%.16g\n", 0.0);
    fprintf(fp, "3\n%d\n%d\n%d\n", 0, 1, m->getNumMeshVertices());  
    int c[100];
    for (int i=0;i<nbNodes;i++){
      Laplace.getComponents(i+1,c);
      fprintf(fp, "%d %22.15E\n",i+1, getVector(c[0],x));
    }
    fprintf(fp, "$EndNodeData\n");
    fclose (fp);
  }
#ifdef HAVE_GLEVELSETS
  {  
    FILE *fp = fopen("lagrnage.msh","w");
    fprintf(fp, "$MeshFormat\n2 0 8\n$EndMeshFormat\n");
    fprintf(fp, "$NodeData\n");
    fprintf(fp, "1\n\"%s\"\n", "toto");
    fprintf(fp, "1\n%.16g\n", 0.0);
    fprintf(fp, "3\n%d\n%d\n%d\n", 0, 1, tVerts.size());  
    for (int i=0;i<tVerts.size();i++){
      fprintf(fp, "%d %22.15E\n",i+1, getVector(sP1+i,x));
    }
    fprintf(fp, "$EndNodeData\n");
    fclose (fp);
  }
#endif
  clock_t t4 = clock();
  printf("%lf seconds for saving the solution\n",(double)(t4-t3)/CLOCKS_PER_SEC);  
  GmshFinalize();
}

// solve an elasticity pb
int main2(int argc, char **argv)
{
  // globals are still present in Gmsh
  GmshInitialize(argc, argv);
  
  // Creation of a geometric model
  GModel *m = new GModel();
  // a Mesh is read
  m->readMSH(argv[1]);
  int nbNodes = m->getNumMeshVertices();
  int dim = m->getNumRegions() ? 3 : 2;

  gmshLaplaceVectorTerm Laplace(m,1.e10,.3);   
  int sP = Laplace.sizeOfR();
  
  //  Laplace.addDirichlet (200,dim-1,0,gmshVertexEvaluator(0.01));
  Laplace.addDirichlet (100,dim-1,0,gmshVertexEvaluator(0.0));
  Laplace.addDirichlet (100,dim-1,1,gmshVertexEvaluator(0.0));
  Laplace.addDirichlet (100,dim-1,2,gmshVertexEvaluator(0.0));
  

#ifdef HAVE_SPARSKIT
  gmshMatrix k (sP);
#else
  gmshMatrix k (sP,sP);
#endif
  gmshVector x (sP);
  gmshVector b (sP);

  Laplace.addNeumann (200,dim-1,0,gmshVertexEvaluator(0.01),b);

  clock_t t1 = clock();
  Laplace.addToJacobian(k);  
  //  Laplace.addToRightHandSide(b);  
  Laplace.uglyDirichlet (k,b);  
  clock_t t2 = clock();
  printf("%lf seconds for assembling the operator\n",(double)(t2-t1)/CLOCKS_PER_SEC);  
  SystemSolve(k,x,b);
  clock_t t3 = clock();
  //  printf("%lf seconds for solving the system (%d unknowns)\n",(double)(t3-t2)/CLOCKS_PER_SEC,k.size1());  

  FILE *fp = fopen("displacements.msh","w");
  fprintf(fp, "$MeshFormat\n2 0 8\n$EndMeshFormat\n");
  fprintf(fp, "$NodeData\n");
  fprintf(fp, "1\n\"%s\"\n", "toto");
  fprintf(fp, "1\n%.16g\n", 0.0);
  fprintf(fp, "3\n%d\n%d\n%d\n", 0, 3, m->getNumMeshVertices());  
  int c[100];
  for (int i=0;i<nbNodes;i++){
    Laplace.getComponents(i+1,c);
    fprintf(fp, "%d %22.15E %22.15E %22.15E\n",i+1, 
	    getVector(c[0],x),getVector(c[1],x),getVector(c[2],x));
  }
  fprintf(fp, "$EndNodeData\n");
  fclose (fp);
  clock_t t4 = clock();
  printf("%lf seconds for saving the solution\n",(double)(t4-t3)/CLOCKS_PER_SEC);  
  GmshFinalize();
}


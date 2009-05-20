// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GFaceCompound.h"
#include "MLine.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Octree.h"
#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshLinearSystemGmm.h"
#include "gmshLinearSystemFull.h"

class gmshGradientBasedDiffusivity : public gmshFunction<double>
{
private:
  MElement *_current;
  int _iComp;
  mutable std::map<MVertex*, SPoint2> _coordinates;
public:
  gmshGradientBasedDiffusivity (std::map<MVertex*,SPoint2> &coordinates) 
    : _current (0), _iComp(-1),_coordinates(coordinates){}
  void setCurrent (MElement *current){ _current = current; }
  void setComponent (int iComp){ _iComp = iComp; }
  virtual double operator () (double x, double y, double z) const
  {
    if(_iComp == -1) return 1.0;
    double xyz[3] = {x, y, z}, uvw[3];
    _current->xyz2uvw(xyz, uvw);
    double value1[256];
    double value2[256];
    for (int i = 0; i < _current->getNumVertices(); i++){
      const SPoint2 p = _coordinates[_current->getVertex(i)];
      value1[i] = p[0];
      value2[i] = p[1];
    }
    double g1[3], g2[3];
    _current->interpolateGrad(value1, uvw[0], uvw[1], uvw[2], g1);
    _current->interpolateGrad(value2, uvw[0], uvw[1], uvw[2], g2);
    return sqrt(g1[0] * g1[0] + g1[1] * g1[1] + g1[2] * g1[2] +
		g2[0] * g2[0] + g2[1] * g2[1] + g2[2] * g2[2]);
  }
};

class gmshDistanceBasedDiffusivity : public gmshFunction<double>
{
private:
  MElement *_current;
  mutable std::map<MVertex*, SPoint3> _coordinates;
public:
  gmshDistanceBasedDiffusivity (std::map<MVertex*,SPoint3> &coordinates) 
    : _current (0),_coordinates(coordinates){}
  void setCurrent (MElement *current){ _current = current; }
  virtual double operator () (double x, double y, double z) const
  {
    double xyz[3] = {x, y, z}, uvw[3];
    _current->xyz2uvw(xyz, uvw);
    double value[256];
    for (int i = 0; i < _current->getNumVertices(); i++){
      const SPoint3 p = _coordinates[_current->getVertex(i)];
      value[i] = p[2];
    }
    double val = _current->interpolate(value, uvw[0], uvw[1], uvw[2]);
    return 1.0;//exp(15*val);
  }
};

static void fixEdgeToValue(GEdge *ed, double value, gmshAssembler<double> &myAssembler)
{
  myAssembler.fixVertex(ed->getBeginVertex()->mesh_vertices[0], 0, 1, value);
  myAssembler.fixVertex(ed->getEndVertex()->mesh_vertices[0], 0, 1, value);
  for (unsigned int i = 0; i < ed->mesh_vertices.size(); i++){
    myAssembler.fixVertex(ed->mesh_vertices[i], 0, 1, value);
  }
}

void GFaceCompound::parametrize() const
{

  if (!oct){
    coordinates.clear();
    parametrize(ITERD);
    parametrize(ITERU);
    parametrize(ITERV);
    computeNormals();
    buildOct();
  }
}

void GFaceCompound::getBoundingEdges()
{
  printf("***** In GFaceCompound: size U0=%d, v0=%d\n ", _U0.size(), _V0.size());

  //in case the bounding edges are explicitely given
  if (_U0.size()){
    std::list<GEdge*> :: const_iterator it = _U0.begin();
    for ( ; it != _U0.end() ; ++it){
      l_edges.push_back(*it);
      //printf("U0 for edge %d, add face %d \n", (*it)->tag(), this->tag());
      (*it)->addFace(this);
    }
    it = _V0.begin();
    for ( ; it != _V0.end() ; ++it){
      l_edges.push_back(*it);
      //printf("V0 for edge %d, add face %d \n", (*it)->tag(), this->tag());
      (*it)->addFace(this);
    }
    return;
  }

  // in case the bounding edges are not given Boundary { {} };
  std::set<GEdge*> _unique;
  std::multiset<GEdge*> _touched;
  std::list<GFace*>::iterator it = _compound.begin();
  for ( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
   std::list<GEdge*> :: iterator ite = ed.begin();
    for ( ; ite != ed.end(); ++ite){
     _touched.insert(*ite);
    }    
  }    
  it = _compound.begin();
  for ( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*> :: iterator ite = ed.begin();
    for ( ; ite != ed.end() ; ++ite){
      if (!(*ite)->degenerate(0) && _touched.count(*ite) == 1) {	
	_unique.insert(*ite);      }
    }    
  }    

  std::set<GEdge*>::iterator itf = _unique.begin();
  for ( ; itf != _unique.end(); ++itf){
    l_edges.push_back(*itf);
    //printf("for edge %d, add face %d \n", (*itf)->tag(), this->tag());
    (*itf)->addFace(this);
  }

  //find a closed loop for assigning boundary conditions
  std::list<GEdge*> _loop;
  std::map<GVertex*,GEdge*> tempv;
  std::set<GEdge*>::iterator its = _unique.begin();
  GVertex *vB = (*its)->getBeginVertex();
  GVertex *v = (*its)->getEndVertex();
  _loop.push_back(*its);
  printf("boundary add edge=%d \n", (*its)->tag());
  //printf("edge=%d  vB=%d v =%d\n", (*its)->tag(), vB->tag(), v->tag());
  its++;
  for ( ; its != _unique.end() ; ++its){
    GVertex *v1 = (*its)->getBeginVertex();
    GVertex *v2 = (*its)->getEndVertex();
    if (v1 == v) {
      printf("boundary add edge=%d \n", (*its)->tag());
      _loop.push_back(*its);
      v = v2;
    }
    else if (v2 == v) {
      printf("boundaryn add edge=%d \n", (*its)->tag());
      _loop.push_back(*its);
      v = v1;
    }
    if (v == vB) break;
  }
 
  _U0 = _loop;

}

GFaceCompound::GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
			     std::list<GEdge*> &U0, std::list<GEdge*> &V0,
			     std::list<GEdge*> &U1, std::list<GEdge*> &V1)
  : GFace(m, tag), _compound(compound), _U0(U0), _U1(U1), _V0(V0), _V1(V1), oct(0)
{

  for (std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    if (!(*it)){
      Msg::Error("Incorrect face in compound surface %d\n", tag);
      Msg::Exit(1);
    }
  }

  getBoundingEdges();
  if (!_U0.size()) _type = UNITCIRCLE;
  else if (!_V1.size()) _type = UNITCIRCLE;
  else _type = SQUARE;



}

GFaceCompound::~GFaceCompound()
{
  if(oct){
    Octree_Delete(oct);
    delete [] _gfct;
  }
}



static bool orderVertices(const std::list<GEdge*> &e, std::vector<MVertex*> &l,
                          std::vector<double> &coord)
{
  l.clear();
  coord.clear();
  std::list<GEdge*>::const_iterator it = e.begin();
  std::list<MLine*> temp;
  double tot_length = 0;
  for ( ; it != e.end(); ++it ){
    for (unsigned int i = 0; i < (*it)->lines.size(); i++ ){
      temp.push_back((*it)->lines[i]);
      MVertex *v0 = (*it)->lines[i]->getVertex(0);
      MVertex *v1 = (*it)->lines[i]->getVertex(1);    
      const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                 (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                 (v0->z() - v1->z()) * (v0->z() - v1->z()));
      tot_length += length;
    }
  }
  
  MVertex *first_v = (*temp.begin())->getVertex(0);
  MVertex *current_v = (*temp.begin())->getVertex(1);
  
  l.push_back(first_v);
  coord.push_back(0.0);
  temp.erase(temp.begin());

  while (temp.size()){
    bool found = 0;
    for (std::list<MLine*>::iterator itl = temp.begin(); itl != temp.end(); ++itl){
      MLine *ll = *itl;
      MVertex *v0 = ll->getVertex(0);
      MVertex *v1 = ll->getVertex(1);
      if (v0 == current_v){
	found = true;
	l.push_back(current_v);
	current_v = v1;
	temp.erase(itl);
	const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));	
	coord.push_back(coord[coord.size()-1] + length / tot_length);
	break;
      }
      else if (v1 == current_v){
	found = true;
	l.push_back(current_v);
	current_v = v0;
	temp.erase(itl);
	const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));
	coord.push_back(coord[coord.size()-1] + length / tot_length);
	break;
      }
    }
    if(!found) return false;
  }    
  return true;
}

SPoint2 GFaceCompound::getCoordinates(MVertex *v) const 
{ 
  
  parametrize() ; 
  std::map<MVertex*,SPoint3>::iterator it = coordinates.find(v);

  if(it != coordinates.end()){
    return SPoint2(it->second.x(),it->second.y()); 
  }
  else{

    double tGlob, tLoc;
    double tL, tR;
    int iEdge;

    //getParameter Point
    v->getParameter(0,tGlob);
    //printf("*** global param for point (%g, %g, %g ) = %g\n", v->x(), v->y(), v->z(), tGlob);

    //find compound Edge
      GEdgeCompound *gec = dynamic_cast<GEdgeCompound*>(v->onWhat());
      //printf("tag compound=%d, beginvertex=%d, endvertex=%d \n", gec->tag(), gec->getBeginVertex()->tag(), gec->getEndVertex()->tag());
    
    if (gec){

      //compute local parameter on Edge
      gec->getLocalParameter(tGlob,iEdge,tLoc);
      std::vector<GEdge*> gev = gec->getEdgesOfCompound();
      GEdge *ge = gev[iEdge];
      //printf("iEdge =%d, leftV =%d, rightV=%d,  and local param=%g \n", ge->tag(), ge->getBeginVertex()->tag(), ge->getEndVertex()->tag(), tLoc);
      
      //left and right vertex of the Edge
      MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
      MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];
      std::map<MVertex*,SPoint3>::iterator itL = coordinates.find(v0);
      std::map<MVertex*,SPoint3>::iterator itR = coordinates.find(v1);
  
      //for the Edge, find the left and right vertices of the initial 1D mesh and interpolate to find (u,v)
      //printf("number of vertices =%d for Edge =%d \n", ge->mesh_vertices.size(), ge->tag());
      MVertex *vL = v0;
      MVertex *vR = v1;
      double tB = ge->parBounds(0).low();
      double tE = ge->parBounds(0).high();
      //printf("tB=%g uv (%g %g) tE=%g (%g %g), tLoc=%g\n", tB, itL->second.x(), itL->second.y(), tE, itR->second.x(), itR->second.y(), tLoc);
      int j = 0;
      tL=tB;
      bool found = false;
      while (j < ge->mesh_vertices.size()){
	vR = ge->mesh_vertices[j];
	vR->getParameter(0,tR);
	if (!vR->getParameter(0,tR)) {
	  Msg::Error("vertex vr %p not medgevertex \n", vR);
	  Msg::Exit(1);
	}
	//printf("***tLoc=%g tL=%g, tR=%g L=%p (%g,%g,%g) et R= %p (%g,%g,%g)\n", tLoc, tL, tR, vL, vL->x(),vL->y(),vL->z(),vR, vR->x(), vR->y(), vR->z());
	if (tLoc >= tL && tLoc <= tR){
	  found = true;
	  itR = coordinates.find(vR);
	  if (itR == coordinates.end()){
	    Msg::Error("vertex %p (%g %g %g) not found\n", vR, vR->x(), vR->y(), vR->z());
	    Msg::Exit(1);
	  }
	  break;
	}
	else{
	  itL = coordinates.find(vR);
	  vL = vR;
	  tL = tR;
	}
	j++;
	//printf("in while j =%d,  vL (%g,%g,%g), -> uv= (%g,%g)\n",j, vL->x(), vL->y(), vL->z(), itL->second.x(), itL->second.y());
      }
      if (!found) {
	vR = v1; 
	tR = tE;
      }
      //printf("vL (%g,%g,%g), -> uv= (%g,%g)\n",vL->x(), vL->y(), vL->z(), itL->second.x(), itL->second.y());
      //printf("vR (%g,%g,%g), -> uv= (%g,%g)\n",vR->x(), vR->y(), vR->z(), itR->second.x(), itR->second.y());
      //printf("tL:%g, tR=%g, tLoc=%g \n", tL, tR, tLoc);

      //Linear interpolation between tL and tR
      double uloc, vloc;
      uloc = itL->second.x() + (tLoc-tL)/(tR-tL) * (itR->second.x()-itL->second.x());
      vloc = itL->second.y() + (tLoc-tL)/(tR-tL) * (itR->second.y()-itL->second.y());
      //printf("uloc=%g, vloc=%g \n", uloc,vloc);
      //exit(1);

      return SPoint2(uloc,vloc);
    }
  }
}

void GFaceCompound::parametrize(iterationStep step) const
{
  Msg::Info("Parametrizing Surface %d coordinate (ITER %d)", tag(), step); 
  
#ifdef HAVE_GMM
  gmshLinearSystemGmm<double> lsys;
  lsys.setPrec(1.e-15);
  if(Msg::GetVerbosity() == 99) lsys.setNoisy(2);
#else
  gmshLinearSystemFull<double> lsys;
#endif
  gmshAssembler<double> myAssembler(&lsys);

  gmshDistanceBasedDiffusivity diffusivity(coordinates);
  gmshFunction<double> ONE(1.0);

  if (_type == UNITCIRCLE){
    // maps the boundary onto a circle
    std::vector<MVertex*> ordered;
    std::vector<MVertex*> ordered1;
    std::vector<double> coords;  
    std::vector<double> coords1;  
    bool success = orderVertices(_U0, ordered, coords);
    if (!success){
      Msg::Error("Could not order vertices on boundary");
      return;
    }
    for (unsigned int i = 0; i < ordered.size(); i++){
      MVertex *v = ordered[i];
      const double theta = 2 * M_PI * coords[i];
      if (step == ITERU) myAssembler.fixVertex(v, 0, 1, cos(theta));
      else if (step == ITERV) myAssembler.fixVertex(v, 0, 1, sin(theta));
      else if (step == ITERD) myAssembler.fixVertex(v, 0, 1, 1.0);      
    }
    if (step == ITERD && _V0.size()) {
      success = orderVertices(_V0, ordered1, coords1);
      if (!success){
	Msg::Error("Could not order vertices on boundary");
	return;
      }
      for (unsigned int i = 0; i < ordered1.size(); i++){
	MVertex *v = ordered1[i];
	myAssembler.fixVertex(v, 0, 1, 0.0);      
      }    
    }
  }
  else if (_type == SQUARE){
    if (step == ITERU){
      std::list<GEdge*> :: const_iterator it = _U0.begin();
      for ( ; it != _U0.end(); ++it){
	fixEdgeToValue(*it, 0.0, myAssembler);
      }
      it = _U1.begin();
      for ( ; it != _U1.end(); ++it){
	fixEdgeToValue(*it, 1.0, myAssembler);
      }
    }
    else if (step == ITERV){
      std::list<GEdge*> :: const_iterator it = _V0.begin();
      for ( ; it != _V0.end(); ++it){
	fixEdgeToValue (*it, 0.0, myAssembler);
      }
      it = _V1.begin();
      for ( ; it != _V1.end(); ++it){
	fixEdgeToValue (*it, 1.0, myAssembler);
      }
    }
  }
  else throw;

  std::list<GFace*>::const_iterator it = _compound.begin();
  for ( ; it != _compound.end(); ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1); 
    }    
  }    

  Msg::Debug("Creating term %d dofs numbered %d fixed",
             myAssembler.sizeOfR(), myAssembler.sizeOfF());

  if (step == ITERD){
    gmshLaplaceTerm laplace(model(), &ONE, 1);
    it = _compound.begin();
    for ( ; it != _compound.end() ; ++it){
      for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
	MTriangle *t = (*it)->triangles[i];
	diffusivity.setCurrent(t);
	laplace.addToMatrix(myAssembler, t);
      }
    }    
  }
  else{
    gmshLaplaceTerm laplace(model(), &diffusivity, 1);
    it = _compound.begin();
    for ( ; it != _compound.end() ; ++it){
      for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
	MTriangle *t = (*it)->triangles[i];
	diffusivity.setCurrent(t);
	laplace.addToMatrix(myAssembler, t);
      }
    }    
  }

  Msg::Debug("Assembly done");
  lsys.systemSolve();
  Msg::Debug("System solved");
  it = _compound.begin();
  std::set<MVertex *>allNodes;
  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for (int j = 0; j < 3; j++){
	allNodes.insert(t->getVertex(j));
      }
    }
  }
  
  for (std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value = myAssembler.getDofValue(v,0,1);
    //if (step == 1)
    //printf("%p node =%g %g %g , value = %g of size %d \n",v,  v->x(), v->y(), v->z(), value, coordinates.size());
    std::map<MVertex*,SPoint3>::iterator itf = coordinates.find(v);
    if (itf == coordinates.end()){
      SPoint3 p(0,0,0);
      p[step] = value;
      coordinates[v] = p;
    }
    else{
      itf->second[step]= value;
    }
    
 
  }
}

void GFaceCompound::computeNormals () const
{
  _normals.clear();
  std::list<GFace*>::const_iterator it = _compound.begin();
  double J[3][3];
  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      t->getJacobian(0, 0, 0, J);
      // SVector3 n (J[2][0],J[2][1],J[2][2]);
      SVector3 d1(J[0][0], J[0][1], J[0][2]);
      SVector3 d2(J[1][0], J[1][1], J[1][2]);
      SVector3 n = crossprod(d1, d2);
      n.normalize();
      for (int j = 0; j < 3; j++){
	std::map<MVertex*, SVector3>::iterator itn = _normals.find(t->getVertex(j));
	if (itn == _normals.end())_normals[t->getVertex(j)] = n;
	else itn->second += n;
      }
    }
  }    
  std::map<MVertex*,SVector3>::iterator itn = _normals.begin();
  for ( ; itn != _normals.end() ; ++itn) itn->second.normalize();
}

double GFaceCompound::curvature(const SPoint2 &param) const
{
  parametrize();
  double U,V;
  GFaceCompoundTriangle *lt;
  getTriangle (param.x(),param.y(), &lt, U,V);  
  if (!lt){
    return  0.0;
  }

  //   if (lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface){
  //     SPoint2 pv1, pv2, pv3;
  //     bool ok = reparamMeshVertexOnFace(lt->t->getVertex(0), lt->gf, pv1); 
  //     ok |= reparamMeshVertexOnFace(lt->t->getVertex(1), lt->gf, pv2); 
  //     ok |= reparamMeshVertexOnFace(lt->t->getVertex(2), lt->gf, pv3); 
  //     if (ok){
  //       SPoint2 pv = pv1*(1.-U-V) + pv2*U + pv3*V;
  //       return lt->gf->curvature(pv));
  //     }
  //   }

  //  return curvature(lt->t);
  return 0.;
}

double GFaceCompound::curvature(MTriangle *t) const
{
  SVector3 n1 = _normals[t->getVertex(0)];
  SVector3 n2 = _normals[t->getVertex(1)];
  SVector3 n3 = _normals[t->getVertex(2)];
  double val[9] = {n1.x(),n2.x(),n3.x(),
		   n1.y(),n2.y(),n3.y(),
		   n1.z(),n2.z(),n3.z()};
  //  return fabs(t->interpolateDiv (val,0.,0.,0.));
  return 0.;
}

GPoint GFaceCompound::point(double par1, double par2) const
{
  parametrize();
  double U,V;
  GFaceCompoundTriangle *lt;
  getTriangle (par1, par2, &lt, U,V);  
  SPoint3 p(0, 0, 0); 
  if (!lt){
    // Msg::Warning("Re-Parametrized face %d --> point (%g %g) lies outside the domain", tag(), par1,par2); 
  
    return  GPoint(p.x(),p.y(),p.z(),this);
  }
  if (0 && lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface){
    SPoint2 pv = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    return lt->gf->point(pv.x(),pv.y());
  }
  
  p = lt->v1*(1.-U-V) + lt->v2*U + lt->v3*V;
  double par[2] = {par1,par2};
  return GPoint(p.x(),p.y(),p.z(),this,par);
}

Pair<SVector3,SVector3> GFaceCompound::firstDer(const SPoint2 &param) const
{
  parametrize();
  double U,V,UDU,UDV,VDU,VDV;
  GFaceCompoundTriangle *lt;
  getTriangle (param.x(), param.y(), &lt, U,V);
  if (!lt)
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));

  double mat[2][2] = {{lt->p2.x() - lt->p1.x(), lt->p3.x() - lt->p1.x()},
		      {lt->p2.y() - lt->p1.y(), lt->p3.y() - lt->p1.y()}};
  double inv[2][2];
  inv2x2(mat,inv);
 
  SVector3 dXdxi   (lt->v2 - lt->v1);
  SVector3 dXdeta  (lt->v3 - lt->v1);

  SVector3 dXdu (dXdxi*inv[0][0]+dXdeta*inv[1][0]);
  SVector3 dXdv (dXdxi*inv[0][1]+dXdeta*inv[1][1]);

  return Pair<SVector3, SVector3>(dXdu,dXdv);
} 

void GFaceCompound::secondDer(const SPoint2 &param, 
                              SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  Msg::Error("Computation of the second derivatives not implemented for compound faces");
}

static void GFaceCompoundBB(void *a, double*mmin, double*mmax)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  mmin[0] = std::min(std::min(t->p1.x(), t->p2.x()), t->p3.x());
  mmin[1] = std::min(std::min(t->p1.y(), t->p2.y()), t->p3.y());
  mmax[0] = std::max(std::max(t->p1.x(), t->p2.x()), t->p3.x());
  mmax[1] = std::max(std::max(t->p1.y(), t->p2.y()), t->p3.y());
  mmin[2] = -1;
  mmax[2] = 1;

  const double dx = mmax[0] - mmin[0];
  const double dy = mmax[1] - mmin[1];
  mmin[0] -= .02*dx;
  mmin[1] -= .02*dy;
  mmax[0] += .02*dx;
  mmax[1] += .02*dy;
}

static void GFaceCompoundCentroid(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  c[0] = (t->p1.x() + t->p2.x() + t->p3.x()) / 3.0;
  c[1] = (t->p1.y() + t->p2.y() + t->p3.y()) / 3.0;
  c[2] = 0.0;
}

static int GFaceCompoundInEle(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  double M[2][2],R[2],X[2];
  const double eps = 1.e-8;
  const SPoint3 p0 = t->p1;
  const SPoint3 p1 = t->p2;
  const SPoint3 p2 = t->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (c[0] - p0.x());
  R[1] = (c[1] - p0.y());
  sys2x2(M,R,X);
  if (X[0] > -eps && X[1] > -eps && 1. - X[0] - X[1] > -eps){
    return 1;
  }
  return 0;
}

void GFaceCompound::getTriangle(double u, double v, 
                                GFaceCompoundTriangle **lt,
                                double &_u, double &_v) const
{
  parametrize();
  
  double uv[3] = {u, v, 0};
  *lt = (GFaceCompoundTriangle*)Octree_Search(uv, oct);
  if (!(*lt)) return;

  double M[2][2],X[2],R[2];
  const SPoint3 p0 = (*lt)->p1;
  const SPoint3 p1 = (*lt)->p2;
  const SPoint3 p2 = (*lt)->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (u - p0.x());
  R[1] = (v - p0.y());
  sys2x2(M,R,X);
  _u = X[0];
  _v = X[1];
}

void GFaceCompound::buildOct() const
{
  SBoundingBox3d bb;
  int count = 0;
  std::list<GFace*> :: const_iterator it = _compound.begin();
  
  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for (int j=0;j<3;j++){
	std::map<MVertex*,SPoint3>::const_iterator itj = 
	  coordinates.find(t->getVertex(j));
	bb += SPoint3(itj->second.x(),itj->second.y(),0.0);
      }
      count++;
    }
  }
  _gfct = new GFaceCompoundTriangle[count];
  double origin[3] = {bb.min().x(), bb.min().y(), bb.min().z()};
  double ssize[3] = {bb.max().x() - bb.min().x(),
		     bb.max().y() - bb.min().y(),
		     bb.max().z() - bb.min().z()};
  oct = Octree_Create(10, origin, ssize, GFaceCompoundBB, GFaceCompoundCentroid,
                      GFaceCompoundInEle);

  it = _compound.begin();
  count = 0;

  FILE * uvx = fopen("UVX.pos","w");
  FILE * uvy = fopen("UVY.pos","w");
  FILE * uvz = fopen("UVZ.pos","w");
  FILE * xyzu = fopen("XYZU.pos","w");
  FILE * xyzv = fopen("XYZV.pos","w");
  FILE * xyzc = fopen("XYZC.pos","w");

  fprintf(uvx,"View \"\"{\n");
  fprintf(uvy,"View \"\"{\n");
  fprintf(uvz,"View \"\"{\n");
  fprintf(xyzu,"View \"\"{\n");
  fprintf(xyzv,"View \"\"{\n");
  fprintf(xyzc,"View \"\"{\n");

  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint3>::const_iterator it0 = 
	coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint3>::const_iterator it1 = 
	coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint3>::const_iterator it2 = 
	coordinates.find(t->getVertex(2));
      _gfct[count].p1 = it0->second;
      _gfct[count].p2 = it1->second;
      _gfct[count].p3 = it2->second;
      if ((*it)->geomType() != GEntity::DiscreteSurface){
	reparamMeshVertexOnFace(t->getVertex(0), *it, _gfct[count].gfp1); 
	reparamMeshVertexOnFace(t->getVertex(1), *it, _gfct[count].gfp2); 
	reparamMeshVertexOnFace(t->getVertex(2), *it, _gfct[count].gfp3); 
      }
      _gfct[count].v1 = SPoint3(t->getVertex(0)->x(),t->getVertex(0)->y(),t->getVertex(0)->z());      
      _gfct[count].v2 = SPoint3(t->getVertex(1)->x(),t->getVertex(1)->y(),t->getVertex(1)->z());      
      _gfct[count].v3 = SPoint3(t->getVertex(2)->x(),t->getVertex(2)->y(),t->getVertex(2)->z());      
      _gfct[count].gf = *it;      
      fprintf(xyzu,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      it0->second.x(),it1->second.x(),it2->second.x());
      fprintf(xyzv,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      it0->second.y(),it1->second.y(),it2->second.y());
      const double K = fabs(curvature (t));
      fprintf(xyzc,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              K, K, K);
      
      fprintf(uvx,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->x(), t->getVertex(1)->x(), t->getVertex(2)->x());
      fprintf(uvy,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->y(), t->getVertex(1)->y(), t->getVertex(2)->y());
      fprintf(uvz,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(), it0->second.y(), 0.0,
	      it1->second.x(), it1->second.y(), 0.0,
	      it2->second.x(), it2->second.y(), 0.0,
	      t->getVertex(0)->z(), t->getVertex(1)->z(), t->getVertex(2)->z());
      
      Octree_Insert(&_gfct[count], oct);
      count ++;
    }
  }
  fprintf(uvx,"};\n");
  fclose(uvx);
  fprintf(uvy,"};\n");
  fclose(uvy);
  fprintf(uvz,"};\n");
  fclose(uvz);
  fprintf(xyzu,"};\n");
  fclose(xyzu);
  fprintf(xyzv,"};\n");
  fclose(xyzv);
  fprintf(xyzc,"};\n");
  fclose(xyzc);
  Octree_Arrange(oct);
}

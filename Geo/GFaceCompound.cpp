#include "GFaceCompound.h"
#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "Octree.h"
#include "gmshLinearSystemGmm.h"

static void fixEdgeToValue (GEdge *ed, 
			    double value,
			    gmshAssembler &myAssembler)
{
  myAssembler.fixVertex(ed->getBeginVertex()->mesh_vertices[0],
			0, 1, value);
  myAssembler.fixVertex(ed->getEndVertex()->mesh_vertices[0],
			0, 1, value);
  for (unsigned int i = 0 ; i < ed->mesh_vertices.size(); i++){
    myAssembler.fixVertex(ed->mesh_vertices[i],0, 1, value);
  }
}

static void fixEdgeToValueX (GEdge *ed, 
			    gmshAssembler &myAssembler)
{
  for (unsigned int i = 0 ; i < ed->lines.size(); i++){
    myAssembler.fixVertex(ed->lines[i]->getVertex(0), 0, 1, ed->lines[i]->getVertex(0)->x());
    myAssembler.fixVertex(ed->lines[i]->getVertex(1), 0, 1, ed->lines[i]->getVertex(1)->x());
  }
}

static void fixEdgeToValueY (GEdge *ed, 
			    gmshAssembler &myAssembler)
{
  for (unsigned int i = 0 ; i < ed->lines.size(); i++){
    myAssembler.fixVertex(ed->lines[i]->getVertex(0), 0, 1, ed->lines[i]->getVertex(0)->y());
    myAssembler.fixVertex(ed->lines[i]->getVertex(1), 0, 1, ed->lines[i]->getVertex(1)->y());
  }
}


void GFaceCompound::getBoundingEdges ()
{
  if (_U0.size() && !_U1.size()){
    std::list<GEdge*> :: const_iterator it = _U0.begin();
    for ( ; it != _U0.end() ; ++it){
      //      printf("edge %d\n",(*it)->tag());
      l_edges.push_back(*it);
      (*it)->addFace(this);
    }
    return;
  }

  std::set<GEdge*> _unique;
  std::list<GFace*> :: iterator it = _compound.begin();
  for ( ; it != _compound.end() ; ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*> :: iterator ite = ed.begin();
    for ( ; ite != ed.end() ; ++ite){
      std::set<GEdge*>::iterator itf = _unique.find(*ite);
      if (itf == _unique.end())_unique.insert(*ite);
      else _unique.erase(itf);
    }    
  }    
  std::set<GEdge*>::iterator itf = _unique.begin();
  for ( ; itf != _unique.end() ; ++itf){
    l_edges.push_back(*itf);
    (*itf)->addFace(this);
  }
  
}

GFaceCompound::GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
			     std::list<GEdge*> &U0,
			     std::list<GEdge*> &V0,
			     std::list<GEdge*> &U1,
			     std::list<GEdge*> &V1) :
  GFace(m,tag),_compound(compound),_U0(U0),_U1(U1),_V0(V0),_V1(V1), oct(0)
{
  //printf("%d %d %d %d \n",_U0.size(),_U1.size(),_V0.size(),_V1.size());
  getBoundingEdges();
}

GFaceCompound::~GFaceCompound()
{
  if (oct){
    Octree_Delete(oct);
    delete [] _gfct;
  }
}

void GFaceCompound::parametrize (bool _isU) const
{
  gmshLinearSystemGmm lsys;
  gmshAssembler myAssembler(&lsys);

  if (!_U0.size()){
    std::list<GEdge*> :: const_iterator it = l_edges.begin();
    for ( ; it != l_edges.end() ; ++it){
      if (_isU)fixEdgeToValueX (*it, myAssembler);
      else fixEdgeToValueY (*it, myAssembler);
    }
  }
  else if (!_U1.size()){
    std::list<GEdge*> :: const_iterator it = _U0.begin();
    for ( ; it != _U0.end() ; ++it){
      if (_isU)fixEdgeToValueX (*it, myAssembler);
      else fixEdgeToValueY (*it, myAssembler);
    }
  }
  else{
    if (_isU){
      std::list<GEdge*> :: const_iterator it = _U0.begin();
      for ( ; it != _U0.end() ; ++it){
	fixEdgeToValue (*it, 0.0, myAssembler);
      }
      it = _U1.begin();
      for ( ; it != _U1.end() ; ++it){
	fixEdgeToValue (*it, 1.0, myAssembler);
      }
    }
    else{
      std::list<GEdge*> :: const_iterator it = _V0.begin();
      for ( ; it != _V0.end() ; ++it){
	fixEdgeToValue (*it, 0.0, myAssembler);
      }
      it = _V1.begin();
      for ( ; it != _V1.end() ; ++it){
	fixEdgeToValue (*it, 1.0, myAssembler);
      }
    }
  }

  std::list<GFace*> :: const_iterator it = _compound.begin();
  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0),0, 1);
      myAssembler.numberVertex(t->getVertex(1),0, 1);
      myAssembler.numberVertex(t->getVertex(2),0, 1); 
    }    
  }    
  //  printf("%d %d %d %d\n",_U0.size(),_U1.size(),_V0.size(),_V1.size());
  //  printf("creating term %d dofs numbered %d fixed\n", myAssembler.sizeOfR(),myAssembler.sizeOfF());
  gmshLaplaceTerm laplace (model(), 1.0, 1);
  it = _compound.begin();
  for ( ; it != _compound.end() ; ++it){
    laplace.addToMatrix (myAssembler, *it);
  }    
  lsys.systemSolve();

  it = _compound.begin();
  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      double uu[3], vv[3];
      for (int j = 0; j < 3; j++){
	MVertex *v = t->getVertex(j);
	double value = myAssembler.getDofValue(v,0,1);
	std::map<MVertex*,SPoint2>::iterator itf = coordinates.find(v);
	if (itf == coordinates.end()){
	  SPoint2 p (_isU ? value:0.0,_isU ? 0.0:value);
	  coordinates[v] = p;
	}
	else{
	  if(_isU) itf->second[0]= value;
	  else itf->second[1]= value;
	  uu[j] = itf->second[0];
	  vv[j] = itf->second[1];
	}
      }      
    }   
  }

}

GPoint GFaceCompound::point(double par1, double par2) const
{
  parametrize();
  double U, V;
  MTriangle *t;
  getTriangle (par1, par2, &t, U,V);
  SPoint3 p(0, 0, 0); 
  if (!t) return GPoint(p.x(), p.y(), p.z(), this);
  t->pnt(U, V, 0, p);
  double par[2] = {par1, par2};
  return GPoint(p.x(), p.y(), p.z(), this, par);
}

/*
  computing dX/du and dX/dv
*/

Pair<SVector3,SVector3> GFaceCompound::firstDer(const SPoint2 &param) const
{
  parametrize();
  double U, V;
  MTriangle *t;
  getTriangle(param.x(), param.y(), &t, U,V);
  double jac[3][3];
  t->getJacobian(U, V, 0, jac);
  return Pair<SVector3, SVector3>(SVector3(jac[0][0], jac[0][1], jac[0][2]),
                                  SVector3(jac[1][0], jac[1][1], jac[1][2]));
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
}

static void GFaceCompoundCentroid(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  c[0] = (t->p1.x() + t->p2.x() + t->p3.x())/3.0;
  c[1] = (t->p1.y() + t->p2.y() + t->p3.y())/3.0;
  c[2] = 0.0;
}

static int GFaceCompoundInEle(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  double M[2][2],R[2],X[2];
  const double eps = 1.e-6;
  const SPoint2 p0 = t->p1;
  const SPoint2 p1 = t->p2;
  const SPoint2 p2 = t->p3;
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
                                MTriangle **t, 
                                double &_u, double &_v) const
{
  parametrize();
  
  double uv[3] = {u,v,0};
  GFaceCompoundTriangle *tt = (GFaceCompoundTriangle*)Octree_Search(uv, oct);
  if (!tt){*t = 0; return;}

  *t = tt->t;
  double M[2][2],X[2],R[2];
// const double eps = 1.e-6;
  const SPoint2 p0 = tt->p1;
  const SPoint2 p1 = tt->p2;
  const SPoint2 p2 = tt->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (u - p0.x());
  R[1] = (v - p0.y());
  sys2x2(M,R,X);
  _u = X[0];
  _v = X[1];
  return;
  
//   std::list<GFace*> :: const_iterator it = _compound.begin();
//   for ( ; it != _compound.end() ; ++it){
//     for ( int i=0;i<(*it)->triangles.size() ; ++i){
//       *t = (*it)->triangles[i];
//       std::map<MVertex*,SPoint2>::const_iterator it0 = 
// 	coordinates.find((*t)->getVertex(0));
//       std::map<MVertex*,SPoint2>::const_iterator it1 = 
// 	coordinates.find((*t)->getVertex(1));
//       std::map<MVertex*,SPoint2>::const_iterator it2 = 
// 	coordinates.find((*t)->getVertex(2));
//       const SPoint2 p0 = it0->second;
//       const SPoint2 p1 = it1->second;
//       const SPoint2 p2 = it2->second;
//       M[0][0] = p1.x() - p0.x();
//       M[0][1] = p2.x() - p0.x();
//       M[1][0] = p1.y() - p0.y();
//       M[1][1] = p2.y() - p0.y();
//       R[0] = (u - p0.x());
//       R[1] = (v - p0.y());
//       sys2x2(M,R,X);
//       //      printf("T (%g %g,%g %g,%g %g) %g %g vs %g %g\n",p0.x(),p0.y(),p1.x(),p1.y(),p2.x(),p2.y(),u,v,X[0],X[1]);
//       if (X[0] > -eps && 
// 	  X[1] > -eps && 
// 	  1.-X[0]-X[1] > -eps){
// 	_u = X[0];
// 	_v = X[1];
// 	//	printf("OK -- %g %g\n",_u,_v);
// 	return;
//       }
//     }
//   }
//   printf("NOT OK -- %g %g\n",u,v);
//   *t = 0;
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
	std::map<MVertex*,SPoint2>::const_iterator itj = 
	  coordinates.find(t->getVertex(j));
	bb += SPoint3(itj->second.x(),itj->second.y(),0.0);
      }
      count++;
    }
  }
  _gfct = new GFaceCompoundTriangle[count];
  double origin[3] = {bb.min().x(),bb.min().y(),bb.min().z()};
  double ssize[3] = {bb.max().x()-bb.min().x(),
		     bb.max().y()-bb.min().y(),
		     bb.max().z()-bb.min().z()};
  oct = Octree_Create(10, origin, ssize, GFaceCompoundBB, GFaceCompoundCentroid,
                      GFaceCompoundInEle);

  it = _compound.begin();
  count = 0;

  FILE * uvx = fopen ("UVX.pos","w");
  FILE * uvy = fopen ("UVY.pos","w");
  FILE * uvz = fopen ("UVZ.pos","w");
  FILE * xyzu = fopen("XYZU.pos","w");
  FILE * xyzv = fopen("XYZV.pos","w");

  fprintf(uvx,"View \"\"{\n");
  fprintf(uvy,"View \"\"{\n");
  fprintf(uvz,"View \"\"{\n");
  fprintf(xyzu,"View \"\"{\n");
  fprintf(xyzv,"View \"\"{\n");

  for ( ; it != _compound.end() ; ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint2>::const_iterator it0 = 
	coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint2>::const_iterator it1 = 
	coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint2>::const_iterator it2 = 
	coordinates.find(t->getVertex(2));
      _gfct[count].p1 = it0->second;
      _gfct[count].p2 = it1->second;
      _gfct[count].p3 = it2->second;
      _gfct[count].t = t;      
      fprintf(xyzu,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(),
	      t->getVertex(0)->y(),
	      t->getVertex(0)->z(),
	      t->getVertex(1)->x(),
	      t->getVertex(1)->y(),
	      t->getVertex(1)->z(),
	      t->getVertex(2)->x(),
	      t->getVertex(2)->y(),
	      t->getVertex(2)->z(),
	      it0->second.x(),it1->second.x(),it2->second.x());
      fprintf(xyzv,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(),
	      t->getVertex(0)->y(),
	      t->getVertex(0)->z(),
	      t->getVertex(1)->x(),
	      t->getVertex(1)->y(),
	      t->getVertex(1)->z(),
	      t->getVertex(2)->x(),
	      t->getVertex(2)->y(),
	      t->getVertex(2)->z(),
	      it0->second.y(),it1->second.y(),it2->second.y());
      fprintf(uvx,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(),it0->second.y(),0.0,
	      it1->second.x(),it1->second.y(),0.0,
	      it2->second.x(),it2->second.y(),0.0,
	      t->getVertex(0)->x(),t->getVertex(1)->x(),t->getVertex(2)->x());
      fprintf(uvy,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(),it0->second.y(),0.0,
	      it1->second.x(),it1->second.y(),0.0,
	      it2->second.x(),it2->second.y(),0.0,
	      t->getVertex(0)->y(),t->getVertex(1)->y(),t->getVertex(2)->y());
      fprintf(uvz,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      it0->second.x(),it0->second.y(),0.0,
	      it1->second.x(),it1->second.y(),0.0,
	      it2->second.x(),it2->second.y(),0.0,
	      t->getVertex(0)->z(),t->getVertex(1)->z(),t->getVertex(2)->z());

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
  Octree_Arrange(oct);
}


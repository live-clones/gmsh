// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <queue>
#include "GmshMessage.h"
#include "discreteFace.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "Context.h"
#include "OS.h"
#include "MPoint.h"

#ifndef HAVE_HXT
#include <stack>
#include "meshPartitionObjects.h"
#include "meshPartitionOptions.h"
#include "meshPartition.h"
#include "discreteDiskFace.h"
#if defined(HAVE_METIS)
extern "C" {
#include <metis.h>
}
#endif
#else // HAVE_HXT is true
#include "MElementOctree.h"
#include "Octree.h"
#endif

discreteFace::discreteFace(GModel *model, int num, bool meshable)
  : GFace(model, num), _meshable(meshable)
{
  Surface *s = CreateSurface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

void discreteFace::setBoundEdges(const std::vector<int> &tagEdges)
{
  for (unsigned int i = 0; i != tagEdges.size(); i++){
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge){
      l_edges.push_back(ge);
      l_dirs.push_back(1);
      ge->addFace(this);
    }
    else{
      Msg::Error("Unknown model edge %d", tagEdges[i]);
    }
  }
}

void discreteFace::setBoundEdges(const std::vector<int> &tagEdges,
                                 const std::vector<int> &signEdges)
{
  if(signEdges.size() != tagEdges.size()){
    Msg::Error("Wrong number of edge signs in setBoundEdges");
    setBoundEdges(tagEdges);
  }
  for (unsigned int i = 0; i != tagEdges.size(); i++){
    GEdge *ge = model()->getEdgeByTag(tagEdges[i]);
    if(ge){
      l_edges.push_back(ge);
      l_dirs.push_back(signEdges[i]);
      ge->addFace(this);
    }
    else{
      Msg::Error("Unknown model edge %d", tagEdges[i]);
    }
  }
}


// split old GEdge's
void discreteFace::splitDiscreteEdge(GEdge *de , GVertex *gv, discreteEdge* newE[2])
{
  MVertex *vend = de->getEndVertex()->mesh_vertices[0];

  int mytag = this->model()->getMaxElementaryNumber(1) + 1;
  newE[0] = new discreteEdge (de->model(),mytag,de->getBeginVertex(),gv);
  mytag++;
  newE[1] = new discreteEdge (de->model(),mytag,gv, de->getEndVertex());

  int current = 0;
  std::vector<MLine*> mlines;
  // assumption: the MLine's are sorted
  for (unsigned int i=0;i<de->lines.size();i++){
    MLine *l = de->lines[i];
    mlines.push_back(l);
    if (l->getVertex(1) == gv->mesh_vertices[0] || l->getVertex(1) == vend){
      setupDiscreteEdge(newE[current],mlines,NULL);
      mlines.clear();//
      current++;
    }
  }
  de->getBeginVertex()->delEdge(de);
  de->getEndVertex()->delEdge(de);
  de->mesh_vertices.clear();
  de->lines.clear();

  // We replace de by its 2 parts in every face that is adjacent to de
  std::list<GFace*> faces = de->faces();
  for (std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); ++it){
    GFace *gf = *it;
    if (gf->geomType() == GEntity::DiscreteSurface){
      discreteFace *df = static_cast<discreteFace*> (gf);
      if (df){
	std::vector<int> tagEdges;
	std::list<GEdge*> edges = df->edges();
	for (std::list<GEdge*>::iterator it2 = edges.begin(); it2 != edges.end(); ++it2){
	  GEdge* geit2 = *it2;
	  if (geit2 == de){
	    tagEdges.push_back (newE[0]->tag());
	    tagEdges.push_back (newE[1]->tag());
	  }
	  else tagEdges.push_back (geit2->tag());
	}
	df->l_edges.clear();
	df->setBoundEdges(tagEdges);
      }
      else{
        Msg::Error("splitDiscreteEdge only applies to discrete geometries");
        return;
      }
    }
  }
  de->model()->remove(de);
}


void discreteFace::setupDiscreteVertex(GVertex*dv, MVertex*mv,
                                       std::set<MVertex*>*trash)
{
  mv->setEntity(dv);
  dv->mesh_vertices.push_back(mv);
  this->model()->add(dv);
  dv->points.push_back(new MPoint(dv->mesh_vertices.back()));
  if (trash) trash->insert(mv);
}

void discreteFace::setupDiscreteEdge(discreteEdge*de,std::vector<MLine*>mlines,
                                     std::set<MVertex*>*trash)
{
  this->model()->add(de);// new GEdge
  de->setTopo(mlines);// associated MLine's
  for(unsigned int i=1; i<mlines.size(); i++){
    //not the first vertex of the GEdge (neither the last one)
    mlines[i]->getVertex(0)->setEntity(de);
    de->mesh_vertices.push_back(mlines[i]->getVertex(0));
    if(trash) trash->insert(mlines[i]->getVertex(0));
  }
  de->createGeometry();
  de->getBeginVertex()->addEdge(de);
  de->getEndVertex()->addEdge(de);
}

void discreteFace::writeGEO(FILE *fp)
{
  fprintf(fp, "Discrete Face(%d) = {",tag());
  int count = 0;
  for (std::list<GEdge*>::iterator it = l_edges.begin();
       it != l_edges.end() ;++it){
    if (count == 0) fprintf(fp, "%d", (*it)->tag());
    else fprintf(fp, ",%d", (*it)->tag());
    count ++;
  }
  fprintf(fp, "};\n");
}

static inline bool uv2xi(const MElement* my_ddft, double U[2], double Xi[2])
{
  double M[2][2], R[2];
  const SPoint2 p0 (my_ddft->getVertex(0)->x(),my_ddft->getVertex(0)->y());
  const SPoint2 p1 (my_ddft->getVertex(1)->x(),my_ddft->getVertex(1)->y());
  const SPoint2 p2 (my_ddft->getVertex(2)->x(),my_ddft->getVertex(2)->y());
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (U[0] - p0.x());
  R[1] = (U[1] - p0.y());
  if (!sys2x2(M, R, Xi))return false;
  return true;
}


GPoint discreteFace::point(double par1, double par2) const
{
#ifdef HAVE_HXT
  //  printf("coucou2\n");
  double xy[3]={par1,par2,0};
  double uv[3];
  const MElement *e = _parametrizations[_current_parametrization].oct->find(par1,par2,0.0);
  if (!e){
    //    printf("NAAAAAAN %d %g %g\n",_current_parametrization,par1,par2);
    GPoint gp = GPoint(1.e21,1.e21,1.e21,this,xy);
    gp.setNoSuccess();
    return gp;
  }
  //  printf("OK %d %g %g\n",_current_parametrization,par1,par2);
  //  uv2xi(e,xy,uv);
  e->xyz2uvw(xy,uv);
  //  printf("%g %g\n",uv[0],uv[1]);
  const MTriangle &t3d = _parametrizations[_current_parametrization].t3d[e->getPartition()];
  //  printf("%d %d\n",e->getPartition(), _parametrizations[_current_parametrization].t3d.size() );
  double X=0,Y=0,Z=0;
  double eval[3] = {1.-uv[0]-uv[1],uv[0],uv[1]};

  for(int io=0; io<3; io++){
    X += t3d.getVertex(io)->x()*eval[io];
    Y += t3d.getVertex(io)->y()*eval[io];
    Z += t3d.getVertex(io)->z()*eval[io];
  }
  //  printf("%12.5E %12.5E %12.5E \n",X,Y,Z);
  return GPoint(X,Y,Z,this,xy);
#else
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
#endif
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
  // could be better but it is already ok
  double eps = 1.e-8;
  for (size_t i = 0 ; i< _parametrizations[_current_parametrization].t3d.size();i++){
    const MTriangle &t3d = _parametrizations[_current_parametrization].t3d[i];
    const MTriangle &t2d = _parametrizations[_current_parametrization].t2d[i];

    SVector3 v31 (t3d.getVertex(2)->x()- t3d.getVertex(0)->x(),
		  t3d.getVertex(2)->y()- t3d.getVertex(0)->y(),
		  t3d.getVertex(2)->z()- t3d.getVertex(0)->z());
    SVector3 v21 (t3d.getVertex(1)->x()- t3d.getVertex(0)->x(),
		  t3d.getVertex(1)->y()- t3d.getVertex(0)->y(),
		  t3d.getVertex(1)->z()- t3d.getVertex(0)->z());
    SVector3 vp1 (p.x()-t3d.getVertex(0)->x(),
		  p.y()-t3d.getVertex(0)->y(),
		  p.z()-t3d.getVertex(0)->z());
    SVector3 n = crossprod(v31,v21);
    //    printf("n %g %g %g\n",n.x(),n.y(),n.z());

    double dd = n.norm();
    double dist = fabs(dot(n,vp1))/dd;
    //        printf("%d n %g %g %g looking for %g %g %g (cur %d) dd = %12.5E dist to plane %12.5E\n",i,
    //    	   n.x(),n.y(),n.z(),p.x(),p.y(),p.z(),
    //    	   _current_parametrization,dd, dist);

    if( dist < eps){      
      double xyz[3]={p.x(),p.y(),p.z()};
      double uvw[3];
      t3d.xyz2uvw (xyz,uvw);
      /*
      SVector3 vp2 (p.x()-t3d.getVertex(1)->x(),
		    p.y()-t3d.getVertex(1)->y(),
		    p.z()-t3d.getVertex(1)->z());
      SVector3 vp3 (p.x()-t3d.getVertex(2)->x(),
		    p.y()-t3d.getVertex(2)->y(),
		    p.z()-t3d.getVertex(2)->z());
      SVector3 n12 = crossprod(vp1,vp2);
      SVector3 n23 = crossprod(vp2,vp3);
      SVector3 n13 = crossprod(vp1,vp3);
      double U = n23.norm()/dd;
      double V = n13.norm()/dd;
      double W = n12.norm()/dd;
      */
      double U = 1-uvw[0]-uvw[1];
      double V = uvw[0];
      double W = uvw[1];
      /*
      double XXX =
	U*t3d.getVertex(0)->x()+
	V*t3d.getVertex(1)->x()+
	W*t3d.getVertex(2)->x();
      double YYY =
	U*t3d.getVertex(0)->y()+
	V*t3d.getVertex(1)->y()+
	W*t3d.getVertex(2)->y();
      double ZZZ =
	U*t3d.getVertex(0)->z()+
	V*t3d.getVertex(1)->z()+
	W*t3d.getVertex(2)->z();
      */
      if (U > -eps && V > -eps && W > -eps &&
	  U < 1+eps && V < 1+eps && W < 1+eps){
	const MVertex *v0 = t2d.getVertex(0);
	const MVertex *v1 = t2d.getVertex(1);
	const MVertex *v2 = t2d.getVertex(2);
	double U2 = U*v0->x()+V*v1->x()+W*v2->x();
	double V2 = U*v0->y()+V*v1->y()+W*v2->y();
	GPoint ppw = point(U2,V2);
	SVector3 ppp (ppw.x()-p.x(),ppw.y()-p.y(),ppw.z()-p.z());
	if (ppp.norm() > 1.e-5)Msg::Error ("parFromPoint failed");
	//	const MElement *e = _parametrizations[_current_parametrization].oct->find(U2,V2,0.0);
	//	printf("%g %g %g\n",U,V,W);
	//	//	printf("%p %p\n",e,t2d);
	//	printf("UV = %12.5E %12.5E -- %12.5E %12.5E %12.5E vs %12.5E %12.5E %12.5E vs %12.5E %12.5E %12.5E\n",U2,V2,ppw.x(),ppw.y(),ppw.z(),p.x(),p.y(),p.z(),XXX,YYY,ZZZ);
	return SPoint2(U2,V2);
      }
    }
      
  }
  
  Msg::Error("parFromPoint failed");
  return SPoint2();
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
  Msg::Error("function discreteFace::normal not implemented");
  return SVector3();
}

double discreteFace::curvatureMax(const SPoint2 &param) const
{
  return false;
}

double discreteFace::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                double *curvMax, double *curvMin) const
{
  return false;
}

Pair<SVector3, SVector3> discreteFace::firstDer(const SPoint2 &param) const
{
  MElement *e = _parametrizations[_current_parametrization].oct->find(param.x(),param.y(),0.0);
  if (!e){
    Msg::Warning("discreteFace::firstDer << triangle not found %g %g",param[0],param[1]);
    return Pair<SVector3, SVector3>(SVector3(1,0,0), SVector3(0,1,0));
  }
  const MTriangle &t3d = _parametrizations[_current_parametrization].t3d[e->getPartition()];
  const MVertex *v1 = t3d.getVertex(0);
  const MVertex *v2 = t3d.getVertex(1);
  const MVertex *v3 = t3d.getVertex(2);
  
  double M3D[3][2] = { {v2->x()-v1->x(),v3->x()-v1->x()},
		       {v2->y()-v1->y(),v3->y()-v1->y()},
		       {v2->z()-v1->z(),v3->z()-v1->z()}};
  v1 = e->getVertex(0);
  v2 = e->getVertex(1);
  v3 = e->getVertex(2);

  double M2D[2][2] = { { (v3->y()- v1->y()), -(v3->x()- v1->x())},
		       {-(v2->y()- v1->y()),  (v2->x()- v1->x())}};

  double det = 1./(M2D[0][0]*M2D[1][1]-M2D[1][0]*M2D[0][1]);

  //  printf("det = %12.5E\n",det);
  
  SVector3 dxdu (M3D[0][0]*M2D[0][0]+M3D[0][1]*M2D[1][0],
		 M3D[1][0]*M2D[0][0]+M3D[1][1]*M2D[1][0],
		 M3D[2][0]*M2D[0][0]+M3D[2][1]*M2D[1][0]);
  SVector3 dxdv (M3D[0][0]*M2D[0][1]+M3D[0][1]*M2D[1][1],
		 M3D[1][0]*M2D[0][1]+M3D[1][1]*M2D[1][1],
		 M3D[2][0]*M2D[0][1]+M3D[2][1]*M2D[1][1]);
  dxdu *= det;
  dxdv *= det;
  

  return Pair<SVector3, SVector3>(dxdu,dxdv);
}

void discreteFace::secondDer(const SPoint2 &param,
                             SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  return;
}

void discreteFace::createGeometry()
{
  checkAndFixOrientation();
#ifdef HAVE_HXT
  HXTStatus s = reparametrize_through_hxt ();  
  if (s != HXT_STATUS_OK) {
    Msg::Error ("Impossible to create the geometry of discrete surface %d",tag());
    return;
  }
#else 
#if defined(HAVE_SOLVER) && defined(HAVE_ANN)
  int order = 1;
  int nPart = 2;
  double eta = .5*5/(2.*3.14);
  if (!_atlas.empty()) return;

  double dtSplit = 0.0;

  int id=1, iter=1;
  std::stack<triangulation*>  toSplit;
  std::vector<triangulation*> toParam;

  std::vector<MElement*> tem(triangles.begin(),triangles.end());
  triangulation* init = new triangulation(-1, tem,this);
  init->iter = iter++;
  allEdg2Tri = init->ed2tri;
  toSplit.push(init);
  if((toSplit.top())->genus()!=0 ||
     (toSplit.top())->aspectRatio() > eta ||
     (toSplit.top())->seamPoint){

    while(!toSplit.empty()){
      std::vector<triangulation*> part;
      triangulation* tosplit = toSplit.top();
      toSplit.pop();

      double ts0 = Cpu();
      split(tosplit,part,nPart);
      double ts1 = Cpu();
      dtSplit += ts1-ts0;
      delete tosplit;

      for(unsigned int i=0; i<part.size(); i++){
	part[i]->iter = iter++;
	if(part[i]->genus()!=0 || part[i]->aspectRatio() > eta || part[i]->seamPoint)
	  toSplit.push(part[i]);
	else{
	  toParam.push_back(part[i]);
	  part[i]->idNum=id++;
	}
      }
    }
  }
  else{
    toParam.push_back(toSplit.top());
    toSplit.top()->idNum=id++;
  }
  updateTopology(toParam);

  for(unsigned int i=0; i<toParam.size(); i++){
    fillHoles(toParam[i]);
  }

  for(unsigned int i=0; i<toParam.size(); i++){
    discreteDiskFace *df = new discreteDiskFace
      (this, toParam[i], order, NULL);
    df->replaceEdges(toParam[i]->my_GEdges);
    _atlas.push_back(df);
  }
#endif
#endif
}

void discreteFace::checkAndFixOrientation()
{
  // first of all, all the triangles have to be oriented in the same way
  std::map<MEdge,std::vector<MElement*>,Less_Edge> ed2tri; // edge to 1 or 2 triangle(s)

  for(unsigned int i = 0; i < triangles.size(); ++i){
    MElement *e = triangles[i];
    for(int j = 0; j <  e->getNumEdges() ; j++){
      MEdge ed = e->getEdge(j);
      ed2tri[ed].push_back(e);
    }
  }

  // element to its neighbors
  std::map<MElement*,std::vector<MElement*> > neighbors;
  for (unsigned int i=0; i<triangles.size(); ++i){
    MElement* e = triangles[i];
    for(int j = 0; j < e->getNumEdges(); j++){
      // #improveme: efficiency could be improved by setting neighbors mutually
      std::vector<MElement*> my_mt = ed2tri[e->getEdge(j)];
      if (my_mt.size() > 1){// my_mt.size() = {1;2}
	MElement* neighTri  = my_mt[0] == e ? my_mt[1] : my_mt[0];
	neighbors[e].push_back(neighTri);
      }
    }
  }

  // element for reference orientation
  std::queue<MElement*> checkList;
  // corresponding neighbor element to be checked for its orientation
  std::queue< std::vector<MElement*> > checkLists;
  // todo list
  std::queue<MElement*> my_todo;
  // help to complete todo list
  std::map<MElement*,bool> check_todo;

  my_todo.push(triangles[0]);

  check_todo[triangles[0]]=true;
  while(!my_todo.empty()){

    MElement* myMT = my_todo.front();
    my_todo.pop();

    std::vector<MElement*> myV = neighbors[myMT];
    std::vector<MElement*> myInsertion;

    checkList.push(myMT);

    for(unsigned int i=0; i<myV.size(); ++i){
      if (check_todo.find(myV[i]) == check_todo.end()){
	myInsertion.push_back(myV[i]);
	check_todo[myV[i]] = true;
	my_todo.push(myV[i]);
      }
    }
    checkLists.push(myInsertion);
  }// end while

  while(!checkList.empty() && !checkLists.empty()){
    MElement* current = checkList.front();
    checkList.pop();
    std::vector<MElement*> neigs = checkLists.front();
    checkLists.pop();
    for (unsigned int i=0; i<neigs.size(); i++){
      bool myCond = false;
      for (unsigned int k=0; k<3; k++){
	for (unsigned int j=0; j<3; j++){
	  if (current->getVertex(k) == neigs[i]->getVertex(j)){
	    myCond = true;
	    if (!(current->getVertex(k!=2 ?k+1 : 0 ) ==
                  neigs[i]->getVertex(j!=0 ? j-1 : 2) ||
		  current->getVertex(k!=0 ?k-1 : 2 ) ==
                  neigs[i]->getVertex(j!=2 ? j+1 : 0))){
	      neigs[i]->reverse();
	      //Msg::Info("discreteFace: triangle %d has been reoriented.",
              //          neigs[i]->getNum());
	    }
	    break;
	  }
	}
	if (myCond)
	  break;
      }
    }
  }
}

#if defined(HAVE_HXT)

void discreteFace::mesh(bool verbose)
{
  if(!CTX::instance()->meshDiscrete) return;
  
  std::vector<MTriangle*> _t;
  std::vector<MVertex*> _v;
  std::list<GEdge*> tmp = l_edges;
  for (size_t i = 0; i < _parametrizations.size () ; i++){
    std::list<GEdge*> cur;
    cur.insert(cur.begin(), _parametrizations[i].bnd.begin(),
	       _parametrizations[i].bnd.end());
    l_edges = cur;

    //            Msg::Info("Part %d has %d boundaries",i,cur.size());
    //            for (int k=0;k<_parametrizations[i].bnd.size();k++){
    //                printf("%d : %d --> %d\n",_parametrizations[i].bnd[k]->tag(),_parametrizations[i].bnd[k]->getBeginVertex()->tag(),
    //          	     _parametrizations[i].bnd[k]->getEndVertex()->tag());
    //            }
    _current_parametrization = i;
    triangles.clear();
    mesh_vertices.clear();
    GFace::mesh(verbose);
    _t.insert(_t.begin(), triangles.begin(), triangles.end());
    _v.insert(_v.begin(), mesh_vertices.begin(), mesh_vertices.end());
  }
  triangles = _t;
  mesh_vertices = _v;
  l_edges = tmp;
  meshStatistics.status = GFace::DONE;
}

HXTStatus gmsh2hxt (GFace *gf, HXTMesh **pm,
		    std::map<MVertex*,int> &v2c,
		    std::vector<MVertex*> &c2v){

  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *m;
  HXT_CHECK(hxtMeshCreate(context, &m));
  std::set<MVertex*> all;
  for (size_t i = 0; i<gf->triangles.size(); i++){
    all.insert (gf->triangles[i]->getVertex(0));
    all.insert (gf->triangles[i]->getVertex(1));
    all.insert (gf->triangles[i]->getVertex(2));    
  }
  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(hxtAlignedMalloc(&m->vertices.coord, 4*m->vertices.num*sizeof( double )) );

  size_t count = 0;
  c2v.resize(all.size());
  for (std::set<MVertex*>::iterator it = all.begin(); it != all.end(); it++){
    m->vertices.coord[4*count+0] = (*it)->x();
    m->vertices.coord[4*count+1] = (*it)->y();
    m->vertices.coord[4*count+2] = (*it)->z();
    m->vertices.coord[4*count+3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->triangles.num = m->triangles.size = gf->triangles.size();
  HXT_CHECK( hxtAlignedMalloc(&m->triangles.node, (m->triangles.num)*3*sizeof(uint32_t)) );
  HXT_CHECK( hxtAlignedMalloc(&m->triangles.colors, (m->triangles.num)*sizeof(uint16_t)) );
  for (size_t i = 0; i<gf->triangles.size(); i++){
    m->triangles.node[3*i+0] = v2c[gf->triangles[i]->getVertex(0)];
    m->triangles.node[3*i+1] = v2c[gf->triangles[i]->getVertex(1)];
    m->triangles.node[3*i+2] = v2c[gf->triangles[i]->getVertex(2)];
    m->triangles.colors[i] = gf->tag();
  }

  m->lines.num = m->lines.size = 0;
  
  *pm = m;
  return HXT_STATUS_OK;
}



bool discreteFace::compute_topology_of_partition (int nbColors,
						  int *colors,
						  int *nNodes,
						  int *nodes,
						  double *uv,
						  std::vector<MVertex*> &c2v,
						  std::vector<std::vector<MEdge> > &boundaries)
{
  GModel *gm = model();
 
  std::vector<int> cpt (_parametrizations.size());
  std::vector<MTriangle*> &ts = triangles;
  // make a copy of the geometry and of the parametrization (could be smaller)
  std::map<std::pair<MVertex*,int>,SPoint2> params;
  for (size_t i=0;i<_parametrizations.size();i++){
    cpt[colors[i]] = 0;
    for (int j=nNodes[i];j<nNodes[i+1]; j++){
      MVertex *vert = c2v[nodes[j]];
      double U = uv[2*j+0];
      double V = uv[2*j+1];
      std::pair<MVertex*,int> pp = std::make_pair(vert,i);
      params[pp] = SPoint2(U,V);
    }
  }
  //  std::map<std::pair<MVertex*,int>,SPoint2>::iterator it=params.begin();
  //  for (; it != params.end(); ++it){
  //    printf("%p %d %g %g\n",it->first.first, it->first.second, it->second.x(),  it->second.y());
  //  }
  
  FILE *f = fopen ("atlasP.pos","w");
  fprintf(f,"View \"\"{\n");
  FILE *f2 = fopen ("atlasR.pos","w");
  fprintf(f2,"View \"\"{\n");

  for (size_t i = 0 ; i<ts.size(); i++){
    cpt[colors[i]] ++;
  }    
  for (size_t i=0;i<_parametrizations.size();i++){
    //    _parametrizations[colors[i]].v3d.reserve(3*cpt[colors[i]]);
    //    _parametrizations[colors[i]].v2d.reserve(3*cpt[colors[i]]);
    _parametrizations[colors[i]].t3d.reserve(cpt[colors[i]]);
    _parametrizations[colors[i]].t2d.reserve(cpt[colors[i]]);
  }
  
  for (size_t i = 0 ; i<ts.size(); i++){
    MTriangle *t = ts[i];
    int c = colors[i];
    MVertex *v0= new MVertex(t->getVertex(0)->x(),t->getVertex(0)->y(),t->getVertex(0)->z());
    MVertex *v1= new MVertex(t->getVertex(1)->x(),t->getVertex(1)->y(),t->getVertex(1)->z());
    MVertex *v2= new MVertex(t->getVertex(2)->x(),t->getVertex(2)->y(),t->getVertex(2)->z());
    SPoint2 p0 = params[std::make_pair(t->getVertex(0),c)];
    SPoint2 p1 = params[std::make_pair(t->getVertex(1),c)];
    SPoint2 p2 = params[std::make_pair(t->getVertex(2),c)];
    MVertex *vv0 = new MVertex(p0.x(),p0.y(),0.0);
    MVertex *vv1 = new MVertex(p1.x(),p1.y(),0.0);
    MVertex *vv2 = new MVertex(p2.x(),p2.y(),0.0);

    //    size_t s =  _parametrizations[c].v3d.size();
    //    _parametrizations[c].v3d.push_back(v0);
    //    _parametrizations[c].v3d.push_back(v1);
    //    _parametrizations[c].v3d.push_back(v2);
    //    _parametrizations[c].v2d.push_back(vv0);
    //    _parametrizations[c].v2d.push_back(vv1);
    //    _parametrizations[c].v2d.push_back(vv2);
    size_t s2 =  _parametrizations[c].t3d.size();
    MTriangle t3d (v0,v1,v2);
    MTriangle t2d (vv0,vv1,vv2);
      //    MTriangle t3d(&_parametrizations[c].v3d[s],&_parametrizations[c].v3d[s+1],&_parametrizations[c].v3d[s+2]);
      //    MTriangle t2d(&_parametrizations[c].v2d[s],&_parametrizations[c].v2d[s+1],&_parametrizations[c].v2d[s+2]);
    _parametrizations[c].t3d.push_back(t3d);
    _parametrizations[c].t2d.push_back(t2d);
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
    	    vv0->x()+2.2*c,vv0->y(),vv0->z(),
    	    vv1->x()+2.2*c,vv1->y(),vv1->z(),
    	    vv2->x()+2.2*c,vv2->y(),vv2->z(),c,c,c);
    fprintf(f2,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
    	    v0->x(),v0->y(),v0->z(),
    	    v1->x(),v1->y(),v1->z(),
    	    v2->x(),v2->y(),v2->z(),c,c,c);
  }    
    fprintf(f,"};\n");
    fclose(f);
    fprintf(f2,"};\n");
    fclose(f2);

  for (size_t i=0;i<_parametrizations.size();i++){
    for (size_t j=0;j< _parametrizations[i].t3d.size();j++){
      _parametrizations[i].t3d[j].setPartition(j);
      _parametrizations[i].t2d[j].setPartition(j);
    }
  }
  // compute 1D topology ---------------------------------------------------------  
  
  std::map<MEdge, std::pair<int,int>, Less_Edge> l;
  for (size_t i = 0 ; i<ts.size(); i++){
    MTriangle *t = ts[i];
    int c = colors[i];
    for (int j=0;j<3;j++){
      MEdge e = t->getEdge(j);
      std::map<MEdge, std::pair<int,int> ,  Less_Edge>::iterator  it = l.find(e);
      if (it == l.end()){
	std::pair<int,int> p = std::make_pair(c,(int)-1);
	l[e] = p;
      }
      else {
	if (it->second.first == c)l.erase(it);
	else it->second.second=c;
      }
    }
  }

  std::map<std::pair<int,int> , std::vector<MEdge> > edges;
  {  
    std::map<MEdge, std::pair<int,int> ,  Less_Edge>::iterator it  = l.begin();
    for (; it != l.end(); ++it){
      std::pair<int,int> x = it->second;
      std::pair<int,int> y = std::make_pair(std::min(x.first,x.second),std::max(x.first,x.second));
      std::map<std::pair<int,int> , std::vector<MEdge> >:: iterator itf = edges.find(y);
      if (itf == edges.end()){
	std::vector<MEdge> v; v.push_back(it->first);
	edges [y] = v;
      }
      else {
	itf->second.push_back(it->first);
      }
    }
  }

  // split external edges ---------------------------------------------------------
  {
    std::map<std::pair<int,int> , std::vector<MEdge> >::iterator it =  edges.begin();
    for (; it != edges.end() ; ++it) {
      if (it->first.first != -1)boundaries[it->first.first].insert(boundaries[it->first.first].begin(),
								   it->second.begin(),it->second.end());
      if (it->first.second != -1)boundaries[it->first.second].insert(boundaries[it->first.second].begin(),
								     it->second.begin(),it->second.end());      
    }
  }
  
  // split external edges ---------------------------------------------------------
  {
    std::map<std::pair<int,int> , std::vector<MEdge> >::iterator it =  edges.begin();
    for (; it != edges.end() ; ++it) {
      std::vector< std::vector<MVertex *> >vs;
      SortEdgeConsecutive (it->second, vs);     
      for (size_t k = 0; k< vs.size(); k++){
	std::vector<MVertex*> &v = vs[k];
	MVertex *vs[2] = {v[0],v[v.size()-1]};
	for (int i=0;i<2;i++){
	  if(vs[i]->onWhat()->dim() == 1) {
	    discreteEdge *de = static_cast<discreteEdge*> (vs[i]->onWhat());
	    if (!de)Msg::Error("can only split discrete edges at that point");
	    discreteVertex* gstart = new discreteVertex (gm, gm->getNumVertices() + 1);
	    //	    gm->add(gstart);
	    vs[i]->setEntity(gstart);
	    gstart->mesh_vertices.push_back(vs[i]);
	    discreteEdge* des[2];
	    splitDiscreteEdge(de,gstart,des);
	    Msg::Info("Splitting discrete Edge %d",de->tag());
	  }
	}
      }
    }
  }
  
  // at that point, end vertices of split lines are either classified on GVertex or on GFace
  {
    std::map<std::pair<int,int> , std::vector<MEdge> >::iterator it =  edges.begin();
    for (; it != edges.end() ; ++it) {
      std::vector< std::vector<MVertex *> >vs;
      SortEdgeConsecutive (it->second, vs);
      for (size_t k = 0; k< vs.size(); k++){
	std::vector<MVertex*> &v = vs[k];
	MVertex *ends[2] = {v[0],v[v.size()-1]};
	if( ends[0]->onWhat() == this || ends[1]->onWhat() == this) {
	  for (int i=0;i<2;i++){
	    if (ends[i]->onWhat()==this){
	      discreteVertex* gstart = new discreteVertex (gm, gm->getNumVertices() + 1);
	      gm->add(gstart);
	      ends[i]->setEntity(gstart);
	      gstart->mesh_vertices.push_back(ends[i]);
	    }
	  }
	}
	if (it->first.first != -1){
	  discreteEdge *de = new discreteEdge (gm, gm->getNumEdges() + 1, (GVertex*)ends[0]->onWhat(), (GVertex*)ends[1]->onWhat());
	  Msg::Info("Creation of one internal discrete edge %d (%d %d) to discrete face %d",de->tag(),ends[0]->onWhat()->dim(),ends[1]->onWhat()->dim(),tag());
	  gm->add(de);
	  for (size_t i = 1; i< v.size() -1; i++){
	    v[i]->setEntity(de);
	    de->mesh_vertices.push_back(v[i]);
	  }
	  for (size_t i = 1; i< v.size(); i++)de->lines.push_back(new MLine(v[i-1],v[i]));
	}
      }
    }
  }

  triangles.clear();
  //  std::vector<MVertex*> vvv = mesh_vertices;
  mesh_vertices.clear();
  //  for (size_t i=0;i< vvv.size(); i++)if (vvv[i]->onWhat() == this)mesh_vertices.push_back(vvv[i]);  
  return true;
}

HXTStatus discreteFace::reparametrize_through_hxt (){

  int n =1;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));

  HXTMesh *m;
  std::map<MVertex*,int> v2c;
  std::vector<MVertex*> c2v;
  gmsh2hxt (this, &m, v2c,c2v);

  HXTParametrization *parametrization;
  int *colors, *nNodes, *nodes, nc;
  double *uv;
  HXT_CHECK(hxtParametrizationCreate(m, &parametrization));	    
  HXT_CHECK(hxtParametrizationCompute(parametrization, &colors, &nNodes, &nodes, &uv, &nc));
  HXT_CHECK(hxtParametrizationWrite(parametrization, "hop"));


  _parametrizations.resize(nc);
  std::vector<std::vector<MEdge> > boundaries (nc);
  if (!compute_topology_of_partition (nc,  colors, nNodes, nodes, uv,c2v, boundaries))
    Msg::Warning("Impossible to compute the topology of the %d partitions",nc);
  
  Msg::Info("Face %d split int %d parts",tag(),_parametrizations.size());

  for (size_t i=0;i<_parametrizations.size();i++){
    Less_Edge le;
    std::sort(boundaries[i].begin(),boundaries[i].end(),le);
    std::set<discreteEdge*> des;
    for (GModel::eiter it = model()->firstEdge(); it != model()->lastEdge(); it++){
      for (size_t k=0;k<(*it)->lines.size();k++){
	MEdge e ((*it)->lines[k]->getVertex(0),(*it)->lines[k]->getVertex(1));
	if (std::binary_search (boundaries[i].begin(),boundaries[i].end(),e,le)){
	  discreteEdge *de = static_cast<discreteEdge*>(*it);
	  if (!de)Msg::Error("Reparametrization only works for discrete geometries");
	  des.insert(de);
	}
      }
    }
    _parametrizations[i].bnd.insert (_parametrizations[i].bnd.begin(),
				     des.begin(), des.end());
  }
  
  
  for (size_t i=0;i<_parametrizations.size();i++){
    std::vector<MElement*>temp;
    for (size_t j=0;j<_parametrizations[i].t2d.size();j++){
      temp.push_back(&_parametrizations[i].t2d[j]);
    }
    _parametrizations[i].oct = new MElementOctree (temp);
  }
  HXT_CHECK(hxtParametrizationDelete(&parametrization));	    
  HXT_CHECK(hxtMeshDelete(&m));
  return HXT_STATUS_OK;
}

hxt_reparam_surf::~hxt_reparam_surf () {
  if( oct) delete oct;
}

#else // DO NOT HAVE HXT

void discreteFace::mesh(bool verbose)
{
  if(!_meshable && !CTX::instance()->meshDiscrete) return;

#if defined(HAVE_ANN) && defined(HAVE_SOLVER) && defined(HAVE_MESH)
  for (unsigned int i=0;i<_atlas.size();i++){
    _atlas[i]->mesh(verbose);
  }
  gatherMeshes();
  meshStatistics.status = GFace::DONE;
#endif
}



void discreteFace::split(triangulation* trian,std::vector<triangulation*> &partition,
                         int nPartitions)
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN) && defined(HAVE_METIS)

  int nVertex = trian->tri.size(); // number of elements
  // number of edges, (without the boundary ones)
  int nEdge = trian->ed2tri.size() - trian->borderEdg.size();

  std::vector<int> idx;
  idx.resize(nVertex+1);

  std::vector<int> nbh;
  nbh.resize(2*nEdge);

  idx[0]=0;
  for(int i=0; i<nVertex; i++){// triangle by triangle

    MElement* current = trian->tri[i];

    int temp = 0;
    for(int j=0; j<3; j++){ // edge by edge
      MEdge ed = current->getEdge(j);
      int nEd = trian->ed2tri[ed].size();
      if (nEd > 1){
	std::vector<int> local = trian->ed2tri[ed];
	nbh[idx[i]+temp] = local[0] == i ? local[1] : local[0];
	temp++;
      }
    }// end for j
    idx[i+1] = idx[i]+temp;

  }// end for i

  int edgeCut;
  std::vector<int> part;
  part.resize(nVertex);
  int zero = 0;
  METIS_PartGraphRecursive(&nVertex, &(idx[0]), &(nbh[0]), NULL, NULL,
                           &zero, &zero, &nPartitions, &zero, &edgeCut, &(part[0]));

  std::map<MElement*,int> el2part;
  std::vector<std::vector<MElement*> > elem;
  elem.resize(nPartitions);
  for(int i=0; i<nVertex; i++){
    elem[part[i]].push_back(trian->tri[i]);
    el2part[trian->tri[i]] = part[i];
  }

  //check connectivity
  for(int p=0; p<nPartitions; p++){// part by part
    // current elements of the p-th part
    std::set<MElement*> celem(elem[p].begin(),elem[p].end());
    // todo list, for adjacency check - in order to check the connectivity of the part
    std::queue<MElement*> my_todo;
    // help to complete todo list
    std::map<MElement*,bool> check_todo;
    std::vector<MElement*> temp = elem[p];
    MElement* starter = temp[0];
    my_todo.push(starter);
    check_todo[starter] = true;
    // if the element is connected to the previous ones, it is removed from the set
    celem.erase(starter);
    while(!my_todo.empty()){
      MElement* current = my_todo.front();
      my_todo.pop();
      for(int j=0; j<3; j++){// adjacency from edges
	MEdge ed = current->getEdge(j);
	if(trian->ed2tri[ed].size()>1){
	  const std::vector<int> &oldnums = trian->ed2tri[ed];
	  int on = trian->tri[oldnums[0]] == current ? oldnums[1] : oldnums[0];
	  if(check_todo.find(trian->tri[on])==check_todo.end() &&
             el2part[trian->tri[on]]==p){
	    my_todo.push(trian->tri[on]);
	    check_todo[trian->tri[on]] = true;
	    celem.erase(trian->tri[on]);
	  }
	}
      }
    }
    // if the set is empty, it means that the part was connected
    if(!celem.empty()){
      std::vector<MElement*> relem(celem.begin(),celem.end());// new part
      // updating the id part of the element belonging to the new part
      for(unsigned int ie=0; ie<relem.size(); ie++)
	el2part[relem[ie]] = nPartitions;
      nPartitions++;
      elem.push_back(relem);
      // updating the elements of the current part
      std::set<MElement*> _elem(elem[p].begin(),elem[p].end());
      for(std::set<MElement*>::iterator its = celem.begin(); its != celem.end(); ++its)
	_elem.erase(*its);
      elem[p].clear();
      std::vector<MElement*> upe(_elem.begin(),_elem.end());
      elem[p] = upe;
    }
  }
  // new triangulation of the connected parts
  for(int i=0; i<nPartitions; i++)
    partition.push_back(new triangulation(i, elem[i],this));
#endif
}

void discreteFace::updateTopology(std::vector<triangulation*>&partition)
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN) && defined(HAVE_METIS)
  //------------------------------------------------------//
  //---- setting topology, i.e. GEdge's and GVertex's ----//
  //------------------------------------------------------//
  int nPartitions = partition.size();
  // vertices that do not belong to the GFace anymore
  std::set<MVertex*> todelete;
  // initial GEdges of the GFace (to be updated)
  std::set<GEdge*> gGEdges(l_edges.begin(),l_edges.end());

  // each part is going to be compared with the other ones
  for(int i = 0; i < nPartitions; i++){
    // edges defining the border(s) of the i-th new triangulation
    const std::set<MEdge,Less_Edge> &bordi = partition[i]->borderEdg;
    // compare to the ii-th partitions, with ii > i since ii < i have already
    // been compared
    for(int ii=i+1; ii<nPartitions; ii++){
      std::map<MVertex*,MLine*> v02edg; //first vertex of the MLine
      std::set<MVertex*> first, last;
      // edges defining the border(s) of the ii-th new triangulation
      const std::set<MEdge,Less_Edge> &bii = partition[ii]->borderEdg;
      // MEdge by MEdge of the i-th triangulation border(s)
      for(std::set<MEdge,Less_Edge>::iterator ie = bordi.begin();
          ie != bordi.end(); ++ie){
        // if the border edge is common to both triangulations, then it is a
        // future GEdge - composed of MLine's
	if(bii.find(*ie)!=bii.end()){
	  v02edg[ie->getVertex(0)] = new MLine(ie->getVertex(0),
                                               ie->getVertex(1));
	  // identifying first and last vertices of the future GEdge's, if any
	  if( first.find(ie->getVertex(1)) != first.end() )
	    first.erase(ie->getVertex(1));
	  else
	    last.insert(ie->getVertex(1));
	  if( last.find(ie->getVertex(0)) != last.end() )
	    last.erase(ie->getVertex(0));
	  else
	    first.insert(ie->getVertex(0));
	}
      }

      // creation of the GEdge's from new MLine's
      while(!first.empty()){// starting with nonloop GEdge's
	GVertex *v[2]; // a GEdge is defined by two GVertex
	std::vector<MLine*> myLines; // MLine's of the current nonloop GEdge
	std::set<MVertex*>::iterator itf = first.begin();
	MVertex* cv0 = *itf; // starting with a first vertex
	while(last.find(cv0) == last.end()){ // until reaching the corresponding last vertex
	  myLines.push_back(v02edg[cv0]); // push the correspong MLine
	  v02edg.erase(cv0); // and erasing it from the map
	  cv0 = myLines.back()->getVertex(1); // next vertex
	}// end last
	std::vector<MVertex*> mvt;
	mvt.resize(2);
	mvt[0] = *itf;
	mvt[1] = cv0;
	// creation of the GVertex, for new nonloop GEdge's
	for(int imvt=0; imvt<2; imvt++){
          // find the old GEdge that has the current new GVertex
	  std::set<GEdge*>::iterator oe = gGEdges.begin();
	  while(oe !=gGEdges.end() && mvt[imvt]->onWhat() != *oe &&
                mvt[imvt]->onWhat() != (*oe)->getBeginVertex() &&
                mvt[imvt]->onWhat() != (*oe)->getEndVertex())
	    ++oe;

          // not on an existing GEdge: new internal GVertex
	  if (oe == gGEdges.end()){
	    v[imvt] = new discreteVertex (this->model(),
                                          model()->getMaxElementaryNumber(0) + 1);
	    setupDiscreteVertex(v[imvt],mvt[imvt],&todelete);
	  }
	  else{// on an existing GEdge
            // the new GVertex can already exist; if it is the case, there is no
            // need to create a new one
	    GEdge* onit = *oe;
	    if(mvt[imvt] == onit->getBeginVertex()->mesh_vertices[0])
	      v[imvt] = onit->getBeginVertex();
	    else if (mvt[imvt] == onit->getEndVertex()->mesh_vertices[0])
	      v[imvt] = onit->getEndVertex();
	    else{
	      v[imvt] = new discreteVertex (this->model(),
                                            model()->getMaxElementaryNumber(0) + 1);
	      setupDiscreteVertex(v[imvt],mvt[imvt],NULL);
	      discreteEdge* de[2];
	      splitDiscreteEdge(onit,v[imvt],de);
	      gGEdges.erase(onit);
	      gGEdges.insert(de[0]);
	      gGEdges.insert(de[1]);
	    }
	  }
	}
	// the new GEdge can be created with its GVertex
	discreteEdge* internalE = new discreteEdge
          (this->model(), this->model()->getMaxElementaryNumber(1) + 1,v[0],v[1]);
	setupDiscreteEdge(internalE,myLines,&todelete);
	gGEdges.insert(internalE);

	first.erase(itf);// next first vertex of a nonloop GEdge
      }

      // remaining MLines for 'loop'GEdge's
      while(!v02edg.empty()){
	discreteVertex* v;
	std::vector<MLine*> my_MLines;
	MVertex* cv0 = v02edg.begin()->first;
	while(v02edg.find(cv0) != v02edg.end()){// a loop GEdge
	  my_MLines.push_back(v02edg[cv0]);// current MLine of the loop
	  v02edg.erase(cv0);// update the container
	  cv0 = my_MLines.back()->getVertex(1);// next MLine of the loop
	}
	v = new discreteVertex (this->model(),model()->getMaxElementaryNumber(0) + 1);
	setupDiscreteVertex(v,cv0,&todelete);
	discreteEdge* gloop = new discreteEdge
          (this->model(),this->model()->getMaxElementaryNumber(1) + 1,v,v);
	setupDiscreteEdge(gloop,my_MLines,&todelete);
	gGEdges.insert(gloop);
      }
    }
  }

  // adding old-updated bounding GEdge's to the corresponding partitions
  for(std::set<GEdge*>::iterator le=gGEdges.begin(); le!=gGEdges.end(); ++le){
    GEdge* ile = *le;
    MEdge edTest = ile->lines.front()->getEdge(0);
    for(int i=0; i<nPartitions; i++){
      std::set<MEdge,Less_Edge> bordi = partition[i]->borderEdg;
      if(bordi.find(edTest)!=bordi.end()){
	partition[i]->my_GEdges.push_back(ile);
	//break;
      }
    }
  }

  // update GFace mesh_vertices
  std::vector<MVertex*> newMV;
  for(unsigned int imv=0; imv<this->mesh_vertices.size(); imv++){
    MVertex* current = mesh_vertices[imv];
    std::set<MVertex*>::iterator itmv = todelete.find(current);
    if (itmv==todelete.end()) newMV.push_back(current);
  }
  this->mesh_vertices.clear();
  this->mesh_vertices = newMV;
#endif
}

void discreteFace::fillHoles(triangulation* trian)
{
  // #improveme moving the center
#if defined(HAVE_SOLVER) && defined(HAVE_ANN)
  std::map<double,std::vector<MVertex*> > bords = trian->bord;
  std::map<double,std::vector<MVertex*> >::reverse_iterator it = bords.rbegin();
  ++it;
  for(; it!=bords.rend(); ++it){
    SPoint3 x(0.,0.,0.);
    std::vector<MVertex*> mv = it->second;
    for(unsigned int j=0; j<mv.size(); j++){
      SPoint3 v0, v1;
      if(j==0){
	SPoint3 v(mv[mv.size()-1]->x(),mv[mv.size()-1]->y(),mv[mv.size()-1]->z());
	v0 = v;
	SPoint3 v_(mv[j+1]->x(),mv[j+1]->y(),mv[j+1]->z());
	v1 = v_;
      }
      else if (j==mv.size()-1){
	SPoint3 v(mv[j-1]->x(),mv[j-1]->y(),mv[j-1]->z());
	v0 = v;
	SPoint3 v_(mv[0]->x(),mv[0]->y(),mv[0]->z());
	v1 = v_;
      }
      else{
	SPoint3 v(mv[j-1]->x(),mv[j-1]->y(),mv[j-1]->z());
	v0 = v;
	SPoint3 v_(mv[j+1]->x(),mv[j+1]->y(),mv[j+1]->z());
	v1 = v_;
      }
      SPoint3 vpp(mv[j]->x(),mv[j]->y(),mv[j]->z());
      SVector3 v00(vpp,v0);
      SVector3 v11(v1,vpp);
      x += vpp*(norm(v00)+norm(v11));
    }
    x *= .5/it->first;
    MVertex* center = new MVertex(x.x(),x.y(),x.z());
    this->mesh_vertices.push_back(center);
    trian->vert.insert(center);
    SVector3 nmean(0.,0.,0.);
    for(unsigned int j=1; j<mv.size(); j++){
      addTriangle(trian,new MTriangle(mv[j],mv[j-1],center));
      SVector3 temp0(center->x()-mv[j]->x(),
                     center->y()-mv[j]->y(),
                     center->z()-mv[j]->z());
      SVector3 temp1(center->x()-mv[j-1]->x(),
                     center->y()-mv[j-1]->y(),
                     center->z()-mv[j-1]->z());
      SVector3 temp(crossprod(temp0,temp1));
      nmean += temp;
    }
    addTriangle(trian,new MTriangle(mv[0],mv[mv.size()-1],center));
    SVector3 temp0(center->x()-mv[0]->x(),
                   center->y()-mv[0]->y(),
                   center->z()-mv[0]->z());
    SVector3 temp1(center->x()-mv[mv.size()-1]->x(),
                   center->y()-mv[mv.size()-1]->y(),
                   center->z()-mv[mv.size()-1]->z());
    SVector3 temp(crossprod(temp0,temp1));
    nmean += temp;
    nmean *= 1./(norm(nmean)*mv.size());
    MVertex update(center->x()+nmean.x(),
                   center->y()+nmean.y(),
                   center->z()+nmean.z());
    *center = update;
    center->setEntity(this);
  }
#endif
}

void discreteFace::addTriangle(triangulation* trian, MTriangle* t)
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN)
  for(int i=0; i<3; i++){
    MEdge ed = t->getEdge(i);
    int n = trian->tri.size();
    trian->fillingHoles.insert(n);
    trian->ed2tri[ed].push_back(n);
  }
  trian->tri.push_back(t);
#endif
}

void discreteFace::gatherMeshes()
{
#if defined(HAVE_ANN) && defined(HAVE_SOLVER)
  for (unsigned int i=0;i<triangles.size();i++)delete triangles[i];
  for (unsigned int i=0;i<mesh_vertices.size();i++)delete mesh_vertices[i];
  triangles.clear();
  mesh_vertices.clear();
  for (unsigned int i=0;i<_atlas.size();i++){
    for (unsigned int j=0;j<_atlas[i]->triangles.size(); j++){
      MTriangle *t = _atlas[i]->triangles[j];
      SPoint2 p0,p1,p2;
      reparamMeshVertexOnFace(t->getVertex(0),_atlas[i], p0);
      reparamMeshVertexOnFace(t->getVertex(1),_atlas[i], p1);
      reparamMeshVertexOnFace(t->getVertex(2),_atlas[i], p2);
      SPoint2 pc = (p0+p1+p2)*(1./3.0);
      discreteDiskFaceTriangle *mt=NULL;
      double xi, eta;
      // FIXME THAT SUCKS !!!!!
      _atlas[i]->getTriangleUV(pc.x(),pc.y(), &mt, xi,eta);
      if (mt && mt->gf)mt->gf->triangles.push_back(t);
      else
	Msg::Warning("FILE %s LINE %d Triangle from atlas part %u has no "
		     "classification for (u;v)=(%f;%f)",__FILE__,
		     __LINE__, i+1, pc.x(), pc.y());
    }
    _atlas[i]->triangles.clear();

    for (unsigned int j=0;j<_atlas[i]->mesh_vertices.size(); j++){
      MVertex *v = _atlas[i]->mesh_vertices[j];
      double pu,pv; v->getParameter(0,pu);v->getParameter(1,pv);
      discreteDiskFaceTriangle *mt;
      double xi, eta;
      _atlas[i]->getTriangleUV(pu,pv, &mt, xi,eta);
      if(mt && mt->gf){
	v->setEntity(mt->gf);
	// here we should recompute on the CAD if necessary
	mt->gf->mesh_vertices.push_back(v);
      }
      else
        Msg::Warning("FILE %s LINE %d Vertex has no classification",
                     __FILE__, __LINE__);
    }
    _atlas[i]->mesh_vertices.clear();
  }
#endif
}
#endif


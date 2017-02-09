// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteFace.h"
#include "discreteDiskFace.h"
#include "GModelIO_GEO.h"
#include "GFaceCompound.h"
#include "Context.h"
#include "OS.h"
#include <stack>
#include <queue>
#include <complex>
// #include <cmath>

#if defined(HAVE_PETSC)
#include "linearSystemPETSc.h"
#endif

#include "MPoint.h"

#if defined(HAVE_METIS)
extern "C" {
#include <metis.h>
}
#endif

static inline double getAlpha(MTriangle* tri, int edj)
{
  double alpha;
  if (edj==0)
    alpha = 0.;
  else{
    MVertex *v0, *v1, *v2;

    v0 = tri->getVertex(0);
    v1 = tri->getVertex(1);
    v2 = tri->getVertex(2);

    SVector3 a(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    SVector3 b(v2->x()-v0->x(),v2->y()-v0->y(),v2->z()-v0->z());
    SVector3 n = crossprod(a,b); n.normalize();

    v0 = tri->getEdge(0).getSortedVertex(0);
    v1 = tri->getEdge(0).getSortedVertex(1);
    SVector3 U(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    U.normalize();
    SVector3 V = crossprod(n,U); V.normalize();

    v0 = tri->getEdge(edj).getSortedVertex(0);
    v1 = tri->getEdge(edj).getSortedVertex(1);
    SVector3 e(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    e.normalize();

    alpha = std::atan2(dot(e,V),dot(e,U));
  }

  return alpha;

}


static inline void crouzeixRaviart(const std::vector<double> &U,std::vector<double> &F){

  F.resize(3);

  double xsi[3] = {0.,1.,0.};
  double eta[3] = {0.,0.,1.};

  for(int i=0; i<3; i++)
    F[i] =  U[0] * (1.-2.*eta[i]) + U[1] * (2.*(xsi[i]+eta[i])-1.) + U[2] * (1-2.*xsi[i]);

}




discreteFace::discreteFace(GModel *model, int num) : GFace(model, num)
{
  Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
  Tree_Add(model->getGEOInternals()->Surfaces, &s);
  meshStatistics.status = GFace::DONE;
}

void discreteFace::setBoundEdges(GModel *gm, std::vector<int> tagEdges)
{
  for (std::vector<int>::iterator it = tagEdges.begin(); it != tagEdges.end(); it++){
    GEdge *ge = gm->getEdgeByTag(*it);
    l_edges.push_back(ge);
    l_dirs.push_back(1);
    ge->addFace(this);
  }
}

void discreteFace::findEdges(std::map<MEdge, std::vector<int>, Less_Edge> &map_edges)
{
  std::set<MEdge, Less_Edge> bound_edges;
  for (unsigned int iFace = 0; iFace  < getNumMeshElements(); iFace++) {
    MElement *e = getMeshElement(iFace);
    for (int iEdge = 0; iEdge < e->getNumEdges(); iEdge++) {
      MEdge tmp_edge = e->getEdge(iEdge);
      std::set<MEdge, Less_Edge >::iterator itset = bound_edges.find(tmp_edge);
      if(itset == bound_edges.end())
        bound_edges.insert(tmp_edge);
      else
        bound_edges.erase(itset);
    }
  }

  // for the boundary edges, associate the tag of the discrete face
  for (std::set<MEdge, Less_Edge>::iterator itv = bound_edges.begin();
       itv != bound_edges.end(); ++itv){
    std::map<MEdge, std::vector<int>, Less_Edge >::iterator itmap = map_edges.find(*itv);
    if (itmap == map_edges.end()){
      std::vector<int> tagFaces;
      tagFaces.push_back(tag());
      map_edges.insert(std::make_pair(*itv, tagFaces));
    }
    else{
      std::vector<int> tagFaces = itmap->second;
      tagFaces.push_back(tag());
      itmap->second = tagFaces;
    }
  }
}

GPoint discreteFace::point(double par1, double par2) const
{
  Msg::Error("Cannot evaluate point on discrete face");
  return GPoint();
}

SPoint2 discreteFace::parFromPoint(const SPoint3 &p, bool onSurface) const
{
  return SPoint2();
}

SVector3 discreteFace::normal(const SPoint2 &param) const
{
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
  return Pair<SVector3, SVector3>();
}

void discreteFace::secondDer(const SPoint2 &param,
                             SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  return;
}

void discreteFace::createGeometry()
{

  checkAndFixOrientation();


#if defined(HAVE_SOLVER) && defined(HAVE_ANN)



  int order = 1;
  int nPart = 2;
  double eta = .5*5/(2.*3.14);
  if (!_atlas.empty())return;

  double dtSplit = 0.0;

  int id=1, iter=1;
  std::stack<triangulation*>  toSplit;
  std::vector<triangulation*> toParam;

  std::vector<MElement*> tem(triangles.begin(),triangles.end());
  triangulation* init = new triangulation(-1, tem,this);
  init->iter = iter++;
  allEdg2Tri = init->ed2tri;
  toSplit.push(init);
  //  printf("%12.5E\n",(toSplit.top())->aspectRatio() );
  if((toSplit.top())->genus()!=0 ||
     (toSplit.top())->aspectRatio() > eta ||
     (toSplit.top())->seamPoint){

    while( !toSplit.empty()){
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
      }// end for i
    }// !.empty()
  }// end if it is not disk-like
  else{
    toParam.push_back(toSplit.top());
    toSplit.top()->idNum=id++;
  }
  updateTopology(toParam);


  /*
  FILE* debug = Fopen("tralala-init.pos","w");
  fprintf(debug,"View \"discreteEdges\"{\n");
  for(unsigned int j=0; j<toParam.size(); j++){

    std::list<GEdge*> ge = toParam[j]->my_GEdges;
    for(std::list<GEdge*>::iterator it = ge.begin(); it!=ge.end(); ++it){
      if((*it)->tag()==112 ){

	std::vector<MLine*> ml = (*it)->lines;
	printf("___(init) map %d, ge %d___ (%p)\n",j+1,(*it)->tag(),(*it));
	for(unsigned int i=0; i<ml.size(); i++){
	  ml[i]->writePOS(debug,true,false,false,false,false,false,1.,(*it)->tag());
	  printf("%d[%d;%d]--",ml[i]->getNum(),ml[i]->getVertex(0)->getNum(),ml[i]->getVertex(1)->getNum());
	}
	printf("\n");

      }

    }
  }
  fprintf(debug,"};");
  fclose(debug);
  */

  for(unsigned int i=0; i<toParam.size(); i++){

    fillHoles(toParam[i]);
    //sprintf(name,"mapFilled%d.pos",i);
    //toParam[i]->print(name, toParam[i]->idNum);
  }


  for(unsigned int i=0; i<toParam.size(); i++){
    discreteDiskFace *df = new discreteDiskFace (this,toParam[i], order,(_CAD.empty() ? NULL : &_CAD));
    df->printAtlasMesh();
    df->printParamMesh();
    //df->putOnView(tag(), i, true,true);
    df->replaceEdges(toParam[i]->my_GEdges);
    _atlas.push_back(df);
  }
  complex_crossField();
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
      else {
	if (_CAD.empty())triangles.push_back(t);
	else
	  Msg::Warning ("FILE %s LINE %d Triangle from atlas part %u has no classification for (u;v)=(%f;%f)",__FILE__,__LINE__,i+1,pc.x(),pc.y());
      }
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
      else Msg::Warning ("FILE %s LINE %d Vertex has no classification",__FILE__,__LINE__);
    }
    _atlas[i]->mesh_vertices.clear();
  }
#endif
}

void discreteFace::mesh(bool verbose)
{
#if defined(HAVE_ANN) && defined(HAVE_SOLVER) && defined(HAVE_MESH)
  for(unsigned int j=0; j<_atlas.size(); j++){

    std::list<GEdge*> ge = _atlas[j]->edges();
    for(std::list<GEdge*>::iterator it = ge.begin(); it!=ge.end(); ++it){

      char myname[256];
      sprintf(myname,"tralala%d_%d.pos",(*it)->tag(),j+1);
      FILE* debug = Fopen(myname,"w");
      fprintf(debug,"View \"discreteEdges\"{\n");
      std::vector<MLine*> ml = (*it)->lines;

      //printf("___map %d (%d), ge %d___ (%p)\n",j+1,_atlas[j]->tag(),(*it)->tag(),(*it));
      for(unsigned int i=0; i<ml.size(); i++){
	ml[i]->writePOS(debug,false,true,false,false,false,false,1.,(*it)->tag());
	//printf("%d[%d;%d]--",ml[i]->getNum(),ml[i]->getVertex(0)->getNum(),ml[i]->getVertex(1)->getNum());
      }
      //printf("\n");

      fprintf(debug,"};");
      fclose(debug);
    }
  }

  if (!CTX::instance()->meshDiscrete) return;

  //Msg::Info("Discrete Face %d is going to be meshed",tag());
  for (unsigned int i=0;i<_atlas.size();i++){
    //    {
      //      void openProblemsON(void);
      //      if (tag() == 3) openProblemsON();
      //    }
    _atlas[i]->mesh(verbose);
    //    {
    //      void openProblemsOFF(void);
    //      if (tag()==3) openProblemsOFF();
    //    }
    /*
      const char *name = "atlas%d";
      char filename[256];
      sprintf(filename,name,i);t0
      _atlas[i]->printPhysicalMesh(filename);*/
  }

  gatherMeshes();
  meshStatistics.status = GFace::DONE;
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
    for(int j=0; j<e->getNumEdges(); j++){ // #improveme: efficiency could be improved by setting neighbors mutually
      std::vector<MElement*> my_mt = ed2tri[e->getEdge(j)];
      if (my_mt.size() > 1){// my_mt.size() = {1;2}
	MElement* neighTri  = my_mt[0] == e ? my_mt[1] : my_mt[0];
	neighbors[e].push_back(neighTri);
      }
    }
  }

  // queue: first in, first out
  std::queue<MElement*> checkList; // element for reference orientation
  std::queue< std::vector<MElement*> > checkLists; // corresponding neighbor element to be checked for its orientation
  std::queue<MElement*> my_todo; // todo list
  std::map<MElement*,bool> check_todo; // help to complete todo list

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
	    if (!(current->getVertex(k!=2 ?k+1 : 0 ) == neigs[i]->getVertex(j!=0 ? j-1 : 2) ||
		  current->getVertex(k!=0 ?k-1 : 2 ) == neigs[i]->getVertex(j!=2 ? j+1 : 0))){
	      neigs[i]->reverse();
	      //Msg::Info("discreteFace: triangle %d has been reoriented.",neigs[i]->getNum());
	    }
	    break;
	  }
	}
	if (myCond)
	  break;
      }
    } // end for unsigned int i
  } // end while
}


void discreteFace::setupDiscreteVertex(GVertex*dv,MVertex*mv,std::set<MVertex*>*trash){
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
  for(unsigned int i=1; i<mlines.size(); i++){//not the first vertex of the GEdge (neither the last one)
    mlines[i]->getVertex(0)->setEntity(de);
    de->mesh_vertices.push_back(mlines[i]->getVertex(0));
    if(trash) trash->insert(mlines[i]->getVertex(0));
  }
  de->createGeometry();
  de->getBeginVertex()->addEdge(de);
  de->getEndVertex()->addEdge(de);

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
	df->setBoundEdges (df->model(), tagEdges);
      }
      else Msg::Fatal("discreteFace::splitDiscreteEdge, This only applies to discrete geometries");
    }
  }
  de->model()->remove(de);
}


void discreteFace::split(triangulation* trian,std::vector<triangulation*> &partition,
                         int nPartitions)
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN) && defined(HAVE_METIS)

  int nVertex = trian->tri.size(); // number of elements
  int nEdge = trian->ed2tri.size() - trian->borderEdg.size();// number of edges, (without the boundary ones)

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
  METIS_PartGraphRecursive(&nVertex,&(idx[0]),&(nbh[0]),NULL,NULL,&zero,&zero,&nPartitions,&zero,&edgeCut,&(part[0]));

  std::map<MElement*,int> el2part;
  std::vector<std::vector<MElement*> > elem;
  elem.resize(nPartitions);
  for(int i=0; i<nVertex; i++){
    elem[part[i]].push_back(trian->tri[i]);
    el2part[trian->tri[i]] = part[i];
  }

  //check connectivity
  for(int p=0; p<nPartitions; p++){// part by part
    std::set<MElement*> celem(elem[p].begin(),elem[p].end());// current elements of the p-th part
    std::queue<MElement*> my_todo; // todo list, for adjacency check - in order to check the connectivity of the part
    std::map<MElement*,bool> check_todo; // help to complete todo list
    std::vector<MElement*> temp = elem[p];
    MElement* starter = temp[0];
    my_todo.push(starter);
    check_todo[starter] = true;
    celem.erase(starter);// if the element is connected to the previous ones, it is removed from the set
    while(!my_todo.empty()){
      MElement* current = my_todo.front();
      my_todo.pop();
      for(int j=0; j<3; j++){// adjacency from edges
	MEdge ed = current->getEdge(j);
	if(trian->ed2tri[ed].size()>1){
	  const std::vector<int> &oldnums = trian->ed2tri[ed];
	  int on = trian->tri[oldnums[0]] == current ? oldnums[1] : oldnums[0];
	  if(check_todo.find(trian->tri[on])==check_todo.end() && el2part[trian->tri[on]]==p){
	    my_todo.push(trian->tri[on]);
	    check_todo[trian->tri[on]] = true;
	    celem.erase(trian->tri[on]);
	  }
	}
      }// end for j
    }// end while
    if(!celem.empty()){// if the set is empty, it means that the part was connected
      //Msg::Info("discreteFace::split(), a partition (%d) is not connected: it is going to be fixed.",p);
      std::vector<MElement*> relem(celem.begin(),celem.end());// new part
      for(unsigned int ie=0; ie<relem.size(); ie++)// updating the id part of the element belonging to the new part
	el2part[relem[ie]] = nPartitions;
      nPartitions++;
      elem.push_back(relem);
      std::set<MElement*> _elem(elem[p].begin(),elem[p].end());// updating the elements of the current part
      for(std::set<MElement*>::iterator its=celem.begin(); its!=celem.end(); ++its)
	_elem.erase(*its);
      elem[p].clear();
      std::vector<MElement*> upe(_elem.begin(),_elem.end());
      elem[p] = upe;
    }
  }// end for p
  for(int i=0; i<nPartitions; i++)// new triangulation of the connected parts
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
  std::set<MVertex*> todelete; // vertices that do not belong to the GFace anymore
  std::set<GEdge*> gGEdges(l_edges.begin(),l_edges.end());// initial GEdges of the GFace (to be updated)

  for(int i=0; i<nPartitions; i++){// each part is going to be compared with the other ones
    const std::set<MEdge,Less_Edge> &bordi = partition[i]->borderEdg;// edges defining the border(s) of the i-th new triangulation
    for(int ii=i+1; ii<nPartitions; ii++){// compare to the ii-th partitions, with ii > i since ii < i have already been compared
      std::map<MVertex*,MLine*> v02edg;//first vertex of the MLine
      std::set<MVertex*> first, last;
      const std::set<MEdge,Less_Edge> &bii = partition[ii]->borderEdg;// edges defining the border(s) of the ii-th new triangulation
      for(std::set<MEdge,Less_Edge>::iterator ie = bordi.begin(); ie != bordi.end(); ++ie){// MEdge by MEdge of the i-th triangulation border(s)
	if(bii.find(*ie)!=bii.end()){// if the border edge is common to both triangulations, then it is a future GEdge - composed of MLine's
	  v02edg[ie->getVertex(0)] = new MLine(ie->getVertex(0),ie->getVertex(1));// a new MLine is created

	  // identifying first and last vertices of the future GEdge's, if any
	  if( first.find(ie->getVertex(1)) != first.end() )
	    first.erase(ie->getVertex(1));
	  else
	    last.insert(ie->getVertex(1));
	  if( last.find(ie->getVertex(0)) != last.end() )
	    last.erase(ie->getVertex(0));
	  else
	    first.insert(ie->getVertex(0));
	}// end bii.find
      }//end for ie

      //---- creation of the GEdge's from new MLine's ----//
      while(!first.empty()){// starting with nonloop GEdge's
	GVertex *v[2];// a GEdge is defined by two GVertex
	std::vector<MLine*> myLines;// MLine's of the current nonloop GEdge
	std::set<MVertex*>::iterator itf = first.begin();
	MVertex* cv0 = *itf;// starting with a first vertex
	while(last.find(cv0) == last.end()){// until reaching the corresponding last vertex
	  myLines.push_back(v02edg[cv0]);// push the correspong MLine
	  v02edg.erase(cv0);// and erasing it from the map
	  cv0 = myLines.back()->getVertex(1);// next vertex
	}// end last
	std::vector<MVertex*> mvt;
	mvt.resize(2);
	mvt[0] = *itf;
	mvt[1] = cv0;
	// creation of the GVertex, for new nonloop GEdge's
	for(int imvt=0; imvt<2; imvt++){
	  std::set<GEdge*>::iterator oe=gGEdges.begin();// find the old GEdge that has the current new GVertex
	  while(oe !=gGEdges.end() && mvt[imvt]->onWhat() != *oe && mvt[imvt]->onWhat() != (*oe)->getBeginVertex() && mvt[imvt]->onWhat() != (*oe)->getEndVertex())
	    ++oe;


	  if (oe == gGEdges.end()){// not on an existing GEdge: new internal GVertex
	    v[imvt] = new discreteVertex (this->model(),model()->getMaxElementaryNumber(0) + 1);
	    setupDiscreteVertex(v[imvt],mvt[imvt],&todelete);
	  }
	  else{// on an existing GEdge
	    GEdge* onit = *oe;// the new GVertex can already exist; if it is the case, there is no need to create a new one
	    if(mvt[imvt] == onit->getBeginVertex()->mesh_vertices[0])
	      v[imvt] = onit->getBeginVertex();
	    else if (mvt[imvt] == onit->getEndVertex()->mesh_vertices[0])
	      v[imvt] = onit->getEndVertex();
	    else{
	      v[imvt] = new discreteVertex (this->model(),model()->getMaxElementaryNumber(0) + 1);
	      setupDiscreteVertex(v[imvt],mvt[imvt],NULL);
	      discreteEdge* de[2];
	      splitDiscreteEdge(onit,v[imvt],de);
	      gGEdges.erase(onit);
	      gGEdges.insert(de[0]);
	      gGEdges.insert(de[1]);
	    }// end if-elseif-else
	  }// end else oe==end()
	}// end imvt
	// the new GEdge can be created with its GVertex
	discreteEdge* internalE = new discreteEdge (this->model(),this->model()->getMaxElementaryNumber(1) + 1,v[0],v[1]);
	setupDiscreteEdge(internalE,myLines,&todelete);
	gGEdges.insert(internalE);

	first.erase(itf);// next first vertex of a nonloop GEdge
      }//end while first.empty()

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
	discreteEdge* gloop = new discreteEdge (this->model(),this->model()->getMaxElementaryNumber(1) + 1,v,v);
	setupDiscreteEdge(gloop,my_MLines,&todelete);
	gGEdges.insert(gloop);
      }// end while v02edg.empty()
    }//end for ii
  }// end for i


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
{// #improveme moving the center
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
      SVector3 temp0(center->x()-mv[j]->x(),center->y()-mv[j]->y(),center->z()-mv[j]->z());
      SVector3 temp1(center->x()-mv[j-1]->x(),center->y()-mv[j-1]->y(),center->z()-mv[j-1]->z());
      SVector3 temp(crossprod(temp0,temp1));
      nmean += temp;
    }
    addTriangle(trian,new MTriangle(mv[0],mv[mv.size()-1],center));
    SVector3 temp0(center->x()-mv[0]->x(),center->y()-mv[0]->y(),center->z()-mv[0]->z());
    SVector3 temp1(center->x()-mv[mv.size()-1]->x(),center->y()-mv[mv.size()-1]->y(),center->z()-mv[mv.size()-1]->z());
    SVector3 temp(crossprod(temp0,temp1));
    nmean += temp;
    nmean *= 1./(norm(nmean)*mv.size());
    MVertex update(center->x()+nmean.x(),center->y()+nmean.y(),center->z()+nmean.z());
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



void discreteFace::complex_crossField()
{
#if defined(HAVE_SOLVER)
  // COMPLEX linear system
  linearSystem<std::complex<double> > * lsys;

#ifdef HAVE_PETSC
#ifdef PETSC_USE_COMPLEX
  lsys = new linearSystemPETSc<std::complex<double> >;
#else
  Msg::Error("Petsc complex is required (we do need complex in discreteFace::complex_crossField())");
  return;
#endif
#else
  Msg::Error("Petsc is required (we do need complex in discreteFace::crossField())");
  return;
#endif

  std::complex<double> i1(0,1);
  dofManager<std::complex<double> > myAssembler(lsys);

  std::map<MEdge,int,Less_Edge> ed2key;
  for (unsigned int i=0; i<triangles.size(); i++){

    MTriangle* tri = triangles[i];
    for(int j=0; j<3; j++){

      MEdge ed = tri->getEdge(j);
      std::vector<int> iTri = allEdg2Tri[ed];
      int mini = iTri[0];
      if (iTri.size()>1)
	mini = iTri[0] < iTri[1] ? iTri[0] : iTri[1];
      else
	myAssembler.fixDof(3*mini+j,0,std::complex<double>(1)); // #tocheck

      int num,s;
      triangles[mini]->getEdgeInfo(ed,num,s);
      myAssembler.numberDof(3*mini+num,0);
      ed2key[ed] = 3*mini+num;
    }// end for j
  }// end for unsigned int i


  double grad[3][3] = {{0.,-2.,0.},{2.,2.,0.},{-2.,0.,0.}};
  for (unsigned int i=0; i<triangles.size(); i++){

    MTriangle* tri = triangles[i];

    double jac[3][3];
    double invjac[3][3];
    double dJac = tri->getJacobian(0., 0., 0., jac);
    inv3x3(jac, invjac);

    for(int j=0; j<3; j++){

      double alpha_j = getAlpha(tri,j);

      std::complex<double> ej(std::exp(4.*i1*alpha_j));
      Dof R(ed2key[tri->getEdge(j)],0);
      for(int k=0; k<3; k++){

	double alpha_k = getAlpha(tri,k);

	std::complex<double> ek(std::exp(-4.*i1*alpha_k));
	std::complex<double> K_jk = 0.;
	for (int l=0; l<3; l++)
	  for(int jj=0; jj<3; jj++)
	    for(int kk=0; kk<3; kk++)
	      K_jk += grad[j][jj] * invjac[l][jj] * invjac[l][kk] * grad[k][kk];
	K_jk *= ej*ek*dJac/2.;

	Dof C(ed2key[tri->getEdge(k)],0);
	myAssembler.assemble(R,C,K_jk);
      }// end for k

    }// end for j

  }// end for unsigned int


  lsys->systemSolve();
  FILE* myfile = Fopen("crossField.pos","w");
  fprintf(myfile,"View \"cross\"{\n");
  for(unsigned int i=0; i<triangles.size(); i++){
    fprintf(myfile,"VT(");
    MTriangle* tri = triangles[i];
    MEdge ed = tri->getEdge(0);

    MVertex *v0, *v1, *v2;

    v0 = tri->getVertex(0);
    v1 = tri->getVertex(1);
    v2 = tri->getVertex(2);

    SVector3 a(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    SVector3 b(v2->x()-v0->x(),v2->y()-v0->y(),v2->z()-v0->z());
    SVector3 n = crossprod(a,b); n.normalize();

    v0 = ed.getSortedVertex(0);
    v1 = ed.getSortedVertex(1);
    SVector3 e(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    e.normalize();
    SVector3 d = crossprod(n,e); d.normalize();

    std::vector<double> U; U.resize(3);
    std::vector<double> V; V.resize(3);
    for(int j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",tri->getVertex(j)->x(),tri->getVertex(j)->y(),tri->getVertex(j)->z());
      if (j<2) fprintf(myfile,",");
      MEdge ed = tri->getEdge(j);
      std::complex<double> fstar; // edge basis
      myAssembler.getDofValue(ed2key[ed],0,fstar); // conjugate dof in the local edge basis
      double alpha = getAlpha(tri,j); // triangle basis
      std::complex<double> F(std::exp(4.*i1*alpha));
      F *= std::conj(fstar); // dof of the local tri basis
      U[j] = std::real(F);
      V[j] = std::imag(F);
    }
    fprintf(myfile,")");
    std::vector<double> Fu, Fv;
    crouzeixRaviart(U,Fu);
    crouzeixRaviart(V,Fv);
    fprintf(myfile,"{");
    for(int j=0; j<3; j++){
      double u = Fu[j], v = Fv[j]; double theta = std::atan2(v,u)/4.;
      SVector3 cf(cos(theta)*e.x()+sin(theta)*d.x(),cos(theta)*e.y()+sin(theta)*d.y(),cos(theta)*e.z()+sin(theta)*d.z());
      cf = cf*sqrt(u*u+v*v);
      fprintf(myfile,"%f,%f,%f",cf.x(),cf.y(),cf.z());
      if (j<2) fprintf(myfile,",");
    }
    fprintf(myfile,"};\n");
  }
  fprintf(myfile,"};");
  fclose(myfile);
#endif
}




void discreteFace::crossField()
{
#if defined(HAVE_SOLVER)
  // linear system
  linearSystem<double> * lsys;

#ifdef HAVE_PETSC
  lsys = new linearSystemPETSc<double>;
#else
  Msg::Fatal("Petsc is required ");
#endif

  dofManager<double> myAssembler(lsys);

  std::map<MEdge,int,Less_Edge> ed2key;
  for (unsigned int i=0; i<triangles.size(); i++){

    MTriangle* tri = triangles[i];
    for(int j=0; j<3; j++){

      MEdge ed = tri->getEdge(j);
      std::vector<int> iTri = allEdg2Tri[ed];
      int mini = iTri[0];
      if (iTri.size()>1)
	mini = iTri[0] < iTri[1] ? iTri[0] : iTri[1];
      else{
	//printf("CL: ed[%f,%f]--[%f,%f]\t Theta: %f \n",ed.getSortedVertex(0)->x(),ed.getSortedVertex(0)->y(),ed.getSortedVertex(1)->x(),ed.getSortedVertex(1)->y(),alpha*180./M_PI);
	myAssembler.fixDof(3*mini+j,0,1.); // setting theta and not Theta
	myAssembler.fixDof(3*mini+j,1,0.);
      }

      int num,s;
      triangles[mini]->getEdgeInfo(ed,num,s);
      myAssembler.numberDof(3*mini+num,0); // u, not U
      myAssembler.numberDof(3*mini+num,1); // v, not V
      ed2key[ed] = 3*mini+num;
    }// end for j
  }// end for unsigned int i

  double grad[3][3] = {{0.,-2.,0.},{2.,2.,0.},{-2.,0.,0.}};
  for (unsigned int i=0; i<triangles.size(); i++){

    MTriangle* tri = triangles[i];

    double jac[3][3];
    double invjac[3][3];
    double dJac = tri->getJacobian(0., 0., 0., jac);
    inv3x3(jac, invjac);

    for(int j=0; j<3; j++){

      double alpha_j = getAlpha(tri,j);

      Dof Ru(ed2key[tri->getEdge(j)],0);
      Dof Rv(ed2key[tri->getEdge(j)],1);
      for(int k=0; k<3; k++){

	double alpha_k = getAlpha(tri,k);

	Dof Cu(ed2key[tri->getEdge(k)],0);
	Dof Cv(ed2key[tri->getEdge(k)],1);

	double K_jk = 0.;
	for (int l=0; l<3; l++)
	  for(int jj=0; jj<3; jj++)
	    for(int kk=0; kk<3; kk++)
	      K_jk += grad[j][jj] * invjac[l][jj] * invjac[l][kk] * grad[k][kk];
	K_jk *= dJac/2.;
	//printf("%f\t",K_jk);
	//printf("%f \t %f \n %f \t %f \n",cos(4.*(alpha_j-alpha_k))*K_jk,sin(4.*(alpha_j-alpha_k))*K_jk,sin(4.*(alpha_k-alpha_j))*K_jk,cos(4.*(alpha_j-alpha_k))*K_jk);


	myAssembler.assemble(Ru,Cu,cos(4.*(alpha_j-alpha_k))*K_jk);
	myAssembler.assemble(Ru,Cv,sin(4.*(alpha_j-alpha_k))*K_jk);
	myAssembler.assemble(Rv,Cu,sin(4.*(alpha_k-alpha_j))*K_jk);
	myAssembler.assemble(Rv,Cv,cos(4.*(alpha_j-alpha_k))*K_jk);
      }// end for k
      //printf("\n");

    }// end for j
    //printf("\n");
  }// end for unsigned int


  lsys->systemSolve();
  FILE* myfile = Fopen("crossField.pos","w");
  fprintf(myfile,"View \"cross\"{\n");
  for(unsigned int i=0; i<triangles.size(); i++){
    fprintf(myfile,"VT(");
    MTriangle* tri = triangles[i];
    MEdge ed = tri->getEdge(0);

    MVertex *v0, *v1, *v2;

    v0 = tri->getVertex(0);
    v1 = tri->getVertex(1);
    v2 = tri->getVertex(2);

    SVector3 a(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    SVector3 b(v2->x()-v0->x(),v2->y()-v0->y(),v2->z()-v0->z());
    SVector3 n = crossprod(a,b); n.normalize();

    v0 = ed.getSortedVertex(0);
    v1 = ed.getSortedVertex(1);
    SVector3 e(v1->x()-v0->x(),v1->y()-v0->y(),v1->z()-v0->z());
    e.normalize();
    //printf("e=(%f %f)\n",e.x(),e.y());
    SVector3 d = crossprod(n,e); d.normalize();
    //printf("d=(%f %f)\n",d.x(),d.y());


    std::vector<double> U; U.resize(3);
    std::vector<double> V; V.resize(3);
    for(int j=0; j<3; j++){
      fprintf(myfile,"%f,%f,%f",tri->getVertex(j)->x(),tri->getVertex(j)->y(),tri->getVertex(j)->z());
      if (j<2) fprintf(myfile,",");
      MEdge ed = tri->getEdge(j);
      double  u, v;// edge basis
      myAssembler.getDofValue(ed2key[ed],0,u);// u
      myAssembler.getDofValue(ed2key[ed],1,v);// v
      if(std::abs(u*u+v*v-1)>1e-12)
	printf("/!\\ ---> warning unit vector \t %f  \n",sqrt(u*u+v*v));
      double alpha = getAlpha(tri,j);// triangle basis
      U[j] = cos(4.*alpha)*u - sin(4.*alpha)*v;// U, not u
      V[j] = sin(4.*alpha)*u + cos(4.*alpha)*v;// V, not v
      //printf("sol: ed%d[%f,%f]--[%f,%f] \t Theta = %f (tri) ~ theta = %f (ed) ~ alpha = %f ~u=%f, v=%f VS U=%f, V=%f \n",j,ed.getSortedVertex(0)->x(),ed.getSortedVertex(0)->y(),ed.getSortedVertex(1)->x(),ed.getSortedVertex(1)->y(),std::atan2(V[j],U[j])*180./(4.*M_PI),std::atan2(v,u)*180./(4.*M_PI),alpha*180./M_PI,u,v,U[j],V[j]);
    }
    fprintf(myfile,")");
    std::vector<double> Fu, Fv;
    crouzeixRaviart(U,Fu);
    crouzeixRaviart(V,Fv);
    fprintf(myfile,"{");
    for(int j=0; j<3; j++){
      double u = Fu[j], v = Fv[j]; double theta = std::atan2(v,u)/4.;
      //printf("theta_%d = %f\n",j,theta*180./M_PI);
      SVector3 cf(cos(theta)*e.x()+sin(theta)*d.x(),cos(theta)*e.y()+sin(theta)*d.y(),cos(theta)*e.z()+sin(theta)*d.z());
      //cf = cf*sqrt(u*u+v*v);
      fprintf(myfile,"%f,%f,%f",cf.x(),cf.y(),cf.z());//cos(theta)*e.x()-sin(theta)*e.y(),sin(theta)*e.x()+cos(theta)*e.y(),e.z());

      if( std::abs(dot(cf,n)) > 1e-12)
	printf("/!\\ ---> warning orthogonality \t %f \n",dot(cf,n));
      if (j<2) fprintf(myfile,",");
    }
    fprintf(myfile,"};\n");
  }
  fprintf(myfile,"};");
  fclose(myfile);
#endif
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

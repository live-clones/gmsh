// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteFace.h"
#include "discreteDiskFace.h"
#include "Geo.h"
#include "GFaceCompound.h"
#include "Context.h"
#include "OS.h"
#include <stack>
#include <queue>

#if defined(HAVE_METIS)
extern "C" {
#include <metis.h>
}
#endif


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
  int order = 1;
  int nPart = 2;
  double eta = 5/(2.*3.14);


#if defined(HAVE_SOLVER) && defined(HAVE_ANN)

  if (!_atlas.empty())return;

  int id=1;
  std::stack<triangulation*>  toSplit;
  std::vector<triangulation*> toParam;
  std::vector<MElement*> tem(triangles.begin(),triangles.end());

  triangulation* init = new triangulation(-1, tem,this);
  toSplit.push(init);
  if((toSplit.top())->genus()!=0 || (toSplit.top())->aspectRatio() > eta || (toSplit.top())->seamPoint){


    while( !toSplit.empty()){
      std::vector<triangulation*> part;
      triangulation* tosplit = toSplit.top();
      toSplit.pop();
      //      printf("genus %d ar %12.5E\n",tosplit->genus(), tosplit->aspectRatio());
      //      getchar();
      split(tosplit,part,nPart);
      delete tosplit;

      for(unsigned int i=0; i<part.size(); i++){
	if(part[i]->genus()!=0 || part[i]->aspectRatio() > eta || part[i]->seamPoint)
	  toSplit.push(part[i]);
	else{
	  toParam.push_back(part[i]);
	  part[i]->idNum=id++;
	  //	  printf("part %d is OK\n",  part[i]->idNum);
	}
      }// end for i
    }// !.empty()
  }// end if it is not disk-like
  else{
    toParam.push_back(toSplit.top());
    toSplit.top()->idNum=id++;
  }
  double t1 = Cpu();
  printf("split done\n");
  updateTopology(toParam);
  double t2 = Cpu();
  printf("topology done in %8.3f sec\n",t2-t1);

  for(unsigned int i=0; i<toParam.size(); i++){
    printf("MAP(%d) : aspect ratio = %12.5E\n",toParam[i]->idNum,toParam[i]->aspectRatio());
    char name[256];
    sprintf(name,"map%d.pos",i);
    toParam[i]->print(name,i);
    fillHoles(toParam[i]);
    sprintf(name,"mapFilled%d.pos",i);
    toParam[i]->print(name, toParam[i]->idNum);
  }
  for(unsigned int i=0; i<toParam.size(); i++){
    std::vector<MElement*> mytri = toParam[i]->tri;
    discreteDiskFace *df = new discreteDiskFace (this,toParam[i], order,(_CAD.empty() ? NULL : &_CAD));
    df->replaceEdges(toParam[i]->my_GEdges);
    _atlas.push_back(df);
  }

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
      _atlas[i]->getTriangleUV(pc.x(),pc.y(), &mt, xi,eta);
      if (mt && mt->gf)mt->gf->triangles.push_back(t);
      else Msg::Warning ("FILE %s LINE %d Triangle from atlas part %u has no classification for (u;v)=(%f;%f)",__FILE__,__LINE__,i+1,pc.x(),pc.y());


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
  if (!CTX::instance()->meshDiscrete) return;
  for (unsigned int i=0;i<_atlas.size();i++){
    Msg::Info("Discrete Face %d is going to be meshed",i);
    printAtlasMesh(_atlas[i]->discrete_triangles,i);
    _atlas[i]->mesh(verbose);
    //printAtlasMesh(_atlas[i],i);
  }

  gatherMeshes();
  meshStatistics.status = GFace::DONE;
#endif
}

void discreteFace::printAtlasMesh(std::vector<MElement*> elm, int I)
{

  std::map<MVertex*,int> mv2int;
  char buffer[256];
  sprintf(buffer,"atlas_mesh%d.msh",I);
  FILE* pmesh = Fopen(buffer,"w");

  std::set<MVertex*> meshvertices;

  for(unsigned int i=0; i<elm.size(); ++i){
    MElement* tri = elm[i];
    for(unsigned int j=0; j<3; j++)
      if (meshvertices.find(tri->getVertex(j))==meshvertices.end()) meshvertices.insert(tri->getVertex(j));
  }

  fprintf(pmesh,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n%u\n",(unsigned int)meshvertices.size());
  int count = 1;
  for(std::set<MVertex*>::iterator it = meshvertices.begin(); it!=meshvertices.end(); ++it){
    fprintf(pmesh,"%d %f %f %f\n",count,(*it)->x(),(*it)->y(),(*it)->z());
    mv2int[*it] = count;
    count++;
  }
  fprintf(pmesh,"$EndNodes\n$Elements\n%u\n",(unsigned int)elm.size());
  for(unsigned int i=0; i<elm.size(); i++){
    MElement* tri = elm[i];
    fprintf(pmesh,"%d 2 2 0 0",i+1);
    for(int j=0; j<3; j++){
      MVertex* mv = tri->getVertex(j);
      fprintf(pmesh," %d",mv2int[mv]);
    }
    fprintf(pmesh,"\n");
  }
  fprintf(pmesh,"$EndElements\n");
  fclose(pmesh);

}



void discreteFace::printAtlasMesh(discreteDiskFace* ddf, int I)
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN)
  std::map<MVertex*,int> mv2int;
  char buffer[16];
  sprintf(buffer,"atlas_mesh%d.msh",I);
  FILE* pmesh = Fopen(buffer,"w");

  std::set<MVertex*> meshvertices;

  for(unsigned int i=0; i<ddf->triangles.size(); ++i){
    MTriangle* tri = ddf->triangles[i];
    for(unsigned int j=0; j<3; j++)
      if (meshvertices.find(tri->getVertex(j))==meshvertices.end()) meshvertices.insert(tri->getVertex(j));
  }

  fprintf(pmesh,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n%u\n",(unsigned int)meshvertices.size());
  int count = 1;
  for(std::set<MVertex*>::iterator it = meshvertices.begin(); it!=meshvertices.end(); ++it){
    fprintf(pmesh,"%d %f %f %f\n",count,(*it)->x(),(*it)->y(),(*it)->z());
    mv2int[*it] = count;
    count++;
  }
  fprintf(pmesh,"$EndNodes\n$Elements\n%u\n",(unsigned int)ddf->triangles.size());
  for(unsigned int i=0; i<ddf->triangles.size(); i++){
    MTriangle* tri = ddf->triangles[i];
    fprintf(pmesh,"%d 2 2 0 0",i+1);
    for(int j=0; j<3; j++){
      MVertex* mv = tri->getVertex(j);
      fprintf(pmesh," %d",mv2int[mv]);
    }
    fprintf(pmesh,"\n");
  }
  fprintf(pmesh,"$EndElements\n");
  fclose(pmesh);
#endif
}


void discreteFace::checkAndFixOrientation(){

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
  dv->mesh_vertices.push_back(mv);
  mv->setEntity(dv);
  this->model()->add(dv);
  if (trash) trash->insert(mv);
}

void discreteFace::setupDiscreteEdge(discreteEdge*de,std::vector<MLine*>mlines,std::set<MVertex*>*trash){
  this->model()->add(de);// new GEdge
  de->lines = mlines;// associated MLine's
  for(unsigned int i=1; i<mlines.size(); i++){//not the first vertex of the GEdge (neither the last one)
    mlines[i]->getVertex(0)->setEntity(de);
    de->mesh_vertices.push_back(mlines[i]->getVertex(0));
    if(trash) trash->insert(mlines[i]->getVertex(0));
  }
  de->createGeometry();
  if(de->getBeginVertex()->mesh_vertices[0]!=de->lines[0]->getVertex(0))// small hack ... #mark
    de->reverse();
}


// split old GEdge's
void discreteFace::splitDiscreteEdge ( GEdge *de , GVertex *gv, discreteEdge* newE[2]){

  MVertex *vend = de->getEndVertex()->mesh_vertices[0];

  newE[0] = new discreteEdge (de->model(),NEWLINE(),de->getBeginVertex(),gv);
  newE[1] = new discreteEdge (de->model(),NEWLINE(),gv, de->getEndVertex());

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


void discreteFace::split(triangulation* trian,std::vector<triangulation*> &partition,int nPartitions)
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
	  std::vector<int> oldnums = trian->ed2tri[ed];
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
      Msg::Info("discreteFace::split(), a partition (%d) is not connected: it is going to be fixed.",p);
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

  for(int i=0; i<nPartitions; i++){// each part is going ot be compared with the other ones
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
	    v[imvt] = new discreteVertex (this->model(),NEWPOINT());
	    setupDiscreteVertex(v[imvt],mvt[imvt],&todelete);
	  }
	  else{// on an existing GEdge
	    GEdge* onit = *oe;// the new GVertex can already exist; if it is the case, there is no need to create a new one
	    if(mvt[imvt] == onit->getBeginVertex()->mesh_vertices[0])
	      v[imvt] = onit->getBeginVertex();
	    else if (mvt[imvt] == onit->getEndVertex()->mesh_vertices[0])
	      v[imvt] = onit->getEndVertex();
	    else{
	      v[imvt] = new discreteVertex (this->model(),NEWPOINT());
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
	discreteEdge* internalE = new discreteEdge (this->model(),NEWLINE(),v[0],v[1]);
	//	printf("creating new discrete edge %d with %d lines (%p %p)\n", internalE->tag(), myLines.size(),v[0],v[1]);
	setupDiscreteEdge(internalE,myLines,&todelete);
	partition[i]->my_GEdges.push_back(internalE);
	partition[ii]->my_GEdges.push_back(internalE);

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
	v = new discreteVertex (this->model(),NEWPOINT());
	setupDiscreteVertex(v,cv0,&todelete);
	discreteEdge* gloop = new discreteEdge (this->model(),NEWLINE(),v,v);
	setupDiscreteEdge(gloop,my_MLines,&todelete);
	partition[i]->my_GEdges.push_back(gloop);
	partition[ii]->my_GEdges.push_back(gloop);
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
	break;
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

void discreteFace::bisectionEdg(triangulation* trian)
{
  std::map<MEdge,double,Less_Edge> ed2angle;
  std::map<double,std::vector<MEdge> > ed2refine;
  /*
    checkEdges
    for each ed in ed2refine
    ...while ed exists
    ......terminal from lepp(ed)
    ......refine terminal
    ......update ed2refine
  */
  int count = 1;
  checkEdgesBis(trian,ed2refine,ed2angle);
  while(!ed2refine.empty()){
    //for(it = ed2refine.rbegin(); it != ed2refine.rend(); ++it){
    std::map<double,std::vector<MEdge> >::reverse_iterator it = ed2refine.rbegin();
    double key = it->first;
    std::vector<MEdge> & ved = it->second;
    while(!ved.empty()){
      //for(unsigned int i=0; i<ved.size(); i++){
      MEdge ed = ved[0];
      while(ed2angle.find(ed) != ed2angle.end()){
	MEdge terminal = lepp(trian,ed);
	ed2angle.erase(terminal);
	std::vector<MEdge> ed2update;
	refineTriangles(trian,terminal,ed2update);
	updateEd2refineBis(trian,ed2angle,ed2update,ed2refine);
	printAtlasMesh(trian->tri,-count++);
      }// end while exists
      ed2refine[key].erase(ved.begin());
      ved = ed2refine[key];
    }// end for unsigned
    ed2refine.erase(key);
  }// end for it

}

bool discreteFace::checkEdges(triangulation* trian,std::map<double,std::vector<MEdge> >& ed2refine,std::map<MEdge,double,Less_Edge>& ed2angle)
{

  for(unsigned int i=0; i<trian->tri.size(); i++){
    MElement* t = trian->tri[i];
    std::vector<MEdge> eds;
    eds.push_back(t->getEdge(0));eds.push_back(t->getEdge(1));eds.push_back(t->getEdge(2));
    for(int j=0; j<3; j++){
      if(trian->ed2tri[eds[j]].size()>1){
      MEdge ed1 = eds[j+1>2?j-2:j+1];
      MEdge ed2 = eds[j+2>2?j-1:j+2];
      SVector3 v1(ed1.getVertex(0)->x()-ed1.getVertex(1)->x(),
		  ed1.getVertex(0)->y()-ed1.getVertex(1)->y(),
		  ed1.getVertex(0)->z()-ed1.getVertex(1)->z());
      SVector3 v2(ed2.getVertex(1)->x()-ed2.getVertex(0)->x(),
		  ed2.getVertex(1)->y()-ed2.getVertex(0)->y(),
		  ed2.getVertex(1)->z()-ed2.getVertex(0)->z());
      double dotp = dot(v1,v2);
      double lp = ed1.length()*ed2.length();
      std::map<MEdge,double,Less_Edge>::iterator check = ed2angle.find(eds[j]);
      if(check!=ed2angle.end()){
	ed2angle[eds[j]] += std::acos(dotp/lp);
	if(ed2angle[eds[j]]>M_PI)
	  ed2refine[eds[j].length()].push_back(eds[j]);
	else
	  ed2angle.erase(eds[j]);
      }
      else
	  ed2angle[eds[j]] = std::acos(dotp/lp);
      }//end if size()>1
    }// end for j
  }//end for tri
  return !(ed2refine.empty());
}


bool discreteFace::checkEdgesBis(triangulation* trian,std::map<double,std::vector<MEdge> >& ed2refine,std::map<MEdge,double,Less_Edge>& ed2angle)
{

  for(unsigned int i=0; i<trian->tri.size(); i++){
    MElement* t = trian->tri[i];
    std::vector<MEdge> eds;
    eds.push_back(t->getEdge(0));eds.push_back(t->getEdge(1));eds.push_back(t->getEdge(2));
    for(int j=0; j<3; j++){
      MEdge ed1 = eds[j+1>2?j-2:j+1];
      MEdge ed2 = eds[j+2>2?j-1:j+2];
      SVector3 v1(ed1.getVertex(0)->x()-ed1.getVertex(1)->x(),
		  ed1.getVertex(0)->y()-ed1.getVertex(1)->y(),
		  ed1.getVertex(0)->z()-ed1.getVertex(1)->z());
      SVector3 v2(ed2.getVertex(1)->x()-ed2.getVertex(0)->x(),
		  ed2.getVertex(1)->y()-ed2.getVertex(0)->y(),
		  ed2.getVertex(1)->z()-ed2.getVertex(0)->z());
      double dotp = dot(v1,v2);
      double lp = ed1.length()*ed2.length();
      std::map<MEdge,double,Less_Edge>::iterator check = ed2angle.find(eds[j]);
      if(check==ed2angle.end()){
	ed2angle[eds[j]] = std::acos(dotp/lp);
	if(ed2angle[eds[j]]>M_PI/2.)
	  ed2refine[eds[j].length()].push_back(eds[j]);
	else
	  ed2angle.erase(eds[j]);
      }
    }// end for j
  }//end for tri
  return !(ed2refine.empty());
}


MEdge discreteFace::lepp(triangulation* trian,MEdge ed){
  std::vector<int> intri = trian->ed2tri[ed];
  bool isTerminal = false;
  while(intri.size()>1 && !isTerminal){
    MEdge ed0 = maxEdge(trian->tri[intri[0]]);
    MEdge ed1 = maxEdge(trian->tri[intri[1]]);
    if(ed != ed0){
      ed = ed0;
      intri = trian->ed2tri[ed];
    }
    else if(ed != ed1){
      ed = ed1;
      intri = trian->ed2tri[ed];
    }
    else isTerminal = true;
  }// end while
  return ed;
}

void discreteFace::refineTriangles(triangulation* trian,MEdge ed,std::vector<MEdge>&ed2update){

  SPoint3 mid = ed.barycenter();
  MVertex* mv = new MVertex(mid.x(),mid.y(),mid.z());
  trian->vert.insert(mv);

  std::vector<int> t = trian->ed2tri[ed];

  MTriangle *t00, *t01;
  int ie;

  ie = edgeLocalNum(trian->tri[t[0]],ed);
  t00 = new MTriangle(trian->tri[t[0]]->getEdge(ie+1 > 2 ? ie-2 : ie+1).getVertex(0),trian->tri[t[0]]->getEdge(ie+1 > 2 ? ie-2 : ie+1).getVertex(1),mv);
  t01 = new MTriangle(trian->tri[t[0]]->getEdge(ie+2 > 2 ? ie-1 : ie+2).getVertex(0),trian->tri[t[0]]->getEdge(ie+2 > 2 ? ie-1 : ie+2).getVertex(1),mv);

  trian->tri[t[0]] = t00;
  trian->ed2tri[t00->getEdge(2)] = trian->ed2tri[ed];
  trian->ed2tri[t00->getEdge(1)].push_back(t[0]);
  trian->ed2tri[t00->getEdge(1)].push_back(trian->tri.size());

  std::vector<int> oldtri = trian->ed2tri[ed];
  oldtri[0] == t[0] ? oldtri[0] = trian->tri.size() : oldtri[1] = trian->tri.size();
  trian->ed2tri[t01->getEdge(1)] = oldtri;
  oldtri = trian->ed2tri[t01->getEdge(0)];
  oldtri[0] == t[0]  ? oldtri[0] = trian->tri.size() : oldtri[1] = trian->tri.size();
  trian->ed2tri[t01->getEdge(0)] = oldtri;
  trian->tri.push_back(t01);

  ed2update.push_back(t00->getEdge(0));
  ed2update.push_back(t01->getEdge(0));

  if(t.size()>1){

    ed2update.push_back(t01->getEdge(1));
    ed2update.push_back(t00->getEdge(2));
    MTriangle  *t10, *t11;

    this->mesh_vertices.push_back(mv);
    mv->setEntity(this);

    ie = edgeLocalNum(trian->tri[t[1]],ed);
    t11 = new MTriangle(trian->tri[t[1]]->getEdge(ie+1 > 2 ? ie-2 : ie+1).getVertex(0),trian->tri[t[1]]->getEdge(ie+1 > 2 ? ie-2 : ie+1).getVertex(1),mv);
    t10 = new MTriangle(trian->tri[t[1]]->getEdge(ie+2 > 2 ? ie-1 : ie+2).getVertex(0),trian->tri[t[1]]->getEdge(ie+2 > 2 ? ie-1 : ie+2).getVertex(1),mv);

    trian->tri[t[1]] = t10;
    trian->ed2tri[t10->getEdge(1)] = trian->ed2tri[ed];
    trian->ed2tri[t10->getEdge(2)].push_back(t[1]);
    trian->ed2tri[t10->getEdge(2)].push_back(trian->tri.size());

    oldtri = trian->ed2tri[t11->getEdge(2)];
    oldtri[0] == t[1] ? oldtri[0] = trian->tri.size() : oldtri[1] = trian->tri.size();
    trian->ed2tri[t11->getEdge(2)] = oldtri;
    oldtri = trian->ed2tri[t11->getEdge(0)];
    oldtri[0] == t[1]  ? oldtri[0] = trian->tri.size() : oldtri[1] = trian->tri.size();
    trian->ed2tri[t11->getEdge(0)] = oldtri;
    trian->tri.push_back(t11);

    ed2update.push_back(t10->getEdge(0));
    ed2update.push_back(t11->getEdge(0));

  }
  else{
    std::list<GEdge*> gGEdges = trian->my_GEdges;
    std::list<GEdge*>::iterator oe = gGEdges.begin();
    while(oe != gGEdges.end() && ed.getVertex(0)->onWhat() != *oe && ed.getVertex(0)->onWhat() != (*oe)->getBeginVertex())
	    ++oe;
    GEdge* ged = *oe;
    std::vector<MLine*> mlines = ged->lines;
    std::vector<MLine*> conca;
    for (unsigned int i=0; i<mlines.size(); i++){
      if ((mlines[i]->getVertex(0)==ed.getVertex(0)&&mlines[i]->getVertex(1)==ed.getVertex(1))||
	  (mlines[i]->getVertex(1)==ed.getVertex(0)&&mlines[i]->getVertex(0)==ed.getVertex(1))){
	conca.push_back(new MLine(mlines[i]->getVertex(0),mv));
	conca.push_back(new MLine(mv,mlines[i]->getVertex(1)));// delete MLine ?
      }
      else conca.push_back(mlines[i]);
    }
    discreteEdge* de = new discreteEdge(this->model(),NEWLINE(),ged->getBeginVertex(),ged->getEndVertex());
    setupDiscreteEdge(de,conca,NULL);
    trian->my_GEdges.remove(ged);
    ged->lines.clear();
    ged->mesh_vertices.clear();
    trian->my_GEdges.push_back(de);
    trian->borderEdg.erase(ed);
    trian->borderEdg.insert(t00->getEdge(2));
    trian->borderEdg.insert(t01->getEdge(1));
  }
}

void discreteFace::updateEd2refine(triangulation* trian,std::map<MEdge,double,Less_Edge>&ed2angle,std::vector<MEdge>&ed2update,std::map<double,std::vector<MEdge> >&ed2refine){

  for(unsigned int i=0; i<ed2update.size(); i++){
    MEdge current = ed2update[i];
    std::vector<int> intri = trian->ed2tri[current];
    if(intri.size()>1 && ed2angle.find(current) == ed2angle.end() ){
      ed2angle[current] = 0.;
      for(unsigned int j=0; j<intri.size(); j++){
	MElement* tri = trian->tri[intri[j]];
	int num = edgeLocalNum(tri,current);
	MEdge ed1 = tri->getEdge(num+1>2?num-2:num+1);
	MEdge ed2 = tri->getEdge(num+2>2?num-1:num+2);
	SVector3 v1(ed1.getVertex(0)->x()-ed1.getVertex(1)->x(),
		    ed1.getVertex(0)->y()-ed1.getVertex(1)->y(),
		    ed1.getVertex(0)->z()-ed1.getVertex(1)->z());
	SVector3 v2(ed2.getVertex(1)->x()-ed2.getVertex(0)->x(),
		    ed2.getVertex(1)->y()-ed2.getVertex(0)->y(),
		    ed2.getVertex(1)->z()-ed2.getVertex(0)->z());
	double dotp = dot(v1,v2);
	double lp = ed1.length()*ed2.length();
	if(ed2angle[current]==0.)
	  ed2angle[current] = std::acos(dotp/lp);
	else{
	  ed2angle[current] += std::acos(dotp/lp);
	  if(ed2angle[current] > M_PI)
	    ed2refine[current.length()].push_back(current);
	  else
	    ed2angle.erase(current);
	}
      }//end for j
    }
  }// end for i

}


void discreteFace::updateEd2refineBis(triangulation* trian,std::map<MEdge,double,Less_Edge>&ed2angle,std::vector<MEdge>&ed2update,std::map<double,std::vector<MEdge> >&ed2refine){

  for(unsigned int i=0; i<ed2update.size(); i++){
    MEdge current = ed2update[i];
    std::vector<int> intri = trian->ed2tri[current];
    for(unsigned int j=0; j<intri.size(); j++){
      if(ed2angle.find(current) == ed2angle.end() ){
	MElement* tri = trian->tri[intri[j]];
	int num = edgeLocalNum(tri,current);
	MEdge ed1 = tri->getEdge(num+1>2?num-2:num+1);
	MEdge ed2 = tri->getEdge(num+2>2?num-1:num+2);
	SVector3 v1(ed1.getVertex(0)->x()-ed1.getVertex(1)->x(),
		    ed1.getVertex(0)->y()-ed1.getVertex(1)->y(),
		    ed1.getVertex(0)->z()-ed1.getVertex(1)->z());
	SVector3 v2(ed2.getVertex(1)->x()-ed2.getVertex(0)->x(),
		    ed2.getVertex(1)->y()-ed2.getVertex(0)->y(),
		    ed2.getVertex(1)->z()-ed2.getVertex(0)->z());
	double dotp = dot(v1,v2);
	double lp = ed1.length()*ed2.length();
	ed2angle[current] = std::acos(dotp/lp);
	if (ed2angle[current]>M_PI/2.)
	  ed2refine[current.length()].push_back(current);
	else
	  ed2angle.erase(current);
      }//end for j
    }
  }// end for i

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


// delete all discrete disk faces
//void discreteFace::deleteAtlas() {
//}
//---------------------------------------------------------

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

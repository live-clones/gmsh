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
  std::vector<triangulation*> part;
  part.resize(nPart);
#if defined(HAVE_ANN) && defined(HAVE_SOLVER)

  if (!_atlas.empty())return;

  int id=1;
  std::stack<triangulation*>  toSplit;
  std::vector<triangulation*> toParam;
  std::vector<MElement*> tem(triangles.begin(),triangles.end());

  triangulation* init = new triangulation(tem,this);  
  init->my_GEdges = l_edges;

  toSplit.push(init);
  int mygen, compteur=1;
  Msg::Info("First Genus Value:");
  //std::cin>>mygen;
  mygen=1;
  if(mygen!=0){//((toSplit.top())->genus()!=0){
   
    while( !toSplit.empty()){

      triangulation* tosplit = toSplit.top();
      toSplit.pop();

      split(tosplit,part,nPart);
      delete tosplit; // #mark

      for(int i=0; i<nPart; i++){
	Msg::Info("Partition %d Genus:",compteur);
	std::cin>>mygen;
	if(mygen!=0)//part[i]->genus()!=0)
	  toSplit.push(part[i]);
	else{
	  toParam.push_back(part[i]);
	  part[i]->idNum=id++;
	}
	compteur++;
      }// end for i
    }// !.empty()    
  }// end if it is not disk-like
  else{
    toParam.push_back(toSplit.top());
    toSplit.top()->idNum=id++;
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
      else Msg::Warning ("FILE %s LINE %d Triangle has no classification",__FILE__,__LINE__);
	
      

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
    _atlas[i]->mesh(verbose);
  }
  gatherMeshes();
  meshStatistics.status = GFace::DONE;
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
	      Msg::Info("discreteFace: triangle %d has been reoriented.",neigs[i]->getNum());
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

// split old GEdge's
void discreteFace::splitDiscreteEdge ( GEdge *de , GVertex *gv, discreteEdge* newE[2]){

  MVertex *vstart = de->getBeginVertex()->mesh_vertices[0];
  //MVertex *vend   = de->getEndVertex()->mesh_vertices[0];

  // We create a new Model vertex and we classify
  /*
  discreteVertex *newV = new discreteVertex (de->model(),NEWPOINT());
  newV->mesh_vertices.push_back (v);
  v->setEntity (newV);
  de->model()->add(newV);*/
  
  // We create 2 new Model edges and we classify vertices
  // The creation of discrete edge geometries have already been done (or not)
  // FIXME !!!!!
  //discreteEdge *newE[2];
  newE[0] = new discreteEdge (de->model(),NEWLINE(),de->getBeginVertex(),gv);
  newE[1] = new discreteEdge (de->model(),NEWLINE(),gv, de->getEndVertex());
  de->model()->add(newE[0]);
  de->model()->add(newE[1]);
  
  int current = 0;
  
  // assumption: the MLine's are sorted
  for (unsigned int i=0;i<de->lines.size();i++){
    MLine *l = de->lines[i];
    newE[current]->lines.push_back(l);
    if (l->getVertex(0) != vstart && l->getVertex(0) != gv->mesh_vertices[0]) {
      l->getVertex(0)->setEntity(newE[current]);
      newE[current]->mesh_vertices.push_back(l->getVertex(0));
    }
    if (l->getVertex(1) ==  gv->mesh_vertices[0]) current ++;
  }
  for(int ie=0; ie<2; ie++)  newE[ie]->createGeometry();
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
      else Msg::Fatal("discreteFace::splitDiscreteEdge \t This only applies to discrete geometries");      
    }    
  }  
  de->model()->remove(de);
  
}


void discreteFace::split(triangulation* trian,std::vector<triangulation*> &partition,int nPartitions)
{
#if defined(HAVE_METIS)

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

  std::vector<std::vector<MElement*> > elem;
  elem.resize(nPartitions);

  for(int i=0; i<nVertex; i++)
    elem[part[i]].push_back(trian->tri[i]);


  for(int i=0; i<nPartitions; i++)
    partition[i] = new triangulation(elem[i],this);







  //---- setting topology, i.e. GEdge's and GVertex's ----//

  std::set<MVertex*> todelete; // vertices that do not belong to the GFace anymore
  std::set<GEdge*> gGEdges(trian->my_GEdges.begin(),trian->my_GEdges.end());

  for(int i=0; i<nPartitions; i++){
  
    // create new GEdge's
    std::set<MEdge,Less_Edge> bordi = partition[i]->borderEdg;// edges defining the border(s) of the i-th new triangulation
    

    for(int ii=i+1; ii<nPartitions; ii++){// compare to the ii-th ones, with ii > i since ii < i have already been compared
      

      std::map<MVertex*,MLine*> v02edg;//first vertex of the MLine
      std::set<MVertex*> first, last;
      for(std::set<MEdge,Less_Edge>::iterator ie = bordi.begin();
	  ie != bordi.end(); ++ie){// MEdge by MEdge of the i-th triangulation border(s)

	std::set<MEdge,Less_Edge> bii = partition[ii]->borderEdg;// edges defining the border(s) of the ii-th new triangulation
	if(bii.find(*ie)!=bii.end()){// if the border edge is common to both triangulations . . .

	  v02edg[ie->getVertex(0)] = new MLine(ie->getVertex(0),ie->getVertex(1));// . . . a new MLine is created

	  // identifying first and last vertices of GEdge's, if any
	  if( first.find(ie->getVertex(1)) != first.end() )
	    first.erase(ie->getVertex(1));
	  else
	    last.insert(ie->getVertex(1));
	  if( last.find(ie->getVertex(0)) != last.end() )
	    last.erase(ie->getVertex(0));
	  else
	    first.insert(ie->getVertex(0));
	}

      }//end for ie


      //---- creation of the GEdge's from new MLine's ----//
      
      while(!first.empty()){// starting with nonloop GEdge's

	GVertex *v[2];

	std::vector<MLine*> myLines;// MLine's of the current nonloop GEdge
	std::set<MVertex*>::iterator itf = first.begin();
	MVertex* cv0 = *itf;// starting with a first vertex
	while(last.find(cv0) == last.end()){// until reaching the corresponding last vertex
	  myLines.push_back(v02edg[cv0]);// push the correspong MLine
	  v02edg.erase(cv0);// and erasing it from the "list"
	  cv0 = myLines.back()->getVertex(1);// next vertex
	}// end last

	std::vector<MVertex*> mvt; 
	mvt.resize(2);
	mvt[0] = *itf;
	mvt[1] = cv0;
	  
	for(int imvt=0; imvt<2; imvt++){
	  
	  std::set<GEdge*>::iterator oe=gGEdges.begin();
	  while(mvt[imvt]->onWhat() != *oe)
	    ++oe;

	  if (oe == gGEdges.end()) Msg::Error("discreteFace::split \t This Vertex is not on a GEdge !");	    
	  GEdge* onit = *oe;
	  if(mvt[imvt] == onit->getBeginVertex()->mesh_vertices[0])
	    v[imvt] = onit->getBeginVertex();
	  else if (mvt[imvt] == onit->getEndVertex()->mesh_vertices[0])
	    v[imvt] = onit->getEndVertex();
	  else{
	    v[imvt] = new discreteVertex (this->model(),NEWPOINT());
	    v[imvt]->mesh_vertices.push_back(mvt[imvt]);
	    mvt[imvt]->setEntity(v[imvt]);
	    this->model()->add(v[imvt]);
	    discreteEdge* de[2];	    	   
	    gGEdges.erase(onit);
	    splitDiscreteEdge(onit,v[imvt],de);	    
	    gGEdges.insert(de[0]);
	    gGEdges.insert(de[1]);	    
	  }// end else    
	  
	}// end imvt	

	discreteEdge* internalE = new discreteEdge (this->model(),NEWLINE(),v[0],v[1]);
	this->model()->add(internalE);// new GEdge
	internalE->lines = myLines;// associated MLine's
	for(unsigned int iml=1; iml<myLines.size(); iml++){//not the first vertex of the GEdge (neither the last one)
	  myLines[iml]->getVertex(0)->setEntity(internalE);
	  internalE->mesh_vertices.push_back(myLines[iml]->getVertex(0));
	  todelete.insert(myLines[iml]->getVertex(0));
	}
	internalE->createGeometry();
	partition[i]->my_GEdges.push_back(internalE);
	partition[ii]->my_GEdges.push_back(internalE);	

	first.erase(itf);// next first vertex of a nonloop GEdge
      }//end while first.empty()

      	for(std::set<GEdge*>::iterator le=gGEdges.begin(); le!=gGEdges.end(); ++le){
	  GEdge* ile = *le;	     
	  MEdge edTest = ile->lines.front()->getEdge(0);
	  if(bordi.find(edTest)!=bordi.end())
	    partition[i]->my_GEdges.push_back(ile);	      	  
	  else
	    partition[ii]->my_GEdges.push_back(ile);	     
	}

      while(!v02edg.empty()){// remaining MLines for 'loop'GEdge's

	discreteVertex* v;	  
	std::vector<MLine*> my_MLines;

	MVertex* cv0 = v02edg.begin()->first;
	while(v02edg.find(cv0) != v02edg.end()){// a loop GEdge
	  my_MLines.push_back(v02edg[cv0]);// current MLine of the loop
	  v02edg.erase(cv0);// update the container
	  cv0 = my_MLines.back()->getVertex(1);// next MLine of the loop
	}
	  
	v = new discreteVertex (this->model(),NEWPOINT());
	v->mesh_vertices.push_back(cv0);
	cv0->setEntity(v);
	this->model()->add(v);
	todelete.insert(cv0);

	discreteEdge* gloop = new discreteEdge (this->model(),NEWLINE(),v,v);
	this->model()->add(gloop);
	gloop->lines = my_MLines;
	for(unsigned int iml=1; iml<my_MLines.size(); iml++){//not the first vertex of the GEdge (neither the last one)
	  my_MLines[iml]->getVertex(0)->setEntity(gloop);
	  gloop->mesh_vertices.push_back(my_MLines[iml]->getVertex(0));
	  todelete.insert(my_MLines[iml]->getVertex(0));
	}
	gloop->createGeometry();
	partition[i]->my_GEdges.push_back(gloop);
	partition[ii]->my_GEdges.push_back(gloop);
      }// end while v02edg.empty()
      
    }//end for ii
    
  }// end for i
  
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

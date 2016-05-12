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
extern "C" {
#include <metis.h>
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

  int order = 2;
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
  if((toSplit.top())->genus()!=0){
    
    while( !toSplit.empty()){

      triangulation* tosplit = toSplit.top();
      toSplit.pop();
      
      split(tosplit,part,nPart);
      delete tosplit; // #mark

      for(int i=0; i<nPart; i++){
	if(part[i]->genus()!=0)
	  toSplit.push(part[i]);
	else{
	  toParam.push_back(part[i]);
	  part[i]->idNum=id++;
	  // discreteEdges
	}
      }// end for i      
    }

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

void discreteFace::split(triangulation* trian,std::vector<triangulation*> &partition,int nPartitions)
{
  
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
  
  

  for(int i=0; i<nPartitions; i++){// setting GEdge's

    //"update" old GEdge's
    std::list<GEdge*> upGed = partition[i]->my_GEdges;// old GEdge's list
    for(std::list<GEdge*>::iterator cGedg=trian->my_GEdges.begin(); cGedg!=trian->my_GEdges.end(); cGedg++){// GEdge by GEdge
      std::set<MVertex*> first, last;
      double lc = 0.;
      std::vector<MLine*> upMli;     
      for(unsigned int k=0; k<(*cGedg)->lines.size(); k++){// MLine by MLine (for a GEdge)
	MLine* cMli = (*cGedg)->lines[k];
	std::set<MVertex*>::iterator mvit0 = partition[i]->vert.find(cMli->getVertex(0));
	std::set<MVertex*>::iterator mvit1 = partition[i]->vert.find(cMli->getVertex(1));
	if(mvit0 != partition[i]->vert.end() && mvit1 != partition[i]->vert.end()){// check if the MLine belong to this part

	  if( first.find(cMli->getVertex(1)) != first.end() )
	    first.erase(cMli->getVertex(1));
	  else
	    last.insert(cMli->getVertex(1));
	  
	  if( last.find(cMli->getVertex(0)) != last.end() )
	    last.erase(cMli->getVertex(0));
	  else
	    first.insert(cMli->getVertex(0));
	  
	  upMli.push_back(cMli);
	  lc += cMli->getLength();

	}
      }// end for k  
      GVertex *v0, *v1;
      if(first.empty()){
	v0 = this->model()->addVertex(upMli[0]->getVertex(0)->x(),upMli[0]->getVertex(0)->y(),upMli[0]->getVertex(0)->z(),1.);//#fixme
	v1 = v0;
      }
      else{
	v0 = this->model()->addVertex((*(first.begin()))->x(),(*(first.begin()))->y(),(*(first.begin()))->z(),1.);//#fixme
	v1 = this->model()->addVertex((*(last.begin()))->x(),(*(last.begin()))->y(),(*(last.begin()))->z(),1.);
      }
      upGed.push_back(this->model()->addLine(v0,v1));
      upGed.back()->lines = upMli;
    }// end for j
    
    
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


      while(!v02edg.empty()){// creation of the GEdge's from new MLine's
	
	GVertex *v0, *v1;
	
	while(!first.empty()){// starting with nonloop GEdge's
	  
	  std::vector<MLine*> myLines;// MLine's of the current nonloop GEdge
	  std::set<MVertex*>::iterator itf = first.begin();
	  MVertex* cv0 = *itf;// starting with a first vertex
	  while(last.find(cv0) != last.end()){// until reaching the corresponding last vertex
	    myLines.push_back(v02edg[cv0]);// push the correspong MLine
	    v02edg.erase(cv0);// and erasing it from the "list"
	    cv0 = myLines.back()->getVertex(1);// next vertex
	  }
	  
	  v0 = this->model()->addVertex((*itf)->x(),myLines[0]->getVertex(0)->y(),myLines[0]->getVertex(0)->z(),1.);
	  v1 = this->model()->addVertex(cv0->x(),cv0->y(),cv0->z(),1.);
	  
	  GEdge* toadd = this->model()->addLine(v0,v1);// new GEdge
	  toadd->lines = myLines;// associated MLine's
	  
	  partition[i]->my_GEdges.push_back(toadd);
	  partition[ii]->my_GEdges.push_back(toadd);
	  
	  first.erase(itf);// next first vertex of a nonloop GEdge
	}//end while first.empty()
	
	std::vector<MLine*> my_MLines;// remaining MLines for 'loop'GEdge's
	MVertex* cv0 = v02edg.begin()->first;
	while(v02edg.find(cv0) != v02edg.end()){// a loop GEdge	  
	  my_MLines.push_back(v02edg[cv0]);// current MLine of the loop
	  v02edg.erase(cv0);// update the container
	  cv0 = my_MLines.back()->getVertex(1);// next MLine of the loop	  	  
	}

	v0 =  this->model()->addVertex(cv0->x(),cv0->y(),cv0->z(),1.);
	v1 = v0;

	GEdge* to_add = this->model()->addLine(v0,v1);
	to_add->lines = my_MLines;

	partition[i]->my_GEdges.push_back(to_add);
	partition[ii]->my_GEdges.push_back(to_add);
	
      }// end while v02edg.empty()
      
    }//end for ii
    
  }// end for i

  return;
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

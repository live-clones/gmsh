#include "Context.h"
#include "multiscaleLaplace.h"
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "OS.h"
#include "SBoundingBox3d.h"
#include "SPoint3.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemCSR.h"

#ifdef HAVE_GMM
#include "linearSystemGmm.h"
#endif

#include "linearSystemFull.h"
#include "MTriangle.h"
#include "robustPredicates.h"

/*
//-- returns 0 if no intersection occurs --\\
//-- returns 1 
p1 (1-u) + p2 u = q1 (1-t) + q2 t 

we search the intersection into segment q1-q2

robustPredicates

if ( isLeftOf (

*/
static int intersection_segments_b (SPoint2 &p1, SPoint2 &p2,
				    SPoint2 &q1, SPoint2 &q2, 
				    double x[2]){
  double P1[2] = {p1.x(),p1.y()};
  double P2[2] = {p2.x(),p2.y()};
  double Q1[2] = {q1.x(),q1.y()};
  double Q2[2] = {q2.x(),q2.y()};

  double PQ1 = robustPredicates::orient2d(P1,P2,Q1);
  double PQ2 = robustPredicates::orient2d(P1,P2,Q2);

  double QP1 = robustPredicates::orient2d(Q1,Q2,P1);
  double QP2 = robustPredicates::orient2d(Q1,Q2,P2);

}


static int intersection_segments (SPoint2 &p1, SPoint2 &p2,
				  SPoint2 &q1, SPoint2 &q2, 
				  double x[2]){
  double A[2][2];
  A[0][0] = p2.x()-p1.x();
  A[0][1] = q1.x()-q2.x();
  A[1][0] = p2.y()-p1.y();
  A[1][1] = q1.y()-q2.y();
  double b[2] = {q1.x()-p1.x(),q1.y()-p1.y()};
  sys2x2(A,b,x);

  return (x[0] >= 0.0 && x[0] <= 1. &&
	  x[1] >= 0.0 && x[1] <= 1.); 
  
}

static void recur_compute_centers_ (double R, double a1, double a2,
				    multiscaleLaplaceLevel * root ){

  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > &centers = root->cut;
  multiscaleLaplaceLevel* zero = 0;

  SPoint2 PL (R*cos(a1),R*sin(a1));
  SPoint2 PR (R*cos(a2),R*sin(a2));
  centers.push_back(std::make_pair(PL,zero));  
  centers.push_back(std::make_pair(PR,zero));  
  for (int i=0;i<root->childeren.size();i++){
    centers.push_back(std::make_pair(root->childeren[i]->center,root->childeren[i]));  
    multiscaleLaplaceLevel* m = root->childeren[i];    
    m->radius = 0.0;
    for (std::map<MVertex*,SPoint2>::iterator it = m->coordinates.begin();
	 it !=  m->coordinates.end() ; ++it){
      const SPoint2 &p = it->second;
      m->radius = std::max(m->radius,sqrt ((m->center.x() - p.x())*(m->center.x() - p.x())+
					   (m->center.y() - p.y())*(m->center.y() - p.y())));
    }
  }
  std::sort(centers.begin(),centers.end());

  for (int i=1;i<centers.size()-1;i++){
    multiscaleLaplaceLevel* m1 = centers[i-1].second;
    multiscaleLaplaceLevel* m2 = centers[i].second;
    multiscaleLaplaceLevel* m3 = centers[i+1].second;
    if (m2){
      a1 = atan2 (m2->center.y() - centers[i-1].first.y(),m2->center.x() - centers[i-1].first.x()); 
      a2 = atan2 (m2->center.y() - centers[i+1].first.y(),m2->center.x() - centers[i+1].first.x()); 
      recur_compute_centers_ (m2->radius, a1, a2, m2);
    }
  }
}

static void recur_cut_edges_ (multiscaleLaplaceLevel * root,
			      std::multimap<MEdge,MElement*,Less_Edge> &e2e,
			      std::map<MEdge,MVertex*,Less_Edge> &cutEdges,
			      std::set<MVertex*> &cutVertices){
  std::set<MEdge,Less_Edge> allEdges;
  for (std::multimap <MEdge,MElement*,Less_Edge>::iterator it = e2e.begin();
	 it != e2e.end() ; ++it){
    allEdges.insert(it->first);
  }
  
  const double EPS = 0.001;

  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > &centers = root->cut;
  for (int i=0;i<centers.size()-1;i++){
    SPoint2 p1 = centers[i].first;
    SPoint2 p2 = centers[i+1].first;
    for (std::set <MEdge,Less_Edge>::iterator it = allEdges.begin();
	 it != allEdges.end() ; ++it){
      if(e2e.count(*it) == 2 && cutEdges.find(*it) == cutEdges.end()){
	std::map<MVertex *, SPoint2>::iterator it0 = root->coordinates.find(it->getVertex(0));
	std::map<MVertex *, SPoint2>::iterator it1 = root->coordinates.find(it->getVertex(1));
	if (it0 != root->coordinates.end() && it1 != root->coordinates.end()){
	  SPoint2 q1 = root->coordinates[it->getVertex(0)];
	  SPoint2 q2 = root->coordinates[it->getVertex(1)];	
	  double x[2];
	  int inters = intersection_segments (p1,p2,q1,q2,x);	
	  if (inters && x[1] > EPS && x[1] < 1.-EPS){
	    //	    printf("%g %g -- %g %g -- %g %g -- %g %g\n",p1.x(),p1.y(),p2.x(),p2.y(),q1.x(),q1.y(),q2.x(),q2.y());
	    MVertex *newv = new MVertex ((1.-x[1])*it->getVertex(0)->x() + x[1]*it->getVertex(1)->x(),
					 (1.-x[1])*it->getVertex(0)->y() + x[1]*it->getVertex(1)->y(),
					 (1.-x[1])*it->getVertex(0)->z() + x[1]*it->getVertex(1)->z());
	    cutEdges[*it] = newv;
	    root->coordinates[newv] = q1*(1.-x[1]) + q2*x[1] ;
	  }
	  else if (inters && x[1] <= EPS)cutVertices.insert(it->getVertex(0));
	  else if (inters && x[1] >= 1.-EPS)cutVertices.insert(it->getVertex(1));
	}
      }
    }
  }
  for (int i=0;i<centers.size();i++){
    multiscaleLaplaceLevel* m2 = centers[i].second;
    if (m2){
      recur_cut_edges_ (m2,e2e,cutEdges,cutVertices);
    }
  }
}

static void recur_cut_elements_ (multiscaleLaplaceLevel * root,
				 std::map<MEdge,MVertex*,Less_Edge> &cutEdges,
				 std::set<MVertex*> &cutVertices,
				 std::set<MEdge,Less_Edge> &theCut,
				 std::vector<MElement*> &_all){
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > &centers = root->cut;
  std::vector<MElement*> newElements;
  for (int i=0;i<root->elements.size();i++){
    MVertex *c[3] = {0,0,0};
    for (int j=0;j<3;j++){
      MEdge ed = root->elements[i]->getEdge(j);
      //      if (cutVertices.find (ed.getVertex(0)) != cutVertices.end() &&
      //	  cutVertices.find (ed.getVertex(1)) != cutVertices.end() )theCut.insert(ed);
      
      std::map<MEdge,MVertex*,Less_Edge> :: iterator it = cutEdges.find(ed);
      if (it != cutEdges.end()){
	c[j] = it->second;
      }
    }
    if (c[0] && c[1]){
      newElements.push_back(new MTriangle (c[0],root->elements[i]->getVertex(1),c[1]));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),c[0],root->elements[i]->getVertex(2)));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(2),c[0],c[1]));
      theCut.insert(MEdge(c[0],c[1]));
      // FIXME should be done !!!!!!
      //delete root->elements[i];      
    }
    else if (c[0] && c[2]){
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),c[0],c[2]));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(1),c[0],root->elements[i]->getVertex(2)));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(2),c[0],c[2]));
      theCut.insert(MEdge(c[0],c[2]));
      //delete root->elements[i];      
    }
    else if (c[1] && c[2]){
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(2),c[2],c[1]));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),root->elements[i]->getVertex(1),c[2]));
      newElements.push_back(new MTriangle (c[2],root->elements[i]->getVertex(1),c[1]));
      theCut.insert(MEdge(c[1],c[2]));
      //delete root->elements[i];      
    }
    else if (c[0]){
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),c[0],root->elements[i]->getVertex(2)));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(2),c[0],root->elements[i]->getVertex(1)));
      if (cutVertices.find (root->elements[i]->getVertex(0)) != cutVertices.end())
	theCut.insert(MEdge(c[0],root->elements[i]->getVertex(0)));
      else if (cutVertices.find (root->elements[i]->getVertex(1)) != cutVertices.end())	
	theCut.insert(MEdge(c[0],root->elements[i]->getVertex(1)));
      else
	theCut.insert(MEdge(c[0],root->elements[i]->getVertex(2)));
      //delete root->elements[i];      
    }
    else if (c[1]){
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(1),c[1],root->elements[i]->getVertex(0)));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),c[1],root->elements[i]->getVertex(2)));
      if (cutVertices.find (root->elements[i]->getVertex(1)) != cutVertices.end())
	theCut.insert(MEdge(c[1],root->elements[i]->getVertex(1)));
      else if (cutVertices.find (root->elements[i]->getVertex(2)) != cutVertices.end())	
	theCut.insert(MEdge(c[1],root->elements[i]->getVertex(2)));
      else
	theCut.insert(MEdge(c[1],root->elements[i]->getVertex(0)));
      //delete root->elements[i];      
    }
    else if (c[2]){
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(0),c[2],root->elements[i]->getVertex(1)));
      newElements.push_back(new MTriangle (root->elements[i]->getVertex(1),c[2],root->elements[i]->getVertex(2)));
      if (cutVertices.find (root->elements[i]->getVertex(0)) != cutVertices.end())
	theCut.insert(MEdge(c[2],root->elements[i]->getVertex(0)));
      else if (cutVertices.find (root->elements[i]->getVertex(2)) != cutVertices.end())	
	theCut.insert(MEdge(c[2],root->elements[i]->getVertex(2)));
      else
	theCut.insert(MEdge(c[2],root->elements[i]->getVertex(1)));
      //delete root->elements[i];      
    }
    else newElements.push_back(root->elements[i]);
  }
  root->elements = newElements;
  _all.insert(_all.end(),newElements.begin(),newElements.end());
  for (int i=0;i<centers.size();i++){
    multiscaleLaplaceLevel* m2 = centers[i].second;
    if (m2){
      recur_cut_elements_ (m2,cutEdges,cutVertices,theCut,_all);
    }
  }
}

static void recur_split_ (MElement *e,
			  std::multimap<MEdge,MElement*,Less_Edge> &e2e,
			  std::set<MElement*> &group,
			  std::set<MEdge,Less_Edge> &theCut){
  if (group.find(e) != group.end())return;
  group.insert(e);
  for (int i=0;i<e->getNumEdges();i++){
    MEdge ed = e->getEdge(i);
    if (theCut.find(ed) == theCut.end()){
      for (std::multimap <MEdge,MElement*,Less_Edge>::iterator it = e2e.lower_bound(ed);
	 it != e2e.upper_bound(ed) ; ++it){
	if (it->second != e)recur_split_ (it->second,e2e,group,theCut);
      }
    }
  }
}


// starting form a list of elements, returns
// lists of lists that are all simply connected
static void recur_connect (const MEdge &e,
			   std::multimap<MEdge,MElement*,Less_Edge> &e2e,
			   std::set<MElement*> &group,
			   std::set<MEdge,Less_Edge> &touched){
  if (touched.find(e) != touched.end())return;
  touched.insert(e);
  for (std::multimap <MEdge,MElement*,Less_Edge>::iterator it = e2e.lower_bound(e);
	 it != e2e.upper_bound(e) ; ++it){
    group.insert(it->second);
    for (int i=0;i<it->second->getNumEdges();++i){
      recur_connect (it->second->getEdge(i),e2e,group,touched);
    }
  }
}

static void connectedRegions (std::vector<MElement*> &elements,
			      std::vector<std::vector<MElement*> > &regions)
{
  std::multimap<MEdge,MElement*,Less_Edge> e2e;
  for (int i=0;i<elements.size();++i){
    for (int j=0;j<elements[i]->getNumEdges();j++){
      e2e.insert(std::make_pair(elements[i]->getEdge(j),elements[i]));
    }
  }
  while (!e2e.empty()){
    std::set<MElement*> group;
    std::set<MEdge,Less_Edge> touched;
    recur_connect (e2e.begin()->first,e2e,group,touched);
    std::vector<MElement*> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    regions.push_back(temp);
    for ( std::set<MEdge>::iterator it = touched.begin() ; it != touched.end();++it)
      e2e.erase(*it);
  }
}

static void printLevel ( const char* fn,
			 std::vector<MElement *> &elements,
			 std::map<MVertex*,SPoint2> *coordinates,
			 double version){

  
  std::set<MVertex*> vs;
  for (int i=0;i<elements.size();i++){
    for (int j=0;j<elements[i]->getNumVertices();j++){
      vs.insert(elements[i]->getVertex(j));
    }
  }

  bool binary = false;
  FILE *fp = fopen (fn, "w");
  fprintf(fp, "$MeshFormat\n");  
  fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
  fprintf(fp, "$EndMeshFormat\n");  

  fprintf(fp,"$Nodes\n%d\n",vs.size());
  std::set<MVertex*> :: iterator it = vs.begin();
  int index = 1;
  for (; it != vs.end() ; ++it){
    (*it)->setIndex(index++);
    SPoint2 p = (coordinates) ? (*coordinates)[*it] : SPoint2(0,0);
    if (coordinates) fprintf(fp,"%d %g %g 0\n",(*it)->getIndex(),p.x(),p.y());
    else fprintf(fp,"%d %g %g %g\n",(*it)->getIndex(),
		 (*it)->x(),(*it)->y(),(*it)->z());
  }
  fprintf(fp,"$EndNodes\n",elements.size());
  
  fprintf(fp,"$Elements\n%d\n",elements.size());
  for (int i=0;i<elements.size();i++){
    elements[i]->writeMSH(fp);
  }
  fprintf(fp,"$EndElements\n%d\n",elements.size());
  
  fclose(fp);
}

multiscaleLaplace::multiscaleLaplace (std::vector<MElement *> &elements,
				      std::vector<MVertex*> &boundaryNodes,
				      std::vector<double> &linearAbscissa) {

  if (!CTX::instance()->mesh.smoothInternalEdges)return;
#if defined(HAVE_TAUCS)
  _lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_GMM)
  linearSystemGmm<double> *_lsysb = new linearSystemGmm<double>;
  _lsysb->setGmres(1);
  _lsys = _lsysb;
#else
  _lsys = new linearSystemFull<double>;
#endif
  
  root = new multiscaleLaplaceLevel;
  root->elements = elements;
  for(unsigned int i = 0; i < boundaryNodes.size(); i++){
    MVertex *v = boundaryNodes[i];
    const double theta = 2 * M_PI * linearAbscissa[i];
    root->coordinates[v] = SPoint2(cos(theta),sin(theta));
  }
  root->recur = 0;
  root->region = 0;
  parametrize(*root);

  std::multimap<MEdge,MElement*,Less_Edge> e2e;
  for (int i=0;i<elements.size();++i){
    for (int j=0;j<elements[i]->getNumEdges();j++){
      e2e.insert(std::make_pair(elements[i]->getEdge(j),elements[i]));
    }
  }
  std::map<MEdge,MVertex*,Less_Edge> cutEdges;
  std::set<MVertex*> cutVertices;
  recur_compute_centers_ (1.0,0, M_PI, root);
  recur_cut_edges_ (root,e2e,cutEdges,cutVertices);

  if (1){
    // DEBUG : EXPORT -----------------
    std::map<MEdge,MVertex*,Less_Edge>::iterator it = cutEdges.begin();
    FILE *f = fopen("points.pos","w");
    fprintf(f,"View\"\"{\n");
    for ( ; it != cutEdges.end();++it){
      fprintf(f,"SP(%g,%g,%g){1.0};\n",it->second->x(),it->second->y(),it->second->z());
    }
    fprintf(f,"};\n");
    fclose(f);
    // ------END DEBUG 
  }
  std::set<MEdge,Less_Edge> theCut;
  std::vector<MElement*> _all;
  recur_cut_elements_ (root,cutEdges,cutVertices,theCut,_all);
  if (1){
    // DEBUG : EXPORT -----------------
    std::set<MEdge,Less_Edge>::iterator it = theCut.begin();
    FILE *f = fopen("edges.pos","w");
    fprintf(f,"View\"\"{\n");
    for ( ; it != theCut.end();++it){
      fprintf(f,"SL(%g,%g,%g,%g,%g,%g){1.0,1.0};\n",it->getVertex(0)->x(),it->getVertex(0)->y(),it->getVertex(0)->z(),
	      it->getVertex(1)->x(),it->getVertex(1)->y(),it->getVertex(1)->z());
    }
    fprintf(f,"};\n");
    fclose(f);
    // ------END DEBUG 
  }
  e2e.clear();
  for (int i=0;i<_all.size();++i){
    for (int j=0;j<_all[i]->getNumEdges();j++){
      e2e.insert(std::make_pair(_all[i]->getEdge(j),_all[i]));
    }
  }
  //  std::set<MElement*> leftSet;
  //  recur_split_ (_all[0],e2e,leftSet,theCut);

  std::vector<MElement*> left,right;
  /*
  for (int i=0;i<_all.size();i++){
    if(leftSet.find(_all[i]) == leftSet.end())right.push_back(_all[i]);
    else left.push_back(_all[i]);
  }
  */
  cut (left,right);

  printLevel ("multiscale_left.msh",left,0,1.0);
  printLevel ("multiscale_right.msh",right,0,1.0);  
  printLevel ("multiscale_all.msh",_all,0,1.0);  
  // FIXME !!!!!
  throw;
}

static double localSize(MElement *e,  std::map<MVertex*,SPoint2> &solution){
  SBoundingBox3d local;
  for(unsigned int j = 0; j<e->getNumVertices(); ++j){
    SPoint2 p = solution[e->getVertex(j)];
    local += SPoint3(p.x(),p.y(),0.0);
  }    
  return local.max().distance(local.min());    
}

void multiscaleLaplace::parametrize (multiscaleLaplaceLevel & level){
  simpleFunction<double> ONE(1.0);
  std::set<MVertex*> allNodes;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      allNodes.insert(e->getVertex(j));
    }
  }  
  std::map<MVertex*,SPoint2> solution;
  // PARAMETRIZE ---------------------------------
  for (int step =0 ; step<2 ; step++){
    dofManager<double> myAssembler(_lsys);
    for(std::map<MVertex*,SPoint2>::iterator it = level.coordinates.begin();
	it != level.coordinates.end(); ++it){
      MVertex *v = it->first;
      myAssembler.fixVertex(v, 0, 1, it->second[step]);
    }
    // do the numbering
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      MVertex *v = *itv;
      myAssembler.numberVertex(v, 0, 1);
    }
    // assemble
    laplaceTerm laplace(0, 1, &ONE);
    for(unsigned int i = 0; i < level.elements.size(); ++i){
      MElement *e = level.elements[i];
      SElement se(e);
      laplace.addToMatrix(myAssembler, &se);
    }
    // solve
    if (myAssembler.sizeOfR() != 0) _lsys->systemSolve();
    // get the values 
    int count = 0;
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      MVertex *v = *itv;
      double value = myAssembler.getDofValue(v, 0, 1);      
      if (step == 0)solution[v] = SPoint2(value,0);
      else solution[v] = SPoint2(solution[v][0],value);
    }    
    _lsys->clear();
  }

  // compute the bbox of the parametric space
  SBoundingBox3d bbox;
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    SPoint2 p = solution[v];
    bbox += SPoint3(p.x(),p.y(),0.0);
  }
  double global_size = bbox.max().distance(bbox.min());
  // check elements that are too small
  std::vector<MElement*> tooSmall, goodSize;

  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    std::vector<SPoint2> localCoord;
    double local_size = localSize(e,solution);
    if (local_size < 1.e-6 * global_size){
      tooSmall.push_back(e);
    }
    else{
      goodSize.push_back(e);
    }
  }
  // only keep the right elements and nodes
  level.elements = goodSize;

  std::vector<std::vector<MElement*> > regions, regions_;
  connectedRegions (tooSmall,regions_);

  // remove small regions
  
  for (int i=0;i< regions_.size() ; i++){    
    bool region_has_really_small_elements = false;
    for (int k=0; k<regions_[i].size() ; k++){
      MElement *e = regions_[i][k];
      double local_size = localSize(e,solution);
      if (local_size < 1.e-8 * global_size){
	region_has_really_small_elements = true;
      }
    }
    if(region_has_really_small_elements) regions.push_back(regions_[i]);
    else level.elements.insert(level.elements.begin(),  regions_[i].begin(), regions_[i].end() );
  }  

  std::set<MVertex*> goodSizev;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      goodSizev.insert(e->getVertex(j));
      level.coordinates[e->getVertex(j)] = solution[e->getVertex(j)];
    }
  }
  
  //END PARAMETRIZE ---------------------------------
  // DEBUG
  char name[245];
  sprintf(name,"multiscale_level%d_region%d_real.msh",level.recur, level.region);
  printLevel (name,level.elements,0,1.0);
  sprintf(name,"multiscale_level%d_region%d_param.msh",level.recur, level.region);
  printLevel (name,level.elements,&level.coordinates,1.0);
  // END DEBUG

  Msg::Info("%d connected regions\n",regions.size());

  for (int i=0;i< regions.size() ; i++){    
    // check nodes that appear both on too small and good size
    // and set it to the next level
    // maybe more than one level should be created here
    std::set<MVertex*> tooSmallv;
    for (int k=0; k<regions[i].size() ; k++){
      MElement *e = regions[i][k];
      for(unsigned int j = 0; j<e->getNumVertices(); ++j){
	tooSmallv.insert(e->getVertex(j));
      }    
    }
    
    multiscaleLaplaceLevel *nextLevel = new multiscaleLaplaceLevel;
    nextLevel->elements = regions[i];
    nextLevel->recur = level.recur+1;
    nextLevel->region = i;
    SBoundingBox3d smallB;
    for(std::set<MVertex *>::iterator itv = tooSmallv.begin(); itv !=tooSmallv.end() ; ++itv){
      SPoint2 p = solution[*itv];
      nextLevel->center += p;
      smallB += SPoint3(p.x(),p.y(),0.0);
    }
    nextLevel->center *= (1./(double)tooSmallv.size());
    nextLevel->scale = smallB.max().distance(smallB.min());
    
    for(std::set<MVertex *>::iterator itv = tooSmallv.begin(); itv !=tooSmallv.end() ; ++itv){
      MVertex *v = *itv;
      if (goodSizev.find(v) != goodSizev.end()){
	nextLevel->coordinates[v] =  (solution[v]-nextLevel->center)*(1./nextLevel->scale);
      }
    }
    // recursively continue if tooSmall is not empty
    if (!tooSmall.empty()){
      Msg::Info("Multiscale Laplace, level %d region %d, %d too small",level.recur,level.region,tooSmall.size());
      level.childeren.push_back(nextLevel);
      parametrize (*nextLevel);
    }
    else {
      Msg::Info("Multiscale Laplace, level %d DONE",level.recur);
      delete nextLevel;
    }
  }
}

static void recur_cut_ (double R, double a1, double a2,
			multiscaleLaplaceLevel * root, 
			std::vector<MElement *> &left, 
			std::vector<MElement *> &right ){
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > &centers = root->cut;
  centers.clear();
  multiscaleLaplaceLevel* zero = 0;

  SPoint2 PL (R*cos(a1),R*sin(a1));
  SPoint2 PR (R*cos(a2),R*sin(a2));
  centers.push_back(std::make_pair(PL,zero));  
  centers.push_back(std::make_pair(PR,zero));  
  for (int i=0;i<root->childeren.size();i++){
    centers.push_back(std::make_pair(root->childeren[i]->center,root->childeren[i]));  
    multiscaleLaplaceLevel* m = root->childeren[i];    
    m->radius = 0.0;
    for (std::map<MVertex*,SPoint2>::iterator it = m->coordinates.begin();
	 it !=  m->coordinates.end() ; ++it){
      const SPoint2 &p = it->second;
      m->radius = std::max(m->radius,sqrt ((m->center.x() - p.x())*(m->center.x() - p.x())+
					   (m->center.y() - p.y())*(m->center.y() - p.y())));
    }
  }
  std::sort(centers.begin(),centers.end());
  /*
  printf("%d %d ",root->recur,root->region);
  for (int j=0;j<centers.size();j++){
    printf("(%g %g) ",centers[j].first.x(),centers[j].first.y());
  }
  printf("\n");
  */
  double d = sqrt((PL.x()-PR.x())*(PL.x()-PR.x())+
		  (PL.y()-PR.y())*(PL.y()-PR.y()));
  SPoint2 farLeft (0.5*(PL.x()+PR.x()) - (PR.y()-PL.y())/d ,
		   0.5*(PL.y()+PR.y()) + (PR.x()-PL.x())/d );
  
  for (int i=0;i<root->elements.size();i++){
    SPoint2 pp (0,0);
    for (int j=0; j<root->elements[i]->getNumVertices(); j++){
      pp += root->coordinates[root->elements[i]->getVertex(j)];
    }
    pp *= 1./(double)root->elements[i]->getNumVertices();
    int nbIntersect = 0;
    for (int j=0;j<centers.size()-1;j++){
      double x[2];
      nbIntersect += intersection_segments (centers[j].first,centers[j+1].first,pp,farLeft,x); 
    }
    if (root->recur != 0){
      if (nbIntersect %2 == 0)
	left.push_back(root->elements[i]);
      else
	right.push_back(root->elements[i]);
    }
    else{
      if (nbIntersect %2 != 0)
	left.push_back(root->elements[i]);
      else
	right.push_back(root->elements[i]);
    }
  }
  
  for (int i=1;i<centers.size()-1;i++){
    multiscaleLaplaceLevel* m1 = centers[i-1].second;
    multiscaleLaplaceLevel* m2 = centers[i].second;
    multiscaleLaplaceLevel* m3 = centers[i+1].second;
    if (m2){
      /*center of the local system is always 0,0
	its relative position to its parent is center
	only 2 angles have to be computed for in and out*/
      a1 = atan2 (m2->center.y() - centers[i-1].first.y(),m2->center.x() - centers[i-1].first.x()); 
      a2 = atan2 (m2->center.y() - centers[i+1].first.y(),m2->center.x() - centers[i+1].first.x()); 
      recur_cut_ (m2->radius, a1, a2, m2, left, right);
    }
  }
}


void multiscaleLaplace::cut (std::vector<MElement *> &left, 
			     std::vector<MElement *> &right)
{
  recur_cut_ (1.0,0, M_PI, root,left,right);
}

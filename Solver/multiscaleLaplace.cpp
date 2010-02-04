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
#include "convexCombinationTerm.h"
#include "linearSystemCSR.h"
#include "robustPredicates.h"
#include "meshGFaceOptimize.h"
#include "GFaceCompound.h"

#ifdef HAVE_GMM
#include "linearSystemGMM.h"
#endif

#include "linearSystemFull.h"
#include "MTriangle.h"
#include "robustPredicates.h"

//--------------------------------------------------------------

struct sort_pred {
    bool operator()(const std::pair<SPoint2,multiscaleLaplaceLevel*> &left, const std::pair<SPoint2,multiscaleLaplaceLevel*> &right) {
      return left.first.x() < right.first.x();
    }
};


//--------------------------------------------------------------
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
//--------------------------------------------------------------
static void recur_connect (MVertex *v,
			   std::multimap<MVertex*,MEdge> &v2e,
			   std::set<MEdge,Less_Edge> &group,
			   std::set<MVertex*> &touched){

  if (touched.find(v) != touched.end())return;

  touched.insert(v);
  for (std::multimap <MVertex*,MEdge>::iterator it = v2e.lower_bound(v); 
       it != v2e.upper_bound(v) ; ++it){
    group.insert(it->second);
    for (int i=0;i<it->second.getNumVertices();++i){
      recur_connect (it->second.getVertex(i),v2e,group,touched);
    }
  }

}
//--------------------------------------------------------------
static void connected_bounds (std::vector<MElement*> &elements, 
			      std::vector<std::vector<MEdge> > &boundaries){

  std::vector<MEdge> bEdges;  
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumEdges(); j++){
      MEdge me =  elements[i]->getEdge(j);
      if(std::find(bEdges.begin(), bEdges.end(), me) == bEdges.end())
	bEdges.push_back(me);
      else
	bEdges.erase(std::find(bEdges.begin(), bEdges.end(),me));
    }    
  }    
 
  std::multimap<MVertex*,MEdge> v2e;
  for (unsigned i=0;i<bEdges.size();++i){
    for (int j=0;j<bEdges[i].getNumVertices();j++){
      v2e.insert(std::make_pair(bEdges[i].getVertex(j),bEdges[i]));
    }
  }
  while (!v2e.empty()){
    std::set<MEdge, Less_Edge> group;
    std::set<MVertex*> touched;
    recur_connect (v2e.begin()->first,v2e,group,touched);
    std::vector<MEdge> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    boundaries.push_back(temp);
    for ( std::set<MVertex*>::iterator it = touched.begin() ; it != touched.end();++it)
      v2e.erase(*it);
  }

  return;
}
//--------------------------------------------------------------
static double getSizeBB(std::vector<MEdge> &me){

  SBoundingBox3d bb ;
  SOrientedBoundingBox obbox ;

  std::vector<SPoint3> vertices;
  for (int i=0; i< me.size(); i++){
    MVertex *v0 = me[i].getVertex(0);
    MVertex *v1 = me[i].getVertex(1);
    SPoint3 pt1(v0->x(),v0->y(), v0->z());
    vertices.push_back(pt1);
    SPoint3 pt2(v1->x(),v1->y(), v1->z());
    vertices.push_back(pt2);
    bb+=pt1;
    bb+=pt2;
  }
  
  //double H = norm(SVector3(bb.max(), bb.min()));
  //printf("H=%g \n", H);

  obbox =  SOrientedBoundingBox::buildOBB(vertices);
  double H =  obbox.getMaxSize();
  
  return H; 

}
//--------------------------------------------------------------
static void  ordering_dirichlet(std::vector<MElement*> &elements, 
				std::vector<std::pair<MVertex*,double> > &dirichletNodes){

  //finding all boundaries
  std::vector<std::vector<MEdge> > boundaries;
  connected_bounds(elements,boundaries);
  
  //largest boundary is dirichlet boundary
  std::vector<MEdge> dirichletEdges;
  double maxSize = 0.0;
  for(int i=0; i< boundaries.size(); i++){
    std::vector<MEdge> iBound = boundaries[i];
    double size = getSizeBB(iBound);
    if (size > maxSize) {
      dirichletEdges = iBound; 
      maxSize = size;
    }
  }

  //ordering dirichletNodes
  dirichletNodes.clear();
  std::list<MEdge> temp;
  double tot_length = 0.0;
  for(int i= 0 ; i < dirichletEdges.size(); i++ ){
      MVertex *v0 =  dirichletEdges[i].getVertex(0);
      MVertex *v1 =  dirichletEdges[i].getVertex(1); 
      double len = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
		       (v0->y() - v1->y()) * (v0->y() - v1->y()) +
			(v0->z() - v1->z()) * (v0->z() - v1->z())) ;  
      tot_length += len;
      temp.push_back(dirichletEdges[i]);
  }
 
  dirichletNodes.push_back(std::make_pair(dirichletEdges[0].getVertex(0),0.0));
  MVertex *current_v =  dirichletEdges[0].getVertex(1);
  temp.erase(temp.begin());

  while(temp.size()){
    bool found = false;
    for(std::list<MEdge>::iterator itl = temp.begin(); itl != temp.end(); ++itl){
      MVertex *v0 =  itl->getVertex(0);
      MVertex *v1 =  itl->getVertex(1);
      if(v0 == current_v){
	found = true;
	current_v = v1;
	temp.erase(itl);
	double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
			     (v0->y() - v1->y()) * (v0->y() - v1->y()) +
			     (v0->z() - v1->z()) * (v0->z() - v1->z()));
	double iLength = dirichletNodes[dirichletNodes.size()-1].second + (length / tot_length);
	dirichletNodes.push_back(std::make_pair(v0,iLength));
	break;
      }
      else if(v1 == current_v){
	found = true;
	current_v = v0;
	temp.erase(itl);
	double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) + 
			     (v0->y() - v1->y()) * (v0->y() - v1->y()) +
			     (v0->z() - v1->z()) * (v0->z() - v1->z()));
	double iLength = dirichletNodes[dirichletNodes.size()-1].second + (length  / tot_length);
	dirichletNodes.push_back(std::make_pair(v1,iLength));
	break;
      }
    }
    if(!found) return ;
  }    

  return;
}
//--------------------------------------------------------------
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
//--------------------------------------------------------------
static void recur_compute_centers_ (double R, double a1, double a2,
				    multiscaleLaplaceLevel * root ){

  root->radius = R;
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > &centers = root->cut;
  centers.clear();
  multiscaleLaplaceLevel* zero = 0;

  SPoint2 PL (R*cos(a1),R*sin(a1));
  SPoint2 PR (R*cos(a2),R*sin(a2));
  centers.push_back(std::make_pair(PL,zero));  
  centers.push_back(std::make_pair(PR,zero)); 
 
  for (int i=0;i<root->children.size();i++){
    multiscaleLaplaceLevel* m = root->children[i];    
    centers.push_back(std::make_pair(m->center,m));   
    m->radius = 0.0;
    for (std::map<MVertex*,SPoint2>::iterator it = m->coordinates.begin();
	 it !=  m->coordinates.end() ; ++it){
      const SPoint2 &p = it->second;
      m->radius = std::max(m->radius,sqrt ((m->center.x() - p.x())*(m->center.x() - p.x())+
					   (m->center.y() - p.y())*(m->center.y() - p.y())));
    }
  }

  //add the center of real holes ... 
  if (root->children.size()==0 ){//|| boundaries.size()-1 != root->children.size()){
    std::vector<std::vector<MEdge> > boundaries;
    connected_bounds(root->elements, boundaries);
    for (int i = 0; i < boundaries.size(); i++){
      std::vector<MEdge> me = boundaries[i];
      SPoint2 c(0.0,0.0);
      double rad = 0.0;
      for(int j= 0; j< me.size(); j++){
	MVertex *v = me[j].getVertex(0);
	std::map<MVertex *, SPoint2>::iterator it0 = root->coordinates.find(v);
	c += it0->second;
      }
      c *= 1./((double)me.size());
      for(int j= 0; j< me.size(); j++){
	SPoint2 p =  root->coordinates[me[j].getVertex(0)];
	rad = std::max(rad,sqrt ((c.x() - p.x())*(c.x() - p.x())+
				 (c.y() - p.y())*(c.y() - p.y())));
      }
      if (std::abs(rad/root->radius) < 0.9 && abs(rad) < 0.99){
	centers.push_back(std::make_pair(c,zero));  
      }
    }
  }

  //sort centers
  std::sort(centers.begin(),centers.end(), sort_pred());

  for (int i=1;i<centers.size()-1;i++){
    multiscaleLaplaceLevel* m1 = centers[i-1].second;
    multiscaleLaplaceLevel* m2 = centers[i].second;
    multiscaleLaplaceLevel* m3 = centers[i+1].second;
    if (m2){
      a1 = myatan2 (centers[i-1].first.y()- m2->center.y() , centers[i-1].first.x()-m2->center.x()); 
      a2 = myatan2 (centers[i+1].first.y()- m2->center.y() , centers[i+1].first.x()-m2->center.x()); 
      recur_compute_centers_ (m2->radius, a1, a2, m2);
    }
  }

}
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
//--------------------------------------------------------------

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

//--------------------------------------------------------------
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
    for ( std::set<MEdge,Less_Edge>::iterator it = touched.begin() ; it != touched.end();++it)
      e2e.erase(*it);
  }
}
//--------------------------------------------------------------
static void recur_cut_ (double R, double a1, double a2,
			multiscaleLaplaceLevel * root, 
			std::vector<MElement *> &left, 
			std::vector<MElement *> &right ){


  SPoint2 PL (R*cos(a1),R*sin(a1));
  SPoint2 PR (R*cos(a2),R*sin(a2));
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > centers = root->cut;

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
//     if (root->recur != 0){
//       if (nbIntersect %2 == 0)
// 	left.push_back(root->elements[i]);
//       else
// 	right.push_back(root->elements[i]);
//     }
//     else{
      if (nbIntersect %2 != 0)
	left.push_back(root->elements[i]);
      else
	right.push_back(root->elements[i]);
 //    }
  }
  
  for (int i=1;i<centers.size()-1;i++){
    multiscaleLaplaceLevel* m1 = centers[i-1].second;
    multiscaleLaplaceLevel* m2 = centers[i].second;
    multiscaleLaplaceLevel* m3 = centers[i+1].second;
    if (m2){
      a1 = myatan2 (centers[i-1].first.y() - m2->center.y() , centers[i-1].first.x() - m2->center.x() ); 
      a2 = myatan2 (centers[i+1].first.y() - m2->center.y() , centers[i+1].first.x() - m2->center.x() );
      recur_cut_ (m2->radius, a1, a2, m2, left, right);
    }
  }
}

//--------------------------------------------------------------
static void connected_left_right (std::vector<MElement *> &left, 
				 std::vector<MElement *> &right ){


  //connected left
  std::vector<std::vector<MElement*> >  subRegionsL;
  connectedRegions (left,subRegionsL);
  int indexL=0;

  if (subRegionsL.size()  > 0){
    int maxSize= subRegionsL[0].size(); 
    for (int i=1;i< subRegionsL.size() ; i++){   
      int size = subRegionsL[i].size();
      if(size > maxSize){
	maxSize = size;
	indexL = i;
      }
    }
  }
  
  left.clear();
  for (int i=0;i< subRegionsL.size() ; i++){   
    if (i == indexL)
      left.insert(left.begin(), subRegionsL[i].begin(),  subRegionsL[i].end());
    else
      right.insert(right.begin(), subRegionsL[i].begin(),  subRegionsL[i].end());
  }

  //connected right
  std::vector<std::vector<MElement*> >  subRegionsR;
  connectedRegions (right,subRegionsR);
  int indexR=0;

  if (subRegionsR.size()  > 0){
    int maxSize= subRegionsR[0].size(); 
    for (int i=1;i< subRegionsR.size() ; i++){   
      int size = subRegionsR[i].size();
      if(size > maxSize){
	maxSize = size;
	indexR = i;
      }
    }
  }

  right.clear();
  for (int i=0;i< subRegionsR.size() ; i++){   
    if (i == indexR)
      right.insert(right.begin(), subRegionsR[i].begin(),  subRegionsR[i].end());
    else
      left.insert(left.begin(), subRegionsR[i].begin(),  subRegionsR[i].end());
  }

  //assign partitions
  for (int i= 0; i< left.size(); i++)
    left[i]->setPartition(1);
  for (int i= 0; i< right.size(); i++)
    right[i]->setPartition(2);

}
//--------------------------------------------------------------
static void printLevel ( const char* fn,
			 std::vector<MElement *> &elements,
			 std::map<MVertex*,SPoint2> *coordinates,
			 double version){

  
  std::set<MVertex*> vs;
  for (int i=0;i<elements.size();i++)
    for (int j=0;j<elements[i]->getNumVertices();j++)
      vs.insert(elements[i]->getVertex(j));

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
    elements[i]->writeMSH(fp,version);
  }
  fprintf(fp,"$EndElements\n%d\n",elements.size());
  
  fclose(fp);
}
//--------------------------------------------------------------
static double localSize(MElement *e,  std::map<MVertex*,SPoint2> &solution){

  SBoundingBox3d local;
  for(unsigned int j = 0; j<e->getNumVertices(); ++j){
    SPoint2 p = solution[e->getVertex(j)];
    local += SPoint3(p.x(),p.y(),0.0);
  }    
  return local.max().distance(local.min());

//   MVertex* v0 = e->getVertex(0); 
//   MVertex* v1 = e->getVertex(1); 
//   MVertex* v2 = e->getVertex(2); 
//   double p0[3] = {v0->x(), v0->y(), v0->z()}; 
//   double p1[3] = {v1->x(), v1->y(), v1->z()};
//   double p2[3] = {v2->x(), v2->y(), v2->z()};
//   double a_3D = fabs(triangle_area(p0, p1, p2));
//   SPoint2 s1 = solution[v0];
//   SPoint2 s2 = solution[v1];
//   SPoint2 s3 = solution[v2];
//   double q0[3] = {s1.x(), s1.y(), 0.0}; 
//   double q1[3] = {s2.x(), s2.y(), 0.0};
//   double q2[3] = {s3.x(), s3.y(), 0.0};
//   double a_2D = fabs(triangle_area(q0, q1, q2)); 
 
//   return a_2D;  //a_2D / a_3D;
 
   
}
//-------------------------------------------------------------
static void one2OneMap(std::vector<MElement *> &elements, std::map<MVertex*,SPoint2> &solution) {


//   v2t_cont adjv;
//   std::vector<MTriangle*> allTri;
//   for(int i=0; i< elements.size(); i++){
//     allTri.push_back( (MTriangle*) elements[i] );
//   }
//   buildVertexToTriangle(allTri, adjv);
  
//   for(v2t_cont::iterator it = adjv.begin(); it!= adjv.end(); ++it){
//     MVertex *v = it->first;
//     std::vector<MElement*> vTri = it->second;
//     std::map<MVertex*,SPoint2> vCoord;
//     for (int j=0; j < vTri.size(); j++){
//       for (int k= 0; k < vTri[j]->getNumVertices(); k++){
// 	MVertex *vk = vTri[j]->getVertex(k);
// 	vCoord[vk] = solution(vk);
//       }
//     }
//     bool badCavity = closedCavity(v,vTri) ? checkCavity(vTri, vCoord) : false;
    
//     if(badCavity){
//       Msg::Debug("Wrong cavity around vertex %d (onwhat=%d).",
//                 v->getNum(),  v->onWhat()->dim());
//       Msg::Debug("--> Place vertex at center of gravity of %d-Polygon kernel." ,
//                 vTri.size());
      
//       double u_cg, v_cg;
//       std::vector<MVertex*> cavV;
//       myPolygon(vTri, cavV);
//       computeCGKernelPolygon(coordinates, cavV, u_cg, v_cg);
//       SPoint3 p_cg(u_cg,v_cg,0);
//       coordinates[v] = p_cg;
      
//     }
//   }

  return;

}
//--------------------------------------------------------------
static bool checkOrientation(std::vector<MElement *> &elements,   
			     std::map<MVertex*,SPoint2> &solution, int iter) {
 
  double a_old = 0, a_new;
  bool oriented = true;
  int count = 0;
  for(unsigned int i = 0; i < elements.size(); ++i){
    MElement *t = elements[i];
    SPoint2 v1 = solution[t->getVertex(0)];
    SPoint2 v2 = solution[t->getVertex(1)];
    SPoint2 v3 = solution[t->getVertex(2)];
    double p0[2] = {v1[0],v1[1]};
    double p1[2] = {v2[0],v2[1]};
    double p2[2] = {v3[0],v3[1]};
    a_new = robustPredicates::orient2d(p0, p1, p2);
    if(count == 0) a_old=a_new;   
    if(a_new*a_old < 0.){
      oriented = false;
      break;
    }
    else{
      a_old = a_new;
    }
    count++;
  }    
  
  int iterMax = 1;
  if(!oriented && iter < iterMax){
    if (iter == 0) Msg::Debug("Parametrization is NOT 1 to 1 : applying cavity checks.");
    Msg::Debug("Cavity Check - iter %d -",iter);
    one2OneMap(elements, solution);
    return checkOrientation(elements, solution, iter+1);
  }
  else if (iter < iterMax){
    Msg::Debug("Parametrization is 1 to 1 :-)");
  }

  return oriented;

}
//--------------------------------------------------------------

multiscaleLaplace::multiscaleLaplace (std::vector<MElement *> &elements, 
				      std::map<MVertex*, SPoint3> &allCoordinates) 
{

  //To go through this execute gmsh with the option -optimize_hom
  //if (!CTX::instance()->mesh.smoothInternalEdges)return; 

  //Find the boundary loops 
  //The loop with the largest equivalent radius is the Dirichlet boundary
  std::vector<std::pair<MVertex*,double> > boundaryNodes;
  ordering_dirichlet(elements,boundaryNodes);

#if defined(HAVE_TAUCS)
  _lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_GMM)
  linearSystemGmm<double> *_lsysb = new linearSystemGmm<double>;
  _lsysb->setGmres(1);
  _lsys = _lsysb;
#else
  _lsys = new linearSystemFull<double>;
#endif

  //Assign Dirichlet BCs
  root = new multiscaleLaplaceLevel;
  root->elements = elements;
  for(unsigned int i = 0; i < boundaryNodes.size(); i++){
     MVertex *v = boundaryNodes[i].first;
     const double theta = 2 * M_PI * boundaryNodes[i].second;
     root->coordinates[v] = SPoint2(cos(theta),sin(theta));
  }

  //Recursively parametrize
  root->recur = 0;
  root->region = 0;
  root->scale = 1.0;
  parametrize(*root);

  //fill the coordinates
  std::vector<double> iScale; 
  std::vector<SPoint2> iCenter;
  fillCoordinates(*root, allCoordinates, iScale, iCenter);

  //Compute centers for the cut
  recur_compute_centers_ (1.0, M_PI, 0.0, root);

  //Partition the mesh in left and right
  cut (elements); 

  //---- Testing other cut for partitionning  ----
  //---- cutEdges and connected_regions       ----
//    std::multimap<MEdge,MElement*,Less_Edge> e2e;
//    for (int i=0;i<elements.size();++i){
//      for (int j=0;j<elements[i]->getNumEdges();j++){
//        e2e.insert(std::make_pair(elements[i]->ge
      //a1 = atan2 (m2->center.y() - centers[i-1].first.y(),m2->center.x() - centers[i-1].first.x()); 
      //a2 = atan2 (m2->center.y() - centers[i+1].first.y(),m2->center.x() - centers[i+1].first.x()); tEdge(j),elements[i]));
//      }
//    }
//    std::map<MEdge,MVertex*,Less_Edge> cutEdges;
//    std::set<MVertex*> cutVertices;
//    recur_cut_edges_ (root,e2e,cutEdges,cutVertices);

//    printf("Writing points.pos \n");
//    std::map<MEdge,MVertex*,Less_Edge>::iterator ite = cutEdges.begin();
//    FILE *f1 = fopen("points.pos","w");
//    fprintf(f1,"View\"\"{\n");
//    for ( ; ite != cutEdges.end();++ite){
//      fprintf(f1,"SP(%g,%g,%g){1.0};\n",ite->second->x(),ite->second->y(),ite->second->z());
//    }
//    fprintf(f1,"};\n");
//    fclose(f1);
 
//    std::set<MEdge,Less_Edge> theCut;   
//    std::vector<MElement*> _all;
//    recur_cut_elements_ (root,cutEdges,cutVertices,theCut,_all);
   
//    printf("Writing edges.pos \n");
//    std::set<MEdge,Less_Edge>::iterator itc = theCut.begin();
//    FILE *f2 = fopen("edges.pos","w");
//    fprintf(f2,"View\"\"{\n");
//    for ( ; itc != theCut.end();++itc){
//      fprintf(f2,"SL(%g,%g,%g,%g,%g,%g){1.0,1.0};\n",itc->getVertex(0)->x(),itc->getVertex(0)->y(),itc->getVertex(0)->z(),
// 	     itc->getVertex(1)->x(),itc->getVertex(1)->y(),itc->getVertex(1)->z());
//    }
//    fprintf(f2,"};\n");
//    fclose(f2);

//   e2e.clear();
//   for (int i=0;i<_all.size();++i){
//     for (int j=0;j<_all[i]->getNumEdges();j++){
//       e2e.insert(std::make_pair(_all[i]->getEdge(j),_all[i]));
//     }
//   }
//  std::set<MElement*> leftSet;
//  recur_split_ (_all[0],e2e,leftSet,theCut);
//   for (int i=0;i<_all.size();i++){
//     if(leftSet.find(_all[i]) == leftSet.end())right.push_back(_all[i]);
//     else left.push_back(_all[i]);
//   }

}

void multiscaleLaplace::fillCoordinates (multiscaleLaplaceLevel & level, 
					 std::map<MVertex*, SPoint3> &allCoordinates, 
					 std::vector<double> &iScale, 
					 std::vector<SPoint2> &iCenter){

  iScale.push_back(level.scale);
  iCenter.push_back(level.center);

  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      MVertex *v = e->getVertex(j);
      SPoint2 coord  = level.coordinates[v];
      for (int k= iScale.size()-1; k > 0; k--){
	coord = coord*iScale[k] + iCenter[k];
      }
      allCoordinates[v] = SPoint3(coord.x(), coord.y(), 0.0);
    }
  }

  
  for (int i=0;i<level.children.size();i++){
    multiscaleLaplaceLevel* m = level.children[i]; 
    fillCoordinates(*m, allCoordinates, iScale, iCenter);
 }

  
}

void multiscaleLaplace::parametrize (multiscaleLaplaceLevel & level){


  //Compute all nodes for the level
  std::set<MVertex*> allNodes;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      allNodes.insert(e->getVertex(j));
    }
  }  
  
  //Parametrize level
  std::map<MVertex*,SPoint2> solution;
  parametrize_method(level, allNodes, solution, HARMONIC);
  if (!checkOrientation(level.elements, solution, 0)){
    Msg::Debug("Parametrization switched to convex combination");
    parametrize_method(level, allNodes, solution, CONVEXCOMBINATION);
  }

  //Compute the bbox of the parametric space
  SBoundingBox3d bbox;
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    SPoint2 p = solution[v];
    bbox += SPoint3(p.x(),p.y(),0.0);
  }
  double global_size = bbox.max().distance(bbox.min());

  //Check elements that are too small
  std::vector<MElement*> tooSmall, goodSize;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    std::vector<SPoint2> localCoord;
    double local_size = localSize(e,solution);
    if (local_size < 1.e-5 * global_size) 
      tooSmall.push_back(e);
    else  goodSize.push_back(e);
  }

  //Only keep the connected elements vectors goodSize and tooSmall
  std::vector<std::vector<MElement*> >  regGoodSize;
  connectedRegions (goodSize,regGoodSize);
  if (regGoodSize.size()  > 0){
    int index=0;
    int maxSize= regGoodSize[0].size(); 
    for (int i=1;i< regGoodSize.size() ; i++){   
      int size = regGoodSize[i].size();
      if(size > maxSize){
	index = i;
	maxSize = size;
      }
    }
    goodSize.clear();
    for (int i=0;i< regGoodSize.size() ; i++){   
      if (i == index)  goodSize.insert(goodSize.begin(), regGoodSize[i].begin(),  regGoodSize[i].end());
      else  tooSmall.insert(tooSmall.begin(), regGoodSize[i].begin(),  regGoodSize[i].end());
    }
  }
  level.elements.clear();
  level.elements = goodSize;

  //Add the not too small regions to the level.elements 
  std::vector<std::vector<MElement*> >  regions_, regions ;
  regions.clear(); regions_.clear();
  connectedRegions (tooSmall,regions_);
  for (int i=0;i< regions_.size() ; i++){    
    bool really_small_elements = false;
    for (int k=0; k<regions_[i].size() ; k++){
      MElement *e = regions_[i][k];
      double local_size = localSize(e,solution);
      if (local_size < 1.e-7 * global_size) 
	really_small_elements = true;
    }
    if(really_small_elements ) regions.push_back(regions_[i]);
    else
      level.elements.insert(level.elements.begin(), regions_[i].begin(), regions_[i].end() );
  }  

  //Fill level.coordinates
  std::set<MVertex*> goodSizev;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      MVertex *v = e->getVertex(j);
      goodSizev.insert(v);
      level.coordinates[v] = solution[v];
    }
  }

  //Save multiscale meshes
  char name[245];
  sprintf(name,"multiscale_%d_%d_real.msh",level.recur, level.region);
  printLevel (name,level.elements,0,2.0);
  sprintf(name,"multiscale_%d_%d_param.msh",level.recur, level.region);
  printLevel (name,level.elements,&level.coordinates,2.0);

  //For every small region compute a new parametrization
  Msg::Info("Level (%d-%d): %d connected small regions",level.recur, level.region, regions.size());
  for (int i=0;i< regions.size() ; i++){    
    std::set<MVertex*> tooSmallv;
    tooSmallv.clear();
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
    if (!tooSmallv.empty()){
      Msg::Info("Level (%d-%d) Multiscale Laplace (reg[%d] =  %d too small)",level.recur,level.region, i, tooSmallv.size());
      level.children.push_back(nextLevel);
      parametrize (*nextLevel);
    }
  }

}

void multiscaleLaplace::parametrize_method (multiscaleLaplaceLevel & level, 
					    std::set<MVertex*> &allNodes,
					    std::map<MVertex*,SPoint2> &solution, 
					    typeOfMapping tom)
{

  solution.clear();
  simpleFunction<double> ONE(1.0);

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
    femTerm<double> *mapping;
    if (tom == HARMONIC){
      mapping = new laplaceTerm(0, 1, &ONE);
    }
    else if (tom == CONVEXCOMBINATION){
      mapping = new convexCombinationTerm(0, 1, &ONE);
    }

    for(unsigned int i = 0; i < level.elements.size(); ++i){
      MElement *e = level.elements[i];
      SElement se(e);
      mapping->addToMatrix(myAssembler, &se);
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
}
void multiscaleLaplace::cut (std::vector<MElement *> &elements)
{

  std::vector<MElement*> left,right;
  recur_cut_ (1.0, M_PI, 0.0, root,left,right);
  connected_left_right(left, right);

  if ( elements.size() != left.size()+right.size()) 
    Msg::Error("Cutting laplace wrong nb elements (%d) != left + right (%d)",  elements.size(), left.size()+right.size());

  elements.clear();
  elements.insert(elements.end(),left.begin(),left.end());
  elements.insert(elements.end(),right.begin(),right.end());

  printLevel ("multiscale-all.msh",elements, 0,2.0);  
  printLevel ("multiscale-left.msh",left,0,2.0);  
  printLevel ("multiscale-right.msh",right,0,2.0);  

}


// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "meshGFaceQuadrilateralize.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "GFace.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGFaceBDS.h"
#include "BDS.h"
#include "SVector3.h"

class edgeFront {
 public:
  typedef std::set<BDS_Edge *>::const_iterator eiter;
 private:
  BDS_Mesh *m;
  GFace *gf;
  void getFrontEdges(BDS_Point *p, eiter & it1, eiter & it2) const;  
  void getFrontEdges(BDS_Point *p, std::vector<eiter> & f) const;
 public:
  std::set<BDS_Edge *> edges;  
  std::set<BDS_Edge*> stat[5];
  eiter begin() { return edges.begin(); }
  eiter end() { return edges.end(); }
  edgeFront(BDS_Mesh *_m, GFace *_gf) : m(_m), gf(_gf) {}
  // initiate edges in the front i.e.
  // take all edges that have one neighbor 
  // and all edges that have a quad and a triangle 
  // neighbor
  void initiate();
  // compute normal vector to an edge that points
  // inside the domain
  SVector3 normal(BDS_Edge *e) const;    
  // compute the state of a front edge
  // 0 both vertices have edge angles < 60 deg 
  // 1 e->p1 have and edge angle > 60 deg 
  // 2 e->p2 have and edge angle > 60 deg 
  // 3 both vertices have edge angles > 60 deg 
  int computeStatus(BDS_Edge *e) const;
  inline bool inFront(BDS_Edge *e) const{ return getStatus(e) != -1; }
  inline int getStatus(BDS_Edge *e) const{
    for(int i = 0; i < 5; i++){
      if(stat[i].find(e) != stat[i].end()) return i;
    }
    return -1;
  }
  // get one edge of the front that is tagged "tag"
  // and do whatever has to be done to remove it from
  // the front/tag. return false if the front is not empty.
  bool emptyFront(int tag);
  // update the status of the edge
  void updateStatus(BDS_Edge *e);
  // form a quad now
  bool formQuad(BDS_Edge *e, BDS_Edge *left, BDS_Edge *right);
  // delete the cavity delimitated by 4 edges
  void emptyCavity(BDS_Edge *bottom, BDS_Edge *top, BDS_Edge *left, BDS_Edge *right);
  // delete an edge from the front
  void deleteFromFront(BDS_Edge *e)
  {
    edges.erase(e);
    for(int i = 0; i < 5; i++){
      std::set<BDS_Edge*>::iterator it = stat[i].find(e);
      if(it != stat[i].end()){
        stat[i].erase(it);
        return;
      }
    }
  }
  // taking a point from the front, find the optimal edge
  BDS_Edge *findOptimalEdge(BDS_Point *p, BDS_Point *avoid);
};

void edgeFront::updateStatus(BDS_Edge *e)
{
  for(int i = 0; i < 5; i++){
    std::set<BDS_Edge*>::iterator it = stat[i].find(e);
    if(it !=stat[i].end()){
      stat[i].erase(it);
      stat[computeStatus(e)].insert(e);
      return;
    }
  }
  Msg::Error("Something wrong in updateStatus");
}

SVector3 norm_edge(BDS_Point *p1, BDS_Point *p2)
{
  SVector3 n(p2->X-p1->X,p2->Y-p1->Y,p2->Z-p1->Z);
  n.normalize();
  return n;
}

void recur_empty_cavity(BDS_Face *f,
                        BDS_Edge   *be[4],
                        BDS_Point *bv[4],
                        std::set<BDS_Face*> & faces, 
                        std::set<BDS_Edge*> & edges, 
                        std::set<BDS_Point*> & vertices)
{
  if(faces.find(f) != faces.end()) return;
  faces.insert(f);
  BDS_Edge *ee[3] = {f->e1,f->e2,f->e3};
  for(int i=0;i<3;i++){
    BDS_Edge *e = ee[i];
    if(e != be[0] && e != be[1] && e != be[2] && e != be[3]){
      edges.insert(e);
      BDS_Face *of = e->otherFace(f);
      recur_empty_cavity(of,be,bv,faces,edges,vertices);
    }
  }
}

void edgeFront::emptyCavity(BDS_Edge *bottom, BDS_Edge *top, BDS_Edge *left, 
                            BDS_Edge *right)
{
  // not optimal for now, will be improved further away
  BDS_Face *f = 0;
  if(bottom->faces(0) && bottom->faces(0)->numEdges() == 3) f=bottom->faces(0);
  else if(bottom->faces(1))f = bottom->faces(1);

  std::set<BDS_Face*> m_faces;
  std::set<BDS_Edge*> m_edges;
  std::set<BDS_Point*> m_vertices;
  BDS_Edge   *be[4] = {bottom,top,left,right};
  BDS_Point *bv[4] = {bottom->commonvertex(left),
                      left->commonvertex(top),
                      top->commonvertex(right),
                      right->commonvertex(bottom)};

  recur_empty_cavity(f, be, bv, m_faces, m_edges, m_vertices);
  //  printf("%d edges %d faces\n",m_edges.size(),m_faces.size());
  for(std::set<BDS_Face*>::iterator it = m_faces.begin(); 
      it != m_faces.end(); ++it) m->del_face(*it);
  for(std::set<BDS_Edge*>::iterator it = m_edges.begin(); 
      it != m_edges.end(); ++it) m->del_edge(*it);
}


SVector3 edgeFront::normal(BDS_Edge*e) const
{
  BDS_Face *t = e->faces(0);
  if(e->numfaces() == 2 && e->faces(1)->numEdges() == 3)t=e->faces(1);

  /*
    points p1, p2 and p3
    p3 does NOT belong to the edge
    p = p1 (1-u-v) + p2 u + p3 v;
    J = [p2-p1 p3-p1 (p2-p1)x(p3-p1)]
    N = - J^-1 * {0,1,0}
    n = N/|N|    
   */
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  BDS_Point *p3;
  if(e == t->e1)
    p3 = t->e2->commonvertex(t->e3);
  else if(e == t->e2)
    p3 = t->e1->commonvertex(t->e3);
  else if(e == t->e3)
    p3 = t->e2->commonvertex(t->e1);
  else {
    Msg::Error("Could not compute fron normal");
    return SVector3();
  }
  
  SVector3 t1(p2->X-p1->X,p2->Y-p1->Y,p2->Z-p1->Z);
  SVector3 t2(p3->X-p1->X,p3->Y-p1->Y,p3->Z-p1->Z);
  SVector3 t3 = crossprod(t1,t2);
  double m[3][3] = {{t1.x(),t2.x(),t3.x()},
                    {t1.y(),t2.y(),t3.y()},
                    {t1.z(),t2.z(),t3.z()}};
  double im[3][3];
  inv3x3(m,im);
  SVector3 n(im[1][0],im[1][1],im[1][2]);
  n.normalize();
  return n;
}

void edgeFront::getFrontEdges(BDS_Point *p, std::vector<eiter> & fe) const
{
  for(std::list<BDS_Edge*>::iterator itp = p->edges.begin(); 
      itp != p->edges.end(); ++ itp){
    eiter it = edges.find(*itp); 
    if(it != edges.end())
      fe.push_back(it);
  }
}

void edgeFront::getFrontEdges(BDS_Point *p, eiter & it1, eiter & it2) const
{
  int count = 0;
  for(std::list<BDS_Edge*>::iterator itp = p->edges.begin(); 
      itp != p->edges.end(); ++ itp){
    if(count == 0){
      it1 = edges.find(*itp); 
      if(it1 != edges.end()) count++;
    }
    else if(count == 1){
      it2 = edges.find(*itp); 
      if(it2 != edges.end()) return;
    }
  }  
  Msg::Error("point %d is in the front but has only %d edges\n",p->iD,count);
}

void edgeFront::initiate()
{
  edges.clear();
  for(int i = 0; i < 5; i++) stat[i].clear();
  std::list<BDS_Edge*>::iterator it = m->edges.begin();
  while(it != m->edges.end()){
    if(((*it)->numfaces() == 1 && (*it)->faces(0)->e4 == 0) ||
        ((*it)->numfaces() == 2 && (*it)->numTriangles() == 1)) {
      edges.insert(*it);
    }
    ++it;
  }
  for(eiter it2 = begin(); it2 !=end(); ++it2){
    int status = computeStatus(*it2);
    stat[status].insert(*it2);
  }
}

static double angle3Points(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3)
{
  SVector3 a(p1->X - p2->X, p1->Y - p2->Y, p1->Z - p2->Z);
  SVector3 b(p3->X - p2->X, p3->Y - p2->Y, p3->Z - p2->Z);
  SVector3 c = crossprod(a,b);
  double sinA = c.norm();
  double cosA = dot(a,b);
  //  printf("%d %d %d -> %g %g\n",p1->iD,p2->iD,p3->iD,cosA,sinA);
  return atan2(sinA, cosA);
}

int edgeFront::computeStatus(BDS_Edge *e) const
{
  eiter it11, it12, it21,it22;
  getFrontEdges(e->p1, it11, it12);  
  getFrontEdges(e->p2, it21, it22);  
  
  BDS_Edge *e1 = (*it11) == e ? *it12 : *it11;
  BDS_Edge *e2 = (*it21) == e ? *it22 : *it21;
  
  double angle1 = angle3Points((*it11)->othervertex(e->p1), e->p1,
                               (*it12)->othervertex(e->p1));
  double angle2 = angle3Points((*it21)->othervertex(e->p2), e->p2,
                               (*it22)->othervertex(e->p2));

  SVector3 n1 = normal(e);
  SVector3 n2 = norm_edge(e->p1, e1->othervertex(e->p1));
  SVector3 n3 = norm_edge(e->p2, e2->othervertex(e->p2));
  if(dot(n1,n2) < 0)angle1 = M_PI;
  if(dot(n1,n3) < 0)angle2 = M_PI;

  const double angleLimit = 3 * M_PI/4.;

  if(angle1 > angleLimit && angle2 > angleLimit) return 0;
  if(angle1 > angleLimit && angle2 < angleLimit) return 1;
  if(angle1 < angleLimit && angle2 > angleLimit) return 2;
  return 3;
}

bool edgeFront::formQuad(BDS_Edge *e, BDS_Edge *left, BDS_Edge *right)
{

  printf("e (%d,%d), l(%d,%d), r(%d,%d)\n",
         e->p1->iD,e->p2->iD,
         left->p1->iD,left->p2->iD,
         right->p1->iD,right->p2->iD);
  
  //  outputScalarField(m->triangles, "deb_before.pos", 0);

  std::vector<BDS_Point*> toUpdate;

  BDS_Point *pleft  = left->othervertex(e->p1);
  BDS_Point *pright = right->othervertex(e->p2);
  
  // recover edge pleft->pright
  BDS_Edge *top = m->find_edge(pleft,pright);

  /*
    We first have to ensure that, if left or right
    are closing the front, then even number of edges should remain in
    both left and right parts of the front
   */

  if(!top) {
    //    printf("recover\n");
    //    top = m->recover_edge_fast(pleft,pright);
    //    if(!top)
    bool _fatallyFailed;
    top = m->recover_edge(pleft->iD, pright->iD,_fatallyFailed);
    //    printf("recover done %p\n",top);
    if(!top) return false;
  }
  // delete internal triangles
  emptyCavity(e, top, left, right);
  // add the quad
  m->add_quadrangle(e, left, top, right);
  // update the edge status
  // bottom edge leaves the front
  deleteFromFront(e);
  // top edge becomes part of the front

  /*  printf("(%d,%d),(%d,%d),(%d,%d),(%d,%d)\n",
         e->p1->iD,e->p2->iD,
         left->p1->iD,left->p2->iD,
         top->p1->iD,top->p2->iD,
         right->p1->iD,right->p2->iD);
  */
  //  outputScalarField(m->triangles, "deb.pos", 0);


  // if left edge was in the front, then it leaves the front
  // because it has either 2 neighboring quads or one quad
  // and the void
  // if the left edge was not in the front, then it becomes
  // part of it. 
  //  printf("coucou1\n");
  if(inFront(left)) deleteFromFront(left);
  else edges.insert(left);

  //  printf("coucou2\n");
  if(inFront(right)) deleteFromFront(right);
  else edges.insert(right);

  //  printf("coucou3\n");
  if(inFront(top)) deleteFromFront(top);
  else edges.insert(top);
  
  toUpdate.push_back(e->p1);
  toUpdate.push_back(e->p2);
  toUpdate.push_back(pleft);
  toUpdate.push_back(pright);

  for(unsigned int i = 0; i < toUpdate.size(); i++){
    toUpdate[i]->config_modified = true;
    //bool done = 
    m->smooth_point_parametric(toUpdate[i], gf);
    //    printf("smooth done %d (g %d)\n",done,toUpdate[i]->g->classif_degree);
  }

  for(unsigned int i = 0; i < toUpdate.size(); i++){
    BDS_Point *p = toUpdate[i];
    for(std::list<BDS_Edge*>::iterator itp = p->edges.begin(); 
        itp != p->edges.end(); ++ itp){
      if(inFront(*itp)){
        updateStatus(*itp);     
      } 
    }
  }  
  return true;
}

BDS_Edge *edgeFront::findOptimalEdge(BDS_Point *p, BDS_Point *avoid)
{
  eiter it1, it2;
  getFrontEdges(p, it1, it2);
  // compute bissector of front edges, this is the optimal direction
  SVector3 n1 = normal(*it1);
  SVector3 n2 = normal(*it2);
  SVector3 n = n1 + n2;
  n.normalize();

  //  printf("POINT %g %g %g N %g %g %g\n",p->X,p->Y,p->Z,n.x(),n.y(),n.z());
  
  double lowerBound = cos(M_PI / 6.0);
  BDS_Edge *found = 0;
  for(std::list<BDS_Edge*>::iterator itp = p->edges.begin(); 
      itp != p->edges.end(); ++ itp){
    // the edge is not in the front and is not bounded by quads only
    if(*it1 != *itp && *it2 != *itp && (*itp)->numTriangles()){
      BDS_Point *q = (*itp)->othervertex(p);
      SVector3 d(q->X - p->X, q->Y - p->Y, q->Z - p->Z);
      d.normalize();
      double COS = dot(n,d);
      if(COS > lowerBound && q != avoid){
        lowerBound = COS;
        found = *itp;
      } 
    }    
  }
  if(found) return found;
  else{
    std::list<BDS_Face*> ts;
    double x[2];
    const double L = 0.5*sqrt(3.0)*((*it2)->length() * (*it1)->length());
    p->getTriangles(ts);
    std::list<BDS_Face*>::iterator it = ts.begin();
    std::list<BDS_Face*>::iterator ite = ts.end();
    while(it != ite) {
      BDS_Face *t = *it;
      if(!t->e4){
        BDS_Edge *e = t->oppositeEdge(p);
        if(e->numfaces() == 2){
          BDS_Face *f = e->otherFace(t);
          if(!f->e4){
            BDS_Point *target = f->oppositeVertex(e);
            // ONLY WORKS IN 2D for now !!!!!!!!!!!!!!!!!!!
            Intersect_Edges_2d(e->p1->X, e->p1->Y,
                               e->p2->X, e->p2->Y,
                               p->X, p->Y,
                               p->X + n.x(), p->Y + n.y(), x);
            if(x[0] >= 0 && x[0] <= 1){
              SVector3 d(target->X-p->X,target->Y-p->Y,target->Z-p->Z);
              d.normalize();
              double COS = dot(n,d);
              double L2 = sqrt((target->X - p->X) *(target->X - p->X) +
                               (target->X - p->Y) *(target->X - p->Y) +
                               (target->X - p->Z) *(target->X - p->Z) );
              
              // swapping the edge alllow to find an edgge that has the right direction and
              // right size
              if(COS > cos(M_PI/6.0) && L2 < L){
                m->swap_edge(e, BDS_SwapEdgeTestQuality(false,false));
                BDS_Edge *newE = m->find_edge(p,target);
                //            printf("swapping -> %p\n",newE);
                return newE;          
              }
              // split the edge
              else{          
                BDS_Point *mid;
                mid  = m->add_point(++m->MAXPOINTNUMBER,(1.-x[0])*e->p1->u + x[0]*e->p2->u,
                                    (1.-x[0])*e->p1->v + x[0]*e->p2->v,gf);
                mid->lc() = 0.5 * (p->lc() +  target->lc());
                mid->g = e->p1->g;
                m->split_edge(e, mid);
                BDS_Edge *newE = m->find_edge(p,mid);
                //            printf("splitting -> %p %p\n",newE,e->p1->g);
                //            m->cleanup();
                return newE;
              }
            }
          }
        }
      }
      ++it;
    }    
  }
  printf("zarbi\n");
  return 0;
}

bool edgeFront::emptyFront(int tag)
{
  // front edges tagged "tag" is empty
  if(stat[tag].size() == 0) return true;
  BDS_Edge *e = *(stat[tag].begin());
  BDS_Edge *left, *right = 0;
  eiter it1, it2;

  std::vector<eiter> fe1, fe2;
 
  printf("front edges %d %d tag %d\n", e->p1->iD, e->p2->iD, tag);

  switch(tag){
    // both left and right neighboring edges are
    // sufficiently angled in order to allow to
    // form the quad
  case 3:
    {
      getFrontEdges(e->p1, it1, it2);
      if(*it1 == e) left=*it2;
      else left = *it1;
      getFrontEdges(e->p2, it1, it2);
      if(*it1 == e) right = *it2;
      else right = *it1;
      //      printf("case 3\n");
    }
    break;
    // right edge is angled with current edge
    // we therefore find a new front edge in the
    // mesh that allows to move to tag 3
  case 2:
    getFrontEdges(e->p1, it1, it2);
    if(*it1 == e) left = *it2;
    else left = *it1;
    //    printf("case 2 left edge %p\n",left);
    right = findOptimalEdge(e->p2, left->othervertex(e->p1));
    if(right) getFrontEdges(right->othervertex(e->p2), fe2);
    break;
    // left edge is angled with current edge
    // we therefore find a new front edge in the
    // mesh that allows to move to tag 3
  case 1:
    getFrontEdges(e->p2, it1, it2);
    if(*it2 == e) right = *it1;
    else right = *it2;
    //    printf("case 1 right edge %p %p\n",e,right);
    left = findOptimalEdge(e->p1, right->othervertex(e->p2));
    if(left) getFrontEdges(left->othervertex(e->p1), fe1);
    break;
    // no neighboring edge is angled with current edge
    // we therefore find a new front edge in the
    // mesh that allows to move to tag 3
  case 0:
    left = findOptimalEdge(e->p1, 0);
    if(left) right= findOptimalEdge(e->p2, left->othervertex(e->p1));
    if(right) getFrontEdges(right->othervertex(e->p2), fe2);
    if(left) getFrontEdges(left->othervertex(e->p1), fe1);
    //    printf("strange\n");
    break;
  default:
    Msg::Error("Unknown case in emptyFront");
    return false;
  }

  if(fe1.size() || fe2.size() || !left || !right || !formQuad(e, left, right)){
    //    printf("front cloeses : algo has to be finished\n");
    stat[tag].erase(stat[tag].begin());
    stat[4].insert(e);
  }
  return false;
}

static int numQuads(BDS_Mesh *m)
{
  int N = 0;
  for(std::list<BDS_Face*>::iterator it = m->triangles.begin();
      it != m->triangles.end(); ++it){
    if((*it)->e4) N++;
  }
  return N;
}

int gmshQMorph(GFace *gf)
{
  // assert first that there exist a triangulation of
  // the face  
  if(!gf->triangles.size()){
    Msg::Warning("Cannot Quadrilaterize a face that has not been triangulated");
    return -1;
  }

  // create data structures for mesh manipulations
  std::list<GFace*> l; l.push_back(gf);
  BDS_Mesh *pm = gmsh2BDS(l);

  // create the front
  edgeFront front(pm,gf);
  front.initiate();
  
  int ITER = 1;
  
  // empty the front for front edges tagged 3, 2, 1 then 0
  int _numQuads = 0;
  while(1){
    if(front.emptyFront(3)){
      if(front.emptyFront(2)){
        if(front.emptyFront(1)){
          if(front.emptyFront(0)){
            int ns;
            smoothVertexPass(gf,*pm,ns,false);
            printf("nex row iter %6d->>>\n",ITER);
            front.initiate();
            int _numQuadsNew = numQuads(pm);
            if(front.edges.size() == 0 || _numQuads == _numQuadsNew)
              break;
            _numQuads = _numQuadsNew;
          }
        }
      }
    }
    ITER++;
    if(1 || ITER%100 == 0){
      char name[256];
      sprintf(name,"qmorph-face%d-iter%d.pos",gf->tag(),ITER);
      outputScalarField(pm->triangles, name, 0);
    }
    //    if(ITER == 1123)break;
  }
  // delete the BDS
  delete pm;
  return 1;
}

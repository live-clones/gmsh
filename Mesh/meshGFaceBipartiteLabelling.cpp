// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
// Original idea of Christos Georgiadis -- 2021 

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "meshTriangulation.h"
#include "SVector3.h"
#include "GModel.h"
#include "GFace.h"
#include "MQuadrangle.h"
#if defined(HAVE_QUADMESHINGTOOLS)
#include "qmtMeshGeometryOptimization.h"
#include "qmtMeshUtils.h"
#include "cppUtils.h"
#include "geolog.h"
#endif
#include "gmsh.h"
#include "meshOctreeLibOL.h"

static void computeNaturalCross (PolyMesh::Vertex *v,
				 SVector3 &n,
				 SVector3 &t1,
				 SVector3 &t2){
  PolyMesh::HalfEdge *he = v->he;
  n = SVector3(0,0,0);
  while(1){
    if(he->opposite == NULL) {
      t1 = he->d();
      break;
    }
    SVector3 ta = he->d();
    he = he->opposite->next;
    SVector3 tb = he->d();
    n += crossprod(ta,tb);
  }

  he = v->he->prev;
  while(1){
    if(he->opposite == NULL) {
      t2 = -he->d();
      break;
    }
    SVector3 ta = -he->d();
    he = he->opposite->prev;
    SVector3 tb = -he->d();
    n += crossprod(ta,tb);
  }

  n.normalize();
  
  if (fabs(dot(t1,t2)) > 0.95){
    t2 = crossprod(n,t1);
    t2.normalize();
  }
  else if (fabs(dot(t1,t2)) > 0.5){
    t1 = t1-t2;
    t1.normalize();
    t2 = crossprod(n,t1);
    t2.normalize();
  }
}

static void printLabelling (const char* fn, PolyMesh *pm, std::unordered_map<PolyMesh::Vertex*,int> &_labels)
{
  if (Msg::GetVerbosity()  < 99)return;
  FILE *f = fopen(fn,"w");
  fprintf(f,"View \"labels\"{\n");
  for (auto v :  pm->vertices){
    fprintf(f,"SP(%g,%g,%g){%d};\n",
	    v->position.x(),v->position.y(),v->position.z(),_labels[v]);
    /*
    if (pm->degree(v) == -1){
      SVector3 n,t1,t2;
      computeNaturalCross (v,n,t1,t2);
      fprintf(f,"VP(%g,%g,%g){%g,%g,%g};\n",
	      v->position.x(),v->position.y(),v->position.z(),t1.x(),t1.y(),t1.z());
      fprintf(f,"VP(%g,%g,%g){%g,%g,%g};\n",
	      v->position.x(),v->position.y(),v->position.z(),t2.x(),t2.y(),t2.z());
      
    }
    */
  }

  for (auto face : pm->faces){
    PolyMesh::Vertex *v0 = face->he->v;
    PolyMesh::Vertex *v1 = face->he->next->v;
    PolyMesh::Vertex *v2 = face->he->next->next->v;
    PolyMesh::Vertex *v3 = face->he->next->next->next->v;
    int l0 = _labels[v0];
    int l1 = _labels[v1];
    int l2 = _labels[v2];
    int color;
    if ((l0 == 0 && l1 == 0 && l2 == 0) ||
	(l0 == 1 && l1 == 1 && l2 == 1)) color = 1;
    else color = 0;
    if (v0 == v3)
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
	      v0->position.x(),v0->position.y(),v0->position.z(),
	      v1->position.x(),v1->position.y(),v1->position.z(),
	      v2->position.x(),v2->position.y(),v2->position.z(),
	      color,color,color);
    else
      fprintf(f,"SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
	      v0->position.x(),v0->position.y(),v0->position.z(),
	      v1->position.x(),v1->position.y(),v1->position.z(),
	      v2->position.x(),v2->position.y(),v2->position.z(),
	      v3->position.x(),v3->position.y(),v3->position.z(),
	      0,0,0,0);
      
  }
  fprintf(f,"};\n");
  fclose(f);
}

// inline int merge_faces_2(PolyMesh::HalfEdge *he){
//   PolyMesh::HalfEdge *heo = he->opposite;

//   if(heo == nullptr) return -1;

//   PolyMesh::Face *to_delete = heo->f;
  
//   do{
//     heo->f = he->f;
//     heo = heo->next;
//   }while(heo != he->opposite);
  
//   he->next->prev = heo->prev;
//   heo->prev->next = he->next;
//   he->prev->next = heo->next;
//   heo->next->prev = he->prev;

//   he->f->he = he->next;
//   he->v->he = heo->next;
//   heo->v->he = he->next;
  
//   // remove afterwards...
//   he->v = nullptr;
//   heo->v = nullptr;
//   to_delete->he = nullptr;
//   return 0;
// }

void laplacianSmoothing(PolyMesh::Vertex* v) {
  SVector3 avg(0.,0.,0.);
  double n = 0.;
  PolyMesh::HalfEdge *he = v->he;
  do {
    he = he->opposite;
    if(he == NULL) return;
    avg = avg + he->v->position;
    n += 1;
    he = he->next;
  } while(he != v->he);
  if (n == 0.) return;
  v->position = avg * double(1./n);
}

void laplacianSmoothingForQuadMesh(PolyMesh::Vertex* v,
    std::unordered_map<PolyMesh::Vertex*,int> &_labels
    ) {
  auto itv = _labels.find(v);
  if (itv == _labels.end()) return;
  int color = itv->second;

  SVector3 avg(0.,0.,0.);
  double n = 0.;
  PolyMesh::HalfEdge *he = v->he;
  do {
    he = he->opposite;
    if(he == NULL) return;
    auto itv2 = _labels.find(he->v);
    if (itv2 != _labels.end() && itv2->second != color) {
      avg = avg + he->v->position;
      n += 1;
    }
    he = he->next;
  } while(he != v->he);
  if (n == 0.) return;
  v->position = avg * double(1./n);
}

double quadQuality(PolyMesh* pm, PolyMesh::Face* f) {
  if (pm->num_sides(f->he) == 4) {
    PolyMesh::Vertex *v0 = f->he->v;
    PolyMesh::Vertex *v1 = f->he->next->v;
    PolyMesh::Vertex *v2 = f->he->next->next->v;
    PolyMesh::Vertex *v3 = f->he->next->next->next->v;
    MVertex a(v0->position.x(),v0->position.y(),v0->position.z());
    MVertex b(v1->position.x(),v1->position.y(),v1->position.z());
    MVertex c(v2->position.x(),v2->position.y(),v2->position.z());
    MVertex d(v3->position.x(),v3->position.y(),v3->position.z());
    MQuadrangle q(&a,&b,&c,&d);
    double sicn = q.minSICNShapeMeasure();
    if (std::isnan(sicn)) sicn = -999.;
    return sicn;
  }
  Msg::Error("quadQuality: not a quad");
  return -1.;
}

double quadQualityAfterMerge(PolyMesh::HalfEdge* he) {
  /* quad vertices: [v0,v1,v2,v3] */
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->next->v;
  PolyMesh::Vertex *v2 = he->next->v;
  PolyMesh::Vertex *v3 = he->opposite->next->next->v;
  MVertex a(v0->position.x(),v0->position.y(),v0->position.z());
  MVertex b(v1->position.x(),v1->position.y(),v1->position.z());
  MVertex c(v2->position.x(),v2->position.y(),v2->position.z());
  MVertex d(v3->position.x(),v3->position.y(),v3->position.z());
  MQuadrangle q(&a,&b,&c,&d);
  double sicn = q.minSICNShapeMeasure();
  if (std::isnan(sicn)) sicn = -999.;
  return sicn;
}

SVector3 face_center(PolyMesh::Face* f) { 
  const PolyMesh::HalfEdge *he = f->he;
  SVector3 avg(0.,0.,0.);
  double sum = 0.;
  do {
    avg = avg + he->v->position;
    sum += 1.;
    he = he->next;
  } while(he != f->he);
  if (sum > 0.) avg = 1./sum * avg;
  return avg;
}

void setOpposite(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->opposite = b;
  b->opposite = a;
}

void setConsecutive(PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b) {
  a->next = b;
  b->prev = a;
}

void setQuadRelations(PolyMesh::Face* f, 
    PolyMesh::HalfEdge* a, PolyMesh::HalfEdge* b,
    PolyMesh::HalfEdge* c, PolyMesh::HalfEdge* d) {
  f->he = a;
  a->f = f;
  b->f = f;
  c->f = f;
  d->f = f;
  setConsecutive(a,b);
  setConsecutive(b,c);
  setConsecutive(c,d);
  setConsecutive(d,a);
}

bool fixFlatBoundaryQuadWithInterior(PolyMesh* pm, PolyMesh::HalfEdge* he0) {
  PolyMesh::Face* f0 = he0->f;
  PolyMesh::HalfEdge* he1 = he0->next;
  PolyMesh::HalfEdge* he2 = he1->next;
  PolyMesh::HalfEdge* he3 = he2->next;
  PolyMesh::Vertex* v2 = he2->v;

  int valInterior = pm->degree(v2);
  if (valInterior == 5) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 5, fixing ...");
    PolyMesh::HalfEdge* he4 = he1->opposite->prev->opposite->prev;
    PolyMesh::HalfEdge* he4b = he4->opposite;

    /* New vertices */
    PolyMesh::Vertex* v5 = new PolyMesh::Vertex(he1->opposite->prev->center(),-1);
    PolyMesh::Vertex* v6 = new PolyMesh::Vertex(he2->opposite->next->center(),-1);
    pm->vertices.push_back(v5);
    pm->vertices.push_back(v6);
    v5->he = he1->opposite;
    v6->he = he2;
    v2->position = 0.8 * v2->position  + 0.2 * he0->v->position;

    /* Update halfedge vertex outside the three quads */
    he1->opposite->v = v5;
    he4->next->v = v5;
    he2->opposite->next->v = v6;
    he4b->v = v6;
    /* Update halfedge vertex inside the three quads */
    he2->v = v6;

    /* New halfedges and new quads */
    PolyMesh::HalfEdge* sp = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* s = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sb = new PolyMesh::HalfEdge(he0->v);
    PolyMesh::HalfEdge* sbn = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* spb = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sbnb = new PolyMesh::HalfEdge(v6);
    PolyMesh::HalfEdge* he4o = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* he4bo = new PolyMesh::HalfEdge(he4->v);
    pm->hedges.push_back(sp);
    pm->hedges.push_back(s);
    pm->hedges.push_back(sb);
    pm->hedges.push_back(sbn);
    pm->hedges.push_back(spb);
    pm->hedges.push_back(sbnb);
    pm->hedges.push_back(he4o);
    pm->hedges.push_back(he4bo);
    setOpposite(s,sb);
    setOpposite(sp,spb);
    setOpposite(sbn,sbnb);
    setOpposite(he4,he4o);
    setOpposite(he4b,he4bo);

    PolyMesh::Face* nfr = new PolyMesh::Face(he3);
    PolyMesh::Face* nft = new PolyMesh::Face(sbnb);
    nfr->data = f0->data;
    nft->data = f0->data;
    pm->faces.push_back(nfr);
    pm->faces.push_back(nft);

    setQuadRelations(f0,he0,he1,sp,s);
    setQuadRelations(nfr,he2,he3,sb,sbn);
    setQuadRelations(nft,spb,he4o,he4bo,sbnb);

    laplacianSmoothing(v5);
    laplacianSmoothing(v6);

    return true;
  } else if (valInterior == 4) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 4, fixing ...");
    PolyMesh::HalfEdge* tl = he1->opposite->prev->opposite;
    PolyMesh::HalfEdge* tr = tl->prev;
    PolyMesh::Vertex* vtop = tl->next->next->v;
    PolyMesh::Face* ftl = tl->f;

    /* New vertices */
    PolyMesh::Vertex* v5 = new PolyMesh::Vertex(face_center(he1->opposite->f),-1);
    PolyMesh::Vertex* v6 = new PolyMesh::Vertex(face_center(he2->opposite->f),-1);
    pm->vertices.push_back(v5);
    pm->vertices.push_back(v6);
    v5->he = he1->opposite;
    v6->he = he2;

    /* In bottom quads (adjacent to bdr) */
    PolyMesh::HalfEdge* sp = new PolyMesh::HalfEdge(v5);
    PolyMesh::HalfEdge* s = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sb = new PolyMesh::HalfEdge(he0->v);
    PolyMesh::HalfEdge* sbn = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* spb = new PolyMesh::HalfEdge(v2);
    PolyMesh::HalfEdge* sbnb = new PolyMesh::HalfEdge(v6);
    pm->hedges.push_back(sp);
    pm->hedges.push_back(s);
    pm->hedges.push_back(sb);
    pm->hedges.push_back(sbn);
    pm->hedges.push_back(spb);
    pm->hedges.push_back(sbnb);
    setOpposite(s,sb);
    setOpposite(sp,spb);
    setOpposite(sbn,sbnb);

    PolyMesh::Face* nfr = new PolyMesh::Face(he3);
    nfr->data = f0->data;
    pm->faces.push_back(nfr);

    v2->he = s;
    setQuadRelations(f0,he0,he1,sp,s);
    setQuadRelations(nfr,he2,he3,sb,sbn);

    /* In top quads */
    PolyMesh::HalfEdge* tm = new PolyMesh::HalfEdge(vtop);
    PolyMesh::HalfEdge* tmb = new PolyMesh::HalfEdge(v2);
    pm->hedges.push_back(tm);
    pm->hedges.push_back(tmb);
    setOpposite(tm,tmb);

    PolyMesh::Face* nftr = new PolyMesh::Face(tr);
    nftr->data = f0->data;
    pm->faces.push_back(nftr);

    setQuadRelations(ftl,tl,tl->next,tm,spb);
    setQuadRelations(nftr,tr->prev,tr,sbnb,tmb);

    /* Update halfedge vertex inside the four quads */
    tl->v = v5;
    he2->v = v6;
    /* Update halfedge vertex outside the four quads */
    he1->opposite->v = v5;
    he2->opposite->next->v = v6;

    laplacianSmoothing(v5);
    laplacianSmoothing(v6);

    return true;
  } else if (valInterior == 3) {
    Msg::Debug("fixFlatBoundaryQuadWithInterior: tip is valence 3, fixing ...");
    PolyMesh::Face* f1 = he1->opposite->f;
    PolyMesh::Face* f2 = he2->opposite->f;

    setQuadRelations(f1, 
        he0, 
        he1->opposite->next,
        he1->opposite->next->next,
        he1->opposite->next->next->next);

    setQuadRelations(f2, 
        he3, 
        he2->opposite->next,
        he2->opposite->next->next,
        he2->opposite->next->next->next);

    /* Flag for delete by pm->clean */
    f0->he = nullptr;
    v2->he = nullptr;
    he1->f = nullptr;
    he1->opposite->f = nullptr;
    he2->f = nullptr;
    he2->opposite->f = nullptr;

    return true;
  }

  Msg::Warning("flat boundary quad but interior valence %i, no rule to fix it", valInterior);
  return false;
}

bool fixFlatBoundaryQuadWithNeighbor(PolyMesh* pm, PolyMesh::HalfEdge* he0) {
  PolyMesh::Face* f0 = he0->f;
  PolyMesh::HalfEdge* he1 = he0->next;
  PolyMesh::HalfEdge* he2 = he1->next;
  PolyMesh::HalfEdge* he3 = he2->next;
  PolyMesh::Vertex* v2 = he2->v;
  if (he1->opposite != nullptr) {
    Msg::Debug("fixFlatBoundaryQuadWithNeighbor: quad on left ...");
    PolyMesh::HalfEdge* he4 = he1->opposite;
    PolyMesh::HalfEdge* he7 = he4->prev;
    PolyMesh::Face* f1 = he4->f;
    PolyMesh::Vertex* a = new PolyMesh::Vertex(face_center(f0),-1);
    PolyMesh::Vertex* b = new PolyMesh::Vertex(face_center(f1),-1);
    pm->vertices.push_back(a);
    pm->vertices.push_back(b);
    PolyMesh::HalfEdge* ab = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* ba = new PolyMesh::HalfEdge(b);
    pm->hedges.push_back(ab);
    pm->hedges.push_back(ba);
    setOpposite(ab,ba);
    a->he = ab;
    b->he = ba;
    PolyMesh::HalfEdge* av0 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v0a = new PolyMesh::HalfEdge(he0->v);
    pm->hedges.push_back(av0);
    pm->hedges.push_back(v0a);
    setOpposite(av0,v0a);
    PolyMesh::HalfEdge* av2 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v2a = new PolyMesh::HalfEdge(he2->v);
    pm->hedges.push_back(av2);
    pm->hedges.push_back(v2a);
    setOpposite(av2,v2a);
    PolyMesh::HalfEdge* bv7 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v7b = new PolyMesh::HalfEdge(he7->v);
    pm->hedges.push_back(bv7);
    pm->hedges.push_back(v7b);
    setOpposite(bv7,v7b);
    he4->v = b;
    PolyMesh::Face* fb = new PolyMesh::Face(he0);
    PolyMesh::Face* ft = new PolyMesh::Face(he7);
    pm->faces.push_back(fb);
    pm->faces.push_back(ft);
    fb->data = f0->data;
    ft->data = f0->data;
    v2->he = he2;
    he0->v->he = he0;
    he7->v->he = he7;
    setQuadRelations(f0,he2,he3,v0a,av2);
    setQuadRelations(f1,he4,he4->next,he4->next->next,v7b);
    setQuadRelations(ft,he7,v2a,ab,bv7);
    setQuadRelations(fb,he0,he1,ba,av0);

    laplacianSmoothing(a);
    laplacianSmoothing(b);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    return true;
  } else if (he2->opposite != nullptr) {
    Msg::Debug("fixFlatBoundaryQuadWithNeighbor: quad on right ...");
    PolyMesh::HalfEdge* he4 = he2->opposite;
    PolyMesh::HalfEdge* he5 = he4->next;
    PolyMesh::HalfEdge* he6 = he4->next->next;
    PolyMesh::Face* f1 = he4->f;
    PolyMesh::Vertex* a = new PolyMesh::Vertex(face_center(f0),-1);
    PolyMesh::Vertex* b = new PolyMesh::Vertex(face_center(f1),-1);
    pm->vertices.push_back(a);
    pm->vertices.push_back(b);
    PolyMesh::HalfEdge* ab = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* ba = new PolyMesh::HalfEdge(b);
    pm->hedges.push_back(ab);
    pm->hedges.push_back(ba);
    setOpposite(ab,ba);
    a->he = ab;
    b->he = ba;
    PolyMesh::HalfEdge* av0 = new PolyMesh::HalfEdge(a);
    PolyMesh::HalfEdge* v0a = new PolyMesh::HalfEdge(he0->v);
    pm->hedges.push_back(av0);
    pm->hedges.push_back(v0a);
    setOpposite(av0,v0a);

    he4->v = a;

    PolyMesh::HalfEdge* bv3 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v3b = new PolyMesh::HalfEdge(he3->v);
    pm->hedges.push_back(bv3);
    pm->hedges.push_back(v3b);
    setOpposite(bv3,v3b);

    PolyMesh::HalfEdge* bv6 = new PolyMesh::HalfEdge(b);
    PolyMesh::HalfEdge* v6b = new PolyMesh::HalfEdge(he6->v);
    pm->hedges.push_back(bv6);
    pm->hedges.push_back(v6b);
    setOpposite(bv6,v6b);

    PolyMesh::Face* fb = new PolyMesh::Face(he3);
    PolyMesh::Face* ft = new PolyMesh::Face(he4);
    pm->faces.push_back(fb);
    pm->faces.push_back(ft);
    fb->data = f0->data;
    ft->data = f0->data;
    he3->v->he = he3;
    he0->v->he = he0;
    he6->v->he = he6;
    setQuadRelations(f0,he0,he1,he2,av0);
    setQuadRelations(f1,he6,he6->next,v3b,bv6);
    setQuadRelations(ft,ba,he4,he5,v6b);
    setQuadRelations(fb,he3,v0a,ab,bv3);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    laplacianSmoothing(a);
    laplacianSmoothing(b);
    return true;
  }
  Msg::Warning("flat boundary quad but tip on bdr, no rule to fix it");
  return false;
}

inline double angleAcosDot(const SVector3& a, const SVector3& b) {
  double dp = dot(a,b);
  if (dp < -1.) {
    dp = -1.;
  } else if (dp > 1.) {
    dp = 1.;
  }
  return acos(dp);
}

void meshGFaceQuadrangulateBipartiteLabelling (int faceTag,
    std::map<MVertex*,int>* bipartiteLabel) 
{
  PolyMesh *pm = nullptr;
  Msg::Debug("- Face %i: quadrangulation using Bipartite Labelling",faceTag);

  int result = GFace2PolyMesh (faceTag, &pm);
  Msg::Debug("-- %d  Transfer to Half Edge done\n",faceTag);
  if (result == -1)return;

  std::unordered_map<PolyMesh::Vertex*,int> _labels;

  if (bipartiteLabel == nullptr || bipartiteLabel->size() == 0) {
    /* Create a labelling from scratch */
    Msg::Debug("-- generate bipartite labels from scratch");

    std::queue<PolyMesh::Vertex*> _queue;
    std::unordered_map<PolyMesh::Vertex*,SVector3> _dirs;


    for (auto v : pm->vertices)_labels[v] = -1;

    for (auto v : pm->vertices){
      // boundary vertex , degree returns 1 (one of the halfedges has no opposite)
      //    printf("vertex %d\n",v->data);
      //    printf("vertex %d has degree %d\n",v->data,pm->degree(v));
      if (_labels[v] == -1 && pm->degree(v) == -1) {
        //      printf("vertex %d is on the boundary\n",v->data);
        PolyMesh::HalfEdge *he = v->he;
        bool currentLabel = true;
        _labels[v] = currentLabel;
        _queue.push(v);
        size_t nodeCount = 0;
        while(1){
          if(he->opposite == NULL) {
            he = he->next;
            //	  printf("--> vertex %d is on the boundary\n",he->v->data);
            nodeCount++;
            if(_labels[he->v] != -1)break;	  
            currentLabel = !currentLabel;
            _labels[he->v] = currentLabel;
            _queue.push(he->v);
          }
          else he = he->opposite->next;
        }
        if (nodeCount%2 != 0){
          Msg::Warning("Bipartite algorithm requires an even numer of boundary"
              " vertices on every edge loop that bounds face %d. This loop has %d nodes and some triangles will remain.", faceTag,nodeCount );		     
        }
      }
    }

    Msg::Debug("-- %d  Initial labelling done\n",faceTag);

    while(!_queue.empty()){
      //    printf("SIZE %lu\n",_queue.size());
      auto v = _queue.front();
      _queue.pop();
      bool currentLabel = _labels[v];

      if (pm->degree(v) == -1){
        SVector3 n,t1,t2;
        computeNaturalCross (v,n,t1,t2);
        PolyMesh::HalfEdge *he = v->he;
        while(he->opposite)he = he->opposite->next;
        double dot_max = 0.0;
        PolyMesh::HalfEdge *best = nullptr;
        //      printf("treating %lu\n",v->data);
        while(he){
          //	printf("  %lu\n",he->prev->v->data);
          SVector3 t = he->d();
          if (_labels[he->next->v] == -1){
            double dd = std::max(fabs(dot(t1,t)),
                fabs(dot(t2,t)));
            if (dd > dot_max){
              dot_max = dd;
              best = he;
            }
          }
          he = he->prev->opposite;
        }
        if (best && dot_max > 0.9){
          //	printf("connecting %lu to (%lu %lu) (%g %g)\n",v->data,best->v->data,best->next->v->data,
          //	       best->d().x(),best->d().y());
          _dirs[best->next->v] = best->d();
          _labels[best->next->v] = !currentLabel;
          _queue.push(best->next->v);
        }
      }
      else {
        SVector3 n = pm->normal(v);
        SVector3 t1 = _dirs[v];
        SVector3 t2 = crossprod(n,t1);
        PolyMesh::HalfEdge *he = v->he;
        std::vector<std::pair<double, PolyMesh::HalfEdge *> > bests;      
        //      printf ("Vertex %d (%g %g): ",v->data,t1.x(),t1.y());
        do {
          SVector3 t = he->d();
          double dd = -std::max(fabs(dot(t1,t)),
              fabs(dot(t2,t)));
          bests.push_back(std::make_pair(dd,he));
          //	printf ("(%d,%g,%g,%g) ",he->next->v->data,dd,t.x(),t.y());
          he = he->opposite->next;
        } while(he != v->he);

        std::sort(bests.begin(),bests.end());

        int count = 0;
        for (auto it : bests){
          if (count ++ > 3)break;
          PolyMesh::HalfEdge *best = it.second;	
          if (_labels[best->next->v] == -1){	  
            //	  printf("(%lu %g)", best->next->v->data, it.first);
            _dirs[best->next->v] = best->d();
            _labels[best->next->v] = /*rand()%2; // TEST*/ !currentLabel;
            _queue.push(best->next->v);
          }
        }
        //      printf("\n");
      }
    }

    Msg::Debug("-- %d  internal labelling done\n",faceTag);

    // enhancement.
    bool changed = false;
    printLabelling ("labelling_initial.pos",pm, _labels);  
    do {
      changed = false;
      for (auto v : pm->vertices){
        if (pm->degree(v) != -1){
          PolyMesh::HalfEdge *he = v->he;
          int myIndex = _labels[v];
          if (myIndex == -1){
            _labels[v] = myIndex = 1;
          }
          int oppositeIndex = (myIndex==1)?0:1;
          std::vector<int> l;
          do {
            l.push_back(_labels[he->next->v]);
            he = he->opposite->next;
          } while(he != v->he);
          int nbInvalidBefore = 0;
          int nbInvalidAfter = 0;
          for (size_t i=0;i<l.size();i++){
            int i0 = l[i];
            int i1 = l[(i+1)%l.size()];
            if (i0 == i1 && i0 == myIndex) nbInvalidBefore++;
            if (i0 == i1 && i0 == oppositeIndex) nbInvalidAfter++;
          }
          if (nbInvalidBefore > nbInvalidAfter){
            //	  printf("%d %d\n",nbInvalidBefore,nbInvalidAfter);
            _labels[v]=oppositeIndex;
            changed = true;
          }
        }
      }
    } while(changed);
    printLabelling ("labelling_final.pos",pm, _labels);  

    Msg::Debug("-- %d  optimum labelling done\n",faceTag);

  } else {
    Msg::Debug("-- set bipartite labels from exterior");
    /* Use existing labelling (from the surface mesher) */
    for (size_t i = 0; i < pm->vertices.size(); ++i) {
      int nodeTag = pm->vertices[i]->data;
      MVertex* v = GModel::current()->getMeshVertexByTag(nodeTag);
      if (v == nullptr) {
        Msg::Error("vertex with nodeTag %i not found in GModel mesh", nodeTag);
        continue;
      }
      auto it = bipartiteLabel->find(v);
      if (it == bipartiteLabel->end()) {
        Msg::Warning("vertex %i (entity: %i,%i) not found in bipartite labels, use color 0", 
            v->getNum(), v->onWhat()->dim(),v->onWhat()->tag());
        _labels[pm->vertices[i]] = 0;
        GeoLog::add(pm->vertices[i]->position,0.,"label_not_found");

        Msg::Error("TODOMX abort");
        GeoLog::flush();
        gmsh::fltk::run();
        abort();

        continue;
      }
      _labels[pm->vertices[i]] = it->second;

      GeoLog::add(pm->vertices[i]->position,double(it->second),"label");
    }
  }

  size_t nsplit = 0;
  while (true) {
    size_t n = 0;
    // split invalid edges according to labels
    for (auto he : pm->hedges) if (he->opposite  != nullptr){
      PolyMesh::Vertex *v0 = he->v;
      PolyMesh::Vertex *v1 = he->next->v;
      PolyMesh::Vertex *v2 = he->next->next->v;
      PolyMesh::Vertex *v3 = he->opposite->next->next->v;
      int l0 = _labels[v0];
      int l1 = _labels[v1];
      int l2 = _labels[v2];
      int l3 = _labels[v3];
      if (l0 == l1 && l0 == l2 && l0 == l3){
        SVector3 pos = (v0->position+v1->position)*.5;
        if (pm->split_edge (he,pos,-1) == 0){
          n += 1;
          PolyMesh::Vertex* nv = pm->vertices[pm->vertices.size()-1];
          _labels[nv] = l0 == 1 ? 0 : 1;
          laplacianSmoothingForQuadMesh(nv,_labels);
        }
      }
      else if (l0 == l1 && l0 == l2){
        SVector3 pos = (v0->position+v1->position)*.5;
        if (pm->split_edge (he,pos,-1) == 0){
          n += 1;
          PolyMesh::Vertex* nv = pm->vertices[pm->vertices.size()-1];
          _labels[nv] = l0 == 1 ? 0 : 1;
          laplacianSmoothingForQuadMesh(nv,_labels);
        }	
      }
    }    

    nsplit += n;
    if (n == 0) break; /* no split in current pass */
  }

  Msg::Debug("-- %d  steiner points added\n",faceTag);

  printLabelling ("labelling_final_split.pos",pm, _labels);  
  
  Msg::Debug("-- combine triangles into quads");
  for (auto he : pm->hedges){
    if (he->v != nullptr && he->opposite  != nullptr){
      PolyMesh::Vertex *v0 = he->v;
      PolyMesh::Vertex *v1 = he->next->v;
      int l0 = _labels[v0];
      int l1 = _labels[v1];
      if (l0 == l1 &&
          pm->num_sides(he) == 3 &&
          pm->num_sides(he->opposite) == 3) pm->merge_faces (he); 
    }
  }
  pm->clean();
  printLabelling ("labelling_final_split_quad.pos",pm, _labels);  
  
  Msg::Debug("-- %d  quads created\n",faceTag);

  Msg::Debug("-- check flat quads on boundary");
  std::unordered_set<PolyMesh::Vertex*> onBdr;
  for (auto he : pm->hedges) if (he->opposite == nullptr) {
    onBdr.insert(he->first());
    onBdr.insert(he->second());
  } 
  size_t nflatfix = 0;
  for (auto he0 : pm->hedges) if (he0->opposite == nullptr && he0->next->opposite == nullptr) {
    PolyMesh::HalfEdge* he1 = he0->next;
    PolyMesh::HalfEdge* he2 = he1->next;
    PolyMesh::HalfEdge* he3 = he2->next;
    if (he2->opposite != nullptr && he3->opposite != nullptr) {
      /* The tip of the flat quad is inside the surface mesh */
      PolyMesh::Vertex* intVertex = he3->v;
      if (onBdr.find(intVertex) != onBdr.end()) continue;
      double sicn = quadQuality(pm, he1->f);
      double aglDeg = angleAcosDot(he0->d(),he1->d()) * 180./M_PI;
      if (aglDeg < 5 || (sicn < 0.1 && aglDeg < 30)) {
        // printf("quality: %f, agl: %f\n",sicn, aglDeg);
        // GeoLog::add(he0->center(),he0->d(),"agl"+std::to_string(aglDeg));
        // GeoLog::add(he1->center(),he1->d(),"agl"+std::to_string(aglDeg));
        bool okf = fixFlatBoundaryQuadWithInterior(pm, he1);
        if (okf) {
          nflatfix += 1;
        } else {
          Msg::Error("failed to fix flat quad on boundary");
        }
      }
    } else if (he2->opposite != nullptr || he3->opposite != nullptr) {
      /* The tip of the flat quad is on the boundary, so the configuration
       * is very constrained, but there is one side adjacent to another quad */
      double sicn = quadQuality(pm, he1->f);
      double aglDeg = angleAcosDot(he0->d(),he1->d()) * 180./M_PI;
      if (aglDeg < 5 || (sicn < 0.1 && aglDeg < 30)) {
        // printf("quality: %f, agl: %f\n",sicn, aglDeg);
        bool okf = fixFlatBoundaryQuadWithNeighbor(pm, he1);
        if (okf) {
          nflatfix += 1;
        } else {
          Msg::Error("failed to fix flat quad on boundary");
        }
      }
    }
  }

  pm->clean();
  
  PolyMesh2GFace(pm, faceTag);

  Msg::Debug("-- %d  2 gmsh done\n",faceTag);

  delete pm;

  GFace *gf = GModel::current()->getFaceByTag(faceTag);
  if (gf->triangles.size() > 0) {
    Msg::Warning("- Face %i: bipartite labelling and recombination: %i splits, %li flat fixed, %li quads, %li triangles",
        gf->tag(), nsplit, nflatfix, gf->quadrangles.size(), gf->triangles.size());
  } else {
    Msg::Info("- Face %i: bipartite labelling and recombination: %i splits, %li flat fixed, %li quads, %li triangles", 
        gf->tag(), nsplit, nflatfix, gf->quadrangles.size(), gf->triangles.size());
  }

  GeoLog::flush(); // TODOMX debug
  
  // Msg::Error("TODOMX");
  // gmsh::fltk::run();
  // abort();

  /*  GFace *gf = GModel::current()->getFaceByTag(faceTag);
  SurfaceProjector sp;
  fillSurfaceProjector(gf, &sp);
  optimizeGeometryQuadMesh(gf, &sp);
  */
}

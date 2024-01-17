// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Original idea of Christos Georgiadis -- 2021

#include <queue>
#include <unordered_map>
#include "meshTriangulation.h"
#include "SVector3.h"
#include "GModel.h"
#include "GFace.h"
#include "meshOctreeLibOL.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "qmtMeshGeometryOptimization.h"
#include "qmtMeshUtils.h"

static void computeNaturalCross(PolyMesh::Vertex *v, SVector3 &n, SVector3 &t1,
                                SVector3 &t2)
{
  PolyMesh::HalfEdge *he = v->he;
  n = SVector3(0, 0, 0);
  while(1) {
    if(he->opposite == NULL) {
      t1 = he->d();
      break;
    }
    SVector3 ta = he->d();
    he = he->opposite->next;
    SVector3 tb = he->d();
    n += crossprod(ta, tb);
  }

  he = v->he->prev;
  while(1) {
    if(he->opposite == NULL) {
      t2 = -he->d();
      break;
    }
    SVector3 ta = -he->d();
    he = he->opposite->prev;
    SVector3 tb = -he->d();
    n += crossprod(ta, tb);
  }

  n.normalize();

  if(fabs(dot(t1, t2)) > 0.95) {
    t2 = crossprod(n, t1);
    t2.normalize();
  }
  else if(fabs(dot(t1, t2)) > 0.5) {
    t1 = t1 - t2;
    t1.normalize();
    t2 = crossprod(n, t1);
    t2.normalize();
  }
}

static void printLabelling(const char *fn, PolyMesh *pm,
                           std::unordered_map<PolyMesh::Vertex *, int> &_labels)
{
  if(Msg::GetVerbosity() < 99) return;
  FILE *f = fopen(fn, "w");
  fprintf(f, "View \"labels\"{\n");
  for(auto v : pm->vertices) {
    fprintf(f, "SP(%g,%g,%g){%d};\n", v->position.x(), v->position.y(),
            v->position.z(), _labels[v]);
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

  for(auto face : pm->faces) {
    PolyMesh::Vertex *v0 = face->he->v;
    PolyMesh::Vertex *v1 = face->he->next->v;
    PolyMesh::Vertex *v2 = face->he->next->next->v;
    PolyMesh::Vertex *v3 = face->he->next->next->next->v;
    int l0 = _labels[v0];
    int l1 = _labels[v1];
    int l2 = _labels[v2];
    int color;
    if((l0 == 0 && l1 == 0 && l2 == 0) || (l0 == 1 && l1 == 1 && l2 == 1))
      color = 1;
    else
      color = 0;
    if(v0 == v3)
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
              v0->position.x(), v0->position.y(), v0->position.z(),
              v1->position.x(), v1->position.y(), v1->position.z(),
              v2->position.x(), v2->position.y(), v2->position.z(), color,
              color, color);
    else
      fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
              v0->position.x(), v0->position.y(), v0->position.z(),
              v1->position.x(), v1->position.y(), v1->position.z(),
              v2->position.x(), v2->position.y(), v2->position.z(),
              v3->position.x(), v3->position.y(), v3->position.z(), 0, 0, 0, 0);
  }
  fprintf(f, "};\n");
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

void meshGFaceQuadrangulateBipartiteLabelling(int faceTag)
{
  PolyMesh *pm = nullptr;
  Msg::Debug("Quadrangulation of face %d using Bipartite Labelling", faceTag);

  printf("%d  Quadrangulation of face\n", faceTag);
  int result = GFace2PolyMesh(faceTag, &pm);
  printf("%d  Transfer to Half Edge done\n", faceTag);
  if(result == -1) return;
  std::queue<PolyMesh::Vertex *> _queue;
  std::unordered_map<PolyMesh::Vertex *, int> _labels;
  std::unordered_map<PolyMesh::Vertex *, SVector3> _dirs;

  for(auto v : pm->vertices) _labels[v] = -1;

  for(auto v : pm->vertices) {
    // boundary vertex , degree returns 1 (one of the halfedges has no opposite)
    //    printf("vertex %d\n",v->data);
    //    printf("vertex %d has degree %d\n",v->data,pm->degree(v));
    if(_labels[v] == -1 && pm->degree(v) == -1) {
      //      printf("vertex %d is on the boundary\n",v->data);
      PolyMesh::HalfEdge *he = v->he;
      bool currentLabel = true;
      _labels[v] = currentLabel;
      _queue.push(v);
      size_t nodeCount = 0;
      while(1) {
        if(he->opposite == NULL) {
          he = he->next;
          //	  printf("--> vertex %d is on the boundary\n",he->v->data);
          nodeCount++;
          if(_labels[he->v] != -1) break;
          currentLabel = !currentLabel;
          _labels[he->v] = currentLabel;
          _queue.push(he->v);
        }
        else
          he = he->opposite->next;
      }
      if(nodeCount % 2 != 0) {
        Msg::Warning("Bipartite algorithm requires an even numer of boundary"
                     " vertices on every edge loop that bounds face %d. This "
                     "loop has %d nodes and some triangles will remain.",
                     faceTag, nodeCount);
      }
    }
  }

  printf("%d  Initial labelling done\n", faceTag);

  while(!_queue.empty()) {
    //    printf("SIZE %lu\n",_queue.size());
    auto v = _queue.front();
    _queue.pop();
    bool currentLabel = _labels[v];

    if(pm->degree(v) == -1) {
      SVector3 n, t1, t2;
      computeNaturalCross(v, n, t1, t2);
      PolyMesh::HalfEdge *he = v->he;
      while(he->opposite) he = he->opposite->next;
      double dot_max = 0.0;
      PolyMesh::HalfEdge *best = nullptr;
      //      printf("treating %lu\n",v->data);
      while(he) {
        //	printf("  %lu\n",he->prev->v->data);
        SVector3 t = he->d();
        if(_labels[he->next->v] == -1) {
          double dd = std::max(fabs(dot(t1, t)), fabs(dot(t2, t)));
          if(dd > dot_max) {
            dot_max = dd;
            best = he;
          }
        }
        he = he->prev->opposite;
      }
      if(best && dot_max > 0.9) {
        //	printf("connecting %lu to (%lu %lu) (%g
        //%g)\n",v->data,best->v->data,best->next->v->data,
        //	       best->d().x(),best->d().y());
        _dirs[best->next->v] = best->d();
        _labels[best->next->v] = !currentLabel;
        _queue.push(best->next->v);
      }
    }
    else {
      SVector3 n = pm->normal(v);
      SVector3 t1 = _dirs[v];
      SVector3 t2 = crossprod(n, t1);
      PolyMesh::HalfEdge *he = v->he;
      std::vector<std::pair<double, PolyMesh::HalfEdge *> > bests;
      //      printf ("Vertex %d (%g %g): ",v->data,t1.x(),t1.y());
      do {
        SVector3 t = he->d();
        double dd = -std::max(fabs(dot(t1, t)), fabs(dot(t2, t)));
        bests.push_back(std::make_pair(dd, he));
        //	printf ("(%d,%g,%g,%g) ",he->next->v->data,dd,t.x(),t.y());
        he = he->opposite->next;
      } while(he != v->he);

      std::sort(bests.begin(), bests.end());

      int count = 0;
      for(auto it : bests) {
        if(count++ > 3) break;
        PolyMesh::HalfEdge *best = it.second;
        if(_labels[best->next->v] == -1) {
          //	  printf("(%lu %g)", best->next->v->data, it.first);
          _dirs[best->next->v] = best->d();
          _labels[best->next->v] = /*rand()%2; // TEST*/ !currentLabel;
          _queue.push(best->next->v);
        }
      }
      //      printf("\n");
    }
  }

  printf("%d  internal labelling done\n", faceTag);

  // enhancement.
  bool changed = false;
  printLabelling("labelling_initial.pos", pm, _labels);
  do {
    changed = false;
    for(auto v : pm->vertices) {
      if(pm->degree(v) != -1) {
        PolyMesh::HalfEdge *he = v->he;
        int myIndex = _labels[v];
        if(myIndex == -1) { _labels[v] = myIndex = 1; }
        int oppositeIndex = (myIndex == 1) ? 0 : 1;
        std::vector<int> l;
        do {
          l.push_back(_labels[he->next->v]);
          he = he->opposite->next;
        } while(he != v->he);
        int nbInvalidBefore = 0;
        int nbInvalidAfter = 0;
        for(size_t i = 0; i < l.size(); i++) {
          int i0 = l[i];
          int i1 = l[(i + 1) % l.size()];
          if(i0 == i1 && i0 == myIndex) nbInvalidBefore++;
          if(i0 == i1 && i0 == oppositeIndex) nbInvalidAfter++;
        }
        if(nbInvalidBefore > nbInvalidAfter) {
          //	  printf("%d %d\n",nbInvalidBefore,nbInvalidAfter);
          _labels[v] = oppositeIndex;
          changed = true;
        }
      }
    }
  } while(changed);
  printLabelling("labelling_final.pos", pm, _labels);

  printf("%d  optimum labelling done\n", faceTag);

  // split invalid edges

  for(auto he : pm->hedges) {
    if(he->opposite != nullptr) {
      PolyMesh::Vertex *v0 = he->v;
      PolyMesh::Vertex *v1 = he->next->v;
      PolyMesh::Vertex *v2 = he->next->next->v;
      PolyMesh::Vertex *v3 = he->opposite->next->next->v;
      int l0 = _labels[v0];
      int l1 = _labels[v1];
      int l2 = _labels[v2];
      int l3 = _labels[v3];
      if(l0 == l1 && l0 == l2 && l0 == l3) {
        SVector3 pos = (v0->position + v1->position) * .5;
        if(pm->split_edge(he, pos, -1) == 0) {
          _labels[pm->vertices[pm->vertices.size() - 1]] = l0 == 1 ? 0 : 1;
        }
      }
      else if(l0 == l1 && l0 == l2) {
        SVector3 pos = (v0->position + v1->position) * .5;
        if(pm->split_edge(he, pos, -1) == 0) {
          _labels[pm->vertices[pm->vertices.size() - 1]] = l0 == 1 ? 0 : 1;
        }
      }
    }
  }

  printf("%d  steiner points added\n", faceTag);

  printLabelling("labelling_final_split.pos", pm, _labels);

  for(auto he : pm->hedges) {
    if(he->v != nullptr && he->opposite != nullptr) {
      PolyMesh::Vertex *v0 = he->v;
      PolyMesh::Vertex *v1 = he->next->v;
      int l0 = _labels[v0];
      int l1 = _labels[v1];
      if(l0 == l1 && pm->num_sides(he) == 3 && pm->num_sides(he->opposite) == 3)
        pm->merge_faces(he);
    }
  }
  pm->clean();
  printLabelling("labelling_final_split_quad.pos", pm, _labels);

  printf("%d  quads created\n", faceTag);

  PolyMesh2GFace(pm, faceTag);

  printf("%d  2 gmsh done\n", faceTag);

  delete pm;

  /*  GFace *gf = GModel::current()->getFaceByTag(faceTag);
  SurfaceProjector sp;
  fillSurfaceProjector(gf, &sp);
  optimizeGeometryQuadMesh(gf, &sp);
  */
}

#else

void meshGFaceQuadrangulateBipartiteLabelling(int faceTag)
{
  Msg::Error("This requires quad meshing tools");
}

#endif

#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "SPoint2.h"
#include "meshPolyMesh.h"
#include "Numeric.h"
#include "OS.h"

// #include "geodesic_mesh.h"
// #include "geodesic_algorithm_exact.h"

PolyMesh::PolyMesh(const PolyMesh &p)
{
  std::map<Vertex *, Vertex *> vs;
  for(auto v : p.vertices) {
    Vertex *newv =
      new Vertex(v->position.x(), v->position.y(), v->position.z());
    newv->data = v->data;
    vs[v] = newv;
    vertices.push_back(newv);
  }

  std::map<HalfEdge *, HalfEdge *> hs;
  for(auto h : p.hedges) {
    HalfEdge *newh = new HalfEdge(vs[h->v]);
    newh->v->he = newh;
    newh->data = h->data;
    hs[h] = newh;
    hedges.push_back(newh);
  }

  std::map<Face *, Face *> fs;
  for(auto f : p.faces) {
    Face *newf = new Face(hs[f->he]);
    newf->data = f->data;
    fs[f] = newf;
    faces.push_back(newf);
  }

  for(auto h : p.hedges) {
    HalfEdge *he = hs[h];
    he->next = h->next == nullptr ? nullptr : hs[h->next];
    he->prev = h->prev == nullptr ? nullptr : hs[h->prev];
    he->opposite = h->opposite == nullptr ? nullptr : hs[h->opposite];
    he->f = h->f == nullptr ? nullptr : fs[h->f];
  }
}

static void update(double lsit, PolyMesh::Vertex *vi,
                   std::map<PolyMesh::Vertex *, double> &ls,
                   std::set<std::pair<double, PolyMesh::Vertex *>> &front)
{
  std::pair<double, PolyMesh::Vertex *> pp = std::make_pair(ls[vi], vi);
  front.erase(pp);
  std::pair<double, PolyMesh::Vertex *> pp_new = std::make_pair(lsit, vi);
  front.insert(pp_new);
  ls[vi] = lsit;
}

static double trialedge(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj, double lsi)
{
  SVector3 base = vj->position - vi->position;
  double l = base.norm();
  return lsi + l;
}

double trialtriangle(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj,
                     PolyMesh::Vertex *vk, double lsi, double lsj)
{
  SVector3 ki = vk->position - vi->position;
  SVector3 kj = vk->position - vj->position;
  SVector3 pv = crossprod(ki, kj);

  SPoint2 pk(0.0, 0.0);
  SPoint2 pi(ki.norm(), 0.0);
  double xj = dot(ki, kj) / ki.norm();
  double yj = pv.norm() / ki.norm();
  SPoint2 pj(xj, yj);

  double base[2][2] = {{pk.x() - pi.x(), pk.x() - pj.x()},
                       {pk.y() - pi.y(), pk.y() - pj.y()}};
  double m00 = base[0][0] * base[0][0] + base[1][0] * base[1][0];
  double m11 = base[0][1] * base[0][1] + base[1][1] * base[1][1];
  double m01 = base[0][0] * base[0][1] + base[1][0] * base[1][1];
  double detm = m00 * m11 - m01 * m01;
  double dm00 = m11 / detm;
  double dm11 = m00 / detm;
  double dm01 = -m01 / detm;
  double a = dm00 + dm11 + 2 * dm01;
  double dmd0 = dm00 * lsi + dm01 * lsj;
  double dmd1 = dm01 * lsi + dm11 * lsj;
  double b = -2. * (dmd0 + dmd1);
  double c = lsi * dmd0 + lsj * dmd1 - 1.;
  double delta = b * b - 4. * a * c;
  if(delta < 0) return -1.0;
  double sdelta = sqrt(delta);
  double lskt = (-b - sdelta) / 2. / a;
  if(lskt <= lsi) lskt = (-b + sdelta) / 2. / a;
  if(lskt < lsi) return -1.0;
  double gduali = lskt - lsi;
  double gdualj = lskt - lsj;
  double g1 = dm00 * gduali + dm01 * gdualj;
  double g2 = dm01 * gduali + dm11 * gdualj;
  if(g1 >= 0 && g2 >= 0) return lskt;
  return -1.0;
}

static void treatedge(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj,
                      std::map<PolyMesh::Vertex *, double> &ls,
                      std::set<std::pair<double, PolyMesh::Vertex *>> &front)
{
  double lsjt = trialedge(vi, vj, ls[vi]);
  if(lsjt < ls[vj]) update(lsjt, vj, ls, front);
}

static void
treattriangle(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj, PolyMesh::Vertex *vk,
              std::map<PolyMesh::Vertex *, double> &ls,
              std::set<std::pair<double, PolyMesh::Vertex *>> &front)
{
  double lskt = trialtriangle(vi, vj, vk, ls[vi], ls[vj]);
  if(lskt < 0) return;
  if(lskt < ls[vk]) update(lskt, vk, ls, front);
}

void print__(const char *fn, PolyMesh *pm,
             std::map<PolyMesh::Vertex *, double> &ls)
{
  FILE *f = fopen(fn, "w");
  fprintf(f, "View\"\"{\n");
  for(auto he : pm->hedges) {
    if(he->v) {
      PolyMesh::Vertex *v1 = he->v;
      PolyMesh::Vertex *v2 = he->next->v;
      if(he->data != -1) {
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", v1->position.x(),
                v1->position.y(), v1->position.z(), v2->position.x(),
                v2->position.y(), v2->position.z(), he->data, he->data);
      }
    }
  }
  for(auto t : pm->faces) {
    if(t->he) {
      PolyMesh::Vertex *v1 = t->he->v;
      PolyMesh::Vertex *v2 = t->he->next->v;
      PolyMesh::Vertex *v3 = t->he->next->next->v;
      PolyMesh::Vertex *v4 = t->he->next->next->next->v;

      if (ls.empty()){
	fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
		v1->position.x(),v1->position.y(),v1->position.z(),
		v2->position.x(),v2->position.y(),v2->position.z(),
		v3->position.x(),v3->position.y(),v3->position.z(),
		//		v1->data,v2->data,v3->data,
		t->data,t->data,t->data);
      }    
      else{
	std::map<PolyMesh::Vertex*,double>::iterator it1 = ls.find(v1);
	std::map<PolyMesh::Vertex*,double>::iterator it2 = ls.find(v2);
	std::map<PolyMesh::Vertex*,double>::iterator it3 = ls.find(v3);
	std::map<PolyMesh::Vertex*,double>::iterator it4 = ls.find(v4);
	
	if (v4 == v1 && it1 != ls.end() && it2 != ls.end() && it3 != ls.end()){
	  double l1 = it1->second;
	  double l2 = it2->second;
	  double l3 = it3->second;
	  fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
		  v1->position.x(),v1->position.y(),v1->position.z(),
		  v2->position.x(),v2->position.y(),v2->position.z(),
		  v3->position.x(),v3->position.y(),v3->position.z(),l1,l2,l3);
	}
	else if (it1 != ls.end() && it2 != ls.end() && it3 != ls.end() && it4 != ls.end()){
	  double l1 = it1->second;
	  double l2 = it2->second;
	  double l3 = it3->second;
	  double l4 = it4->second;
	  fprintf(f,"SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
		  v1->position.x(),v1->position.y(),v1->position.z(),
		  v2->position.x(),v2->position.y(),v2->position.z(),
		  v3->position.x(),v3->position.y(),v3->position.z(),
		  v4->position.x(),v4->position.y(),v4->position.z(),
		  l1,l2,l3,l4);
	}
      }    
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

// static void distanceProxy (PolyMesh *pm,
// 			   const PolyMesh::VertexOnFace &_start,
// 			   double distance,
// 			   std::vector<PolyMesh::Vertex *> &proxyVertices,
// 			   //			   std::vector<PolyMesh::HalfEdge *> &proxyEdges,
// 			   std::vector<PolyMesh::Face *> &proxyFaces){

//   std::queue<PolyMesh::Face*> _s;

//   std::unordered_map<PolyMesh::Face*, double> _d;

//   PolyMesh::HalfEdge *he = _start.he;
//   do {
//     if(he->prev->opposite == NULL) break;
//     he = he->prev->opposite;
//   } while(he != _start.he);
//   do {
//     _s.push(he->f);
//     SVector3 dst = _start.he->v->position - he->f->cog();
//     _d[he->f] = dst.norm();
//     he = he->opposite;
//     if(he == NULL) break;
//     he = he->next;
//   } while(he != _start.he);

//   while (!_s.empty()){
//     auto _f = _s.front();
//     _s.pop();
//     double D = _d [_f];
//     PolyMesh::HalfEdge *ns[3] = {_f->he,_f->he->next,_f->he->next->next};
//     for (int k=0;k<3;k++){
//       if (ns[k]->opposite){
// 	PolyMesh::Face *neigh = ns[k]->opposite->f;
// 	std::unordered_map<PolyMesh::Face*, double>::iterator it = _d.find(neigh);
// 	if (it == _d.end()){
// 	  SVector3 dx = _f->cog() - neigh->cog();
// 	  double DD = D + dx.norm();
// 	  if (DD < distance){
// 	    _d[neigh] = DD;
// 	    _s.push(neigh);
// 	  }
// 	}
//       }
//     }
//   }

//   proxyVertices.clear();

//   for (auto fac : _d) {
//     proxyFaces.push_back(fac.first);
//     fac.first->he->v->data = -1;
//     fac.first->he->next->v->data = -1;
//     fac.first->he->next->next->v->data = -1;
//   }

//   for (auto fac : _d) {
//     if (fac.first->he->v->data == -1){
//       fac.first->he->v->data = proxyVertices.size();
//       proxyVertices.push_back(fac.first->he->v);
//     }
//     if (fac.first->he->next->v->data == -1){
//       fac.first->he->next->v->data = proxyVertices.size();
//       proxyVertices.push_back(fac.first->he->next->v);
//     }
//     if (fac.first->he->next->next->v->data == -1){
//       fac.first->he->next->next->v->data = proxyVertices.size();
//       proxyVertices.push_back(fac.first->he->next->next->v);
//     }
//   }
// }

// void PolyMesh::exactGeodesics (const PolyMesh::VertexOnFace &_start,
// 			       std::vector<PolyMesh::VertexOnFace> &incident_edges,
// 			       double proxyDistance, int save_, FILE *f){

//   std::vector<PolyMesh::Vertex *>_vvv;
//   std::vector<PolyMesh::Face *>_fff;

//   distanceProxy (this,_start,proxyDistance,_vvv,_fff);

//   std::vector<double> _points;
//   std::vector<unsigned> _faces;
//   int num = 0;
//   for (auto v : _vvv){
//     _points.push_back(v->position.x());
//     _points.push_back(v->position.y());
//     _points.push_back(v->position.z());
//     v->data = num++;
//   }

//   std::map<PolyMesh::Face*,int> f2n;

//   int nnn = 0;
//   for (auto f : _fff){
//     _faces.push_back(f->he->v->data);
//     _faces.push_back(f->he->next->v->data);
//     _faces.push_back(f->he->next->next->v->data);
//     f2n[f] = nnn++;
//   }

//   geodesic::Mesh mesh;
//   mesh.initialize_mesh_data(_points, _faces);

//   SVector3 p_start = _start.point();

//   geodesic::SurfacePoint sp (&mesh.faces()[f2n[_start.he->f]],p_start.x(),
//   p_start.y(), p_start.z(),geodesic::FACE);
//   std::vector<geodesic::SurfacePoint> pts = {sp};

//   std::vector<geodesic::SurfacePoint> _stop ;
//   for (auto v : incident_edges){
//     SVector3 p_end = v.point();
//     geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(),
//     p_end.y(), p_end.z(),geodesic::FACE); _stop.push_back(spe);
//   }

//   geodesic::GeodesicAlgorithmExact algorithm(&mesh);
//   algorithm.propagate(pts,0,&_stop);
//   //  algorithm.propagate(pts,proxyDistance);

//   printf("Vertex with %lu incident edges proxy %12.5E n
//   %lu\n",incident_edges.size(),proxyDistance,nnn);

//   for (auto v : incident_edges){
//     SVector3 p_end = v.point();
//     // fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
//     //	    p_start.x(),p_start.y(),p_start.z(),
//     //	    p_end.x(),p_end.y(),p_end.z(),
//     //	    save_,save_);
//     geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(),
//     p_end.y(), p_end.z(),geodesic::FACE); std::vector<geodesic::SurfacePoint>
//     path; algorithm.trace_back(spe, path);
//     //    printf("path with %lu nodes\n",path.size());

//     for (size_t i = 0; i< path.size()-1;i++){
//       fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
//       	      path[i].x(),path[i].y(),path[i].z(),
//       	      path[i+1].x(),path[i+1].y(),path[i+1].z(),_start.he->v->data,_start.he->v->data);
//     }
//   }
// }

void PolyMesh::fastMarching(std::vector<Vertex *> &seeds,
                            std::map<Vertex *, double> &ls)
{
  double t1 = Cpu();
  std::set<std::pair<double, PolyMesh::Vertex *>> front;
  std::set<PolyMesh::Vertex *> visited;
  for(auto v : vertices)
    if(ls.find(v) == ls.end()) ls[v] = 1.e22;
  for(auto v : seeds) {
    if(ls.find(v) == ls.end()) ls[v] = 0.0;
    front.insert(std::make_pair(0.0, v));
  }

  while(!front.empty()) {
    auto it = front.begin();
    front.erase(it);
    Vertex *vi = it->second;
    visited.insert(vi);
    HalfEdge *he = vi->he;
    // take into account boundary vertices
    do {
      if(he->prev->opposite == nullptr) break;
      he = he->prev->opposite;
    } while(he != vi->he);
    // loop around vert
    do {
      Vertex *vj = he->next->v;
      if(visited.find(vj) == visited.end()) { treatedge(vi, vj, ls, front); }
      else {
        HalfEdge *ij = getEdge(vi, vj);
        HalfEdge *ji = getEdge(vj, vi);
        if(ij) {
          Vertex *vk = ij->prev->v;
          treattriangle(vi, vj, vk, ls, front);
        }
        if(ji) {
          Vertex *vk = ji->prev->v;
          treattriangle(vi, vj, vk, ls, front);
        }
      }
      if(he->opposite == nullptr) break;
      he = he->opposite->next;
    } while(he != vi->he);
  }
  double t2 = Cpu();
  Msg::Info("fast marching time : %g", t2 - t1);
  print__("fm.pos", this, ls);
}

/// DECIMATION OF TRIANGLE MESHES
// Will Schroeder et al. -- 1992 -- Computer Graphics

void PolyMesh::computeNormalsAndCentersOfGravity(
  std::map<PolyMesh::Vertex *, SVector3> &cogs,
  std::map<PolyMesh::Vertex *, SVector3> &nrms)
{
  for(auto v : vertices) {
    std::vector<Vertex *> neigh;
    bool onBoundary = false;
    vertexNeighbors(v, &neigh, &onBoundary);
    if(onBoundary) continue;
    SVector3 nrm(0, 0, 0);
    SVector3 cog(0, 0, 0);
    double sumai = 0;
    for(size_t i = 0; i < neigh.size(); i++) {
      Vertex *v0 = neigh[i];
      Vertex *v1 = neigh[(i + 1) % 3];
      SVector3 t1 = v1->position - v->position;
      SVector3 t0 = v0->position - v->position;
      SVector3 ni = crossprod(t1, t0);
      double ai = ni.norm();
      sumai += ai;
      cog += (v0->position * ai);
      nrm += ni;
    }
    cog *= (1. / sumai);
    nrm.normalize();
    cogs[v] = cog;
    nrms[v] = nrm;
  }
}

int PolyMesh::decimate(double thresholdDistance,
                       std::map<Vertex *, SVector3> *cogs,
                       std::map<Vertex *, SVector3> *nrms)
{
  Msg::Info(
    "Decimating a surface with %8lu vertices (threshold distance %12.5E)",
    vertices.size(), thresholdDistance);

  size_t nbRemove = 0;
  size_t nbProcessed = 0;

  for(auto v : vertices) {
    nbProcessed++;

    std::vector<Vertex *> neigh;
    bool onBoundary = false;
    vertexNeighbors(v, &neigh, &onBoundary);

    if (onBoundary)continue;
    if (neigh.empty())continue;

    //        printf("%d (%d) ",v->data,onBoundary);
    //            for (auto nsa : neigh) printf("%p ",nsa);
    //            printf("\n");

    SVector3 nrm(0, 0, 0);
    SVector3 cog(0, 0, 0);
    if(nrms && cogs) {
      cog = (*cogs)[v];
      nrm = (*nrms)[v];
    }
    else {
      double sumai = 0;
      for(size_t i = 0; i < neigh.size(); i++) {
        Vertex *v0 = neigh[i];
        Vertex *v1 = neigh[(i + 1) % neigh.size()];
        SVector3 t1 = v1->position - v->position;
        SVector3 t0 = v0->position - v->position;
        SVector3 ni = crossprod(t1, t0);
        double ai = ni.norm();
        sumai += ai;
        cog += (v0->position * ai);
        nrm += ni;
      }
      cog *= (1. / sumai);
      nrm.normalize();
    }
    double d = fabs(dot(nrm, v->position - cog));

    if(d > thresholdDistance) continue;
    std::stack<std::vector<Vertex *>> loops;
    std::vector<std::vector<Vertex *>> triangles;
    loops.push(neigh);

    bool remove_vertex = true;

    while(!loops.empty()) {
      std::vector<Vertex *> loop = loops.top();
      //      //            printf("total size %lu loop size %lu loop
      //      :",loops.size(),loop.size());
      //            for (auto aaa : loop)printf("%d ",aaa->data);
      //            printf("\n");
      loops.pop();
      if(loop.size() == 3) {
        std::reverse(loop.begin(), loop.end());
        triangles.push_back(loop);
      }
      else { // split the loop
        int best_start = -1;
        int best_end = -1;
        double best_aspect_ratio = -1.0;
        for(size_t _start = 0; _start < loop.size(); _start++) {
          for(size_t end = _start + 2; end < _start + loop.size() - 1; end++) {
            size_t _end = end % loop.size();

            // only consider split edge once
            if(_start < _end) {
              Vertex *vi = loop[_start];
              Vertex *vj = loop[_end];

              //	      printf("CUTTING WITH %d %d\n",vi->data,vj->data);

              SVector3 t = vj->position - vi->position;
              double L = t.norm();
              t.normalize();
              SVector3 b = crossprod(t, nrm);
              double aspect_ratio = 1.e22;
              bool sign_consistency = true;
              double firstDist;
              for(size_t j = _start + 1; j < _end; j++) {
                Vertex *vk = loop[j % loop.size()];
                SVector3 tik = vk->position - vi->position;
                double dist = dot(b, tik);
                //	printf("side 1 vertex %d dist %g\n",vk->data,dist);
                if(j == _start + 1)
                  firstDist = dist;
                else if(dist * firstDist < 0)
                  sign_consistency = false;
                aspect_ratio = std::min(aspect_ratio, fabs(dist) / L);
              }
              firstDist = -firstDist;
              for(size_t j = _end + 1; j < _start + loop.size(); j++) {
                Vertex *vk = loop[j % loop.size()];
                SVector3 tik = vk->position - vi->position;
                double dist = dot(b, tik);
                //		printf("side 2 vertex %d dist %g\n",vk->data,dist);
                //		if (j == _end+1)firstDist = dist;
                if(dist * firstDist < 0) sign_consistency = false;
                aspect_ratio = std::min(aspect_ratio, fabs(dist) / L);
              }
              //	      printf("considering %d %d -- %g %g %g AR
              //%12.5E\n",vi->data,vj->data,_end,b.x(),b.y(),b.z(),aspect_ratio);
              if(!sign_consistency) continue;
              if(aspect_ratio < 0.1) continue;
              if(aspect_ratio > best_aspect_ratio) {
                best_aspect_ratio = aspect_ratio;
                best_start = _start;
                best_end = _end;
              }
            }
          }
        }
        if(best_start >= 0) {
          std::vector<Vertex *> newLoop;
          for(size_t i = best_start; i < best_end + 1; i++)
            newLoop.push_back(loop[i % loop.size()]);
          loops.push(newLoop);
          newLoop.clear();
          for(size_t i = best_end; i < best_start + loop.size() + 1; i++)
            newLoop.push_back(loop[i % loop.size()]);
          loops.push(newLoop);
        }
        else {
          remove_vertex = false;
          break;
        }
      }
    }

    // impossible to unrefine that pattern so continue

    if (!remove_vertex)continue;

    //    if (triangles.size() == 2)
    //    if (v->data > 42800){	
    //      std::map<PolyMesh::Vertex*,double> nothing;
    //      char name[123];
    //      sprintf(name,"x%d.pos",v->data);
    //      print__ (name, this, nothing);
    //    }
    

    
    if (deleteVertexAndRemeshCavity2 (v,triangles)){
      //      printf("%d remeshed with %lu triangles\n",v->data,triangles.size());
      v->he = nullptr;
      nbRemove++;
      if(nbProcessed % 100000 == 0) {
        Msg::Info("vertex %ld / %lu -- %lu processed -- %lu removed\n", v->data,
                  vertices.size(), nbProcessed, nbRemove);
      }
    }
    //    if (triangles.size() == 2)printf("%d remeshing with %lu triangles
    //    done\n",v->data,triangles.size());
  }

  if(nbRemove == 0) return 0;

  {
    std::vector<Vertex *> new_v;
    for(auto v : vertices) {
      if(v->he == nullptr) { delete v; }
      else
        new_v.push_back(v);
    }
    vertices = new_v;
    std::vector<HalfEdge *> new_edges;
    for(auto e : hedges) {
      if(e->v == nullptr) { delete e; }
      else
        new_edges.push_back(e);
    }
    hedges = new_edges;
    std::vector<Face *> new_faces;
    for(auto f : faces) {
      if(f->he == nullptr) { delete f; } // delete f;
      else
        new_faces.push_back(f);
    }
    faces = new_faces;
  }

  Msg::Debug("Pass done -- %8lu vertices removed \n", nbRemove);

  return nbRemove;
}

/*void PolyMesh::deleteIsolatedVertex (PolyMesh::Vertex* he){
  auto it = std::find(vertices.begin(), vertices.end(), he);
  if (it != vertices.end()) vertices.erase(it);
  delete he;
}
*/

/*
void PolyMesh::deleteHalfEdge (PolyMesh::HalfEdge* he){
  //  printf("%p %p\n",he,he->v);
  //  printf("deleting half edge %d %d\n",he->v->data,he->next->v->data);
  auto it = std::find(hedges.begin(), hedges.end(), he);
  if (it != hedges.end()) hedges.erase(it);
  if (he->opposite) {
    //    printf("vertex %d  has currently edge %d %d --> %d %d\n",he->v->data,
    //	   he->v->he->v->data,he->v->he->next->v->data,
    //	   he->opposite->next->v->data,
    //	   he->opposite->next->next->v->data);
    he->v->he = he->opposite->next;
    he->opposite->opposite = nullptr;
  }
  delete he;
}


void PolyMesh::deleteFace (PolyMesh::Face* f){
  HalfEdge* he0 = f->he;
  HalfEdge* he1 = he0->next;
  HalfEdge* he2 = he1->next;
  //  printf("deleting triangle %d %d
%d\n",he0->v->data,he1->v->data,he2->v->data); deleteHalfEdge (he0);
  deleteHalfEdge (he1);
  deleteHalfEdge (he2);
  auto it = std::find(faces.begin(), faces.end(), f);
  if (it != faces.end()) faces.erase(it);
  delete f;
  return;
}


// A bousiller
PolyMesh::HalfEdge * getEdgeBad (PolyMesh *pm, PolyMesh::Vertex *v0,
PolyMesh::Vertex *v1){
  //  PolyMesh::HalfEdge *he = pm->getEdge(v0,v1);
  //  if (he)return he;
  for (auto h : pm->hedges){
    if (h->v == v0 && h->next->v == v1)return h;
  }
  return nullptr;
}
*/
// A refaire

bool PolyMesh::deleteVertexAndRemeshCavity2(
  Vertex *toDelete, std::vector<std::vector<Vertex *>> &triangles)
{
  HalfEdge *he = toDelete->he;
  std::vector<Face *> old_faces;
  std::vector<HalfEdge *> bnd;
  std::vector<HalfEdge *> old_inner;
  //  printf("starting with edge %d %d\n",he->v->data,he->next->v->data);
  do {
    old_faces.push_back(he->f);
    bnd.push_back(he->next);
    //    printf("boundary added %d
    //    %d\n",he->next->v->data,he->next->next->v->data);
    old_inner.push_back(he);
    if(he->opposite) old_inner.push_back(he->opposite);
    //        printf("inner added %d %d\n",he->v->data,he->next->v->data);
    if(he->opposite == NULL)
      return false; // for now no boundary considered
    else {
      he = he->opposite->next;
    }
  } while(he != toDelete->he);

  // If one of the new inner edges exist outside the cavity --> topological
  // change --> exit If one of the new triangles exist outside the cavity -->
  // topological change --> exit

  //  for (auto t : triangles){
  //    auto temp = t[0];
  //    t[0] = t[2];
  //    t[2] = temp;
  //  }

  //      for (auto e : bnd)printf("(%d,%d)",e->v->data,e->next->v->data);
  //      printf("\n");

  for(auto t : triangles) {
    Vertex *v0 = t[0];
    Vertex *v1 = t[1];
    Vertex *v2 = t[2];

    if(!v0->he || !v1->he || !v2->he) return false;

    HalfEdge *h10 = getEdge(v1, v0);
    HalfEdge *h21 = getEdge(v2, v1);
    HalfEdge *h02 = getEdge(v0, v2);

    if(h10 && h21 && h02 && h10->f == h21->f && h10->f == h02->f) {
      Msg::Debug("Vertex %d Cannot Be Removed -- Topological Obstruction "
                 "(creation of a non manifold face %d %d %d)",
                 toDelete->data, v0->data, v1->data, v2->data);
      return false;
    }
  }

  for(auto t : triangles) {
    Vertex *v0 = t[0];
    Vertex *v1 = t[1];
    Vertex *v2 = t[2];

    HalfEdge *h01 = getEdge(v0, v1);
    HalfEdge *h12 = getEdge(v1, v2);
    HalfEdge *h20 = getEdge(v2, v0);
    /*
    printf("%d %d %d %p %p %p %d %d %d %d %d %d\n",
       v0->data,v1->data,v2->data,
       h01,h12,h20,
       std::find(old_inner.begin(), old_inner.end(), h01) == old_inner.end(),
       std::find(old_inner.begin(), old_inner.end(), h12) == old_inner.end(),
       std::find(old_inner.begin(), old_inner.end(), h20) == old_inner.end(),
       std::find(bnd.begin(), bnd.end(), h01) == bnd.end(),
       std::find(bnd.begin(), bnd.end(), h12) == bnd.end(),
       std::find(bnd.begin(), bnd.end(), h20) == bnd.end());
    */

    if(h01 &&
       std::find(old_inner.begin(), old_inner.end(), h01) == old_inner.end() &&
       std::find(bnd.begin(), bnd.end(), h01) == bnd.end()) {
      Msg::Debug("Vertex %d Cannot Be Removed -- Topological Obstruction "
                 "(creation of a non manifold edge %d %d)",
                 toDelete->data, v0->data, v1->data);
      return false;
    }
    if(h12 &&
       std::find(old_inner.begin(), old_inner.end(), h12) == old_inner.end() &&
       std::find(bnd.begin(), bnd.end(), h12) == bnd.end()) {
      Msg::Debug("Vertex Cannot Be Removed -- Topological Obstruction "
                 "(creation of a non manifold edge %d %d)",
                 toDelete->data, v1->data, v2->data);
      return false;
    }
    if(h20 &&
       std::find(old_inner.begin(), old_inner.end(), h20) == old_inner.end() &&
       std::find(bnd.begin(), bnd.end(), h20) == bnd.end()) {
      Msg::Debug("Vertex Cannot Be Removed -- Topological Obstruction "
                 "(creation of a non manifold edge %d %d)",
                 toDelete->data, v2->data, v0->data);
      return false;
    }
  }

  //  printf("replacing a cavity %lu by %lu (%lu
  //  %lu)\n",old_faces.size(),triangles.size(), old_inner.size(), bnd.size());

  // now it works

  std::vector<HalfEdge *> new_edges;
  std::vector<HalfEdge *> new_inner;

  for(auto t : triangles) {
    for(size_t i = 0; i < 3; i++) {
      HalfEdge *he = getEdge(t[i], t[(i + 1) % 3]);
      if(std::find(bnd.begin(), bnd.end(), he) == bnd.end()) {
        he = new PolyMesh::HalfEdge(t[i]);
        //	printf("creating new edge %d %d\n",t[i]->data,t[(i+1)%3]->data);
        new_inner.push_back(he);
      }
      new_edges.push_back(he);
    }
  }

  //  printf("creating %lu new edges\n",new_edges.size());

  // if (new_inner.size()/2 != bnd.size() - 3)printf("aaaaaaargh %lu
  // %lu\n",new_inner.size(),bnd.size());

  std::vector<Face *> new_faces;
  for(size_t i = 0; i < new_edges.size(); i += 3) {
    auto hev0 = new_edges[i];
    auto hev1 = new_edges[i + 1];
    auto hev2 = new_edges[i + 2];
    hev0->next = hev1;
    hev1->next = hev2;
    hev2->next = hev0;
    hev0->prev = hev2;
    hev1->prev = hev0;
    hev2->prev = hev1;
    PolyMesh::Face *f = new PolyMesh::Face(hev0);
    hev0->f = f;
    hev1->f = f;
    hev2->f = f;
    hev0->v->he = hev0;
    hev1->v->he = hev1;
    hev2->v->he = hev2;
    new_faces.push_back(f);
  }

  for(size_t i = 0; i < new_inner.size(); i++) {
    for(size_t j = i + 1; j < new_inner.size(); j++) {
      HalfEdge *h0 = new_inner[i];
      HalfEdge *h1 = new_inner[j];
      if(h0->v == h1->next->v && h1->v == h0->next->v) {
        h1->opposite = h0;
        h0->opposite = h1;
      }
    }
  }

  for(auto f : old_faces) { f->he = nullptr; }
  for(auto e : old_inner) { e->v = nullptr; }
  for(auto f : new_faces) {
    //    printf("%d %d %d -- %p %p %p
    //    \n",f->he->v->data,f->he->next->v->data,f->he->next->next->v->data,
    //	   f->he->opposite,f->he->next->opposite,f->he->next->next->opposite);
    faces.push_back(f);
  }
  for(auto e : new_inner) hedges.push_back(e);
  //  printf("%d done\n",toDelete->data);
  return true;
}

/*
void PolyMesh::createTriangle (PolyMesh::Vertex *v0, PolyMesh::Vertex *v1 ,
PolyMesh::Vertex *v2 ){
  //  printf("creating triangle %d %d %d\n",v0->data,v1->data,v2->data);
  HalfEdge *hev0 = new PolyMesh::HalfEdge(v0);
  HalfEdge *hev1 = new PolyMesh::HalfEdge(v1);
  HalfEdge *hev2 = new PolyMesh::HalfEdge(v2);
  hedges.push_back(hev0);
  hedges.push_back(hev1);
  hedges.push_back(hev2);
  hev0->next = hev1;
  hev1->next = hev2;
  hev2->next = hev0;
  hev0->prev = hev2;
  hev1->prev = hev0;
  hev2->prev = hev1;
  HalfEdge *op0 = getEdgeBad(this,v1,v0);
  if (op0){op0->opposite = hev0;hev0->opposite = op0; }
//  else printf ("1 %d %d NOT connevcted\n",v1->data,v0->data);
  HalfEdge *op1 = getEdgeBad(this,v2,v1);
  if (op1){op1->opposite = hev1;hev1->opposite = op1; }
  //  else printf ("2 %d %d NOT connevcted\n",v2->data,v1->data);
  HalfEdge *op2 = getEdgeBad(this,v0,v2);
  if (op2){op2->opposite = hev2;hev2->opposite = op2; }
  //  else printf ("3 %d %d NOT connevcted\n",v0->data,v2->data);
  PolyMesh::Face *f = new PolyMesh::Face (hev0);
  v0->he = hev0;
  v1->he = hev1;
  v2->he = hev2;
  hev0->f = f;
  hev1->f = f;
  hev2->f = f;
  faces.push_back(f);
  }


static int poincare (const std::vector<std::vector<PolyMesh::Vertex*> >
&triangles){ std::set<std::pair<int,int> > edges; std::set<int> vertices; for
(size_t i=0 ;i < triangles.size() ; i++){ int v0 = triangles[i][0]->data; int v1
= triangles[i][1]->data; int v2 = triangles[i][2]->data;

    for (size_t j=i+1 ;j < triangles.size() ; j++){
      int w0 = triangles[j][0]->data;
      int w1 = triangles[j][1]->data;
      int w2 = triangles[j][2]->data;
      if ((v0 == w0 || v0 == w1 || v0 == w2) &&
      (v1 == w0 || v1 == w1 || v1 == w2) &&
      (v2 == w0 || v2 == w1 || v2 == w2))return 1200;
    }
  }
  for (auto t : triangles){
    for (size_t i=0;i<3 ;i++){
      vertices.insert(t[i]->data);
      int v0 = t[i]->data;
      int v1 = t[(i+1)%3]->data;
      vertices.insert(v0);
      edges.insert(std::make_pair(std::min(v0,v1),std::max(v0,v1)));
    }
  }
  return triangles.size() - edges.size() + vertices.size();
}



bool PolyMesh::deleteVertexAndRemeshCavity (PolyMesh::Vertex *v,
std::vector<std::vector<Vertex*> > &triangles) { HalfEdge* he = v->he; HalfEdge*
bndHe = nullptr; std::vector<Face*> faces; std::vector<std::vector<Vertex*> >
old_triangles; do { faces.push_back(he->f); std::vector<Vertex*> t = {he->v,
he->next->v, he->next->next->v}; old_triangles.push_back(t); if (he->opposite ==
NULL) bndHe = he; else { he = he->opposite->next;
    }
  } while(he != v->he && bndHe == nullptr);


  for (auto t : triangles){
    HalfEdge * he0 = getEdgeBad (this, t[1], t[0]);
    HalfEdge * he1 = getEdgeBad (this, t[2], t[1]);
    HalfEdge * he2 = getEdgeBad (this, t[0], t[2]);
    if (he0 && he1 && he2 && he0->f == he1->f && he0->f == he2->f &&
std::find(faces.begin(), faces.end(), he0->f) == faces.end())return false;
  }
  //  printf("poincare : %d %d\n",poincare(triangles),poincare (old_triangles));

  if (poincare(triangles) != poincare (old_triangles))return false;

  for (auto f : faces) deleteFace(f);
  for (auto t : triangles) createTriangle(t[0],t[1],t[2]);
  return true;
}
*/

/*
void PolyMesh::Path::print4debug (int id, FILE *f) {

  //  if (_start.he == nullptr)return;
  if (_pts.size() < 2)return;
  //  printf("coucou%d\n",id);
  FILE *fff = f;
  if (!f){
    char name [245];
    sprintf(name,"Geodesic%d.pos",id);
    f = fopen (name, "w");
    fprintf(f,"View \"Geodesic %d\" {\n",id);
  }
  SVector3 p ;
  if (_start.he){
    p = _start.point();
    fprintf(f,"SP(%22.15E,%22.15E,%22.15E) {%d};\n",p.x(),p.y(),p.z(),id);
  }

  int ii = 0;
  for (auto pt : _pts){
    SVector3 pp = pt.point();
    if (ii++ != 0 ||  _start.he){
      fprintf(f,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E)
{%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);
    }
    p = pp;
  }
  if (_end.he){
    SVector3 pp = _end.point();
    fprintf(f,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E)
{%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);
    fprintf(f,"SP(%22.15E,%22.15E,%22.15E) {%d};\n",pp.x(),pp.y(),pp.z(),id);
  }
  if (!fff){
    fprintf(f,"};\n");
    fclose(f);
  }
}
*/

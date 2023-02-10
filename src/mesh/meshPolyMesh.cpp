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

//#include "/Users/CODES/geodesic_matlab/src/geodesic_mesh.h"
//#include "/Users/CODES/geodesic_matlab/src/geodesic_algorithm_exact.h" 

static void update(double lsit, PolyMesh::Vertex *vi, std::map<PolyMesh::Vertex*, double> &ls,
		   std::set<std::pair<double, PolyMesh::Vertex *> > & front) {
  std::pair<double, PolyMesh::Vertex *> pp = std::make_pair(ls[vi], vi);
  front.erase(pp);
  std::pair<double, PolyMesh::Vertex *> pp_new = std::make_pair(lsit, vi);
  front.insert(pp_new);
  ls[vi] = lsit;
}

static double trialedge(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj, double lsi) {
  SVector3 base = vj->position - vi->position;
  double l = base.norm();
  return lsi + l;
}

double trialtriangle(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj,PolyMesh::Vertex *vk, double lsi, double lsj){

  SVector3 ki = vk->position - vi->position;
  SVector3 kj = vk->position - vj->position;
  SVector3 pv = crossprod(ki,kj);

  SPoint2 pk (0.0, 0.0);
  SPoint2 pi (ki.norm(), 0.0);
  double xj = dot(ki,kj) / ki.norm();
  double yj = pv.norm()  / ki.norm();
  SPoint2 pj (xj, yj);
  
  double base[2][2] = {{pk.x() - pi.x(), pk.x() - pj.x()},
		       {pk.y() - pi.y(), pk.y() - pj.y()}};
  double m00 = base[0][0]*base[0][0] + base[1][0]*base[1][0];
  double m11 = base[0][1]*base[0][1] + base[1][1]*base[1][1];
  double m01 = base[0][0]*base[0][1] + base[1][0]*base[1][1];
  double detm = m00*m11-m01*m01;
  double dm00 = m11/detm;
  double dm11 = m00/detm;
  double dm01 = -m01/detm;
  double a = dm00+dm11+2*dm01;
  double dmd0= dm00*lsi + dm01*lsj;
  double dmd1 = dm01*lsi + dm11*lsj;
  double b = -2.*(dmd0+dmd1);
  double c = lsi*dmd0+lsj*dmd1-1.;
  double delta = b*b - 4.*a*c;
  if (delta < 0)return -1.0;
  double sdelta = sqrt(delta); 
  double lskt = (-b-sdelta)/2./a;
  if (lskt <= lsi) lskt = (-b+sdelta)/2./a;
  if (lskt < lsi) return -1.0;
  double gduali = lskt - lsi;
  double gdualj = lskt - lsj;
  double g1 = dm00*gduali+ dm01*gdualj;
  double g2 = dm01*gduali+ dm11*gdualj;
  if (g1 >= 0 && g2 >=0)return lskt;
  return -1.0;
}

static void treatedge (PolyMesh::Vertex *vi, PolyMesh::Vertex *vj,
		       std::map<PolyMesh::Vertex*, double> &ls,
		       std::set<std::pair<double, PolyMesh::Vertex *> > & front){    
  double lsjt = trialedge(vi,vj,ls[vi]); 
  if (lsjt < ls[vj]) update(lsjt, vj,ls,front);
}

static void treattriangle(PolyMesh::Vertex *vi, PolyMesh::Vertex *vj, PolyMesh::Vertex *vk,
			  std::map<PolyMesh::Vertex*, double> &ls,
			  std::set<std::pair<double, PolyMesh::Vertex *> > & front){
  double lskt = trialtriangle(vi, vj, vk, ls[vi], ls[vj]);
  if (lskt < 0) return;
  if (lskt < ls[vk]) update(lskt, vk, ls, front);
}

void print__ (const char *fn, PolyMesh*pm, std::map<PolyMesh::Vertex*,double> &ls){
  FILE *f = fopen(fn,"w");
  fprintf(f,"View\"\"{\n");
  for (auto t : pm->faces){
    PolyMesh::Vertex *v1 = t->he->v;
    PolyMesh::Vertex *v2 = t->he->next->v;
    PolyMesh::Vertex *v3 = t->he->next->next->v;
    std::map<PolyMesh::Vertex*,double>::iterator it1 = ls.find(v1);
    std::map<PolyMesh::Vertex*,double>::iterator it2 = ls.find(v2);
    std::map<PolyMesh::Vertex*,double>::iterator it3 = ls.find(v3);

    if (it1 != ls.end() && it2 != ls.end() && it3 != ls.end()){
      double l1 = it1->second;
      double l2 = it2->second;
      double l3 = it3->second;
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      v1->position.x(),v1->position.y(),v1->position.z(),
	      v2->position.x(),v2->position.y(),v2->position.z(),
	      v3->position.x(),v3->position.y(),v3->position.z(),l1,l2,l3);
    }
  }
  fprintf(f,"};\n");
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
  
//   geodesic::SurfacePoint sp (&mesh.faces()[f2n[_start.he->f]],p_start.x(), p_start.y(), p_start.z(),geodesic::FACE);
//   std::vector<geodesic::SurfacePoint> pts = {sp};

//   std::vector<geodesic::SurfacePoint> _stop ;
//   for (auto v : incident_edges){
//     SVector3 p_end = v.point();
//     geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(), p_end.y(), p_end.z(),geodesic::FACE);
//     _stop.push_back(spe);
//   }

  
//   geodesic::GeodesicAlgorithmExact algorithm(&mesh);
//   algorithm.propagate(pts,0,&_stop);
//   //  algorithm.propagate(pts,proxyDistance);

//   printf("Vertex with %lu incident edges proxy %12.5E n %lu\n",incident_edges.size(),proxyDistance,nnn);
  
//   for (auto v : incident_edges){
//     SVector3 p_end = v.point();
//     //    fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
//     //	    p_start.x(),p_start.y(),p_start.z(),
//     //	    p_end.x(),p_end.y(),p_end.z(),
//     //	    save_,save_);
//     geodesic::SurfacePoint spe (&mesh.faces()[f2n[v.he->f]],p_end.x(), p_end.y(), p_end.z(),geodesic::FACE);
//     std::vector<geodesic::SurfacePoint> path;
//     algorithm.trace_back(spe, path);
//     //    printf("path with %lu nodes\n",path.size());
    
//     for (size_t i = 0; i< path.size()-1;i++){
//       fprintf(f,"SL(%12.5E,%12.5E,%12.5E,%12.5E,%12.5E,%12.5E){%d,%d};\n",
//       	      path[i].x(),path[i].y(),path[i].z(),
//       	      path[i+1].x(),path[i+1].y(),path[i+1].z(),_start.he->v->data,_start.he->v->data);
//     }
//   }
// }


void PolyMesh::fastMarching (std::vector<Vertex *> &seeds, std::map<Vertex*,double> &ls)
{
  double t1 = Cpu();
  std::set<std::pair<double, PolyMesh::Vertex *> > front;
  std::set<PolyMesh::Vertex *> visited;
  for (auto v : vertices)if (ls.find(v) == ls.end())ls[v] = 1.e22;
  for (auto v : seeds){
    if (ls.find(v) == ls.end())ls[v] = 0.0;
    front.insert(std::make_pair(0.0,v));		 
  }    

  while(!front.empty()) {
    auto it = front.begin();
    front.erase(it);
    Vertex *vi = it->second;
    visited.insert(vi);
    HalfEdge *he = vi->he;      
    // take into account boundary vertices
    do {
      if (he->prev->opposite == nullptr)break;
      he = he->prev->opposite;
    } while (he != vi->he);
    // loop around vert 
    do {
      Vertex *vj = he->next->v;
      if (visited.find(vj) == visited.end()){
	treatedge(vi, vj, ls, front);
      }
      else {
	HalfEdge *ij = getEdge(vi, vj);
	HalfEdge *ji = getEdge(vj, vi);
	if (ij){
	  Vertex *vk =  ij->prev->v;
	  treattriangle(vi, vj, vk, ls, front);
	}	
	if (ji){
	  Vertex *vk =  ji->prev->v;
	  treattriangle(vi, vj, vk, ls, front);
	}	
      } 
      if (he->opposite == nullptr)break;
      he = he->opposite->next;
    }while (he != vi->he);
  }
  double t2 = Cpu();
  Msg::Info("fast marching time : %g",t2-t1);
  print__ ("fm.pos", this, ls);
}

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
      fprintf(f,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E) {%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);
    }
    p = pp;
  }
  if (_end.he){
    SVector3 pp = _end.point();
    fprintf(f,"SL(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E) {%d,%d};\n",p.x(),p.y(),p.z(),pp.x(),pp.y(),pp.z(),id,id);  
    fprintf(f,"SP(%22.15E,%22.15E,%22.15E) {%d};\n",pp.x(),pp.y(),pp.z(),id);
  }
  if (!fff){
    fprintf(f,"};\n");
    fclose(f);
  }
}

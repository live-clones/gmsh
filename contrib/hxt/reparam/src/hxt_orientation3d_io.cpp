#include "hxt_orientation3d_io.h"

extern "C" {
#include "hxt_orientation3d.h"
  // #include "hxt_orientation3dExplicit.h"
#include "hxt_orientation3d_tools.h"
#include "predicates.h"
#include "hxt_tetRepair.h"
#include "hxt_bbox.h"
}

#include "rtree.hpp"

#include <ios>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using std::vector;

namespace Streamlines {

  const uint64_t NO_CELL = UINT64_MAX;
  static bool rtreeCallback(int id, void *ctx) {
    std::vector<int>* vec = reinterpret_cast< std::vector<int>* >(ctx);
    vec->push_back(id);
    return true;
  }

  class vec3 {
  public:
    vec3() { 
      data[0] = 0; data[1] = 0; data[2] = 0; 
    };
    vec3(double x, double y, double z) {
      data[0] = x; data[1] = y; data[2] = z;
    }
    vec3(const double *x) {
      data[0] = x[0]; data[1] = x[1]; data[2] = x[2];
    }
    double operator [](unsigned int i) const {return data[i];}
    double &operator [](unsigned int i) {return data[i];}
    vec3 operator + (const vec3& v) const  { return vec3(data[0]+v[0], data[1]+v[1], data[2]+v[2]); }
    vec3 operator - (const vec3& v) const  { return vec3(data[0]-v[0], data[1]-v[1], data[2]-v[2]); }
    vec3 operator / (const double f) const { return vec3(data[0] / f, data[1] / f, data[2] / f); }
    vec3 operator * (const double f) const { return vec3(data[0] * f, data[1] * f, data[2] * f); }
    double length2() const {return data[0]*data[0]+data[1]*data[1]+data[2]*data[2];}
    double length() const {return std::sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]);}
  public:
    double data[3];
  };
  double dot(vec3 a, vec3 b) { return a[0]*b[0] + a[1] * b[1] + a[2]*b[2]; };
  vec3 cross(vec3 a, vec3 b) { 
    return { a.data[1]*b.data[2] - a.data[2]*b.data[1],
      a.data[2]*b.data[0] - a.data[0]*b.data[2],
      a.data[0]*b.data[1] - a.data[1]*b.data[0] }; 
  }

  bool getBarycentricTetra(const HXTMesh *mesh, uint64_t c, const double *p, double *lambda) {
    const double eps = 1.e-12;
    const uint32_t vtet[4] = {
      mesh->tetrahedra.node[4*c+0],
      mesh->tetrahedra.node[4*c+1],
      mesh->tetrahedra.node[4*c+2],
      mesh->tetrahedra.node[4*c+3]};
    const double *v0 = mesh->vertices.coord + 4*vtet[0];
    const double *v1 = mesh->vertices.coord + 4*vtet[1];
    const double *v2 = mesh->vertices.coord + 4*vtet[2];
    const double *v3 = mesh->vertices.coord + 4*vtet[3];
    
    const double x0 = orient3d(p, v1, v2, v3);
    const double x4 = orient3d(v0, v1, v2, v3);
    lambda[0] = x0/x4;
    if (lambda[0] < 0. - eps || lambda[0] > 1. + eps) return false;

    const double x1 = orient3d(p, v0, v2, v3);
    const double x5 = orient3d(v1, v0, v2, v3);
    lambda[1] = x1/x5;
    if (lambda[1] < 0. - eps || lambda[1] > 1. + eps) return false;

    double x2 = orient3d(p, v0, v1, v3);
    double x6 = orient3d(v2, v0, v1, v3);
    lambda[2] = x2/x6;
    if (lambda[2] < 0. - eps || lambda[2] > 1. + eps) return false;

    lambda[3] = 1.-lambda[0]-lambda[1]-lambda[2];
    return lambda[3] >= 0. - eps && lambda[3] <= 1 + eps;
  }

  uint64_t getTetrahedron(const HXTMesh* m, const RTree<int, double, 3>& tetRtree, vec3 pt, double lambda[4], uint64_t firstGuess) {
    if (firstGuess != NO_CELL) {
      /* Try in first guess tetrahedron */
      if (getBarycentricTetra(m, firstGuess, pt.data, lambda)) {
        return firstGuess;
      }

      if (m->tetrahedra.neigh != NULL) {
        /* Collect adjacent tetrahedra */
        const uint64_t MAX_ADJ = 12;
        std::vector<uint64_t> adj_tets;
        adj_tets.reserve(MAX_ADJ);
        adj_tets.push_back(firstGuess);
        std::deque<uint64_t> Q;
        Q.push_back(firstGuess);
        while (Q.size() > 0 && adj_tets.size() < MAX_ADJ) {
          const uint64_t curTet = Q.front();
          Q.pop_front();
          for (uint8_t lf = 0; lf < 4; ++lf) {
            const uint64_t neigh = m->tetrahedra.neigh[4*curTet + lf];
            if (neigh != HXT_NO_ADJACENT){
              uint64_t adjTet = neigh / 4;
              bool alreadyVisited = std::find(adj_tets.begin(), adj_tets.end(), adjTet) != adj_tets.end();
              if (!alreadyVisited) {
                adj_tets.push_back(adjTet);
                Q.push_back(adjTet);
              }
            }
          }
        }

        /* Check if pt is in adjacent tetrahedra */
        for (uint64_t lc = 1; lc < adj_tets.size(); ++lc) {
          uint64_t c = adj_tets[lc];
          if (getBarycentricTetra(m, c, pt.data, lambda)) {
            return c;
          }
        }
      }
    }

    /* Use the rtree if not yet found */
    const double epsilon = 1.e-12;
    const vec3 min = pt - vec3(epsilon, epsilon, epsilon);
    const vec3 max = pt + vec3(epsilon, epsilon, epsilon);
    std::vector<int> candidates;
    tetRtree.Search(min.data, max.data, rtreeCallback, &candidates);
    for (uint32_t lc = 0; lc < candidates.size(); ++lc) {
      uint64_t curTet = candidates[lc];
      if (getBarycentricTetra(m, curTet, pt.data, lambda)) {
        return curTet;
      }
    }

    /* Not found */
    return NO_CELL;
  }

  uint64_t getTetrahedron(const HXTMesh* M, const RTree<int, double, 3>& tetRtree, vec3 pt) {
    double lambda[4];
    return getTetrahedron(M, tetRtree, pt, lambda, NO_CELL);
  }

  vec3 closestVectorInCandidates(vec3 inputVector, const vec3 candidates[3]) {
    if (inputVector.length2() == 0) return {0,0,0};
    double maxDot = - 999999.;
    vec3 out = {0,0,0};
    for (uint8_t i = 0; i < 3; ++i) {
      if (candidates[i].length2() == 0) continue;
      const double d = dot(inputVector, candidates[i]);
      if (abs(d) > maxDot) {
        maxDot = abs(d);
        if (d > 0) {
          out = candidates[i];
        } else {
          out = candidates[i] * -1.;
        }
      }
    }
    return out;
  }
  
  bool projectTensorOnCrossManifold(const double tIn[9], double tOut[9]) {
    double dir[3*3]={0.0};
    hxtOr3DframeToDirections(tIn, NULL, dir);
    hxtOr3DdirectionsToFrame(dir, tOut);
    return true;
  }

  double getTetShortestEdge(const HXTMesh* mesh, uint64_t tet) {
    const uint32_t TET_EDGES[6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
    double me = 1.e30;
    for (uint8_t le = 0; le < 6; ++le) {
      double e = (vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+TET_EDGES[le][1]]])
		  - vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+TET_EDGES[le][0]]])).length2();
      if (e < me) me = e;
    }
    return std::sqrt(me);
  }

  vec3 tetCenter(const HXTMesh* mesh, uint64_t tet) {
    vec3 center = {0,0,0};
    center =  center + vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+0]]) * 0.25;
    center =  center + vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+1]]) * 0.25;
    center =  center + vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+2]]) * 0.25;
    center =  center + vec3(&mesh->vertices.coord[4*mesh->tetrahedra.node[4*tet+3]]) * 0.25;
    return center;
  }

  double clamp(double x, double lower, double upper) {
    return std::min(upper, std::max(x, lower));
  }

  void getVectorsFromTensor(const double tensor[9], vec3 vectors[3]) {
    double dev = 0.;
    hxtOr3DcomputeQuality(tensor, &dev);
    if (dev < 0.2) { /* valid cross */
      double _vectors[9]={0.};
      hxtOr3DframeToDirections(tensor, NULL, _vectors);
      for (uint8_t i = 0; i < 3; ++i) {
        vectors[i] = {_vectors[i],_vectors[3+i],_vectors[6+i]};
      }
    } 
  }

  vec3 normalize(vec3 v) {
    HXT_ASSERT(v.length() > 1.e-8);
    return v / v.length();
  }

  double angleVectors(vec3 A, vec3 B, bool normaliz = false, bool absolute = true) {
    if (normaliz) {
      A = normalize(A);
      B = normalize(B);
    }
    if (absolute) {
      return 180./M_PI * acos(clamp(abs(dot(A,B)),-1.,1.));
    }
    return 180./M_PI * acos(clamp(dot(A,B),-1.,1.));
  }

  vec3 getVector(const vec3* vectors, uint32_t v, int dir) {
    if (dir >= 1 && dir <= 3) {
      return vectors[3*v+dir-1];
    } else if (dir <= -1 && dir >= -3) {
      return vectors[3*v-dir-1]*-1.;
    }
    return {0.,0.,0.};
  }

  vec3 getClosestVector(vec3 input, vec3 candidates[3]) {
    if (input.length2() == 0) return {0,0,0};
    double maxDot = - 999999.;
    vec3 out = {0,0,0};
    for (uint8_t i = 0; i < 3; ++i) {
      if (candidates[i].length2() == 0) continue;
      const double d = dot(input, candidates[i]);
      if (abs(d) > maxDot) {
        maxDot = abs(d);
        if (d > 0) {
          out = candidates[i];
        } else {
          out = candidates[i] * -1.;
        }
      }
    }
    return out;
  }

  bool interpolateVector(const HXTMesh* m, const vec3* vectorField, 
			 uint64_t tetSearch, const double pt[3], vec3 input, vec3& output, uint64_t& nextTet) {
    vector<uint64_t> visited;
    visited.reserve(100);
    visited.push_back(tetSearch);
    std::deque<uint64_t> Q;
    Q.push_back(tetSearch);
    while (Q.size() > 0 && visited.size() < 100) {
      const uint64_t curTet = Q.front();
      Q.pop_front();
      double lambda[4];
      if (getBarycentricTetra(m, curTet, pt, lambda)) {
        output = {0,0,0};
        for (uint8_t lv = 0; lv < 4; ++lv) {
          const uint32_t v = m->tetrahedra.node[4*curTet+lv];
          const vec3 nodeVec = closestVectorInCandidates(input, &vectorField[3*v]);
          if (nodeVec.length2() == 0) return false;
          output = output + nodeVec;
        }
        if (output.length2() > 0) {
          nextTet = curTet;
          output = output * 1./sqrt(output.length2());
          double a = angleVectors(output, input * 1./sqrt(input.length2()));
          if (angleVectors(output, input * 1./sqrt(input.length2())) > 30) return false;
          return true;
        } else {
          return false;
        }
      }
      /* Propagation to neighbors */
      for (uint8_t lf = 0; lf < 4; ++lf) {
        const uint64_t neigh = m->tetrahedra.neigh[4*curTet+lf];
        if (neigh != HXT_NO_ADJACENT){
          bool alreadyVisited = std::find(visited.begin(), visited.end(), neigh/4) != visited.end();
          if (!alreadyVisited) {
            visited.push_back(neigh/4);
            Q.push_back(neigh/4);
          }
        }
      }
    }
    return false;
  }

  bool interpolateVectorRtree(const HXTMesh* M, const vec3* vectorField, 
      const RTree<int, double, 3>& tetRtree, vec3 pt, vec3 input, vec3& output, uint64_t& tet, double angleFilter = 45) {
    double lambda[4];
    tet = getTetrahedron(M, tetRtree, pt, lambda, tet);
    if (tet == NO_CELL) return false;
    output = {0,0,0};
    vec3 ref = input;
    for (uint8_t lv = 0; lv < 4; ++lv) {
      const uint32_t v = M->tetrahedra.node[4*tet+lv];
      const vec3 nodeVec = closestVectorInCandidates(ref, &vectorField[3*v]);
      if (nodeVec.length2() == 0) return false;
      output = output + nodeVec;
      ref = nodeVec;
    }
    if (output.length2() > 0) {
      output = output * 1./sqrt(output.length2());
      double a = angleVectors(output, input * 1./sqrt(input.length2()));
      if (a > angleFilter) return false;
      return true;
    }
    return false;
  }

  void generateStreamLine(
			  const HXTMesh* mesh, 
			  const vec3* vectorField, 
			  uint64_t tet, 
			  const RTree<int, double, 3>& tetRtree,
			  const double* pt, 
			  const double* dir,
			  double lineLength, 
			  vector<vec3>& line) {
    line.clear();
    double length = 0;
    double DELTA_FACTOR = 0.8;

    /* Initialisation */
    vec3 curPos = vec3(pt);
    vec3 curVec = vec3(dir);

    /* Propagation 
     * curPos(t+1) = curPos(t) + DELTA * crossDirectionAt( curPos(t) + DELTA/2 * crossDirectionAt(curPos(t)) ) */
    line.push_back(curPos);
    bool start = true;
    while (length < lineLength) {
      if (tet == NO_CELL) tet = getTetrahedron(mesh, tetRtree, curPos);
      const double delta = DELTA_FACTOR*getTetShortestEdge(mesh, tet);

      /* Interpolate vector field at curPos */
      bool ok = interpolateVectorRtree(mesh, vectorField, tetRtree, curPos.data, curVec, curVec, tet);
      if (!ok) return;

      /* Interpolate vector field at intPos */
      const vec3 intPos = curPos + curVec * delta / 2;
      ok = interpolateVectorRtree(mesh, vectorField, tetRtree, intPos.data, curVec, curVec, tet);
      if (!ok) return;

      /* New position */
      curPos = curPos + curVec * delta;
      length += delta;
      line.push_back(curPos);
    }
  }

  bool extractPointsWithCoherentDirections(std::vector<std::tuple<double,double,vec3>>& lm_dev_angle_pt, uint64_t nbDirs, double toleranceDeg, 
      std::vector<vec3>& pts) {
    pts.clear();
    if (lm_dev_angle_pt.size() < nbDirs) return false;
    std::sort(lm_dev_angle_pt.begin(), lm_dev_angle_pt.end(), 
        [](const std::tuple<double,double,vec3> &left, const std::tuple<double,double,vec3> &right) { return std::get<0>(left) < std::get<0>(right);});

    /* minimum deviation is reference point */
    pts.push_back(std::get<2>(lm_dev_angle_pt[0]));
    double ref_angle = std::get<1>(lm_dev_angle_pt[0]);

    for (uint64_t i = 1; i < nbDirs; ++i) {
      double searched_angle = fmod((ref_angle + 360. * i / nbDirs),360.);
      bool found = false;
      for(uint64_t j = 1; j < lm_dev_angle_pt.size(); ++j){
        double cangle = std::get<1>(lm_dev_angle_pt[j]);
        double diff = 180 - abs(abs(cangle - searched_angle) - 180); 
        if (abs(diff) < toleranceDeg) {
          pts.push_back(std::get<2>(lm_dev_angle_pt[j]));
          found = true;
          break;
        }
      }
      if (!found) {
        pts.clear();
        return false;
      }
    }
    if (pts.size() == nbDirs) {
      return true;
    }
    pts.clear();
    return false;
  }

  void buildTetRtree(const HXTMesh* m, RTree<int,double,3>& tetRtree) {
    for (uint64_t c = 0; c < m->tetrahedra.num; ++c) {
      double min[3], max[3];
      for (uint8_t d = 0; d < 3; ++d) {
        min[d] =  DBL_MAX;
        max[d] = -DBL_MAX;
        for (uint8_t lv = 0; lv < 4; ++lv) {
          const uint32_t v = m->tetrahedra.node[4*c+lv];
          min[d] = std::min(min[d], m->vertices.coord[4*v+d]);
          max[d] = std::max(max[d], m->vertices.coord[4*v+d]);
        }
      }
      tetRtree.Insert(min, max, (int)c);
    }
  }

  void generateSingularityFans(HXTMesh* m, const vec3* vectorField, std::vector<vec3>& sFans) {
    if (m->tetrahedra.neigh == NULL) {
      hxtTetAdjacencies(m);
    }

    const double factor = 1.5; /* disk radius relative to local smallest edge */

    /* build rtree with tets */
    RTree<int, double, 3> tetRtree;
    buildTetRtree(m, tetRtree);

    /* loop on vertices with one non-zero direction (the first one) in vectorField */
    for (uint32_t v = 0; v < m->vertices.num; ++v) {
      if (vectorField[3*v+1].length2() > 0) continue;
      if (vectorField[3*v+2].length2() > 0) continue;
      if (vectorField[3*v+0].length2() == 0) continue;
      vec3 pt = vec3(&(m->vertices.coord[4*v]));
      vec3 sDir = vectorField[3*v+0];
      sDir = normalize(sDir);

      uint64_t elt = NO_CELL;
      double rsize = 0;
      elt = getTetrahedron(m, tetRtree, pt);
      if (elt == NO_CELL) continue;
      rsize = factor*getTetShortestEdge(m, elt);

      /* Build orthogonal directions (sDir, dir1, dir2) */
      vec3 dir2;
      if (abs(sDir.data[2]) < abs(sDir.data[0])) {
        dir2 = {sDir.data[1], -sDir.data[0], 0};
      } else {
        dir2 = {0, -sDir.data[2], sDir.data[1]};
      }
      dir2 = dir2 / dir2.length();
      vec3 dir3 = cross(sDir, dir2);

      /* Get candidates */
      double tol = 20.;
      std::vector<std::tuple<double,double,vec3>> lm_dev_angle_pt;
      const uint64_t nbSample = 300;
      {
        bool okd = true;
        /* Sample the circle around sDir, of radius rsize */
        std::vector<std::tuple<double,double,vec3>> dev_angle_pt(nbSample, std::make_tuple(360, 0, vec3(0,0,0)));
        uint64_t tet = NO_CELL;
        uint64_t nbFailed = 0;
        for (uint64_t k = 0; k < nbSample; ++k) {
          double theta = (double) k / (double) nbSample * 2 * M_PI;
          vec3 pTest = pt + (dir2 * cos(theta) + dir3 * sin(theta)) * rsize;
          vec3 rdir = pTest - pt;
          rdir = rdir / rdir.length();
          bool ok = false;
          vec3 out = {0,0,0};
          ok = interpolateVectorRtree(m, vectorField, tetRtree, pTest, rdir, out, tet);
          if (!ok || out.length() == 0) {
            continue;
          }
          if (abs(angleVectors(out, sDir, false, true)-90) > 20) {
            nbFailed += 1;
            if ((double)nbFailed / nbSample > 0.1) {
              okd = false;
              break;
            }
            continue;
          }
          if (!okd) continue; /* failed this disk, go to next singular point */
          dev_angle_pt[k] = std::make_tuple(angleVectors(rdir,out), theta*360./(2.*M_PI), pTest);
        }

        /* Extract the local minima of deviation */
        for (uint64_t k = 0; k < nbSample; ++k) {
          if (   std::get<0>(dev_angle_pt[k]) < tol
              && std::get<0>(dev_angle_pt[k]) < std::get<0>(dev_angle_pt[(k+1)%nbSample])
              && std::get<0>(dev_angle_pt[k]) < std::get<0>(dev_angle_pt[(k+2)%nbSample])
              && std::get<0>(dev_angle_pt[k]) < std::get<0>(dev_angle_pt[(k-1)%nbSample])
              && std::get<0>(dev_angle_pt[k]) < std::get<0>(dev_angle_pt[(k-2)%nbSample])
             ) {
            lm_dev_angle_pt.push_back(dev_angle_pt[k]);
          }
        }
      } 

      /* Extract and check consistency */
      std::vector<vec3> sPoints;
      bool consistent = false;
      consistent = extractPointsWithCoherentDirections(lm_dev_angle_pt, 3, tol, sPoints);
      if (!consistent) {
        consistent = extractPointsWithCoherentDirections(lm_dev_angle_pt, 5, 3./5*tol, sPoints);
      }
      if (!consistent) continue;

      /* Draw the fan */
      for (uint64_t k = 0; k < sPoints.size(); ++k) {
        sFans.push_back(pt);
        sFans.push_back(sPoints[k]);
      }
    }
  }
}


using namespace Streamlines;

void writeLine(const vector<vec3>& line, FILE* fp, double color) {
  for (uint32_t l = 0; l < line.size() - 1; ++l) {
    fprintf(fp, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%f,%f};\n", 
	    line[l][0], line[l][1], line[l][2], 
	    line[l+1][0], line[l+1][1], line[l+1][2], 
	    color, color);
  }
}

uint32_t idFromIds(const uint32_t nb[3], uint32_t i, uint32_t j, uint32_t k) {
  return nb[2]*nb[1]*k + nb[1] * j + i;
}

HXTStatus extractCrossDirectionsFromField(const HXTMesh* mesh, const double* field, double* crossDirs, double* deviation = NULL) {
  double crossDirLoc[9];
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    const double *frame=field+9*i;
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frame, stableDir, crossDirLoc);
    double color[3];
    for(int k=0;k<3;k++)
      color[k]=1.0;
    double quality=0.0;
    hxtOr3DcomputeQuality(frame,&quality);
    if (deviation != NULL) deviation[i] = quality;
    if(quality>0.25){
      for(int k=0; k<3; k++){
        double val=stableDir[k]-0.9;
        (val<0)? color[k]=0.0:color[k]=1.0;
      }
    }
    int nDirStored=0;
    int nZero=0;
    for (int j = 0; j < 3; ++j) {
      double d[3] = {crossDirLoc[3*j], crossDirLoc[3*j+1], crossDirLoc[3*j+2]};
      if(fabs(color[j])<1e-5)
        nZero++;
      else{
        for(int k=0; k<3; k++)
          crossDirs[9*i+3*nDirStored+k]=d[k];
        nDirStored++;
      }
    }
    for(int j=0; j<nZero; j++){
      for(int k=0; k<3; k++)
        crossDirs[9*i+3*nDirStored+k]=0.0;
      nDirStored++;
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosScalarTet(HXTMesh *mesh, double *directions, double *scalarField, const char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Scalar Field\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    double value=0.0;
    int isTetSing=0;
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    if(directions){
      double frame[9]={0.0};
      for(int k=0;k<4;k++){
	for(int l=0;l<9;l++){
	  frame[l]=directions[9*tet[k]+l];
	}
	double quality=0.0;
	hxtOr3DcomputeQuality(frame,&quality);
	if(quality>10)
	  isTetSing=1;
      }
      if(!isTetSing)
	value=scalarField[i];
      else
	value=0.0;
    }
    else{
      value=scalarField[i];
    }
    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    fprintf(myfile,"SS(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2],value,value,value,value);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosVectorTet(HXTMesh *mesh, double *vectorField, const char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"vector Field\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    double value[3]={0.0};
    int isTetSing=0;
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    value[0]=vectorField[3*i+0];
    value[1]=vectorField[3*i+1];
    value[2]=vectorField[3*i+2];
    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    double barCoor[3]={0.25*(x0[0]+x1[0]+x2[0]+x3[0]),
		       0.25*(x0[1]+x1[1]+x2[1]+x3[1]),
		       0.25*(x0[2]+x1[2]+x2[2]+x3[2])};
    fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",barCoor[0],barCoor[1],barCoor[2],value[0],value[1],value[2]);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosPotentials(HXTMesh *mesh, double *uvw, const char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"potential U\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    double *potTet=uvw+4*i;
    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    fprintf(myfile,"SS(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2],potTet[0],potTet[1],potTet[2],potTet[3]);
  }
  fprintf(myfile,"};");
  fprintf(myfile,"View \"potential V\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    double *potTet=uvw+(4*mesh->tetrahedra.num+4*i);
    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    fprintf(myfile,"SS(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2],potTet[0],potTet[1],potTet[2],potTet[3]);
  }
  fprintf(myfile,"};");
  fprintf(myfile,"View \"potential W\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    double *potTet=uvw+2*4*mesh->tetrahedra.num+4*i;
    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    fprintf(myfile,"SS(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2],potTet[0],potTet[1],potTet[2],potTet[3]);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosScalarTri(HXTMesh *mesh, double *scalarField, const char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Scalar Field\"{\n");
  for (uint64_t i = 0; i < mesh->triangles.num; ++i) {
    double value=0.0;
    uint32_t *tri = mesh->triangles.node+i*3;
    value=scalarField[i];
    double *x0 = mesh->vertices.coord + 4*tri[0];
    double *x1 = mesh->vertices.coord + 4*tri[1];
    double *x2 = mesh->vertices.coord + 4*tri[2];
    fprintf(myfile,"ST(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],value,value,value);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3dWritePosScalarNode(HXTMesh *mesh, double *scalarField, char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Energy Error\"{\n");
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    double *x0 = mesh->vertices.coord + 4*i;
    fprintf(myfile,"SP(%.16g,%.16g,%.16g){%.16g};\n",x0[0],x0[1],x0[2],scalarField[i]);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWriteStreamLines(HXTMesh* mesh, const double* field, const char* path, const char* viewName){
  const int NB_PER_AXIS = 6;

  if (mesh->tetrahedra.neigh == NULL) {
    hxtTetAdjacencies(mesh);
  }

  /* Building regular grid to start streamlines
   * For each grid point, find the closest tet */
  HXTBbox bbox;
  hxtBboxInit(&bbox);
  hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);
  double h = (bbox.max[0] - bbox.min[0]) / NB_PER_AXIS;
  if ((bbox.max[1] - bbox.min[1]) / NB_PER_AXIS < h) h = (bbox.max[1] - bbox.min[1]) / NB_PER_AXIS;
  if ((bbox.max[2] - bbox.min[2]) / NB_PER_AXIS < h) h = (bbox.max[2] - bbox.min[2]) / NB_PER_AXIS;
  uint32_t nb[3] = {0,0,0};
  nb[0] = (bbox.max[0] - bbox.min[0]) / h;
  nb[1] = (bbox.max[1] - bbox.min[1]) / h;
  nb[2] = (bbox.max[2] - bbox.min[2]) / h;
  vector<uint64_t> closestTet(nb[0]*nb[1]*nb[2], -1);
  vector<double> dist(nb[0]*nb[1]*nb[2], DBL_MAX);
  for (uint64_t c = 0; c < mesh->tetrahedra.num; ++c) {
    vec3 C = tetCenter(mesh, c);
    uint32_t voxel[3];
    for (uint8_t d = 0; d < 3; ++d) {
      voxel[d] = (C.data[d] - bbox.min[d]) / h;
    }
    double distTetToVoxel = (C - (vec3(bbox.min) + vec3(voxel[0],voxel[1],voxel[2]) * h)).length2();
    if (distTetToVoxel < dist[idFromIds(nb, voxel[0], voxel[1], voxel[2])]) {
      dist[idFromIds(nb, voxel[0], voxel[1], voxel[2])] = distTetToVoxel ;
      closestTet[idFromIds(nb, voxel[0], voxel[1], voxel[2])] = c;
    }
  }

  /* Extract 3 vector directions for each tensor */
  vector<vec3> vectorField(3*mesh->vertices.num, {0,0,0});
  vector<double> deviations(mesh->vertices.num, 0);
  HXT_CHECK(extractCrossDirectionsFromField(mesh, field, vectorField[0].data, &deviations[0]));

  /* build rtree with tets */
  RTree<int, double, 3> tetRtree;
  buildTetRtree(mesh, tetRtree);

  /* Generate streamlines */
  vector<vector<vec3> > streamlines;
  for (uint64_t i = 0; i < nb[0]*nb[1]*nb[2]; ++i) {
    if (dist[i] == DBL_MAX) continue;
    const vec3 C = tetCenter(mesh, closestTet[i]);
    vector<vec3> line;
    line.reserve(100);
    for (int d = -3; d <= 3; ++d) {
      if (d == 0) continue;
      double lineLength = 20.*getTetShortestEdge(mesh, closestTet[i]);
      vec3 dir = getVector(&vectorField[0],mesh->tetrahedra.node[4*closestTet[i]], d);
      generateStreamLine(mesh, &vectorField[0], closestTet[i], tetRtree, C.data, dir.data, lineLength, line);
      if (line.size() >= 2) {
        streamlines.push_back(line);
      }
    }
  }

  /* Export */
  printf("writing orientation field streamlines to \"%s\"\n", path);
  FILE* fp;
  fp = fopen(path, "w");

  /* - streamlines */
  fprintf(fp, "View \"%s\" {\n", viewName);
  for (uint32_t l = 0; l < streamlines.size(); ++l) {
    writeLine(streamlines[l], fp, 0);
  }
  fprintf(fp, "};\n\n");

  /* - singular regions */
  fprintf(fp, "View \"%s\" {\n", "singular regions");
  for (uint64_t c = 0; c < mesh->tetrahedra.num; ++c) {
    bool keep = false;
    const uint32_t* nodes = &(mesh->tetrahedra.node[4*c]);
    for (uint8_t lv = 0; lv < 4; ++lv) {
      if (deviations[nodes[lv]] > 0.2) keep = true;
    }
    if (!keep) continue;
    const double* X = mesh->vertices.coord;
    fprintf(fp, "  SS(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f,%f};\n", 
	    X[4*nodes[0]+0], X[4*nodes[0]+1], X[4*nodes[0]+2], 
	    X[4*nodes[1]+0], X[4*nodes[1]+1], X[4*nodes[1]+2], 
	    X[4*nodes[2]+0], X[4*nodes[2]+1], X[4*nodes[2]+2], 
	    X[4*nodes[3]+0], X[4*nodes[3]+1], X[4*nodes[3]+2], 
	    deviations[nodes[0]], deviations[nodes[1]], deviations[nodes[2]], deviations[nodes[3]]);
  }
  fprintf(fp, "};\n\n");

  /* - initial mesh lines */
  fprintf(fp, "View \"%s\" {\n", "mesh lines");
  for (uint64_t l = 0; l < mesh->lines.num; ++l) {
    const double* v1 = &(mesh->vertices.coord[4*mesh->lines.node[2*l+0]]);
    const double* v2 = &(mesh->vertices.coord[4*mesh->lines.node[2*l+1]]);
    fprintf(fp, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%f,%f};\n", 
	    v1[0], v1[1], v1[2], 
	    v2[0], v2[1], v2[2], 
	    0., 0.);
  }
  fprintf(fp, "};\n\n");
  /* - gmsh visu options */
  fprintf(fp,"View[0].LineType = 1;\n");
  fprintf(fp,"View[0].LineWidth = 3;\n");
  fprintf(fp,"View[0].ColormapNumber = 17;\n");
  fprintf(fp,"View[1].LineType = 0;\n");
  fprintf(fp,"View[1].LineWidth = 3;\n");
  fprintf(fp,"View[1].ColormapNumber = 0;\n");
  fprintf(fp,"View[2].ColormapNumber = 14;\n");
  fprintf(fp,"View[2].IntervalsType = 1;\n");
  fprintf(fp,"View[2].RangeType = 2;\n");
  fprintf(fp,"View[2].CustomMax = 0.2;\n");
  fprintf(fp,"View[2].CustomMin = 0.2;\n");
  fclose(fp);
  printf("%li streamlines written.\n", streamlines.size());

  return HXT_STATUS_OK;
}

void write_vector(const char* filepath, size_t n, double* data){
  printf("(I/O) writing a vector of %li values at %s\n", n, filepath);
  std::ofstream ofs(filepath, std::ios::out | std::ios::binary);
  ofs.write(reinterpret_cast<char*>(&n), sizeof(n));
  ofs.write(reinterpret_cast<char*>(data), n * sizeof(double));
}

HXTStatus read_vector(const char* filepath, double** data){
  std::ifstream ifs(filepath, std::ios::in | std::ios::binary);
  if(ifs.fail()){
    std::cerr << "(I/O) file " << filepath << " not found" << std::endl;
    return HXT_STATUS_READ_ERROR;
  }
  // Read size at beginning of file and resize vector
  size_t size = 0;
  ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
  printf("(I/O) read a vector containing %li values from %s\n", size, filepath);
  hxtMalloc(data, size*sizeof(double));
  // Read data in the file
  ifs.read(reinterpret_cast<char*>(*data), size * sizeof(double));
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWriteBinaryFrames(const HXTMesh *mesh, double *frames, const char *filepath)
{
  double *crossDir;
  HXT_CHECK(hxtMalloc(&crossDir, 9*mesh->vertices.num*sizeof(double)));
  HXT_CHECK(extractCrossDirectionsFromField(mesh, frames, crossDir));
  write_vector(filepath, 9*mesh->vertices.num, crossDir);
  HXT_CHECK(hxtFree(&crossDir));
  return HXT_STATUS_OK;
}


HXTStatus hxtOr3DWriteSingularityFans(HXTMesh* mesh, const double* field, const char* path, const char* viewName, int traceStreamlines) {
  /* Extract 3 directions per vertex */
  std::vector<vec3> vectors(3*mesh->vertices.num, vec3(0,0,0));
  vector<double> deviations(mesh->vertices.num, 0);
  HXT_CHECK(extractCrossDirectionsFromField(mesh, field, vectors[0].data, &deviations[0]));

  /* Compute the fans (disk sampling around singular vertices) */
  std::vector<vec3> sFans;
  generateSingularityFans(mesh, &vectors[0], sFans);

  if (sFans.size() == 0) {
    printf("no sigularity fans found\n");
    return HXT_STATUS_OK;
  }

  /* Export the fans */
  printf("writing singularity fans to \"%s\"\n", path);
  FILE* fp;
  fp = fopen(path, "w");

  /* - streamlines */
  fprintf(fp, "View \"%s\" {\n", viewName);
  for (uint32_t l = 0; l < sFans.size() / 2; ++l) {
    fprintf(fp, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%f,%f};\n", 
        sFans[2*l][0], sFans[2*l][1], sFans[2*l][2],
        sFans[2*l+1][0], sFans[2*l+1][1], sFans[2*l+1][2],
        0., 0.);
  }
  fprintf(fp, "};\n\n");
  fprintf(fp,"View[0].LineType = 0;\n");
  fprintf(fp,"View[0].LineWidth = 3;\n");
  printf("%li edges of singularity fans written.\n", sFans.size() / 2);

  /* - singular regions */
  fprintf(fp, "View \"%s\" {\n", "sing. regions");
  for (uint64_t c = 0; c < mesh->tetrahedra.num; ++c) {
    bool keep = false;
    const uint32_t* nodes = &(mesh->tetrahedra.node[4*c]);
    for (uint8_t lv = 0; lv < 4; ++lv) {
      if (deviations[nodes[lv]] > 0.2) keep = true;
    }
    if (!keep) continue;
    const double* X = mesh->vertices.coord;
    fprintf(fp, "  SS(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f,%f};\n", 
	    X[4*nodes[0]+0], X[4*nodes[0]+1], X[4*nodes[0]+2], 
	    X[4*nodes[1]+0], X[4*nodes[1]+1], X[4*nodes[1]+2], 
	    X[4*nodes[2]+0], X[4*nodes[2]+1], X[4*nodes[2]+2], 
	    X[4*nodes[3]+0], X[4*nodes[3]+1], X[4*nodes[3]+2], 
	    deviations[nodes[0]], deviations[nodes[1]], deviations[nodes[2]], deviations[nodes[3]]);
  }
  fprintf(fp, "};\n\n");
  fprintf(fp,"View[1].ColormapNumber = 14;\n");
  fprintf(fp,"View[1].IntervalsType = 1;\n");
  fprintf(fp,"View[1].RangeType = 2;\n");
  fprintf(fp,"View[1].CustomMax = 0.2;\n");
  fprintf(fp,"View[1].CustomMin = 0.2;\n");

  if (traceStreamlines) {
    /*  - streamlines starting from fans */
    HXTBbox bbox;
    hxtBboxInit(&bbox);
    hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);
    double maxDiag = -DBL_MAX;
    maxDiag = std::max(maxDiag, bbox.max[0] - bbox.min[0]);
    maxDiag = std::max(maxDiag, bbox.max[1] - bbox.min[1]);
    maxDiag = std::max(maxDiag, bbox.max[2] - bbox.min[2]);

    /* build rtree with tets */
    RTree<int, double, 3> tetRtree;
    buildTetRtree(mesh, tetRtree);

    /* One streamline from each fan edge */
    vector<vector<vec3> > streamlines;
    uint64_t tetGuess = NO_CELL;
    for (uint32_t i = 0; i < sFans.size() / 2; ++i) {
      vector<vec3> line;
      line.reserve(100);
      vec3 p1 = sFans[2*i+0];
      vec3 p2 = sFans[2*i+1];
      generateStreamLine(mesh, &vectors[0], tetGuess, tetRtree, p2.data, (p2-p1).data, 1.*maxDiag, line);
      if (line.size() >= 2) {
        streamlines.push_back(line);
      }
    }

    /* Export */
    printf("writing orientation field streamlines (from sing.) to \"%s\"\n", path);
    fprintf(fp, "View \"%s slines\" {\n", viewName);
    for (uint32_t l = 0; l < streamlines.size(); ++l) {
      writeLine(streamlines[l], fp, 0);
    }
    fprintf(fp, "};\n\n");
    fprintf(fp,"View[2].LineType = 0;\n");
    fprintf(fp,"View[2].LineWidth = 3;\n");
    printf("%li streamlines written.\n", streamlines.size());
  } 
  if (mesh->lines.num > 0) {
    /* - initial mesh lines */
    fprintf(fp, "View \"%s\" {\n", "mesh lines");
    for (uint64_t l = 0; l < mesh->lines.num; ++l) {
      const double* v1 = &(mesh->vertices.coord[4*mesh->lines.node[2*l+0]]);
      const double* v2 = &(mesh->vertices.coord[4*mesh->lines.node[2*l+1]]);
      fprintf(fp, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%f,%f};\n", 
          v1[0], v1[1], v1[2], 
          v2[0], v2[1], v2[2], 
          0., 0.);
    }
    fprintf(fp, "};\n\n");
    int viewNo = traceStreamlines ? 3 : 2;
    fprintf(fp,"View[%i].ColormapNumber = 0;\n",viewNo);
    fprintf(fp,"View[%i].LineType = 0;\n",viewNo);
    fprintf(fp,"View[%i].LineWidth = 3;\n",viewNo);
  }

  fclose(fp);

  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosCrossesFromFrames(const HXTMesh *mesh, const double *frames, const char *fileName, const char* viewName){

  double cross[9];
  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"Crosses\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"Cross\"{\n");
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    double *x = mesh->vertices.coord +4*i;
    const double *vertexFrame = frames+i*9;
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(vertexFrame, stableDir, cross);
    double color[3];
    for(int k=0;k<3;k++)
      color[k]=1.0;
    double quality=0.0;
    hxtOr3DcomputeQuality(vertexFrame,&quality);
    if(quality>0.25){
      for(int k=0; k<3; k++){
    	double val=stableDir[k]-0.9;
	(val<0)? color[k]=0.:color[k]=0.5;
      }
    }
    for (int j = 0; j < 3; ++j) {
      double d[3] = {cross[3*j+0], cross[3*j+1], cross[3*j+2]};
      if(j == 0){
        fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],color[j]/2.*d[0],color[j]/2.*d[1],color[j]/2.*d[2]);
        fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-color[j]/2.*d[0],-color[j]/2.*d[1],-color[j]/2.*d[2]);
    } else{
        fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],color[j]*d[0],color[j]*d[1],color[j]*d[2]);
        fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-color[j]*d[0],-color[j]*d[1],-color[j]*d[2]);
      }
    }
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

// HXTStatus hxtOr3DWritePosCrossesFromFrames(const HXTMesh *mesh, const double *frames, const char *fileName, const char* viewName){

//   double cross[9];
//   FILE* myfile = fopen(fileName,"w");
//   viewName==NULL ? fprintf(myfile,"View \"Crosses\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
//   // fprintf(myfile,"View \"Cross\"{\n");
//   for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
//     double *x = mesh->vertices.coord +4*i;
//     const double *vertexFrame = frames+i*9;
//     double stableDir[3]={0.0};
//     hxtOr3DframeToDirections(vertexFrame, stableDir, cross);
//     double color[3];
//     for(int k=0;k<3;k++)
//       color[k]=1.0;
//     double quality=0.0;
//     hxtOr3DcomputeQuality(vertexFrame,&quality);
//     if(quality>0.25){
//       for(int k=0; k<3; k++){
//     	double val=stableDir[k]-0.9;
//     	(val<0)? color[k]=0.0:color[k]=0.5;
//       }
//     }
//     for (int j = 0; j < 3; ++j) {
//       double d[3] = {cross[3*j+0], cross[3*j+1], cross[3*j+2]};
//       fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-color[j]*d[0]),(x[1]-color[j]*d[1]),(x[2]-color[j]*d[2]),(x[0]+color[j]*d[0]),(x[1]+color[j]*d[1]),(x[2]+color[j]*d[2]),1-color[j],1-color[j]);
//     }
//   }
//   fprintf(myfile,"};");
//   fclose(myfile);
//   return HXT_STATUS_OK;
// }

HXTStatus hxtOr3DWritePosNormals(const HXTMesh *mesh, const double *normals, const char *fileName, const char* viewName){
  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"Normals\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"Cross\"{\n");
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    double *x = mesh->vertices.coord +4*i;
    const double *vertexNormal = normals+i*3;
    double color[3];
    for(int k=0;k<3;k++)
      color[k]=1.0;
    double d[3] = {vertexNormal[0],vertexNormal[1],vertexNormal[2]};
    fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-color[0]*d[0]),(x[1]-color[0]*d[1]),(x[2]-color[0]*d[2]),(x[0]+color[0]*d[0]),(x[1]+color[0]*d[1]),(x[2]+color[0]*d[2]),1-color[0],1-color[0]);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosCrossesFromDirections(const HXTMesh *mesh, double *directions, const char *fileName, const char* viewName)
{

  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"Crosses\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"Cross\"{\n");
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
    double *x = mesh->vertices.coord +4*i;
    double *cross = directions+i*9;
    double color[3];
    for(int k=0;k<3;k++){
      hxtNorm2V(cross+3*k, 3, color+k);
    }
    for (int j = 0; j < 3; ++j) {
      double d[3] = {cross[3*j], cross[3*j+1], cross[3*j+2]};
      // fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-color[j]*d[0]),(x[1]-color[j]*d[1]),(x[2]-color[j]*d[2]),(x[0]+color[j]*d[0]),(x[1]+color[j]*d[1]),(x[2]+color[j]*d[2]),color[j],color[j]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],d[0],d[1],d[2]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
    }
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DWritePosCrossesFromDirectionsElem(const HXTMesh *mesh, double *directionsElem, const char *fileName, const char* viewName){
  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"Crosses\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"Cross\"{\n");
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    double x[3]={0.0};	  
    for (int k = 0; k < 4; ++k){
      for (int j = 0; j < 3; ++j)
	x[j]+=0.25*mesh->vertices.coord[4*mesh->tetrahedra.node[4*i+k]+j];
    }      
    double *cross = directionsElem+i*9;
    double color[3];
    for(int k=0;k<3;k++){
      hxtNorm2V(cross+3*k, 3, color+k);
    }
    for (int j = 0; j < 3; ++j) {
      double d[3] = {cross[3*j], cross[3*j+1], cross[3*j+2]};
      // fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-color[j]*d[0]),(x[1]-color[j]*d[1]),(x[2]-color[j]*d[2]),(x[0]+color[j]*d[0]),(x[1]+color[j]*d[1]),(x[2]+color[j]*d[2]),color[j],color[j]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],d[0],d[1],d[2]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
    }
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

// HXTStatus hxtOr3DWritePosCrossesFromDirections(const HXTMesh *mesh, double *directions, const char *fileName, const char* viewName)
// {

//   FILE* myfile = fopen(fileName,"w");
//   viewName==NULL ? fprintf(myfile,"View \"Crosses\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
//   // fprintf(myfile,"View \"Cross\"{\n");
//   for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
//     double *x = mesh->vertices.coord +4*i;
//     double *cross = directions+i*9;
//     double color[3];
//     for(int k=0;k<3;k++){
//       hxtNorm2V(cross+3*k, 3, color+k);
//     }
//     for (int j = 0; j < 3; ++j) {
//       double d[3] = {cross[3*j], cross[3*j+1], cross[3*j+2]};
//       // fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-color[j]*d[0]),(x[1]-color[j]*d[1]),(x[2]-color[j]*d[2]),(x[0]+color[j]*d[0]),(x[1]+color[j]*d[1]),(x[2]+color[j]*d[2]),color[j],color[j]);
//       fprintf(myfile,"SL(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g};\n",(x[0]-d[0]),(x[1]-d[1]),(x[2]-d[2]),(x[0]+d[0]),(x[1]+d[1]),(x[2]+d[2]),color[j],color[j]);
//     }
//   }
//   fprintf(myfile,"};");
//   fclose(myfile);
//   return HXT_STATUS_OK;
// }

HXTStatus hxtOr3DWritePosQuality(const HXTMesh *mesh, const double *directions, const char *fileName, const char* viewName)
{
  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"Crosses quality\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"constraint check\"{\n");
  double value=0.0;
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    double *x = mesh->vertices.coord + 4*i;
    // value = testConstraintVP(directions+9*i);
    hxtOr3DcomputeQuality(directions+9*i,&value);
    fprintf(myfile,"SP(%.16g,%.16g,%.16g){%.16g};\n",x[0],x[1],x[2],value);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DdrawSkin(HXTMesh *mesh, const char *fileName){

  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Skin\"{\n");
  for(uint64_t i = 0; i < mesh->triangles.num; ++i){
    double value=1.0;
    uint32_t *tri = mesh->triangles.node+i*3;

    double *x0 = mesh->vertices.coord + 4*tri[0];
    double *x1 = mesh->vertices.coord + 4*tri[1];
    double *x2 = mesh->vertices.coord + 4*tri[2];

    fprintf(myfile,"ST(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],value,value,value);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus hxtOr3DwritePosTriMesh(HXTMesh *mesh, double *scalarField, const char *fileName){
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Skin\"{\n");
  for (uint64_t i = 0; i < mesh->triangles.num; ++i) {
    uint32_t *tri = mesh->triangles.node+i*3;
    double value[3]={scalarField[tri[0]],scalarField[tri[1]],scalarField[tri[2]]};
    double *x0 = mesh->vertices.coord + 4*tri[0];
    double *x1 = mesh->vertices.coord + 4*tri[1];
    double *x2 = mesh->vertices.coord + 4*tri[2];
    fprintf(myfile,"ST(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],value[0],value[1],value[2]);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

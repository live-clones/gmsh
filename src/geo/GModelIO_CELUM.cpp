// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MQuadrangle.h"

class CelumInfo {
public:
  SVector3 normal, dirMax, dirMin;
  double curvMax, curvMin;
};

int GModel::writeCELUM(const std::string &name, bool saveAll,
                       double scalingFactor)
{
  std::string namef = name + "_f";
  FILE *fpf = Fopen(namef.c_str(), "w");
  if(!fpf) {
    Msg::Error("Unable to open file '%s'", namef.c_str());
    return 0;
  }

  std::string names = name + "_s";
  FILE *fps = Fopen(names.c_str(), "w");
  if(!fps) {
    Msg::Error("Unable to open file '%s'", names.c_str());
    fclose(fpf);
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // count faces and vertices; the CELUM format duplicates vertices on the
  // boundary of CAD patches
  int numf = 0, nums = 0;
  for(auto it = firstFace(); it != lastFace(); it++) {
    GFace *f = *it;
    if(!saveAll && f->physicals.empty()) continue;
    numf += f->triangles.size();
    std::set<MVertex *> vset;
    for(std::size_t i = 0; i < f->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) vset.insert(f->triangles[i]->getVertex(j));
    }
    nums += vset.size();
  }

  Msg::Info("Writing %d triangles and %d nodes", numf, nums);

  int idf = 1, ids = 1;
  /*
   * a file with faces
     - number of faces
     - empty line
     ... for each face
     - number of the face (starts at 1 : used for read errors)
     - char string (name of geom part, material,... )
     - list of 3 vertex nums
     - empty line
     ...
   * a file with vertices
     - number of vertices
     - conversion factor
     - empty line
     ... for each vertex
     - number of the vertex (starts at 1 : used for read errors)
     - cartesian coordinates of the vertex
     - componants of the exterior oriented normal
     - value of 1st principal curvature
     - value of second princpal curvature
     - components of 1st principal direction
     - components of 2nd principal direction
     - empty line
     ...
  */
  fprintf(fpf, "%d\n\n", numf);
  fprintf(fps, "%d %g\n\n", nums, 1.0);
  for(auto it = firstFace(); it != lastFace(); it++) {
    GFace *f = *it;
    if(!saveAll && f->physicals.empty()) continue;
    std::vector<MVertex *> vvec;
    std::map<MVertex *, CelumInfo> vmap;
    for(std::size_t i = 0; i < f->triangles.size(); i++) {
      fprintf(fpf, "%d \"face %d\"", idf++, f->tag());
      for(int j = 0; j < 3; j++) {
        MVertex *v = f->triangles[i]->getVertex(j);
        if(!vmap.count(v)) {
          v->setIndex(ids++);
          SPoint2 param;
          bool ok = reparamMeshVertexOnFace(v, f, param);
          if(!ok)
            Msg::Warning("Could not reparamtrize node %d on surface %d",
                         v->getNum(), f->tag());
          CelumInfo info;
          info.normal = f->normal(param);
          f->curvatures(param, info.dirMax, info.dirMin, info.curvMax,
                        info.curvMin);
          vmap[v] = info;
          vvec.push_back(v);
        }
        fprintf(fpf, " %ld", v->getIndex());
      }
      fprintf(fpf, "\n\n");
    }
    for(std::size_t i = 0; i < vvec.size(); i++) {
      MVertex *v = vvec[i];
      auto it = vmap.find(v);
      fprintf(fps, "%ld %g %g %g %g %g %g %g %g %g %g %g %g %g %g\n\n",
              it->first->getIndex(), it->first->x(), it->first->y(),
              it->first->z(), it->second.normal.x(), it->second.normal.y(),
              it->second.normal.z(), it->second.curvMin, it->second.curvMax,
              it->second.dirMin.x(), it->second.dirMin.y(),
              it->second.dirMin.z(), it->second.dirMax.x(),
              it->second.dirMax.y(), it->second.dirMax.z());
    }
  }

  fclose(fpf);
  fclose(fps);
  return 1;
}

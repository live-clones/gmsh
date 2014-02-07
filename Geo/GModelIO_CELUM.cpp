// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GModel.h"
#include "OS.h"
#include "MTriangle.h"
#include "MQuadrangle.h"

class CelumInfo{
public:
  SVector3 normal, dirMax, dirMin;
  double curvMax, curvMin;
};

int GModel::writeCELUM(const std::string &name, bool saveAll,
                       double scalingFactor)
{
  std::string namef = name + "_f";
  FILE *fpf = Fopen(namef.c_str(), "w");
  if(!fpf){
    Msg::Error("Unable to open file '%s'", namef.c_str());
    return 0;
  }

  std::string names = name + "_s";
  FILE *fps = Fopen(names.c_str(), "w");
  if(!fps){
    Msg::Error("Unable to open file '%s'", names.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  // count faces and vertices; the CELUM format duplicates vertices on the
  // boundary of CAD patches
  int numf = 0, nums = 0;
  for(fiter it = firstFace(); it != lastFace(); it++){
    GFace *f = *it;
    if(!saveAll && f->physicals.empty()) continue;
    numf += f->triangles.size();
    std::set<MVertex*> vset;
    for(unsigned int i = 0; i < f->triangles.size(); i++){
      for(int j = 0; j < 3; j++)
        vset.insert(f->triangles[i]->getVertex(j));
    }
    nums += vset.size();
  }

  Msg::Info("Writing %d triangles and %d vertices", numf, nums);

  int idf = 1, ids = 1;
  /*
   * un fichier de facettes
     - nombre de facettes
     - ligne vide
     ... pour chaque facette

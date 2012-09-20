// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "discreteFace.h"
#include "discreteRegion.h"

int GModel::readP3D(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "r");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numBlocks = 0;
  if(fscanf(fp, "%d", &numBlocks) != 1 || numBlocks <= 0) return 0;

  std::vector<int> Ni(numBlocks), Nj(numBlocks), Nk(numBlocks);
  for(int n = 0; n < numBlocks; n++)
    if(fscanf(fp, "%d %d %d", &Ni[n], &Nj[n], &Nk[n]) != 3) return 0;

  for(int n = 0; n < numBlocks; n++){
    if(Nk[n] == 1){
      GFace *gf = new discreteFace(this, getMaxElementaryNumber(2) + 1);
      add(gf);
      gf->transfinite_vertices.resize(Ni[n]);
      for(int i = 0; i < Ni[n]; i++)
        gf->transfinite_vertices[i].resize(Nj[n]);
      for(int coord = 0; coord < 3; coord++){
        for(int i = 0; i < Ni[n]; i++){
          for(int j = 0; j < Nj[n]; j++){
            double d;
            if(fscanf(fp, "%lf", &d) != 1) return 0;
            if(coord == 0){
              MVertex *v = new MVertex(d, 0., 0., gf);
              gf->transfinite_vertices[i][j] = v;
              gf->mesh_vertices.push_back(v);
            }
            else if(coord == 1){
              gf->transfinite_vertices[i][j]->y() = d;
            }
            else if(coord == 2){
              gf->transfinite_vertices[i][j]->z() = d;
            }
          }
        }
      }
      for(unsigned int i = 0; i < gf->transfinite_vertices.size() - 1; i++)
        for(unsigned int j = 0; j < gf->transfinite_vertices[0].size() - 1; j++)
          gf->quadrangles.push_back
            (new MQuadrangle(gf->transfinite_vertices[i    ][j    ],
                             gf->transfinite_vertices[i + 1][j    ],
                             gf->transfinite_vertices[i + 1][j + 1],
                             gf->transfinite_vertices[i    ][j + 1]));
    }
    else{
      GRegion *gr = new discreteRegion(this,  getMaxElementaryNumber(3) + 1);
      add(gr);
      gr->transfinite_vertices.resize(Ni[n]);
      for(int i = 0; i < Ni[n]; i++){
        gr->transfinite_vertices[i].resize(Nj[n]);
        for(int j = 0; j < Nj[n]; j++){
          gr->transfinite_vertices[i][j].resize(Nk[n]);
        }
      }
      for(int coord = 0; coord < 3; coord++){
        for(int i = 0; i < Ni[n]; i++){
          for(int j = 0; j < Nj[n]; j++){
            for(int k = 0; k < Nk[n]; k++){
              double d;
              if(fscanf(fp, "%lf", &d) != 1) return 0;
              if(coord == 0){
                MVertex *v = new MVertex(d, 0., 0., gr);
                gr->transfinite_vertices[i][j][k] = v;
                gr->mesh_vertices.push_back(v);
              }
              else if(coord == 1){
                gr->transfinite_vertices[i][j][k]->y() = d;
              }
              else if(coord == 2){
                gr->transfinite_vertices[i][j][k]->z() = d;
              }
            }
          }
        }
      }
      for(unsigned int i = 0; i < gr->transfinite_vertices.size() - 1; i++)
        for(unsigned int j = 0; j < gr->transfinite_vertices[0].size() - 1; j++)
          for(unsigned int k = 0; k < gr->transfinite_vertices[0][0].size() - 1; k++)
            gr->hexahedra.push_back
              (new MHexahedron(gr->transfinite_vertices[i    ][j    ][k    ],
                               gr->transfinite_vertices[i + 1][j    ][k    ],
                               gr->transfinite_vertices[i + 1][j + 1][k    ],
                               gr->transfinite_vertices[i    ][j + 1][k    ],
                               gr->transfinite_vertices[i    ][j    ][k + 1],
                               gr->transfinite_vertices[i + 1][j    ][k + 1],
                               gr->transfinite_vertices[i + 1][j + 1][k + 1],
                               gr->transfinite_vertices[i    ][j + 1][k + 1]));
    }
  }

  fclose(fp);
  return 1;
}

int GModel::writeP3D(const std::string &name, bool saveAll, double scalingFactor)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  if(noPhysicalGroups()) saveAll = true;

  std::vector<GFace*> faces;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((*it)->transfinite_vertices.size() &&
       (*it)->transfinite_vertices[0].size() &&
       ((*it)->physicals.size() || saveAll)) faces.push_back(*it);

  std::vector<GRegion*> regions;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((*it)->transfinite_vertices.size() &&
       (*it)->transfinite_vertices[0].size() &&
       (*it)->transfinite_vertices[0][0].size() &&
       ((*it)->physicals.size() || saveAll)) regions.push_back(*it);

  if(faces.empty() && regions.empty()){
    Msg::Warning("No structured grids to save");
    fclose(fp);
    return 0;
  }

  fprintf(fp, "%d\n", (int)(faces.size() + regions.size()));

  for(unsigned int i = 0; i < faces.size(); i++)
    fprintf(fp, "%d %d 1\n",
            (int)faces[i]->transfinite_vertices.size(),
            (int)faces[i]->transfinite_vertices[0].size());

  for(unsigned int i = 0; i < regions.size(); i++)
    fprintf(fp, "%d %d %d\n",
            (int)regions[i]->transfinite_vertices.size(),
            (int)regions[i]->transfinite_vertices[0].size(),
            (int)regions[i]->transfinite_vertices[0][0].size());

  for(unsigned int i = 0; i < faces.size(); i++){
    GFace *gf = faces[i];
    for(int coord = 0; coord < 3; coord++){
      for(unsigned int j = 0; j < gf->transfinite_vertices.size(); j++){
        for(unsigned int k = 0; k < gf->transfinite_vertices[j].size(); k++){
          MVertex *v = gf->transfinite_vertices[j][k];
          double d = (coord == 0) ? v->x() : (coord == 1) ? v->y() : v->z();
          fprintf(fp, "%.16g ", d * scalingFactor);
        }
        fprintf(fp, "\n");
      }
    }
  }

  for(unsigned int i = 0; i < regions.size(); i++){
    GRegion *gr = regions[i];
    for(int coord = 0; coord < 3; coord++){
      for(unsigned int j = 0; j < gr->transfinite_vertices.size(); j++){
        for(unsigned int k = 0; k < gr->transfinite_vertices[j].size(); k++){
          for(unsigned int l = 0; l < gr->transfinite_vertices[j][k].size(); l++){
            MVertex *v = gr->transfinite_vertices[j][k][l];
            double d = (coord == 0) ? v->x() : (coord == 1) ? v->y() : v->z();
            fprintf(fp, "%.16g ", d * scalingFactor);
          }
          fprintf(fp, "\n");
        }
      }
    }
  }

  fclose(fp);
  return 1;
}


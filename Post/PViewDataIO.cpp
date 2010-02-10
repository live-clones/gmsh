// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include <string.h>
#include "GmshMessage.h"
#include "Numeric.h"
#include "PViewData.h"

bool PViewData::writeSTL(std::string fileName)
{
  FILE *fp = fopen(fileName.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  if(!getNumTriangles() && !getNumQuadrangles()){
    Msg::Error("No surface elements to save");
    return false;
  }

  int step = 0;

  fprintf(fp, "solid Created by Gmsh\n");
  for(int ent = 0; ent < getNumEntities(step); ent++){
    for(int ele = 0; ele < getNumElements(step, ent); ele++){
      if(getDimension(step, ent, ele) != 2) continue;
      int N = getNumNodes(step, ent, ele);
      if(N != 3 && N != 4) continue;
      double x[4], y[4], z[4], n[3];
      for(int i = 0; i < N; i++)
        getNode(step, ent, ele, i, x[i], y[i], z[i]);
      normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      if(N == 3){
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]); 
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
      else{
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "    vertex %g %g %g\n", x[3], y[3], z[3]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
    }
  }
  fprintf(fp, "endsolid Created by Gmsh\n");
  
  fclose(fp);
  return true;
}

bool PViewData::writeTXT(std::string fileName)
{
  FILE *fp = fopen(fileName.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  for(int step = 0; step < getNumTimeSteps(); step++){  
    for(int ent = 0; ent < getNumEntities(step); ent++){
      for(int ele = 0; ele < getNumElements(step, ent); ele++){
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++){
          double x, y, z;
          getNode(step, ent, ele, nod, x, y, z);
          fprintf(fp, "%.16g %.16g %.16g ", x, y, z);
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++){   
            double val;
            getValue(step, ent, ele, nod, comp, val);
            fprintf(fp, "%.16g ", val);
          }
        }
        fprintf(fp, "\n");
      }
      fprintf(fp, "\n");
    }
    fprintf(fp, "\n");  
  }

  fclose(fp);
  return true;
}

bool PViewData::writePOS(std::string fileName, bool binary, bool parsed, bool append)
{ 
  Msg::Error("POS export not implemented for this view type");
  return false; 
}

bool PViewData::writeMSH(std::string fileName, bool binary)
{ 
  Msg::Error("MSH export not implemented for this view type");
  return false; 
}

bool PViewData::writeMED(std::string fileName)
{
  Msg::Error("MED export not implemented for this view type");
  return false; 
}

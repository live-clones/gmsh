// $Id: PViewDataIO.cpp,v 1.5 2008-03-19 16:38:16 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
// 

#include <string.h>
#include "Message.h"
#include "Numeric.h"
#include "PViewData.h"

bool PViewData::writeSTL(std::string name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  if(!getNumTriangles() && !getNumQuadrangles()){
    Msg(GERROR, "No surface elements to save");
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
	fprintf(fp, "    vertex %g %g %g\n", x[2], y[1], z[1]);
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

bool PViewData::writeTXT(std::string name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
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

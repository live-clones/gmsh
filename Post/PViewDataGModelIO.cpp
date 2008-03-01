// $Id: PViewDataGModelIO.cpp,v 1.2 2008-03-01 01:32:03 geuzaine Exp $
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
#include "PViewDataGModel.h"

/*
  if(!fgets(str, sizeof(str), fp)) return 0;
  // name = str[1] + remove final "
  int timeStep, numData, numComponents;
  double time;
  if(fscanf(fp, "%d %lf %d %d", &timeStep, &time, &numData, &numComponents) != 4)
    return 0;
  Msg(INFO, "%d node data", numData);
  fill in data
*/

bool PViewDataGModel::readMSH(FILE *fp)
{
  Msg(INFO, "Filling PViewDataGModel...");
  
  MVertex *v = _model->getMeshVertexByTag(10);
  if(v){
    printf("vertex 10 in mesh is %p\n", v);
  }

  finalize();
  return true;
}

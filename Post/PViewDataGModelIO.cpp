// $Id: PViewDataGModelIO.cpp,v 1.4 2008-03-09 14:47:32 geuzaine Exp $
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
#include "MVertex.h"
#include "Numeric.h"

bool PViewDataGModel::readMSH(FILE *fp, bool binary, bool swap, int timeStep, double time, 
			      int numComp, int numNodes)
{
  Msg(INFO, "Reading step %d (time %g): %d nodes", timeStep, time, numNodes);

  while(timeStep >= _nodeData.size()) _nodeData.push_back(0);

  if(!_nodeData[timeStep]) _nodeData[timeStep] = new stepData<double>();

  _nodeData[timeStep]->time = time;
  _nodeData[timeStep]->values.resize(numNodes);

  if(0 &&binary){
    Msg(GERROR, "not ready yet for binary");
    return 0;
  }
  else{
    for(int i = 0; i < numNodes; i++){
      int num;
      if(fscanf(fp, "%d", &num) != 1) return 0;
      MVertex *v = _model->getMeshVertexByTag(num);
      if(!v) return 0;
      if(v->getDataIndex() < 0){
	int max = _model->getMaxVertexDataIndex();
	_model->setMaxVertexDataIndex(max + 1);
	v->setDataIndex(max + 1);
      }
      int index = v->getDataIndex();
      if(index >= _nodeData[timeStep]->values.size())
	_nodeData[timeStep]->values.resize(index + 1);
      for(int j = 0; j < numComp; j++){
	double val;
	if(fscanf(fp, "%lf", &val) != 1) return 0;
	_nodeData[timeStep]->values[index].push_back(val);
      }
      double s = ComputeScalarRep(numComp, &_nodeData[timeStep]->values[index][0]);
      _nodeData[timeStep]->min = std::min(_nodeData[timeStep]->min, s);
      _nodeData[timeStep]->max = std::max(_nodeData[timeStep]->max, s);
    }
  }
  finalize();
  return true;
}

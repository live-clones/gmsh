// $Id: PViewDataGModelIO.cpp,v 1.7 2008-03-12 21:28:53 geuzaine Exp $
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
#include "StringUtils.h"

// Todo: slightly change this as follows:
// - always populate the _dataXX vector with stepData (for all time steps)
// - make the actual data allocatable (e.g. ptr to vector<vector>>)
// - only alloc data if...
//     - e.g. only alloc data for first time step
// in "skipElement": if no data, read it from file (using fileName/Index info
// in stepData) and free another if...
//
// usage should be as simple as: "gmsh *.pos". This would not load all
// time steps by default: only the 1st one(s). Then load/cache the
// others as needed on the fly.

bool PViewDataGModel::readMSH(std::string fileName, int fileIndex, FILE *fp,
			      bool binary, bool swap, int timeStep, double time, 
			      int partition, int numComp, int numNodes)
{
  Msg(INFO, "Reading step %d (time %g) partition %d: %d nodes", 
      timeStep, time, partition, numNodes);

  while(timeStep >= (int)_nodeData.size()) _nodeData.push_back(0);

  if(!_nodeData[timeStep]) _nodeData[timeStep] = new stepData<double>();

  _nodeData[timeStep]->fileName = fileName;
  _nodeData[timeStep]->fileIndex = fileIndex;
  _nodeData[timeStep]->time = time;
  _nodeData[timeStep]->values.resize(numNodes);

  std::vector<double> tmp(numComp, 0.);

  for(int i = 0; i < numNodes; i++){
    int num;
    if(binary){
      if(fread(&num, sizeof(int), 1, fp) != 1) return false;
      if(swap) swapBytes((char*)&num, sizeof(int), 1);
    }
    else{
      if(fscanf(fp, "%d", &num) != 1) return false;
    }
    MVertex *v = _model->getMeshVertexByTag(num);
    if(!v){
      Msg(GERROR, "Unknown vertex %d in data", num);
      return false;
    }
    if(v->getDataIndex() < 0){
      int max = _model->getMaxVertexDataIndex();
      _model->setMaxVertexDataIndex(max + 1);
      v->setDataIndex(max + 1);
    }
    int index = v->getDataIndex();
    if(index >= (int)_nodeData[timeStep]->values.size())
      _nodeData[timeStep]->values.resize(index + 100); // optimize this
    if(binary){
      if((int)fread(&tmp[0], sizeof(double), numComp, fp) != numComp) return false;
      if(swap) swapBytes((char*)&tmp[0], sizeof(double), numComp);
    }
    else{
      for(int j = 0; j < numComp; j++)
	if(fscanf(fp, "%lf", &tmp[j]) != 1) return false;
    }
    for(int j = 0; j < numComp; j++)
      _nodeData[timeStep]->values[index].push_back(tmp[j]);
    double s = ComputeScalarRep(numComp, &_nodeData[timeStep]->values[index][0]);
    _nodeData[timeStep]->min = std::min(_nodeData[timeStep]->min, s);
    _nodeData[timeStep]->max = std::max(_nodeData[timeStep]->max, s);
  }

  _partitions.insert(partition);

  finalize();
  return true;
}

bool PViewDataGModel::writeMSH(std::string name, bool binary)
{
  binary = true;

  bool saveAll = true;
  if(!_model->writeMSH(name, 2.0, binary, saveAll)) return false;

  // append data
  FILE *fp = fopen(name.c_str(), binary ? "ab" : "a");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  // map data index to vertex tags
  std::vector<int> tags(_model->getMaxVertexDataIndex() + 1, 0);
  for(unsigned int i = 0; i < _entities.size(); i++){
    for(unsigned int j = 0; j < _entities[i]->mesh_vertices.size(); j++){
      MVertex *v = _entities[i]->mesh_vertices[j];
      if(v->getDataIndex() >= 0) tags[v->getDataIndex()] = v->getNum();
    }
  }

  for(unsigned int ts = 0; ts < _nodeData.size(); ts++){
    if(!_nodeData[ts]) continue;
    int numNodes = 0, numComp = 100;
    for(unsigned int i = 0; i < _nodeData[ts]->values.size(); i++){
      if(_nodeData[ts]->values[i].size()){
	numComp = std::min(numComp, (int)_nodeData[ts]->values[i].size());
	numNodes++;
      }
    }
    if(numNodes && numComp){
      fprintf(fp, "$NodeData\n");
      fprintf(fp, "\"%s\"\n", getName().c_str());
      fprintf(fp, "%d %.16g 0 0 %d %d\n", ts, _nodeData[ts]->time, numComp, numNodes);
      for(unsigned int i = 0; i < _nodeData[ts]->values.size(); i++){
	if((int)_nodeData[ts]->values[i].size() >= numComp){
	  if(binary){
	    fwrite(&tags[i], sizeof(int), 1, fp);
	    fwrite(&_nodeData[ts]->values[i][0], sizeof(double), numComp, fp);
	  }
	  else{
	    fprintf(fp, "%d", tags[i]);
	    for(int k = 0; k < numComp; k++)
	      fprintf(fp, " %.16g", _nodeData[ts]->values[i][k]);
	    fprintf(fp, "\n");
	  }
	}
      }
      if(binary) fprintf(fp, "\n");
      fprintf(fp, "$EndNodeData\n");
    }
  }
    
  fclose(fp);
  return true;
}

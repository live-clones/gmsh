// $Id: PViewDataGModelIO.cpp,v 1.13 2008-03-25 20:48:32 geuzaine Exp $
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

bool PViewDataGModel::readMSH(std::string fileName, int fileIndex, FILE *fp,
                              bool binary, bool swap, int step, double time, 
                              int partition, int numComp, int numNodes)
{
  Msg(INFO, "Reading step %d (time %g) partition %d: %d nodes", 
      step, time, partition, numNodes);

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(GModel::current(), 
                                          stepData<double>::NodeData, numComp));
  
  _steps[step]->setFileName(fileName);
  _steps[step]->setFileIndex(fileIndex);
  _steps[step]->setTime(time);

  // if we already have maxSteps for this view, return
  int numSteps = 0, maxSteps = 1000000000;
  for(unsigned int i = 0; i < _steps.size(); i++)
    numSteps += _steps[i]->getNumData() ? 1 : 0;
  if(numSteps > maxSteps) return true;

  _steps[step]->resizeData(numNodes);

  for(int i = 0; i < numNodes; i++){
    int num;
    if(binary){
      if(fread(&num, sizeof(int), 1, fp) != 1) return false;
      if(swap) swapBytes((char*)&num, sizeof(int), 1);
    }
    else{
      if(fscanf(fp, "%d", &num) != 1) return false;
    }
    MVertex *v = _steps[step]->getModel()->getMeshVertexByTag(num);
    if(!v){
      Msg(GERROR, "Unknown vertex %d in data", num);
      return false;
    }
    if(v->getDataIndex() < 0){
      int max = _steps[step]->getModel()->getMaxVertexDataIndex();
      _steps[step]->getModel()->setMaxVertexDataIndex(max + 1);
      v->setDataIndex(max + 1);
    }
    int index = v->getDataIndex();
    double *d = _steps[step]->getData(index, true);
    if(binary){
      if((int)fread(d, sizeof(double), numComp, fp) != numComp) return false;
      if(swap) swapBytes((char*)d, sizeof(double), numComp);
    }
    else{
      for(int j = 0; j < numComp; j++)
        if(fscanf(fp, "%lf", &d[j]) != 1) return false;
    }
    double s = ComputeScalarRep(numComp, d);
    _steps[step]->setMin(std::min(_steps[step]->getMin(), s));
    _steps[step]->setMax(std::max(_steps[step]->getMax(), s));
  }

  _partitions.insert(partition);

  finalize();
  return true;
}

bool PViewDataGModel::writeMSH(std::string name, bool binary)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg(GERROR, "Export not done for multi-mesh views");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  binary = true;

  if(!model->writeMSH(name, 2.0, binary, true)) return false;

  // append data
  FILE *fp = fopen(name.c_str(), binary ? "ab" : "a");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  // map data index to vertex tags
  std::vector<int> tags(model->getMaxVertexDataIndex() + 1, 0);
  for(int i = 0; i < _steps[0]->getNumEntities(); i++){
    for(unsigned int j = 0; j < _steps[0]->getEntity(i)->mesh_vertices.size(); j++){
      MVertex *v = _steps[0]->getEntity(i)->mesh_vertices[j];
      if(v->getDataIndex() >= 0) tags[v->getDataIndex()] = v->getNum();
    }
  }

  for(unsigned int step = 0; step < _steps.size(); step++){
    int numNodes = 0, numComp = _steps[step]->getNumComp();
    for(int i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) numNodes++;
    if(numNodes){
      fprintf(fp, "$NodeData\n");
      fprintf(fp, "\"%s\"\n", getName().c_str());
      fprintf(fp, "%d %.16g 0 0 %d %d\n", step, _steps[step]->getTime(), 
              numComp, numNodes);
      for(int i = 0; i < _steps[step]->getNumData(); i++){
        if(_steps[step]->getData(i)){
          if(binary){
            fwrite(&tags[i], sizeof(int), 1, fp);
            fwrite(_steps[step]->getData(i), sizeof(double), numComp, fp);
          }
          else{
            fprintf(fp, "%d", tags[i]);
            for(int k = 0; k < numComp; k++)
              fprintf(fp, " %.16g", _steps[step]->getData(i)[k]);
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

bool PViewDataGModel::writeMED(std::string name)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg(GERROR, "Export not done for multi-mesh views");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  //  if(!model->writeMSH(name, 2.0, binary, true)) return false;

  // append data
  FILE *fp = fopen(name.c_str(), "ab");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  // map data index to vertex tags
  std::vector<int> tags(model->getMaxVertexDataIndex() + 1, 0);
  for(int i = 0; i < _steps[0]->getNumEntities(); i++){
    for(unsigned int j = 0; j < _steps[0]->getEntity(i)->mesh_vertices.size(); j++){
      MVertex *v = _steps[0]->getEntity(i)->mesh_vertices[j];
      if(v->getDataIndex() >= 0) tags[v->getDataIndex()] = v->getNum();
    }
  }

  for(unsigned int step = 0; step < _steps.size(); step++){
    int numNodes = 0, numComp = _steps[step]->getNumComp();
    for(int i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) numNodes++;

    if(numNodes){
      /*
      fprintf(fp, "$NodeData\n");
      fprintf(fp, "\"%s\"\n", getName().c_str());
      fprintf(fp, "%d %.16g 0 0 %d %d\n", step, _steps[step]->getTime(), 
              numComp, numNodes);
      for(int i = 0; i < _steps[step]->getNumData(); i++){
        if(_steps[step]->getData(i)){
          fprintf(fp, "%d", tags[i]);
          for(int k = 0; k < numComp; k++)
            fprintf(fp, " %.16g", _steps[step]->getData(i)[k]);
          fprintf(fp, "\n");
        }
      }
      fprintf(fp, "$EndNodeData\n");
      */
    }
  }
    
  fclose(fp);
  return true;
}

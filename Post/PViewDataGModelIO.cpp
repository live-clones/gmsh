// $Id: PViewDataGModelIO.cpp,v 1.15 2008-03-29 11:51:37 geuzaine Exp $
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

bool PViewDataGModel::writeMSH(std::string fileName, bool binary)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg(GERROR, "Export not done for multi-mesh views");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  binary = true;

  if(!model->writeMSH(fileName, 2.0, binary, true)) return false;

  // append data
  FILE *fp = fopen(fileName.c_str(), binary ? "ab" : "a");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
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

#if defined(HAVE_MED)

extern "C" {
#include <med.h>
}

bool PViewDataGModel::readMED(std::string fileName, int fileIndex)
{
  med_idt fid = MEDouvrir((char*)fileName.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
    return false;
  }
  
  med_int numComp = MEDnChamp(fid, fileIndex + 1);
  if(numComp <= 0){
    Msg(GERROR, "Could not get number of components for MED field");
    return false;
  }

  char name[MED_TAILLE_NOM + 1];
  std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
  std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
  med_type_champ type;
  if(MEDchampInfo(fid, fileIndex + 1, name, &type, &compName[0], &compUnit[0], 
		  numComp) < 0){
    Msg(GERROR, "Could not get MED field info");
    return false;
  }

  Msg(INFO, "Reading %d-component field <<%s>>\n", numComp, name);
  setName(name);

  med_int numSteps = MEDnPasdetemps(fid, name, MED_NOEUD, MED_NONE);
  if(numSteps < 0){
    Msg(GERROR, "Could not get number of steps");
    return false;
  }

  for(int step = 0; step < numSteps; step++){
    med_int numdt, numo, ngauss, numMeshes;
    char dtunit[MED_TAILLE_PNOM +1], meshName[MED_TAILLE_NOM + 1];
    med_float dt;
    med_booleen local;
    if(MEDpasdetempsInfo(fid, name, MED_NOEUD, MED_NONE, step + 1, 
			 &ngauss, &numdt, &numo, dtunit, &dt, meshName,
			 &local, &numMeshes) < 0){
      Msg(GERROR, "Could not get step info");
      return false;
    }

    med_int numNodes = MEDnVal(fid, name, MED_NOEUD, MED_NONE, numdt, numo, 
			       meshName, MED_COMPACT);
    if(numNodes <= 0) continue;

    std::vector<double> val(numNodes * numComp);
    char locname[MED_TAILLE_NOM + 1], profileName[MED_TAILLE_NOM + 1];
    if(MEDchampLire(fid, meshName, name, (unsigned char*)&val[0], MED_FULL_INTERLACE,
		    MED_ALL, locname, profileName, MED_COMPACT, MED_NOEUD, MED_NONE, 
		    numdt, numo) < 0){
      Msg(GERROR, "Could not get field values");
      return false;
    }

    int numCompGmsh = (numComp == 2) ? 3 : numComp;
    stepData<double> *sd = new stepData<double>
      (GModel::current(), stepData<double>::NodeData, numCompGmsh);
    _steps.push_back(sd);
    sd->setFileName(fileName);
    sd->setFileIndex(fileIndex);
    sd->setTime(dt);
    sd->resizeData(numNodes);

    std::vector<med_int> nodeTags(numNodes);
    if(MEDnumLire(fid, meshName, &nodeTags[0], numNodes, MED_NOEUD, MED_NONE) < 0)
      nodeTags.clear();

    std::vector<med_int> profile;
    if(std::string(profileName) != MED_NOPFL){
      med_int n = MEDnValProfil(fid, profileName);
      if(n > 0){
	profile.resize(n);
	if(MEDprofilLire(fid, &profile[0], profileName) < 0){
	  Msg(GERROR, "Could not read profile");
	  return false;
	}
      }
    }
    if(profile.empty()){
      profile.resize(numNodes);
      for(int i = 0; i < numNodes; i++)
	profile[i] = i + 1;
    }
    
    for(unsigned int i = 0; i < profile.size(); i++){
      int num = nodeTags.empty() ? profile[i] : nodeTags[profile[i] - 1];
      MVertex *v = sd->getModel()->getMeshVertexByTag(num);
      if(!v){
	Msg(GERROR, "Unknown vertex %d in data", num);
	return false;
      }
      if(v->getDataIndex() < 0){
	int max = sd->getModel()->getMaxVertexDataIndex();
	sd->getModel()->setMaxVertexDataIndex(max + 1);
	v->setDataIndex(max + 1);
      }
      int index = v->getDataIndex();
      double *d = sd->getData(index, true);
      for(int j = 0; j < numComp; j++)
        d[j] = val[numComp * i + j];
      for(int j = numComp; j < numCompGmsh; j++)
        d[j] = 0.;
      double s = ComputeScalarRep(numCompGmsh, d);
      sd->setMin(std::min(sd->getMin(), s));
      sd->setMax(std::max(sd->getMax(), s));
    }
  }
  
  finalize();

  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)fileName.c_str());
    return false;
  }
  return true;
}

bool PViewDataGModel::writeMED(std::string fileName)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg(GERROR, "Export not done for multi-mesh views");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  // save the mesh
  if(!model->writeMED(fileName, true)) return false;

  char *meshName = (char*)model->getName().c_str();
  char *fieldName = (char*)getName().c_str();

  med_idt fid = MEDouvrir((char*)fileName.c_str(), MED_LECTURE_AJOUT);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
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

  // compute profile
  std::vector<med_int> prof;
  for(int i = 0; i < _steps[0]->getNumData(); i++){
    if(_steps[0]->getData(i))
      prof.push_back(tags[i]);
  }
  char *profileName = (char*)"nodeProfile";
  if(MEDprofilEcr(fid, &prof[0], (med_int)prof.size(), profileName) < 0){
    Msg(GERROR, "Could not create MED profile");
    return false;
  }

  int numComp = _steps[0]->getNumComp();
  if(MEDchampCr(fid, fieldName, MED_FLOAT64, (char*)"unknown", (char*)"unknown",
		(med_int)numComp) < 0){
    Msg(GERROR, "Could not create MED field");
    return false;
  }

  med_int numNodes = MEDnEntMaa(fid, meshName, MED_COOR, MED_NOEUD, 
				MED_NONE, (med_connectivite)0);
  if(numNodes <= 0){
    Msg(GERROR, "Could not get valid number of nodes in mesh");
    return false;
  }

  for(unsigned int step = 0; step < _steps.size(); step++){
    unsigned int n = 0;
    for(int i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) n++;
    if(n != prof.size() || numComp != _steps[step]->getNumComp()){
      Msg(GERROR, "Skipping incompatible step");
      continue;
    }
    double time = _steps[step]->getTime();
    std::vector<double> val(numNodes * numComp);
    for(int i = 0; i < _steps[step]->getNumData(); i++){
      if(_steps[step]->getData(i)){
	for(int k = 0; k < numComp; k++)
	  val[i * numComp + k] = _steps[step]->getData(i)[k];
      }
    }
    if(MEDchampEcr(fid, meshName, fieldName, (unsigned char*)&val[0], 
		   MED_FULL_INTERLACE, numNodes, MED_NOGAUSS, MED_ALL,
		   profileName, MED_COMPACT, MED_NOEUD, MED_NONE, (med_int)step,
		   (char*)"unknown", time, MED_NONOR) < 0) {
      Msg(GERROR, "Could not write MED field");
      return false;
    }
  }
  
  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)fileName.c_str());
    return false;
  }
  return true;
}

#else

bool PViewDataGModel::readMED(std::string fileName, int fileIndex)
{
  Msg(GERROR, "Gmsh must be compiled with MED support to read '%s'", 
      fileName.c_str());
  return false;
}

bool PViewDataGModel::writeMED(std::string fileName)
{
  Msg(GERROR, "Gmsh must be compiled with MED support to write '%s'",
      fileName.c_str());
  return false;
}

#endif

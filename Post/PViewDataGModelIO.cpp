// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"
#include "StringUtils.h"

bool PViewDataGModel::addData(GModel *model, std::map<int, std::vector<double> > &data,
                              int step, double time, int partition, int numComp)
{
  if(data.empty()) return false;

  if (numComp < 0){
    numComp = 9;
    for(std::map<int, std::vector<double> >::iterator it = data.begin();
        it != data.end(); it++)
      numComp = std::min(numComp, (int)it->second.size());
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));

  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
    model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  for(std::map<int, std::vector<double> >::iterator it = data.begin();
      it != data.end(); it++){
    int mult = it->second.size() / numComp;
    double *d  = _steps[step]->getData(it->first, true, mult);
    for(int j = 0; j < numComp * mult; j++)
      d[j] = it->second[j];
  }
  if(partition >= 0)
    _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

bool PViewDataGModel::readMSH(std::string fileName, int fileIndex, FILE *fp,
                              bool binary, bool swap, int step, double time,
                              int partition, int numComp, int numEnt)
{
  Msg::Info("Reading step %d (time %g) partition %d: %d records",
            step, time, partition, numEnt);

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(GModel::current(), numComp));

  _steps[step]->setFileName(fileName);
  _steps[step]->setFileIndex(fileIndex);
  _steps[step]->setTime(time);

  // if we already have maxSteps for this view, return
  int numSteps = 0, maxSteps = 1000000000;
  for(unsigned int i = 0; i < _steps.size(); i++)
    numSteps += _steps[i]->getNumData() ? 1 : 0;
  if(numSteps > maxSteps) return true;

  _steps[step]->resizeData(numEnt);

  Msg::ResetProgressMeter();
  for(int i = 0; i < numEnt; i++){
    int num;
    if(binary){
      if(fread(&num, sizeof(int), 1, fp) != 1) return false;
      if(swap) SwapBytes((char*)&num, sizeof(int), 1);
    }
    else{
      if(fscanf(fp, "%d", &num) != 1) return false;
    }
    int mult = 1;
    if(_type == ElementNodeData || _type == GaussPointData){
      if(binary){
        if(fread(&mult, sizeof(int), 1, fp) != 1) return false;
        if(swap) SwapBytes((char*)&mult, sizeof(int), 1);
      }
      else{
        if(fscanf(fp, "%d", &mult) != 1) return false;
      }
    }
    double *d = _steps[step]->getData(num, true, mult);
    if(binary){
      if((int)fread(d, sizeof(double), numComp * mult, fp) != numComp * mult)
        return false;
      if(swap) SwapBytes((char*)d, sizeof(double), numComp * mult);
    }
    else{
      for(int j = 0; j < numComp * mult; j++)
        if(fscanf(fp, "%lf", &d[j]) != 1) return false;
    }
    // compute min/max here to avoid calling finalize(true) later:
    // this would be very slow for large multi-step, multi-partition
    // datasets (since we would recompute the min/max for all the
    // previously loaded steps/partitions, and thus loop over all the
    // elements many times)
    for(int j = 0; j < mult; j++){
      double val = ComputeScalarRep(numComp, &d[numComp * j]);
      _steps[step]->setMin(std::min(_steps[step]->getMin(), val));
      _steps[step]->setMax(std::max(_steps[step]->getMax(), val));
      _min = std::min(_min, val);
      _max = std::max(_max, val);
    }
    if(numEnt > 100000)
      Msg::ProgressMeter(i + 1, numEnt, "Reading data");
  }

  if(partition >= 0)
    _steps[step]->getPartitions().insert(partition);

  finalize(false);
  return true;
}

bool PViewDataGModel::writeMSH(std::string fileName, bool binary, bool savemesh)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg::Error("Export not done for multi-mesh views");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  bool writeNodesAndElements = savemesh;
  FILE *fp;
  if(writeNodesAndElements){
    if(!model->writeMSH(fileName, 2.0, binary)) return false;
    // append data
    fp = fopen(fileName.c_str(), binary ? "ab" : "a");
    if(!fp){
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return false;
    }
  }
  else{
    fp = fopen(fileName.c_str(), binary ? "wb" : "w");
    if(!fp){
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return false;
    }
    fprintf(fp, "$MeshFormat\n");
    fprintf(fp, "%g %d %d\n", 2.2, binary ? 1 : 0, (int)sizeof(double));
    if(binary){
      int one = 1;
      fwrite(&one, sizeof(int), 1, fp);
      fprintf(fp, "\n");
    }
    fprintf(fp, "$EndMeshFormat\n");
  }

  for(unsigned int step = 0; step < _steps.size(); step++){
    int numEnt = 0, numComp = _steps[step]->getNumComponents();
    for(int i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) numEnt++;
    if(numEnt){
      if(_type == NodeData){
        fprintf(fp, "$NodeData\n");
        fprintf(fp, "1\n\"%s\"\n", getName().c_str());
        fprintf(fp, "1\n%.16g\n", _steps[step]->getTime());
        fprintf(fp, "3\n%d\n%d\n%d\n", step, numComp, numEnt);
        for(int i = 0; i < _steps[step]->getNumData(); i++){
          if(_steps[step]->getData(i)){
            MVertex *v = _steps[step]->getModel()->getMeshVertexByTag(i);
            if(!v){
              Msg::Error("Unknown vertex %d in data", i);
              return false;
            }
            int num = v->getIndex();
            if(binary){
              fwrite(&num, sizeof(int), 1, fp);
              fwrite(_steps[step]->getData(i), sizeof(double), numComp, fp);
            }
            else{
              fprintf(fp, "%d", num);
              for(int k = 0; k < numComp; k++)
                fprintf(fp, " %.16g", _steps[step]->getData(i)[k]);
              fprintf(fp, "\n");
            }
          }
        }
        if(binary) fprintf(fp, "\n");
        fprintf(fp, "$EndNodeData\n");
      }
      else{
        if(_type == ElementNodeData)
          fprintf(fp, "$ElementNodeData\n");
        else
          fprintf(fp, "$ElementData\n");
        fprintf(fp, "1\n\"%s\"\n", getName().c_str());
        fprintf(fp, "1\n%.16g\n", _steps[step]->getTime());
        fprintf(fp, "3\n%d\n%d\n%d\n", step, numComp, numEnt);
        for(int i = 0; i < _steps[step]->getNumData(); i++){
          if(_steps[step]->getData(i)){
            MElement *e = model->getMeshElementByTag(i);
            if(!e){
              Msg::Error("Unknown element %d in data", i);
              return false;
            }
            int mult = _steps[step]->getMult(i);
            int num = model->getMeshElementIndex(e);
            if(binary){
              fwrite(&num, sizeof(int), 1, fp);
              if(_type == ElementNodeData)
                fwrite(&mult, sizeof(int), 1, fp);
              fwrite(_steps[step]->getData(i), sizeof(double), numComp * mult, fp);
            }
            else{
              fprintf(fp, "%d", num);
              if(_type == ElementNodeData)
                fprintf(fp, " %d", mult);
              for(int k = 0; k < numComp * mult; k++)
                fprintf(fp, " %.16g", _steps[step]->getData(i)[k]);
              fprintf(fp, "\n");
            }
          }
        }
        if(binary) fprintf(fp, "\n");
        if(_type == ElementNodeData)
          fprintf(fp, "$EndElementNodeData\n");
        else
          fprintf(fp, "$EndElementData\n");
      }
    }
  }

  fclose(fp);
  return true;
}

#if defined(HAVE_MED)

extern "C" {
#include <med.h>
}

extern int med2mshElementType(med_geometrie_element med);
extern int med2mshNodeIndex(med_geometrie_element med, int k);

bool PViewDataGModel::readMED(std::string fileName, int fileIndex)
{
  med_idt fid = MEDouvrir((char*)fileName.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  med_int numComp = MEDnChamp(fid, fileIndex + 1);
  if(numComp <= 0){
    Msg::Error("Could not get number of components for MED field");
    return false;
  }

  char name[MED_TAILLE_NOM + 1];
  std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
  std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
  med_type_champ type;
  if(MEDchampInfo(fid, fileIndex + 1, name, &type, &compName[0], &compUnit[0],
                  numComp) < 0){
    Msg::Error("Could not get MED field info");
    return false;
  }

  Msg::Info("Reading %d-component field <<%s>>", numComp, name);
  setName(name);

  int numCompMsh =
    (numComp <= 1) ? 1 : (numComp <= 3) ? 3 : (numComp <= 9) ? 9 : numComp;

  if(numCompMsh > 9) Msg::Warning("More than 9 components in field");

  // Warning! The ordering of the elements in the last two lists is
  // important: it should match the ordering of the MSH element types
  // (when elements are saved without tags, this governs the order
  // with which we implicitly index them in GModel::readMED)
  const med_entite_maillage entType[] =
    {MED_NOEUD, MED_MAILLE, MED_NOEUD_MAILLE};
  const med_geometrie_element eleType[] =
    {MED_NONE, MED_SEG2, MED_TRIA3, MED_QUAD4, MED_TETRA4, MED_HEXA8,
     MED_PENTA6, MED_PYRA5, MED_SEG3, MED_TRIA6, MED_TETRA10,
     MED_POINT1, MED_QUAD8, MED_HEXA20, MED_PENTA15, MED_PYRA13};
  const int nodesPerEle[] =
    {0, 2, 3, 4, 4, 8, 6, 5, 3, 6, 10, 1, 8, 20, 15, 13};

  med_int numSteps = 0;
  std::vector<std::pair<int, int> > pairs;
  for(unsigned int i = 0; i < sizeof(entType) / sizeof(entType[0]); i++){
    for(unsigned int j = 0; j < sizeof(eleType) / sizeof(eleType[0]); j++){
      med_int n = MEDnPasdetemps(fid, name, entType[i], eleType[j]);
      if(n > 0){
        pairs.push_back(std::pair<int, int>(i, j));
        numSteps = std::max(numSteps, n);
      }
      if(!i && !j) break; // MED_NOEUD does not care about eleType
    }
  }

  if(numSteps < 1 || pairs.empty()){
    Msg::Error("Nothing to import from MED file");
    return false;
  }
  else{
    med_entite_maillage ent = entType[pairs[0].first];
    _type = (ent == MED_NOEUD) ? NodeData : (ent == MED_MAILLE) ? ElementData :
      ElementNodeData;
  }

  for(int step = 0; step < numSteps; step++){
    for(unsigned int pair = 0; pair < pairs.size(); pair++){
      // get step info
      med_entite_maillage ent = entType[pairs[pair].first];
      med_geometrie_element ele = eleType[pairs[pair].second];
      med_int numdt, numo, ngauss, numMeshes;
      char dtunit[MED_TAILLE_PNOM + 1], meshName[MED_TAILLE_NOM + 1];
      med_float dt;
      med_booleen local;
      if(MEDpasdetempsInfo(fid, name, ent, ele, step + 1, &ngauss, &numdt, &numo,
                           dtunit, &dt, meshName, &local, &numMeshes) < 0){
        Msg::Error("Could not read step info");
        return false;
      }

      // create step data
      if(!pair){
        GModel *m = GModel::findByName(meshName);
        if(!m){
          Msg::Error("Could not find mesh <<%s>>", meshName);
          return false;
        }
        while(step >= (int)_steps.size())
          _steps.push_back(new stepData<double>(m, numCompMsh));
        _steps[step]->setFileName(fileName);
        _steps[step]->setFileIndex(fileIndex);
        _steps[step]->setTime(dt);
      }

      // get number of values in the field (numVal takes the number of
      // Gauss points or the number of nodes per element into account,
      // but not the number of components)
      med_int numVal = MEDnVal(fid, name, ent, ele, numdt, numo, meshName,
                               MED_COMPACT);
      if(numVal <= 0) continue;
      int mult = 1;
      if(ent == MED_NOEUD_MAILLE){
        mult = nodesPerEle[pairs[pair].second];
      }
      else if(ngauss != MED_NOPG){
        mult = ngauss;
        _type = GaussPointData;
      }
      _steps[step]->resizeData(numVal / mult);

      // read field data
      std::vector<double> val(numVal * numComp);
      char locname[MED_TAILLE_NOM + 1], profileName[MED_TAILLE_NOM + 1];
      if(MEDchampLire(fid, meshName, name, (unsigned char*)&val[0], MED_FULL_INTERLACE,
                      MED_ALL, locname, profileName, MED_COMPACT, ent, ele,
                      numdt, numo) < 0){
        Msg::Error("Could not read field values");
        return false;
      }

      // read Gauss point data
      if(_type == GaussPointData){
        std::vector<double> &p(_steps[step]->getGaussPoints(med2mshElementType(ele)));
        if(std::string(locname) == MED_GAUSS_ELNO){
          // hack: the points are the vertices
          p.resize(ngauss * 3, 1.e22);
        }
        else{
          int dim = ele / 100;
          std::vector<med_float> refcoo((ele % 100) * dim);
          std::vector<med_float> gscoo(ngauss * dim);
          std::vector<med_float> wg(ngauss);
          if(MEDgaussLire(fid, &refcoo[0], &gscoo[0], &wg[0], MED_FULL_INTERLACE,
                          locname) < 0){
            Msg::Error("Could not read Gauss points");
            return false;
          }
          // FIXME: we should check that refcoo corresponds to our
          // internal reference element
          for(int i = 0; i < (int)gscoo.size(); i++){
            p.push_back(gscoo[i]);
            if(i % dim == dim - 1) for(int j = 0; j < 3 - dim; j++) p.push_back(0.);
          }
        }
      }

      // compute profile (indices in full array of entities of given type)
      std::vector<med_int> profile;
      if(std::string(profileName) != MED_NOPFL){
        med_int n = MEDnValProfil(fid, profileName);
        if(n > 0){
          profile.resize(n);
          if(MEDprofilLire(fid, &profile[0], profileName) < 0){
            Msg::Error("Could not read profile");
            return false;
          }
        }
      }
      if(profile.empty()){
        profile.resize(numVal / mult);
        for(unsigned int i = 0; i < profile.size(); i++)
          profile[i] = i + 1;
      }

      // get size of full array and tags (if any) of entities
      bool nodal = (ent == MED_NOEUD);
      med_int numEnt = MEDnEntMaa(fid, meshName, nodal ? MED_COOR : MED_CONN,
                                  nodal ? MED_NOEUD : MED_MAILLE,
                                  nodal ? MED_NONE : ele,
                                  nodal ? (med_connectivite)0 : MED_NOD);
      std::vector<med_int> tags(numEnt);
      if(MEDnumLire(fid, meshName, &tags[0], numEnt, nodal ? MED_NOEUD : MED_MAILLE,
                    nodal ? MED_NONE : ele) < 0)
        tags.clear();

      // if we don't have tags, compute the starting index (i.e., how
      // many elements of different type are in the mesh before these
      // ones)
      int startIndex = 0;
      if(!nodal && tags.empty()){
        for(int i = 1; i < pairs[pair].second; i++){
          med_int n = MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE,
                                 eleType[i], MED_NOD);
          if(n > 0) startIndex += n;
        }
      }

      // compute entity numbers using profile, then fill step data
      for(unsigned int i = 0; i < profile.size(); i++){
        int num;
        if(tags.empty()){
          num = startIndex + profile[i];
        }
        else{
          if(profile[i] == 0 || profile[i] > (int)tags.size()){
            Msg::Error("Wrong index in profile");
            return false;
          }
          num = tags[profile[i] - 1];
        }
        double *d = _steps[step]->getData(num, true, mult);
        for(int j = 0; j < mult; j++){
          // reorder nodes if we have ElementNode data
          int j2 = (ent == MED_NOEUD_MAILLE) ? med2mshNodeIndex(ele, j) : j;
          for(int k = 0; k < numComp; k++)
            d[numCompMsh * j + k] = val[numComp * mult * i + numComp * j2 + k];
        }
      }
    }
  }

  finalize();

  if(MEDfermer(fid) < 0){
    Msg::Error("Unable to close file '%s'", (char*)fileName.c_str());
    return false;
  }
  return true;
}

bool PViewDataGModel::writeMED(std::string fileName)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()){
    Msg::Error("Export not done for multi-mesh views");
    return false;
  }

  if(_type != NodeData){
    Msg::Error("Can only export node-based datasets for now");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  // save the mesh
  if(!model->writeMED(fileName, true)) return false;

  char *meshName = (char*)model->getName().c_str();
  char *fieldName = (char*)getName().c_str();

  med_idt fid = MEDouvrir((char*)fileName.c_str(), MED_LECTURE_AJOUT);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  // compute profile
  char *profileName = (char*)"nodeProfile";
  std::vector<med_int> profile, indices;
  for(int i = 0; i < _steps[0]->getNumData(); i++){
    if(_steps[0]->getData(i)){
      MVertex *v = _steps[0]->getModel()->getMeshVertexByTag(i);
      if(!v){
        Msg::Error("Unknown vertex %d in data", i);
        return false;
      }
      profile.push_back(v->getIndex());
      indices.push_back(i);
    }
  }

  if(profile.empty()){
    Msg::Error("Nothing to save");
    return false;
  }

  if(MEDprofilEcr(fid, &profile[0], (med_int)profile.size(), profileName) < 0){
    Msg::Error("Could not create MED profile");
    return false;
  }

  int numComp = _steps[0]->getNumComponents();
  if(MEDchampCr(fid, fieldName, MED_FLOAT64, (char*)"unknown", (char*)"unknown",
                (med_int)numComp) < 0){
    Msg::Error("Could not create MED field");
    return false;
  }

  med_int numNodes = MEDnEntMaa(fid, meshName, MED_COOR, MED_NOEUD,
                                MED_NONE, (med_connectivite)0);
  if(numNodes <= 0){
    Msg::Error("Could not get valid number of nodes in mesh");
    return false;
  }
  for(unsigned int step = 0; step < _steps.size(); step++){
    unsigned int n = 0;
    for(int i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) n++;
    if(n != profile.size() || numComp != _steps[step]->getNumComponents()){
      Msg::Error("Skipping incompatible step");
      continue;
    }
    double time = _steps[step]->getTime();
    std::vector<double> val(profile.size() * numComp);
    for(unsigned int i = 0; i < profile.size(); i++)
      for(int k = 0; k < numComp; k++)
        val[i * numComp + k] = _steps[step]->getData(indices[i])[k];
    if(MEDchampEcr(fid, meshName, fieldName, (unsigned char*)&val[0],
                   MED_FULL_INTERLACE, numNodes, (char*)MED_NOGAUSS, MED_ALL,
                   profileName, MED_COMPACT, MED_NOEUD, MED_NONE, (med_int)step,
                   (char*)"unknown", time, MED_NONOR) < 0) {
      Msg::Error("Could not write MED field");
      return false;
    }
  }

  if(MEDfermer(fid) < 0){
    Msg::Error("Unable to close file '%s'", (char*)fileName.c_str());
    return false;
  }
  return true;
}

#else

bool PViewDataGModel::readMED(std::string fileName, int fileIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             fileName.c_str());
  return false;
}

bool PViewDataGModel::writeMED(std::string fileName)
{
  Msg::Error("Gmsh must be compiled with MED support to write '%s'",
             fileName.c_str());
  return false;
}

#endif

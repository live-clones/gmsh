// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "OS.h"
#include "Context.h"
#include "fullMatrix.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

bool PViewDataGModel::addData(GModel *model,
                              const std::map<int, std::vector<double> > &data,
                              int step, double time, int partition, int numComp)
{
  if(data.empty()) return false;
  if(step < 0) return false;

  if(numComp < 0) {
    numComp = 9;
    for(auto it = data.begin(); it != data.end(); it++)
      numComp = std::min(numComp, (int)it->second.size());
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  for(auto it = data.begin(); it != data.end(); it++) {
    int mult = it->second.size() / numComp;
    double *d = _steps[step]->getData(it->first, true, mult);
    for(int j = 0; j < numComp * mult; j++) d[j] = it->second[j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

bool PViewDataGModel::addData(GModel *model,
                              const std::vector<std::size_t> &tags,
                              const std::vector<std::vector<double> > &data,
                              int step, double time, int partition, int numComp)
{
  if(data.empty() || tags.empty() || data.size() != tags.size()) return false;

  if(numComp < 0) {
    if(_type == ElementNodeData) {
      numComp = 1; // cannot infer, as we can have different element types
    }
    else {
      numComp = 9;
      for(std::size_t i = 0; i < data.size(); i++)
        numComp = std::min(numComp, (int)data[i].size());
    }
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  for(std::size_t i = 0; i < data.size(); i++) {
    int mult = data[i].size() / numComp;
    double *d = _steps[step]->getData(tags[i], true, mult);
    for(int j = 0; j < numComp * mult; j++) d[j] = data[i][j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

bool PViewDataGModel::addData(GModel *model,
                              const std::vector<std::size_t> &tags,
                              const std::vector<double> &data, int step,
                              double time, int partition, int numComp)
{
  if(data.empty() || tags.empty()) return false;

  std::size_t stride = data.size() / tags.size();
  if(stride < 1) return false;

  if(numComp < 0) {
    if(_type == ElementNodeData) {
      numComp = 1; // cannot infer, as we can have different element types
    }
    else {
      numComp = (int)stride;
    }
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  int mult = stride / numComp;
  for(std::size_t i = 0; i < tags.size(); i++) {
    double *d = _steps[step]->getData(tags[i], true, mult);
    int k = i * stride;
    for(std::size_t j = 0; j < stride; j++) d[j] = data[k + j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

void PViewDataGModel::destroyData()
{
  for(std::size_t i = 0; i < _steps.size(); i++) _steps[i]->destroyData();
}

bool PViewDataGModel::readMSH(const std::string &viewName,
                              const std::string &fileName, int fileIndex,
                              FILE *fp, bool binary, bool swap, int step,
                              double time, int partition, int numComp,
                              int numEnt,
                              const std::string &interpolationScheme)
{
  Msg::Debug("Reading view `%s' step %d (time %g) partition %d: %d records",
             viewName.c_str(), step, time, partition, numEnt);

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(GModel::current(), numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setFileName(fileName);
  _steps[step]->setFileIndex(fileIndex);
  _steps[step]->setTime(time);

  /*
  // if we already have maxSteps for this view, return
  int numSteps = 0, maxSteps = 1000000000;
  for(std::size_t i = 0; i < _steps.size(); i++)
    numSteps += _steps[i]->getNumData() ? 1 : 0;
  if(numSteps > maxSteps) return true;
  */

  _steps[step]->resizeData(numEnt);

  Msg::StartProgressMeter(numEnt);
  for(int i = 0; i < numEnt; i++) {
    int num;
    if(binary) {
      if(fread(&num, sizeof(int), 1, fp) != 1) return false;
      if(swap) SwapBytes((char *)&num, sizeof(int), 1);
    }
    else {
      if(fscanf(fp, "%d", &num) != 1) return false;
    }
    if(num < 0) return false;
    int mult = 1;
    if(_type == ElementNodeData || _type == GaussPointData) {
      if(binary) {
        if(fread(&mult, sizeof(int), 1, fp) != 1) return false;
        if(swap) SwapBytes((char *)&mult, sizeof(int), 1);
      }
      else {
        if(fscanf(fp, "%d", &mult) != 1) return false;
      }
    }
    double *d = _steps[step]->getData(num, true, mult);
    if(binary) {
      if((int)fread(d, sizeof(double), numComp * mult, fp) != numComp * mult)
        return false;
      if(swap) SwapBytes((char *)d, sizeof(double), numComp * mult);
    }
    else {
      for(int j = 0; j < numComp * mult; j++)
        if(fscanf(fp, "%lf", &d[j]) != 1) return false;
    }
    // compute min/max here to avoid calling finalize(true) later:
    // this would be very slow for large multi-step, multi-partition
    // datasets (since we would recompute the min/max for all the
    // previously loaded steps/partitions, and thus loop over all the
    // elements many times)
    for(int j = 0; j < mult; j++) {
      double val = ComputeScalarRep(numComp, &d[numComp * j]);
      _steps[step]->setMin(std::min(_steps[step]->getMin(), val));
      _steps[step]->setMax(std::max(_steps[step]->getMax(), val));
      _min = std::min(_min, val);
      _max = std::max(_max, val);
    }
    if(numEnt > 100000) Msg::ProgressMeter(i + 1, true, "Reading data");
  }
  Msg::StopProgressMeter();
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);

  finalize(false, interpolationScheme);
  return true;
}

bool PViewDataGModel::writeMSH(const std::string &fileName, double version,
                               bool binary, bool saveMesh, bool multipleView,
                               int partitionNum, bool saveInterpolationMatrices,
                               bool forceNodeData, bool forceElementData)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()) {
    Msg::Info("Exporting multi-mesh view in separate files");
  }

  if(forceNodeData && _type != NodeData) {
    Msg::Warning("Cannot force NodeData for this dataset: saving native data");
  }

  if(forceElementData && _type != ElementData) {
    Msg::Warning(
      "Cannot force ElementData for this dataset: saving native data");
  }

  FILE *fp = nullptr;
  GModel *model0 = _steps[0]->getModel();
  int numFile = 0;

  for(std::size_t step = 0; step < _steps.size(); step++) {
    int numEnt = 0, numComp = _steps[step]->getNumComponents();
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) numEnt++;
    if(!numEnt) continue; // skip step

    // open file, save mesh and save interpolation matrices
    if(!fp || _steps[step]->getModel() != model0) {
      if(fp) fclose(fp);
      std::string stepFileName = fileName;
      if(hasMultipleMeshes()) {
        std::ostringstream sstream;
        std::vector<std::string> n = SplitFileName(fileName);
        sstream << n[0] << n[1] << "_" << numFile++ << n[2];
        stepFileName = sstream.str();
        model0 = _steps[step]->getModel();
      }
      if(saveMesh) {
        if(!_steps[step]->getModel()->writeMSH(stepFileName, version, binary,
                                               false, false, 1.0, 0, 0,
                                               multipleView))
          return false;
        // append data
        fp = Fopen(stepFileName.c_str(), binary ? "ab" : "a");
        if(!fp) {
          Msg::Error("Unable to open file '%s'", stepFileName.c_str());
          return false;
        }
      }
      else {
        if(multipleView) {
          fp = Fopen(stepFileName.c_str(), binary ? "ab" : "a");
          if(!fp) {
            Msg::Error("Unable to open file '%s'", stepFileName.c_str());
            return false;
          }
        }
        else {
          fp = Fopen(stepFileName.c_str(), binary ? "wb" : "w");
          if(!fp) {
            Msg::Error("Unable to open file '%s'", stepFileName.c_str());
            return false;
          }
          fprintf(fp, "$MeshFormat\n");
          fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0,
                  (int)sizeof(double));
          if(binary) {
            int one = 1;
            fwrite(&one, sizeof(int), 1, fp);
            fprintf(fp, "\n");
          }
          fprintf(fp, "$EndMeshFormat\n");
        }
      }
      // save the interpolation matrix?
      if(saveInterpolationMatrices && haveInterpolationMatrices()) {
        fprintf(fp, "$InterpolationScheme\n");
        fprintf(fp, "\"INTERPOLATION_SCHEME\"\n");
        fprintf(fp, "%d\n", (int)_interpolation.size());
        for(auto it = _interpolation.begin(); it != _interpolation.end();
            it++) {
          if(it->second.size() >= 2) {
            fprintf(fp, "%d\n2\n", it->first);
            for(int mat = 0; mat < 2; mat++) {
              int m = it->second[mat]->size1(), n = it->second[mat]->size2();
              fprintf(fp, "%d %d\n", m, n);
              for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++)
                  fprintf(fp, "%.16g ", it->second[mat]->get(i, j));
                fprintf(fp, "\n");
              }
            }
          }
        }
        fprintf(fp, "$EndInterpolationScheme\n");
      }
    }

    // save the data
    if(_type == NodeData) {
      fprintf(fp, "$NodeData\n");
      fprintf(fp, "1\n\"%s\"\n", getName().c_str());
      fprintf(fp, "1\n%.16g\n", _steps[step]->getTime());
      if(partitionNum > 0) {
        fprintf(fp, "4\n%lu\n%d\n%d\n%d\n", step, numComp, numEnt,
                partitionNum);
      }
      else if(_steps[step]->getPartitions().size() == 1) {
        int p = *_steps[step]->getPartitions().begin();
        fprintf(fp, "4\n%lu\n%d\n%d\n%d\n", step, numComp, numEnt, p);
      }
      else {
        fprintf(fp, "3\n%lu\n%d\n%d\n", step, numComp, numEnt);
      }
      for(std::size_t i = 0; i < _steps[step]->getNumData(); i++) {
        if(_steps[step]->getData(i)) {
          MVertex *v = _steps[step]->getModel()->getMeshVertexByTag(i);
          if(!v) {
            Msg::Error("Unknown node %d in data", i);
            fclose(fp);
            return false;
          }
          int num = (version >= 3.0) ? v->getNum() : v->getIndex();
          if(binary) {
            fwrite(&num, sizeof(int), 1, fp);
            fwrite(_steps[step]->getData(i), sizeof(double), numComp, fp);
          }
          else {
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
    else {
      if(_type == ElementNodeData)
        fprintf(fp, "$ElementNodeData\n");
      else
        fprintf(fp, "$ElementData\n");
      if(saveInterpolationMatrices && haveInterpolationMatrices())
        fprintf(fp, "2\n\"%s\"\n\"INTERPOLATION_SCHEME\"\n", getName().c_str());
      else
        fprintf(fp, "1\n\"%s\"\n", getName().c_str());

      fprintf(fp, "1\n%.16g\n", _steps[step]->getTime());
      if(partitionNum > 0) {
        fprintf(fp, "4\n%lu\n%d\n%d\n%d\n", step, numComp, numEnt,
                partitionNum);
      }
      else if(_steps[step]->getPartitions().size() == 1) {
        int p = *_steps[step]->getPartitions().begin();
        fprintf(fp, "4\n%lu\n%d\n%d\n%d\n", step, numComp, numEnt, p);
      }
      else {
        fprintf(fp, "3\n%lu\n%d\n%d\n", step, numComp, numEnt);
      }
      for(std::size_t i = 0; i < _steps[step]->getNumData(); i++) {
        if(_steps[step]->getData(i)) {
          MElement *e = _steps[step]->getModel()->getMeshElementByTag(i);
          if(!e) {
            Msg::Error("Unknown element %d in data", i);
            fclose(fp);
            return false;
          }
          int mult = _steps[step]->getMult(i);
          int num = (version >= 3.0) ?
                      e->getNum() :
                      _steps[step]->getModel()->getMeshElementIndex(e);
          if(binary) {
            fwrite(&num, sizeof(int), 1, fp);
            if(_type == ElementNodeData) fwrite(&mult, sizeof(int), 1, fp);
            fwrite(_steps[step]->getData(i), sizeof(double), numComp * mult,
                   fp);
          }
          else {
            fprintf(fp, "%d", num);
            if(_type == ElementNodeData) fprintf(fp, " %d", mult);
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

  fclose(fp);
  return true;
}

void PViewDataGModel::importLists(int N[24], std::vector<double> *V[24])
{
  for(int idxtype = 0; idxtype < 24; idxtype++) {
    int nbe = N[idxtype];
    if(!nbe) continue;
    std::vector<double> *list = V[idxtype];
    int nc = 0, nn = 0;
    switch(idxtype) {
    case 0:
      nc = 1;
      nn = 1;
      break; // SP
    case 1:
      nc = 3;
      nn = 1;
      break; // VP
    case 2:
      nc = 9;
      nn = 1;
      break; // TP
    case 3:
      nc = 1;
      nn = 2;
      break; // SL
    case 4:
      nc = 3;
      nn = 2;
      break; // VL
    case 5:
      nc = 9;
      nn = 2;
      break; // TL
    case 6:
      nc = 1;
      nn = 3;
      break; // ST
    case 7:
      nc = 3;
      nn = 3;
      break; // VT
    case 8:
      nc = 9;
      nn = 3;
      break; // TT
    case 9:
      nc = 1;
      nn = 4;
      break; // SQ
    case 10:
      nc = 3;
      nn = 4;
      break; // VQ
    case 11:
      nc = 9;
      nn = 4;
      break; // TQ
    case 12:
      nc = 1;
      nn = 4;
      break; // SS
    case 13:
      nc = 3;
      nn = 4;
      break; // VS
    case 14:
      nc = 9;
      nn = 4;
      break; // TS
    case 15:
      nc = 1;
      nn = 8;
      break; // SH
    case 16:
      nc = 3;
      nn = 8;
      break; // VH
    case 17:
      nc = 9;
      nn = 8;
      break; // TH
    case 18:
      nc = 1;
      nn = 6;
      break; // SI
    case 19:
      nc = 3;
      nn = 6;
      break; // VI
    case 20:
      nc = 9;
      nn = 6;
      break; // TI
    case 21:
      nc = 1;
      nn = 5;
      break; // SY
    case 22:
      nc = 3;
      nn = 5;
      break; // VY
    case 23:
      nc = 9;
      nn = 5;
      break; // TY
    }
    int stride = list->size() / nbe;
    int numSteps = (stride - 1) / nc / nn;
    for(int step = 0; step < numSteps; step++) {
      _steps.push_back(new stepData<double>(GModel::current(), nc));
      _steps[step]->fillEntities();
      _steps[step]->computeBoundingBox();
      _steps[step]->setTime(step);
      _steps[step]->resizeData(nbe);
      for(std::size_t j = 0; j < list->size(); j += stride) {
        double *tmp = &(*list)[j];
        int num = (int)tmp[0];
        double *d = _steps[step]->getData(num, true, nn);
        for(int k = 0; k < nc * nn; k++) { d[k] = tmp[1 + nc * nn * step + k]; }
      }
    }
  }

  finalize();
}

#if defined(HAVE_MED)

#include <med.h>

#if(MED_MAJOR_NUM >= 3)
// To avoid too many ifdefs below we use defines for the bits of the
// API that did not change too much between MED2 and MED3. If we
// remove MED2 support at some point, please remove these defines and
// replace the symbols accordingly.
#define med_geometrie_element med_geometry_type
#define med_entite_maillage med_entity_type
#define med_type_champ med_field_type
#define MED_TAILLE_NOM MED_NAME_SIZE
#define MED_TAILLE_PNOM MED_SNAME_SIZE
#define MED_LECTURE MED_ACC_RDONLY
#define MED_LECTURE_AJOUT MED_ACC_RDEXT
#define MED_NOEUD MED_NODE
#define MED_MAILLE MED_CELL
#define MED_NOEUD_MAILLE MED_NODE_ELEMENT
#define MED_NOPFL MED_NO_PROFILE
#define MEDouvrir MEDfileOpen
#define MEDfermer MEDfileClose
#define MEDnChamp MEDfieldnComponent
#define MEDnValProfil MEDprofileSizeByName
#endif

extern int med2mshElementType(med_geometrie_element med);
extern int med2mshNodeIndex(med_geometrie_element med, int k);

std::vector<std::string> medGetFieldNames(const std::string &fileName)
{
  std::vector<std::string> fieldNames;

#if(MED_MAJOR_NUM >= 3)
  med_idt fid = MEDfileOpen(fileName.c_str(), MED_ACC_RDONLY);
#else
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE);
#endif
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return fieldNames;
  }

#if(MED_MAJOR_NUM >= 3)
  med_int numFields = MEDnField(fid);
#else
  med_int numFields = MEDnChamp(fid, 0);
#endif

  for(int index = 0; index < numFields; index++) {
    med_int numComp = MEDnChamp(fid, index + 1);
    if(numComp <= 0) {
      Msg::Error("Could not get number of components for MED field");
      return fieldNames;
    }

    char name[MED_TAILLE_NOM + 1], meshName[MED_TAILLE_NOM + 1];
    char dtUnit[MED_TAILLE_PNOM + 1];
    std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
    std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
    med_int numSteps = 0;
    med_type_champ type;
#if(MED_MAJOR_NUM >= 3)
    med_bool localMesh;
    if(MEDfieldInfo(fid, index + 1, name, meshName, &localMesh, &type,
                    &compName[0], &compUnit[0], dtUnit, &numSteps) < 0) {
#else
    if(MEDchampInfo(fid, index + 1, name, &type, &compName[0], &compUnit[0],
                    numComp) < 0) {
#endif
      Msg::Error("Could not get MED field info");
      return fieldNames;
    }
    fieldNames.push_back(name);
  }

#if(MED_MAJOR_NUM >= 3)
  if(MEDfileClose(fid) < 0) {
#else
  if(MEDfermer(fid) < 0) {
#endif
    Msg::Error("Unable to close file '%s'", fileName.c_str());
  }
  return fieldNames;
}

bool PViewDataGModel::readMED(const std::string &fileName, int fileIndex)
{
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  med_int numComp = MEDnChamp(fid, fileIndex + 1);
  if(numComp <= 0) {
    Msg::Error("Could not get number of components for MED field");
    return false;
  }

  char name[MED_TAILLE_NOM + 1], meshName[MED_TAILLE_NOM + 1];
  char dtUnit[MED_TAILLE_PNOM + 1];
  std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
  std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
  med_int numSteps = 0;
  med_type_champ type;
#if(MED_MAJOR_NUM >= 3)
  med_bool localMesh;
  if(MEDfieldInfo(fid, fileIndex + 1, name, meshName, &localMesh, &type,
                  &compName[0], &compUnit[0], dtUnit, &numSteps) < 0) {
#else
  if(MEDchampInfo(fid, fileIndex + 1, name, &type, &compName[0], &compUnit[0],
                  numComp) < 0) {
#endif
    Msg::Error("Could not get MED field info");
    return false;
  }

  Msg::Info("Reading %d-component field '%s'", numComp, name);
  setName(name);
  setFileName(fileName);
  setFileIndex(fileIndex);

  int numCompMsh = (numComp <= 1) ? 1 :
                   (numComp <= 3) ? 3 :
                   (numComp <= 9) ? 9 :
                                    numComp;

  if(numCompMsh > 9)
    Msg::Info(
      "More than 9 components in field: you will probably want to force "
      "the field type to scalar, vector or tensor in the options");

  // Warning! The ordering of the elements in the last two lists is
  // important: it should match the ordering of the MSH element types
  // (when elements are saved without tags, this governs the order
  // with which we implicitly index them in GModel::readMED)
  const med_entite_maillage entType[] = {MED_NOEUD, MED_MAILLE,
                                         MED_NOEUD_MAILLE};
#if(MED_MAJOR_NUM >= 3)
  const med_geometrie_element eleType[] = {
    MED_NONE,   MED_SEG2,   MED_TRIA3, MED_QUAD4,  MED_TETRA4,  MED_HEXA8,
    MED_PENTA6, MED_PYRA5,  MED_SEG3,  MED_TRIA6,  MED_QUAD9,   MED_TETRA10,
    MED_HEXA27, MED_POINT1, MED_QUAD8, MED_HEXA20, MED_PENTA15, MED_PYRA13};
  const int nodesPerEle[] = {0, 2, 3,  4,  4, 8, 6,  5,  3,
                             6, 9, 10, 27, 1, 8, 20, 15, 13};
#else
  const med_geometrie_element eleType[] = {
    MED_NONE,   MED_SEG2,   MED_TRIA3,   MED_QUAD4, MED_TETRA4,  MED_HEXA8,
    MED_PENTA6, MED_PYRA5,  MED_SEG3,    MED_TRIA6, MED_TETRA10, MED_POINT1,
    MED_QUAD8,  MED_HEXA20, MED_PENTA15, MED_PYRA13};
  const int nodesPerEle[] = {0, 2, 3,  4, 4, 8,  6,  5,
                             3, 6, 10, 1, 8, 20, 15, 13};
#endif

  std::vector<std::pair<int, int> > pairs;
  for(std::size_t i = 0; i < sizeof(entType) / sizeof(entType[0]); i++) {
    for(std::size_t j = 0; j < sizeof(eleType) / sizeof(eleType[0]); j++) {
      if((!i && !j) || j) {
#if(MED_MAJOR_NUM >= 3)
        med_int n = numSteps;
#else
        med_int n = MEDnPasdetemps(fid, name, entType[i], eleType[j]);
#endif
        if(n > 0) {
          pairs.push_back(std::make_pair(i, j));
          numSteps = std::max(numSteps, n);
        }
        if(!i && !j) break; // MED_NOEUD does not care about eleType
      }
    }
  }

  if(numSteps < 1 || pairs.empty()) {
    Msg::Error("Nothing to import from MED file");
    return false;
  }

  for(int step = 0; step < numSteps; step++) {
    // FIXME: in MED3 we might want to loop over all profiles instead
    // of relying of the default one

    // FIXME: MED3 allows to store multi-step meshes; we should
    // interface this with our own gmodel-per-step structure

    for(std::size_t pair = 0; pair < pairs.size(); pair++) {
      // get step info
      med_entite_maillage ent = entType[pairs[pair].first];
      med_geometrie_element ele = eleType[pairs[pair].second];
      med_int numdt, numit, ngauss;
      med_float dt;
#if(MED_MAJOR_NUM >= 3)
      if(MEDfieldComputingStepInfo(fid, name, step + 1, &numdt, &numit, &dt) <
         0) {
#else
      char dtunit[MED_TAILLE_PNOM + 1];
      med_booleen local;
      med_int numMeshes;
      if(MEDpasdetempsInfo(fid, name, ent, ele, step + 1, &ngauss, &numdt,
                           &numit, dtunit, &dt, meshName, &local,
                           &numMeshes) < 0) {
#endif
        Msg::Error("Could not read step info");
        return false;
      }
      // create step data
      if(!pair) {
        GModel *m = GModel::findByName(meshName);
        if(!m) {
          Msg::Error("Could not find mesh '%s'", meshName);
          return false;
        }
        while(step >= (int)_steps.size())
          _steps.push_back(new stepData<double>(m, numCompMsh));
        _steps[step]->fillEntities();
        _steps[step]->computeBoundingBox();
        _steps[step]->setFileName(fileName);
        _steps[step]->setFileIndex(fileIndex);
        _steps[step]->setTime(dt);
      }

      char locName[MED_TAILLE_NOM + 1], profileName[MED_TAILLE_NOM + 1];

      // get number of values in the field (numVal takes the number of
      // Gauss points or the number of nodes per element into account,
      // but not the number of components)
#if(MED_MAJOR_NUM >= 3)
      med_int profileSize;
      med_int numVal = MEDfieldnValueWithProfile(
        fid, name, numdt, numit, ent, ele, 1, MED_COMPACT_STMODE, profileName,
        &profileSize, locName, &ngauss);
      numVal *= ngauss;
#else
      med_int numVal =
        MEDnVal(fid, name, ent, ele, numdt, numit, meshName, MED_COMPACT);
#endif
      if(numVal <= 0) continue;

      _type = (ent == MED_NOEUD)  ? NodeData :
              (ent == MED_MAILLE) ? ElementData :
                                    ElementNodeData;
      int mult = 1;
      if(ent == MED_NOEUD_MAILLE) { mult = nodesPerEle[pairs[pair].second]; }
      else if(ngauss != 1) {
        mult = ngauss;
        _type = GaussPointData;
      }
      _steps[step]->resizeData(numVal / mult);

      // read field data
      std::vector<double> val(numVal * numComp);
#if(MED_MAJOR_NUM >= 3)
      if(MEDfieldValueWithProfileRd(fid, name, numdt, numit, ent, ele,
                                    MED_COMPACT_STMODE, profileName,
                                    MED_FULL_INTERLACE, MED_ALL_CONSTITUENT,
                                    (unsigned char *)&val[0]) < 0) {
#else
      if(MEDchampLire(fid, meshName, name, (unsigned char *)&val[0],
                      MED_FULL_INTERLACE, MED_ALL, locName, profileName,
                      MED_COMPACT, ent, ele, numdt, numit) < 0) {
#endif
        Msg::Error("Could not read field values");
        return false;
      }

      Msg::Debug(
        "MED: eletyp=%d entity=%d (0:cell, 3:node, 4:elenode) ngauss=%d "
        "localizationName=%s profileName=%s -- stepDataType=%d",
        ele, ent, ngauss, locName, profileName, _type);

      // read Gauss point data
      if(_type == GaussPointData) {
        std::vector<double> &p(
          _steps[step]->getGaussPoints(med2mshElementType(ele)));
        if(std::string(locName) == MED_GAUSS_ELNO) {
          // special case: the gauss points are the vertices of the
          // element; in this case no explicit localization has to be
          // created in MED
          p.resize(ngauss * 3, 1.e22);
        }
        else {
          int dim = ele / 100;
          std::vector<med_float> refcoo((ele % 100) * dim);
          std::vector<med_float> gscoo(ngauss * dim);
          std::vector<med_float> wg(ngauss);
#if(MED_MAJOR_NUM >= 3)
          if(MEDlocalizationRd(fid, locName, MED_FULL_INTERLACE, &refcoo[0],
                               &gscoo[0], &wg[0]) < 0) {
#else
          if(MEDgaussLire(fid, &refcoo[0], &gscoo[0], &wg[0],
                          MED_FULL_INTERLACE, locName) < 0) {
#endif
            Msg::Error("Could not read Gauss points");
            return false;
          }
          // FIXME: we should check that refcoo corresponds to our
          // internal reference element
          for(int i = 0; i < (int)gscoo.size(); i++) {
            p.push_back(gscoo[i]);
            if(i % dim == dim - 1)
              for(int j = 0; j < 3 - dim; j++) p.push_back(0.);
          }
        }
      }

      // compute profile (indices in full array of entities of given type)
      std::vector<med_int> profile;
      if(std::string(profileName) != MED_NOPFL) {
        med_int n = MEDnValProfil(fid, profileName);
        if(n > 0) {
          Msg::Debug("MED has full profile");
          profile.resize(n);
#if(MED_MAJOR_NUM >= 3)
          if(MEDprofileRd(fid, profileName, &profile[0]) < 0) {
#else
          if(MEDprofilLire(fid, &profile[0], profileName) < 0) {
#endif
            Msg::Error("Could not read profile");
            return false;
          }
        }
      }
      if(profile.empty()) {
        Msg::Debug("MED profile is empty -- using continuous sequence");
        profile.resize(numVal / mult);
        for(std::size_t i = 0; i < profile.size(); i++) profile[i] = i + 1;
      }

      // get size of full array and tags (if any) of entities
      bool nodal = (ent == MED_NOEUD);
#if(MED_MAJOR_NUM >= 3)
      med_bool changeOfCoord;
      med_bool geoTransform;
      med_int numEnt = MEDmeshnEntity(
        fid, meshName, MED_NO_DT, MED_NO_IT, nodal ? MED_NODE : MED_CELL,
        nodal ? MED_NO_GEOTYPE : ele, nodal ? MED_COORDINATE : MED_CONNECTIVITY,
        nodal ? MED_NO_CMODE : MED_NODAL, &changeOfCoord, &geoTransform);
#else
      med_int numEnt =
        MEDnEntMaa(fid, meshName, nodal ? MED_COOR : MED_CONN,
                   nodal ? MED_NOEUD : MED_MAILLE, nodal ? MED_NONE : ele,
                   nodal ? (med_connectivite)0 : MED_NOD);
#endif
      std::vector<med_int> tags(numEnt);
#if(MED_MAJOR_NUM >= 3)
      if(MEDmeshEntityNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT,
                               nodal ? MED_NODE : MED_CELL,
                               nodal ? MED_NO_GEOTYPE : ele, &tags[0]) < 0)
#else
      if(MEDnumLire(fid, meshName, &tags[0], numEnt,
                    nodal ? MED_NOEUD : MED_MAILLE, nodal ? MED_NONE : ele) < 0)
#endif
        tags.clear();

      // if we don't have tags, compute the starting index (i.e., how many
      // elements of different type are in the mesh before these ones)
      std::size_t startIndex = 0;
      if(tags.empty()) {
        std::size_t maxv, maxe;
        _steps[step]->getModel()->getCheckPointedMaxNumbers(maxv, maxe);
        if(nodal) { startIndex += maxv; }
        else {
          for(int i = 1; i < pairs[pair].second; i++) {
#if(MED_MAJOR_NUM >= 3)
            med_int n = MEDmeshnEntity(
              fid, meshName, MED_NO_DT, MED_NO_IT, MED_CELL, eleType[i],
              MED_CONNECTIVITY, MED_NODAL, &changeOfCoord, &geoTransform);
#else
            med_int n = MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE,
                                   eleType[i], MED_NOD);
#endif
            if(n > 0) startIndex += n;
          }
          startIndex += maxe;
        }
        Msg::Debug("MED has no tags -- assuming starting index %lu",
                   startIndex);
      }

      // compute entity numbers using profile, then fill step data
      for(std::size_t i = 0; i < profile.size(); i++) {
        std::size_t num;
        if(tags.empty()) { num = startIndex + profile[i]; }
        else {
          if(profile[i] == 0 || profile[i] > (int)tags.size()) {
            Msg::Error("Wrong index in profile");
            return false;
          }
          num = tags[profile[i] - 1];
        }

        double *d = _steps[step]->getData(num, true, mult);
        for(int j = 0; j < mult; j++) {
          // reorder nodes if we have ElementNode data
          int j2 = (ent == MED_NOEUD_MAILLE) ? med2mshNodeIndex(ele, j) : j;
          for(int k = 0; k < numComp; k++)
            d[numCompMsh * j + k] = val[numComp * mult * i + numComp * j2 + k];
        }
      }
    }
  }

  finalize();

  if(MEDfermer(fid) < 0) {
    Msg::Error("Unable to close file '%s'", (char *)fileName.c_str());
    return false;
  }
  return true;
}

bool PViewDataGModel::writeMED(const std::string &fileName)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()) {
    Msg::Error("Export not done for multi-mesh views");
    return false;
  }

  if(_type != NodeData) {
    Msg::Error("Can only export node-based datasets for now");
    return false;
  }

  GModel *model = _steps[0]->getModel();

  // save the mesh
  if(!model->writeMED(fileName, true)) return false;

  std::string meshName(model->getName());
  std::string fieldName(getName());

#if (MED_MAJOR_NUM >= 4) || ((MED_MAJOR_NUM >= 3) && (MED_MINOR_NUM >= 3))
  // MEDfileVersionOpen actually appeared in MED 3.2.1
  med_int major = MED_MAJOR_NUM, minor = MED_MINOR_NUM,
          release = MED_RELEASE_NUM;
  if(CTX::instance()->mesh.medFileMinorVersion >= 0) {
    minor = (int)CTX::instance()->mesh.medFileMinorVersion;
    Msg::Info("Forcing MED file version to %d.%d", major, minor);
  }
  med_idt fid = MEDfileVersionOpen((char *)fileName.c_str(), MED_ACC_RDEXT,
                                   major, minor, release);
#else
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE_AJOUT);
#endif

  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  // compute profile
  char *profileName = (char *)"nodeProfile";
  std::vector<med_int> profile, indices;
  for(std::size_t i = 0; i < _steps[0]->getNumData(); i++) {
    if(_steps[0]->getData(i)) {
      MVertex *v = _steps[0]->getModel()->getMeshVertexByTag(i);
      if(!v) {
        Msg::Error("Unknown node %d in data", i);
        return false;
      }
      profile.push_back(v->getIndex());
      indices.push_back(i);
    }
  }

  if(profile.empty()) {
    Msg::Error("Nothing to save");
    return false;
  }

#if(MED_MAJOR_NUM >= 3)
  if(MEDprofileWr(fid, profileName, (med_int)profile.size(), &profile[0]) < 0) {
#else
  if(MEDprofilEcr(fid, &profile[0], (med_int)profile.size(), profileName) < 0) {
#endif
    Msg::Error("Could not create MED profile");
    return false;
  }

  int numComp = _steps[0]->getNumComponents();
#if(MED_MAJOR_NUM >= 3)
  if(MEDfieldCr(fid, (char *)fieldName.c_str(), MED_FLOAT64, (med_int)numComp,
                "unknown", "unknown", "unknown",
                (char *)meshName.c_str()) < 0) {
#else
  if(MEDchampCr(fid, (char *)fieldName.c_str(), MED_FLOAT64, (char *)"unknown",
                (char *)"unknown", (med_int)numComp) < 0) {
#endif
    Msg::Error("Could not create MED field");
    return false;
  }

#if(MED_MAJOR_NUM >= 3)
  med_bool changeOfCoord, geoTransform;
  med_int numNodes =
    MEDmeshnEntity(fid, (char *)meshName.c_str(), MED_NO_DT, MED_NO_IT,
                   MED_NODE, MED_NO_GEOTYPE, MED_COORDINATE, MED_NO_CMODE,
                   &changeOfCoord, &geoTransform);
#else
  med_int numNodes = MEDnEntMaa(fid, (char *)meshName.c_str(), MED_COOR,
                                MED_NOEUD, MED_NONE, (med_connectivite)0);
#endif
  if(numNodes <= 0) {
    Msg::Error("Could not get valid number of nodes in mesh");
    return false;
  }
  for(std::size_t step = 0; step < _steps.size(); step++) {
    std::size_t n = 0;
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) n++;
    if(n != profile.size() || numComp != _steps[step]->getNumComponents()) {
      Msg::Error("Skipping incompatible step");
      continue;
    }
    double time = _steps[step]->getTime();
    std::vector<double> val(profile.size() * numComp);
    for(std::size_t i = 0; i < profile.size(); i++)
      for(int k = 0; k < numComp; k++)
        val[i * numComp + k] = _steps[step]->getData(indices[i])[k];
#if(MED_MAJOR_NUM >= 3)
    if(MEDfieldValueWithProfileWr(
         fid, (char *)fieldName.c_str(), (med_int)(step + 1), MED_NO_IT, time,
         MED_NODE, MED_NO_GEOTYPE, MED_COMPACT_STMODE, profileName, "",
         MED_FULL_INTERLACE, MED_ALL_CONSTITUENT, numNodes,
         (unsigned char *)&val[0]) < 0) {
#else
    if(MEDchampEcr(fid, (char *)meshName.c_str(), (char *)fieldName.c_str(),
                   (unsigned char *)&val[0], MED_FULL_INTERLACE, numNodes,
                   (char *)MED_NOGAUSS, MED_ALL, profileName, MED_COMPACT,
                   MED_NOEUD, MED_NONE, (med_int)step, (char *)"unknown", time,
                   MED_NONOR) < 0) {
#endif
      Msg::Error("Could not write MED field");
      return false;
    }
  }

  if(MEDfermer(fid) < 0) {
    Msg::Error("Unable to close file '%s'", (char *)fileName.c_str());
    return false;
  }
  return true;
}

#else

bool PViewDataGModel::readMED(const std::string &fileName, int fileIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             fileName.c_str());
  return false;
}

bool PViewDataGModel::writeMED(const std::string &fileName)
{
  Msg::Error("Gmsh must be compiled with MED support to write '%s'",
             fileName.c_str());
  return false;
}

#endif

bool PViewDataGModel::readPCH(const std::string &fileName, int fileIndex)
{
  Msg::Info("Placeholder for reading punch file '%s'", fileName.c_str());

  std::map<int, std::vector<double> > data;
  for(int i = 1; i < 200; i++) data[i].push_back(1.234);
  addData(GModel::current(), data, 0, 0.0, 1, 1);

  return true;
}

void PViewDataGModel::sendToServer(const std::string &name)
{
  if(_steps.empty()) return;

  if(_type != NodeData) {
    Msg::Error("sendToServer currently only implemented for nodal datasets");
    return;
  }

  int numEnt = 0, numComp = 0;
  for(std::size_t step = 0; step < _steps.size(); step++) {
    int nc = _steps[step]->getNumComponents();
    int ne = 0;
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) ne++;
    if(!step) {
      numEnt = ne;
      numComp = nc;
    }
    else {
      if(ne != numEnt || nc != numComp) {
        Msg::Error("Can not send heterogeneous view to server");
        return;
      }
    }
  }

  std::vector<double> exp;
  exp.push_back(numEnt);

  for(std::size_t i = 0; i < _steps[0]->getNumData(); i++) {
    if(_steps[0]->getData(i)) {
      MVertex *v = _steps[0]->getModel()->getMeshVertexByTag(i);
      if(!v) {
        Msg::Error("Unknown node %d in data", i);
        return;
      }
      int num = v->getNum();
      exp.push_back(num);
      for(std::size_t step = 0; step < _steps.size(); step++) {
        for(int k = 0; k < numComp; k++) {
          double data = _steps[step]->getData(i)[k];
          exp.push_back(data);
        }
      }
    }
  }

  Msg::SetOnelabNumber(name, exp, false);
}

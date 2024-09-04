// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "Context.h"
#include "fullMatrix.h"
#include "StringUtils.h"
#include "OS.h"

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

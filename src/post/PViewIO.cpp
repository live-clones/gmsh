// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "VertexArray.h"
#include "StringUtils.h"
#include "Context.h"
#include "OS.h"
#include "adaptiveData.h"

bool PView::readPOS(const std::string &fileName, int fileIndex)
{
  FILE *fp = Fopen(fileName.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  char str[256] = "XXX";
  double version = -1.;
  int format = -1, size = -1, index = -1;

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    if(feof(fp)) break;

    if(!strncmp(&str[1], "PostFormat", 10)) {
      if(!fscanf(fp, "%lf %d %d\n", &version, &format, &size)) {
        Msg::Error("Read error");
        fclose(fp);
        return false;
      }
      if(version < 1.0) {
        Msg::Error("Post-processing file too old (ver. %g < 1.0)", version);
        fclose(fp);
        return false;
      }
      if(size == sizeof(double))
        Msg::Debug("Data is in double precision format (size==%d)", size);
      else {
        Msg::Error("Unknown data size (%d) in post-processing file", size);
        fclose(fp);
        return false;
      }
    }
    else if(!strncmp(&str[1], "View", 4)) {
      index++;
      if(fileIndex < 0 || fileIndex == index) {
        PViewDataList *d = new PViewDataList();
        if(!d->readPOS(fp, version, format ? true : false)) {
          Msg::Error("Could not read data in list format");
          delete d;
          fclose(fp);
          return false;
        }
        else {
          d->setFileName(fileName);
          d->setFileIndex(index);
          new PView(d);
        }
      }
    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    } while(str[0] != '$');
  }

  fclose(fp);
  return true;
}

bool PView::readMSHInterpolationScheme(FILE *fp)
{
  char str[256] = "XXX";
  std::string name;
  if(!fgets(str, sizeof(str), fp)) {
    return false;
  }
  name = ExtractDoubleQuotedString(str, sizeof(str));
  Msg::Debug("Reading interpolation scheme '%s'", name.c_str());
  PViewData::removeInterpolationScheme(name);
  int numTypes;
  if(fscanf(fp, "%d", &numTypes) != 1) {
    return false;
  }
  for(int i = 0; i < numTypes; i++) {
    int type, numMatrices;
    if(fscanf(fp, "%d %d", &type, &numMatrices) != 2) {
      return false;
    }
    for(int j = 0; j < numMatrices; j++) {
      int m, n;
      if(fscanf(fp, "%d %d", &m, &n) != 2) {
        return false;
      }
      fullMatrix<double> mat(m, n);
      for(int k = 0; k < m; k++) {
        for(int l = 0; l < n; l++) {
          double d;
          if(fscanf(fp, "%lf", &d) != 1) {
            return false;
          }
          mat.set(k, l, d);
        }
      }
      PViewData::addMatrixToInterpolationScheme(name, type, mat);
    }
  }
  return true;
}

bool PView::readMSHViewData(const std::string &fileName, FILE *fp,
                            bool binary, bool swap, const char *dataType,
                            int partitionToRead)
{
  PViewDataGModel::DataType type;
  if(!strncmp(dataType, "NodeData", 8))
    type = PViewDataGModel::NodeData;
  else if(!strncmp(dataType, "ElementData", 11))
    type = PViewDataGModel::ElementData;
  else
    type = PViewDataGModel::ElementNodeData;

  char str[256] = "XXX";

  int numTags;
  // string tags
  std::string viewName, interpolationScheme;
  if(!fgets(str, sizeof(str), fp)) {
    return false;
  }
  if(sscanf(str, "%d", &numTags) != 1) {
    return false;
  }
  for(int i = 0; i < numTags; i++) {
    if(!fgets(str, sizeof(str), fp)) {
      return false;
    }
    if(i == 0)
      viewName = ExtractDoubleQuotedString(str, sizeof(str));
    else if(i == 1)
      interpolationScheme = ExtractDoubleQuotedString(str, sizeof(str));
  }
  // double tags
  double time = 0.;
  if(!fgets(str, sizeof(str), fp)) {
    return false;
  }
  if(sscanf(str, "%d", &numTags) != 1) {
    return false;
  }
  for(int i = 0; i < numTags; i++) {
    if(!fgets(str, sizeof(str), fp)) {
      return false;
    }
    if(i == 0) {
      if(sscanf(str, "%lf", &time) != 1) {
        return false;
      }
    }
  }
  // integer tags
  int timeStep = 0, numComp = 0, numEnt = 0, partition = 0;
  long int blocksize = 0;
  if(!fgets(str, sizeof(str), fp)) {
    return false;
  }
  if(sscanf(str, "%d", &numTags) != 1) {
    return false;
  }
  for(int i = 0; i < numTags; i++) {
    if(!fgets(str, sizeof(str), fp)) {
      return false;
    }
    if(i == 0) {
      if(sscanf(str, "%d", &timeStep) != 1) {
        return false;
      }
    }
    else if(i == 1) {
      if(sscanf(str, "%d", &numComp) != 1) {
        return false;
      }
    }
    else if(i == 2) {
      if(sscanf(str, "%d", &numEnt) != 1) {
        return false;
      }
    }
    else if(i == 3) {
      if(sscanf(str, "%d", &partition) != 1) {
        return false;
      }
    }
    else if(i == 4) {
      if(sscanf(str, "%ld", &blocksize) != 1) {
        return false;
      }
    }
  }
  if(partitionToRead == -1 || partitionToRead == partition) {
    // if default (no particular partition requested from MergeFile -> -1) or
    // if current partition corresponds to the requested partition, read the
    // data
    if(numEnt > 0) {
      // the block completes a view that does not have this step and
      // partition yet, if it holds the same type of data with the same number
      // of components
      auto accept = [&](PViewDataGModel *d) {
        return !(d->hasTimeStep(timeStep) &&
                 d->hasPartition(timeStep, partition)) &&
               d->canAddData(type, timeStep, numComp);
      };
      auto read = [&](PViewDataGModel *d) {
        return d->readMSH(viewName, fileName, -1, fp, binary, swap, timeStep,
                          time, partition, numComp, numEnt,
                          interpolationScheme);
      };
      if(!PViewDataGModel::readInView(viewName, fileName, type, accept, read)) {
        Msg::Error("Could not read data in file '%s'", fileName.c_str());
        return false;
      }
    }
  }
  else if(blocksize > 0 && partitionToRead != partition) {
    // if current partition does not correspond to the requested partition
    // and if its blocksise has been read (5th integer in the header),
    // jump over it
    fseek(fp, blocksize, SEEK_CUR);
  }
  return true;
}

#if defined(HAVE_MED)

extern std::vector<std::string> medGetFieldNames(const std::string &fileName);

bool PView::readMED(const std::string &fileName, int fileIndex)
{
  std::vector<std::string> fieldNames = medGetFieldNames(fileName);

  for(std::size_t index = 0; index < fieldNames.size(); index++) {
    if(fileIndex >= 0 && (int)index != fileIndex) continue;
    // the file is a kind of partition: the field completes a view read from
    // other files (e.g. of a domain decomposition)
    auto accept = [&](PViewDataGModel *d) { return !d->hasFileName(fileName); };
    auto read = [&](PViewDataGModel *d) { return d->readMED(fileName, index); };
    if(!PViewDataGModel::readInView(fieldNames[index], fileName,
                                    PViewDataGModel::NodeData, accept, read)) {
      Msg::Error("Could not read data in MED file");
      return false;
    }
  }

  return true;
}

#else

bool PView::readMED(const std::string &fileName, int fileIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             fileName.c_str());
  return false;
}

#endif

// write the data of a view in a format of a single view
static bool writeData(PViewData *data, const std::string &fileName,
                      int format, bool append)
{
  switch(format) {
  case PView::POS_ASCII: return data->writePOS(fileName, false, false, append);
  case PView::POS_BINARY: return data->writePOS(fileName, true, false, append);
  case PView::POS_PARSED: return data->writePOS(fileName, false, true, append);
  case PView::STL: return data->writeSTL(fileName);
  case PView::TXT: return data->writeTXT(fileName);
  case PView::MSH:
    return data->writeMSH(fileName, CTX::instance()->mesh.mshFileVersion,
                          CTX::instance()->mesh.binary,
                          CTX::instance()->post.saveMesh, append, 0,
                          CTX::instance()->post.saveInterpolationMatrices,
                          CTX::instance()->post.forceNodeData,
                          CTX::instance()->post.forceElementData);
  case PView::MED: return data->writeMED(fileName);
  default: Msg::Error("Unknown view format %d", format); return false;
  }
}

bool PView::write(const std::string &fileName, int format, bool append)
{
  Msg::StatusBar(true, "Writing '%s'...", fileName.c_str());

  if(format == AUTO) {
    std::string ext = SplitFileName(fileName)[2];
    if(ext == ".pos")
      format = CTX::instance()->post.binary ? POS_BINARY : POS_PARSED;
    else if(ext == ".stl")
      format = STL;
    else if(ext == ".msh")
      format = MSH;
    else if(ext == ".med")
      format = MED;
    else if(ext == ".x3d")
      format = X3D;
    else if(ext == ".vtu" || ext == ".pvtu" || ext == ".pvd")
      format = VTU;
    else
      format = TXT;
  }

  // a file for each mesh if there are several, named after its first step
  std::vector<std::string> split = SplitFileName(fileName);
  bool several = savesSeveralMeshes();
  auto name = [&](int step) {
    if(!several) return fileName;
    char s[32];
    snprintf(s, sizeof(s), "_%04d", step);
    return split[0] + split[1] + s + split[2];
  };

  bool ret = true;
  if(format == VTU)
    ret = writeVTU(fileName, CTX::instance()->post.binary, {this});
  else if(format == X3D)
    ret = writeX3D(fileName);
  else if(savesAdapted()) {
    // refined, each step on a mesh of its own
    std::vector<PViewDataList *> steps = getAdaptedSteps();
    for(std::size_t step = 0; step < steps.size(); step++)
      if(steps[step] && !writeData(steps[step], name(step), format, append))
        ret = false;
    doneSaving();
  }
  else if(several) {
    ret = static_cast<PViewDataGModel *>(_data)->forEachMesh([&](int step) {
      return writeData(_data, name(step), format, append);
    });
  }
  else
    ret = writeData(_data, fileName, format, append);

  if(ret) Msg::StatusBar(true, "Done writing '%s'", fileName.c_str());
  return ret;
}

void PView::sendToServer(const std::string &name)
{
  Msg::Info("Sending View[%d] to ONELAB as parameter '%s'", _index,
            name.c_str());
  _data->sendToServer(name);
}

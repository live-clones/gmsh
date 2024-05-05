// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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

bool PView::readMSH(const std::string &fileName, int fileIndex,
                    int partitionToRead)
{
  // TODO: this should be replaced by functions reading each section, called
  // directly from the GModel::readMSH()

  FILE *fp = Fopen(fileName.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  GModel *model = GModel::current();
  if(model->empty()) {
    Msg::Error("Model is empty: please load a mesh before loading the dataset");
    fclose(fp);
    return false;
  }

  char str[256] = "XXX";
  int index = -1;
  bool binary = false, swap = false;

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    if(feof(fp)) break;

    std::string sectionName(&str[1]);
    std::string endSectionName = "End" + sectionName;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      double version;
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return false;
      }
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) {
        fclose(fp);
        return false;
      }
      if(format) {
        binary = true;
        Msg::Debug("View data is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) {
          fclose(fp);
          return 0;
        }
        if(one != 1) {
          swap = true;
          Msg::Debug("Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "PhysicalNames", 13) ||
            !strncmp(&str[1], "Entities", 8) ||
            !strncmp(&str[1], "PartitionedEntities", 19) ||
            !strncmp(&str[1], "Nodes", 5) ||
            !strncmp(&str[1], "Elements", 8) ||
            !strncmp(&str[1], "Periodic", 8) ||
            !strncmp(&str[1], "GhostElements", 13) ||
            !strncmp(&str[1], "Parametrizations", 16)) {
      // skip
    }
    else if(!strncmp(&str[1], "InterpolationScheme", 19)) {
      std::string name;
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return false;
      }
      name = ExtractDoubleQuotedString(str, sizeof(str));
      Msg::Debug("Reading interpolation scheme '%s'", name.c_str());
      PViewData::removeInterpolationScheme(name);
      int numTypes;
      if(fscanf(fp, "%d", &numTypes) != 1) {
        fclose(fp);
        return false;
      }
      for(int i = 0; i < numTypes; i++) {
        int type, numMatrices;
        if(fscanf(fp, "%d %d", &type, &numMatrices) != 2) {
          fclose(fp);
          return false;
        }
        for(int j = 0; j < numMatrices; j++) {
          int m, n;
          if(fscanf(fp, "%d %d", &m, &n) != 2) {
            fclose(fp);
            return false;
          }
          fullMatrix<double> mat(m, n);
          for(int k = 0; k < m; k++) {
            for(int l = 0; l < n; l++) {
              double d;
              if(fscanf(fp, "%lf", &d) != 1) {
                fclose(fp);
                return false;
              }
              mat.set(k, l, d);
            }
          }
          PViewData::addMatrixToInterpolationScheme(name, type, mat);
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      index++;
      if(fileIndex < 0 || fileIndex == index) {
        PViewDataGModel::DataType type;
        if(!strncmp(&str[1], "NodeData", 8))
          type = PViewDataGModel::NodeData;
        else if(!strncmp(&str[1], "ElementData", 11))
          type = PViewDataGModel::ElementData;
        else
          type = PViewDataGModel::ElementNodeData;
        int numTags;
        // string tags
        std::string viewName, interpolationScheme;
        if(!fgets(str, sizeof(str), fp)) {
          fclose(fp);
          return false;
        }
        if(sscanf(str, "%d", &numTags) != 1) {
          fclose(fp);
          return false;
        }
        for(int i = 0; i < numTags; i++) {
          if(!fgets(str, sizeof(str), fp)) {
            fclose(fp);
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
          fclose(fp);
          return false;
        }
        if(sscanf(str, "%d", &numTags) != 1) {
          fclose(fp);
          return false;
        }
        for(int i = 0; i < numTags; i++) {
          if(!fgets(str, sizeof(str), fp)) {
            fclose(fp);
            return false;
          }
          if(i == 0) {
            if(sscanf(str, "%lf", &time) != 1) {
              fclose(fp);
              return false;
            }
          }
        }
        // integer tags
        int timeStep = 0, numComp = 0, numEnt = 0, partition = 0;
        long int blocksize = 0;
        if(!fgets(str, sizeof(str), fp)) {
          fclose(fp);
          return false;
        }
        if(sscanf(str, "%d", &numTags) != 1) {
          fclose(fp);
          return false;
        }
        for(int i = 0; i < numTags; i++) {
          if(!fgets(str, sizeof(str), fp)) {
            fclose(fp);
            return false;
          }
          if(i == 0) {
            if(sscanf(str, "%d", &timeStep) != 1) {
              fclose(fp);
              return false;
            }
          }
          else if(i == 1) {
            if(sscanf(str, "%d", &numComp) != 1) {
              fclose(fp);
              return false;
            }
          }
          else if(i == 2) {
            if(sscanf(str, "%d", &numEnt) != 1) {
              fclose(fp);
              return false;
            }
          }
          else if(i == 3) {
            if(sscanf(str, "%d", &partition) != 1) {
              fclose(fp);
              return false;
            }
          }
          else if(i == 4) {
            if(sscanf(str, "%ld", &blocksize) != 1) {
              fclose(fp);
              return false;
            }
          }
        }
        if(partitionToRead == -1 || partitionToRead == partition) {
          // if default (no particular partition requested from MergeFile -> -1)
          // or if current partition corresponds to the requested partition,
          // read the data
          if(numEnt > 0) {
            // either get existing viewData, or create new one
            PView *p = getViewByName(viewName, timeStep, partition);
            PViewDataGModel *d = nullptr;
            if(p) d = dynamic_cast<PViewDataGModel *>(p->getData());
            bool create = d ? false : true;
            if(create) d = new PViewDataGModel(type);
            if(!d->readMSH(viewName, fileName, fileIndex, fp, binary, swap,
                           timeStep, time, partition, numComp, numEnt,
                           interpolationScheme)) {
              Msg::Error("Could not read data in msh file");
              if(create) delete d;
              fclose(fp);
              return false;
            }
            else {
              d->setName(viewName);
              d->setFileName(fileName);
              d->setFileIndex(index);
              if(create) new PView(d);
            }
          }
        }
        else if(blocksize > 0 && partitionToRead != partition) {
          // if current partition does not correspond to the requested partition
          // and if its blocksise has been read (5th integer in the header),
          // jump over it
          fseek(fp, blocksize, SEEK_CUR);
        }
      }
    }
    else if(strlen(&str[1]) > 0){
      if(!CTX::instance()->mesh.ignoreUnknownSections) {
        sectionName.pop_back();
        Msg::Info("Storing section $%s as model attribute", sectionName.c_str());
        std::vector<std::string> section;
        while(1) {
          if(!fgets(str, sizeof(str), fp) || feof(fp) ||
             !strncmp(&str[1], endSectionName.c_str(), endSectionName.size())) {
            break;
          }
          std::string s(str);
          if(s.back() == '\n') s.pop_back();
          if(s.back() == '\r') s.pop_back();
          section.push_back(s);
        }
        model->getAttributes()[sectionName] = section;
      }
    }

    while(strncmp(&str[1], endSectionName.c_str(), endSectionName.size())) {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) { break; }
    }
    str[0] = 'a';
  }

  fclose(fp);
  return true;
}

#if defined(HAVE_MED)

extern std::vector<std::string> medGetFieldNames(const std::string &fileName);

bool PView::readMED(const std::string &fileName, int fileIndex)
{
  std::vector<std::string> fieldNames = medGetFieldNames(fileName);

  for(std::size_t index = 0; index < fieldNames.size(); index++) {
    if(fileIndex < 0 || (int)index == fileIndex) {
      PViewDataGModel *d = nullptr;
      // we use the filename as a kind of "partition" indicator, allowing to
      // complete datasets provided in separate files (e.g. coming from DDM)
      PView *p = getViewByName(fieldNames[index], -1, -1, fileName);
      if(p) d = dynamic_cast<PViewDataGModel *>(p->getData());
      bool create = d ? false : true;
      if(create) d = new PViewDataGModel();
      if(!d->readMED(fileName, index)) {
        Msg::Error("Could not read data in MED file");
        if(create) delete d;
        return false;
      }
      else {
        if(create) new PView(d);
      }
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

bool PView::readPCH(const std::string &fileName, int fileIndex)
{
  PViewDataGModel::DataType type = PViewDataGModel::NodeData;
  // PViewDataGModel::ElementData;
  // PViewDataGModel::ElementNodeData;
  PViewDataGModel *d = new PViewDataGModel(type);
  d->setFileName(fileName);
  d->readPCH(fileName, fileIndex);
  new PView(d);
  return true;
}

bool PView::write(const std::string &fileName, int format, bool append)
{
  Msg::StatusBar(true, "Writing '%s'...", fileName.c_str());

  bool ret;
  switch(format) {
  case 0: ret = _data->writePOS(fileName, false, false, append); break; // ASCII
  case 1: ret = _data->writePOS(fileName, true, false, append); break; // binary
  case 2: ret = _data->writePOS(fileName, false, true, append); break; // parsed
  case 3: ret = _data->writeSTL(fileName); break;
  case 4: ret = _data->writeTXT(fileName); break;
  case 5:
    ret = _data->writeMSH(fileName, CTX::instance()->mesh.mshFileVersion,
                          CTX::instance()->mesh.binary,
                          CTX::instance()->post.saveMesh, append, 0,
                          CTX::instance()->post.saveInterpolationMatrices,
                          CTX::instance()->post.forceNodeData,
                          CTX::instance()->post.forceElementData);
    break;
  case 6: ret = _data->writeMED(fileName); break;
  case 7: ret = writeX3D(fileName); break;
  case 10: {
    std::string ext = SplitFileName(fileName)[2];
    if(ext == ".pos")
      ret = _data->writePOS(fileName, CTX::instance()->post.binary,
                            !CTX::instance()->post.binary, append);
    else if(ext == ".stl")
      ret = _data->writeSTL(fileName);
    else if(ext == ".msh")
      ret = _data->writeMSH(fileName, CTX::instance()->mesh.mshFileVersion,
                            CTX::instance()->mesh.binary,
                            CTX::instance()->post.saveMesh, append, 0,
                            CTX::instance()->post.saveInterpolationMatrices,
                            CTX::instance()->post.forceNodeData,
                            CTX::instance()->post.forceElementData);
    else if(ext == ".med")
      ret = _data->writeMED(fileName);
    else if(ext == ".x3d")
      ret = writeX3D(fileName);
    else
      ret = _data->writeTXT(fileName);
    break;
  }
  default:
    ret = false;
    Msg::Error("Unknown view format %d", format);
    break;
  }

  if(ret) Msg::StatusBar(true, "Done writing '%s'", fileName.c_str());
  return ret;
}

// Routines for export of adapted views to pvtu file format for parallel
// visualization with paraview.
bool PView::writeAdapt(const std::string &guifileName, int useDefaultName,
                       bool isBinary, int adaptLev, double adaptErr, int npart,
                       bool append)
{
  Msg::StatusBar(true, "Writing '%s'...", guifileName.c_str());
  _data->saveAdaptedViewForVTK(guifileName, useDefaultName, _options->timeStep,
                               adaptLev, adaptErr, npart, isBinary);
  return true;
}

void PView::sendToServer(const std::string &name)
{
  Msg::Info("Sending View[%d] to ONELAB as parameter '%s'", _index,
            name.c_str());
  _data->sendToServer(name);
}

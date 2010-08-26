// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "StringUtils.h"

bool PView::readPOS(std::string fileName, int fileIndex)
{
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  char str[256] = "XXX";
  double version;
  int format, size, index = -1;

  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } 
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "PostFormat", 10)) {

      if(!fscanf(fp, "%lf %d %d\n", &version, &format, &size)){
        Msg::Error("Read error");
        return false;
      }
      if(version < 1.0) {
        Msg::Error("Post-processing file too old (ver. %g < 1.0)", version);
        return false;
      }
      if(size == sizeof(double))
        Msg::Debug("Data is in double precision format (size==%d)", size);
      else {
        Msg::Error("Unknown data size (%d) in post-processing file", size);
        return false;
      }

    }
    else if(!strncmp(&str[1], "View", 4)){
      index++;
      if(fileIndex < 0 || fileIndex == index){
        PViewDataList *d = new PViewDataList();
        if(!d->readPOS(fp, version, format ? true : false)){
          Msg::Error("Could not read data in list format");
          delete d;
          return false;
        }
        else{
          d->setFileName(fileName);
          d->setFileIndex(index);
          new PView(d);
        }
      }

    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');

  }

  fclose(fp);

  return true;
}

bool PView::readMSH(std::string fileName, int fileIndex)
{
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  char str[256] = "XXX";
  int index = -1;
  bool binary = false, swap = false;

  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      double version;
      if(!fgets(str, sizeof(str), fp)) return false;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return false;
      if(format){
        binary = true;
        Msg::Info("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
        if(one != 1){
          swap = true;
          Msg::Info("Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8) ||
            !strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {
      index++;
      if(fileIndex < 0 || fileIndex == index){
        PViewDataGModel::DataType type;
        if(!strncmp(&str[1], "NodeData", 8))
          type = PViewDataGModel::NodeData;
        else if(!strncmp(&str[1], "ElementData", 11))
          type = PViewDataGModel::ElementData;
        else
          type = PViewDataGModel::ElementNodeData;
        int numTags;
        // string tags
        std::string viewName, interpolName;
        if(!fgets(str, sizeof(str), fp)) return false;
        if(sscanf(str, "%d", &numTags) != 1) return false;
        for(int i = 0; i < numTags; i++){
          if(!fgets(str, sizeof(str), fp)) return false;
          if(i == 0) 
            viewName = ExtractDoubleQuotedString(str, sizeof(str));
          else if(i == 1) 
            interpolName = ExtractDoubleQuotedString(str, sizeof(str));
        }
        // double tags
        double time = 0.;
        if(!fgets(str, sizeof(str), fp)) return false;
        if(sscanf(str, "%d", &numTags) != 1) return false;
        for(int i = 0; i < numTags; i++){
          if(!fgets(str, sizeof(str), fp)) return false;
          if(i == 0){
            if(sscanf(str, "%lf", &time) != 1) return false;
          }
        }
        // integer tags
        int timeStep = 0, numComp = 0, numEnt = 0, partition = 0;
        if(!fgets(str, sizeof(str), fp)) return false;
        if(sscanf(str, "%d", &numTags) != 1) return false;
        for(int i = 0; i < numTags; i++){
          if(!fgets(str, sizeof(str), fp)) return false;
          if(i == 0){
            if(sscanf(str, "%d", &timeStep) != 1) return false;
          }
          else if(i == 1){
            if(sscanf(str, "%d", &numComp) != 1) return false;
          }
          else if(i == 2){
            if(sscanf(str, "%d", &numEnt) != 1) return false;
          }
          else if(i == 3){
            if(sscanf(str, "%d", &partition) != 1) return false;
          }
        }
        // either get existing viewData, or create new one
        PView *p = getViewByName(viewName, timeStep, partition);
        PViewDataGModel *d = 0;
        if(p) d = dynamic_cast<PViewDataGModel*>(p->getData());
        bool create = d ? false : true;
        if(create) d = new PViewDataGModel(type);
        if(!d->readMSH(fileName, fileIndex, fp, binary, swap, timeStep, 
                       time, partition, numComp, numEnt)){
          Msg::Error("Could not read data in msh file");
          if(create) delete d;
          return false;
        }
        else{
          d->setName(viewName);
          d->setFileName(fileName);
          d->setFileIndex(index);
          if(create) new PView(d);
        }
      }
    }
    
    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');
  }

  fclose(fp);
  return true;
}

#if defined(HAVE_MED)

extern "C" {
#include <med.h>
}

bool PView::readMED(std::string fileName, int fileIndex)
{
  med_idt fid = MEDouvrir((char*)fileName.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }
  
  med_int numFields = MEDnChamp(fid, 0);

  if(MEDfermer(fid) < 0){
    Msg::Error("Unable to close file '%s'", fileName.c_str());
    return false;
  }

  for(int index = 0; index < numFields; index++){
    if(fileIndex < 0 || index == fileIndex){
      PViewDataGModel *d = new PViewDataGModel();
      if(!d->readMED(fileName, index)){
        Msg::Error("Could not read data in MED file");
        delete d;
        return false;
      }
      else{
        d->setFileName(fileName);
        d->setFileIndex(index);
        new PView(d);
      }
    }
  }

  return true;
}

#else

bool PView::readMED(std::string fileName, int fileIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'", 
      fileName.c_str());
  return false;
}

#endif

bool PView::write(std::string fileName, int format, bool append)
{
  Msg::StatusBar(2, true, "Writing '%s'...", fileName.c_str());
  
  bool ret;
  switch(format){
  case 0: ret = _data->writePOS(fileName, false, false, append); break; // ASCII
  case 1: ret = _data->writePOS(fileName, true, false, append); break; // binary
  case 2: ret = _data->writePOS(fileName, false, true, append); break; // parsed
  case 3: ret = _data->writeSTL(fileName); break;
  case 4: ret = _data->writeTXT(fileName); break;
  case 5: ret = _data->writeMSH(fileName); break;
  case 6: ret = _data->writeMED(fileName); break;
  case 10: 
    {
      std::string ext = SplitFileName(fileName)[2];
      if(ext == ".pos")
        ret = _data->writePOS(fileName, false, true, append);
      else if(ext == ".stl")
        ret = _data->writeSTL(fileName);
      else if(ext == ".msh")
        ret = _data->writeMSH(fileName);
      else if(ext == ".med") 
        ret = _data->writeMED(fileName);
      else
        ret = _data->writeTXT(fileName);
      break;
    }
  default: ret = false; Msg::Error("Unknown view format %d", format); break;
  }
  
  if(ret) Msg::StatusBar(2, true, "Done writing '%s'", fileName.c_str());
  return ret;
}

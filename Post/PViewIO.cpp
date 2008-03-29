// $Id: PViewIO.cpp,v 1.3 2008-03-29 10:19:43 geuzaine Exp $
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

#include "PView.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "StringUtils.h"
#include "Message.h"

bool PView::readPOS(std::string fileName, int fileIndex)
{
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
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
        Msg(GERROR, "Read error");
        return false;
      }
      if(version < 1.0) {
        Msg(GERROR, "Post-processing file too old (ver. %g < 1.0)", version);
        return false;
      }
      if(size == sizeof(double))
        Msg(DEBUG, "Data is in double precision format (size==%d)", size);
      else {
        Msg(GERROR, "Unknown data size (%d) in post-processing file", size);
        return false;
      }
      if(format == 0)
        format = LIST_FORMAT_ASCII;
      else if(format == 1)
        format = LIST_FORMAT_BINARY;
      else {
        Msg(GERROR, "Unknown format for view");
        return false;
      }

    }
    else if(!strncmp(&str[1], "View", 4)){

      index++;
      if(fileIndex < 0 || fileIndex == index){
        PViewDataList *d = new PViewDataList(false);
        if(!d->readPOS(fp, version, format, size)){
          Msg(GERROR, "Could not read data in list format");
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
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
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
        Msg(INFO, "Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
        if(one != 1){
          swap = true;
          Msg(INFO, "Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8)) {
      index++;
      if(fileIndex < 0 || fileIndex == index){
        // read data info
        if(!fgets(str, sizeof(str), fp)) return false;
        std::string name = extractDoubleQuotedString(str, sizeof(str));
        int timeStep, partition, interpolationScheme, numComp, numNodes;
        double time;
        if(!fgets(str, sizeof(str), fp)) return false;
        if(sscanf(str, "%d %lf %d %d %d %d", &timeStep, &time, &partition,
                  &interpolationScheme, &numComp, &numNodes) != 6) return false;
        // either get existing viewData, or create new one
        PView *p = getViewByName(name, timeStep, partition);
        PViewDataGModel *d = 0;
        if(p) d = dynamic_cast<PViewDataGModel*>(p->getData());
        bool create = d ? false : true;
        if(create) d = new PViewDataGModel();
        if(!d->readMSH(fileName, fileIndex, fp, binary, swap, timeStep, 
                       time, partition, numComp, numNodes)){
          Msg(GERROR, "Could not read data in msh file");
          if(create) delete d;
          return false;
        }
        else{
          d->setName(name);
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
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
    return false;
  }
  
  med_int numFields = MEDnChamp(fid, 0);

  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)fileName.c_str());
    return false;
  }

  for(int index = 0; index < numFields; index++){
    if(fileIndex < 0 || index == fileIndex){
      PViewDataGModel *d = new PViewDataGModel();
      if(!d->readMED(fileName, index)){
	Msg(GERROR, "Could not read data in MED file");
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
  Msg(GERROR, "Gmsh must be compiled with MED support to read '%s'", 
      fileName.c_str());
  return false;
}

#endif

bool PView::write(std::string fileName, int format, bool append)
{
  Msg(STATUS2, "Writing '%s'", fileName.c_str());
  
  bool ret;
  switch(format){
  case 0: ret = _data->writePOS(fileName, false, false, append); break; // ASCII
  case 1: ret = _data->writePOS(fileName, true, false, append); break; // binary
  case 2: ret = _data->writePOS(fileName, false, true, append); break; // parsed
  case 3: ret = _data->writeSTL(fileName); break;
  case 4: ret = _data->writeTXT(fileName); break;
  case 5: ret = _data->writeMSH(fileName); break;
  case 6: ret = _data->writeMED(fileName); break;
  default: ret = false; Msg(GERROR, "Unknown view format %d", format); break;
  }
  
  if(ret) Msg(STATUS2, "Wrote '%s'", fileName.c_str());
  return ret;
}

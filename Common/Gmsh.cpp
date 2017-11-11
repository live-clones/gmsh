// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "gmsh.h"
#include "GmshGlobal.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"

// Gmsh

int gmshInitialize(int argc, char **argv)
{
  return !GmshInitialize(argc, argv);
}

int gmshFinalize()
{
  return !GmshFinalize();
}

int gmshOpen(const std::string &fileName)
{
  return !GmshOpenProject(fileName);
}

int gmshMerge(const std::string &fileName)
{
  return !GmshMergeFile(fileName);
}

int gmshExport(const std::string &fileName)
{
  return !GmshWriteFile(fileName);
}

int gmshClear()
{
  return !GmshClearProject();
}

// GmshOption

static void splitOptionName(const std::string &fullName, std::string &category,
                            std::string &name, int &index)
{
  std::string::size_type d = fullName.find_first_of('.');
  category = fullName.substr(0, d);
  std::string::size_type b1 = fullName.find_first_of('[');
  std::string::size_type b2 = fullName.find_last_of(']');
  if(b1 != std::string::npos && b2 != std::string::npos){
    std::string id = fullName.substr(b1, b2 - b1);
    name = fullName.substr(d, b1 - d);
  }
  else{
    index = 0;
    name = fullName.substr(d);
  }
  Msg::Debug("Decoded option name '%s' . '%s' '[%d]'", category.c_str(),
             name.c_str(), index);
}

int gmshOptionSetNumber(const std::string &name, double value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetNumber(const std::string &name, double &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

int gmshOptionSetString(const std::string &name, const std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetString(const std::string &name, std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

// GmshModel

int gmshModelCreate(const std::string &name)
{
  GModel *m = new GModel(name);
  return m ? 0 : 1;
}

int gmshModelSetCurrent(const std::string &name)
{
  GModel *m = GModel::findByName(name);
  if(m){
    GModel::setCurrent(m);
    return 0;
  }
  return 1;
}

int gmshModelDestroy()
{
  GModel *m = GModel::current();
  if(m){
    delete m;
    return 0;
  }
  return 1;
}

int gmshModelMesh(int dim)
{
  GModel *m = GModel::current();
  if(m){
    m->mesh(dim);
    return 0;
  }
  return 1;
}

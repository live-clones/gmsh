// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GMSH_H_
#define _GMSH_H_

#include <string>
#include "GmshMessage.h"

int GmshInitialize(int argc=0, char **argv=0);
int GmshSetMessageHandler(GmshMessage *callback);
GmshMessage *GmshGetMessageHandler();
int GmshSetBoundingBox(double xmin, double xmax,
                       double ymin, double ymax,
                       double zmin, double zmax);
int GmshSetOption(const std::string &category, const std::string &name,
                  std::string value, int index=0);
int GmshSetOption(const std::string &category, const std::string &name,
                  double value, int index=0);
int GmshSetOption(const std::string &category, const std::string &name,
                  unsigned int value, int index=0);
int GmshGetOption(const std::string &category, const std::string &name,
                  std::string &value, int index=0);
int GmshGetOption(const std::string &category, const std::string &name,
                  double &value, int index=0);
int GmshGetOption(const std::string &category, const std::string &name,
                  unsigned int &value, int index=0);
int GmshOpenProject(const std::string &fileName);
int GmshMergeFile(const std::string &fileName);
int GmshMergePostProcessingFile(const std::string &fileName);
int GmshWriteFile(const std::string &fileName);
int GmshFinalize();
int GmshBatch();
int GmshFLTK(int argc=0, char **argv=0);

#endif

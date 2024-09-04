// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GLOBAL_H
#define GMSH_GLOBAL_H

#include <string>
#include "GmshMessage.h"

int GmshInitialize(int argc = 0, char **argv = nullptr, bool readConfigFiles = false,
                   bool exitOnCommandLineError = true);
int GmshSetMessageHandler(GmshMessage *callback);
GmshMessage *GmshGetMessageHandler();
int GmshSetBoundingBox(double xmin, double xmax, double ymin, double ymax,
                       double zmin, double zmax);
int GmshSetOption(const std::string &category, const std::string &name,
                  std::string value, int index = 0);
int GmshSetOption(const std::string &category, const std::string &name,
                  double value, int index = 0);
int GmshSetOption(const std::string &category, const std::string &name,
                  unsigned int value, int index = 0);
void GmshSetStringOption(const std::string &category, const std::string &name,
                         std::string value, int index = 0);
void GmshSetNumberOption(const std::string &category, const std::string &name,
                         double value, int index = 0);
void GmshSetColorOption(const std::string &category, const std::string &name,
                        unsigned int value, int index = 0);
int GmshGetOption(const std::string &category, const std::string &name,
                  std::string &value, int index = 0);
int GmshGetOption(const std::string &category, const std::string &name,
                  double &value, int index = 0);
int GmshGetOption(const std::string &category, const std::string &name,
                  unsigned int &value, int index = 0);
std::string GmshGetStringOption(const std::string &category,
                                const std::string &name, int index = 0);
double GmshGetNumberOption(const std::string &category, const std::string &name,
                           int index = 0);
unsigned int GmshGetColorOption(const std::string &category,
                                const std::string &name, int index = 0);
int GmshRestoreDefaultOptions();
int GmshOpenProject(const std::string &fileName);
int GmshClearProject();
int GmshMergeFile(const std::string &fileName);
int GmshMergePostProcessingFile(const std::string &fileName);
int GmshWriteFile(const std::string &fileName);
int GmshFinalize();
int GmshBatch();
int GmshFLTK(int argc = 0, char **argv = nullptr);

// these two functions are the only functions exported in addition to the
// functions of the official stable API, so that we can also build the main Gmsh
// binary directly from the DLL

#if defined(GMSH_DLL)
#if defined(GMSH_DLL_EXPORT)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
#define GMSH_API __attribute__ ((visibility("default")))
#else
#define GMSH_API
#endif

GMSH_API int GmshMainBatch(int argc, char **argv);
GMSH_API int GmshMainFLTK(int argc, char **argv);

#endif

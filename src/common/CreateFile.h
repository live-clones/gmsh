// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <string>

int GetFileFormatFromExtension(const std::string &fileName,
                               double *version = nullptr);
int GuessFileFormatFromFileName(const std::string &fileName,
                                double *version = nullptr);
std::string GetDefaultFileExtension(int format, bool onlyMeshFormats = false);
std::string GetDefaultFileName(int format);
std::string GetKnownFileFormats(bool onlyMeshFormats = false);
void CreateOutputFile(const std::string &fileName, int format,
                      bool status = true);

#endif

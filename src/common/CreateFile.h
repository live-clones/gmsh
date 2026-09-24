// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <string>
#include <vector>

int GetFileFormatFromExtension(const std::string &fileName,
                               double *version = nullptr);
int GuessFileFormatFromFileName(const std::string &fileName,
                                double *version = nullptr);
std::string GetDefaultFileExtension(int format, bool onlyMeshFormats = false);
std::string GetDefaultFileName(int format);
std::string GetKnownFileFormats(bool onlyMeshFormats = false);
void CreateOutputFile(const std::string &fileName, int format,
                      bool status = true);

// When what is saved as fileName makes several files (next to it), write
// fileName.geo, the script that reads them back as they were: each file merged
// in a model of its own if its flag says so (a file with a mesh: the last one
// is then current, as the model saved), or else in the current one (views in
// POS files, partitions of a mesh)
void CreateReadBackScript(const std::string &fileName,
                          const std::vector<std::pair<std::string, bool> > &files);

#endif

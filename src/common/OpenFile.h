// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPENFILE_H
#define OPENFILE_H

#include <string>

int ParseFile(const std::string &fileName, bool close,
              bool errorIfMissing = false);
void ParseString(const std::string &str, bool inCurrentModelDir = false);
void OpenProject(const std::string &filename, bool errorIfMissing = false);
void OpenProjectMacFinder(const char *fileName);
int MergeFile(const std::string &fileName, bool errorIfMissing = false,
              bool setBoundingBox = true, bool importPhysicalsInOnelab = true,
              int partitionToRead = -1);
int MergePostProcessingFile(const std::string &fileName, int showViews = 2,
                            bool showLastStep = false,
                            bool errorIfMissing = false);
void DeleteAllModelsAndViews();
void ClearProject();
void SetBoundingBox(double xmin, double xmax, double ymin, double ymax,
                    double zmin, double zmax);
void SetBoundingBox(bool aroundVisible = false);
void AddToTemporaryBoundingBox(double x, double y, double z);

#endif

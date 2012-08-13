// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OPENFILE_H_
#define _OPENFILE_H_

#include <string>

int ParseFile(const std::string & fileName, bool close, bool warnIfMissing=false);
void ParseString(const std::string & str);
void OpenProject(const std::string &filename);
void OpenProjectMacFinder(const char *fileName);
int MergeFile(const std::string &fileName, bool warnIfMissing=false);
int MergePostProcessingFile(const std::string &fileName, bool showLastStep=false,
                            bool hideNewViews=false, bool warnIfMissing=false);
void ClearProject();
void SetBoundingBox(double xmin, double xmax,
                    double ymin, double ymax,
                    double zmin, double zmax);
void SetBoundingBox(bool aroundVisible=false);
void AddToTemporaryBoundingBox(double x, double y, double z);

#endif

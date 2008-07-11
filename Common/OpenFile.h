// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OPENFILE_H_
#define _OPENFILE_H_

int ParseFile(const char *filename, int close, int warn_if_missing=0);
void ParseString(const char *str);
void OpenProject(const char *filename);
void OpenProjectMacFinder(const char *filename);
int MergeFile(const char *filename, int warn_if_missing=0);
void SetBoundingBox(double xmin, double xmax,
                    double ymin, double ymax, 
                    double zmin, double zmax);
void SetBoundingBox();
void AddToTemporaryBoundingBox(double x, double y, double z);

#endif

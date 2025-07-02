// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef READ_IMG
#define READ_IMG

#include <string>

int read_pnm(const std::string &fileName);
int read_jpeg(const std::string &fileName);
int read_png(const std::string &fileName);
int read_bmp(const std::string &fileName);

#endif

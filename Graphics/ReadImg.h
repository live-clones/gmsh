// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _READ_IMG_
#define _READ_IMG_

int read_pnm(const char *name);
int read_jpeg(const char *name);
int read_png(const char *name);
int read_bmp(const char *name);

#endif

// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FILE_DIALOGS_H_
#define _FILE_DIALOGS_H_

#include <string>

typedef enum {
  FILE_CHOOSER_SINGLE, 
  FILE_CHOOSER_MULTI, 
  FILE_CHOOSER_CREATE, 
  FILE_CHOOSER_DIRECTORY 
} FILE_CHOOSER_TYPE;

int fileChooser(FILE_CHOOSER_TYPE type, const char *message,
                const char *pat, const char *fname=NULL);
std::string fileChooserGetName(int num);
int fileChooserGetFilter();
void fileChooserGetPosition(int *x, int *y);

int jpegFileDialog(const char *filename);
int mpegFileDialog(const char *filename);
int gifFileDialog(const char *filename);
int geoFileDialog(const char *filename);
int genericBitmapFileDialog(const char *filename, const char *title, int format);
int genericMeshFileDialog(const char *filename, const char *title, int format,
                          bool binary_support, bool element_tag_support);
int posFileDialog(const char *name);
int genericViewFileDialog(const char *name, const char *title, int format);
int gl2psFileDialog(const char *filename, const char *title, int format);
int optionsFileDialog(const char *filename);
int meshStatFileDialog(const char *filename);
int mshFileDialog(const char *filename);
int unvFileDialog(const char *filename);
int bdfFileDialog(const char *filename);
int latexFileDialog(const char *filename);
int cgnsFileDialog(const char *filename);

#endif

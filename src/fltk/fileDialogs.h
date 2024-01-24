// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILE_DIALOGS_H
#define FILE_DIALOGS_H

#include <string>

typedef enum {
  FILE_CHOOSER_SINGLE,
  FILE_CHOOSER_MULTI,
  FILE_CHOOSER_CREATE,
  FILE_CHOOSER_DIRECTORY
} FILE_CHOOSER_TYPE;

int fileChooser(FILE_CHOOSER_TYPE type, const char *message, const char *pat,
                const char *fname = nullptr);
std::string fileChooserGetName(int num);
int fileChooserGetFilter();
void fileChooserGetPosition(int *x, int *y);

int mpegFileDialog(const char *filename);
int gifFileDialog(const char *filename);
int geoFileDialog(const char *filename);
int genericBitmapFileDialog(const char *filename, const char *title,
                            int format);
int pgfBitmapFileDialog(const char *filename, const char *title, int format);
int genericMeshFileDialog(const char *filename, const char *title, int format,
                          bool binary_support, bool element_tag_support);
int posFileDialog(const char *name);
int x3dViewFileDialog(const char *name, const char *title, int format);
int pvtuAdaptFileDialog(const char *name);
int genericViewFileDialog(const char *name, const char *title, int format);
int gl2psFileDialog(const char *filename, const char *title, int format);
int optionsFileDialog(const char *filename);
int meshStatFileDialog(const char *filename);
int mshFileDialog(const char *filename);
int stlFileDialog(const char *filename);
void format_cb(Fl_Widget *widget, void *data);
int unvinpFileDialog(const char *filename, const char *title, int format);
int keyFileDialog(const char *filename, const char *title, int format);
int radFileDialog(const char *filename, const char *title, int format);
int bdfFileDialog(const char *filename);
int latexFileDialog(const char *filename);
int cgnsFileDialog(const char *filename);

#endif

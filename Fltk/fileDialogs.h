// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FILE_DIALOGS_H_
#define _FILE_DIALOGS_H_

#include <string>

int file_chooser(int multi, int create, const char *message,
                 const char *pat, const char *fname=NULL);
std::string file_chooser_get_name(int num);
int file_chooser_get_filter();
void file_chooser_get_position(int *x, int *y);

int jpeg_dialog(const char *filename);
int gif_dialog(const char *filename);
int geo_dialog(const char *filename);
int generic_bitmap_dialog(const char *filename, const char *title, int format);
int generic_mesh_dialog(const char *filename, const char *title, int format,
			bool binary_supports);
int gl2ps_dialog(const char *filename, const char *title, int format);
int options_dialog(const char *filename);
int pos_dialog(const char *filename);
int msh_dialog(const char *filename);
int unv_dialog(const char *filename);
int bdf_dialog(const char *filename);
int latex_dialog(const char *filename);
int cgns_write_dialog(const char *filename);

#endif

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DRAW_H_
#define _DRAW_H_

#include <string>

void SetOpenglContext(int index=0);
void ClearOpengl();
void Draw();
void Draw2d3d(int index=0);
void DrawPlugin(void (*draw)(void *context));
void GetStoredViewport(int viewport[4], int index=0);
int GetFontIndex(const char *fontname);
int GetFontEnum(int index);
const char *GetFontName(int index);
int GetFontAlign(const char *alignstr);
int GetFontSize();


#endif

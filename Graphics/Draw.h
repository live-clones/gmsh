// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DRAW_H_
#define _DRAW_H_

// Widget-toolkit-dependent drawing functions (need to be redefined
// for each widget toolkit: FLTK, Qt, etc.)

void Draw();
void DrawPlugin(void (*draw)(void *context));
void DrawCurrentOpenglWindow(bool make_current);
int GetFontIndex(const char *fontname);
int GetFontEnum(int index);
const char *GetFontName(int index);
int GetFontAlign(const char *alignstr);
int GetFontSize();
void SetFont(int fontid, int fontsize);
double GetStringWidth(const char *str);
int GetStringHeight();
int GetStringDescent();
void DrawString(const char *str);

#endif

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DRAW_H_
#define _DRAW_H_

#include <string>

void SetOpenglContext();
void ClearOpengl();

void Draw();
void Draw2d3d();
void DrawPlugin(void (*draw)(void *context));

void Draw_String(std::string);
void Draw_String(std::string, double style);
void Draw_String_Center(std::string);
void Draw_String_Right(std::string);
void Draw_OnScreenMessages();

void GetStoredViewport(int viewport[4]);
void Viewport2World(double win[3], double xyz[3]);
void World2Viewport(double xyz[3], double win[3]);

#endif

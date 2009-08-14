// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "QGui.h"
#include "gl2ps.h"
#include "Context.h"
#include "drawContext.h"

void Draw()
{
  drawContext *ctx = QGui::instance()->getDrawContext();
  ctx->draw3d();
  ctx->draw2d();
}

void DrawCurrentOpenglWindow(bool make_current)
{
}

void DrawPlugin(void (*draw)(void *context))
{
}

int GetFontIndex(const char *fontname)
{
  return 0;
}

int GetFontEnum(int index)
{
  return 0;
}

const char *GetFontName(int index)
{
  return "Helvetica";
}

int GetFontAlign(const char *alignstr)
{
  return 0;
}

int GetFontSize()
{
  return 14;
}

void SetFont(int fontid, int fontsize)
{
}

double GetStringWidth(const char *str)
{
  return 14.;
}

int GetStringHeight()
{
  return 14.;
}

int GetStringDescent()
{
  return 10.;
}

void DrawString(const char *str)
{
}

// $Id: CreateFile.cpp,v 1.40 2003-03-07 18:53:21 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "OpenFile.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"

extern Context_T CTX;
extern Mesh M;

#include "gl2ps.h"
#include "gl2gif.h"
#include "gl2jpeg.h"
#include "gl2ppm.h"
#include "gl2yuv.h"

void FillBuffer(void)
{
  InitOpengl();
  ClearOpengl();
  Draw3d();
  Draw2d();
}

void CreateOutputFile(char *name, int format)
{
  FILE *fp;
  GLint size3d;
  char ext[256];
  int res, i, oldformat, psformat, pssort, psoptions;

  if(!name || !strlen(name))
    return;

  oldformat = CTX.print.format;
  CTX.print.format = format;

  switch (format) {

  case FORMAT_AUTO:
    for(i = strlen(name) - 1; i >= 0; i--) {
      if(name[i] == '.') {
        strcpy(ext, &name[i]);
        break;
      }
    }
    if(i <= 0)
      strcpy(ext, "");

    if(!strcmp(ext, ".geo"))
      CreateOutputFile(name, FORMAT_GEO);
    else if(!strcmp(ext, ".opt"))
      CreateOutputFile(name, FORMAT_OPT);
    else if(!strcmp(ext, ".msh"))
      CreateOutputFile(name, FORMAT_MSH);
    else if(!strcmp(ext, ".unv"))
      CreateOutputFile(name, FORMAT_UNV);
    else if(!strcmp(ext, ".gif"))
      CreateOutputFile(name, FORMAT_GIF);
    else if(!strcmp(ext, ".jpg"))
      CreateOutputFile(name, FORMAT_JPEG);
    else if(!strcmp(ext, ".jpeg"))
      CreateOutputFile(name, FORMAT_JPEG);
    else if(!strcmp(ext, ".ps"))
      CreateOutputFile(name, FORMAT_PS);
    else if(!strcmp(ext, ".eps"))
      CreateOutputFile(name, FORMAT_EPS);
    else if(!strcmp(ext, ".tex"))
      CreateOutputFile(name, FORMAT_TEX);
    else if(!strcmp(ext, ".pstex"))
      CreateOutputFile(name, FORMAT_PSTEX);
    else if(!strcmp(ext, ".epstex"))
      CreateOutputFile(name, FORMAT_EPSTEX);
    else if(!strcmp(ext, ".jpegtex"))
      CreateOutputFile(name, FORMAT_JPEGTEX);
    else if(!strcmp(ext, ".ppm"))
      CreateOutputFile(name, FORMAT_PPM);
    else if(!strcmp(ext, ".yuv"))
      CreateOutputFile(name, FORMAT_YUV);
    else if(!strcmp(ext, ".gref"))
      CreateOutputFile(name, FORMAT_GREF);
    else if(!strcmp(ext, ".Gref"))
      CreateOutputFile(name, FORMAT_GREF);
    else if(!strcmp(ext, ".wrl"))
      CreateOutputFile(name, FORMAT_VRML);
    else
      Msg(GERROR, "Unknown extension '%s' for automatic format detection",
          ext);
    break;

  case FORMAT_GEO:
    Print_Geo(&M, name);
    break;

  case FORMAT_OPT:
    Print_Options(0, GMSH_FULLRC, name);
    break;

  case FORMAT_MSH:
    Print_Mesh(&M, name, FORMAT_MSH);
    break;

  case FORMAT_UNV:
    Print_Mesh(&M, name, FORMAT_UNV);
    break;

  case FORMAT_GREF:
    Print_Mesh(&M, name, FORMAT_GREF);
    break;

  case FORMAT_VRML:
    Print_Mesh(&M, name, FORMAT_VRML);
    break;

  case FORMAT_JPEG:
  case FORMAT_JPEGTEX:
    if(!(fp = fopen(name, "wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    if(format == FORMAT_JPEGTEX)
      CTX.print.gl_fonts = 0;
    FillBuffer();
    CTX.print.gl_fonts = 1;
    create_jpeg(fp, CTX.viewport[2] - CTX.viewport[0],
                CTX.viewport[3] - CTX.viewport[1], CTX.print.jpeg_quality);
    Msg(INFO, "JPEG creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_GIF:
    if(!(fp = fopen(name, "wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    FillBuffer();
    create_gif(fp, CTX.viewport[2] - CTX.viewport[0],
               CTX.viewport[3] - CTX.viewport[1],
               CTX.print.gif_dither,
               CTX.print.gif_sort,
               CTX.print.gif_interlace,
               CTX.print.gif_transparent,
               UNPACK_RED(CTX.color.bg),
               UNPACK_GREEN(CTX.color.bg), UNPACK_BLUE(CTX.color.bg));
    Msg(INFO, "GIF creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_PPM:
    if(!(fp = fopen(name, "wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    FillBuffer();
    create_ppm(fp, CTX.viewport[2] - CTX.viewport[0],
               CTX.viewport[3] - CTX.viewport[1]);
    Msg(INFO, "PPM creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_YUV:
    if(!(fp = fopen(name, "wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    FillBuffer();
    create_yuv(fp, CTX.viewport[2] - CTX.viewport[0],
               CTX.viewport[3] - CTX.viewport[1]);
    Msg(INFO, "YUV creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_PS:
  case FORMAT_PSTEX:
  case FORMAT_EPS:
  case FORMAT_EPSTEX:
    if(!(fp = fopen(name, "w"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    psformat = (format == FORMAT_PS || format == FORMAT_PSTEX) ? GL2PS_PS : GL2PS_EPS;
    pssort = (CTX.print.eps_quality == 1) ? GL2PS_SIMPLE_SORT : GL2PS_BSP_SORT;
    psoptions =
      GL2PS_SIMPLE_LINE_OFFSET | GL2PS_SILENT | 
      (CTX.print.eps_occlusion_culling ? GL2PS_OCCLUSION_CULL : 0) |
      (CTX.print.eps_best_root ? GL2PS_BEST_ROOT : 0) |
      (CTX.print.eps_background ? GL2PS_DRAW_BACKGROUND : 0) |
      (format == FORMAT_PSTEX ? GL2PS_NO_TEXT : 0) |
      (format == FORMAT_EPSTEX ? GL2PS_NO_TEXT : 0);

    size3d = 0;
    res = GL2PS_OVERFLOW;
    while(res == GL2PS_OVERFLOW) {
      size3d += 2048 * 2048;
      gl2psBeginPage(CTX.base_filename, "Gmsh", CTX.viewport, 
		     psformat, pssort, psoptions, GL_RGBA, 0, NULL, 
		     0, 0, 0, size3d, fp, name);
      CTX.print.gl_fonts = 0;
      FillBuffer();
      CTX.print.gl_fonts = 1;
      res = gl2psEndPage();
    }
    Msg(INFO, "PS/EPS creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_TEX:
    if(!(fp = fopen(name, "w"))) {
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    gl2psBeginPage(CTX.base_filename, "Gmsh", CTX.viewport,
                   GL2PS_TEX, GL2PS_NO_SORT, GL2PS_NONE, GL_RGBA, 0, NULL, 
		   0, 0, 0, 1, fp, name);
    CTX.print.gl_fonts = 0;
    FillBuffer();
    CTX.print.gl_fonts = 1;
    res = gl2psEndPage();
    Msg(INFO, "TEX creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  default:
    Msg(WARNING, "Unknown print format");
    break;
  }

  CTX.print.format = oldformat;

}

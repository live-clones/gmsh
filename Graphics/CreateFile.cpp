// $Id: CreateFile.cpp,v 1.77 2006-05-17 01:19:05 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "OpenFile.h"
#include "Context.h"
#include "Options.h"

#include "gl2ps.h"
#include "gl2gif.h"
#include "gl2jpeg.h"
#include "gl2png.h"
#include "gl2ppm.h"
#include "gl2yuv.h"

extern Context_T CTX;
extern Mesh M;

int GuessFileFormatFromFileName(char *name)
{
  int len;
  char ext[256];

  for(len = strlen(name) - 1; len >= 0; len--) {
    if(name[len] == '.') {
      strcpy(ext, &name[len]);
      break;
    }
  }
  if(len <= 0)
    strcpy(ext, "");
  
  if(!strcmp(ext, ".geo"))          return FORMAT_GEO;
  else if(!strcmp(ext, ".opt"))     return FORMAT_OPT;
  else if(!strcmp(ext, ".msh"))     return FORMAT_MSH;
  else if(!strcmp(ext, ".unv"))     return FORMAT_UNV;
  else if(!strcmp(ext, ".p3d"))     return FORMAT_P3D;
  else if(!strcmp(ext, ".dmg"))     return FORMAT_DMG;
  else if(!strcmp(ext, ".stl"))     return FORMAT_STL;
  else if(!strcmp(ext, ".pos"))     return FORMAT_LC;
  else if(!strcmp(ext, ".gif"))     return FORMAT_GIF;
  else if(!strcmp(ext, ".jpg"))     return FORMAT_JPEG;
  else if(!strcmp(ext, ".jpeg"))    return FORMAT_JPEG;
  else if(!strcmp(ext, ".png"))     return FORMAT_PNG;
  else if(!strcmp(ext, ".ps"))      return FORMAT_PS;
  else if(!strcmp(ext, ".eps"))     return FORMAT_EPS;
  else if(!strcmp(ext, ".pdf"))     return FORMAT_PDF;
  else if(!strcmp(ext, ".tex"))     return FORMAT_TEX;
  else if(!strcmp(ext, ".epstex"))  return FORMAT_EPSTEX;
  else if(!strcmp(ext, ".pdftex"))  return FORMAT_PDFTEX;
  else if(!strcmp(ext, ".jpegtex")) return FORMAT_JPEGTEX;
  else if(!strcmp(ext, ".ppm"))     return FORMAT_PPM;
  else if(!strcmp(ext, ".yuv"))     return FORMAT_YUV;
  else if(!strcmp(ext, ".gref"))    return FORMAT_GREF;
  else if(!strcmp(ext, ".Gref"))    return FORMAT_GREF;
  else if(!strcmp(ext, ".wrl"))     return FORMAT_VRML;
  else                              return -1;
}

void CreateOutputFile(char *name, int format)
{
  FILE *fp;
  GLint size3d, viewport[4], width, height;
  int res, oldformat, psformat, pssort, psoptions;

  if(!name || !strlen(name))
    return;

  oldformat = CTX.print.format;
  CTX.print.format = format;

  for(int i = 0; i < 4; i++) viewport[i] = CTX.viewport[i];
  width = viewport[2]-viewport[0];
  height = viewport[3]-viewport[1];
  
  switch (format) {

  case FORMAT_AUTO:
    CreateOutputFile(name, GuessFileFormatFromFileName(name));
    break;
    
  case FORMAT_GEO:
    Print_Geo(&M, name);
    break;

  case FORMAT_OPT:
    Print_Options(0, GMSH_FULLRC, 1, 1, name);
    break;

  case FORMAT_MSH:
  case FORMAT_UNV:
  case FORMAT_P3D:
  case FORMAT_DMG:
  case FORMAT_STL:
  case FORMAT_GREF:
  case FORMAT_VRML:
    Print_Mesh(&M, name, format);
    break;

  case FORMAT_LC:
    ExportMeshStatistics(&M, name);
    Msg(STATUS2N, "Wrote '%s'", name);
    break;

  case FORMAT_PPM:
  case FORMAT_YUV:
  case FORMAT_GIF:  
  case FORMAT_JPEG:
  case FORMAT_JPEGTEX:
  case FORMAT_PNG:
  case FORMAT_PNGTEX:
    {
      if(!(fp = fopen(name, "wb"))) {
	Msg(GERROR, "Unable to open file '%s'", name);
	return;
      }

      if(format == FORMAT_JPEGTEX || format == FORMAT_PNGTEX)
	CTX.print.gl_fonts = 0;

      PixelBuffer buffer(width, height, GL_RGB, GL_UNSIGNED_BYTE);
      buffer.Fill();

      CTX.print.gl_fonts = 1;
      if(format == FORMAT_PPM){
	Msg(INFO, "Writing PPM file '%s'", name);
	create_ppm(fp, &buffer);
	Msg(INFO, "Wrote PPM file '%s'", name);
      }
      else if (format == FORMAT_YUV){
	Msg(INFO, "Writing YUV file '%s'", name);
	create_yuv(fp, &buffer);
	Msg(INFO, "Wrote YUV file '%s'", name);
      }
      else if (format == FORMAT_GIF){
	Msg(INFO, "Writing GIF file '%s'", name);
	create_gif(fp, &buffer,
		   CTX.print.gif_dither,
		   CTX.print.gif_sort,
		   CTX.print.gif_interlace,
		   CTX.print.gif_transparent,
		   CTX.UNPACK_RED(CTX.color.bg),
		   CTX.UNPACK_GREEN(CTX.color.bg), 
		   CTX.UNPACK_BLUE(CTX.color.bg));
	Msg(INFO, "Wrote GIF file '%s'", name);
      }
      else if(format == FORMAT_JPEG || format == FORMAT_JPEGTEX){
	Msg(INFO, "Writing JPEG file '%s'", name);
	create_jpeg(fp, &buffer, CTX.print.jpeg_quality, CTX.print.jpeg_smoothing);
	Msg(INFO, "Wrote JPEG file '%s'", name);
      }
      else{
	Msg(INFO, "Writing PNG file '%s'", name);
	create_png(fp, &buffer, 100);
	Msg(INFO, "Wrote PNG file '%s'", name);
      }
      
      Msg(STATUS2N, "Wrote '%s'", name);
      fclose(fp);
    }
    break;

  case FORMAT_PS:
  case FORMAT_EPS:
  case FORMAT_EPSTEX:
  case FORMAT_PDF:
  case FORMAT_PDFTEX:
    {
      if(!(fp = fopen(name, "wb"))) {
	Msg(GERROR, "Unable to open file '%s'", name);
	return;
      }
      
      switch(format){
      case FORMAT_PDF:
      case FORMAT_PDFTEX:
	psformat = GL2PS_PDF;
	break;
      case FORMAT_PS:
	psformat = GL2PS_PS;
	break;
      default:
	psformat = GL2PS_EPS;
	break;
      }
      
      PixelBuffer buffer(width, height, GL_RGB, GL_FLOAT);
      
      if(CTX.print.eps_quality == 0){
	if(format == FORMAT_EPSTEX || format == FORMAT_PDFTEX)
	  CTX.print.gl_fonts = 0;
	buffer.Fill();
	CTX.print.gl_fonts = 1;
      }
      
      pssort = (CTX.print.eps_quality == 2) ? GL2PS_BSP_SORT : GL2PS_SIMPLE_SORT;
      psoptions =
	GL2PS_SIMPLE_LINE_OFFSET | GL2PS_SILENT | GL2PS_NO_BLENDING |
	(CTX.print.eps_occlusion_culling ? GL2PS_OCCLUSION_CULL : 0) |
	(CTX.print.eps_best_root ? GL2PS_BEST_ROOT : 0) |
	(CTX.print.eps_background ? GL2PS_DRAW_BACKGROUND : 0) |
	(CTX.print.eps_compress ? GL2PS_COMPRESS : 0) |
	(CTX.print.eps_ps3shading ? 0 : GL2PS_NO_PS3_SHADING) |
	(format == FORMAT_EPSTEX ? GL2PS_NO_TEXT : 0) |
	(format == FORMAT_PDFTEX ? GL2PS_NO_TEXT : 0);
      
      Msg(INFO, "Writing %s file '%s'", (psformat == GL2PS_PDF) ? "PDF" : "PS/EPS", name);
      
      size3d = 0;
      res = GL2PS_OVERFLOW;
      while(res == GL2PS_OVERFLOW) {
	size3d += 2048 * 2048;
	gl2psBeginPage(CTX.base_filename, "Gmsh", viewport, 
		       psformat, pssort, psoptions, GL_RGBA, 0, NULL, 
		       15, 20, 10, size3d, fp, name);
	if(CTX.print.eps_quality == 0){
	  double modelview[16], projection[16];
	  glGetDoublev(GL_PROJECTION_MATRIX, projection);
	  glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
		  (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
	  glMatrixMode(GL_MODELVIEW);
	  glLoadIdentity();
	  glRasterPos2d(0, 0);
	  gl2psDrawPixels(width, height, 0, 0, GL_RGB, GL_FLOAT, buffer.GetPixels());
	  glMatrixMode(GL_PROJECTION);
	  glLoadMatrixd(projection);
	  glMatrixMode(GL_MODELVIEW);
	  glLoadMatrixd(modelview);
	}
	else{
	  CTX.print.gl_fonts = 0;
	  buffer.Fill();
	  CTX.print.gl_fonts = 1;
	}
	res = gl2psEndPage();
      }

      Msg(INFO, "Wrote %s file '%s'", (psformat == GL2PS_PDF) ? "PDF" : "PS/EPS", name);
      Msg(STATUS2N, "Wrote '%s'", name);
      fclose(fp);
    }
    break;

  case FORMAT_TEX:
    {
      if(!(fp = fopen(name, "w"))) {
	Msg(GERROR, "Unable to open file '%s'", name);
	return;
      }
      Msg(INFO, "Writing TEX file '%s'", name);
      gl2psBeginPage(CTX.base_filename, "Gmsh", viewport,
		     GL2PS_TEX, GL2PS_NO_SORT, GL2PS_SILENT, GL_RGBA, 0, NULL, 
		     0, 0, 0, 1000, fp, name);
      CTX.print.gl_fonts = 0;
      PixelBuffer buffer(width, height, GL_RGB, GL_UNSIGNED_BYTE);
      buffer.Fill();
      CTX.print.gl_fonts = 1;
      res = gl2psEndPage();
      Msg(INFO, "Wrote TEX file '%s'", name);
      Msg(STATUS2N, "Wrote '%s'", name);
      fclose(fp);
    }
    break;

  default:
    Msg(GERROR, "Unknown output file format (%d)", format);
    break;
  }

  CTX.print.format = oldformat;
}

// $Id: CreateFile.cpp,v 1.23 2001-11-19 09:29:18 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "OpenFile.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"

extern Context_T   CTX;
extern Mesh        M;

#include "gl2ps.h"
#include "gl2gif.h"
#include "gl2jpeg.h"
#include "gl2ppm.h"
#include "gl2yuv.h"

void FillBuffer(void){
  InitOpengl();
  ClearOpengl();
  Draw3d();
  Draw2d();
}

void CreateOutputFile (char *name, int format) {
  FILE    *fp;
  GLint    size3d;
  char     ext[256];
  int      res, i;

  if(!name || !strlen(name)) return;

  CTX.print.gl_fonts = 1;

  switch(format){

  case FORMAT_AUTO :
    for(i=strlen(name)-1; i>=0; i--){
      if(name[i] == '.'){
	strcpy(ext,&name[i]);
	break;
      }
    }
    if(i<=0) strcpy(ext,"");

    if     (!strcmp(ext,".geo")) CreateOutputFile(name, FORMAT_GEO);
    else if(!strcmp(ext,".opt")) CreateOutputFile(name, FORMAT_OPT);
    else if(!strcmp(ext,".msh")) CreateOutputFile(name, FORMAT_MSH);
    else if(!strcmp(ext,".unv")) CreateOutputFile(name, FORMAT_UNV);
    else if(!strcmp(ext,".gif")) CreateOutputFile(name, FORMAT_GIF);
    else if(!strcmp(ext,".jpg")) CreateOutputFile(name, FORMAT_JPEG);
    else if(!strcmp(ext,".jpeg")) CreateOutputFile(name, FORMAT_JPEG);
    else if(!strcmp(ext,".ps")) CreateOutputFile(name, FORMAT_PS);
    else if(!strcmp(ext,".eps")) CreateOutputFile(name, FORMAT_PS);
    else if(!strcmp(ext,".tex")) CreateOutputFile(name, FORMAT_TEX);
    else if(!strcmp(ext,".pstex")) CreateOutputFile(name, FORMAT_PSTEX);
    else if(!strcmp(ext,".ppm")) CreateOutputFile(name, FORMAT_PPM);
    else if(!strcmp(ext,".yuv")) CreateOutputFile(name, FORMAT_YUV);
    else if(!strcmp(ext,".gref")) CreateOutputFile(name, FORMAT_GREF);
    else if(!strcmp(ext,".Gref")) CreateOutputFile(name, FORMAT_GREF);
    else Msg(GERROR, "Unknown extension '%s' for automatic format detection", ext);
    break;

  case FORMAT_GEO :
    Print_Geo(&M, name);
    break;

  case FORMAT_OPT :
    Print_Options(0,GMSH_FULLRC, name); 
    break;

  case FORMAT_MSH :
    Print_Mesh(&M, name, FORMAT_MSH); 
    break;

  case FORMAT_UNV :
    Print_Mesh(&M, name, FORMAT_UNV); 
    break;
    
  case FORMAT_GREF :
    Print_Mesh(&M, name, FORMAT_GREF); 
    break;

  case FORMAT_JPEG :
    if(!(fp = fopen(name,"wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    FillBuffer();
    create_jpeg(fp, CTX.viewport[2]-CTX.viewport[0],
		CTX.viewport[3]-CTX.viewport[1],
		CTX.print.jpeg_quality);
    Msg(INFO, "JPEG creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_GIF :
    if(!(fp = fopen(name,"wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    FillBuffer();
    create_gif(fp, CTX.viewport[2]-CTX.viewport[0],
               CTX.viewport[3]-CTX.viewport[1], 
	       CTX.print.gif_dither,
	       CTX.print.gif_sort, 
	       CTX.print.gif_interlace,
	       CTX.print.gif_transparent,
	       UNPACK_RED(CTX.color.bg),
	       UNPACK_GREEN(CTX.color.bg),
	       UNPACK_BLUE(CTX.color.bg));
    Msg(INFO, "GIF creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_PPM :
    if(!(fp = fopen(name,"wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    FillBuffer();
    create_ppm(fp, CTX.viewport[2]-CTX.viewport[0],
	       CTX.viewport[3]-CTX.viewport[1]);
    Msg(INFO, "PPM creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_YUV :
    if(!(fp = fopen(name,"wb"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    FillBuffer();
    create_yuv(fp, CTX.viewport[2]-CTX.viewport[0],
	       CTX.viewport[3]-CTX.viewport[1]);
    Msg(INFO, "YUV creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_PS :
  case FORMAT_PSTEX :
    if(!(fp = fopen(name,"w"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    CTX.print.gl_fonts = 0;
    size3d = 0 ;
    res = GL2PS_OVERFLOW ;
    while(res == GL2PS_OVERFLOW){
      size3d += 2048*2048 ;
      gl2psBeginPage(CTX.base_filename, "Gmsh", 
		     GL2PS_PS,
		     (CTX.print.eps_quality == 1 ? GL2PS_SIMPLE_SORT : GL2PS_BSP_SORT),
		     GL2PS_SIMPLE_LINE_OFFSET | 
		     (CTX.print.eps_background ? GL2PS_DRAW_BACKGROUND : 0) |
		     (format==FORMAT_PSTEX ? GL2PS_NO_TEXT : 0),
		     GL_RGBA, 0, NULL, size3d, fp);
      CTX.stream = TO_FILE ;
      FillBuffer();
      CTX.stream = TO_SCREEN ;
      res = gl2psEndPage();
    }
    Msg(INFO, "EPS creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    CTX.print.gl_fonts = 1;
    break ;

  case FORMAT_TEX :
    if(!(fp = fopen(name,"w"))) {
      Msg(GERROR, "Unable to open file '%s'", name); 
      return;
    }
    gl2psBeginPage(CTX.base_filename, "Gmsh", 
		   GL2PS_TEX, GL2PS_NO_SORT, 0, 
		   GL_RGBA, 0, NULL, 1, fp);
    CTX.stream = TO_FILE ;
    CTX.print.gl_fonts = 0;
    FillBuffer();
    CTX.stream = TO_SCREEN ;
    CTX.print.gl_fonts = 1;
    res = gl2psEndPage();
    Msg(INFO, "TEX creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  default :
    Msg(WARNING, "Unknown print format");
    break;
  }


}


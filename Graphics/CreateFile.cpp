// $Id: CreateFile.cpp,v 1.19 2001-06-06 08:47:48 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "OpenFile.h"
#include "Draw.h"
#include "Context.h"

extern Context_T   CTX;
extern Mesh        M;

#ifdef _XMOTIF
#include <unistd.h>
#include "Widgets.h"
#include "XContext.h"
#include "XDump.h"
extern Widgets_T   WID;
extern XContext_T  XCTX;
#endif

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
  char     ext[10];
  int      res;

#ifdef _XMOTIF
  FILE    *tmp;
  char     cmd[1000], *tmpFileName="tmp.xwd";
#endif

  if(!name || !strlen(name)) return;

  CTX.print.gl_fonts = 1;

  switch(format){

  case FORMAT_AUTO :
    if(strlen(name) < 4)
      Msg(GERROR, "Unknown extension for automatic format detection");
    else{
      strcpy(ext,name+(strlen(name)-4));
      if(!strcmp(ext,".geo")) CreateOutputFile(name, FORMAT_GEO);
      else if(!strcmp(ext,".msh")) CreateOutputFile(name, FORMAT_MSH);
      else if(!strcmp(ext,".unv")) CreateOutputFile(name, FORMAT_UNV);
      else if(!strcmp(ext,".gif")) CreateOutputFile(name, FORMAT_GIF);
      else if(!strcmp(ext,".jpg")) CreateOutputFile(name, FORMAT_JPEG);
      else if(!strcmp(ext,".eps")) CreateOutputFile(name, FORMAT_EPS);
      else if(!strcmp(ext,".xpm")) CreateOutputFile(name, FORMAT_XPM);
      else if(!strcmp(ext,".ppm")) CreateOutputFile(name, FORMAT_PPM);
      else if(!strcmp(ext,".yuv")) CreateOutputFile(name, FORMAT_YUV);
      else {
	if(strlen(name) < 5)
	  Msg(GERROR, "Unknown extension in \"%s\" for automatic format detection",
	      name);
	else{
	  strcpy(ext,name+(strlen(name)-5));
	  if(!strcmp(ext,".jpeg")) CreateOutputFile(name, FORMAT_JPEG);
	  else if(!strcmp(ext,".gref")) CreateOutputFile(name, FORMAT_GREF);
	  else if(!strcmp(ext,".Gref")) CreateOutputFile(name, FORMAT_GREF);
	  else Msg(GERROR, "Unknown extension in \"%s\" for automatic format detection",
		   name);
	}
      }
    }
    break;

  case FORMAT_GEO :
    Print_Geo(&M, name);
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

#ifdef _XMOTIF
  case FORMAT_XPM :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to open file '%s'", name); 
      return;
    }
    Window_Dump(XCTX.display, XCTX.scrnum, XtWindow(WID.G.glw), fp);    
    Msg(INFO, "XPM creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;
#endif

  case FORMAT_JPEG :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to open file '%s'", name); 
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
      Msg(WARNING, "Unable to open file '%s'", name); 
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
      Msg(WARNING, "Unable to open file '%s'", name); 
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
      Msg(WARNING, "Unable to open file '%s'", name); 
      return;
    }
    FillBuffer();
    create_yuv(fp, CTX.viewport[2]-CTX.viewport[0],
	       CTX.viewport[3]-CTX.viewport[1]);
    Msg(INFO, "YUV creation complete '%s'", name);
    Msg(STATUS2, "Wrote '%s'", name);
    fclose(fp);
    break;

  case FORMAT_EPS :

    switch(CTX.print.eps_quality){

#ifdef _XMOTIF
    case 0 : // Bitmap EPS
      if(!(fp = fopen(name,"w"))) {
	Msg(WARNING, "Unable to open file '%s'", name); 
	return;
      }
      if(!(tmp = fopen(tmpFileName,"w"))){
	Msg(WARNING, "Unable to open file '%s'", tmpFileName); 
	return;
      }
      Window_Dump(XCTX.display, XCTX.scrnum, XtWindow(WID.G.glw), tmp);
      fclose(tmp);
      sprintf(cmd, "xpr -device ps -gray 4 %s >%s", tmpFileName, name);
      Msg(INFO, "Executing '%s'", cmd);
      system(cmd);
      unlink(tmpFileName);
      Msg(INFO, "Bitmap EPS creation complete '%s'", name);
      Msg(STATUS2, "Wrote '%s'", name);
      fclose(fp);
      break;
#endif
      
    default : // Vector EPS
      if(!(fp = fopen(name,"w"))) {
	Msg(WARNING, "Unable to open file '%s'", name); 
	return;
      }
      CTX.print.gl_fonts = 0;
      size3d = 0 ;
      res = GL2PS_OVERFLOW ;
      while(res == GL2PS_OVERFLOW){
	size3d += 2048*2048 ;
	gl2psBeginPage(CTX.base_filename, "Gmsh", 
		       (CTX.print.eps_quality == 1 ? GL2PS_SIMPLE_SORT : GL2PS_BSP_SORT),
		       GL2PS_SIMPLE_LINE_OFFSET | 
		       (CTX.print.eps_background ? GL2PS_DRAW_BACKGROUND : 0),
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
      break;
      
    }
    break ;
    
  default :
    Msg(WARNING, "Unknown print format");
    break;
  }


}


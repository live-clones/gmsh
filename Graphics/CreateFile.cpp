// $Id: CreateFile.cpp,v 1.7 2001-01-10 20:23:37 geuzaine Exp $

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


void CreateFile (char *name, int format) {
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
      Msg(GERROR, "Unknown Extension for Automatic Format Detection");
    else{
      strcpy(ext,name+(strlen(name)-4));
      if(!strcmp(ext,".geo")) CreateFile(name, FORMAT_GEO);
      else if(!strcmp(ext,".msh")) CreateFile(name, FORMAT_MSH);
      else if(!strcmp(ext,".unv")) CreateFile(name, FORMAT_UNV);
      else if(!strcmp(ext,".gif")) CreateFile(name, FORMAT_GIF);
      else if(!strcmp(ext,".jpg")) CreateFile(name, FORMAT_JPEG);
      else if(!strcmp(ext,".eps")) CreateFile(name, FORMAT_EPS);
      else if(!strcmp(ext,".xpm")) CreateFile(name, FORMAT_XPM);
      else if(!strcmp(ext,".ppm")) CreateFile(name, FORMAT_PPM);
      else if(!strcmp(ext,".yuv")) CreateFile(name, FORMAT_YUV);
      else {
	if(strlen(name) < 5)
	  Msg(GERROR, "Unknown Extension for Automatic Format Detection");
	else{
	  strcpy(ext,name+(strlen(name)-5));
	  if(!strcmp(ext,".jpeg")) CreateFile(name, FORMAT_JPEG);
	  else if(!strcmp(ext,".gref")) CreateFile(name, FORMAT_GREF);
	  else if(!strcmp(ext,".Gref")) CreateFile(name, FORMAT_GREF);
	  else Msg(GERROR, "Unknown Extension \"%s\" for Automatic Format Detection", ext);
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
      Msg(WARNING, "Unable to Open File '%s'", name); 
      return;
    }
    Window_Dump(XCTX.display, XCTX.scrnum, XtWindow(WID.G.glw), fp);    
    Msg(INFOS, "XPM Creation Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
    fclose(fp);
    break;
#endif

#ifndef WIN32
  case FORMAT_JPEG :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to Open File '%s'", name); 
      return;
    }
    DrawUpdate();
    create_jpeg(fp, CTX.viewport[2]-CTX.viewport[0],
		CTX.viewport[3]-CTX.viewport[1],
		CTX.print.jpeg_quality);
    Msg(INFOS, "JPEG Creation Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
    fclose(fp);
    break;
#endif

  case FORMAT_GIF :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to Open File '%s'", name); 
      return;
    }
    DrawUpdate();
    create_gif(fp, CTX.viewport[2]-CTX.viewport[0],
               CTX.viewport[3]-CTX.viewport[1], 
	       CTX.print.gif_dither,
	       CTX.print.gif_sort, 
	       CTX.print.gif_interlace,
	       CTX.print.gif_transparent,
	       UNPACK_RED(CTX.color.bg),
	       UNPACK_GREEN(CTX.color.bg),
	       UNPACK_BLUE(CTX.color.bg));
    Msg(INFOS, "GIF Creation Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
    fclose(fp);
    break;

  case FORMAT_PPM :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to Open File '%s'", name); 
      return;
    }
    DrawUpdate();
    create_ppm(fp, CTX.viewport[2]-CTX.viewport[0],
	       CTX.viewport[3]-CTX.viewport[1]);
    Msg(INFOS, "PPM Creation Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
    fclose(fp);
    break;

  case FORMAT_YUV :
    if(!(fp = fopen(name,"wb"))) {
      Msg(WARNING, "Unable to Open File '%s'", name); 
      return;
    }
    DrawUpdate();
    create_yuv(fp, CTX.viewport[2]-CTX.viewport[0],
	       CTX.viewport[3]-CTX.viewport[1]);
    Msg(INFOS, "YUV Creation Complete '%s'", name);
    Msg (INFO, "Wrote File '%s'", name);
    fclose(fp);
    break;

  case FORMAT_EPS :

    switch(CTX.print.eps_quality){

#ifdef _XMOTIF
    case 0 : // Bitmap EPS
      if(!(fp = fopen(name,"w"))) {
	Msg(WARNING, "Unable to Open File '%s'", name); 
	return;
      }
      if(!(tmp = fopen(tmpFileName,"w"))){
	Msg(WARNING, "Unable to Open File '%s'", tmpFileName); 
	return;
      }
      Window_Dump(XCTX.display, XCTX.scrnum, XtWindow(WID.G.glw), tmp);
      fclose(tmp);
      sprintf(cmd, "xpr -device ps -gray 4 %s >%s", tmpFileName, name);
      Msg(INFOS, "Executing '%s'", cmd);
      system(cmd);
      unlink(tmpFileName);
      Msg(INFOS, "Bitmap EPS Creation Complete '%s'", name);
      Msg (INFO, "Wrote File '%s'", name);
      fclose(fp);
      break;
#endif
      
    default : // Vector EPS
      if(!(fp = fopen(name,"w"))) {
	Msg(WARNING, "Unable to Open File '%s'", name); 
	return;
      }
      CTX.print.gl_fonts = 0;
      size3d = 0 ;
      res = GL2PS_OVERFLOW ;
      while(res == GL2PS_OVERFLOW){
	size3d += 2048*2048 ;
	gl2psBeginPage(CTX.basefilename, "Gmsh", 
		       (CTX.print.eps_quality == 1 ? GL2PS_SIMPLE_SORT : GL2PS_BSP_SORT),
		       GL2PS_SIMPLE_LINE_OFFSET | GL2PS_DRAW_BACKGROUND,
		       GL_RGBA, 0, NULL, size3d, fp);
	CTX.stream = TO_FILE ;
	DrawUpdate();
	CTX.stream = TO_SCREEN ;
	res = gl2psEndPage();
      }
      Msg(INFOS, "EPS Creation Complete '%s'", name);
      Msg (INFO, "Wrote File '%s'", name);
      fclose(fp);
      CTX.print.gl_fonts = 1;
      break;
      
    }
    break ;
    
  default :
    Msg(WARNING, "Unknown Print Format");
    break;
  }


}


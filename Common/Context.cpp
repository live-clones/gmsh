// $Id: Context.cpp,v 1.36 2001-02-12 17:38:02 geuzaine Exp $

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "DefaultOptions.h"
#include "trackball.c"

extern Context_T CTX ;

// STRING OPTIONS

StringXString * Get_StringOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_String ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_String ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_String ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_String ;
  else if(!strcmp(cat,"View"))           return ViewOptions_String ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_String ;
  else                                   return NULL ;
}

void Set_DefaultStringOptions(int num, StringXString s[]){
  int i = 0;
  while(s[i].str) s[i].function(num, GMSH_SET, s[i++].def) ;
}

void UpdateGUI_StringOptions(int num, StringXString s[]){
  int i = 0;
  while(s[i].str) s[i++].function(num, GMSH_GUI, 0) ;
}

void * Get_StringOption(char *str, StringXString s[]){
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return (void*)s[i].function;
}

void Print_StringOptions(int num, StringXString s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    sprintf(tmp, "%s%s = \"%s\";", prefix, s[i].str, s[i].function(num, GMSH_GET, NULL)) ;
    if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, "%s", tmp);
    i++;
  }
}

// NUMBER OPTIONS

StringXNumber * Get_NumberOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Number ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Number ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Number ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Number ;
  else if(!strcmp(cat,"View"))           return ViewOptions_Number ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Number ;
  else                                   return NULL ;
}

void Set_DefaultNumberOptions(int num, StringXNumber s[]){
  int i = 0;
  while(s[i].str) s[i].function(num, GMSH_SET, s[i++].def) ;
}

void UpdateGUI_NumberOptions(int num, StringXNumber s[]){
  int i = 0;
  while(s[i].str) s[i++].function(num, GMSH_GUI, 0) ;
}

void * Get_NumberOption(char *str, StringXNumber s[]){
  int i = 0;

  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else{
    return (void*)s[i].function;
  }
}

void Print_NumberOptions(int num, StringXNumber s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    sprintf(tmp, "%s%s = %g;", prefix, s[i].str, s[i].function(num, GMSH_GET, 0));
    if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
    i++;
  }
}

// COLOR OPTIONS

StringXColor * Get_ColorOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Color ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Color ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Color ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Color ;
  else if(!strcmp(cat,"View"))           return ViewOptions_Color ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Color ;
  else                                   return NULL ;
}

void Set_DefaultColorOptions(int num, StringXColor s[], int scheme){
  int i = 0;
  switch(scheme){
  case 0 : while(s[i].str) s[i].function(num, GMSH_SET, s[i++].def1) ; break;
  case 1 : while(s[i].str) s[i].function(num, GMSH_SET, s[i++].def2) ; break;
  case 2 : while(s[i].str) s[i].function(num, GMSH_SET, s[i++].def3) ; break;
  }
}

void UpdateGUI_ColorOptions(int num, StringXColor s[]){
  int i = 0;
  while(s[i].str) s[i++].function(num, GMSH_GUI, 0) ;
}

void * Get_ColorOption(char *str, StringXColor s[]) {
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return (void*)s[i].function;
}

void Print_ColorOptions(int num, StringXColor s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    sprintf(tmp, "%sColor.%s = {%d,%d,%d};", 
	    prefix, s[i].str,
	    UNPACK_RED  (s[i].function(num, GMSH_GET, 0)),
	    UNPACK_GREEN(s[i].function(num, GMSH_GET, 0)),
	    UNPACK_BLUE (s[i].function(num, GMSH_GET, 0)));
    if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
    i++;
  }
}

int Get_ColorForString(StringX4Int SX4I[], int alpha, 
		       char * str, int * FlagError) {
  int  i = 0 ;
  while ((SX4I[i].str != NULL) && (strcmp(SX4I[i].str, str)))  i++ ;
  *FlagError = (SX4I[i].str == NULL)? 1 : 0 ;
  if(alpha > 0)
    return PACK_COLOR(SX4I[i].int1,SX4I[i].int2,SX4I[i].int3,alpha) ;
  else
    return PACK_COLOR(SX4I[i].int1,SX4I[i].int2,SX4I[i].int3,SX4I[i].int4) ;
}


/* ------------------------------------------------------------------------ */
/*  C o n t e x t                                                           */
/* ------------------------------------------------------------------------ */

void Init_Context(int num){

  // Cannot be set by the user 
  CTX.expose       = 0 ;
  CTX.db           = 1 ;
  CTX.overlay      = 1 ;
  CTX.stream       = TO_SCREEN ;
  CTX.command_win  = 0 ;
  CTX.threads      = 1 ; // effective on Unix only with -D_USETHREADS
  CTX.threads_lock = 0 ;

  CTX.gl_fontheight = 12;
  CTX.gl_fontascent = 8;

  // only used for motif
  CTX.font = "-*-helvetica-medium-r-*-*-*-*-*-*-*-*-*-*" ;
  CTX.fixed_font = "fixed" ;
  // end(only used for motif)

  // only for fltk
  CTX.fontsize = 12;
  // end(fltk)

  CTX.lc = 1.0 ;
  CTX.min[0]   = CTX.min[1]   = CTX.min[2]   = 0.0 ;
  CTX.max[0]   = CTX.max[1]   = CTX.max[2]   = 1.0 ;
  CTX.range[0] = CTX.range[1] = CTX.range[2] = 1.0 ;

  CTX.vxmin = CTX.vymin = CTX.vxmax = CTX.vymax = 0. ;

  CTX.render_mode    = GMSH_RENDER ;
  CTX.pixel_equiv_x  = CTX.pixel_equiv_y = 0. ; 
  CTX.geom.vis_type  = 0 ;
  CTX.geom.level     = ELEMENTARY ;
  CTX.mesh.vis_type  = 0 ;
  CTX.mesh.draw      = 1 ;  
  CTX.post.draw      = 1 ;

  // Default string options
  Set_DefaultStringOptions(num, GeneralOptions_String);
  Set_DefaultStringOptions(num, GeometryOptions_String);
  Set_DefaultStringOptions(num, MeshOptions_String);
  Set_DefaultStringOptions(num, PostProcessingOptions_String);
  Set_DefaultStringOptions(num, PrintOptions_String);

  // Default number options
  Set_DefaultNumberOptions(num, GeneralOptions_Number);
  Set_DefaultNumberOptions(num, GeometryOptions_Number);
  Set_DefaultNumberOptions(num, MeshOptions_Number);
  Set_DefaultNumberOptions(num, PostProcessingOptions_Number);
  Set_DefaultNumberOptions(num, PrintOptions_Number);

  // Default color options
  Init_Colors(num);
}

void Init_Colors(int num){
  Set_DefaultColorOptions(num, GeneralOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, GeometryOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, MeshOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, PostProcessingOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, PrintOptions_Color, CTX.color_scheme);
}

void UpdateGUI_Context(int num){
  UpdateGUI_StringOptions(num, GeneralOptions_String);
  UpdateGUI_StringOptions(num, GeometryOptions_String);
  UpdateGUI_StringOptions(num, MeshOptions_String);
  UpdateGUI_StringOptions(num, PostProcessingOptions_String);
  UpdateGUI_StringOptions(num, PrintOptions_String);
      
  UpdateGUI_NumberOptions(num, GeneralOptions_Number);
  UpdateGUI_NumberOptions(num, GeometryOptions_Number);
  UpdateGUI_NumberOptions(num, MeshOptions_Number);
  UpdateGUI_NumberOptions(num, PostProcessingOptions_Number);
  UpdateGUI_NumberOptions(num, PrintOptions_Number);

  UpdateGUI_ColorOptions(num, GeneralOptions_Color);
  UpdateGUI_ColorOptions(num, GeometryOptions_Color);
  UpdateGUI_ColorOptions(num, MeshOptions_Color);
  UpdateGUI_ColorOptions(num, PostProcessingOptions_Color);
  UpdateGUI_ColorOptions(num, PrintOptions_Color);
}

void Print_Context(int num, char *filename){
  FILE *file;
  char tmp[256];
  int i ;
  
  if(filename){
    file = fopen(filename,"w");
    if(!file){
      Msg(WARNING, "Unable to Open File '%s'", filename);
      return;
    }
  }
  else
    file = NULL ;

  Print_StringOptions(num, GeneralOptions_String, "General.", file);
  Print_NumberOptions(num, GeneralOptions_Number, "General.", file);
  Print_ColorOptions(num, GeneralOptions_Color, "General.", file);
  Print_StringOptions(num, GeometryOptions_String, "Geometry.", file);
  Print_NumberOptions(num, GeometryOptions_Number, "Geometry.", file);
  Print_ColorOptions(num, GeometryOptions_Color, "Geometry.", file);
  Print_StringOptions(num, MeshOptions_String, "Mesh.", file);
  Print_NumberOptions(num, MeshOptions_Number, "Mesh.", file);
  Print_ColorOptions(num, MeshOptions_Color, "Mesh.", file);
  Print_StringOptions(num, PostProcessingOptions_String, "PostProcessing.", file);
  Print_NumberOptions(num, PostProcessingOptions_Number, "PostProcessing.", file);
  Print_ColorOptions(num, PostProcessingOptions_Color, "PostProcessing.", file);
  for(i=0; i<List_Nbr(Post_ViewList) ; i++){
    sprintf(tmp, "View[%d].", i);
    Print_StringOptions(i, ViewOptions_String, tmp, file);
    Print_NumberOptions(i, ViewOptions_Number, tmp, file);
    Print_ColorOptions(i, ViewOptions_Color, tmp, file);
    strcat(tmp, "ColorTable");
    Print_ColorTable(i, tmp, file);
  }
  Print_StringOptions(num, PrintOptions_String, "Print.", file);
  Print_NumberOptions(num, PrintOptions_Number, "Print.", file);
  Print_ColorOptions(num, PrintOptions_Color, "Print.", file);

  if(filename){
    Msg(INFO, "Options Output Complete '%s'", filename);
    Msg(STATUS2, "Wrote File '%s'", filename);
    fclose(file);
  }
}

void Print_Configuration(int num, char *filename){
  FILE *file;
  
  file = fopen(filename,"w");
  if(!file){
    Msg(WARNING, "Unable to Open File '%s'", filename);
    return;
  }

  fprintf(file, "// Gmsh sessionrc\n");
  fprintf(file, "// This file takes session-specific info (that is info\n");
  fprintf(file, "// you want to keep between two Gmsh sessions). You are\n");
  fprintf(file, "// not supposed to edit it manually, but of course you\n");
  fprintf(file, "// can do. This file will be entirely rewritten every time\n");
  fprintf(file, "// you quit Gmsh. If this file isn't found, defaults\n");
  fprintf(file, "// are used.\n");
  fprintf(file, "General.Viewport0 = %d;\n", CTX.viewport[0]);
  fprintf(file, "General.Viewport1 = %d;\n", CTX.viewport[1]);
  fprintf(file, "General.Viewport2 = %d;\n", CTX.viewport[2]);
  fprintf(file, "General.Viewport3 = %d;\n", CTX.viewport[3]);
  fprintf(file, "General.GraphicsFontSize = %d;\n", CTX.gl_fontsize);
  fprintf(file, "General.GraphicsPosition0 = %d;\n", CTX.gl_position[0]);
  fprintf(file, "General.GraphicsPosition1 = %d;\n", CTX.gl_position[1]);
  fprintf(file, "General.MenuFontSize = %d;\n", CTX.fontsize);
  fprintf(file, "General.MenuPosition0 = %d;\n", CTX.position[0]);
  fprintf(file, "General.MenuPosition1 = %d;\n", CTX.position[1]);
  fclose(file);
}


/*
  3 rotations successives autour de x, y et z:

           c(y)c(z)    s(x)s(y)c(z)+c(x)s(z)   -c(x)s(y)c(z)+s(x)s(z) 
  t[][] = -c(y)s(z)   -s(x)s(y)s(z)+c(x)c(z)    c(x)s(y)s(z)+s(x)c(z)
           s(y)       -s(x)c(y)                 c(x)c(y)

  get the position angles:

  y = asin(t31)
      Pi - asin(t31)
 
  si y != +- Pi/2 :

  x = atan(-t32/t33)    si t33 cos y > 0
      atan(-t32/t33)+Pi si t33 cos y < 0

  z = atan(-t21/t11)    si t11 cos y > 0
      atan(-t21/t11)+Pi si t11 cos y < 0

*/

void Context_T::buildRotmatrix(void)
{
  double x, y, z;
  extern void set_r(int i, double val);

  if(CTX.useTrackball){
    build_rotmatrix(rot, quaternion);
    // get the position angles
    /*
      double x=0., y=0., z=0.

      y = asin(rot[2][0]) ; y = Pi - asin(rot[2][0]) ; // choix ???
  
      if(fabs(y) != Pi/2.){
        if(rot[2][2]*cos(y) > 0.) x = atan2(-rot[2][1],rot[2][2]);
	else                      x = atan2(-rot[2][1],rot[2][2]) + Pi;
	if(rot[0][0]*cos(y) > 0.) z = atan2(-rot[1][0],rot[0][0]);
	else                      z = atan2(-rot[1][0],rot[0][0]) + Pi;
      }
      set_r(0, x * 180./Pi);
      set_r(1, y * 180./Pi);
      set_r(2, z * 180./Pi);
    */
    /*
    double r0, r1, r2;

    r1 = atan2(-rot[0][2],sqrt(rot[1][2]*rot[1][2] + rot[2][2]*rot[2][2]));
    
    double c = cos(r1);  
    if(c != 0.0){
      r0 = atan2(rot[1][2]/c,rot[2][2]/c) ;
      r2 = atan2(-rot[1][0]/c,rot[0][0]/c) ;
      r0 *= 180./(Pi);
      r2 *= 180./(Pi);
    }
    set_r(0, r0);
    set_r(1, r1 * 180./(Pi));  // lazyyyyyy
    set_r(2, r2);
    */

    // until we can compute this correctly
    set_r(0, 0.);
    set_r(1, 0.);
    set_r(2, 0.);

  }
  else{
    x = r[0] * Pi / 180.;
    y = r[1] * Pi / 180.;
    z = r[2] * Pi / 180.;

    rot[0][0] = cos(y)*cos(z) ; 
    rot[0][1] = sin(x)*sin(y)*cos(z)+cos(x)*sin(z);
    rot[0][2] = -cos(x)*sin(y)*cos(z)+sin(x)*sin(z);
    rot[0][3] = 0.0;

    rot[1][0] = -cos(y)*sin(z);
    rot[1][1] = -sin(x)*sin(y)*sin(z)+cos(x)*cos(z);
    rot[1][2] = cos(x)*sin(y)*sin(z)+sin(x)*cos(z);
    rot[1][3] = 0.0;
    
    rot[2][0] = sin(y);
    rot[2][1] = -sin(x)*cos(y);
    rot[2][2] = cos(x)*cos(y);
    rot[2][3] = 0.0;

    rot[3][0] = 0.0 ;
    rot[3][1] = 0.0 ;
    rot[3][2] = 0.0 ;
    rot[3][3] = 1.0 ;
    /*
    printf("x=%g y=%g z=%g\n", r[0], r[1], r[2]);
    printf("[%g %g %g]\n", rot[0][0], rot[0][1], rot[0][2]);
    printf("[%g %g %g]\n", rot[1][0], rot[1][1], rot[1][2]);
    printf("[%g %g %g]\n", rot[2][0], rot[2][1], rot[2][2]);
    */
  }

}

void Context_T::addQuaternion (float p1x, float p1y, float p2x, float p2y)
{
  float quat[4];
  trackball(quat,p1x,p1y,p2x,p2y);
  add_quats(quat, quaternion, quaternion);  
}

void Context_T::setQuaternion (float q0, float q1, float q2, float q3)
{
  quaternion[0] = q0;
  quaternion[1] = q1;
  quaternion[2] = q2;
  quaternion[3] = q3;
}

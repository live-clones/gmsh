// $Id: Context.cpp,v 1.32 2001-01-12 13:28:54 geuzaine Exp $

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "trackball.c"

extern Context_T CTX ;

extern StringXString GeneralOptions_String[] ;
extern StringXString GeometryOptions_String[] ;
extern StringXString MeshOptions_String[] ;
extern StringXString PostProcessingOptions_String[] ;
extern StringXString PrintOptions_String[] ;

extern StringXNumber GeneralOptions_Number[] ;
extern StringXNumber GeometryOptions_Number[] ;
extern StringXNumber MeshOptions_Number[] ;
extern StringXNumber PostProcessingOptions_Number[] ;
extern StringXNumber PrintOptions_Number[] ;

extern StringXColor GeneralOptions_Color[] ;
extern StringXColor GeometryOptions_Color[] ;
extern StringXColor MeshOptions_Color[] ;
extern StringXColor PostProcessingOptions_Color[] ;
extern StringXColor PrintOptions_Color[] ;


// STRING OPTIONS

StringXString * Get_StringOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_String ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_String ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_String ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_String ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_String ;
  else                                   return NULL ;
}

void Set_DefaultStringOptions(StringXString s[]){
  int i = 0;
  while(s[i].str){
    *s[i].ptr = s[i].def ;
    i++;
  }
}

char ** Get_StringOption(char *str, StringXString s[]){
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return s[i].ptr;
}

void Print_StringOptions(StringXString s[], char *prefix, FILE *file){
  int i = 0;
  while(s[i].str){
    fprintf(file, "%s%s = \"%s\";\n", prefix, s[i].str, *s[i].ptr) ;
    i++;
  }
}

// NUMBER OPTIONS

StringXNumber * Get_NumberOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Number ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Number ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Number ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Number ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Number ;
  else                                   return NULL ;
}

void Set_DefaultNumberOptions(StringXNumber s[]){
  int i = 0;
  while(s[i].str){
    switch(s[i].type){
    case GMSH_INT: *(int*)s[i].ptr = (int)s[i].def; break;
    case GMSH_LONG: *(long*)s[i].ptr = (long)s[i].def; break;
    case GMSH_FLOAT: *(float*)s[i].ptr = (float)s[i].def; break;
    case GMSH_DOUBLE: *(double*)s[i].ptr = (double)s[i].def; break;
    }
    i++;
  }
}

void * Get_NumberOption(char *str, StringXNumber s[], int *type){
  int i = 0;

  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else{
    *type = s[i].type ;
    return s[i].ptr;
  }
}

void Print_NumberOptions(StringXNumber s[], char *prefix, FILE *file){
  int i = 0;
  while(s[i].str){
    fprintf(file, "%s%s = ", prefix, s[i].str);
    switch(s[i].type){
    case GMSH_INT : fprintf(file, "%d;\n", *(int*)s[i].ptr); break;
    case GMSH_LONG : fprintf(file, "%ld;\n", *(long*)s[i].ptr); break;
    case GMSH_FLOAT : fprintf(file, "%g;\n", *(float*)s[i].ptr); break;
    case GMSH_DOUBLE : fprintf(file, "%g;\n", *(double*)s[i].ptr); break;
    }
    i++;
  }
}

// COLORS

StringXColor * Get_ColorOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Color ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Color ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Color ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Color ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Color ;
  else                                   return NULL ;
}

void Set_DefaultColorOptions(StringXColor s[], int num){
  int i = 0;
  while(s[i].str){
    switch(num){
    case 0 : *s[i].ptr = s[i].def1; break;
    case 1 : *s[i].ptr = s[i].def2; break;
    case 2 : *s[i].ptr = s[i].def3; break;
    }
    i++;
  }
}

unsigned int * Get_ColorOption(char *str, StringXColor s[]) {
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return s[i].ptr;
}

void Print_ColorOptions(StringXColor s[], char *prefix, FILE *file){
  int i = 0;
  while(s[i].str){
    fprintf(file, "%sColor.%s = {%d,%d,%d};\n", 
	    prefix, s[i].str,
	    UNPACK_RED(*s[i].ptr),
	    UNPACK_GREEN(*s[i].ptr),
	    UNPACK_BLUE(*s[i].ptr));
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

void Init_Colors(int num){
  if(num < 0 || num > 2){
    return;
  }
  CTX.color.id = num ;
  Set_DefaultColorOptions(GeneralOptions_Color, num);
  Set_DefaultColorOptions(GeometryOptions_Color, num);
  Set_DefaultColorOptions(MeshOptions_Color, num);
  Set_DefaultColorOptions(PostProcessingOptions_Color, num);
  Set_DefaultColorOptions(PrintOptions_Color, num);
}

void Init_Context(void){

  // Cannot be set by the user 
  CTX.expose       = 0 ;
  CTX.db           = 1 ;
  CTX.overlay      = 1 ;
  CTX.stream       = TO_SCREEN ;
  CTX.command_win  = 0 ;
  CTX.threads      = 1 ; // effective on Unix only with -D_USETHREADS
  CTX.threads_lock = 0 ;

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
  Set_DefaultStringOptions(GeneralOptions_String);
  Set_DefaultStringOptions(GeometryOptions_String);
  Set_DefaultStringOptions(MeshOptions_String);
  Set_DefaultStringOptions(PostProcessingOptions_String);
  Set_DefaultStringOptions(PrintOptions_String);

  // Default number options
  Set_DefaultNumberOptions(GeneralOptions_Number);
  Set_DefaultNumberOptions(GeometryOptions_Number);
  Set_DefaultNumberOptions(MeshOptions_Number);
  Set_DefaultNumberOptions(PostProcessingOptions_Number);
  Set_DefaultNumberOptions(PrintOptions_Number);

  // Default color options
  Init_Colors(0);

}

void Print_Context(char *filename){
  FILE *file;
  int i ;
  
  if(filename){
    file = fopen(filename,"w");
    if(!file){
      Msg(WARNING, "Unable to Open File '%s'", filename);
      return;
    }
  }
  else
    file = stdout;

  Print_StringOptions(GeneralOptions_String, "General.", file);
  Print_NumberOptions(GeneralOptions_Number, "General.", file);
  Print_ColorOptions(GeneralOptions_Color, "General.", file);
  fprintf(file, "\n");
  Print_StringOptions(GeometryOptions_String, "Geometry.", file);
  Print_NumberOptions(GeometryOptions_Number, "Geometry.", file);
  Print_ColorOptions(GeometryOptions_Color, "Geometry.", file);
  fprintf(file, "\n");
  Print_StringOptions(MeshOptions_String, "Mesh.", file);
  Print_NumberOptions(MeshOptions_Number, "Mesh.", file);
  Print_ColorOptions(MeshOptions_Color, "Mesh.", file);
  fprintf(file, "\n");
  Print_StringOptions(PostProcessingOptions_String, "PostProcessing.", file);
  Print_NumberOptions(PostProcessingOptions_Number, "PostProcessing.", file);
  Print_ColorOptions(PostProcessingOptions_Color, "PostProcessing.", file);
  for(i=0; i<List_Nbr(Post_ViewList) ; i++){
    Print_StringViewOptions(i, file);
    Print_NumberViewOptions(i, file);
  }
  fprintf(file, "\n");
  Print_StringOptions(PrintOptions_String, "Print.", file);
  Print_NumberOptions(PrintOptions_Number, "Print.", file);
  Print_ColorOptions(PrintOptions_Color, "Print.", file);

  if(filename){
    Msg(INFO, "Options Output Complete '%s'", filename);
    Msg(STATUS2, "Wrote File '%s'", filename);
    fclose(file);
  }
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

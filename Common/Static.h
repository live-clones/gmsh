#ifndef _STATIC_H_
#define _STATIC_H_

#include "Version.h"

char gmsh_progname[]  = "This is Gmsh" ;
char gmsh_copyright[] = "Copyright (C) 1997-2000 J.-F. Remacle, C. Geuzaine";
char gmsh_version[]   = "Version          : " ;
char gmsh_os[]        = "Operating System : " GMSH_OS ;
char gmsh_date[]      = "Build Date       : " GMSH_DATE ;
char gmsh_host[]      = "Build Host       : " GMSH_HOST ;
char gmsh_packager[]  = "Packager         : " GMSH_PACKAGER ;
char gmsh_email[]     = "E-Mail           : "
                        "Christophe.Geuzaine@ulg.ac.be, Remacle@scorec.rpi.edu";
char gmsh_url[]       = "URL              : http://www.geuz.org/gmsh/";


char  yyname[NAME_STR_L];
int   yyerrorstate;

char  TheFileNameTab[MAX_OPEN_FILES][NAME_STR_L], TheFileName[NAME_STR_L];
char  TheBaseFileName[NAME_STR_L], TheMshFileName[NAME_STR_L], TheBgmFileName[NAME_STR_L];
char  ThePathForIncludes[NAME_STR_L] = "";

Context_T   CTX ;
Mesh        M, *THEM, *LOCAL;
Simplex     Boundary;

Tree_T     *EntitesVisibles = NULL;
List_T     *TrsfVolNum = NULL;
List_T     *Post_ViewList = NULL;

double      LC, MiddleLC, FACTEUR_MULTIPLICATIF=1.0;
int         LC_ORDER;
double      RANDOM_FACTOR=1.0, GLOBALSCALINGFACTOR=1.0;

char       *TextBuffer, TextAbout[1024];

int  NbFileName=0;
int  EXPOSE = 0 ;
int  WARNING_OVERRIDE=0;
int  ACTUAL_ENTITY, SHOW_ALL;
int  LocalNewPoint= CENTER_CIRCCIRC, FindQualityMethod=FEM_INTERPOLATION;
int  Alerte_Point_Scabreux, Alerte_Point_Exterieur, Highlight_Selection=0;
int  SPEED_MAX=0 ;
int  LISSAGE=3; 
int  INITIALBGMESH=NONE, TYPBGMESH=WITHPOINTS;
int  CurrentNodeNumber, CurrentSimplexNumber;
int  NbComplexVolumes=0, BD_EXISTS=0;
int  FLAG_OLD_CIRCLE = 0 ; /* Pour David : cercles > Pi */


#endif

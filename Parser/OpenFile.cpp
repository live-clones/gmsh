// $Id: OpenFile.cpp,v 1.2 2001-01-09 09:52:17 geuzaine Exp $
#include "Gmsh.h"
#include "Const.h"
#include "Context.h"
#include "Parser.h"
#include "OpenFile.h"
#include "Geo.h"
#include "Mesh.h"
#include "Views.h"
#include "MinMax.h"

#ifndef _BLACKBOX
#include "GmshUI.h"
#include "Draw.h"
extern int        SHOW_ALL_ENTITIES ;
extern Tree_T    *EntitesVisibles;
extern void RemplirEntitesVisibles (int add_rem);
#endif

#ifdef _XMOTIF
#include "Widgets.h"
extern Widgets_T WID;
#endif

extern Mesh      *THEM, M;
extern Context_T  CTX;

void ParseFile(char *f){
  char String[256];

  strncpy(yyname,f,NAME_STR_L);
  yyerrorstate=0;
  yylineno=1;

  if(!(yyin = fopen(yyname,"r"))){
    //Msg(INFO, "File '%s' Does not Exist", f);
    return;
  }
  
  fpos_t position;
  fgetpos(yyin, &position);
  fgets(String, sizeof(String), yyin) ; 
  fsetpos(yyin, &position);

  if(!strncmp(String, "$PTS", 4) || 
     !strncmp(String, "$NO", 3) || 
     !strncmp(String, "$ELM", 4)){
    if(THEM->status < 0) mai3d(THEM, 0);
    Read_Mesh(THEM, yyin, FORMAT_MSH);
  }
  else if(!strncmp(String, "$PostFormat", 11) ||
          !strncmp(String, "$View", 5)){
    Read_View(yyin, yyname);
  }
  else{
    while(!feof(yyin)) yyparse();
  }
  fclose(yyin);
}

void MergeProblem(char *name){
  Msg(INFOS, "Merging '%s'",name); 

  ParseFile(name);  
  if (yyerrorstate) return;

#ifndef _BLACKBOX
  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL_ENTITIES = 1;
  }
#endif
}

void OpenProblem(char *name){
  char ext[6];
  
  InitSymbols();
  Init_Mesh(&M, 1);

  strncpy(CTX.filename,name,NAME_STR_L);
  strncpy(CTX.basefilename,name,NAME_STR_L);

  strcpy(ext,name+(strlen(name)-4));
  if(!strcmp(ext,".GEO") || 
     !strcmp(ext,".geo") || 
     !strcmp(ext,".msh") || 
     !strcmp(ext,".pos")){
    CTX.basefilename[strlen(name)-4] = '\0';
  }
  else{
    strcat(CTX.filename,".geo");
  }

  strncpy(THEM->name, CTX.basefilename,NAME_STR_L);

#ifdef _XMOTIF
  if(!CTX.interactive){
    XtVaSetValues(WID.G.shell,
                  XmNtitle, CTX.filename,
                  XmNiconName, CTX.basefilename,
                  NULL);
  }
#endif

  Msg(INFOS, "Opening '%s'", CTX.filename); 

  ParseFile(CTX.filename);  

  ApplyLcFactor(THEM);
  mai3d(THEM,0);  
  Maillage_Dimension_0(&M);

#ifndef _BLACKBOX
  ZeroHighlight(&M); 
#endif

  CalculateMinMax(THEM->Points);  

#ifndef _BLACKBOX
  if (!EntitesVisibles) {
    RemplirEntitesVisibles(1);
    SHOW_ALL_ENTITIES = 1;
  }
#endif

}


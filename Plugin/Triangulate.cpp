// $Id: Triangulate.cpp,v 1.4 2001-12-03 08:41:45 geuzaine Exp $

#include "Gmsh.h"
#include "Plugin.h"
#include "Triangulate.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"
#include "Geo.h"
#include "Mesh.h"
#include "Utils.h"
#include "Create.h"


extern Context_T CTX;

StringXNumber TriangulateOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTriangulatePlugin ()
  {
    return new GMSH_TriangulatePlugin();
  }
}

GMSH_TriangulatePlugin::GMSH_TriangulatePlugin()
{
}

void GMSH_TriangulatePlugin::getName(char *name) const
{
  strcpy(name,"Triangulate");
}

void GMSH_TriangulatePlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text, 
	 "Triangulates a scalar point view\n"
	 "and outputs a scalar triangle view.\n"
	 "Script name: Plugin(Triangulate).\n");
}

int GMSH_TriangulatePlugin::getNbOptions() const
{
  return sizeof(TriangulateOptions_Number)/sizeof(StringXNumber);
}

StringXNumber *GMSH_TriangulatePlugin:: GetOption (int iopt)
{
  return &TriangulateOptions_Number[iopt];
}

void GMSH_TriangulatePlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"Triangulate failed...");
}


#define ANSI_DECLARATORS
#define REAL double

extern "C" {
#include "triangle.h"
}

void Triangulate(Post_View *vin, Post_View *vout){
  int nb, i, j=0, j0, j1, j2;
  Surface *s;
  Vertex *v;
  struct triangulateio in, out;

  List_T *points = List_Create(vin->NbSP,1,sizeof(Vertex*));
  nb = List_Nbr(vin->SP)/vin->NbSP ;

  for(i = 0 ; i < List_Nbr(vin->SP) ; i+=nb){
    v = Create_Vertex(j++,
		      *(double*)List_Pointer_Fast(vin->SP,i), 
		      *(double*)List_Pointer_Fast(vin->SP,i+1), 
		      *(double*)List_Pointer_Fast(vin->SP,i+2),
		      1., 0.);
    List_Add(points, &v);
  }

  s = Create_Surface(1,MSH_SURF_PLAN);
  MeanPlane(points, s);

  for(i=0;i<List_Nbr(points);i++){
    List_Read(points, i, &v);
    Projette (v, s->plan);
  }

  Free_Surface(&s,NULL);

  in.numberofpoints = List_Nbr(points);
  in.pointlist = (REAL *) Malloc(in.numberofpoints * 2 * sizeof(REAL));
  in.numberofpointattributes = 0;
  in.pointattributelist = NULL;
  in.pointmarkerlist = NULL; 
  in.numberofsegments = 0;
  in.segmentlist = NULL;    
  in.segmentmarkerlist = NULL;
  in.numberofregions = 0;
  in.regionlist = NULL; 
  in.numberofholes = 0;
  in.holelist = NULL;

  j=0;
  for(i=0;i<List_Nbr(points);i++){
    List_Read(points, i, &v);
    in.pointlist[j] = v->Pos.X;
    in.pointlist[j+1] = v->Pos.Y;
    j+=2;
  }

  for(i=0;i<List_Nbr(points);i++){
    List_Read(points, i, &v);
    Free_Vertex(&v,NULL);
  }
  List_Delete(points);

  out.pointlist = NULL; 
  out.pointattributelist = NULL;
  out.pointmarkerlist = NULL;
  out.trianglelist = NULL;
  out.triangleattributelist = NULL;
  out.neighborlist = NULL;
  out.segmentlist = NULL;
  out.segmentmarkerlist = NULL;
  out.edgelist = NULL;
  out.edgemarkerlist = NULL;

  char opts[128]="z";
  if(CTX.verbosity < 3) strcat(opts, "Q");
  triangulate(opts, &in, &out, NULL);

  Free(in.pointlist);
  Free(out.pointlist);

  for (i = 0; i < out.numberoftriangles; i++) {
    j0 = out.trianglelist[i * out.numberofcorners + 0];
    j1 = out.trianglelist[i * out.numberofcorners + 1];
    j2 = out.trianglelist[i * out.numberofcorners + 2];
    for(j=0;j<3;j++){
      List_Add(vout->ST, List_Pointer(vin->SP,(j0*nb)+j));
      List_Add(vout->ST, List_Pointer(vin->SP,(j1*nb)+j));
      List_Add(vout->ST, List_Pointer(vin->SP,(j2*nb)+j));
    }
    for(j=0;j<vin->NbTimeStep;j++){
      List_Add(vout->ST, List_Pointer(vin->SP,(j0*nb)+3+j));
      List_Add(vout->ST, List_Pointer(vin->SP,(j1*nb)+3+j));
      List_Add(vout->ST, List_Pointer(vin->SP,(j2*nb)+3+j));
    }
    vout->NbST++;
  }

  Free(out.trianglelist);

}


Post_View *GMSH_TriangulatePlugin::execute (Post_View *v)
{
  Post_View *vv, *View;

  int iView = (int)TriangulateOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(CTX.post.list,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }

  if(vv->NbSP > 2){
    View = BeginView(1);
    Triangulate(vv,View);
    char name[1024], filename[1024];
    sprintf(name,"triangulate-%s",vv->Name);
    sprintf(filename,"triangulate-%s",vv->FileName);
    EndView(View, 1, filename, name);
    Msg(INFO, "Created view '%s'", name);
    return View;
  }
  else{
    Msg(WARNING, "No scalar points to triangulate in view '%s'", vv->Name);
    return 0;
  }

}

void GMSH_TriangulatePlugin::Run ()
{
  execute(0);
}

void GMSH_TriangulatePlugin::Save ()
{
}

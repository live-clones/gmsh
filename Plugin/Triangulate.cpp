// $Id: Triangulate.cpp,v 1.22 2004-05-17 21:28:02 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTriangulatePlugin()
  {
    return new GMSH_TriangulatePlugin();
  }
}

GMSH_TriangulatePlugin::GMSH_TriangulatePlugin()
{
  ;
}

void GMSH_TriangulatePlugin::getName(char *name) const
{
  strcpy(name, "Triangulate");
}

void GMSH_TriangulatePlugin::getInfos(char *author, char *copyright,
                                      char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Triangulate) triangulates the points\n"
	 "in the scalar view `iView', assuming that all\n"
         "the points belong to a surface that can be\n"
	 "univoquely projected into a plane. If `iView'\n"
	 "< 0, the plugin is run on the current view.\n"
	 "\n"
	 "Plugin(Triangulate) creates one new view.\n");
}

int GMSH_TriangulatePlugin::getNbOptions() const
{
  return sizeof(TriangulateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TriangulatePlugin::getOption(int iopt)
{
  return &TriangulateOptions_Number[iopt];
}

void GMSH_TriangulatePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Triangulate failed...");
}

#if !defined(HAVE_TRIANGLE)

void Triangulate(Post_View * vin, Post_View * vout)
{
  Msg(GERROR, "Triangle is not compiled in this version of Gmsh");
}

#else

#define ANSI_DECLARATORS
#define REAL double

extern "C"
{
#include "triangle.h"
}

void Triangulate(Post_View * vin, Post_View * vout)
{
  int nb, i, j = 0, j0, j1, j2;
  Surface *s;
  Vertex *v;
  struct triangulateio in, out;

  List_T *points = List_Create(vin->NbSP, 1, sizeof(Vertex *));
  nb = List_Nbr(vin->SP) / vin->NbSP;

  for(i = 0; i < List_Nbr(vin->SP); i += nb) {
    v = Create_Vertex(j++,
                      *(double *)List_Pointer_Fast(vin->SP, i),
                      *(double *)List_Pointer_Fast(vin->SP, i + 1),
                      *(double *)List_Pointer_Fast(vin->SP, i + 2), 1., 0.);
    List_Add(points, &v);
  }

  s = Create_Surface(1, MSH_SURF_PLAN);
  MeanPlane(points, s);

  for(i = 0; i < List_Nbr(points); i++) {
    List_Read(points, i, &v);
    Projette(v, s->plan);
  }

  Free_Surface(&s, NULL);

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

  j = 0;
  for(i = 0; i < List_Nbr(points); i++) {
    List_Read(points, i, &v);
    in.pointlist[j] = v->Pos.X;
    in.pointlist[j + 1] = v->Pos.Y;
    j += 2;
  }

  for(i = 0; i < List_Nbr(points); i++) {
    List_Read(points, i, &v);
    Free_Vertex(&v, NULL);
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

  char opts[128] = "z";
  if(CTX.verbosity < 4)
    strcat(opts, "Q");
  triangulate(opts, &in, &out, NULL);

  Free(in.pointlist);
  Free(out.pointlist);

  for(i = 0; i < out.numberoftriangles; i++) {
    j0 = out.trianglelist[i * out.numberofcorners + 0];
    j1 = out.trianglelist[i * out.numberofcorners + 1];
    j2 = out.trianglelist[i * out.numberofcorners + 2];
    for(j = 0; j < 3; j++) {
      List_Add(vout->ST, List_Pointer(vin->SP, (j0 * nb) + j));
      List_Add(vout->ST, List_Pointer(vin->SP, (j1 * nb) + j));
      List_Add(vout->ST, List_Pointer(vin->SP, (j2 * nb) + j));
    }
    for(j = 0; j < vin->NbTimeStep; j++) {
      List_Add(vout->ST, List_Pointer(vin->SP, (j0 * nb) + 3 + j));
      List_Add(vout->ST, List_Pointer(vin->SP, (j1 * nb) + 3 + j));
      List_Add(vout->ST, List_Pointer(vin->SP, (j2 * nb) + 3 + j));
    }
    vout->NbST++;
  }

  Free(out.trianglelist);

}

#endif // !HAVE_TRIANGLE

Post_View *GMSH_TriangulatePlugin::execute(Post_View * v)
{
  int iView = (int)TriangulateOptions_Number[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);
  
  if(v1->NbSP > 2) {
    // FIXME: this is not secure: if BeginView forces a post.list
    // reallocation, v1 could be wrong
    Post_View *v2 = BeginView(1);
    Triangulate(v1, v2);
    // copy time data
    for(int i = 0; i < List_Nbr(v1->Time); i++)
      List_Add(v2->Time, List_Pointer(v1->Time, i));
    // finalize
    char name[1024], filename[1024];
    sprintf(name, "%s_Triangulate", v1->Name);
    sprintf(filename, "%s_Triangulate.pos", v1->Name);
    EndView(v2, 1, filename, name);
    return v2;
  }

  return v1;
}


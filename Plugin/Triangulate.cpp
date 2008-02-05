// $Id: Triangulate.cpp,v 1.41 2008-02-05 18:58:04 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <vector>
#include "GModel.h"
#include "discreteFace.h"
#include "DivideAndConquer.h"
#include "Message.h"
#include "MVertex.h"
#include "Triangulate.h"
#include "Malloc.h"
#include "Context.h"

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
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Triangulate) triangulates the points in the\n"
	 "view `iView', assuming that all the points belong\n"
         "to a surface that can be projected one-to-one\n"
	 "onto a plane. If `iView' < 0, the plugin is run on\n"
	 "the current view.\n"
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

static void Project(MVertex *v, double mat[3][3])
{
  double X = v->x() * mat[0][0] + v->y() * mat[0][1] + v->z() * mat[0][2];
  double Y = v->x() * mat[1][0] + v->y() * mat[1][1] + v->z() * mat[1][2];
  double Z = v->x() * mat[2][0] + v->y() * mat[2][1] + v->z() * mat[2][2];
  v->x() = X;
  v->y() = Y;
  v->z() = Z;
}

static void Triangulate(int nbIn, List_T *inList, int *nbOut, List_T *outList,
			int nbTimeStep, int nbComp)
{
  if(nbIn < 3) return;

  // project points onto plane
  std::vector<MVertex*> points;
  int nb = List_Nbr(inList) / nbIn;
  for(int i = 0; i < List_Nbr(inList); i += nb)
    points.push_back(new MVertex(*(double *)List_Pointer_Fast(inList, i),
				 *(double *)List_Pointer_Fast(inList, i + 1),
				 *(double *)List_Pointer_Fast(inList, i + 2)));
  discreteFace *s = new discreteFace(GModel::current(), GModel::current()->numFace() + 1);
  s->computeMeanPlane(points);
  double plan[3][3];
  s->getMeanPlaneData(plan);
  for(unsigned int i = 0; i < points.size(); i++) Project(points[i], plan);
  delete s;

  // get lc
  SBoundingBox3d bbox;
  for(unsigned int i = 0; i < points.size(); i++) bbox += points[i]->point();
  double lc = norm(SVector3(bbox.max(), bbox.min()));

  // build a point record structure for the divide and conquer
  DocRecord doc;  
  doc.points =  (PointRecord*)malloc(points.size() * sizeof(PointRecord));
  for (unsigned int i = 0; i < points.size(); i++){
    double XX = CTX.mesh.rand_factor * lc * (double)rand() / (double)RAND_MAX;
    double YY = CTX.mesh.rand_factor * lc * (double)rand() / (double)RAND_MAX;
    doc.points[i].where.h = points[i]->x() + XX;
    doc.points[i].where.v = points[i]->y() + YY;
    doc.points[i].adjacent = NULL;
    doc.points[i].data = List_Pointer_Fast(inList, i * nb); 
    delete points[i];
  }

  // triangulate
  Make_Mesh_With_Points(&doc, doc.points, points.size());

  // create output (using unperturbed data)
  for(int i = 0; i < doc.numTriangles; i++){
    double *pa = (double*)doc.points[doc.delaunay[i].t.a].data;
    double *pb = (double*)doc.points[doc.delaunay[i].t.b].data;
    double *pc = (double*)doc.points[doc.delaunay[i].t.c].data;
    for(int j = 0; j < 3; j++) {
      List_Add(outList, pa + j);
      List_Add(outList, pb + j);
      List_Add(outList, pc + j);
    }
    for(int j = 0; j < nbTimeStep; j++) {
      for(int k = 0; k < nbComp; k++) List_Add(outList, pa + 3 + j * nbComp + k);
      for(int k = 0; k < nbComp; k++) List_Add(outList, pb + 3 + j * nbComp + k);
      for(int k = 0; k < nbComp; k++) List_Add(outList, pc + 3 + j * nbComp + k);
    }
    (*nbOut)++;
  }

  free(doc.points);
  free(doc.delaunay);
}

PView *GMSH_TriangulatePlugin::execute(PView *v)
{
  int iView = (int)TriangulateOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  int nts = data1->getNumTimeSteps();
  Triangulate(data1->NbSP, data1->SP, &data2->NbST, data2->ST, nts, 1);
  Triangulate(data1->NbVP, data1->VP, &data2->NbVT, data2->VT, nts, 3);
  Triangulate(data1->NbTP, data1->TP, &data2->NbTT, data2->TT, nts, 9);

  for(int i = 0; i < List_Nbr(data1->Time); i++)
    List_Add(data2->Time, List_Pointer(data1->Time, i));
  data2->setName(data1->getName() + "_Triangulate");
  data2->setFileName(data1->getName() + "_Triangulate.pos");
  data2->finalize();

  return v2;
}

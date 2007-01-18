// $Id: Generator.cpp,v 1.113 2007-01-18 10:18:30 geuzaine Exp $
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

#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Views.h"
#include "OS.h"
#include "GModel.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "BackgroundMesh.h"
#include "SecondOrder.h"

extern Context_T CTX;
extern GModel *GMODEL;

template<class T>
static void GetQualityMeasure(std::vector<T*>& ele, 
			      double &gamma, double &gammaMin, double &gammaMax, 
			      double &eta, double &etaMin, double &etaMax, 
			      double &rho, double &rhoMin, double &rhoMax,
			      double quality[3][100])
{
  for(unsigned int i = 0; i < ele.size(); i++){
    double g = ele[i]->gammaShapeMeasure();
    gamma += g; 
    gammaMin = std::min(gammaMin, g); 
    gammaMax = std::max(gammaMax, g);
    double e = ele[i]->etaShapeMeasure();
    eta += e; 
    etaMin = std::min(etaMin, e); 
    etaMax = std::max(etaMax, e);
    double r = ele[i]->rhoShapeMeasure();
    rho += r; 
    rhoMin = std::min(rhoMin, r); 
    rhoMax = std::max(rhoMax, r);
    for(int j = 0; j < 100; j++){
      if(g > j / 100. && g <= (j + 1) / 100.) quality[0][j]++;
      if(e > j / 100. && e <= (j + 1) / 100.) quality[1][j]++;
      if(r > j / 100. && r <= (j + 1) / 100.) quality[2][j]++;
    }
  }
}

void GetStatistics(double stat[50], double quality[3][100])
{
  for(int i = 0; i < 50; i++) stat[i] = 0.;

  stat[0] = GMODEL->numVertex();
  stat[1] = GMODEL->numEdge();
  stat[2] = GMODEL->numFace();
  stat[3] = GMODEL->numRegion();
  
  std::map<int, std::vector<GEntity*> > physicals[4];
  GMODEL->getPhysicalGroups(physicals);
  stat[45] = physicals[0].size() + physicals[1].size() + 
    physicals[2].size() + physicals[3].size();
  
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); ++it)
    stat[4] += (*it)->mesh_vertices.size();
  
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); ++it){
    stat[5] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
  }
  
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); ++it){
    stat[6] += (*it)->mesh_vertices.size();
    stat[9] += (*it)->tetrahedra.size();
    stat[10] += (*it)->hexahedra.size();
    stat[11] += (*it)->prisms.size();
    stat[12] += (*it)->pyramids.size();
  }
  
  stat[13] = CTX.mesh_timer[0];
  stat[14] = CTX.mesh_timer[1];
  stat[15] = CTX.mesh_timer[2];
  
  if(quality){
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 100; j++)
	quality[i][j] = 0.;
    double gamma=0., gammaMin=1., gammaMax=0.;
    double eta=0., etaMin=1., etaMax=0.;
    double rho=0., rhoMin=1., rhoMax=0.;
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); ++it){
      GetQualityMeasure((*it)->tetrahedra, gamma, gammaMin, gammaMax,
			eta, etaMin, etaMax, rho, rhoMin, rhoMax, quality);
      GetQualityMeasure((*it)->hexahedra, gamma, gammaMin, gammaMax,
			eta, etaMin, etaMax, rho, rhoMin, rhoMax, quality);
      GetQualityMeasure((*it)->prisms, gamma, gammaMin, gammaMax,
			eta, etaMin, etaMax, rho, rhoMin, rhoMax, quality);
      GetQualityMeasure((*it)->pyramids, gamma, gammaMin, gammaMax,
			eta, etaMin, etaMax, rho, rhoMin, rhoMax, quality);
    }
    double N = stat[9] + stat[10] + stat[11] + stat[12];
    stat[17] = N ? gamma / N : 0.;
    stat[18] = gammaMin;
    stat[19] = gammaMax;
    stat[20] = N ? eta / N : 0.;
    stat[21] = etaMin;
    stat[22] = etaMax;
    stat[23] = N ? rho / N : 0;
    stat[24] = rhoMin;
    stat[25] = rhoMax;
  }

  stat[26] = List_Nbr(CTX.post.list);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    stat[27] += v->NbSP + v->NbVP + v->NbTP;
    stat[28] += v->NbSL + v->NbVL + v->NbTL;
    stat[29] += v->NbST + v->NbVT + v->NbTT;
    stat[30] += v->NbSQ + v->NbVQ + v->NbTQ;
    stat[31] += v->NbSS + v->NbVS + v->NbTS;
    stat[32] += v->NbSH + v->NbVH + v->NbTH;
    stat[33] += v->NbSI + v->NbVI + v->NbTI;
    stat[34] += v->NbSY + v->NbVY + v->NbTY;
    stat[35] += v->NbT2 + v->NbT3;
    if(v->Visible) {
      if(v->DrawPoints)
        stat[36] += 
	  (v->DrawScalars ? v->NbSP : 0) + (v->DrawVectors ? v->NbVP : 0) + 
	  (v->DrawTensors ? v->NbTP : 0);
      if(v->DrawLines)
        stat[37] += 
	  (v->DrawScalars ? v->NbSL : 0) + (v->DrawVectors ? v->NbVL : 0) + 
	  (v->DrawTensors ? v->NbTL : 0);
      if(v->DrawTriangles)
        stat[38] += 
	  (v->DrawScalars ? v->NbST : 0) + (v->DrawVectors ? v->NbVT : 0) + 
	  (v->DrawTensors ? v->NbTT : 0);
      if(v->DrawQuadrangles)
        stat[39] +=
	  (v->DrawScalars ? v->NbSQ : 0) + (v->DrawVectors ? v->NbVQ : 0) + 
	  (v->DrawTensors ? v->NbTQ : 0);
      if(v->DrawTetrahedra)
        stat[40] += 
	  (v->DrawScalars ? v->NbSS : 0) + (v->DrawVectors ? v->NbVS : 0) + 
	  (v->DrawTensors ? v->NbTS : 0);
      if(v->DrawHexahedra)
        stat[41] +=
	  (v->DrawScalars ? v->NbSH : 0) + (v->DrawVectors ? v->NbVH : 0) +
	  (v->DrawTensors ? v->NbTH : 0);
      if(v->DrawPrisms)
        stat[42] += 
	  (v->DrawScalars ? v->NbSI : 0) + (v->DrawVectors ? v->NbVI : 0) +
	  (v->DrawTensors ? v->NbTI : 0);
      if(v->DrawPyramids)
        stat[43] += 
	  (v->DrawScalars ? v->NbSY : 0) + (v->DrawVectors ? v->NbVY : 0) + 
	  (v->DrawTensors ? v->NbTY : 0);
      if(v->DrawStrings)
        stat[44] += v->NbT2 + v->NbT3;
    }
  }

}

bool TooManyElements(int dim){
  if(CTX.expert_mode || !GMODEL->numVertex()) return false;

  // try to detect obvious mistakes in characteristic lenghts (one of
  // the most common cause for erroneous bug reports on the mailing
  // list)
  double sumAllLc = 0.;
  for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); ++it)
    sumAllLc += (*it)->prescribedMeshSizeAtVertex();
  sumAllLc /= (double)GMODEL->numVertex();
  if(!sumAllLc || pow(CTX.lc / sumAllLc, dim) > 1.e10) 
    return !GetBinaryAnswer("Your choice of characteristic lengths will likely produce\n"
			    "a very large mesh. Do you really want to continue?\n\n"
			    "(To disable this warning in the future, select `Enable\n"
			    "expert mode' in the option dialog.)",
			    "Continue", "Cancel");
  return false;
}

void Mesh1D()
{
  if(TooManyElements(1)) return;
  Msg(STATUS1, "Meshing 1D...");
  double t1 = Cpu();

  std::for_each(GMODEL->firstEdge(), GMODEL->lastEdge(), meshGEdge());

  double t2 = Cpu();
  CTX.mesh_timer[0] = t2 - t1;
  Msg(INFO, "Mesh 1D complete (%g s)", CTX.mesh_timer[0]);
  Msg(STATUS1, "Mesh");
}

void Mesh2D()
{
  if(TooManyElements(2)) return;
  Msg(STATUS1, "Meshing 2D...");
  double t1 = Cpu();

  std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), meshGFace());

  double t2 = Cpu();
  CTX.mesh_timer[1] = t2 - t1;
  Msg(INFO, "Mesh 2D complete (%g s)", CTX.mesh_timer[1]);
  Msg(STATUS1, "Mesh");
}

void Mesh3D()
{
  if(TooManyElements(3)) return;
  Msg(STATUS1, "Meshing 3D...");
  double t1 = Cpu();

  // mesh the extruded volumes first
  std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), meshGRegionExtruded());
  // then subdivide if necessary (unfortunately the subdivision is a
  // global operation, which can require changing the surface mesh!)
  SubdivideExtrudedMesh(GMODEL);
  // then mesh all the non-delaunay regions
  std::vector<GRegion*> delaunay;
  std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), meshGRegion(delaunay));
  // and finally mesh the delaunay regions (again, this is global)
  MeshDelaunayVolume(delaunay);

  double t2 = Cpu();
  CTX.mesh_timer[2] = t2 - t1;
  Msg(INFO, "Mesh 3D complete (%g s)", CTX.mesh_timer[2]);
  Msg(STATUS1, "Mesh");
}

void OptimizeMesh()
{
  Msg(STATUS1, "Optimizing 3D...");
  double t1 = Cpu();

  std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), optimizeMeshGRegion());

  double t2 = Cpu();
  Msg(INFO, "Mesh 3D optimization complete (%g s)", t2 - t1);
  Msg(STATUS1, "Mesh");
}

void GenerateMesh(int ask)
{
  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;

  int old = GMODEL->getMeshStatus();

  // Change any high order elements back into first order ones
  Degre1();

  // 1D mesh
  if(ask == 1 || (ask > 1 && old < 1)) {
    std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), deMeshGRegion());
    std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), deMeshGFace());
    Mesh1D();
  }

  // 2D mesh
  if(ask == 2 || (ask > 2 && old < 2)) {
    std::for_each(GMODEL->firstRegion(), GMODEL->lastRegion(), deMeshGRegion());
    Mesh2D();
  }

  // 3D mesh
  if(ask == 3) {
    Mesh3D();
  }

  // Orient the surface mesh so that it matches the geometry
  if(GMODEL->getMeshStatus() >= 2)
    std::for_each(GMODEL->firstFace(), GMODEL->lastFace(), orientMeshGFace());

  // Optimize quality
  if(GMODEL->getMeshStatus() == 3 && CTX.mesh.optimize)
    OptimizeMesh();
  
  // Create second order elements
  if(GMODEL->getMeshStatus() && CTX.mesh.order == 2) 
    Degre2(CTX.mesh.second_order_linear, CTX.mesh.second_order_incomplete);

  CTX.threads_lock = 0;
  CTX.mesh.changed = ENT_ALL;
}

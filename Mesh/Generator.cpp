// $Id: Generator.cpp,v 1.124 2007-11-04 21:03:17 remacle Exp $
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
#include "PView.h"
#include "OS.h"
#include "GModel.h"
#include "meshGEdge.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "BackgroundMesh.h"
#include "BoundaryLayer.h"
#include "HighOrder.h"

extern Context_T CTX;

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

  GModel *m = GModel::current();

  stat[0] = m->numVertex();
  stat[1] = m->numEdge();
  stat[2] = m->numFace();
  stat[3] = m->numRegion();
  
  std::map<int, std::vector<GEntity*> > physicals[4];
  m->getPhysicalGroups(physicals);
  stat[45] = physicals[0].size() + physicals[1].size() + 
    physicals[2].size() + physicals[3].size();
  
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    stat[4] += (*it)->mesh_vertices.size();
  
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    stat[5] += (*it)->mesh_vertices.size();
    stat[7] += (*it)->triangles.size();
    stat[8] += (*it)->quadrangles.size();
  }
  
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
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
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
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

  stat[26] = PView::list.size();
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    PViewData *data = PView::list[i]->getData();
    stat[27] += data->getNumElements(PViewData::Point);
    stat[28] += data->getNumElements(PViewData::Line);
    stat[29] += data->getNumElements(PViewData::Triangle);
    stat[30] += data->getNumElements(PViewData::Quadrangle);
    stat[31] += data->getNumElements(PViewData::Tetrahedron);
    stat[32] += data->getNumElements(PViewData::Hexahedron);
    stat[33] += data->getNumElements(PViewData::Prism);
    stat[34] += data->getNumElements(PViewData::Pyramid);
    stat[35] += data->getNumStrings2D() + data->getNumStrings3D();
  }
}

bool TooManyElements(GModel *m, int dim)
{
  if(CTX.expert_mode || !m->numVertex()) return false;

  // try to detect obvious mistakes in characteristic lenghts (one of
  // the most common cause for erroneous bug reports on the mailing
  // list)
  double sumAllLc = 0.;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it)
    sumAllLc += (*it)->prescribedMeshSizeAtVertex();
  sumAllLc /= (double)m->numVertex();
  if(!sumAllLc || pow(CTX.lc / sumAllLc, dim) > 1.e10) 
    return !GetBinaryAnswer("Your choice of characteristic lengths will likely produce\n"
			    "a very large mesh. Do you really want to continue?\n\n"
			    "(To disable this warning in the future, select `Enable\n"
			    "expert mode' in the option dialog.)",
			    "Continue", "Cancel");
  return false;
}

void Mesh1D(GModel *m)
{
  if(TooManyElements(m, 1)) return;
  Msg(STATUS1, "Meshing 1D...");
  double t1 = Cpu();

  std::for_each(m->firstEdge(), m->lastEdge(), meshGEdge());

  double t2 = Cpu();
  CTX.mesh_timer[0] = t2 - t1;
  Msg(INFO, "Mesh 1D complete (%g s)", CTX.mesh_timer[0]);
  Msg(STATUS1, "Mesh");
}

void PrintMesh2dStatistics (GModel *m)
{
  double worst=1,best=0,avg=0;
  double e_long=0,e_short=1.e22,e_avg=0;
  int nTotT=0,nTotE=0,nTotGoodLength=0,nTotGoodQuality=0;
  Msg(INFO,"2D Mesh Statistics :");
  for (GModel::fiter it = m->firstFace() ; it!=m->lastFace(); ++it)
    {
      worst = std::min((*it)->meshStatistics.worst_element_shape,worst);
      best  = std::max((*it)->meshStatistics.best_element_shape,best);
      avg += (*it)->meshStatistics.average_element_shape * (*it)->meshStatistics.nbTriangle ;

      e_avg += (*it)->meshStatistics.efficiency_index ;//* (*it)->meshStatistics.nbEdge;

      e_long = std::max((*it)->meshStatistics.longest_edge_length,e_long);
      e_short = std::min((*it)->meshStatistics.smallest_edge_length,e_short);

      if ((*it)->meshStatistics.worst_element_shape < 0.05)
	Msg(INFO,"Badly Shaped Element (rho = %12.5E) on GFace %d (%d triangles)",(*it)->meshStatistics.worst_element_shape,(*it)->tag(),(*it)->meshStatistics.nbTriangle);
      if ((*it)->meshStatistics.status == GFace::FAILED)
	Msg(INFO,"GMSH was unable to mesh GFace %d ",(*it)->tag());

      nTotT +=  (*it)->meshStatistics.nbTriangle ;
      nTotE += (*it)->meshStatistics.nbEdge ;
      nTotGoodLength += (*it)->meshStatistics.nbGoodLength ;
      nTotGoodQuality+= (*it)->meshStatistics.nbGoodQuality ;
    }

  Msg(INFO,"Element Quality (%d triangles) : avg %8.7f best %8.7f worst %8.7f greaterthan90 %d (%12.5E\\%)",
      nTotT,avg/(double)nTotT,best,worst,nTotGoodQuality,(double)nTotGoodQuality/nTotT);
  Msg(INFO,"Size Field Accuracy (%d edges) : %8.7f (should be as close as 1 as possible) in good brackets %d (%12.5E\%)",
      nTotE,exp(e_avg/(double)nTotE),nTotGoodLength,(double)nTotGoodLength/nTotE);


}

void Mesh2D(GModel *m)
{
  if(TooManyElements(m, 2)) return;

  if(CTX.mesh.algo2d == ALGO_2D_DELAUNAY && !CTX.expert_mode){
    if(!GetBinaryAnswer("The 2D Delaunay algorithm is still highly experimental\n"
			"and produces triangles with random orientations. Do you\n"
			"really want to continue?\n\n"
			"(To disable this warning in the future, select `Enable\n"
			"expert mode' in the option dialog.)",
			"Continue", "Cancel")) return;
  }

  Msg(STATUS1, "Meshing 2D...");
  double t1 = Cpu();

  // boundary layers are special: their generation (including vertices
  // and curve meshes) is global as it depends on a smooth normal
  // field generated from the surface mesh of the source surfaces
  if(!Mesh2DWithBoundaryLayers(m))
    std::for_each(m->firstFace(), m->lastFace(), meshGFace());  
  
  PrintMesh2dStatistics(m);

  double t2 = Cpu();
  CTX.mesh_timer[1] = t2 - t1;
  Msg(INFO, "Mesh 2D complete (%g s)", CTX.mesh_timer[1]);
  Msg(STATUS1, "Mesh");
}


void FindConnectedRegions(std::vector<GRegion*> &delaunay, 
			  std::vector<std::vector<GRegion*> > &connected)
{
  // FIXME: need to split region vector into connected components here!
  connected.push_back(delaunay);
}

void Mesh3D(GModel *m)
{
  if(TooManyElements(m, 3)) return;
  Msg(STATUS1, "Meshing 3D...");
  double t1 = Cpu();

  // mesh the extruded volumes first
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegionExtruded());

  // then subdivide if necessary (unfortunately the subdivision is a
  // global operation, which can require changing the surface mesh!)
  SubdivideExtrudedMesh(m);

  // then mesh all the non-delaunay regions
  std::vector<GRegion*> delaunay;
  std::for_each(m->firstRegion(), m->lastRegion(), meshGRegion(delaunay));

  // and finally mesh the delaunay regions (again, this is global; but
  // we mesh each connected part separately for performance and mesh
  // quality reasons)
  std::vector<std::vector<GRegion*> > connected;
  FindConnectedRegions(delaunay, connected);
  for(unsigned int i = 0; i < connected.size(); i++)
    MeshDelaunayVolume(connected[i]);

  double t2 = Cpu();
  CTX.mesh_timer[2] = t2 - t1;
  Msg(INFO, "Mesh 3D complete (%g s)", CTX.mesh_timer[2]);
  Msg(STATUS1, "Mesh");
}

void OptimizeMesh(GModel *m)
{
  Msg(STATUS1, "Optimizing 3D...");
  double t1 = Cpu();

  std::for_each(m->firstRegion(), m->lastRegion(), optimizeMeshGRegion());

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

  GModel *m = GModel::current();

  int old = m->getMeshStatus(false);

  // Change any high order elements back into first order ones
  SetOrder1(m);

  // 1D mesh
  if(ask == 1 || (ask > 1 && old < 1)) {
    std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
    std::for_each(m->firstFace(), m->lastFace(), deMeshGFace());
    Mesh1D(m);
  }

  // 2D mesh
  if(ask == 2 || (ask > 2 && old < 2)) {
    std::for_each(m->firstRegion(), m->lastRegion(), deMeshGRegion());
    Mesh2D(m);
  }

  // 3D mesh
  if(ask == 3) {
    Mesh3D(m);
  }

  // Orient the surface mesh so that it matches the geometry
  if(m->getMeshStatus() >= 2)
    std::for_each(m->firstFace(), m->lastFace(), orientMeshGFace());
  
  // Optimize quality
  if(m->getMeshStatus() == 3 && CTX.mesh.optimize)
    OptimizeMesh(m);
  
  // Create high order elements
  if(m->getMeshStatus() && CTX.mesh.order > 1) 
    SetOrderN(m, CTX.mesh.order, CTX.mesh.second_order_linear, 
	      CTX.mesh.second_order_incomplete);

  Msg(INFO, "%d vertices %d elements", m->numVertices(), m->numElements());

  CTX.threads_lock = 0;
  CTX.mesh.changed = ENT_ALL;
}

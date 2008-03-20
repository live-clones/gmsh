// $Id: meshGRegion.cpp,v 1.45 2008-03-20 11:44:09 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "meshGRegion.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "gmshRegion.h"
#include "BDS.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;

void getAllBoundingVertices(GRegion *gr, std::set<MVertex*> &allBoundingVertices)
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  
  while (it != faces.end()){
    GFace *gf = (*it);      
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      for(int k = 0; k < 3; k++)
        if(allBoundingVertices.find(t->getVertex(k)) ==  allBoundingVertices.end())
          allBoundingVertices.insert(t->getVertex(k));
    }
    ++it;
  }
}

#if defined(HAVE_TETGEN)

#include "tetgen.h"

void buildTetgenStructure(GRegion *gr, tetgenio &in, std::vector<MVertex*> &numberedV)
{
  std::set<MVertex*> allBoundingVertices;
  getAllBoundingVertices(gr, allBoundingVertices);

  in.mesh_dim = 3;
  in.firstnumber = 1;
  in.numberofpoints = allBoundingVertices.size();
  in.pointlist = new REAL[in.numberofpoints * 3];
  in.pointmarkerlist = NULL;

  std::set<MVertex*>::iterator itv =  allBoundingVertices.begin();
  int I = 1;
  while(itv != allBoundingVertices.end()){
    in.pointlist[(I-1)*3 + 0] = (*itv)->x();
    in.pointlist[(I-1)*3 + 1] = (*itv)->y();
    in.pointlist[(I-1)*3 + 2] = (*itv)->z();
    (*itv)->setNum(I++);
    numberedV.push_back(*itv);
    ++itv;
  }
  
  int nbFace = 0;
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while(it != faces.end()){
    GFace *gf = (*it);
    nbFace += gf->triangles.size();
    ++it;
  }

  in.numberoffacets = nbFace;
  in.facetlist = new tetgenio::facet[in.numberoffacets];
  in.facetmarkerlist = new int[in.numberoffacets];

  it = faces.begin();
  I = 0;
  while(it != faces.end()){
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      tetgenio::facet *f = &in.facetlist[I];
      tetgenio::init(f);
      f->numberofholes = 0;
      f->numberofpolygons = 1;
      f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
      tetgenio::polygon *p = &f->polygonlist[0];
      tetgenio::init(p);
      p->numberofvertices = 3;
      p->vertexlist = new int[p->numberofvertices];
      p->vertexlist[0] = t->getVertex(0)->getNum();
      p->vertexlist[1] = t->getVertex(1)->getNum();
      p->vertexlist[2] = t->getVertex(2)->getNum();
      in.facetmarkerlist[I] = gf->tag();
      ++I;
    }
    ++it;
  }   
}

void TransferTetgenMesh(GRegion *gr, tetgenio &in, tetgenio &out, 
                        std::vector<MVertex*> &numberedV)
{
  for(int i = numberedV.size(); i < out.numberofpoints; i++){
    MVertex *v = new MVertex(out.pointlist[i * 3 + 0],
                             out.pointlist[i * 3 + 1],
                             out.pointlist[i * 3 + 2], gr); 
    gr->mesh_vertices.push_back(v);
    numberedV.push_back(v);
  }
 
  Msg(INFO,"%d points %d edges and %d faces in the final mesh",
      out.numberofpoints, out.numberofedges, out.numberoftrifaces);

  // Tetgen modifies both surface & edge mesh, so we need to re-create
  // everything
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while(it != faces.end()){
    GFace *gf = (*it); 
    for(unsigned int i = 0; i < gf->triangles.size(); i++)
      delete gf->triangles[i];
    gf->triangles.clear();
    gf->deleteVertexArrays();
    ++it;
  }
  
  // TODO: re-create 1D mesh
  for(int i = 0; i < out.numberofedges; i++){
    MVertex *v[2];
    v[0] = numberedV[out.edgelist[i * 2 + 0] - 1];
    v[1] = numberedV[out.edgelist[i * 2 + 1] - 1];
  }

  // re-create the triangular meshes FIXME: this can lead to hanging
  // nodes for non manifold geometries (single surface connected to
  // volume)
  for (int i = 0; i < out.numberoftrifaces; i++){
    MVertex *v[3];
    v[0] = numberedV[out.trifacelist[i * 3 + 0] - 1];
    v[1] = numberedV[out.trifacelist[i * 3 + 1] - 1];
    v[2] = numberedV[out.trifacelist[i * 3 + 2] - 1];
    GFace *gf = gr->model()->getFaceByTag(out.trifacemarkerlist[i]);
    for(int j = 0; j < 3; j++){   
      if(v[j]->onWhat()->dim() == 3){
        v[j]->onWhat()->mesh_vertices.erase
          (std::find(v[j]->onWhat()->mesh_vertices.begin(),
                     v[j]->onWhat()->mesh_vertices.end(),
                     v[j]));
        MVertex *v1b = new MVertex(v[j]->x(), v[j]->y(), v[j]->z(), gf);
        gf->mesh_vertices.push_back(v1b);
        numberedV[out.trifacelist[i * 3 + j] - 1] = v1b;
        delete v[j];
        v[j] = v1b;
      }
    }
    MTriangle *t = new  MTriangle(v[0], v[1], v[2]);
    gf->triangles.push_back(t);   
  }
  for(int i = 0; i < out.numberoftetrahedra; i++){
    MVertex *v1 = numberedV[out.tetrahedronlist[i * 4 + 0] - 1];
    MVertex *v2 = numberedV[out.tetrahedronlist[i * 4 + 1] - 1];
    MVertex *v3 = numberedV[out.tetrahedronlist[i * 4 + 2] - 1];
    MVertex *v4 = numberedV[out.tetrahedronlist[i * 4 + 3] - 1];
    MTetrahedron *t = new  MTetrahedron(v1, v2, v3, v4);
    gr->tetrahedra.push_back(t);
  }
}

#endif

void MeshDelaunayVolume(std::vector<GRegion*> &regions)
{
  if(regions.empty()) return;

#if !defined(HAVE_TETGEN)
  Msg(GERROR, "Tetgen is not compiled in this version of Gmsh");
#else

  for(unsigned int i = 0; i < regions.size(); i++)
    Msg(STATUS2, "Meshing volume %d (Tetgen+Delaunay)", regions[i]->tag());

  // put all the faces in the same model
  GRegion *gr = regions[0];
  std::list<GFace*> faces = gr->faces();

  std::set<GFace*> allFacesSet;
  for(unsigned int i = 0; i < regions.size(); i++){
    std::list<GFace*> f = regions[i]->faces();
    allFacesSet.insert(f.begin(), f.end());
  }
  std::list<GFace*> allFaces;
  for(std::set<GFace*>::iterator it = allFacesSet.begin(); it != allFacesSet.end(); it++)
    allFaces.push_back(*it);
  gr->set(allFaces);

  // mesh with tetgen, possibly changing the mesh on boundaries (leave
  // this in block, so in/out are destroyed before we refine the mesh)
  {
    tetgenio in, out;
    std::vector<MVertex*> numberedV;
    char opts[128];
    buildTetgenStructure(gr, in, numberedV);
    sprintf(opts, "pe%c", (CTX.verbosity < 3) ? 'Q': (CTX.verbosity > 6)? 'V': '\0');
    try{
      tetrahedralize(opts, &in, &out);
    }
    catch (int error){
      Msg (WARNING, "Self intersecting Surface Mesh, computing intersections "
           "(this could take a while)");
      sprintf(opts, "dV");
      try{
        tetrahedralize(opts, &in, &out);
        Msg(INFO,"%d faces self-intersect",out.numberoftrifaces);
        for (int i = 0; i < out.numberoftrifaces; i++){
          Msg(INFO,"face (%d %d %d) on model face %d",
              numberedV[out.trifacelist[i * 3 + 0] - 1]->getNum(),
              numberedV[out.trifacelist[i * 3 + 1] - 1]->getNum(),
              numberedV[out.trifacelist[i * 3 + 2] - 1]->getNum(),
              out.trifacemarkerlist[i]);
        }
      }
      catch (int error2){
        Msg(GERROR, "Surface Mesh is wrong, cannot do the 3D mesh");      
      }
      gr->set(faces);
      return;
    }
    TransferTetgenMesh(gr, in, out, numberedV);
  }

  // sort triangles in all model faces in order to be able to search in vectors
  std::list<GFace*>::iterator itf =  allFaces.begin();
  while(itf != allFaces.end()){
    compareMTriangleLexicographic cmp;
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(), cmp);
    ++itf;
  }

  // restore the initial set of faces
  gr->set(faces);

  // now do insertion of points
  insertVerticesInRegion(gr);
  Msg(INFO, "Gmsh 3D Delaunay has generated %d tets", gr->tetrahedra.size());
#endif
}

#if defined(HAVE_NETGEN)

namespace nglib {
#include "nglib.h"
#include "nglib_addon.h"
}
using namespace nglib;

Ng_Mesh *buildNetgenStructure(GRegion *gr, bool importVolumeMesh,
                              std::vector<MVertex*> &numberedV)
{
  NgAddOn_Init();
  Ng_Mesh *ngmesh = Ng_NewMesh();

  std::set<MVertex*> allBoundingVertices;
  getAllBoundingVertices(gr, allBoundingVertices);
  
  std::set<MVertex*>::iterator itv = allBoundingVertices.begin();
  int I = 1;
  while(itv != allBoundingVertices.end()){
    double tmp[3];
    tmp[0] = (*itv)->x();
    tmp[1] = (*itv)->y();
    tmp[2] = (*itv)->z();
    (*itv)->setNum(I++);
    numberedV.push_back(*itv);
    Ng_AddPoint(ngmesh, tmp);
    ++itv;
  }

  if(importVolumeMesh){
    for(unsigned int i = 0; i < gr->mesh_vertices.size(); i++){
      double tmp[3];
      tmp[0] = gr->mesh_vertices[i]->x();
      tmp[1] = gr->mesh_vertices[i]->y();
      tmp[2] = gr->mesh_vertices[i]->z();
      gr->mesh_vertices[i]->setNum(I++);
      Ng_AddPoint(ngmesh, tmp);
    }
  }
  
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while(it != faces.end()){
    GFace *gf = (*it);
    for(unsigned int i = 0; i< gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      int tmp[3];
      tmp[0] = t->getVertex(0)->getNum();
      tmp[1] = t->getVertex(1)->getNum();
      tmp[2] = t->getVertex(2)->getNum();
      Ng_AddSurfaceElement(ngmesh, NG_TRIG, tmp);
    }
    ++it;
  }
  
  if(importVolumeMesh){
    for(unsigned int i = 0; i< gr->tetrahedra.size(); i++){
      MTetrahedron *t = gr->tetrahedra[i];
      // netgen expects tet with negative volume
      if(t->getVolumeSign() > 0) t->revert();
      int tmp[4];
      tmp[0] = t->getVertex(0)->getNum();
      tmp[1] = t->getVertex(1)->getNum();
      tmp[2] = t->getVertex(2)->getNum();
      tmp[3] = t->getVertex(3)->getNum();
      Ng_AddVolumeElement(ngmesh, NG_TET, tmp);
    }
  }
  
  return ngmesh;
}

void TransferVolumeMesh(GRegion *gr, Ng_Mesh *ngmesh, 
                        std::vector<MVertex*> &numberedV)
{
  // Gets total number of vertices of Netgen's mesh
  int nbv = Ng_GetNP(ngmesh);  
  if(!nbv) return;

  int nbpts = numberedV.size();

  // Create new volume vertices
  for(int i = nbpts; i < nbv; i++){
    double tmp[3];
    Ng_GetPoint(ngmesh, i + 1, tmp);
    MVertex *v = new MVertex (tmp[0], tmp[1], tmp[2], gr);
    numberedV.push_back(v);
    gr->mesh_vertices.push_back(v);
  }
  
  // Get total number of simplices of Netgen's mesh
  int nbe = Ng_GetNE(ngmesh);
  
  // Create new volume simplices
  for(int i = 0; i < nbe; i++){
    int tmp[4];
    Ng_GetVolumeElement(ngmesh, i + 1, tmp);
    MTetrahedron *t = new MTetrahedron(numberedV[tmp[0] - 1],
                                       numberedV[tmp[1] - 1],
                                       numberedV[tmp[2] - 1],
                                       numberedV[tmp[3] - 1]);
    gr->tetrahedra.push_back(t);
  }  
}

#endif

void deMeshGRegion::operator() (GRegion *gr)
{
  if(gr->geomType() == GEntity::DiscreteVolume) return;

  for(unsigned int i = 0; i < gr->mesh_vertices.size(); i++)
    delete gr->mesh_vertices[i];
  gr->mesh_vertices.clear();
  gr->transfinite_vertices.clear();
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
    delete gr->tetrahedra[i];
  gr->tetrahedra.clear();
  for(unsigned int i = 0; i < gr->hexahedra.size(); i++) 
    delete gr->hexahedra[i];
  gr->hexahedra.clear();
  for(unsigned int i = 0; i < gr->prisms.size(); i++) 
    delete gr->prisms[i];
  gr->prisms.clear();
  for(unsigned int i = 0; i < gr->pyramids.size(); i++)
    delete gr->pyramids[i];
  gr->pyramids.clear();
  gr->deleteVertexArrays();
}

int intersect_line_triangle(double X[3], double Y[3], double Z[3] , 
                            double P[3], double N[3] )
{
  double mat[3][3], det;
  double b[3], res[3];
  const double eps_prec = 1.e-9;

  mat[0][0] = X[1] - X[0];
  mat[0][1] = X[2] - X[0];
  mat[0][2] = N[0];

  mat[1][0] = Y[1] - Y[0];
  mat[1][1] = Y[2] - Y[0];
  mat[1][2] = N[1];

  mat[2][0] = Z[1] - Z[0];
  mat[2][1] = Z[2] - Z[0];
  mat[2][2] = N[2];

  b[0] = P[0] - X[0];
  b[1] = P[1] - Y[0];
  b[2] = P[2] - Z[0];

  if(!sys3x3_with_tol(mat, b, res, &det))
    return 0;

  // Msg(INFO, "going there %g %g %g", res[0], res[1], res[2]);

  if(res[0] >= eps_prec && res[0] <= 1.0 - eps_prec && 
     res[1] >= eps_prec && res[1] <= 1.0 - eps_prec && 
     1 - res[0] - res[1] >= eps_prec && 1 - res[0] - res[1] <= 1.0 - eps_prec){
    // the line clearly intersects the triangle
    return (res[2] > 0) ? 1 : 0;
  }
  else if(res[0] < -eps_prec || res[0] > 1.0 + eps_prec || 
          res[1] < -eps_prec || res[1] > 1.0 + eps_prec || 
          1 - res[0] - res[1] < -eps_prec || 1 - res[0] - res[1] > 1.0 + eps_prec){
    // the line clearly does NOT intersect the triangle
    return 0;
  }
  else{
    // the intersection is not robust, try another triangle
    return -10000;
  }
}

void setRand(double r[6])
{
  for (int i=0;i<6;i++)
    r[i] = 0.0001 * ((double)rand() / (double)RAND_MAX);
}

void meshNormalsPointOutOfTheRegion(GRegion *gr)
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();

  double rrr[6];
  setRand(rrr);
                   
  while(it != faces.end()){
    GFace *gf = (*it); 
    int nb_intersect = 0;
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      double X[3] = {t->getVertex(0)->x(), t->getVertex(1)->x(), t->getVertex(2)->x()};
      double Y[3] = {t->getVertex(0)->y(), t->getVertex(1)->y(), t->getVertex(2)->y()};
      double Z[3] = {t->getVertex(0)->z(), t->getVertex(1)->z(), t->getVertex(2)->z()};
      double P[3] = {(X[0]+X[1]+X[2])/3., (Y[0]+Y[1]+Y[2])/3., (Z[0]+Z[1]+Z[2])/3.};
      double v1[3] = {X[0]-X[1], Y[0]-Y[1], Z[0]-Z[1]};
      double v2[3] = {X[2]-X[1], Y[2]-Y[1], Z[2]-Z[1]};
      double N[3];
      prodve(v1, v2, N);
      norme(v1);
      norme(v2);
      norme(N);
      N[0] += rrr[0] * v1[0] + rrr[1] * v2[0];
      N[1] += rrr[2] * v1[1] + rrr[3] * v2[1];
      N[2] += rrr[4] * v1[2] + rrr[5] * v2[2];
      norme(N);
      std::list<GFace*>::iterator it_b = faces.begin();
      while(it_b != faces.end()){
        GFace *gf_b = (*it_b);
        for(unsigned int i_b = 0; i_b < gf_b->triangles.size(); i_b++){
          MTriangle *t_b = gf_b->triangles[i_b];
          if(t_b != t){
            double X_b[3] = {t_b->getVertex(0)->x(), t_b->getVertex(1)->x(), 
                             t_b->getVertex(2)->x()};
            double Y_b[3] = {t_b->getVertex(0)->y(), t_b->getVertex(1)->y(),
                             t_b->getVertex(2)->y()};
            double Z_b[3] = {t_b->getVertex(0)->z(), t_b->getVertex(1)->z(),
                             t_b->getVertex(2)->z()};
            int inters = intersect_line_triangle(X_b, Y_b, Z_b, P, N);
            nb_intersect += inters;
          }
        }
        ++it_b;
      }
      Msg(INFO,"Region %d Face %d, %d intersect", gr->tag(), gf->tag(), nb_intersect);
      if(nb_intersect >= 0) break; // negative value means intersection is not "robust"
    }
    
    if(nb_intersect < 0){
      setRand(rrr);
    }
    else{
      if(nb_intersect % 2 == 1){ 
        // odd nb of intersections: the normal points inside the region 
        for (unsigned int i = 0; i < gf->triangles.size(); i++){
          gf->triangles[i]->revert();
        }
      }
      ++it;
    }
  }

  // FILE *fp = fopen("debug.pos", "w");
  // fprintf(fp, "View \"debug\" {\n");
  // for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++)
  //   for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
  //     (*it)->triangles[i]->writePOS(fp, 1., (*it)->tag());
  // fprintf(fp, "};\n");
  // fclose(fp);
}

void meshGRegion::operator() (GRegion *gr) 
{  
  if(gr->geomType() == GEntity::DiscreteVolume) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if(ep && ep->mesh.ExtrudeMesh) return;

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  if(gr->meshAttributes.Method == TRANSFINI){
    MeshTransfiniteVolume(gr);
    return;
  }
  
  std::list<GFace*> faces = gr->faces();

  // sanity check
  for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
    if((*it)->quadrangles.size()){
      Msg(GERROR, "Cannot tetrahedralize volume with quadrangles on boundary");
      return;
    }
  }

  if(CTX.mesh.algo3d == ALGO_3D_TETGEN_DELAUNAY){
    delaunay.push_back(gr);
  }
  else if(CTX.mesh.algo3d == ALGO_3D_NETGEN ){
#if !defined(HAVE_NETGEN)
    Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
#else
    Msg(STATUS2, "Meshing volume %d (Netgen)", gr->tag());
    // orient the triangles of with respect to this region
    meshNormalsPointOutOfTheRegion(gr);
    std::vector<MVertex*> numberedV;
    Ng_Mesh *ngmesh = buildNetgenStructure(gr, false, numberedV);
    Ng_Meshing_Parameters mp;
    mp.maxh = 1;
    mp.fineness = 1;
    mp.secondorder = 0;
    NgAddOn_GenerateVolumeMesh(ngmesh, &mp); // does not optimize
    TransferVolumeMesh(gr, ngmesh, numberedV);
    Ng_DeleteMesh(ngmesh);
    Ng_Exit();
#endif
  }
}

void optimizeMeshGRegionNetgen::operator() (GRegion *gr) 
{  
  if(gr->geomType() == GEntity::DiscreteVolume) return;
  
  // don't optimize extruded meshes
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;
  
#if !defined(HAVE_NETGEN)
  Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
#else
  Msg(STATUS2, "Optimizing volume %d", gr->tag());
  // import mesh into netgen, including volume tets
  std::vector<MVertex*> numberedV;
  Ng_Mesh *ngmesh = buildNetgenStructure(gr, true, numberedV);
  // delete volume vertices and tets
  deMeshGRegion dem;
  dem(gr);
  // optimize mesh
  Ng_Meshing_Parameters mp;
  mp.maxh = 1;
  mp.fineness = 1;
  mp.secondorder = 0;
  NgAddOn_OptimizeVolumeMesh(ngmesh, &mp);
  TransferVolumeMesh(gr, ngmesh, numberedV);
  Ng_DeleteMesh(ngmesh);
  Ng_Exit();
#endif
}

void optimizeMeshGRegionGmsh::operator() (GRegion *gr) 
{  
  if(gr->geomType() == GEntity::DiscreteVolume) return;
  
  // don't optimize extruded meshes
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;
  
  Msg(STATUS2, "Optimizing volume %d", gr->tag());
  // import mesh into netgen, including volume tets
  
  gmshOptimizeMesh (gr, QMTET_2);  
}

bool buildFaceSearchStructure(GModel *model, fs_cont &search)
{  
  search.clear();

  GModel::fiter fit = model->firstFace();
  while(fit != model->lastFace()){    
    for(unsigned int i = 0; i < (*fit)->triangles.size(); i++){
      MVertex *p1 = (*fit)->triangles[i]->getVertex(0);
      MVertex *p2 = (*fit)->triangles[i]->getVertex(1);
      MVertex *p3 = (*fit)->triangles[i]->getVertex(2);
      MVertex *p = std::min(p1, std::min(p2, p3));
      search.insert(std::pair<MVertex*, std::pair<MTriangle*, GFace*> >
                    (p, std::pair<MTriangle*, GFace*>((*fit)->triangles[i], *fit)));
    }
    ++fit;
  }
  return true;
}

bool buildEdgeSearchStructure(GModel *model, es_cont &search)
{  
  search.clear();

  GModel::eiter eit = model->firstEdge();
  while(eit != model->lastEdge()){    
    for(unsigned int i = 0; i < (*eit)->lines.size(); i++){
      MVertex *p1 = (*eit)->lines[i]->getVertex(0);
      MVertex *p2 = (*eit)->lines[i]->getVertex(1);
      MVertex *p = std::min(p1, p2);
      search.insert(std::pair<MVertex*, std::pair<MLine*, GEdge*> > 
                    (p, std::pair<MLine*, GEdge*>((*eit)->lines[i], *eit)));
    }
    ++eit;
  }
  return true;
}

GFace *findInFaceSearchStructure(MVertex *p1, MVertex *p2, MVertex *p3, 
                                 const fs_cont &search)
{
  MVertex *p = std::min(p1, std::min(p2, p3));
  
  for(fs_cont::const_iterator it = search.lower_bound(p);
      it != search.upper_bound(p);
      ++it){
    MTriangle *t = it->second.first;
    GFace *gf= it->second.second;
    if((t->getVertex(0) == p1 || t->getVertex(0) == p2 || t->getVertex(0) == p3) &&
       (t->getVertex(1) == p1 || t->getVertex(1) == p2 || t->getVertex(1) == p3) &&
       (t->getVertex(2) == p1 || t->getVertex(2) == p2 || t->getVertex(2) == p3)) 
      return gf;
  }
  return 0;
}

GEdge *findInEdgeSearchStructure(MVertex *p1, MVertex *p2, const es_cont &search)
{
  MVertex *p = std::min(p1, p2);
  
  for(es_cont::const_iterator it = search.lower_bound(p);
      it != search.upper_bound(p);
      ++it){
    MLine *l = it->second.first;
    GEdge *ge = it->second.second;
    if ((l->getVertex(0) == p1 || l->getVertex(0) == p2) &&
        (l->getVertex(1) == p1 || l->getVertex(1) == p2)) 
      return ge;
  }
  return 0;
}

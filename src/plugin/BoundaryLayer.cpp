// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <set>
#include "GModel.h"
#include "GRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "meshGEdge.h"
#include "BoundaryLayer.h"
#include "Context.h"

#if defined(HAVE_WINSLOWUNTANGLER)
#include "winslowUntangler.h"
#endif

StringXNumber BoundaryLayerOptions_Number[] = {
  {GMSH_FULLRC, "Thickness", nullptr, 1.e-2},
  {GMSH_FULLRC, "Size", nullptr, 1.e-3},
  {GMSH_FULLRC, "Ratio", nullptr, 1.2}};

StringXString BoundaryLayerOptions_String[] = {
  {GMSH_FULLRC, "Volumes", nullptr, ""},
  {GMSH_FULLRC, "Surfaces", nullptr, ""},
  {GMSH_FULLRC, "Curves", nullptr, ""},
  {GMSH_FULLRC, "Points", nullptr, ""},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin()
{
  return new GMSH_BoundaryLayerPlugin();
}
}

std::string GMSH_BoundaryLayerPlugin::getHelp() const
{
  return "Plugin(BoundaryLayer) performs magic.";
}

int GMSH_BoundaryLayerPlugin::getNbOptions() const
{
  return sizeof(BoundaryLayerOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BoundaryLayerPlugin::getOption(int iopt)
{
  return &BoundaryLayerOptions_Number[iopt];
}

int GMSH_BoundaryLayerPlugin::getNbOptionsStr() const
{
  return sizeof(BoundaryLayerOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_BoundaryLayerPlugin::getOptionStr(int iopt)
{
  return &BoundaryLayerOptions_String[iopt];
}

#if defined(HAVE_WINSLOWUNTANGLER)

/*
    nodes at start (s) and end (e) of GEdge ge
    that does NOT belong tho the list of BL edges
    but is connected to a BL edge (vertical)

    Vertex a is inserted after s
    Vertex b is (possibly) inserted before e

    |
    |
    s--a---x(t(0))---x(t(1))--...--x(t(n-2))-----x(t(n-1))---e
*/

static double triangle_area_2d(std::array<double, 2> a, std::array<double, 2> b,
                               std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

const int _debugBL3D = 1;

static void getEmbeddedStructure (GModel *m, std::map<GVertex*,std::vector<GFace*> > & v2f,
				  std::map<GEdge*,std::vector<GFace*> > & e2f,
				  std::map<GEdge*,std::vector<GRegion*> > & e2r,
				  std::map<GFace*,std::vector<GRegion*> > & f2r){
  for (GModel::fiter fit = m->firstFace() ; fit != m->lastFace() ; ++fit){
    auto ee = (*fit)->embeddedEdges();
    for (auto ge : ee ){
      v2f[ge->getBeginVertex()].push_back(*fit);
      v2f[ge->getEndVertex()].push_back(*fit);
      e2f[ge].push_back(*fit);
    }
  }
  for (GModel::riter rit = m->firstRegion() ; rit != m->lastRegion() ; ++rit){
    auto ef = (*rit)->embeddedFaces();
    for (auto gf : ef ){
      f2r[gf].push_back(*rit);
      auto ee = (gf)->embeddedEdges();
      for (auto ge : ee ){
	if (e2f.find(ge) == e2f.end())e2r[ge].push_back(*rit);
      }
      auto e = (gf)->edges();
      for (auto ge : e ){
	if (e2f.find(ge) == e2f.end())e2r[ge].push_back(*rit);
      }
    }

  }
}

static void replaceEdges (GModel *gm ,
			  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split){
  for(GModel::eiter eit = gm->firstEdge() ; eit != gm->lastEdge() ; ++eit) {
    GEdge *ge = (*eit);
    printf("%d\n",ge->tag());
    MLine *l0 = ge->lines.front();
    MLine *l1 = ge->lines.back();
    MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
    MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
    auto it0 = split.find(m0);
    auto it1 = split.find(m1);
    
    if(it0 != split.end()) {
      printf("coucou %d %d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
      std::vector<MLine *> old = ge->lines;
      ge->lines.clear();
      for(size_t j = 0; j < it0->second.size() - 1; j++)
	ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
      for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
      delete old.front();
    }
    if(it1 != split.end()) {
      	printf("poucou %d %d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
      size_t s = it1->second.size();
      ge->lines.back()->setVertex(0, it1->second[s - 2]);
      for(size_t j = 2; j < s; j++)
	ge->lines.push_back(
			    new MLine(it1->second[s - j], it1->second[s - j - 1]));
    }
  }
}
  
  
bool bl3d(GModel *m, std::vector<GFace *> &onSurfaces,
          std::vector<GRegion *> &inVolumes, double thickness,
          std::map<MElement *, double> &layers,
	  std::vector<GFace*> &toExpand)
{
  // 3D case:
  // for each GVertex connected to the GFaces in inSurfaces:
  //   - if all adjacent GFaces to the GVertex are in inSurface, spawn 1 MVertex
  //     in each GRegion connected to the GVertex that are in inVolumes
  //   - if some adjacent GFaces are not in inSurfaces, spawn 1 MVertex in each
  //     connected GFace
  //   -
  // for each MVertex classified on a GEdge connected to the GFaces in
  // inSurfaces:
  //   -
  // for each MVertex classified on the GFaces in inSurfaces:
  //   -

  std::set<GFace *> onSurfacesSet;
  onSurfacesSet.insert(onSurfaces.begin(), onSurfaces.end());

  std::set<GRegion *> inVolumesSet;
  inVolumesSet.insert(inVolumes.begin(), inVolumes.end());

  std::map<MVertex *, std::vector<MVertex *>> spawned;

  std::set<GVertex *> connectedPoints;
  for(auto gf : onSurfaces) {
    auto vs = gf->vertices();
    connectedPoints.insert(vs.begin(), vs.end());
  }

  ///// ----> TREAT POINTS
  ///---------------------------------------------------------
  // spawn nodes for model points

  // All model points that are corners of surfaces where
  // we want to create a layer.
  // Consider a point gv
  //   --> for all curves ge attached to gv
  //       if (ge) has more that one ajacent face that wants layers

  if (_debugBL3D)printf("connected points size %zu\n",connectedPoints.size());

  for(auto gv : connectedPoints) {

    if(gv->mesh_vertices.empty()) {
      Msg::Warning("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }


    if (_debugBL3D)printf("connected point %d\n",gv->tag());

    auto connectedCurves = gv->edges();
    auto connectedSurfaces = gv->faces();
    auto connectedVolumes = gv->regions();

    std::vector<GEdge *> toinsert;

    std::size_t found = 0;

    std::set<GEdge *> curvesThatAreAdjacentToonSurfacesSet;
    for(auto gf : onSurfacesSet) {
      if (_debugBL3D)printf("onSurfacesSet %d\n",gf->tag());
      auto e = gf->edges();
      curvesThatAreAdjacentToonSurfacesSet.insert(e.begin(), e.end());
    }

    for(auto ge : connectedCurves) {
      if (_debugBL3D)printf("connectedCurve %d",ge->tag());
      if(curvesThatAreAdjacentToonSurfacesSet.find(ge) !=
         curvesThatAreAdjacentToonSurfacesSet.end()) {
	if (_debugBL3D)printf(" found\n");
        found++;
      }
      else {
        toinsert.push_back(ge);
	if (_debugBL3D)printf(" not found\n");
      }
    }

    for(auto ge : toinsert) {
      if (_debugBL3D)printf("   EDDD -- toinsert %d",ge->tag());
      MVertex *v = gv->mesh_vertices[0];
      double param;
      if(reparamMeshVertexOnEdge(v, ge, param)) {
        bool end = ge->getEndVertex() == gv;
        MVertex *newv;
        if(end) {
          MEdgeVertex *vend =
            static_cast<MEdgeVertex *>(ge->mesh_vertices.back());
          newv =
            new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vend->getLc());
          ge->mesh_vertices.push_back(newv);
        }
        else {
          MEdgeVertex *vbeg =
            static_cast<MEdgeVertex *>(ge->mesh_vertices.front());
          newv =
            new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vbeg->getLc());
          ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
        }

        spawned[v].push_back(newv);
        Msg::Debug(
          "inserted node %zu from point %d in curve %d -- %zu internal nodes",
          newv->getNum(), gv->tag(), ge->tag(), ge->mesh_vertices.size());
        if(end)
          ge->lines.push_back(new MLine(v, newv));
        else
          ge->lines.insert(ge->lines.begin(), new MLine(newv, v));
      }
      else {
        Msg::Warning("Could not compute parametric coordinates of node on "
                     "curve %d",
                     ge->tag());
      }
    }

    // We insert mesh that is classified on a model vertex on a surface

    std::vector<GFace *> toinsert2;
    for(auto gf : connectedSurfaces) {
      if (_debugBL3D)printf(" --> connectedSurface %d\n",gf->tag());
      auto ed = gf->edges();
      bool edgeAlreadyDone = false;
      for(auto ge : ed)
        if(std::find(toinsert.begin(), toinsert.end(), ge) != toinsert.end()){
	  if (_debugBL3D)printf(" x-> edgeAlreadyDone %d\n",ge->tag());
          edgeAlreadyDone = true;
	}

      if (_debugBL3D)printf(" --> edgeAlreadyDone %d\n",edgeAlreadyDone);
      if(edgeAlreadyDone || onSurfacesSet.find(gf) != onSurfacesSet.end()) {
        found++;
      }
      else {
        toinsert2.push_back(gf);
      }
    }

    if (_debugBL3D)printf(" --> toInstert2 size %zu\n",toinsert2.size());
    for(auto gf : toinsert2) {
      MVertex *v = gv->mesh_vertices[0];
      SPoint2 param;
      if(reparamMeshVertexOnFace(v, gf, param)) {
        MFaceVertex *newv =
          new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
        gf->mesh_vertices.push_back(newv);
        spawned[v].push_back(newv);
      }
    }
  }
  ///// ----> END OF TREAT POINTS
  ///---------------------------------------------------------

  ///// ----> TREAT CURVES
  ///--------------------------------------------------------- / --> Spawn nodes
  ///on model curves

  std::set<GEdge *> connectedCurves;
  for(auto gf : onSurfaces) {
    auto es = gf->edges();
    connectedCurves.insert(es.begin(), es.end());
  }
  for(auto ge : connectedCurves) {
    if (_debugBL3D)printf(" XC-> connectedCurve %d\n",ge->tag());
    auto fs = ge->faces();

    // for all faces f2ge adjacent to ge
    for(auto f2ge : fs) {
      if (_debugBL3D)printf("  XC-> face adj %d onSurfacesSet %d\n",f2ge->tag(),
			    onSurfacesSet.find(f2ge) != onSurfacesSet.end());
      // if f2ge is onSurfaces of f2ge continue
      if(onSurfacesSet.find(f2ge) != onSurfacesSet.end()) continue;
      auto vs = f2ge->regions();

      // for all volumes v adjacent to f2ge
      for(auto vol : vs) {
        if(inVolumesSet.find(vol) == inVolumesSet.end()) continue;
        auto facesOfvol = vol->faces();
	if (_debugBL3D)printf("  XC-> volume %d is a BL volume -- face belongs to it %d \n",vol->tag(),
			      std::find(facesOfvol.begin(), facesOfvol.end(), f2ge) !=
			      facesOfvol.end());
        if(std::find(facesOfvol.begin(), facesOfvol.end(), f2ge) !=
           facesOfvol.end()) {

	  if (_debugBL3D)printf("  XC-> edge %d onSurface %d\n",ge->tag(),f2ge->tag());

          for(auto ev : ge->mesh_vertices) {
            SPoint2 param;
            reparamMeshVertexOnFace(ev, f2ge, param);
            MFaceVertex *newv = new MFaceVertex(ev->x(), ev->y(), ev->z(), f2ge,
                                                param.x(), param.y());
            f2ge->mesh_vertices.push_back(newv);
            spawned[ev].push_back(newv);
          }
        }
        else {
	  if (_debugBL3D)printf(" --> edge %d in volume %d\n",ge->tag(),vol->tag());
          for(auto ev : ge->mesh_vertices) {
            MVertex *newv = new MVertex(ev->x(), ev->y(), ev->z(), vol);
            vol->mesh_vertices.push_back(newv);
            spawned[ev].push_back(newv);
          }
        }
      }
    }
  }

  for(auto gf : onSurfaces) {
    std::map<MVertex*,MVertex*> v2v;
    auto eds = gf->edges();
    auto vol = gf->regions();
    for (auto gr : vol){
      if (inVolumesSet.find(gr) == inVolumesSet.end())continue;
      for (auto v : gf->mesh_vertices){
	MVertex *newv = new MVertex (v->x(),v->y(),v->z(),gr);
	gr->mesh_vertices.push_back(newv);
	v2v[v] = newv;
	spawned[v].push_back(newv);
      }
      for (auto t : gf->triangles){
	MVertex *vs[3] = {t->getVertex(0),t->getVertex(1),t->getVertex(2)};
	MVertex *bs[3] = {nullptr,nullptr,nullptr};
	for (size_t i=0;i<3;i++){
	  std::map<MVertex*,MVertex*>::iterator it = v2v.find(vs[i]);
	  std::map<MVertex*,std::vector<MVertex*> >::iterator its = spawned.find(vs[i]);
	  if (it != v2v.end()) bs[i] = it->second;
	  else if (its != spawned.end() && its->second.size() ){
	    //	    printf("vertex %p has %d spawns\n",vs[i],its->second.size());
	    for (auto vv : its->second){
	      if (vv->onWhat() == gr){bs[i] = vv;}
	      if (vv->onWhat() == gf){bs[i] = vv;}
	      if (std::find(eds.begin(), eds.end(),vv->onWhat()) == eds.end()){bs[i] = vv; }
	    }
	  }
	  if (!bs[i]) {
	    bs[i] = new MVertex (vs[i]->x(),vs[i]->y(),vs[i]->z(),gr);
	    spawned[vs[i]].push_back(bs[i]);
	    //	    Msg::Error("no counterpart vertex for %d",vs[i]->getNum());
	  }
	}
      }
    }
  }

  for(auto gf : onSurfacesSet) {
    auto vs = gf->regions();
    for(auto vol : vs) {
      if(inVolumesSet.find(vol) != inVolumesSet.end()) {
        for(auto vv : gf->mesh_vertices) {
          MVertex *newv = new MVertex(vv->x(), vv->y(), vv->z(), vol);
          vol->mesh_vertices.push_back(newv);
          spawned[vv].push_back(newv);
	  //  printf("Spawned node %zu in volume %d from surface %d\n",
	  //                 newv->getNum(), vol->tag(), gf->tag());
        }
      }
    }
  }


  // Embedded Stuff ------------------------------------------------------------------------
  std::map<GVertex*,std::vector<GFace*> > verticesEmbeddedInFacesAsCurveEndpoints;
  std::map<GEdge*,std::vector<GFace*> > edgesEmbeddedInFaces;
  std::map<GEdge*,std::vector<GRegion*> > edgesEmbeddedInRegions;
  std::map<GFace*,std::vector<GRegion*> > facesEmbeddedInRegions;
  getEmbeddedStructure (m, verticesEmbeddedInFacesAsCurveEndpoints,edgesEmbeddedInFaces,
			edgesEmbeddedInRegions,facesEmbeddedInRegions);

  for (auto v2f : verticesEmbeddedInFacesAsCurveEndpoints){
    for (auto gf : v2f.second){
      if (_debugBL3D)printf(" --EMP  Vertex %d embedded in Face %d\n",v2f.first->tag(),gf->tag());
      MVertex *v = v2f.first->mesh_vertices[0];
      SPoint2 param;
      if(reparamMeshVertexOnFace(v, gf, param)) {
        MFaceVertex *newv =
          new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
        gf->mesh_vertices.push_back(newv);
        spawned[v].push_back(newv);
      }
    }
  }

  for (auto e2f : edgesEmbeddedInFaces){
    for (auto gf : e2f.second){
      if (_debugBL3D)printf(" --EMP  Edge %d embedded in Face %d\n",e2f.first->tag(),gf->tag());
      for (auto v : e2f.first->mesh_vertices) {
	SPoint2 param;
	if(reparamMeshVertexOnFace(v, gf, param)) {
	  for (size_t kk=0 ; kk < 2 ; kk++){
	    MFaceVertex *newv =
	      new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
	    gf->mesh_vertices.push_back(newv);
	    spawned[v].push_back(newv);
	  }
	}
      }
    }
  }

  for (auto e2r : edgesEmbeddedInRegions){
    for (auto gr : e2r.second){
      if (_debugBL3D)printf(" --EMP  Edge %d embedded in Region %d\n",e2r.first->tag(),gr->tag());
      for (auto v : e2r.first->mesh_vertices) {
	MVertex *newv = new MVertex(v->x(), v->y(), v->z(), gr);
	gr->mesh_vertices.push_back(newv);
	spawned[v].push_back(newv);
      }
    }
  }

  for (auto f2r : facesEmbeddedInRegions){
    for (auto gr : f2r.second){
      if (_debugBL3D)printf(" --EMP  Face %d embedded in Region %d\n",f2r.first->tag(),gr->tag());
      for (auto v : f2r.first->mesh_vertices) {
	for (size_t kk=0 ; kk < 2 ; kk++){
	  MVertex *newv = new MVertex(v->x(), v->y(), v->z(), gr);
	  gr->mesh_vertices.push_back(newv);
	  spawned[v].push_back(newv);
	}
      }
    }
  }

  // Embedded Stuff ------------------------------------------------------------------------

  // Create Elements

  for(auto gr : inVolumes) {
    for(std::size_t i = 0; i < gr->getNumMeshElements(); i++) {
      MElement *e = gr->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gr || v->onWhat()->dim() < 3) {
            e->setVertex(j, v);
          }
        }
      }
    }
  }

  std::set<GFace *> surfacesAdjacentToVolumesForBoundaryLayer;
  for(auto gr : inVolumes) {
    auto fs = gr->faces();
    surfacesAdjacentToVolumesForBoundaryLayer.insert(fs.begin(), fs.end());
  }

  for(auto gf : surfacesAdjacentToVolumesForBoundaryLayer) {
    if(onSurfacesSet.find(gf) != onSurfacesSet.end()) continue;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gf || v->onWhat()->dim() == 1) {
            e->setVertex(j, v);
          }
        }
      }
    }
  }

  // create zero-sized elements in connected surfaces

  std::set<GEdge *> onCurves;
  for(auto gf : onSurfaces) {
    auto es = gf->edges();
    onCurves.insert(es.begin(), es.end());
  }

  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      std::set<MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumEdges(); j++)
          edges_of_elements.insert(e->getEdge(j));
      }

      if(onSurfacesSet.find(gf) != onSurfacesSet.end()) continue;
      if(surfacesAdjacentToVolumesForBoundaryLayer.find(gf) ==
         surfacesAdjacentToVolumesForBoundaryLayer.end())
        continue;

      toExpand.push_back(gf);

      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%zu and/or %zu",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum());
        }
        else {
          std::vector<MVertex *> V0, V1;
          for(auto V : sp0)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V0.push_back(V);
            }
          for(auto V : sp1)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V1.push_back(V);
            }
          // There can be several vertices for the same face -- in case of
          // embedded edges. Assume that points are spawned on one side and then
          // on the other in the same order.
          if(V0.size() != V1.size())
            Msg::Error("Error Boundary Layer %zu %zu", V0.size(), V1.size());
          for(size_t j = 0; j < V0.size(); j++) {
            std::set<MEdge, MEdgeLessThan>::iterator it =
              edges_of_elements.find(MEdge(V1[j], V0[j]));
            if(it == edges_of_elements.end()) {
              Msg::Error("Edge not found in boundary layer");
            }
            else {
              // orientation matters !!!
              if(it->getVertex(0) == V0[j])
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(0), l->getVertex(1), V1[j], V0[j]));
              else
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(1), l->getVertex(0), V0[j], V1[j]));
              layers[gf->quadrangles.back()] = thickness;
            }
          }
        }
      }
    }
  }

  ///---------------------------------------------------------
  ///// ----> TREAT FACES -- creat prismatic layers
  ///---------------------------------------------------------

  for(auto gf : onSurfaces) {
    std::map<MVertex*,MVertex*> v2v;
    auto eds = gf->edges();
    auto vol = gf->regions();
    for (auto gr : vol){
      if (inVolumesSet.find(gr) == inVolumesSet.end())continue;
      for (auto t : gf->triangles){
	MVertex *vs[3] = {t->getVertex(0),t->getVertex(1),t->getVertex(2)};
	MVertex *bs[3] = {nullptr,nullptr,nullptr};
	for (size_t i=0;i<3;i++){
	  std::map<MVertex*,MVertex*>::iterator it = v2v.find(vs[i]);
	  std::map<MVertex*,std::vector<MVertex*> >::iterator its = spawned.find(vs[i]);
	  if (it != v2v.end()) bs[i] = it->second;
	  else if (its != spawned.end() && its->second.size() ){
	    //	    printf("vertex %p has %d spawns\n",vs[i],its->second.size());
	    for (auto vv : its->second){
	      if (vv->onWhat() == gr){bs[i] = vv;}
	      if (vv->onWhat() == gf){bs[i] = vv;}
	      if (std::find(eds.begin(), eds.end(),vv->onWhat()) == eds.end()){bs[i] = vv; }
	    }
	  }
	}
	if (bs[0] && bs[1] && bs[2]){
	  gr->prisms.push_back(new MPrism(vs[0],vs[1],vs[2],bs[0],bs[1],bs[2]));
	  layers[gr->prisms.back()] = thickness;
	}
	else{
	  Msg::Error("Impossible to create prism in BL (%d,%d) (%d,%d) (%d,%d) %p %p %p",vs[0]->onWhat()->dim(),vs[0]->onWhat()->tag(),
		     vs[1]->onWhat()->dim(),vs[1]->onWhat()->tag(),vs[2]->onWhat()->dim(),vs[2]->onWhat()->tag(),bs[0],bs[1],bs[2]);
	}
      }
    }
  }

  return true;
}

bool bl(GModel *m, std::vector<GVertex *> &onPoints,
        std::vector<GEdge *> &onCurves, std::vector<GFace *> &inSurfaces,
        double thickness, std::map<MElement *, double> &layers)
{
  // 2D case:
  // for each GVertex connected to the GEdges in onCurves:
  //   - if all adjacent GEdges to the GVertex are in onCurves, spawn 1 MVertex
  //     in each GFace connected to the GVertex that are in inSurfaces
  //   - if some adjacent GEdges are not in onCurves, spawn 1 MVertex on each
  //     connected GEdge
  // for each MVertex classified on the GEdges in onCurves:
  //   - spawn 1 MVertex in the connected GFaces that are in inSurfaces

  std::set<GEdge *> onCurvesSet;
  onCurvesSet.insert(onCurves.begin(), onCurves.end());

  std::set<GFace *> inSurfacesSet;
  inSurfacesSet.insert(inSurfaces.begin(), inSurfaces.end());

  std::map<MVertex *, std::vector<MVertex *>> spawned;

  std::set<GVertex *> connectedPoints;
  for(auto ge : onCurves) {
    auto vs = ge->vertices();
    connectedPoints.insert(vs.begin(), vs.end());
  }

  // spawn nodes for model points
  for(auto gv : connectedPoints) {
    if(gv->mesh_vertices.empty()) {
      Msg::Error("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }

    std::vector<GEdge *> connectedCurves = gv->edges();
    std::vector<GFace *> connectedSurfaces = gv->faces();
    std::vector<GEdge *> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedCurves) {
      if(onCurvesSet.find(ge) != onCurvesSet.end()) { found++; }
      else {
        toinsert.push_back(ge);
      }
    }
    // All edges adjacent to this model edge are in the boundart layer
    // thus we only add one point on the face -- the strategy here is
    // to possibly add "fans" in a second stage as another "plugin"
    if(found == connectedCurves.size()) {
      for(auto gf : connectedSurfaces) {
        if(inSurfacesSet.find(gf) != inSurfacesSet.end()) {
          MVertex *v = gv->mesh_vertices[0];
          SPoint2 param;
          if(reparamMeshVertexOnFace(v, gf, param)) {
            MVertex *newv =
              new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
            gf->mesh_vertices.push_back(newv);
            spawned[v].push_back(newv);
            Msg::Debug("inserted node %zu from point %d in surface %d",
                       newv->getNum(), gv->tag(), gf->tag());
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of node on "
                         "surface %d - maybe on seam?",
                         gf->tag());
          }
        }
      }
    }
    // insert a boundary layer node in every connected edge that is NOT
    // on the boundary layer -- this includes "slip" walls and embedded edges
    else {
      for(auto ge : toinsert) {
        MVertex *v = gv->mesh_vertices[0];
        double param;
        if(reparamMeshVertexOnEdge(v, ge, param)) {
          bool end = ge->getEndVertex() == gv;
          MVertex *newv;
          if(end) {
            MEdgeVertex *vend =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.back());
            newv =
              new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vend->getLc());
            ge->mesh_vertices.push_back(newv);
          }
          else {
            MEdgeVertex *vbeg =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.front());
            newv =
              new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vbeg->getLc());
            ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
          }

          spawned[v].push_back(newv);
          Msg::Debug(
            "inserted node %zu from point %d in curve %d -- %zu internal nodes",
            newv->getNum(), gv->tag(), ge->tag(), ge->mesh_vertices.size());
          if(end)
            ge->lines.push_back(new MLine(v, newv));
          else
            ge->lines.insert(ge->lines.begin(), new MLine(newv, v));
        }
        else {
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d",
                       ge->tag());
        }
      }
    }
  }

  // spawn nodes for model curves
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(auto v : ge->mesh_vertices) {
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv =
            new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
          gf->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
      }
    }
  }

  std::set<GEntity *> modified;
  for(auto vv : spawned)
    for(auto v : vv.second) modified.insert(v->onWhat());

  for(auto gf : inSurfaces) {
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gf || v->onWhat()->dim() == 1) {
            e->setVertex(j, v);
          }
        }
      }
    }
  }

  // create zero-sized elements in connected surfaces
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      std::set<MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumEdges(); j++)
          edges_of_elements.insert(e->getEdge(j));
      }

      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%zu and/or %zu",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum());
        }
        else {
          std::vector<MVertex *> V0, V1;
          for(auto V : sp0)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V0.push_back(V);
            }
          for(auto V : sp1)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V1.push_back(V);
            }
          // There can be several vertices for the same face -- in case of
          // embedded edges. Assume that points are spawned on one side and then
          // on the other in the same order.
          if(V0.size() != V1.size())
            Msg::Error("Error Boundary Layer %zu %zu", V0.size(), V1.size());
          for(size_t j = 0; j < V0.size(); j++) {
            std::set<MEdge, MEdgeLessThan>::iterator it =
              edges_of_elements.find(MEdge(V1[j], V0[j]));
            if(it == edges_of_elements.end()) {
              Msg::Error("Edge not found in boundary layer");
            }
            else {
              // orientation matters !!!
              if(it->getVertex(0) == V0[j])
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(0), l->getVertex(1), V1[j], V0[j]));
              else
                gf->quadrangles.push_back(new MQuadrangle(
                  l->getVertex(1), l->getVertex(0), V0[j], V1[j]));
              layers[gf->quadrangles.back()] = thickness;
            }
          }
        }
      }
    }
  }

  return true;
}


namespace {

  inline bool elementTouchesVertexSet(MElement *e,
				      std::set<MVertex *, MVertexPtrLessThan> &touched)
  {
    for(size_t j = 0; j < e->getNumVertices(); ++j)
      if(touched.find(e->getVertex(j)) != touched.end()) return true;
    return false;
  }
  
  template <class GEntityT>
  static void buildUntangleSets(
				GEntityT *ge,
				int targetDim, // 2 for faces, 3 for regions
				const std::map<MElement *, double> &layers,
				size_t nRings, // how many adjacency expansions
				std::set<MElement *, MElementPtrLessThan> &toProcess,
				std::set<MVertex *, MVertexPtrLessThan> &fixed)
  {
    std::set<MVertex *, MVertexPtrLessThan> touched;
    
    // 1) seed touched with vertices of BL elements
    for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
      MElement *e = ge->getMeshElement(i);
      if(layers.find(e) == layers.end()) continue;
      for(size_t j = 0; j < e->getNumVertices(); ++j)
	touched.insert(e->getVertex(j));
    }
    
    // 2) expand neighborhood by nRings
    for(size_t ring = 0; ring < nRings; ++ring) {
      std::set<MVertex *, MVertexPtrLessThan> newlyTouched;
      
      for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
	MElement *e = ge->getMeshElement(i);
	if(!elementTouchesVertexSet(e, touched)) continue;
	
	toProcess.insert(e);
	for(size_t j = 0; j < e->getNumVertices(); ++j)
	  newlyTouched.insert(e->getVertex(j));
      }
      
      touched.insert(newlyTouched.begin(), newlyTouched.end());
    }
    
    // 3) build fixed = vertices of elements not processed + vertices not classified on targetDim
    for(std::size_t i = 0; i < ge->getNumMeshElements(); ++i) {
      MElement *e = ge->getMeshElement(i);
      
      if(toProcess.find(e) == toProcess.end()) {
	for(size_t j = 0; j < e->getNumVertices(); ++j)
	  fixed.insert(e->getVertex(j));
      }
      
      for(size_t j = 0; j < e->getNumVertices(); ++j) {
	MVertex *v = e->getVertex(j);
	if(v->onWhat()->dim() != targetDim) fixed.insert(v);
      }
    }
  }
  
} // namespace




static void expandBL(
  GFace *gf,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes,
  std::map<MElement *, double> &layers, std::vector<GFace *> &inSurfaces)
{
  //  printf("layer size %zu\n",layers.size());
  //  std::vector<double> areas;

  constexpr size_t nRings = 3;

  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gf, /*targetDim=*/2, layers, nRings, toProcess, fixed);
  
  std::vector<std::array<std::array<double, 2>, 3>> sh;
  for(auto e : toProcess) {
    //    printf("%zu %zu\n",i,gf->getNumMeshElements());
    //    MElement *e = gf->getMeshElement(i);

    std::array<std::array<double, 2>, 4> vs;

    auto it = layers.find(e);

    if(e->getNumVertices() == 3) {
      if(it != layers.end()) {
        double T = M_PI / 6.;
        double thickness = it->second;
        //	double fact = it->second/sqrt(3.0);
        vs[0] = {0, 0.};
        vs[1] = {thickness, 0.};
        vs[2] = {thickness * cos(T), thickness * sin(T)};
        //	vs[0] = {fact, 0.};
        //	vs[1] = {fact*cos(2. * M_PI / 3.), fact*sin(2 * M_PI / 3.)};
        //	vs[2] = {fact*cos(4. * M_PI / 3.), fact*sin(4 * M_PI / 3.)};
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
      }
      sh.push_back({vs[0], vs[1], vs[2]});
    }
    else {
      if(it != layers.end()) {
        double thickness = it->second;
	//	printf("thickness = %g\n",thickness);
        /*
        (0,thickness)  (dx,thickness)
        +-------------+
        |             |
        +-------------+
        (0,0)     (dx,0)
      */
	// assume here zero size quads have been generated such as nodes 0 and 1 are
	// along the curve ... nodes 1 and 2 are at the same position, same for 0 and 3
	double dx = distance(e->getVertex(0),e->getVertex(1));

        std::array<double, 2> p0 = {0, 0};
        std::array<double, 2> p1 = {dx, 0};
        std::array<double, 2> p2 = {dx, thickness};
        std::array<double, 2> p3 = {0, thickness};

        sh.push_back({p0, p1, p2});
        sh.push_back({p2, p3, p0});
        sh.push_back({p0, p1, p3});
        sh.push_back({p1, p2, p3});
	//	printf(" %g %g %g %g %g %g\n",dx,thickness, triangle_area_2d(p0, p1, p2), triangle_area_2d(p2, p3, p0),
	//	       triangle_area_2d(p0, p1, p3),triangle_area_2d(p1, p2, p3));
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh -- perfect shapes cannot be found ...");
        sh.push_back({vs[0], vs[1], vs[2]});
        sh.push_back({vs[2], vs[3], vs[0]});
        sh.push_back({vs[0], vs[1], vs[3]});
        sh.push_back({vs[1], vs[2], vs[3]});
      }
    }
  }

  std::vector<std::array<double, 2>> points;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<bool> locked;
  std::set<MVertex *> verts;

  for(auto e : toProcess) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    if (fixed.find(v) == fixed.end())
      locked.push_back(false);
    else
      locked.push_back(true);

    SPoint2 param;
    reparamMeshVertexOnFace(v, gf, param);
    points.push_back({param.x(), param.y()});
  }
  // int tricount = 0;
  double area = 0.0;
  for(auto e : toProcess) {
    if(e->getNumVertices() == 3) {
      uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
      uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
      uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
      std::array<double, 2> pa = points[a];
      std::array<double, 2> pb = points[b];
      std::array<double, 2> pc = points[c];
      area += triangle_area_2d(pa, pb, pc);
    }
  }
  //  printf("->area(%d) = %g\n",gf->tag(),area);

  for(auto e : toProcess) {
    uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
    uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
    uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
    if(e->getNumVertices() == 3) {
      if (area > 0)triangles.push_back({a,b,c});
      else triangles.push_back({b,a,c});
    }
    else {
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      if (area > 0){
	triangles.push_back({a,b,c});
	triangles.push_back({c,d,a});
	triangles.push_back({a,b,d});
	triangles.push_back({b,c,d});
      }
      else{
	triangles.push_back({b,a,d});
	triangles.push_back({d,c,b});
	triangles.push_back({b,a,c});
	triangles.push_back({a,d,c});
      }
    }
  }
  untangle_triangles_2D(points, locked, triangles, sh, 1.e+0);

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      GPoint gp = gf->point(points[i][0], points[i][1]);
      v->x() = gp.x();
      v->y() = gp.y();
      v->z() = gp.z();
      v->setParameter(0, gp.u());
      v->setParameter(1, gp.v());
    }
  }
}

inline std::array<double,3> sub(const std::array<double,3>& x,
                                const std::array<double,3>& y)
{
    return { x[0] - y[0],
             x[1] - y[1],
             x[2] - y[2] };
}

inline double dot(const std::array<double,3>& u,
                  const std::array<double,3>& v)
{
    return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}

inline std::array<double,3> cross(const std::array<double,3>& u,
                                  const std::array<double,3>& v)
{
    return {
        u[1]*v[2] - u[2]*v[1],
        u[2]*v[0] - u[0]*v[2],
        u[0]*v[1] - u[1]*v[0]
    };
}

inline double tet_volume(const std::array<double,3>& a,
                         const std::array<double,3>& b,
                         const std::array<double,3>& c,
                         const std::array<double,3>& d)
{
    return dot(sub(a, d), cross(sub(b, d), sub(c, d))) / 6.0;
}
static void expandBL3D(
  GRegion *gr,
  std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes3D,
  std::map<MElement *, double> &layers)
{
  //  printf("layer size %zu\n",layers.size());
  //  std::vector<double> areas;

  constexpr size_t nRings = 1;
  
  std::set<MElement *, MElementPtrLessThan> toProcess;
  std::set<MVertex *, MVertexPtrLessThan> fixed;
  buildUntangleSets(gr, /*targetDim=*/3, layers, nRings, toProcess, fixed);
  
  std::vector<std::array<std::array<double, 3>, 4>> sh;
  for(auto e : toProcess) {

    std::array<std::array<double, 3>, 8> vs;

    auto it = layers.find(e);

    // TETRAHEDRA NOT IN BL !!
    if(e->getNumVertices() == 4) {
      auto it2 = perfectShapes3D.find(e);
      if(it2 != perfectShapes3D.end())
	vs = it2->second;
      else
	Msg::Error("Argh");
      sh.push_back({vs[0], vs[1], vs[2], vs[3]});
    }
    else if(e->getNumVertices() == 6) {
      if(it != layers.end()) {
	double tk = it->second;
	//	printf("tk = %12.5E\n",tk);
	SVector3 t1 = e->getVertex(1)->point()-e->getVertex(0)->point();
	SVector3 t2 = e->getVertex(2)->point()-e->getVertex(0)->point();
	SVector3 n = crossprod(t2,t1);
	n.normalize();
	vs[0] = {e->getVertex(0)->x(), e->getVertex(0)->y(),e->getVertex(0)->z()};
	vs[1] = {e->getVertex(1)->x(), e->getVertex(1)->y(),e->getVertex(1)->z()};
	vs[2] = {e->getVertex(2)->x(), e->getVertex(2)->y(),e->getVertex(2)->z()};
	vs[3] = {e->getVertex(0)->x()+n.x()*tk, e->getVertex(0)->y()+n.y()*tk,e->getVertex(0)->z()+n.z()*tk};
	vs[4] = {e->getVertex(1)->x()+n.x()*tk, e->getVertex(1)->y()+n.y()*tk,e->getVertex(1)->z()+n.z()*tk};
	vs[5] = {e->getVertex(2)->x()+n.x()*tk, e->getVertex(2)->y()+n.y()*tk,e->getVertex(2)->z()+n.z()*tk};
	int pp  [3][4] = {{0,1,2,3},{0,1,2,4},{0,1,2,5}};
	for (size_t j=0;j<3;j++)
	  sh.push_back({vs[pp[j][0]], vs[pp[j][1]], vs[pp[j][2]], vs[pp[j][3]]});
      }
    }
  }
  std::vector<std::array<double, 3>> points;
  std::vector<std::array<uint32_t, 4>> tets;
  std::vector<bool> locked;
  std::set<MVertex *> verts;

  for(auto e : toProcess) {
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }

  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    if (fixed.find(v) == fixed.end())
      locked.push_back(false);
    else
      locked.push_back(true);
    points.push_back({v->x(),v->y(),v->z()});
  }

  double volume = 0.0;
  for(auto e : toProcess) {
    if(e->getNumVertices() == 4) {
      uint32_t a = (uint32_t)e->getVertex(0)->getIndex();
      uint32_t b = (uint32_t)e->getVertex(1)->getIndex();
      uint32_t c = (uint32_t)e->getVertex(2)->getIndex();
      uint32_t d = (uint32_t)e->getVertex(3)->getIndex();
      std::array<double, 3> pa = points[a];
      std::array<double, 3> pb = points[b];
      std::array<double, 3> pc = points[c];
      std::array<double, 3> pd = points[d];
      volume  += tet_volume (pa, pb, pc, pd);
    }
  }

  printf("VOLUME = %12.5E\n'",volume);

  for(auto e : toProcess) {
    uint32_t nn[8] = {(uint32_t)e->getVertex(0)->getIndex(),
		      (uint32_t)e->getVertex(1)->getIndex(),
		      (uint32_t)e->getVertex(2)->getIndex(),
		      (uint32_t)e->getVertex(3)->getIndex(),0,0,0,0};
    if(e->getNumVertices() == 4) {
      if (volume > 0)tets.push_back({nn[0],nn[1],nn[2],nn[3]});
      else tets.push_back({nn[1],nn[0],nn[2],nn[3]});
    }
    else if (e->getNumVertices() == 6) {
      int ppi   [3][4] = {{0,1,2,3},{0,1,2,4},{0,1,2,5}};
      int pp  [3][4] = {{1,0,2,3},{1,0,2,4},{1,0,2,5}};
      nn[4] = (uint32_t)e->getVertex(4)->getIndex();
      nn[5] = (uint32_t)e->getVertex(5)->getIndex();
      if (volume > 0)for (size_t j=0;j<3;j++)tets.push_back({nn[pp[j][0]],nn[pp[j][1]],nn[pp[j][2]],nn[pp[j][3]]});
      else for (size_t j=0;j<3;j++)tets.push_back({nn[ppi[j][0]],nn[ppi[j][1]],nn[ppi[j][2]],nn[ppi[j][3]]});
    }
  }
  printf("coucou1\n");
  untangle_tetrahedra(points, locked, tets, sh, 1.e+0);
  printf("coucou2\n");

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      v->x() = points[i][0];
      v->y() = points[i][1];
      v->z() = points[i][2];
    }
  }
}


static std::vector<MVertex *>
splitedge(MEdge me,
          std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
          std::vector<double> &t)
{
  auto it = split.find(me);
  if(it != split.end()) return it->second;

  std::vector<MVertex *> vs;
  vs.push_back(me.getVertex(0));
  if(me.getVertex(1)->onWhat()->dim() == 3) {
    GRegion *gr = static_cast<GRegion *>(me.getVertex(1)->onWhat());
    SPoint3 p0 = me.getVertex(0)->point();
    SPoint3 p1 = me.getVertex(1)->point();
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint3 p = p0 + (p1 - p0) * t[i];
      vs.push_back(new MVertex(p.x(),p.y(),p.z(), gr));
      gr->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 2) {
    SPoint2 p0, p1;
    GFace *gf = static_cast<GFace *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnFace(me.getVertex(0), gf, p0);
    reparamMeshVertexOnFace(me.getVertex(1), gf, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint2 p = p0 + (p1 - p0) * t[i];
      GPoint gp = gf->point(p.x(), p.y());
      vs.push_back(new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, p.x(), p.y()));
      gf->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 1) {
    double p0, p1;
    GEdge *ge = static_cast<GEdge *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnEdge(me.getVertex(0), ge, p0);
    reparamMeshVertexOnEdge(me.getVertex(1), ge, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      double p = p0 + t[i] * (p1 - p0);
      GPoint gp = ge->point(p);
      vs.push_back(new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, p));
      ge->mesh_vertices.push_back(vs.back());
    }
  }
  vs.push_back(me.getVertex(1));
  split[me] = vs;
  return vs;
}

void splitounette3D(std::vector<GRegion *> &r,
                    std::map<MElement *, double> &layers,
                    std::vector<double> &widths)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;

  // Build normalized cumulative parameters t in (0,1)
  std::vector<double> t;
  double tot = 0.0;
  for(double w : widths) tot += w;

  double wloc = 0.0;
  for(double w : widths) {
    wloc += w;
    t.push_back(wloc / tot);
  }

  printf("splitounette3D 2\n");
  
  for(auto gr : r) {
    // Copy pointers first (like in splitounette) to avoid iterating on growing vectors
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gr->getNumMeshElements(); ++i)
      temp.push_back(gr->getMeshElement(i));

    for(size_t i = 0; i < temp.size(); ++i) {
      MElement *e = temp[i];
      auto itL = layers.find(e);
      if(itL == layers.end()) continue;

      const int nv = (int)e->getNumVertices();

      // -----------------------------
      // PRISM: (0,1,2) bottom, (3,4,5) top
      // -----------------------------
      if(nv == 6) {
        MVertex *b0 = e->getVertex(0);
        MVertex *b1 = e->getVertex(1);
        MVertex *b2 = e->getVertex(2);
        MVertex *t0 = e->getVertex(3);
        MVertex *t1 = e->getVertex(4);
        MVertex *t2 = e->getVertex(5);

	//	printf("nv = 6 %d %d %d %d %d %d\n",b0->getNum(),b1->getNum(),b2->getNum(),
	//	       t0->getNum(),t1->getNum(),t2->getNum())


        // split the 3 "vertical" edges
        std::vector<MVertex *> p0 = splitedge(MEdge(b0, t0), split, t);
        std::vector<MVertex *> p1 = splitedge(MEdge(b1, t1), split, t);
        std::vector<MVertex *> p2 = splitedge(MEdge(b2, t2), split, t);

        // p?.size() should be widths.size()+1 (if splitedge returns both endpoints)
        // We create slabs between index j and j+1
        for(size_t j = 0; j < p0.size() - 1; ++j) {
          MVertex *vb0 = p0[j];
          MVertex *vb1 = p1[j];
          MVertex *vb2 = p2[j];
          MVertex *vt0 = p0[j + 1];
          MVertex *vt1 = p1[j + 1];
          MVertex *vt2 = p2[j + 1];

          if(j == 0) {
            // reuse original element as first layer
            e->setVertex(0, vb0);
            e->setVertex(1, vb1);
            e->setVertex(2, vb2);
            e->setVertex(3, vt0);
            e->setVertex(4, vt1);
            e->setVertex(5, vt2);
            layers[e] = widths[j];
          }
          else {
            MPrism *p = new MPrism(vb0, vb1, vb2, vt0, vt1, vt2);
            gr->prisms.push_back(p);
            layers[p] = widths[j];
          }
        }
      }

      // -----------------------------
      // HEX: (0,1,2,3) bottom, (4,5,6,7) top
      // -----------------------------
      else if(nv == 8) {
        MVertex *b0 = e->getVertex(0);
        MVertex *b1 = e->getVertex(1);
        MVertex *b2 = e->getVertex(2);
        MVertex *b3 = e->getVertex(3);
        MVertex *t0 = e->getVertex(4);
        MVertex *t1 = e->getVertex(5);
        MVertex *t2 = e->getVertex(6);
        MVertex *t3 = e->getVertex(7);

        std::vector<MVertex *> p0 = splitedge(MEdge(b0, t0), split, t);
        std::vector<MVertex *> p1 = splitedge(MEdge(b1, t1), split, t);
        std::vector<MVertex *> p2 = splitedge(MEdge(b2, t2), split, t);
        std::vector<MVertex *> p3 = splitedge(MEdge(b3, t3), split, t);

        for(size_t j = 0; j < p0.size() - 1; ++j) {
          MVertex *vb0 = p0[j];
          MVertex *vb1 = p1[j];
          MVertex *vb2 = p2[j];
          MVertex *vb3 = p3[j];
          MVertex *vt0 = p0[j + 1];
          MVertex *vt1 = p1[j + 1];
          MVertex *vt2 = p2[j + 1];
          MVertex *vt3 = p3[j + 1];

          if(j == 0) {
            e->setVertex(0, vb0);
            e->setVertex(1, vb1);
            e->setVertex(2, vb2);
            e->setVertex(3, vb3);
            e->setVertex(4, vt0);
            e->setVertex(5, vt1);
            e->setVertex(6, vt2);
            e->setVertex(7, vt3);
            layers[e] = widths[j];
          }
          else {
            MHexahedron *h = new MHexahedron(vb0, vb1, vb2, vb3, vt0, vt1, vt2, vt3);
            gr->hexahedra.push_back(h);
            layers[h] = widths[j];
          }
        }
      }
    }
  }

  printf("repladceEdges\n");
  replaceEdges (r[0]->model(), split);
  printf("repladceEdges\n");
  

}


void splitounette(std::vector<GFace *> &f, std::map<MElement *, double> &layers,
                  std::vector<double> &widths)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  std::vector<double> t;
  double tot = 0.0;
  for(auto w : widths) tot += w;

  double wloc = 0.0;
  for(auto w : widths) {
    wloc += w;
    t.push_back(wloc / tot);
  }

  //  for (auto w : widths) printf("%12.5E\n",w);
  //  for (auto x : t) printf("%12.5E\n",x);

  for(auto gf : f) {
    std::vector<MElement *> temp;	
    for(size_t i = 0; i < gf->getNumMeshElements(); i++)
      temp.push_back(gf->getMeshElement(i));

    for(size_t i = 0; i < temp.size(); i++) {
      if(layers.find(temp[i]) != layers.end()) {
        if(temp[i]->getNumEdges() == 3) {
          //	  printf("FAN %d %d
          //%d\n",temp[i]->getVertex(0)->getNum(),temp[i]->getVertex(1)->getNum(),temp[i]->getVertex(2)->getNum());
          MEdge m01 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(1));
          MEdge m02 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(2));
          std::vector<MVertex *> p01 = splitedge(m01, split, t);
          std::vector<MVertex *> p02 = splitedge(m02, split, t);
          temp[i]->setVertex(1, p01[1]);
          temp[i]->setVertex(2, p02[1]);
          layers[temp[i]] = widths[0];
          for(size_t j = 1; j < p01.size() - 1; j++) {
            MVertex *v0 = p01[j];
            MVertex *v1 = p01[j + 1];
            MVertex *v2 = p02[j + 1];
            MVertex *v3 = p02[j];
            MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
            gf->quadrangles.push_back(q);
            layers[q] = widths[j];
          }
        }
        else if(temp[i]->getNumEdges() == 4) {
          MEdge m03 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(3));
          MEdge m12 = MEdge(temp[i]->getVertex(1), temp[i]->getVertex(2));
          std::vector<MVertex *> p03 = splitedge(m03, split, t);
          std::vector<MVertex *> p12 = splitedge(m12, split, t);
          for(size_t j = 0; j < p03.size() - 1; j++) {
            MVertex *v0 = p03[j];
            MVertex *v1 = p12[j];
            MVertex *v2 = p12[j + 1];
            MVertex *v3 = p03[j + 1];
            if(j == 0) {
              temp[i]->setVertex(0, v0);
              temp[i]->setVertex(1, v1);
              temp[i]->setVertex(2, v2);
              temp[i]->setVertex(3, v3);
              layers[temp[i]] = widths[j];
            }
            else {
              MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
              gf->quadrangles.push_back(q);
              layers[q] = widths[j];
            }
          }
        }
      }
    }
    auto edges = gf->edges();
    for(auto ge : edges) {
      MLine *l0 = ge->lines.front();
      MLine *l1 = ge->lines.back();
      MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
      MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
      auto it0 = split.find(m0);
      auto it1 = split.find(m1);

      if(it0 != split.end()) {
        //	printf("coucou %d
        //%d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
        std::vector<MLine *> old = ge->lines;
        ge->lines.clear();
        for(size_t j = 0; j < it0->second.size() - 1; j++)
          ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
        for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
        delete old.front();
      }
      if(it1 != split.end()) {
        //	printf("poucou %d
        //%d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
        size_t s = it1->second.size();
        ge->lines.back()->setVertex(0, it1->second[s - 2]);
        for(size_t j = 2; j < s; j++)
          ge->lines.push_back(
            new MLine(it1->second[s - j], it1->second[s - j - 1]));
      }
    }
  }
}

#endif // HAVE_WINSLOWUNTANGLER


std::string GMSH_BoundaryLayerPlugin::parse(std::string str,
                                            std::list<int> &physical)
{
  // Remove spaces
  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  // Replace commas by spaces
  replace(str.begin(), str.end(), ',', ' ');

  // Init string stream
  std::stringstream stream;
  stream << str;

  // Parse stream for integers
  int tag;
  std::string tmp;
  while(!stream.eof()) {
    stream >> tmp; // Take next 'word'
    if(sscanf(tmp.c_str(), "%d", &tag) > 0) physical.push_back(tag);
  }

  // Return modified string
  return str;
}


void computePerfectShapes (std::vector<GFace*> & f,
			   std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes){

  for(auto gf : f) {
    //      std::map<MVertex*,SPoint2> ivp;
    double area = 0.0;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
	SPoint2 param;
	reparamMeshVertexOnFace(gf->getMeshElement(i)->getVertex(j), gf,
				param);
	pts.push_back(param);
      }
      if(pts.size() == 3) {
	std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
	std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
	std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
	area += triangle_area_2d(vs0, vs1, vs2);
      }
    }

    //    printf("area (%d) = %g\n",gf->tag(), area);

    for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
      std::vector<SPoint2> pts;
      for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
	SPoint2 param;
	reparamMeshVertexOnFace(gf->getMeshElement(i)->getVertex(j), gf,
				param);
	pts.push_back(param);
      }
      std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
      std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
      std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
      if(pts.size() == 3) {
	if(area > 0)
	  perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs2};
	else
	  perfectShapes[gf->getMeshElement(i)] = {vs1, vs0, vs2, vs2};
      }
      else {
	std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
	if(area > 0)
	  perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs3};
	else
	  perfectShapes[gf->getMeshElement(i)] = {vs1, vs0, vs3, vs2};
      }
    }
  }
}


void computePerfectShapes (std::vector<GRegion*> & r,
			   std::map<MElement *, std::array<std::array<double, 3>, 8>> &perfectShapes){
  double volume = 0.0;
  for(auto gr : r) {
    //      std::map<MVertex*,SPoint2> ivp;
    for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
      std::array<std::array<double, 3>, 8> vs;
      for(size_t j = 0; j < gr->getMeshElement(i)->getNumVertices(); j++) {
	MVertex *v = gr->getMeshElement(i)->getVertex(j);
	vs[j] = {v->x(),v->y(),v->z()};
      }
      volume  += tet_volume (vs[0],vs[1],vs[2],vs[3]);
    }

    printf("colume = %12.5E\n",volume);

    for(size_t i = 0; i < gr->getNumMeshElements(); i++) {
      std::array<std::array<double, 3>, 8> vs;
      for(size_t j = 0; j < gr->getMeshElement(i)->getNumVertices(); j++) {
	MVertex *v = gr->getMeshElement(i)->getVertex(j);
	vs[j] = {v->x(),v->y(),v->z()};
      }
      if (volume > 0)
	perfectShapes[gr->getMeshElement(i)] = {vs[0],vs[1],vs[2],vs[3],vs[4],vs[5],vs[6],vs[7]};
      else
	perfectShapes[gr->getMeshElement(i)] = {vs[1],vs[0],vs[2],vs[3],vs[4],vs[5],vs[6],vs[7]};
    }
  }
}




PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
#if defined(HAVE_WINSLOWUNTANGLER)
  GModel *m = GModel::current();

  std::string volume = BoundaryLayerOptions_String[0].def;
  std::string surface = BoundaryLayerOptions_String[1].def;
  std::string curve = BoundaryLayerOptions_String[2].def;
  std::string point = BoundaryLayerOptions_String[3].def;

  std::vector<std::list<int>> entities(4);
  point = parse(point, entities[0]);
  curve = parse(curve, entities[1]);
  surface = parse(surface, entities[2]);
  volume = parse(volume, entities[3]);

  std::vector<GVertex *> vv;
  for(auto v : entities[0]) {
    GVertex *gv = m->getVertexByTag(v);
    if(gv) vv.push_back(gv);
  }
  std::vector<GEdge *> e;
  for(auto c : entities[1]) {
    GEdge *ge = m->getEdgeByTag(c);
    if(ge) e.push_back(ge);
  }
  std::vector<GFace *> f;
  for(auto s : entities[2]) {
    GFace *gf = m->getFaceByTag(s);
    if(gf) f.push_back(gf);
  }
  std::vector<GRegion *> r;
  for(auto e : entities[3]) {
    GRegion *gr = m->getRegionByTag(e);
    if(gr) r.push_back(gr);
  }

  double thickness = BoundaryLayerOptions_Number[0].def;
  double size = BoundaryLayerOptions_Number[1].def;
  double ratio = BoundaryLayerOptions_Number[2].def;

  std::map<MElement *, double> layers;

  //  printf("perfectshapes = %zu\n",perfectShapes.size());

  double ww = 0.0;
  std::vector<double> ws;
  double hwall = size;
  while(1) {
    ws.push_back(hwall);
    ww += hwall;
    if(ww + hwall >= thickness) break;
    hwall *= ratio;
  }

  //  printf("ww = %12.5E\n",ww);
  //  double h = 0.;
  //  for (auto wid  : ws){
  //    h += wid;
  //    printf("h = %g y = %g\n",wid,h);
  //  }

  std::vector<GFace*> toExpand;

  if(r.empty())
    bl(m, vv, e, f, ww*1.6, layers);
  else
    bl3d(m, f, r, ww, layers, toExpand);

  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); ++eit)
    meshGEdgeInsertBoundaryLayer(*eit, ww);

  std::map<MElement *, std::array<std::array<double, 2>, 4>> perfectShapes;
  std::map<MElement *, std::array<std::array<double, 3>, 8>> perfectShapes3D;

  if (r.empty()){
    computePerfectShapes (f,perfectShapes);
    for(auto gf : f) expandBL(gf, perfectShapes, layers, f);
  }
  else{
    computePerfectShapes (toExpand,perfectShapes);
    for(auto gf : toExpand) {
      expandBL(gf, perfectShapes, layers, toExpand);
    }
    computePerfectShapes (r,perfectShapes3D);
    for(auto gr : r) {
      expandBL3D(gr, perfectShapes3D, layers);
    }
  }

  if(r.empty()){
    if(ws.size() > 1) splitounette(f, layers, ws);
  }
  else{
    if(ws.size() > 1) splitounette3D(r, layers, ws);
  }
      
  //  for (auto gf : f)
  //    expandL(gf, perfectShapes, layers, f);

  CTX::instance()->mesh.changed = ENT_ALL;

#else
  Msg::Error("Plugin(BoundaryLayer) requires Winslow untangler");
#endif
  return v;
}

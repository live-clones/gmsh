// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <set>
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGEdge.h"
#include "BoundaryLayer.h"
#include "winslowUntangler.h"

StringXNumber BoundaryLayerOptions_Number[] = {
  {GMSH_FULLRC, "Width", nullptr, 1.e-2},
  {GMSH_FULLRC, "Hwall", nullptr, 1.e-3},
  {GMSH_FULLRC, "NbLayers", nullptr, 10}
};

StringXString BoundaryLayerOptions_String[] = {
  {GMSH_FULLRC, "Volumes", nullptr, ""},
  {GMSH_FULLRC, "Surfaces", nullptr, ""},
  {GMSH_FULLRC, "Curves", nullptr, ""},
};


extern "C" {
  GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin() {
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


static double triangle_area_2d(std::array<double, 2> a, std::array<double, 2> b, std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}



bool bl2d(GModel *m,
          std::vector<GEdge*> &onCurves,
          std::vector<GFace*> &inSurfaces,
	  double width)
{
  // for each GVertex connected to the GEdges in onCurves:
  //   - if all adjacent GEdges to the GVertex are in onCurves, spawn 1 MVertex
  //     in each GFace connected to the GVertex that are in inSurfaces
  //   - if some adjacent GEdges are not in onCurves, spawn 1 MVertex on each
  //     connected GEdge
  // for each MVertex classified the GEdges in onCurves:
  //   - spawn 1 MVertex in the connected GFaces that are in inSurfaces

  std::set<GEdge*> onCurvesSet;
  onCurvesSet.insert(onCurves.begin(), onCurves.end());

  std::set<GFace*> inSurfacesSet;
  inSurfacesSet.insert(inSurfaces.begin(), inSurfaces.end());

  std::map<MVertex*, std::vector<MVertex*>> spawned;

  std::set<GVertex*> connectedPoints;
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

    std::vector<GEdge*> connectedCurves = gv->edges();
    std::vector<GFace*> connectedSurfaces = gv->faces();
    std::vector<GEdge*> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedCurves) {
      if(onCurvesSet.find(ge) != onCurvesSet.end()) {
        found++;
      }
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
            MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                            param.x(), param.y());
            gf->mesh_vertices.push_back(newv);
            spawned[v].push_back(newv);
            printf("inserted node %lu from point %d in surface %d\n",
                   newv->getNum(), gv->tag(), gf->tag());
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of node on "
                         "surface %d - maybe on seam?", gf->tag());
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
        if(reparamMeshVertexOnEdge(v, ge, param)){
	  bool end = ge->getEndVertex() == gv;
	  MVertex *newv;
	  if (end){
	    MEdgeVertex *vend = static_cast<MEdgeVertex*> (ge->mesh_vertices.back());
	    newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param,vend->getLc());
	    ge->mesh_vertices.push_back(newv);
	  }
	  else {
	    MEdgeVertex *vbeg = static_cast<MEdgeVertex*> (ge->mesh_vertices.front());
	    newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param,vbeg->getLc());
	    ge->mesh_vertices.insert(ge->mesh_vertices.begin(),newv);
	  }
	  
          spawned[v].push_back(newv);
          printf("inserted node %lu from point %d in curve %d -- %lu internal nodes\n",
                 newv->getNum(), gv->tag(), ge->tag(),ge->mesh_vertices.size());
	  if (end)ge->lines.push_back(new MLine(v, newv));
	  else ge->lines.insert(ge->lines.begin(),new MLine(newv, v));
        }
        else{
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d", ge->tag());
        }
      }
    }
  }

  // spawn nodes for model curves
  for(auto ge : onCurves) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(auto v : ge->mesh_vertices) {
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                          param.x(), param.y());
          gf->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
      }
    }
  }

  
  std::set<GEntity*> modified;
  for(auto vv : spawned)
    for(auto v : vv.second)
      modified.insert(v->onWhat());

  // connect old elements to new spawned vertices

  //  for(auto ge : modified) {
  //    for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
  //      MElement *e = ge->getMeshElement(i);
  //      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
  //	auto sp = spawned[e->getVertex(j)];
  //	for(auto v : sp) {
  //	  if(v->onWhat() == ge) {
  //	    e->setVertex(j, v);
  //	    break;
  //	  }
  //	}
  //      }
  //    }
  //  }

  
  for (auto gf : inSurfaces) {
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
	
  /*  for(auto ge : modified) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
	MElement *e = gf->getMeshElement(i);
	for(std::size_t j = 0; j < e->getNumVertices(); j++) {
	  auto sp = spawned[e->getVertex(j)];
	  for(auto v : sp) {
	    if(v->onWhat() == ge) {
	      e->setVertex(j, v);
	      break;
	    }
	  }
        }
      }
    }
    }*/

  // create zero-sized elements in connected surfaces
  for(auto ge : onCurves) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {

      std::set <MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
	MElement *e = gf->getMeshElement(i);
	for (size_t j=0;j<e->getNumEdges();j++)
	  edges_of_elements.insert(e->getEdge(j));
      }


      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%lu and/or %lu", l->getVertex(0)->getNum(),
                       l->getVertex(1)->getNum());
        }
        else {
	  // orientation matters !!!
	  MVertex *V0,*V1;
	  for (auto V : sp0)if (V->onWhat() == gf){V0 = V ; break;}
	  for (auto V : sp1)if (V->onWhat() == gf){V1 = V ; break;}
	  std::set <MEdge, MEdgeLessThan>::iterator it = edges_of_elements.find(MEdge(V1, V0));
	  if (it == edges_of_elements.end())Msg::Error ("Edge Not Found in Boundary Layer");
	  if (it->getVertex(0) == V0)
	    gf->quadrangles.push_back(new MQuadrangle(l->getVertex(0), l->getVertex(1),
						      V1, V0));
	  else
	    gf->quadrangles.push_back(new MQuadrangle(l->getVertex(1), l->getVertex(0),
						      V0,V1));
	  // FIXME !!!
	  //          for(std::size_t j = 1; j < sp0.size(); j++)
	  //            gf->triangles.push_back(new MTriangle(l->getVertex(0),
	  //                                                  sp0[j - 1], sp0[j]));
	  //          for(std::size_t j = 1; j < sp1.size(); j++)
	  //            gf->triangles.push_back(new MTriangle(l->getVertex(1),
	  //                                                  sp1[j - 1], sp1[j]));
	}
      }
    }
  }

  std::map<GFace*, std::vector<std::array<std::array<double, 2>, 3> > > triIdealShapes;    

  std::vector<double> areas;
  
  for (auto gf : inSurfaces) {
    std::vector<std::array<std::array<double, 2>, 3> > sh;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      std::vector<std::array<double, 2> > vs;
      for (size_t j=0;j<e->getNumVertices();j++){
	SPoint2 param;
	reparamMeshVertexOnFace(e->getVertex(j),gf,param);
	vs.push_back({param.x(),param.y()});
      }
      if (e->getNumVertices() == 3){
	double a = triangle_area_2d (vs[0],vs[1],vs[2]);
	areas.push_back(a);
	if (a > 0) sh.push_back({vs[0],vs[1],vs[2]});
	else sh.push_back({vs[0],vs[2],vs[1]});
      }
      else {
	/*
          (0,width)  (dx,width)
	  +-------------+
	  |             |  
	  +-------------+
          (0,0)     (dx,0) 
	 */
	double dx = sqrt ((vs[0][0] - vs[1][0])*(vs[0][0] - vs[1][0])+
			  (vs[0][1] - vs[1][1])*(vs[0][1] - vs[1][1]));
	std::array<double, 2> p0 ={0,0};
	std::array<double, 2> p1 = {dx,0};
	std::array<double, 2> p2 ={dx,width};
	std::array<double, 2> p3 ={0,width};
	sh.push_back({p0,p1,p2});
	sh.push_back({p2,p3,p0});
	sh.push_back({p0,p1,p3});
	sh.push_back({p1,p2,p3});
      }
    }
    triIdealShapes[gf] = sh;
  }
  
  
  for (GModel::eiter eit = m->firstEdge() ; eit != m->lastEdge() ; ++eit) meshGEdgeInsertBoundaryLayer(*eit, width);

  int tricount = 0;
  for (auto gf : inSurfaces) {
    std::vector<std::array<double, 2> > points;
    std::vector<std::array<uint32_t, 3> > triangles;
    std::vector<bool> locked;
    std::set<MVertex*> verts;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for (size_t j=0;j<e->getNumVertices();j++)
	verts.insert(e->getVertex(j));
    }
    int index = 0;
    for (auto v : verts ) {
      v->setIndex(index++);
      locked.push_back(v->onWhat()->dim() == 2 ? false : true);
      SPoint2 param;
      reparamMeshVertexOnFace(v,gf,param);
      points.push_back({param.x(),param.y()});
    }
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      if (e->getNumVertices() == 3){
	if (areas[tricount] > 0)
	  triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
		(uint32_t)e->getVertex(1)->getIndex(),
		(uint32_t)e->getVertex(2)->getIndex()});
	else 
	  triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
		(uint32_t)e->getVertex(2)->getIndex(),
		(uint32_t)e->getVertex(1)->getIndex()});
	tricount++;
      }
      else {
	triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
	      (uint32_t)e->getVertex(1)->getIndex(),
	      (uint32_t)e->getVertex(2)->getIndex()});
	triangles.push_back({(uint32_t)e->getVertex(2)->getIndex(),
	      (uint32_t)e->getVertex(3)->getIndex(),
	      (uint32_t)e->getVertex(0)->getIndex()});
	triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
	      (uint32_t)e->getVertex(1)->getIndex(),
	      (uint32_t)e->getVertex(3)->getIndex()});
	triangles.push_back({(uint32_t)e->getVertex(1)->getIndex(),
	      (uint32_t)e->getVertex(2)->getIndex(),
	      (uint32_t)e->getVertex(3)->getIndex()});
      }
    }

    untangle_triangles_2D (points, locked, triangles, triIdealShapes[gf] );

    for (auto v : verts ) {
      int i = v->getIndex();
      if (!locked[i]){
	GPoint gp = gf->point (points[i][0],points[i][1]);
	v->x() = gp.x();
	v->y() = gp.y();
	v->z() = gp.z();
	v->setParameter(0,gp.u());
	v->setParameter(1,gp.v());
      }
    }

  }
}

std::string GMSH_BoundaryLayerPlugin::parse(std::string str, std::list<int> &physical)
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


PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  std::string volume = BoundaryLayerOptions_String[0].def;
  std::string surface = BoundaryLayerOptions_String[1].def;
  std::string curve = BoundaryLayerOptions_String[2].def;

  std::vector<std::list<int> > entities(3);
  curve = parse(curve, entities[0]);
  surface = parse(surface, entities[1]);
  volume = parse(volume, entities[2]);
  
  std::vector<GEdge*> e;
  for (auto c : entities[0]) {
    GEdge *ge = m->getEdgeByTag(c);
    if (ge) e.push_back(ge);
  }
  std::vector<GFace*> f;
  for (auto s : entities[1]) {
    GFace *gf = m->getFaceByTag(s);
    if (gf) f.push_back(gf);
  }

  double width = BoundaryLayerOptions_Number[0].def;
  
  bl2d(m, e, f, width);

  return v;
}

// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "GModelIO_ACIS.h"
#include "ACISVertex.h"
#include "ACISEdge.h"
#include "ACISFace.h"

#if defined(HAVE_ACIS)

#include <meshmg.hxx>
#include <acis.hxx>
#include <base.hxx>
#include <license.hxx>
#include <spa_unlock_result.hxx>
#include <spa_lic_err_gui.hxx>
#include <api.hxx>
#include <kernapi.hxx>
#include <mmgr.err>
#include <lists.hxx>
#include <acistype.hxx>
#include "acis.hxx"
#include "kernapi.hxx"
#include "boolapi.hxx"
#include "eulerapi.hxx"
#include "cstrapi.hxx"
#include "af_api.hxx"
#include "intrapi.hxx"
#include "ga_api.hxx"
#include "spl_api.hxx"

class GMSH_MESH_MANAGER : public MESH_MANAGER {
  GModel *_gm;
  GFace *_current;
 public:
  GMSH_MESH_MANAGER(GModel *gm) 
    : _gm(gm)
  {    
  }
  virtual ~GMSH_MESH_MANAGER()
  {
  }
  virtual void begin_mesh_output(ENTITY *entity, ENTITY *app_ref, ENTITY *format)
  {
    FACE *acisFace = dynamic_cast<FACE*>(entity);
    if (!acisFace)return;    
    _current = getACISFaceByNativePtr (_gm,acisFace);
  }
  virtual void announce_counts(int npoly, int nnode, int nref)
  {
    _current->stl_vertices.resize(nnode);
    _current->stl_triangles.resize(nref);
  }
  virtual logical need_indexed_polygons()
  {
    return 1;
  }
  virtual void announce_indexed_polynode(int ipoly, int i, void *pnode);
  virtual void *announce_indexed_node(int inode, const SPApar_pos &pos, 
                                      const SPAposition &X, const SPAunit_vector &N)
  {
    SPoint2 p(pos.u,pos.v); 
    _current->stl_vertices[inode] = p; 
    //    printf("node %d pos %g %g\n",inode,p.x(),p.y());
    return (void*)inode; // bad idea, but...
  }
  virtual void 	announce_indexed_polynode(ENTITY *E, int ipoly, int i, 
                                          void *id, const double &edge_tpar, 
                                          const SPApar_pos &uv, const SPAposition &iX,
                                          const SPAunit_vector &N)
  {
  }
  virtual void *announce_indexed_polyedge(int ipoly, int i, void *mate)
  {
    return 0;
  }
  virtual void	start_indexed_polygon(int polygonIndex,int _polygonNodeCount, 
                                      int ishare = -2)
  {
  }
  virtual void announce_indexed_polynode(ENTITY *,int,int,void*)
  {
  }
  virtual void end_mesh_output(ENTITY *entity,	ENTITY *app_ref,ENTITY *format)
  {
  }
  virtual void save_mesh_output(ENTITY *entity,ENTITY *app_ref,ENTITY *format)
  {
  }
};

void GMSH_MESH_MANAGER::announce_indexed_polynode (int ipoly, int i, void *pnode)
{
  _current->stl_triangles[ipoly*3+i] = (int)(long)pnode;
}

class ACIS_Internals {
public:
  ENTITY_LIST entities;
  GMSH_MESH_MANAGER *_mm;
  ACIS_Internals(GModel *gm);
  ~ACIS_Internals();
  void loadSAT(std::string fileName, GModel*);  
  void addVertices(GModel *gm, ENTITY_LIST &l);
  void addEdges(GModel *gm, ENTITY_LIST &l);
  void addFaces(GModel *gm, ENTITY_LIST &l);
};

ACIS_Internals::ACIS_Internals(GModel *gm)
{
  // put your acis unlock string here...
#include "ACISLICENSE.h"

  spa_unlock_result out = spa_unlock_products(unlock_str);
  outcome prout = api_start_modeller(0);
  if (!prout.ok()){
    Msg::Error("Unable to start ACIS");
  }

  option_header* seam_option = NULL;
 
  seam_option = find_option("periodic_no_seam");
  if (seam_option != NULL)
    seam_option->push(FALSE);

  api_initialize_booleans();
  api_initialize_euler_ops();
  api_initialize_constructors();
  api_initialize_intersectors();
  api_initialize_generic_attributes();
  api_initialize_kernel();
  api_initialize_spline();
  api_initialize_faceter();

  _mm = new GMSH_MESH_MANAGER(gm);
  api_set_mesh_manager(_mm);
  /*
  REFINEMENT *ref = new REFINEMENT;
  ref->set_surf_mode(AF_SURF_ALL);
  ref->set_normal_tol(60); // 30
  ref->set_surface_tol(0.1); // 0.05
  ref->set_grid_mode(AF_GRID_TO_EDGES);
  ref->set_triang_mode(AF_TRIANG_ALL );
  api_set_default_refinement(ref);
  */
}

ACIS_Internals::~ACIS_Internals()
{
  outcome prout = api_stop_modeller();
  if (!prout.ok()){
    Msg::Error("Unable to stop ACIS");
  }  
  delete _mm;
}

void ACIS_Internals::addVertices (GModel *gm, ENTITY_LIST &l)
{
  l.init();
  ENTITY *e;
  while((e = l.next())){
    VERTEX *av = dynamic_cast<VERTEX*>(e);
    if (av){
      GVertex *v = getACISVertexByNativePtr(gm, av);
      if (!v)
	gm->add(new ACISVertex (gm, gm->getMaxElementaryNumber(0) + 1, av));
    }
  }
}

void ACIS_Internals::addEdges (GModel *gm, ENTITY_LIST &l)
{
  l.init();
  ENTITY *e;
  while((e = l.next())){
    EDGE *av = dynamic_cast<EDGE*>(e);
    if (av){
      GEdge *v = getACISEdgeByNativePtr(gm, av);
      if (!v){
	GVertex *v1 = getACISVertexByNativePtr(gm, av->start());
	GVertex *v2 = getACISVertexByNativePtr(gm, av->end());      
	gm->add(new ACISEdge(gm, av, gm->getMaxElementaryNumber(1) + 1, v1, v2));
      }
    }
  }
}

void ACIS_Internals::addFaces (GModel *gm, ENTITY_LIST &l)
{
  l.init();
  ENTITY *e;
  while((e = l.next())){
    FACE *av = dynamic_cast<FACE*>(e);
    if (av){
      GFace *v = getACISFaceByNativePtr(gm,av);
      if (!v){
	gm->add(new ACISFace(gm, av, gm->getMaxElementaryNumber(2) + 1));
      }
    }
  }
}

void ACIS_Internals::loadSAT(std::string fileName, GModel *gm)
{
  FILE *f = fopen (fileName.c_str(), "r");
  if (!f){
    return;
  }  
  outcome prout = api_restore_entity_list(f,1,entities); 	
  if (!prout.ok()){
    Msg::Error("Unable to load ACIS FILE %d",fileName.c_str());
    return;
  }  
  Msg::Info("ACIS FILE %d Loaded",fileName.c_str());
  
  ENTITY *e;
  entities.init();
  while((e = entities.next())){
    //    printf("an entity\n");
    if (is_VERTEX(e)){
      //      printf("VERTEX FOUND\n");
    }
    if (is_BODY(e)){
      api_split_periodic_faces(e);
      {
	ENTITY_LIST vertex_list;
	outcome prout = api_get_vertices (e,vertex_list);
	addVertices (gm,vertex_list);
	printf("BODY COUNT %d !\n",vertex_list.count());
      }
      {
	ENTITY_LIST edge_list;
	outcome prout = api_get_edges (e,edge_list);
	addEdges (gm,edge_list);
	printf("BODY COUNT %d !\n",edge_list.count());
      }
      {
	ENTITY_LIST face_list;
	outcome prout = api_get_faces(e,face_list);
	addFaces (gm,face_list);
	printf("BODY COUNT %d !\n",face_list.count());
      }
    }
  }
}

int GModel::readACISSAT(const std::string &fn)
{
  _acis_internals = new ACIS_Internals(this);
  _acis_internals->loadSAT(fn,this);
  return 1;
}

#else

int GModel::readACISSAT(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with ACIS support to load '%s'",
             fn.c_str());
  return 0;
}

#endif

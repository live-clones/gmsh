#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "GModelIO_ACIS.h"
#include "ACISVertex.h"
#include "ACISEdge.h"

#if defined(HAVE_ACIS)
#define MacX 1
#define mac 1
#define ANSI 1

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


class ACIS_Internals {
public:
  ENTITY_LIST entities;
  ACIS_Internals();
  ~ACIS_Internals();
  void loadSAT ( std::string fileName, GModel*);  
  void addVertices (GModel *gm, ENTITY_LIST &l);
  void addEdges (GModel *gm, ENTITY_LIST &l);
  //  void addFaces (GModel *gm, ENTITY_LIST &l);
};

ACIS_Internals::ACIS_Internals() {
  // put your acis unlock string here ...
#include "ACISLICENSE.h"

  spa_unlock_result out = spa_unlock_products( unlock_str );

  outcome prout = api_start_modeller(0);
  if (!prout.ok()){
    Msg::Error("Unable to start ACIS");
  }
}
ACIS_Internals::~ACIS_Internals(){
  outcome prout = api_stop_modeller();
  if (!prout.ok()){
    Msg::Error("Unable to stop ACIS");
  }  
}

void ACIS_Internals :: addVertices (GModel *gm, ENTITY_LIST &l){
  l.init();
  ENTITY *e;
  while(e = l.next()){
    VERTEX *av = dynamic_cast<VERTEX*>(e);
    if (av){
      GVertex *v = getACISVertexByNativePtr(gm,av);
      if (!v)
	gm->add(new ACISVertex (gm,gm->maxVertexNum()+1,av));
    }
  }
}

void ACIS_Internals :: addEdges (GModel *gm, ENTITY_LIST &l){
  l.init();
  ENTITY *e;
  while(e = l.next()){
    EDGE *av = dynamic_cast<EDGE*>(e);
    if (av){
      GEdge *v = getACISEdgeByNativePtr(gm,av);
      if (!v){
	GVertex *v1 = getACISVertexByNativePtr(gm,av->start());
	GVertex *v2 = getACISVertexByNativePtr(gm,av->end());      
	gm->add(new ACISEdge(gm,av,gm->maxEdgeNum()+1,v1,v2));
      }
    }
  }
}
/*
void ACIS_Internals :: addFaces (GModel *gm, ENTITY_LIST &l){
  l.init();
  ENTITY *e;
  while(e = l.next()){
    FACE *av = dynamic_cast<FACE*>(e);
    if (av){
      GFace *v = getACISFaceByNativePtr(gm,av);
      if (!v){
	GVertex *v1 = getACISVertexByNativePtr(gm,av->start());
	GVertex *v2 = getACISVertexByNativePtr(gm,av->end());      
	gm->add(new ACISEdge(gm,av,gm->maxEdgeNum()+1,v1,v2));
      }
    }
  }
}
*/

void ACIS_Internals::loadSAT (std::string fileName, GModel *gm) {
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
  while(e = entities.next()){
    printf("an entity\n");
    if (is_VERTEX(e)){
      printf("VERTEX FOUND\n");
    }
    if (is_BODY(e)){
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
    }
  }
}

int GModel::readACISSAT(const std::string &fn)
{
  _acis_internals = new ACIS_Internals;
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

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshMesquite.h"

#ifdef HAVE_MESQUITE
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MVertex.h"
#include "Mesquite_all_headers.hpp"

int mesquiteImprove (GRegion *gr){
  for (auto t : gr->tetrahedra){
    t->getVertex(0)->setIndex(-1);
    t->getVertex(1)->setIndex(-1);
    t->getVertex(2)->setIndex(-1);
    t->getVertex(3)->setIndex(-1);
  }
  int current = 0;
  std::vector<double> verts;
  std::vector<size_t> tets;
  std::vector<int> fixed;
  std::vector<MVertex*> vs;
  for (auto t : gr->tetrahedra){
    for (int i=0;i<4;i++){
      if (t->getVertex(i)->getIndex() == -1){
	t->getVertex(i)->setIndex(current++);
	if (t->getVertex(i)->onWhat()->dim() != 3)
	  fixed.push_back(1);
	else
	  fixed.push_back(0);
	vs.push_back(t->getVertex(i));
	verts.push_back(t->getVertex(i)->x());
	verts.push_back(t->getVertex(i)->y());
	verts.push_back(t->getVertex(i)->z());
      }
      tets.push_back(t->getVertex(i)->getIndex());
    }
  }

  // create an ArrayMesh to pass the above mesh into Mesquite 
  MESQUITE_NS::ArrayMesh mesh (3 , verts.size()/3 , &verts[0],
			       &fixed[0], tets.size()/4, MESQUITE_NS::TETRAHEDRON, &tets[0]);
  // 
  MESQUITE_NS::MsqError err ;

  MESQUITE_NS::ShapeImprover shape_wrapper ;
  
  if (err) {
    std::cout << err << std::endl;
    return -1;
  }
  shape_wrapper.run_instructions(&mesh, err);

  MESQUITE_NS::VertexIterator *it = mesh.vertex_iterator(err);

  if (err) {
    std::cout << err << std::endl;
    return -1;
  }

  std::vector<MESQUITE_NS::Mesh::VertexHandle> vert_handles;
  mesh.get_all_vertices( vert_handles, err );     
  MESQUITE_NS::MsqVertex mesh_vertex;
  for (size_t i = 0; i <  vert_handles.size(); ++i) {
    mesh.vertices_get_coordinates(&vert_handles[i], 
				  &mesh_vertex,
				  1,
				  err);    
    vs[i]->x() = mesh_vertex.x();
    vs[i]->y() = mesh_vertex.y();
    vs[i]->z() = mesh_vertex.z();
  }

  

  return 0;

}

int mesquiteImprove (GFace *gf){
  for (auto t : gf->triangles){
    t->getVertex(0)->setIndex(-1);
    t->getVertex(1)->setIndex(-1);
    t->getVertex(2)->setIndex(-1);
  }
  int current = 0;
  std::vector<double> verts;
  std::vector<size_t> tris;
  std::vector<int> fixed;
  std::vector<MVertex*> vs;
  for (auto t : gf->triangles){
    for (int i=0;i<3;i++){
      if (t->getVertex(i)->getIndex() == -1){
	t->getVertex(i)->setIndex(current++);
	if (t->getVertex(i)->onWhat()->dim() != 2)
	  fixed.push_back(1);
	else
	  fixed.push_back(0);
	vs.push_back(t->getVertex(i));
	verts.push_back(t->getVertex(i)->x());
	verts.push_back(t->getVertex(i)->y());
	//	verts.push_back(t->getVertex(i)->z());
      }
      tris.push_back(t->getVertex(i)->getIndex());
    }
  }

  // create an ArrayMesh to pass the above mesh into Mesquite 
  MESQUITE_NS::ArrayMesh mesh (2 , verts.size()/2 , &verts[0],
			       &fixed[0], tris.size()/3, MESQUITE_NS::TRIANGLE, &tris[0]);
  // 
  MESQUITE_NS::MsqError err ;


  MESQUITE_NS::ShapeImprover shape_wrapper ;
  MESQUITE_NS::Vector3D normal(0,0,1);
  MESQUITE_NS::Vector3D point(0,0,0);
  MESQUITE_NS::PlanarDomain my_mesh_plane(normal, point);
  MESQUITE_NS::LaplaceWrapper mesh_quality_algorithm;
  MESQUITE_NS::MeshDomainAssoc mesh_and_domain(&mesh, &my_mesh_plane);
  
  
  if (err) {
    std::cout << err << std::endl;
    return -1;
  }
  mesh_quality_algorithm.run_instructions(&mesh_and_domain, err);

  if (err) {
    std::cout << err << std::endl;
    return -1;
  }

  std::vector<MESQUITE_NS::Mesh::VertexHandle> vert_handles;
  mesh.get_all_vertices( vert_handles, err );     
  MESQUITE_NS::MsqVertex mesh_vertex;
  for (size_t i = 0; i <  vert_handles.size(); ++i) {
    mesh.vertices_get_coordinates(&vert_handles[i], 
				  &mesh_vertex,
				  1,
				  err);    
    vs[i]->x() = mesh_vertex.x();
    vs[i]->y() = mesh_vertex.y();
    //    vs[i]->z() = mesh_vertex.z();
  }
 
  return 0;

}


#else
int mesquiteImprove (GRegion *gr){
  Msg::Error("Gmsh must be compiled with the UNTANGLE lib to be able to untangle a tet mesh");
  return -1;
}
int mesquiteImprove (GFace *gf){
  Msg::Error("Gmsh must be compiled with the UNTANGLE lib to be able to untangle a tet mesh");
  return -1;
}
#endif

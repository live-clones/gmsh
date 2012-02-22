// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "periodical.h"
#include "GModel.h"
#include "meshGRegion.h"
#include <fstream>
#include <algorithm>
#include "MElement.h"
#if defined(HAVE_Voro3D)
#include "voro++.hh"
#endif

#if defined(HAVE_Voro3D)
using namespace voro;
#endif

/*********class voroMetal3D*********/

voroMetal3D::voroMetal3D(){}

voroMetal3D::~voroMetal3D(){}

void voroMetal3D::execute(){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
  {
    gr = *it;
	if(gr->getNumMeshElements()>0){
	  execute(gr);
	}
  }
}

void voroMetal3D::execute(GRegion* gr){
  int i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::vector<SPoint3> vertices2;
  std::set<MVertex*> vertices;
  std::set<MVertex*>::iterator it;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  vertices.insert(vertex);
	}
  }
	
  for(it=vertices.begin();it!=vertices.end();it++){
    vertices2.push_back(SPoint3((*it)->x(),(*it)->y(),(*it)->z()));
  }
	
  execute(vertices2);	
}

void voroMetal3D::execute(std::vector<SPoint3>& vertices){
#if defined(HAVE_Voro3D)
  int i;
  int j;
  int start;
  int end;
  int index1;
  int index2;
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double delta;
  double min_x,max_x;
  double min_y,max_y;
  double min_z,max_z;
  voronoicell_neighbor* pointer;
  voronoicell_neighbor cell;
  std::vector<int> faces;
  std::vector<double> voronoi_vertices;
  std::vector<voronoicell_neighbor*> pointers;
  std::vector<SPoint3> generators;
	
  min_x = 1000000000.0;
  max_x = -1000000000.0;
  min_y = 1000000000.0;
  max_y = -1000000000.0;
  min_z = 1000000000.0;
  max_z = -1000000000.0;
  for(i=0;i<vertices.size();i++){
    min_x = std::min(vertices[i].x(),min_x);
	max_x = std::max(vertices[i].x(),max_x);
	min_y = std::min(vertices[i].y(),min_y);
	max_y = std::max(vertices[i].y(),max_y);
	min_z = std::min(vertices[i].z(),min_z);
	max_z = std::max(vertices[i].z(),max_z);
  }

  delta = 0.2*(max_x - min_x);
  container cont(min_x-delta,max_x+delta,min_y-delta,max_y+delta,min_z-delta,max_z+delta,6,6,6,true,true,true,vertices.size());
	
  for(i=0;i<vertices.size();i++){
    cont.put(i,vertices[i].x(),vertices[i].y(),vertices[i].z());
  }

  c_loop_all loop(cont);
  loop.start();
  do{
    cont.compute_cell(cell,loop);
	loop.pos(x,y,z);
	pointer = new voronoicell_neighbor();
	*pointer = cell;
	pointers.push_back(pointer);
	generators.push_back(SPoint3(x,y,z));
  }while(loop.inc());	
	
  std::ofstream file("cells.pos");
  file << "View \"test\" {\n";	
  for(i=0;i<pointers.size();i++){
	faces.clear();
	voronoi_vertices.clear();
	pointers[i]->face_vertices(faces);
	pointers[i]->vertices(generators[i].x(),generators[i].y(),generators[i].z(),voronoi_vertices);
	end = 0;
    while(end<faces.size()){
	  start = end + 1;
	  end = start + faces[end];
	  for(j=start;j<end;j++){
		if(j<end-1){
	      index1 = faces[j];
		  index2 = faces[j+1];
		}
		else{
		  index1 = faces[start];
		  index2 = faces[end-1];
		}
		x1 = voronoi_vertices[3*index1];
		y1 = voronoi_vertices[3*index1+1];
		z1 = voronoi_vertices[3*index1+2];
		x2 = voronoi_vertices[3*index2];
		y2 = voronoi_vertices[3*index2+1];
		z2 = voronoi_vertices[3*index2+2];
		print_segment(SPoint3(x1,y1,z1),SPoint3(x2,y2,z2),file);
	  }
	}
  }
  file << "};\n";
  	
  for(i=0;i<pointers.size();i++) delete pointers[i];
#else
  Msg::Error("Gmsh needs to be compiled with Voro3D to use voroMetal3D");
#endif
}

void voroMetal3D::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL (" 
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() 
  << "){10, 20};\n";	
}

// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "voro++.hh"
#include "Voronoi3D.h"
#include "GModel.h"
#include "MElement.h"
#include "meshGRegion.h"
#include <fstream>
#include "Levy3D.h"

using namespace voro;

/*********class clip*********/

clip::clip(){}

clip::~clip(){}

void clip::execute(){
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

void clip::execute(GRegion* gr){
  int i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::vector<SPoint3> vertices2;
  std::set<MVertex*> vertices;
  std::set<MVertex*>::iterator it;
  std::vector<VoronoiElement> clipped;
	
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
	
  execute(vertices2,clipped);
  printf("%d\n",clipped.size());	
	
  std::ofstream file("cells.pos");
  file << "View \"test\" {\n";
  for(i=0;i<clipped.size();i++){
    print_segment(clipped[i].get_v1().get_point(),clipped[i].get_v2().get_point(),file);
	print_segment(clipped[i].get_v1().get_point(),clipped[i].get_v3().get_point(),file);
	print_segment(clipped[i].get_v1().get_point(),clipped[i].get_v4().get_point(),file);
	print_segment(clipped[i].get_v2().get_point(),clipped[i].get_v3().get_point(),file);
	print_segment(clipped[i].get_v3().get_point(),clipped[i].get_v4().get_point(),file);
	print_segment(clipped[i].get_v4().get_point(),clipped[i].get_v2().get_point(),file);
  }
  file << "};\n";
}

void clip::execute(std::vector<SPoint3>& vertices,std::vector<VoronoiElement>& clipped){
  int i;
  int j;
  int start;
  int end;
  int index;
  int index1;
  int index2;
  int index3;
  int count;
  int pid;
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double delta;
  double min_x,max_x;
  double min_y,max_y;
  double min_z,max_z;
  double volume1;
  double volume2;
  double l1,l2,l3,l4,l5;
  voronoicell_neighbor* pointer;
  voronoicell_neighbor cell;
  VoronoiVertex v1,v2,v3,v4;
  VoronoiElement e;
  std::vector<int> faces;
  std::vector<double> voronoi_vertices;
  std::vector<voronoicell_neighbor*> pointers;
  std::vector<SPoint3> generators;
  std::vector<int> IDs;
  std::vector<int> IDs2;
  std::vector<int> neighbors;
  std::vector<std::vector<std::vector<int> > > bisectors;
	
  min_x = 1000000000.0;
  max_x = -1000000000.0;
  min_y = 1000000000.0;
  max_y = -1000000000.0;
  min_z = 1000000000.0;
  max_z = -1000000000.0;
  for(i=0;i<vertices.size();i++){
    min_x = min(vertices[i].x(),min_x);
	max_x = max(vertices[i].x(),max_x);
	min_y = min(vertices[i].y(),min_y);
	max_y = max(vertices[i].y(),max_y);
	min_z = min(vertices[i].z(),min_z);
	max_z = max(vertices[i].z(),max_z);
  }

  delta = 0.2*(max_x - min_x);
  container cont(min_x-delta,max_x+delta,min_y-delta,max_y+delta,min_z-delta,max_z+delta,6,6,6,false,false,false,vertices.size());
  volume1 = (max_x-min_x+2.0*delta)*(max_y-min_y+2.0*delta)*(max_z-min_z+2.0*delta);
	
  for(i=0;i<vertices.size();i++){
    cont.put(i,vertices[i].x(),vertices[i].y(),vertices[i].z());
  }

  count = 0;
  IDs.resize(vertices.size());
  c_loop_all loop(cont);
  loop.start();
  do{
    cont.compute_cell(cell,loop);
	loop.pos(x,y,z);
	pointer = new voronoicell_neighbor();
	*pointer = cell;
	pointers.push_back(pointer);
	generators.push_back(SPoint3(x,y,z));
	pid = loop.pid();
	IDs[pid] = count;
	IDs2.push_back(pid);
	count++;
  }while(loop.inc());	
	
  bisectors.resize(pointers.size());
  for(i=0;i<pointers.size();i++){
    faces.clear();
	voronoi_vertices.clear();
	pointers[i]->face_vertices(faces);
	pointers[i]->neighbors(neighbors);
	pointers[i]->vertices(generators[i].x(),generators[i].y(),generators[i].z(),voronoi_vertices);
	bisectors[i].resize(voronoi_vertices.size()/3);
	for(j=0;j<bisectors[i].size();j++){
	  bisectors[i][j].push_back(IDs2[i]);
	}
	count = 0;
	end = 0;
	while(end<faces.size()){
	  start = end + 1;
	  end = start + faces[end];
	  for(j=start;j<end;j++){
	    index = faces[j];
		bisectors[i][index].push_back(neighbors[count]);
	  }
	  count++;
	}
  }

  for(i=0;i<bisectors.size();i++){
    for(j=0;j<bisectors[i].size();j++){
      //printf("%d %d %d %d %d %d\n",i,IDs2[i],bisectors[i][j][0],bisectors[i][j][1],bisectors[i][j][2],bisectors[i][j][3]);
	}
  }
	
  for(i=0;i<pointers.size();i++){
	faces.clear();
	voronoi_vertices.clear();
	pointers[i]->face_vertices(faces);
	pointers[i]->vertices(generators[i].x(),generators[i].y(),generators[i].z(),voronoi_vertices);
	end = 0;
    while(end<faces.size()){
	  start = end + 1;
	  end = start + faces[end];
	  for(j=start+1;j<end-1;j++){
	    index1 = faces[start];
	    index2 = faces[j];
		index3 = faces[j+1];
		x1 = voronoi_vertices[3*index1];
		y1 = voronoi_vertices[3*index1+1];
		z1 = voronoi_vertices[3*index1+2];
		x2 = voronoi_vertices[3*index2];
		y2 = voronoi_vertices[3*index2+1];
		z2 = voronoi_vertices[3*index2+2];
		x3 = voronoi_vertices[3*index3];
		y3 = voronoi_vertices[3*index3+1];
		z3 = voronoi_vertices[3*index3+2];
		v1 = VoronoiVertex();
		v2 = VoronoiVertex();
		v3 = VoronoiVertex();
		v4 = VoronoiVertex();
		v1.set_point(SPoint3(generators[i].x(),generators[i].y(),generators[i].z()));
		v1.set_category(4);
		v1.set_index1(IDs2[i]);
		v2.set_point(SPoint3(x1,y1,z1));
		v2.set_category(category(bisectors[i][index1][0],bisectors[i][index1][1],bisectors[i][index1][2],bisectors[i][index1][3]));
		v2.set_index1(bisectors[i][index1][0]);
		v2.set_index2(bisectors[i][index1][1]);
		v2.set_index3(bisectors[i][index1][2]);
		v2.set_index4(bisectors[i][index1][3]);
		v3.set_point(SPoint3(x2,y2,z2));
		v3.set_category(category(bisectors[i][index2][0],bisectors[i][index2][1],bisectors[i][index2][2],bisectors[i][index2][3]));
		v3.set_index1(bisectors[i][index2][0]);
		v3.set_index2(bisectors[i][index2][1]);
		v3.set_index3(bisectors[i][index2][2]);
		v3.set_index4(bisectors[i][index2][3]);
		v4.set_point(SPoint3(x3,y3,z3));
		v4.set_category(category(bisectors[i][index3][0],bisectors[i][index3][1],bisectors[i][index3][2],bisectors[i][index3][3]));
		v4.set_index1(bisectors[i][index3][0]);
		v4.set_index2(bisectors[i][index3][1]);
		v4.set_index3(bisectors[i][index3][2]);
		v4.set_index4(bisectors[i][index3][3]);
		e = VoronoiElement();
		e.set_v1(v1);
		e.set_v2(v2);
		e.set_v3(v3);
		e.set_v4(v4);
		clipped.push_back(e);
	  }
	}
  }
  
  volume2 = 0.0;
  for(i=0;i<clipped.size();i++){
    if(clipped[i].get_v2().get_category()==1){
	  l1 = (clipped[i].get_v2().get_point()).distance(clipped[i].get_v1().get_point());
	  l2 = (clipped[i].get_v2().get_point()).distance(generators[IDs[clipped[i].get_v2().get_index1()]]);
	  l3 = (clipped[i].get_v2().get_point()).distance(generators[IDs[clipped[i].get_v2().get_index2()]]);
	  l4 = (clipped[i].get_v2().get_point()).distance(generators[IDs[clipped[i].get_v2().get_index3()]]);
	  l5 = (clipped[i].get_v2().get_point()).distance(generators[IDs[clipped[i].get_v2().get_index4()]]);
	  //printf("%f %f %f %f %f %f %f %f %f\n",l1,l2,l3,l4,l5,l1-l2,l1-l3,l1-l4,l1-l5);
	}
	if(clipped[i].get_v3().get_category()==1){
	  l1 = (clipped[i].get_v3().get_point()).distance(clipped[i].get_v1().get_point());
	  l2 = (clipped[i].get_v3().get_point()).distance(generators[IDs[clipped[i].get_v3().get_index1()]]);
	  l3 = (clipped[i].get_v3().get_point()).distance(generators[IDs[clipped[i].get_v3().get_index2()]]);
	  l4 = (clipped[i].get_v3().get_point()).distance(generators[IDs[clipped[i].get_v3().get_index3()]]);
	  l5 = (clipped[i].get_v3().get_point()).distance(generators[IDs[clipped[i].get_v3().get_index4()]]);
	  //printf("%f %f %f %f %f %f %f %f %f\n",l1,l2,l3,l4,l5,l1-l2,l1-l3,l1-l4,l1-l5);
	}
	if(clipped[i].get_v4().get_category()==1){
	  l1 = (clipped[i].get_v4().get_point()).distance(clipped[i].get_v1().get_point());
	  l2 = (clipped[i].get_v4().get_point()).distance(generators[IDs[clipped[i].get_v4().get_index1()]]);
	  l3 = (clipped[i].get_v4().get_point()).distance(generators[IDs[clipped[i].get_v4().get_index2()]]);
	  l4 = (clipped[i].get_v4().get_point()).distance(generators[IDs[clipped[i].get_v4().get_index3()]]);
	  l5 = (clipped[i].get_v4().get_point()).distance(generators[IDs[clipped[i].get_v4().get_index4()]]);
	  //printf("%f %f %f %f %f %f %f %f %f\n",l1,l2,l3,l4,l5,l1-l2,l1-l3,l1-l4,l1-l5);
	}
	clipped[i].compute_jacobian();
	volume2 = volume2 + fabs(clipped[i].get_jacobian())/6.0;
  }
  //printf("%f %f\n",volume1,volume2);
	
  for(i=0;i<pointers.size();i++) delete pointers[i];
}

double clip::min(double a,double b){
  if(a<b) return a;
  else return b;
}

double clip::max(double a,double b){
  if(a>b) return a;
  else return b;
}

int clip::category(int a,int b,int c,int d)
{
  int count;
  count = 0;
  if(a<0) count++;
  if(b<0) count++;
  if(c<0) count++;
  if(d<0) count++;
  if(count==0) return 1;
  else if(count==1) return 2;
  else if(count==2) return 3;
  else return 4;
}

void clip::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL (" 
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() 
  << "){10, 20};\n";	
}
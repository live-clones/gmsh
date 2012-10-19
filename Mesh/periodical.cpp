// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "periodical.h"
#include "GModel.h"
#include "meshGRegion.h"
#include <fstream>
#include <algorithm>
#include "MElement.h"
#if defined(HAVE_VORO3D)
#include "voro++.hh"
#endif

#if defined(HAVE_VORO3D)
using namespace voro;
#endif

/*********definitions*********/

class geo_cell{
 public:
  std::vector<std::pair<int,int> > lines;
  std::vector<std::vector<int> > line_loops;
  std::vector<std::vector<int> > orientations;

  std::vector<int> points2;
  std::vector<int> lines2;
  std::vector<int> line_loops2;
  std::vector<int> faces2;
  int face_loops2;

  geo_cell();
  ~geo_cell();

  int search_line(std::pair<int,int>);
};

/*********class geo_cell*********/

geo_cell::geo_cell(){}

geo_cell::~geo_cell(){}

int geo_cell::search_line(std::pair<int,int> line){
  unsigned int i;

  for(i=0;i<lines.size();i++){
    if(lines[i].first==line.first && lines[i].second==line.second) return i;
	if(lines[i].first==line.second && lines[i].second==line.first) return i;
  }

  return -1;
}

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
  unsigned int i;
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

void voroMetal3D::execute(std::vector<double>& vertices){
  unsigned int i;
  SPoint3 point;
  std::vector<SPoint3> temp;
  
  temp.clear();	
	
  for(i=0;i<vertices.size()/3;i++){
	point = SPoint3(vertices[3*i],vertices[3*i+1],vertices[3*i+2]);
    temp.push_back(point);
  }
  
  execute(temp);
}

void voroMetal3D::execute(std::vector<SPoint3>& vertices)
{
#if defined(HAVE_VORO3D)
  unsigned int i;
  unsigned int j;
  unsigned int k;
  int start;
  unsigned int end;
  int index1;
  int index2;
  int val;
  int face_number;
  int last;
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double delta;
  double min_x,max_x;
  double min_y,max_y;
  double min_z,max_z;
  double min_area;
  voronoicell_neighbor* pointer;
  voronoicell_neighbor cell;
  std::vector<int> faces;
  std::vector<double> voronoi_vertices;
  std::vector<voronoicell_neighbor*> pointers;
  std::vector<SPoint3> generators;
  std::vector<int> temp;
  std::vector<int> temp2;
  std::vector<double> areas;
  geo_cell obj;

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
  min_x=min_y=min_z = 0;
  max_x=max_y=max_z = 1;
  delta = 0;

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

  initialize_counter();

  min_area = 1000000000.0;
	
  for(i=0;i<pointers.size();i++){
    areas.clear();
	
    pointers[i]->face_areas(areas);
	  
    for(j=0;j<areas.size();j++){
	  if(areas[j]<min_area){
	    min_area = areas[j];
	  }
	}
  }
	
  printf("Squared root of smallest face area : %.9f\n",sqrt(min_area));
		
  std::ofstream file("cells.pos");
  file << "View \"test\" {\n";
  std::ofstream file2("cells.geo");
  file2 << "c = 1.0;\n";
		
  for(i=0;i<pointers.size();i++){
	obj = geo_cell();

	faces.clear();
	voronoi_vertices.clear();
	pointers[i]->face_vertices(faces);
	pointers[i]->vertices(generators[i].x(),generators[i].y(),generators[i].z(),voronoi_vertices);

	obj.line_loops.resize(pointers[i]->number_of_faces());
	obj.orientations.resize(pointers[i]->number_of_faces());

	face_number = 0;
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
		  index1 = faces[end-1];
		  index2 = faces[start];
		}
		x1 = voronoi_vertices[3*index1];
		y1 = voronoi_vertices[3*index1+1];
		z1 = voronoi_vertices[3*index1+2];
		x2 = voronoi_vertices[3*index2];
		y2 = voronoi_vertices[3*index2+1];
		z2 = voronoi_vertices[3*index2+2];
		print_segment(SPoint3(x1,y1,z1),SPoint3(x2,y2,z2),file);

		val = obj.search_line(std::pair<int,int>(index1,index2));
		if(val==-1){
		  obj.lines.push_back(std::pair<int,int>(index1,index2));
		  obj.line_loops[face_number].push_back(obj.lines.size()-1);
		  val = obj.lines.size()-1;
		}
		else{
		  obj.line_loops[face_number].push_back(val);
		}

		last = obj.line_loops[face_number].size()-1;
		if(last==0){
	      obj.orientations[face_number].push_back(0);
		}
		else if(obj.lines[obj.line_loops[face_number][last-1]].second==obj.lines[val].first){
		  obj.orientations[face_number][last-1] = 0;
		  obj.orientations[face_number].push_back(0);
		}
		else if(obj.lines[obj.line_loops[face_number][last-1]].first==obj.lines[val].first){
		  obj.orientations[face_number][last-1] = 1;
		  obj.orientations[face_number].push_back(0);
		}
		else if(obj.lines[obj.line_loops[face_number][last-1]].second==obj.lines[val].second){
		  obj.orientations[face_number][last-1] = 0;
		  obj.orientations[face_number].push_back(1);
		}
		else{
		  obj.orientations[face_number][last-1] = 1;
		  obj.orientations[face_number].push_back(1);
		}
	  }

	  face_number++;
	}

	for(j=0;j<voronoi_vertices.size()/3;j++){
	  print_geo_point(get_counter(),voronoi_vertices[3*j],voronoi_vertices[3*j+1],voronoi_vertices[3*j+2],file2);
	  obj.points2.push_back(get_counter());
	  increase_counter();
	}

	for(j=0;j<obj.lines.size();j++){
	  print_geo_line(get_counter(),obj.points2[obj.lines[j].first],obj.points2[obj.lines[j].second],file2);
	  obj.lines2.push_back(get_counter());
	  increase_counter();
	}

	for(j=0;j<obj.line_loops.size();j++){
	  temp.clear();
	  temp2.clear();
	  for(k=0;k<obj.line_loops[j].size();k++){
	    temp.push_back(obj.lines2[obj.line_loops[j][k]]);
		temp2.push_back(obj.orientations[j][k]);
	  }
	  print_geo_line_loop(get_counter(),temp,temp2,file2);
	  obj.line_loops2.push_back(get_counter());
	  increase_counter();
	}

	for(j=0;j<obj.line_loops2.size();j++){
	  print_geo_face(get_counter(),obj.line_loops2[j],file2);
	  obj.faces2.push_back(get_counter());
	  increase_counter();
	}

	print_geo_face_loop(get_counter(),obj.faces2,file2);
	obj.face_loops2 = get_counter();
	increase_counter();

	print_geo_volume(get_counter(),obj.face_loops2,file2);
	increase_counter();
  }

  file2 << "Coherence;\n";	
  file << "};\n";

  for(i=0;i<pointers.size();i++) delete pointers[i];
#endif
}

void voroMetal3D::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z()
  << "){10, 20};\n";
}

void voroMetal3D::initialize_counter(){
  counter = 1;
}

void voroMetal3D::increase_counter(){
  counter = counter+1;
}

int voroMetal3D::get_counter(){
  return counter;
}

void voroMetal3D::print_geo_point(int index,double x,double y,double z,std::ofstream& file){
  file << "Point(" << index << ")={"
  << x << "," << y << "," << z
  << ",c};\n";
}

void voroMetal3D::print_geo_line(int index1,int index2,int index3,std::ofstream& file){
  file << "Line(" << index1 << ")={"
  << index2 << "," << index3
  << "};\n";
}

void voroMetal3D::print_geo_face(int index1,int index2,std::ofstream& file){
  file << "Plane Surface(" << index1 << ")={"
  << index2
  << "};\n";
}

void voroMetal3D::print_geo_volume(int index1,int index2,std::ofstream& file){
  file << "Volume(" << index1 << ")={"
  << index2
  << "};\n";
}

void voroMetal3D::print_geo_line_loop(int index,std::vector<int>& indices,std::vector<int>& orientations,std::ofstream& file){
  unsigned int i;

  file << "Line Loop(" << index << ")={";

  for(i=0;i<indices.size();i++){
	if(orientations[i]==1) file << "-";
    file << indices[i];
	if(i<indices.size()-1) file << ",";
  }

  file << "};\n";
}

void voroMetal3D::print_geo_face_loop(int index,std::vector<int>& indices,std::ofstream& file){
  unsigned int i;

  file << "Surface Loop(" << index << ")={";

  for(i=0;i<indices.size();i++){
    file << indices[i];
	if(i<indices.size()-1) file << ",";
  }

  file << "};\n";
}

void voroMetal3D::correspondance(double e){
  unsigned int i;
  unsigned int j;
  int count;
  int count2;
  bool flag;
  double x,y,z;
  double delta_x;
  double delta_y;
  double delta_z;
  SPoint3 p1;
  SPoint3 p2;
  GFace* gf;
  GModel* model = GModel::current();
  GModel::fiter it;
  std::vector<GFace*> faces;
  std::list<GVertex*> vertices;
  std::map<GFace*,SPoint3> centers;
  std::map<GFace*,bool> markings;
  std::list<GVertex*>::iterator it2;
  std::map<GFace*,SPoint3>::iterator it3;
  std::map<GFace*,SPoint3>::iterator it4;
  std::map<GFace*,bool>::iterator it5;
  std::map<GFace*,bool>::iterator it6;
	
  faces.clear();	
	
  for(it=model->firstFace();it!=model->lastFace();it++)
  {
    gf = *it;
	if(gf->numRegions()==1){
	  faces.push_back(gf);
	}
  }
	
  centers.clear();
  markings.clear();	
	
  for(i=0;i<faces.size();i++){
	x = 0.0;
	y = 0.0;
	z = 0.0;
	
	vertices.clear();
	
	vertices = faces[i]->vertices();
	
	for(it2=vertices.begin();it2!=vertices.end();it2++){
	  x = x + (*it2)->x();
	  y = y + (*it2)->y();
	  z = z + (*it2)->z();
    }
	  
	x = x/vertices.size();
	y = y/vertices.size();
	z = z/vertices.size();
	  
	centers.insert(std::pair<GFace*,SPoint3>(faces[i],SPoint3(x,y,z)));
  }	
	
  for(i=0;i<faces.size();i++){
    markings.insert(std::pair<GFace*,bool>(faces[i],0));
  }
	
  count = 0;
  count2 = 0;
	
  std::ofstream file;
  file.open("cells.geo",std::ios::out | std::ios::app);	
  std::ofstream file2("check.pos");
  file2 << "View \"test\" {\n";	
		
  printf("Face 1 nbr. - Face 2 nbr.\n");	
	
  for(i=0;i<faces.size();i++){
    for(j=0;j<faces.size();j++){
	  flag = 0;	
	
	  it3 = centers.find(faces[i]);
	  it4 = centers.find(faces[j]);
		
	  p1 = it3->second;
	  p2 = it4->second;
		
	  delta_x = fabs(p2.x()-p1.x());
	  delta_y = fabs(p2.y()-p1.y());
	  delta_z = fabs(p2.z()-p1.z());
		
	  if(equal(delta_x,1.0,e) && equal(delta_y,0.0,e) && equal(delta_z,0.0,e)){
	    flag = 1;
	  }
	  if(equal(delta_x,0.0,e) && equal(delta_y,1.0,e) && equal(delta_z,0.0,e)){
	    flag = 1;
	  }
	  if(equal(delta_x,0.0,e) && equal(delta_y,0.0,e) && equal(delta_z,1.0,e)){
	    flag = 1;
	  }
	  
	  if(equal(delta_x,1.0,e) && equal(delta_y,1.0,e) && equal(delta_z,0.0,e)){
	    flag = 1;
	  }
	  if(equal(delta_x,0.0,e) && equal(delta_y,1.0,e) && equal(delta_z,1.0,e)){
	    flag = 1;
	  }
	  if(equal(delta_x,1.0,e) && equal(delta_y,0.0,e) && equal(delta_z,1.0,e)){
	    flag = 1;
	  }
			
	  if(equal(delta_x,1.0,e) && equal(delta_y,1.0,e) && equal(delta_z,1.0,e)){
	    flag = 1;
	  }
		
	  if(flag){
	    it5 = markings.find(faces[i]);
	    it6 = markings.find(faces[j]);
		if(it5->second==0 && it6->second==0){
		  it5->second = 1;
		  it6->second = 1;
		  
		  printf("%d %d\n",faces[i]->tag(),faces[j]->tag());
		  print_segment(p1,p2,file2);
		  //file << faces[i]->tag() << " " << faces[j]->tag() << "\n";
		  
		  count++;
		}
		else{
		  count2++;
		}
	  }
	}
  }

  file2 << "};\n";
	
  printf("Number of linked exterior faces : %d\n",2*count);
  printf("Total number of exterior faces : %zu\n",faces.size());
  printf("Number of mislinked : %d\n",count2-count);
}

bool voroMetal3D::equal(double x,double y,double e){
  bool flag;
	
  if(x>y-e && x<y+e){
    flag = 1;
  }
  else{
    flag = 0;
  }
	
  return flag;
}
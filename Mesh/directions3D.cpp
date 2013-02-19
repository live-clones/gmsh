// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include <fstream>
#include "GModel.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "MTetrahedron.h"
#include "directions3D.h"

#if defined(HAVE_PETSC)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#endif

/****************class Frame_field****************/

Frame_field::Frame_field(){}

void Frame_field::init_region(GRegion* gr){
  // Fill in the ANN tree with the bondary cross field of region gr
#if defined(HAVE_ANN)
  int index;
  MVertex* vertex;
  GFace* gf;
  std::list<GFace*> faces;
  Matrix m;

  Nearest_point::init_region(gr);	
	
  faces = gr->faces();	
	
  temp.clear();
  field.clear();

  for( std::list<GFace*>::iterator it=faces.begin();it!=faces.end();it++){
    gf = *it;
    init_face(gf);
  }

  duplicate = annAllocPts(temp.size(),3);

  index = 0;
  for(std::map<MVertex*,Matrix>::iterator it=temp.begin(); it != temp.end(); it++){
    vertex = it->first;
    m = it->second;
    duplicate[index][0] = vertex->x();
    duplicate[index][1] = vertex->y();
    duplicate[index][2] = vertex->z();
    field.push_back(std::pair<MVertex*,Matrix>(vertex,m));
    index++;
  }

  kd_tree = new ANNkd_tree(duplicate, temp.size(), 3);
#endif
}

void Frame_field::init_face(GFace* gf){
  unsigned int i;
  int j;
  bool ok;
  double average_x,average_y;
  SPoint2 point;
  SVector3 v1,v2,v3;
  MVertex* vertex;
  MElement* element;
  MElementOctree* octree;
  Matrix m;

  backgroundMesh::set(gf);
  octree = backgroundMesh::current()->get_octree();

  for(i=0;i<gf->getNumMeshElements();i++){
    element = gf->getMeshElement(i);
	  
    average_x = 0.0;
    average_y = 0.0;
	  
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      reparamMeshVertexOnFace(vertex,gf,point);
      average_x = average_x + point.x();
      average_y = average_y + point.y();
    }	
	  
    average_x = average_x/element->getNumVertices();
    average_y = average_y/element->getNumVertices();
	  
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      ok = translate(gf,octree,vertex,SPoint2(average_x,average_y),v1,v2);

      if(ok){
	v1.normalize();
	v2.normalize();
	v3 = crossprod(v1,v2);
	v3.normalize();
	m.set_m11(v1.x());
	m.set_m21(v1.y());
	m.set_m31(v1.z());
	m.set_m12(v2.x());
	m.set_m22(v2.y());
	m.set_m32(v2.z());
	m.set_m13(v3.x());
	m.set_m23(v3.y());
	m.set_m33(v3.z());
	temp.insert(std::pair<MVertex*,Matrix>(vertex,m));
      }
    }
  }
}

bool Frame_field::translate(GFace* gf,MElementOctree* octree,MVertex* vertex,SPoint2 corr,SVector3& v1,SVector3& v2){
  bool ok;
  double k;
  double size;
  double angle;
  double delta_x;
  double delta_y;
  double x,y;
  double x1,y1;
  double x2,y2;
  SPoint2 point;
  GPoint gp1;
  GPoint gp2;

  ok = true;
  k = 0.0001;
  reparamMeshVertexOnFace(vertex,gf,point);
  x = point.x();
  y = point.y();
  size = backgroundMesh::current()->operator()(x,y,0.0)*get_ratio(gf,corr);
  angle = backgroundMesh::current()->getAngle(x,y,0.0);

  delta_x = k*size*cos(angle);
  delta_y = k*size*sin(angle);

  x1 = x + delta_x;
  y1 = y + delta_y;
  x2 = x + delta_y;
  y2 = y - delta_x;

  if(!inside_domain(octree,x1,y1)){
    x1 = x - delta_x;
    y1 = y - delta_y;
    if(!inside_domain(octree,x1,y1)) ok = false;
  }
  if(!inside_domain(octree,x2,y2)){
    x2 = x - delta_y;
    y2 = y + delta_x;
    if(!inside_domain(octree,x2,y2)) ok = false;
  }

  ok = true; //?
	
  if(ok){
    gp1 = gf->point(x1,y1);
    gp2 = gf->point(x2,y2);
    v1 = SVector3(gp1.x()-vertex->x(),gp1.y()-vertex->y(),gp1.z()-vertex->z());
    v2 = SVector3(gp2.x()-vertex->x(),gp2.y()-vertex->y(),gp2.z()-vertex->z());
  }
  else{
    v1 = SVector3(1.0,0.0,0.0);
    v2 = SVector3(0.0,1.0,0.0);
  }
  return ok;
}

Matrix Frame_field::search(double x,double y,double z){
  // Determines the frame/cross at location (x,y,z)
  int index=0;
#if defined(HAVE_ANN)
  ANNpoint query;
  ANNidxArray indices;
  ANNdistArray distances;

  query = annAllocPt(3);
  query[0] = x;
  query[1] = y;
  query[2] = z;

  indices = new ANNidx[1];
  distances = new ANNdist[1];

  double e = 0.0;
  kd_tree->annkSearch(query,1,indices,distances,e);
  index = indices[0];

  annDeallocPt(query);
  delete[] indices;
  delete[] distances;
#endif
  return field[index].second;
}

Matrix Frame_field::combine(double x,double y,double z){
  // Determines the frame/cross at location (x,y,z)
  // Alternative to Frame_field::search
  bool ok;
  double val1,val2,val3;
  SVector3 vec,other;
  SVector3 vec1,vec2,vec3;
  SVector3 final1,final2;
  Matrix m,m2;
	
  m = search(x,y,z);
  m2 = m;
  ok = Nearest_point::search(x,y,z,vec);	
	
  if(ok){
    vec1 = SVector3(m.get_m11(),m.get_m21(),m.get_m31());
    vec2 = SVector3(m.get_m12(),m.get_m22(),m.get_m32());
    vec3 = SVector3(m.get_m13(),m.get_m23(),m.get_m33());
	
    val1 = fabs(dot(vec,vec1));
    val2 = fabs(dot(vec,vec2));
    val3 = fabs(dot(vec,vec3));

    if(val1<=val2 && val1<=val3){
      other = vec1;
    }
    else if(val2<=val1 && val2<=val3){
	  other = vec2;
    }
    else{
      other = vec3;
    }
	
    final1 = crossprod(vec,other);
    final1.normalize();
    final2 = crossprod(vec,final1);
	
    m2.set_m11(vec.x());
    m2.set_m21(vec.y());
    m2.set_m31(vec.z());
    m2.set_m12(final1.x());
    m2.set_m22(final1.y());
    m2.set_m32(final1.z());
    m2.set_m13(final2.x());
    m2.set_m23(final2.y());
    m2.set_m33(final2.z());
  }
	
  return m2;
}

bool Frame_field::inside_domain(MElementOctree* octree,double x,double y){
  MElement* element;
  element = (MElement*)octree->find(x,y,0.0,2,true);
  if(element!=NULL) return 1;
  else return 0;
}

double Frame_field::get_ratio(GFace* gf,SPoint2 point){
  double val;
  double uv[2];
  double tab[3];
	
  uv[0] = point.x();
  uv[1] = point.y();
  buildMetric(gf,uv,tab);
  val = 1.0/pow(tab[0]*tab[2]-tab[1]*tab[1],0.25);
  return val;
}

void Frame_field::print_segment(SPoint3 p1,SPoint3 p2,double val1, double val2, std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
       << "{" << val1 << "," << val2 << "};\n";
}

void Frame_field::print_field1(){
  // Saves a file with the surface cross field contained in Frame_field.temp
  // Frame_field.temp is constructed by Frame_field::init_region
  double k;
  SPoint3 p;
  SPoint3 p1,p2,p3,p4,p5,p6;
  MVertex* vertex;
  std::map<MVertex*,Matrix>::iterator it;
  Matrix m;

  k = 0.05;
  std::ofstream file("frame1.pos");
  file << "View \"cross field\" {\n";

  for(it=temp.begin();it!=temp.end();it++){
    vertex = it->first;
    m = it->second;

    p = SPoint3(vertex->x(),vertex->y(),vertex->z());
    p1 = SPoint3(vertex->x() + k*m.get_m11(),
		 vertex->y() + k*m.get_m21(),
		 vertex->z() + k*m.get_m31());
    p2 = SPoint3(vertex->x() - k*m.get_m11(),
		 vertex->y() - k*m.get_m21(),
		 vertex->z() - k*m.get_m31());
    p3 = SPoint3(vertex->x() + k*m.get_m12(),
		 vertex->y() + k*m.get_m22(),
		 vertex->z() + k*m.get_m32());
    p4 = SPoint3(vertex->x() - k*m.get_m12(),
		 vertex->y() - k*m.get_m22(),
		 vertex->z() - k*m.get_m32());
    p5 = SPoint3(vertex->x() + k*m.get_m13(),
		 vertex->y() + k*m.get_m23(),
		 vertex->z() + k*m.get_m33());
    p6 = SPoint3(vertex->x() - k*m.get_m13(),
		 vertex->y() - k*m.get_m23(),
		 vertex->z() - k*m.get_m33());
    double val1=10, val2=20;
    print_segment(p,p1,val1,val2,file);
    print_segment(p,p2,val1,val2,file);
    print_segment(p,p3,val1,val2,file);
    print_segment(p,p4,val1,val2,file);
    print_segment(p,p5,val1,val2,file);
    print_segment(p,p6,val1,val2,file);
  }
  file << "};\n";
}

void Frame_field::print_field2(GRegion* gr){
  // Saves a file with the cross fields inside the given GRegion, excluding the boundary.
  unsigned int i;
  int j;
  double k;
  SPoint3 p;
  SPoint3 p1,p2,p3,p4,p5,p6;
  MVertex* vertex;
  MElement* element;
  Matrix m;

  k = 0.05;
  std::ofstream file("frame2.pos");
  file << "View \"cross field\" {\n";

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      if(vertex->onWhat()->dim()>2){
	m = search(vertex->x(),vertex->y(),vertex->z());
	p = SPoint3(vertex->x(),vertex->y(),vertex->z());
	p1 = SPoint3(vertex->x() + k*m.get_m11(),
		     vertex->y() + k*m.get_m21(),
		     vertex->z() + k*m.get_m31());
	p2 = SPoint3(vertex->x() - k*m.get_m11(),
		     vertex->y() - k*m.get_m21(),
		     vertex->z() - k*m.get_m31());
	p3 = SPoint3(vertex->x() + k*m.get_m12(),
		     vertex->y() + k*m.get_m22(),
		     vertex->z() + k*m.get_m32());
	p4 = SPoint3(vertex->x() - k*m.get_m12(),
		     vertex->y() - k*m.get_m22(),
		     vertex->z() - k*m.get_m32());
	p5 = SPoint3(vertex->x() + k*m.get_m13(),
		     vertex->y() + k*m.get_m23(),
		     vertex->z() + k*m.get_m33());
	p6 = SPoint3(vertex->x() - k*m.get_m13(),
		     vertex->y() - k*m.get_m23(),
		     vertex->z() - k*m.get_m33());
	double val1=10, val2=20;
	print_segment(p,p1,val1,val2,file);
	print_segment(p,p2,val1,val2,file);
	print_segment(p,p3,val1,val2,file);
	print_segment(p,p4,val1,val2,file);
	print_segment(p,p5,val1,val2,file);
	print_segment(p,p6,val1,val2,file);
      }
    }
  }
  file << "};\n";
}

GRegion* Frame_field::test(){
  GRegion* gr;
  GModel* model = GModel::current();
  gr = *(model->firstRegion());
  return gr;
}

void Frame_field::clear(){
  Nearest_point::clear();	
  temp.clear();
  field.clear();
#if defined(HAVE_ANN)
  delete duplicate;
  delete kd_tree;
  annClose();
#endif
}

#include "cross3D.h"

CWTSSpaceVector<> convert(const SVector3 v){
  return CWTSSpaceVector<> (v.x(), v.y(), v.z());
}

SVector3 convert(const CWTSSpaceVector<> x){
  return SVector3 (x[0], x[1], x[2]);
}

ostream& operator<< (ostream &os, SVector3 &v) {
  os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return os;
}


void Frame_field::init(GRegion* gr){
  CWTSSpaceVector<> Ex(1,0,0), Ey(0,1,0), Ez(0,0,1);
  CWTSSpaceVector<> v(1,2,0), w(0,1,1.3);
  cross3D x(Ez, Ex);
  cross3D y = cross3D(v, w);

  //Recombinator crossData;
  crossData.build_vertex_to_vertices(gr);
  std::cout << "Vertices in crossData = " << crossData.vertex_to_vertices.size() << std::endl;
  for(std::map<MVertex*, std::set<MVertex*> >::const_iterator iter 
  	= crossData.vertex_to_vertices.begin(); 
      iter != crossData.vertex_to_vertices.end(); ++iter){
    MVertex* pVertex = iter->first;
    Matrix m = search(pVertex->x(), pVertex->y(), pVertex->z());
    // if(pVertex->onWhat()->dim() <= 2)
    crossField[pVertex->getNum()] = m;
  }
}

double Frame_field::findBarycenter(std::map<MVertex*, std::set<MVertex*> >::const_iterator iter, Matrix &m0){
  double theta, gradient, energy;
  Matrix m;
  CWTSSpaceVector<> axis;
  bool debug = false;

  MVertex* pVertex0 = iter->first;
  std::set<MVertex*> list = iter->second;
  cross3D x(m0);
  if(debug) std::cout << "#  " << pVertex0->getNum() 
		       << " with " << list.size() << " neighbours" << std::endl;

  SVector3 T = SVector3(0.0), dT;
  double temp = 0.;
  energy = 0;
  for (std::set<MVertex*>::const_iterator it=list.begin(); it != list.end(); ++it){
    MVertex *pVertex = *it;
    if(pVertex->getNum() == pVertex0->getNum()) 
      std::cout << "This should not happen!" << std::endl;
    std::map<int, Matrix>::const_iterator itB = crossField.find(pVertex->getNum());
    if(itB == crossField.end())
      m = search(pVertex->x(), pVertex->y(), pVertex->z());
    else
      m = itB->second;
    cross3D y(m);
    CWTSQuaternion<> Rxy = x.rotationTo(y);

    MEdge edge(pVertex0, pVertex);
    theta = eulerAngleFromQtn(Rxy);
    gradient = theta/edge.length();
    energy += gradient * gradient;
    crossDist[edge] = theta;
    if (fabs(theta) > 1e-10) {
      axis = eulerAxisFromQtn(Rxy); // undefined if theta==0
      dT = convert(axis) * (theta / edge.length() / edge.length()) ;
      T += dT;
    }
    temp += 1. / edge.length() / edge.length();
    //std::cout << "   " << pVertex->getNum() << " : " << theta << dT << std::endl;
  }
  if(list.size()) T *= 1.0/temp; // average rotation vector
  double a = T.norm();
  SVector3 b = T; b.normalize();
  if(debug) std::cout << "energy= " << energy << " T= " << a << b << std::endl;

  //std::cout << "xold=> " << x << std::endl;
  theta = T.norm();
  if(fabs(theta) > 1e-10){
    axis = convert(T);
    if(debug) std::cout << "-> " << pVertex0->getNum() << " : " << T << std::endl;
    CWTSQuaternion<> R = qtnFromEulerAxisAndAngle(axis.unit(),theta);
    x.rotate(R);
    m0 = convert(x);
  }
  //std::cout << "xnew=> " << x << std::endl << std::endl;
  return energy;
}

double Frame_field::smooth(GRegion* gr){
  // loops on crossData.vertex_to_vertices
  // 
  Matrix m, m0;
  double enew, eold;

  // Recombinator crossData;
  // crossData.build_vertex_to_vertices(gr);
  //std::cout << "NbVert=  " << crossData.vertex_to_vertices.size() << std::endl ;

  double energy = 0;
  for(std::map<MVertex*, std::set<MVertex*> >::const_iterator iter 
  	= crossData.vertex_to_vertices.begin(); 
      iter != crossData.vertex_to_vertices.end(); ++iter){

    MVertex* pVertex0 = iter->first;
    if(pVertex0->onWhat()->dim()>2){
      SVector3 T(0, 0, 0);
      std::map<int, Matrix>::iterator itA = crossField.find(iter->first->getNum());
      if(itA == crossField.end())
	m0 = search(pVertex0->x(), pVertex0->y(), pVertex0->z());
      else
	m0 = itA->second;

      m = m0;
      unsigned int NbIter = 0;
      enew = findBarycenter(iter, m); // initial energy in cell
      do{
	eold = enew;
	crossField[itA->first] = m;
	enew = findBarycenter(iter, m);
      } while ((enew < eold) && (++NbIter < 10));
      energy += eold;
    }
  }
  return energy;
}

void Frame_field::save(GRegion* gr, const std::string& filename){
  SPoint3 p, p1;
  MVertex* pVertex;
  std::map<MVertex*,Matrix>::iterator it;
  Matrix m;
  // Recombinator crossData;
  // crossData.build_vertex_to_vertices(gr);

  double k = 0.04;
  std::ofstream file(filename.c_str());
  file << "View \"cross field\" {\n";

  for(std::map<MVertex*, std::set<MVertex*> >::iterator iter = crossData.vertex_to_vertices.begin(); 
      iter != crossData.vertex_to_vertices.end(); ++iter){
    pVertex = iter->first;
    std::map<int, Matrix>::iterator itA = crossField.find(pVertex->getNum());
    if(itA == crossField.end())
      m = search(pVertex->x(), pVertex->y(), pVertex->z());
    else
      m = itA->second;

    p = SPoint3(pVertex->x(),pVertex->y(),pVertex->z());
    p1 = SPoint3(pVertex->x() + k*m.get_m11(),
		 pVertex->y() + k*m.get_m21(),
		 pVertex->z() + k*m.get_m31());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
    p1 = SPoint3(pVertex->x() - k*m.get_m11(),
		 pVertex->y() - k*m.get_m21(),
		 pVertex->z() - k*m.get_m31());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
    p1 = SPoint3(pVertex->x() + k*m.get_m12(),
		 pVertex->y() + k*m.get_m22(),
		 pVertex->z() + k*m.get_m32());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
    p1 = SPoint3(pVertex->x() - k*m.get_m12(),
		 pVertex->y() - k*m.get_m22(),
		 pVertex->z() - k*m.get_m32());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
    p1 = SPoint3(pVertex->x() + k*m.get_m13(),
		 pVertex->y() + k*m.get_m23(),
		 pVertex->z() + k*m.get_m33());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
    p1 = SPoint3(pVertex->x() - k*m.get_m13(),
		 pVertex->y() - k*m.get_m23(),
		 pVertex->z() - k*m.get_m33());
    print_segment(p,p1,pVertex->z(),pVertex->z(),file);
  }
  file << "};\n";
  file.close();
}

void Frame_field::fillTreeVolume(GRegion* gr){
#if defined(HAVE_ANN)
  int n = crossData.vertex_to_vertices.size();
  std::cout << "Filling ANN tree with " << n << " vertices" << std::endl;
  annTreeData = annAllocPts(n,3);
  int index=0;
  for(std::map<MVertex*, std::set<MVertex*> >::iterator iter = crossData.vertex_to_vertices.begin(); 
      iter != crossData.vertex_to_vertices.end(); ++iter){
    MVertex* pVertex = iter->first;
    annTreeData[index][0] = pVertex->x();
    annTreeData[index][1] = pVertex->y();
    annTreeData[index][2] = pVertex->z();
    vertIndices.push_back(pVertex->getNum());
  }
  annTree = new ANNkd_tree(annTreeData,n,3);
#endif
}

Matrix Frame_field::findNearestCross(double x,double y,double z){
#if defined(HAVE_ANN)
  ANNpoint query = annAllocPt(3);
  ANNidxArray indices = new ANNidx[1];
  ANNdistArray distances = new ANNdist[1];
  query[0] = x;
  query[1] = y;
  query[2] = z;
  double e = 0.0;
  annTree->annkSearch(query,1,indices,distances,e);
  annDeallocPt(query);
  std::map<int, Matrix>::const_iterator it = crossField.find(vertIndices[indices[0]]);
  //annTreeData[indices[0]] gives the coordinates
  delete[] indices;
  delete[] distances;
  return it->second;
#else
  return Matrix();
#endif
}

void Frame_field::save_dist(const std::string& filename){
  std::ofstream file(filename.c_str());
  file << "View \"Distance\" {\n";

  for(std::map<MEdge, double>::iterator it = crossDist.begin(); 
      it != crossDist.end(); it++){
    MVertex* pVerta = it->first.getVertex(0);
    MVertex* pVertb = it->first.getVertex(1);
    double value = it->second;
    if(it->first.length())
      value /= it->first.length();
    file << "SL ("
	 << pVerta->x() << ", " << pVerta->y() << ", " << pVerta->z() << ", "
	 << pVertb->x() << ", " << pVertb->y() << ", " << pVertb->z() << ")"
	 << "{" << value << "," << value << "};\n";
  }
  file << "};\n";
  file.close();
}

#include "PView.h"
#include "PViewDataList.h"
void Frame_field::save_energy(GRegion* gr, const std::string& filename){
  MElement* pElem;
  const int order = 1;
  const int NumNodes = 4;

  PViewDataList *data = new PViewDataList();
  for(unsigned int i = 0; i < gr->getNumMeshElements(); i++){
    pElem = gr->getMeshElement(i);
    MTetrahedron* pTet = new MTetrahedron(pElem->getVertex(0),
					  pElem->getVertex(1),
					  pElem->getVertex(2),
					  pElem->getVertex(3));
    //std::vector<double> *out = data->incrementList(1, TYPE_TET, NumNodes);
    std::vector<double> *out = data->incrementList(3, TYPE_TET, NumNodes);
    for(int j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->x());    
    for(int j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->y());    
    for(int j = 0; j < pTet->getNumVertices(); j++)
      out->push_back(pTet->getVertex(j)->z());
    for(int j = 0; j < pTet->getNumVertices(); j++){
      double u, v, w;
      pTet->getNode(j,u,v,w);
      double sf[4], gsf[4][3];
      pTet->getShapeFunctions(u, v, w, sf, order);
      pTet->getGradShapeFunctions(u, v, w, gsf, order);
      double jac[3][3], inv[3][3];
      pTet->getJacobian(u, v, w, jac);
      inv3x3(jac, inv);
      SVector3 sum(0,0,0); 
      for(int k = 0; k < pTet->getNumEdges(); k++){
	int nod1 = pTet->edges_tetra(k,0);
	int nod2 = pTet->edges_tetra(k,1);
	double grd1[3], grd2[3];
	matvec(inv, gsf[nod1], grd1);
	matvec(inv, gsf[nod2], grd2);
	SVector3 esf = sf[nod1] * SVector3(grd2) - sf[nod2] * SVector3(grd1);
	std::map<MEdge, double>::iterator it = crossDist.find(pTet->getEdge(k));
	sum += it->second * esf;
	//sum += (pTet->getVertex(nod2)->z() - pTet->getVertex(nod1)->z()) * esf;
      }
      out->push_back(sum[0]);
      out->push_back(sum[1]);
      out->push_back(sum[2]);
      //out->push_back(sum.norm());
    }
    delete pTet;
  }
  data->setName("energy");
  //data->setFileName("energ.pos");
  data->writePOS(filename + ".pos");
  data->writeMSH(filename + ".msh");
  data->finalize();
}

/****************class Size_field****************/

Size_field::Size_field(){}

void Size_field::init_region(GRegion* gr){
  size_t i;
  int j;
  double local_size;
  double average_x,average_y;
  SPoint2 point;
  MElement* element;
  MVertex* vertex;
  GFace* gf;
  GModel* model = GModel::current();
  std::list<GFace*> faces;
  std::list<GFace*>::iterator it;

  faces = gr->faces();

  boundary.clear();	

  for(it=faces.begin();it!=faces.end();it++){
    gf = *it;
    backgroundMesh::set(gf);

    for(i=0;i<gf->getNumMeshElements();i++){
      element = gf->getMeshElement(i);

      average_x = 0.0;
      average_y = 0.0;

      for(j=0;j<element->getNumVertices();j++){
        vertex = element->getVertex(j);
        reparamMeshVertexOnFace(vertex,gf,point);
        average_x = average_x + point.x();
        average_y = average_y + point.y();
      }

      average_x = average_x/element->getNumVertices();
      average_y = average_y/element->getNumVertices();

      for(j=0;j<element->getNumVertices();j++){
        vertex = element->getVertex(j);
        reparamMeshVertexOnFace(vertex,gf,point);
        local_size = backgroundMesh::current()->operator()(point.x(),point.y(),0.0);
        boundary.insert(std::pair<MVertex*,double>(vertex,local_size));
      }
    }
  }

  octree = new MElementOctree(model);
}

void Size_field::solve(GRegion* gr){
  #if defined(HAVE_PETSC)
  linearSystem<double>* system = 0;
  system = new linearSystemPETSc<double>;

  size_t i;
  int count;
  int count2;	
  double val;
  double volume;
  std::set<MVertex*> interior;
  std::set<MVertex*>::iterator it;
  std::map<MVertex*,double>::iterator it2;

  interior.clear();

  dofManager<double> assembler(system);

  count = 0;
  for(it2=boundary.begin();it2!=boundary.end();it2++){
    assembler.fixVertex(it2->first,0,1,it2->second);
    count++;
  }
  //printf("\n");
  //printf("number of boundary vertices = %d\n",count);	

  for(i=0;i<gr->tetrahedra.size();i++){
    interior.insert(gr->tetrahedra[i]->getVertex(0));
    interior.insert(gr->tetrahedra[i]->getVertex(1));
    interior.insert(gr->tetrahedra[i]->getVertex(2));
    interior.insert(gr->tetrahedra[i]->getVertex(3));
  }	

  for(it=interior.begin();it!=interior.end();it++){
    it2 = boundary.find(*it);
    if(it2==boundary.end()){
      assembler.numberVertex(*it,0,1);
    }
  }

  for(i=0;i<gr->tetrahedra.size();i++){
    gr->tetrahedra[i]->setVolumePositive();
  }

  count2 = 0;
  volume = 0.0;
  simpleFunction<double> ONE(1.0);
  laplaceTerm term(0,1,&ONE);
  for(i=0;i<gr->tetrahedra.size();i++){
    SElement se(gr->tetrahedra[i]);
    term.addToMatrix(assembler,&se);
    count2++;
    volume = volume + gr->tetrahedra[i]->getVolume();
  }
  //printf("number of tetrahedra = %d\n",count2);	
  //printf("volume = %f\n",volume);

  if (assembler.sizeOfR())
    system->systemSolve();

  for(it=interior.begin();it!=interior.end();it++){
    assembler.getDofValue(*it,0,1,val);
    boundary.insert(std::pair<MVertex*,double>(*it,val));
  }

  delete system;
  #endif	
}

double Size_field::search(double x,double y,double z){
  double u,v,w;
  double val;
  MElement* element;
  double temp1[3];
  double temp2[3];
  std::map<MVertex*,double>::iterator it1;
  std::map<MVertex*,double>::iterator it2;
  std::map<MVertex*,double>::iterator it3;
  std::map<MVertex*,double>::iterator it4;
	
  val = 1.0;	
	
  element = (MElement*)octree->find(x,y,z,3,true);
	
  if(element!=NULL){
    temp1[0] = x;
    temp1[1] = y;
    temp1[2] = z;

    element->xyz2uvw(temp1,temp2);

    u = temp2[0];
    v = temp2[1];
    w = temp2[2];

    it1 = boundary.find(element->getVertex(0)); 
    it2 = boundary.find(element->getVertex(1));
    it3 = boundary.find(element->getVertex(2));
    it4 = boundary.find(element->getVertex(3));

    if(it1!=boundary.end() && it2!=boundary.end() && it3!=boundary.end() && it4!=boundary.end()){
      val = (it1->second)*(1.0-u-v-w) + (it2->second)*u + (it3->second)*v + (it4->second)*w;
    }
  }

  return val;
}

double Size_field::get_ratio(GFace* gf,SPoint2 point){
  double val;
  double uv[2];
  double tab[3];

  uv[0] = point.x();
  uv[1] = point.y();
  buildMetric(gf,uv,tab);
  val = 1.0/pow(tab[0]*tab[2]-tab[1]*tab[1],0.25);
  return val;
}

void Size_field::print_field(GRegion* gr){
  size_t i;
  double min,max;
  //double x,y,z;
  double x1,y1,z1,h1;
  double x2,y2,z2,h2;
  double x3,y3,z3,h3;
  double x4,y4,z4,h4;
  std::map<MVertex*,double>::iterator it;
  std::map<MVertex*,double>::iterator it1;
  std::map<MVertex*,double>::iterator it2;
  std::map<MVertex*,double>::iterator it3;
  std::map<MVertex*,double>::iterator it4;

  min = 1000000000.0;
  max = -1000000000.0;

  for(it=boundary.begin();it!=boundary.end();it++){
    //x = (it->first)->x();
    //y = (it->first)->y();
    //z = (it->first)->z();

    if(it->second>max){
      max = it->second;
    }

    if(it->second<min){
      min = it->second;
    }

    //printf("x = %f, y = %f, z = %f, mesh size = %f\n",x,y,z,it->second);
  }

  //printf("\n");	

  printf("min mesh size = %f\n",min);
  printf("max mesh size = %f\n",max);	

  printf("total number of vertices = %zu\n",boundary.size());
  printf("\n");	

  std::ofstream file("laplace.pos");
  file << "View \"test\" {\n";	

  for(i=0;i<gr->tetrahedra.size();i++){
    x1 = gr->tetrahedra[i]->getVertex(0)->x();
    y1 = gr->tetrahedra[i]->getVertex(0)->y();
    z1 = gr->tetrahedra[i]->getVertex(0)->z();
    it1 = boundary.find(gr->tetrahedra[i]->getVertex(0));

    x2 = gr->tetrahedra[i]->getVertex(1)->x();
    y2 = gr->tetrahedra[i]->getVertex(1)->y();
    z2 = gr->tetrahedra[i]->getVertex(1)->z();
    it2 = boundary.find(gr->tetrahedra[i]->getVertex(1));

    x3 = gr->tetrahedra[i]->getVertex(2)->x();
    y3 = gr->tetrahedra[i]->getVertex(2)->y();
    z3 = gr->tetrahedra[i]->getVertex(2)->z();
    it3 = boundary.find(gr->tetrahedra[i]->getVertex(2));

    x4 = gr->tetrahedra[i]->getVertex(3)->x();
    y4 = gr->tetrahedra[i]->getVertex(3)->y();
    z4 = gr->tetrahedra[i]->getVertex(3)->z();
    it4 = boundary.find(gr->tetrahedra[i]->getVertex(3));

    if(it1!=boundary.end() && it2!=boundary.end() && it3!=boundary.end() && it4!=boundary.end()){
      h1 = it1->second;
      h2 = it2->second;
      h3 = it3->second;
      h4 = it4->second;

      file << "SS ("
      << x1 << ", " << y1 << ", " << z1 << ", " 
      << x2 << ", " << y2 << ", " << z2 << ", "
      << x3 << ", " << y3 << ", " << z3 << ", "
      << x4 << ", " << y4 << ", " << z4 << "){"
      << h1 << ", " << h2 << ", " << h3 << ", "
      << h4 << "};\n";
    }
  }

  file << "};\n";
}

GRegion* Size_field::test(){
  GRegion* gr;
  GModel* model = GModel::current();

  gr = *(model->firstRegion());

  return gr;
}

void Size_field::clear(){
  delete octree;
  boundary.clear();
}

/****************class Nearest_point****************/

Nearest_point::Nearest_point(){}

void Nearest_point::init_region(GRegion* gr){
#if defined(HAVE_ANN)
  unsigned int i;
  int j;
  int gauss_num;
  double u,v;
  double x,y,z;
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::set<MVertex*> temp;
  std::list<GFace*>::iterator it;
  std::set<MVertex*>::iterator it2;
  fullMatrix<double> gauss_points;
  fullVector<double> gauss_weights;
	
  gaussIntegration::getTriangle(8,gauss_points,gauss_weights);
  gauss_num = gauss_points.size1();	
	
  faces = gr->faces();
	
  field.clear();
  vicinity.clear();
  temp.clear();
	
  for(it=faces.begin();it!=faces.end();it++){
    gf = *it;
	for(i=0;i<gf->getNumMeshElements();i++){
	  element = gf->getMeshElement(i);
		
	  x1 = element->getVertex(0)->x();
	  y1 = element->getVertex(0)->y();
	  z1 = element->getVertex(0)->z();
		
	  x2 = element->getVertex(1)->x();
	  y2 = element->getVertex(1)->y();
	  z2 = element->getVertex(1)->z();
		
	  x3 = element->getVertex(2)->x();
	  y3 = element->getVertex(2)->y();
	  z3 = element->getVertex(2)->z();
		
	  for(j=0;j<gauss_num;j++){
		u = gauss_points(j,0);
		v = gauss_points(j,1);
	    
		x = T(u,v,x1,x2,x3);
		y = T(u,v,y1,y2,y3);
		z = T(u,v,z1,z2,z3);
		
		field.push_back(SPoint3(x,y,z));
		vicinity.push_back(element);
	  }
		
	  temp.insert(element->getVertex(0));
	  temp.insert(element->getVertex(1));
	  temp.insert(element->getVertex(2));
	}
  }

  for(it2=temp.begin();it2!=temp.end();it2++){
	x = (*it2)->x();
	y = (*it2)->y();
	z = (*it2)->z();
    //field.push_back(SPoint3(x,y,z));
	//vicinity.push_back(NULL);
  }
	
  duplicate = annAllocPts(field.size(),3);
	
  for(i=0;i<field.size();i++){
	duplicate[i][0] = field[i].x();
	duplicate[i][1] = field[i].y();
	duplicate[i][2] = field[i].z();
  }

  kd_tree = new ANNkd_tree(duplicate,field.size(),3);
#endif
}

bool Nearest_point::search(double x,double y,double z,SVector3& vec){
  int index;
  bool val;
  #if defined(HAVE_ANN)
  double e;
  double e2;
  SPoint3 found;
  ANNpoint query;
  ANNidxArray indices;
  ANNdistArray distances;
	
  query = annAllocPt(3);
  query[0] = x;
  query[1] = y;
  query[2] = z;
	
  indices = new ANNidx[1];
  distances = new ANNdist[1];
	
  e = 0.0;
  kd_tree->annkSearch(query,1,indices,distances,e);
  index = indices[0];
	
  annDeallocPt(query);
  delete[] indices;
  delete[] distances;

  if(vicinity[index]!=NULL){
	found = closest(vicinity[index],SPoint3(x,y,z));
  }
  else{
    found = field[index];
  }
	
  e2 = 0.000001;	
	
  if(fabs(found.x()-x)>e2 || fabs(found.y()-y)>e2 || fabs(found.z()-z)>e2){
    vec = SVector3(found.x()-x,found.y()-y,found.z()-z);
    vec.normalize();
	val = 1;
  }
  else{
    vec = SVector3(1.0,0.0,0.0);
	val = 0;
  }
  #endif
	
  return val;
}

double Nearest_point::T(double u,double v,double val1,double val2,double val3){
  return (1.0-u-v)*val1 + u*val2 + v*val3;
}

//The following method comes from this page : gamedev.net/topic/552906-closest-point-on-triangle
//It can also be found on this page : geometrictools.com/LibMathematics/Distance/Distance.html
SPoint3 Nearest_point::closest(MElement* element,SPoint3 point){		
  SVector3 edge0 = SVector3(element->getVertex(1)->x()-element->getVertex(0)->x(),element->getVertex(1)->y()-element->getVertex(0)->y(),
							element->getVertex(1)->z()-element->getVertex(0)->z());
  SVector3 edge1 = SVector3(element->getVertex(2)->x()-element->getVertex(0)->x(),element->getVertex(2)->y()-element->getVertex(0)->y(),
							element->getVertex(2)->z()-element->getVertex(0)->z());
  SVector3 v0 = SVector3(element->getVertex(0)->x()-point.x(),element->getVertex(0)->y()-point.y(),
						 element->getVertex(0)->z()-point.z());
	
  double a = dot(edge0,edge0);
  double b = dot(edge0,edge1);
  double c = dot(edge1,edge1);
  double d = dot(edge0,v0);
  double e = dot(edge1,v0);
		
  double det = a*c-b*b;
  double s = b*e-c*d;
  double t = b*d-a*e;
		
  if(s+t<det){
    if(s<0.0){
	  if(t<0.0){
	    if(d<0.0){
		  s = clamp(-d/a,0.0,1.0);
		  t = 0.0;
		}
		else{
		  s = 0.0;
		  t = clamp(-e/c,0.0,1.0);
		}
	  }
	  else{
	    s = 0.0;
		t = clamp(-e/c,0.0,1.0);
	  }
	}
	else if(t<0.0){
	  s = clamp(-d/a,0.0,1.0);
	  t = 0.0;
	}
	else{
	  double invDet = 1.0/det;
	  s *= invDet;
	  t *= invDet;
	}
  }
  else{
    if(s<0.0){
	  double tmp0 = b+d;
	  double tmp1 = c+e;
	  if(tmp1>tmp0){
	    double numer = tmp1-tmp0;
		double denom = a-2.0*b+c;
		s = clamp(numer/denom,0.0,1.0);
		t = 1.0-s;
	  }
	  else{
	    t = clamp(-e/c,0.0,1.0);
		s = 0.0;
	  }
	}
	else if(t<0.0){
	  if(a+d>b+e){
	    double numer = c+e-b-d;
		double denom = a-2.0*b+c;
		s = clamp(numer/denom,0.0,1.0);
		t = 1.0-s;
	  }
	  else{
	    s = clamp(-e/c,0.0,1.0);
		t = 0.0;
	  }
	}
	else{
	  double numer = c+e-b-d;
	  double denom = a-2.0*b+c;
	  s = clamp(numer/denom,0.0,1.0);
	  t = 1.0-s;
	}
  }
		
  return SPoint3(element->getVertex(0)->x()+s*edge0.x()+t*edge1.x(),element->getVertex(0)->y()+s*edge0.y()+t*edge1.y(),
				 element->getVertex(0)->z()+s*edge0.z()+t*edge1.z());
}

double Nearest_point::clamp(double x,double min,double max){
  double val;
	
  val = x;
  
  if(val<min){
    val = min;
  }
  else if(val>max){
    val = max;
  }
	
  return val;
}

void Nearest_point::print_field(GRegion* gr){
  unsigned int i;
  int j;
  bool val;
  double k;
  double x,y,z;
  MElement* element;
  MVertex* vertex;
  SVector3 vec;
	
  k = 0.05;
  std::ofstream file("nearest.pos");
  file << "View \"test\" {\n";
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  x = vertex->x();
	  y = vertex->y();
	  z = vertex->z();
	  val = search(x,y,z,vec);
	  if(val){
	    print_segment(SPoint3(x+k*vec.x(),y+k*vec.y(),z+k*vec.z()),
			  SPoint3(x-k*vec.x(),y-k*vec.y(),z-k*vec.z()),file);
	  }
	}
  }
	
  file << "};\n";
}

void Nearest_point::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
  << "{10, 20};\n";
}

GRegion* Nearest_point::test(){
  GRegion* gr;
  GModel* model = GModel::current();
	
  gr = *(model->firstRegion());
	
  return gr;
}

void Nearest_point::clear(){
  field.clear();
  vicinity.clear();
  #if defined(HAVE_ANN)
  delete duplicate;
  delete kd_tree;
  annClose();
  #endif
}

/****************static declarations****************/

std::map<MVertex*,Matrix> Frame_field::temp;
std::vector<std::pair<MVertex*,Matrix> > Frame_field::field;
std::map<int, Matrix> Frame_field::crossField;
std::map<MEdge, double, Less_Edge> Frame_field::crossDist;
Recombinator Frame_field::crossData;

#if defined(HAVE_ANN)
ANNpointArray Frame_field::duplicate;
ANNkd_tree* Frame_field::kd_tree;
ANNpointArray Frame_field::annTreeData;
ANNkd_tree* Frame_field::annTree;
std::vector<int> Frame_field::vertIndices;
#endif

std::map<MVertex*,double> Size_field::boundary;
MElementOctree* Size_field::octree;

std::vector<SPoint3> Nearest_point::field;
std::vector<MElement*> Nearest_point::vicinity;
#if defined(HAVE_ANN)
ANNpointArray Nearest_point::duplicate;
ANNkd_tree* Nearest_point::kd_tree;
#endif

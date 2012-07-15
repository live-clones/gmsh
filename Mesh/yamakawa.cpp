// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "yamakawa.h"
#include "GModel.h"
#include "MVertex.h"
#include "MElement.h"
#include <fstream>
#include "MHexahedron.h"
#include "MQuadrangle.h"

/****************class Hex****************/

Hex::Hex(){}

Hex::Hex(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2,MVertex* g2,MVertex* h2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
  g = g2;
  h = h2;
}

Hex::~Hex(){}

double Hex::get_quality() const{
  return quality;
}

void Hex::set_quality(double new_quality){
  quality = new_quality;
}

MVertex* Hex::get_a(){
  return a;
}

MVertex* Hex::get_b(){
  return b;
}

MVertex* Hex::get_c(){
  return c;
}

MVertex* Hex::get_d(){
  return d;
}

MVertex* Hex::get_e(){
  return e;
}

MVertex* Hex::get_f(){
  return f;
}

MVertex* Hex::get_g(){
  return g;
}

MVertex* Hex::get_h(){
  return h;
}

void Hex::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2,MVertex* g2,MVertex* h2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
  g = g2;
  h = h2;
}

bool Hex::operator<(const Hex& hex) const{
  return quality>hex.get_quality();
}

/****************class Recombinator****************/

Recombinator::Recombinator(){}

Recombinator::~Recombinator(){}

void Recombinator::execute(){
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

void Recombinator::execute(GRegion* gr){
  init_markings(gr);

  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);

  potential.clear();
  patern1(gr);
  patern2(gr);
  patern3(gr);

  std::sort(potential.begin(),potential.end());

  merge(gr);

  rearrange(gr);

  statistics(gr);
}

void Recombinator::init_markings(GRegion* gr){
  size_t i;
  MElement* element;

  markings.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	markings.insert(std::pair<MElement*,bool>(element,0));
  }
}

void Recombinator::patern1(GRegion* gr){
  size_t i;
  int index;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::vector<MVertex*> already1;
  std::vector<MVertex*> already2;
  std::vector<MVertex*> already3;
  std::vector<MVertex*> already4;
  std::set<MVertex*> bin1;
  std::set<MVertex*> bin2;
  std::set<MVertex*> bin3;
  std::set<MVertex*> bin4;
  std::set<MVertex*>::iterator it1;
  std::set<MVertex*>::iterator it2;
  std::set<MVertex*>::iterator it3;
  std::set<MVertex*>::iterator it4;
  Hex hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	max_scaled_jacobian(element,index);

	a = element->getVertex(index);
	b = element->getVertex((index+1)%4);
	c = element->getVertex((index+2)%4);
	d = element->getVertex((index+3)%4);

	already1.clear();
	already1.push_back(a);
	already1.push_back(b);
	already1.push_back(c);
	already1.push_back(d);
	bin1.clear();
	find(b,d,already1,bin1);
	for(it1=bin1.begin();it1!=bin1.end();it1++){
	  p = *it1;
	  already2.clear();
	  already2.push_back(a);
	  already2.push_back(b);
	  already2.push_back(c);
	  already2.push_back(d);
	  already2.push_back(p);
	  bin2.clear();
	  find(b,c,already2,bin2);
	  for(it2=bin2.begin();it2!=bin2.end();it2++){
	    q = *it2;
		already3.clear();
		already3.push_back(a);
		already3.push_back(b);
		already3.push_back(c);
		already3.push_back(d);
		already3.push_back(p);
		already3.push_back(q);
		bin3.clear();
		find(c,d,already3,bin3);
	    for(it3=bin3.begin();it3!=bin3.end();it3++){
		  r = *it3;
		  already4.clear();
		  already4.push_back(a);
		  already4.push_back(b);
		  already4.push_back(c);
		  already4.push_back(d);
		  already4.push_back(p);
		  already4.push_back(q);
		  already4.push_back(r);
		  bin4.clear();
		  find(p,q,r,already4,bin4);
		  for(it4=bin4.begin();it4!=bin4.end();it4++){
			s = *it4;
			hex = Hex(a,b,q,c,d,p,s,r);
			quality = min_scaled_jacobian(hex);
			hex.set_quality(quality);
			if(valid(hex)){
			  potential.push_back(hex);
			}
		  }
		}
	  }
	}
  }
}

void Recombinator::patern2(GRegion* gr){
  size_t i;
  int index1,index2,index3,index4;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::set<MElement*> verif;
  Hex hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    diagonal(element,index1,index2);
    two_others(index1,index2,index3,index4);

	b = element->getVertex(index1);
    d = element->getVertex(index2);
    a = element->getVertex(index3);
    c = element->getVertex(index4);

	verif.clear();
	find(b,d,verif);
	if(verif.size()==6){
	  s = find(a,b,d,c,verif);
	  p = find(b,c,d,a,verif);
	  if(s!=0 && p!=0){
	    r = find(s,b,d,a,verif);
	    q = find(p,b,d,c,verif);
		if(r!=0 && q!=0){
	      hex = Hex(a,s,b,c,d,r,q,p);
	      quality = min_scaled_jacobian(hex);
	      hex.set_quality(quality);
	      if(valid(hex)){
	        potential.push_back(hex);
	      }

	      hex = Hex(a,c,d,s,b,p,q,r);
	      quality = min_scaled_jacobian(hex);
	      hex.set_quality(quality);
	      if(valid(hex)){
	        potential.push_back(hex);
	      }
		}
	  }
	}
  }
}

void Recombinator::patern3(GRegion* gr){
  size_t i;
  int index1,index2,index3,index4;
  bool c1,c2,c3,c4,c5;
  bool c6,c7,c8,c9,c10;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  MVertex *fA,*fB,*bA,*bB;
  std::set<MElement*> verif1;
  std::set<MElement*> verif2;
  Hex hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	diagonal(element,index1,index2);
	two_others(index1,index2,index3,index4);

	b = element->getVertex(index1);
	d = element->getVertex(index2);
	a = element->getVertex(index3);
	c = element->getVertex(index4);

	verif1.clear();
	verif2.clear();
	find(b,d,verif1);
	find(a,c,verif2);

	if(verif1.size()==4 && verif2.size()==4){
	  fA = find(b,d,a,c,verif1);
	  fB = find(b,d,c,a,verif1);
	  bA = find(a,c,b,d,verif2);
	  bB = find(a,c,d,b,verif2);

	  if(fA!=0 && fB!=0 && bA!=0 && bB!=0 && fA!=fB && bA!=bB){
		if(scalar(fA,fB,a,b)>scalar(fA,fB,b,c) && scalar(bA,bB,a,b)>scalar(bA,bB,b,c)){
		  if(distance(fA,b,c)<distance(fB,b,c)){
		    p = fA;
			q = fB;
		  }
		  else{
		    p = fB;
			q = fA;
		  }

		  if(distance(bA,b,c)<distance(bB,b,c)){
		    r = bA;
			s = bB;
		  }
		  else{
		    r = bB;
			s = bA;
		  }

		  c1 = linked(b,p);
		  c2 = linked(c,p);
		  c3 = linked(p,q);
		  c4 = linked(a,q);
		  c5 = linked(d,q);

		  c6 = linked(b,r);
		  c7 = linked(c,r);
		  c8 = linked(r,s);
		  c9 = linked(a,s);
		  c10 = linked(d,s);

		  if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
		    hex = Hex(p,c,r,b,q,d,s,a);
			quality = min_scaled_jacobian(hex);
			hex.set_quality(quality);
			if(valid(hex)){
			  potential.push_back(hex);
			}
		  }
		}
		else if(scalar(fA,fB,a,b)<=scalar(fA,fB,b,c) && scalar(bA,bB,a,b)<=scalar(bA,bB,b,c)){
		  if(distance(fA,a,b)<distance(fB,a,b)){
		    p = fA;
			q = fB;
		  }
		  else{
		    p = fB;
			q = fA;
		  }

		  if(distance(bA,a,b)<distance(bB,a,b)){
		    r = bA;
			s = bB;
		  }
		  else{
		    r = bB;
			s = bA;
		  }

		  c1 = linked(b,p);
		  c2 = linked(a,p);
		  c3 = linked(p,q);
		  c4 = linked(c,q);
		  c5 = linked(d,q);

		  c6 = linked(b,r);
		  c7 = linked(a,r);
		  c8 = linked(r,s);
		  c9 = linked(c,s);
		  c10 = linked(d,s);

		  if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
		    hex = Hex(p,b,r,a,q,c,s,d);
			quality = min_scaled_jacobian(hex);
			hex.set_quality(quality);
			if(valid(hex)){
		      potential.push_back(hex);
			}
		  }
		}
	  }
	}
  }
}

void Recombinator::merge(GRegion* gr){
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::set<MElement*> parts;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  std::vector<MTetrahedron*>::iterator it3;
  Hex hex;

  count = 1;
  quality = 0.0;

  for(i=0;i<potential.size();i++){
    hex = potential[i];

	a = hex.get_a();
	b = hex.get_b();
	c = hex.get_c();
	d = hex.get_d();
	e = hex.get_e();
	f = hex.get_f();
	g = hex.get_g();
	h = hex.get_h();

	parts.clear();
	find(a,hex,parts);
	find(b,hex,parts);
	find(c,hex,parts);
	find(d,hex,parts);
	find(e,hex,parts);
	find(f,hex,parts);
	find(g,hex,parts);
	find(h,hex,parts);

	flag = 1;

	for(it=parts.begin();it!=parts.end();it++){
	  element = *it;
	  it2 = markings.find(element);
	  if(it2->second==1 && !sliver(element,hex)){
	    flag = 0;
		break;
	  }
	}

	threshold = 0.25;
	if(hex.get_quality()<threshold){
	  flag = 0;
	}

	if(!valid(hex,parts)){
	  flag = 0;
	}

	if(flag){
	  printf("%d - %d/%d - %f\n",count,i,(int)potential.size(),hex.get_quality());
	  quality = quality + hex.get_quality();
	  for(it=parts.begin();it!=parts.end();it++){
	    element = *it;
		it2 = markings.find(element);
		it2->second = 1;
	  }
	  gr->addHexahedron(new MHexahedron(a,b,c,d,e,f,g,h));
	  count++;
	}
  }

  it3 = gr->tetrahedra.begin();
  while(it3!=gr->tetrahedra.end()){
	element = (MElement*)(*it3);
	it2 = markings.find(element);
    if(it2->second==1){
      it3 = gr->tetrahedra.erase(it3);
	}
	else{
	  it3++;
	}
  }

  printf("hex average quality (0->1) : %f\n",quality/count);
}

void Recombinator::rearrange(GRegion* gr){
  size_t i;
  MElement* element;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	element->setVolumePositive();
  }
}

void Recombinator::statistics(GRegion* gr){
  size_t i;
  int all_nbr,hex_nbr;
  double all_volume,hex_volume,volume;
  MElement* element;

  all_nbr = 0;
  hex_nbr = 0;
  all_volume = 0.0;
  hex_volume = 0.0;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	volume = element->getVolume();

	if(element->getNumVertices()==8){
	  hex_nbr = hex_nbr + 1;
	  hex_volume = hex_volume + volume;
	}

	all_nbr = all_nbr + 1;
	all_volume = all_volume + volume;
  }

  printf("percentage of hex (number) : %.2f\n",hex_nbr*100.0/all_nbr);
  printf("percentage of hex (volume) : %.2f\n",hex_volume*100.0/all_volume);
}

bool Recombinator::sliver(MElement* element,Hex hex){
  bool val;
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;

  val = 0;
  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  flag1 = inclusion(a,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag2 = inclusion(b,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag3 = inclusion(c,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag4 = inclusion(d,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag2 = inclusion(b,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag3 = inclusion(c,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag4 = inclusion(d,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag2 = inclusion(b,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag3 = inclusion(c,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag4 = inclusion(d,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag2 = inclusion(b,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag3 = inclusion(c,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag4 = inclusion(d,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag2 = inclusion(b,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag3 = inclusion(c,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag4 = inclusion(d,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag2 = inclusion(b,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag3 = inclusion(c,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag4 = inclusion(d,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  return val;
}

double Recombinator::diagonal(MElement* element,int& index1,int& index2){
  double max;
  double l1,l2,l3,l4,l5,l6;
  MVertex *a,*b,*c,*d;

  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  max = 1000000.0;
  l1 = distance(a,b);
  l2 = distance(a,c);
  l3 = distance(a,d);
  l4 = distance(b,c);
  l5 = distance(c,d);
  l6 = distance(d,b);

  if(l1>=l2 && l1>=l3 && l1>=l4 && l1>=l5 && l1>=l6){
    index1 = 0;
	index2 = 1;
	max = l1;
  }
  else if(l2>=l1 && l2>=l3 && l2>=l4 && l2>=l5 && l2>=l6){
    index1 = 0;
	index2 = 2;
	max = l2;
  }
  else if(l3>=l1 && l3>=l2 && l3>=l4 && l3>=l5 && l3>=l6){
    index1 = 0;
	index2 = 3;
	max = l3;
  }
  else if(l4>=l1 && l4>=l2 && l4>=l3 && l4>=l5 && l4>=l6){
    index1 = 1;
	index2 = 2;
	max = l4;
  }
  else if(l5>=l1 && l5>=l2 && l5>=l3 && l5>=l4 && l5>=l6){
    index1 = 2;
	index2 = 3;
	max = l5;
  }
  else if(l6>=l1 && l6>=l2 && l6>=l3 && l6>=l4 && l6>=l5){
    index1 = 3;
	index2 = 1;
	max = l6;
  }

  return max;
}

double Recombinator::distance(MVertex* v1,MVertex* v2){
  double val;
  double x,y,z;

  x = v2->x() - v1->x();
  y = v2->y() - v1->y();
  z = v2->z() - v1->z();

  val = sqrt(x*x + y*y + z*z);
  return val;
}

double Recombinator::distance(MVertex* v,MVertex* v1,MVertex* v2){
  double val;
  double x,y,z;

  x = 0.5*(v2->x() + v1->x()) - v->x();
  y = 0.5*(v2->y() + v1->y()) - v->y();
  z = 0.5*(v2->z() + v1->z()) - v->z();

  val = sqrt(x*x + y*y + z*z);
  return val;
}

double Recombinator::scalar(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4){
  double val;
  double l1,l2;
  SVector3 vec1,vec2;

  vec1 = SVector3(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
  vec2 = SVector3(v4->x()-v3->x(),v4->y()-v3->y(),v4->z()-v3->z());

  l1 = vec1.norm();
  l2 = vec2.norm();

  val = dot(vec1,vec2);
  return fabs(val)/(l1*l2);
}

void Recombinator::two_others(int index1,int index2,int& index3,int& index4){
  int i;

  for(i=0;i<4;i++){
    if(i!=index1 && i!=index2){
	  index3 = i;
	  break;
	}
  }

  for(i=0;i<4;i++){
    if(i!=index1 && i!=index2 && i!=index3){
	  index4 = i;
	  break;
	}
  }
}

bool Recombinator::valid(Hex hex,const std::set<MElement*>& parts){
  bool ok1,ok2,ok3;
  bool ok4,ok5,ok6;
  bool flag1A,flag1B,flag1C,flag1D;
  bool flag2A,flag2B,flag2C,flag2D;
  bool flag3A,flag3B,flag3C,flag3D;
  bool flag4A,flag4B,flag4C,flag4D;
  bool flag5A,flag5B,flag5C,flag5D;
  bool flag6A,flag6B,flag6C,flag6D;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  flag1A = inclusion(a,b,c,parts);
  flag1B = inclusion(a,c,d,parts);
  flag1C = inclusion(b,c,d,parts);
  flag1D = inclusion(a,b,d,parts);
  ok1 = (flag1A && flag1B) || (flag1C && flag1D);

  flag2A = inclusion(e,f,g,parts);
  flag2B = inclusion(e,g,h,parts);
  flag2C = inclusion(f,g,h,parts);
  flag2D = inclusion(e,f,h,parts);
  ok2 = (flag2A && flag2B) || (flag2C && flag2D);

  flag3A = inclusion(a,b,f,parts);
  flag3B = inclusion(a,f,e,parts);
  flag3C = inclusion(b,e,f,parts);
  flag3D = inclusion(a,b,e,parts);
  ok3 = (flag3A && flag3B) || (flag3C && flag3D);

  flag4A = inclusion(b,c,g,parts);
  flag4B = inclusion(b,g,f,parts);
  flag4C = inclusion(c,g,f,parts);
  flag4D = inclusion(b,c,f,parts);
  ok4 = (flag4A && flag4B) || (flag4C && flag4D);

  flag5A = inclusion(c,d,g,parts);
  flag5B = inclusion(d,g,h,parts);
  flag5C = inclusion(c,g,h,parts);
  flag5D = inclusion(c,d,h,parts);
  ok5 = (flag5A && flag5B) || (flag5C && flag5D);

  flag6A = inclusion(a,d,h,parts);
  flag6B = inclusion(a,e,h,parts);
  flag6C = inclusion(d,e,h,parts);
  flag6D = inclusion(a,d,e,parts);
  ok6 = (flag6A && flag6B) || (flag6C && flag6D);

  if(ok1 && ok2 && ok3 && ok4 && ok5 && ok6){
    return 1;
  }
  else{
    return 0;
  }
}

bool Recombinator::valid(Hex hex){
  double k;
  double eta1,eta2,eta3;
  double eta4,eta5,eta6;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  k = 0.000001;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  eta1 = eta(a,b,c,d);
  eta2 = eta(e,f,g,h);
  eta3 = eta(a,b,f,e);
  eta4 = eta(b,c,g,f);
  eta5 = eta(d,a,e,h);
  eta6 = eta(d,c,g,h);

  if(eta1>k && eta2>k && eta3>k && eta4>k && eta5>k && eta6>k){
    return 1;
  }
  else{
    return 0;
  }
}

double Recombinator::eta(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  MQuadrangle* quad;

  quad = new MQuadrangle(a,b,c,d);
  val = quad->etaShapeMeasure();
  delete quad;
  return val;
}

bool Recombinator::linked(MVertex* v1,MVertex* v2){
  bool flag;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;

  it = vertex_to_vertices.find(v1);
  flag = 0;

  for(it2=(it->second).begin();it2!=(it->second).end();it2++){
	if(*it2==v2){
	  flag = 1;
	  break;
	}
  }

  return flag;
}

void Recombinator::find(MVertex* v1,MVertex* v2,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);

  intersection(it1->second,it2->second,already,final);
}

void Recombinator::find(MVertex* v1,MVertex* v2,MVertex* v3,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;
  std::map<MVertex*,std::set<MVertex*> >::iterator it3;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);
  it3 = vertex_to_vertices.find(v3);

  intersection(it1->second,it2->second,it3->second,already,final);
}

void Recombinator::find(MVertex* v1,MVertex* v2,std::set<MElement*>& final){
  std::map<MVertex*,std::set<MElement*> >::iterator it1;
  std::map<MVertex*,std::set<MElement*> >::iterator it2;

  it1 = vertex_to_elements.find(v1);
  it2 = vertex_to_elements.find(v2);

  intersection(it1->second,it2->second,final);
}

void Recombinator::find(MVertex* vertex,Hex hex,std::set<MElement*>& final){
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::set<MElement*>::iterator it2;

  it = vertex_to_elements.find(vertex);

  for(it2=(it->second).begin();it2!=(it->second).end();it2++){
    a = (*it2)->getVertex(0);
	b = (*it2)->getVertex(1);
	c = (*it2)->getVertex(2);
	d = (*it2)->getVertex(3);

	flag1 = inclusion(a,hex);
	flag2 = inclusion(b,hex);
	flag3 = inclusion(c,hex);
	flag4 = inclusion(d,hex);

	if(flag1 && flag2 && flag3 && flag4){
	  final.insert(*it2);
	}
  }
}

MVertex* Recombinator::find(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* already,const std::set<MElement*>& bin){
  bool flag1,flag2,flag3,flag4;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex* pointer;
  std::set<MElement*>::iterator it;

  pointer = 0;

  for(it=bin.begin();it!=bin.end();it++){
    element = *it;

	a = element->getVertex(0);
	b = element->getVertex(1);
	c = element->getVertex(2);
	d = element->getVertex(3);

	flag1 = inclusion(v1,a,b,c,d);
	flag2 = inclusion(v2,a,b,c,d);
	flag3 = inclusion(v3,a,b,c,d);
	flag4 = inclusion(already,a,b,c,d);

	if(flag1 && flag2 && flag3 && !flag4){
	  if(a!=v1 && a!=v2 && a!=v3){
	    pointer = a;
	  }
	  else if(b!=v1 && b!=v2 && b!=v3){
	    pointer = b;
	  }
	  else if(c!=v1 && c!=v2 && c!=v3){
	    pointer = c;
	  }
	  else{
	    pointer = d;
	  }
	  break;
	}
  }

  return pointer;
}

void Recombinator::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,
								const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  size_t i;
  bool ok;
  std::set<MVertex*> temp;
  std::set<MVertex*>::iterator it;

  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(temp,temp.end()));

  for(it=temp.begin();it!=temp.end();it++){
	ok = 1;

	for(i=0;i<already.size();i++){
	  if((*it)==already[i]){
	    ok = 0;
		break;
	  }
	}

	if(ok){
	  final.insert(*it);
	}
  }
}

void Recombinator::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,const std::set<MVertex*>& bin3,
								const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  size_t i;
  bool ok;
  std::set<MVertex*> temp;
  std::set<MVertex*> temp2;
  std::set<MVertex*>::iterator it;

  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(temp,temp.end()));
  std::set_intersection(temp.begin(),temp.end(),bin3.begin(),bin3.end(),std::inserter(temp2,temp2.end()));

  for(it=temp2.begin();it!=temp2.end();it++){
    ok = 1;

	for(i=0;i<already.size();i++){
	  if((*it)==already[i]){
	    ok = 0;
		break;
	  }
    }

	if(ok){
	  final.insert(*it);
	}
  }
}

void Recombinator::intersection(const std::set<MElement*>& bin1,const std::set<MElement*>& bin2,std::set<MElement*>& final){
  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(final,final.end()));
}

bool Recombinator::inclusion(MVertex* vertex,Hex hex){
  bool flag;

  flag = 0;

  if(vertex==hex.get_a()) flag = 1;
  else if(vertex==hex.get_b()) flag = 1;
  else if(vertex==hex.get_c()) flag = 1;
  else if(vertex==hex.get_d()) flag = 1;
  else if(vertex==hex.get_e()) flag = 1;
  else if(vertex==hex.get_f()) flag = 1;
  else if(vertex==hex.get_g()) flag = 1;
  else if(vertex==hex.get_h()) flag = 1;

  return flag;
}

bool Recombinator::inclusion(MVertex* vertex,MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag;

  flag = 0;

  if(vertex==a) flag = 1;
  else if(vertex==b) flag = 1;
  else if(vertex==c) flag = 1;
  else if(vertex==d) flag = 1;

  return flag;
}

bool Recombinator::inclusion(MVertex* v1,MVertex* v2,MVertex* v3,const std::set<MElement*>& bin){
  bool ok;
  bool flag1,flag2,flag3;
  MVertex *a,*b,*c,*d;
  MElement* element;
  std::set<MElement*>::iterator it;

  ok = 0;

  for(it=bin.begin();it!=bin.end();it++){
    element = *it;

	a = element->getVertex(0);
	b = element->getVertex(1);
	c = element->getVertex(2);
	d = element->getVertex(3);

	flag1 = inclusion(v1,a,b,c,d);
	flag2 = inclusion(v2,a,b,c,d);
	flag3 = inclusion(v3,a,b,c,d);

	if(flag1 && flag2 && flag3){
	  ok = 1;
	  break;
	}
  }

  return ok;
}

void Recombinator::build_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex *a,*b,*c,*d;
  std::set<MVertex*> bin;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;

  vertex_to_vertices.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
      a = element->getVertex(j);
	  b = element->getVertex((j+1)%4);
	  c = element->getVertex((j+2)%4);
	  d = element->getVertex((j+3)%4);

	  it = vertex_to_vertices.find(a);
	  if(it!=vertex_to_vertices.end()){
	    it->second.insert(b);
	    it->second.insert(c);
	    it->second.insert(d);
	  }
	  else{
	    bin.clear();
	    bin.insert(b);
	    bin.insert(c);
	    bin.insert(d);
	    vertex_to_vertices.insert(std::pair<MVertex*,std::set<MVertex*> >(a,bin));
	  }
	}
  }
}

void Recombinator::build_vertex_to_elements(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  vertex_to_elements.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);

	  it = vertex_to_elements.find(vertex);
	  if(it!=vertex_to_elements.end()){
	    it->second.insert(element);
	  }
	  else{
	    bin.clear();
		bin.insert(element);
		vertex_to_elements.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
	  }
	}
  }
}

void Recombinator::print_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  SPoint3 p1,p2;
  MElement* element;
  MVertex* vertex;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;

  std::ofstream file("vertex_to_vertices.pos");
  file << "View \"test\" {\n";

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  p1 = SPoint3(vertex->x(),vertex->y(),vertex->z());
	  it = vertex_to_vertices.find(vertex);
	  for(it2=(it->second).begin();it2!=(it->second).end();it2++){
	    p2 = SPoint3((*it2)->x(),(*it2)->y(),(*it2)->z());
		print_segment(p1,p2,file);
	  }
    }
  }
  file << "};\n";
}

void Recombinator::print_vertex_to_elements(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  it = vertex_to_elements.find(vertex);
	  it2 = vertex_to_vertices.find(vertex);
	  printf("%d %d\n",(int)(it->second).size(),(int)(it2->second).size());
	}
  }
}

void Recombinator::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
  << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
  << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
  << "{10, 20};\n";
}

double Recombinator::scaled_jacobian(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  double l1,l2,l3;
  SVector3 vec1,vec2,vec3;

  vec1 = SVector3(b->x()-a->x(),b->y()-a->y(),b->z()-a->z());
  vec2 = SVector3(c->x()-a->x(),c->y()-a->y(),c->z()-a->z());
  vec3 = SVector3(d->x()-a->x(),d->y()-a->y(),d->z()-a->z());

  l1 = vec1.norm();
  l2 = vec2.norm();
  l3 = vec3.norm();

  val = dot(vec1,crossprod(vec2,vec3));
  return fabs(val)/(l1*l2*l3);
}

double Recombinator::max_scaled_jacobian(MElement* element,int& index){
  double val;
  double j1,j2,j3,j4;
  MVertex *a,*b,*c,*d;

  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  j1 = scaled_jacobian(a,b,c,d);
  j2 = scaled_jacobian(b,c,d,a);
  j3 = scaled_jacobian(c,d,a,b);
  j4 = scaled_jacobian(d,a,b,c);

  if(j1>=j2 && j1>=j3 && j1>=j4){
    index = 0;
	val = j1;
  }
  else if(j2>=j3 && j2>=j4 && j2>=j1){
    index = 1;
	val = j2;
  }
  else if(j3>=j4 && j3>=j1 && j3>=j2){
    index = 2;
	val = j3;
  }
  else{
    index = 3;
	val = j4;
  }

  return val;
}

double Recombinator::min_scaled_jacobian(Hex hex){
  int i;
  double min;
  double j1,j2,j3,j4,j5,j6,j7,j8;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  std::vector<double> jacobians;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  j1 = scaled_jacobian(a,b,d,e);
  j2 = scaled_jacobian(b,a,c,f);
  j3 = scaled_jacobian(c,b,d,g);
  j4 = scaled_jacobian(d,a,c,h);
  j5 = scaled_jacobian(e,a,f,h);
  j6 = scaled_jacobian(f,b,e,g);
  j7 = scaled_jacobian(g,c,f,h);
  j8 = scaled_jacobian(h,d,e,g);

  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);
  jacobians.push_back(j7);
  jacobians.push_back(j8);

  min = 1000000000.0;
  for(i=0;i<8;i++){
    if(jacobians[i]<=min){
	  min = jacobians[i];
	}
  }

  return min;
}

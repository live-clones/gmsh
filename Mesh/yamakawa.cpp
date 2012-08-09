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
#include "MPyramid.h"
#include "MPrism.h"

/*****************************************/
/****************class Hex****************/
/*****************************************/

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

/*******************************************/
/****************class Facet****************/
/*******************************************/

Facet::Facet(){}

Facet::Facet(MVertex* a2,MVertex* b2,MVertex* c2){
  a = a2;
  b = b2;
  c = c2;
  compute_hash();
}

Facet::~Facet(){}

MVertex* Facet::get_a(){
  return a;
}

MVertex* Facet::get_b(){
  return b;
}

MVertex* Facet::get_c(){
  return c;
}

void Facet::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2){
  a = a2;
  b = b2;
  c = c2;
  compute_hash();
}

bool Facet::same_vertices(Facet facet){
  bool c1,c2,c3;
	
  c1 = (a==facet.get_a()) || (a==facet.get_b()) || (a==facet.get_c());
  c2 = (b==facet.get_a()) || (b==facet.get_b()) || (b==facet.get_c());
  c3 = (c==facet.get_a()) || (c==facet.get_b()) || (c==facet.get_c());
	
  return c1 && c2 && c3;
}

void Facet::compute_hash(){
  hash = (unsigned long long)a + (unsigned long long)b + (unsigned long long)c;
}

unsigned long long Facet::get_hash() const{
  return hash;
}

bool Facet::operator<(const Facet& facet) const{
  return hash<facet.get_hash();
}

/**********************************************/
/****************class Diagonal****************/
/**********************************************/

Diagonal::Diagonal(){}

Diagonal::Diagonal(MVertex* a2,MVertex* b2){
  a = a2;
  b = b2;
  compute_hash();
}

Diagonal::~Diagonal(){}

MVertex* Diagonal::get_a(){
  return a;
}

MVertex* Diagonal::get_b(){
  return b;
}

void Diagonal::set_vertices(MVertex* a2,MVertex* b2){
  a = a2;
  b = b2;
  compute_hash();
}

bool Diagonal::same_vertices(Diagonal diagonal){
  bool c1,c2;
	
  c1 = (a==diagonal.get_a()) || (a==diagonal.get_b());
  c2 = (b==diagonal.get_a()) || (b==diagonal.get_b());
	
  return c1 && c2;
}

void Diagonal::compute_hash(){
  hash = (unsigned long long)a + (unsigned long long)b;
}

unsigned long long Diagonal::get_hash() const{
  return hash;
}

bool Diagonal::operator<(const Diagonal& diagonal) const{
  return hash<diagonal.get_hash();
}

/**************************************************/
/****************class Recombinator****************/
/**************************************************/

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
  printf("................HEXAHEDRA................\n");
  init_markings(gr);

  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);
  printf("connectivity\n");

  potential.clear();
  patern1(gr);
  printf("patern no. 1\n");
  patern2(gr);
  printf("patern no. 2\n");
  patern3(gr);
  printf("patern no. 3\n");
	
  std::sort(potential.begin(),potential.end());

  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();
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
  std::vector<MVertex*> already;
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

	already.clear();
	already.push_back(a);
	already.push_back(b);
	already.push_back(c);
	already.push_back(d);
	bin1.clear();
	bin2.clear();
	bin3.clear();
	find(b,d,already,bin1);
	find(b,c,already,bin2);
	find(c,d,already,bin3);

	for(it1=bin1.begin();it1!=bin1.end();it1++){
	  p = *it1;
	  for(it2=bin2.begin();it2!=bin2.end();it2++){
	    q = *it2;
	    for(it3=bin3.begin();it3!=bin3.end();it3++){
		  r = *it3;
		  if(p!=q && p!=r && q!=r){
		    already.clear();
		    already.push_back(a);
		    already.push_back(b);
		    already.push_back(c);
		    already.push_back(d);
		    already.push_back(p);
		    already.push_back(q);
		    already.push_back(r);
		    bin4.clear();
		    find(p,q,r,already,bin4);
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
  int idle;
  bool flag;
  double threshold;
  double quality;
  double coeff;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::set<MElement*> parts;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  std::vector<MTetrahedron*>::iterator it3;
  Hex hex;

  count = 1;
  idle = 0;
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

	if(!conformityA(hex)){
	  flag = 0;
	}
	  
	if(!conformityB(hex)){
	  flag = 0;
	}  

	if(!conformityC(hex)){
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
	  build_hash_tableA(hex);
	  build_hash_tableB(hex);
	  build_hash_tableC(hex);
	  idle = 0;
	  count++;
	}
	else{
	  idle++;
	}
	  
	coeff = 0.1;  
	if((double)idle>coeff*(double)potential.size() && potential.size()>2000){
	  break;
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

  printf("hexahedra average quality (0->1) : %f\n",quality/count);
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

  printf("percentage of hexahedra (number) : %.2f\n",hex_nbr*100.0/all_nbr);
  printf("percentage of hexahedra (volume) : %.2f\n",hex_volume*100.0/all_volume);
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

bool Recombinator::inclusion(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;
	
  it = hash_tableA.find(facet);
  flag = 0;
	
  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(facet.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Recombinator::inclusion(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableB.find(diagonal);
  flag = 0;
	
  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Recombinator::duplicate(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableC.find(diagonal);
  flag = 0;
	
  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Recombinator::conformityA(Hex hex){
  bool c1,c2,c3,c4,c5,c6;
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
	
  c1 = conformityA(a,b,c,d);
  c2 = conformityA(e,f,g,h);
  c3 = conformityA(a,b,f,e);
  c4 = conformityA(b,c,g,f);
  c5 = conformityA(d,c,g,h);
  c6 = conformityA(d,a,e,h);
	
  return c1 && c2 && c3 && c4 && c5 && c6;
}

bool Recombinator::conformityA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool c1,c2,c3,c4;
	
  c1 = inclusion(Facet(a,b,c));
  c2 = inclusion(Facet(a,c,d));
  c3 = inclusion(Facet(a,b,d));
  c4 = inclusion(Facet(b,c,d));
	
  return (c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4);
}

bool Recombinator::conformityB(Hex hex){
  bool flag1;
  bool flag2;
  bool c1,c2,c3,c4;
  bool c5,c6,c7,c8;
  bool c9,c10,c11,c12;
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
	
  flag1 = inclusion(Diagonal(a,b));
  flag1 = flag1 || inclusion(Diagonal(b,f));
  flag1 = flag1 || inclusion(Diagonal(f,e));
  flag1 = flag1 || inclusion(Diagonal(e,a));
  flag1 = flag1 || inclusion(Diagonal(d,c));
  flag1 = flag1 || inclusion(Diagonal(c,g));
  flag1 = flag1 || inclusion(Diagonal(g,h));
  flag1 = flag1 || inclusion(Diagonal(h,d));
  flag1 = flag1 || inclusion(Diagonal(b,c));
  flag1 = flag1 || inclusion(Diagonal(f,g));
  flag1 = flag1 || inclusion(Diagonal(e,h));
  flag1 = flag1 || inclusion(Diagonal(a,d));
	
  c1 = inclusion(Diagonal(a,f));
  c2 = inclusion(Diagonal(b,e));
  flag2 = (c1 && !c2) || (!c1 && c2);
  c3 = inclusion(Diagonal(d,g));
  c4 = inclusion(Diagonal(c,h));
  flag2 = flag2 || (c3 && !c4) || (!c3 && c4);
  c5 = inclusion(Diagonal(b,g));
  c6 = inclusion(Diagonal(c,f));
  flag2 = flag2 || (c5 && !c6) || (!c5 && c6);
  c7 = inclusion(Diagonal(e,g));
  c8 = inclusion(Diagonal(f,h));
  flag2 = flag2 || (c7 && !c8) || (!c7 && c8);
  c9 = inclusion(Diagonal(a,h));
  c10 = inclusion(Diagonal(d,e));
  flag2 = flag2 || (c9 && !c10) || (!c9 && c10);
  c11 = inclusion(Diagonal(a,c));
  c12 = inclusion(Diagonal(b,d));
  flag2 = flag2 || (c11 && !c12) || (!c11 && c12);
	
  if(flag1 || flag2){
    return 0;
  }
  else{
    return 1;
  }
}

bool Recombinator::conformityC(Hex hex){
  bool flag;
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
	
  flag = duplicate(Diagonal(a,f));
  flag = flag || duplicate(Diagonal(b,e));
  flag = flag || duplicate(Diagonal(d,g));
  flag = flag || duplicate(Diagonal(c,h));
  flag = flag || duplicate(Diagonal(b,g));
  flag = flag || duplicate(Diagonal(c,f));
  flag = flag || duplicate(Diagonal(e,g));
  flag = flag || duplicate(Diagonal(f,h));
  flag = flag || duplicate(Diagonal(a,h));
  flag = flag || duplicate(Diagonal(d,e));
  flag = flag || duplicate(Diagonal(a,c));
  flag = flag || duplicate(Diagonal(b,d));
	
  if(flag){
    return 0;
  }
  else{
    return 1;
  }
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

void Recombinator::build_hash_tableA(Hex hex){
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
	
  build_hash_tableA(a,b,c,d);
  build_hash_tableA(e,f,g,h);
  build_hash_tableA(a,b,f,e);
  build_hash_tableA(b,c,g,f);
  build_hash_tableA(d,c,g,h);
  build_hash_tableA(d,a,e,h);
}

void Recombinator::build_hash_tableA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableA(Facet(a,b,c));
  build_hash_tableA(Facet(a,c,d));
  build_hash_tableA(Facet(a,b,d));
  build_hash_tableA(Facet(b,d,c));
}

void Recombinator::build_hash_tableA(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;
	
  it = hash_tableA.find(facet);
  flag = 1;
	
  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(facet.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableA.insert(facet);
  }	
}

void Recombinator::build_hash_tableB(Hex hex){
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
	
  build_hash_tableB(a,b,c,d);
  build_hash_tableB(e,f,g,h);
  build_hash_tableB(a,b,f,e);
  build_hash_tableB(b,c,g,f);
  build_hash_tableB(d,c,g,h);
  build_hash_tableB(d,a,e,h);
}

void Recombinator::build_hash_tableB(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableB(Diagonal(a,c));
  build_hash_tableB(Diagonal(b,d));
}

void Recombinator::build_hash_tableB(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableB.find(diagonal);
  flag = 1;
	
  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableB.insert(diagonal);
  }	
}

void Recombinator::build_hash_tableC(Hex hex){
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
	
  build_hash_tableC(Diagonal(a,b));
  build_hash_tableC(Diagonal(b,c));
  build_hash_tableC(Diagonal(c,d));
  build_hash_tableC(Diagonal(d,a));
  build_hash_tableC(Diagonal(e,f));
  build_hash_tableC(Diagonal(f,g));
  build_hash_tableC(Diagonal(g,h));
  build_hash_tableC(Diagonal(h,e));
  build_hash_tableC(Diagonal(a,e));
  build_hash_tableC(Diagonal(b,f));
  build_hash_tableC(Diagonal(c,g));
  build_hash_tableC(Diagonal(d,h));
}

void Recombinator::build_hash_tableC(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableC.find(diagonal);
  flag = 1;
	
  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableC.insert(diagonal);
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

void Recombinator::print_hash_tableA(){
  std::multiset<Facet>::iterator it;
	
  for(it=hash_tableA.begin();it!=hash_tableA.end();it++){
    printf("%lld\n",it->get_hash());
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

/*******************************************/
/****************class Prism****************/
/*******************************************/

Prism::Prism(){}

Prism::Prism(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

Prism::~Prism(){}

double Prism::get_quality() const{
  return quality;
}

void Prism::set_quality(double new_quality){
  quality = new_quality;
}

MVertex* Prism::get_a(){
  return a;
}

MVertex* Prism::get_b(){
  return b;
}

MVertex* Prism::get_c(){
  return c;
}

MVertex* Prism::get_d(){
  return d;
}

MVertex* Prism::get_e(){
  return e;
}

MVertex* Prism::get_f(){
  return f;
}

void Prism::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

bool Prism::operator<(const Prism& prism) const{
  return quality>prism.get_quality();
}

/***************************************************/
/****************class Supplementary****************/
/***************************************************/

Supplementary::Supplementary(){}

Supplementary::~Supplementary(){}

void Supplementary::execute(){
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

void Supplementary::execute(GRegion* gr){
  unsigned int i;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
	
  printf("................PRISMS................\n");
  init_markings(gr);
 
  build_vertex_to_vertices(gr);
  build_vertex_to_tetrahedra(gr);
  printf("connectivity\n");
	
  potential.clear();
  patern(gr);
  printf("patern\n");
	
  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(eight(element)){
	  a = element->getVertex(0);
	  b = element->getVertex(1);
	  c = element->getVertex(2);
	  d = element->getVertex(3);
	  e = element->getVertex(4);
	  f = element->getVertex(5);
	  g = element->getVertex(6);
	  h = element->getVertex(7);
		
	  build_hash_tableA(a,b,c,d);
	  build_hash_tableA(e,f,g,h);
	  build_hash_tableA(a,b,f,e);
	  build_hash_tableA(b,c,g,f);
	  build_hash_tableA(d,c,g,h);
	  build_hash_tableA(d,a,e,h);
		
	  build_hash_tableB(a,b,c,d);
	  build_hash_tableB(e,f,g,h);
	  build_hash_tableB(a,b,f,e);
	  build_hash_tableB(b,c,g,f);
	  build_hash_tableB(d,c,g,h);
	  build_hash_tableB(d,a,e,h);
		
	  build_hash_tableC(Diagonal(a,b));
	  build_hash_tableC(Diagonal(b,c));
	  build_hash_tableC(Diagonal(c,d));
	  build_hash_tableC(Diagonal(d,a));
	  build_hash_tableC(Diagonal(e,f));
	  build_hash_tableC(Diagonal(f,g));
	  build_hash_tableC(Diagonal(g,h));
	  build_hash_tableC(Diagonal(h,e));
	  build_hash_tableC(Diagonal(a,e));
	  build_hash_tableC(Diagonal(b,f));
	  build_hash_tableC(Diagonal(c,g));
	  build_hash_tableC(Diagonal(d,h));
	}
  }
	
  std::sort(potential.begin(),potential.end());
	
  merge(gr);	
	
  rearrange(gr);
	
  statistics(gr);
}

void Supplementary::init_markings(GRegion* gr){
  unsigned int i;
  MElement* element;
	
  markings.clear();
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
	  markings.insert(std::pair<MElement*,bool>(element,0));
	}
  }
}

void Supplementary::patern(GRegion* gr){
  size_t i;
  int j,k;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q;
  std::vector<MVertex*> vertices;
  std::vector<MVertex*> already;
  std::set<MVertex*> bin1;
  std::set<MVertex*> bin2;
  std::set<MVertex*>::iterator it1;
  std::set<MVertex*>::iterator it2;
  Prism prism;
	
  vertices.resize(3);
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
	  for(j=0;j<4;j++){ 
	    a = element->getVertex(j);
		vertices[0] = element->getVertex((j+1)%4);
		vertices[1] = element->getVertex((j+2)%4);
		vertices[2] = element->getVertex((j+3)%4);
		for(k=0;k<3;k++){
		  b = vertices[k%3];
		  c = vertices[(k+1)%3];
		  d = vertices[(k+2)%3];
		  already.clear();
		  already.push_back(a);
		  already.push_back(b);
		  already.push_back(c);
		  already.push_back(d);
		  bin1.clear();
		  bin2.clear();
		  find(b,d,already,bin1);
		  find(c,d,already,bin2);
		  for(it1=bin1.begin();it1!=bin1.end();it1++){
			p = *it1;
			for(it2=bin2.begin();it2!=bin2.end();it2++){
			  q = *it2;
			  if(p!=q && linked(p,q)){
			    prism = Prism(a,b,c,d,p,q);
				quality = min_scaled_jacobian(prism);
				prism.set_quality(quality);
				if(valid(prism)){
				  potential.push_back(prism);
				}
			  }
			}
		  }
		}
	  }
	}
  }
}

void Supplementary::merge(GRegion* gr){
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
  MElement* element;
  std::set<MElement*> parts;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  std::vector<MTetrahedron*>::iterator it3;
  Prism prism;
	
  count = 1;
  quality = 0.0;
	
  for(i=0;i<potential.size();i++){
    prism = potential[i];
		
	a = prism.get_a();
	b = prism.get_b();
	c = prism.get_c();
	d = prism.get_d();
	e = prism.get_e();
	f = prism.get_f();
		
	parts.clear();
	find(a,prism,parts);
	find(b,prism,parts);
	find(c,prism,parts);
	find(d,prism,parts);
	find(e,prism,parts);
	find(f,prism,parts);
		
	flag = 1;
		
	for(it=parts.begin();it!=parts.end();it++){
	  element = *it;
	  it2 = markings.find(element);
	  if(it2->second==1 && !sliver(element,prism)){
	    flag = 0;
		break;
	  }
	}
		
	threshold = 0.15;
	if(prism.get_quality()<threshold){
      flag = 0;
	}
		
	if(!valid(prism,parts)){
      flag = 0;
	}
		
	if(!conformityA(prism)){
	  flag = 0;
	}
	  
	if(!conformityB(prism)){
	  flag = 0;
	}  
	  
	if(!conformityC(prism)){
	  flag = 0;
	}  
	  
	if(flag){
	  printf("%d - %d/%d - %f\n",count,i,(int)potential.size(),prism.get_quality());
	  quality = quality + prism.get_quality();
	  for(it=parts.begin();it!=parts.end();it++){
	    element = *it;
		it2 = markings.find(element);
		it2->second = 1;
	  }
	  gr->addPrism(new MPrism(a,b,c,d,e,f));
	  build_hash_tableA(prism);
	  build_hash_tableB(prism);
	  build_hash_tableC(prism);
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
	
  printf("prisms average quality (0->1) : %f\n",quality/count);
}

void Supplementary::rearrange(GRegion* gr){
  size_t i;
  MElement* element;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	element->setVolumePositive();
  }
}

void Supplementary::statistics(GRegion* gr){
  size_t i;
  int all_nbr,prism_nbr;
  double all_volume,prism_volume,volume;
  MElement* element;
	
  all_nbr = 0;
  prism_nbr = 0;
  all_volume = 0.0;
  prism_volume = 0.0;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	volume = element->getVolume();
		
	if(six(element)){
	  prism_nbr = prism_nbr + 1;
	  prism_volume = prism_volume + volume;
	}
		
	all_nbr = all_nbr + 1;
	all_volume = all_volume + volume;
  }
	
  printf("percentage of prisms (number) : %.2f\n",prism_nbr*100.0/all_nbr);
  printf("percentage of prisms (volume) : %.2f\n",prism_volume*100.0/all_volume);
}

bool Supplementary::four(MElement* element){
  if(element->getNumVertices()==4) return 1;
  else return 0;
}

bool Supplementary::five(MElement* element){
  if(element->getNumVertices()==5) return 1;
  else return 0;
}

bool Supplementary::six(MElement* element){
  if(element->getNumVertices()==6) return 1;
  else return 0;
}

bool Supplementary::eight(MElement* element){
  if(element->getNumVertices()==8) return 1;
  else return 0;
}

bool Supplementary::sliver(MElement* element,Prism prism){
  bool val;
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;
	
  val = 0;
  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);
	
  flag1 = inclusion(a,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag2 = inclusion(b,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag3 = inclusion(c,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag4 = inclusion(d,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  if(flag1 && flag2 && flag3 && flag4) val = 1;
	
  flag1 = inclusion(a,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag2 = inclusion(b,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag3 = inclusion(c,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag4 = inclusion(d,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  if(flag1 && flag2 && flag3 && flag4) val = 1;
	
  flag1 = inclusion(a,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag2 = inclusion(b,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag3 = inclusion(c,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag4 = inclusion(d,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  if(flag1 && flag2 && flag3 && flag4) val = 1;
	
  return val;
}

bool Supplementary::valid(Prism prism,const std::set<MElement*>& parts){
  bool ok1,ok2,ok3,ok4;
  bool flag1A,flag1B,flag1C,flag1D;
  bool flag2A,flag2B,flag2C,flag2D;
  bool flag3A,flag3B,flag3C,flag3D;
  bool flag4,flag5;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  flag1A = inclusion(a,d,f,parts);
  flag1B = inclusion(a,f,c,parts);
  flag1C = inclusion(a,c,d,parts);
  flag1D = inclusion(c,d,f,parts);
  ok1 = (flag1A && flag1B) || (flag1C && flag1D);
	
  flag2A = inclusion(a,b,d,parts);
  flag2B = inclusion(b,d,e,parts);
  flag2C = inclusion(a,d,e,parts);
  flag2D = inclusion(a,b,e,parts);
  ok2 = (flag2A && flag2B) || (flag2C && flag2D);
	
  flag3A = inclusion(b,c,f,parts);
  flag3B = inclusion(b,e,f,parts);
  flag3C = inclusion(b,c,e,parts);
  flag3D = inclusion(c,e,f,parts);
  ok3 = (flag3A && flag3B) || (flag3C && flag3D);
	
  flag4 = inclusion(a,b,c,parts);
  flag5 = inclusion(d,e,f,parts);
  ok4 = flag4 && flag5;
	
  if(ok1 && ok2 && ok3 && ok4){
    return 1;
  }
  else{
    return 0;
  }
}

bool Supplementary::valid(Prism prism){
  double k;
  double eta1,eta2,eta3;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  k = 0.000001;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  eta1 = eta(a,d,f,c);
  eta2 = eta(a,b,e,d);
  eta3 = eta(b,c,f,e);
	
  if(eta1>k && eta2>k && eta3>k){
    return 1;
  }
  else{
    return 0;
  }
}

double Supplementary::eta(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  MQuadrangle* quad;
	
  quad = new MQuadrangle(a,b,c,d);
  val = quad->etaShapeMeasure();
  delete quad;
  return val;
}

bool Supplementary::linked(MVertex* v1,MVertex* v2){
  bool flag;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;
	
  it = vertex_to_vertices.find(v1);
  flag = 0;
	
  if(it!=vertex_to_vertices.end()){
    for(it2=(it->second).begin();it2!=(it->second).end();it2++){
      if(*it2==v2){
	    flag = 1;
	    break;
	  }
    }
  }
	
  return flag;
}

void Supplementary::find(MVertex* v1,MVertex* v2,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;
	
  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);
	
  if(it1!=vertex_to_vertices.end() && it2!=vertex_to_vertices.end()){
    intersection(it1->second,it2->second,already,final);
  }
}

void Supplementary::find(MVertex* vertex,Prism prism,std::set<MElement*>& final){
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::set<MElement*>::iterator it2;
	
  it = vertex_to_tetrahedra.find(vertex);
	
  if(it!=vertex_to_tetrahedra.end()){
    for(it2=(it->second).begin();it2!=(it->second).end();it2++){
      a = (*it2)->getVertex(0);
	  b = (*it2)->getVertex(1);
	  c = (*it2)->getVertex(2);
	  d = (*it2)->getVertex(3);
		
	  flag1 = inclusion(a,prism);
	  flag2 = inclusion(b,prism);
	  flag3 = inclusion(c,prism);
	  flag4 = inclusion(d,prism);
		
	  if(flag1 && flag2 && flag3 && flag4){
	    final.insert(*it2);
	  }
    }
  }
}

void Supplementary::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,
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

bool Supplementary::inclusion(MVertex* vertex,Prism prism){
  bool flag;
	
  flag = 0;
	
  if(vertex==prism.get_a()) flag = 1;
  else if(vertex==prism.get_b()) flag = 1;
  else if(vertex==prism.get_c()) flag = 1;
  else if(vertex==prism.get_d()) flag = 1;
  else if(vertex==prism.get_e()) flag = 1;
  else if(vertex==prism.get_f()) flag = 1;
	
  return flag;
}

bool Supplementary::inclusion(MVertex* vertex,MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag;
	
  flag = 0;
	
  if(vertex==a) flag = 1;
  else if(vertex==b) flag = 1;
  else if(vertex==c) flag = 1;
  else if(vertex==d) flag = 1;
	
  return flag;
}

bool Supplementary::inclusion(MVertex* v1,MVertex* v2,MVertex* v3,const std::set<MElement*>& bin){
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

bool Supplementary::inclusion(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;
	
  it = hash_tableA.find(facet);
  flag = 0;
	
  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(facet.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Supplementary::inclusion(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableB.find(diagonal);
  flag = 0;
	
  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Supplementary::duplicate(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableC.find(diagonal);
  flag = 0;
	
  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 1;
	  break;
	}
		
	it++;
  }
	
  return flag;
}

bool Supplementary::conformityA(Prism prism){
  bool c1,c2,c3;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  c1 = conformityA(a,d,f,c);
  c2 = conformityA(a,d,e,b);
  c3 = conformityA(b,c,f,e);
	
  return c1 && c2 && c3;
}

bool Supplementary::conformityA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool c1,c2,c3,c4;
	
  c1 = inclusion(Facet(a,b,c));
  c2 = inclusion(Facet(a,c,d));
  c3 = inclusion(Facet(a,b,d));
  c4 = inclusion(Facet(b,c,d));
	
  return (c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4);
}

bool Supplementary::conformityB(Prism prism){
  bool flag1;
  bool flag2;
  bool c1,c2,c3;
  bool c4,c5,c6;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  flag1 = inclusion(Diagonal(a,c));
  flag1 = flag1 || inclusion(Diagonal(d,f));
  flag1 = flag1 || inclusion(Diagonal(d,a));
  flag1 = flag1 || inclusion(Diagonal(f,c));
  flag1 = flag1 || inclusion(Diagonal(e,b));
  flag1 = flag1 || inclusion(Diagonal(d,e));
  flag1 = flag1 || inclusion(Diagonal(e,f));
  flag1 = flag1 || inclusion(Diagonal(a,b));
  flag1 = flag1 || inclusion(Diagonal(b,c));
	
  c1 = inclusion(Diagonal(a,f));
  c2 = inclusion(Diagonal(d,c));
  flag2 = (c1 && !c2) || (!c1 && c2);
  c3 = inclusion(Diagonal(a,e));
  c4 = inclusion(Diagonal(b,d));
  flag2 = flag2 || (c3 && !c4) || (!c3 && c4);
  c5 = inclusion(Diagonal(b,f));
  c6 = inclusion(Diagonal(c,e));
  flag2 = flag2 || (c5 && !c6) || (!c5 && c6);
	
  if(flag1 || flag2){
    return 0;
  }
  else{
    return 1;
  }
}

bool Supplementary::conformityC(Prism prism){
  bool flag;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  flag = duplicate(Diagonal(a,f));
  flag = flag || duplicate(Diagonal(d,c));
  flag = flag || duplicate(Diagonal(a,e));
  flag = flag || duplicate(Diagonal(b,d));
  flag = flag || duplicate(Diagonal(b,f));
  flag = flag || duplicate(Diagonal(c,e));
	
  if(flag){
    return 0;
  }
  else{
    return 1;
  }
}

void Supplementary::build_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex *a,*b,*c,*d;
  std::set<MVertex*> bin;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
	
  vertex_to_vertices.clear();
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
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
}

void Supplementary::build_vertex_to_tetrahedra(GRegion* gr){
  unsigned int i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
	
  vertex_to_tetrahedra.clear();
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
	  for(j=0;j<element->getNumVertices();j++){
	    vertex = element->getVertex(j);
				
		it = vertex_to_tetrahedra.find(vertex);
		if(it!=vertex_to_tetrahedra.end()){
		  it->second.insert(element);
		}
		else{
		  bin.clear();
		  bin.insert(element);
		  vertex_to_tetrahedra.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
		}
	  }
	}
  }
}

void Supplementary::build_hash_tableA(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  build_hash_tableA(a,d,f,c);
  build_hash_tableA(a,d,e,b);
  build_hash_tableA(b,c,f,e);
}

void Supplementary::build_hash_tableA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableA(Facet(a,b,c));
  build_hash_tableA(Facet(a,c,d));
  build_hash_tableA(Facet(a,b,d));
  build_hash_tableA(Facet(b,d,c));
}

void Supplementary::build_hash_tableA(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;
	
  it = hash_tableA.find(facet);
  flag = 1;
	
  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(facet.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableA.insert(facet);
  }	
}

void Supplementary::build_hash_tableB(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  build_hash_tableB(a,d,f,c);
  build_hash_tableB(a,d,e,b);
  build_hash_tableB(b,e,f,c);
}

void Supplementary::build_hash_tableB(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableB(Diagonal(a,c));
  build_hash_tableB(Diagonal(b,d));
}

void Supplementary::build_hash_tableB(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableB.find(diagonal);
  flag = 1;
	
  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableB.insert(diagonal);
  }	
}

void Supplementary::build_hash_tableC(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  build_hash_tableC(Diagonal(a,d));
  build_hash_tableC(Diagonal(d,f));
  build_hash_tableC(Diagonal(f,c));
  build_hash_tableC(Diagonal(a,c));
  build_hash_tableC(Diagonal(e,b));
  build_hash_tableC(Diagonal(d,e));
  build_hash_tableC(Diagonal(f,e));
  build_hash_tableC(Diagonal(a,b));
  build_hash_tableC(Diagonal(b,c));
}

void Supplementary::build_hash_tableC(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;
	
  it = hash_tableC.find(diagonal);
  flag = 1;
	
  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
	  break;
	}
		
	if(diagonal.same_vertices(*it)){
	  flag = 0;
	  break;
	}
		
	it++;
  }
	
  if(flag){
    hash_tableC.insert(diagonal);
  }	
}

double Supplementary::scaled_jacobian(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
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

double Supplementary::min_scaled_jacobian(Prism prism){
  int i;
  double min;
  double j1,j2,j3,j4,j5,j6;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
  std::vector<double> jacobians;
	
  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();
	
  j1 = scaled_jacobian(a,b,c,d);
  j2 = scaled_jacobian(b,a,c,e);
  j3 = scaled_jacobian(c,a,b,f);
  j4 = scaled_jacobian(d,a,e,f);
  j5 = scaled_jacobian(e,b,d,f);
  j6 = scaled_jacobian(f,c,d,e);
	
  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);
	
  min = 1000000000.0;
  for(i=0;i<6;i++){
    if(jacobians[i]<=min){
	  min = jacobians[i];
	}
  }
	
  return min;
}

/********************************************/
/****************class PostOp****************/
/********************************************/

PostOp::PostOp(){}

PostOp::~PostOp(){}

void PostOp::execute(){
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

void PostOp::execute(GRegion* gr){
  printf("................PYRAMIDS................\n");
  init_markings(gr);
  build_vertex_to_tetrahedra(gr);
  pyramids(gr);
  rearrange(gr);
  statistics(gr);
}

void PostOp::init_markings(GRegion* gr){
  unsigned int i;
  MElement* element;
	
  markings.clear();
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
	  markings.insert(std::pair<MElement*,bool>(element,0));
	}
  }
}

void PostOp::pyramids(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::vector<MElement*> hexahedra;
  std::vector<MElement*> prisms;
  std::vector<MTetrahedron*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
	
  hexahedra.clear();
  prisms.clear();
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(eight(element)){
	  hexahedra.push_back(element);
	}
  }

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(six(element)){
	  prisms.push_back(element);
	}
  }	

  for(i=0;i<hexahedra.size();i++){
    element = hexahedra[i];
		
	a = element->getVertex(0);
	b = element->getVertex(1);
	c = element->getVertex(2);
	d = element->getVertex(3);
	e = element->getVertex(4);
	f = element->getVertex(5);
	g = element->getVertex(6);
	h = element->getVertex(7);
		
	pyramids(a,b,c,d,gr);
	pyramids(e,f,g,h,gr);
	pyramids(a,b,f,e,gr);
	pyramids(b,c,g,f,gr);
	pyramids(d,c,g,h,gr);
	pyramids(d,a,e,h,gr);
  }
	
  for(i=0;i<prisms.size();i++){
    element = prisms[i];
		
	a = element->getVertex(0);
	b = element->getVertex(1);
	c = element->getVertex(2);
	d = element->getVertex(3);
	e = element->getVertex(4);
	f = element->getVertex(5);
		
	pyramids(a,d,f,c,gr);
	pyramids(a,b,e,d,gr);
	pyramids(b,c,f,e,gr);
  }	
	
  it = gr->tetrahedra.begin();
  while(it!=gr->tetrahedra.end()){
    element = (MElement*)(*it);
	it2 = markings.find(element);
	if(it2->second==1){
	  it = gr->tetrahedra.erase(it);
	}
	else{
	  it++;
	}
  }
}

void PostOp::pyramids(MVertex* a,MVertex* b,MVertex* c,MVertex* d,GRegion* gr){
  MVertex* vertex;
  std::set<MElement*> bin;
  std::set<MElement*> bin1;
  std::set<MElement*> bin2;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it1;
  std::map<MElement*,bool>::iterator it2;
	
  bin1.clear();
  bin2.clear();
  find(a,c,bin1);
  find(b,d,bin2);
	
  bin.clear();
  for(it=bin1.begin();it!=bin1.end();it++){
    bin.insert(*it);
  }
  for(it=bin2.begin();it!=bin2.end();it++){
    bin.insert(*it);
  }
	
  if(bin.size()==2){
    it = bin.begin();
	it1 = markings.find(*it);
	it++;
	it2 = markings.find(*it);
		
	if(it1->second==0 && it2->second==0){
	  vertex = find(a,b,c,d,*it);
			
	  if(vertex!=0){
	    it1->second = 1;
		it2->second = 1;
		gr->addPyramid(new MPyramid(a,b,c,d,vertex));
	  }
	}
  }
}

void PostOp::rearrange(GRegion* gr){
  unsigned int i;
  MElement* element;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	element->setVolumePositive();
  }
}

void PostOp::statistics(GRegion* gr){
  unsigned int i;
  int nbr,nbr8,nbr6,nbr5,nbr4;
  double vol,vol8,vol6,vol5,vol4;
  MElement* element;
	
  nbr = 0;
  nbr8 = 0;
  nbr6 = 0;
  nbr5 = 0;
  nbr4 = 0;
  vol = 0.0;
  vol8 = 0.0;
  vol6 = 0.0;
  vol5 = 0.0;
  vol4 = 0.0;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
		
	if(eight(element)){
	  nbr8 = nbr8 + 1;
	  vol8 = vol8 + element->getVolume();
	}
		
	if(six(element)){
	  nbr6 = nbr6 + 1;
	  vol6 = vol6 + element->getVolume();
	}  
	  
    if(five(element)){
	  nbr5 = nbr5 + 1;
	  vol5 = vol5 + element->getVolume();
	}
		
	if(four(element)){
	  nbr4 = nbr4 + 1;
	  vol4 = vol4 + element->getVolume();
	}
		
	nbr = nbr + 1;
	vol = vol + element->getVolume();
  }
	
  printf("Number :\n");
  printf("  percentage of hexahedra : %.2f\n",nbr8*100.0/nbr);
  printf("  percentage of prisms : %.2f\n",nbr6*100.0/nbr);
  printf("  percentage of pyramids : %.2f\n",nbr5*100.0/nbr);
  printf("  percentage of tetrahedra : %.2f\n",nbr4*100.0/nbr);
  printf("Volume :\n");
  printf("  percentage of hexahedra : %.2f\n",vol8*100.0/vol);
  printf("  percentage of prisms : %.2f\n",vol6*100.0/vol);
  printf("  percentage of pyramids : %.2f\n",vol5*100.0/vol);
  printf("  percentage of tetrahedra : %.2f\n",vol4*100.0/vol);
  printf("Total number of elements : %d\n",gr->getNumMeshElements());
}

bool PostOp::four(MElement* element){
  if(element->getNumVertices()==4) return 1;
  else return 0;
}

bool PostOp::five(MElement* element){
  if(element->getNumVertices()==5) return 1;
  else return 0;
}

bool PostOp::six(MElement* element){
  if(element->getNumVertices()==6) return 1;
  else return 0;
}

bool PostOp::eight(MElement* element){
  if(element->getNumVertices()==8) return 1;
  else return 0;
}

MVertex* PostOp::find(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4,MElement* element){
  int i;
  MVertex* vertex;
  MVertex* pointer;
	
  pointer = 0;	
	
  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);
	if(vertex!=v1 && vertex!=v2 && vertex!=v3 && vertex!=v4){
	  pointer = vertex;
	  break;
	}
  }
	
  return pointer;
}

void PostOp::find(MVertex* v1,MVertex* v2,std::set<MElement*>& final){
  std::map<MVertex*,std::set<MElement*> >::iterator it1;
  std::map<MVertex*,std::set<MElement*> >::iterator it2;
	
  it1 = vertex_to_tetrahedra.find(v1);
  it2 = vertex_to_tetrahedra.find(v2);
	
  if(it1!=vertex_to_tetrahedra.end() && it2!=vertex_to_tetrahedra.end()){
    intersection(it1->second,it2->second,final);
  }
}

void PostOp::intersection(const std::set<MElement*>& bin1,const std::set<MElement*>& bin2,std::set<MElement*>& final){
  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(final,final.end()));
}

void PostOp::build_vertex_to_tetrahedra(GRegion* gr){
  unsigned int i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
	
  vertex_to_tetrahedra.clear();	
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	if(four(element)){
	  for(j=0;j<element->getNumVertices();j++){
	    vertex = element->getVertex(j);
				
		it = vertex_to_tetrahedra.find(vertex);
		if(it!=vertex_to_tetrahedra.end()){
		  it->second.insert(element);
		}
		else{
		  bin.clear();
		  bin.insert(element);
		  vertex_to_tetrahedra.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
		}
	  }
	}
  }
}
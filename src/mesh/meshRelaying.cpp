#include <algorithm>
#include "meshRelaying.h"
#include "GModel.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MVertex.h"
#include "robustPredicates.h"
#include "qualityMeasures.h"
//#include "libol1.h"

discreteFront *discreteFront::_instance = nullptr;
meshRelaying *meshRelaying::_instance = nullptr;

int ITERR = 0;
int TESTCASE = 2;

//discreteFront::discreteFront (std::vector<double> &p, std::vector<size_t> &l, std::vector<int> &c, double _t){
//  addLines(p,l,c);
//}

void discreteFront::printGeometry(FILE *f){
  for (size_t i=0 ; i< lines.size() ; i+=2){
    fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	    pos[3*lines[i]],pos[3*lines[i]+1],
	    pos[3*lines[i+1]],pos[3*lines[i+1]+1],-colors[i/2],-colors[i/2]);
  }
}

/// ---> relax a front node
void discreteFront::relaxFrontNode (size_t i, double r){

  int current_color = getColor(fn[0].line);
  std::vector<frontNode> frontColor;
  int _pos = -1;
  size_t posk;
  for (size_t k=0;k<fn.size();k++){
    int color = getColor(fn[k].line);
    if (color == current_color){
      if (fn[k].meshNode == i)  {
	_pos = frontColor.size();
	posk = k;
      }
      frontColor.push_back(fn[k]);
    }
    else {
      if (_pos != -1) break;
      frontColor.clear();
      current_color = color;
    }
  }
 
  size_t posp, posm;

  if (_pos == 0) posm = frontColor.size() - 1;
  else posm = _pos-1;

  if (_pos == frontColor.size() - 1) posp = 0;
  else posp = _pos+1;  
    
  size_t lpos = frontColor[_pos].line;
  size_t lposp = frontColor[posp].line;
  size_t lposm = frontColor[posm].line;

  double qmax_init = 0.0;
  {
    size_t lp = lpos;
    size_t n1 = lines[lp];
    size_t n2 = lines[lp+1];
    SVector3 pa (pos[3*n1],pos[3*n1+1],pos[3*n1+2]);
    SVector3 pb (pos[3*n2],pos[3*n2+1],pos[3*n2+2]);
    SVector3 newPos = pa + (pb-pa)*fn[posk].t;
    qmax_init = meshRelaying::instance()->smallest_quality_measure (i,newPos);
  }

  double qmax = qmax_init;
  
  size_t lp = lposm;
  size_t n1 = lines[lp];
  size_t n2 = lines[lp+1];
  SVector3 pa (pos[3*n1],pos[3*n1+1],pos[3*n1+2]);
  SVector3 pb (pos[3*n2],pos[3*n2+1],pos[3*n2+2]);
  double L = (pb-pa).norm();
  double CURR=0.0;

  const int nsamples = 10;
  double samples[10] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
  
  size_t lpmax;
  double tmax;
  SVector3 posmax;
  
  while (1){
    lp = (lp + 2)%lines.size();
    size_t n1 = lines[lp];
    size_t n2 = lines[lp+1];
    pa = SVector3(pos[3*n1],pos[3*n1+1],pos[3*n1+2]);
    pb = SVector3(pos[3*n2],pos[3*n2+1],pos[3*n2+2]);
    
    for (size_t j=0;j<nsamples;j++){
      SVector3 newPos = pa + (pb-pa)*samples[j];
      double q = meshRelaying::instance()->smallest_quality_measure (i,newPos);
      if (q > qmax){
	qmax = q;
	lpmax = lp;
	tmax = samples[j];
	posmax = newPos;
      }
    }
    L+= (pb-pa).norm();
    if (lp == lpos){
      SVector3 kk = pa + (pb-pa)*fn[posk].t;
      CURR = L + (kk-pa).norm();
    }
    if (lp == lposp)break;
  }
  
  if (qmax > qmax_init){
    fn[posk].line = lpmax;
    fn[posk].t = tmax;
    meshRelaying::instance()->setPos (i, posmax.x(), posmax.y(), posmax.z());
    return;
  }
  return;

  double HALF = CURR + (L/2-CURR)*r;

  lp = lposm;
  pa = SVector3 (pos[3*lp],pos[3*lp+1],pos[3*lp+2]);
  pb = SVector3 (pos[3*(lp+1)],pos[3*(lp+1)+1],pos[3*(lp+1)+2]);
  L = (pb-pa).norm();
  while (1){
    lp = (lp + 2)%lines.size();
    size_t n1 = lines[lp];
    size_t n2 = lines[lp+1];
    pa = SVector3(pos[3*n1],pos[3*n1+1],pos[3*n1+2]);
    pb = SVector3(pos[3*n2],pos[3*n2+1],pos[3*n2+2]);
    double dL = (pb-pa).norm();
    if (L +dL > HALF){
      double t = HALF/(L+dL);
      SVector3 newPos = pa + (pb-pa)*t;
      if (meshRelaying::instance()->smallest_measure (i,newPos) >= 0){
	fn[posk].line = lp;
	fn[posk].t = t;
	meshRelaying::instance()->setPos (i, newPos.x(), newPos.y(), newPos.z());
	return;
      }
    }
    L+= dL;
    if (lp == lposp)break;
  }
}

//double discreteFront::mass (int color){
//}

double discreteFront::massMarkers (int color){
  double mass = 0.0;
  for (size_t i=0 ; i< lines.size() ; i+=2){
    if (colors[i/2] == color){
      SVector3 A(pos[3*lines[i]],pos[3*lines[i]+1],0);
      SVector3 B(pos[3*lines[i+1]],pos[3*lines[i+1]+1],0);
      SVector3 AB = B-A;
      SVector3 Z (0,0,1);
      SVector3 n = crossprod(AB,Z);
      SVector3 mid = (B+A)*0.5;
      mass += 0.5* (mid.x()*n.x()+mid.y()*n.y());      
    }
  }
  return mass;
}

double meshRelaying::massTriangles (int color){

  double mass = 0.0;
  for (size_t i=0;i<tris.size();i+=3){
    SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
		 (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
		 0);
    if (discreteFront::instance()->whatIsTheColorOf2d(COG) == color){
      double aa[2] = {pos[3*tris[i]],pos[3*tris[i]+1]}; 
      double bb[2] = {pos[3*tris[i+1]],pos[3*tris[i+1]+1]}; 
      double cc[2] = {pos[3*tris[i+2]],pos[3*tris[i+2]+1]};
      double area = robustPredicates::orient2d(aa,bb,cc);
      mass += area;
    }
  }
  return mass;
}


int discreteFront::whatIsTheColorOf2d (const SVector3 &P){
  // compute winding number -- fast
  std::set<int> cs;
  std::vector<int> cols;
  double pp[2] = {P.x(),P.y()};
  for (auto c : colors){
    if (cs.find(c) == cs.end()){
      cs.insert(c);
      int wn = 0;
      for (size_t i=0 ; i< lines.size() ; i+=2){
	if (colors[i/2] == c){
	  double aa[2] = {pos[3*lines[i]],pos[3*lines[i]+1]};
	  double bb[2] = {pos[3*lines[i+1]],pos[3*lines[i+1]+1]};
	  double area = robustPredicates::orient2d(aa,bb,pp); 
	  if(aa[1]<= P.y()){
	    if (bb[1] > P.y() && area < 0)wn++;
	  }
	  else if(bb[1]<= P.y()){
	    if (area > 0)wn--;
	  }
	}
      }
      if (wn != 0)cols.push_back(c);
    }
  }
  if (cols.empty())return -1;
  if (cols.size() == 1)return cols[0];
  if (cols.size() == 2){
    return -10*std::max(cols[0],cols[1]) - std::min(cols[0],cols[1]);
  }
  return cols[0];
}

int discreteFront::whatIsTheColorOf2dSlow (const SVector3 &P){

  std::set<int> cs;
  std::vector<int> cols;
  for (auto c : colors){
    if (cs.find(c) == cs.end()){
      cs.insert(c);
      double angTot = 0.0;
      for (size_t i=0 ; i< lines.size() ; i+=2){
	if (colors[i/2] == c){
	  SVector3 A(pos[3*lines[i]],pos[3*lines[i]+1],0);
	  SVector3 B(pos[3*lines[i+1]],pos[3*lines[i+1]+1],0);
	  SVector3 PA = A-P;
	  SVector3 PB = B-P;
	  SVector3 pv = crossprod(PB,PA);
	  double a = atan2(pv.z(),dot(PA,PB));
	  angTot += a;
	}
      }
      if (fabs(angTot) > M_PI*1.99)cols.push_back(c);
    }
  }
  if (cols.empty())return -1;
  if (cols.size() == 1)return cols[0];
  if (cols.size() == 2){
    return -10*std::max(cols[0],cols[1]) - std::min(cols[0],cols[1]);
  }
  return cols[0];
}

void discreteFront::cornersInTriangle2d (const SVector3 &p0, const SVector3 &p1, const SVector3 &p2,
					 std::vector<SVector3> &c, std::vector<int> &col){
  SPoint2 a0(p0.x(),p0.y());
  SPoint2 a1(p1.x(),p1.y());
  SPoint2 a2(p2.x(),p2.y());
  for (auto i : corners){
    SPoint2 p(pos[3*i],pos[3*i+1]);
    SVector3 p3(pos[3*i],pos[3*i+1],0);
    double d = std::min(std::min((p0-p3).norm(),(p1-p3).norm()),(p2-p3).norm());
    if (d < 1.e-12)continue ; // FIXME
    double a01p = robustPredicates::orient2d(a0,a1,p);
    double a12p = robustPredicates::orient2d(a1,a2,p);
    double a20p = robustPredicates::orient2d(a2,a0,p);

    if (a01p*a12p >=0 && a01p*a20p >=0 && a20p*a12p >=0){
      for (size_t j =0; j< lines.size() ; j+=2 ){
	if (lines[j] == i){
	  col.push_back(j);
	  break;
	}
      }
      c.push_back(SVector3(pos[3*i],pos[3*i+1],0));      
    }
  }
}

void discreteFront::intersectLine2d (const SVector3 &p0, const SVector3 &p1,
				     std::vector<double> &d,
				     std::vector<int> &c){
  SPoint2 a1(p0.x(),p0.y());
  SPoint2 a2(p1.x(),p1.y());

  double xmin = std::min(p0.x(),p1.x());
  double xmax = std::max(p0.x(),p1.x());
  double ymin = std::min(p0.y(),p1.y());
  double ymax = std::max(p0.y(),p1.y());

  
  if (xmin < bbox.min().x())return;
  if (xmax > bbox.max().x())return;
  if (ymin < bbox.min().y())return;
  if (ymax > bbox.max().y())return;
  
  std::vector<size_t> _ind;
  int IMIN,IMAX,JMIN,JMAX;
  getCoordinates(xmin,ymin,IMIN,JMIN);
  getCoordinates(xmax,ymax,IMAX,JMAX);
  for (int I=IMIN; I<=IMAX;I++){
    for (int J=JMIN; J<=JMAX;J++){
      int index = I+NX*J;
      _ind.insert(_ind.begin(),sss[index].begin(),sss[index].end());
    }
  }
  std::sort(_ind.begin(), _ind.end());
  auto last = std::unique (_ind.begin(), _ind.end());
  _ind.erase(last,_ind.end());

  for (size_t I=0 ; I< _ind.size() ; I++){
    size_t i = _ind[I];
    //    printf("%lu\n",i);
    double a3[2]= {pos[3*lines[i]],pos[3*lines[i]+1]};
    double a4[2]= {pos[3*lines[i+1]],pos[3*lines[i+1]+1]};
    
    double xminb = std::min(a3[0],a4[0]);
    double xmaxb = std::max(a3[0],a4[0]);
    double yminb = std::min(a3[1],a4[1]);
    double ymaxb = std::max(a3[1],a4[1]);
    if  (ymaxb < ymin)continue;
    if  (xmaxb < xmin)continue;
    if  (xminb > xmax)continue;    
    if  (yminb > ymax)continue;
    
    double a143 = robustPredicates::orient2d(a1,a4,a3);
    double a243 = robustPredicates::orient2d(a2,a4,a3);    

    if (a143*a243 > 0) continue;
    double a123 = robustPredicates::orient2d(a1,a2,a3);
    double a124 = robustPredicates::orient2d(a1,a2,a4);

    if (a123*a124 > 0) continue;
    d.push_back(a143/(a143-a243));
    c.push_back(i);
  }
}

void discreteFront::getCoordinates(double x, double y, int &IX, int &IY){
  IX = (NX-1)*(x-bbox.min().x())/(bbox.max().x()-bbox.min().x());
  IY = (NY-1)*(y-bbox.min().y())/(bbox.max().y()-bbox.min().y());    
}

void discreteFront::buildSpatialSearchStructure () {    
  if(empty())return;
  for (size_t i=0;i<pos.size();i+=3)
    bbox += SPoint3(pos[i],pos[i+1],pos[i+2]);    
  NX = 300;
  NY = 300;
  sss.clear();
  sss.resize(NX*NY);
  for (size_t i = 0; i< lines.size() ; i+=2){
    int IX,IY,JX,JY;
    getCoordinates(pos[3*lines[i]],pos[3*lines[i]+1], IX, IY);
    getCoordinates(pos[3*lines[i+1]],pos[3*lines[i+1]+1], JX, JY);
    for (size_t I=std::min(IX,JX);I<=std::max(IX,JX);I++){
      for (size_t J=std::min(IY,JY);J<=std::max(IY,JY);J++){
	sss[I+J*NX].push_back(i);
      }
    }
  }
  return;
}

SVector3 discreteFront::velocity (double x, double y, double z, double t, int col){
  // doublet
  if (TESTCASE == 12){
    //    double x1 = 0.5, y1=0.5;
    if (col == 0) return SVector3(0,0,0);
    double x2 = 1.5, y2=0.5;
    //    double r1 = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    double r2 = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
    double theta_2 = atan2(y-y2,x-x2);
    double U = 1.0;
    double R = 0.6;
    //    if (r2 <= R) return SVector3(0,0,0);
    double ur = U*cos(theta_2)*(1.-R*R/(r2*r2));
    double ut = -U*sin(theta_2)*(1.+R*R/(r2*r2));
    double ux = ur*cos(theta_2)-ut*sin(theta_2);
    double uy = ur*sin(theta_2)+ut*cos(theta_2);
    return SVector3(ux,uy,0);
    //    double Gamma = 1;
    //    double theta_1 = atan2(y-y1,x-x1);
    //    double theta_2 = atan2(y-y2,x-x2);
    // SVector3 v1  ((Gamma/(2*M_PI))*sin(theta_1)/r1,
    // 		  (-Gamma/(2*M_PI))*cos(theta_1)/r1,0);
    // SVector3 v2  ((-Gamma/(2*M_PI))*sin(theta_2)/r2,
    // 		  (Gamma/(2*M_PI))*cos(theta_2)/r2,0);
    //    SVector3 v1  ((Gamma/(2*M_PI))*cos(theta_1)/r1,
    //		  (Gamma/(2*M_PI))*sin(theta_1)/r1,0);
    //    SVector3 v2  ((Gamma/(2*M_PI))*cos(theta_2)/r2,
    //		  (Gamma/(2*M_PI))*sin(theta_2)/r2,0);
    // return v1+v2;
  }
  if (TESTCASE == 11){
    double r = col == 1 ? sqrt(x*x+y*y) : sqrt((x-.3)*(x-.3)+y*y);
    double theta = col == 1 ? atan2(y,x) : atan2(y,x-.3);    
    return col == 1 ? SVector3(-r*sin(theta),r*cos(theta),0) : SVector3(r*sin(theta),-r*cos(theta),0);
  }
  if (TESTCASE == 1){
    if (col == 1)return SVector3(cos (M_PI*t),0,0);
    if (col == 2)return SVector3(-cos (M_PI*t),0,0);
    if (col == 3)return SVector3(0,0,0);
  }
  double vx = sin(2*M_PI*y)*sin(M_PI*x)*sin(M_PI*x);
  double vy = -sin(2*M_PI*x)*sin(M_PI*y)*sin(M_PI*y);
  double TT = 1;//cos (M_PI*t/8.0);
  return SVector3(vx*TT,vy*TT,0.0);
}

void discreteFront::move (double dt){
  std::map<size_t,int> cols;
  for (size_t i=0;i<lines.size();i+=2){
    cols[lines[i]] = colors[i/2];
    cols[lines[i+1]] = colors[i/2];
  }
  
  for (size_t i=0;i<pos.size();i+=3){
    double x = pos[i];
    double y = pos[i+1];
    double z = pos[i+2];
    SVector3 v = velocity(x,y,z,t,cols[i/3]);
    x += 0.5*v.x()*dt;
    y += 0.5*v.y()*dt;
    z += 0.5*v.z()*dt;
    v = velocity(x,y,z,t+dt*.5,cols[i/3]);
    pos[i] += v.x()*dt;
    pos[i+1] += v.y()*dt;
    pos[i+2] += v.z()*dt;
  }
  t+=dt;
}

SVector3 discreteFront::closestPoints2d (const SVector3 &P){
  double dmin = 1.e22;
  SVector3 res;
  for (size_t i=0 ; i< lines.size() ; i+=2){
    SVector3 A (pos[3*lines[i]],pos[3*lines[i]+1],pos[3*lines[i]+2]);
    SVector3 B (pos[3*lines[i+1]],pos[3*lines[i+1]+1],pos[3*lines[i+1]+2]);
    if (dim() == 2){
      SVector3 AB = B - A;
      double lAB = AB.norm();
      AB.normalize();
      SVector3 AP = P - A;
      double L = dot(AP,AB);
      SVector3 H;
      if (L < 0)H = A;
      else if (L > lAB)H = B;
      else H = A + AB * L;
      SVector3 HP = P - H;
      double d = HP.norm();
      if (d < dmin){
	dmin = d;
	res = H;
      }
    }
  }
  return res;
}

void discreteFront::addRectangle (int tag, double x0, double y0, double r1, double r2, int n){
  std::vector<double> p;
  std::vector<size_t> l;
  std::vector<int> c;
  double dX[4] = {r1,0,-r1,0};
  double dY[4] = {0,r2,0,-r2};
  double x = x0-r1/2, y=y0-r2/2;
  double dx = r1/n;
  double dy = r2/n;
  for (int k=0;k<4;k++){
    for (int i=0;i<n;i++){
      c.push_back(tag);
      l.push_back(k*n+i);
      l.push_back((k*n+i+1)%(4*n));
      p.push_back(x);
      p.push_back(y);
      p.push_back(0.);
      x += dx * dX[k];
      y += dy * dY[k];
    }
  }
  addLines (p,l,c);
}

void discreteFront::addPolygon (int tag, const std::vector<SVector3> &poly, int n){
  for (size_t k=0;k<poly.size();k++){
    std::vector<double> p;
    std::vector<size_t> l;
    std::vector<int> c;
    SVector3 p0 = poly[k];
    SVector3 p1 = poly[(k+1)%poly.size()];
    for (int i=0;i<n;i++){
      c.push_back(tag);
      l.push_back(i);
      l.push_back((i+1)%n);
      double t = (double) i/(n-1);
      double x = p0.x() + (p1.x()-p0.x())*t;
      double y = p0.y() + (p1.y()-p0.y())*t;
      p.push_back(x);
      p.push_back(y);
      p.push_back(0.);
      addLines (p,l,c);
    }
  }  
}

void discreteFront::addEllipsis (int tag, double x0, double y0, double theta0, double r1, double r2, int n){
  std::vector<double> p;
  std::vector<size_t> l;
  std::vector<int> c;
  for (int i=0;i<n;i++){
    c.push_back(tag);
    l.push_back(i);
    l.push_back((i+1)%n);
    double theta = theta0+2.*(double)i*M_PI/n;
    p.push_back(x0 + r1*cos(theta));
    p.push_back(y0 + r2*sin(theta));
    p.push_back(0.);
  }
  addLines (p,l,c);
}

void discreteFront::boolOp (){
  // this stuff is just about finding corners
  corners.clear();
  // corners are where angles are above a certain threshold 
  std::vector<std::vector<size_t> > _lls;
  std::vector<size_t> _ll;

  for (size_t i=0;i<lines.size();i+=2){
    _ll.push_back(lines[i]);
    _ll.push_back(lines[i+1]);
    if (lines[(i+2)%lines.size()] != lines[i+1]){
      _lls.push_back(_ll);
      _ll.clear();
    }
  }
  if (_ll.size()) _lls.push_back(_ll);
  for (size_t k=0;k<_lls.size();k++){
    for (size_t i=0;i<_lls[k].size();i+=2){
      double a1[2] = {pos[3*_lls[k][i]],pos[3*_lls[k][i]+1]};
      double a2[2] = {pos[3*_lls[k][i+1]],pos[3*_lls[k][i+1]+1]};
      double a3[2] = {pos[3*_lls[k][(i+3)%_lls[k].size()]],
		      pos[3*_lls[k][(i+3)%_lls[k].size()]+1]};
      SVector3 v1 (a2[0]-a1[0],a2[1]-a1[1],0);
      SVector3 v2 (a3[0]-a2[0],a3[1]-a2[1],0);
      v1.normalize();
      v2.normalize();
      double c = dot(v1,v2);
      if (c < sqrt(3)/2){
	corners.push_back(_lls[k][i+1]);
      }
    }
  }
  
  //  printf("%lu cornres %lu\n",corners.size(),_lls.size());
  
  std::map<size_t, std::vector<size_t> > cuts;
  for (size_t i=0;i<lines.size();i+=2){
    double a1[2] = {pos[3*lines[i]],pos[3*lines[i]+1]};
    double a2[2] = {pos[3*lines[i+1]],pos[3*lines[i+1]+1]};
    int IMIN,IMAX,JMIN,JMAX;
    getCoordinates(std::min(a1[0],a2[0]),std::min(a1[1],a2[1]),IMIN,JMIN);
    getCoordinates(std::max(a1[0],a2[0]),std::max(a1[1],a2[1]),IMAX,JMAX);
    std::set<size_t> touched;
    for (size_t I=IMIN; I<=IMAX;I++){
      for (size_t J=JMIN; J<=JMAX;J++){
	size_t index = I+NX*J;
	for (auto j : sss [index]){
	  if (touched.find(j) != touched.end())continue;
	  touched.insert(j);
	  if (i < j){ // only compute once intersections
	    double a3[2] = {pos[3*lines[j]],pos[3*lines[j]+1]};
	    double a4[2] = {pos[3*lines[j+1]],pos[3*lines[j+1]+1]};
	    double a143 = robustPredicates::orient2d(a1,a4,a3);
	    double a243 = robustPredicates::orient2d(a2,a4,a3);    
	    double a123 = robustPredicates::orient2d(a1,a2,a3);
	    double a124 = robustPredicates::orient2d(a1,a2,a4);
	    if (a143*a243 < 0 && a123*a124 < 0){
	      double t = a143/(a143-a243);
	      size_t n = pos.size()/3;
	      cuts[i].push_back(n);
	      cuts[j].push_back(n);
	      corners.push_back(n);
	      //	      printf("corner %lu %lu %lu %12.5E %12.5E\n",i,j,n,a1[0]+(a2[0]-a1[0])*t,a1[1]+(a2[1]-a1[1])*t);
	      pos.push_back(a1[0]+(a2[0]-a1[0])*t);
	      pos.push_back(a1[1]+(a2[1]-a1[1])*t);
	      pos.push_back(0.0);
	    }
	  }
	}
      }
    }
  }
  return;
  std::vector<size_t> l;
  std::vector<int> c;
  for (size_t i=0;i<lines.size();i+=2){
    auto it = cuts.find(i);
    if (it == cuts.end()){
      l.push_back(lines[i]);
      l.push_back(lines[i+1]);
      c.push_back(colors[i/2]);
    }
    else {
      l.push_back(lines[i]);
      c.push_back(colors[i/2]);
      for (auto j : it->second){
	l.push_back(j);
	l.push_back(j);	
	c.push_back(colors[i/2]);
      }
      l.push_back(lines[i+1]);
    }
  }
  lines = l;
  colors = c;
}

void discreteFront :: printMesh (FILE *f) {
  std::sort(fn.begin(), fn.end());
  std::vector<SVector3> pp;
  int current_color = getColor(fn[0].line);
  for (size_t i=0;i<fn.size();i++){
    const frontNode &n = fn[i];
    //    printf("front node %lu %lu %g\n",n.meshNode,n.line,n.t);
    size_t l = n.line;
    int color = getColor(l);
    SVector3 p0 (pos[3*lines[l]],pos[3*lines[l]+1],pos[3*lines[l]+2]);
    SVector3 p1 (pos[3*lines[l+1]],pos[3*lines[l+1]+1],pos[3*lines[l+1]+2]);
    SVector3 p = p0+(p1-p0)*n.t;
    fprintf(f,"SP(%g,%g,%g){%d};\n",p.x(),p.y(),p.z(),current_color);
    if (current_color != color){
      for (size_t j=0;j<pp.size();j++){
	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",
		pp[j].x(),pp[j].y(),pp[j].z(),
		pp[(j+1)%pp.size()].x(),pp[(j+1)%pp.size()].y(),pp[(j+1)%pp.size()].z(),
		current_color,current_color);	
      }
      pp.clear();
      current_color = color;
    }
    pp.push_back(p);
  }
  for (size_t i=0;i<pp.size();i++){
    fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",
	    pp[i].x(),pp[i].y(),pp[i].z(),
	    pp[(i+1)%pp.size()].x(),pp[(i+1)%pp.size()].y(),pp[(i+1)%pp.size()].z(),
	    current_color,current_color);	
  }  
}

std::vector<std::pair<size_t,size_t> > discreteFront :: getFrontEdges() {
  std::sort(fn.begin(), fn.end());
  std::vector<std::pair<size_t,size_t> > pp;
  std::vector<size_t>  curr;
  int current_color = getColor(fn[0].line);
  for (size_t i=0;i<fn.size();i++){
    const frontNode &n = fn[i];
    size_t l = n.line;
    int color = getColor(l);
    if (current_color != color){
      for (size_t j=0;j<curr.size();j++){
	size_t A = curr[j];
	size_t B = curr[(j+1)%curr.size()];
	std::pair<size_t,size_t> pa = std::make_pair(std::min(A,B), std::max(A,B));
	pp.push_back(pa);
      }
      curr.clear();
      current_color = color;
    }
    curr.push_back(n.meshNode);
  }
  for (size_t j=0;j<curr.size();j++){
    size_t A = curr[j];
    size_t B = curr[(j+1)%curr.size()];
    if (A == B){
      Msg::Warning("should not happen line %d file %s",__LINE__,__FILE__);
      continue;
    }
    std::pair<size_t,size_t> pa = std::make_pair(std::min(A,B), std::max(A,B));
    pp.push_back(pa);
  }
  return pp;
}



// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------


double ll (double x, double y, double z, double t){
  //  return x+t;
  return (x-.05)*(x-.05)+.3*y*y+z*z-0.25*sin(t*M_PI)*sin(t*M_PI);
}


void testRelaying() {
  if (TESTCASE == 0){
    discreteFront::instance()->addEllipsis(1,-0.6,0.4,M_PI/8,0.25,0.5,300);
    discreteFront::instance()->addRectangle(3,0,0.5,.7172,.7172,10);
    discreteFront::instance()->addEllipsis(2,0.6,0.25,0,0.35,0.25,300);
    discreteFront::instance()->buildSpatialSearchStructure () ;
    discreteFront::instance()->boolOp();
  }
  if (TESTCASE == 1){
    //    df.addEllipsis(1,-0.6,0.4,M_PI/8,0.25,0.5,300);
    discreteFront::instance()->addPolygon(1,{{-.5,0,0}, {0,0,0}, {0.25,0.25,0}, {0.001,-0.0005,0}, {0.25,-0.25,0}, {0.0,-0.001,0}},10);
    discreteFront::instance()->addEllipsis(2,0.,0.,0,0.35,0.35,300);
    discreteFront::instance()->buildSpatialSearchStructure () ;
    discreteFront::instance()->boolOp();
  }
  else if (TESTCASE == 11){
    discreteFront::instance()->addRectangle(1,0,0,.7172,.7172,10);
    discreteFront::instance()->addRectangle(2,0.3,0,.7,.7,10);
    discreteFront::instance()->buildSpatialSearchStructure () ;
    discreteFront::instance()->boolOp();
  }
  else if (TESTCASE == 12){
    discreteFront::instance()->addEllipsis(1,-2.,0.5,0,0.8,0.8,1000);
    //    df.addEllipsis(0,1.5,0.5,0,0.6,0.6,1000);
  }
  else if (TESTCASE == 2){
    //    df.addRectangle(1,0.5,0.75,0.3,0.003,200);
    discreteFront::instance()->addEllipsis(1,0.5,0.75,0,0.15,0.15,10000);
    //    df.addEllipsis(2,0.5,0.25,0,0.15,0.15,1000);
    //    df.addEllipsis(3,0.25,0.5,0,0.15,0.15,1000);
  }
  else if (TESTCASE == 3){
    discreteFront::instance()->addEllipsis(1, 0.5, 0.75, 0, 0.15,0.15,200);
    discreteFront::instance()->addEllipsis(2, 0.37, 0.75, 0, 0.15,0.15,200);
    discreteFront::instance()->buildSpatialSearchStructure () ;
    discreteFront::instance()->boolOp();
  }

  meshRelaying::instance()->setLevelset (ll);
  meshRelaying::instance()->setDiscreteFrontBBox();
  double t = 0.0;
  double massInit = discreteFront::instance()->massMarkers(1);
  for (size_t i=0;i<1200;i++){
    double massM = discreteFront::instance()->massMarkers(1);
    double massT = meshRelaying::instance()->massTriangles(1);
    printf("ITER %8d time %12.5E MASS = %12.5E/%12.5E (ERR %12.10lf) MassT = %12.5E\n",ITERR,t,
	   massM,massInit,(massM-massInit)/massInit, massT);
    meshRelaying::instance()->doRelaying (t);
    if(ITERR%1==0){
      char name [245];
      sprintf(name, "test%lu.pos",i);
      meshRelaying::instance()->print4debug (name);
    }
    meshRelaying::instance()->advanceInTime(0.025);
    if (t > 16)break;
    t+= 0.025;
    ITERR++;
  }
}


//------------------------------------------------
// ---           Constructor                   ---
// ---  Create datastructures in 2D and 3D     ---
//------------------------------------------------

meshRelaying::meshRelaying(GModel *gm){
  
  if (!gm)gm=GModel::current();

  std::set <MVertex*, MVertexPtrLessThan> vs; 

  // Get all vertices.
  for (auto eit = gm->firstEdge() ; eit != gm->lastEdge() ; ++eit){
    for (auto e : (*eit)->lines){
      for (size_t i=0;i<2;i++)vs.insert(e->getVertex(i));
    }
  }
  for (auto fit = gm->firstFace() ; fit != gm->lastFace() ; ++fit){
    for (auto t : (*fit)->triangles){
      for (size_t i=0;i<3;i++)vs.insert(t->getVertex(i));
    }
  }
  for (auto git = gm->firstRegion() ; git != gm->lastRegion() ; ++git){
    for (auto t : (*git)->tetrahedra){
      for (size_t i=0;i<4;i++)vs.insert(t->getVertex(i));
    }    
  }

  // Store positions
  size_t counter = 0;
  for (auto v : vs){
    v->setIndex(counter++);
    pos.push_back(v->x());
    pos.push_back(v->y());
    pos.push_back(v->z());
    dimVertex.push_back(v->onWhat()->dim());
  }

  v2v.resize(counter);
  v2tet.resize(counter);
  v2tri.resize(counter);
  v2edg.resize(counter);
  
  size_t tetCount = 0;
  for (auto git = gm->firstRegion() ; git != gm->lastRegion() ; ++git){
    for (auto t : (*git)->tetrahedra){
      for (size_t i=0;i<6;i++){
	MEdge e = t->getEdge(i);
	v2v[e.getVertex(0)->getIndex()].push_back(e.getVertex(1)->getIndex());
	v2v[e.getVertex(1)->getIndex()].push_back(e.getVertex(0)->getIndex());
      }
      for (size_t i=0;i<4;i++){
	tets.push_back(t->getVertex(i)->getIndex());
	v2tet[t->getVertex(i)->getIndex()].push_back(tetCount);
      }
      tetCount++;
    }    
  }
  
  size_t triCount = 0;
  for (auto fit = gm->firstFace() ; fit != gm->lastFace() ; ++fit){
    for (auto t : (*fit)->triangles){
      for (size_t i=0;i<3;i++){
	MEdge e = t->getEdge(i);
	v2v[e.getVertex(0)->getIndex()].push_back(e.getVertex(1)->getIndex());
	v2v[e.getVertex(1)->getIndex()].push_back(e.getVertex(0)->getIndex());
	if (tetCount){
	  std::pair<size_t,size_t> p =
	    std::make_pair(std::min(e.getVertex(0)->getIndex(),e.getVertex(1)->getIndex()),
			   std::max(e.getVertex(0)->getIndex(),e.getVertex(1)->getIndex()));
	  bnd2d.push_back(p);
	}	
      }
      for (size_t i=0;i<3;i++){
	tris.push_back(t->getVertex(i)->getIndex());
	v2tri[t->getVertex(i)->getIndex()].push_back(triCount);
      }
      triCount++;
    }
  }

  size_t edgCount = 0;
  for (auto eit = gm->firstEdge() ; eit != gm->lastEdge() ; ++eit){
    for (auto e : (*eit)->lines){
      if (triCount){
	std::pair<size_t,size_t> p =
	  std::make_pair(std::min(e->getVertex(0)->getIndex(),e->getVertex(1)->getIndex()),
			 std::max(e->getVertex(0)->getIndex(),e->getVertex(1)->getIndex()));
	bnd1d.push_back(p);
      }	
      for (size_t i=0;i<2;i++){
	edgs.push_back(e->getVertex(i)->getIndex());
	v2edg[e->getVertex(i)->getIndex()].push_back(edgCount);
      }
      edgCount++;
    }
  }

  {
    std::sort(bnd2d.begin(), bnd2d.end());
    auto last = std::unique (bnd2d.begin(), bnd2d.end());
    bnd2d.erase(last,bnd2d.end());
  }
  {
    std::sort(bnd1d.begin(), bnd1d.end());
    auto last = std::unique (bnd1d.begin(), bnd1d.end());
    bnd1d.erase(last,bnd1d.end());
  }
  {
    size_t count = 0;
    for (auto v : v2v){
      std::sort(v.begin(), v.end());
      auto last = std::unique (v.begin(), v.end());
      v.erase(last,v.end());
      v2v[count++] = v;
    }
  }
  initial_pos = pos;
}

//------------------------------------------------
// ---            doRelaying                   ---
// ---  Assume a levelset has been provided    ---
//------------------------------------------------

void meshRelaying::doRelaying (double t){
  time = t;
  auto f_levelset = [this] (size_t i, size_t j) -> std::vector<std::pair<double,int > > {
    double x0 = pos [3*i];
    double y0 = pos [3*i+1];
    double z0 = pos [3*i+2];
    double x1 = pos [3*j];
    double y1 = pos [3*j+1];
    double z1 = pos [3*j+2];
    double l0 = levelset(x0,y0,z0,time);
    double l1 = levelset(x1,y1,z1,time);
    double t = -1;
    std::vector<std::pair<double,int > > ds;
    if (l0 * l1 < 0){
      t = l0/(l0-l1);
      std::pair<double,int > d = std::make_pair(t,1);
      ds.push_back(d);
    }
    return ds;    
  };

  auto f_discrete = [this] (size_t i, size_t j) -> std::vector<std::pair<double,int > > {
    SVector3 p0(pos [3*i],pos [3*i+1],pos [3*i+2]);
    SVector3 p1(pos [3*j],pos [3*j+1],pos [3*j+2]);   
    
    std::vector<double> d;
    std::vector<int> c;

    discreteFront::instance()->intersectLine2d (p0, p1,d,c);
    std::vector<std::pair<double,int > > ds;
    for (size_t i=0;i<d.size();i++){
      std::pair<double,int > p = std::make_pair(d[i],c[i]);
      ds.push_back(p);
    }
    std::sort(ds.begin(),ds.end());
    return ds;
  };
  if (discreteFront::instance()->empty())
    doRelaying(f_levelset);
  else{
    pos = initial_pos;
    doRelaying(f_discrete);
  }
}


double meshRelaying::smallest_measure (const size_t n, 
				    const SVector3 &t){
  
  double volume = 1.e22;
  if (tets.size()){
    for (auto tri : v2tet[n]) {
      size_t n0 = tets[4*tri];
      size_t n1 = tets[4*tri+1];
      size_t n2 = tets[4*tri+2];
      size_t n3 = tets[4*tri+3];
      double x0 = n0 == n ? t.x() : pos [3*n0];
      double y0 = n0 == n ? t.y() : pos [3*n0+1];
      double z0 = n0 == n ? t.z() : pos [3*n0+2];
      double x1 = n1 == n ? t.x() : pos [3*n1];
      double y1 = n1 == n ? t.y() : pos [3*n1+1];
      double z1 = n1 == n ? t.z() : pos [3*n1+2];
      double x2 = n2 == n ? t.x() : pos [3*n2];
      double y2 = n2 == n ? t.y() : pos [3*n2+1];
      double z2 = n2 == n ? t.z() : pos [3*n2+2];
      double x3 = n3 == n ? t.x() : pos [3*n3];
      double y3 = n3 == n ? t.y() : pos [3*n3+1];
      double z3 = n3 == n ? t.z() : pos [3*n3+2];
      double p0[3]={x0,y0,z0};
      double p1[3]={x1,y1,z1};
      double p2[3]={x2,y2,z2};
      double p3[3]={x3,y3,z3};
      double v = robustPredicates::orient3d(p0,p1,p2,p3);
      volume = std::min(v,volume);
    }
  }
  else if (tris.size()){
    for (auto tri : v2tri[n]) {
      size_t n0 = tris[3*tri];
      size_t n1 = tris[3*tri+1];
      size_t n2 = tris[3*tri+2];
      double x0 = n0 == n ? t.x() : pos [3*n0];
      double y0 = n0 == n ? t.y() : pos [3*n0+1];
      double x1 = n1 == n ? t.x() : pos [3*n1];
      double y1 = n1 == n ? t.y() : pos [3*n1+1];
      double x2 = n2 == n ? t.x() : pos [3*n2];
      double y2 = n2 == n ? t.y() : pos [3*n2+1];
      double p0[2]={x0,y0};
      double p1[2]={x1,y1};
      double p2[2]={x2,y2};
      double v = robustPredicates::orient2d(p0,p1,p2);
      volume = std::min(v,volume);
    }
  }
  return volume;
}

double meshRelaying::smallest_quality_measure (const size_t n, 
					       const SVector3 &t){
  
  double volume = 1.e22;
  if (tets.size()){
  }
  else if (tris.size()){
    for (auto tri : v2tri[n]) {
      size_t n0 = tris[3*tri];
      size_t n1 = tris[3*tri+1];
      size_t n2 = tris[3*tri+2];
      double x0 = n0 == n ? t.x() : pos [3*n0];
      double y0 = n0 == n ? t.y() : pos [3*n0+1];
      double x1 = n1 == n ? t.x() : pos [3*n1];
      double y1 = n1 == n ? t.y() : pos [3*n1+1];
      double x2 = n2 == n ? t.x() : pos [3*n2];
      double y2 = n2 == n ? t.y() : pos [3*n2+1];
      double p0[2]={x0,y0};
      double p1[2]={x1,y1};
      double p2[2]={x2,y2};
      double v = robustPredicates::orient2d(p0,p1,p2);
      double gamma = qmTriangle::gamma(x0,y0,0.0,
				       x1,y1,0.0,
				       x2,y2,0.0);
      if (v < 0)return -1;
      gamma = v > 0 ? gamma : -1.e-22;
      volume = std::min(gamma,volume);
    }
  }
  return volume;
}

void meshRelaying::doRelaying (const std::function<std::vector<std::pair<double,int> >(size_t, size_t)> &f){
  
  front_nodes.clear();
  discreteFront::instance()->clearFrontNodes();
  //Compute all cuts ...
  discreteFront::instance()->buildSpatialSearchStructure ();
  discreteFront::instance()->boolOp();

  int MAXIT = 3;
  int ITTT = 1;
  
  while(1) {

    auto front_edges = discreteFront::instance()->getFrontEdges();
    
    if (ITTT++ == MAXIT)break;
    if (tets.empty()){      
      for (size_t i=0;i<tris.size();i+=3){
	std::vector<SVector3> c;
	std::vector<int> col;
	discreteFront::instance()->cornersInTriangle2d (SVector3(pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2]),
							SVector3(pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2]),
							SVector3(pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2]),
							c,col);
	if (!c.empty()){
	  for (int j=0;j<3;j++){
	    double qMin = smallest_measure (tris[i+j],c[0]);
	    if (qMin > 0 && std::find(front_nodes.begin(),front_nodes.end(),tris[i+j]) == front_nodes.end()){
	      pos[3*tris[i+j]]   = c[0].x();
	      pos[3*tris[i+j]+1] = c[0].y();
	      front_nodes.push_back(tris[i+j]);
	      discreteFront::instance()->addFrontNode (tris[i+j],col[0],c[0]);
	      corners.push_back(tris[i+j]);
	      break;
	    }
	  }
	}
      }
    }
    std::sort(front_nodes.begin(),front_nodes.end());
    std::sort(corners.begin(),corners.end());
    std::set<std::pair<size_t,size_t> > cuts;
    std::vector<edgeCut> moves;

    for (size_t i = 0; i< v2v.size() ; i++){
      for (auto j : v2v[i]){
	if (i < j){
	  std::pair<size_t,size_t> pa = std::make_pair(i,j);
	  if (std::find(front_edges.begin(), front_edges.end(), pa) != front_edges.end())continue;

	  std::vector<std::pair<double,int> > ds = f (i,j);
	  if (ds.empty())continue;
	  std::pair<size_t,size_t> p = std::make_pair(std::min(i,j),std::max(i,j));
	  cuts.insert(p);
	  
	  size_t indexi = 0; 
	  size_t indexj = ds.size() - 1;

	  const double di = ds[indexi].first;
	  const double dj = ds[indexj].first;
	  const int    ii = ds[indexi].second;
	  const int    ij = ds[indexj].second;
	  int dimEdge = tets.size() ? 3:2;
	  if (std::binary_search(bnd2d.begin(), bnd2d.end(), p))dimEdge = std::min(dimEdge,2);
	  if (std::binary_search(bnd1d.begin(), bnd1d.end(), p))dimEdge = std::min(dimEdge,1);
	  int dimi = dimVertex[i];
	  int dimj = dimVertex[j];
	  SVector3 pi (pos[3*i],pos[3*i+1],pos[3*i+2]); 
	  SVector3 pj (pos[3*j],pos[3*j+1],pos[3*j+2]); 
	  SVector3 pOpti  = pi + (pj-pi)*di;
	  SVector3 pOptj  = pi + (pj-pi)*dj;
	  SVector3 DI = pi-pOpti;
	  SVector3 DJ = pj-pOptj;
	  edgeCut mi(i, j, pOpti, DI.norm(), ii);
	  edgeCut mj(j, i, pOptj, DJ.norm(), ij);

	  // Not perfect ... but workable
	  if (!std::binary_search(front_nodes.begin(),front_nodes.end(),i))
	    if(di>0.0000001 && di<0.999999 && dimi >= dimEdge)moves.push_back(mi);
	  if (!std::binary_search(front_nodes.begin(),front_nodes.end(),j))
	    if(dj>0.0000001 && dj<0.999999 && dimj >= dimEdge)moves.push_back(mj);
	}
      }
    }

    if (moves.empty())break;
    std::sort(moves.begin(), moves.end());

    for (auto c : moves){
      size_t i = c.a;
      size_t j = c.b;
      std::pair<size_t,size_t> p = std::make_pair(std::min(i,j), std::max(i,j));
      if (cuts.find(p) == cuts.end())continue;
      
      SVector3 pOpt = c.p;
      double qMin = smallest_measure (i,pOpt);
      
      if (qMin < 0) continue;
      
      for (auto j : v2v[i]){
	p = std::make_pair(std::min(i,j), std::max(i,j));
	cuts.erase(p);
      }

      front_nodes.push_back(i);
      discreteFront::instance()->addFrontNode (i,c.index,pOpt);
      pos[3*i] = pOpt.x();
      pos[3*i+1] = pOpt.y();
      pos[3*i+2] = pOpt.z();
    }    
    std::sort(front_nodes.begin(),front_nodes.end());
  }

  {
    auto front_edges = discreteFront::instance()->getFrontEdges();
    auto missing_edges = front_edges;
    missing_edges.clear();
    for (auto fe : front_edges){
      bool found = false;
      for (auto j : v2v[fe.first]){
	if (j== fe.second)found = true; 
      }
      if (!found){
	missing_edges.push_back(fe);
      }
    }
    if (!missing_edges.empty()){
      char name[245];
      printf("%lu missing font edges on the mesh :",missing_edges.size());
      sprintf(name,"missing%d.pos",ITERR);
      FILE *fi = fopen(name,"w");
      fprintf(fi,"View \"\"{\n");
      for (auto fe : missing_edges){
	size_t i = fe.first;
	size_t j = fe.second;
	printf("(%lu,%lu)",i,j);
	fprintf(fi,"SL(%g,%g,0,%g,%g,0){%lu,%lu};\n",pos[3*i],pos[3*i+1],pos[3*j],pos[3*j+1],i,j);
      }
      printf("\n");
      fprintf(fi,"};\n");
      fclose(fi);
    }
  }
}
static SVector3 average (const std::vector<size_t> &vs, const std::vector<double> &pos){
  SVector3 a(0,0,0);
  for (auto i : vs){
    SVector3 p(pos[3*i],pos[3*i+1],pos[3*i+2]);
    a += p;
  }
  a *= (1./vs.size());
  return a;
}

void meshRelaying::doRelaxFrontNode (size_t i, const std::vector<size_t> &n, double r,
				     std::vector<std::pair<size_t,size_t> > &fe){

  if (discreteFront::instance()->empty())return;
  if (std::binary_search(corners.begin(),corners.end(),i))return;

  discreteFront::instance()->relaxFrontNode(i,r);
}

void meshRelaying::doRelax (double r){
  auto front_edges = discreteFront::instance()->getFrontEdges();

  //  const int nsamples = 10;
  //  double samples[10] = {0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};

  const int nsamples = 1;
  double samples[nsamples] = {1};
  
  for (size_t i=0;i<v2v.size();i++){
    if (!std::binary_search(front_nodes.begin(), front_nodes.end(),i)){
      continue;
      SVector3 pi (initial_pos[3*i],initial_pos[3*i+1],initial_pos[3*i+2]);
      double qMax = smallest_quality_measure (i,pi);
      if (tets.empty() && dimVertex[i] == 2)pi = average(v2v[i],pos);
      SVector3 pj (pos[3*i],pos[3*i+1],pos[3*i+2]);
      for (size_t j=0;j<nsamples;j++){
	SVector3 p = pj*(1-samples[j]) + pi*samples[j];
	double qMin = smallest_quality_measure (i,p);
	if (qMin > qMax){
	  qMax = qMin;
	  pos[3*i] = p.x();
	  pos[3*i+1] = p.y();
	  pos[3*i+2] = p.z();
	}
      }
    }
    else {
      doRelaxFrontNode (i, v2v[i], r, front_edges);
    }
  }
}

void meshRelaying::print4debug(const char *fn){
  FILE *f = fopen (fn,"w");
  fprintf(f,"View \"Front Geometry\"{\n");
  discreteFront::instance()->printGeometry(f);
  fprintf(f,"};\n");
  fprintf(f,"View \"Front Mesh\"{\n");
  discreteFront::instance()->printMesh(f);
  fprintf(f,"};\n");
  fprintf(f,"View \"Mesh\"{\n");  
  for (size_t i=0;i<tets.size();i+=4){
    fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
	    pos[3*tets[i]],pos[3*tets[i]+1],pos[3*tets[i]+2],
	    pos[3*tets[i+1]],pos[3*tets[i+1]+1],pos[3*tets[i+1]+2],
	    pos[3*tets[i+2]],pos[3*tets[i+2]+1],pos[3*tets[i+2]+2],
	    pos[3*tets[i+3]],pos[3*tets[i+3]+1],pos[3*tets[i+3]+2],
	    ll(pos[3*tets[i]],pos[3*tets[i]+1],pos[3*tets[i]+2],time),
	    ll(pos[3*tets[i+1]],pos[3*tets[i+1]+1],pos[3*tets[i+1]+2],time),
	    ll(pos[3*tets[i+2]],pos[3*tets[i+2]+1],pos[3*tets[i+2]+2],time),  
	    ll(pos[3*tets[i+3]],pos[3*tets[i+3]+1],pos[3*tets[i+3]+2],time));    
  }

  for (size_t i=0;i<tris.size();i+=3){
    SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
		 (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
		 (pos[3*tris[i]+2]+pos[3*tris[i+1]+2]+pos[3*tris[i+2]+2])/3.0);
    int color = 1;
    if (!discreteFront::instance()->empty()){
      color = discreteFront::instance()->whatIsTheColorOf2d(COG);
    }
    
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
	    pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2],
	    pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2],
	    pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2],color,color,color);
  }

  for (size_t i=0;i<front_nodes.size();i++){
    fprintf(f,"SP(%g,%g,%g){3};\n",pos[3*front_nodes[i]],
	    pos[3*front_nodes[i]+1],pos[3*front_nodes[i]+2]);
  }
  

  fprintf(f,"};\n");
  fclose(f);
}

/*
  FOR API
*/


void concentration(std::vector<int> &concentration){
  meshRelaying::instance()->concentration(&concentration);
}

void advanceInTime(double dt, std::vector<SVector3> v){
  meshRelaying::instance()->advanceInTime(dt, v);
}

void addFreeForm(int tag, const std::vector<SVector3> &poly){
   discreteFront::instance()->addFreeForm(tag, poly);
}

void getDFPosition(std::vector<double> &api_position){
  meshRelaying::instance()->getDFPosition(&api_position);
}

void getNodesPosition(std::vector<double> &api_position){
  meshRelaying::instance()->getNodesPosition(&api_position);
}

void initRelaying(){
}

void setDiscreteFront(){
}

void resetDiscreteFront(){
  discreteFront::instance()->clear();
}

void relayingAndRelax(){
  meshRelaying::instance()->print4debug("in_gmsh.pos");
  meshRelaying::instance()->doRelaying(0);      // time not used for df -> 0
  meshRelaying::instance()->print4debug("between_gmsh.pos");
  meshRelaying::instance()->doRelax(1);         // full relax
  meshRelaying::instance()->print4debug("out_gmsh.pos");
}

void redistFront(double lc){
  meshRelaying::instance()->redistFront(lc);
}

void setBndFront(){
  meshRelaying::instance()->setBndFront();
}

void meshRelaying::setBndFront(){
  std::vector<size_t> l;
  std::vector<double> p;
  std::vector<int> c; 

  size_t iter = 0;
  l.push_back(iter);
  iter++;
  c.push_back(-1);
  p.push_back(pos[3*bnd1d[0].first]);
  p.push_back(pos[3*bnd1d[0].first+1]);
  p.push_back(pos[3*bnd1d[0].first+2]);
  size_t current = bnd1d[0].second;
  size_t first = bnd1d[0].first;
  size_t id_current = 0;
  
  while(current!= first){
    l.push_back(iter);
    l.push_back(iter);
    iter++;
    c.push_back(-1);
    p.push_back(pos[3*current]);
    p.push_back(pos[3*current+1]);
    p.push_back(pos[3*current+2]);
    
    for(size_t j=0; j<bnd1d.size(); ++j){
      if(bnd1d[j].first == current && j!=id_current){
        current = bnd1d[j].second;
        id_current = j;
        break;
      } else if(bnd1d[j].second == current && j!=id_current){
        current = bnd1d[j].first;
        id_current = j;
        break;
      }
    }
  }
  l.push_back(l[0]);

  discreteFront::instance()->addLines(p,l,c); 
}

void discreteFront::clear(){
  colors.clear();
  corners.clear();
  lines.clear();
  pos.clear();
}

void meshRelaying::concentration(std::vector<int> *concentration){
  for (size_t i=0;i<tris.size();i+=3){
    SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
		 (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
		 0);
    int color = 1;
    if (!discreteFront::instance()->empty()){
      color = discreteFront::instance()->whatIsTheColorOf2d(COG);
      if(color<0) color = 0;
    }
    (*concentration).push_back(color);
  }
}




void discreteFront::redistFront(double lc){
  double fc_min=0.5; 
  double fc_max=1.5;
  double small_dist = fc_min*lc;
  double large_dist = fc_max*lc;
  std::vector<std::vector<size_t> > _lls;
  std::vector<size_t> _ll;

  std::vector<size_t> l;
  std::vector<int> c;
  std::vector<double> p;

  for (size_t i=0;i<lines.size();i+=2){
    _ll.push_back(lines[i]);
    _ll.push_back(lines[i+1]);
    if (lines[(i+2)%lines.size()] != lines[i+1]){
      _lls.push_back(_ll);
      _ll.clear();
    }
  }
  if(!_ll.empty()){
    _lls.push_back(_ll);
  }
  
  size_t iter = 0;
  for(size_t i=0; i<_lls.size(); ++i){
    int n = _lls[i].size();
    // first marker
    size_t first = iter;
    l.push_back(iter);
    for(int k=0; k<3; ++k){
      p.push_back(pos[3*_lls[i][0]+k]);
    }

    // loop through markers
    for(size_t j=1; j<n; j+=2){
      double dist;
      if(colors[_lls[i][j]]<0){
        dist = lc;
      } else {
        dist = sqrt(pow(pos[3*_lls[i][j]] - p.end()[-3], 2) + pow(pos[3*_lls[i][j]+1] - p.end()[-2], 2)); 
      }
      
      if(dist<small_dist){          // markers too close -> take the middle position
        if(j==n-1){
          c.push_back(colors[_lls[i][j]]);
          l.push_back(first);
        } else {
          double temp;
          for(int k=0; k<3; k++){
            temp = (pos[3*_lls[i][j]+k] + p.end()[-3+k])/2.0;
            p.end()[-3+k] = temp;
          }
        }
      } else if(dist>large_dist){   // markers too far -> add markers
        int n_new = (int) (dist/lc - (fc_max-1.01));
        double temp[3];
        for(int k=0; k<3; k++){
          temp[k] = p.end()[-3+k];
        }
        for(int k=0; k<n_new; ++k){
          double s = (k+1.0)/(n_new+1.0);
          iter++;
          l.push_back(iter);
          l.push_back(iter);
          c.push_back(colors[_lls[i][j]]);
          for(int k=0; k<3; k++){
            p.push_back(s*temp[k]+(1-s)*pos[3*_lls[i][j]+k]);
          }
        }

        c.push_back(colors[_lls[i][j]]);
        if(j!=n-1){
          iter++;
          l.push_back(iter);
          l.push_back(iter);
          for(int k=0; k<3; ++k){
            p.push_back(pos[3*_lls[i][j]+k]);
          }
        } else {
          l.push_back(first);
        }
        
      }else{                        // good distance
        c.push_back(colors[_lls[i][j]]);
        if(j!=n-1){
          iter++;
          l.push_back(iter);
          l.push_back(iter);
          for(int k=0; k<3; ++k){
            p.push_back(pos[3*_lls[i][j]+k]);
          }
        } else {
          l.push_back(first);
        }
      }
    }
    iter++;
  }

  pos.clear(); colors.clear(); lines.clear();
  for(int i=0; i<p.size(); ++i){
    pos.push_back(p[i]);
  }
  for(int i=0; i<c.size(); ++i){
    colors.push_back(c[i]);
  }
  for(int i=0; i<l.size(); ++i){
    lines.push_back(l[i]);
  }
  
}

void discreteFront::addFreeForm (int tag, const std::vector<SVector3> &poly){
  std::vector<double> p;
  std::vector<size_t> l;
  std::vector<int> c;
  for (size_t k=0;k<poly.size();k++){
    SVector3 p0 = poly[k];
    c.push_back(tag);
    l.push_back(k);
    l.push_back((k+1)%poly.size());
    p.push_back(p0.x());
    p.push_back(p0.y());
    p.push_back(0.);
  }  
  addLines(p,l,c);
}

void discreteFront::getDFPosition(std::vector<double> *position){
  for(int i=0; i<pos.size(); ++i){
    position->push_back(pos[i]);
  }
  return;
}


void discreteFront::moveFromV (double dt, std::vector<SVector3> v, bool bnd){
  size_t n = v.size();
  std::vector<double> target(pos);
  std::vector<bool> found(n, false);

  for (size_t i=0;i<n;++i){
    if(colors[i]>=0){
      target[3*i] += v[i].x()*dt;
      target[3*i+1] += v[i].y()*dt;
      target[3*i+2] = 0;
    }
  }
  
  if(bnd) {
    while(1){
      for(size_t i=0; i<n; ++i){
        if(found[i]) continue;
        if(colors[i]<0){
          found[i] = true;
          continue;
        }
        // compute all intersection with bnd
        double a1[2] = {pos[3*i], pos[3*i+1]};
        double a2[2] = {target[3*i], target[3*i+1]}; 
        int IMIN,IMAX,JMIN,JMAX;
        getCoordinates(std::min(a1[0],a2[0]),std::min(a1[1],a2[1]),IMIN,JMIN);
        getCoordinates(std::max(a1[0],a2[0]),std::max(a1[1],a2[1]),IMAX,JMAX);
        std::set<size_t> touched;
        std::vector<std::pair<double, size_t>> intersection;  // vector of [s, j]. s = parametric coord of the movement, index in lines (and sss)
        for (size_t I=IMIN; I<=IMAX;I++){
          for (size_t J=JMIN; J<=JMAX;J++){
            size_t index = I+NX*J;
            for (auto j : sss [index]){
              if(colors[j/2]>0) continue;                     // bnd has a -1 color
              if (touched.find(j) != touched.end())continue;
              touched.insert(j);
              double a3[2] = {pos[3*lines[j]],pos[3*lines[j]+1]};
              double a4[2] = {pos[3*lines[j+1]],pos[3*lines[j+1]+1]};
              double a143 = robustPredicates::orient2d(a1,a4,a3);
              double a243 = robustPredicates::orient2d(a2,a4,a3);    
              double a123 = robustPredicates::orient2d(a1,a2,a3);
              double a124 = robustPredicates::orient2d(a1,a2,a4);
              if (a143*a243 < 0 && a123*a124 < 0){
                double t = a143/(a143-a243);
                intersection.push_back(std::make_pair(t, j));
              }
              if ((a143*a243 == 0 && a123*a124 < 0) || (a143*a243 < 0 && a123*a124 == 0)){
                double t = a143/(a143-a243);
                intersection.push_back(std::make_pair(t, j));
              }
            }
          }
        }
        
        // choose closest intersection or target if none
        if(intersection.empty()){
          found[i] = true;
        } else {
          double t_min = 2;
          size_t id_min;
          for(size_t k=0; k<intersection.size(); ++k){
            if(intersection[k].first<t_min){
              t_min = intersection[k].first;
              id_min = intersection[k].second;
            }
          }
          // continue movement along the edge
          pos[3*i] = a1[0]+(a2[0]-a1[0])*t_min;
          pos[3*i+1] = a1[1]+(a2[1]-a1[1])*t_min;
          double a4[2] = {pos[3*lines[id_min+1]],pos[3*lines[id_min+1]+1]};

          double pt[2] = {target[3*i]-pos[3*i], target[3*i+1]-pos[3*i+1]};
          double pa4[2] = {a4[0]-pos[3*i], a4[1]-pos[3*i+1]};

          double pnewt[2];
          double norm_pa4 = sqrt(pa4[0]*pa4[0] + pa4[1]*pa4[1]);
          double pt_dot_pa4 = pt[0]*pa4[0] + pt[1]*pa4[1];
          pnewt[0] = pt_dot_pa4*pa4[0]/(norm_pa4*norm_pa4);
          pnewt[1] = pt_dot_pa4*pa4[1]/(norm_pa4*norm_pa4);

          target[3*i] = pos[3*i]+pnewt[0];
          target[3*i+1] = pos[3*i+1]+pnewt[1];
        }
        
      }
      if (std::find(begin(found), end(found), false) == end(found)) {
        break; // All false
      }
    }
  }

  for(size_t i=0; i<target.size(); ++i){
    pos[i] = target[i];
  }
  return;
}

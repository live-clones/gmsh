#include <algorithm>
#include "meshRelaying.h"
#include "GModel.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MVertex.h"
#include "robustPredicates.h"
//#include "libol1.h"

#if defined(HAVE_WINSLOWUNTANGLER)
#include "meshSurfaceUntangling.h"
#include "meshVolumeUntangling.h"
#include "winslowUntangler.h"
#endif


discreteFront *discreteFront::_instance = nullptr;
meshRelaying *meshRelaying::_instance = nullptr;

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
    if(c<0) continue;
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

void discreteFront::cornersInTriangle2d (const SVector3 &p0, const SVector3 &p1, const SVector3 &p2,
					 std::vector<SVector3> &c, std::vector<int> &col){
  SPoint2 a0(p0.x(),p0.y());
  SPoint2 a1(p1.x(),p1.y());
  SPoint2 a2(p2.x(),p2.y());
  for (auto i : corners){
    if(colors[i]<0) continue;
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
    if(colors[i/2]<0) continue; // don't compute intersection with bnd
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

// SVector3 discreteFront::velocity (double x, double y, double z, double t, int col){
//   // doublet
//   if (TESTCASE == 12){
//     //    double x1 = 0.5, y1=0.5;
//     if (col == 0) return SVector3(0,0,0);
//     double x2 = 1.5, y2=0.5;
//     //    double r1 = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
//     double r2 = sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
//     double theta_2 = atan2(y-y2,x-x2);
//     double U = 1.0;
//     double R = 0.6;
//     //    if (r2 <= R) return SVector3(0,0,0);
//     double ur = U*cos(theta_2)*(1.-R*R/(r2*r2));
//     double ut = -U*sin(theta_2)*(1.+R*R/(r2*r2));
//     double ux = ur*cos(theta_2)-ut*sin(theta_2);
//     double uy = ur*sin(theta_2)+ut*cos(theta_2);
//     return SVector3(ux,uy,0);
//     //    double Gamma = 1;
//     //    double theta_1 = atan2(y-y1,x-x1);
//     //    double theta_2 = atan2(y-y2,x-x2);
//     // SVector3 v1  ((Gamma/(2*M_PI))*sin(theta_1)/r1,
//     // 		  (-Gamma/(2*M_PI))*cos(theta_1)/r1,0);
//     // SVector3 v2  ((-Gamma/(2*M_PI))*sin(theta_2)/r2,
//     // 		  (Gamma/(2*M_PI))*cos(theta_2)/r2,0);
//     //    SVector3 v1  ((Gamma/(2*M_PI))*cos(theta_1)/r1,
//     //		  (Gamma/(2*M_PI))*sin(theta_1)/r1,0);
//     //    SVector3 v2  ((Gamma/(2*M_PI))*cos(theta_2)/r2,
//     //		  (Gamma/(2*M_PI))*sin(theta_2)/r2,0);
//     // return v1+v2;
//   }
//   if (TESTCASE == 11){
//     double r = col == 1 ? sqrt(x*x+y*y) : sqrt((x-.3)*(x-.3)+y*y);
//     double theta = col == 1 ? atan2(y,x) : atan2(y,x-.3);    
//     return col == 1 ? SVector3(-r*sin(theta),r*cos(theta),0) : SVector3(r*sin(theta),-r*cos(theta),0);
//   }
//   if (TESTCASE == 1){
//     if (col == 1)return SVector3(cos (M_PI*t),0,0);
//     if (col == 2)return SVector3(-cos (M_PI*t),0,0);
//     if (col == 3)return SVector3(0,0,0);
//   }
//   double vx = sin(2*M_PI*y)*sin(M_PI*x)*sin(M_PI*x);
//   double vy = -sin(2*M_PI*x)*sin(M_PI*y)*sin(M_PI*y);
//   double TT = 1;//cos (M_PI*t/8.0);
//   return SVector3(vx*TT,vy*TT,0.0);
// }

void discreteFront::moveFromV (double dt, std::vector<SVector3> v, bool bnd){
  buildSpatialSearchStructure ();
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
  int iter = 0;
  if(bnd) {
    while(1){
      iter++;
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
                double t = fabs(a143)/(fabs(a143)+fabs(a243));
                intersection.push_back(std::make_pair(t, j));
              } else if(fabs(a143)<1e-12){ //previous position on the bnd
                if(a1[0] == a3[0] && a1[1] == a3[1]){
                  double a14[2] = {a4[0]-a1[0], a4[1]-a1[1]};
                  double a12[2] = {a2[0]-a1[0], a2[1]-a1[1]};
                  if((a14[0]*a12[0]+a14[1]*a12[1])>-1e-12){
                    intersection.push_back(std::make_pair(0, j));
                  }
                } else if(a1[0] == a4[0] && a1[1] == a4[1]){
                  double a13[2] = {a3[0]-a1[0], a3[1]-a1[1]};
                  double a12[2] = {a2[0]-a1[0], a2[1]-a1[1]};
                  if((a13[0]*a12[0]+a13[1]*a12[1])>-1e-12){
                    intersection.push_back(std::make_pair(0, j));
                  }
                } else {
                  intersection.push_back(std::make_pair(0, j));
                }
              }

            }
          }
        }
        
        // choose closest intersection or target if none
        if(intersection.empty()){
          pos[3*i] = target[3*i];
          pos[3*i+1] = target[3*i+1];
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

          double a3[2] = {pos[3*lines[id_min]],pos[3*lines[id_min]+1]};
          double a4[2] = {pos[3*lines[id_min+1]],pos[3*lines[id_min+1]+1]};
          
          double proj_p[2], proj_t[2];
          projectPonLine(a3, a4, &pos[3*i], proj_p);
          projectPonLine(a3, a4, &target[3*i], proj_t);

          double pnewt[2] = {proj_t[0]-proj_p[0], proj_t[1]-proj_p[1]};
          double dotProduct = pnewt[0]*(a4[0]-a3[0]) + pnewt[1]*(a4[1]-a3[1]);

          double pa3_norm2 = (pos[3*i]-a3[0])*(pos[3*i]-a3[0]) + (pos[3*i+1]-a3[1])*(pos[3*i+1]-a3[1]);
          double pa4_norm2 = (pos[3*i]-a4[0])*(pos[3*i]-a4[0]) + (pos[3*i+1]-a4[1])*(pos[3*i+1]-a4[1]); 
          double pnewt_norm2 = pnewt[0]*pnewt[0]+pnewt[1]*pnewt[1];
          
          if(dotProduct>0){
            if(pnewt_norm2 > pa4_norm2){
              target[3*i] = pos[3*i]+pnewt[0];
              target[3*i+1] = pos[3*i+1]+pnewt[1];
              pos[3*i] = a4[0];
              pos[3*i+1] = a4[1];
            } else{
              pos[3*i] = pos[3*i]+pnewt[0];
              pos[3*i+1] = pos[3*i+1]+pnewt[1];
              found[i] = true;
            }
          } else {
            if(pnewt_norm2 > pa3_norm2){
              target[3*i] = pos[3*i]+pnewt[0];
              target[3*i+1] = pos[3*i+1]+pnewt[1];
              pos[3*i] = a3[0];
              pos[3*i+1] = a3[1];
            } else{
              pos[3*i] = pos[3*i]+pnewt[0];
              pos[3*i+1] = pos[3*i+1]+pnewt[1];
              found[i] = true;
            }
          }
          
          
        }
        
      }
      if (std::find(begin(found), end(found), false) == end(found)) {
        break; // All false
      }
    }
  }

  FILE *f = fopen ("after_v.pos","w");
  fprintf(f,"View \"Front Geometry\"{\n");
  printGeometry(f);
  fprintf(f,"};\n");
  fclose(f);

  return;
}

void projectPonLine(double A[2], double B[2], double P[2], double *proj){
  double dx = B[0]-A[0];
  double dy = B[1]-A[1];
  double mat[2][2] = {{dx*dx, dx*dy},{dx*dy, dy*dy}};
  double norm = dx*dx+dy*dy;
  (proj)[0] = (mat[0][0]*P[0] + mat[0][1]*P[1])/norm;
  (proj)[1] = (mat[1][0]*P[0] + mat[1][1]*P[1])/norm;
  (proj)[0] += (1-mat[0][0]/norm)*A[0] - mat[0][1]*A[1]/norm;
  (proj)[1] += (-mat[1][0]/norm)*A[0] +(1 - mat[1][1]/norm)*A[1];
}

// SVector3 discreteFront::closestPoints2d (const SVector3 &P){
//   double dmin = 1.e22;
//   SVector3 res;
//   for (size_t i=0 ; i< lines.size() ; i+=2){
//     SVector3 A (pos[3*lines[i]],pos[3*lines[i]+1],pos[3*lines[i]+2]);
//     SVector3 B (pos[3*lines[i+1]],pos[3*lines[i+1]+1],pos[3*lines[i+1]+2]);
//     if (dim() == 2){
//       SVector3 AB = B - A;
//       double lAB = AB.norm();
//       AB.normalize();
//       SVector3 AP = P - A;
//       double L = dot(AP,AB);
//       SVector3 H;
//       if (L < 0)H = A;
//       else if (L > lAB)H = B;
//       else H = A + AB * L;
//       SVector3 HP = P - H;
//       double d = HP.norm();
//       if (d < dmin){
//         dmin = d;
//         res = H;
//       }
//     }
//   }
//   return res;
// }

void discreteFront::getDFPosition(std::vector<double> &position, std::vector<int> &tags){
  position = pos;
  tags = colors;
  return;
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
            p.push_back((1-s)*temp[k]+s*pos[3*_lls[i][j]+k]);
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
    std::pair<size_t,size_t> pa = std::make_pair(std::min(A,B), std::max(A,B));
    pp.push_back(pa);
  }
  std::sort(pp.begin(),pp.end());
  return pp;
}

//FIX ME
void discreteFront::moveFromFront(double dt, std::vector<SVector3> v){
  
  std::vector<SVector3> v_marker(pos.size()/3, SVector3(0.0));
  std::sort(fn.begin(), fn.end());
  std::vector<double> mesh_pos;
  meshRelaying::instance()->getNodesPosition(mesh_pos);

  std::vector<std::vector<size_t> > _lls;
  std::vector<size_t> _ll;

  for (size_t i=0;i<lines.size();i+=2){
    if(colors[i/2]<0) continue;
    _ll.push_back(lines[i]);
    _ll.push_back(lines[i+1]);
    if (lines[(i+2)%lines.size()] != lines[i+1]){
      _lls.push_back(_ll);
      _ll.clear();
    }
  }

  std::vector<std::vector<std::pair<size_t,int>>> fls;
  std::vector<std::pair<size_t,int>> fl;

  for(size_t i=0; i<_lls.size();++i){
    //    size_t start = _lls[i][0];
    for(size_t j=0; j<_lls[i].size(); j+=2){
      fl.push_back(std::make_pair(_lls[i][j],-1));
      for(size_t k=0; k<fn.size(); ++k){
        if( _lls[i][j] == lines[fn[k].line] ){
          fl.push_back(std::make_pair(fn[k].meshNode,k));
        }
      }
    }
    fls.push_back(fl);
    fl.clear();
  }

  

  for(int i=0; i<fls.size(); ++i){
    int current=0;
    while(fls[i][current].second<0 && current<fls[i].size()) ++current;
    int start = current;
    int next = current;
    std::vector<std::pair<size_t, double>> in_between_markers;
    while (next<fls[i].size()-1){
      next++;
      if(fls[i][next].second >= 0){
        printf(" front node : %d, v = %f,%f \n", fls[i][next].second, v[fls[i][next].second].x(), v[fls[i][next].second].y());
        // compute velocity for markers between current and next front node
        double total_dist;
        if(!in_between_markers.empty()){
          total_dist = in_between_markers.back().second + sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][next].second +1],2));
        }
  
        for(size_t k=0; k<in_between_markers.size(); ++k){
          double s = in_between_markers[k].second/total_dist;
          SVector3 v1 = v[fls[i][current].second];
          SVector3 v2 = v[fls[i][next].second]; 
          v_marker[in_between_markers[k].first] = s*v2 + (1-s)*v1;

        }
        current = next;
        in_between_markers.clear();
      }else{
        double dist;
        if(in_between_markers.empty()){
          dist = sqrt(pow(mesh_pos[3*current]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*current+1]-pos[3*fls[i][next].second +1],2));
          in_between_markers.push_back(std::make_pair(fls[i][next].first, dist));
        }else{
          dist = sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][next].second +1],2));
          in_between_markers.push_back(std::make_pair(fls[i][next].first, in_between_markers.back().second + dist));
        }
      }
    }

    int reset = 0;
    while(fls[i][reset].second<0 && current<fls[i].size()){
      double dist;
      if(in_between_markers.empty()){
        dist = sqrt(pow(mesh_pos[3*current]-pos[3*fls[i][reset].second],2) + pow(mesh_pos[3*current+1]-pos[3*fls[i][reset].second +1],2));
        in_between_markers.push_back(std::make_pair(fls[i][reset].first, dist));
      }else{
        dist = sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][reset].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][reset].second +1],2));
        in_between_markers.push_back(std::make_pair(fls[i][reset].first, in_between_markers.back().second + dist));
      }
      ++reset;
    }
    double total_dist;
    if(!in_between_markers.empty()){
      total_dist = in_between_markers.back().second + sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][start].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][start].second +1],2));
    }
    for(size_t k=0; k<in_between_markers.size(); ++k){
      double s = in_between_markers[k].second/total_dist;
      printf("end marker = %lu s = %f \n", in_between_markers[k].first, s);
      SVector3 v1 = v[fls[i][current].second];
      SVector3 v2 = v[fls[i][start].second];
      v_marker[in_between_markers[k].first] = s*v2 + (1-s)*v1;

    }
    
    
  }

  for(size_t i=0; i<fls.size(); ++i){
    for(size_t j=0; j<fls[i].size(); ++j){
      if(fls[i][j].second<0){
        printf("marker : %lu, v = %f,%f \n", fls[i][j].first, v_marker[fls[i][j].first].x(), v_marker[fls[i][j].first].y());
      } else {
        printf("front node: %d, v = %f,%f \n", fls[i][j].second, v[fls[i][j].second].x(), v[fls[i][j].second].y());
      }
    }
    
  }
  
  moveFromV(dt, v_marker, true);
}

// NEED FIX
void discreteFront::adjustBnd(std::vector<std::pair<size_t,size_t>> bnd1d){

  std::vector<double> position;
  meshRelaying::instance()->getNodesPosition(position);
  std::vector<double> old_pos;
  for(size_t i=0; i<pos.size();++i){
    old_pos.push_back(pos[i]);
  }

  size_t current = bnd1d[0].second;
  size_t first = bnd1d[0].first;
  size_t id_current = 0;
  size_t i = 0;
  pos[3*i] = position[3*first];
  pos[3*i+1] = position[3*first+1];
  pos[3*i+2] = position[3*first+2];
  ++i;

  while(current!= first){
    pos[3*i] = position[3*current];
    pos[3*i+1] = position[3*current+1];
    pos[3*i+2] = position[3*current+2];
    ++i;
    
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

  std::vector<int> moved(pos.size()/3, 0);
  for(size_t i=0; i<pos.size()/3; ++i){
    if (old_pos[3*i]!=pos[3*i] || old_pos[3*i+1]!=pos[3*i+1]){
      moved[i] = 1;
    }
  }

  for(size_t i=0; i<lines.size(); i+=2){
    if(!moved[lines[i]] && !moved[lines[i+1]]) continue;
    // compute if markers went through
    for(size_t j=0; j<lines.size(); j+=2){
      if(colors[lines[j]]<0) continue;
      
      double b1[2] = {pos[3*lines[i]], pos[3*lines[i]+1]};
      double b2[2] = {pos[3*lines[i+1]], pos[3*lines[i+1]+1]};
      double a1[2]  = {old_pos[3*lines[i]], old_pos[3*lines[i]+1]};
      double a2[2]  = {old_pos[3*lines[i+1]], old_pos[3*lines[i+1]+1]};
      double p[2] = {pos[3*lines[j]], pos[3*lines[j]+1]};

      double a12p  = robustPredicates::orient2d(a1,a2,p);
      double b12p = robustPredicates::orient2d(b1,b2,p);
      if(a12p*b12p<=1e-12){
	//        double a1b1p = robustPredicates::orient2d(a1,b1,p);
	//        double a2b2p = robustPredicates::orient2d(a2,b2,p);
        double lengthSquared = (b2[0]-b1[0])*(b2[0]-b1[0]) + (b2[1]-b1[1])*(b2[1]-b1[1]);
        // Avoid division by zero
        if (lengthSquared == 0.0) {
            pos[3*lines[j]] = b1[0];
            pos[3*lines[j]+1] = b1[1];
        } else {
          double t = ((p[0]-b1[0])*(b2[0]-b1[0]) + (p[1]-b1[1])*(b2[1]-b1[1])) / lengthSquared;
          // t = std::max(0.0, std::min(1.0, t));
          if(t>=0.0 && t<=1.0){
            pos[3*lines[j]] = b1[0]+t*(b2[0]-b1[0]);
            pos[3*lines[j]+1] = b1[1]+t*(b2[1]-b1[1]);
          }
        }
      }
    }
  }
}

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

void meshRelaying::doRelaying (const std::function<std::vector<std::pair<double,int> >(size_t, size_t)> &f){
  
  front_nodes.clear();
  discreteFront::instance()->clearFrontNodes();
  discreteFront::instance()->buildSpatialSearchStructure ();

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
            
            // do not move a bnd node on a corner 
            // JF do not remove this
            int dimEdge = tets.size() ? 3:2;
            int dimi = dimVertex[tris[i+j]];
            if(dimi<dimEdge){
              continue;
            } 

            double qMin = smallest_measure (tris[i+j],c[0]);
            if (qMin > 0){
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
      
      for (auto k : v2v[i]){
        p = std::make_pair(std::min(i,k), std::max(i,k));
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
    /*    if (!missing_edges.empty()){
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
    */
  }
}

void meshRelaying::print4debug(const char *fn){
  FILE *f = fopen (fn,"w");
  fprintf(f,"View \"Front Mesh\"{\n");
  discreteFront::instance()->printMesh(f);
  fprintf(f,"};\n");
  fprintf(f,"View \"Mesh\"{\n");  
  /*  for (size_t i=0;i<tets.size();i+=4){
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
  */
  
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

  for (size_t i=0;i<tris.size();i+=3){
    fprintf(f, "SL(%g,%g,0.005,%g,%g,0.005){%d,%d};\n", pos[3*tris[i]],pos[3*tris[i]+1], pos[3*tris[i+1]],pos[3*tris[i+1]+1], 5,5);
    fprintf(f, "SL(%g,%g,0.005,%g,%g,0.005){%d,%d};\n", pos[3*tris[i+1]],pos[3*tris[i+1]+1], pos[3*tris[i+2]],pos[3*tris[i+2]+1], 5,5);
    fprintf(f, "SL(%g,%g,0.005,%g,%g,0.005){%d,%d};\n", pos[3*tris[i]],pos[3*tris[i]+1], pos[3*tris[i+2]],pos[3*tris[i+2]+1], 5,5);
  }
  for (size_t i=0;i<front_nodes.size();i++){
    fprintf(f,"SP(%g,%g,%g){3};\n",pos[3*front_nodes[i]],
	    pos[3*front_nodes[i]+1],pos[3*front_nodes[i]+2]);
  }
  fprintf(f,"};\n");

  fprintf(f,"View \"Front Geometry\"{\n");
  discreteFront::instance()->printGeometry(f);
  fprintf(f,"};\n");
  fclose(f);
}

void meshRelaying::curvature(std::vector<int> concentration, std::vector<double> *curvature){
  curvature->resize(v2v.size());
  for(size_t i=0; i<v2v.size(); ++i){
    std::vector<std::pair<size_t, int>> front_node_i;
    for(size_t j=0; j<v2v[i].size(); ++j){

      std::vector<std::pair<size_t,int>> edgeij2tri;
      for(size_t k=0; k<v2tri[i].size(); ++k){
        for(int d=0; d<3; ++d){
          if(tris[3*v2tri[i][k]+d] == v2v[i][j]){
            if(tris[3*v2tri[i][k]+((d+1)%3)] == i){
              edgeij2tri.push_back(std::make_pair(v2tri[i][k], 1));
            } else {
              edgeij2tri.push_back(std::make_pair(v2tri[i][k], -1));
            }
            
          }
        }
      }
      
      if(edgeij2tri.size()!=2){
        (*curvature)[i] = 0.0;
        continue;
      }
      if(concentration[edgeij2tri[0].first]!=concentration[edgeij2tri[1].first]){
        int sign = 0;
        if(concentration[edgeij2tri[0].first]==1){
          sign = edgeij2tri[0].second;
        } else {
          sign = edgeij2tri[1].second;
        }
        front_node_i.push_back(std::make_pair(v2v[i][j], sign));
      }
    }
    
    if(front_node_i.size()!=2){
      (*curvature)[i] = 0.0;
      continue;
    } 
    
    
    size_t triplet[3];
    if(front_node_i[0].second == 1){
      triplet[0] = front_node_i[0].first;
      triplet[1] = i;
      triplet[2] = front_node_i[1].first;
    } else {
      triplet[0] = front_node_i[1].first;
      triplet[1] = i;
      triplet[2] = front_node_i[0].first;
    }
    (*curvature)[i] = kappa(&pos[3*triplet[0]], &pos[3*triplet[1]], &pos[3*triplet[2]]);
    
  }
}

double kappa(double x1[2], double x2[2], double x3[2]){
  double dy1 = x1[1]-x2[1];
  double dy2 = x2[1]-x3[1];
  double dy3 = x3[1]-x1[1];

  double n1 = x1[0]*x1[0] + x1[1]*x1[1];
  double n2 = x2[0]*x2[0] + x2[1]*x2[1];
  double n3 = x3[0]*x3[0] + x3[1]*x3[1];

  double area = 0.5*(x1[0]*dy2 + x2[0]*dy3 + x3[0]*dy1);
  if (area == 0.0){
      return 0.0;
  } else {
    double Ux = (1/(4*area))*(n1*dy2 + n2*dy3 + n3*dy1);
    double Uy = (1/(4*area))*(n1*(x3[0]-x2[0]) + n2*(x1[0]-x3[0]) + n3*(x2[0]-x1[0]));

    double radius = sqrt((Ux-x2[0])*(Ux-x2[0]) + (Uy-x2[1])*(Uy-x2[1]));
    double sign = 0.0;
    if(robustPredicates::orient2d(x1,x2,x3)>0){
      sign = 1.0;
    } else {
      sign = -1.0;
    }
    return -sign*(1.0/radius);
  }
  return 0;
}

void meshRelaying::untangle(){
#if defined(HAVE_WINSLOWUNTANGLER)
  std::vector<bool> _locked;
  std::vector<std::array<double,2> > _points;
  std::vector<std::array<uint32_t, 4> > _elements;
  for (size_t i=0;i<tris.size()/3;i++)_elements.push_back({static_cast<unsigned int>(tris[3*i]),
	static_cast<unsigned int>(tris[3*i+1]),static_cast<unsigned int>(tris[3*i+2]),uint32_t(-1)});
  for (size_t i=0;i<pos.size()/3;i++)_points.push_back({pos[3*i],pos[3*i+1]});  
  for (size_t i=0;i<pos.size()/3;i++)_locked.push_back(dimVertex[i] == 2 ? false : true);
  for (size_t i=0;i<front_nodes.size();i++)_locked[front_nodes[i]]=true;  
  std::vector<std::array<uint32_t, 3> > _triangles;
  std::vector<std::array<std::array<double,2>, 3> > _triIdealShapes;    
  buildTrianglesAndTargetsFromElements(_points,_elements,_triangles,_triIdealShapes);
  untangle_triangles_2D(_points, _locked, _triangles, _triIdealShapes);
  for (size_t i=0;i<_points.size();i++){
    pos[3*i] = _points[i][0];
    pos[3*i+1] = _points[i][1];
  }    
#else
  Msg::Error ("Gmsh Must Be Compiled With WinslowUntangler to be able to use meshRelaying::untangle()");  
#endif
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
  discreteFront::instance()->addLines(p,l,c);
}



void discreteFront :: printMesh (FILE *f) {
  if(fn.empty()) return;
  std::sort(fn.begin(), fn.end());
  std::vector<SVector3> pp;
  int current_color = getColor(fn[0].line);
  for (size_t i=0;i<fn.size();i++){
    const frontNode &n = fn[i];
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

void discreteFront::printGeometry(FILE *f){
  for (size_t i=0 ; i< lines.size() ; i+=2){
    fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	    pos[3*lines[i]],pos[3*lines[i]+1],
	    pos[3*lines[i+1]],pos[3*lines[i+1]+1],-colors[i/2],-colors[i/2]);
  }

  for(size_t i=0; i<lines.size(); i+=2){
    fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%lu'};\n", pos[3*lines[i]],pos[3*lines[i]+1], lines[i]);
    fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%lu'};\n", pos[3*lines[i+1]],pos[3*lines[i+1]+1], lines[i+1]);
  }

}

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

double meshRelaying::massElements (int color){

  double mass = 0.0;
  // if (tets.empty()){
  //   for (size_t i=0;i<tris.size();i+=3){
  //     SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
	// 	   (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
	// 	   0);
  //     if (discreteFront::instance()->whatIsTheColorOf2d(COG) == color){
	// double aa[2] = {pos[3*tris[i]],pos[3*tris[i]+1]}; 
	// double bb[2] = {pos[3*tris[i+1]],pos[3*tris[i+1]+1]}; 
	// double cc[2] = {pos[3*tris[i+2]],pos[3*tris[i+2]+1]};
	// double area = robustPredicates::orient2d(aa,bb,cc);
	// mass += area;
  //     }
  //   }
  // }
  return mass;
}

double meshRelaying::qualityElement (size_t elem){

  if (!tets.empty()){
    size_t n0 = tets[4*elem+0];
    size_t n1 = tets[4*elem+1];
    size_t n2 = tets[4*elem+2];
    size_t n3 = tets[4*elem+3];
    //    printf("%lu %lu %lu %lu -- %lu\n",n0,n1,n2,n3, pos.size());
    double aa[3] = {pos[3*n0],pos[3*n0+1],pos[3*n0+2]}; 
    //    printf("%g %g %g \n",aa[0],aa[1],aa[2]);
    double bb[3] = {pos[3*n1],pos[3*n1+1],pos[3*n1+2]}; 
    //    printf("%g %g %g \n",bb[0],bb[1],bb[2]);
    double cc[3] = {pos[3*n2],pos[3*n2+1],pos[3*n2+2]}; 
    //    printf("%g %g %g \n",cc[0],cc[1],cc[2]);
    double dd[3] = {pos[3*n3],pos[3*n3+1],pos[3*n3+2]}; 
    //    printf("%g %g %g \n",dd[0],dd[1],dd[2]);
    double volume;
    return qmTetrahedron::gamma(aa[0],aa[1],aa[2],
				bb[0],bb[1],bb[2],
				cc[0],cc[1],cc[2],
				dd[0],dd[1],dd[2],&volume);
  }
  return 0.0;
}


int discreteFront::whatIsTheColorOf2d (const SVector3 &P, std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags){
  // compute winding number -- fast
  std::set<int> cs;
  std::vector<int> cols;
  double pp[2] = {P.x(),P.y()};
  for (size_t i=0 ; i<loops.size(); ++i){
    int c = loops_tags[i];
    if(c<0)continue;
    
    int wn = 0;
    size_t n = loops[i].size();
    for (size_t j=0 ; j<n ; ++j){
      double aa[2] = {pos[3*loops[i][j]],pos[3*loops[i][j]+1]};
      double bb[2] = {pos[3*loops[i][(j+1)%n]],pos[3*loops[i][(j+1)%n]+1]};
      double area = robustPredicates::orient2d(aa,bb,pp); 
      if(aa[1]<= P.y()){
        if (bb[1] > P.y() && area < 0)wn++;
      }
      else if(bb[1]<= P.y()){
        if (area > 0)wn--;
      }
    }
    if (wn != 0)cols.push_back(c);
    
  }
  if (cols.empty())return -1;
  if (cols.size() == 1)return cols[0];
  if (cols.size() > 1){
    return 1;
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

void discreteFront::tripleInTriangle2d (const SVector3 &p0, const SVector3 &p1, const SVector3 &p2,
					 std::vector<size_t> &interface_id, std::vector<size_t> &m1, std::vector<size_t> &m2, std::vector<SVector3> &p_out){
  SPoint2 a0(p0.x(),p0.y());
  SPoint2 a1(p1.x(),p1.y());
  SPoint2 a2(p2.x(),p2.y());
  for (size_t ii=0; ii< triple_points.size(); ++ii){
    triple_p i = triple_points[ii];
    SPoint2 p(i.pos[0],i.pos[1]);
    SVector3 p3(i.pos[0],i.pos[1],0);
    double d = std::min(std::min((p0-p3).norm(),(p1-p3).norm()),(p2-p3).norm());
    if (d < 1.e-12)continue ; // FIXME
    double a01p = robustPredicates::orient2d(a0,a1,p);
    double a12p = robustPredicates::orient2d(a1,a2,p);
    double a20p = robustPredicates::orient2d(a2,a0,p);

    if (a01p*a12p >=0 && a01p*a20p >=0 && a20p*a12p >=0){
      interface_id.push_back(i.id_interface);
      m1.push_back(interfaces[i.id_interface].markers[i.id_marker]);
      m2.push_back(interfaces[i.id_interface].markers[i.id_marker]);
      p_out.push_back(SVector3(i.pos[0],i.pos[1],0));
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
  
  std::vector<std::pair<size_t, std::pair<int,int>>> _ind;
  int IMIN,IMAX,JMIN,JMAX;
  getCoordinates(xmin,ymin,IMIN,JMIN);
  getCoordinates(xmax,ymax,IMAX,JMAX);
  for (int I=IMIN; I<=IMAX;I++){
    for (int J=JMIN; J<=JMAX;J++){
      int index = I+NX*J;
      _ind.insert(_ind.begin(),sss_inter[index].begin(),sss_inter[index].end());
    }
  }
  std::sort(_ind.begin(), _ind.end());
  auto last = std::unique (_ind.begin(), _ind.end());
  _ind.erase(last,_ind.end());

  for (size_t I=0 ; I< _ind.size() ; I++){
    std::pair<size_t, std::pair<int,int>> line = _ind[I];
    int m = line.second.first;
    int mp1 = line.second.second;
    double a3[2]= {pos[3*m],pos[3*m+1]};
    double a4[2]= {pos[3*mp1],pos[3*mp1+1]};
    
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
    c.push_back(m);
    c.push_back(mp1);
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


void discreteFront::buildSpatialSearchStructureInterface() {    
  if(empty())return;
  for (size_t i=0;i<pos.size();i+=3)
    bbox += SPoint3(pos[i],pos[i+1],pos[i+2]);    
  NX = 300;
  NY = 300;
  sss_inter.clear();
  sss_inter.resize(NX*NY);
  for(size_t i=0; i<interfaces.size(); ++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      size_t n_m = interfaces[i].markers.size();
      int IX,IY,JX,JY;
      getCoordinates(pos[3*interfaces[i].markers[j]],pos[3*interfaces[i].markers[j]+1], IX, IY);
      getCoordinates(pos[3*interfaces[i].markers[(j+1)%n_m]],pos[3*interfaces[i].markers[(j+1)%n_m]+1], JX, JY);
      for (size_t I=std::min(IX,JX);I<=std::max(IX,JX);I++){
        for (size_t J=std::min(IY,JY);J<=std::max(IY,JY);J++){
          sss_inter[I+J*NX].push_back(std::make_pair(i,std::make_pair(interfaces[i].markers[j],interfaces[i].markers[(j+1)%n_m])));
        }
      }
    }
  }
  return;
}

void discreteFront::intersectInterfaces(std::vector<std::pair<size_t, size_t>> *interactions){
  std::vector<interface> new_interfaces = interfaces;
  std::vector<size_t> intersection_struct;
  std::vector<double> intersection_param;
  for(size_t i=0; i<interfaces.size(); ++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      size_t n_m = interfaces[i].markers.size();
      size_t m = interfaces[i].markers[j];
      size_t mp1 = interfaces[i].markers[(j+1)%n_m];
      double a1[2] = {pos[3*m],pos[3*m+1]};
      double a2[2] = {pos[3*mp1],pos[3*mp1+1]};

      int IMIN,IMAX,JMIN,JMAX;
      getCoordinates(std::min(a1[0],a2[0]),std::min(a1[1],a2[1]),IMIN,JMIN);
      getCoordinates(std::max(a1[0],a2[0]),std::max(a1[1],a2[1]),IMAX,JMAX);
      std::set<std::pair<size_t, std::pair<int,int>>> touched;
      for(size_t I=IMIN; I<=IMAX;I++){
        for(size_t J=JMIN; J<=JMAX;J++){
          size_t index = I+NX*J;
          for(auto s : sss_inter[index]){
            size_t id_interface = s.first;
            int id_marker = s.second.first;
            int id_markerp1 = s.second.second;

            if(touched.find(s) != touched.end())continue;
            touched.insert(s);
            if(i>id_interface) continue;                      // only compute once intersections and allow interface auto-intersecion 
            if(i == id_interface && (m == id_marker || mp1 == id_marker)) continue; // don't compute intersection with himself
            if(i == id_interface){
              size_t it = std::find(interfaces[i].markers.begin(), interfaces[i].markers.end(), id_marker) - interfaces[i].markers.begin();
              if(it>j){
                printf("skipped intersection interface in %d, %d markers : markers %d - %d with %d -%d  \n", i, id_interface, m, mp1, id_marker, id_markerp1);
                continue;
              }
            }

            double a3[2] = {pos[3*id_marker],pos[3*id_marker+1]};
            double a4[2] = {pos[3*id_markerp1],pos[3*id_markerp1+1]};
            double inter[2] = {0,0};
            double param[1] = {0};
            int b_inter = computeIntersection(a1, a2, a3, a4, inter, param);
            if(b_inter){
              printf("intersection interface in %f, %f markers : markers %d - %d with %d -%d  \n", inter[0], inter[1], m, mp1, id_marker, id_markerp1);
              printf("sss size = %d, i,j / n = %d,%d / %d\n", sss_inter[index].size(), i,j, interfaces[i].markers.size());
              interactions->push_back(std::make_pair(id_interface, i));
              size_t n_pos = pos.size()/3;
              pos.push_back(inter[0]);
              pos.push_back(inter[1]);
              pos.push_back(0.0);

              int idx = std::find(new_interfaces[id_interface].markers.begin(), new_interfaces[id_interface].markers.end(), id_marker)-new_interfaces[id_interface].markers.begin();
              size_t to_add = 0;
              for(size_t k=0; k< intersection_param.size(); ++k){
                printf("inter m = %d, %d\n", intersection_struct[3*k+1], intersection_struct[3*k+2]);
                printf("id m = %d\n", id_marker);
                printf("param = %f, %f\n", intersection_param[k], param[0]);
                if(intersection_struct[3*k+1] == id_marker && intersection_param[k]<param[0]){
                  to_add += 1;
                }
                if(intersection_struct[3*k+2] == id_marker && intersection_param[k]<param[0]){
                  to_add += 1;
                }
              }
              printf("add marker %d at %d\n", n_pos, idx+1+to_add);
              printf("to_add = %d\n", to_add);
              new_interfaces[id_interface].markers.insert(new_interfaces[id_interface].markers.begin()+idx+1+to_add, n_pos);

              int idx_j = std::find(new_interfaces[i].markers.begin(), new_interfaces[i].markers.end(), m)-new_interfaces[i].markers.begin();
              size_t to_add_j = 0;
              for(size_t k=0; k< intersection_param.size(); ++k){
                printf("inter m = %d, %d\n", intersection_struct[3*k+1], intersection_struct[3*k+2]);
                printf("id m = %d\n", m);
                printf("param = %f, %f\n", intersection_param[k], param[0]);
                if(intersection_struct[3*k+1] == m && intersection_param[k]<param[0]){
                  to_add_j += 1;
                }
                if(intersection_struct[3*k+2] == m && intersection_param[k]<param[0]){
                  to_add_j += 1;
                }
              }
              printf("add marker %d at %d\n", n_pos, idx_j+1+to_add_j);
              printf("to_add_j = %d\n", to_add_j);
              new_interfaces[i].markers.insert(new_interfaces[i].markers.begin()+idx_j+1+to_add_j, n_pos);

              intersection_struct.push_back(n_pos);
              intersection_struct.push_back(id_marker);
              intersection_struct.push_back(m);
              intersection_param.push_back(param[0]);
            }
          }
        }
      }
    }
  }
  interfaces = new_interfaces;
  //update triple points
  for(size_t i=0; i<triple_points.size(); ++i){
    size_t ii = triple_points[i].id_interface;
    size_t marker = triple_points[i].marker;
    for(size_t j=0; j<interfaces[ii].markers.size(); ++j){
      if(interfaces[ii].markers[j] == marker){
        triple_points[i].id_marker = j;
        break;
      }
    }

    size_t i_on_i = triple_points[i].id_on_interface;
    for(size_t j=0; j<interfaces[i_on_i].markers.size(); ++j){
      if(interfaces[i_on_i].markers[j] == marker){
        triple_points[i].id_on_marker = j;
        break;
      }
    }
  }
}

void discreteFront::bool_op_priority(){
  std::vector<std::pair<size_t,size_t>> list_inter;
  std::vector<size_t> to_remove;
  for(size_t i=0; i<triple_points.size(); ++i){
    std::pair<size_t,size_t> p = std::make_pair(triple_points[i].id_on_interface, triple_points[i].id_interface);
    if(std::find(list_inter.begin(), list_inter.end(), p) == list_inter.end()){
      list_inter.push_back(p);
    }
  }
  
}

// loop1 and loop2 need to be in counterclockwise order with the intersection marker, inter is the ids of the two intersection
// return merged, the list of the markers 
void discreteFront::mergeLoop(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *merged){
  size_t n1 = loop1.size();
  size_t n2 = loop2.size();

  std::vector<size_t> it_inters;
  for(size_t i=0; i<inter.size(); ++i){
    it_inters.push_back(std::find(loop1.begin(), loop1.end(), inter[i]) - loop1.begin());
  }

  size_t it_inter11 = std::find(loop1.begin(), loop1.end(), inter[0]) - loop1.begin();
  size_t it_inter12 = std::find(loop1.begin(), loop1.end(), inter[1]) - loop1.begin();

  size_t it_inter21 = std::find(loop2.begin(), loop2.end(), inter[0]) - loop2.begin();
  size_t it_inter22 = std::find(loop2.begin(), loop2.end(), inter[1]) - loop2.begin();

  //first point outside
  size_t it1 = 0;
  double P[2];
  while(true){
    if(it1>=loop1.size()){
      exit(1);
    }

    if(it1==it_inter11 || it1==it_inter12){
      it1++;
      continue;
    }

    P[0] = pos[3*loop1[it1]];
    P[1] = pos[3*loop1[it1]+1];

    if(!insideList(loop2, P)){
      break;
    } else{
      it1++;
    } 
  }

  

  merged->push_back(loop1[it1]);
  while((it1+1)%n1 != it_inter11 && (it1+1)%n1 != it_inter12){
    merged->push_back(loop1[(it1+1)%n1]);
    it1++;
  }

  // first intersection
  size_t it2;
  if((it1+1)%n1 == it_inter11){
    it2 = it_inter21;
  } else {
    it2 = it_inter22;
  }

  merged->push_back(loop2[it2]);
  while((it2+1)%n2 != it_inter21 && (it2+1)%n2 != it_inter22){
    merged->push_back(loop2[(it2+1)%n2]);
    it2++;
  }

  // second intersection
  if((it2+1)%n2 == it_inter21){
    it1 = it_inter11;
  } else {
    it1 = it_inter12;
  }

  // close loop 
  merged->push_back(loop1[it1]);
  while(loop1[(it1+1)%n1]!=(*merged)[0]){
    merged->push_back(loop1[(it1+1)%n1]);
    it1++;
  }

  return;
}

// loop1 and loop2 need to be in counterclockwise order with the intersection marker, inter is the ids of the two intersection
// return loop1 \ loop2, the list of the markers for side by side loops
void discreteFront::loop1Minusloop2(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *minus){
  size_t n1 = loop1.size();
  size_t n2 = loop2.size();

  size_t it_inter11 = std::find(loop1.begin(), loop1.end(), inter[0]) - loop1.begin();
  size_t it_inter12 = std::find(loop1.begin(), loop1.end(), inter[1]) - loop1.begin();

  size_t it_inter21 = std::find(loop2.begin(), loop2.end(), inter[0]) - loop2.begin();
  size_t it_inter22 = std::find(loop2.begin(), loop2.end(), inter[1]) - loop2.begin();

  //first point outside
  size_t it1 = 0;
  double P[2];
  while(true){
    if(it1>=loop1.size()){
      exit(1);
    }

    if(it1==it_inter11 || it1==it_inter12){
      it1++;
      continue;
    }

    P[0] = pos[3*loop1[it1]];
    P[1] = pos[3*loop1[it1]+1];

    if(!insideList(loop2, P) && loop1[it1]!=inter[0] &&  loop1[it1]!=inter[1]){
      break;
    } else{
      it1++;
    } 
  }

  

  minus->push_back(loop1[it1]);
  while((it1+1)%n1 != it_inter11 && (it1+1)%n1 != it_inter12){
    minus->push_back(loop1[(it1+1)%n1]);
    it1++;
  }

  // first intersection
  size_t it2;
  if((it1+1)%n1 == it_inter11){
    it2 = it_inter21;
  } else {
    it2 = it_inter22;
  }

  minus->push_back(loop2[it2]);
  while((it2-1+n2)%n2 != it_inter21 && (it2-1+n2)%n2 != it_inter22){
    minus->push_back(loop2[(it2-1+n2)%n2]);
    it2--;
  }

  // second intersection
  if((it2-1+n2)%n2 == it_inter21){
    it1 = it_inter11;
  } else {
    it1 = it_inter12;
  }

  // close loop 
  minus->push_back(loop1[it1]);
  while(loop1[(it1+1)%n1]!=(*minus)[0]){
    minus->push_back(loop1[(it1+1)%n1]);
    it1++;
  }
  return;
}

void discreteFront::loop1Minusloop2_inside(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *minus){
  size_t n1 = loop1.size();
  size_t n2 = loop2.size();

  printf("inter size = %d\n", inter.size());
  for(size_t i=0; i<inter.size(); ++i){
    printf("inter[%d] = %d\n", i, inter[i]);
  }

  size_t it_inter11 = std::find(loop1.begin(), loop1.end(), inter[0]) - loop1.begin();
  size_t it_inter12 = std::find(loop1.begin(), loop1.end(), inter[1]) - loop1.begin();

  size_t it_inter21 = std::find(loop2.begin(), loop2.end(), inter[0]) - loop2.begin();
  size_t it_inter22 = std::find(loop2.begin(), loop2.end(), inter[1]) - loop2.begin();

  //first point outside
  size_t it1 = 0;
  double P[2];
  while(true){
    if(it1>=loop2.size()){
      exit(1);
    }

    if(it1==it_inter21 || it1==it_inter22){
      it1++;
      continue;
    }

    P[0] = pos[3*loop2[it1]];
    P[1] = pos[3*loop2[it1]+1];

    if(insideList(loop1, P) && loop2[it1]!=inter[0] &&  loop2[it1]!=inter[1]){
      break;
    } else{
      it1++;
    } 
  }

  

  minus->push_back(loop2[it1]);
  while((it1+1)%n1 != it_inter21 && (it1+1)%n1 != it_inter22){
    minus->push_back(loop2[(it1+1)%n2]);
    it1++;
  }

  // first intersection
  size_t it2;
  if((it1+1)%n2 == it_inter21){
    it2 = it_inter11;
  } else {
    it2 = it_inter12;
  }

  minus->push_back(loop1[it2]);
  while((it2+1)%n1 != it_inter11 && (it2+1)%n1 != it_inter12){
    minus->push_back(loop1[(it2+1)%n1]);
    it2++;
  }

  // second intersection
  if((it2+1)%n1 == it_inter11){
    it1 = it_inter21;
  } else {
    it1 = it_inter22;
  }

  // close loop 
  minus->push_back(loop2[it1]);
  while(loop2[(it1+1)%n2]!=(*minus)[0]){
    minus->push_back(loop2[(it1+1)%n2]);
    it1++;
  }

  printf("minus = \n");
  for(size_t i=0; i<minus->size(); ++i){
    printf("%d, ", (*minus)[i]);
  }
  printf("\n");
  return;
}

void discreteFront::autoIntersect(std::vector<size_t> loop, std::vector<size_t> inter, std::vector<size_t> *outside, std::vector<size_t> *inside){
  std::vector<size_t> temp1, temp2;
  size_t n = loop.size();
  int *flag = (int*) calloc(n, sizeof(int)); 

  std::vector<size_t>::iterator iter1 = std::find(loop.begin(), loop.end(), inter[0]);
  std::vector<size_t>::iterator iter2 = std::find(iter1+1, loop.end(), inter[0]);
  size_t it_inter11 = iter1 - loop.begin();
  size_t it_inter12 = iter2 - loop.begin();

  iter1 = std::find(loop.begin(), loop.end(), inter[1]);
  iter2 = std::find(iter1+1, loop.end(), inter[1]);
  size_t it_inter21 = iter1 - loop.begin();
  size_t it_inter22 = iter2 - loop.begin();

  //first point exterior 
  size_t it;
  double y_max= -1e100;

  for(size_t i=0; i<loop.size(); ++i){
    if(pos[3*loop[i]+1]>y_max){
      it = i;
      y_max = pos[3*loop[i]+1];
    }
  }

  //exterior loop
  temp1.push_back(loop[it]);
  flag[it] = 1;
  while((it+1)%n!=it_inter11 && (it+1)%n!=it_inter12 && (it+1)%n!=it_inter21 && (it+1)%n!=it_inter22){
    temp1.push_back(loop[(it+1)%n]);
    flag[(it+1)%n] = 1;
    ++it;
  }
  temp1.push_back(loop[(it+1)%n]);
  if((it+1)%n == it_inter11){
    it = it_inter12;
  } else if((it+1)%n == it_inter12){
    it = it_inter11;
  } if((it+1)%n == it_inter21){
    it = it_inter22;
  } else if((it+1)%n == it_inter22){
    it = it_inter21;
  }
  
  temp1.push_back(loop[it]);
  flag[it] = 1;
  while(loop[(it+1)%n]!=temp1[0]){
    temp1.push_back(loop[(it+1)%n]);
    flag[(it+1)%n] = 1;
    ++it;
  }

  //first point interior
  size_t start_it;
  if(flag[it_inter11]==1 || flag[it_inter12]==1){
    it = it_inter21;
    start_it = it_inter21;
  } else {
    it = it_inter11;
    start_it = it_inter11;
  }
  // interior loop
  temp2.push_back(loop[it]);
  while(loop[(it+1)%n] != inter[0] && loop[(it+1)%n] != inter[1]){
    temp2.push_back(loop[(it+1)%n]);
    it++;
  }

  if(loop[(it+1)%n] != loop[start_it]){
    temp2.clear();
    if(start_it == it_inter21){
      it = it_inter22;
    } else {
      it = it_inter12;
    }

    temp2.push_back(loop[it]);
    while(loop[(it+1)%n] != inter[0] && loop[(it+1)%n] != inter[1]){
      temp2.push_back(loop[(it+1)%n]);
      it++;
    }
  }

  for(size_t i=0; i<temp1.size(); ++i){
    outside->push_back(temp1[i]);
  }
  for(size_t i=0; i<temp2.size(); ++i){
    inside->push_back(temp2[i]);
  }
}

void discreteFront::autoIntersectNew(std::vector<size_t> loop, std::vector<size_t> inter, std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags){
  size_t n = loop.size();
  std::vector<std::vector<size_t>> out_loops;
  std::vector<int> out_loops_tags;

  int *flag = (int*) calloc(n, sizeof(int));
  for (size_t i=0; i<inter.size(); ++i){
    std::vector<size_t>::iterator it = std::find(loop.begin(), loop.end(), inter[i]);
    std::vector<size_t>::iterator itp1 = std::find(it+1, loop.end(), inter[i]);
    flag[it-loop.begin()] = itp1-loop.begin()+1;
    flag[itp1-loop.begin()] = it-loop.begin()+1;
  }
  
  while(std::find(flag, flag+n, 0) != flag+n){
    size_t current_id = std::find(flag, flag+n, 0) - flag;
    std::vector<size_t> temp;
    temp.push_back(loop[current_id]);
    flag[current_id] = -1;
    size_t start = loop[current_id];
    size_t next = -1;
    while(start != next){
      
      if(flag[current_id+1]>0){ //intersection case
        next = loop[(current_id+1)%n];
        current_id = flag[current_id+1]-1;
        // temp.push_back(next);
        next = loop[(current_id)%n];
      } else {                  //normal case 
        flag[(current_id+1)%n] = -1;
        next = loop[(current_id+1)%n];
        current_id = (current_id+1)%n;
      }
      // printf("current_id = %d\n", current_id);
      temp.push_back(next);

    }
    
    std::vector<double> temp_pos;
    for(size_t i=0; i<temp.size(); ++i){
      temp_pos.push_back(pos[3*temp[i]]);
      temp_pos.push_back(pos[3*temp[i]+1]);
      temp_pos.push_back(pos[3*temp[i]+2]);
    }
    
    if(loopOrientation(temp_pos) < 0){
      out_loops_tags.push_back(1);
    } else {
      std::reverse(temp.begin(), temp.end());
      out_loops_tags.push_back(-1);
    }
    out_loops.push_back(temp);
  }

  // compute local tree
  T_node* tree = newT_node(out_loops.size(), -1);
  for(size_t i=0; i<out_loops.size(); ++i){
    T_node *leaf = newT_node(i, out_loops_tags[i]);
    tree->leafs.push_back(leaf);
  }

  std::vector<T_node*> todo;
  std::vector<T_node*> new_todo;
  todo.push_back(tree);
  while(todo.size()>0){
    for(size_t td=0; td<todo.size(); td++){
      T_node *level = todo[td];
      for(size_t i=0; i<level->leafs.size(); ++i){
        for(size_t j=0; j<level->leafs.size(); ++j){
          if(j==i) continue;
          //nodes from loop j
          std::vector<size_t> loopj = out_loops[level->leafs[j]->id];
          // one node from loop i
          size_t nodei = out_loops[level->leafs[i]->id][0];
          size_t id_ = 0;
          while(std::find(inter.begin(), inter.end(), nodei) != inter.end()){ //find node that is not an intersection
            id_++;
            nodei = out_loops[level->leafs[i]->id][id_];
          }

          if(insideList(loopj, &pos[3*nodei])){ //check if leafs i is in leafs j
            printf("leaf %d is in leaf %d\n", level->leafs[i]->id, level->leafs[j]->id);
            level->leafs[j]->leafs.push_back(level->leafs[i]);
            level->leafs.erase(level->leafs.begin()+i);
            i--;
            new_todo.push_back(level->leafs[j]);
            break;
          }
        }
      }
    }
    todo = new_todo;
    new_todo.clear();
  }

  int *flag_loop = (int*) calloc(out_loops.size(), sizeof(int));

  // go through the tree
  // start with the first leaf
  std::vector<T_node*> state;
  state.push_back(tree);
  while(state.back()->leafs.size()>0){
    state.push_back(state.back()->leafs[0]);
  }
  //go through leafs
  while(state.size()>0){
    T_node *current = state.back();
    if(state.size()>1){
      if(current->tag != state[state.size()-2]->tag){
        current->data = 1;
        flag_loop[current->id] = 1;
      }else{
        current->data = -1;
        flag_loop[current->id] = -1;
      }
    }
    
    if(current->leafs.size()>0){
      int id_ = -1;
      for(int i=0; i<current->leafs.size(); ++i){
        if(current->leafs[i]->data == 0){
          id_ = i;
        }
      }
      if(id_ == -1){
        state.pop_back();
        continue;
      }
      state.push_back(current->leafs[id_]);
      while(state.back()->leafs.size()>0){
        state.push_back(state.back()->leafs[0]);
      }
    } else {
      state.pop_back();
    }
  }

  //print tree
  printf("tree: %d leafs \n", tree->leafs.size());
  for(size_t i=0; i<tree->leafs.size(); ++i){
    printf("leaf %d, data = %d, tag = %d\n", i, tree->leafs[i]->data, tree->leafs[i]->tag);
    for(size_t j=0; j<tree->leafs[i]->leafs.size(); ++j){
      printf("  leaf %d, data = %d, tag = %d\n", tree->leafs[i]->leafs[j]->id, tree->leafs[i]->leafs[j]->data, tree->leafs[i]->leafs[j]->tag);
    }
  }

  printf("out_loops size = %d\n", out_loops.size());
  for(size_t i=0; i<out_loops.size(); ++i){
    printf("loop %d, tag = %d\n", i, out_loops_tags[i]);
    for(size_t j=0; j<out_loops[i].size(); ++j){
      printf("%d, ", out_loops[i][j]);
    }
    printf("\n");
  }

  for(size_t i=0; i<out_loops.size(); ++i){
    if(flag_loop[i] == 1){
      new_loops->push_back(out_loops[i]);
      new_loops_tags->push_back(out_loops_tags[i]);
    }
  }

  
}

void discreteFront::interactionsOrder(std::vector<std::pair<size_t,size_t>> interactions, std::vector<std::pair<size_t,size_t>> *ordered){
  std::vector<size_t> order;
  int *flag = (int*) calloc(interactions.size(), sizeof(int));

  printf("interactions size = %d\n", interactions.size());
  for(size_t i=0; i<interactions.size(); ++i){
    printf("%d - %d\n", interactions[i].first, interactions[i].second);
  }

  //sort interactions vector
  auto it = std::unique(interactions.begin(), interactions.end(), [](const auto a, const auto b) {
    if((a.first == b.first && a.second == b.second) || (a.first == b.second && a.second == b.first)){
      return 1;
    } else {
      return 0;
    }
  });
  interactions.erase(it, interactions.end());

  for(size_t i=0; i<interactions.size(); ++i){
    if(interactions[i].first == interactions[i].second){
      order.push_back(i);
      flag[i] = 1;
    }
  }

  std::vector<T_node*> todo;
  std::vector<T_node*> new_todo;
  size_t level = 0;
  size_t *levels = (size_t*) calloc(interfaces.size(), sizeof(size_t));
  todo.push_back(Tree);
  levels[Tree->id] = level;
  while(todo.size()>0){
    level++;
    for(size_t i=0; i<todo.size(); ++i){
      T_node *current = todo[i];
      for(size_t j=0; j<current->leafs.size(); ++j){
        new_todo.push_back(current->leafs[j]);
        levels[current->leafs[j]->id] = level;
      }
    }
    todo = new_todo;
    new_todo.clear();
  }

  int *interaction_level = (int*) calloc(interactions.size(), sizeof(int));
  for(size_t i=0; i<interactions.size(); ++i){
    if(flag[i] == 1) continue;
    size_t level1 = levels[interactions[i].first];
    size_t level2 = levels[interactions[i].second];
    if(level1>level2){
      size_t temp = interactions[i].first;
      interactions[i].first = interactions[i].second;
      interactions[i].second = temp;
    }
    interaction_level[i] = (level1+level2)/2;
  }

  std::vector<std::pair<size_t, size_t>> index;
  for( size_t i=0; i<interactions.size(); ++i){
    if(flag[i] == 0){
      index.push_back(std::make_pair(i, interaction_level[i]));
    }
  }

  std::sort(std::begin(index), std::end(index), [](const auto a, const auto b)
  { 
    return a.second < b.second; 
  });

  for(size_t i=0; i<index.size(); ++i){
    order.push_back(index[i].first);
  }
  
  for(size_t i=0; i<order.size(); ++i){
    ordered->push_back(interactions[order[i]]);
  }
}

void discreteFront::manageIntersection(std::vector<std::pair<size_t,size_t>> ordered, std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags, std::vector<int> loops_sense, std::vector<size_t> inter_markers, std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags, std::vector<int> *new_loops_sense){
  std::vector<int> flag_inter;
  for(size_t i=0; i<inter_markers.size(); ++i){
    flag_inter.push_back(0);
  }
  
  std::reverse(ordered.begin(), ordered.end());
  std::vector<int> to_keep;
  for(size_t i=0; i<loops.size(); ++i){
    to_keep.push_back(1);
  }

  printf("loops before intersection management\n");
  for(size_t i=0; i<loops.size(); ++i){
    printf("loop %d, tag = %d\n", i, loops_tags[i]);
    for(size_t j=0; j<loops[i].size(); ++j){
      printf("%d, ", loops[i][j]);
    }
    printf("\n");
  }

  printf("ordered size = %d\n", ordered.size());
  for(size_t i=0; i<ordered.size(); ++i){
    printf("%d - %d\n", ordered[i].first, ordered[i].second);
    printf(" with sense : %d - %d\n", loops_sense[ordered[i].first], loops_sense[ordered[i].second]);
  }

  while(ordered.size()>0){
    std::pair<size_t, size_t> interaction = ordered.back();
    ordered.pop_back();
    if(interaction.first == interaction.second){      //auto-intersection
      printf("auto-intersection : %d\n", interaction.first);
      int tag1 = loops_tags[interaction.first];
      std::vector<std::vector<size_t>> auto_loops;
      std::vector<int> auto_loops_tags;
      std::vector<size_t> loop = loops[interaction.first];
      std::vector<size_t> temp = loop;
      std::sort(temp.begin(), temp.end());
      auto it = adjacent_find(temp.begin(), temp.end());
      std::vector<size_t> inter;
      while(it != temp.end()){
        inter.push_back(*it);
        it = adjacent_find(it+1, temp.end());
      }

      printf("inter size = %d\n", inter.size());
      for(size_t i=0; i<inter.size(); ++i){
        printf("%d, ", inter[i]);
      }
      printf("\n");
      printf("loop size = %d\n", loop.size());
      for(size_t i=0; i<loop.size(); ++i){
        printf("%d, ", loop[i]);
      }
      printf("\n");
      autoIntersectNew(loop, inter, &auto_loops, &auto_loops_tags);
      // add auto_loops in loops
      int tag_pos, tag_neg;
      if(tag1 == 1){
        tag_pos = 1;
        tag_neg = 0;
      } else {
        tag_pos = 0;
        tag_neg = 1;
      }
      size_t start_id = loops.size();
      size_t n_auto_loops = auto_loops.size();

      for(size_t i=0; i<auto_loops.size(); ++i){
        loops.push_back(auto_loops[i]);
        if(auto_loops_tags[i] == 1){
          loops_tags.push_back(tag_pos);
        } else {
          loops_tags.push_back(tag_neg);
        }
        to_keep.push_back(1);
      }
      to_keep[interaction.first] = 0;
      //update ordered
      for(size_t i=0; i<ordered.size(); ++i){
        if(ordered[i].first == interaction.first){
          for(size_t j=0; j<n_auto_loops; ++j){
            std::vector<size_t> temp1 = auto_loops[j];
            std::sort(temp1.begin(), temp1.end());
            std::vector<size_t> temp2 = loops[ordered[i].first];
            std::sort(temp2.begin(), temp2.end());
            if(std::set_intersection(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), temp1.begin()) != temp1.begin()){
              ordered.push_back(std::make_pair(start_id+j, ordered[i].second));
            }
          }
        }
        if(ordered[i].second == interaction.first){
          for(size_t j=0; j<n_auto_loops; ++j){
            std::vector<size_t> temp1 = auto_loops[j];
            std::sort(temp1.begin(), temp1.end());
            std::vector<size_t> temp2 = loops[ordered[i].first];
            std::sort(temp2.begin(), temp2.end());
            if(std::set_intersection(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), temp1.begin()) != temp1.begin()){
              ordered.push_back(std::make_pair(ordered[i].first, start_id+j));
            }
          }
        }
      }

    } else{
      int tag1 = loops_tags[interaction.first];
      int tag2 = loops_tags[interaction.second];
      std::vector<size_t> loop1 = loops[interaction.first];
      std::vector<size_t> loop2 = loops[interaction.second];

      // find intersections in loop1 and loop2
      std::vector<size_t> inter1(10);
      std::vector<size_t> inter2(10);
      auto temp1 = loop1;
      auto temp2 = loop2;
      std::sort(temp1.begin(), temp1.end());
      std::sort(temp2.begin(), temp2.end());
      auto it1 = std::set_intersection(temp1.begin(), temp1.end(), inter_markers.begin(), inter_markers.end(), inter1.begin());
      inter1.resize(it1-inter1.begin());
      auto it2 = std::set_intersection(temp2.begin(), temp2.end(), inter_markers.begin(), inter_markers.end(), inter2.begin());
      inter2.resize(it2-inter2.begin());

      std::vector<size_t> inter;
      std::sort(inter1.begin(), inter1.end());
      std::sort(inter2.begin(), inter2.end());
      std::set_intersection(inter1.begin(), inter1.end(), inter2.begin(), inter2.end(), std::back_inserter(inter));
      for(size_t i=0; i<inter.size(); ++i){
        for(size_t j=0; j<inter_markers.size(); ++j){
          if(inter[i]==inter_markers[j]){
            if(flag_inter[j]==1){
              inter.erase(inter.begin()+i);
              i--;
            }
          }
        }
      }

      printf("flag \n");
      for(size_t i=0; i<flag_inter.size(); ++i){
        printf("%d, ", flag_inter[i]);
      }
      printf("\n");

      printf("inter size = %d\n", inter.size());
      for(size_t i=0; i<inter.size(); ++i){
        printf("%d, ", inter[i]);
      }

      if(tag1 == tag2){               //same tag = merge
        ordered.push_back(interaction);
        choose2Inter(loop1, loop2, &inter, true);
        
        // if(inter.size()==0) continue;
        for(size_t i=0; i<inter_markers.size(); ++i){
          if(inter_markers[i] == inter[0] || inter_markers[i] == inter[1]){
            flag_inter[i] = 1;
          }
        }
        
        std::vector<size_t> merged;
        mergeLoop(loop1, loop2, inter, &merged);
        
        //add merge in loops
        size_t id_merged = loops.size();
        loops.push_back(merged);
        loops_tags.push_back(tag1);
        loops_sense.push_back(1);
        //update loops to keep
        to_keep.push_back(1);
        to_keep[interaction.first] = 0;
        to_keep[interaction.second] = 0;
        //update ordered
        for(size_t i=0; i<ordered.size(); ++i){
          if(ordered[i].first == interaction.first || ordered[i].first == interaction.second ){
            ordered[i].first = id_merged;
          }
          if(ordered[i].second == interaction.first || ordered[i].second == interaction.second ){
            ordered[i].second = id_merged;
          }
        }
        printf("updated ordered\n");
        for(size_t i=0; i<ordered.size(); ++i){
          printf("%d - %d\n", ordered[i].first, ordered[i].second);
        }

      } else {                            //different tag = minus
        printf("minus \n");
        
        std::vector<size_t> minus;
        choose2Inter(loop1, loop2, &inter, false);
        if(inter.size()==0) continue;
        ordered.push_back(interaction);
        printf("inter size = %d ; inter = %d, %d \n", inter.size(), inter[0], inter[1]);
        for(size_t i=0; i<inter.size(); ++i){
          int founded = 0;
          for(size_t j=0; j<inter_markers.size(); ++j){
            if(inter_markers[j] == inter[i]){
              flag_inter[j] = 1;
              founded = 1;
              break;
            }
          }
          if(founded==0){
            inter_markers.push_back(inter[i]);
            flag_inter.push_back(1);
          }
        }
        
        printf("flag inter : \n");
        for(size_t i=0; i<flag_inter.size(); ++i){
          printf("%d, ", flag_inter[i]);
        }
        printf("\n");
        printf("inter markers = \n");
        for(size_t i=0; i<inter_markers.size(); ++i){
          printf("%d, ", inter_markers[i]);
        }
        printf("\n");

        if(loops_sense[interaction.first] == 1){
          printf("loop1Minusloop2\n");
          loop1Minusloop2(loop1, loop2, inter, &minus);
          //update loops to keep
          to_keep.push_back(1);
          to_keep[interaction.first] = 0;
          to_keep[interaction.second] = 0;
          loops_tags.push_back(tag1);
        } else {
          printf("loop1Minusloop2_inside\n");
          loop1Minusloop2_inside(loop1, loop2, inter, &minus);
          //update loops to keep
          to_keep.push_back(1);
          to_keep[interaction.first] = 1;
          to_keep[interaction.second] = 0;
          loops_tags.push_back(tag2);
        }
        //add minus in loops
        size_t id_minus = loops.size();
        loops.push_back(minus);
        
        loops_sense.push_back(1);
        
        //update ordered
        for(size_t i=0; i<ordered.size(); ++i){
          if(ordered[i].first == interaction.second ){
            ordered[i].first = id_minus;
          }
          if(ordered[i].second == interaction.second ){
            ordered[i].second = id_minus;
          }
        }
      }
    }
  }

  for(size_t i=0; i<to_keep.size(); ++i){
    if(to_keep[i] == 1){
      new_loops->push_back(loops[i]);
      new_loops_tags->push_back(loops_tags[i]);
      new_loops_sense->push_back(loops_sense[i]);
    }
  }

  printf("loops after intersection management\n");
  for(size_t i=0; i<new_loops->size(); ++i){
    printf("loop %d, tag = %d\n", i, (*new_loops_tags)[i]);
    for(size_t j=0; j<(*new_loops)[i].size(); ++j){
      printf("%d, ", (*new_loops)[i][j]);
    }
    printf("\n");
  }
}

void discreteFront::choose2Inter(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> *inter, bool start_outside){
  printf("\n \n \n in choose two inter : start_outside = %d \n \n \n", start_outside);
  if(inter->size() == 0){
    return;
  }

  printf("inter size = %d\n", inter->size());
  for(size_t i=0; i<inter->size(); ++i){
    printf("%d, ", (*inter)[i]);
  }
  printf("\n");

  std::vector<size_t> temp;
  for(size_t i=0; i<inter->size(); ++i){
    int is_triple = 0;
    for(size_t j=0; j<triple_points.size(); ++j){
      if((*inter)[i] == triple_points[j].marker){
        is_triple = 1;
      }
    }
    if(is_triple == 0){
      temp.push_back((*inter)[i]);
      break;
    }
  }

  if(temp.size() == 0){
    inter->clear();
    return;
  } 
  printf("temp = %d\n", temp[0]);

  size_t n1 = loop1.size();
  size_t n2 = loop2.size();

  size_t start_id = std::find(loop2.begin(), loop2.end(), temp[0]) - loop2.begin();
  size_t next_id = (start_id+1)%n2;

  size_t next = loop2[next_id];
  
  double P[2];
  P[0] = pos[3*next];
  P[1] = pos[3*next+1];
  int sense = 0;
  if(insideList(loop1, P) && start_outside==true){
    sense = 1;
  } else if(!insideList(loop1, P) && start_outside==false){
    sense = 1;
  } else{
    sense = -1;
  }

  printf("sense = %d\n", sense);

  // loop through
  size_t it1 = (start_id+sense+n2)%n2;
  size_t start = loop2[it1];
  printf("start = %d \n", start);
  printf("next = %d \n", next);
  while(true){
    if(std::find(inter->begin(), inter->end(), loop2[it1]) != inter->end()){
      temp.push_back(loop2[it1]);
      if(temp.size() == 2){
        break;
      }
      it1 = (it1+sense+n2)%n2;
    } else {
      for(size_t i=0; i<triple_points.size(); ++i){
        if(loop2[it1] == triple_points[i].marker){
          temp.push_back(loop2[it1]);
          if(temp.size() == 2){
            break;
          }
        }
      }
      if(temp.size() == 2){
        break;
      }
      it1 = (it1+sense+n2)%n2;
      if(loop2[it1] == start){
        inter->clear();
        for(size_t i=0; i<temp.size(); ++i){
          inter->push_back(temp[i]);
        }
        return;
      }
      
    } 
  }

  inter->clear();
  inter->push_back(temp[0]);
  inter->push_back(temp[1]);
  return;
}
  

void discreteFront::loops2Interfaces(std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags, std::vector<int> loops_sense, std::vector<interface> *new_interfaces){
  // define a taged vector to detect which markers are found in multiple loops
  size_t n_markers = pos.size()/3;
  std::vector<std::vector<std::pair<size_t, size_t>>> taged;
  taged.resize(n_markers);
  for(size_t i=0; i<loops.size(); ++i){
    for(size_t j=0; j<loops[i].size(); ++j){
      taged[loops[i][j]].push_back(std::make_pair(i,j));
    }
  }
  std::vector<std::pair<size_t,size_t>> triple_pair;
  std::vector<triple_p> new_triple_points;
  for(size_t i=0; i<loops.size(); ++i){
    size_t ni = loops[i].size();
    std::vector<size_t> markers;
    
    std::vector<triple_p> triple;
    std::vector<size_t> tp_list;
    printf("loop i = %d, tag = %d, sense = %d \n", i, loops_tags[i], loops_sense[i]);
    for(size_t j=0; j<loops[i].size(); ++j){      // go through the loop
      markers.push_back(loops[i][j]);             // add markers in case no triple points
      printf(" %d, ", loops[i][j]);
      if(taged[loops[i][j]].size()>1){            //detect triple points
        std::vector<std::pair<size_t, size_t>> taged_ij = taged[loops[i][j]];
        std::pair<size_t, size_t> pair_i; 
        std::vector<std::pair<size_t, size_t>> pair_j;

        int min_index = 100;
        size_t k_min = 100;
        
        for(size_t k=0; k<taged_ij.size(); ++k){                // find taged for i -> pair_i
          if(taged_ij[k].first == i){
            pair_i = taged_ij[k];
          } else {
            int ind = std::find(priority.begin(), priority.end(), loops_tags[taged_ij[k].first]) - priority.begin();
            pair_j.push_back(taged_ij[k]);                      // other in pair_j
            if(ind < min_index){                                // find highest priority other than for i -> pair_j[k_min]
              min_index = ind;
              k_min = pair_j.size()-1;
            }
          }
        }
        
        // no triple point if i is the highest in priority
        int index = std::find(priority.begin(), priority.end(), loops_tags[i]) - priority.begin();
        if(index<min_index) continue;

        // no triple point if i is going in the same direction as an other interface
        size_t neigh_i[2] = {loops[pair_i.first][(pair_i.second-1+ni)%ni], loops[pair_i.first][(pair_i.second+1+ni)%ni]};
        bool same_direction = 0;
        for(size_t k=0; k<pair_j.size(); ++k){
          size_t neigh_k[2] = {loops[pair_j[k].first][(pair_j[k].second-1+ni)%ni], loops[pair_j[k].first][(pair_j[k].second+1+ni)%ni]};
          if((neigh_k[0]==neigh_i[0] && neigh_k[1]==neigh_i[1]) || (neigh_k[0]==neigh_i[1] && neigh_k[1]==neigh_i[0])){
            same_direction = 1;
          }
        }
        if(same_direction) continue;

        // determine sense of triple point with the highest priority loop
        size_t neigh_min[2] = {loops[pair_j[k_min].first][(pair_j[k_min].second-1+ni)%ni], loops[pair_j[k_min].first][(pair_j[k_min].second+1+ni)%ni]}; 
        if(neigh_i[0]==neigh_min[0] || neigh_i[1]==neigh_min[1]){
          triple_p temp = triple_p(loops[i][j], i, j, loops_tags[i], &pos[3*loops[i][j]]);
          temp.id_on_interface = pair_j[k_min].first;
          temp.id_on_marker = pair_j[k_min].second;
          temp.sense = 1;
          triple.push_back(temp);
          tp_list.push_back(j);
          triple_pair.push_back(std::make_pair(i, loops[i][j]));
        } else if(neigh_i[1] == neigh_min[0] || neigh_i[0] == neigh_min[1]){
          triple_p temp = triple_p(loops[i][j], i, j, loops_tags[i], &pos[3*loops[i][j]]);
          temp.id_on_interface = pair_j[k_min].first;
          temp.id_on_marker = pair_j[k_min].second;
          temp.sense = -1;
          triple.push_back(temp);
          tp_list.push_back(j);
          triple_pair.push_back(std::make_pair(i, loops[i][j]));
        } 
        
      }
    }

    printf( "in interface : triple size = %d\n \n", triple.size());
    
    if(triple.size()==0){     // no triple point = easy interface
      interface tmp_interface = interface(i, loops_tags[i], markers);
      tmp_interface.sense = loops_sense[i];
      new_interfaces->push_back(tmp_interface);
    } else{
      markers.clear();
      interface tmp_interface = interface(i, loops_tags[i], markers);  
      tmp_interface.sense = loops_sense[i];

      //starting triple point
      triple_p current;
      for(size_t j=0; j<triple.size(); ++j){
        current = triple[j];
        size_t nj = loops[current.id_on_interface].size();
        if(loops[i][(current.id_marker+1)%ni] != loops[current.id_on_interface][(current.id_on_marker+current.sense+nj)%nj]){
          break;
        }
      }
      
      size_t iter = 0;
      size_t id_triple = triple_points.size();
      tmp_interface.triple.push_back(id_triple);
      triple_points.push_back(current);
      while(tmp_interface.triple.size()!=triple.size()){

        if(tmp_interface.triple.size()%2 == 1){                     // only add markers for between odd and even number of triple point
          markers.push_back(loops[i][(current.id_marker+iter)%ni]);
        }

        iter++;
        if(std::find(tp_list.begin(), tp_list.end(), (current.id_marker+iter)%ni)!=tp_list.end()){ // next triple point
          for(size_t k=0; k<triple.size(); ++k){
            if((current.id_marker+iter)%ni == triple[k].id_marker){
              size_t id_triple = triple_points.size();
              tmp_interface.triple.push_back(id_triple);
              triple_points.push_back(triple[k]);
              markers.push_back(loops[i][(current.id_marker+iter)%ni]);
              iter = 0;
              break;
            }
          }  
        }
      }

      tmp_interface.markers = markers;
      new_interfaces->push_back(tmp_interface);
    }
    for(size_t j=0; j<triple.size(); ++j){
      new_triple_points.push_back(triple[j]);
    }
  }

  for(size_t i=0; i<new_triple_points.size(); ++i){
    size_t marker = new_triple_points[i].marker;
    size_t ii = new_triple_points[i].id_interface;
    for(size_t j=0; j<(*new_interfaces)[ii].markers.size(); ++j){
      if(marker == (*new_interfaces)[ii].markers[j]){
        new_triple_points[i].id_marker = j;
        break;
      }
    }

    size_t i_on_i = new_triple_points[i].id_on_interface;
    for(size_t j=0; j<(*new_interfaces)[i_on_i].markers.size(); ++j){
      if(marker == (*new_interfaces)[i_on_i].markers[j]){
        new_triple_points[i].id_on_marker = j;
        break;
      }
    }
  }

  triple_points = new_triple_points;

  // for(size_t i=0; i<new_interfaces->size(); ++i){
  //   for(size_t j=0; j<(*new_interfaces)[i].markers.size(); ++j){
  //     for(size_t k=0; k<triple_pair.size(); ++k){
  //       if((*new_interfaces)[i].markers[j] == triple_pair[k].second && i != triple_pair[k].first){
  //         (*new_interfaces)[i].markers.erase((*new_interfaces)[i].markers.begin()+j);
  //       }
  //     }
  //   }
  // }

}

void discreteFront::interfaces2Loops(std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags, std::vector<int> *new_loops_sense){
  printf("triple points = \n");
  for(size_t i=0; i<triple_points.size(); ++i){
    printf(" marker = %d, sense = %d \n", triple_points[i].marker, triple_points[i].sense); 
  }
  for(size_t i=0; i<interfaces.size(); ++i){
    printf("markers of interface %d = ", i);
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      printf("%d, ", interfaces[i].markers[j]);
    }
    printf("\n");
    std::vector<size_t> temp_loop;
    if(interfaces[i].triple.size()==0){ // if no triple point -> easy: loop = markers
      temp_loop = interfaces[i].markers;
    } else {
      std::vector<size_t> ms = interfaces[i].markers;
      std::vector<size_t> tp_list;
      for(size_t j=0; j<interfaces[i].triple.size(); ++j){         // stock all triple point in tp_list
        tp_list.push_back(triple_points[interfaces[i].triple[j]].marker);
      }

      printf("tp list : ");
      for(size_t j=0; j<tp_list.size(); ++j){
        printf("%d, ", tp_list[j]);
      }
      printf("\n");

      size_t start_i = 0;  
      while(true){
        if(std::find(tp_list.begin(), tp_list.end(), ms[start_i])==tp_list.end()){
          break;
        }
        start_i++;
      }
      
      size_t n_m = ms.size();    
      for(size_t j=0; j<ms.size(); ++j){                            // loop on the markers
        size_t marker = ms[(start_i+j)%n_m];
        temp_loop.push_back(marker);
        auto it = std::find(tp_list.begin(), tp_list.end(), marker);
        printf("%d, ", marker);
        if(it!=tp_list.end()){                                      // if a marker is a triple node
          size_t idx = it-tp_list.begin();
          printf("\n idx in interfaces2loops = %d \n", idx);
          printf("size triple of interface %d = %d \n", i, interfaces[i].triple.size());
          triple_p tp = triple_points[interfaces[i].triple[idx]];
          size_t iter = 1;
          std::vector<size_t> on_ms = interfaces[tp.id_on_interface].markers;    // take the markers of interface on which the triple point is
          size_t on_n = on_ms.size();
          while(true){                                              
            size_t current = on_ms[(tp.id_on_marker+iter*tp.sense+on_n)%on_n];     // go through the reference markers in the sense given by the tp
            printf("current = %d \n", current);
            auto it = std::find(tp_list.begin(), tp_list.end(), current);
            if(it!=tp_list.end()){       
              printf("found\n");   
              temp_loop.push_back(current);                                    // until finding an other tp
              ++j;
              break;
            }else{
              temp_loop.push_back(current);
              iter++;
            }
          }
        }
        
      }
    }
    new_loops->push_back(temp_loop);
    new_loops_tags->push_back(interfaces[i].tag);
    new_loops_sense->push_back(interfaces[i].sense);
  }
  printf("new loops : \n");
  for(size_t j=0; j<new_loops->size(); ++j){
    printf("loop %d, tag = %d, sense = %d \n", j, (*new_loops_tags)[j], (*new_loops_sense)[j]);
    for(size_t k=0; k<(*new_loops)[j].size(); ++k){
      printf("%d, ", (*new_loops)[j][k]);
    }
    printf("\n");
  }
}

void discreteFront::createTree(){
  // find initial t_node
  size_t initial_interface = -1;
  for(size_t i=0; i<interfaces.size(); ++i){
    int inside = 0;
    for(size_t j=0; j<interfaces.size(); ++j){
      int inside_ij = insideList(interfaces[j].markers, &pos[3*interfaces[i].markers[0]]);
      if(inside_ij == 1){
        inside = 1;
      }
    }
    if(inside==0){
      initial_interface = i;
    }
  }

  T_node *init = newT_node(initial_interface, interfaces[initial_interface].tag);
  for(size_t i=0; i<interfaces.size(); ++i){
    if(i==initial_interface) continue;
    T_node *node_i = newT_node(i, interfaces[i].tag);
    init->leafs.push_back(node_i);
  }
  
  std::vector<T_node*> todo;
  std::vector<T_node*> new_todo;
  todo.push_back(init);
  while(todo.size()>0){
    for(size_t td=0; td<todo.size(); td++){
      T_node *level = todo[td];
      for(size_t i=0; i<level->leafs.size(); ++i){
        for(size_t j=0; j<level->leafs.size(); ++j){
          if(j==i) continue;
          if(insideList(interfaces[level->leafs[j]->id].markers, &pos[3*interfaces[level->leafs[i]->id].markers[0]])){

            level->leafs[j]->leafs.push_back(level->leafs[i]);
            level->leafs.erase(level->leafs.begin()+i);
            i--;
            new_todo.push_back(level->leafs[j]);
            break;
          }
        }
      }
    }
    todo = new_todo;
    new_todo.clear();
  }

  Tree = init;
}

void discreteFront::renumberLoops(std::vector<std::vector<size_t>> loops, std::vector<std::vector<size_t>> *new_loops, std::vector<double> *new_pos){
  size_t iter = 0;
  size_t max = 0; 
  for(size_t i=0; i<loops.size(); ++i){
    std::vector<size_t> v = loops[i];
    size_t max_i = *std::max_element(loops[i].begin(),loops[i].end());
    if(max_i>max){
      max = max_i;
    }
  }
  std::vector<int> map(max, -1);
  std::vector<double> new_p;
  for(size_t i=0; i<loops.size(); ++i){
    std::vector<size_t> new_loop;
    for(size_t j=0; j<loops.size(); ++j){
      if(map[loops[i][j]]==-1){
        new_loop.push_back(iter);
        map[loops[i][j]] = iter;

        new_p.push_back(pos[3*loops[i][j]]); 
        new_p.push_back(pos[3*loops[i][j]]);
        new_p.push_back(0.0);

        iter++;
      } else {
        new_loop.push_back(map[loops[i][j]]);
      }
    }
    new_loops->push_back(new_loop);
  }
  *new_pos = new_p;
}

void discreteFront::renumberInterfaces(){
  size_t max = 0; 
  for(size_t i=0; i<interfaces.size(); ++i){
    interface ii = interfaces[i];
    size_t max_i = *std::max_element(ii.markers.begin(),ii.markers.end());
    if(max_i>max){
      max = max_i;
    }
  }
  std::vector<int> map(max+1, -1);
  std::vector<double> new_p;

  size_t iter = 0;
  for(size_t i=0; i<interfaces.size(); ++i){
    interface ii = interfaces[i];
    std::vector<size_t> new_markers;
    for(size_t j=0; j<ii.markers.size(); ++j){
      size_t m = ii.markers[j];
      if(map[m]==-1){
        new_markers.push_back(iter);
        map[m] = iter;

        new_p.push_back(pos[3*m]); 
        new_p.push_back(pos[3*m+1]);
        new_p.push_back(0.0);

        iter++;
      } else {
        new_markers.push_back(map[m]);
      }
    }
    interfaces[i].markers = new_markers;
  }
  pos = new_p;

  for(size_t i=0; i<fn.size(); ++i){
    if(map[fn[i].m1]>=0 && map[fn[i].m2]>=0){
      fn[i].m1 = map[fn[i].m1];
      fn[i].m2 = map[fn[i].m2];
    }
  }

  for(size_t i=0; i<triple_points.size(); ++i){
    if(map[triple_points[i].marker]>=0){
      triple_points[i].marker = map[triple_points[i].marker];
    }
    size_t ii = triple_points[i].id_interface;
    for(size_t j=0; j<interfaces[ii].markers.size(); ++j){
      if(interfaces[ii].markers[j] == triple_points[i].marker){
        triple_points[i].id_marker = j;
      }
    }
    size_t ioni = triple_points[i].id_on_interface;
    for(size_t j=0; j<interfaces[ioni].markers.size(); ++j){
      if(interfaces[ioni].markers[j] == triple_points[i].marker){
        triple_points[i].id_on_marker = j;
      }
    }
  }

  //printf interface
  for(size_t i=0; i<interfaces.size(); ++i){
    printf("interface %d, tag = %d, sense = %d, markers = ", i, interfaces[i].tag, interfaces[i].sense);
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      printf("%d, ", interfaces[i].markers[j]);
    }
    printf("\n");
    printf("triple = ");
    for(size_t j=0; j<interfaces[i].triple.size(); ++j){
      printf("%d, ", triple_points[interfaces[i].triple[j]].marker);
    }
  }
  printf("\n");

}



int discreteFront::insideList(std::vector<size_t> loop, double P[2]){
  int wn = 0;
  size_t n = loop.size();
  for (size_t i=0 ; i<loop.size() ; ++i){
    double aa[2] = {pos[3*loop[i]],pos[3*loop[i]+1]};
    double bb[2] = {pos[3*loop[(i+1)%n]],pos[3*loop[(i+1)%n]+1]};
    double area = robustPredicates::orient2d(aa,bb,P); 
    if(aa[1]<= P[1]){
      if (bb[1] > P[1] && area < 0)wn++;
    }
    else if(bb[1]<= P[1]){
      if (area > 0)wn--;
    }
  }
  if (wn != 0){
    return 1;
  }
  return 0;
}

int computeIntersection(double a1[2], double a2[2], double a3[2], double a4[2], double *inter, double *param){
  double a143 = robustPredicates::orient2d(a1,a4,a3);
  double a243 = robustPredicates::orient2d(a2,a4,a3);  
  double eps = 1e-10;
  if((a143>eps && a243<-eps) || (a143<-eps && a243>eps)){
    double a123 = robustPredicates::orient2d(a1,a2,a3);
    double a124 = robustPredicates::orient2d(a1,a2,a4);
    if((a123>eps && a124<-eps) || (a123<-eps && a124>eps)){
      double t = fabs(a143)/(fabs(a143)+fabs(a243));
      inter[0] = a1[0] + t*(a2[0]-a1[0]);
      inter[1] = a1[1] + t*(a2[1]-a1[1]);
      param[0] = t;
      return 1;
    }
  } 

  return 0; 
  
}

double loopOrientation(std::vector<double> pos){
  double tot = 0;
  int n = pos.size()/3;
  for(int i=0; i<n; ++i){
    double a[2] = {pos[3*i], pos[3*i+1]};
    double b[2] = {pos[3*((i+1)%n)], pos[3*((i+1)%n)+1]};
    tot += (b[0]-a[0])*(b[1]+a[1]);
  }
  return tot;
}




void discreteFront::moveFromV (double dt, const std::vector<SVector3> &v, bool bnd){
  size_t n_ = v.size();
  // buildSpatialSearchStructure ();

  size_t n = v.size();
  std::vector<double> target(pos);
  std::vector<bool> found(n, false);

  //move markers except triple points
  printf("before loop\n");
  size_t iter=0;
  std::vector<size_t> map_triple;
  map_triple.resize(triple_points.size());
  for (size_t i=0;i<interfaces.size();++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      size_t m_ij = interfaces[i].markers[j];
      bool is_triple = false;
      for(size_t j=0; j<triple_points.size(); ++j){
        size_t m = interfaces[triple_points[j].id_interface].markers[triple_points[j].id_marker];
        if(m_ij == m){
          is_triple = true;
          map_triple[j] = iter;
          break;
        }
      }
      if(is_triple){ 
        iter++;
        continue;
      }
      target[3*m_ij] += v[iter].x()*dt;
      target[3*m_ij+1] += v[iter].y()*dt;
      target[3*m_ij+2] = 0;
      iter++;
    }
    
  }
  printf("after loop\n");
  // move triple points
  for(size_t i=0; i<triple_points.size(); ++i){
    size_t m = interfaces[triple_points[i].id_interface].markers[triple_points[i].id_marker];
    printf("triple point %d, %d, %d\n", triple_points[i].id_interface, triple_points[i].id_marker, m);
    size_t id_on_interface = triple_points[i].id_on_interface;
    size_t n_on_interface = interfaces[id_on_interface].markers.size();
    size_t neigh1 = interfaces[id_on_interface].markers[(triple_points[i].id_on_marker+1)%n_on_interface];
    size_t neigh2 = interfaces[id_on_interface].markers[(triple_points[i].id_on_marker-1+n_on_interface)%n_on_interface];

    // find direction of the movement
    SVector3 mn1 = SVector3(pos[3*neigh1]-pos[3*m], pos[3*neigh1+1]-pos[3*m+1], 0);
    SVector3 mn2 = SVector3(pos[3*neigh2]-pos[3*m], pos[3*neigh2+1]-pos[3*m+1], 0);
    double dot1 = dot(mn1, v[map_triple[i]]);
    double dot2 = dot(mn2, v[map_triple[i]]);

    if(dot1>dot2){ // project v on neigh1
      target[3*m] += dot1*mn1.x()*dt;
      target[3*m+1] += dot1*mn1.y()*dt;
      target[3*m+2] = 0;
    } else { // go to neigh2
      target[3*m] += dot2*mn2.x()*dt;
      target[3*m+1] += dot2*mn2.y()*dt;
      target[3*m+2] = 0;
    }
  }
  printf("after triple points\n");
  printf("target size = %d\n", target.size());
  printf("n = %d\n", n);
  for(size_t i=0; i<pos.size()/3; ++i){
    pos[3*i] = target[3*i];
    pos[3*i+1] = target[3*i+1];
    pos[3*i+2] = 0;
  }
  
  printf("ended\n");


  // int iter = 0;
  // if(bnd) {
  //   while(1){
  //     iter++;
  //     for(size_t i=0; i<n; ++i){
  //       if(found[i]) continue;
  //       if(colors[i]<0){
  //         found[i] = true;
  //         continue;
  //       }
  //       // compute all intersection with bnd
  //       double a1[2] = {pos[3*i], pos[3*i+1]};
  //       double a2[2] = {target[3*i], target[3*i+1]}; 
  //       int IMIN,IMAX,JMIN,JMAX;
  //       getCoordinates(std::min(a1[0],a2[0]),std::min(a1[1],a2[1]),IMIN,JMIN);
  //       getCoordinates(std::max(a1[0],a2[0]),std::max(a1[1],a2[1]),IMAX,JMAX);
  //       std::set<size_t> touched;
  //       std::vector<std::pair<double, size_t>> intersection;  // vector of [s, j]. s = parametric coord of the movement, index in lines (and sss)
  //       for (size_t I=IMIN; I<=IMAX;I++){
  //         for (size_t J=JMIN; J<=JMAX;J++){
  //           size_t index = I+NX*J;
  //           for (auto j : sss [index]){
  //             if(colors[j/2]>0) continue;                     // bnd has a -1 color
  //             if (touched.find(j) != touched.end())continue;
  //             touched.insert(j);
  //             double a3[2] = {pos[3*lines[j]],pos[3*lines[j]+1]};
  //             double a4[2] = {pos[3*lines[j+1]],pos[3*lines[j+1]+1]};
  //             double a143 = robustPredicates::orient2d(a1,a4,a3);
  //             double a243 = robustPredicates::orient2d(a2,a4,a3);    
  //             double a123 = robustPredicates::orient2d(a1,a2,a3);
  //             double a124 = robustPredicates::orient2d(a1,a2,a4);
  //             if (a143*a243 < 0 && a123*a124 < 0){
  //               double t = fabs(a143)/(fabs(a143)+fabs(a243));
  //               intersection.push_back(std::make_pair(t, j));
  //             } else if(fabs(a143)<1e-12){ //previous position on the bnd
  //               if(a1[0] == a3[0] && a1[1] == a3[1]){
  //                 double a14[2] = {a4[0]-a1[0], a4[1]-a1[1]};
  //                 double a12[2] = {a2[0]-a1[0], a2[1]-a1[1]};
  //                 if((a14[0]*a12[0]+a14[1]*a12[1])>-1e-12){
  //                   intersection.push_back(std::make_pair(0, j));
  //                 }
  //               } else if(a1[0] == a4[0] && a1[1] == a4[1]){
  //                 double a13[2] = {a3[0]-a1[0], a3[1]-a1[1]};
  //                 double a12[2] = {a2[0]-a1[0], a2[1]-a1[1]};
  //                 if((a13[0]*a12[0]+a13[1]*a12[1])>-1e-12){
  //                   intersection.push_back(std::make_pair(0, j));
  //                 }
  //               } else {
  //                 intersection.push_back(std::make_pair(0, j));
  //               }
  //             }

  //           }
  //         }
  //       }
        
  //       // choose closest intersection or target if none
  //       if(intersection.empty()){
  //         pos[3*i] = target[3*i];
  //         pos[3*i+1] = target[3*i+1];
  //         found[i] = true;
  //       } else {
  //         double t_min = 2;
  //         size_t id_min;
  //         for(size_t k=0; k<intersection.size(); ++k){
  //           if(intersection[k].first<t_min){
  //             t_min = intersection[k].first;
  //             id_min = intersection[k].second;
  //           }
  //         }
  //         // continue movement along the edge
  //         pos[3*i] = a1[0]+(a2[0]-a1[0])*t_min;
  //         pos[3*i+1] = a1[1]+(a2[1]-a1[1])*t_min;

  //         double a3[2] = {pos[3*lines[id_min]],pos[3*lines[id_min]+1]};
  //         double a4[2] = {pos[3*lines[id_min+1]],pos[3*lines[id_min+1]+1]};
          
  //         double proj_p[2], proj_t[2];
  //         projectPonLine(a3, a4, &pos[3*i], proj_p);
  //         projectPonLine(a3, a4, &target[3*i], proj_t);

  //         double pnewt[2] = {proj_t[0]-proj_p[0], proj_t[1]-proj_p[1]};
  //         double dotProduct = pnewt[0]*(a4[0]-a3[0]) + pnewt[1]*(a4[1]-a3[1]);

  //         double pa3_norm2 = (pos[3*i]-a3[0])*(pos[3*i]-a3[0]) + (pos[3*i+1]-a3[1])*(pos[3*i+1]-a3[1]);
  //         double pa4_norm2 = (pos[3*i]-a4[0])*(pos[3*i]-a4[0]) + (pos[3*i+1]-a4[1])*(pos[3*i+1]-a4[1]); 
  //         double pnewt_norm2 = pnewt[0]*pnewt[0]+pnewt[1]*pnewt[1];
          
  //         if(dotProduct>0){
  //           if(pnewt_norm2 > pa4_norm2){
  //             target[3*i] = pos[3*i]+pnewt[0];
  //             target[3*i+1] = pos[3*i+1]+pnewt[1];
  //             pos[3*i] = a4[0];
  //             pos[3*i+1] = a4[1];
  //           } else{
  //             pos[3*i] = pos[3*i]+pnewt[0];
  //             pos[3*i+1] = pos[3*i+1]+pnewt[1];
  //             found[i] = true;
  //           }
  //         } else {
  //           if(pnewt_norm2 > pa3_norm2){
  //             target[3*i] = pos[3*i]+pnewt[0];
  //             target[3*i+1] = pos[3*i+1]+pnewt[1];
  //             pos[3*i] = a3[0];
  //             pos[3*i+1] = a3[1];
  //           } else{
  //             pos[3*i] = pos[3*i]+pnewt[0];
  //             pos[3*i+1] = pos[3*i+1]+pnewt[1];
  //             found[i] = true;
  //           }
  //         }
          
          
  //       }
        
  //     }
  //     if (std::find(begin(found), end(found), false) == end(found)) {
  //       break; // All false
  //     }
  //   }
  // }

  // FILE *f = fopen ("after_v.pos","w");
  // fprintf(f,"View \"Front Geometry\"{\n");
  // printGeometry(f);
  // fprintf(f,"};\n");
  // fclose(f);

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
  // position = pos;
  // tags = colors;
  for(size_t i=0; i<interfaces.size();++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      position.push_back(pos[3*interfaces[i].markers[j]]);
      position.push_back(pos[3*interfaces[i].markers[j]+1]);
      position.push_back(pos[3*interfaces[i].markers[j]+2]);
      tags.push_back(interfaces[i].tag);
    }
  }
  return;
}

void discreteFront::redistFrontNew(double lc){
  double fc_min=0.5; 
  double fc_max=1.5;
  double small_dist = fc_min*lc;
  double large_dist = fc_max*lc;

  for(size_t i=0; i<interfaces.size(); ++i){
    std::vector<size_t> markers = interfaces[i].markers;
    std::vector<size_t> new_markers;
    size_t n = markers.size();
    size_t previous = markers[0];
    new_markers.push_back(markers[0]);
    for(size_t j=1; j<markers.size(); ++j){
      size_t current = markers[j];
      double dist = sqrt(pow(pos[3*current]-pos[3*previous],2)+pow(pos[3*current+1]-pos[3*previous+1],2));
      if(dist<small_dist){
        printf("small dist\n");
        if(j==n-1){
          new_markers.push_back(current);
        }
      } else if(dist>large_dist){
        printf("large dist\n");

        int n_new = (int) (dist/lc - (fc_max-1.01));
        printf(" \n n_new = %d\n", n_new);
        size_t new_marker;
        printf("pos previous : %d = %f, %f\n", previous, pos[3*previous], pos[3*previous+1]);
        for(size_t k=0; k<n_new; ++k){
          double s = (k+1.0)/(n_new+1.0);
          new_marker = pos.size()/3;
          pos.push_back((1-s)*pos[3*previous]+s*pos[3*current]);
          pos.push_back((1-s)*pos[3*previous+1]+s*pos[3*current+1]);
          pos.push_back(0.0);
          new_markers.push_back(new_marker);
          printf("new marker %d : %f, %f\n", new_marker, pos[3*new_marker], pos[3*new_marker+1]);
        }
        printf("pos current %d = %f, %f\n", current, pos[3*current], pos[3*current+1]);
        new_markers.push_back(current);
        previous = current;
      } else {
        // printf("good dist\n");
        new_markers.push_back(current);
        previous = current;
      }
    }
    interfaces[i].markers = new_markers;
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
  if (fn.size() == 0) return pp;
  int current_color = interfaces[fn[0].interface].tag;
  for (size_t i=0;i<fn.size();i++){
    const frontNode &n = fn[i];
    int color = interfaces[fn[i].interface].tag;
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

// void discreteFront::moveFromFront(double dt, const std::vector<SVector3> &v){
  
//   std::vector<SVector3> v_marker(pos.size()/3, SVector3(0.0));
//   std::sort(fn.begin(), fn.end());
//   std::vector<double> mesh_pos;
//   meshRelaying::instance()->getNodesPosition(mesh_pos);

//   std::vector<std::vector<size_t> > _lls;
//   std::vector<size_t> _ll;

//   for (size_t i=0;i<lines.size();i+=2){
//     if(colors[i/2]<0) continue;
//     _ll.push_back(lines[i]);
//     _ll.push_back(lines[i+1]);
//     if (lines[(i+2)%lines.size()] != lines[i+1]){
//       _lls.push_back(_ll);
//       _ll.clear();
//     }
//   }

//   std::vector<std::vector<std::pair<size_t,int>>> fls;
//   std::vector<std::pair<size_t,int>> fl;

//   for(size_t i=0; i<_lls.size();++i){
//     //    size_t start = _lls[i][0];
//     for(size_t j=0; j<_lls[i].size(); j+=2){
//       fl.push_back(std::make_pair(_lls[i][j],-1));
//       for(size_t k=0; k<fn.size(); ++k){
//         if( _lls[i][j] == lines[fn[k].line] ){
//           fl.push_back(std::make_pair(fn[k].meshNode,k));
//         }
//       }
//     }
//     fls.push_back(fl);
//     fl.clear();
//   }

  

//   for(int i=0; i<fls.size(); ++i){
//     int current=0;
//     while(fls[i][current].second<0 && current<fls[i].size()) ++current;
//     int start = current;
//     int next = current;
//     std::vector<std::pair<size_t, double>> in_between_markers;
//     while (next<fls[i].size()-1){
//       next++;
//       if(fls[i][next].second >= 0){
//         printf(" front node : %d, v = %f,%f \n", fls[i][next].second, v[fls[i][next].second].x(), v[fls[i][next].second].y());
//         // compute velocity for markers between current and next front node
//         double total_dist;
//         if(!in_between_markers.empty()){
//           total_dist = in_between_markers.back().second + sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][next].second +1],2));
//         }
  
//         for(size_t k=0; k<in_between_markers.size(); ++k){
//           double s = in_between_markers[k].second/total_dist;
//           SVector3 v1 = v[fls[i][current].second];
//           SVector3 v2 = v[fls[i][next].second]; 
//           v_marker[in_between_markers[k].first] = s*v2 + (1-s)*v1;

//         }
//         current = next;
//         in_between_markers.clear();
//       }else{
//         double dist;
//         if(in_between_markers.empty()){
//           dist = sqrt(pow(mesh_pos[3*current]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*current+1]-pos[3*fls[i][next].second +1],2));
//           in_between_markers.push_back(std::make_pair(fls[i][next].first, dist));
//         }else{
//           dist = sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][next].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][next].second +1],2));
//           in_between_markers.push_back(std::make_pair(fls[i][next].first, in_between_markers.back().second + dist));
//         }
//       }
//     }

//     int reset = 0;
//     while(fls[i][reset].second<0 && current<fls[i].size()){
//       double dist;
//       if(in_between_markers.empty()){
//         dist = sqrt(pow(mesh_pos[3*current]-pos[3*fls[i][reset].second],2) + pow(mesh_pos[3*current+1]-pos[3*fls[i][reset].second +1],2));
//         in_between_markers.push_back(std::make_pair(fls[i][reset].first, dist));
//       }else{
//         dist = sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][reset].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][reset].second +1],2));
//         in_between_markers.push_back(std::make_pair(fls[i][reset].first, in_between_markers.back().second + dist));
//       }
//       ++reset;
//     }
//     double total_dist;
//     if(!in_between_markers.empty()){
//       total_dist = in_between_markers.back().second + sqrt(pow(pos[3*in_between_markers.back().first]-pos[3*fls[i][start].second],2) + pow(mesh_pos[3*in_between_markers.back().first+1]-pos[3*fls[i][start].second +1],2));
//     }
//     for(size_t k=0; k<in_between_markers.size(); ++k){
//       double s = in_between_markers[k].second/total_dist;
//       printf("end marker = %lu s = %f \n", in_between_markers[k].first, s);
//       SVector3 v1 = v[fls[i][current].second];
//       SVector3 v2 = v[fls[i][start].second];
//       v_marker[in_between_markers[k].first] = s*v2 + (1-s)*v1;

//     }
    
    
//   }

//   for(size_t i=0; i<fls.size(); ++i){
//     for(size_t j=0; j<fls[i].size(); ++j){
//       if(fls[i][j].second<0){
//         printf("marker : %lu, v = %f,%f \n", fls[i][j].first, v_marker[fls[i][j].first].x(), v_marker[fls[i][j].first].y());
//       } else {
//         printf("front node: %d, v = %f,%f \n", fls[i][j].second, v[fls[i][j].second].x(), v[fls[i][j].second].y());
//       }
//     }
    
//   }
  
//   moveFromV(dt, v_marker, true);
// }

// NEED FIX
void discreteFront::adjustBnd(const std::vector<std::pair<size_t,size_t>> &bnd1d){

  if (empty())return;
  
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

void discreteFront::printInterfaces(FILE *f){
  fprintf(f,"View \"Interface\"{\n");
  for(size_t i=0; i<interfaces.size(); ++i){
    for(size_t j=0; j<interfaces[i].markers.size()-1; ++j){
      fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	    pos[3*interfaces[i].markers[j]],pos[3*interfaces[i].markers[j]+1],
	    pos[3*interfaces[i].markers[j+1]],pos[3*interfaces[i].markers[j+1]+1],interfaces[i].tag, interfaces[i].tag);
      fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n", pos[3*interfaces[i].markers[j]],pos[3*interfaces[i].markers[j]+1], interfaces[i].markers[j]);
    }

    // if(interfaces[i].start!=nullptr){
    //   fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	  //   interfaces[i].start->pos[0], interfaces[i].start->pos[1],
	  //   pos[3*interfaces[i].markers[0]],pos[3*interfaces[i].markers[0]+1],interfaces[i].tag, interfaces[i].tag);
    // }

    // if(interfaces[i].end!=nullptr){
    //   fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	  //   interfaces[i].end->pos[0], interfaces[i].end->pos[1],
	  //   pos[3*interfaces[i].markers.back()],pos[3*interfaces[i].markers.back()+1],interfaces[i].tag, interfaces[i].tag);
    // }

    if(interfaces[i].triple.size()==0){
      fprintf(f,"SL(%12.5E,%12.5E,0,%12.5E,%12.5E,0){%d,%d};\n",
	    pos[3*interfaces[i].markers[0]],pos[3*interfaces[i].markers[0]+1],
	    pos[3*interfaces[i].markers.back()],pos[3*interfaces[i].markers.back()+1],interfaces[i].tag, interfaces[i].tag);
      fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n", pos[3*interfaces[i].markers.back()],pos[3*interfaces[i].markers.back()+1], interfaces[i].markers.back());
    }else{
      size_t j = interfaces[i].markers.size()-1;
      fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n", pos[3*interfaces[i].markers[j]],pos[3*interfaces[i].markers[j]+1], interfaces[i].markers[j]);
    }
  }

  for(size_t i=0; i<triple_points.size();++i){
    fprintf(f, "SP(%12.5E, %12.5E, 0){%d};\n", triple_points[i].pos[0], triple_points[i].pos[1], triple_points[i].tag);
    // fprintf(f, "T3(%12.5E, %12.5E, 0.01, 0){'%d'};\n", triple_points[i].pos[0],triple_points[i].pos[1], triple_points[i].id_marker);
  }
  fprintf(f,"};\n");
}

size_t discreteFront::findMarker(size_t marker){
  for(size_t i=0; i<interfaces.size(); ++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      if(interfaces[i].markers[j] == marker){
        return i;
      }
    }
  }

}

size_t discreteFront::max_marker(){
  size_t max_marker = 0;
  for(size_t i=0; i<interfaces.size(); ++i){
    for(size_t j=0; j<interfaces[i].markers.size(); ++j){
      if(interfaces[i].markers[j] > max_marker){
        max_marker = interfaces[i].markers[j];
      }
    }
  }
  return max_marker;
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

void meshRelaying::doRelaying (double t){
  auto f_levelset = [this] (size_t i, size_t j) -> std::vector<std::pair<double,std::pair<size_t,size_t> > > {
    std::vector<std::pair<double,std::pair<size_t, size_t>>> ds;
    for (size_t k = 0; k < levelsets.size() ; k++){    
      double l0 = levelsets[k][i];
      double l1 = levelsets[k][j];
      if (l0 * l1 < 0){
        double t = l0/(l0-l1);
        std::pair<double,std::pair<size_t, size_t>> d = std::make_pair(t,std::make_pair(k,k));
        ds.push_back(d);
      }
    }
    std::sort(ds.begin(),ds.end());
    return ds;    
  };

  auto f_discrete = [this] (size_t i, size_t j) -> std::vector< std::pair<double,std::pair<size_t,size_t>>> {
    SVector3 p0(pos [3*i],pos [3*i+1],pos [3*i+2]);
    SVector3 p1(pos [3*j],pos [3*j+1],pos [3*j+2]);   
    
    std::vector<double> d;
    std::vector<int> c;
    discreteFront::instance()->intersectLine2d (p0, p1,d,c);
    std::vector<std::pair<double, std::pair<size_t, size_t>>> ds;
    for (size_t i=0;i<d.size();i++){
      std::pair<double, std::pair<size_t,size_t>> p = std::make_pair(d[i],std::make_pair(c[2*i],c[2*i+1]));
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

void meshRelaying::doRelaying (const std::function<std::vector<std::pair<double, std::pair<size_t,size_t>>>(size_t, size_t)> &f){
  
  front_nodes.clear();
  discreteFront::instance()->clearFrontNodes();
  discreteFront::instance()->buildSpatialSearchStructureInterface ();

  int MAXIT = (discreteFront::instance()->empty()) ? 2 : 3;
  int ITTT = 1;

  printf("doRelaying\n");
  
  while(1) {
    auto front_edges = discreteFront::instance()->getFrontEdges();
    printf("after getFrontEdges\n");
    if (ITTT++ == MAXIT)break;
    if (tets.empty()){      
      // for (size_t i=0;i<tris.size();i+=3){
      //   std::vector<SVector3> c;
      //   std::vector<int> col;
      //   discreteFront::instance()->cornersInTriangle2d (SVector3(pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2]),
			// 				SVector3(pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2]),
			// 				SVector3(pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2]),
			// 				c,col);
      //   if (!c.empty()){
      //     for (int j=0;j<3;j++){
            
      //       // do not move a bnd node on a corner 
      //       // JF do not remove this
      //       int dimEdge = tets.size() ? 3:2;
      //       int dimi = dimVertex[tris[i+j]];
      //       if(dimi<dimEdge){
      //         continue;
      //       } 

      //       double qMin = smallest_measure (tris[i+j],c[0]);
      //       if (qMin > 0){
      //         pos[3*tris[i+j]]   = c[0].x();
      //         pos[3*tris[i+j]+1] = c[0].y();
      //         front_nodes.push_back(tris[i+j]);
      //         discreteFront::instance()->addFrontNode (tris[i+j],col[0],c[0]);
      //         corners.push_back(tris[i+j]);
      //         break;
      //       }
      //     }
      //   }
      // }

      for (size_t i=0;i<tris.size();i+=3){
        std::vector<size_t> interface_id;
        std::vector<size_t> m1;
        std::vector<size_t> m2;
        std::vector<SVector3> p_triple;

        discreteFront::instance()->tripleInTriangle2d (SVector3(pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2]),
							SVector3(pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2]),
							SVector3(pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2]),
							interface_id, m1, m2, p_triple);
        if (!p_triple.empty()){
          for (int j=0;j<3;j++){
            
            // int dimEdge = tets.size() ? 3:2;
            // int dimi = dimVertex[tris[i+j]];
            // if(dimi<dimEdge){
            //   printf("continued\n");
            //   continue;
            // } 

            double qMin = smallest_measure (tris[i+j],p_triple[0]);
            if (qMin > 0){
              pos[3*tris[i+j]]   = p_triple[0].x();
              pos[3*tris[i+j]+1] = p_triple[0].y();
              front_nodes.push_back(tris[i+j]);
              discreteFront::instance()->addFrontNode (tris[i+j],interface_id[0],m1[0],m2[0],p_triple[0]);
              corners.push_back(tris[i+j]);
              break;
            }
          }
        }
      }
    }
    // printf("before sort \n");

    std::sort(front_nodes.begin(),front_nodes.end());
    std::sort(corners.begin(),corners.end());
    std::set<std::pair<size_t,size_t> > cuts;
    std::vector<edgeCut> moves;

    printf("%lu\n",v2v.size());
    
    for (size_t i = 0; i< v2v.size() ; i++){
      for (auto j : v2v[i]){
        if (i < j){
          std::pair<size_t,size_t> pa = std::make_pair(i,j);
          if (std::find(front_edges.begin(), front_edges.end(), pa) != front_edges.end())continue;

	        std::vector<std::pair<double,std::pair<size_t, size_t>>> ds = f (i,j);
          if (ds.empty())continue;
          std::pair<size_t,size_t> p = std::make_pair(std::min(i,j),std::max(i,j));
          cuts.insert(p);
	  
          size_t indexi = 0; 
          size_t indexj = ds.size() - 1;

          const double di = ds[indexi].first;
          const double dj = ds[indexj].first;
          const size_t    m1i = ds[indexi].second.first;
          const size_t    m2i = ds[indexi].second.second;
          const size_t    m1j = ds[indexj].second.first;
          const size_t    m2j = ds[indexj].second.second;
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
          size_t interface_i = discreteFront::instance()->findMarker(m1i);
          size_t interface_j = discreteFront::instance()->findMarker(m1j);
          edgeCut mi(i, j, pOpti, DI.norm(), interface_i, m1i, m2i);
          edgeCut mj(j, i, pOptj, DJ.norm(), interface_j, m1j, m2j);

          // Not perfect ... but workable
          if (!std::binary_search(front_nodes.begin(),front_nodes.end(),i))
            if(di>0.0000001 && di<0.999999 && dimi >= dimEdge) moves.push_back(mi);
          if (!std::binary_search(front_nodes.begin(),front_nodes.end(),j))
            if(dj>0.0000001 && dj<0.999999 && dimj >= dimEdge) moves.push_back(mj);
        }
      }
    }
    
    if (moves.empty())break;
    std::sort(moves.begin(), moves.end());

    printf("%lu moves\n",moves.size());
    
    for (auto c : moves){
      size_t i = c.a;
      size_t j = c.b;
      std::pair<size_t,size_t> p = std::make_pair(std::min(i,j), std::max(i,j));
      if (cuts.find(p) == cuts.end())continue;
      
      SVector3 pOpt = c.p;
      //      double qMin = smallest_measure (i,pOpt);      
      //      if (qMin < 0) continue;
      
      for (auto k : v2v[i]){
        p = std::make_pair(std::min(i,k), std::max(i,k));
        cuts.erase(p);
      }

      if (levelsets.size()){
	      levelsets[c.m1][i] = 0.0;
      }
      
      front_nodes.push_back(i);
      discreteFront::instance()->addFrontNode(i,c.interface,c.m1,c.m2,pOpt);
      pos[3*i] = pOpt.x();
      pos[3*i+1] = pOpt.y();
      pos[3*i+2] = pOpt.z();
    }    
    printf("coucou %lu fn\n",front_nodes.size());
    std::sort(front_nodes.begin(),front_nodes.end());
  }

  
  if (!discreteFront::instance()->empty()){
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

T_node *newT_node(size_t id, int tag){
    T_node *temp = new T_node;
    temp->id = id;
    temp->tag = tag;
    temp->leafs = {};
    return temp;
}

void meshRelaying::untangle(){
#if defined(HAVE_WINSLOWUNTANGLER)
  std::vector<bool> _locked;
  if (tets.size()){
    std::vector<std::vector<uint32_t> > _elements;
    std::vector<std::array<double,3> > _points;
    for (size_t i=0;i<tets.size()/4;i++)_elements.push_back({
	static_cast<unsigned int>(tets[4*i]),
	  static_cast<unsigned int>(tets[4*i+1]),
	  static_cast<unsigned int>(tets[4*i+2]),
	  static_cast<unsigned int>(tets[4*i+3])});
    for (size_t i=0;i<pos.size()/3;i++)_points.push_back({pos[3*i],pos[3*i+1],pos[3*i+2]});  
    for (size_t i=0;i<pos.size()/3;i++)_locked.push_back(dimVertex[i] == 3 ? false : true);
    for (size_t i=0;i<front_nodes.size();i++)_locked[front_nodes[i]]=true;  
    std::vector<std::array<uint32_t, 4> > _tets;
    std::vector<std::array<std::array<double,3>, 4> > _tetIdealShapes;
    std::vector<std::vector<std::array<double,3> > > _elementTargetShapes;
    {
      //      double minQual = 1.0;
      double avgQual = 0.0;
      for (size_t i=0;i<tets.size()/4;i++){
	//	minQual = std::min(qualityElement(i),minQual);
	avgQual += qualityElement(i);
      }
      avgQual /= (tets.size()/4);
      Msg::Info ("Avg Quality Before Untangling %12.5E",avgQual);
    }
    buildTetrahedraFromElements(_elements,_elementTargetShapes, _tets,_tetIdealShapes);
    untangle_tetrahedra(_points, _locked, _tets, _tetIdealShapes);
    for (size_t i=0;i<_points.size();i++){
      pos[3*i] = _points[i][0];
      pos[3*i+1] = _points[i][1];
      pos[3*i+2] = _points[i][2];
    }
    {
      //      double minQual = 1.0;
      double avgQual = 0.0;
      for (size_t i=0;i<tets.size()/4;i++){
	//	minQual = std::min(qualityElement(i),minQual);
	avgQual += qualityElement(i);
      }
      avgQual /= (tets.size()/4);
      //      Msg::Info ("Min Quality Before Untangling %12.5E",avgQual);
      //      for (size_t i=0;i<tets.size()/4;i++)minQual = std::min(qualityElement(i),minQual);
      Msg::Info ("Avg Quality After Untangling %12.5E",avgQual);
    }
  }
  else{  
    std::vector<std::array<uint32_t,4> >  _elements;
    std::vector<std::array<double,2> > _points;
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

  // discreteFront::instance()->addLines(p,l,c);
  discreteFront::instance()->addInterface(p, -1, -1); 
}

void discreteFront::clear(){
  colors.clear();
  corners.clear();
  lines.clear();
  pos.clear();
}

void meshRelaying::concentration(std::vector<int> *concentration){
  std::vector<std::vector<size_t>> loops;
  std::vector<int> loops_tags;
  std::vector<int> loops_senses;
  discreteFront::instance()->interfaces2Loops(&loops, &loops_tags, &loops_senses);
  // printf("in concentration\n");
  // for(size_t i=0; i<loops_tags.size(); ++i){
  //   printf("%d\n", loops_tags[i]);
  // }
  for (size_t i=0;i<tris.size();i+=3){
    SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
		 (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
		 0);
    int color = 1;
    // if(i==9323*3){
    //   printf("9323\n");
    //   printf("%f %f %f\n", COG.x(), COG.y(), COG.z());
    // }
    if (!discreteFront::instance()->empty()){
      color = discreteFront::instance()->whatIsTheColorOf2d(COG, loops, loops_tags);
      if(color<0) color = 0;
    }
    // if(i==9323*3){
    //   printf("color %d\n", color);
    //   printf("n loops = %d \n", loops.size());

    //   std::set<int> cs;
    //   std::vector<int> cols;
    //   double pp[2] = {COG.x(),COG.y()};
    //   for (size_t i=0 ; i<loops.size(); ++i){
    //     int c = loops_tags[i];
    //     printf(" c = %d, loop %d \n", c, i);
    //     if(c<0)continue;
    //     if (cs.find(c) == cs.end()){
    //       cs.insert(c);
    //       int wn = 0;
    //       size_t n = loops[i].size();
    //       for (size_t j=0 ; j<n ; ++j){
    //         double aa[2] = {pos[3*loops[i][j]],pos[3*loops[i][j]+1]};
    //         double bb[2] = {pos[3*loops[i][(j+1)%n]],pos[3*loops[i][(j+1)%n]+1]};
    //         double area = robustPredicates::orient2d(aa,bb,pp); 
    //         if(aa[1]<= COG.y()){
    //           if (bb[1] > COG.y() && area < 0)wn++;
    //         }
    //         else if(bb[1]<= COG.y()){
    //           if (area > 0)wn--;
    //         }
    //       }
    //       printf("loop %d \n", i);
    //       printf("wn = %d \n", wn);
    //       if (wn != 0)cols.push_back(c);
    //     }
    //   }
    //   printf("cols %lu\n", cols.size());
    //   for(size_t i=0; i<cols.size(); ++i){
    //     printf("%d ", cols[i]);
    //   }
    // }
    (*concentration).push_back(color);
  }
}


void discreteFront::addFreeForm (int tag, const std::vector<SVector3> &poly, const std::vector<size_t> &_corners, const int sense){
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
  // discreteFront::instance()->addLines(p,l,c,_corners);
  discreteFront::instance()->addInterface(p, tag, sense); 
}

void discreteFront :: printMesh (FILE *f) {
  if(fn.empty()) return;
  std::sort(fn.begin(), fn.end());
  std::vector<SVector3> pp;
  int current_color = interfaces[fn[0].interface].tag;
  for (size_t i=0;i<fn.size();i++){
    const frontNode &n = fn[i];
    size_t m1 = n.m1;
    size_t m2 = n.m2;
    int color = interfaces[n.interface].tag;
    SVector3 p0 (pos[3*m1],pos[3*m1+1],pos[3*m1+2]);
    SVector3 p1 (pos[3*m2],pos[3*m2+1],pos[3*m2+2]);
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

void meshRelaying::print4debug(const char *fn){
  FILE *f = fopen (fn,"w");
  if (discreteFront::instance()->empty()){
    for (size_t k=0;k<levelsets.size();k++){
      fprintf(f,"View \"Levelset %lu\"{\n",k);
      for (size_t i=0;i<tris.size();i+=3){
	      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
        pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2],
        pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2],
        pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2],
        levelsets[k][tris[i]],
        levelsets[k][tris[i+1]],
        levelsets[k][tris[i+2]]);    
      }
      for (size_t i=0;i<tets.size();i+=4){
	      fprintf(f,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
        pos[3*tets[i]],pos[3*tets[i]+1],pos[3*tets[i]+2],
        pos[3*tets[i+1]],pos[3*tets[i+1]+1],pos[3*tets[i+1]+2],
        pos[3*tets[i+2]],pos[3*tets[i+2]+1],pos[3*tets[i+2]+2],
        pos[3*tets[i+3]],pos[3*tets[i+3]+1],pos[3*tets[i+3]+2],
        levelsets[k][tets[i]],
        levelsets[k][tets[i+1]],
        levelsets[k][tets[i+2]],
        levelsets[k][tets[i+3]]);       
      }    
      fprintf(f,"};\n");
    }
  }
  else{
    fprintf(f,"View \"Front Mesh\"{\n");
    discreteFront::instance()->printMesh(f);
    fprintf(f,"};\n");
    fprintf(f,"View \"Mesh\"{\n");  
    printf("after print mesh \n");
    std::vector<std::vector<size_t>> loops;
    std::vector<int> loops_tags;
    std::vector<int> loops_senses;
    discreteFront::instance()->interfaces2Loops(&loops, &loops_tags, &loops_senses);
    printf("after interface 2 loops \n");
    for (size_t i=0;i<tris.size();i+=3){
      SVector3 COG((pos[3*tris[i]]+pos[3*tris[i+1]]+pos[3*tris[i+2]])/3.0,
		   (pos[3*tris[i]+1]+pos[3*tris[i+1]+1]+pos[3*tris[i+2]+1])/3.0,
		 (pos[3*tris[i]+2]+pos[3*tris[i+1]+2]+pos[3*tris[i+2]+2])/3.0);
      int color = 1;
      if (!discreteFront::instance()->empty()){
	      color = discreteFront::instance()->whatIsTheColorOf2d(COG, loops, loops_tags);
      }
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
	      pos[3*tris[i]],pos[3*tris[i]+1],pos[3*tris[i]+2],
	      pos[3*tris[i+1]],pos[3*tris[i+1]+1],pos[3*tris[i+1]+2],
	      pos[3*tris[i+2]],pos[3*tris[i+2]+1],pos[3*tris[i+2]+2],color,color,color);
    }
    printf("after color \n");
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
    printf("before geometry \n");
    discreteFront::instance()->printInterfaces(f);
  }
  fclose(f);
}
  

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Field.h"
#include <sstream>
#include <fstream>
#include "SPoint2.h"
#include "GSHHS.h"
#include "GModel.h"

class GMSH_GSHHSPlugin:public GMSH_Post_Plugin
{
  public:
    // ************** Inputs (readers) *************
    class reader{
      public:
        virtual int next_loop(bool &closed)=0;
        virtual bool next_point(SPoint3 &point)=0;
    };
    class reader_loops2:public reader{
      FILE *fp;
      int npoints_in_loop;
      int ipoint;
      std::string filename;
      public:
      reader_loops2(std::string _filename){
        filename=_filename;
        fp=fopen(filename.c_str(),"r");
      }
      ~reader_loops2(){
        fclose(fp);
      }
      int next_loop(bool & closed){
        ipoint=0;
        npoints_in_loop=-1;
        int i_closed;
        if(fscanf(fp, "%d %d", &npoints_in_loop,&i_closed) != 2)
          return 0;
        closed = i_closed;
        return npoints_in_loop;
      }
      bool next_point(SPoint3 &point){
        if(ipoint>=npoints_in_loop)
          return false;
        point[2]=0;
        ipoint++;
        if(fscanf(fp, "%le %le", &point[0], &point[1]) != 2) 
          Msg::Error("gshhs:  Error reading loops2 file.\n");
        return true;
      }
    };
    class reader_gshhs:public reader{
      /*	$Id: GSHHS.cpp,v 1.27 2009-01-31 00:28:27 geuzaine Exp $
       *
       * Include file defining structures used in gshhs.c
       *
       * Paul Wessel, SOEST
       *
       *	Copyright (c) 1996-2008 by P. Wessel and W. H. F. Smith
       *	See COPYING file for copying and redistribution conditions.
       *
       *	This program is free software; you can redistribute it and/or modify
       *	it under the terms of the GNU General Public License as published by
       *	the Free Software Foundation; version 2 of the License.
       *
       *	This program is distributed in the hope that it will be useful,
       *	but WITHOUT ANY WARRANTY; without even the implied warranty of
       *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
       *	GNU General Public License for more details.
       *
       *	Contact info: www.soest.hawaii.edu/pwessel
       *
       *	14-SEP-2004.  PW: Version 1.3.  Header is now n * 8 bytes (n = 5)
       *			  For use with version 1.3 of GSHHS
       *	2-MAY-2006.  PW: Version 1.4.  Header is now 32 bytes (all int 4)
       *			  For use with version 1.4 of GSHHS
       *	31-MAR-2007.  PW: Version 1.5.  no format change
       *			  For use with version 1.5 of GSHHS
       *	28-AUG-2007.  PW: Version 1.6.  no format change
       *			  For use with version 1.6 of GSHHS which now has WDBII
       *			  borders and rivers.
       */
#define GSHHS_DATA_VERSION 6	// For v1.5 data set 
      //define GSHHS_PROG_VERSION "1.9"
#define GSHHS_SCL 1.0e-6	// COnvert micro-degrees to degrees 
      inline unsigned int swabi4(unsigned int i4){ // For byte swapping on little-endian systems (GSHHS is defined to be bigendian) 
        return (((i4) >> 24) + (((i4) >> 8) & 65280) + (((i4) & 65280) << 8) + (((i4) & 255) << 24));
      }
      class	POINT {	/* Each lon, lat pair is stored in micro-degrees in 4-byte integer format */
        public:
          int	x;
          int	y;
      };
      class GSHHS {	/* Global Self-consistent Hierarchical High-resolution Shorelines */
        public:
          int id;				/* Unique polygon id number, starting at 0 */
          int n;				/* Number of points in this polygon */
          int flag;			/* = level + version << 8 + greenwich << 16 + source << 24 */
          /* flag contains 4 items, one in each byte, as follows:
           * low byte:	level = flag & 255: Values: 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake
           * 2nd byte:	version = (flag >> 8) & 255: Values: Should be 4 for GSHHS version 1.4
           * 3rd byte:	greenwich = (flag >> 16) & 255: Values: Greenwich is 1 if Greenwich is crossed
           * 4th byte:	source = (flag >> 24) & 255: Values: 0 = CIA WDBII, 1 = WVS
           */
          int west, east, south, north;	/* min/max extent in micro-degrees */
          int area;			/* Area of polygon in 1/10 km^2 */
      };
      GSHHS h;
      POINT p;
      FILE *fp;
      int max_east,flip,ip,greenwich;
      bool first_loop;
      public:
      reader_gshhs(std::string filename){
        fp=fopen(filename.c_str(),"r");
        max_east = 270000000;
        first_loop=true;
      }
      ~reader_gshhs(){
        fclose(fp);
      }
      int next_loop(bool &closed){
        closed=true;
        int level=0;
        ip=0;
        while(level!=1){
          int n_read = fread ((void *)&h, (size_t)sizeof (struct GSHHS), (size_t)1, fp);
          if(n_read!=1 || feof(fp))
            return 0;
          level = h.flag & 255;
          int version = (h.flag >> 8) & 255;
          flip = (version != GSHHS_DATA_VERSION);	/* Take as sign that byte-swabbing is needed */
          if (flip) {
            h.id = swabi4 ((unsigned int)h.id);
            h.n  = swabi4 ((unsigned int)h.n);
            h.west  = swabi4 ((unsigned int)h.west);
            h.east  = swabi4 ((unsigned int)h.east);
            h.south = swabi4 ((unsigned int)h.south);
            h.north = swabi4 ((unsigned int)h.north);
            h.area  = swabi4 ((unsigned int)h.area);
            h.flag  = swabi4 ((unsigned int)h.flag);
          }
          if(level!=1)
            fseek(fp, (size_t)(h.n * sizeof(struct POINT)), SEEK_CUR);
          if(first_loop)
            first_loop=false;
          else
            max_east = 180000000;	/* Only Eurasiafrica needs 270 */
        }
        greenwich = (h.flag >> 16) & 255;
        int src = (h.flag >> 24) & 255;
        double w = h.west  * GSHHS_SCL;	/* Convert from microdegrees to degrees */
        double e = h.east  * GSHHS_SCL;
        double s = h.south * GSHHS_SCL;
        double n = h.north * GSHHS_SCL;
        char source = (src == 1) ? 'W' : 'C';	/* Either WVS or CIA (WDBII) pedigree */
        int line = (h.area) ? 0 : 1;		/* Either Polygon (0) or Line (1) (if no area) */
        double area = 0.1 * h.area;			/* Now im km^2 */
        return h.n;
      }
      bool next_point(SPoint3 &point){
        if(ip>=h.n)
          return false;
        if (fread ((void *)&p, (size_t)sizeof(struct POINT), (size_t)1, fp) != 1) {
          printf ("gshhs:  Error reading gshhs file.\n");
          exit(1);
        }
        if (flip) {
          p.x = swabi4 ((unsigned int)p.x);
          p.y = swabi4 ((unsigned int)p.y);
        }
        double lon = p.x * GSHHS_SCL;
        if (greenwich && p.x > max_east)
          lon -= 360.0;
        double lat = p.y * GSHHS_SCL;
        point[0]=lon*M_PI/180;
        point[1]=lat*M_PI/180;
        point[2]=0;
        ip++;
        return true;
      }
    };

    // ************** Coordinate Systems *************
    class coordinate_system{
      public:
        virtual void to_cartesian(const SPoint3 coord, SPoint3 &cartesian)=0;
        virtual void from_cartesian(const SPoint3 cartesian, SPoint3 &coord)=0;
    };
    // ************** Longitude Latitude ***************
    class coordinate_lonlat:public coordinate_system{
      double radius;
      public:
      coordinate_lonlat(double r){
        radius=r;
      }
      void to_cartesian(const SPoint3 ll, SPoint3 &xyz){
        double clat = cos(ll.y());
        xyz.setPosition( clat * cos(ll.x())*radius, clat * sin(ll.x())*radius, sin(ll.y())*radius);
      }
      void from_cartesian(const SPoint3 xyz, SPoint3 &ll){
        double r=sqrt(xyz.x()*xyz.x()+xyz.y()*xyz.y()+xyz.z()*xyz.z());
        ll.setPosition( atan2(xyz.y(),xyz.x()), asin(xyz.z()/r), r);
      }
    };
    // ************** Longitude Latitude (degrees) ***************
    class coordinate_lonlat_degrees:public coordinate_system{
      coordinate_lonlat cll;
      SPoint3 llradian;
      public:
      coordinate_lonlat_degrees(double r):cll(r){};
      void to_cartesian(const SPoint3 ll, SPoint3 &xyz){
        llradian.setPosition(ll.x()*M_PI/180,ll.y()*M_PI/180,0);
        cll.to_cartesian(llradian,xyz);
      }
      void from_cartesian(const SPoint3 xyz, SPoint3 &ll){
        cll.from_cartesian(xyz,llradian);
        ll.setPosition(llradian.x()*180/M_PI,llradian.y()*180/M_PI,0);
      }
    };

    // ************** UTM ************** 
    class coordinate_utm :public coordinate_system{
      int zone;
      coordinate_lonlat ll_conv;
      SPoint3 ll;
      double a, b, n, n2, n3, n4, n5, e, e2, e1, e12, e13, e14, J1, J2, J3, J4,
             Ap, Bp, Cp, Dp, Ep, e4, e6, ep, ep2, ep4, k0, mu_fact;
      public:
      static int get_zone_from_longitude(double lon){
        return (int)ceil((lon / M_PI + 1) * 30);
      }
      double meridionalarc(double lon, double lat){
        return Ap * lat + Bp * sin(2 * lat) + Cp * sin(4 * lat) +
          Dp * sin(6 * lat) + Ep;
      }
      void from_cartesian(const SPoint3 xyz,SPoint3 &utm) {
        ll_conv.from_cartesian(xyz,ll);
        double S = meridionalarc(ll.x(),ll.y());
        double slat = sin(ll.y());
        double clat = cos(ll.y());
        double slat2 = slat * slat;
        double clat2 = clat * clat;
        double clat3 = clat2 * clat;
        double clat4 = clat3 * clat;
        double tlat2 = slat2 / clat2;
        double nu = a / sqrt(1 - e * e * slat2);
        double p = ll.x() - ((zone - 0.5) / 30 - 1) * M_PI;
        double p2 = p * p;
        double p3 = p * p2;
        double p4 = p2 * p2;
        utm.setPosition(
            k0 * nu * clat * p + (k0 * nu * clat3 / 6) 
            * (1 - tlat2 + ep2 * clat2) * p3 + 5e5,
            S * k0 + k0 * nu * slat * clat / 2 * p2 
            + k0 * nu * slat * clat3 / 24 
            * (5 - tlat2 + 9 * ep2 * clat2 + 4 * ep4 * clat4) * p4,
            0);
      }
      void to_cartesian(const SPoint3 utm, SPoint3 &xyz){
        double mu = utm.y() * mu_fact;
        double fp =
          mu + J1 * sin(2 * mu) + J2 * sin(4 * mu) + J3 * sin(6 * mu) +
          J4 * sin(8 * mu);
        double cfp = cos(fp);
        double cfp2 = cfp * cfp;
        double sfp = sin(fp);
        double sfp2 = sfp * sfp;
        double c1 = ep2 * cfp2;
        double c12 = c1 * c1;
        double t1 = sfp2 / cfp2;
        double t12 = t1 * t1;
        double r1 = a * (1 - e2) / pow((1 - e2 * sfp2), 1.5);
        double n1 = a / sqrt(1 - e2 * sfp2);
        double d = (utm.x() - 5e5) / (n1 * k0);
        double d2 = d * d;
        double d3 = d2 * d;
        double d4 = d2 * d2;
        double d5 = d4 * d;
        double d6 = d4 * d2;
        ll.setPosition(
            ((zone - 0.5) / 30 - 1) * M_PI + (d - (1 + 2 * t1 + c1) * d3 / 6 +
              (5 - 2 * c1 + 28 * t1 - 3 * c12 +
               8 * ep2 +
               24 * t12) * d5 / 120) / cfp,
            fp - n1 * sfp / cfp / r1 
            * (d2 / 2 - (5 + 3 * t1 + 10 * c1 - 4 * c12 - 9 * ep2) * d4 / 24 
              + (61 + 90 * t1 + 298 * c1 + 45 * t12 - 3 * c12 - 252 * ep2) * d6 / 720),
            0);
        ll_conv.to_cartesian(ll,xyz);
      }
      coordinate_utm(int _zone,double ll_radius, double _a = 6378137, double _b = 6356752.3142) :ll_conv(ll_radius){
        /* see http://www.uwgb.edu/dutchs/UsefulData/UTMFormulas.HTM */
        a = _a;     /* Equatorial Radius*/
        b = _b;     /* Rayon Polar Radius*/
        zone=_zone;
        n = (a - b) / (a + b);
        n2 = n * n;
        n3 = n * n * n;
        n4 = n * n * n * n;
        n5 = n * n * n * n * n;
        e = sqrt(1 - b * b / a / a);
        e2 = e * e;
        e1 = (1 - sqrt(1 - e2)) / (1 + sqrt(1 - e2));
        e12 = e1 * e1;
        e13 = e1 * e1 * e1;
        e14 = e1 * e1 * e1 * e1;
        J1 = (3 * e1 / 2 - 27 * e13 / 32);
        J2 = (21 * e12 / 16 - 55 * e14 / 32);
        J3 = 151 * e13 / 96;
        J4 = 1097 * e14 / 512;
        Ap = a * (1 - n + (5. / 4.) * (n2 - n3) + (81. / 64.) * (n4 - n5));
        Bp = -3 * a * n / 2 * (1 - n + (7. / 8.) * (n2 - n3) +
            (55. / 64.) * (n4 - n5));
        Cp = 14 * a * n2 / 16 * (1 - n + (3. / 4) * (n2 - n3));
        Dp = -35 * a * n3 / 48 * (1 - n + 11. / 16. * (n2 - n3));
        Ep = +315 * a * n4 / 51 * (1 - n);
        e4 = e2 * e2;
        e6 = e2 * e2 * e2;
        ep = e * a / b;
        ep2 = ep * ep;
        ep4 = ep2 * ep2;
        k0 = 0.9996;
        mu_fact = 1 / (k0 * a * (1 - e2 / 4 - 3 * e4 / 64 - 5 * e6 / 256));
      }
    };

    /********** classes and functions to ensure minimal distance and angle between points **********/
    class box;
    class loop;
    class point{
      public:
        SPoint3 v;
        std::list<point>::iterator it_loop;
        std::list<point*>::iterator it_box;
        box *b;
        double min_dist;
        loop *l;
        point(double _x,double _y,double _z,Field *f){
          v[0]=_x; v[1]=_y; v[2]=_z;
          if(f)
            min_dist=(*f)(v[0],v[1],v[2]);
        }
        point(double _x,double _y,double _z,double _min_dist){
          v[0]=_x; v[1]=_y; v[2]=_z;
          min_dist=_min_dist;
        }
        double dist(point p){
          return sqrt(
              (v[0]-p.v[0])*(v[0]-p.v[0])
              +(v[1]-p.v[1])*(v[1]-p.v[1])
              +(v[2]-p.v[2])*(v[2]-p.v[2]));
        }
        void to_stereo(double &xp,double &yp,bool inverse_stereo=false){
          if(inverse_stereo){
            yp=v[1]/(1-v[2]);
            xp=v[0]/(1-v[2]);
          }else{
            xp=-v[1]/(1+v[2]);
            yp=-v[0]/(1+v[2]);
          }
        }
        void to_latlon(double &lat,double &lon){
          lat=asin(v[2]);
          lon=atan2(v[1],v[0]);
          if(lon<-15*M_PI/16)lon+=2*M_PI;
        }
    };
    class box{
      public:
        box *sub_boxes[2];
        point min,max;
        int max_n;
        double min_size,size;
        bool splitted;
        std::list<point*> list;
        int cut_dim,ndim;
        int n;
        box(point _min,point _max,int _max_n=100,double _min_size=0,int _cut_dim=0):min(_min),max(_max),max_n(_max_n){
          n=0;
          min_size=_min_size;
          size=0;
          ndim=3;
          for(int i=0;i<ndim;i++)
            size=std::max(size,fabs(max.v[i]-min.v[i]));
          splitted=false;
          cut_dim=_cut_dim;
        }
        void add( point &p){
          if(!splitted){
            list.push_back(&p);
            p.it_box=list.end();
            p.it_box--;
            p.b=this;
            n++;
            if(n>max_n && size>=min_size){
              point mid0(min);
              point mid1(max);
              mid1.v[cut_dim]=mid0.v[cut_dim]=(min.v[cut_dim]+max.v[cut_dim])/2;
              int newdim=(cut_dim+1)%ndim;
              sub_boxes[0]=new box(min,mid1,max_n,min_size,newdim);
              sub_boxes[1]=new box(mid0,max,max_n,min_size,newdim);
              splitted=true;
              for(std::list<point*>::iterator it=list.begin();it!=list.end();it++)
                add(**it);
              list.clear();
            }
          }else{
            int ix=(p.v[cut_dim]-min.v[cut_dim])>(max.v[cut_dim]-min.v[cut_dim])/2;
            sub_boxes[ix]->add(p);
          }
        }
        void remove(point *p){
          if(p->b!=this)
            p->b->remove(p);
          else{
            list.erase(p->it_box);
            n--;
          }
        }
        void find_closest(point p,int nc,double *d,point **cp){
          int i=(cut_dim+ndim-1)%ndim;
          if(p.v[i]<min.v[i]-d[nc-1] || p.v[i]>max.v[i]+d[nc-1])
            return;
          if(splitted){
            for(int i=0;i<2;i++)
              sub_boxes[i]->find_closest(p,nc,d,cp);
          }else for(std::list<point*>::iterator it=list.begin();it!=list.end();it++){
            double dd=p.dist(**it);
            if(dd<d[nc-1]){
              int j;
              for(j=nc-2;j>=0;j--){
                if(dd>d[j])break;
                d[j+1]=d[j];
                cp[j+1]=cp[j];
              }
              d[j+1]=dd;
              cp[j+1]=*it;
            }
          }
        }
    };
    static double get_angle(double x0,double y0,double x1,double y1,double x2,double y2){
      double dx0=x1-x0;
      double dx1=x2-x1;
      double dy0=y1-y0;
      double dy1=y2-y1;
      return atan2(dx0*dy1-dx1*dy0,dx1*dx0+dy1*dy0);
    }
    static double get_angle(point &p0,point &p1,point &p2){
      double dx0=p1.v[0]-p0.v[0];
      double dy0=p1.v[1]-p0.v[1];
      double dz0=p1.v[2]-p0.v[2];
      double dx1=p2.v[0]-p1.v[0];
      double dy1=p2.v[1]-p1.v[1];
      double dz1=p2.v[2]-p1.v[2];
      double scalar=dx0*dx1+dy0*dy1+dz0*dz1;
      double vectx=dy0*dz1-dy1*dz0;
      double vecty=dz0*dx1-dz1*dx0;
      double vectz=dx0*dy1-dx1*dy0;
      int sign=vectx*p1.v[0]+vecty*p1.v[1]+vectz*p1.v[2]<0?-1:1;
      double vect=sqrt(vectx*vectx+vecty*vecty+vectz*vectz);
      return atan2(-vect*sign,scalar);
    }
    // angle (01,12)
    class loop:public std::list<point>{
      public:
        bool closed;
        loop(){
          closed=true;
        }
        inline iterator next(iterator i){
          ++i;
          if(i==end()){
            i=begin();
          }
          return i;
        }
        inline iterator prev(iterator i){
          if(i==begin())
            i=end();
          --i;
          return i;
        }
        iterator remove_range(loop::iterator i0,loop::iterator i1){ //remove [id0, id1] and replace it by a single point at (id0+id1)/2;
          for(int i=0;i<3;i++)
            i1->v[i]=(i0->v[i]+i1->v[i])/2;
          while(i0!=i1){
            if(i0->b)
              i0->b->remove(&*i0);
            i0=erase(i0);
            if(i0==end())
              i0=begin();
          }
          return i1;
        }
        int orientation(iterator i0, iterator i1,bool reverse_stereo){
          if(next(i0)==i1)
            return 0;
          double alpha=0;
          double x[3],y[3];
          i1->to_stereo(x[0],y[0],reverse_stereo);
          i0->to_stereo(x[1],y[1],reverse_stereo);
          iterator p=i0;
          do{
            p=next(p);
            p->to_stereo(x[2],y[2],reverse_stereo);
            alpha+=get_angle(x[0],y[0],x[1],y[1],x[2],y[2]);
            x[0]=x[1];y[0]=y[1];
            x[1]=x[2];y[1]=y[2];
          }while(p!=i1);
          i0->to_stereo(x[2],y[2],reverse_stereo);
          alpha+=get_angle(x[0],y[0],x[1],y[1],x[2],y[2]);
          return (int)(alpha/(M_PI*2));
        }
        int length(iterator i0,iterator i1){
          int l=1;
          while(i0!=i1){
            i0=next(i0);
            l++;
          }
          return l;
        }
        void insert_range(iterator i,iterator j0,iterator j1){
          iterator n=j0;
          do{
            j0=n;
            iterator is=insert(i,*j0);
            is->it_loop=is;
            is->l=this;
            *(j0->it_box)=&*is;
            n=j0->l->next(j0);
          }while(j0!=j1);
        }
    };

    class loops:public std::list<loop>{
      public:
        void print_gnuplot(std::ostream &stream){
          double lat,lon;
          for(iterator il=begin();il!=end();il++){
            stream<<"\n";
            for(loop::iterator ip=il->begin();ip!=il->end();ip++){
              ip->to_latlon(lat,lon);
              stream<<lon*180/M_PI<<" "<<lat*180/M_PI<<"\n";
            }
            il->front().to_latlon(lat,lon);
            stream<<lon*180/M_PI<<" "<<lat*180/M_PI<<"\n";
          }
        }
    };

    double stereo_cross_product(point p00,point p01, point p10,point p11){
      double x[4],y[4];
      p00.to_stereo(x[0],y[0]);
      p01.to_stereo(x[1],y[1]);
      p10.to_stereo(x[2],y[2]);
      p11.to_stereo(x[3],y[3]);
      return (x[1]-x[0])*(y[3]-y[2])-(y[1]-y[0])*(x[3]-x[2]);
    }
    bool is_intersected(point p00,point p01, point p10,point p11){
      if(stereo_cross_product(p00,p01,p00,p10)*stereo_cross_product(p00,p01,p00,p11)>0)
        return false;
      if(stereo_cross_product(p10,p11,p10,p00)*stereo_cross_product(p10,p11,p10,p01)>0)
        return false;
      return true;
    }
    void loop_fill_box(loop *l,box &b){
      int i=0;
      for(loop::iterator ip=l->begin();ip!=l->end();ip++){
        ip->l=l;
        ip->it_loop=ip;
        b.add(*ip);
      }
    }
    bool loop_check_intersections(loop *l,box &b){
      // Check for intersections
      bool result=false;
      for(loop::iterator i00=l->begin();i00!=l->end();++i00){
        loop::iterator i01=l->next(i00);
        if(i01==l->begin() && !l->closed)
          break;
        double length0=i00->dist(*i01);
#define NP 5
        double d[NP*2]={length0*1.0001};
        for(int i=0;i<NP*2;i++)
          d[i]=DBL_MAX;
        point *cp[NP*2];
        b.find_closest(*i00,NP,d,cp);
        b.find_closest(*i01,NP,d+NP,cp+NP);
        for(int i=0;i<NP*2;i++){
          if(d[i]>length0)
            break;
          if(i00!=cp[i]->it_loop && i01!=cp[i]->it_loop){
            loop::iterator i10=cp[i]->it_loop;
            loop::iterator i11=l->next(i10);
            if((i11!=l->begin() || l->closed) &&(i11 != i00 && i11 != i01))
              if(is_intersected(*i00,*i01,*i10,*i11)){
                if(l->length(i11,i00)<l->length(i01,i10))
                  i00=l->remove_range(i11,i00);
                else
                  i00=l->remove_range(i01,i10);
                result=true;
                if(i00!=l->begin())
                  i00--;
                break;
              }
            i11=i10;
            i10=l->prev(i11);
            if((i11!=l->begin() || l->closed) &&(i10 != i00 && i10 != i01))
              if(is_intersected(*i00,*i01,*i10,*i11)){
                if(l->length(i11,i00)<l->length(i01,i10))
                  i00=l->remove_range(i11,i00);
                else
                  i00=l->remove_range(i01,i10);
                result=true;
                if(i00!=l->begin())
                  i00--;
                break;
              }
          }
        }
      }
      return result;
    }

    bool loop_check_close_points_self(loop *l,box &b){
      bool result=false;
      bool reverse_stereo=(l->orientation(l->begin(),--l->end(),false)<0);
      for(loop::iterator i=l->begin();i!=l->end();){
        double d[2]={i->min_dist*1.001,i->min_dist*1.001};
        point *cp[2];
        b.find_closest(*i,2,d,cp);
        if(d[1]<i->min_dist){
          loop::iterator id1=cp[1]->it_loop;
          int not_a_loop=-1;
          if(!l->closed){
            loop::iterator ii;
            for(ii=i;ii!=l->end() && ii!=id1;ii++);
            not_a_loop= ii==l->end()?0:1;
          }
          if(not_a_loop!=0 && (l->orientation(i,id1,reverse_stereo)==-1 || l->length(i,id1)<3)){
            i=l->remove_range(i,id1);
            result=true;
          }
          if(not_a_loop!=1 &&(l->orientation(id1,i,reverse_stereo)==-1 || l->length(id1,i)<3)){
            i=l->remove_range(id1,i);
            result=true;
          }else
            i++;
        }else
          i++;
      }
      return result;
    }

    bool loop_check_small_angles(loop *l){
      bool removed=false;
      for(loop::iterator i=l->begin();i!=l->end();++i){
        loop::iterator i1=l->next(i);
        loop::iterator i2=l->next(i1);
        if((!l->closed) && i2==l->begin())
          break;
        double alpha=get_angle(*i,*i1,*i2);
        if(alpha>3*M_PI/4){
          i1->b->remove(&*i1);
          i=l->erase(i1);
          removed=true;
        }
      }
      return removed;
    }

    bool loop_check_close_points(loop *l,box &b){
#define NPD 10
      for(loop::iterator i=l->begin();i!=l->end();){
        double d[NPD];
        point *cp[NPD];
        for(int j=0;j<NPD;j++){
          d[j]=i->min_dist*1.001;
          cp[j]=NULL;
        }
        b.find_closest(*i,NPD,d,cp);
        bool merged=false;
        for(int j=0;j<NPD;j++){
          if(!cp[j])break;
          if(i->l!=cp[j]->l){
            double lat,lon;
            i->to_latlon(lat,lon);
            loop::iterator f0=i;
            loop::iterator f1=cp[j]->it_loop;
            double newx[3],dx[3],crossx[3];
            for(int k=0;k<3;k++){
              newx[k]=(f0->v[k]+f1->v[k])/2;
              dx[k]=(f1->v[k]-f0->v[k])/2;
            }
            for(int k=0;k<3;k++){
              int k1=(k+1)%3;
              int k2=(k+2)%3;
              crossx[k]=newx[k1]*dx[k2]-newx[k2]*dx[k1];
            }
            double norm=sqrt(crossx[0]*crossx[0]+crossx[1]*crossx[1]+crossx[2]*crossx[2]);
            for(int k=0;k<3;k++){
              crossx[k]*=i->min_dist*0.1/norm;
              f0->v[k]=newx[k]-crossx[k];
              f1->v[k]=newx[k]+crossx[k];
            }

            l->insert_range(++f0,f1->l->next(f1),f1);
            cp[j]->l->clear();
            merged=true;
            break;
          }
        }
        if(!merged)
          i++;
      }
      return true;
    }
    class GeoEarthImport
    {
      std::ostringstream loop_buff, surface_buff;;
      std::string filename;
      std::ofstream *file;
      int il, ip, is, ill, ifi;
      int first_point_in_loop, first_point_in_surface,first_point_in_attractor;
      bool empty_surface;
      void new_attractor(){
        first_point_in_attractor = ip;
      }
      void new_surface() {
        surface_buff.str("");
        surface_buff << "Plane Surface( IS + " << is++ << " ) = { ";
        first_point_in_surface = ip;
        empty_surface = true;
      }
      void new_loop(){
        loop_buff.str("");
        first_point_in_loop = ip;
      }
      public:
      GeoEarthImport(const std::string _filename, bool  write_polar_sphere,double radius)
      {
        filename = _filename;
        file=new std::ofstream(filename.c_str());
        loop_buff.precision(16);
        std::ostringstream buff;
        il = ip = ill = is = ifi = 0;
        buff << "IP = newp;\n";
        buff << "IL = newl;\n";
        buff << "ILL = newll;\n";
        buff << "IS = news;\n";
        buff << "IFI = newf;\n";
        if(write_polar_sphere){
          buff << "Point ( IP + " << ip++ << " ) = {0, 0, 0 };\n";
          buff << "Point ( IP + " << ip++ <<" ) = {0, 0,"<<radius<<"};\n";
          buff << "PolarSphere ( IS + " << is++ << " ) = {IP , IP+1};\n";
        }
        *file << buff.str();
        new_surface();
        new_attractor();
        new_loop();
      }
      ~GeoEarthImport(){
        //file << "Euclidian Coordinates;";
        file->close();
      }
      void add_point(SPoint3 point){
        double r=sqrt(point.x()*point.x()+point.y()*point.y()+point.z()*point.z());
        SPoint2 stereo(-point.x() / (r + point.z()), -point.y() / (r + point.z()));
        loop_buff << "Point ( IP + " << ip++ << " ) = {" << stereo.
          x() << ", " << stereo.y() << ", " << 0 << " };\n";
      }
      void end_loop(bool closed) {
        if(ip - first_point_in_loop > 3) {
          loop_buff<<"LoopStart"<<il<<" = IP + "<< first_point_in_loop<<";\n";
          loop_buff<<"LoopEnd"<<il<<" = IP + "<< ip - 1<<";\n";
          loop_buff << "Spline ( IL + " << il++ << " ) = { IP + " <<
            first_point_in_loop << " : IP + " << ip - 1 ;
          if(closed) loop_buff<< ", IP + " << first_point_in_loop;
          loop_buff<< " };\n";
          if(closed){
            loop_buff << "Line Loop ( ILL + " << ill++ << " ) = { IL + " << il -
              1 << " };";
          }
          *file << loop_buff.str();
          if(closed){
            if(!empty_surface)
              surface_buff << ", ";
            surface_buff << "ILL + " << ill - 1;
            empty_surface = false;
          }
        }
        else {
          ip = first_point_in_loop;
        }
        new_loop();
      }
      void end_surface(){
        if(!empty_surface) {
          surface_buff << "};\n";
          surface_buff.str("");
          *file << surface_buff.str()<<"\n";
        }
        new_surface();
      }
      void end_attractor(){
        *file << "Field [ IFI + " << ifi << "]  = Attractor;\n";
        *file << "Field [ IFI + " << ifi++ << "].NodesList  = { IP + " <<
          first_point_in_attractor << " : IP + " << ip - 1 << " };";
        new_attractor();
      }
    };
    void getName(char *name) const;
    void getInfos(char *author, char *copyright, char *help_text) const;
    void catchErrorMessage(char *errorMessage) const;
    int getNbOptions() const;
    int getNbOptionsStr() const;
    StringXNumber *getOption(int iopt);
    StringXString *getOptionStr(int iopt);
    PView *execute(PView *);
};









// ************** MAIN PLUGIN ************** 
StringXNumber GSHHSOptions_Number[] = {
  {GMSH_FULLRC, "iField", NULL, -1.},
  {GMSH_FULLRC, "UTMZone", NULL, 0},
  {GMSH_FULLRC, "UTMEquatorialRadius", NULL, 6378137},
  {GMSH_FULLRC, "UTMPolarRadius", NULL, 6356752.3142},
  {GMSH_FULLRC, "radius", NULL,6371009},
  {GMSH_FULLRC, "WritePolarSphere",NULL,1},
  {GMSH_FULLRC, "MinStraitsFactor",NULL,1}
};
StringXString GSHHSOptions_String[] = {
  {GMSH_FULLRC, "InFileName", NULL, "gshhs_c.b"},
  {GMSH_FULLRC, "OutFileName", NULL, "earth.geo"},
  {GMSH_FULLRC, "Format", NULL, "gshhs"},
  {GMSH_FULLRC, "Coordinate", NULL, "cartesian"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterGSHHSPlugin()
  {
    return new GMSH_GSHHSPlugin();
  }
}

void GMSH_GSHHSPlugin::getName(char *name) const
{
  strcpy(name, "GSHHS");
}

void GMSH_GSHHSPlugin::getInfos(char *author, char *copyright,
    char *help_text) const
{
  strcpy(author, "J. Lambrechts");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text, 
      "Plugin(GSHHS) read different kind of contour lines data and write a .geo file on the surface of a sphere (the Earth).\n"
      "The principal application is to load GSHHS data\n (see http://www.soest.hawaii.edu/wessel/gshhs/gshhs.html).\n"
      "Valid values for \"Format\" are ):\n"
      " -\"gshhs\" : open GSHHS file\n"
      " -\"loops2\" : import 2D contour lines in simple text format :\n"
      "   NB_POINTS_IN_FIRST_LOOP FIRST_LOOP_IS_CLOSED\n"
      "   COORD1 COORD2\n"
      "   COORD1 COORD2\n"
      "   ...    ...\n"
      "   NB_POINTS_IN_SECOND_LOOP SECOND_LOOP_IS_CLOSED\n"
      "   ...\n"
      "   (LOOP_IS_CLOSED specify if this coast line describe a closed curve (0=no, 1=yes).\n"
      "In the case of \"loops2\" format, you can specify the the coordinate system used in the input file with the"
      "\"Coordinate\" option, valid values are\n"
      " -\"lonlat\" for longitude-latidute radian,\n"
      " -\"lonlat_degrees\" for longitude-latitude degrees,\n"
      " -\"UTM\" for universal transverse mercartor (\"UTMZone\" option should be specified)\n"
      " -\"cartesian\" for full 3D coordinates\n"
      "\"radius\" specify the earth radius.\n"
      "If the \"iField\" option is set, consecutive points closer than the value of the field iField (in meters) will not be added.\n"
      "If \"MinStraitsFactor\" >0 and if a field iField is provided, coastlines closer than MinStraitsFactor*field(IField) are merged and inner corners which form an angle < pi/3 are removed.\n"
      "The output is always in stereographic coordinates, if the \"WritePolarSphere\" option is not 0, a sphere is added to the geo file.\n"
      "WARNING : this plugin is still experimental and need polishing and error-handling. In particular, it will probably crash if an inexistant field id is given or if the input/output cannot be open."
      );
}

int GMSH_GSHHSPlugin::getNbOptions() const
{
  return sizeof(GSHHSOptions_Number) / sizeof(StringXNumber);
}

int GMSH_GSHHSPlugin::getNbOptionsStr() const
{
  return sizeof(GSHHSOptions_String) / sizeof(StringXString);
}

StringXNumber *GMSH_GSHHSPlugin::getOption(int iopt)
{
  return &GSHHSOptions_Number[iopt];
}

StringXString *GMSH_GSHHSPlugin::getOptionStr(int iopt)
{
  return &GSHHSOptions_String[iopt];
}

void GMSH_GSHHSPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "GSHHS failed...");
}

PView *GMSH_GSHHSPlugin::execute(PView * v)
{
  void projector(SPoint2,SPoint3);
  int iField = (int)GSHHSOptions_Number[0].def;
  char *filename = (char *)GSHHSOptions_String[0].def.c_str();
  char *outfilename = (char *)GSHHSOptions_String[1].def.c_str();
  std::string format(GSHHSOptions_String[2].def);
  std::string coordinate_name(GSHHSOptions_String[3].def);
  int utm_zone=(int)GSHHSOptions_Number[1].def;
  double utm_equatorial_radius=(double)GSHHSOptions_Number[2].def;
  double utm_polar_radius=(double)GSHHSOptions_Number[3].def;
  double radius=(double)GSHHSOptions_Number[4].def;
  bool write_polar_sphere = (bool)GSHHSOptions_Number[5].def;
  double straits_factor = (double)GSHHSOptions_Number[6].def;
  coordinate_lonlat lonlat(radius);
  coordinate_lonlat_degrees lonlat_degrees(radius);
  coordinate_utm utm(utm_zone, radius,utm_equatorial_radius, utm_polar_radius);
  GeoEarthImport geo_import(outfilename,write_polar_sphere,radius);
  coordinate_system *c_syst=NULL;
  if(coordinate_name == "lonlat")
    c_syst=&lonlat;
  else if(coordinate_name == "lonlat_degrees")
    c_syst=&lonlat_degrees;
  else if(coordinate_name == "utm")
    c_syst=&utm;
  else if(coordinate_name != "cartesian"){
    Msg::Error("gshhs: Unknown coordinate system %s.\n",
        coordinate_name.c_str());
    return NULL;
  }
  Field *field = NULL;
  if (iField != -1) {
    field = GModel::current()->getFields()->get(iField);
    if(!field){
      Msg::Error("Field[%d] does not exist", iField);
      return NULL;
    }
  }
  double x,y,z;
  SPoint3 p;
  reader *read;
  if(format == "loops2") {
    read=new reader_loops2(filename);
  }else if(format == "gshhs") {
    c_syst=&lonlat;
    read=new reader_gshhs(filename);
  }
  loops ll;
  bool closed;
  while(read->next_loop(closed)!=0){
    loop l;
    l.closed=closed;
    point oldp(0,0,0,0.);
    while(read->next_point(p)){
      if(c_syst)
        c_syst->to_cartesian(p,p);
      point newp(p[0],p[1],p[2],field);
      if(newp.min_dist<0){
        while(!l.empty() && l.back().dist(l.front())<l.back().min_dist)
          l.pop_back();
        l.closed=false;
        if(l.size()>=3)
          ll.push_back(l);
        l.clear();
      } else if (l.empty() || oldp.dist(newp)>newp.min_dist){
        l.push_back(newp);
        oldp=newp;
      }
    }
    while(!l.empty() && l.back().dist(l.front())<l.back().min_dist)
      l.pop_back();
    if(l.size()>=3)
      ll.push_back(l);
  }
  delete read;
  if(straits_factor>0 && iField !=0){
    for(loops::iterator il=ll.begin();il!=ll.end();il++)
      for(loop::iterator ip=il->begin();ip!=il->end();ip++)
        ip->min_dist*=straits_factor;
    box *b=new box(point(-radius,-radius,-radius,0.),point(radius,radius,radius,0.));
    for(loops::iterator il=ll.begin();il!=ll.end();il++)
      loop_fill_box(&*il,*b);
    for(loops::iterator il=ll.begin();il!=ll.end();il++)
      loop_check_close_points(&*il,*b);
    delete b;
    for(loops::iterator il=ll.begin();il!=ll.end();il++){
      box b(point(-radius,-radius,-radius,0.),point(radius,radius,radius,0.));
      loop_fill_box(&*il,b);
      while(false 
          || loop_check_small_angles(&*il)
          || loop_check_close_points_self(&*il,b)
          || loop_check_intersections(&*il,b)
          );
    }
  }
  for(std::list<loop>::iterator l=ll.begin();l!=ll.end();l++){
    for(loop::iterator p=l->begin();p!=l->end();p++)
      geo_import.add_point(p->v);
    geo_import.end_loop(l->closed);
  }
  geo_import.end_surface();
  geo_import.end_attractor();

  return NULL;
}

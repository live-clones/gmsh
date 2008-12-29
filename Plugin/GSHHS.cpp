// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GSHHS.h"
#include "Field.h"
#include "GModel.h"
#include <sstream>
#include <fstream>
/*static void projectInvStereo(Point &pplan,Point3D &psphere){
	double rp2=pplan.x*pplan.x+pplan.y*pplan.y;
	psphere.z= (4-rp2)/(4+rp2);
	psphere.x= (1+psphere.z)/2*pplan.x;
	psphere.y= (1+psphere.z)/2*pplan.y;
	psphere.zone_id=pplan.zone_id;
}
static void projectStereo(Point3D &psphere,Point &pplan){
	pplan.x=2*psphere.x/(psphere.z+1);
	pplan.y=2*psphere.y/(psphere.z+1);
	pplan.zone_id=psphere.zone_id;
}*/
// ************** Coordinate Systems *************
class coordinate_system{
  public:
  virtual void to_cartesian(const SPoint3 coord, SPoint3 &cartesian)=0;
  virtual void from_cartesian(const SPoint3 cartesian, SPoint3 &coord)=0;
};
// ************** Longitude Latitude ***************
class coordinate_lonlat:public coordinate_system{
  public:
  void to_cartesian(const SPoint3 ll, SPoint3 &xyz){
    double clat = cos(ll.y());
    xyz.setPosition( clat * cos(ll.x()), clat * sin(ll.x()), sin(ll.y()));
  }
  void from_cartesian(const SPoint3 xyz, SPoint3 &ll){
    double r=sqrt(xyz.x()*xyz.x()+xyz.y()*xyz.y()+xyz.z()*xyz.z());
    ll.setPosition( atan2(xyz.y(),xyz.x()), asin(xyz.z()/r), 0);
  }
};
// ************** Longitude Latitude (degrees) ***************
class coordinate_lonlat_degrees:public coordinate_system{
  coordinate_lonlat cll;
  SPoint3 llradian;
  public:
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
  coordinate_utm(int _zone, double _a = 6378137, double _b = 6356752.3142) {
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
class GeoEarthImport
{
  Field *size_field;
  std::ostringstream loop_buff, surface_buff;;
  std::string filename;
  std::ofstream *file;
  int il, ip, is, ill, ifi;
  int first_point_in_loop, first_point_in_surface,first_point_in_attractor;
  bool empty_surface,closed_loop;
  SPoint3 lastpoint;
  coordinate_system *c_syst;
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
    closed_loop=true;
  }

  public:
  void set_coordinate_system(coordinate_system *_c_syst){
    c_syst=_c_syst;
  }
  GeoEarthImport(const std::string _filename, bool  write_polar_sphere){
    c_syst=NULL;
    filename = _filename;
    file=new std::ofstream(filename.c_str());
    size_field = NULL;
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
      buff << "Point ( IP + " << ip++ <<" ) = {0, 0, 6.371e6 };\n";
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
  void set_size_field(Field * _size_field){
    size_field = _size_field;
  }
  void add_point(SPoint3 point){
    if(c_syst)
      c_syst->to_cartesian(point,point);
    double lc=0;
    if(size_field){
      double d=(*size_field)(point[0]* 6361e3,point[1]* 6361e3,point[2]* 6361e3);
      if(d<0){
        if(first_point_in_loop!=ip){
          closed_loop=false;
          end_loop();
          closed_loop=false;
        }
       return; 
      }
      lc=std::min(d, (*size_field) (lastpoint[0],lastpoint[1],lastpoint[2]));
    }
    lc/=6361e3;
    if(ip == first_point_in_loop || point.distance(lastpoint) >lc){
      SPoint2 stereo(-point.x() / (1 + point.z()), -point.y() / (1 + point.z()));
      loop_buff << "Point ( IP + " << ip++ << " ) = {" << stereo.
      x() << ", " << stereo.y() << ", " << 0 << " };\n";
      lastpoint = point;
    }
  }
  void end_loop(bool closed=true) {
    closed&=closed_loop;
    if(ip - first_point_in_loop > 3) {
      loop_buff<<"LoopStart"<<il<<" = IP + "<< first_point_in_loop<<";\n";
      loop_buff<<"LoopEnd"<<il<<" = IP + "<< ip - 1<<";\n";
      loop_buff << "BSpline ( IL + " << il++ << " ) = { IP + " <<
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

/*	$Id: GSHHS.cpp,v 1.18 2008-12-29 09:43:39 geuzaine Exp $
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GSHHS_DATA_VERSION	6	/* For v1.5 data set */
#define GSHHS_PROG_VERSION	"1.9"

#define GSHHS_SCL	1.0e-6	/* COnvert micro-degrees to degrees */

/* For byte swapping on little-endian systems (GSHHS is defined to be bigendian) */

#define swabi4(i4) (((i4) >> 24) + (((i4) >> 8) & 65280) + (((i4) & 65280) << 8) + (((i4) & 255) << 24))

struct GSHHS {	/* Global Self-consistent Hierarchical High-resolution Shorelines */
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

struct	POINT {	/* Each lon, lat pair is stored in micro-degrees in 4-byte integer format */
	int	x;
	int	y;
};

void import_gshhs(FILE * fp, GeoEarthImport & geo_import)
{
  double w, e, s, n;
  char source;
  int k, max_east = 270000000, n_read, flip;
  struct POINT p;
  struct GSHHS h;


	n_read = fread ((void *)&h, (size_t)sizeof (struct GSHHS), (size_t)1, fp);
	int version = (h.flag >> 8) & 255;
	flip = (version != GSHHS_DATA_VERSION);	/* Take as sign that byte-swabbing is needed */
	
	while (n_read == 1 && ! feof(fp)) {
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
		int level = h.flag & 255;
		version = (h.flag >> 8) & 255;
		int greenwich = (h.flag >> 16) & 255;
		int src = (h.flag >> 24) & 255;
		w = h.west  * GSHHS_SCL;	/* Convert from microdegrees to degrees */
		e = h.east  * GSHHS_SCL;
		s = h.south * GSHHS_SCL;
		n = h.north * GSHHS_SCL;
		source = (src == 1) ? 'W' : 'C';	/* Either WVS or CIA (WDBII) pedigree */
		int line = (h.area) ? 0 : 1;		/* Either Polygon (0) or Line (1) (if no area) */
    double area = 0.1 * h.area;			/* Now im km^2 */

    if(level != 1) {  // Skip data (lake,island,pond)
      fseek(fp, (size_t)(h.n * sizeof(struct POINT)), SEEK_CUR);
    }else{
      for (k = 0; k < h.n; k++) {
        if (fread ((void *)&p, (size_t)sizeof(struct POINT), (size_t)1, fp) != 1) {
          Msg::Error ("gshhs:  Error reading gshhs file.\n");
          return;
        }
        if (flip) {
          p.x = swabi4 ((unsigned int)p.x);
          p.y = swabi4 ((unsigned int)p.y);
        }
        double lon = p.x * GSHHS_SCL;
        if (greenwich && p.x > max_east) lon -= 360.0;
        double lat = p.y * GSHHS_SCL;
        geo_import.add_point(SPoint3(M_PI/180*lon,M_PI/180*lat,0));
      }
      geo_import.end_loop();
    }
		max_east = 180000000;	/* Only Eurasiafrica needs 270 */
		n_read = fread((void *)&h, (size_t)sizeof (struct GSHHS), (size_t)1, fp);
	}
  geo_import.end_surface();
  geo_import.end_attractor();
}


// ************** MAIN PLUGIN ************** 
StringXNumber GSHHSOptions_Number[] = {
  {GMSH_FULLRC, "iField", NULL, -1.},
  {GMSH_FULLRC, "UTMZone", NULL, 0},
  {GMSH_FULLRC, "UTMEquatorialRadius", NULL, 6378137},
  {GMSH_FULLRC, "UTMPolarRadius", NULL, 6356752.3142},
  {GMSH_FULLRC, "UTMScale", NULL, 1},
  {GMSH_FULLRC, "UTMShiftX", NULL, 0},
  {GMSH_FULLRC, "UTMShiftY", NULL, 0},
  {GMSH_FULLRC, "WritePolarSphere",NULL,1}
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
  strcpy(help_text, "Plugin(GSHHS) read differenct kind of contour lines data and write a .geo file.\n"
  "Valid values for \"Format\" are :\n"
  " -\"gshhs\" : open GSHHS file\n"
  " -\"loops2\" : import 2D contour lines in simple text format :\n"
  "   NB_POINTS_IN_FIRST_LOOP\n"
  "   COORD1 COORD2\n"
  "   COORD1 COORD2\n"
  "   ...    ...\n"
  "   NB_POINTS_IN_SECOND_LOOP\n"
  "   ...\n"
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
  char *filename = (char *)GSHHSOptions_String[0].def;
  char *outfilename = (char *)GSHHSOptions_String[1].def;
  std::string format(GSHHSOptions_String[2].def);
  std::string coordinate_name(GSHHSOptions_String[3].def);
  double scale = GSHHSOptions_Number[4].def;
  double shiftx = GSHHSOptions_Number[5].def;
  double shifty = GSHHSOptions_Number[6].def;
  bool write_polar_sphere = (bool)GSHHSOptions_Number[7].def;
  int utm_zone=(int)GSHHSOptions_Number[1].def;
  double utm_equatorial_radius=(double)GSHHSOptions_Number[2].def;
  double utm_polar_radius=(double)GSHHSOptions_Number[3].def;
  coordinate_lonlat lonlat;
  coordinate_lonlat_degrees lonlat_degrees;
  coordinate_utm utm(utm_zone, utm_equatorial_radius, utm_polar_radius);
  GeoEarthImport geo_import(outfilename,write_polar_sphere);
  if(coordinate_name == "lonlat")
    geo_import.set_coordinate_system(&lonlat);
  else if(coordinate_name == "lonlat_degrees")
    geo_import.set_coordinate_system(&lonlat_degrees);
  else if(coordinate_name == "utm")
    geo_import.set_coordinate_system(&utm);
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
    }else{
      geo_import.set_size_field(field);
    }
  }
  FILE *fp;
  if ((fp = fopen (filename, "rb")) == NULL ) {
    Msg::Error("gshhs: Could not find file %s.\n", filename);
    return NULL;
  }
  double x,y,z;
  if(format == "gshhs") {
    geo_import.set_coordinate_system(&lonlat);
    import_gshhs(fp, geo_import);
  }
  else if(format == "loops2") {
    int npoints_in_loop;
    int closed;
    while(fscanf(fp, "%d %d", &npoints_in_loop,&closed) == 2) {
      for(int i = 0; i < npoints_in_loop; i++) {
        if(fscanf(fp, "%le %le", &x, &y) != 2) {
          Msg::Error("gshhs:  Error reading loops2 file \'%s\'.\n", filename);
          return NULL;
        }
        geo_import.add_point(SPoint3(x,y,0));
      }
      geo_import.end_loop(closed);
    }
    geo_import.end_surface();
    geo_import.end_attractor();
   }
  return NULL;
}

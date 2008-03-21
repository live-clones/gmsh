// $Id: GSHHS.cpp,v 1.5 2008-03-21 18:27:38 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GSHHS.h"
#include "Field.h"
#include "GModel.h"
#include "GeoStringInterface.h"
#include <sstream>
#include <iostream>
#include "Context.h"
#include "GeoEarthImport.h"
extern Context_T CTX;

// ************** GSHHS ************** 
/*      $Id: GSHHS.cpp,v 1.5 2008-03-21 18:27:38 geuzaine Exp $
 *
 * PROGRAM:     gshhs.c
 * AUTHOR:      Paul Wessel (pwessel@hawaii.edu)
 * CREATED:     JAN. 28, 1996
 * PURPOSE:     To extract ASCII data from binary shoreline data
 *              as described in the 1996 Wessel & Smith JGR Data Analysis Note.
 * VERSION:     1.1 (Byte flipping added)
 *              1.2 18-MAY-1999:
 *                 Explicit binary open for DOS systems
 *                 POSIX.1 compliant
 *              1.3 08-NOV-1999: Released under GNU GPL
 *              1.4 05-SEPT-2000: Made a GMT supplement; FLIP no longer needed
 *              1.5 14-SEPT-2004: Updated to deal with latest GSHHS database (1.3)
 *
 *      Copyright (c) 1996-2004 by P. Wessel and W. H. F. Smith
 *      See COPYING file for copying and redistribution conditions.
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; version 2 of the License.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      Contact info: www.soest.hawaii.edu/pwessel */
/* For byte swapping on little-endian systems (GSHHS is bigendian) */
#define swabi2(i2) (((i2) >> 8) + (((i2) & 255) << 8))
#define swabi4(i4) (((i4) >> 24) + (((i4) >> 8) & 65280) + (((i4) & 65280) << 8) + (((i4) & 255) << 24))
#define _POSIX_SOURCE 1 /* GSHHS code is POSIX compliant */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI          3.14159265358979323846
#endif
#ifndef SEEK_CUR        /* For really ancient systems */
#define SEEK_CUR 1
#endif
  struct GSHHS
{                               /* Global Self-consistent Hierarchical High-resolution Shorelines */
  int id;                       /* Unique polygon id number, starting at 0 */
  int n;                        /* Number of points in this polygon */
  int level;                    /* 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake */
  int west, east, south, north; /* min/max extent in micro-degrees */
  int area;                     /* Area of polygon in 1/10 km^2 */
  int version;                  /* Version of GSHHS polygon (3 is latest and first with this item) */
  short int greenwich;          /* Greenwich is 1 if Greenwich is crossed */
  short int source;             /* 0 = CIA WDBII, 1 = WVS */
};

struct POINT
{                               /* Each lon, lat pair is stored in micro-degrees in 4-byte integer format */
  int x;
  int y;
};

void import_gshhs(FILE * fp, GeoEarthImport & geo_import)
{
  double w, e, s, n;
  char source;
  int k, max_east = 270000000, n_read, flip;
  struct POINT p;
  struct GSHHS h;
  while(1) {
    n_read = fread((void *)&h, (size_t) sizeof(struct GSHHS), (size_t) 1, fp);
    if(n_read != 1)
      break;
    flip = (!(h.level > 0 && h.level < 5));     /* Take as sign that byte-swabbing is needed */
    if(flip) {
      h.id = swabi4((unsigned int)h.id);
      h.n = swabi4((unsigned int)h.n);
      h.level = swabi4((unsigned int)h.level);
      h.west = swabi4((unsigned int)h.west);
      h.east = swabi4((unsigned int)h.east);
      h.south = swabi4((unsigned int)h.south);
      h.north = swabi4((unsigned int)h.north);
      h.area = swabi4((unsigned int)h.area);
      h.version = swabi4((unsigned int)h.version);
      h.greenwich = swabi2((unsigned int)h.greenwich);
      h.source = swabi2((unsigned int)h.source);
    }
    w = h.west * 1.0e-6;        /* Convert from microdegrees to degrees */
    e = h.east * 1.0e-6;
    s = h.south * 1.0e-6;
    n = h.north * 1.0e-6;
    source = (h.source == 1) ? 'W' : 'C';       /* Either WVS or CIA (WDBII) pedigree */
    if(h.level != 1) {  // Skip data (lake,island,pond)
      fseek(fp, (long)(h.n * sizeof(struct POINT)), SEEK_CUR);
      continue;
    }
    for(k = 0; k < h.n; k++) {
      if(fread((void *)&p, (size_t) sizeof(struct POINT), (size_t) 1, fp) !=
         1) {
        Msg(GERROR,
            "gshhs:  Error reading gshhs file for polygon %d, point %d.\n",
            h.id, k);
        return;
      }
      if(flip) {
        p.x = swabi4((unsigned int)p.x);
        p.y = swabi4((unsigned int)p.y);
      }
      SPoint2 ll(((h.greenwich
                   && p.x >
                   max_east) ? p.x * 1.0e-6 -
                  360.0 : p.x * 1.0e-6) * M_PI / 180,
                 (p.y * 1.0e-6) * M_PI / 180);
      geo_import.add_point_lon_lat(ll);
    }
    geo_import.end_loop();
  }
  geo_import.end_surface();
}


// ************** UTM ************** 
#include "math.h"
#include "stdio.h"
class UTM
{
  public:double x, y;
  int zone;
    UTM():x(0), y(0), zone(-1)
  {
  };
  UTM(double _x, double _y, int _zone):x(_x), y(_y), zone(_zone)
  {
  };
};
class UTMConverter
{
  double meridionalarc(double lat, double lon);
  double a, b, n, n2, n3, n4, n5, e, e2, e1, e12, e13, e14, J1, J2, J3, J4,
    Ap, Bp, Cp, Dp, Ep, e4, e6, ep, ep2, ep4, k0, mu_fact;
    public: void latlon2utm(double lat, double lon, UTM & utm);
  void utm2latlon(UTM & utm, double &lat, double &lon);
    UTMConverter(double _a = 6378137, double _b = 6356752.3142) {
    /* see http://www.uwgb.edu/dutchs/UsefulData/UTMFormulas.HTM */
    a = _a;     /* Rayon Equatorial */
    b = _b;                     /* Rayon Polaire */
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
    Bp =
      -3 * a * n / 2 * (1 - n + (7. / 8.) * (n2 - n3) +
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


double UTMConverter::meridionalarc(double lat, double lon)
{
  return Ap * lat + Bp * sin(2 * lat) + Cp * sin(4 * lat) +
    Dp * sin(6 * lat) + Ep;
}

void UTMConverter::utm2latlon(UTM & utm, double &lat, double &lon)
{
  double mu = utm.y * mu_fact;
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
  double d = (utm.x - 5e5) / (n1 * k0);
  double d2 = d * d;
  double d3 = d2 * d;
  double d4 = d2 * d2;
  double d5 = d4 * d;
  double d6 = d4 * d2;
  lat =
    fp - n1 * sfp / cfp / r1 * (d2 / 2 -
                                (5 + 3 * t1 + 10 * c1 - 4 * c12 -
                                 9 * ep2) * d4 / 24 + (61 + 90 * t1 +
                                                       298 * c1 + 45 * t12 -
                                                       3 * c12 -
                                                       252 * ep2) * d6 / 720);
  lon =
    ((utm.zone - 0.5) / 30 - 1) * M_PI + (d - (1 + 2 * t1 + c1) * d3 / 6 +
                                          (5 - 2 * c1 + 28 * t1 - 3 * c12 +
                                           8 * ep2 +
                                           24 * t12) * d5 / 120) / cfp;
}

void UTMConverter::latlon2utm(double lat, double lon, UTM & utm)
{
  if(utm.zone == -1)
    utm.zone = (int)ceil((lon / M_PI + 1) * 30);
  double S = meridionalarc(lat, lon);
  double slat = sin(lat);
  double clat = cos(lat);
  double slat2 = slat * slat;
  double clat2 = clat * clat;
  double clat3 = clat2 * clat;
  double clat4 = clat3 * clat;
  double tlat2 = slat2 / clat2;
  double nu = a / sqrt(1 - e * e * slat2);
  double p = lon - ((utm.zone - 0.5) / 30 - 1) * M_PI;
  double p2 = p * p;
  double p3 = p * p2;
  double p4 = p2 * p2;
  utm.y =
    S * k0 + k0 * nu * slat * clat / 2 * p2 +
    k0 * nu * slat * clat3 / 24 * (5 - tlat2 + 9 * ep2 * clat2 +
                                   4 * ep4 * clat4) * p4;
  utm.x =
    k0 * nu * clat * p + (k0 * nu * clat3 / 6) * (1 - tlat2 +
                                                  ep2 * clat2) * p3 + 5e5;
}

// ************** MAIN PLUGIN ************** 
StringXNumber GSHHSOptions_Number[] = {
  {GMSH_FULLRC, "iField", NULL, -1.},
  {GMSH_FULLRC, "UTMEquatorialRadius", NULL, 6378137},
  {GMSH_FULLRC, "UTMPolarRadius", NULL, 6356752.3142},
  {GMSH_FULLRC, "UTMScale", NULL, 1},
  {GMSH_FULLRC, "UTMShiftX", NULL, 0},
  {GMSH_FULLRC, "UTMShiftY", NULL, 0},
  {GMSH_FULLRC, "UTMZone", NULL, 0}

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
  strcpy(author, "J. Lambrechts (jonathanlambrechts@gmail.com)");
  strcpy(copyright, "GPL");
  strcpy(help_text, "Plugin(GSHHS) import GSHHS data.\n");
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
  int iField = (int)GSHHSOptions_Number[0].def;
  char *filename = (char *)GSHHSOptions_String[0].def;
  char *outfilename = (char *)GSHHSOptions_String[1].def;
  std::string format(GSHHSOptions_String[2].def);
  std::string coordinate_name(GSHHSOptions_String[3].def);
  double scale = GSHHSOptions_Number[3].def;
  double shiftx = GSHHSOptions_Number[4].def;
  double shifty = GSHHSOptions_Number[5].def;
  if(coordinate_name != "cartesian" && coordinate_name != "utm") {
    Msg(GERROR, "gshhs: unknown coordinate system %s.\n",
        coordinate_name.c_str());
    return NULL;
  }
  Field *field = NULL;
  GeoEarthImport geo_import(outfilename);
  if(iField != -1) {
    field = GModel::current()->getFields()->get(iField);
    if(!field) {
      Msg(GERROR, "Field[%d] does not exist", iField);
      return NULL;
    }
    else {
      geo_import.set_size_field(field);
    }
  }
  FILE *fp;
  if((fp = fopen(filename, "rb")) == NULL) {
    Msg(GERROR, "gshhs: Could not open file %s.\n", filename);
    return NULL;
  }
  if(format == "gshhs") {
    import_gshhs(fp, geo_import);
  }
  else if(format == "loops2") {
    int npoints_in_loop;
    UTMConverter utmc((double)GSHHSOptions_Number[1].def,
                      (double)GSHHSOptions_Number[2].def);
    UTM utm;
    while(fscanf(fp, "%d", &npoints_in_loop) == 1) {
      utm.zone = (int)GSHHSOptions_Number[6].def;
      for(int i = 0; i < npoints_in_loop; i++) {
        if(fscanf(fp, "%le %le", &utm.x, &utm.y) != 2) {
          Msg(GERROR, "gshhs:  Error reading loops2 file \'%s\'.\n",
              filename);
          return NULL;
        }
        double lat, lon;
        utm.x = utm.x * scale + shiftx;
        utm.y = utm.y * scale + shifty;
        utmc.utm2latlon(utm, lat, lon);
        geo_import.add_point_lon_lat(SPoint2(lon, lat));
      }
      geo_import.end_loop();
    }
    geo_import.end_surface();
  }
  else {
    Msg(GERROR, "gshhs: Unknown format %s.\n", format.c_str());
    return NULL;
  }
  return NULL;
}

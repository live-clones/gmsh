// $Id: GSHHS.cpp,v 1.1 2008-03-18 09:27:59 remacle Exp $
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

/*	$Id: GSHHS.cpp,v 1.1 2008-03-18 09:27:59 remacle Exp $
 *
 * PROGRAM:	gshhs.c
 * AUTHOR:	Paul Wessel (pwessel@hawaii.edu)
 * CREATED:	JAN. 28, 1996
 * PURPOSE:	To extract ASCII data from binary shoreline data
 *		as described in the 1996 Wessel & Smith JGR Data Analysis Note.
 * VERSION:	1.1 (Byte flipping added)
 *		1.2 18-MAY-1999:
 *		   Explicit binary open for DOS systems
 *		   POSIX.1 compliant
 *		1.3 08-NOV-1999: Released under GNU GPL
 *		1.4 05-SEPT-2000: Made a GMT supplement; FLIP no longer needed
 *		1.5 14-SEPT-2004: Updated to deal with latest GSHHS database (1.3)
 *
 *	Copyright (c) 1996-2004 by P. Wessel and W. H. F. Smith
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
 *	Contact info: www.soest.hawaii.edu/pwessel */

/* For byte swapping on little-endian systems (GSHHS is bigendian) */
#define swabi2(i2) (((i2) >> 8) + (((i2) & 255) << 8))
#define swabi4(i4) (((i4) >> 24) + (((i4) >> 8) & 65280) + (((i4) & 65280) << 8) + (((i4) & 255) << 24))
#define _POSIX_SOURCE 1		/* GSHHS code is POSIX compliant */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI          3.14159265358979323846
#endif

#ifndef SEEK_CUR	/* For really ancient systems */
#define SEEK_CUR 1
#endif

struct GSHHS {	/* Global Self-consistent Hierarchical High-resolution Shorelines */
	int id;				/* Unique polygon id number, starting at 0 */
	int n;				/* Number of points in this polygon */
	int level;			/* 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake */
	int west, east, south, north;	/* min/max extent in micro-degrees */
	int area;			/* Area of polygon in 1/10 km^2 */
	int version;			/* Version of GSHHS polygon (3 is latest and first with this item) */
	short int greenwich;		/* Greenwich is 1 if Greenwich is crossed */
	short int source;		/* 0 = CIA WDBII, 1 = WVS */
};

struct	POINT {	/* Each lon, lat pair is stored in micro-degrees in 4-byte integer format */
	int	x;
	int	y;
};

StringXNumber GSHHSOptions_Number[] = {
  {GMSH_FULLRC, "iField", NULL, -1.}
};
StringXString GSHHSOptions_String[] = {
	{GMSH_FULLRC, "InFileName",NULL,"gshhs_c.b"},
	{GMSH_FULLRC, "OutFileName",NULL,"earth.geo"}
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
  strcpy(author, "J. Lambrechts (jonathanlambrechts@gmail.org)");
  strcpy(copyright, "GPL");
  strcpy(help_text,
	 "Plugin(GSHHS) import GSHHS data.\n");
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

PView *GMSH_GSHHSPlugin::execute(PView *v)
{
  int iField = (int)GSHHSOptions_Number[0].def;
	char *filename=(char*)GSHHSOptions_String[0].def;
	char *outfilename=(char*)GSHHSOptions_String[1].def;
	Field *field=NULL;
	GeoEarthImport geo_import(outfilename);
	if(iField!=-1){
		field = GModel::current()->fields.get(iField);
		if(!field){
			Msg(GERROR, "Field[%d] does not exist", iField);
			return NULL;
		}else{
			geo_import.set_size_field(field);
		}
	}
	FILE *fp;
	if ((fp = fopen (filename, "rb")) == NULL ) {
		Msg(GERROR, "gshhs: Could not find file %s.\n", filename);
		return NULL;
	}
	double w, e, s, n;
	char source;
	int	k, max_east = 270000000, info, n_read, flip;
	struct	POINT p;
	struct GSHHS h;
	while(1){
		n_read = fread ((void *)&h, (size_t)sizeof (struct GSHHS), (size_t)1, fp);
		if(n_read!=1)break;
		flip = (! (h.level > 0 && h.level < 5));	/* Take as sign that byte-swabbing is needed */
		if (flip) {
			h.id = swabi4 ((unsigned int)h.id);
			h.n  = swabi4 ((unsigned int)h.n);
			h.level = swabi4 ((unsigned int)h.level);
			h.west  = swabi4 ((unsigned int)h.west);
			h.east  = swabi4 ((unsigned int)h.east);
			h.south = swabi4 ((unsigned int)h.south);
			h.north = swabi4 ((unsigned int)h.north);
			h.area  = swabi4 ((unsigned int)h.area);
			h.version  = swabi4 ((unsigned int)h.version);
			h.greenwich = swabi2 ((unsigned int)h.greenwich);
			h.source = swabi2 ((unsigned int)h.source);
		}
		w = h.west  * 1.0e-6;	/* Convert from microdegrees to degrees */
		e = h.east  * 1.0e-6;
		s = h.south * 1.0e-6;
		n = h.north * 1.0e-6;
		source = (h.source == 1) ? 'W' : 'C';	/* Either WVS or CIA (WDBII) pedigree */
		if ( h.level!=1) {	// Skip data (lake,island,pond)
			fseek (fp, (long)(h.n * sizeof(struct POINT)), SEEK_CUR);
			continue;
		} 
		for (k = 0; k < h.n; k++) {
			if (fread ((void *)&p, (size_t)sizeof(struct POINT), (size_t)1, fp) != 1) {
				Msg(GERROR, "gshhs:  Error reading gshhs file for polygon %d, point %d.\n",h.id, k);
				return NULL;
			}
			if (flip) {
				p.x = swabi4 ((unsigned int)p.x);
				p.y = swabi4 ((unsigned int)p.y);
			}
			SPoint2 ll(
				((h.greenwich && p.x > max_east) ? p.x * 1.0e-6 - 360.0 : p.x * 1.0e-6)*M_PI/180,
				 (p.y * 1.0e-6)*M_PI/180);
			geo_import.add_point_lon_lat(ll);
		}
		geo_import.end_loop();
	} 
	geo_import.end_surface();
  return NULL;
}

#ifndef _EXTRUDE_PARAMS_H_
#define _EXTRUDE_PARAMS_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

// geo.Mode
#define EXTRUDED_ENTITY 1
#define COPIED_ENTITY 2

// geo.Type
#define TRANSLATE 1
#define ROTATE 2
#define TRANSLATE_ROTATE 3

class ExtrudeParams{
private :
  bool  _useZonLayer;
public :
  ExtrudeParams(int Mode = EXTRUDED_ENTITY);
  void fill(int type,
	    double T0, double T1, double T2,
	    double A0, double A1, double A2,
	    double X0, double X1, double X2, double angle);
  double u(int iLayer, int iElemLayer);
  void Extrude(int iLayer, int iElemLayer,
	       double &dx, double &dy, double &dz);
  void Extrude(double t, double &x, double &y, double &z);
  void Rotate(double matr[3][3]);
  void useZonLayer(bool val){ _useZonLayer = val; };
  bool useZonLayer(){ return _useZonLayer; };
  struct{
    bool    ExtrudeMesh;
    bool    Recombine;
    int     NbLayer;
    int     *NbElmLayer;
    int     *ZonLayer;
    double  *hLayer;
  }mesh;
  struct{
    int Mode;
    int Type;
    int Source;
    double trans[3];
    double axe[3], pt[3], angle;
  }geo;
  
};

#endif

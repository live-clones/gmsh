#ifndef STRUCTURAL_SOLVER_H_
#define STRUCTURAL_SOLVER_H_
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include <map>
#include <list>
#include <vector>
#include "Geo.h"
#include "Mesh.h"
#include "Plugin.h"
#include <string>

#ifdef HAVE_FLTK
#include "GmshUI.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tabs.H>
#include <FL/filename.H>
#include <FL/Fl_PNG_Image.H>
#endif

extern "C"
{
  GMSH_Plugin *GMSH_RegisterStructuralSolverPlugin();
}

struct Structural_Texture
{
  std::string filename;
#ifdef HAVE_FLTK
  GLuint  tag ;
#endif
  void setup();
};

struct Structural_BeamSection
{
  Mesh m;
  double xc,yc,area,Iy,Iz,J;
  std::string name;
  Structural_BeamSection ( const char *direct, std::string _name );
  ~Structural_BeamSection();
  void computeGeometricalProperties();
  void GL_DrawBeam (double pinit[3], double dir[3], const double Y[3], Structural_Texture &texture);
};

struct Structural_Material
{
  std::string name;
  std::vector<double> par;
};



struct PhysicalPointInfo 
{
  double angle;
  int disp[3];
  double val[3];
};

struct PhysicalLineInfo 
{
  PhysicalLineInfo() : fx1(0),fx2(0),fy1(0),fy2(0),fz1(0),fz2(0){dirz[0]=0;dirz[1]=0;dirz[2]=1;}
  std::string material, section, model;
  double fx1,fx2,fy1,fy2,fz1,fz2;
  double dirz[3];
};


class StructuralSolver : public GMSH_Solve_Plugin
{
  std::list < struct Structural_BeamSection*     > beam_sections;
  std::list < struct Structural_Material  > materials;
  std::map <int, struct PhysicalPointInfo  > points;
  std::map <int, struct PhysicalLineInfo   > lines;
  std::map <std::string , struct Structural_Texture   > textures;
  void    RegisterBeamSections     ();
  void    RegisterMaterials        ();
  void addPhysicalPoint         (int id);
  void addPhysicalLine          (int id);
#ifdef HAVE_FLTK 
  Fl_Window        *_window ;
  Fl_Value_Input   *_value[20] ;
  Fl_Choice        *_choice[20] ;
#endif
  double MAX_FORCE;
  double MAX_DISPLACEMENT;
  Structural_BeamSection* GetBeamSection (const std::string & name) const ;
  Structural_Material    GetMaterial    (const std::string & name) const ;
public:
  StructuralSolver();
  virtual ~StructuralSolver();
  virtual void getName(char *name) const;
  virtual void getInfos(char *author, char *copyright, char *helpText) const;

  // When an error is thrown by the plugin, the plugin manager will
  // show the message and hopefully continue
  virtual void catchErrorMessage(char *errorMessage) const;
  virtual void popupPropertiesForPhysicalEntity (int dim);
  virtual void receiveNewPhysicalGroup (int dim, int id)
  {
    switch(dim){
    case ENT_POINT:addPhysicalPoint(id);break;
    case ENT_LINE:addPhysicalLine(id);break;
    }      
  }
  virtual void writeSolverFile ( const char *geom_file ) const; 
  virtual void readSolverFile  ( const char *geom_file );
  bool GL_enhancePoint ( Vertex *v) ;
  bool GL_enhanceLine (  int CurveId , Vertex *v1, Vertex *v2) ;
};

#endif


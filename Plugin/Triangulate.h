#ifndef _TRIANGULATE_H_
#define _TRIANGULATE_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTriangulatePlugin ();
}

class GMSH_TriangulatePlugin : public GMSH_Post_Plugin
{
public:
  GMSH_TriangulatePlugin();
  virtual void Run();
  virtual void Save();
  virtual void getName  (char *name) const;
  virtual void getInfos (char *author, 
			 char *copyright,
			 char *help_text) const;
  virtual void CatchErrorMessage (char *errorMessage) const;
  virtual int getNbOptions() const;
  virtual StringXNumber* GetOption (int iopt);  
  virtual Post_View *execute (Post_View *);
};
#endif

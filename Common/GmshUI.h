#ifndef _GMSH_UI_H_
#define _GMSH_UI_H_

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

#if defined(HAVE_FLTK)
#  include <FL/Fl.H>
#  if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1)
#    if (FL_PATCH_VERSION >= 6)
#      define HAVE_FLTK_1_1_6_OR_ABOVE
#    endif
#    if (FL_PATCH_VERSION >= 5)
#      define HAVE_FLTK_1_1_5_OR_ABOVE
#    endif
#  else
#    error "Gmsh requires FLTK 1.1.x"
#  endif
#  include <FL/gl.h>
#  if defined(__APPLE__)
#    include <OpenGL/glu.h>
#  else
#    include <GL/glu.h>
#  endif
# define GMSH_WINDOW_BOX   FL_FLAT_BOX
# define GMSH_TOGGLE_BOX   FL_DOWN_BOX
# define GMSH_TOGGLE_COLOR FL_BLACK
# define GMSH_RADIO_BOX    FL_ROUND_DOWN_BOX
# define GMSH_RADIO_COLOR  FL_BLACK
#endif

#endif

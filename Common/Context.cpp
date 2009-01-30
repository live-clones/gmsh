// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Context.h"
#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#endif

CTX::CTX()
{
  // These options have no default values in DefaultOptions.h (i.e.,
  // cannot be set by the user)
  batch = batch_after_mesh = 0;
  output_filename = "";
  bgm_filename = "";
  lc = 1.;
  min[0] = min[1] = min[2] = max[2] = 0.; 
  max[0] = max[1] = 1.; // for nice view when adding point in new model
  cg[0] = cg[1] = cg[2] = 0.;
  polygon_offset = 0;
  printing = 0;
  mesh_timer[0] = mesh_timer[1] = mesh_timer[2] = 0.;
  draw_rotation_center = 0;
  pick_elements = 0;
  geom.draw = 1;
  mesh.draw = 1;
  post.draw = 1;
  threads_lock = 0; // very primitive locking
  mesh.changed = 0;
  post.combine_time = 0; // try to combine_time views at startup
  post.plugin_draw_function = 0;
#if defined(HAVE_FLTK)
  gl_font_enum = FL_HELVETICA;
#else
  gl_font_enum = -1;
#endif
  forced_bbox = 0;
  hide_unselected = 0;
  num_windows = num_tiles = 1;
  deltafontsize = 0;
}

CTX *CTX::_instance = 0;

CTX *CTX::instance()
{
  if(!_instance) _instance = new CTX();
  return _instance;
}

unsigned int CTX::pack_color(int R, int G, int B, int A)
{
  if(big_endian)
    return ( (unsigned int)((R)<<24 | (G)<<16 | (B)<<8 | (A)) );
  else
    return ( (unsigned int)((A)<<24 | (B)<<16 | (G)<<8 | (R)) );
}

int CTX::unpack_red(unsigned int X)
{
  if(big_endian)
    return ( ( (X) >> 24 ) & 0xff );
  else
    return ( (X) & 0xff );
}

int CTX::unpack_green(unsigned int X)
{
  if(big_endian)
    return ( ( (X) >> 16 ) & 0xff );
  else
    return ( ( (X) >> 8 ) & 0xff );
}

int CTX::unpack_blue(unsigned int X)
{
  if(big_endian)
    return ( ( (X) >> 8 ) & 0xff );
  else
    return ( ( (X) >> 16 ) & 0xff );
}

int CTX::unpack_alpha(unsigned int X)
{
  if(big_endian)
    return ( (X) & 0xff );
  else
    return ( ( (X) >> 24 ) & 0xff );
}

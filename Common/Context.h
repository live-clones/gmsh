#ifndef _CONTEXT_H_
#define _CONTEXT_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "List.h"

// How RGBA values are packed and unpacked into/from a 4-byte
// integer. Don't use 'LITTLE_ENDIAN': Apple defines it in its system
// headers.

#if defined(HAVE_BIG_ENDIAN)
#  define PACK_COLOR(R,G,B,A)   ( (R)<<24 | (G)<<16 | (B)<<8 | (A) )
#  define UNPACK_RED(X)         ( ( (X) >> 24 ) & 0xff )
#  define UNPACK_GREEN(X)       ( ( (X) >> 16 ) & 0xff )
#  define UNPACK_BLUE(X)        ( ( (X) >> 8 ) & 0xff )
#  define UNPACK_ALPHA(X)       ( (X) & 0xff )
#else
#  define PACK_COLOR(R,G,B,A)   ( (A)<<24 | (B)<<16 | (G)<<8 | (R) )
#  define UNPACK_RED(X)         ( (X) & 0xff )
#  define UNPACK_GREEN(X)       ( ( (X) >> 8 ) & 0xff )
#  define UNPACK_BLUE(X)        ( ( (X) >> 16 ) & 0xff )
#  define UNPACK_ALPHA(X)       ( ( (X) >> 24 ) & 0xff )
#endif

// Interface-independent context 

class Context_T {

public :

  // general options
  char filename[256];         // the name of the currently opened file
  char base_filename[256];    // the same without the extension
  char *output_filename;      // output file specified with command line option '-o'
  char *default_filename;     // the name of the default file
  char *tmp_filename, tmprc_filename[256];
                              // the name of the temp file
  char *session_filename, sessionrc_filename[256];
                              // the name of the sessionrc configuration file
  char *options_filename, optionsrc_filename[256]; 
                              // the name of the optionrc configuration file
  char *error_filename, errorrc_filename[256];
                              // the name of the error file

  int session_save, options_save; // save session/option file on exit
  int confirm_overwrite;      // confirm overwrite when file->save as
  char *display;              // forced display host:0.0 under X11 
  int  terminal;              // show we print to the terminal console?
  char *editor;               // text editor command (with included '%s')
  char *web_browser;          // web browser command (with included '%s')
  char home_dir[256];         // the home directory
  char *scheme;               // FLTK GUI theme
  int  tooltips;              // show tootips in GUI?

  int position[2];            // position of the menu window on the screen
  int gl_position[2];         // position of the graphic window on the screen
  int msg_position[2];        // position of the message window on the screen
  int msg_size[2];            // size of the message window on the screen
  int opt_position[2];        // position of the option window on the screen
  int vis_position[2];        // position of the visibility window on the screen
  int stat_position[2];       // position of the statistics window on the screen
  int ctx_position[2];        // position of the geo/mesh context windows on the screen
  int solver_position[2];     // position of the solver windows on the screen
  int system_menu_bar;        // use the system menu bar on MacOS?

  int default_plugins;        // do we load default plugins on startup?

  int batch;                  // 0=full gfx; -1=just parse; 1,2,3=batch 1D, 2D, 3D mesh 
  int initial_context;        // 0=automatic; 1=geom; 2=mesh; 3=solver; 4=post 
  int verbosity;              // 0=silent -> 3=debug 

  float rot[4][4];            // current rotation matrix 
  double r[3];                // position angles (if succ. rot. along x, y and z) 
  double t[3], s[3];          // current translation and scale 
  int rlock[3], tlock[3], slock[3];
                              // locks for r, t and s 
  float quaternion[4];        // the actual quaternion used for "trackball" rotating 
  int useTrackball;           // do or do not use the trackball for rotations 
  double rotation_center[3];  // point around which to rotate the scene
  int rotation_center_cg;     // rotate around the center of gravity instead of rotation_center[]
  double min[3];              // x, y and z min for the current geometry 
  double max[3];              // x, y and z max for the current geometry 
  double cg[3];               // "center of gravity" of the current geometry
  double range[3];            // maximum range in the three directions 
  double lc, lc_middle;       // characteristic lengths for the whole problem, 
  double lc_order;            // and never used in mesh generation (->only for geo/post) 

  int db;                     // double buffer? 
  int overlay;                // overlay graphic window? 
  int ortho;                  // orthogonal projection? 
  int fast;                   // inhibit mesh and postpro drawing when changing r,s,t 
  int command_win;            // command window? 
  int axes, small_axes;       // draw axes? 
  int small_axes_pos[2];      // small axes position 
  int threads, threads_lock;  // threads?, lock (should be a mutex...) 
  int alpha;                  // enable alpha blending 
  double zoom_factor;         // mouse2 zoom coefficient

  int fontsize;               // font size for fltk UI
  int gl_fontsize;            // font size for opengl graphics
  double point_size, line_width; // point/line widths

  int viewport[4];            // current viewport 
  double vxmin, vxmax, vymin, vymax; // current viewport in real coordinates 
  int light[6];               // status of light 
  float light_position[6][4]; // light sources positions 
  int moving_light;           // type of light (follows the model or not)
  float shine;                // specular value 
  int render_mode;            // GMSH_RENDER, GMSH_SELECT, GMSH_FEEDBACK 
  int clip[6];                // status of clip planes 
  double clip_plane[6][4];    // clip planes 
  double pixel_equiv_x, pixel_equiv_y ; 
                              // approximative equivalent model length of a pixel 
  int color_scheme ;          // general color scheme
  int quadric_subdivisions;   // nb of subdivisions for gluQuadrics (spheres/cylinders)
  int visibility_mode ;       // VIS_GEOM, VIS_MESH, ...
  int vector_type;            // default vector display type (for normals, etc.)
  double arrow_rel_head_radius;  // relative radius of arrow head
  double arrow_rel_stem_radius;  // relative radius of arrow stem
  double arrow_rel_stem_length;  // relative length of arrow stem

  // geometry options 
  struct{
    int vis_type;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    double point_size, line_width, point_sel_size, line_sel_width;
    int point_type, line_type; // flat or 3D
    int light;
    int highlight;
    int level, old_circle, circle_points, circle_warning;
    int extrude_spline_points, old_newreg;
    double normals, tangents;
    double scaling_factor;
    int color_scheme ;
    int auto_coherence;
    int stl_create_elementary, stl_create_physical;
  } geom;

  // mesh options 
  struct {
    double msh_file_version;
    int vis_type, changed, display_lists;
    int draw;
    int points, lines, surfaces_edges, surfaces_faces, volumes_edges, volumes_faces;
    int points_num, lines_num, surfaces_num, volumes_num;
    int point_type, line_type; // flat or 3D
    double point_size, line_width;
    double quality;
    double gamma_inf, gamma_sup, radius_inf, radius_sup;
    double scaling_factor, lc_factor, rand_factor;
    int dual, interactive;
    int light;
    int format, nb_smoothing, algo, order;
    int point_insertion, speed_max, min_circ_points, constrained_bgmesh;
    int histogram, initial_only;
    double normals, tangents, explode;
    int color_scheme, color_carousel ;
    int use_cut_plane;
    double cut_planea,cut_planeb,cut_planec,cut_planed;
    double evalCutPlane (double x, double y, double z){
      double val = cut_planea * x + cut_planeb * y + cut_planec * z + cut_planed; 
      return val;
    }
    int oldxtrude, oldxtrude_recombine, check_duplicates;
    int allow_degenerated_extrude, save_all;
    char *triangle_options;
  } mesh;

  // post processing options 
  struct{
    List_T *list ;
    int force_num, compute_bb, display_lists;
    int draw, scales, link ;
    int smooth, anim_cycle, combine_time ;
    double anim_delay ;
  }post;

  // print options 
  struct{
    int format;
    int eps_quality, eps_background, eps_font_size, eps_compress, eps_ps3shading;
    int eps_occlusion_culling, eps_best_root;
    char *eps_font;
    double eps_line_width_factor, eps_point_size_factor;
    int jpeg_quality;
    int gif_dither, gif_sort, gif_interlace, gif_transparent;
    int gl_fonts;
  } print;

  // color options
  struct{
    unsigned int bg, fg, text, axes, small_axes;
    struct{
      unsigned int point, line, surface, volume;
      unsigned int point_sel, line_sel, surface_sel, volume_sel;
      unsigned int point_hlt, line_hlt, surface_hlt, volume_hlt;
      unsigned int tangents, normals;
    } geom;
    struct{
      unsigned int vertex, vertex_deg2, line, triangle, quadrangle;
      unsigned int tetrahedron, hexahedron, prism, pyramid;
      unsigned int carousel[10];
      unsigned int tangents, normals;
    } mesh;
  } color;
  
  // trackball functions 
  void buildRotmatrix(void);
  void setQuaternion (float p1x, float p1y, float p2x, float p2y);
  void addQuaternion (float p1x, float p1y, float p2x, float p2y);
};

#endif

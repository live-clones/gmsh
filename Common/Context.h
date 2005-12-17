#ifndef _CONTEXT_H_
#define _CONTEXT_H_

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

#include "List.h"

// How RGBA values are packed and unpacked into/from a 4-byte
// integer:

#if defined(__BIG_ENDIAN__)
#  define PACK_COLOR(R,G,B,A)   ( (unsigned int)((R)<<24 | (G)<<16 | (B)<<8 | (A)) )
#  define UNPACK_RED(X)         ( ( (X) >> 24 ) & 0xff )
#  define UNPACK_GREEN(X)       ( ( (X) >> 16 ) & 0xff )
#  define UNPACK_BLUE(X)        ( ( (X) >> 8 ) & 0xff )
#  define UNPACK_ALPHA(X)       ( (X) & 0xff )
#else
#  define PACK_COLOR(R,G,B,A)   ( (unsigned int)((A)<<24 | (B)<<16 | (G)<<8 | (R)) )
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
  char *bgm_filename;         // background mesh
  List_T *files;              // all the files on the command line
  char *output_filename;      // output file specified with command line option '-o'
  char *default_filename, default_filename_fullpath[256];
                              // the name of the default file
  char *tmp_filename, tmp_filename_fullpath[256];
                              // the name of the temp file
  char *session_filename, session_filename_fullpath[256];
                              // the name of the session configuration file
  char *options_filename, options_filename_fullpath[256]; 
                              // the name of the option configuration file
  char *error_filename, error_filename_fullpath[256];
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
  int clip_position[2];       // position of the clipping planes window on the screen
  int manip_position[2];      // position of the manipulator window on the screen
  int stat_position[2];       // position of the statistics window on the screen
  int ctx_position[2];        // position of the geo/mesh context windows on the screen
  int solver_position[2];     // position of the solver windows on the screen
  int file_chooser_position[2]; // position of the file chooser window on the screen
  int system_menu_bar;        // use the system menu bar on MacOS?

  int batch;                  // 0=full gfx; -1=just parse; 1,2,3=batch 1D, 2D, 3D mesh 
  int initial_context;        // 0=automatic; 1=geom; 2=mesh; 3=solver; 4=post 
  int verbosity;              // 0=silent -> 3=debug 
  int nopopup;                // never popup dialogs in scripts (use default values instead)

  double rot[16];             // current rotation matrix 
  double r[3];                // current Euler angles (in degrees!) 
  double t[3], s[3];          // current translation and scale 
  double clip_factor;         // clipping plane distance factor
  double quaternion[4];       // current quaternion used for "trackball" rotation
  int useTrackball;           // do or do not use the trackball for rotations 
  double rotation_center[3];  // point around which to rotate the scene
  int rotation_center_cg;     // rotate around the center of mass instead of rotation_center[]
  double min[3];              // x, y and z min for the current geometry 
  double max[3];              // x, y and z max for the current geometry 
  double cg[3];               // "center of mass" of the current geometry
  double range[3];            // maximum range in the three directions 
  double lc;                  // characteristic length for the whole problem (never
                              // used in mesh generation ->only for geo/post) 

  int db;                     // double buffer? 
  int ortho;                  // orthogonal projection? 
  int draw_bbox;              // always draw the bounding boxes?
  int fast_redraw;            // only draw the bbox when rotating/panning the model?
  int small_axes, small_axes_size, small_axes_pos[2]; // small axes
  int axes, axes_auto_position, axes_tics[3]; // large axes
  double axes_position[6];  
  char axes_label[3][256], axes_format[3][256];
  int threads, threads_lock;  // threads?, lock (should be a mutex...) 
  int alpha;                  // enable alpha blending 
  double zoom_factor;         // mouse2 zoom coefficient
  int bg_gradient;            // draw background gradient?

  int fontsize;               // font size for fltk UI
  char *gl_font;              // font for opengl graphics
  int gl_font_enum;           // font for opengl graphics (fltk enum value)
  int gl_fontsize;            // font size for opengl graphics
  double point_size, line_width; // point/line widths

  int viewport[4];            // current viewport 
  double vxmin, vxmax, vymin, vymax; // current viewport in real coordinates 
  int light[6];               // status of lights
  double light_position[6][4]; // light sources positions 
  double shine, shine_exponent; // material specular reflection parameters
  int render_mode;            // GMSH_RENDER, GMSH_SELECT, GMSH_FEEDBACK 
  int clip[6];                // status of clip planes (bit arrays)
  double clip_plane[6][4];    // clip planes 
  int polygon_offset, polygon_offset_always; // polygon offset control
  double polygon_offset_factor, polygon_offset_units; // params for glPolygonOffset
  double pixel_equiv_x, pixel_equiv_y ; 
                              // approximative equivalent model length of a pixel 
  int color_scheme ;          // general color scheme
  int quadric_subdivisions;   // nb of subdivisions for gluQuadrics (spheres/cylinders)
  int visibility_mode ;       // VIS_GEOM, VIS_MESH, ...
  int vector_type;            // default vector display type (for normals, etc.)
  double arrow_rel_head_radius;  // relative radius of arrow head
  double arrow_rel_stem_radius;  // relative radius of arrow stem
  double arrow_rel_stem_length;  // relative length of arrow stem

  double model[16], proj[16]; // the modelview and projection matrix as they were
                              // at the time of the last InitPosition() call
  double model_init[16]; // the modelview matrix before applying s, t and rot

  int forced_bbox; // dynamic variable tracking if the bbox is currently imposed

  // geometry options 
  struct{
    int vis_type;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    double point_size, line_width, point_sel_size, line_sel_width;
    int point_type, line_type; // flat or 3D
    int light;
    int level, old_circle, circle_points, circle_warning;
    int extrude_spline_points, old_newreg;
    double normals, tangents;
    double scaling_factor;
    int auto_coherence;
  } geom;

  // mesh options 
  struct {
    double msh_file_version;
    int vis_type, changed, vertex_arrays;
    int draw;
    int points, lines, surfaces_edges, surfaces_faces, volumes_edges, volumes_faces;
    int points_num, lines_num, surfaces_num, volumes_num;
    double label_frequency;
    int point_type, line_type; // flat or 3D
    double point_size, line_width;
    int points_per_element;
    int optimize;
    double quality;
    int quality_type, label_type;
    double quality_inf, quality_sup, radius_inf, radius_sup;
    double scaling_factor, lc_factor, rand_factor;
    int dual, interactive;
    int light, light_two_side, light_lines;
    int format, nbPartitions,nb_smoothing, algo2d, algo3d, order,algo_recombine;
    int point_insertion, speed_max, min_circ_points, constrained_bgmesh;
    int histogram, initial_only;
    double normals, tangents, explode;
    int color_carousel ;
    int use_cut_plane, cut_plane_as_surface, cut_plane_only_volume;
    double cut_planea,cut_planeb,cut_planec,cut_planed;
    double evalCutPlane (double x, double y, double z){
      double val = cut_planea * x + cut_planeb * y + cut_planec * z + cut_planed; 
      return val;
    }
    int oldxtrude, oldxtrude_recombine, check_duplicates;
    int allow_degenerated_extrude, save_all;
    char *triangle_options;
    int smooth_normals;
    double angle_smooth_normals;
    double stl_distance_tol, dihedral_angle_tol;
    int edge_prolongation_threshold, do_not_coarsen;
    double  nb_elem_per_rc ,   min_elem_size_fact , target_elem_size_fact, beta_smooth_metric;
  } mesh;

  // post processing options 
  struct{
    List_T *list ;
    int force_num, compute_bb, vertex_arrays;
    int draw, link, horizontal_scales ;
    int smooth, anim_cycle, combine_time, combine_remove_orig ;
    int file_format, plugins;
    double anim_delay ;
    void (*plugin_draw_function)(void) ;
  }post;

  // solver options 
  struct{
    int max_delay, plugins, listen ;
    char *socket_name ;
  }solver;

  // print options 
  struct{
    int format;
    int eps_quality, eps_background, eps_compress, eps_ps3shading;
    int eps_occlusion_culling, eps_best_root;
    double eps_line_width_factor, eps_point_size_factor;
    int jpeg_quality, jpeg_smoothing;
    int gif_dither, gif_sort, gif_interlace, gif_transparent;
    int gl_fonts;
  } print;

  // color options
  struct{
    unsigned int bg, bg_grad, fg, text, axes, small_axes;
    unsigned int ambient_light[6], diffuse_light[6], specular_light[6];
    struct{
      unsigned int point, line, surface, volume;
      unsigned int point_sel, line_sel, surface_sel, volume_sel;
      unsigned int point_hlt, line_hlt, surface_hlt, volume_hlt;
      unsigned int tangents, normals;
    } geom;
    struct{
      unsigned int vertex, vertex_deg2, line, triangle, quadrangle;
      unsigned int tetrahedron, hexahedron, prism, pyramid;
      unsigned int carousel[20];
      unsigned int tangents, normals;
    } mesh;
  } color;
  
  // trackball functions 
  void buildRotationMatrix(void);
  void setQuaternion(double p1x, double p1y, double p2x, double p2y);
  void addQuaternion(double p1x, double p1y, double p2x, double p2y);
  void addQuaternionFromAxisAndAngle(double axis[3], double angle);
  void setQuaternionFromEulerAngles(void);
  void setEulerAnglesFromRotationMatrix(void);
};

#endif

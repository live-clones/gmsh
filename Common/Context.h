#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "Const.h"

// How RGBA values are packed and unpacked into/from a 4-byte integer 

#  ifdef _LITTLE_ENDIAN
#    define PACK_COLOR(R,G,B,A)   ( (A)<<24 | (B)<<16 | (G)<<8 | (R) )
#    define UNPACK_RED(X)         ( (X) & 0xff )
#    define UNPACK_GREEN(X)       ( ( (X) >> 8 ) & 0xff )
#    define UNPACK_BLUE(X)        ( ( (X) >> 16 ) & 0xff )
#    define UNPACK_ALPHA(X)       ( ( (X) >> 24 ) & 0xff )
#  else
#    define PACK_COLOR(R,G,B,A)   ( (R)<<24 | (G)<<16 | (B)<<8 | (A) )
#    define UNPACK_RED(X)         ( ( (X) >> 24 ) & 0xff )
#    define UNPACK_GREEN(X)       ( ( (X) >> 16 ) & 0xff )
#    define UNPACK_BLUE(X)        ( ( (X) >> 8 ) & 0xff )
#    define UNPACK_ALPHA(X)       ( (X) & 0xff )
#  endif

// Interface-independant context 

class Context_T {

public :

  // general options
  char filename[NAME_STR_L];  // the name of the currently opened file
  char basefilename[NAME_STR_L]; // the same without the extension
  char *configfilename;       // the name of the configuration file
  char *display;              // forced display host:0.0 under X11 
  int  terminal;              // show we print to the terminal console?

  int position[2];            // position of the menu window on the screen
  int gl_position[2];         // position of the graphic window on the screen
  int center_windows;         // center popup windows on the menu window

  int interactive;            // 0=full gfx; -1=just parse; 1,2,3=batch mesh 
  int verbosity;              // 0=silent -> 3=debug 
  int expose;                 // 1 if everything is ready to expose and draw 

  float rot[4][4];            // current rotation matrix 
  double r[3];                // position angles (if succ. rot. along x, y and z) 
  double t[3], s[3];          // current translation and scale 
  int rlock[3], tlock[3], slock[3];
                              // locks for r, t and s 
  float quaternion[4];        // the actual quaternion used for "trackball" rotating 
  int useTrackball;           // do or do not use the trackball for rotations 

  double min[3];              // x, y and z min for the current geometry 
  double max[3];              // x, y and z max for the current geometry 
  double range[3];            // maximum range in the three directions 
  double lc, lc_middle;       // characteristic lengths for the whole problem, 
  double lc_order;            // and never used in mesh generation (->only for geo/post) 

  int db;                     // double buffer? 
  int overlay;                // overlay graphic window? 
  int stream;                 // output stream: TO_SCREEN or TO_FILE 
  int ortho;                  // orthogonal projection? 
  int fast;                   // inhibit mesh and postpro drawing when changing r,s,t 
  int command_win;            // command window? 
  int display_lists;          // use display lists? 
  int axes, small_axes;       // draw axes? 
  int threads, threads_lock;  // threads?, lock (should be a mutex...) 
  int alpha;                  // enable alpha blending 
  int flash;                  // authorize colormap flashing (beek) 
  int same_visual;            // force same visual for GUI and Graphics 
  double zoom_factor;         // mouse2 zoom coefficient

  //only used for Motif
  int font_base;              // display list index for the font 
  char *font;                 // main font
  char *fixed_font;           // font for colorbar 
  //end(only used for Motif)

  int fontsize;               // font size for fltk UI
  int gl_fontsize;            // font size for opengl graphics
  int gl_fontheight;          // font height
  int gl_fontascent;          // height of the font above the reference point

  int viewport[4];            // current viewport 
  double vxmin, vxmax, vymin, vymax; // current viewport in real coordinates 
  int light[6];               // status of light 
  float light_position[6][4]; // light sources positions 
  float shine;                // specular value 
  int render_mode;            // GMSH_RENDER, GMSH_SELECT, GMSH_FEEDBACK 
  int clip[6];                // status of clip planes 
  double clip_plane[6][4];    // clip planes 
  double pixel_equiv_x, pixel_equiv_y ; 
                              // approximative equivalent model length of a pixel 
  int color_scheme ;

  // geometry options 
  struct{
    int vis_type;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    int hidden, shade;
    int highlight;
    int level, old_circle;
    double normals, tangents;
    double scaling_factor;
  } geom;

  // mesh options 
  struct {
    int vis_type;
    int draw;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    double quality;
    double limit_gamma, limit_eta, limit_rho;
    double scaling_factor, lc_factor, rand_factor;
    int dual, interactive;
    int hidden, shade;
    int format, nb_smoothing, algo, degree;
    int point_insertion, speed_max, min_circ_points;
    double normals, tangents, explode;
    int use_cut_plane;
    double cut_planea,cut_planeb,cut_planec,cut_planed;
    double evalCutPlane (double x, double y, double z)
    {
      double val = cut_planea * x + 
	cut_planeb * y + 
	cut_planec * z + cut_planed; 
      return val;
    }
  } mesh;

  // post processing options 
  struct{
    int draw, scales, link ;
    int smooth ;
    int  initial_visibility, initial_nbiso, initial_intervals, nb_views ;
    double anim_delay ;
  }post;

  // print options 
  struct{
    int format;
    int eps_quality;
    int jpeg_quality;
    int gif_dither, gif_sort, gif_interlace, gif_transparent;
    char *font;
    int  font_size, gl_fonts;
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
      unsigned int vertex, vertex_supp, line, triangle, quadrangle;
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

void Init_Context (int num);
void Init_Colors (int num);
void UpdateGUI_Context (int num);
void Print_Context(int num, char *filename);
void Print_Configuration(int num, char *filename);

#endif

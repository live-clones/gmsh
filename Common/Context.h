/* $Id: Context.h,v 1.23 2000-12-21 12:30:36 geuzaine Exp $ */
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

/* 
   Interface-independant context
 */

#define GMSH_INT     1
#define GMSH_LONG    2
#define GMSH_FLOAT   3
#define GMSH_DOUBLE  4

/* How RGBA values are packed and unpacked into/from a 4-byte integer */

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

typedef struct{
  int id;                       /* the current rgbacolors id */
  
  /* general colors */
  unsigned int bg, fg, text, axes, small_axes;
  
  /* geometry colors */
  struct{
    unsigned int point, line, surface, volume;
    unsigned int point_sel, line_sel, surface_sel, volume_sel;
    unsigned int point_hlt, line_hlt, surface_hlt, volume_hlt;
    unsigned int tangents, normals;
  }
  geom;
  
  /* mesh colors */
  struct{
    unsigned int vertex, vertex_supp, line, triangle, quadrangle;
    unsigned int tetrahedron, hexahedron, prism, pyramid;
    unsigned int carousel[10];
    unsigned int tangents, normals;
  }
  mesh;
  
}rgbacolors;

class Context_T {
  public :
  int interactive;            /* 0=full gfx; -1=just parse; 1,2,3=batch mesh */
  int verbosity;              /* 0=silent -> 3=debug */
  int expose;                 /* 1 if everything is ready to expose and draw */

  float rot[4][4];            /* current rotation matrix */
  double r[3];                /* position angles (if succ. rot. along x, y and z) */
  double t[3], s[3];          /* current translation and scale */
  int rlock[3], tlock[3], slock[3];
                              /* locks for r, t and s */
  float quaternion[4];        /* the actual quaternion used for "trackball" rotating */
  int useTrackball;           /* do or do not use the trackball for rotations */

  double min[3];              /* x, y and z min for the current geometry */
  double max[3];              /* x, y and z max for the current geometry */
  double range[3];            /* maximum range in the three directions */
  double lc, lc_middle;       /* characteristic lengths for the whole problem, */
  double lc_order;            /* and never used in mesh generation (->only for geo/post) */

  int db;                     /* double buffer? */
  int overlay;                /* overlay graphic window? */
  int stream;                 /* output stream: TO_SCREEN or TO_FILE */
  int ortho;                  /* orthogonal projection? */
  int fast;                   /* inhibit mesh and postpro drawing when changing r,s,t */
  int command_win;            /* command window? */
  int display_lists;          /* use display lists? */
  int font_base;              /* display list indice for the font */
  int axes, small_axes;       /* draw axes? */
  int threads, threads_lock;  /* threads?, lock (should be a mutex...) */
  int alpha;                  /* enable alpha blending */
  int flash;                  /* authorize colormap flashing (beek) */
  int same_visual;            /* force same visual for GUI and Graphics */
  
  char *font;                 /* main font */
  char *fixed_font;           /* font for colorbar */

  /* OpenGL stuff */
  int viewport[4];            /* current viewport */
  double vxmin, vxmax, vymin, vymax;
                              /* current viewport in real coordinates */
  int light[6];               /* status of light */
  float light_position[6][4]; /* light sources positions */
  float shine;                /* specular value */
  int render_mode;            /* GMSH_RENDER, GMSH_SELECT, GMSH_FEEDBACK */
  int clip[6];                /* status of clip planes */
  double clip_plane[6][4];    /* clip planes */
  double pixel_equiv_x, pixel_equiv_y ; 
                              /* approximative equivalent model length of a pixel */
  
  rgbacolors color;           /* all colors except postpro colormaps */
  
  /* geometry options */
  struct{
    int vis_type;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    int hidden, shade;
    int highlight;
    int level;
    double normals, tangents;
    double scaling_factor;
  } geom;

  /* mesh options */
  struct {
    int vis_type;
    int draw;
    int points, lines, surfaces, volumes;
    int points_num, lines_num, surfaces_num, volumes_num;
    double limit_gamma, limit_eta, limit_rho;
    double scaling_factor, lc_factor, rand_factor;
    int dual, interactive;
    int hidden, shade;
    int format, nb_smoothing, algo, degree;
    int point_insertion, speed_max, min_circ_points;
    double normals, tangents, explode;
  } mesh;

  /* post processing options */
  struct{
    int draw, scales, link ;
    int  initial_visibility, initial_nbiso, initial_intervals ;
    long anim_delay, nb_views ;
  }post;

  /* print options */
  struct{
    int format;
    int eps_quality, jpeg_quality;
    char *font;
    int  font_size, gl_fonts;
  } print;

  // trackball functions 
  void buildRotmatrix(void);
  void setQuaternion (float p1x, float p1y, float p2x, float p2y);
  void addQuaternion (float p1x, float p1y, float p2x, float p2y);
};

typedef struct {
  char *str ; 
  int int1, int2, int3, int4 ;
} StringX4Int;

typedef struct {
  char *str, **ptr, *def ;
} StringXString ;

typedef struct {
  char *str;
  int type;
  void *ptr;
  double def ;
} StringXNumber ;

typedef struct {
  char *str ; 
  unsigned int *ptr ;
  unsigned int def1, def2, def3 ;
} StringXColor ;

StringXString * Get_StringOptionCategory(char * cat);
StringXNumber * Get_NumberOptionCategory(char * cat);
StringXColor * Get_ColorOptionCategory(char * cat);

void Set_DefaultStringOptions(StringXString s[]);
void Set_DefaultNumberOptions(StringXNumber s[]);
void Set_DefaultColorOptions(StringXColor s[], int num);

char ** Get_StringOption(char *str, StringXString s[]);
void * Get_NumberOption(char *str, StringXNumber s[], int *type);
unsigned int * Get_ColorOption(char *str, StringXColor s[]);

void Print_StringOptions(StringXString s[], char *prefix, FILE *file);
void Print_NumberOptions(StringXNumber s[], char *prefix, FILE *file);
void Print_ColorOptions(StringXColor s[], char *prefix, FILE *file);

void Init_Colors (int num);
void Init_Context (void);
void Print_Context(char *filename);

#endif

#ifndef _GMSH_DEFINES_H_
#define _GMSH_DEFINES_H_

// IO file formats
#define FORMAT_MSH           1
#define FORMAT_UNV           2
#define FORMAT_GREF          3
#define FORMAT_XPM           4
#define FORMAT_PS            5
#define FORMAT_BMP           6
#define FORMAT_GIF           7
#define FORMAT_GEO           8
#define FORMAT_JPEG          9
#define FORMAT_AUTO          10
#define FORMAT_PPM           11
#define FORMAT_YUV           12
#define FORMAT_DMG           13
#define FORMAT_SMS           14
#define FORMAT_OPT           15
#define FORMAT_VTK           16
#define FORMAT_TEX           18
#define FORMAT_VRML          19
#define FORMAT_EPS           20
#define FORMAT_PNG           22
#define FORMAT_PDF           24
#define FORMAT_POS           26
#define FORMAT_STL           27
#define FORMAT_P3D           28
#define FORMAT_SVG           29
#define FORMAT_MESH          30
#define FORMAT_BDF           31

// Element types in .msh file format
#define LIN_2  1
#define TRI_3  2
#define QUA_4  3
#define TET_4  4
#define HEX_8  5
#define PRI_6  6
#define PYR_5  7
#define LIN_3  8
#define TRI_6  9
#define QUA_9  10
#define TET_10 11
#define HEX_27 12
#define PRI_18 13
#define PYR_14 14
#define PNT_1  15
#define QUA_8  16
#define HEX_20 17
#define PRI_15 18
#define PYR_13 19

// Geometric entities
#define ENT_NONE     0
#define ENT_POINT    (1<<0)
#define ENT_LINE     (1<<1)
#define ENT_SURFACE  (1<<2)
#define ENT_VOLUME   (1<<3)
#define ENT_ALL      (ENT_POINT | ENT_LINE | ENT_SURFACE | ENT_VOLUME)

#define ELEMENTARY 1
#define PHYSICAL   2
#define PARTITION  3

// Mesh algorithms
#define QUALITY_EDGES_BASED 1
#define QUALITY_SIMPLEX_BASED 2
#define DELAUNAY_ISO 1
#define DELAUNAY_ANISO 2
#define DELAUNAY_TRIANGLE 3
#define FRONTAL_NETGEN 4
#define DELAUNAY_TETGEN 5

#define CONV_VALUE    0.8

#define NOTTOLINK 1
#define TOLINK    2

#define BOF         1
#define A_TOUT_PRIX 2

#define CENTER_CIRCCIRC 1
#define BARYCENTER      2

#define EXTERN      1
#define INTERN      2

#define ONFILE      2
#define WITHPOINTS  3

#define TRANSFINI 1
#define LIBRE     2
#define ELLIPTIC  3

#endif

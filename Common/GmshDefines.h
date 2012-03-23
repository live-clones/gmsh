// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_DEFINES_H_
#define _GMSH_DEFINES_H_

// IO file formats (numbers should not be changed)
#define FORMAT_MSH   1
#define FORMAT_UNV   2
#define FORMAT_GREF  3
#define FORMAT_XPM   4
#define FORMAT_PS    5
#define FORMAT_BMP   6
#define FORMAT_GIF   7
#define FORMAT_GEO   8
#define FORMAT_JPEG  9
#define FORMAT_AUTO  10
#define FORMAT_PPM   11
#define FORMAT_YUV   12
#define FORMAT_DMG   13
#define FORMAT_SMS   14
#define FORMAT_OPT   15
#define FORMAT_VTK   16
#define FORMAT_MPEG  17
#define FORMAT_TEX   18
#define FORMAT_VRML  19
#define FORMAT_EPS   20
#define FORMAT_MAIL  21
#define FORMAT_PNG   22
#define FORMAT_TXT   23
#define FORMAT_PDF   24
#define FORMAT_RMED  25
#define FORMAT_POS   26
#define FORMAT_STL   27
#define FORMAT_P3D   28
#define FORMAT_SVG   29
#define FORMAT_MESH  30
#define FORMAT_BDF   31
#define FORMAT_CGNS  32
#define FORMAT_MED   33
#define FORMAT_DIFF  34
#define FORMAT_BREP  35
#define FORMAT_STEP  36
#define FORMAT_IGES  37
#define FORMAT_IR3   38
#define FORMAT_INP   39
#define FORMAT_PLY2  40

// Element types
#define TYPE_PNT     1
#define TYPE_LIN     2
#define TYPE_TRI     3
#define TYPE_QUA     4
#define TYPE_TET     5
#define TYPE_PYR     6
#define TYPE_PRI     7
#define TYPE_HEX     8
#define TYPE_POLYG   9
#define TYPE_POLYH   10

// Element types in .msh file format (numbers should not be changed)
#define MSH_LIN_2    1
#define MSH_TRI_3    2
#define MSH_QUA_4    3
#define MSH_TET_4    4
#define MSH_HEX_8    5
#define MSH_PRI_6    6
#define MSH_PYR_5    7
#define MSH_LIN_3    8
#define MSH_TRI_6    9
#define MSH_QUA_9    10
#define MSH_TET_10   11
#define MSH_HEX_27   12
#define MSH_PRI_18   13
#define MSH_PYR_14   14
#define MSH_PNT      15
#define MSH_QUA_8    16
#define MSH_HEX_20   17
#define MSH_PRI_15   18
#define MSH_PYR_13   19
#define MSH_TRI_9    20
#define MSH_TRI_10   21
#define MSH_TRI_12   22
#define MSH_TRI_15   23
#define MSH_TRI_15I  24
#define MSH_TRI_21   25
#define MSH_LIN_4    26
#define MSH_LIN_5    27
#define MSH_LIN_6    28
#define MSH_TET_20   29
#define MSH_TET_35   30
#define MSH_TET_56   31
#define MSH_TET_34   32
#define MSH_TET_52   33
#define MSH_POLYG_   34
#define MSH_POLYH_   35
#define MSH_QUA_16   36
#define MSH_QUA_25   37
#define MSH_QUA_36   38
#define MSH_QUA_12   39
#define MSH_QUA_16I  40
#define MSH_QUA_20   41
#define MSH_TRI_28   42
#define MSH_TRI_36   43
#define MSH_TRI_45   44
#define MSH_TRI_55   45
#define MSH_TRI_66   46
#define MSH_QUA_49   47
#define MSH_QUA_64   48
#define MSH_QUA_81   49
#define MSH_QUA_100  50
#define MSH_QUA_121  51
#define MSH_TRI_18   52
#define MSH_TRI_21I  53
#define MSH_TRI_24   54
#define MSH_TRI_27   55
#define MSH_TRI_30   56
#define MSH_QUA_24   57
#define MSH_QUA_28   58
#define MSH_QUA_32   59
#define MSH_QUA_36I  60
#define MSH_QUA_40   61
#define MSH_LIN_7    62
#define MSH_LIN_8    63
#define MSH_LIN_9    64
#define MSH_LIN_10   65
#define MSH_LIN_11   66
#define MSH_LIN_B    67
#define MSH_TRI_B    68
#define MSH_POLYG_B  69
#define MSH_LIN_C    70
#define MSH_TET_84   71
#define MSH_TET_120  72
#define MSH_TET_165  73
#define MSH_TET_220  74
#define MSH_TET_286  75
#define MSH_TET_74   79
#define MSH_TET_100  80
#define MSH_TET_130  81
#define MSH_TET_164  82
#define MSH_TET_202  83
#define MSH_LIN_1    84
#define MSH_TRI_1    85
#define MSH_QUA_1    86
#define MSH_TET_1    87
#define MSH_HEX_1    88
#define MSH_PRI_1    89
#define MSH_PRI_40   90
#define MSH_PRI_75   91
// HEXES COMPLETE (3->9)
#define MSH_HEX_64   92
#define MSH_HEX_125  93
#define MSH_HEX_216  94
#define MSH_HEX_343  95
#define MSH_HEX_512  96
#define MSH_HEX_729  97
#define MSH_HEX_1000 98
// HEXES INCOMPLETE (3->9)
#define MSH_HEX_56   99
#define MSH_HEX_98  100
#define MSH_HEX_152 101
#define MSH_HEX_222 102
#define MSH_HEX_296 103
#define MSH_HEX_386 104
#define MSH_HEX_488 105
// PRISMS COMPLETE (5->9)
#define MSH_PRI_126 106
#define MSH_PRI_196 107
#define MSH_PRI_288 108
#define MSH_PRI_405 109
#define MSH_PRI_550 110
// PRISMS INCOMPLETE (3->9)
#define MSH_PRI_38  111
#define MSH_PRI_66  112
#define MSH_PRI_102 113
#define MSH_PRI_146 114
#define MSH_PRI_198 115
#define MSH_PRI_258 116
#define MSH_PRI_326 117
// PYRAMIDS COMPLETE (3->9)
#define MSH_PYR_30  118
#define MSH_PYR_55  119
#define MSH_PYR_91  120
#define MSH_PYR_140 121
#define MSH_PYR_204 122
#define MSH_PYR_285 123
#define MSH_PYR_385 124
// PYRAMIDS INCOMPLETE (3->9)
#define MSH_PYR_29  125
#define MSH_PYR_50  126
#define MSH_PYR_77  127
#define MSH_PYR_110 128
#define MSH_PYR_149 129
#define MSH_PYR_194 130
#define MSH_PYR_245 131
// Additional types
#define MSH_PYR_1   132

#define MSH_NUM_TYPE 132

// Geometric entities
#define ENT_NONE     0
#define ENT_POINT    (1<<0)
#define ENT_LINE     (1<<1)
#define ENT_SURFACE  (1<<2)
#define ENT_VOLUME   (1<<3)
#define ENT_ALL      (ENT_POINT | ENT_LINE | ENT_SURFACE | ENT_VOLUME)

// 2D meshing algorithms (numbers should not be changed)
#define ALGO_2D_MESHADAPT      1
#define ALGO_2D_AUTO           2
#define ALGO_2D_MESHADAPT_OLD  4
#define ALGO_2D_DELAUNAY       5
#define ALGO_2D_FRONTAL        6
#define ALGO_2D_BAMG           7
#define ALGO_2D_FRONTAL_QUAD   8

// 3D meshing algorithms (numbers should not be changed)
#define ALGO_3D_DELAUNAY       1
#define ALGO_3D_FRONTAL        4
#define ALGO_3D_FRONTAL_DEL    5
#define ALGO_3D_FRONTAL_HEX    6
#define ALGO_3D_MMG3D          7
#define ALGO_3D_RTREE          9

// Meshing methods
#define MESH_NONE         0
#define MESH_TRANSFINITE  1
#define MESH_UNSTRUCTURED 2

// QuadTri options (structured/unstructured coupling with pyramids)
#define NO_QUADTRI               0
#define QUADTRI_DBL_1            1
#define QUADTRI_DBL_1_RECOMB     2
#define QUADTRI_SNGL_1           3
#define QUADTRI_SNGL_1_RECOMB    4
#define TRANSFINITE_QUADTRI_1    5

#endif

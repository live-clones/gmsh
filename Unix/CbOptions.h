/* $Id: CbOptions.h,v 1.3 2000-11-23 14:11:41 geuzaine Exp $ */
#ifndef _CB_OPTIONS_H_
#define _CB_OPTIONS_H_

/* options globales */
					     
#define  OPTIONS_REPLOT                         1
#define  OPTIONS_AXES                           2
#define  OPTIONS_LITTLE_AXES                    3
#define  OPTIONS_XVIEW                          4
#define  OPTIONS_YVIEW                          5
#define  OPTIONS_ZVIEW                          6
#define  OPTIONS_CVIEW                          7
#define  OPTIONS_PVIEW                          8
#define  OPTIONS_SCALEX                         9
#define  OPTIONS_SCALEY                         10
#define  OPTIONS_SCALEZ                         11
#define  OPTIONS_ROTX                           12
#define  OPTIONS_ROTY                           13
#define  OPTIONS_ROTZ                           14
#define  OPTIONS_TRANX                          15
#define  OPTIONS_TRANY                          16
#define  OPTIONS_TRANZ                          17
#define  OPTIONS_ROTX_LOCKED                    18
#define  OPTIONS_ROTY_LOCKED                    19
#define  OPTIONS_ROTZ_LOCKED                    20
#define  OPTIONS_TRANX_LOCKED                   21
#define  OPTIONS_TRANY_LOCKED                   22
#define  OPTIONS_TRANZ_LOCKED                   23
#define  OPTIONS_SCALEX_LOCKED                  24
#define  OPTIONS_SCALEY_LOCKED                  25
#define  OPTIONS_SCALEZ_LOCKED                  26
#define  OPTIONS_ORTHOGRAPHIC                   27
#define  OPTIONS_PERSPECTIVE                    28
#define  OPTIONS_LIGHT_X_SCALE                  29
#define  OPTIONS_LIGHT_Y_SCALE                  30
#define  OPTIONS_LIGHT_Z_SCALE                  31
#define  OPTIONS_SHINE_SCALE                    32
#define  OPTIONS_ALPHA_BLENDING                 33
#define  OPTIONS_DISPLAY_LISTS                  34
#define  OPTIONS_FAST_REDRAW                    35
#define  OPTIONS_COLOR_SCHEME_SCALE             36

/* options geometrie */

#define  OPTIONS_GEOM_CHECK                     100
#define  OPTIONS_GEOM_POINTS                    101
#define  OPTIONS_GEOM_LINES                     102
#define  OPTIONS_GEOM_SURFACES                  103
#define  OPTIONS_GEOM_VOLUMES                   104
#define  OPTIONS_GEOM_NORMALS_SCALE             105
#define  OPTIONS_GEOM_NORMALS_TEXT              106
#define  OPTIONS_GEOM_TANGENTS_SCALE            107
#define  OPTIONS_GEOM_TANGENTS_TEXT             108
#define  OPTIONS_GEOM_HIDE_SHOW                 109
#define  OPTIONS_GEOM_VISIBILITY_ENTITY         110
#define  OPTIONS_GEOM_VISIBILITY_NUMBER         111

/* options mesh */

#define  OPTIONS_MESH_POINTS                    200
#define  OPTIONS_MESH_LINES                     201
#define  OPTIONS_MESH_SURFACES                  202
#define  OPTIONS_MESH_VOLUMES                   203
#define  OPTIONS_MESH_HIDDEN_LINES              204
#define  OPTIONS_MESH_SHADING                   205
#define  OPTIONS_MESH_WIREFRAME                 206
#define  OPTIONS_MESH_NORMALS_SCALE             207
#define  OPTIONS_MESH_NORMALS_TEXT              208
#define  OPTIONS_MESH_TANGENTS_SCALE            209
#define  OPTIONS_MESH_TANGENTS_TEXT             210
#define  OPTIONS_MESH_EXPLODE_SCALE             211
#define  OPTIONS_MESH_EXPLODE_TEXT              212
#define  OPTIONS_MESH_FORMAT_MSH                213
#define  OPTIONS_MESH_FORMAT_UNV                214
#define  OPTIONS_MESH_FORMAT_GREF               215
#define  OPTIONS_MESH_HIDE_SHOW                 216
#define  OPTIONS_MESH_ABORT                     217
#define  OPTIONS_MESH_SMOOTHING_SCALE           218
#define  OPTIONS_MESH_SMOOTHING_TEXT            219
#define  OPTIONS_MESH_DEGRE2                    220
#define  OPTIONS_MESH_ANISOTROPIC               221
#define  OPTIONS_MESH_INTERACTIVE               222
#define  OPTIONS_MESH_VISIBILITY_ENTITY         223
#define  OPTIONS_MESH_VISIBILITY_NUMBER         224

/* options post */

#define  OPTIONS_POST_LINK_NONE                 300
#define  OPTIONS_POST_LINK_VISIBLE              301
#define  OPTIONS_POST_LINK_ALL                  302
#define  OPTIONS_POST_ANIM_START                303
#define  OPTIONS_POST_ANIM_STOP                 304
#define  OPTIONS_POST_ANIM_DELAY                305

/* options print */

#define  OPTIONS_PRINT_XDUMP                    400
#define  OPTIONS_PRINT_GLPPAINTER               401
#define  OPTIONS_PRINT_GLPRECURSIVE             402
#define  OPTIONS_PRINT_GLPIMAGE                 403
#define  OPTIONS_PRINT_GL2PS_SIMPLE             404
#define  OPTIONS_PRINT_GL2PS_COMPLEX            405
#define  OPTIONS_PRINT_GL2PS_IMAGE              406
#define  OPTIONS_PRINT_GIF                      407
					     
#endif

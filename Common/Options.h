#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

extern Context_T   CTX ;

// Option Database, with default values

// STRINGS

StringXString GeneralOptions_String[] = {
  { "Display" , &CTX.display , "" },
  { NULL , NULL , NULL }
} ;

StringXString GeometryOptions_String[] = {
  { NULL , NULL ,  NULL }
} ;

StringXString MeshOptions_String[] = {
  { NULL , NULL ,  NULL }
} ;

StringXString PostProcessingOptions_String[] = {
  { NULL , NULL ,  NULL }
} ;

StringXString PrintOptions_String[] = {
  { "Font" ,  &CTX.print.font , "Courier" },
  { NULL , NULL , NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { "Viewport0"            , GMSH_INT,    (void*)&CTX.viewport[0]    , 0. }, 
  { "Viewport1"            , GMSH_INT,    (void*)&CTX.viewport[1]    , 0. }, 
  { "Viewport2"            , GMSH_INT,    (void*)&CTX.viewport[2]    , 700. }, 
  { "Viewport3"            , GMSH_INT,    (void*)&CTX.viewport[3]    , 500. }, 
  { "GraphicsPosition0"    , GMSH_INT,    (void*)&CTX.gl_position[0] , 20. }, 
  { "GraphicsPosition1"    , GMSH_INT,    (void*)&CTX.gl_position[1] , 30. }, 
  { "GraphicsFontSize"     , GMSH_INT,    (void*)&CTX.gl_fontsize    , 11. }, 
  { "MenuPosition0"        , GMSH_INT,    (void*)&CTX.position[0]    , 800. }, 
  { "MenuPosition1"        , GMSH_INT,    (void*)&CTX.position[1]    , 50. }, 
  { "MenuFontSize"         , GMSH_INT,    (void*)&CTX.fontsize       , 12. }, 
  { "CenterWindows"        , GMSH_INT,    (void*)&CTX.center_windows , 1. }, 
  { "Rotation0"            , GMSH_DOUBLE, (void*)&CTX.r[0]           , 0.0 }, 
  { "Rotation1"            , GMSH_DOUBLE, (void*)&CTX.r[1]           , 0.0 }, 
  { "Rotation2"            , GMSH_DOUBLE, (void*)&CTX.r[2]           , 0.0 }, 
  { "TrackballQuaternion0" , GMSH_FLOAT,  (void*)&CTX.quaternion[0]  , 0.0 }, 
  { "TrackballQuaternion1" , GMSH_FLOAT,  (void*)&CTX.quaternion[1]  , 0.0 }, 
  { "TrackballQuaternion2" , GMSH_FLOAT,  (void*)&CTX.quaternion[2]  , 0.0 }, 
  { "TrackballQuaternion3" , GMSH_FLOAT,  (void*)&CTX.quaternion[3]  , 1.0 }, 
  { "Translation0"         , GMSH_DOUBLE, (void*)&CTX.t[0]           , 0.0 }, 
  { "Translation1"         , GMSH_DOUBLE, (void*)&CTX.t[1]           , 0.0 }, 
  { "Translation2"         , GMSH_DOUBLE, (void*)&CTX.t[2]           , 0.0 }, 
  { "Scale0"               , GMSH_DOUBLE, (void*)&CTX.s[0]           , 1.0 }, 
  { "Scale1"               , GMSH_DOUBLE, (void*)&CTX.s[1]           , 1.0 }, 
  { "Scale2"               , GMSH_DOUBLE, (void*)&CTX.s[2]           , 1.0 }, 
  { "Shininess"            , GMSH_FLOAT,  (void*)&CTX.shine          , 0.4 }, 
  { "Verbosity"            , GMSH_INT,    (void*)&CTX.verbosity      , 2. },
  { "Orthographic"         , GMSH_INT,    (void*)&CTX.ortho          , 1. }, 
  { "FastRedraw"           , GMSH_INT,    (void*)&CTX.fast           , 1. },
  { "Axes"                 , GMSH_INT,    (void*)&CTX.axes           , 1. },
  { "SmallAxes"            , GMSH_INT,    (void*)&CTX.small_axes     , 1. },
  { "DisplayLists"         , GMSH_INT,    (void*)&CTX.display_lists  , 0. },
  { "SameVisual"           , GMSH_INT,    (void*)&CTX.same_visual    , 0. },
  { "Flash"                , GMSH_INT,    (void*)&CTX.flash          , 0. },
  { "AlphaBlending"        , GMSH_INT,    (void*)&CTX.alpha          , 0. },
  { "Trackball"            , GMSH_INT,    (void*)&CTX.useTrackball   , 1. },
  { "Clip0"                , GMSH_INT,    (void*)&CTX.clip[0]        , 0. },
  { "Clip00"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[0][0] , 0.0 }, 
  { "Clip01"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[0][1] , 0.0 }, 
  { "Clip02"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[0][2] , 0.0 }, 
  { "Clip03"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[0][3] , 0.0 }, 
  { "Clip1"                , GMSH_INT,    (void*)&CTX.clip[1]          , 0. },
  { "Clip10"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[1][0] , 0.0 }, 
  { "Clip11"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[1][1] , 0.0 }, 
  { "Clip12"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[1][2] , 0.0 }, 
  { "Clip13"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[1][3] , 0.0 }, 
  { "Clip2"                , GMSH_INT,    (void*)&CTX.clip[2]          , 0. },
  { "Clip20"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[2][0] , 0.0 }, 
  { "Clip21"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[2][1] , 0.0 }, 
  { "Clip22"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[2][2] , 0.0 }, 
  { "Clip23"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[2][3] , 0.0 }, 
  { "Clip3"                , GMSH_INT,    (void*)&CTX.clip[3]          , 0. },
  { "Clip30"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[3][0] , 0.0 }, 
  { "Clip31"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[3][1] , 0.0 }, 
  { "Clip32"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[3][2] , 0.0 }, 
  { "Clip33"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[3][3] , 0.0 }, 
  { "Clip4"                , GMSH_INT,    (void*)&CTX.clip[4]          , 0. },
  { "Clip40"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[4][0] , 0.0 }, 
  { "Clip41"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[4][1] , 0.0 }, 
  { "Clip42"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[4][2] , 0.0 }, 
  { "Clip43"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[4][3] , 0.0 }, 
  { "Clip5"                , GMSH_INT,    (void*)&CTX.clip[5]          , 0. },
  { "Clip50"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[5][0] , 0.0 }, 
  { "Clip51"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[5][1] , 0.0 }, 
  { "Clip52"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[5][2] , 0.0 }, 
  { "Clip53"               , GMSH_DOUBLE, (void*)&CTX.clip_plane[5][3] , 0.0 }, 
  { "Light0"               , GMSH_INT,    (void*)&CTX.light[0]         , 1. },
  { "Light00"              , GMSH_FLOAT,  (void*)&CTX.light_position[0][0] , 0.5 }, 
  { "Light01"              , GMSH_FLOAT,  (void*)&CTX.light_position[0][1] , 0.3 }, 
  { "Light02"              , GMSH_FLOAT,  (void*)&CTX.light_position[0][2] , 1.0 }, 
  { "Light03"              , GMSH_FLOAT,  (void*)&CTX.light_position[0][3] , 0.0 }, 
  { "Light1"               , GMSH_INT,    (void*)&CTX.light[1]             , 0. },
  { "Light10"              , GMSH_FLOAT,  (void*)&CTX.light_position[1][0] , 0.0 }, 
  { "Light11"              , GMSH_FLOAT,  (void*)&CTX.light_position[1][1] , 0.0 }, 
  { "Light12"              , GMSH_FLOAT,  (void*)&CTX.light_position[1][2] , 0.0 }, 
  { "Light13"              , GMSH_FLOAT,  (void*)&CTX.light_position[1][3] , 0.0 }, 
  { "Light2"               , GMSH_INT,    (void*)&CTX.light[2]             , 0. },
  { "Light20"              , GMSH_FLOAT,  (void*)&CTX.light_position[2][0] , 0.0 }, 
  { "Light21"              , GMSH_FLOAT,  (void*)&CTX.light_position[2][1] , 0.0 }, 
  { "Light22"              , GMSH_FLOAT,  (void*)&CTX.light_position[2][2] , 0.0 }, 
  { "Light23"              , GMSH_FLOAT,  (void*)&CTX.light_position[2][3] , 0.0 }, 
  { "Light3"               , GMSH_INT,    (void*)&CTX.light[3]             , 0. },
  { "Light30"              , GMSH_FLOAT,  (void*)&CTX.light_position[3][0] , 0.0 }, 
  { "Light31"              , GMSH_FLOAT,  (void*)&CTX.light_position[3][1] , 0.0 }, 
  { "Light32"              , GMSH_FLOAT,  (void*)&CTX.light_position[3][2] , 0.0 }, 
  { "Light33"              , GMSH_FLOAT,  (void*)&CTX.light_position[3][3] , 0.0 }, 
  { "Light4"               , GMSH_INT,    (void*)&CTX.light[4]             , 0. },
  { "Light40"              , GMSH_FLOAT,  (void*)&CTX.light_position[4][0] , 0.0 }, 
  { "Light41"              , GMSH_FLOAT,  (void*)&CTX.light_position[4][1] , 0.0 }, 
  { "Light42"              , GMSH_FLOAT,  (void*)&CTX.light_position[4][2] , 0.0 }, 
  { "Light43"              , GMSH_FLOAT,  (void*)&CTX.light_position[4][3] , 0.0 }, 
  { "Light5"               , GMSH_INT,    (void*)&CTX.light[5]             , 0. },
  { "Light50"              , GMSH_FLOAT,  (void*)&CTX.light_position[5][0] , 0.0 }, 
  { "Light51"              , GMSH_FLOAT,  (void*)&CTX.light_position[5][1] , 0.0 }, 
  { "Light52"              , GMSH_FLOAT,  (void*)&CTX.light_position[5][2] , 0.0 }, 
  { "Light53"              , GMSH_FLOAT,  (void*)&CTX.light_position[5][3] , 0.0 }, 
  { NULL                   , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber GeometryOptions_Number[] = {
  { "Normals"         , GMSH_DOUBLE, (void*)&CTX.geom.normals      , 0. }, 
  { "Tangents"        , GMSH_DOUBLE, (void*)&CTX.geom.tangents     , 0. }, 
  { "Points"          , GMSH_INT,    (void*)&CTX.geom.points       , 1. }, 
  { "Lines"           , GMSH_INT,    (void*)&CTX.geom.lines        , 1. }, 
  { "Surfaces"        , GMSH_INT,    (void*)&CTX.geom.surfaces     , 0. }, 
  { "Volumes"         , GMSH_INT,    (void*)&CTX.geom.volumes      , 0. }, 
  { "PointsNumbers"   , GMSH_INT,    (void*)&CTX.geom.points_num   , 0. }, 
  { "LinesNumbers"    , GMSH_INT,    (void*)&CTX.geom.lines_num    , 0. }, 
  { "SurfacesNumbers" , GMSH_INT,    (void*)&CTX.geom.surfaces_num , 0. }, 
  { "VolumesNumbers"  , GMSH_INT,    (void*)&CTX.geom.volumes_num  , 0. }, 
  { "HiddenLines"     , GMSH_INT,    (void*)&CTX.geom.hidden       , 0. }, 
  { "Shading"         , GMSH_INT,    (void*)&CTX.geom.shade        , 0. }, 
  { "Highlight"       , GMSH_INT,    (void*)&CTX.geom.highlight    , 1. }, 
  { "OldCircle"       , GMSH_INT,    (void*)&CTX.geom.old_circle   , 0. }, 
  { "ScalingFactor"   , GMSH_DOUBLE, (void*)&CTX.geom.scaling_factor , 1.0 }, 
  { NULL              , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber MeshOptions_Number[] = {
  { "Quality"         , GMSH_DOUBLE, (void*)&CTX.mesh.quality        , 0.0 }, 
  { "Normals"         , GMSH_DOUBLE, (void*)&CTX.mesh.normals        , 0.0 }, 
  { "Tangents"        , GMSH_DOUBLE, (void*)&CTX.mesh.tangents       , 0.0 }, 
  { "Explode"         , GMSH_DOUBLE, (void*)&CTX.mesh.explode        , 1.0 }, 
  { "ScalingFactor"   , GMSH_DOUBLE, (void*)&CTX.mesh.scaling_factor , 1.0 }, 
  { "CharacteristicLengthFactor" , 
                        GMSH_DOUBLE, (void*)&CTX.mesh.lc_factor      , 1.0 }, 
  { "RandomFactor"    , GMSH_DOUBLE, (void*)&CTX.mesh.rand_factor    , 1.e-5 }, 
  { "GammaLimit"      , GMSH_DOUBLE, (void*)&CTX.mesh.limit_gamma    , 0.0 }, 
  { "EtaLimit"        , GMSH_DOUBLE, (void*)&CTX.mesh.limit_eta      , 0.0 }, 
  { "RhoLimit"        , GMSH_DOUBLE, (void*)&CTX.mesh.limit_rho      , 0.0 }, 
  { "Points"          , GMSH_INT,    (void*)&CTX.mesh.points         , 1. }, 
  { "Lines"           , GMSH_INT,    (void*)&CTX.mesh.lines          , 1. }, 
  { "Surfaces"        , GMSH_INT,    (void*)&CTX.mesh.surfaces       , 1. }, 
  { "Volumes"         , GMSH_INT,    (void*)&CTX.mesh.volumes        , 1. }, 
  { "PointsNumbers"   , GMSH_INT,    (void*)&CTX.mesh.points_num     , 0. }, 
  { "LinesNumbers"    , GMSH_INT,    (void*)&CTX.mesh.lines_num      , 0. }, 
  { "SurfacesNumbers" , GMSH_INT,    (void*)&CTX.mesh.surfaces_num   , 0. }, 
  { "VolumesNumbers"  , GMSH_INT,    (void*)&CTX.mesh.volumes_num    , 0. }, 
  { "HiddenLines"     , GMSH_INT,    (void*)&CTX.mesh.hidden         , 0. }, 
  { "Shading"         , GMSH_INT,    (void*)&CTX.mesh.shade          , 0. }, 
  { "Format"          , GMSH_INT,    (void*)&CTX.mesh.format         , FORMAT_MSH }, 
  { "Smoothing"       , GMSH_INT,    (void*)&CTX.mesh.nb_smoothing   , 0. }, 
  { "Algorithm"       , GMSH_INT,    (void*)&CTX.mesh.algo           , DELAUNAY_OLDALGO }, 
  { "PointInsertion"  , GMSH_INT,    (void*)&CTX.mesh.point_insertion, CENTER_CIRCCIRC }, 
  { "SpeedMax"        , GMSH_INT,    (void*)&CTX.mesh.speed_max      , 0. }, 
  { "MinimumCirclePoints" ,
                        GMSH_INT,    (void*)&CTX.mesh.min_circ_points, 7. }, 
  { "Degree"          , GMSH_INT,    (void*)&CTX.mesh.degree         , 1. }, 
  { "Dual"            , GMSH_INT,    (void*)&CTX.mesh.dual           , 0. }, 
  { "Interactive"     , GMSH_INT,    (void*)&CTX.mesh.interactive    , 0. }, 
  { NULL              , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { "Scales"           , GMSH_INT,    (void*)&CTX.post.scales             , 1. }, 
  { "Link"             , GMSH_INT,    (void*)&CTX.post.link               , 0. }, 
  { "Visibility"       , GMSH_INT,    (void*)&CTX.post.initial_visibility , 1. }, 
  { "IntervalsMode"    , GMSH_INT,    (void*)&CTX.post.initial_intervals  , DRAW_POST_ISO }, 
  { "IntervalsNumber"  , GMSH_INT,    (void*)&CTX.post.initial_nbiso      , 15. }, 
  { "AnimationDelay"   , GMSH_INT,    (void*)&CTX.post.anim_delay         , 0. }, 
  { "NbViews"          , GMSH_INT,    (void*)&CTX.post.nb_views           , 0. }, 
  { NULL               , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber PrintOptions_Number[] = {
  { "Format"         , GMSH_INT,    (void*)&CTX.print.format         , FORMAT_AUTO }, 
  { "EpsQuality"     , GMSH_INT,    (void*)&CTX.print.eps_quality    , 1 }, 
  { "JpegQuality"    , GMSH_INT,    (void*)&CTX.print.jpeg_quality   , 85 }, 
  { "GifDither"      , GMSH_INT,    (void*)&CTX.print.gif_dither     , 0 }, 
  { "GifSort"        , GMSH_INT,    (void*)&CTX.print.gif_sort       , 1 }, 
  { "GifInterlace"   , GMSH_INT,    (void*)&CTX.print.gif_interlace  , 0 }, 
  { "GifTransparent" , GMSH_INT,    (void*)&CTX.print.gif_transparent, 0 }, 
  { "FontSize"       , GMSH_INT,    (void*)&CTX.print.font_size      , 12. }, 
  { NULL             , GMSH_DOUBLE, NULL , 0. }
} ;

// COLORS

StringXColor GeneralOptions_Color[] = {
  { "Background" , &CTX.color.bg ,
    PACK_COLOR(0,   0,   0,   255), 
    PACK_COLOR(255, 255, 255, 255), 
    PACK_COLOR(255, 255, 255, 255) },
  { "Foreground" , &CTX.color.fg ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Text"       , &CTX.color.text ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Axes"       , &CTX.color.axes ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SmallAxes"  , &CTX.color.small_axes ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { NULL         , NULL ,  0, 0, 0 }
} ;

StringXColor GeometryOptions_Color[] = {
  { "Points"             , &CTX.color.geom.point , 
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(0,   0,   0,   255) },
  { "Lines"              , &CTX.color.geom.line ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Surfaces"           , &CTX.color.geom.surface ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Volumes"            , &CTX.color.geom.volume ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "PointsSelect"       , &CTX.color.geom.point_sel ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "LinesSelect"        , &CTX.color.geom.line_sel ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SurfacesSelect"     , &CTX.color.geom.surface_sel ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "VolumesSelect"      , &CTX.color.geom.volume_sel ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "PointsHighlight"    , &CTX.color.geom.point_hlt ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "LinesHighlight"     , &CTX.color.geom.line_hlt ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SurfacesHighlight"  , &CTX.color.geom.surface_hlt ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "VolumesHighlight"   , &CTX.color.geom.volume_hlt ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tangents"           , &CTX.color.geom.tangents ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Normals"            , &CTX.color.geom.normals ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { NULL                 , NULL , 0, 0, 0  }
} ;

StringXColor MeshOptions_Color[] = {
  { "Points"             , &CTX.color.mesh.vertex , 
    PACK_COLOR(0  , 123, 59 , 255),
    PACK_COLOR(0  , 123, 59 , 255),
  },
  { "PointsSupp"         , &CTX.color.mesh.vertex_supp , 
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Lines"              , &CTX.color.mesh.line , 
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Triangles"          , &CTX.color.mesh.triangle ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Quadrangles"        , &CTX.color.mesh.quadrangle ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tetrahedra"         , &CTX.color.mesh.tetrahedron ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Hexahedra"          , &CTX.color.mesh.hexahedron ,
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Prisms"             , &CTX.color.mesh.prism ,
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Pyramids"           , &CTX.color.mesh.pyramid ,
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tangents"           , &CTX.color.mesh.tangents ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Normals"            , &CTX.color.mesh.normals ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "One"                , &CTX.color.mesh.carousel[0] ,
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Two"                , &CTX.color.mesh.carousel[1] ,
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Three"              , &CTX.color.mesh.carousel[2] ,
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Four"               , &CTX.color.mesh.carousel[3] ,
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Five"               , &CTX.color.mesh.carousel[4] ,
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Six"                , &CTX.color.mesh.carousel[5] ,
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Seven"              , &CTX.color.mesh.carousel[6] ,
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Eight"              , &CTX.color.mesh.carousel[7] ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Nine"               , &CTX.color.mesh.carousel[8] ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Ten"                , &CTX.color.mesh.carousel[9] ,
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { NULL                 , NULL , 0, 0, 0  }
} ;

StringXColor PostProcessingOptions_Color[] = {
  { NULL         , NULL ,  0, 0, 0 }
} ;

StringXColor PrintOptions_Color[] = {
  { NULL         , NULL ,  0, 0, 0 }
} ;

#endif

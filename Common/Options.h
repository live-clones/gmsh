/* $Id: Options.h,v 1.1 2000-12-05 15:28:22 geuzaine Exp $ */
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
  { NULL   , NULL             ,   NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { "Rotation0"    , GMSH_DOUBLE, (void*)&CTX.r[0]          , 0.0 }, 
  { "Rotation1"    , GMSH_DOUBLE, (void*)&CTX.r[1]          , 0.0 }, 
  { "Rotation2"    , GMSH_DOUBLE, (void*)&CTX.r[2]          , 0.0 }, 
  { "Translation0" , GMSH_DOUBLE, (void*)&CTX.t[0]          , 0.0 }, 
  { "Translation1" , GMSH_DOUBLE, (void*)&CTX.t[1]          , 0.0 }, 
  { "Translation2" , GMSH_DOUBLE, (void*)&CTX.t[2]          , 0.0 }, 
  { "Scale0"       , GMSH_DOUBLE, (void*)&CTX.s[0]          , 1.0 }, 
  { "Scale1"       , GMSH_DOUBLE, (void*)&CTX.s[1]          , 1.0 }, 
  { "Scale2"       , GMSH_DOUBLE, (void*)&CTX.s[2]          , 1.0 }, 
  { "Shininess"    , GMSH_FLOAT,  (void*)&CTX.shine         , 0.4 }, 
  { "Verbosity"    , GMSH_INT,    (void*)&CTX.verbosity     , 2. },
  { "Orthographic" , GMSH_INT,    (void*)&CTX.ortho         , 1. }, 
  { "FastRedraw"   , GMSH_INT,    (void*)&CTX.fast          , 1. },
  { "Axes"         , GMSH_INT,    (void*)&CTX.axes          , 1. },
  { "SmallAxes"    , GMSH_INT,    (void*)&CTX.small_axes    , 1. },
  { "DisplayLists" , GMSH_INT,    (void*)&CTX.display_lists , 0. },
  { "SameVisual"   , GMSH_INT,    (void*)&CTX.same_visual   , 0. },
  { "Flash"        , GMSH_INT,    (void*)&CTX.flash         , 0. },
  { "AlphaBlending", GMSH_INT,    (void*)&CTX.alpha         , 0. },
  { "Clip0"        , GMSH_INT,    (void*)&CTX.clip[0]       , 0. },
  { "Clip1"        , GMSH_INT,    (void*)&CTX.clip[1]       , 0. },
  { "Clip2"        , GMSH_INT,    (void*)&CTX.clip[2]       , 0. },
  { "Clip3"        , GMSH_INT,    (void*)&CTX.clip[3]       , 0. },
  { "Clip4"        , GMSH_INT,    (void*)&CTX.clip[4]       , 0. },
  { "Clip5"        , GMSH_INT,    (void*)&CTX.clip[5]       , 0. },
  { "Light0"       , GMSH_INT,    (void*)&CTX.light[0]      , 1. },
  { "Light1"       , GMSH_INT,    (void*)&CTX.light[1]      , 0. },
  { "Light2"       , GMSH_INT,    (void*)&CTX.light[2]      , 0. },
  { "Light3"       , GMSH_INT,    (void*)&CTX.light[3]      , 0. },
  { "Light4"       , GMSH_INT,    (void*)&CTX.light[4]      , 0. },
  { "Light5"       , GMSH_INT,    (void*)&CTX.light[5]      , 0. },
  { NULL           , GMSH_DOUBLE, NULL , 0. }
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
  { NULL              , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber MeshOptions_Number[] = {
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
  { NULL               , GMSH_DOUBLE, NULL , 0. }
} ;

StringXNumber PrintOptions_Number[] = {
  { "Type"           , GMSH_INT,    (void*)&CTX.print.type      , PRINT_GL2PS_SIMPLE }, 
  { "Format"         , GMSH_INT,    (void*)&CTX.print.format    , FORMAT_EPS }, 
  { "FontSize"       , GMSH_INT,    (void*)&CTX.print.font_size , 12. }, 
  { NULL             , GMSH_DOUBLE, NULL , 0. }
} ;

// ARRAYS

StringXArray GeneralOptions_Array[] = {
  { "ClipPlane0"     , GMSH_DOUBLE, CTX.clip_plane[0] , 0., 0., 0., 0. }, 
  { "ClipPlane1"     , GMSH_DOUBLE, CTX.clip_plane[1] , 0., 0., 0., 0. }, 
  { "ClipPlane2"     , GMSH_DOUBLE, CTX.clip_plane[2] , 0., 0., 0., 0. }, 
  { "ClipPlane3"     , GMSH_DOUBLE, CTX.clip_plane[3] , 0., 0., 0., 0. }, 
  { "ClipPlane4"     , GMSH_DOUBLE, CTX.clip_plane[4] , 0., 0., 0., 0. }, 
  { "ClipPlane5"     , GMSH_DOUBLE, CTX.clip_plane[5] , 0., 0., 0., 0. }, 
  { "LightPosition0" , GMSH_FLOAT,  CTX.light_position[0]  , 0.5, 0.3, 1.0, 0.0 }, 
  { "LightPosition1" , GMSH_FLOAT,  CTX.light_position[1]  , 0.5, 0.3, 1.0, 0.0 }, 
  { "LightPosition2" , GMSH_FLOAT,  CTX.light_position[2]  , 0.5, 0.3, 1.0, 0.0 }, 
  { "LightPosition3" , GMSH_FLOAT,  CTX.light_position[3]  , 0.5, 0.3, 1.0, 0.0 }, 
  { "LightPosition4" , GMSH_FLOAT,  CTX.light_position[4]  , 0.5, 0.3, 1.0, 0.0 }, 
  { "LightPosition5" , GMSH_FLOAT,  CTX.light_position[5]  , 0.5, 0.3, 1.0, 0.0 }, 
  { NULL ,             GMSH_DOUBLE, NULL, 0., 0., 0., 0. }
} ;

StringXArray GeometryOptions_Array[] = {
  { NULL , GMSH_DOUBLE, NULL, 0., 0., 0., 0. }
} ;

StringXArray MeshOptions_Array[] = {
  { NULL , GMSH_DOUBLE, NULL, 0., 0., 0., 0. }
} ;

StringXArray PostProcessingOptions_Array[] = {
  { NULL , GMSH_DOUBLE, NULL, 0., 0., 0., 0. }
} ;

StringXArray PrintOptions_Array[] = {
  { NULL , GMSH_DOUBLE, NULL, 0., 0., 0., 0. }
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

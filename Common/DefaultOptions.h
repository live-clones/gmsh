#ifndef _DEFAULT_OPTIONS_H_
#define _DEFAULT_OPTIONS_H_

// Option Database (General, Geometry, Mesh, Post, View, Print), with
// default values

// STRINGS

StringXString GeneralOptions_String[] = {
  { "Display" , opt_general_display , "" },
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

StringXString ViewOptions_String[] = {
  { "Name"      , opt_view_name , "" },
  { "Format"    , opt_view_format , "%.3e" },
  { "FileName"  , opt_view_filename , "" },
  { NULL , NULL , NULL }
} ;

StringXString PrintOptions_String[] = {
  { "Font" ,  opt_print_font , "Courier" },
  { NULL , NULL , NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { "Viewport0"            , opt_general_viewport0 , 0. }, 
  { "Viewport1"            , opt_general_viewport1 , 0. }, 
  { "Viewport2"            , opt_general_viewport2 , 700. }, 
  { "Viewport3"            , opt_general_viewport3 , 500. }, 
  { "GraphicsPosition0"    , opt_general_graphics_position0 , 20. }, 
  { "GraphicsPosition1"    , opt_general_graphics_position1 , 30. }, 
  { "GraphicsFontSize"     , opt_general_graphics_fontsize , 11. }, 
  { "MenuPosition0"        , opt_general_menu_position0 , 800. }, 
  { "MenuPosition1"        , opt_general_menu_position1 , 50. }, 
  { "MenuFontSize"         , opt_general_menu_fontsize , 12. }, 
  { "CenterWindows"        , opt_general_center_windows , 1. }, 
  { "Rotation0"            , opt_general_rotation0 , 0.0 }, 
  { "Rotation1"            , opt_general_rotation1 , 0.0 }, 
  { "Rotation2"            , opt_general_rotation2 , 0.0 }, 
  { "TrackballQuaternion0" , opt_general_quaternion0 , 0.0 }, 
  { "TrackballQuaternion1" , opt_general_quaternion1 , 0.0 }, 
  { "TrackballQuaternion2" , opt_general_quaternion2 , 0.0 }, 
  { "TrackballQuaternion3" , opt_general_quaternion3 , 1.0 }, 
  { "Translation0"         , opt_general_translation0 , 0.0 }, 
  { "Translation1"         , opt_general_translation1 , 0.0 }, 
  { "Translation2"         , opt_general_translation2 , 0.0 }, 
  { "Scale0"               , opt_general_scale0 , 1.0 }, 
  { "Scale1"               , opt_general_scale1 , 1.0 }, 
  { "Scale2"               , opt_general_scale2 , 1.0 }, 
  { "Shininess"            , opt_general_shine , 0.4 }, 
  { "ColorScheme"          , opt_general_color_scheme , 0. }, 
  { "Verbosity"            , opt_general_verbosity , 2. },
  { "Terminal"             , opt_general_terminal , 1. },
  { "Orthographic"         , opt_general_orthographic , 1. }, 
  { "FastRedraw"           , opt_general_fast_redraw , 1. },
  { "Axes"                 , opt_general_axes , 1. },
  { "SmallAxes"            , opt_general_small_axes , 1. },
  { "DisplayLists"         , opt_general_display_lists , 0. },
  { "AlphaBlending"        , opt_general_alpha_blending , 0. },
  { "Trackball"            , opt_general_trackball , 1. },
  { "ZoomFactor"           , opt_general_zoom_factor , 1.1 }, 
  { "Clip0"                , opt_general_clip0 , 0. },
  { "Clip0a"               , opt_general_clip0a , 0.0 }, 
  { "Clip0b"               , opt_general_clip0b , 0.0 }, 
  { "Clip0c"               , opt_general_clip0c , 0.0 }, 
  { "Clip0d"               , opt_general_clip0d , 0.0 }, 
  { "Clip1"                , opt_general_clip1 , 0. },
  { "Clip1a"               , opt_general_clip1a , 0.0 }, 
  { "Clip1b"               , opt_general_clip1b , 0.0 }, 
  { "Clip1c"               , opt_general_clip1c , 0.0 }, 
  { "Clip1d"               , opt_general_clip1d , 0.0 }, 
  { "Clip2"                , opt_general_clip2 , 0. },
  { "Clip2a"               , opt_general_clip2a , 0.0 }, 
  { "Clip2b"               , opt_general_clip2b , 0.0 }, 
  { "Clip2c"               , opt_general_clip2c , 0.0 }, 
  { "Clip2d"               , opt_general_clip2d , 0.0 }, 
  { "Clip3"                , opt_general_clip3 , 0. },
  { "Clip3a"               , opt_general_clip3a , 0.0 }, 
  { "Clip3b"               , opt_general_clip3b , 0.0 }, 
  { "Clip3c"               , opt_general_clip3c , 0.0 }, 
  { "Clip3d"               , opt_general_clip3d , 0.0 }, 
  { "Clip4"                , opt_general_clip4 , 0. },
  { "Clip4a"               , opt_general_clip4a , 0.0 }, 
  { "Clip4b"               , opt_general_clip4b , 0.0 }, 
  { "Clip4c"               , opt_general_clip4c , 0.0 }, 
  { "Clip4d"               , opt_general_clip4d , 0.0 }, 
  { "Clip5"                , opt_general_clip5 , 0. },
  { "Clip5a"               , opt_general_clip5a , 0.0 }, 
  { "Clip5b"               , opt_general_clip5b , 0.0 }, 
  { "Clip5c"               , opt_general_clip5c , 0.0 }, 
  { "Clip5d"               , opt_general_clip5d , 0.0 }, 
  { "Light0"               , opt_general_light0 , 1. },
  { "Light00"              , opt_general_light00 , 0.5 }, 
  { "Light01"              , opt_general_light01 , 0.3 }, 
  { "Light02"              , opt_general_light02 , 1.0 }, 
  { "Light1"               , opt_general_light1 , 0. },
  { "Light10"              , opt_general_light10 , 0.5 }, 
  { "Light11"              , opt_general_light11 , 0.3 }, 
  { "Light12"              , opt_general_light12 , 1.0 }, 
  { "Light2"               , opt_general_light2 , 0. },
  { "Light20"              , opt_general_light20 , 0.5 }, 
  { "Light21"              , opt_general_light21 , 0.3 }, 
  { "Light22"              , opt_general_light22 , 1.0 }, 
  { "Light3"               , opt_general_light3 , 0. },
  { "Light30"              , opt_general_light30 , 0.5 }, 
  { "Light31"              , opt_general_light31 , 0.3 }, 
  { "Light32"              , opt_general_light32 , 1.0 }, 
  { "Light4"               , opt_general_light4 , 0. },
  { "Light40"              , opt_general_light40 , 0.5 }, 
  { "Light41"              , opt_general_light41 , 0.3 }, 
  { "Light42"              , opt_general_light42 , 1.0 }, 
  { "Light5"               , opt_general_light5 , 0. },
  { "Light50"              , opt_general_light50 , 0.5 }, 
  { "Light51"              , opt_general_light51 , 0.3 }, 
  { "Light52"              , opt_general_light52 , 1.0 }, 
  { NULL , NULL , 0. }
} ;

StringXNumber GeometryOptions_Number[] = {
  { "Normals"         , opt_geometry_normals , 0. }, 
  { "Tangents"        , opt_geometry_tangents , 0. }, 
  { "Points"          , opt_geometry_points , 1. }, 
  { "Lines"           , opt_geometry_lines , 1. }, 
  { "Surfaces"        , opt_geometry_surfaces , 0. }, 
  { "Volumes"         , opt_geometry_volumes , 0. }, 
  { "PointsNumbers"   , opt_geometry_points_num , 0. }, 
  { "LinesNumbers"    , opt_geometry_lines_num , 0. }, 
  { "SurfacesNumbers" , opt_geometry_surfaces_num , 0. }, 
  { "VolumesNumbers"  , opt_geometry_volumes_num , 0. }, 
  { "HiddenLines"     , opt_geometry_hidden , 0. }, 
  { "Shading"         , opt_geometry_shade , 0. }, 
  { "Highlight"       , opt_geometry_highlight , 1. }, 
  { "OldCircle"       , opt_geometry_old_circle , 0. }, 
  { "ScalingFactor"   , opt_geometry_scaling_factor , 1.0 }, 
  { NULL , NULL , 0. }
} ;

StringXNumber MeshOptions_Number[] = {
  { "Quality"         , opt_mesh_quality , 0.0 }, 
  { "Normals"         , opt_mesh_normals , 0.0 }, 
  { "Tangents"        , opt_mesh_tangents , 0.0 }, 
  { "Explode"         , opt_mesh_explode , 1.0 }, 
  { "ScalingFactor"   , opt_mesh_scaling_factor , 1.0 }, 
  { "CharacteristicLengthFactor" , opt_mesh_lc_factor , 1.0 }, 
  { "RandomFactor"    , opt_mesh_rand_factor , 1.e-5 }, 
  { "GammaLimit"      , opt_mesh_limit_gamma , 0.0 }, 
  { "EtaLimit"        , opt_mesh_limit_eta , 0.0 }, 
  { "RhoLimit"        , opt_mesh_limit_rho , 0.0 }, 
  { "Points"          , opt_mesh_points , 1. }, 
  { "Lines"           , opt_mesh_lines , 1. }, 
  { "Surfaces"        , opt_mesh_surfaces , 1. }, 
  { "Volumes"         , opt_mesh_volumes , 1. }, 
  { "PointsNumbers"   , opt_mesh_points_num , 0. }, 
  { "LinesNumbers"    , opt_mesh_lines_num , 0. }, 
  { "SurfacesNumbers" , opt_mesh_surfaces_num , 0. }, 
  { "VolumesNumbers"  , opt_mesh_volumes_num , 0. }, 
  { "HiddenLines"     , opt_mesh_hidden , 0. }, 
  { "Shading"         , opt_mesh_shade , 0. }, 
  { "Format"          , opt_mesh_format , FORMAT_MSH }, 
  { "Smoothing"       , opt_mesh_nb_smoothing , 0. }, 
  { "Algorithm"       , opt_mesh_algo , DELAUNAY_OLDALGO }, 
  { "PointInsertion"  , opt_mesh_point_insertion, CENTER_CIRCCIRC }, 
  { "SpeedMax"        , opt_mesh_speed_max , 0. }, 
  { "MinimumCirclePoints" , opt_mesh_min_circ_points, 7. }, 
  { "Degree"          , opt_mesh_degree , 1. }, 
  { "Dual"            , opt_mesh_dual , 0. }, 
  { "Interactive"     , opt_mesh_interactive , 0. }, 
  { "use_cut_plane"   , opt_mesh_use_cut_plane , 0  }, 
  { "cut_planea"      , opt_mesh_cut_planea , 1. }, 
  { "cut_planeb"      , opt_mesh_cut_planeb , 0. }, 
  { "cut_planec"      , opt_mesh_cut_planec , 0. }, 
  { "cut_planed"      , opt_mesh_cut_planed , 0. }, 
  { NULL , NULL , 0. }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { "Scales"           , opt_post_scales , 1. }, 
  { "Link"             , opt_post_link , 0. }, 
  { "Smoothing"        , opt_post_smooth , 1. }, 
  { "AnimationDelay"   , opt_post_anim_delay , 0.25 }, 
  { "NbViews"          , opt_post_nb_views , 0. }, 
  { NULL , NULL , 0. }
} ;

StringXNumber ViewOptions_Number[] = {
  { "NbTimeStep"       , opt_view_nb_timestep , 1. }, 
  { "TimeStep"         , opt_view_timestep , 0. }, 
  { "Min"              , opt_view_min , 1.e200 }, 
  { "Max"              , opt_view_max , -1.e200 }, 
  { "CustomMin"        , opt_view_custom_min , 0. }, 
  { "CustomMax"        , opt_view_custom_max , 0. }, 
  { "Offset0"          , opt_view_offset0 , 0. }, 
  { "Offset1"          , opt_view_offset1 , 0. }, 
  { "Offset2"          , opt_view_offset2 , 0. }, 
  { "Raise0"           , opt_view_raise0 , 0. }, 
  { "Raise1"           , opt_view_raise1 , 0. }, 
  { "Raise2"           , opt_view_raise2 , 0. }, 
  { "ArrowScale"       , opt_view_arrow_scale , 100. }, 
  { "Visible"          , opt_view_visible , 1. }, 
  { "IntervalsType"    , opt_view_intervals_type , DRAW_POST_ISO }, 
  { "NbIso"            , opt_view_nb_iso , 15. }, 
  { "Light"            , opt_view_light , 0. }, 
  { "ShowElement"      , opt_view_show_element , 0. }, 
  { "ShowTime"         , opt_view_show_time , 1. }, 
  { "ShowScale"        , opt_view_show_scale , 1. }, 
  { "TransparentScale" , opt_view_transparent_scale , 1. }, 
  { "ScaleType"        , opt_view_scale_type , DRAW_POST_LINEAR }, 
  { "RangeType"        , opt_view_range_type , DRAW_POST_DEFAULT }, 
  { "ArrowType"        , opt_view_arrow_type , DRAW_POST_ARROW }, 
  { "ArrowLocation"    , opt_view_arrow_location , DRAW_POST_LOCATE_COG }, 
  { NULL , NULL , 0. }
} ;

StringXNumber PrintOptions_Number[] = {
  { "Format"         , opt_print_format , FORMAT_AUTO }, 
  { "EpsQuality"     , opt_print_eps_quality , 1 }, 
  { "JpegQuality"    , opt_print_jpeg_quality , 85 }, 
  { "GifDither"      , opt_print_gif_dither , 0 }, 
  { "GifSort"        , opt_print_gif_sort , 1 }, 
  { "GifInterlace"   , opt_print_gif_interlace , 0 }, 
  { "GifTransparent" , opt_print_gif_transparent , 0 }, 
  { "FontSize"       , opt_print_font_size , 12. }, 
  { NULL , NULL , 0. }
} ;

// COLORS

StringXColor GeneralOptions_Color[] = {
  { "Background" , opt_general_color_background ,
    PACK_COLOR(0,   0,   0,   255), 
    PACK_COLOR(255, 255, 255, 255), 
    PACK_COLOR(255, 255, 255, 255) },
  { "Foreground" , opt_general_color_foreground ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Text" , opt_general_color_text ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Axes" , opt_general_color_axes ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SmallAxes" , opt_general_color_small_axes ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { NULL , NULL ,  0, 0, 0 }
} ;

StringXColor GeometryOptions_Color[] = {
  { "Points" , opt_geometry_color_points , 
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(0,   0,   0,   255) },
  { "Lines" , opt_geometry_color_lines ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Surfaces" , opt_geometry_color_surfaces ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Volumes" , opt_geometry_color_volumes ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "PointsSelect" , opt_geometry_color_points_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "LinesSelect" , opt_geometry_color_lines_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SurfacesSelect" , opt_geometry_color_surfaces_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "VolumesSelect" , opt_geometry_color_volumes_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "PointsHighlight" , opt_geometry_color_points_highlight ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "LinesHighlight" , opt_geometry_color_lines_highlight ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "SurfacesHighlight" , opt_geometry_color_surfaces_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "VolumesHighlight" , opt_geometry_color_volumes_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tangents" , opt_geometry_color_tangents ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Normals" , opt_geometry_color_normals ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { NULL , NULL , 0, 0, 0  }
} ;

StringXColor MeshOptions_Color[] = {
  { "Points" , opt_mesh_color_points , 
    PACK_COLOR(0  , 123, 59 , 255),
    PACK_COLOR(0  , 123, 59 , 255),
  },
  { "PointsSupp" , opt_mesh_color_points_supp , 
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Lines" , opt_mesh_color_lines , 
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Triangles" , opt_mesh_color_triangles ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Quadrangles" , opt_mesh_color_quadrangles ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tetrahedra" , opt_mesh_color_tetrahedra ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Hexahedra" , opt_mesh_color_hexahedra ,
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Prisms" , opt_mesh_color_prisms ,
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Pyramids" , opt_mesh_color_pyramid ,
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Tangents" , opt_mesh_color_tangents ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "Normals" , opt_mesh_color_normals ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { "One" , opt_mesh_color_1 ,
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Two" , opt_mesh_color_2 ,
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Three" , opt_mesh_color_3 ,
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Four" , opt_mesh_color_4 ,
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Five" , opt_mesh_color_5 ,
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Six" , opt_mesh_color_6 ,
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Seven" , opt_mesh_color_7 ,
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Eight" , opt_mesh_color_8 ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Nine" , opt_mesh_color_9 ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { "Ten" , opt_mesh_color_10 ,
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { NULL , NULL , 0, 0, 0  }
} ;

StringXColor PostProcessingOptions_Color[] = {
  { NULL , NULL ,  0, 0, 0 }
} ;

StringXColor ViewOptions_Color[] = {
  { NULL , NULL ,  0, 0, 0 }
} ;

StringXColor PrintOptions_Color[] = {
  { NULL , NULL ,  0, 0, 0 }
} ;

#endif

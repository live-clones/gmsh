#ifndef _DEFAULT_OPTIONS_H_
#define _DEFAULT_OPTIONS_H_

// Option Database (General, Geometry, Mesh, Post, View, Print), with
// default values. The first number defines the level of saving: O
// for the option file, S for the session file and F for the full
// listing:

#define S GMSH_SESSIONRC
#define O GMSH_OPTIONSRC
#define F GMSH_FULLRC

// STRINGS

StringXString GeneralOptions_String[] = {
  { F, "Display" , opt_general_display , "" },
  { 0, "SessionFileName" , opt_general_session_filename , ".gmshrc" },
  { F|S, "DefaultFileName" , opt_general_default_filename , "unnamed.geo" },
  { F|S, "TmpFileName" , opt_general_tmp_filename , ".gmsh-tmp" },
  { F|S, "ErrorFileName" , opt_general_error_filename , ".gmsh-errors" },
  { F|S, "OptionsFileName" , opt_general_options_filename , ".gmsh-options" },
  { 0, NULL , NULL , NULL }
} ;

StringXString GeometryOptions_String[] = {
  { 0, NULL , NULL , NULL }
} ;

StringXString MeshOptions_String[] = {
  { 0, NULL , NULL , NULL }
} ;

StringXString PostProcessingOptions_String[] = {
  { 0, NULL , NULL , NULL }
} ;

StringXString ViewOptions_String[] = {
  { F, "Name" , opt_view_name , "" },
  { F|O, "Format" , opt_view_format , "%.3e" },
  { F, "FileName" , opt_view_filename , "" },
  { 0, NULL , NULL , NULL }
} ;

StringXString PrintOptions_String[] = {
  { F|O, "Font" , opt_print_font , "Courier" },
  { 0, NULL , NULL , NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { F|S, "SaveSession" , opt_general_session_save, 1. }, 
  { F|S, "SaveOptions" , opt_general_options_save, 0. }, 
  { F|S, "FontSize" , opt_general_fontsize , 12. }, 
  { F|S, "GraphicsFontSize" , opt_general_graphics_fontsize , 11. }, 
  { F|S, "GraphicsPositionX" , opt_general_graphics_position0 , 20. }, 
  { F|S, "GraphicsPositionY" , opt_general_graphics_position1 , 30. }, 
  { F|S, "GraphicsWidth" , opt_general_viewport2 , 700. }, 
  { F|S, "GraphicsHeight" , opt_general_viewport3 , 500. }, 
  { F|S, "MenuPositionX" , opt_general_menu_position0 , 800. }, 
  { F|S, "MenuPositionY" , opt_general_menu_position1 , 50. }, 
  { F|S, "MessagePositionX" , opt_general_message_position0 , 650. }, 
  { F|S, "MessagePositionY" , opt_general_message_position1 , 150. }, 
  { F|S, "MessageWidth" , opt_general_message_size0 , 450. }, 
  { F|S, "MessageHeight" , opt_general_message_size1 , 350. }, 
  { F|O, "CenterWindows" , opt_general_center_windows , 1. }, 
  { F, "RotationX" , opt_general_rotation0 , 0.0 }, 
  { F, "RotationY" , opt_general_rotation1 , 0.0 }, 
  { F, "RotationZ" , opt_general_rotation2 , 0.0 }, 
  { F, "TrackballQuaternion0" , opt_general_quaternion0 , 0.0 }, 
  { F, "TrackballQuaternion1" , opt_general_quaternion1 , 0.0 }, 
  { F, "TrackballQuaternion2" , opt_general_quaternion2 , 0.0 }, 
  { F, "TrackballQuaternion3" , opt_general_quaternion3 , 1.0 }, 
  { F, "TranslationX" , opt_general_translation0 , 0.0 }, 
  { F, "TranslationY" , opt_general_translation1 , 0.0 }, 
  { F, "TranslationZ" , opt_general_translation2 , 0.0 }, 
  { F, "ScaleX" , opt_general_scale0 , 1.0 }, 
  { F, "ScaleY" , opt_general_scale1 , 1.0 }, 
  { F, "ScaleZ" , opt_general_scale2 , 1.0 }, 
  { F|O, "Shininess" , opt_general_shine , 0.4 }, 
  { F|O, "ColorScheme", opt_general_color_scheme , 0. }, 
#ifdef _BLACKBOX
  { F|O, "Verbosity" , opt_general_verbosity , 0. },
#else
  { F|O, "Verbosity" , opt_general_verbosity , 2. },
#endif
#ifdef _FLTK
  { F|O, "Terminal" , opt_general_terminal , 0. },
#else		      
  { F|O, "Terminal" , opt_general_terminal , 1. },
#endif
  { F|O, "Orthographic" , opt_general_orthographic , 1. }, 
  { F|O, "FastRedraw" , opt_general_fast_redraw , 1. },
  { F|O, "Axes" , opt_general_axes , 1. },
  { F|O, "SmallAxes" , opt_general_small_axes , 1. },
  { F|O, "DoubleBuffer" , opt_general_double_buffer , 1. },
  { F|O, "DisplayLists" , opt_general_display_lists , 0. },
  { F|O, "AlphaBlending" , opt_general_alpha_blending , 0. },
  { F|O, "Trackball" , opt_general_trackball , 1. },
  { F|O, "ZoomFactor" , opt_general_zoom_factor , 1.1 }, 
  { F, "Clip0" , opt_general_clip0 , 0. },
  { F, "Clip0A" , opt_general_clip0a , 0.0 }, 
  { F, "Clip0B" , opt_general_clip0b , 0.0 }, 
  { F, "Clip0C" , opt_general_clip0c , 0.0 }, 
  { F, "Clip0D" , opt_general_clip0d , 0.0 }, 
  { F, "Clip1" , opt_general_clip1 , 0. },
  { F, "Clip1A" , opt_general_clip1a , 0.0 }, 
  { F, "Clip1B" , opt_general_clip1b , 0.0 }, 
  { F, "Clip1C" , opt_general_clip1c , 0.0 }, 
  { F, "Clip1D" , opt_general_clip1d , 0.0 }, 
  { F, "Clip2" , opt_general_clip2 , 0. },
  { F, "Clip2A" , opt_general_clip2a , 0.0 }, 
  { F, "Clip2B" , opt_general_clip2b , 0.0 }, 
  { F, "Clip2C" , opt_general_clip2c , 0.0 }, 
  { F, "Clip2D" , opt_general_clip2d , 0.0 }, 
  { F, "Clip3" , opt_general_clip3 , 0. },
  { F, "Clip3A" , opt_general_clip3a , 0.0 }, 
  { F, "Clip3B" , opt_general_clip3b , 0.0 }, 
  { F, "Clip3C" , opt_general_clip3c , 0.0 }, 
  { F, "Clip3D" , opt_general_clip3d , 0.0 }, 
  { F, "Clip4" , opt_general_clip4 , 0. },
  { F, "Clip4A" , opt_general_clip4a , 0.0 }, 
  { F, "Clip4B" , opt_general_clip4b , 0.0 }, 
  { F, "Clip4C" , opt_general_clip4c , 0.0 }, 
  { F, "Clip4D" , opt_general_clip4d , 0.0 }, 
  { F, "Clip5" , opt_general_clip5 , 0. },
  { F, "Clip5A" , opt_general_clip5a , 0.0 }, 
  { F, "Clip5B" , opt_general_clip5b , 0.0 }, 
  { F, "Clip5C" , opt_general_clip5c , 0.0 }, 
  { F, "Clip5D" , opt_general_clip5d , 0.0 }, 
  { F|O, "MovingLight" , opt_general_moving_light , 0. },
  { F|O, "Light0" , opt_general_light0 , 1. },
  { F|O, "Light0X" , opt_general_light00 , 0.5 }, 
  { F|O, "Light0Y" , opt_general_light01 , 0.3 }, 
  { F|O, "Light0Z" , opt_general_light02 , 1.0 }, 
  { F|O, "Light1" , opt_general_light1 , 0. },
  { F|O, "Light1X" , opt_general_light10 , 0.5 }, 
  { F|O, "Light1Y" , opt_general_light11 , 0.3 }, 
  { F|O, "Light1Z" , opt_general_light12 , 1.0 }, 
  { F|O, "Light2" , opt_general_light2 , 0. },
  { F|O, "Light2X" , opt_general_light20 , 0.5 }, 
  { F|O, "Light2Y" , opt_general_light21 , 0.3 }, 
  { F|O, "Light2Z" , opt_general_light22 , 1.0 }, 
  { F|O, "Light3" , opt_general_light3 , 0. },
  { F|O, "Light3X" , opt_general_light30 , 0.5 }, 
  { F|O, "Light3Y" , opt_general_light31 , 0.3 }, 
  { F|O, "Light3Z" , opt_general_light32 , 1.0 }, 
  { F|O, "Light4" , opt_general_light4 , 0. },
  { F|O, "Light4X" , opt_general_light40 , 0.5 }, 
  { F|O, "Light4Y" , opt_general_light41 , 0.3 }, 
  { F|O, "Light4Z" , opt_general_light42 , 1.0 }, 
  { F|O, "Light5" , opt_general_light5 , 0. },
  { F|O, "Light5X" , opt_general_light50 , 0.5 }, 
  { F|O, "Light5Y" , opt_general_light51 , 0.3 }, 
  { F|O, "Light5Z" , opt_general_light52 , 1.0 }, 
  { 0, NULL , NULL , 0. }
} ;

StringXNumber GeometryOptions_Number[] = {
  { F|O, "Normals" , opt_geometry_normals , 0. }, 
  { F|O, "Tangents" , opt_geometry_tangents , 0. }, 
  { F|O, "Points" , opt_geometry_points , 1. }, 
  { F|O, "Lines" , opt_geometry_lines , 1. }, 
  { F|O, "Surfaces" , opt_geometry_surfaces , 0. }, 
  { F|O, "Volumes" , opt_geometry_volumes , 0. }, 
  { F|O, "PointsNumbers" , opt_geometry_points_num , 0. }, 
  { F|O, "LinesNumbers" , opt_geometry_lines_num , 0. }, 
  { F|O, "SurfacesNumbers" , opt_geometry_surfaces_num , 0. }, 
  { F|O, "VolumesNumbers" , opt_geometry_volumes_num , 0. }, 
  { F|O, "Aspect" , opt_geometry_aspect , 0. }, 
  { F|O, "Highlight" , opt_geometry_highlight , 1. }, 
  { F|O, "OldCircle" , opt_geometry_old_circle , 0. }, 
  { F|O, "ScalingFactor" , opt_geometry_scaling_factor , 1.0 }, 
  { F|O, "ColorScheme" , opt_geometry_color_scheme , 0. }, 
  { 0, NULL , NULL , 0. }
} ;

StringXNumber MeshOptions_Number[] = {
  { F|O, "Quality" , opt_mesh_quality , 0.0 }, 
  { F|O, "Normals" , opt_mesh_normals , 0.0 }, 
  { F|O, "Tangents" , opt_mesh_tangents , 0.0 }, 
  { F|O, "Explode" , opt_mesh_explode , 1.0 }, 
  { F|O, "ScalingFactor" , opt_mesh_scaling_factor , 1.0 }, 
  { F|O, "CharacteristicLengthFactor" , opt_mesh_lc_factor , 1.0 }, 
  { F|O, "RandomFactor" , opt_mesh_rand_factor , 1.e-4 }, 
  { F|O, "GammaLimit" , opt_mesh_limit_gamma , 0.0 }, 
  { F|O, "EtaLimit" , opt_mesh_limit_eta , 0.0 }, 
  { F|O, "RhoLimit" , opt_mesh_limit_rho , 0.0 }, 
  { F|O, "Points" , opt_mesh_points , 1. }, 
  { F|O, "Lines" , opt_mesh_lines , 1. }, 
  { F|O, "Surfaces" , opt_mesh_surfaces , 1. }, 
  { F|O, "Volumes" , opt_mesh_volumes , 1. }, 
  { F|O, "PointsNumbers" , opt_mesh_points_num , 0. }, 
  { F|O, "LinesNumbers" , opt_mesh_lines_num , 0. }, 
  { F|O, "SurfacesNumbers" , opt_mesh_surfaces_num , 0. }, 
  { F|O, "VolumesNumbers" , opt_mesh_volumes_num , 0. }, 
  { F|O, "Aspect" , opt_mesh_aspect , 0. }, 
  { F|O, "Format" , opt_mesh_format , FORMAT_MSH }, 
  { F|O, "Smoothing" , opt_mesh_nb_smoothing , 0. }, 
  { F|O, "Algorithm" , opt_mesh_algo , DELAUNAY_OLDALGO }, 
  { F|O, "PointInsertion" , opt_mesh_point_insertion, CENTER_CIRCCIRC }, 
  { F|O, "SpeedMax" , opt_mesh_speed_max , 0. }, 
  { F|O, "MinimumCirclePoints" , opt_mesh_min_circ_points, 7. }, 
  { F|O, "Degree" , opt_mesh_degree , 1. }, 
  { F|O, "Dual" , opt_mesh_dual , 0. }, 
  { F|O, "Interactive" , opt_mesh_interactive , 0. }, 
  { F|O, "ColorScheme" , opt_mesh_color_scheme , 0. }, 
  { F|O, "ColorCarousel" , opt_mesh_color_carousel , 1. }, 
  { F, "use_cut_plane" , opt_mesh_use_cut_plane , 0  }, 
  { F, "cut_planea" , opt_mesh_cut_planea , 1. }, 
  { F, "cut_planeb" , opt_mesh_cut_planeb , 0. }, 
  { F, "cut_planec" , opt_mesh_cut_planec , 0. }, 
  { F, "cut_planed" , opt_mesh_cut_planed , 0. }, 
  { 0, NULL , NULL , 0. }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { F|O, "Scales" , opt_post_scales , 1. }, 
  { F|O, "Link" , opt_post_link , 0. }, 
  { F|O, "Smoothing" , opt_post_smooth , 0. }, 
  { F|O, "AnimationDelay" , opt_post_anim_delay , 0.25 }, 
  { F, "NbViews" , opt_post_nb_views , 0. }, 
  { 0, NULL , NULL , 0. }
} ;

StringXNumber ViewOptions_Number[] = {
  { F, "NbTimeStep" , opt_view_nb_timestep , 1. }, 
  { F, "TimeStep" , opt_view_timestep , 0. }, 
  { F, "Min" , opt_view_min , 1.e200 }, 
  { F, "Max" , opt_view_max , -1.e200 }, 
  { F, "CustomMin" , opt_view_custom_min , 0. }, 
  { F, "CustomMax" , opt_view_custom_max , 0. }, 
  { F, "OffsetX" , opt_view_offset0 , 0. }, 
  { F, "OffsetY" , opt_view_offset1 , 0. }, 
  { F, "OffsetZ" , opt_view_offset2 , 0. }, 
  { F, "RaiseX" , opt_view_raise0 , 0. }, 
  { F, "RaiseY" , opt_view_raise1 , 0. }, 
  { F, "RaiseZ" , opt_view_raise2 , 0. }, 
  { F|O, "ArrowScale" , opt_view_arrow_scale , 50. }, 
  { F, "Visible" , opt_view_visible , 1. }, 
  { F|O, "IntervalsType" , opt_view_intervals_type , DRAW_POST_ISO }, 
  { F|O, "NbIso" , opt_view_nb_iso , 15. }, 
  { F|O, "Light" , opt_view_light , 0. }, 
  { F|O, "ShowElement" , opt_view_show_element , 0. }, 
  { F|O, "ShowTime" , opt_view_show_time , 1. }, 
  { F|O, "ShowScale" , opt_view_show_scale , 1. }, 
  { F|O, "DrawPoints" , opt_view_draw_points , 1. }, 
  { F|O, "DrawLines" , opt_view_draw_lines , 1. }, 
  { F|O, "DrawTriangles" , opt_view_draw_triangles , 1. }, 
  { F|O, "DrawTetrahedra" , opt_view_draw_tetrahedra , 1. }, 
  { F|O, "TransparentScale" , opt_view_transparent_scale , 1. }, 
  { F|O, "ScaleType" , opt_view_scale_type , DRAW_POST_LINEAR }, 
  { F|O, "RangeType" , opt_view_range_type , DRAW_POST_DEFAULT }, 
  { F|O, "ArrowType" , opt_view_arrow_type , DRAW_POST_ARROW }, 
  { F|O, "ArrowLocation" , opt_view_arrow_location , DRAW_POST_LOCATE_COG }, 
  { 0, NULL , NULL , 0. }
} ;

StringXNumber PrintOptions_Number[] = {
  { F|O, "Format" , opt_print_format , FORMAT_AUTO }, 
  { F|O, "EpsQuality" , opt_print_eps_quality , 1 }, 
  { F|O, "JpegQuality" , opt_print_jpeg_quality , 85 }, 
  { F|O, "GifDither" , opt_print_gif_dither , 0 }, 
  { F|O, "GifSort" , opt_print_gif_sort , 1 }, 
  { F|O, "GifInterlace" , opt_print_gif_interlace , 0 }, 
  { F|O, "GifTransparent" , opt_print_gif_transparent , 0 }, 
  { F|O, "FontSize" , opt_print_font_size , 12. }, 
  { 0, NULL , NULL , 0. }
} ;

// COLORS

StringXColor GeneralOptions_Color[] = {
  { F|O, "Background" , opt_general_color_background ,
    PACK_COLOR(0,   0,   0,   255), 
    PACK_COLOR(255, 255, 255, 255), 
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Foreground" , opt_general_color_foreground ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Text" , opt_general_color_text ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Axes" , opt_general_color_axes ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "SmallAxes" , opt_general_color_small_axes ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { 0, NULL , NULL ,  0, 0, 0 }
} ;

StringXColor GeometryOptions_Color[] = {
  { F|O, "Points" , opt_geometry_color_points , 
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Lines" , opt_geometry_color_lines ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Surfaces" , opt_geometry_color_surfaces ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Volumes" , opt_geometry_color_volumes ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "PointsSelect" , opt_geometry_color_points_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "LinesSelect" , opt_geometry_color_lines_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "SurfacesSelect" , opt_geometry_color_surfaces_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "VolumesSelect" , opt_geometry_color_volumes_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "PointsHighlight" , opt_geometry_color_points_highlight ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "LinesHighlight" , opt_geometry_color_lines_highlight ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "SurfacesHighlight" , opt_geometry_color_surfaces_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "VolumesHighlight" , opt_geometry_color_volumes_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Tangents" , opt_geometry_color_tangents ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Normals" , opt_geometry_color_normals ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { 0, NULL , NULL , 0, 0, 0  }
} ;

StringXColor MeshOptions_Color[] = {
  { F|O, "Points" , opt_mesh_color_points , 
    PACK_COLOR(0  , 123, 59 , 255),
    PACK_COLOR(0  , 123, 59 , 255),
  },
  { F|O, "PointsSupp" , opt_mesh_color_points_supp , 
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Lines" , opt_mesh_color_lines , 
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Triangles" , opt_mesh_color_triangles ,
    PACK_COLOR(153, 143, 255, 255),
    PACK_COLOR(153, 143, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Quadrangles" , opt_mesh_color_quadrangles ,
    PACK_COLOR(182, 92,  255, 255),
    PACK_COLOR(182, 92,  255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Tetrahedra" , opt_mesh_color_tetrahedra ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Hexahedra" , opt_mesh_color_hexahedra ,
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(128, 255, 0,   255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Prisms" , opt_mesh_color_prisms ,
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(0,   255, 128, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Pyramids" , opt_mesh_color_pyramid ,
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(128, 255, 128, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Tangents" , opt_mesh_color_tangents ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "Normals" , opt_mesh_color_normals ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255) },
  { F|O, "One" , opt_mesh_color_1 ,
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(0  , 82 , 138, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Two" , opt_mesh_color_2 ,
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 0  , 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Three" , opt_mesh_color_3 ,
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(31 , 110, 171, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Four" , opt_mesh_color_4 ,
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Five" , opt_mesh_color_5 ,
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Six" , opt_mesh_color_6 ,
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(128, 128, 0  , 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Seven" , opt_mesh_color_7 ,
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(128, 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Eight" , opt_mesh_color_8 ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Nine" , opt_mesh_color_9 ,
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(128, 128, 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { F|O, "Ten" , opt_mesh_color_10 ,
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(0  , 0  , 255, 255),
    PACK_COLOR(255, 255, 255, 255) },
  { 0, NULL , NULL , 0, 0, 0  }
} ;

StringXColor PostProcessingOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 }
} ;

StringXColor ViewOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 }
} ;

StringXColor PrintOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 }
} ;

#undef S
#undef O
#undef F

#endif

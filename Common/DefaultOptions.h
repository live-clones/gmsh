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
  { F, "Display" , opt_general_display , "" ,
    "X server to use (only for Unix versions)" },
  { 0, "SessionFileName" , opt_general_session_filename , ".gmshrc" ,
    "File into which session specific information is saved, and which is read on startup" },
  { F|S, "DefaultFileName" , opt_general_default_filename , "unnamed.geo" ,
    "Default project file name" },
  { F|S, "TmpFileName" , opt_general_tmp_filename , ".gmsh-tmp" ,
    "Temporary file (created in your home directory)" },
  { F|S, "ErrorFileName" , opt_general_error_filename , ".gmsh-errors" ,
    "File into which the log is saved if a fatal error occurs" },
  { F|S, "OptionsFileName" , opt_general_options_filename , ".gmsh-options" ,
    "File created in your home directory with 'Options->Save options', and which is read on startup" },
#ifdef WIN32
  { F|O, "TextEditor" , opt_general_editor , "notepad %s" , 
#else
  { F|O, "TextEditor" , opt_general_editor , "emacs %s &" ,
#endif
    "System command to launch a text editor" },
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString GeometryOptions_String[] = {
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString MeshOptions_String[] = {
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString SolverOptions_String[] = {
#ifdef WIN32
  { F|O, "GetDPCommand" , opt_solver_getdp_command , "./getdp.exe" , 
#else
  { F|O, "GetDPCommand" , opt_solver_getdp_command , "getdp" , 
#endif
    "System command to launch the GetDP solver (should _not_ contain the '&' character)" },
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString PostProcessingOptions_String[] = {
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString ViewOptions_String[] = {
  { F, "Name" , opt_view_name , "" , 
    "Default name to assign to the post-processing view" },
  { F|O, "Format" , opt_view_format , "%.3e" , 
    "Number format (in standard C form)" },
  { F, "FileName" , opt_view_filename , "" , 
    "Default file name to assign to the post-processing view" },
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString PrintOptions_String[] = {
  { F|O, "Font" , opt_print_font , "Courier" , 
    "Font used for postscript printing" },
  { 0, NULL , NULL , NULL , NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { F|O, "InitialModule", opt_general_initial_context, 0. , 
    "Module launched on startup (0=automatic, 1=geometry, 2=mesh, 3=solver, 4=post-processing) " },
  { F|S, "SaveSession" , opt_general_session_save, 1. , 
    "Automatically save session specific information each time you quit Gmsh?" }, 
  { F|S, "SaveOptions" , opt_general_options_save, 0. , 
    "Automatically save all current options each time you quit Gmsh?" }, 
  { F|S, "FontSize" , opt_general_fontsize , 12. , 
    "Size of the font in the graphical user interface" }, 
  { F|S, "GraphicsFontSize" , opt_general_graphics_fontsize , 11. , 
    "Size of the font in the graphic window" }, 
  { F|S, "GraphicsPositionX" , opt_general_graphics_position0 , 20. , 
    "Horizontal position (in pixels) of the upper left corner of the graphic window" }, 
  { F|S, "GraphicsPositionY" , opt_general_graphics_position1 , 30. ,
    "Vertical position (in pixels) of the upper left corner of the graphic window" }, 
  { F|S, "GraphicsWidth" , opt_general_viewport2 , 700. , 
    "Width (in pixels) of the graphic window" }, 
  { F|S, "GraphicsHeight" , opt_general_viewport3 , 500. , 
    "Height (in pixels) of the graphic window" }, 
  { F|S, "MenuPositionX" , opt_general_menu_position0 , 800. , 
    "Horizontal position (in pixels) of the upper left corner of the menu window" }, 
  { F|S, "MenuPositionY" , opt_general_menu_position1 , 50. ,
    "Vertical position (in pixels) of the upper left corner of the menu window" }, 
  { F|S, "MessagePositionX" , opt_general_message_position0 , 650. , 
    "Horizontal position (in pixels) of the upper left corner of the message window" }, 
  { F|S, "MessagePositionY" , opt_general_message_position1 , 150. , 
    "Vertical position (in pixels) of the upper left corner of the message window" }, 
  { F|S, "MessageWidth" , opt_general_message_size0 , 450. , 
    "Width (in pixels) of the message window" }, 
  { F|S, "MessageHeight" , opt_general_message_size1 , 350. , 
    "Height (in pixels) of the message window" }, 
  { F|O, "CenterWindows" , opt_general_center_windows , 1. , 
    "Center new windows on the menu window" }, 
  { F, "RotationX" , opt_general_rotation0 , 0.0 , 
    "First Euler angle (used if Trackball == 0)" }, 
  { F, "RotationY" , opt_general_rotation1 , 0.0 , 
    "Second Euler angle (used if Trackball == 0)" }, 
  { F, "RotationZ" , opt_general_rotation2 , 0.0 , 
    "Third Euler angle (used if Trackball == 0)" }, 
  { F, "TrackballQuaternion0" , opt_general_quaternion0 , 0.0 , 
    "First trackball quaternion component (used if Trackball == 1)" }, 
  { F, "TrackballQuaternion1" , opt_general_quaternion1 , 0.0 , 
    "Second trackball quaternion component (used if Trackball == 1)" }, 
  { F, "TrackballQuaternion2" , opt_general_quaternion2 , 0.0 , 
    "Third trackball quaternion component (used if Trackball == 1)" }, 
  { F, "TrackballQuaternion3" , opt_general_quaternion3 , 1.0 , 
    "Fourth trackball quaternion component (used if Trackball == 1)" }, 
  { F, "TranslationX" , opt_general_translation0 , 0.0 , 
    "X-axis translation (in model units)" },
  { F, "TranslationY" , opt_general_translation1 , 0.0 , 
    "Y-axis translation (in model units)" },
  { F, "TranslationZ" , opt_general_translation2 , 0.0 , 
    "Z-axis translation (in model units)" },
  { F, "ScaleX" , opt_general_scale0 , 1.0 , 
    "X-axis scale factor" },
  { F, "ScaleY" , opt_general_scale1 , 1.0 , 
    "Y-axis scale factor" },
  { F, "ScaleZ" , opt_general_scale2 , 1.0 , 
    "Z-axis scale factor" },
  { F|O, "Shininess" , opt_general_shine , 0.4 , 
    "Material shininess (must be > 0)" },
  { F|O, "ColorScheme", opt_general_color_scheme , 0. ,
    "Default color scheme (0, 1 or 2)" },
#ifdef _BLACKBOX
  { F|O, "Verbosity" , opt_general_verbosity , 0. , 
#else
  { F|O, "Verbosity" , opt_general_verbosity , 2. ,
#endif
    "Level of information printed during processing (0=no information)" },
#ifdef _FLTK
  { F|O, "Terminal" , opt_general_terminal , 0. ,
#else		      
  { F|O, "Terminal" , opt_general_terminal , 1. ,
#endif
    "Should information be printed on the terminal (if available)?" },
  { F|O, "Orthographic" , opt_general_orthographic , 1. ,
    "Orthographic projection mode (0=perspective projection)" },
  { F|O, "FastRedraw" , opt_general_fast_redraw , 1. ,
    "Fast redraw (no mesh or view display) when moving the model" },
  { F|O, "Axes" , opt_general_axes , 1. ,
    "Display the axes linked to the model" },
  { F|O, "SmallAxes" , opt_general_small_axes , 1. ,
    "Display the small axes" },
  { F|O, "DoubleBuffer" , opt_general_double_buffer , 1. ,
    "Use a double buffered graphic window (on Unix, should be set to 0 when working on a remote host without GLX)" },
  { F|O, "DisplayLists" , opt_general_display_lists , 0. ,
    "Use OpenGL display lists (useful with real time manipulation of 'big' post-processing views)" },
  { F|O, "AlphaBlending" , opt_general_alpha_blending , 0. ,
    "Enable alpha blending (transparency) in post-processing views" },
  { F|O, "Trackball" , opt_general_trackball , 1. ,
    "Use trackball rotation mode" },
  { F|O, "ZoomFactor" , opt_general_zoom_factor , 1.1 ,
    "'Speed' of the middle mouse button zoom" },
  { F|O, "DefaultPlugins" , opt_general_default_plugins , 0. ,
    "Load default plugins on startup" },
  { F, "Clip0" , opt_general_clip0 , 0. ,
    "Enable clip plane 0" },
  { F, "Clip0A" , opt_general_clip0a , 0.0 ,
    "First clip plane 0 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip0B" , opt_general_clip0b , 0.0 , 
    "Second clip plane 0 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip0C" , opt_general_clip0c , 0.0 , 
    "Third clip plane 0 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip0D" , opt_general_clip0d , 0.0 , 
    "Fourth clip plane 0 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip1" , opt_general_clip1 , 0.,
    "Enable clip plane 1" },
  { F, "Clip1A" , opt_general_clip1a , 0.0 , 
    "First clip plane 1 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip1B" , opt_general_clip1b , 0.0 , 
    "Second clip plane 1 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip1C" , opt_general_clip1c , 0.0 , 
    "Third clip plane 1 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip1D" , opt_general_clip1d , 0.0 , 
    "Fourth clip plane 1 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip2" , opt_general_clip2 , 0.,
    "Enable clip plane 2" },
  { F, "Clip2A" , opt_general_clip2a , 0.0 , 
    "First clip plane 2 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip2B" , opt_general_clip2b , 0.0 , 
    "Second clip plane 2 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip2C" , opt_general_clip2c , 0.0 , 
    "Third clip plane 2 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip2D" , opt_general_clip2d , 0.0 , 
    "Fourth clip plane 2 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip3" , opt_general_clip3 , 0.,
    "Enable clip plane 3" },
  { F, "Clip3A" , opt_general_clip3a , 0.0 , 
    "First clip plane 3 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip3B" , opt_general_clip3b , 0.0 , 
    "Second clip plane 3 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip3C" , opt_general_clip3c , 0.0 , 
    "Third clip plane 3 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip3D" , opt_general_clip3d , 0.0 , 
    "Fourth clip plane 3 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip4" , opt_general_clip4 , 0.,
    "Enable clip plane 4" },
  { F, "Clip4A" , opt_general_clip4a , 0.0 , 
    "First clip plane 4 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip4B" , opt_general_clip4b , 0.0 , 
    "Second clip plane 4 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip4C" , opt_general_clip4c , 0.0 , 
    "Third clip plane 4 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip4D" , opt_general_clip4d , 0.0 , 
    "Fourth clip plane 4 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip5" , opt_general_clip5 , 0.,
    "Enable clip plane 5" },
  { F, "Clip5A" , opt_general_clip5a , 0.0 , 
    "First clip plane 5 equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip5B" , opt_general_clip5b , 0.0 , 
    "Second clip plane 5 equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip5C" , opt_general_clip5c , 0.0 , 
    "Third clip plane 5 equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "Clip5D" , opt_general_clip5d , 0.0 , 
    "Fourth clip plane 5 equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { F|O, "MovingLight" , opt_general_moving_light , 0. ,
    "Use a moving (i.e. which follows the model) light source" },
  { F|O, "Light0" , opt_general_light0 , 1. ,
    "Enable light source 0" },
  { F|O, "Light0X" , opt_general_light00 , 0.5 ,
    "X position of light source 0" },
  { F|O, "Light0Y" , opt_general_light01 , 0.3 , 
    "Y position of light source 0" },
  { F|O, "Light0Z" , opt_general_light02 , 1.0 , 
    "Z position of light source 0" },
  { F|O, "Light1" , opt_general_light1 , 0.,
    "Enable light source 1" },
  { F|O, "Light1X" , opt_general_light10 , 0.5 , 
    "X position of light source 1" },
  { F|O, "Light1Y" , opt_general_light11 , 0.3 , 
    "Y position of light source 1" },
  { F|O, "Light1Z" , opt_general_light12 , 1.0 , 
    "Z position of light source 1" },
  { F|O, "Light2" , opt_general_light2 , 0.,
    "Enable light source 2" },
  { F|O, "Light2X" , opt_general_light20 , 0.5 , 
    "X position of light source 2" },
  { F|O, "Light2Y" , opt_general_light21 , 0.3 , 
    "Y position of light source 2" },
  { F|O, "Light2Z" , opt_general_light22 , 1.0 , 
    "Z position of light source 2" },
  { F|O, "Light3" , opt_general_light3 , 0.,
    "Enable light source 3" },
  { F|O, "Light3X" , opt_general_light30 , 0.5 , 
    "X position of light source 3" },
  { F|O, "Light3Y" , opt_general_light31 , 0.3 , 
    "Y position of light source 3" },
  { F|O, "Light3Z" , opt_general_light32 , 1.0 , 
    "Z position of light source 3" },
  { F|O, "Light4" , opt_general_light4 , 0.,
    "Enable light source 4" },
  { F|O, "Light4X" , opt_general_light40 , 0.5 , 
    "X position of light source 4" },
  { F|O, "Light4Y" , opt_general_light41 , 0.3 , 
    "Y position of light source 4" },
  { F|O, "Light4Z" , opt_general_light42 , 1.0 , 
    "Z position of light source 4" },
  { F|O, "Light5" , opt_general_light5 , 0.,
    "Enable light source 5" },
  { F|O, "Light5X" , opt_general_light50 , 0.5 , 
    "X position of light source 5" },
  { F|O, "Light5Y" , opt_general_light51 , 0.3 , 
    "Y position of light source 5" },
  { F|O, "Light5Z" , opt_general_light52 , 1.0 , 
    "Z position of light source 5" },
  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber GeometryOptions_Number[] = {
  { F|O, "Normals" , opt_geometry_normals , 0. , 
    "Size of the vectors normal to the surfaces" }, 
  { F|O, "Tangents" , opt_geometry_tangents , 0. ,
    "Size of the vectors tangent to the curves" }, 
  { F|O, "Points" , opt_geometry_points , 1. ,
    "Display geometry points?" },
  { F|O, "Lines" , opt_geometry_lines , 1. , 
    "Display geometry curves?" },
  { F|O, "Surfaces" , opt_geometry_surfaces , 0. , 
    "Display geometry surfaces?" },
  { F|O, "Volumes" , opt_geometry_volumes , 0. , 
    "Display geometry volumes? (not implemented yet)" },
  { F|O, "PointsNumbers" , opt_geometry_points_num , 0. , 
    "Display points numbers?" },
  { F|O, "LinesNumbers" , opt_geometry_lines_num , 0. , 
    "Display curve numbers?" },
  { F|O, "SurfacesNumbers" , opt_geometry_surfaces_num , 0. , 
    "Display surface numbers?" },
  { F|O, "VolumesNumbers" , opt_geometry_volumes_num , 0. , 
    "Display volume numbers? (not implemented yet)" },
  { F|O, "Aspect" , opt_geometry_aspect , 0. , 
    "Not used" },
  { F|O, "Highlight" , opt_geometry_highlight , 1. , 
    "Not used" },
  { F|O, "OldCircle" , opt_geometry_old_circle , 0. , 
    "Use old circle description (compatibility option for old Gmsh geometries)" },
  { F|O, "ScalingFactor" , opt_geometry_scaling_factor , 1.0 , 
    "Global geometry scaling factor" },
  { F|O, "ColorScheme" , opt_geometry_color_scheme , 0. , 
    "Default geometry color scheme (0, 1 or 2)" },
  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber MeshOptions_Number[] = {
  { F|O, "Quality" , opt_mesh_quality , 0.0 ,
    "Target quality for tetrahedral elements (not fully functional)" },
  { F|O, "Normals" , opt_mesh_normals , 0.0 ,
    "Size of the normal vectors" }, 
  { F|O, "Tangents" , opt_mesh_tangents , 0.0 , 
    "Size of the tangent vectors" }, 
  { F|O, "Explode" , opt_mesh_explode , 1.0 ,
    "Display mesh with non adjacent elements (factor between 0 and 1)" },
  { F|O, "ScalingFactor" , opt_mesh_scaling_factor , 1.0 ,
    "Global scaling factor applied to the saved mesh" },
  { F|O, "CharacteristicLengthFactor" , opt_mesh_lc_factor , 1.0 ,
    "Factor applied to all charcteristic lenghts (and background meshes)" },
  { F|O, "RandomFactor" , opt_mesh_rand_factor , 1.e-4 ,
    "Random factor used in 2D and 3D meshing algorithm (test other values when the algorithm fails)" },
  { F|O, "GammaInf" , opt_mesh_gamma_inf , 0.0 , 
    "Only display elements whose Gamma factor is greater than GammaInf" },
  { F|O, "GammaSup" , opt_mesh_gamma_sup , 0.0 , 
    "Only display elements whose Gamma factor is smaller than GammaSup" },
  { F|O, "RadiusInf" , opt_mesh_radius_inf , 0.0 , 
    "Only display elements whose Radius is greater than RadiusInf" },
  { F|O, "RadiusSup" , opt_mesh_radius_sup , 0.0 , 
    "Only display elements whose Radius is smaller than RadiusSup" },
  { F|O, "Points" , opt_mesh_points , 1. , 
    "Display mesh vertices?" },
  { F|O, "Lines" , opt_mesh_lines , 1. , 
    "Display mesh vertices on curves?" },
  { F|O, "Surfaces" , opt_mesh_surfaces , 1. , 
    "Display surface mesh?" },
  { F|O, "Volumes" , opt_mesh_volumes , 1. , 
    "Display volume mesh?" },
  { F|O, "PointsNumbers" , opt_mesh_points_num , 0. , 
    "Display mesh vertices numbers?" },
  { F|O, "LinesNumbers" , opt_mesh_lines_num , 0. , 
    "Display mesh line numbers?" },
  { F|O, "SurfacesNumbers" , opt_mesh_surfaces_num , 0. , 
    "Display mesh surface numbers?" },
  { F|O, "VolumesNumbers" , opt_mesh_volumes_num , 0. , 
    "Display mesh elements numbers?" },
  { F|O, "Aspect" , opt_mesh_aspect , 0. , 
    "Mesh apsect (0=wireframe, 1=hidden lines, 2=solid)" },
  { F|O, "Format" , opt_mesh_format , FORMAT_MSH , 
    "Mesh output format (1=MSH, 2=UNV)" },
  { F|O, "Smoothing" , opt_mesh_nb_smoothing , 0. ,
    "Number of smoothing steps applied to the final mesh" },
  { F|O, "Algorithm" , opt_mesh_algo , DELAUNAY_OLDALGO ,
    "2D mesh algorithm (1=isotropic, 2=anisotropic)" }, 
  { F|O, "PointInsertion" , opt_mesh_point_insertion, CENTER_CIRCCIRC ,
    "Point insertion method for isotropic 2D algorithm (1=center of circ. circle, 2=voronoi, 3=cog)" },
  { F|O, "SpeedMax" , opt_mesh_speed_max , 0. ,
    "Disable dubious point insertion tests" },
  { F|O, "MinimumCirclePoints" , opt_mesh_min_circ_points, 7. ,
    "Minimum number of points used to mesh a circle" },
  { F|O, "ConstrainedBackgroundMesh" , opt_mesh_constrained_bgmesh, 0. ,
    "Should the background mesh be constrained by the characteristic lengths associated with the geometry?" },
  { F|O, "Degree" , opt_mesh_degree , 1. ,
    "Element order" },
  { F|O, "Dual" , opt_mesh_dual , 0. ,
    "Display the dual mesh obtained by barycentric subdivision" },
  { F|O, "Interactive" , opt_mesh_interactive , 0. ,
    "Show the construction of the 2D mesh in real time (only with the anisotropic algorithm)" },
  { F|O, "ColorScheme" , opt_mesh_color_scheme , 0. , 
    "Default mesh color scheme (0, 1 or 2)" },
  { F|O, "ColorCarousel" , opt_mesh_color_carousel , 1. ,
    "Use a 'color by region number' scheme" },
  { F, "use_cut_plane" , opt_mesh_use_cut_plane , 0 ,
    "Enable mesh clip plane" },
  { F, "cut_planea" , opt_mesh_cut_planea , 1. , 
    "First clip plane equation coefficient ('A' in equation 'AX+BY+CZ+D=0')" },
  { F, "cut_planeb" , opt_mesh_cut_planeb , 0. , 
    "Second clip plane equation coefficient ('B' in equation 'AX+BY+CZ+D=0')" },
  { F, "cut_planec" , opt_mesh_cut_planec , 0. , 
    "Third clip plane equation coefficient ('C' in equation 'AX+BY+CZ+D=0')" },
  { F, "cut_planed" , opt_mesh_cut_planed , 0. , 
    "Fourth clip plane equation coefficient ('D' in equation 'AX+BY+CZ+D=0')" },
  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber SolverOptions_Number[] = {
  { F|O, "GetDPPopupMessages" , opt_solver_getdp_popupmessages , 1.0 ,
    "Automatically display GetDP messages" },
  { F|O, "GetDPMergeViews" , opt_solver_getdp_mergeviews , 1.0 , 
    "Automatically merge any post-processing view created by GetDP" },
  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { F|O, "Scales" , opt_post_scales , 1. , 
    "Show value scales" },
  { F|O, "Link" , opt_post_link , 0. ,
    "Link post-processing views (0=no, 1=visible views, 2=all views)" },
  { F|O, "Smoothing" , opt_post_smooth , 0. ,
    "Apply (non-reversible) smoothing to post-processing view when merged" },
  { F|O, "AnimationDelay" , opt_post_anim_delay , 0.25 ,
    "Delay (in seconds) between to animation frames" },
  { F, "NbViews" , opt_post_nb_views , 0. ,
    "Current number of views merged (do _not_ change this!)" },
  { 0, NULL , NULL , 0. }
} ;

StringXNumber ViewOptions_Number[] = {
  { F, "NbTimeStep" , opt_view_nb_timestep , 1. ,
    "Number of time steps in the view (do _not_ change this!)" },
  { F, "TimeStep" , opt_view_timestep , 0. ,
    "Current time step displayed" },
  { F, "Min" , opt_view_min , 1.e200 ,
    "Minimum value in the view (do _not_ change this!)" },
  { F, "Max" , opt_view_max , -1.e200 , 
    "Maximum value in the view (do _not_ change this!)" },
  { F, "CustomMin" , opt_view_custom_min , 0. , 
    "User defined minimum value to be displayed" },
  { F, "CustomMax" , opt_view_custom_max , 0. , 
    "User defined maximum value to be displayed" },
  { F, "OffsetX" , opt_view_offset0 , 0. , 
    "Translation of the view along X-axis (in model coordinates)" },
  { F, "OffsetY" , opt_view_offset1 , 0. , 
    "Translation of the view along Y-axis (in model coordinates)" },
  { F, "OffsetZ" , opt_view_offset2 , 0. , 
    "Translation of the view along Z-axis (in model coordinates)" },
  { F, "RaiseX" , opt_view_raise0 , 0. , 
    "Elevation of the view along X-axis (in model coordinates)" },
  { F, "RaiseY" , opt_view_raise1 , 0. , 
    "Elevation of the view along Y-axis (in model coordinates)" },
  { F, "RaiseZ" , opt_view_raise2 , 0. , 
    "Elevation of the view along Z-axis (in model coordinates)" },
  { F|O, "ArrowScale" , opt_view_arrow_scale , 50. ,
    "Size of the vector (e.g. arrow size in pixels)" },
  { F, "Visible" , opt_view_visible , 1. ,
    "Is the view visible?" },
  { F|O, "IntervalsType" , opt_view_intervals_type , DRAW_POST_ISO ,
    "Type of interval display (1=iso, 2=discrete, 3=continuous, 4=numeric)" },
  { F|O, "NbIso" , opt_view_nb_iso , 15. ,
    "Number of intervals" },
  { F|O, "Light" , opt_view_light , 0. ,
    "Enable light sources?" },
  { F|O, "ShowElement" , opt_view_show_element , 0. ,
    "Show element boundaries?" },
  { F|O, "ShowTime" , opt_view_show_time , 1. ,
    "Show time value (or time step) if NbTimeStep > 1?" },
  { F|O, "ShowScale" , opt_view_show_scale , 1. ,
    "Show value scale?" },
  { F|O, "DrawPoints" , opt_view_draw_points , 1. ,
    "Display post-processing points?" },
  { F|O, "DrawLines" , opt_view_draw_lines , 1. , 
    "Display post-processing lines?" },
  { F|O, "DrawTriangles" , opt_view_draw_triangles , 1. , 
    "Display post-processing triangles?" },
  { F|O, "DrawTetrahedra" , opt_view_draw_tetrahedra , 1. , 
    "Display post-processing tetrahedra?" },
  { F|O, "DrawScalars" , opt_view_draw_scalars , 1. , 
    "Display scalar values?" },
  { F|O, "DrawVectors" , opt_view_draw_vectors , 1. , 
    "Display vector values?" },
  { F|O, "DrawTensors" , opt_view_draw_tensors , 1. , 
    "Display tensor values?" },
  { F|O, "TransparentScale" , opt_view_transparent_scale , 1. ,
    "Display a 'transparent' value scale?" },
  { F|O, "ScaleType" , opt_view_scale_type , DRAW_POST_LINEAR ,
    "Value scale type (1=linear, 2=logarithmic)" },
  { F|O, "RangeType" , opt_view_range_type , DRAW_POST_DEFAULT ,
    "Value scale range type (1=default, 2=custom)" },
  { F|O, "ArrowType" , opt_view_arrow_type , DRAW_POST_ARROW ,
    "Vector display type (1=segment, 2=arrow, 3=pyramid, 4=cone, 5=displacement)" },
  { F|O, "ArrowLocation" , opt_view_arrow_location , DRAW_POST_LOCATE_COG , 
    "Arrow location (1=cog, 2=vertex)" },
  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber PrintOptions_Number[] = {
  { F|O, "Format" , opt_print_format , FORMAT_AUTO , 
    "Print format" }, 
  { F|O, "EpsQuality" , opt_print_eps_quality , 1 ,
    "Postscript quality (1=simple sort, 2=recursive sort)" },
  { F|O, "JpegQuality" , opt_print_jpeg_quality , 85 ,
    "JPEG quality (between 1 and 100)" },
  { F|O, "GifDither" , opt_print_gif_dither , 0 ,
    "Apply dithering to GIF output" },
  { F|O, "GifSort" , opt_print_gif_sort , 1 ,
    "Sort the colormap in GIF output" },
  { F|O, "GifInterlace" , opt_print_gif_interlace , 0 ,
    "Interlace GIF output" },
  { F|O, "GifTransparent" , opt_print_gif_transparent , 0 ,
    "Output transparent GIF image" },
  { F|O, "FontSize" , opt_print_font_size , 12. ,
    "Font size used for postscript printing" },
  { 0, NULL , NULL , 0. }
} ;

// COLORS

StringXColor GeneralOptions_Color[] = {
  { F|O, "Background" , opt_general_color_background ,
    PACK_COLOR(0,   0,   0,   255), 
    PACK_COLOR(255, 255, 255, 255), 
    PACK_COLOR(255, 255, 255, 255), 
    "Background color" },
  { F|O, "Foreground" , opt_general_color_foreground ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Foreground color" },
  { F|O, "Text" , opt_general_color_text ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Text color" },
  { F|O, "Axes" , opt_general_color_axes ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Axes color" },
  { F|O, "SmallAxes" , opt_general_color_small_axes ,
    PACK_COLOR(255, 255, 255, 255),
    PACK_COLOR(0,   0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Small axes color" },
  { 0, NULL , NULL ,  0, 0, 0 , NULL }
} ;

StringXColor GeometryOptions_Color[] = {
  { F|O, "Points" , opt_geometry_color_points , 
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(178, 182, 129, 255) ,
    PACK_COLOR(0,   0,   0,   255), 
    "Normal geometry point color" },
  { F|O, "Lines" , opt_geometry_color_lines ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal geometry curve color" },
  { F|O, "Surfaces" , opt_geometry_color_surfaces ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal geometry surface color" },
  { F|O, "Volumes" , opt_geometry_color_volumes ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal geometry volume color" },
  { F|O, "PointsSelect" , opt_geometry_color_points_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Selected geometry point color" },
  { F|O, "LinesSelect" , opt_geometry_color_lines_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Selected geometry curve color"  },
  { F|O, "SurfacesSelect" , opt_geometry_color_surfaces_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Selected geometry surface color" },
  { F|O, "VolumesSelect" , opt_geometry_color_volumes_select ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Selected geometry volume color" },
  { F|O, "PointsHighlight" , opt_geometry_color_points_highlight ,
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Highlighted geometry point color" },
  { F|O, "LinesHighlight" , opt_geometry_color_lines_highlight ,
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   255, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Highlighted geometry curve color" },
  { F|O, "SurfacesHighlight" , opt_geometry_color_surfaces_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Highlighted geometry surface color" },
  { F|O, "VolumesHighlight" , opt_geometry_color_volumes_highlight ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Highlighted geometry volume color" },
  { F|O, "Tangents" , opt_geometry_color_tangents ,
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(255, 255, 0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Tangent geometry vectors color" },
  { F|O, "Normals" , opt_geometry_color_normals ,
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(255, 0,   0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal geometry vectors color" },
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

#define COL1  PACK_COLOR( 232, 210, 23, 255  )
#define COL2  PACK_COLOR( 226, 167, 29, 255  )
#define COL3  PACK_COLOR( 217, 113, 38, 255  )
#define COL4  PACK_COLOR( 201, 54, 54, 255   )
#define COL5  PACK_COLOR( 169, 12, 86, 255   )
#define COL6  PACK_COLOR( 114, 2, 141, 255   )
#define COL7  PACK_COLOR( 67, 30, 188, 255   )
#define COL8  PACK_COLOR( 44, 86, 211, 255   )
#define COL9  PACK_COLOR( 32, 145, 223, 255  )
#define COL10 PACK_COLOR( 25, 193, 230, 255  )
#define COLW  PACK_COLOR( 255, 255, 255, 255 )
#define COLT  PACK_COLOR( 160, 150, 255, 255 )
#define COLQ  PACK_COLOR( 130, 120, 225, 255 )
#define COLP  PACK_COLOR( 232, 210, 23, 255  )
#define COLY  PACK_COLOR( 217, 113, 38, 255  )

StringXColor MeshOptions_Color[] = {
  { F|O, "Points" , opt_mesh_color_points , 
    PACK_COLOR(0  , 123, 59 , 255),
    PACK_COLOR(0  , 123, 59 , 255),
    PACK_COLOR(0,   0,   0,   255),
    "Mesh vertex color" },
  { F|O, "PointsSupp" , opt_mesh_color_points_supp , 
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(255, 0,   255, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Mesh high order vertex color" },
  { F|O, "Lines" , opt_mesh_color_lines , 
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Mesh line color" },
  { F|O, "Triangles" , opt_mesh_color_triangles , 
    COLT, COLT, COLW, "Mesh triangle color (if ColorCarousel=0)" },
  { F|O, "Quadrangles" , opt_mesh_color_quadrangles ,
    COLQ, COLQ, COLW, "Mesh quadrangle color (if ColorCarousel=0)" },
  { F|O, "Tetrahedra" , opt_mesh_color_tetrahedra ,
    COLT, COLT, COLW, "Mesh tetrahedron color (if ColorCarousel=0)" },
  { F|O, "Hexahedra" , opt_mesh_color_hexahedra ,
    COLQ, COLQ, COLW, "Mesh hexahedron color (if ColorCarousel=0)" },
  { F|O, "Prisms" , opt_mesh_color_prisms ,
    COLP, COLP, COLW, "Mesh prism color (if ColorCarousel=0)" },
  { F|O, "Pyramids" , opt_mesh_color_pyramid ,
    COLY, COLY, COLW, "Mesh pyramid color (if ColorCarousel=0)" },
  { F|O, "Normals" , opt_mesh_color_normals ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal mesh vector color" },
  { F|O, "Tangents" , opt_mesh_color_tangents ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Tangent mesh vector color" },
  { F|O, "One" , opt_mesh_color_1   , COL1, COL1, COLW, "First color in color carousel" },
  { F|O, "Two" , opt_mesh_color_2   , COL2, COL2, COLW, "Second color in color carousel" },
  { F|O, "Three" , opt_mesh_color_3 , COL3, COL3, COLW, "Third color in color carousel" },
  { F|O, "Four" , opt_mesh_color_4  , COL4, COL4, COLW, "Fourth color in color carousel" },
  { F|O, "Five" , opt_mesh_color_5  , COL5, COL5, COLW, "Fifth color in color carousel" },
  { F|O, "Six" , opt_mesh_color_6   , COL6, COL6, COLW, "Sixth color in color carousel" },
  { F|O, "Seven" , opt_mesh_color_7 , COL7, COL7, COLW, "Seventh color in color carousel" },
  { F|O, "Eight" , opt_mesh_color_8 , COL8, COL8, COLW, "Eighth color in color carousel" },
  { F|O, "Nine" , opt_mesh_color_9  , COL9, COL9, COLW, "Nitnth color in color carousel" },
  { F|O, "Ten" , opt_mesh_color_10  , COL10, COL10, COLW,  "tenth color in color carousel" },
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

#undef COL1
#undef COL2
#undef COL3
#undef COL4
#undef COL5
#undef COL6
#undef COL7
#undef COL8
#undef COL9
#undef COL10
#undef COLW

StringXColor SolverOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

StringXColor PostProcessingOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

StringXColor ViewOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

StringXColor PrintOptions_Color[] = {
  { 0, NULL , NULL , 0, 0, 0 , NULL }
} ;

#undef S
#undef O
#undef F

#endif

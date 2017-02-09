// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DEFAULT_OPTIONS_H_
#define _DEFAULT_OPTIONS_H_

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Options.h"

//          PLEASE RESPECT THE ALPHABETICAL ORDER WHEN
//                    INSERTING A NEW OPTION!
//
// Option Database (General, Geometry, Mesh, Post, View, Print), with
// default values. The first number defines the level of saving: O
// for the option file, S for the session file and F for the full
// listing:

#define S GMSH_SESSIONRC
#define O GMSH_OPTIONSRC
#define F GMSH_FULLRC

// STRINGS

StringXString GeneralOptions_String[] = {
  { F|O, "AxesFormatX" , opt_general_axes_format0 , "%.3g" ,
    "Number format for X-axis (in standard C form)" },
  { F|O, "AxesFormatY" , opt_general_axes_format1 , "%.3g" ,
    "Number format for Y-axis (in standard C form)" },
  { F|O, "AxesFormatZ" , opt_general_axes_format2 , "%.3g" ,
    "Number format for Z-axis (in standard C form)" },
  { F|O, "AxesLabelX" , opt_general_axes_label0 , "" ,
    "X-axis label" },
  { F|O, "AxesLabelY" , opt_general_axes_label1 , "" ,
    "Y-axis label" },
  { F|O, "AxesLabelZ" , opt_general_axes_label2 , "" ,
    "Z-axis label" },

  { F|O, "BackgroundImageFileName" , opt_general_background_image_filename , "" ,
    "Background image file in JPEG, PNG or PDF format" },

  { F|O, "DefaultFileName" , opt_general_default_filename , "untitled.geo" ,
    "Default project file name" },
  { F,   "Display" , opt_general_display , "" ,
    "X server to use (only for Unix versions)" },

  { F|O, "ErrorFileName" , opt_general_error_filename ,
#if defined(WIN32)
    "gmsh-errors" ,
#else
    ".gmsh-errors" ,
#endif
    "File into which the log is saved if a fatal error occurs" },
  { F|S, "ExecutableFileName", opt_general_executable_filename , "" ,
    "File name of the Gmsh executable (read-only)"},

  { F,   "FileName" , opt_general_filename , "" ,
    "Current project file name (read-only)" },
  { F|S, "FltkTheme" , opt_general_gui_theme , "" ,
    "FLTK user interface theme (try e.g. plastic or gtk+)" },

  { F|O, "GraphicsFont" , opt_general_graphics_font , "Helvetica" ,
    "Font used in the graphic window" },
  { F|O, "GraphicsFontEngine" , opt_general_graphics_font_engine , "Native" ,
    "Set graphics font engine (Native, Cairo)" },
  { F|O, "GraphicsFontTitle" , opt_general_graphics_font_title , "Helvetica" ,
    "Font used in the graphic window for titles" },

  { F|S, "OptionsFileName" , opt_general_options_filename ,
#if defined(WIN32)
    "gmsh-options" ,
#else
    ".gmsh-options" ,
#endif
    "Option file created with `Tools->Options->Save'; automatically read on startup" },

  { F|S, "RecentFile0", opt_general_recent_file0 , "untitled.geo" ,
    "Most recent opened file"},
  { F|S, "RecentFile1", opt_general_recent_file1 , "untitled.geo" ,
    "2nd most recent opened file"},
  { F|S, "RecentFile2", opt_general_recent_file2 , "untitled.geo" ,
    "3rd most recent opened file"},
  { F|S, "RecentFile3", opt_general_recent_file3 , "untitled.geo" ,
    "4th most recent opened file"},
  { F|S, "RecentFile4", opt_general_recent_file4 , "untitled.geo" ,
    "5th most recent opened file"},
  { F|S, "RecentFile5", opt_general_recent_file5 , "untitled.geo" ,
    "6th most recent opened file"},
  { F|S, "RecentFile6", opt_general_recent_file6 , "untitled.geo" ,
    "7th most recent opened file"},
  { F|S, "RecentFile7", opt_general_recent_file7 , "untitled.geo" ,
    "8th most recent opened file"},
  { F|S, "RecentFile8", opt_general_recent_file8 , "untitled.geo" ,
    "9th most recent opened file"},
  { F|S, "RecentFile9", opt_general_recent_file9 , "untitled.geo" ,
    "10th most recent opened file"},

  { 0,   "SessionFileName" , opt_general_session_filename ,
#if defined(WIN32)
    "gmshrc" ,
#else
    ".gmshrc" ,
#endif
    "Option file into which session specific information is saved; automatically "
    "read on startup" },

  { F|O, "TextEditor" , opt_general_editor ,
#if defined(WIN32)
    "notepad.exe %s" ,
#elif defined(__APPLE__)
    "open -t %s" ,
#else
    "gedit %s" ,
#endif
    "System command to launch a text editor" },
  { F|S, "TmpFileName" , opt_general_tmp_filename ,
#if defined(WIN32)
    "gmsh-tmp" ,
#else
    ".gmsh-tmp" ,
#endif
    "Temporary file used by the geometry module" },

  { F, "WatchFilePattern", opt_general_watch_file_pattern , "" ,
     "Pattern of files to merge as they become available"},

   { 0, 0 , 0 , "" , 0 }
} ;

StringXString GeometryOptions_String[] = {
  { F|O, "DoubleClickedPointCommand" , opt_geometry_double_clicked_point_command, "" ,
    "Command parsed when double-clicking on a point" },
  { F|O, "DoubleClickedLineCommand" , opt_geometry_double_clicked_line_command, "" ,
    "Command parsed when double-clicking on a line" },
  { F|O, "DoubleClickedSurfaceCommand" , opt_geometry_double_clicked_surface_command, "" ,
    "Command parsed when double-clicking on a surface" },
  { F|O, "DoubleClickedVolumeCommand" , opt_geometry_double_clicked_volume_command, "" ,
    "Command parsed when double-clicking on a volume" },

  { 0, 0 , 0 , "" , 0 }
} ;

StringXString MeshOptions_String[] = {
  { 0, 0 , 0 , "" , 0 }
} ;

StringXString SolverOptions_String[] = {
  { F|S, "Executable0" , opt_solver_executable0 , "",
    "System command to launch solver 0" },
  { F|S, "Executable1" , opt_solver_executable1 , "" ,
    "System command to launch solver 1" },
  { F|S, "Executable2" , opt_solver_executable2 , "" ,
    "System command to launch solver 2" },
  { F|S, "Executable3" , opt_solver_executable3 , "" ,
    "System command to launch solver 3" },
  { F|S, "Executable4" , opt_solver_executable4 , "" ,
    "System command to launch solver 4" },
  { F|S, "Executable5" , opt_solver_executable5 , "",
    "System command to launch solver 5" },
  { F|S, "Executable6" , opt_solver_executable6 , "" ,
    "System command to launch solver 6" },
  { F|S, "Executable7" , opt_solver_executable7 , "" ,
    "System command to launch solver 7" },
  { F|S, "Executable8" , opt_solver_executable8 , "" ,
    "System command to launch solver 8" },
  { F|S, "Executable9" , opt_solver_executable9 , "" ,
    "System command to launch solver 9" },

  { F|S, "Name0" , opt_solver_name0 , "GetDP" ,
    "Name of solver 0" },
  { F|S, "Name1" , opt_solver_name1 , "" ,
    "Name of solver 1" },
  { F|S, "Name2" , opt_solver_name2 , "" ,
    "Name of solver 2" },
  { F|S, "Name3" , opt_solver_name3 , "" ,
    "Name of solver 3" },
  { F|S, "Name4" , opt_solver_name4 , "" ,
    "Name of solver 4" },
  { F|S, "Name5" , opt_solver_name5 , "" ,
    "Name of solver 5" },
  { F|S, "Name6" , opt_solver_name6 , "" ,
    "Name of solver 6" },
  { F|S, "Name7" , opt_solver_name7 , "" ,
    "Name of solver 7" },
  { F|S, "Name8" , opt_solver_name8 , "" ,
    "Name of solver 8" },
  { F|S, "Name9" , opt_solver_name9 , "" ,
    "Name of solver 9" },

  { F|S, "Extension0" , opt_solver_extension0 , ".pro" ,
    "File extension for solver 0" },
  { F|S, "Extension1" , opt_solver_extension1 , "" ,
    "File extension for solver 1" },
  { F|S, "Extension2" , opt_solver_extension2 , "" ,
    "File extension for solver 2" },
  { F|S, "Extension3" , opt_solver_extension3 , "" ,
    "File extension for solver 3" },
  { F|S, "Extension4" , opt_solver_extension4 , "" ,
    "File extension for solver 4" },
  { F|S, "Extension5" , opt_solver_extension5 , "" ,
    "File extension for solver 5" },
  { F|S, "Extension6" , opt_solver_extension6 , "" ,
    "File extension for solver 6" },
  { F|S, "Extension7" , opt_solver_extension7 , "" ,
    "File extension for solver 7" },
  { F|S, "Extension8" , opt_solver_extension8 , "" ,
    "File extension for solver 8" },
  { F|S, "Extension9" , opt_solver_extension9 , "" ,
    "File extension for solver 9" },

  { F|S, "OctaveInterpreter" , opt_solver_octave_interpreter , "octave" ,
    "Name of the Octave interpreter (used to run .m files)" },
  { F|S, "PythonInterpreter" , opt_solver_python_interpreter , "python" ,
    "Name of the Python interpreter (used to run .py files if they are not executable)" },

  { F|S, "RemoteLogin0" , opt_solver_remote_login0 , "",
    "Command to login to a remote host to launch solver 0" },
  { F|S, "RemoteLogin1" , opt_solver_remote_login1 , "" ,
    "Command to login to a remote host to launch solver 1" },
  { F|S, "RemoteLogin2" , opt_solver_remote_login2 , "" ,
    "Command to login to a remote host to launch solver 2" },
  { F|S, "RemoteLogin3" , opt_solver_remote_login3 , "" ,
    "Command to login to a remote host to launch solver 3" },
  { F|S, "RemoteLogin4" , opt_solver_remote_login4 , "" ,
    "Command to login to a remote host to launch solver 4" },
  { F|S, "RemoteLogin5" , opt_solver_remote_login5 , "",
    "Command to login to a remote host to launch solver 5" },
  { F|S, "RemoteLogin6" , opt_solver_remote_login6 , "" ,
    "Command to login to a remote host to launch solver 6" },
  { F|S, "RemoteLogin7" , opt_solver_remote_login7 , "" ,
    "Command to login to a remote host to launch solver 7" },
  { F|S, "RemoteLogin8" , opt_solver_remote_login8 , "" ,
    "Command to login to a remote host to launch solver 8" },
  { F|S, "RemoteLogin9" , opt_solver_remote_login9 , "" ,
    "Command to login to a remote host to launch solver 9" },

  { F|O, "SocketName" , opt_solver_socket_name ,
#if defined(WIN32) && !defined(__CYGWIN__)
    "127.0.0.1:0" , // use TCP/IP sockets by default on Windows
#else
    ".gmshsock" , // otherwise use Unix sockets by default
#endif
    "Base name of socket (UNIX socket if the name does not contain a colon, TCP/IP "
    "otherwise, in the form 'host:baseport'; the actual name/port is constructed "
    "by appending the unique client id. If baseport is 0 or is not provided, the "
    "port is chosen automatically (recommended))"},

  { 0, 0 , 0 , "" , 0 }
} ;

StringXString PostProcessingOptions_String[] = {
  { F|O, "DoubleClickedGraphPointCommand" , opt_post_double_clicked_graph_point_command, "" ,
    "Command parsed when double-clicking on a graph data point "
    "(e.g. Merge Sprintf('file_%g.pos', PostProcessing.GraphPointX);)" },

  { F|O, "GraphPointCommand" , opt_post_double_clicked_graph_point_command, "" ,
    "Synonym for `DoubleClickedGraphPointCommand'" },

  { 0, 0 , 0 , "" , 0 }
} ;

StringXString ViewOptions_String[] = {
  { F|O, "Attributes" , opt_view_attributes , "" ,
    "Optional string attributes" },
  { F|O, "AxesFormatX" , opt_view_axes_format0 , "%.3g" ,
    "Number format for X-axis (in standard C form)" },
  { F|O, "AxesFormatY" , opt_view_axes_format1 , "%.3g" ,
    "Number format for Y-axis (in standard C form)" },
  { F|O, "AxesFormatZ" , opt_view_axes_format2 , "%.3g" ,
    "Number format for Z-axis (in standard C form)" },
  { F|O, "AxesLabelX" , opt_view_axes_label0 , "" ,
    "X-axis label" },
  { F|O, "AxesLabelY" , opt_view_axes_label1 , "" ,
    "Y-axis label" },
  { F|O, "AxesLabelZ" , opt_view_axes_label2 , "" ,
    "Z-axis label" },

  { F|O, "DoubleClickedCommand" , opt_view_double_clicked_command , "" ,
    "Command parsed when double-clicking on the view" },

  { F,   "FileName" , opt_view_filename , "" ,
    "Default post-processing view file name" },
  { F|O, "Format" , opt_view_format , "%.3g" ,
    "Number format (in standard C form)" },

  { F|O, "GeneralizedRaiseX" , opt_view_gen_raise0 , "v0" ,
    "Generalized elevation of the view along X-axis (in model coordinates, "
    "using formula possibly containing x, y, z, s[tep], t[ime], v0, ... v8)" },
  { F|O, "GeneralizedRaiseY" , opt_view_gen_raise1 , "v1" ,
    "Generalized elevation of the view along Y-axis (in model coordinates, "
    "using formula possibly containing x, y, z, s[tep], t[ime], v0, ... v8)" },
  { F|O, "GeneralizedRaiseZ" , opt_view_gen_raise2 , "v2" ,
    "Generalized elevation of the view along Z-axis (in model coordinates, "
    "using formula possibly containing x, y, z, s[tep], t[ime], v0, ... v8)" },
  { F|O, "Group" , opt_view_group , "" ,
    "Group to which this view belongs" },

  { F,   "Name" , opt_view_name , "" ,
    "Default post-processing view name" },

  { F|O, "Stipple0" , opt_view_stipple0 , "1*0x1F1F" ,
    "First stippling pattern" },
  { F|O, "Stipple1" , opt_view_stipple1 , "1*0x3333" ,
    "Second stippling pattern" },
  { F|O, "Stipple2" , opt_view_stipple2 , "1*0x087F" ,
    "Third stippling pattern" },
  { F|O, "Stipple3" , opt_view_stipple3 , "1*0xCCCF" ,
    "Fourth stippling pattern" },
  { F|O, "Stipple4" , opt_view_stipple4 , "2*0x1111" ,
    "Fifth stippling pattern" },
  { F|O, "Stipple5" , opt_view_stipple5 , "2*0x0F0F" ,
    "Sixth stippling pattern" },
  { F|O, "Stipple6" , opt_view_stipple6 , "1*0xCFFF" ,
    "Seventh stippling pattern" },
  { F|O, "Stipple7" , opt_view_stipple7 , "2*0x0202" ,
    "Eighth stippling pattern" },
  { F|O, "Stipple8" , opt_view_stipple8 , "2*0x087F" ,
    "Ninth stippling pattern" },
  { F|O, "Stipple9" , opt_view_stipple9 , "1*0xFFFF" ,
    "Tenth stippling pattern" },

  { 0, 0 , 0 , "" , 0 }
} ;

StringXString PrintOptions_String[] = {
  { F|O, "ParameterCommand" , opt_print_parameter_command ,
    "Mesh.Clip=1; View.Clip=1; General.ClipWholeElements=1; "
    "General.Clip0D=Print.Parameter; SetChanged;" ,
    "Command parsed when the print parameter is changed" },

  { 0, 0 , 0 , "" , 0 }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { F|O, "AlphaBlending" , opt_general_alpha_blending , 1. ,
    "Enable alpha blending (transparency) in post-processing views" },
  { F|O, "Antialiasing" , opt_general_antialiasing , 0. ,
    "Use multisample antialiasing (will slow down rendering)" },
  { F|O, "ArrowHeadRadius" , opt_general_arrow_head_radius , 0.12 ,
    "Relative radius of arrow head" },
  { F|O, "ArrowStemLength" , opt_general_arrow_stem_length , 0.56 ,
    "Relative length of arrow stem" },
  { F|O, "ArrowStemRadius" , opt_general_arrow_stem_radius , 0.02 ,
    "Relative radius of arrow stem" },
  { F|O, "Axes" , opt_general_axes , 0. ,
    "Axes (0=none, 1=simple axes, 2=box, 3=full grid, 4=open grid, 5=ruler)" },
  { F|O, "AxesMikado" , opt_general_axes_mikado , 0. ,
    "Mikado axes style" },
  { F|O, "AxesAutoPosition" , opt_general_axes_auto_position , 1. ,
    "Position the axes automatically" },
  { F|O, "AxesForceValue" , opt_general_axes_force_value , 0. ,
    "Force values on axes (otherwise use natural coordinates)" },
  { F|O, "AxesMaxX" , opt_general_axes_xmax , 1. ,
    "Maximum X-axis coordinate" },
  { F|O, "AxesMaxY" , opt_general_axes_ymax , 1. ,
    "Maximum Y-axis coordinate" },
  { F|O, "AxesMaxZ" , opt_general_axes_zmax , 1. ,
    "Maximum Z-axis coordinate" },
  { F|O, "AxesMinX" , opt_general_axes_xmin , 0. ,
    "Minimum X-axis coordinate" },
  { F|O, "AxesMinY" , opt_general_axes_ymin , 0. ,
    "Minimum Y-axis coordinate" },
  { F|O, "AxesMinZ" , opt_general_axes_zmin , 0. ,
    "Minimum Z-axis coordinate" },
  { F|O, "AxesTicsX" , opt_general_axes_tics0 , 5. ,
    "Number of tics on the X-axis" },
  { F|O, "AxesTicsY" , opt_general_axes_tics1 , 5. ,
    "Number of tics on the Y-axis" },
  { F|O, "AxesTicsZ" , opt_general_axes_tics2 , 5. ,
    "Number of tics on the Z-axis" },
  { F|O, "AxesValueMaxX" , opt_general_axes_value_xmax , 1. ,
    "Maximum X-axis forced value" },
  { F|O, "AxesValueMaxY" , opt_general_axes_value_ymax , 1. ,
    "Maximum Y-axis forced value" },
  { F|O, "AxesValueMaxZ" , opt_general_axes_value_zmax , 1. ,
    "Maximum Z-axis forced value" },
  { F|O, "AxesValueMinX" , opt_general_axes_value_xmin , 0. ,
    "Minimum X-axis forced value" },
  { F|O, "AxesValueMinY" , opt_general_axes_value_ymin , 0. ,
    "Minimum Y-axis forced value" },
  { F|O, "AxesValueMinZ" , opt_general_axes_value_zmin , 0. ,
    "Minimum Z-axis forced value" },

  { F|O, "BackgroundGradient" , opt_general_background_gradient , 1. ,
    "Draw background gradient (0=none, 1=vertical, 2=horizontal, 3=radial)" },
  { F|O, "BackgroundImage3D" , opt_general_background_image_3d , 0 ,
    "Create background image in the 3D model (units = model units) or as "
    "2D background (units = pixels)" },
  { F|O, "BackgroundImagePage" , opt_general_background_image_page , 0 ,
    "Page to render in the background image (for multi-page PDFs)" },
  { F|O, "BackgroundImagePositionX" , opt_general_background_image_position0 , 0 ,
    "X position of background image (for 2D background: < 0: measure from right window edge; "
    ">= 1e5: centered)" },
  { F|O, "BackgroundImagePositionY" , opt_general_background_image_position1 , 0 ,
    "Y position of background image (for 2D background: < 0: measure from bottom window edge; "
    ">= 1e5: centered)" },
  { F|O, "BackgroundImageWidth" , opt_general_background_image_size0 , -1. ,
    "Width of background image (0: actual width if height = 0, natural scaling if not; "
    "-1: graphic window width)" },
  { F|O, "BackgroundImageHeight" , opt_general_background_image_size1 , -1 ,
    "Height of background image (0: actual height if width = 0, natural scaling if not; "
    "-1: graphic window height)" },
  { F|O, "BoundingBoxSize" , opt_general_lc, 1. ,
    "Overall bounding box size (read-only)" },

  { F|O, "Camera" , opt_general_camera_mode, 0. ,
    "Enable camera view mode" },
  { F|O, "CameraAperture" , opt_general_camera_aperture, 40. ,
    "Camera aperture in degrees" },
  { F|O, "CameraEyeSeparationRatio" , opt_general_eye_sep_ratio, 1.5 ,
    "Eye separation ratio in % for stereo rendering" },
  { F|O, "CameraFocalLengthRatio" , opt_general_focallength_ratio, 1.0 ,
    "Camera Focal length ratio" },
  { F,   "Clip0A" , opt_general_clip0a , 1.0 ,
    "First coefficient in equation for clipping plane 0 (`A' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0B" , opt_general_clip0b , 0.0 ,
    "Second coefficient in equation for clipping plane 0 (`B' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0C" , opt_general_clip0c , 0.0 ,
    "Third coefficient in equation for clipping plane 0 (`C' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0D" , opt_general_clip0d , 0.0 ,
    "Fourth coefficient in equation for clipping plane 0 (`D' in `AX+BY+CZ+D=0')" },
  { F,   "Clip1A" , opt_general_clip1a , 0.0 ,
    "First coefficient in equation for clipping plane 1" },
  { F,   "Clip1B" , opt_general_clip1b , 1.0 ,
    "Second coefficient in equation for clipping plane 1" },
  { F,   "Clip1C" , opt_general_clip1c , 0.0 ,
    "Third coefficient in equation for clipping plane 1" },
  { F,   "Clip1D" , opt_general_clip1d , 0.0 ,
    "Fourth coefficient in equation for clipping plane 1" },
  { F,   "Clip2A" , opt_general_clip2a , 0.0 ,
    "First coefficient in equation for clipping plane 2" },
  { F,   "Clip2B" , opt_general_clip2b , 0.0 ,
    "Second coefficient in equation for clipping plane 2" },
  { F,   "Clip2C" , opt_general_clip2c , 1.0 ,
    "Third coefficient in equation for clipping plane 2" },
  { F,   "Clip2D" , opt_general_clip2d , 0.0 ,
    "Fourth coefficient in equation for clipping plane 2" },
  { F,   "Clip3A" , opt_general_clip3a , -1.0 ,
    "First coefficient in equation for clipping plane 3" },
  { F,   "Clip3B" , opt_general_clip3b , 0.0 ,
    "Second coefficient in equation for clipping plane 3" },
  { F,   "Clip3C" , opt_general_clip3c , 0.0 ,
    "Third coefficient in equation for clipping plane 3" },
  { F,   "Clip3D" , opt_general_clip3d , 1.0 ,
    "Fourth coefficient in equation for clipping plane 3" },
  { F,   "Clip4A" , opt_general_clip4a , 0.0 ,
    "First coefficient in equation for clipping plane 4" },
  { F,   "Clip4B" , opt_general_clip4b , -1.0 ,
    "Second coefficient in equation for clipping plane 4" },
  { F,   "Clip4C" , opt_general_clip4c , 0.0 ,
    "Third coefficient in equation for clipping plane 4" },
  { F,   "Clip4D" , opt_general_clip4d , 1.0 ,
    "Fourth coefficient in equation for clipping plane 4" },
  { F,   "Clip5A" , opt_general_clip5a , 0.0 ,
    "First coefficient in equation for clipping plane 5" },
  { F,   "Clip5B" , opt_general_clip5b , 0.0 ,
    "Second coefficient in equation for clipping plane 5" },
  { F,   "Clip5C" , opt_general_clip5c , -1.0 ,
    "Third coefficient in equation for clipping plane 5" },
  { F,   "Clip5D" , opt_general_clip5d , 1.0 ,
    "Fourth coefficient in equation for clipping plane 5" },
  { F,   "ClipFactor" , opt_general_clip_factor , 5.0 ,
    "Near and far clipping plane distance factor (decrease value for better "
    "z-buffer resolution)" },
  { F|O, "ClipOnlyDrawIntersectingVolume" ,
    opt_general_clip_only_draw_intersecting_volume , 0. ,
    "Only draw layer of elements that intersect the clipping plane" },
  { F|O, "ClipOnlyVolume" , opt_general_clip_only_volume , 0. ,
    "Only clip volume elements" },
  { F|S, "ClipPositionX" , opt_general_clip_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the clipping "
    "planes window" },
  { F|S, "ClipPositionY" , opt_general_clip_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the clipping "
    "planes window" },
  { F|O, "ClipWholeElements" , opt_general_clip_whole_elements , 0. ,
    "Clip whole elements" },
  { F|S, "ColorScheme", opt_general_color_scheme , 1. ,
    "Default color scheme for graphics (0=dark, 1=light, 2=grayscale, 3=reverse)" },
  { F|O, "ConfirmOverwrite" , opt_general_confirm_overwrite, 1. ,
    "Ask confirmation before overwriting files?" },
  { F|S, "ContextPositionX" , opt_general_context_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the contextual "
    "windows" },
  { F|S, "ContextPositionY" , opt_general_context_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the contextual "
    "windows" },

  { F|S, "DetachedMenu" , opt_general_detached_menu , 0. ,
    "Should the menu window be detached from the graphic window?" },
  { F|O, "DisplayBorderFactor" , opt_general_display_border_factor , 0.2 ,
    "Border factor for model display (0: model fits window size exactly)" },
  { F|O, "DoubleBuffer" , opt_general_double_buffer , 1. ,
    "Use a double buffered graphic window (on Unix, should be set to 0 when "
    "working on a remote host without GLX)" },
  { F|O, "DrawBoundingBoxes" , opt_general_draw_bounding_box, 0. ,
    "Draw bounding boxes" },

  { F|O, "ExpertMode" , opt_general_expert_mode, 0. ,
    "Enable expert mode (to disable all the messages meant for inexperienced "
    "users)" },
  { F|S, "ExtraPositionX" , opt_general_extra_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the generic extra window" },
  { F|S, "ExtraPositionY" , opt_general_extra_position1 , 350. ,
    "Vertical position (in pixels) of the upper left corner of the generic extra window" },
  { F|S, "ExtraHeight" , opt_general_extra_size1 , 100. ,
    "Height (in pixels) of the generic extra window" },
  { F|S, "ExtraWidth" , opt_general_extra_size0 , 100. ,
    "Width (in pixels) of the generic extra window" },

 { F|O, "FastRedraw" , opt_general_fast_redraw, 0. ,
    "Draw simplified model while rotating, panning and zooming" },
  { F|S, "FieldPositionX" , opt_general_field_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the field window" },
  { F|S, "FieldPositionY" , opt_general_field_position1 , 550. ,
    "Vertical position (in pixels) of the upper left corner of the field window" },
  { F|S, "FieldHeight" , opt_general_field_size1 , 320. ,
    "Height (in pixels) of the field window" },
  { F|S, "FieldWidth" , opt_general_field_size0 , 420. ,
    "Width (in pixels) of the field window" },
  { F|S, "FileChooserPositionX" , opt_general_file_chooser_position0 , 200. ,
    "Horizontal position (in pixels) of the upper left corner of the file chooser "
    "windows" },
  { F|S, "FileChooserPositionY" , opt_general_file_chooser_position1 , 200. ,
    "Vertical position (in pixels) of the upper left corner of the file chooser "
    "windows" },
  { F|S, "FltkColorScheme" , opt_general_gui_color_scheme , 0. ,
    "FLTK user interface color theme (0: standard, 1:dark)" },
  { F|O, "FontSize" , opt_general_fontsize , -1. ,
    "Size of the font in the user interface, in pixels (-1: automatic)" },

  { F|O, "GraphicsFontSize" , opt_general_graphics_fontsize , 15. ,
    "Size of the font in the graphic window, in pixels" },
  { F|O, "GraphicsFontSizeTitle" , opt_general_graphics_fontsize_title , 18. ,
    "Size of the font in the graphic window for titles, in pixels" },
  { F|S, "GraphicsHeight" , opt_general_graphics_size1 , 600. ,
    "Height (in pixels) of the graphic window" },
  { F|S, "GraphicsPositionX" , opt_general_graphics_position0 , 50. ,
    "Horizontal position (in pixels) of the upper left corner of the graphic "
    "window" },
  { F|S, "GraphicsPositionY" , opt_general_graphics_position1 , 50. ,
    "Vertical position (in pixels) of the upper left corner of the graphic "
    "window" },
  { F|S, "GraphicsWidth" , opt_general_graphics_size0 , 800. ,
    "Width (in pixels) of the graphic window" },

  { F|S, "HighOrderToolsPositionX" , opt_general_hot_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the high order "
    "tools window" },
  { F|S, "HighOrderToolsPositionY" , opt_general_hot_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the high order "
    "tools window" },
  { F|O, "HighResolutionGraphics" , opt_general_high_resolution_graphics , 1. ,
    "Use high-resolution OpenGL graphics (e.g. for Macs with retina displays)" },
  { F|O, "HighResolutionPointSizeFactor" , opt_general_high_resolution_point_size_factor , 2. ,
    "Point size factor when using high-resolution OpenGL graphics" },

  { F|O, "InitialModule", opt_general_initial_context, 0. ,
    "Module launched on startup (0=automatic, 1=geometry, 2=mesh, 3=solver, "
    "4=post-processing) " },

  { F|O, "Light0" , opt_general_light0 , 1. ,
    "Enable light source 0" },
  { F|O, "Light0X" , opt_general_light00 , 0.65 ,
    "X position of light source 0" },
  { F|O, "Light0Y" , opt_general_light01 , 0.65 ,
    "Y position of light source 0" },
  { F|O, "Light0Z" , opt_general_light02 , 1.0 ,
    "Z position of light source 0" },
  { F|O, "Light0W" , opt_general_light03 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 0 (W=0 means "
    "infinitely far source)" },
  { F|O, "Light1" , opt_general_light1 , 0.,
    "Enable light source 1" },
  { F|O, "Light1X" , opt_general_light10 , 0.5 ,
    "X position of light source 1" },
  { F|O, "Light1Y" , opt_general_light11 , 0.3 ,
    "Y position of light source 1" },
  { F|O, "Light1Z" , opt_general_light12 , 1.0 ,
    "Z position of light source 1" },
  { F|O, "Light1W" , opt_general_light13 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 1 (W=0 means infinitely "
    "far source)" },
  { F|O, "Light2" , opt_general_light2 , 0.,
    "Enable light source 2" },
  { F|O, "Light2X" , opt_general_light20 , 0.5 ,
    "X position of light source 2" },
  { F|O, "Light2Y" , opt_general_light21 , 0.3 ,
    "Y position of light source 2" },
  { F|O, "Light2Z" , opt_general_light22 , 1.0 ,
    "Z position of light source 2" },
  { F|O, "Light2W" , opt_general_light23 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 2 (W=0 means infinitely "
    "far source)" },
  { F|O, "Light3" , opt_general_light3 , 0.,
    "Enable light source 3" },
  { F|O, "Light3X" , opt_general_light30 , 0.5 ,
    "X position of light source 3" },
  { F|O, "Light3Y" , opt_general_light31 , 0.3 ,
    "Y position of light source 3" },
  { F|O, "Light3Z" , opt_general_light32 , 1.0 ,
    "Z position of light source 3" },
  { F|O, "Light3W" , opt_general_light33 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 3 (W=0 means infinitely "
    "far source)" },
  { F|O, "Light4" , opt_general_light4 , 0.,
    "Enable light source 4" },
  { F|O, "Light4X" , opt_general_light40 , 0.5 ,
    "X position of light source 4" },
  { F|O, "Light4Y" , opt_general_light41 , 0.3 ,
    "Y position of light source 4" },
  { F|O, "Light4Z" , opt_general_light42 , 1.0 ,
    "Z position of light source 4" },
  { F|O, "Light4W" , opt_general_light43 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 4 (W=0 means infinitely "
    "far source)" },
  { F|O, "Light5" , opt_general_light5 , 0.,
    "Enable light source 5" },
  { F|O, "Light5X" , opt_general_light50 , 0.5 ,
    "X position of light source 5" },
  { F|O, "Light5Y" , opt_general_light51 , 0.3 ,
    "Y position of light source 5" },
  { F|O, "Light5Z" , opt_general_light52 , 1.0 ,
    "Z position of light source 5" },
  { F|O, "Light5W" , opt_general_light53 , 0.0 ,
    "Divisor of the X, Y and Z coordinates of light source 5 (W=0 means infinitely "
    "far source)" },
  { F|O, "LineWidth" , opt_general_line_width , 1.0 ,
    "Display width of lines (in pixels)" },

  { F|S, "ManipulatorPositionX" , opt_general_manip_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the manipulator "
    "window" },
  { F|S, "ManipulatorPositionY" , opt_general_manip_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the manipulator "
    "window" },
  { F,   "MaxX" , opt_general_xmax , 0. ,
    "Maximum model coordinate along the X-axis (read-only)" },
  { F,   "MaxY" , opt_general_ymax , 0. ,
    "Maximum model coordinate along the Y-axis (read-only)" },
  { F,   "MaxZ" , opt_general_zmax , 0. ,
    "Maximum model coordinate along the Z-axis (read-only)" },
  { F|S, "MenuWidth" , opt_general_menu_size0 , 200. ,
    "Width (in pixels) of the menu tree" },
  { F|S, "MenuHeight" , opt_general_menu_size1 , 200. ,
    "Height (in pixels) of the (detached) menu tree" },
  { F|S, "MenuPositionX" , opt_general_menu_position0 , 400. ,
    "Horizontal position (in pixels) of the (detached) menu tree" },
  { F|S, "MenuPositionY" , opt_general_menu_position1 , 400. ,
    "Vertical position (in pixels) of the (detached) menu tree" },
  { F|O, "MeshDiscrete" , opt_general_meshdiscrete , 0. ,
    "Mesh discrete surfaces through automatic parametrization (MUMPS required for efficiency) (0)" },
  { F|O, "MessageFontSize" , opt_general_message_fontsize , -1. ,
    "Size of the font in the message window, in pixels (-1: automatic)" },
  { F|S, "MessageHeight" , opt_general_message_size , 300. ,
    "Height (in pixels) of the message console when it is visible (should be > 0)" },
  { F,   "MinX" , opt_general_xmin , 0. ,
    "Minimum model coordinate along the X-axis (read-only)" },
  { F,   "MinY" , opt_general_ymin , 0. ,
    "Minimum model coordinate along the Y-axis (read-only)" },
  { F,   "MinZ" , opt_general_zmin , 0. ,
    "Minimum model coordinate along the Z-axis (read-only)" },
  { F|O, "MouseHoverMeshes" , opt_general_mouse_hover_meshes , 0. ,
    "Enable mouse hover on meshes" },
  { F|O, "MouseSelection" , opt_general_mouse_selection , 1. ,
    "Enable mouse selection" },

  { F|S, "NonModalWindows" , opt_general_non_modal_windows , 1. ,
    "Force all control windows to be on top of the graphic window "
    "(\"non-modal\")" },
  { F|O, "NoPopup" , opt_general_nopopup , 0. ,
    "Disable interactive dialog windows in scripts (and use default values "
    "instead)" },

  { F|S, "OptionsPositionX" , opt_general_option_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the option "
    "window" },
  { F|S, "OptionsPositionY" , opt_general_option_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the option window" },
  { F|O, "Orthographic" , opt_general_orthographic , 1. ,
    "Orthographic projection mode (0=perspective projection)" },

  { F|S, "PluginPositionX" , opt_general_plugin_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the plugin "
    "window" },
  { F|S, "PluginPositionY" , opt_general_plugin_position1 , 550. ,
    "Vertical position (in pixels) of the upper left corner of the plugin window" },
  { F|S, "PluginHeight" , opt_general_plugin_size1 , 320. ,
    "Height (in pixels) of the plugin window" },
  { F|S, "PluginWidth" , opt_general_plugin_size0 , 420. ,
    "Width (in pixels) of the plugin window" },
  { F|O, "PointSize" , opt_general_point_size , 3. ,
    "Display size of points (in pixels)" },
  { F|O, "PolygonOffsetAlwaysOn" , opt_general_polygon_offset_always , 0. ,
    "Always apply polygon offset, instead of trying to detect when it is required" },
  { F|O, "PolygonOffsetFactor" , opt_general_polygon_offset_factor ,
#if defined(__APPLE__)
    0.5 ,
#else
    1.0 ,
#endif
    "Polygon offset factor (offset = factor * DZ + r * units)" },
  { F|O, "PolygonOffsetUnits" , opt_general_polygon_offset_units , 1. ,
    "Polygon offset units (offset = factor * DZ + r * units)" },
  { F|O, "ProgressMeterStep" , opt_general_progress_meter_step , 20. ,
    "Increment (in percent) of the progress meter bar" },

  { F|O, "QuadricSubdivisions" , opt_general_quadric_subdivisions, 6. ,
    "Number of subdivisions used to draw points or lines as spheres or cylinders" },

  { F,   "RotationX" , opt_general_rotation0 , 0.0 ,
    "First Euler angle (used if Trackball=0)" },
  { F,   "RotationY" , opt_general_rotation1 , 0.0 ,
    "Second Euler angle (used if Trackball=0)" },
  { F,   "RotationZ" , opt_general_rotation2 , 0.0 ,
    "Third Euler angle (used if Trackball=0)" },
  { F|O, "RotationCenterGravity" , opt_general_rotation_center_cg , 1. ,
    "Rotate around the (pseudo) center of mass instead of (RotationCenterX, "
    "RotationCenterY, RotationCenterZ)" },
  { F,   "RotationCenterX" , opt_general_rotation_center0 , 0.0 ,
    "X coordinate of the center of rotation" },
  { F,   "RotationCenterY" , opt_general_rotation_center1 , 0.0 ,
    "Y coordinate of the center of rotation" },
  { F,   "RotationCenterZ" , opt_general_rotation_center2 , 0.0 ,
    "Z coordinate of the center of rotation" },

  { F|S, "SaveOptions" , opt_general_options_save, 0. ,
    "Automatically save current options in General.OptionsFileName (1) or per model (2)"
    "each time you quit Gmsh?" },
  { F|S, "SaveSession" , opt_general_session_save, 1. ,
    "Automatically save session specific information in General.SessionFileName "
    "each time you quit Gmsh?" },
  { F,   "ScaleX" , opt_general_scale0 , 1.0 ,
    "X-axis scale factor" },
  { F,   "ScaleY" , opt_general_scale1 , 1.0 ,
    "Y-axis scale factor" },
  { F,   "ScaleZ" , opt_general_scale2 , 1.0 ,
    "Z-axis scale factor" },
  { F|O, "Shininess" , opt_general_shine , 0.4 ,
    "Material shininess" },
  { F|O, "ShininessExponent" , opt_general_shine_exponent , 40. ,
    "Material shininess exponent (between 0 and 128)" },
  { F|O, "SmallAxes" , opt_general_small_axes , 1. ,
    "Display the small axes" },
  { F|O, "SmallAxesPositionX" , opt_general_small_axes_position0 , -60. ,
    "X position (in pixels) of small axes (< 0: measure from right window edge; >= 1e5:"
    " centered)" },
  { F|O, "SmallAxesPositionY" , opt_general_small_axes_position1 , -40. ,
    "Y position (in pixels) of small axes (< 0: measure from bottom window edge; >= 1e5:"
    " centered)" },
  { F|O, "SmallAxesSize" , opt_general_small_axes_size , 30. ,
    "Size (in pixels) of small axes" },
  { F|S, "StatisticsPositionX" , opt_general_statistics_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the statistic "
    "window" },
  { F|S, "StatisticsPositionY" , opt_general_statistics_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the statistic"
    " window" },
  { F|O, "Stereo" , opt_general_stereo_mode , 0. ,
    "Use stereo rendering" },
  { F|S, "SystemMenuBar" , opt_general_system_menu_bar , 1. ,
    "Use the system menu bar on Mac OS X?" },

  { F|O, "Terminal" , opt_general_terminal , 0. ,
    "Should information be printed on the terminal (if available)?" },
  { F|O, "Tooltips" , opt_general_tooltips , 1. ,
    "Show tooltips in the user interface" },
  { F|O, "Trackball" , opt_general_trackball , 1. ,
    "Use trackball rotation mode" },
  { F|O, "TrackballHyperbolicSheet" , opt_general_trackball_hyperbolic_sheet , 1. ,
    "Use hyperbolic sheet away from trackball center for z-rotations" },
  { F,   "TrackballQuaternion0" , opt_general_quaternion0 , 0.0 ,
    "First trackball quaternion component (used if General.Trackball=1)" },
  { F,   "TrackballQuaternion1" , opt_general_quaternion1 , 0.0 ,
    "Second trackball quaternion component (used if General.Trackball=1)" },
  { F,   "TrackballQuaternion2" , opt_general_quaternion2 , 0.0 ,
    "Third trackball quaternion component (used if General.Trackball=1)" },
  { F,   "TrackballQuaternion3" , opt_general_quaternion3 , 1.0 ,
    "Fourth trackball quaternion component (used if General.Trackball=1)" },
  { F,   "TranslationX" , opt_general_translation0 , 0.0 ,
    "X-axis translation (in model units)" },
  { F,   "TranslationY" , opt_general_translation1 , 0.0 ,
    "Y-axis translation (in model units)" },
  { F,   "TranslationZ" , opt_general_translation2 , 0.0 ,
    "Z-axis translation (in model units)" },

  { F|O, "VectorType" , opt_general_vector_type , 4 ,
    "Default vector display type (for normals, etc.)" },
  { F|O, "Verbosity" , opt_general_verbosity , 5. ,
    "Level of information printed during processing (0=no information)" },
  { F|S, "VisibilityPositionX" , opt_general_visibility_position0 , 650. ,
    "Horizontal position (in pixels) of the upper left corner of the visibility "
    "window" },
  { F|S, "VisibilityPositionY" , opt_general_visibility_position1 , 150. ,
    "Vertical position (in pixels) of the upper left corner of the visibility "
    "window" },

  { F|O, "ZoomFactor" , opt_general_zoom_factor , 4.0 ,
    "Middle mouse button zoom acceleration factor" },

  { 0, 0 , 0 , 0. , 0 }
} ;

StringXNumber GeometryOptions_Number[] = {
  { F|O, "AutoCoherence" , opt_geometry_auto_coherence , 1. ,
    "Should all duplicate entities be automatically removed? (If AutoCoherence == 2, "
    "also remove degenerate entities)" },

  { F,   "Clip" , opt_geometry_clip , 0.,
    "Enable clipping planes? (Plane[i]=2^i, i=0,...,5)" },
  { F|O, "CopyMeshingMethod" , opt_geometry_copy_meshing_method, 0. ,
    "Copy meshing method (unstructured or transfinite) when duplicating geometrical entities?" },
  { F|O, "CopyDisplayAttributes" , opt_geometry_copy_display_attributes, 0. ,
    "Copy display attributes (visibiliy, color) when duplicating geometrical entities?" },

  { F, "DoubleClickedEntityTag" , opt_geometry_double_clicked_entity_tag, 0. ,
    "Tag of last double-clicked geometrical entity" },

  { F|O, "ExactExtrusion" , opt_geometry_exact_extrusion, 1. ,
    "Use exact extrusion formula in interpolations (set to 0 to allow "
    "geometrical transformations of extruded entities)" },
  { F|O, "ExtrudeReturnLateralEntities" , opt_geometry_extrude_return_lateral, 1. ,
    "Add lateral entities in lists returned by extrusion commands?" },
  { F|O, "ExtrudeSplinePoints" , opt_geometry_extrude_spline_points, 5. ,
    "Number of control points for splines created during extrusion" },

  { F|O, "HideCompounds" , opt_geometry_hide_compounds, 1. ,
    "Hide entities that make up compound entities?" },
  { F|O, "HighlightOrphans" , opt_geometry_highlight_orphans, 0. ,
    "Highlight orphan entities (lines connected to a single surface, etc.)?" },

  { F|O, "LabelType" , opt_geometry_label_type , 1. ,
    "Type of entity label (1=elementary number, 2=physical number)" },
  { F|O, "Light" , opt_geometry_light , 1. ,
    "Enable lighting for the geometry" },
  { F|O, "LightTwoSide" , opt_geometry_light_two_side , 0. ,
    "Light both sides of surfaces (leads to slower rendering)" },
  { F|O, "Lines" , opt_geometry_lines , 1. ,
    "Display geometry curves?" },
  { F|O, "LineNumbers" , opt_geometry_lines_num , 0. ,
    "Display curve numbers?" },
  { F|O, "LineSelectWidth" , opt_geometry_line_sel_width , 2. ,
    "Display width of selected lines (in pixels)" },
  { F|O, "LineType" , opt_geometry_line_type , 0. ,
    "Display lines as solid color segments (0), 3D cylinders (1) or tapered "
    "cylinders (2)" },
  { F|O, "LineWidth" , opt_geometry_line_width , 2. ,
    "Display width of lines (in pixels)" },

  { F|O, "MatchGeomAndMesh" , opt_geometry_match_geom_and_mesh, 0 ,
    "Matches geometries and meshes" },

  { F|O, "Normals" , opt_geometry_normals , 0. ,
    "Display size of normal vectors (in pixels)" },
  { F|O, "NumSubEdges" , opt_geometry_num_sub_edges , 20. ,
    "Number of edge subdivisions between control points when displaying curves" },

  { F|O, "OCCFixDegenerated" , opt_geometry_occ_fix_degenerated , 0. ,
    "Fix degenerated edges/faces in STEP, IGES and BRep models" },
  { F|O, "OCCFixSmallEdges" , opt_geometry_occ_fix_small_edges , 0. ,
    "Fix small edges in STEP, IGES and BRep models" },
  { F|O, "OCCFixSmallFaces" , opt_geometry_occ_fix_small_faces , 0. ,
    "Fix small faces in STEP, IGES and BRep models" },
  { F|O, "OCCSewFaces" , opt_geometry_occ_sew_faces , 0. ,
    "Sew faces in STEP, IGES and BRep models" },
  { F|O, "OCCParallel" , opt_geometry_occ_parallel , 0. ,
    "Use multi-threaded OCC boolean operators" },
  { F|O, "OCCScaling" , opt_geometry_occ_scaling , 1. ,
    "Scale STEP, IGES and BRep model by given factor" },
  { F,   "OffsetX" , opt_geometry_offset0 , 0. ,
    "Model display offset along X-axis (in model coordinates)" },
  { F,   "OffsetY" , opt_geometry_offset1 , 0. ,
    "Model display offset along Y-axis (in model coordinates)" },
  { F,   "OffsetZ" , opt_geometry_offset2 , 0. ,
    "Model display offset along Z-axis (in model coordinates)" },
  { F|O, "OldCircle" , opt_geometry_old_circle , 0. ,
    "Use old circle description (compatibility option for old Gmsh geometries)" },
  { F|O, "OldRuledSurface" , opt_geometry_old_ruled_surface , 0. ,
    "Use old 3-sided ruled surface interpolation (compatibility option for old Gmsh geometries)" },
  { F|O, "OldNewReg" , opt_geometry_old_newreg , 1. ,
    "Use old newreg definition for geometrical transformations (compatibility "
    "option for old Gmsh geometries)" },

  { F|O, "Points" , opt_geometry_points , 1. ,
    "Display geometry points?" },
  { F|O, "PointNumbers" , opt_geometry_points_num , 0. ,
    "Display points numbers?" },
  { F|O, "PointSelectSize" , opt_geometry_point_sel_size , 5. ,
    "Display size of selected points (in pixels)" },
  { F|O, "PointSize" , opt_geometry_point_size , 4. ,
    "Display size of points (in pixels)" },
  { F|O, "PointType" , opt_geometry_point_type , 0. ,
    "Display points as solid color dots (0) or 3D spheres (1)" },

  { F|O, "ScalingFactor" , opt_geometry_scaling_factor , 1.0 ,
    "Global geometry scaling factor" },
  { F|O, "OrientedPhysicals" , opt_geometry_oriented_physicals, 1. ,
    "Use sign of elementary entity in physical definition as orientation indicator" },
  { F|O, "SnapX" , opt_geometry_snap0 , 0.1 ,
    "Snapping grid spacing along the X-axis" },
  { F|O, "SnapY" , opt_geometry_snap1 , 0.1 ,
    "Snapping grid spacing along the Y-axis" },
  { F|O, "SnapZ" , opt_geometry_snap2 , 0.1 ,
    "Snapping grid spacing along the Z-axis" },
  { F|O, "Surfaces" , opt_geometry_surfaces , 0. ,
    "Display geometry surfaces?" },
  { F|O, "SurfaceNumbers" , opt_geometry_surfaces_num , 0. ,
    "Display surface numbers?" },
  { F|O, "SurfaceType" , opt_geometry_surface_type , 2. ,
    "Surface display type (0=cross, 1=wireframe, 2=solid)" },

  { F|O, "Tangents" , opt_geometry_tangents , 0. ,
    "Display size of tangent vectors (in pixels)" },
  { F|O, "Tolerance" , opt_geometry_tolerance, 1.e-8 ,
    "Geometrical tolerance" },
  { F|O, "ToleranceBoolean" , opt_geometry_tolerance_boolean, 0. ,
    "Geometrical tolerance for boolean operations" },
  { F,   "Transform" , opt_geometry_transform , 0. ,
    "Transform model display coordinates (0=no, 1=scale)" },
  { F,   "TransformXX" , opt_geometry_transform00 , 1. ,
    "Element (1,1) of the 3x3 model display transformation matrix" },
  { F,   "TransformXY" , opt_geometry_transform01 , 0. ,
    "Element (1,2) of the 3x3 model display transformation matrix" },
  { F,   "TransformXZ" , opt_geometry_transform02 , 0. ,
    "Element (1,3) of the 3x3 model display transformation matrix" },
  { F,   "TransformYX" , opt_geometry_transform10 , 0. ,
    "Element (2,1) of the 3x3 model display transformation matrix" },
  { F,   "TransformYY" , opt_geometry_transform11 , 1. ,
    "Element (2,2) of the 3x3 model display transformation matrix" },
  { F,   "TransformYZ" , opt_geometry_transform12 , 0. ,
    "Element (2,3) of the 3x3 model display transformation matrix" },
  { F,   "TransformZX" , opt_geometry_transform20 , 0. ,
    "Element (3,1) of the 3x3 model display transformation matrix" },
  { F,   "TransformZY" , opt_geometry_transform21 , 0. ,
    "Element (3,2) of the 3x3 model display transformation matrix" },
  { F,   "TransformZZ" , opt_geometry_transform22 , 1. ,
    "Element (3,3) of the 3x3 model display transformation matrix" },

  { F|O, "Volumes" , opt_geometry_volumes , 0. ,
    "Display geometry volumes? (not implemented yet)" },
  { F|O, "VolumeNumbers" , opt_geometry_volumes_num , 0. ,
    "Display volume numbers? (not implemented yet)" },

  { 0, 0 , 0 , 0. , 0 }
} ;

StringXNumber MeshOptions_Number[] = {
  { F|O, "Algorithm" , opt_mesh_algo2d , ALGO_2D_AUTO ,
    "2D mesh algorithm (1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=BAMG, 8=DelQuad)" },
  { F|O, "Algorithm3D" , opt_mesh_algo3d ,
#if defined(HAVE_TETGEN)
    ALGO_3D_DELAUNAY ,
#else
    ALGO_3D_DELAUNAY_NEW ,
#endif
    "3D mesh algorithm (1=Delaunay, 2=New Delaunay, 4=Frontal, 5=Frontal Delaunay, "
    "6=Frontal Hex, 7=MMG3D, 9=R-tree)" },
  { F|O, "AngleSmoothNormals" , opt_mesh_angle_smooth_normals , 30.0 ,
    "Threshold angle below which normals are not smoothed" },
  { F|O, "AnisoMax" , opt_mesh_aniso_max, 1.e33,
    "Maximum anisotropy of the mesh" },
  { F|O, "AllowSwapAngle" , opt_mesh_allow_swap_edge_angle , 10.0 ,
    "Threshold angle (in degrees) between faces normals under which we allow "
    "an edge swap" },

  { F|O, "BdfFieldFormat" , opt_mesh_bdf_field_format , 1. ,
    "Field format for Nastran BDF files (0=free, 1=small, 2=large)" },
  { F|O, "Binary" , opt_mesh_binary , 0. ,
    "Write mesh files in binary format (if possible)" },
  { F|O, "Lloyd" , opt_mesh_lloyd , 0. ,
    "Apply lloyd optimization on surface meshes" },
  { F|O, "SmoothCrossField" , opt_mesh_smooth_cross_field , 0. ,
    "Apply n barycentric smoothing passes to the cross field" },

  { F|O, "CgnsImportOrder" , opt_mesh_cgns_import_order , 1. ,
   "Enable the creation of high-order mesh from CGNS structured meshes"
   "(1, 2, 4, 8, ...)" },
  { F|O, "ChacoArchitecture" , opt_mesh_partition_chaco_architecture, 1. ,
    "(Adv. Chaco): Parallel architecture topology (0=hypercube, 1-3=mesh "
    "dimensions)" },
  { F|O, "ChacoEigensolver" , opt_mesh_partition_chaco_eigensolver, 1. ,
    "(Adv. Chaco): Type of eigensolver for a spectral algorithm (0=Lanczos, "
    "1=Multilevel RQI/Symmlq)" },
  { F|O, "ChacoEigTol" , opt_mesh_partition_chaco_eigtol, 1.E-3 ,
    "(Adv. Chaco): Tolerance of the eigensolver for spectral or multilevel-KL "
    "algorithms" },
  { F|O, "ChacoGlobalMethod" , opt_mesh_partition_chaco_global_method, 1. ,
    "Chaco partitioning algorithm (1=Multilevel-KL, 2=Spectral, 4=Linear, "
    "5=Random, 6=Scattered)" },
  { F|O, "ChacoHypercubeDim" , opt_mesh_partition_chaco_ndims_tot, 2. ,
    "(Adv. Chaco): Dimensional partitioning for a hypercube topology" },
  { F|O, "ChacoLocalMethod" , opt_mesh_partition_chaco_local_method, 1. ,
    "(Adv. Chaco): Local partitioning algorithm" },
  { F|O, "ChacoMeshDim1" , opt_mesh_partition_chaco_mesh_dims1, 4. ,
    "(Adv. Chaco): Number of partitions in the first dimension of a mesh topology" },
  { F|O, "ChacoMeshDim2" , opt_mesh_partition_chaco_mesh_dims2, 1. ,
    "(Adv. Chaco): Number of partitions in the second dimension of a mesh topology" },
  { F|O, "ChacoMeshDim3" , opt_mesh_partition_chaco_mesh_dims3, 1. ,
    "(Adv. Chaco): Number of partitions in the third dimension of a mesh topology" },
  { F|O, "ChacoPartitionSection" , opt_mesh_partition_chaco_nsection, 1. ,
    "(Adv. Chaco): Partition by (1=bisection, 2=quadrisection, 3=octasection" },
  { F|O, "ChacoSeed" , opt_mesh_partition_chaco_seed, 7654321. ,
    "(Adv. Chaco): Seed for random number generator" },
  { F|O, "ChacoVMax" , opt_mesh_partition_chaco_vmax, 250. ,
    "(Adv. Chaco): Maximum vertices in a coarse graph (for multilevel-KL "
    "algorithm and Multilevel RQI/Symmlq eigensolver)" },
  { F|O, "ChacoParamINTERNAL_VERTICES" ,
    opt_mesh_partition_chaco_internal_vertices, 0. ,
    "(Adv. Chaco): Parameter INTERNAL_VERTICES" },
  { F|O, "ChacoParamREFINE_MAP" , opt_mesh_partition_chaco_refine_map, 1. ,
    "(Adv. Chaco): Parameter REFINE_MAP" },
  { F|O, "ChacoParamREFINE_PARTITION" ,
    opt_mesh_partition_chaco_refine_partition, 0. ,
    "(Adv. Chaco): Parameter REFINE_PARTITION" },
  { F|O, "ChacoParamTERMINAL_PROPOGATION" ,
    opt_mesh_partition_chaco_terminal_propogation, 0. ,
    "(Adv. Chaco): Parameter TERMINAL_PROPOGATION" },
  { F|O, "CharacteristicLengthExtendFromBoundary" ,
    opt_mesh_lc_extend_from_boundary, 1. ,
    "Extend computation of mesh element sizes from the boundaries into the surfaces/volumes" },
  { F|O, "CharacteristicLengthFactor" , opt_mesh_lc_factor , 1.0 ,
    "Factor applied to all mesh element sizes" },
  { F|O, "CharacteristicLengthMin" , opt_mesh_lc_min, 0.0 ,
    "Minimum mesh element size" },
  { F|O, "CharacteristicLengthMax" , opt_mesh_lc_max, 1.e22,
    "Maximum mesh element size" },
  { F|O, "CharacteristicLengthFromCurvature" , opt_mesh_lc_from_curvature , 0. ,
    "Automatically compute mesh element sizes from curvature (experimental)" },
  { F|O, "CharacteristicLengthFromPoints" , opt_mesh_lc_from_points , 1. ,
    "Compute mesh element sizes from values given at geometry points" },
  { F,   "Clip" , opt_mesh_clip , 0.,
    "Enable clipping planes? (Plane[i]=2^i, i=0,...,5)" },
  { F|O, "ColorCarousel" , opt_mesh_color_carousel , 1. ,
    "Mesh coloring (0=by element type, 1=by elementary entity, 2=by physical "
    "entity, 3=by partition)" },
  { F,   "CpuTime" , opt_mesh_cpu_time , 0. ,
    "CPU time (in seconds) for the generation of the current mesh (read-only)" },

  { F|O, "DrawSkinOnly" , opt_mesh_draw_skin_only , 0. ,
    "Draw only the skin of 3D meshes?" },
  { F|O, "Dual" , opt_mesh_dual , 0. ,
    "Display the dual mesh obtained by barycentric subdivision" },

  { F|O, "ElementOrder" , opt_mesh_order , 1. ,
    // "Order" is a reserved token in the parser
    "Element order (1=linear elements, N (<6) = elements of higher order)" },
  { F|O, "Explode" , opt_mesh_explode , 1.0 ,
    "Element shrinking factor (between 0 and 1)" },

  { F|O, "FlexibleTransfinite" , opt_mesh_flexible_transfinite , 0 ,
    "Allow transfinite contraints to be modified for Blossom or by global mesh size factor" },
  { F|O, "NewtonConvergenceTestXYZ" , opt_mesh_newton_convergence_test_xyz , 0. ,
    "Force inverse surface mapping algorithm (Newton-Raphson) to converge in real "
    "coordinates (experimental)" },
  { F|O, "Format" , opt_mesh_file_format , FORMAT_AUTO ,
    "Mesh output format (1=msh, 2=unv, 10=automatic, 19=vrml, 26=pos statistics, 27=stl, "
    "30=mesh, 31=bdf, 32=cgns, 33=med, 39=inp, 40=ply2)" },

  { F|O, "Hexahedra" , opt_mesh_hexahedra , 1. ,
    "Display mesh hexahedra?" },
  { F|0, "HighOrderNumLayers", opt_mesh_ho_nlayers, 6.,
    "Number of high order mesh elements to consider for optimization"},
  { F|O, "HighOrderOptimize" , opt_mesh_ho_optimize , 0.,
    "Optimize high order meshes?" },
  { F|0, "HighOrderPoissonRatio", opt_mesh_ho_poisson, 0.33,
    "Poisson ratio of the material used in the elastic smoother for high order meshes"
    "Must be between -1.0 and 0.5, excluded"},
  { F|O, "HighOrderThresholdMin", opt_mesh_ho_threshold_min, 0.1,
    "Minimum threshold for high order element optimization"},
  { F|O, "HighOrderThresholdMax", opt_mesh_ho_threshold_max, 2.0,
    "Maximum threshold for high order element optimization"},
  { F|O, "HighOrderOptPrimSurfMesh", opt_mesh_ho_opt_prim_surf_mesh, 0,
    "Try to fix flipped surface mesh elements in high-order optimizer"},

  { F|O, "LabelSampling" , opt_mesh_label_sampling , 1. ,
    "Label sampling rate (display one label every `LabelSampling' elements)" },
  { F|O, "LabelType" , opt_mesh_label_type , 0. ,
    "Type of element label (0=element number, 1=elementary entity number, "
    "2=physical entity number, 3=partition number, 4=coordinates)" },
  { F|O, "LcIntegrationPrecision" , opt_mesh_lc_integration_precision, 1.e-9 ,
    "Accuracy of evaluation of the LC field for 1D mesh generation" },
  { F|O, "Light" , opt_mesh_light , 1. ,
    "Enable lighting for the mesh" },
  { F|O, "LightLines" , opt_mesh_light_lines , 2. ,
    "Enable lighting for mesh edges (0=no, 1=surfaces, 2=surfaces+volumes" },
  { F|O, "LightTwoSide" , opt_mesh_light_two_side , 0. ,
    "Light both sides of surfaces (leads to slower rendering)" },
  { F|O, "Lines" , opt_mesh_lines , 0. ,
    "Display mesh lines (1D elements)?" },
  { F|O, "LineNumbers" , opt_mesh_lines_num , 0. ,
    "Display mesh line numbers?" },
  { F|O, "LineWidth" , opt_mesh_line_width , 1.0 ,
    "Display width of mesh lines (in pixels)" },

  { F|O, "MeshOnlyVisible" , opt_mesh_mesh_only_visible, 0. ,
    "Mesh only visible entities (experimental: use with caution!)" },
  { F|O, "MetisAlgorithm" , opt_mesh_partition_metis_algorithm, 1. ,
    "METIS partitioning algorithm (1=Recursive, 2=K-way, 3=Nodal weight)" },
  { F|O, "MetisEdgeMatching" , opt_mesh_partition_metis_edge_matching, 3. ,
    "(Adv. METIS): Determines the matching type (1=Random, 2=Heavy-Edge, "
    "3=Sorted Heavy-Edge)" },
  { F|O, "MetisRefinementAlgorithm" , opt_mesh_partition_metis_refine_algorithm, 3. ,
    "(Adv. METIS): Algorithm for k-way refinement (1=Random, 2=Greedy, "
    "3=Random with minimized connectivity)" },
  { F|O, "MinimumCirclePoints" , opt_mesh_min_circ_points, 7. ,
    "Minimum number of points used to mesh a circle" },
  { F|O, "MinimumCurvePoints" , opt_mesh_min_curv_points, 3. ,
    "Minimum number of points used to mesh a (non-straight) curve" },
  { F|O, "MshFileVersion" , opt_mesh_msh_file_version , 2.2 ,
    "Version of the MSH file format to use" },
  { F|O, "MshFilePartitioned" , opt_mesh_msh_file_partitioned , 0. ,
    "Split MSH file by mesh partition (0: no, 1: yes, 2: create physicals by partition)" },
  { F|O, "PartitionHexWeight"     , opt_mesh_partition_hex_weight , 1 ,
    "Weight of hexahedral element for METIS load balancing" },
  { F|O, "PartitionPrismWeight"   , opt_mesh_partition_pri_weight , 1 ,
    "Weight of prismatic element (wedge) for METIS load balancing" },
  { F|O, "PartitionPyramidWeight" , opt_mesh_partition_pyr_weight , 1 ,
    "Weight of pyramidal element for METIS load balancing" },
  { F|O, "PartitionTrihedronWeight" , opt_mesh_partition_trih_weight , 0 ,
    "Weight of trihedron element for METIS load balancing" },
  { F|O, "PartitionQuadWeight"    , opt_mesh_partition_qua_weight , 1 ,
    "Weight of quadrangle for METIS load balancing" },
  { F|O, "PartitionTetWeight"     , opt_mesh_partition_tet_weight , 1 ,
    "Weight of tetrahedral element for METIS load balancing" },
  { F|O, "PartitionTriWeight"     , opt_mesh_partition_tri_weight , 1 ,
    "Weight of triangle for METIS load balancing" ,},

  { F, "NbHexahedra" , opt_mesh_nb_hexahedra , 0. ,
    "Number of hexahedra in the current mesh (read-only)" },
  { F, "NbNodes" , opt_mesh_nb_nodes , 0. ,
    "Number of nodes in the current mesh (read-only)" },
  { F|O, "NbPartitions" , opt_mesh_partition_num, 1. ,
    "Number of partitions" },
  { F, "NbPrisms" , opt_mesh_nb_prisms , 0. ,
    "Number of prisms in the current mesh (read-only)" },
  { F, "NbPyramids" , opt_mesh_nb_pyramids , 0. ,
    "Number of pyramids in the current mesh (read-only)" },
  { F, "NbTrihedra" , opt_mesh_nb_trihedra , 0. ,
    "Number of trihedra in the current mesh (read-only)" },
  { F, "NbQuadrangles" , opt_mesh_nb_quadrangles , 0. ,
    "Number of quadrangles in the current mesh (read-only)" },
  { F, "NbTetrahedra" , opt_mesh_nb_tetrahedra , 0. ,
    "Number of tetrahedra in the current mesh (read-only)" },
  { F, "NbTriangles" , opt_mesh_nb_triangles , 0. ,
    "Number of triangles in the current mesh (read-only)" },
  { F|O, "Normals" , opt_mesh_normals , 0.0 ,
    "Display size of normal vectors (in pixels)" },
  { F|O, "NumSubEdges" , opt_mesh_num_sub_edges , 2. ,
    "Number of edge subdivisions when displaying high order elements" },

  { F|O, "OldRefinement" , opt_mesh_old_refinement , 1 ,
    "Use old 3D point insertion algorithm" },
  { F|O, "Optimize" , opt_mesh_optimize , 0. ,
    "Optimize the mesh to improve the quality of tetrahedral elements" },
  { F|O, "OptimizeNetgen" , opt_mesh_optimize_netgen , 0. ,
    "Optimize the mesh using Netgen to improve the quality of tetrahedral "
    "elements" },

  { F|O, "Partitioner" , opt_mesh_partition_partitioner, 2. ,
    "Partitioner software (1=Chacho, 2=METIS)" },
  { F|O, "Points" , opt_mesh_points , 0. ,
    "Display mesh vertices (nodes)?" },
  { F|O, "PointNumbers" , opt_mesh_points_num , 0. ,
    "Display mesh node numbers?" },
  { F|O, "PointSize" , opt_mesh_point_size , 4. ,
    "Display size of mesh vertices (in pixels)" },
  { F|O, "PointType" , opt_mesh_point_type , 0. ,
    "Display mesh vertices as solid color dots (0) or 3D spheres (1)" },
  { F|O, "Prisms" , opt_mesh_prisms , 1. ,
    "Display mesh prisms?" },
  { F|O, "Pyramids" , opt_mesh_pyramids , 1. ,
    "Display mesh pyramids?" },
  { F|O, "Trihedra" , opt_mesh_trihedra , 1. ,
    "Display mesh trihedra?" },

  { F|O, "Quadrangles" , opt_mesh_quadrangles , 1. ,
    "Display mesh quadrangles?" },
  { F|O, "QualityInf" , opt_mesh_quality_inf , 0.0 ,
    "Only display elements whose quality measure is greater than QualityInf" },
  { F|O, "QualitySup" , opt_mesh_quality_sup , 0.0 ,
    "Only display elements whose quality measure is smaller than QualitySup" },
  { F|O, "QualityType" , opt_mesh_quality_type , 2. ,
    "Type of quality measure (0=gamma~vol/sum_face/max_edge, "
    "1=eta~vol^(2/3)/sum_edge^2, 2=rho~min_edge/max_edge)" },

  { F|O, "RadiusInf" , opt_mesh_radius_inf , 0.0 ,
    "Only display elements whose longest edge is greater than RadiusInf" },
  { F|O, "RadiusSup" , opt_mesh_radius_sup , 0.0 ,
    "Only display elements whose longest edge is smaller than RadiusSup" },
  { F|O, "RandomFactor" , opt_mesh_rand_factor , 1.e-9 ,
    "Random factor used in the 2D meshing algorithm (should be increased if "
    "RandomFactor * size(triangle)/size(model) approaches machine accuracy)" },
  { F|O, "IgnorePartitionBoundary" , opt_mesh_ignore_part_bound , 0. ,
    "Ignore partitions boundaries (0=no, 1=yes)"},
  { F|O, "PreserveNumberingMsh2" , opt_mesh_preserve_numbering_msh2 , 0. ,
    "Preserve element numbering in MSH2 format (will break meshes with multiple "
    "physical groups for a single elementary entity)"},
  { F|O, "IgnorePeriodicity" , opt_mesh_ignore_periodicity , 0. ,
    "Ignore alignement of periodic boundaries when reading the mesh "
    "(used by ParaView plugin)"},
#if defined(HAVE_BLOSSOM)
  { F|O, "RecombinationAlgorithm" , opt_mesh_algo_recombine , 1 ,
#else
  { F|O, "RecombinationAlgorithm" , opt_mesh_algo_recombine , 0 ,
#endif
    "Mesh recombination algorithm (0=standard, 1=blossom)" },
  { F|O, "RecombineAll" , opt_mesh_recombine_all , 0 ,
    "Apply recombination algorithm to all surfaces, ignoring per-surface spec" },
  { F|O, "Recombine3DAll" , opt_mesh_recombine3d_all , 0 ,
    "Apply recombination3D algorithm to all volumes, ignoring per-volume spec" },
  { F|O, "Recombine3DLevel" , opt_mesh_recombine3d_level , 0 ,
    "3d recombination level (0: hex, 1: hex+prisms, 2: hex+prism+pyramids)" },
  { F|O, "Recombine3DConformity" , opt_mesh_recombine3d_conformity , 0 ,
    "3d recombination conformity type (0: nonconforming, 1: trihedra, "
    "2: pyramids+trihedra, 3:pyramids+hexSplit+trihedra, 4:hexSplit+trihedra)" },
  { F|O, "DoRecombinationTest" , opt_mesh_do_recombination_test , 0 ,
    "Apply recombination algorithm for test" },
  { F|O, "RecombinationTestHorizStart" , opt_mesh_recombination_test_start , 1 ,
    "Depth start" },
  { F|O, "RecombinationTestNoGreedyStrat" , opt_mesh_recombination_no_greedy_strat , 0 ,
    "No greedy (global) strategies" },
  { F|O, "RemeshAlgorithm" , opt_mesh_remesh_algo , 0 ,
    "Remeshing algorithm (0=no split, 1=automatic, 2=automatic only with metis)" },
  { F|O, "RemeshParametrization" , opt_mesh_remesh_param , 4 ,
    "Remeshing using discrete parametrization (0=harmonic_circle, 1=conformal_spectral, "
    "2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square, "
    "7=conformal_fe" },
  { F|O, "RefineSteps" , opt_mesh_refine_steps , 10 ,
    "Number of refinement steps in the MeshAdapt-based 2D algorithms" },

  { F,   "SaveAll" , opt_mesh_save_all , 0. ,
    "Ignore Physical definitions and save all elements" },
  { F|O, "SaveElementTagType" , opt_mesh_save_element_tag_type , 1. ,
    "Type of the element tag saved in mesh formats that don't support saving "
    "physical or partition ids (1=elementary, 2=physical, 3=partition)" },
  { F|O, "SaveParametric" , opt_mesh_save_parametric , 0. ,
    "Save parametric coordinates of nodes" },
  { F|O, "SaveGroupsOfNodes" , opt_mesh_save_groups_of_nodes , 0. ,
    "Save groups of nodes for each physical line and surface (UNV mesh "
    "format only)" },
  { F|O, "ScalingFactor" , opt_mesh_scaling_factor , 1.0 ,
    "Global scaling factor applied to the saved mesh" },
  { F|O, "SecondOrderExperimental" , opt_mesh_second_order_experimental , 0. ,
    "Use experimental code to generate second order mesh" },
  { F|O, "SecondOrderIncomplete" , opt_mesh_second_order_incomplete , 0. ,
    "Create incomplete second order elements? (8-node quads, 20-node hexas, etc.)" },
  { F|O, "SecondOrderLinear" , opt_mesh_second_order_linear , 0. ,
    "Should second order vertices simply be created by linear interpolation?" },
  { F|O, "Smoothing" , opt_mesh_nb_smoothing , 1. ,
    "Number of smoothing steps applied to the final mesh" },
  { F|O, "SmoothNormals" , opt_mesh_smooth_normals , 0. ,
    "Smooth the mesh normals?" },
  { F|O, "SmoothRatio" , opt_mesh_smooth_ratio , 1.8 ,
    "Ratio between mesh sizes at vertices of a same edeg (used in BAMG)" },
  { F|O, "SubdivisionAlgorithm" , opt_mesh_algo_subdivide , 0 ,
    "Mesh subdivision algorithm (0=none, 1=all quadrangles, 2=all hexahedra)" },
  { F|O, "SurfaceEdges" , opt_mesh_surfaces_edges , 1. ,
    "Display edges of surface mesh?" },
  { F|O, "SurfaceFaces" , opt_mesh_surfaces_faces , 0. ,
    "Display faces of surface mesh?" },
  { F|O, "SurfaceNumbers" , opt_mesh_surfaces_num , 0. ,
    "Display surface mesh element numbers?" },
  { F|O, "SwitchElementTags", opt_mesh_switch_elem_tags, 0. ,
    "Invert elementary and physical tags when reading the mesh"},

  { F|O, "Tangents" , opt_mesh_tangents , 0.0 ,
    "Display size of tangent vectors (in pixels)" },
  { F|O, "Tetrahedra" , opt_mesh_tetrahedra , 1. ,
    "Display mesh tetrahedra?" },
  { F|O, "ToleranceEdgeLength" , opt_mesh_tolerance_edge_length, 0.0,
    "Skip a model edge in mesh generation if its length is less than user's "
    "defined tolerance" },
  { F|O, "ToleranceInitialDelaunay" , opt_mesh_tolerance_initial_delaunay, 1.e-8,
    "Tolerance for initial 3D Delaunay mesher" },
  { F|O, "Triangles" , opt_mesh_triangles , 1. ,
    "Display mesh triangles?" },

  { F|O, "VolumeEdges" , opt_mesh_volumes_edges , 1. ,
    "Display edges of volume mesh?" },
  { F|O, "VolumeFaces" , opt_mesh_volumes_faces , 0. ,
    "Display faces of volume mesh?" },
  { F|O, "VolumeNumbers" , opt_mesh_volumes_num , 0. ,
    "Display volume mesh element numbers?" },
  { F|O, "Voronoi" , opt_mesh_voronoi , 0. ,
    "Display the voronoi diagram" },

  { F|O, "ZoneDefinition" , opt_mesh_zone_definition , 0. ,
    "Method for defining a zone (0=single zone, 1=by partition, 2=by physical)" },

  { 0, 0 , 0 , 0. , 0 }
} ;

StringXNumber SolverOptions_Number[] = {
  { F|O, "AlwaysListen" , opt_solver_listen , 0. ,
    "Always listen to incoming connection requests?" },
  { F|O, "AutoArchiveOutputFiles" , opt_solver_auto_archive_output_files , 0. ,
    "Automatically archive output files after each computation" },
  { F|O, "AutoCheck" , opt_solver_auto_check , 1. ,
    "Automatically check model every time a parameter is changed" },
  { F|O, "AutoLoadDatabase" , opt_solver_auto_load_database , 0. ,
    "Automatically load the ONELAB database when launching a solver" },
  { F|O, "AutoSaveDatabase" , opt_solver_auto_save_database , 1. ,
    "Automatically save the ONELAB database after each computation" },
  { F|O, "AutoMesh" , opt_solver_auto_mesh , 1. ,
    "Automatically mesh if necesssary (0: never remesh; 1: on startup, use existing "
    "mesh on disk if available; 2: always remesh; -1: the geometry script creates "
    "the mesh)" },
  { F|O, "AutoMergeFile" , opt_solver_auto_merge_file , 1. ,
    "Automatically merge result files" },
  { F|O, "AutoShowViews" , opt_solver_auto_show_views , 2. ,
    "Automcatically show newly merged results (0: none; 1: all; 2: last one)" },
  { F|O, "AutoShowLastStep" , opt_solver_auto_show_last_step , 1. ,
    "Automatically show the last step in newly merged results, if there are "
    "more than 2 steps" },

  { F|O, "Plugins" , opt_solver_plugins , 0. ,
    "Enable default solver plugins?" },

  { F|O, "ShowInvisibleParameters" , opt_solver_show_invisible_parameters , 0. ,
    "Show all parameters, even those marked invisible" },

  { F|O, "Timeout" , opt_solver_timeout , 5. ,
    "Time (in seconds) before closing the socket if no connection is happening" },

  { 0, 0 , 0 , 0. , 0 }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { F|O, "AnimationDelay" , opt_post_anim_delay , 0.1 ,
    "Delay (in seconds) between frames in automatic animation mode" },
  { F|O, "AnimationCycle" , opt_post_anim_cycle , 0. ,
    "Cycle through time steps (0) or views (1) for animations" },
  { F|O, "AnimationStep" , opt_post_anim_step , 1. ,
    "Step increment for animations" },

  { F|O, "CombineRemoveOriginal" , opt_post_combine_remove_orig , 1. ,
    "Remove original views after a Combine operation" },

  { F, "DoubleClickedGraphPointX" , opt_post_double_clicked_graph_point_x , 0. ,
    "Abscissa of last double-clicked graph point" },
  { F, "DoubleClickedGraphPointY" , opt_post_double_clicked_graph_point_y , 0. ,
    "Ordinate of last double-clicked graph point" },
  { F, "DoubleClickedView" , opt_post_double_clicked_view, 0. ,
    "Index of last double-clicked view" },

  { F|O, "ForceElementData" , opt_post_force_element_data , 0. ,
    "Try to force saving datasets as ElementData" },
  { F|O, "ForceNodeData" , opt_post_force_node_data , 0. ,
    "Try to force saving datasets as NodeData" },
  { F|O, "Format" , opt_post_file_format , 10. ,
    "Default file format for post-processing views (0=ASCII view, 1=binary "
    "view, 2=parsed view, 3=STL triangulation, 4=raw text, 5=Gmsh mesh, 6=MED file, "
    "10=automatic)" },

  { F, "GraphPointX" , opt_post_double_clicked_graph_point_x , 0. ,
    "Synonym for `DoubleClickedGraphPointX'" },
  { F, "GraphPointY" , opt_post_double_clicked_graph_point_y , 0. ,
    "Synonym for `DoubleClickedGraphPointY'" },

  { F|O, "HorizontalScales" , opt_post_horizontal_scales , 1. ,
    "Display value scales horizontally" },

  { F|O, "Link" , opt_post_link , 0. ,
    "Post-processing view links (0=apply next option changes to selected views, "
    "1=force same options for all selected views)" },

  { F,   "NbViews" , opt_post_nb_views , 0. ,
    "Current number of views merged (read-only)" },

  { F|O, "Plugins" , opt_post_plugins , 1. ,
    "Enable default post-processing plugins?" },

  { F|O, "Smoothing" , opt_post_smooth , 0. ,
    "Apply (non-reversible) smoothing to post-processing view when merged" },

  { 0, 0 , 0 , 0. }
} ;

StringXNumber ViewOptions_Number[] = {
  { F|O, "AbscissaRangeType" , opt_view_abscissa_range_type , 1 ,
    "Ascissa scale range type (1=default, 2=custom)" },
  { F|O, "AdaptVisualizationGrid" , opt_view_adapt_visualization_grid , 0. ,
    "Use adaptive visualization grid (for high-order elements)?" },
  { F|O, "AngleSmoothNormals" , opt_view_angle_smooth_normals , 30.0 ,
    "Threshold angle below which normals are not smoothed" },
  { F|O, "ArrowSizeMax" , opt_view_arrow_size_max , 60. ,
    "Maximum display size of arrows (in pixels)" },
  { F|O, "ArrowSizeMin" , opt_view_arrow_size_min , 0. ,
    "Minimum display size of arrows (in pixels)" },
  { F|O, "AutoPosition" , opt_view_auto_position , 1. ,
    "Position the scale or 2D plot automatically (0: manual, 1: automatic, 2: top left, "
    "3: top right, 4: bottom left, 5: bottom right, 6: top, 7: bottom, 8: left, 9: right, "
    "10: full, 11: top third, 12: in model coordinates)" },
  { F|O, "Axes" , opt_view_axes , 0 ,
    "Axes (0=none, 1=simple axes, 2=box, 3=full grid, 4=open grid, 5=ruler)" },
  { F|O, "AxesMikado" , opt_view_axes_mikado , 0. ,
    "Mikado axes style" },
  { F|O, "AxesAutoPosition" , opt_view_axes_auto_position , 1. ,
    "Position the axes automatically" },
  { F|O, "AxesMaxX" , opt_view_axes_xmax , 1. ,
    "Maximum X-axis coordinate" },
  { F|O, "AxesMaxY" , opt_view_axes_ymax , 1. ,
    "Maximum Y-axis coordinate" },
  { F|O, "AxesMaxZ" , opt_view_axes_zmax , 1. ,
    "Maximum Z-axis coordinate" },
  { F|O, "AxesMinX" , opt_view_axes_xmin , 0. ,
    "Minimum X-axis coordinate" },
  { F|O, "AxesMinY" , opt_view_axes_ymin , 0. ,
    "Minimum Y-axis coordinate" },
  { F|O, "AxesMinZ" , opt_view_axes_zmin , 0. ,
    "Minimum Z-axis coordinate" },
  { F|O, "AxesTicsX" , opt_view_axes_tics0 , 5. ,
    "Number of tics on the X-axis" },
  { F|O, "AxesTicsY" , opt_view_axes_tics1 , 5. ,
    "Number of tics on the Y-axis" },
  { F|O, "AxesTicsZ" , opt_view_axes_tics2 , 5. ,
    "Number of tics on the Z-axis" },

  { F|O, "Boundary" , opt_view_boundary , 0. ,
    "Draw the `N minus b'-dimensional boundary of the element (N=element "
    "dimension, b=option value)" },

  { F|O, "CenterGlyphs" , opt_view_center_glyphs , 0,
    "Center glyphs (arrows, numbers, etc.)? (0=left, 1=centered, 2=right)" },
  { F,   "Clip" , opt_view_clip , 0.,
    "Enable clipping planes? (Plane[i]=2^i, i=0,...,5)" },
  { F|O, "Closed" , opt_view_closed , 0,
    "Close the subtree containing this view" },
  { F|O, "ColormapAlpha" , opt_view_colormap_alpha , 1.0 ,
    "Colormap alpha channel value (used only if != 1)" },
  { F|O, "ColormapAlphaPower" , opt_view_colormap_alpha_power , 0.0 ,
    "Colormap alpha channel power" },
  { F|O, "ColormapBeta" , opt_view_colormap_beta , 0.0 ,
    "Colormap beta parameter (gamma = 1-beta)" },
  { F|O, "ColormapBias" , opt_view_colormap_bias , 0.0 ,
    "Colormap bias" },
  { F|O, "ColormapCurvature" , opt_view_colormap_curvature , 0.0 ,
    "Colormap curvature or slope coefficient" },
  { F|O, "ColormapInvert" , opt_view_colormap_invert , 0. ,
    "Invert the color values, i.e., replace x with (255-x) in the colormap?" },
  { F|O, "ColormapNumber" , opt_view_colormap_number , 2. ,
    "Default colormap number (0: black, 1: vis5d, 2: jet, 3: lucie, 4: rainbow, "
    "5: emc2000, 6: incadescent, 7: hot, 8: pink, 9: grayscale, 10: french, "
    "11: hsv, 12: spectrum, 13: bone, 14: spring, 15: summer, 16: autumm, "
    "17: winter, 18: cool, 19: copper, 20: magma, 21: inferno, 22: plasma, "
    "23: viridis)"},
  { F|O, "ColormapRotation" , opt_view_colormap_rotation , 0. ,
    "Incremental colormap rotation" },
  { F|O, "ColormapSwap" , opt_view_colormap_swap , 0. ,
    "Swap the min/max values in the colormap?" },
  { F|O, "ComponentMap0" , opt_view_component_map0 , 0,
    "Forced component 0 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap1" , opt_view_component_map1 , 1,
    "Forced component 1 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap2" , opt_view_component_map2 , 2,
    "Forced component 2 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap3" , opt_view_component_map3 , 3,
    "Forced component 3 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap4" , opt_view_component_map4 , 4,
    "Forced component 4 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap5" , opt_view_component_map5 , 5,
    "Forced component 5 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap6" , opt_view_component_map6 , 6,
    "Forced component 6 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap7" , opt_view_component_map7 , 7,
    "Forced component 7 (if View.ForceComponents > 0)" },
  { F|O, "ComponentMap8" , opt_view_component_map8 , 8,
    "Forced component 8 (if View.ForceComponents > 0)" },
  { F,   "CustomAbscissaMax" , opt_view_custom_abscissa_max , 0. ,
    "User-defined maximum abscissa value" },
  { F,   "CustomAbscissaMin" , opt_view_custom_abscissa_min , 0. ,
    "User-defined minimum abscissa value" },
  { F,   "CustomMax" , opt_view_custom_max , 0. ,
    "User-defined maximum value to be displayed" },
  { F,   "CustomMin" , opt_view_custom_min , 0. ,
    "User-defined minimum value to be displayed" },

  { F|O, "DisplacementFactor" , opt_view_displacement_factor , 1. ,
    "Displacement amplification" },
  { F|O, "DrawHexahedra" , opt_view_draw_hexahedra , 1. ,
    "Display post-processing hexahedra?" },
  { F|O, "DrawLines" , opt_view_draw_lines , 1. ,
    "Display post-processing lines?" },
  { F|O, "DrawPoints" , opt_view_draw_points , 1. ,
    "Display post-processing points?" },
  { F|O, "DrawPrisms" , opt_view_draw_prisms , 1. ,
    "Display post-processing prisms?" },
  { F|O, "DrawPyramids" , opt_view_draw_pyramids , 1. ,
    "Display post-processing pyramids?" },
  { F|O, "DrawTrihedra" , opt_view_draw_trihedra , 1. ,
    "Display post-processing trihedra?" },
  { F|O, "DrawQuadrangles" , opt_view_draw_quadrangles , 1. ,
    "Display post-processing quadrangles?" },
  { F|O, "DrawScalars" , opt_view_draw_scalars , 1. ,
    "Display scalar values?" },
  { F|O, "DrawSkinOnly" , opt_view_draw_skin_only , 0. ,
    "Draw only the skin of 3D scalar views?" },
  { F|O, "DrawStrings" , opt_view_draw_strings , 1. ,
    "Display post-processing annotation strings?" },
  { F|O, "DrawTensors" , opt_view_draw_tensors , 1. ,
    "Display tensor values?" },
  { F|O, "DrawTetrahedra" , opt_view_draw_tetrahedra , 1. ,
    "Display post-processing tetrahedra?" },
  { F|O, "DrawTriangles" , opt_view_draw_triangles , 1. ,
    "Display post-processing triangles?" },
  { F|O, "DrawVectors" , opt_view_draw_vectors , 1. ,
    "Display vector values?" },

  { F|O, "Explode" , opt_view_explode , 1. ,
    "Element shrinking factor (between 0 and 1)" },
  { F|O, "ExternalView" , opt_view_external_view , -1. ,
    "Index of the view used to color vector fields (-1=self)" },

  { F|O, "FakeTransparency" , opt_view_fake_transparency , 0. ,
    "Use fake transparency (cheaper than the real thing, but incorrect)" },
  { F|O, "ForceNumComponents" , opt_view_force_num_components , 0. ,
    "Force number of components to display (see View.ComponentMapN for mapping)" },

  { F|O, "GeneralizedRaiseFactor" , opt_view_gen_raise_factor , 1. ,
    "Generalized raise amplification factor" },
  { F|O, "GeneralizedRaiseView" , opt_view_gen_raise_view , -1. ,
    "Index of the view used for generalized raise (-1=self)" },
  { F|O, "GlyphLocation" , opt_view_glyph_location , 1,
    "Glyph (arrow, number, etc.) location (1=center of gravity, 2=node)" },

  { F|O, "Height" , opt_view_size1 , 200. ,
    "Height (in pixels) of the scale or 2D plot" },

  { F|O, "IntervalsType" , opt_view_intervals_type , 2 ,
    "Type of interval display (1=iso, 2=continuous, 3=discrete, 4=numeric)" },

  { F|O, "Light" , opt_view_light , 1. ,
    "Enable lighting for the view" },
  { F|O, "LightLines" , opt_view_light_lines , 1. ,
    "Light element edges" },
  { F|O, "LightTwoSide" , opt_view_light_two_side , 0. ,
    "Light both sides of surfaces (leads to slower rendering)" },
  { F|O, "LineType" , opt_view_line_type , 0. ,
    "Display lines as solid color segments (0) or 3D cylinders (1)" },
  { F|O, "LineWidth" , opt_view_line_width , 1.0 ,
    "Display width of lines (in pixels)" },

  { F|O,   "MaxRecursionLevel" , opt_view_max_recursion_level , 0. ,
    "Maximum recursion level for adaptive views" },
  { F,   "Max" , opt_view_max , 0. ,
    "Maximum value in the view (read-only)" },
  { F,   "MaxVisible" , opt_view_max_visible , 0. ,
    "Maximum value in the visible parts of the view (read-only)" },
  { F,   "MaxX" , opt_view_xmax , 0. ,
    "Maximum view coordinate along the X-axis (read-only)" },
  { F,   "MaxY" , opt_view_ymax , 0. ,
    "Maximum view coordinate along the Y-axis (read-only)" },
  { F,   "MaxZ" , opt_view_zmax , 0. ,
    "Maximum view coordinate along the Z-axis (read-only)" },
  { F,   "Min" , opt_view_min , 0. ,
    "Minimum value in the view (read-only)" },
  { F,   "MinVisible" , opt_view_min_visible , 0. ,
    "Minimum value in the visible parts of the view (read-only)" },
  { F,   "MinX" , opt_view_xmin , 0. ,
    "Minimum view coordinate along the X-axis (read-only)" },
  { F,   "MinY" , opt_view_ymin , 0. ,
    "Minimum view coordinate along the Y-axis (read-only)" },
  { F,   "MinZ" , opt_view_zmin , 0. ,
    "Minimum view coordinate along the Z-axis (read-only)" },

  { F|O, "NbIso" , opt_view_nb_iso , 10. ,
    "Number of intervals" },
  { F,   "NbTimeStep" , opt_view_nb_timestep , 1. ,
    "Number of time steps in the view (do not change this!)" },
  { F,   "NormalRaise" , opt_view_normal_raise , 0. ,
    "Elevation of the view along the normal (in model coordinates)" },
  { F|O, "Normals" , opt_view_normals , 0. ,
    "Display size of normal vectors (in pixels)" },

  { F,   "OffsetX" , opt_view_offset0 , 0. ,
    "Translation of the view along X-axis (in model coordinates)" },
  { F,   "OffsetY" , opt_view_offset1 , 0. ,
    "Translation of the view along Y-axis (in model coordinates)" },
  { F,   "OffsetZ" , opt_view_offset2 , 0. ,
    "Translation of the view along Z-axis (in model coordinates)" },

  { F|O, "PointSize" , opt_view_point_size , 3. ,
    "Display size of points (in pixels)" },
  { F|O, "PointType" , opt_view_point_type , 0. ,
    "Display points as solid color dots (0), 3D spheres (1), scaled dots "
    "(2) or scaled spheres (3)" },
  { F|O, "PositionX" , opt_view_position0 , 100. ,
    "X position (in pixels) of the scale or 2D plot (< 0: measure from right "
    "edge; >= 1e5: centered)" },
  { F|O, "PositionY" , opt_view_position1 , 50. ,
    "Y position (in pixels) of the scale or 2D plot (< 0: measure from bottom "
    "edge; >= 1e5: centered)" },

  { F,   "RaiseX" , opt_view_raise0 , 0. ,
    "Elevation of the view along X-axis (in model coordinates)" },
  { F,   "RaiseY" , opt_view_raise1 , 0. ,
    "Elevation of the view along Y-axis (in model coordinates)" },
  { F,   "RaiseZ" , opt_view_raise2 , 0. ,
    "Elevation of the view along Z-axis (in model coordinates)" },
  { F|O, "RangeType" , opt_view_range_type , 1 ,
    "Value scale range type (1=default, 2=custom, 3=per time step)" },

  { F|O, "Sampling" , opt_view_sampling , 1. ,
    "Element sampling rate (draw one out every `Sampling' elements)" },
  { F|O, "SaturateValues" , opt_view_saturate_values , 0. ,
    "Saturate the view values to custom min and max (1=true, 0=false)" },
  { F|O, "ScaleType" , opt_view_scale_type , 1 ,
    "Value scale type (1=linear, 2=logarithmic, 3=double logarithmic)" },
  { F|O, "ShowElement" , opt_view_show_element , 0. ,
    "Show element boundaries?" },
  { F|O, "ShowScale" , opt_view_show_scale , 1. ,
    "Show value scale?" },
  { F|O, "ShowTime" , opt_view_show_time , 3. ,
    "Time display mode (0=none, 1=time series, 2=harmonic data, 3=automatic, "
    "4=step data, 5=multi-step data, 6=real eigenvalues, 7=complex eigenvalues)" },
  { F|O, "SmoothNormals" , opt_view_smooth_normals , 0. ,
    "Smooth the normals?" },
  { F|O, "Stipple" , opt_view_use_stipple , 0. ,
    "Stipple curves in 2D plots?" },

  { F|O, "Tangents" , opt_view_tangents , 0. ,
    "Display size of tangent vectors (in pixels)" },
  { F|O, "TargetError" , opt_view_target_error , 0.01 ,
    "Target representation error for adaptive views" },
  { F|O, "TensorType" , opt_view_tensor_type , 1. ,
    "Tensor Visualization Type" },
  { F,   "TimeStep" , opt_view_timestep , 0. ,
    "Current time step displayed" },
  { F,   "Time" , opt_view_time , -1. ,
    "Current time displayed (if positive, sets the time step corresponding "
    "the given time value)" },
  { F,   "TransformXX" , opt_view_transform00 , 1. ,
    "Element (1,1) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformXY" , opt_view_transform01 , 0. ,
    "Element (1,2) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformXZ" , opt_view_transform02 , 0. ,
    "Element (1,3) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformYX" , opt_view_transform10 , 0. ,
    "Element (2,1) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformYY" , opt_view_transform11 , 1. ,
    "Element (2,2) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformYZ" , opt_view_transform12 , 0. ,
    "Element (2,3) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformZX" , opt_view_transform20 , 0. ,
    "Element (3,1) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformZY" , opt_view_transform21 , 0. ,
    "Element (3,2) of the 3x3 coordinate transformation matrix" },
  { F,   "TransformZZ" , opt_view_transform22 , 1. ,
    "Element (3,3) of the 3x3 coordinate transformation matrix" },
  { F,   "Type" , opt_view_type , 1 ,
    "Type of plot (1=3D, 2=2D space, 3=2D time, 4=2D)" },

  { F|O, "UseGeneralizedRaise" , opt_view_use_gen_raise , 0 ,
    "Use generalized raise?" },

  { F|O, "VectorType" , opt_view_vector_type , 4 ,
    "Vector display type (1=segment, 2=arrow, 3=pyramid, 4=3D arrow, "
    "5=displacement, 6=comet)" },
  { F,   "Visible" , opt_view_visible , 1. ,
    "Is the view visible?" },

  { F|O, "Width" , opt_view_size0 , 300. ,
    "Width (in pixels) of the scale or 2D plot" },

  { 0, 0 , 0 , 0. , 0 }
} ;

StringXNumber PrintOptions_Number[] = {
  { F|O, "Parameter" , opt_print_parameter , 0. ,
    "Current value of the print parameter" },
  { F|O, "ParameterFirst" , opt_print_parameter_first , -1. ,
    "First value of print parameter in loop" },
  { F|O, "ParameterLast" , opt_print_parameter_last , 1. ,
    "Last value of print parameter in loop" },
  { F|O, "ParameterSteps" , opt_print_parameter_steps , 10. ,
    "Number of steps in loop over print parameter" },

  { F|O, "Background" , opt_print_background , 0. ,
    "Print background (gradient and image)?" },

  { F|O, "CompositeWindows" , opt_print_composite_windows , 0. ,
    "Composite all window tiles in the same output image (for bitmap output only)" },

  { F|O, "PgfTwoDim" , opt_print_pgf_two_dim , 1. ,
    "Output PGF format for two dimensions. Mostly irrelevant if `PgfExportAxis=0`. "
    "Default `1` (yes)." },

  { F|O, "PgfExportAxis" , opt_print_pgf_export_axis , 0. ,
    "Include axis in export pgf code (not in the png). Default `0` (no)." },

  { F|O, "PgfHorizontalBar" , opt_print_pgf_horiz_bar , 0. ,
    "Use a horizontal color bar in the pgf output. Default `0` (no)." },

  { F|O, "DeleteTemporaryFiles" , opt_print_delete_tmp_files , 1. ,
    "Delete temporary files used during printing" },

  { F|O, "EpsBestRoot" , opt_print_eps_best_root , 1. ,
    "Try to minimize primitive splitting in BSP tree sorted PostScript/PDF output" },
  { F|O, "EpsCompress" , opt_print_eps_compress , 0. ,
    "Compress PostScript/PDF output using zlib" },
  { F|O, "EpsLineWidthFactor" , opt_print_eps_line_width_factor , 1.0 ,
    "Width factor for lines in PostScript/PDF output" },
  { F|O, "EpsOcclusionCulling" , opt_print_eps_occlusion_culling , 1. ,
    "Cull occluded primitives (to reduce PostScript/PDF file size)" },
  { F|O, "EpsPointSizeFactor" , opt_print_eps_point_size_factor , 1.0 ,
    "Size factor for points in PostScript/PDF output" },
  { F|O, "EpsPS3Shading" , opt_print_eps_ps3shading , 0. ,
    "Enable PostScript Level 3 shading" },
  { F|O, "EpsQuality" , opt_print_eps_quality , 1. ,
    "PostScript/PDF quality (0=bitmap, 1=vector (simple sort), 2=vector "
    "(accurate sort), 3=vector (unsorted)" },

  { F|O, "Format" , opt_print_file_format , FORMAT_AUTO ,
    "File format (10=automatic)" },

  { F|O, "GeoLabels" , opt_print_geo_labels , 1. ,
    "Save labels in unrolled Gmsh geometries" },
  { F|O, "GeoOnlyPhysicals" , opt_print_geo_only_physicals , 0. ,
    "Only save entities that belong to physical groups" },
  { F|O, "GifDither" , opt_print_gif_dither , 0. ,
    "Apply dithering to GIF output" },
  { F|O, "GifInterlace" , opt_print_gif_interlace , 0. ,
    "Interlace GIF output" },
  { F|O, "GifSort" , opt_print_gif_sort , 1. ,
    "Sort the colormap in GIF output" },
  { F|O, "GifTransparent" , opt_print_gif_transparent , 0. ,
    "Output transparent GIF image" },

  { F|O, "Height" , opt_print_height , -1. ,
    "Height of printed image; use (possibly scaled) current height if < 0" },

  { F|O, "JpegQuality" , opt_print_jpeg_quality , 100. ,
    "JPEG quality (between 1 and 100)" },
  { F|O, "JpegSmoothing" , opt_print_jpeg_smoothing , 0. ,
    "JPEG smoothing (between 0 and 100)" },

  { F|O, "PostElementary" , opt_print_pos_elementary , 1. ,
    "Save elementary region tags in mesh statistics exported as "
    "post-processing views" },
  { F|O, "PostElement" , opt_print_pos_element , 0. ,
    "Save element numbers in mesh statistics exported as post-processing views" },
  { F|O, "PostGamma" , opt_print_pos_gamma , 0. ,
    "Save Gamma quality measure in mesh statistics exported as "
    "post-processing views" },
  { F|O, "PostEta" , opt_print_pos_eta , 0. ,
    "Save Eta quality measure in mesh statistics exported as "
    "post-processing views" },
  { F|O, "PostRho" , opt_print_pos_rho , 0. ,
    "Save Rho quality measure in mesh statistics exported as "
    "post-processing views" },
  { F|O, "PostDisto" , opt_print_pos_disto , 0. ,
    "Save Disto quality measure in mesh statistics exported as "
    "post-processing views" },

  { F|O, "TexAsEquation" , opt_print_tex_as_equation , 0. ,
    "Print all TeX strings as equations" },
  { F|O, "Text" , opt_print_text , 1. ,
    "Print text strings?" },

  { F|O, "X3dCompatibility" , opt_print_x3d_compatibility, 0. ,
    "Produce highliy compatible X3D output (no scale bar)" },
  { F|O, "X3dPrecision" , opt_print_x3d_precision , 1.e-9 ,
    "Precision of X3D output" },
  { F|O, "X3dRemoveInnerBorders" , opt_print_x3d_remove_inner_borders , 0. ,
    "Remove inner borders in X3D output" },
  { F|O, "X3dTransparency" , opt_print_x3d_transparency , 0. ,
    "Transparency for X3D output" },

  { F|O, "Width" , opt_print_width , -1. ,
    "Width of printed image; use (possibly scaled) current width if < 0)" },

  { 0, 0 , 0 , 0. }
} ;

// COLORS

// CONTRARY TO THE PRECEDING OPTIONS, THE ORDERING OF COLOR OPTIONS MATTERS !

// Solid Works (light blue to light gray): 94,198,255 -> 232,232,232
// Catia (dark grey-blue to light gray-blue): 63,62,119 -> 181,182,202

StringXColor GeneralOptions_Color[] = {
  { F|O, "Background" , opt_general_color_background ,
    {245, 245, 245, 255}, {255, 255, 255, 255}, {245, 245, 245, 255}, {50, 50, 50, 255},
    "Background color" },
  { F|O, "BackgroundGradient" , opt_general_color_background_gradient ,
    {185, 185, 185, 255}, {208, 215, 255, 255}, {185, 185, 185, 255}, {50, 50, 50, 255},
    "Background gradient color" },
  { F|O, "Foreground" , opt_general_color_foreground ,
    {85, 85, 85, 255}, {85, 85, 85, 255}, {85, 85, 85, 255}, {170, 170, 170, 255},
    "Foreground color" },
  { F|O, "Text" , opt_general_color_text ,
    {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}, {245, 245, 245, 255},
    "Text color" },
  { F|O, "Axes" , opt_general_color_axes ,
    {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}, {245, 245, 245, 255},
    "Axes color" },
  { F|O, "SmallAxes" , opt_general_color_small_axes ,
    {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}, {245, 245, 245, 255},
    "Small axes color" },
  { F|O, "AmbientLight" , opt_general_color_ambient_light,
    {25, 25, 25, 255}, {25, 25, 25, 255}, {25, 25, 25, 255}, {25, 25, 25, 255},
    "Ambient light color" },
  { F|O, "DiffuseLight" , opt_general_color_diffuse_light,
    {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255},
    "Diffuse light color" },
  { F|O, "SpecularLight" , opt_general_color_specular_light,
    {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255}, {255, 255, 255, 255},
    "Specular light color" },
  { 0, 0 , 0 ,  {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , {0, 0, 0, 0} , 0 }
} ;

StringXColor GeometryOptions_Color[] = {
  { F|O, "Points" , opt_geometry_color_points ,
    {90, 90, 90, 255}, {90, 90, 90, 255}, {0, 0, 0, 255}, {178, 178, 178, 255},
    "Normal geometry point color" },
  { F|O, "Lines" , opt_geometry_color_lines ,
    {0, 0, 255, 255}, {0, 0, 255, 255}, {0, 0, 0, 255}, {0, 0, 255, 255},
    "Normal geometry curve color" },
  { F|O, "Surfaces" , opt_geometry_color_surfaces ,
    {128, 128, 128, 255}, {128, 128, 128, 255}, {0, 0, 0, 255}, {128, 128, 128, 255},
    "Normal geometry surface color" },
  { F|O, "Volumes" , opt_geometry_color_volumes ,
    {255, 255, 0, 255}, {255, 255, 0, 255}, {0, 0, 0, 255}, {255, 255, 0, 255},
    "Normal geometry volume color" },
  { F|O, "Selection" , opt_geometry_color_selection ,
    {255, 0, 0, 255}, {255, 0, 0, 255}, {255, 0, 0, 255}, {255, 0, 0, 255},
    "Selected geometry color" },
  { F|O, "HighlightZero" , opt_geometry_color_highlight0 ,
    {255, 0, 0, 255}, {255, 0, 0, 255}, {255, 0, 0, 255}, {255, 0, 0, 255},
    "Highlight 0 color" },
  { F|O, "HighlightOne" , opt_geometry_color_highlight1 ,
    {255, 150, 0, 255}, {255, 150, 0, 255}, {255, 150, 0, 255}, {255, 150, 0, 255},
    "Highlight 1 color" },
  { F|O, "HighlightTwo" , opt_geometry_color_highlight2 ,
    {255, 255, 0, 255}, {255, 255, 0, 255}, {255, 255, 0, 255}, {255, 255, 0, 255},
    "Highlight 2 color" },
  { F|O, "Tangents" , opt_geometry_color_tangents ,
    {255, 255, 0, 255}, {255, 255, 0, 255}, {0, 0, 0, 255}, {255, 255, 0, 255},
    "Tangent geometry vectors color" },
  { F|O, "Normals" , opt_geometry_color_normals ,
    {255, 0, 0, 255}, {255, 0, 0, 255}, {0, 0, 0, 255}, {255, 0, 0, 255},
    "Normal geometry vectors color" },
  { F|O, "Projection" , opt_geometry_color_projection ,
    {0, 255, 0, 255}, {0, 255, 0, 255}, {0, 0, 0, 255}, {0, 255, 0, 255},
    "Projection surface color" },
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , 0 }
} ;

#define COLW  {210, 210, 210, 255}
#define COLT  {160, 150, 255, 255}
#define COLQ  {130, 120, 225, 255}
#define COLP  {232, 210, 23, 255}
#define COLY  {217, 113, 38, 255}
#define COLR  {20, 255, 0, 255}

#define COL0  {255, 120, 0, 255}
#define COL2  {255, 160, 0, 255}
#define COL4  {255, 200, 0, 255}
#define COL6  {255, 240, 0, 255}
#define COL8  {228, 255, 0, 255}
#define COL10  {188, 255, 0, 255}
#define COL12  {148, 255, 0, 255}
#define COL14  {108, 255, 0, 255}
#define COL16  {68, 255, 0, 255}
#define COL18  {0, 255, 52, 255}
#define COL1 {0, 255, 132, 255}
#define COL3 {0, 255, 192, 255}
#define COL5 {0, 216, 255, 255}
#define COL7 {0, 176, 255, 255}
#define COL9 {0, 116, 255, 255}
#define COL11 {0, 76, 255, 255}
#define COL13 {24, 0, 255, 255}
#define COL15 {84, 0, 255, 255}
#define COL17 {104, 0, 255, 255}
#define COL19 {184, 0, 255, 255}

StringXColor MeshOptions_Color[] = {
  { F|O, "Points" , opt_mesh_color_points ,
    {0, 0, 255, 255}, {0, 0, 255, 255}, {0, 0, 0, 255}, {0, 0, 255, 255},
    "Mesh node color" },
  { F|O, "PointsSup" , opt_mesh_color_points_sup ,
    {255, 0, 255, 255}, {255, 0, 255, 255}, {0, 0, 0, 255}, {255, 0, 255, 255},
    "Second order mesh node color" },
  { F|O, "Lines" , opt_mesh_color_lines ,
    {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255},
    "Mesh line color" },
  { F|O, "Triangles" , opt_mesh_color_triangles ,
    COLT, COLT, COLW, COLT,
    "Mesh triangle color (if Mesh.ColorCarousel=0)" },
  { F|O, "Quadrangles" , opt_mesh_color_quadrangles ,
    COLQ, COLQ, COLW, COLQ,
    "Mesh quadrangle color (if Mesh.ColorCarousel=0)" },
  { F|O, "Tetrahedra" , opt_mesh_color_tetrahedra ,
    COLT, COLT, COLW, COLT,
     "Mesh tetrahedron color (if Mesh.ColorCarousel=0)" },
  { F|O, "Hexahedra" , opt_mesh_color_hexahedra ,
    COLQ, COLQ, COLW, COLQ,
    "Mesh hexahedron color (if Mesh.ColorCarousel=0)" },
  { F|O, "Prisms" , opt_mesh_color_prisms ,
    COLP, COLP, COLW, COLP,
     "Mesh prism color (if Mesh.ColorCarousel=0)" },
  { F|O, "Pyramids" , opt_mesh_color_pyramid ,
    COLY, COLY, COLW, COLY,
     "Mesh pyramid color (if Mesh.ColorCarousel=0)" },
  { F|O, "Trihedra" , opt_mesh_color_trihedron ,
    COLR, COLR, COLW, COLR,
     "Mesh trihedron color (if Mesh.ColorCarousel=0)" },
  { F|O, "Tangents" , opt_mesh_color_tangents ,
    {255, 255, 0, 255}, {255, 255, 0, 255}, {0, 0, 0, 255}, {255, 255, 0, 255},
    "Tangent mesh vector color" },
  { F|O, "Normals" , opt_mesh_color_normals ,
    {255, 0, 0, 255}, {255, 0, 0, 255}, {0, 0, 0, 255}, {255, 0, 0, 255},
    "Normal mesh vector color" },
  { F|O, "Zero"     , opt_mesh_color_0 , COL0, COL0, COLW, COL0,
    "Color 0 in color carousel" },
  { F|O, "One"      , opt_mesh_color_1 , COL1, COL1, COLW, COL1,
    "Color 1 in color carousel" },
  { F|O, "Two"      , opt_mesh_color_2 , COL2, COL2, COLW, COL2,
    "Color 2 in color carousel" },
  { F|O, "Three"    , opt_mesh_color_3 , COL3, COL3, COLW, COL3,
    "Color 3 in color carousel" },
  { F|O, "Four"     , opt_mesh_color_4 , COL4, COL4, COLW, COL4,
    "Color 4 in color carousel" },
  { F|O, "Five"     , opt_mesh_color_5 , COL5, COL5, COLW, COL5,
    "Color 5 in color carousel" },
  { F|O, "Six"      , opt_mesh_color_6 , COL6, COL6, COLW, COL6,
    "Color 6 in color carousel" },
  { F|O, "Seven"    , opt_mesh_color_7 , COL7, COL7, COLW, COL7,
    "Color 7 in color carousel" },
  { F|O, "Eight"    , opt_mesh_color_8 , COL8, COL8, COLW, COL8,
    "Color 8 in color carousel" },
  { F|O, "Nine"     , opt_mesh_color_9 , COL9, COL9, COLW, COL9,
    "Color 9 in color carousel" },
  { F|O, "Ten"      , opt_mesh_color_10, COL10, COL10, COLW, COL10,
    "Color 10 in color carousel" },
  { F|O, "Eleven"   , opt_mesh_color_11, COL11, COL11, COLW, COL11,
    "Color 11 in color carousel" },
  { F|O, "Twelve"   , opt_mesh_color_12, COL12, COL12, COLW, COL12,
    "Color 12 in color carousel" },
  { F|O, "Thirteen" , opt_mesh_color_13, COL13, COL13, COLW, COL13,
    "Color 13 in color carousel" },
  { F|O, "Fourteen" , opt_mesh_color_14, COL14, COL14, COLW, COL14,
    "Color 14 in color carousel" },
  { F|O, "Fifteen"  , opt_mesh_color_15, COL15, COL15, COLW, COL15,
    "Color 15 in color carousel" },
  { F|O, "Sixteen"  , opt_mesh_color_16, COL16, COL16, COLW, COL16,
    "Color 16 in color carousel" },
  { F|O, "Seventeen", opt_mesh_color_17, COL17, COL17, COLW, COL17,
    "Color 17 in color carousel" },
  { F|O, "Eighteen" , opt_mesh_color_18, COL18, COL18, COLW, COL18,
    "Color 18 in color carousel" },
  { F|O, "Nineteen" , opt_mesh_color_19, COL19, COL19, COLW, COL19,
    "Color 19 in color carousel" },
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , {0, 0, 0, 0} , 0 }
} ;

StringXColor SolverOptions_Color[] = {
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , 0 }
} ;

StringXColor PostProcessingOptions_Color[] = {
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , 0 }
} ;

#define ELECOL  {0, 0, 0, 255}, {0, 0, 0, 255}, {0, 0, 0, 255}, {245, 245, 245, 255}

StringXColor ViewOptions_Color[] = {
  { F|O, "Points" , opt_view_color_points , ELECOL, "Point color" },
  { F|O, "Lines" , opt_view_color_lines , ELECOL, "Line color" },
  { F|O, "Triangles" , opt_view_color_triangles , ELECOL, "Triangle color" },
  { F|O, "Quadrangles" , opt_view_color_quadrangles , ELECOL, "Quadrangle color" },
  { F|O, "Tetrahedra" , opt_view_color_tetrahedra , ELECOL, "Tetrahedron color" },
  { F|O, "Hexahedra" , opt_view_color_hexahedra , ELECOL, "Hexahedron color" },
  { F|O, "Prisms" , opt_view_color_prisms , ELECOL, "Prism color" },
  { F|O, "Pyramids" , opt_view_color_pyramids , ELECOL, "Pyramid color" },
  { F|O, "Trihedra" , opt_view_color_trihedra , ELECOL, "Trihedron color" },
  { F|O, "Tangents" , opt_view_color_tangents ,
    {255, 255, 0, 255}, {255, 255, 0, 255}, {0, 0, 0, 255}, {255, 255, 0, 255},
    "Tangent vector color" },
  { F|O, "Normals" , opt_view_color_normals ,
    {255, 0, 0, 255}, {255, 0, 0, 255}, {0, 0, 0, 255}, {255, 0, 0, 255},
    "Normal vector color" },
  { F|O, "Text2D" , opt_view_color_text2d , ELECOL, "2D text color" },
  { F|O, "Text3D" , opt_view_color_text3d , ELECOL, "3D text color" },
  { F|O, "Axes" , opt_view_color_axes , ELECOL, "Axes color" },
  { F|O, "Background2D" , opt_view_color_background2d ,
    {255, 255, 255, 200}, {255, 255, 255, 200}, {255, 255, 255, 200}, {245, 245, 245, 200},
    "Bacground color for 2D plots" },
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , 0 }
} ;

StringXColor PrintOptions_Color[] = {
  { 0, 0 , 0 , {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} , 0 }
} ;

#undef S
#undef O
#undef F

#endif

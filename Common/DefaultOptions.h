#ifndef _DEFAULT_OPTIONS_H_
#define _DEFAULT_OPTIONS_H_

// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Options.h"
#include "Context.h"
#include "Mesh.h"
#include "Views.h"

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
  { F|S, "DefaultFileName" , opt_general_default_filename , "untitled.geo" ,
    "Default project file name" },
  { F,   "Display" , opt_general_display , "" ,
    "X server to use (only for Unix versions)" },

  { F|S, "ErrorFileName" , opt_general_error_filename , ".gmsh-errors" ,
    "File into which the log is saved if a fatal error occurs" },

  { F|S, "OptionsFileName" , opt_general_options_filename , ".gmsh-options" ,
    "Option file created with `Tools->Options->Save'; automatically read on startup" },

  { 0,   "SessionFileName" , opt_general_session_filename , ".gmshrc" ,
    "Option file into which session specific information is saved; automatically read on startup" },

#if defined(WIN32)
  { F|O, "TextEditor" , opt_general_editor , "notepad.exe %s" , 
#else
  { F|O, "TextEditor" , opt_general_editor , "emacs %s &" ,
#endif
    "System command to launch a text editor (OS-dependent)" },
  { F|S,   "Scheme" , opt_general_scheme , "" ,
    "FLTK graphical user interface scheme (try e.g. plastic)" },
  { F|S, "TmpFileName" , opt_general_tmp_filename , ".gmsh-tmp" ,
    "Temporary file used by the geometry module" },

  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString GeometryOptions_String[] = {
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString MeshOptions_String[] = {
  { F|O, "TriangleOptions" , opt_mesh_triangle_options , "praqzBPY" , 
    "Options for Jonathan Shewchuk's Triangle isotropic algorithm" },
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString SolverOptions_String[] = {
  { F|O, "Name0" , opt_solver_name0 , "GetDP" ,
    "Name of solver 0" },
  { F|O, "Help0" , opt_solver_help0 , 
    "A General environment for the treatment of\nDiscrete Problems\n\n"
    "Copyright (c) 1997-2003\nPatrick Dular and Christophe Geuzaine\n\n"
    "Visit http://www.geuz.org/getdp/ for more info",
    "Help string for solver 0" },
  { F|O, "Executable0" , opt_solver_executable0 , 
#if defined(WIN32)
    "getdp.exe" , 
#else
    "getdp" , 
#endif
    "System command to launch solver 0 (should not contain the `&' character)" },
  { F|O, "Extension0" , opt_solver_extension0 , ".pro" ,
    "Default file name extension for solver 0" },
  { F|O, "MeshName0" , opt_solver_mesh_name0 , "" ,
    "Default mesh file name for solver 0" },
  { F|O, "MeshCommand0" , opt_solver_mesh_command0 , "-msh %s" ,
    "Command used to specify the mesh file for solver 0" },
  { F|O, "OptionCommand0" , opt_solver_option_command0 , "" ,
    "Command to get options from solver 0" },
  { F|O, "FirstOption0" , opt_solver_first_option0 , "Resolution" ,
    "Label of first option for solver 0" },
  { F|O, "SecondOption0" , opt_solver_second_option0 , "PostOperation" ,
    "Label of second option for solver 0" },
  { F|O, "ThirdOption0" , opt_solver_third_option0 , "" ,
    "Label of third option for solver 0" },
  { F|O, "FourthOption0" , opt_solver_fourth_option0 , "" ,
    "Label of fourth option for solver 0" },
  { F|O, "FifthOption0" , opt_solver_fifth_option0 , "" ,
    "Label of fifth option for solver 0" },
  { F|O, "FirstButton0" , opt_solver_first_button0 , "Pre" ,
    "Label of first button for solver 0" },
  { F|O, "FirstButtonCommand0" , opt_solver_first_button_command0 , "-pre %s" ,
    "Command associated with the first button for solver 0" },
  { F|O, "SecondButton0" , opt_solver_second_button0 , "Cal" ,
    "Label of second button for solver 0" },
  { F|O, "SecondButtonCommand0" , opt_solver_second_button_command0 , "-cal" ,
    "Command associated with the second button for solver 0" },
  { F|O, "ThirdButton0" , opt_solver_third_button0 , "Pos" ,
    "Label of third button for solver 0" },
  { F|O, "ThirdButtonCommand0" , opt_solver_third_button_command0 , "-bin -pos %s" ,
    "Command associated with the third button for solver 0" },
  { F|O, "FourthButton0" , opt_solver_fourth_button0 , "" ,
    "Label of fourth button for solver 0" },
  { F|O, "FourthButtonCommand0" , opt_solver_fourth_button_command0 , "" ,
    "Command associated with the fourth button for solver 0" },
  { F|O, "FifthButton0" , opt_solver_fifth_button0 , "" ,
    "Label of fifth button for solver 0" },
  { F|O, "FifthButtonCommand0" , opt_solver_fifth_button_command0 , "" ,
    "Command associated with the fifth button for solver 0" },

  { F|O, "Name1" , opt_solver_name1 , "" ,
    "Name of solver 1" },
  { F|O, "Help1" , opt_solver_help1 , "" ,
    "Help string for solver 1" },
  { F|O, "Executable1" , opt_solver_executable1 , "" , 
    "System command to launch solver 1 (should not contain the `&' character)" },
  { F|O, "Extension1" , opt_solver_extension1 , "" ,
    "Default file name extension for solver 1" },
  { F|O, "MeshName1" , opt_solver_mesh_name1 , "" ,
    "Default mesh file name for solver 1" },
  { F|O, "MeshCommand1" , opt_solver_mesh_command1 , "" ,
    "Command used to specify the mesh file for solver 1" },
  { F|O, "OptionCommand1" , opt_solver_option_command1 , "" ,
    "Command to get options from solver 1" },
  { F|O, "FirstOption1" , opt_solver_first_option1 , "" ,
    "Label of first option for solver 1" },
  { F|O, "SecondOption1" , opt_solver_second_option1 , "" ,
    "Label of second option for solver 1" },
  { F|O, "ThirdOption1" , opt_solver_third_option1 , "" ,
    "Label of third option for solver 1" },
  { F|O, "FourthOption1" , opt_solver_fourth_option1 , "" ,
    "Label of fourth option for solver 1" },
  { F|O, "FifthOption1" , opt_solver_fifth_option1 , "" ,
    "Label of fifth option for solver 1" },
  { F|O, "FirstButton1" , opt_solver_first_button1 , "" ,
    "Label of first button for solver 1" },
  { F|O, "FirstButtonCommand1" , opt_solver_first_button_command1 , "" ,
    "Command associated with the first button for solver 1" },
  { F|O, "SecondButton1" , opt_solver_second_button1 , "" ,
    "Label of second button for solver 1" },
  { F|O, "SecondButtonCommand1" , opt_solver_second_button_command1 , "" ,
    "Command associated with the second button for solver 1" },
  { F|O, "ThirdButton1" , opt_solver_third_button1 , "" ,
    "Label of third button for solver 1" },
  { F|O, "ThirdButtonCommand1" , opt_solver_third_button_command1 , "" ,
    "Command associated with the third button for solver 1" },
  { F|O, "FourthButton1" , opt_solver_fourth_button1 , "" ,
    "Label of fourth button for solver 1" },
  { F|O, "FourthButtonCommand1" , opt_solver_fourth_button_command1 , "" ,
    "Command associated with the fourth button for solver 1" },
  { F|O, "FifthButton1" , opt_solver_fifth_button1 , "" ,
    "Label of fifth button for solver 1" },
  { F|O, "FifthButtonCommand1" , opt_solver_fifth_button_command1 , "" ,
    "Command associated with the fifth button for solver 1" },

  { F|O, "Name2" , opt_solver_name2 , "" ,
    "Name of solver 2" },
  { F|O, "Help2" , opt_solver_help2 , "" ,
    "Help string for solver 2" },
  { F|O, "Executable2" , opt_solver_executable2 , "" , 
    "System command to launch solver 2 (should not contain the `&' character)" },
  { F|O, "Extension2" , opt_solver_extension2 , "" ,
    "Default file name extension for solver 2" },
  { F|O, "MeshName2" , opt_solver_mesh_name2 , "" ,
    "Default mesh file name for solver 2" },
  { F|O, "MeshCommand2" , opt_solver_mesh_command2 , "" ,
    "Command used to specify the mesh file for solver 2" },
  { F|O, "OptionCommand2" , opt_solver_option_command2 , "" ,
    "Command to get options from solver 2" },
  { F|O, "FirstOption2" , opt_solver_first_option2 , "" ,
    "Label of first option for solver 2" },
  { F|O, "SecondOption2" , opt_solver_second_option2 , "" ,
    "Label of second option for solver 2" },
  { F|O, "ThirdOption2" , opt_solver_third_option2 , "" ,
    "Label of third option for solver 2" },
  { F|O, "FourthOption2" , opt_solver_fourth_option2 , "" ,
    "Label of fourth option for solver 2" },
  { F|O, "FifthOption2" , opt_solver_fifth_option2 , "" ,
    "Label of fifth option for solver 2" },
  { F|O, "FirstButton2" , opt_solver_first_button2 , "" ,
    "Label of first button for solver 2" },
  { F|O, "FirstButtonCommand2" , opt_solver_first_button_command2 , "" ,
    "Command associated with the first button for solver 2" },
  { F|O, "SecondButton2" , opt_solver_second_button2 , "" ,
    "Label of second button for solver 2" },
  { F|O, "SecondButtonCommand2" , opt_solver_second_button_command2 , "" ,
    "Command associated with the second button for solver 2" },
  { F|O, "ThirdButton2" , opt_solver_third_button2 , "" ,
    "Label of third button for solver 2" },
  { F|O, "ThirdButtonCommand2" , opt_solver_third_button_command2 , "" ,
    "Command associated with the third button for solver 2" },
  { F|O, "FourthButton2" , opt_solver_fourth_button2 , "" ,
    "Label of fourth button for solver 2" },
  { F|O, "FourthButtonCommand2" , opt_solver_fourth_button_command2 , "" ,
    "Command associated with the fourth button for solver 2" },
  { F|O, "FifthButton2" , opt_solver_fifth_button2 , "" ,
    "Label of fifth button for solver 2" },
  { F|O, "FifthButtonCommand2" , opt_solver_fifth_button_command2 , "" ,
    "Command associated with the fifth button for solver 2" },

  { F|O, "Name3" , opt_solver_name3 , "" ,
    "Name of solver 3" },
  { F|O, "Help3" , opt_solver_help3 , "" ,
    "Help string for solver 3" },
  { F|O, "Executable3" , opt_solver_executable3 , "" , 
    "System command to launch solver 3 (should not contain the `&' character)" },
  { F|O, "Extension3" , opt_solver_extension3 , "" ,
    "Default file name extension for solver 3" },
  { F|O, "MeshName3" , opt_solver_mesh_name3 , "" ,
    "Default mesh file name for solver 3" },
  { F|O, "MeshCommand3" , opt_solver_mesh_command3 , "" ,
    "Command used to specify the mesh file for solver 3" },
  { F|O, "OptionCommand3" , opt_solver_option_command3 , "" ,
    "Command to get options from solver 3" },
  { F|O, "FirstOption3" , opt_solver_first_option3 , "" ,
    "Label of first option for solver 3" },
  { F|O, "SecondOption3" , opt_solver_second_option3 , "" ,
    "Label of second option for solver 3" },
  { F|O, "ThirdOption3" , opt_solver_third_option3 , "" ,
    "Label of third option for solver 3" },
  { F|O, "FourthOption3" , opt_solver_fourth_option3 , "" ,
    "Label of fourth option for solver 3" },
  { F|O, "FifthOption3" , opt_solver_fifth_option3 , "" ,
    "Label of fifth option for solver 3" },
  { F|O, "FirstButton3" , opt_solver_first_button3 , "" ,
    "Label of first button for solver 3" },
  { F|O, "FirstButtonCommand3" , opt_solver_first_button_command3 , "" ,
    "Command associated with the first button for solver 3" },
  { F|O, "SecondButton3" , opt_solver_second_button3 , "" ,
    "Label of second button for solver 3" },
  { F|O, "SecondButtonCommand3" , opt_solver_second_button_command3 , "" ,
    "Command associated with the second button for solver 3" },
  { F|O, "ThirdButton3" , opt_solver_third_button3 , "" ,
    "Label of third button for solver 3" },
  { F|O, "ThirdButtonCommand3" , opt_solver_third_button_command3 , "" ,
    "Command associated with the third button for solver 3" },
  { F|O, "FourthButton3" , opt_solver_fourth_button3 , "" ,
    "Label of fourth button for solver 3" },
  { F|O, "FourthButtonCommand3" , opt_solver_fourth_button_command3 , "" ,
    "Command associated with the fourth button for solver 3" },
  { F|O, "FifthButton3" , opt_solver_fifth_button3 , "" ,
    "Label of fifth button for solver 3" },
  { F|O, "FifthButtonCommand3" , opt_solver_fifth_button_command3 , "" ,
    "Command associated with the fifth button for solver 3" },

  { F|O, "Name4" , opt_solver_name4 , "" ,
    "Name of solver 4" },
  { F|O, "Help4" , opt_solver_help4 , "" ,
    "Help string for solver 4" },
  { F|O, "Executable4" , opt_solver_executable4 , "" , 
    "System command to launch solver 4 (should not contain the `&' character)" },
  { F|O, "Extension4" , opt_solver_extension4 , "" ,
    "Default file name extension for solver 4" },
  { F|O, "MeshName4" , opt_solver_mesh_name4 , "" ,
    "Default mesh file name for solver 4" },
  { F|O, "MeshCommand4" , opt_solver_mesh_command4 , "" ,
    "Command used to specify the mesh file for solver 4" },
  { F|O, "OptionCommand4" , opt_solver_option_command4 , "" ,
    "Command to get options from solver 4" },
  { F|O, "FirstOption4" , opt_solver_first_option4 , "" ,
    "Label of first option for solver 4" },
  { F|O, "SecondOption4" , opt_solver_second_option4 , "" ,
    "Label of second option for solver 4" },
  { F|O, "ThirdOption4" , opt_solver_third_option4 , "" ,
    "Label of third option for solver 4" },
  { F|O, "FourthOption4" , opt_solver_fourth_option4 , "" ,
    "Label of fourth option for solver 4" },
  { F|O, "FifthOption4" , opt_solver_fifth_option4 , "" ,
    "Label of fifth option for solver 4" },
  { F|O, "FirstButton4" , opt_solver_first_button4 , "" ,
    "Label of first button for solver 4" },
  { F|O, "FirstButtonCommand4" , opt_solver_first_button_command4 , "" ,
    "Command associated with the first button for solver 4" },
  { F|O, "SecondButton4" , opt_solver_second_button4 , "" ,
    "Label of second button for solver 4" },
  { F|O, "SecondButtonCommand4" , opt_solver_second_button_command4 , "" ,
    "Command associated with the second button for solver 4" },
  { F|O, "ThirdButton4" , opt_solver_third_button4 , "" ,
    "Label of third button for solver 4" },
  { F|O, "ThirdButtonCommand4" , opt_solver_third_button_command4 , "" ,
    "Command associated with the third button for solver 4" },
  { F|O, "FourthButton4" , opt_solver_fourth_button4 , "" ,
    "Label of fourth button for solver 4" },
  { F|O, "FourthButtonCommand4" , opt_solver_fourth_button_command4 , "" ,
    "Command associated with the fourth button for solver 4" },
  { F|O, "FifthButton4" , opt_solver_fifth_button4 , "" ,
    "Label of fifth button for solver 4" },
  { F|O, "FifthButtonCommand4" , opt_solver_fifth_button_command4 , "" ,
    "Command associated with the fifth button for solver 4" },

  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString PostProcessingOptions_String[] = {
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString ViewOptions_String[] = {
  { F|O, "AbscissaName" , opt_view_abscissa_name , "" , 
    "Abscissa name for 2D graphs" },
  { F|O, "AbscissaFormat" , opt_view_abscissa_format , "%.3e" , 
    "Abscissa number format for 2D graphs (in standard C form)" },

  { F,   "FileName" , opt_view_filename , "" , 
    "Default post-processing view file name" },
  { F|O, "Format" , opt_view_format , "%.3e" , 
    "Number format (in standard C form)" },

  { F,   "Name" , opt_view_name , "" , 
    "Default post-processing view name" },
  { 0, NULL , NULL , NULL , NULL }
} ;

StringXString PrintOptions_String[] = {
  { F|O, "EpsFont" , opt_print_eps_font , "Courier" , 
    "Font used for postscript printing" },
  { 0, NULL , NULL , NULL , NULL }
} ;

// NUMBERS

StringXNumber GeneralOptions_Number[] = {
  { F|O, "AlphaBlending" , opt_general_alpha_blending , 1. ,
    "Enable alpha blending (transparency) in post-processing views" },
  { F|S, "AppleMenuBar" , opt_general_apple_menu_bar , 0. , 
    "Use Apple-style menu bar?" }, 
  { F|O, "Axes" , opt_general_axes , 1. ,
    "Display the axes linked to the model" },

  { F|O, "CenterWindows" , opt_general_center_windows , 1. , 
    "Center new windows on the menu window" }, 
  { F,   "Clip0" , opt_general_clip0 , 0. ,
    "Enable clip plane 0" },
  { F,   "Clip0A" , opt_general_clip0a , 0.0 ,
    "First coefficient in equation for clip plane 0 (`A' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0B" , opt_general_clip0b , 0.0 , 
    "Second coefficient in equation for clip plane 0 (`B' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0C" , opt_general_clip0c , 0.0 , 
    "Third coefficient in equation for clip plane 0 (`C' in `AX+BY+CZ+D=0')" },
  { F,   "Clip0D" , opt_general_clip0d , 0.0 , 
    "Fourth coefficient in equation for clip plane 0 (`D' in `AX+BY+CZ+D=0')" },
  { F,   "Clip1" , opt_general_clip1 , 0.,
    "Enable clip plane 1" },
  { F,   "Clip1A" , opt_general_clip1a , 0.0 , 
    "First coefficient in equation for clip plane 1" },
  { F,   "Clip1B" , opt_general_clip1b , 0.0 , 
    "Second coefficient in equation for clip plane 1" },
  { F,   "Clip1C" , opt_general_clip1c , 0.0 , 
    "Third coefficient in equation for clip plane 1" },
  { F,   "Clip1D" , opt_general_clip1d , 0.0 , 
    "Fourth coefficient in equation for clip plane 1" },
  { F,   "Clip2" , opt_general_clip2 , 0.,
    "Enable clip plane 2" },
  { F,   "Clip2A" , opt_general_clip2a , 0.0 , 
    "First coefficient in equation for clip plane 2" },
  { F,   "Clip2B" , opt_general_clip2b , 0.0 , 
    "Second coefficient in equation for clip plane 2" },
  { F,   "Clip2C" , opt_general_clip2c , 0.0 , 
    "Third coefficient in equation for clip plane 2" },
  { F,   "Clip2D" , opt_general_clip2d , 0.0 , 
    "Fourth coefficient in equation for clip plane 2" },
  { F,   "Clip3" , opt_general_clip3 , 0.,
    "Enable clip plane 3" },
  { F,   "Clip3A" , opt_general_clip3a , 0.0 , 
    "First coefficient in equation for clip plane 3" },
  { F,   "Clip3B" , opt_general_clip3b , 0.0 , 
    "Second coefficient in equation for clip plane 3" },
  { F,   "Clip3C" , opt_general_clip3c , 0.0 , 
    "Third coefficient in equation for clip plane 3" },
  { F,   "Clip3D" , opt_general_clip3d , 0.0 , 
    "Fourth coefficient in equation for clip plane 3" },
  { F,   "Clip4" , opt_general_clip4 , 0.,
    "Enable clip plane 4" },
  { F,   "Clip4A" , opt_general_clip4a , 0.0 , 
    "First coefficient in equation for clip plane 4" },
  { F,   "Clip4B" , opt_general_clip4b , 0.0 , 
    "Second coefficient in equation for clip plane 4" },
  { F,   "Clip4C" , opt_general_clip4c , 0.0 , 
    "Third coefficient in equation for clip plane 4" },
  { F,   "Clip4D" , opt_general_clip4d , 0.0 , 
    "Fourth coefficient in equation for clip plane 4" },
  { F,   "Clip5" , opt_general_clip5 , 0.,
    "Enable clip plane 5" },
  { F,   "Clip5A" , opt_general_clip5a , 0.0 , 
    "First coefficient in equation for clip plane 5" },
  { F,   "Clip5B" , opt_general_clip5b , 0.0 , 
    "Second coefficient in equation for clip plane 5" },
  { F,   "Clip5C" , opt_general_clip5c , 0.0 , 
    "Third coefficient in equation for clip plane 5" },
  { F,   "Clip5D" , opt_general_clip5d , 0.0 , 
    "Fourth coefficient in equation for clip plane 5" },
  { F|O, "ColorScheme", opt_general_color_scheme , 0. ,
    "Default color scheme (0, 1 or 2)" },
  { F|S, "ConfirmOverwrite" , opt_general_confirm_overwrite, 1. , 
    "Ask confirmation before overwriting files?" }, 

  { F|O, "DefaultPlugins" , opt_general_default_plugins , 1. ,
    "Load default plugins on startup" },
  { F|O, "DoubleBuffer" , opt_general_double_buffer , 1. ,
    "Use a double buffered graphic window (on Unix, should be set to 0 when working on a remote host without GLX)" },

  { F|O, "FastRedraw" , opt_general_fast_redraw , 1. ,
    "Fast redraw (no mesh or view display) when interacting with the model" },
  { F|S, "FontSize" , opt_general_fontsize , 12. , 
    "Size of the font in the graphical user interface" },

  { F|S, "GraphicsFontSize" , opt_general_graphics_fontsize , 11. , 
    "Size of the font in the graphic window" }, 
  { F|S, "GraphicsHeight" , opt_general_viewport3 , 500. , 
    "Height (in pixels) of the graphic window" }, 
  { F|S, "GraphicsPositionX" , opt_general_graphics_position0 , 20. , 
    "Horizontal position (in pixels) of the upper left corner of the graphic window" }, 
  { F|S, "GraphicsPositionY" , opt_general_graphics_position1 , 30. ,
    "Vertical position (in pixels) of the upper left corner of the graphic window" }, 
  { F|S, "GraphicsWidth" , opt_general_viewport2 , 700. , 
    "Width (in pixels) of the graphic window" }, 

  { F|O, "InitialModule", opt_general_initial_context, 0. , 
    "Module launched on startup (0=automatic, 1=geometry, 2=mesh, 3=solver, 4=post-processing) " },

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
  { F|O, "LineWidth" , opt_general_line_width , 1.0 , 
    "Display width of lines (in pixels)" },

  { F|S, "MenuPositionX" , opt_general_menu_position0 , 800. , 
    "Horizontal position (in pixels) of the upper left corner of the menu window" }, 
  { F|S, "MenuPositionY" , opt_general_menu_position1 , 50. ,
    "Vertical position (in pixels) of the upper left corner of the menu window" }, 
  { F|S, "MessagePositionX" , opt_general_message_position0 , 650. , 
    "Horizontal position (in pixels) of the upper left corner of the message window" }, 
  { F|S, "MessagePositionY" , opt_general_message_position1 , 150. , 
    "Vertical position (in pixels) of the upper left corner of the message window" }, 
  { F|S, "MessageHeight" , opt_general_message_size1 , 350. , 
    "Height (in pixels) of the message window" }, 
  { F|S, "MessageWidth" , opt_general_message_size0 , 450. , 
    "Width (in pixels) of the message window" }, 
  { F|O, "MovingLight" , opt_general_moving_light , 0. ,
    "Use a moving (i.e. which follows the model) light source" },

  { F|S, "OptionsPositionX" , opt_general_option_position0 , 650. , 
    "Horizontal position (in pixels) of the upper left corner of the option window" }, 
  { F|S, "OptionsPositionY" , opt_general_option_position1 , 150. , 
    "Vertical position (in pixels) of the upper left corner of the option window" }, 
  { F|O, "Orthographic" , opt_general_orthographic , 1. ,
    "Orthographic projection mode (0=perspective projection)" },

  { F|O, "PointSize" , opt_general_point_size , 3. , 
    "Display size of points (in pixels)" },

  { F|O, "QuadricSubdivisions" , opt_general_quadric_subdivisions, 10. ,
    "Number of subdivisions used to draw points or lines as spheres or cylinders" },

  { F,   "RotationX" , opt_general_rotation0 , 0.0 , 
    "First Euler angle (used if Trackball=0)" }, 
  { F,   "RotationY" , opt_general_rotation1 , 0.0 , 
    "Second Euler angle (used if Trackball=0)" }, 
  { F,   "RotationZ" , opt_general_rotation2 , 0.0 , 
    "Third Euler angle (used if Trackball=0)" }, 
  { F|O, "RotationCenterGravity" , opt_general_rotation_center_cg , 1. ,
    "Rotate around the center of gravity instead of (RotationCenterX, RotationCenterY, RotationCenterZ)" },
  { F,   "RotationCenterX" , opt_general_rotation_center0 , 0.0 , 
    "X coordinate of the center of rotation" }, 
  { F,   "RotationCenterY" , opt_general_rotation_center1 , 0.0 , 
    "Y coordinate of the center of rotation" }, 
  { F,   "RotationCenterZ" , opt_general_rotation_center2 , 0.0 , 
    "Z coordinate of the center of rotation" }, 

  { F|S, "SaveOptions" , opt_general_options_save, 0. , 
    "Automatically save current options in General.OptionsFileName each time you quit Gmsh?" }, 
  { F|S, "SaveSession" , opt_general_session_save, 1. , 
    "Automatically save session specific information in General.SessionFileName each time you quit Gmsh?" }, 
  { F,   "ScaleX" , opt_general_scale0 , 1.0 , 
    "X-axis scale factor" },
  { F,   "ScaleY" , opt_general_scale1 , 1.0 , 
    "Y-axis scale factor" },
  { F,   "ScaleZ" , opt_general_scale2 , 1.0 , 
    "Z-axis scale factor" },
  { F|O, "Shininess" , opt_general_shine , 0.4 , 
    "Material shininess (must be > 0)" },
  { F|O, "SmallAxes" , opt_general_small_axes , 1. ,
    "Display the small axes" },
  { F|O, "SmallAxesPositionX" , opt_general_small_axes_position0 , -45. ,
    "X position of small axes (use negative values for right alignment)" },
  { F|O, "SmallAxesPositionY" , opt_general_small_axes_position1 , -35. ,
    "Y position of small axes (use negative values for bottom alignment)" },
  { F|S, "StatisticsPositionX" , opt_general_statistics_position0 , 650. , 
    "Horizontal position (in pixels) of the upper left corner of the statistic window" }, 
  { F|S, "StatisticsPositionY" , opt_general_statistics_position1 , 150. , 
    "Vertical position (in pixels) of the upper left corner of the statistic window" }, 

#if defined(HAVE_FLTK)
  { F|O, "Terminal" , opt_general_terminal , 0. ,
#else		      
  { F|O, "Terminal" , opt_general_terminal , 1. ,
#endif
    "Should information be printed on the terminal (if available)?" },
  { F|O, "Tooltips" , opt_general_tooltips , 1. ,
    "Show tooltips in the graphical user interface" },
  { F|O, "Trackball" , opt_general_trackball , 1. ,
    "Use trackball rotation mode" },
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


  { F|O, "Verbosity" , opt_general_verbosity , 2. ,
    "Level of information printed during processing (0=no information)" },
  { F|S, "VisibilityPositionX" , opt_general_visibility_position0 , 650. , 
    "Horizontal position (in pixels) of the upper left corner of the visibility window" }, 
  { F|S, "VisibilityPositionY" , opt_general_visibility_position1 , 150. , 
    "Vertical position (in pixels) of the upper left corner of the visibility window" }, 

  { F|O, "ZoomFactor" , opt_general_zoom_factor , 1.1 ,
    "`Speed' of the middle mouse button zoom" },

  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber GeometryOptions_Number[] = {
  { F|O, "Aspect" , opt_geometry_aspect , 0. , 
    "Not used" },
  { F|O, "AutoCoherence" , opt_geometry_auto_coherence , 1. , 
    "Should all duplicate entities be automatically removed?" }, 

  { F|O, "CirclePoints" , opt_geometry_circle_points, 20. ,
    "Number of points used to draw a circle/ellipse" },
  { F|O, "ColorScheme" , opt_geometry_color_scheme , 0. , 
    "Default geometry color scheme (0, 1 or 2)" },
  { F|O, "CircleWarning" , opt_geometry_circle_warning, 1. ,
    "Warn if circle arc is greater than Pi" },

  { F|O, "ExtrudeSplinePoints" , opt_geometry_extrude_spline_points, 5. ,
    "Number of control points for splines created during extrusion" },

  { F|O, "Highlight" , opt_geometry_highlight , 1. , 
    "Not used" },

  { F|O, "Lines" , opt_geometry_lines , 1. , 
    "Display geometry curves?" },
  { F|O, "LinesNumbers" , opt_geometry_lines_num , 0. , 
    "Display curve numbers?" },
  { F|O, "LineSelectWidth" , opt_geometry_line_sel_width , 2. , 
    "Display width of selected lines (in pixels)" },
  { F|O, "LineType" , opt_geometry_line_type , 0. , 
    "Display lines as solid color segments (0) or 3D cylinders (1)" },
  { F|O, "LineWidth" , opt_geometry_line_width , 1.0 , 
    "Display width of lines (in pixels)" },

  { F|O, "Normals" , opt_geometry_normals , 0. , 
    "Size of the vectors normal to the surfaces" }, 

  { F|O, "OldCircle" , opt_geometry_old_circle , 0. , 
    "Use old circle description (compatibility option for old Gmsh geometries)" },
  { F|O, "OldNewReg" , opt_geometry_old_newreg , 1. , 
    "Use old newreg definition for geometrical transformations (compatibility option for old Gmsh geometries)" },

  { F|O, "Points" , opt_geometry_points , 1. ,
    "Display geometry points?" },
  { F|O, "PointsNumbers" , opt_geometry_points_num , 0. , 
    "Display points numbers?" },
  { F|O, "PointSelectSize" , opt_geometry_point_sel_size , 5. , 
    "Display size of selected points (in pixels)" },
  { F|O, "PointSize" , opt_geometry_point_size , 3. , 
    "Display size of points (in pixels)" },
  { F|O, "PointType" , opt_geometry_point_type , 0. , 
    "Display points as solid color dots (0) or 3D spheres (1)" },

  { F|O, "ScalingFactor" , opt_geometry_scaling_factor , 1.0 , 
    "Global geometry scaling factor" },
  { F|O, "Surfaces" , opt_geometry_surfaces , 0. , 
    "Display geometry surfaces?" },
  { F|O, "SurfacesNumbers" , opt_geometry_surfaces_num , 0. , 
    "Display surface numbers?" },

  { F|O, "Tangents" , opt_geometry_tangents , 0. ,
    "Size of the vectors tangent to the curves" }, 

  { F|O, "Volumes" , opt_geometry_volumes , 0. , 
    "Display geometry volumes? (not implemented yet)" },
  { F|O, "VolumesNumbers" , opt_geometry_volumes_num , 0. , 
    "Display volume numbers? (not implemented yet)" },

  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber MeshOptions_Number[] = {
  { F|O, "Algorithm" , opt_mesh_algo , DELAUNAY_ISO ,
    "2D mesh algorithm (1=isotropic, 2=anisotropic, 3=triangle)" }, 
  { F,   "AllowDegeneratedExtrude" , opt_mesh_allow_degenerated_extrude , 0. , 
    "Allow the generation of degenerated hexahedra or prisms during extrusion" },
  { F|O, "Aspect" , opt_mesh_aspect , 0. , 
    "Mesh aspect (0=wireframe, 1=hidden lines, 2=solid)" },

  { F|O, "CharacteristicLengthFactor" , opt_mesh_lc_factor , 1.0 ,
    "Factor applied to all characteristic lengths (and background meshes)" },
  { F|O, "ColorCarousel" , opt_mesh_color_carousel , 1. ,
    "Use a `color by region number' coloring scheme" },
  { F|O, "ColorScheme" , opt_mesh_color_scheme , 0. , 
    "Default mesh color scheme (0, 1 or 2)" },
  { F|O, "ConstrainedBackgroundMesh" , opt_mesh_constrained_bgmesh, 0. ,
    "Should the background mesh be constrained by the characteristic lengths associated with the geometry?" },
  { F,   "CpuTime" , opt_mesh_cpu_time , 0. , 
    "CPU time for the generation of the current mesh (in seconds)" },
  { F,   "CutPlane" , opt_mesh_use_cut_plane , 0 ,
    "Enable mesh cut plane" },
  { F,   "CutPlaneA" , opt_mesh_cut_planea , 1. , 
    "First cut plane equation coefficient (`A' in `AX+BY+CZ+D=0')" },
  { F,   "CutPlaneB" , opt_mesh_cut_planeb , 0. , 
    "Second cut plane equation coefficient (`B' in `AX+BY+CZ+D=0')" },
  { F,   "CutPlaneC" , opt_mesh_cut_planec , 0. , 
    "Third cut plane equation coefficient (`C' in `AX+BY+CZ+D=0')" },
  { F,   "CutPlaneD" , opt_mesh_cut_planed , 0. , 
    "Fourth cut plane equation coefficient (`D' in `AX+BY+CZ+D=0')" },

  { F|O, "DisplayLists" , opt_mesh_display_lists , 0. ,
    "Use OpenGL display lists for drawing meshes" },
  { F|O, "Dual" , opt_mesh_dual , 0. ,
    "Display the dual mesh obtained by barycentric subdivision" },

  { F|O, "ElementOrder" , opt_mesh_order , 1. , // "Order" is already a lex token
    "Element order (1=linear elements, 2=quadratic elements)" },
  { F|O, "Explode" , opt_mesh_explode , 1.0 ,
    "Display mesh with non adjacent elements (factor between 0 and 1)" },

  { F|O, "Format" , opt_mesh_format , FORMAT_MSH , 
    "Mesh output format (1=MSH, 2=UNV, 3=GREF, 19=VRML)" },

  { F|O, "GammaInf" , opt_mesh_gamma_inf , 0.0 , 
    "Only display elements whose Gamma factor is greater than GammaInf" },
  { F|O, "GammaSup" , opt_mesh_gamma_sup , 0.0 , 
    "Only display elements whose Gamma factor is smaller than GammaSup" },

  { F|O, "Interactive" , opt_mesh_interactive , 0. ,
    "Show the construction of the 2D mesh in real time (only with the 2D anisotropic algorithm)" },

  { F|O, "Lines" , opt_mesh_lines , 1. , 
    "Display mesh vertices on curves?" },
  { F|O, "LinesNumbers" , opt_mesh_lines_num , 0. , 
    "Display mesh line numbers?" },
  { F|O, "LineType" , opt_mesh_line_type , 0. , 
    "Display lines as solid color segments (0) or 3D cylinders (1)" },
  { F|O, "LineWidth" , opt_mesh_line_width , 1.0 , 
    "Display width of lines (in pixels)" },

  { F|O, "MinimumCirclePoints" , opt_mesh_min_circ_points, 7. ,
    "Minimum number of points used to mesh a circle" },

  { F, "NbHexahedra" , opt_mesh_nb_hexahedra , 0. , 
    "Number of hexahedra in the current mesh" },
  { F, "NbNodes" , opt_mesh_nb_nodes , 0. , 
    "Number of nodes in the current mesh" },
  { F, "NbPrisms" , opt_mesh_nb_prisms , 0. , 
    "Number of prisms in the current mesh" },
  { F, "NbPyramids" , opt_mesh_nb_pyramids , 0. , 
    "Number of pyramids in the current mesh" },
  { F, "NbQuadrangles" , opt_mesh_nb_quadrangles , 0. , 
    "Number of quadrangles in the current mesh" },
  { F, "NbTetrahedra" , opt_mesh_nb_tetrahedra , 0. , 
    "Number of tetrahedra in the current mesh" },
  { F, "NbTriangles" , opt_mesh_nb_triangles , 0. , 
    "Number of triangles in the current mesh" },
  { F|O, "Normals" , opt_mesh_normals , 0.0 ,
    "Size of the normal vectors" }, 

  { F|O, "Points" , opt_mesh_points , 1. , 
    "Display mesh vertices?" },
  { F|O, "PointInsertion" , opt_mesh_point_insertion, CENTER_CIRCCIRC ,
    "Point insertion method for isotropic 2D algorithm (1=center of circumscribed circle, 2=voronoi, 3=cog)" },
  { F|O, "PointsNumbers" , opt_mesh_points_num , 0. , 
    "Display mesh vertex numbers?" },
  { F|O, "PointSize" , opt_mesh_point_size , 2. , 
    "Display size of points (in pixels)" },
  { F|O, "PointType" , opt_mesh_point_type , 0. , 
    "Display points as solid color dots (0) or 3D spheres (1)" },

  { F|O, "Quality" , opt_mesh_quality , 0.0 ,
    "Target quality for tetrahedral elements (not fully functional)" },

  { F|O, "RadiusInf" , opt_mesh_radius_inf , 0.0 , 
    "Only display elements whose Radius is greater than RadiusInf" },
  { F|O, "RadiusSup" , opt_mesh_radius_sup , 0.0 , 
    "Only display elements whose Radius is smaller than RadiusSup" },
  { F|O, "RandomFactor" , opt_mesh_rand_factor , 1.e-4 ,
    "Random factor used in 2D and 3D meshing algorithm (test other values when the algorithm fails)" },

  { F,   "SaveAll" , opt_mesh_save_all , 0. , 
    "Ignore Physical definitions and save all elements" },
  { F|O, "ScalingFactor" , opt_mesh_scaling_factor , 1.0 ,
    "Global scaling factor applied to the saved mesh" },
  { F|O, "Smoothing" , opt_mesh_nb_smoothing , 0. ,
    "Number of smoothing steps applied to the final mesh" },
  { F|O, "SpeedMax" , opt_mesh_speed_max , 0. ,
    "Disable dubious point insertion tests" },
  { F|O, "Surfaces" , opt_mesh_surfaces , 1. , 
    "Display surface mesh?" },
  { F|O, "SurfacesNumbers" , opt_mesh_surfaces_num , 0. , 
    "Display mesh surface numbers?" },

  { F|O, "Tangents" , opt_mesh_tangents , 0.0 , 
    "Size of the tangent vectors" }, 

  { F|O, "Volumes" , opt_mesh_volumes , 1. , 
    "Display volume mesh?" },
  { F|O, "VolumesNumbers" , opt_mesh_volumes_num , 0. , 
    "Display mesh elements numbers?" },

  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber SolverOptions_Number[] = {
  { F|O, "ClientServer0" , opt_solver_client_server0 , 1. ,
    "Connect solver 0 to the Gmsh server" },
  { F|O, "MergeViews0" , opt_solver_merge_views0 , 1. , 
    "Automatically merge any post-processing view created by solver 0" },
#if defined(WIN32)
  { F|O, "PopupMessages0" , opt_solver_popup_messages0 , 0. , // we already have the transient dos window
#else
  { F|O, "PopupMessages0" , opt_solver_popup_messages0 , 1. ,
#endif
    "Automatically display messages produced by solver 0" },

  { F|O, "ClientServer1" , opt_solver_client_server1 , 0. ,
    "Connect solver 1 to the Gmsh server" },
  { F|O, "MergeViews1" , opt_solver_merge_views1 , 1. , 
    "Automatically merge any post-processing view created by solver 1" },
  { F|O, "PopupMessages1" , opt_solver_popup_messages1 , 1. ,
    "Automatically display messages produced by solver 1" },

  { F|O, "ClientServer2" , opt_solver_client_server2 , 0. ,
    "Connect solver 2 to the Gmsh server" },
  { F|O, "MergeViews2" , opt_solver_merge_views2 , 1. , 
    "Automatically merge any post-processing view created by solver 2" },
  { F|O, "PopupMessages2" , opt_solver_popup_messages2 , 1. ,
    "Automatically display messages produced by solver 2" },

  { F|O, "ClientServer3" , opt_solver_client_server3 , 0. ,
    "Connect solver 3 to the Gmsh server" },
  { F|O, "MergeViews3" , opt_solver_merge_views3 , 1. , 
    "Automatically merge any post-processing view created by solver 3" },
  { F|O, "PopupMessages3" , opt_solver_popup_messages3 , 1. ,
    "Automatically display messages produced by solver 3" },

  { F|O, "ClientServer4" , opt_solver_client_server4 , 0. ,
    "Connect solver 4 to the Gmsh server" },
  { F|O, "MergeViews4" , opt_solver_merge_views4 , 1. , 
    "Automatically merge any post-processing view created by solver 4" },
  { F|O, "PopupMessages4" , opt_solver_popup_messages4 , 1. ,
    "Automatically display messages produced by solver 4" },

  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber PostProcessingOptions_Number[] = {
  { F|O, "AnimationDelay" , opt_post_anim_delay , 0.25 ,
    "Delay (in seconds) between frames in automatic animation mode" },
  { F|O, "AnimationCycle" , opt_post_anim_cycle , 0. ,
    "Cycle through views instead of time steps in automatic animation mode" },

  { F|O, "DisplayLists" , opt_post_display_lists , 0. ,
    "Use OpenGL display lists for drawing post-processing views" },

  { F|O, "Link" , opt_post_link , 0. ,
    "Link post-processing views (0=none, 1,2=changes in visible/all, 3,4=everything in visible/all)" },

  { F,   "NbViews" , opt_post_nb_views , 0. ,//this default val is not used
    "Current number of views merged" },

  { F|O, "Scales" , opt_post_scales , 1. , 
    "Show value scales" },
  { F|O, "Smoothing" , opt_post_smooth , 0. ,
    "Apply (non-reversible) smoothing to post-processing view when merged" },

  { 0, NULL , NULL , 0. }
} ;

StringXNumber ViewOptions_Number[] = {
  { F|O, "AngleSmoothNormals" , opt_view_angle_smooth_normals , 15. ,
    "Threshold angle below which normals are not smoothed" },
  { F|O, "ArrowLocation" , opt_view_arrow_location , DRAW_POST_LOCATE_COG , 
    "Arrow location (1=cog, 2=vertex)" },
  { F|O, "ArrowSize" , opt_view_arrow_size , 50. ,
    "Size of vectors arrows (in pixels)" },
  { F|O, "AutoPosition" , opt_view_auto_position , 1. , 
    "Position the scale or the 2D graph automatically to avoid overlaps" }, 

  { F|O, "Boundary" , opt_view_boundary , 0 ,
    "Draw the `N minus b'-dimensional boundary of the simplex (N=simplex dimension, b=option value)" },

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
  { F|O, "DrawQuadrangles" , opt_view_draw_quadrangles , 1. , 
    "Display post-processing quadrangles?" },
  { F|O, "DrawScalars" , opt_view_draw_scalars , 1. , 
    "Display scalar values?" },
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
    "Explode elements (0: reduced to point; 1: not transformed)" },

  { F|O, "Grid" , opt_view_grid , 2 ,
    "Grid mode for 2D graphs (0=none, 1=simple, 2=frame, 3=grid)" },

  { F|O, "Height" , opt_view_size1 , 200. , 
    "Height (in pixels) of the scale or 2D graph" }, 

  { F|O, "IntervalsType" , opt_view_intervals_type , DRAW_POST_CONTINUOUS ,
    "Type of interval display (1=iso, 2=continuous, 3=discrete, 4=numeric)" },

  { F|O, "Light" , opt_view_light , 0. ,
    "Enable light sources?" },
  { F|O, "LineType" , opt_view_line_type , 0. , 
    "Display lines as solid color segments (0) or 3D cylinders (1)" },
  { F|O, "LineWidth" , opt_view_line_width , 1.0 , 
    "Display width of lines (in pixels)" },

  { F,   "Max" , opt_view_max , -1.e200 , 
    "Maximum value in the view (do not change this!)" },
  { F,   "Min" , opt_view_min , 1.e200 ,
    "Minimum value in the view (do not change this!)" },

  { F|O, "NbAbscissa" , opt_view_nb_abscissa , 5. ,
    "Number of abscissa intervals for 2D graphs" },
  { F|O, "NbIso" , opt_view_nb_iso , 15. ,
    "Number of intervals" },
  { F,   "NbTimeStep" , opt_view_nb_timestep , 1. ,
    "Number of time steps in the view (do not change this!)" },

  { F,   "OffsetX" , opt_view_offset0 , 0. , 
    "Translation of the view along X-axis (in model coordinates)" },
  { F,   "OffsetY" , opt_view_offset1 , 0. , 
    "Translation of the view along Y-axis (in model coordinates)" },
  { F,   "OffsetZ" , opt_view_offset2 , 0. , 
    "Translation of the view along Z-axis (in model coordinates)" },

  { F|O, "PointSize" , opt_view_point_size , 2. , 
    "Display size of points (in pixels)" },
  { F|O, "PointType" , opt_view_point_type , 0. , 
    "Display points as solid color dots (0) or 3D spheres (1)" },
  { F|O, "PositionX" , opt_view_position0 , 80. , 
    "Horizontal position (in pixels) of the upper left corner of the scale or 2D graph" }, 
  { F|O, "PositionY" , opt_view_position1 , 50. , 
    "Vertical position (in pixels) of the upper left corner of the scale or 2D graph" }, 

  { F,   "RaiseX" , opt_view_raise0 , 0. , 
    "Elevation of the view along X-axis (in model coordinates)" },
  { F,   "RaiseY" , opt_view_raise1 , 0. , 
    "Elevation of the view along Y-axis (in model coordinates)" },
  { F,   "RaiseZ" , opt_view_raise2 , 0. , 
    "Elevation of the view along Z-axis (in model coordinates)" },
  { F|O, "RangeType" , opt_view_range_type , DRAW_POST_DEFAULT ,
    "Value scale range type (1=default, 2=custom)" },

  { F|O, "SaturateValues" , opt_view_saturate_values , 0 ,
    "Saturate the view values to custom min and max (1=true, 0=false)" },
  { F|O, "ScaleType" , opt_view_scale_type , DRAW_POST_LINEAR ,
    "Value scale type (1=linear, 2=logarithmic, 3=double logarithmic)" },
  { F|O, "ShowElement" , opt_view_show_element , 0. ,
    "Show element boundaries?" },
  { F|O, "ShowScale" , opt_view_show_scale , 1. ,
    "Show value scale?" },
  { F|O, "ShowTime" , opt_view_show_time , 1. ,
    "Show time value (or time step) if NbTimeStep > 1?" },
  { F|O, "SmoothNormals" , opt_view_smooth_normals , 0. ,
    "Smooth the normals?" },
  { F|O, "TensorType" , opt_view_tensor_type , 0. ,
    "Tensor Visualization Type" },
  { F,   "TimeStep" , opt_view_timestep , 0. ,
    "Current time step displayed" },
  { F|O, "TransparentScale" , opt_view_transparent_scale , 1. ,
    "Display a `transparent' value scale?" },
  { F|O, "Type" , opt_view_type , DRAW_POST_3D ,
    "Type of graph (1=3D, 2=2D-space, 3=2D-time)" },

  { F|O, "VectorType" , opt_view_vector_type , DRAW_POST_ARROW ,
    "Vector display type (1=segment, 2=arrow, 3=pyramid, 4=cone, 5=displacement)" },
  { F,   "Visible" , opt_view_visible , 1. ,
    "Is the view visible?" },

  { F|O, "Width" , opt_view_size0 , 300. , 
    "Width (in pixels) of the scale or 2D graph" }, 

  { 0, NULL , NULL , 0. , NULL }
} ;

StringXNumber PrintOptions_Number[] = {
  { F|O, "Compress" , opt_print_compress , 0 ,
    "Compress PostScript and PDF output using zlib" },
  { F|O, "EpsBackground" , opt_print_eps_background , 1 ,
    "Save image background in postscript output" },
  { F|O, "EpsFontSize" , opt_print_eps_font_size , 12. ,
    "Font size used for postscript printing" },
  { F|O, "EpsLineWidthFactor" , opt_print_eps_line_width_factor , 0.2 ,
    "Width factor for lines in postscript output" },
  { F|O, "EpsPointSizeFactor" , opt_print_eps_point_size_factor , 1. ,
    "Size factor for points in postscript output" },
  { F|O, "EpsQuality" , opt_print_eps_quality , 1 ,
    "Postscript quality (1=simple sort, 2=recursive sort)" },
  { F|O, "EpsOcclusionCulling" , opt_print_eps_occlusion_culling , 1 ,
    "Cull occluded primitives (to reduce PostScript file size)" },
  { F|O, "EpsBestRoot" , opt_print_eps_best_root , 1 ,
    "Try to minimize primitive splitting in recursive sort" },

  { F|O, "Format" , opt_print_format , FORMAT_AUTO , 
    "File format (10=automatic)" }, 

  { F|O, "GifDither" , opt_print_gif_dither , 0 ,
    "Apply dithering to GIF output" },
  { F|O, "GifInterlace" , opt_print_gif_interlace , 0 ,
    "Interlace GIF output" },
  { F|O, "GifSort" , opt_print_gif_sort , 1 ,
    "Sort the colormap in GIF output" },
  { F|O, "GifTransparent" , opt_print_gif_transparent , 0 ,
    "Output transparent GIF image" },

  { F|O, "JpegQuality" , opt_print_jpeg_quality , 100 ,
    "JPEG quality (between 1 and 100)" },

  { 0, NULL , NULL , 0. }
} ;

// COLORS

// CONTRARY TO THE PRECEDING OPTIONS, THE ORDERING OF COLOR OPTIONS MATTERS !

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
  { F|O, "Lines" , opt_mesh_color_lines , 
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   255, 0,   255),
    PACK_COLOR(0,   0,   0,   255),
    "Mesh line color" },
  { F|O, "Triangles" , opt_mesh_color_triangles , 
    COLT, COLT, COLW, "Mesh triangle color (if Mesh.ColorCarousel=0)" },
  { F|O, "Quadrangles" , opt_mesh_color_quadrangles ,
    COLQ, COLQ, COLW, "Mesh quadrangle color (if Mesh.ColorCarousel=0)" },
  { F|O, "Tetrahedra" , opt_mesh_color_tetrahedra ,
    COLT, COLT, COLW, "Mesh tetrahedron color (if Mesh.ColorCarousel=0)" },
  { F|O, "Hexahedra" , opt_mesh_color_hexahedra ,
    COLQ, COLQ, COLW, "Mesh hexahedron color (if Mesh.ColorCarousel=0)" },
  { F|O, "Prisms" , opt_mesh_color_prisms ,
    COLP, COLP, COLW, "Mesh prism color (if Mesh.ColorCarousel=0)" },
  { F|O, "Pyramids" , opt_mesh_color_pyramid ,
    COLY, COLY, COLW, "Mesh pyramid color (if Mesh.ColorCarousel=0)" },
  { F|O, "Tangents" , opt_mesh_color_tangents ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Tangent mesh vector color" },
  { F|O, "Normals" , opt_mesh_color_normals ,
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(128, 128, 128, 255),
    PACK_COLOR(0,   0,   0,   255),
    "Normal mesh vector color" },
  { F|O, "One" , opt_mesh_color_1   , COL1, COL1, COLW, "First color in color carousel" },
  { F|O, "Two" , opt_mesh_color_2   , COL2, COL2, COLW, "Second color in color carousel" },
  { F|O, "Three" , opt_mesh_color_3 , COL3, COL3, COLW, "Third color in color carousel" },
  { F|O, "Four" , opt_mesh_color_4  , COL4, COL4, COLW, "Fourth color in color carousel" },
  { F|O, "Five" , opt_mesh_color_5  , COL5, COL5, COLW, "Fifth color in color carousel" },
  { F|O, "Six" , opt_mesh_color_6   , COL6, COL6, COLW, "Sixth color in color carousel" },
  { F|O, "Seven" , opt_mesh_color_7 , COL7, COL7, COLW, "Seventh color in color carousel" },
  { F|O, "Eight" , opt_mesh_color_8 , COL8, COL8, COLW, "Eighth color in color carousel" },
  { F|O, "Nine" , opt_mesh_color_9  , COL9, COL9, COLW, "Ninth color in color carousel" },
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

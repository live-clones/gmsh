#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#define CALLBACK_ARGS   Fl_Widget* w, void* data

// Common callbacks

void cancel_cb(CALLBACK_ARGS) ;
void ok_cb(CALLBACK_ARGS) ;

// Graphical window

void status_xyz1p_cb(CALLBACK_ARGS) ;
void status_play_cb(CALLBACK_ARGS) ;
void status_pause_cb(CALLBACK_ARGS) ;
void status_cancel_cb(CALLBACK_ARGS) ;

// File Menu

void file_open_cb(CALLBACK_ARGS) ;
void file_merge_cb(CALLBACK_ARGS) ;
void file_save_cb(CALLBACK_ARGS) ;
void file_save_as_auto_cb(CALLBACK_ARGS) ;
void file_save_as_geo_cb(CALLBACK_ARGS) ;
void file_save_as_msh_cb(CALLBACK_ARGS) ;
void file_save_as_unv_cb(CALLBACK_ARGS) ;
void file_save_as_gref_cb(CALLBACK_ARGS) ;
void file_save_as_eps_simple_cb(CALLBACK_ARGS) ;
void file_save_as_eps_accurate_cb(CALLBACK_ARGS) ;
void file_save_as_jpeg_cb(CALLBACK_ARGS) ;
void file_save_as_gif_cb(CALLBACK_ARGS) ;
void file_save_as_gif_dithered_cb(CALLBACK_ARGS) ;
void file_save_as_gif_transparent_cb(CALLBACK_ARGS) ;
void file_save_as_ppm_cb(CALLBACK_ARGS) ;
void file_save_as_yuv_cb(CALLBACK_ARGS) ;
void file_reload_all_views_cb(CALLBACK_ARGS) ;
void file_remove_all_views_cb(CALLBACK_ARGS) ;
void file_quit_cb(CALLBACK_ARGS) ;

// Option General Menu

void opt_general_cb(CALLBACK_ARGS) ;
void opt_general_moving_axes_cb(CALLBACK_ARGS) ;
void opt_general_small_axes_cb(CALLBACK_ARGS) ;
void opt_general_fast_redraw_cb(CALLBACK_ARGS) ;
void opt_general_display_lists_cb(CALLBACK_ARGS) ;
void opt_general_alpha_blending_cb(CALLBACK_ARGS) ;
void opt_general_trackball_cb(CALLBACK_ARGS) ;
void opt_general_orthographic_cb(CALLBACK_ARGS) ;
void opt_general_color_cb(CALLBACK_ARGS) ;
void opt_general_shininess_cb(CALLBACK_ARGS) ;
void opt_general_light_cb(CALLBACK_ARGS) ;

// Option Geometry Menu

void opt_geometry_cb(CALLBACK_ARGS) ;

// Option Mesh Menu

void opt_mesh_cb(CALLBACK_ARGS) ;

// Option Post Menu

void opt_post_cb(CALLBACK_ARGS) ;

// Option Statistics Menu

void opt_stat_cb(CALLBACK_ARGS) ;

// Help Menu

void help_short_cb(CALLBACK_ARGS) ;
void help_about_cb(CALLBACK_ARGS) ;

// Module Menu

void mod_geometry_cb(CALLBACK_ARGS) ;
void mod_mesh_cb(CALLBACK_ARGS) ;
void mod_post_cb(CALLBACK_ARGS) ;
void mod_back_cb(CALLBACK_ARGS) ;
void mod_forward_cb(CALLBACK_ARGS) ;

// Dynamic Menus

void geometry_elementary_cb(CALLBACK_ARGS) ;
void geometry_physical_cb(CALLBACK_ARGS) ;
void geometry_reload_cb(CALLBACK_ARGS) ; 
void geometry_elementary_add_cb(CALLBACK_ARGS) ;
void geometry_elementary_translate_cb(CALLBACK_ARGS) ;
void geometry_elementary_rotate_cb(CALLBACK_ARGS) ;
void geometry_elementary_dilate_cb(CALLBACK_ARGS) ;
void geometry_elementary_symmetry_cb(CALLBACK_ARGS) ;
void geometry_elementary_extrude_cb(CALLBACK_ARGS) ;
void geometry_elementary_delete_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_translate_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_rotate_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_dilate_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_parameter_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_line_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_spline_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_circle_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_ellipsis_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_planesurface_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_ruledsurface_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_new_volume_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_translate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_translate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_rotate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_dilate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_dilate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_dilate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_symmetry_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_translate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_translate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_translate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_rotate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_rotate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_rotate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_dilate_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_dilate_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_dilate_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_symmetry_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_symmetry_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_extrude_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_extrude_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_extrude_surface_cb(CALLBACK_ARGS) ;
void geometry_elementary_delete_point_cb(CALLBACK_ARGS) ;
void geometry_elementary_delete_curve_cb(CALLBACK_ARGS) ;
void geometry_elementary_delete_surface_cb(CALLBACK_ARGS) ;
void geometry_physical_add_cb(CALLBACK_ARGS) ;
void geometry_physical_delete_cb(CALLBACK_ARGS) ;
void geometry_physical_add_point_cb (CALLBACK_ARGS) ;
void geometry_physical_add_curve_cb (CALLBACK_ARGS) ;
void geometry_physical_add_surface_cb (CALLBACK_ARGS) ;
void geometry_physical_add_volume_cb (CALLBACK_ARGS) ;
void geometry_physical_delete_point_cb(CALLBACK_ARGS) ;
void geometry_physical_delete_curve_cb(CALLBACK_ARGS) ;
void geometry_physical_delete_surface_cb(CALLBACK_ARGS) ;
void geometry_physical_delete_volume_cb(CALLBACK_ARGS) ;
void mesh_define_cb(CALLBACK_ARGS) ;
void mesh_1d_cb(CALLBACK_ARGS) ;
void mesh_2d_cb(CALLBACK_ARGS) ; 
void mesh_3d_cb(CALLBACK_ARGS) ; 
void mesh_define_length_cb (CALLBACK_ARGS) ;
void mesh_define_recombine_cb (CALLBACK_ARGS) ;
void mesh_define_transfinite_cb (CALLBACK_ARGS) ; 
void mesh_define_transfinite_line_cb(CALLBACK_ARGS) ;
void mesh_define_transfinite_surface_cb(CALLBACK_ARGS) ;
void mesh_define_transfinite_volume_cb(CALLBACK_ARGS) ; 
void view_reload_cb(CALLBACK_ARGS) ;
void view_toggle_cb(CALLBACK_ARGS) ;
void view_remove_cb(CALLBACK_ARGS) ;
void view_duplicate_cb(CALLBACK_ARGS) ;
void view_lighting_cb(CALLBACK_ARGS) ;
void view_elements_cb(CALLBACK_ARGS) ;
void view_applybgmesh_cb(CALLBACK_ARGS) ;
void view_timestep_cb(CALLBACK_ARGS) ;
void view_options_cb(CALLBACK_ARGS) ;



#endif

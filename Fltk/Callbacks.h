#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#define CALLBACK_ARGS   Fl_Widget* w, void* data

int SetGlobalShortcut(int event);
void MarkAllViewsChanged(int action);

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
void file_save_as_geo_options_cb(CALLBACK_ARGS) ;
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
void opt_geometry_entity_cb(CALLBACK_ARGS) ;
void opt_geometry_num_cb(CALLBACK_ARGS) ;
void opt_geometry_show_by_entity_num_cb(CALLBACK_ARGS) ;
void opt_geometry_normals_cb(CALLBACK_ARGS) ;
void opt_geometry_tangents_cb(CALLBACK_ARGS) ;

// Option Mesh Menu

void opt_mesh_cb(CALLBACK_ARGS) ;
void opt_mesh_entity_cb(CALLBACK_ARGS) ;
void opt_mesh_num_cb(CALLBACK_ARGS) ;
void opt_mesh_show_by_entity_num_cb(CALLBACK_ARGS) ;
void opt_mesh_show_by_quality_cb(CALLBACK_ARGS) ;
void opt_mesh_normals_cb(CALLBACK_ARGS) ;
void opt_mesh_degree_cb(CALLBACK_ARGS) ;
void opt_mesh_algo_cb(CALLBACK_ARGS) ;
void opt_mesh_smoothing_cb(CALLBACK_ARGS) ;
void opt_mesh_scaling_factor_cb(CALLBACK_ARGS) ;
void opt_mesh_lc_factor_cb(CALLBACK_ARGS) ;
void opt_mesh_rand_factor_cb(CALLBACK_ARGS) ;
void opt_mesh_interactive_cb(CALLBACK_ARGS) ;
void opt_mesh_explode_cb(CALLBACK_ARGS) ;
void opt_mesh_aspect_cb(CALLBACK_ARGS) ;

// Option Post Menu

void opt_post_cb(CALLBACK_ARGS) ;
void opt_post_link_cb(CALLBACK_ARGS) ;
void opt_post_smooth_cb(CALLBACK_ARGS) ;
void opt_post_anim_delay_cb(CALLBACK_ARGS) ;

// Option Statistics Menu

void opt_statistics_cb(CALLBACK_ARGS) ;
void opt_statistics_update_cb(CALLBACK_ARGS) ;

// Option Message Menu

void opt_message_cb(CALLBACK_ARGS) ;
void opt_message_save_cb(CALLBACK_ARGS) ;

// Help Menu

void help_short_cb(CALLBACK_ARGS) ;
void help_about_cb(CALLBACK_ARGS) ;

// Module Menu

void mod_geometry_cb(CALLBACK_ARGS) ;
void mod_mesh_cb(CALLBACK_ARGS) ;
void mod_post_cb(CALLBACK_ARGS) ;
void mod_back_cb(CALLBACK_ARGS) ;
void mod_forward_cb(CALLBACK_ARGS) ;

// Dynamic Geometry Menus

void geometry_elementary_cb(CALLBACK_ARGS) ;
void   geometry_elementary_add_cb(CALLBACK_ARGS) ;
void     geometry_elementary_add_new_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_parameter_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_point_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_line_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_spline_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_circle_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_ellipsis_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_planesurface_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_ruledsurface_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_new_volume_cb(CALLBACK_ARGS) ;
void     geometry_elementary_add_translate_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_translate_point_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_translate_curve_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS) ;
void     geometry_elementary_add_rotate_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_rotate_curve_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS) ;
void     geometry_elementary_add_scale_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_scale_point_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_scale_curve_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_scale_surface_cb(CALLBACK_ARGS) ;
void     geometry_elementary_add_symmetry_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_symmetry_curve_cb(CALLBACK_ARGS) ;
void       geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_translate_cb(CALLBACK_ARGS) ;
void     geometry_elementary_translate_point_cb(CALLBACK_ARGS) ;
void     geometry_elementary_translate_curve_cb(CALLBACK_ARGS) ;
void     geometry_elementary_translate_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_rotate_cb(CALLBACK_ARGS) ;
void     geometry_elementary_rotate_point_cb(CALLBACK_ARGS) ;
void     geometry_elementary_rotate_curve_cb(CALLBACK_ARGS) ;
void     geometry_elementary_rotate_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_scale_cb(CALLBACK_ARGS) ;
void     geometry_elementary_scale_point_cb(CALLBACK_ARGS) ;
void     geometry_elementary_scale_curve_cb(CALLBACK_ARGS) ;
void     geometry_elementary_scale_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_symmetry_cb(CALLBACK_ARGS) ;
void     geometry_elementary_symmetry_point_cb(CALLBACK_ARGS) ;
void     geometry_elementary_symmetry_curve_cb(CALLBACK_ARGS) ;
void     geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_extrude_cb(CALLBACK_ARGS) ;
void     geometry_elementary_extrude_translate_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_translate_point_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_translate_curve_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_translate_surface_cb(CALLBACK_ARGS) ;
void     geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_rotate_point_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_rotate_curve_cb(CALLBACK_ARGS) ;
void        geometry_elementary_extrude_rotate_surface_cb(CALLBACK_ARGS) ;
void   geometry_elementary_delete_cb(CALLBACK_ARGS) ;
void     geometry_elementary_delete_point_cb(CALLBACK_ARGS) ;
void     geometry_elementary_delete_curve_cb(CALLBACK_ARGS) ;
void     geometry_elementary_delete_surface_cb(CALLBACK_ARGS) ;
void geometry_physical_cb(CALLBACK_ARGS) ;
void   geometry_physical_add_cb(CALLBACK_ARGS) ;
void     geometry_physical_add_point_cb (CALLBACK_ARGS) ;
void     geometry_physical_add_curve_cb (CALLBACK_ARGS) ;
void     geometry_physical_add_surface_cb (CALLBACK_ARGS) ;
void     geometry_physical_add_volume_cb (CALLBACK_ARGS) ;
void geometry_reload_cb(CALLBACK_ARGS) ; 

void con_geometry_define_parameter_cb(CALLBACK_ARGS) ;
void con_geometry_define_point_cb(CALLBACK_ARGS) ;
void con_geometry_define_translation_cb(CALLBACK_ARGS) ;
void con_geometry_define_rotation_cb(CALLBACK_ARGS) ;
void con_geometry_define_scale_cb(CALLBACK_ARGS) ;
void con_geometry_define_symmetry_cb(CALLBACK_ARGS) ;

// Dynamic Mesh Menus

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

void con_mesh_define_length_cb(CALLBACK_ARGS) ;
void con_mesh_define_transfinite_line_cb(CALLBACK_ARGS) ;
void con_mesh_define_transfinite_volume_cb(CALLBACK_ARGS) ;

// Dynamic post menus

void view_reload_cb(CALLBACK_ARGS) ;
void view_toggle_cb(CALLBACK_ARGS) ;
void view_remove_cb(CALLBACK_ARGS) ;
void view_duplicate_cb(CALLBACK_ARGS) ;
void view_lighting_cb(CALLBACK_ARGS) ;
void view_elements_cb(CALLBACK_ARGS) ;
void view_applybgmesh_cb(CALLBACK_ARGS) ;
void view_options_cb(CALLBACK_ARGS) ;
void view_options_show_scale_cb(CALLBACK_ARGS) ;
void view_options_show_time_cb(CALLBACK_ARGS) ;
void view_options_transparent_scale_cb(CALLBACK_ARGS) ;
void view_options_name_cb(CALLBACK_ARGS) ;
void view_options_format_cb(CALLBACK_ARGS) ;
void view_options_custom_range_cb(CALLBACK_ARGS) ;
void view_options_custom_min_cb(CALLBACK_ARGS) ;
void view_options_custom_max_cb(CALLBACK_ARGS) ;
void view_options_linear_range_cb(CALLBACK_ARGS) ;
void view_options_logarithmic_range_cb(CALLBACK_ARGS) ;
void view_options_nbiso_cb(CALLBACK_ARGS) ;
void view_options_iso_cb(CALLBACK_ARGS) ;
void view_options_fillediso_cb(CALLBACK_ARGS) ;
void view_options_continuousiso_cb(CALLBACK_ARGS) ;
void view_options_numericiso_cb(CALLBACK_ARGS) ;
void view_options_xoffset_cb(CALLBACK_ARGS) ;
void view_options_yoffset_cb(CALLBACK_ARGS) ;
void view_options_zoffset_cb(CALLBACK_ARGS) ;
void view_options_xraise_cb(CALLBACK_ARGS) ;
void view_options_yraise_cb(CALLBACK_ARGS) ;
void view_options_zraise_cb(CALLBACK_ARGS) ;
void view_options_timestep_cb(CALLBACK_ARGS) ;
void view_options_vector_line_cb(CALLBACK_ARGS) ;
void view_options_vector_arrow_cb(CALLBACK_ARGS) ;
void view_options_vector_cone_cb(CALLBACK_ARGS) ;
void view_options_vector_displacement_cb(CALLBACK_ARGS) ;
void view_options_vector_scale_cb(CALLBACK_ARGS) ;
void view_options_vector_cog_cb(CALLBACK_ARGS) ;
void view_options_vector_vertex_cb(CALLBACK_ARGS) ;

#endif


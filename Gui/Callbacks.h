#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

void file_open_cb(void) ;
void file_merge_cb(void) ;
void file_save_cb(void) ;
void file_save_as_cb(void) ;
void file_reload_all_views_cb(void) ;
void file_remove_all_views_cb(void) ;
void file_quit_cb(void) ;

void opt_general_cb(void) ;
void opt_geometry_cb(void) ;
void opt_mesh_cb(void) ;
void opt_post_cb(void) ;
void opt_stat_cb(void) ;

void help_short_cb(void) ;
void help_about_cb(void) ;

void mod_geometry_cb(void) ;
void mod_mesh_cb(void) ;
void mod_post_cb(void) ;

void view_reload_cb(Fl_Widget* w, void*) ;
void view_remove_cb(Fl_Widget* w, void*) ;
void view_duplicate_cb(Fl_Widget* w, void*) ;
void view_lighting_cb(Fl_Widget* w, void*) ;
void view_elements_cb(Fl_Widget* w, void*) ;
void view_timestep_cb(Fl_Widget* w, void*) ;
void view_options_cb(Fl_Widget* w, void*) ;
void view_applybgmesh_cb(Fl_Widget* w, void*) ;

#endif

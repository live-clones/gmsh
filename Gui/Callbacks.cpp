
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "OpenFile.h"
#include "Context.h"
#include "GUI.h"

#include <FL/fl_file_chooser.H>

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

// File Menu

void file_open_cb(void) {
  char *newfile;
  newfile = fl_file_chooser("Open File", "*.geo", NULL);
  if (newfile != NULL) {
    OpenProblem(newfile); 
    Init();
    Draw(); 
  }
}

void file_merge_cb(void) {
  char *newfile;
  newfile = fl_file_chooser("Merge File", "*.{geo,pos,msh}", NULL);
  if (newfile != NULL) {
    MergeProblem(newfile); 
    Init();
    Draw(); 
  }
}

void file_save_cb(void) {
}

void file_save_as_cb(void) {
}

void file_reload_all_views_cb(void) {
}

void file_remove_all_views_cb(void) {
}

void file_quit_cb(void) {
  exit(0);
}

// Option Menu

void opt_general_cb(void) {
  WID->opt_general();
}

void opt_geometry_cb(void) {
}
void opt_mesh_cb(void) {
}
void opt_post_cb(void) {
}
void opt_stat_cb(void) {
}

// Help Menu

void help_short_cb(void){
}
void help_about_cb(void){
}

// Module Menu

void mod_geometry_cb(void){
}
void mod_mesh_cb(void){
}
void mod_post_cb(void){
}

// View Menus

void view_reload_cb(Fl_Widget* w, void* data){
  printf("Reload view %d \n", (int)data);
}
void view_remove_cb(Fl_Widget* w, void* data){
  printf("Remove view %d \n", (int)data);
}
void view_duplicate_cb(Fl_Widget* w, void* data){
  printf("Duplicate view %d \n", (int)data);
}
void view_lighting_cb(Fl_Widget* w, void* data){
  printf("Light view %d \n", (int)data);
}
void view_elements_cb(Fl_Widget* w, void* data){
  printf("Show Elements view %d \n", (int)data);
}
void view_applybgmesh_cb(Fl_Widget* w, void* data){
  printf("Apply bgmesh view %d \n", (int)data);
}
void view_timestep_cb(Fl_Widget* w, void* data){
  printf("Timestep view %d \n", (int)data);
}
void view_options_cb(Fl_Widget* w, void* data){
  printf("Options view %d \n", (int)data);
}

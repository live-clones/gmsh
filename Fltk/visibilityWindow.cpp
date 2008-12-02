// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "Draw.h"
#include "visibilityWindow.h"
#include "shortcutWindow.h"
#include "contextWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Visibility.h"
#include "GeoStringInterface.h"
#include "Options.h"
#include "Context.h"

extern Context_T CTX;

// Visibility Menu

void visibility_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char*)data;
  if(str && !strcmp(str, "redraw_only"))
    GUI::instance()->visibility->show(true);
  else
    GUI::instance()->visibility->show(false);

  GUI::instance()->visibility->browser->clear();

  int type = GUI::instance()->visibility->type->value();

  VisibilityManager::instance()->update(type);
  for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
    GUI::instance()->visibility->browser->add
      (VisibilityManager::instance()->getBrowserLine(i).c_str());
    if(VisibilityManager::instance()->getVisibility(i))
      GUI::instance()->visibility->browser->select(i + 1);
  }
  
  // activate the delete button for physicals only!
  if(type == 1)
    GUI::instance()->visibility->push[0]->activate();
  else
    GUI::instance()->visibility->push[0]->deactivate();

  // disable numeric and interactive selection for partitions
  if(type == 2){
    GUI::instance()->visibility->group[1]->deactivate();
    GUI::instance()->visibility->group[2]->deactivate();
  }
  else{
    GUI::instance()->visibility->group[1]->activate();
    GUI::instance()->visibility->group[2]->activate();
  }
}

static void visibility_ok_cb(Fl_Widget *w, void *data)
{
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityManager::instance()->getNumEntities()){
    CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;
    int type = GUI::instance()->visibility->type->value();
    VisibilityManager::instance()->setAllInvisible(type);
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(GUI::instance()->visibility->browser->selected(i + 1))
        VisibilityManager::instance()->setVisibility(i, 1, recursive);
    // then refresh the browser to account for recursive selections
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(VisibilityManager::instance()->getVisibility(i))
        GUI::instance()->visibility->browser->select(i + 1);
    Draw();
  }
}

static void visibility_save_cb(Fl_Widget *w, void *data)
{
  std::string str = VisibilityManager::instance()->getStringForGEO();
  add_infile(str.c_str(), CTX.filename);
}

static void visibility_delete_cb(Fl_Widget *w, void *data)
{
  int type = GUI::instance()->visibility->type->value();
  if(type != 1) return; // delete only available for physicals

  bool all = true;
  for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
    if(!GUI::instance()->visibility->browser->selected(i + 1)){
      all = false;
      break;
    }
  }
  if(all){
    GModel::current()->deletePhysicalGroups();
  }
  else{
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
      if(GUI::instance()->visibility->browser->selected(i + 1)){
        Vis *v = VisibilityManager::instance()->getEntity(i);
        GModel::current()->deletePhysicalGroup(v->getDim(), v->getTag());
      }
    }
  }

  visibility_cb(NULL, (void*)"redraw_only");
}

static void visibility_sort_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  int val;
  if(!strcmp(str, "type"))
    val = 1;
  else if(!strcmp(str, "number"))
    val = 2;
  else if(!strcmp(str, "name"))
    val = 3;
  else if(!strcmp(str, "-"))
    val = -1;
  else if(!strcmp(str, "+"))
    val = -2;
  else
    val = 0;

  if(val == 0) { // select or deselect everything
    int selectall = 0;
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      if(!GUI::instance()->visibility->browser->selected(i + 1)) {
        selectall = 1;
        break;
      }
    if(selectall)
      for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
        GUI::instance()->visibility->browser->select(i + 1);
    else
      GUI::instance()->visibility->browser->deselect();
  }
  else if(val == -1){ // invert the selection
    int *state = new int[GUI::instance()->visibility->browser->size()];
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      state[i] = GUI::instance()->visibility->browser->selected(i + 1);
    GUI::instance()->visibility->browser->deselect();
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      if(!state[i]) GUI::instance()->visibility->browser->select(i + 1);
    delete [] state;
  }
  else if(val == -2){ // create new parameter name for selection
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++){
      if(GUI::instance()->visibility->browser->selected(i + 1)){
        static char tmpstr[256];
        sprintf(tmpstr, "%d", VisibilityManager::instance()->getTag(i));
        GUI::instance()->geoContext->input[1]->value(tmpstr);
        break;
      }
    }
    GUI::instance()->geoContext->input[0]->value("NewName");
    GUI::instance()->geoContext->show(0);
  }
  else { // set new sorting mode
    VisibilityManager::instance()->setSortMode(val);
    visibility_cb(NULL, (void*)"redraw_only");
  }
}

static void visibility_number_cb(Fl_Widget *w, void *data)
{
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);

  // type = 0 for elementary, 1 for physical and 2 for partitions
  int type = GUI::instance()->visibility->type->value();
  if(type != 0 && type != 1) return;

  // what = 0 for nodes, 1 for elements, 2 for points, 3 for lines, 4
  // for surfaces, 5 for volumes, 6 for physical points, 7 for
  // physical lines, 8 for physical surfaces and 9 for physical
  // volumes
  int what = (int)(long)data;
  char val;
  if(what >= 100){ // show
    val = 1;
    what -= 100;
  }
  else{ // hide
    val = 0;
  }
  const char *str = GUI::instance()->visibility->input[what]->value();
  if(type == 1 && what >= 2 && what <= 5) what += 4;

  int num = (!strcmp(str, "all") || !strcmp(str, "*")) ? -1 : atoi(str);
  bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;
  
  VisibilityManager::instance()->setVisibilityByNumber(what, num, val, recursive);

  int pos = GUI::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  GUI::instance()->visibility->browser->position(pos);
  Draw();
}

static void apply_visibility(char mode,
                             std::vector<GVertex*> &vertices,
                             std::vector<GEdge*> &edges,
                             std::vector<GFace*> &faces,
                             std::vector<GRegion*> &regions,
                             std::vector<MElement*> &elements)
{
  // type = 0 for elementary, 1 for physical and 2 for partitions
  int type = GUI::instance()->visibility->type->value();
  if(type != 0 && type != 1) return;
  bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;

  if(mode == 1){ // when showing a single entity, first hide everything
    if(CTX.pick_elements)
      VisibilityManager::instance()->setVisibilityByNumber(1, -1, 0, false);
    else
      for(int i = 2; i <= 5; i++)
        VisibilityManager::instance()->setVisibilityByNumber(i, -1, 0, false);
  }

  if(mode == 2) mode = 1;
  
  if(CTX.pick_elements){
    for(unsigned int i = 0; i < elements.size(); i++)
      elements[i]->setVisibility(mode);
  }
  else{
    for(unsigned int i = 0; i < vertices.size(); i++){
      if(type == 0)
        vertices[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < vertices[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (6, vertices[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < edges.size(); i++){
      if(type == 0)
        edges[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < edges[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (7, edges[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < faces.size(); i++){
      if(type == 0)
        faces[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < faces[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (8, faces[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < regions.size(); i++){
      if(type == 0)
        regions[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < regions[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (9, regions[i]->physicals[j], mode, recursive);
    }
  }
  int pos = GUI::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  GUI::instance()->visibility->browser->position(pos);
}

static void visibility_interactive_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  const char *help;
  int what;
  char mode;

  if(!strcmp(str, "hide_elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
    mode = 0;
    help = "elements to hide";
  }
  else if(!strcmp(str, "hide_points")){
    CTX.pick_elements = 0;
    what = ENT_POINT;
    mode = 0;
    help = "points to hide";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
    mode = 0;
    help = "lines to hide";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
    mode = 0;
    help = "surfaces to hide";
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
    mode = 0;
    help = "volumes to hide";
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
    mode = 1;
    help = "elements to show";
  }
  else if(!strcmp(str, "show_points")){
    CTX.pick_elements = 0;
    what = ENT_POINT;
    mode = 1;
    help = "points to show";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
    mode = 1;
    help = "lines to show";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
    mode = 1;
    help = "surfaces to show";
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
    mode = 1;
    help = "volumes to show";
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_all")){
    for(int i = 1; i <= 5; i++) // elements, points, lines, surfaces, volumes
      VisibilityManager::instance()->setVisibilityByNumber(i, -1, 1, false);
    CTX.mesh.changed = ENT_ALL;
    Draw();  
    return;
  }
  else
    return;

  std::vector<GVertex*> vertices, vertices_old;
  std::vector<GEdge*> edges, edges_old;
  std::vector<GFace*> faces, faces_old;
  std::vector<GRegion*> regions, regions_old;
  std::vector<MElement*> elements, elements_old;

  while(1) {
    if(what == ENT_ALL) 
      CTX.mesh.changed = ENT_ALL;
    Draw();
    Msg::StatusBar(3, false, "Select %s\n[Press %s'q' to abort]", 
                   help, mode ? "" : "'u' to undo or ");

    char ib = GUI::instance()->selectEntity
      (what, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      apply_visibility(mode, vertices, edges, faces, regions, elements);
      // store for possible undo later
      vertices_old = vertices;
      edges_old = edges;
      faces_old = faces;
      regions_old = regions;
      elements_old = elements;
    }
    if(ib == 'u' && !mode){ // undo only in hide mode
      apply_visibility(2, vertices_old, edges_old, faces_old, 
                       regions_old, elements_old);
    }
    if(ib == 'q'){
      break;
    }
  }

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg::StatusBar(3, false, "");
}

// derive our own browser, that reacts differently to the Enter key
class visBrowser : public Fl_Browser{
  int handle(int event)
  {
    if(event == FL_KEYBOARD){
      switch(Fl::event_key()) {
      case FL_Enter:
      case FL_KP_Enter:
        visibility_ok_cb(NULL, NULL);
        return 1;
      }
    }
    return Fl_Browser::handle(event);
  }
 public:
  visBrowser(int x, int y, int w , int h, const char* c = 0)
    : Fl_Browser(x, y, w, h, c){}
};

visibilityWindow::visibilityWindow(int fontsize) 
  : _fontsize(fontsize)
{
  static int cols[5] = {15, 95, 95, 180, 0};
  static Fl_Menu_Item type_table[] = {
    {"Elementary entities", 0, (Fl_Callback *) visibility_cb},
    {"Physical groups", 0, (Fl_Callback *) visibility_cb},
    {"Mesh partitions", 0, (Fl_Callback *) visibility_cb},
    {0}
  };

  int width = cols[0] + cols[1] + cols[2] + cols[3] + 6 * WB;
  int height = 18 * BH;
  int brw = width - 4 * WB;

  win = new dialogWindow
    (width, height, CTX.non_modal_windows, "Visibility");
  win->box(GMSH_WINDOW_BOX);

  type = new Fl_Choice(WB, WB, (width - 3 * WB) / 2, BH);
  type->menu(type_table);
  
  butt[0] = new Fl_Check_Button
    (WB + (width - 3 * WB) / 2 + WB, WB, (width - 3 * WB) / 2, BH, 
     "Set visibility recursively");
  butt[0]->type(FL_TOGGLE_BUTTON);
  butt[0]->value(1);

  Fl_Tabs *o = new Fl_Tabs
    (WB, 2 * WB + BH, width - 2 * WB, height - 4 * WB - 2 * BH);
  {
    group[0] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 3 * BH, "Browser");

    Fl_Button *o0 = new Fl_Button
      (2 * WB, 3 * WB + 2 * BH, cols[0], BH/2, "*");
    o0->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);
    o0->tooltip("Select/unselect all");
    o0->callback(visibility_sort_cb, (void *)"*");

    Fl_Button *o1 = new Fl_Button
      (2 * WB, 3 * WB + 2 * BH + BH/2, cols[0], BH - BH/2, "-");
    o1->tooltip("Invert selection");
    o1->callback(visibility_sort_cb, (void *)"-");

    Fl_Button *o2 = new Fl_Button
      (2 * WB + cols[0], 3 * WB + 2 * BH, cols[1], BH, "Type");
    o2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o2->tooltip("Sort by type");
    o2->callback(visibility_sort_cb, (void *)"type");

    Fl_Button *o3 = new Fl_Button
      (2 * WB + cols[0] + cols[1], 3 * WB + 2 * BH, cols[2], BH, "Number");
    o3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o3->tooltip("Sort by number");
    o3->callback(visibility_sort_cb, (void *)"number");

    Fl_Button *o4 = new Fl_Button
      (2 * WB + cols[0] + cols[1] + cols[2], 3 * WB + 2 * BH, cols[3], BH, "Name");
    o4->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o4->tooltip("Sort by name");
    o4->callback(visibility_sort_cb, (void *)"name");

    Fl_Button *o5 = new Fl_Button
      (width - 4 * WB, 3 * WB + 2 * BH, 2 * WB, BH, "+");
    o5->tooltip("Add parameter name for first selected item");
    o5->callback(visibility_sort_cb, (void *)"+");

    {
      Fl_Group *o = new Fl_Group
        (2 * WB, 3 * WB + 3 * BH, brw, height - 7 * WB - 5 * BH);
      
      browser = new visBrowser
        (2 * WB, 3 * WB + 3 * BH, brw, height - 7 * WB - 5 * BH);
      browser->type(FL_MULTI_BROWSER);
      browser->column_widths(cols);
      
      o->end();
      Fl_Group::current()->resizable(o);
    }

    push[0] = new Fl_Button
      (width - 2 * BB - 3 * WB, height - 2 * BH - 3 * WB, BB, BH, "Delete");
    push[0]->callback(visibility_delete_cb);

    Fl_Return_Button *b1 = new Fl_Return_Button
      (width - 1 * BB - 2 * WB, height - 2 * BH - 3 * WB, BB, BH, "Apply");
    b1->callback(visibility_ok_cb);

    group[0]->end();
    Fl_Group::current()->resizable(group[0]);
  }
  {
    group[1] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 2 * BH, "Numeric input");
    group[1]->resizable(NULL);

    for(int i = 0; i < 6; i++){
      input[i] = new Fl_Input
        (width / 2 - WB / 2 - IW, 3 * WB + (i + 2) * BH, IW, BH);
      input[i]->align(FL_ALIGN_LEFT);
      input[i]->value("*");

      Fl_Button *o1 = new Fl_Button
        (width / 2 + WB / 2, 3 * WB + (i + 2) * BH, BB, BH, "Show");
      o1->callback(visibility_number_cb, (void *)(100+i));

      Fl_Button *o2 = new Fl_Button
        (width / 2 + WB / 2 + BB + WB, 3 * WB + (i + 2) * BH, BB, BH, "Hide");
      o2->callback(visibility_number_cb, (void *)i);
    }

    input[0]->label("Node");
    input[0]->tooltip("Enter node number, or *");

    input[1]->label("Element");
    input[1]->tooltip("Enter element number, or *");

    input[2]->label("Point");
    input[2]->tooltip("Enter point number, or *");

    input[3]->label("Line");
    input[3]->tooltip("Enter line number, or *");

    input[4]->label("Surface");
    input[4]->tooltip("Enter surface number, or *");

    input[5]->label("Volume");
    input[5]->tooltip("Enter volume number, or *");

    group[1]->end();
  }
  {
    group[2] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 2 * BH, "Interactive");
    group[2]->resizable(NULL);

    int ll = width/2 - BH - WB - IW;

    Fl_Box *b2 = new Fl_Box
      (FL_NO_BOX, ll, 3 * WB + 2 * BH, IW, BH, "Hide with the mouse:");
    b2->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);

    Fl_Button *butt1 = new Fl_Button(ll, 3 * WB + 3 * BH, IW, BH, "Elements");
    butt1->callback(visibility_interactive_cb, (void *)"hide_elements");
    Fl_Button *butt2 = new Fl_Button(ll, 3 * WB + 4 * BH, IW, BH, "Points");
    butt2->callback(visibility_interactive_cb, (void *)"hide_points");
    Fl_Button *butt3 = new Fl_Button(ll, 3 * WB + 5 * BH, IW, BH, "Lines");
    butt3->callback(visibility_interactive_cb, (void *)"hide_lines");
    Fl_Button *butt4 = new Fl_Button(ll, 3 * WB + 6 * BH, IW, BH, "Surfaces");
    butt4->callback(visibility_interactive_cb, (void *)"hide_surfaces");
    Fl_Button *butt5 = new Fl_Button(ll, 3 * WB + 7 * BH, IW, BH, "Volumes");
    butt5->callback(visibility_interactive_cb, (void *)"hide_volumes");

    Fl_Button *butt6 = new Fl_Button
      (ll + IW + WB, 3 * WB + 3 * BH, 2 * BH, 5*BH, "Show\nAll");
    butt6->callback(visibility_interactive_cb, (void *)"show_all");

    int ll2 = ll + IW + WB + 2*BH + WB;

    Fl_Box *b12 = new Fl_Box
      (FL_NO_BOX, ll2, 3 * WB + 2 * BH, IW, BH, "Show with the mouse:");
    b12->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);

    Fl_Button *butt11 = new Fl_Button(ll2, 3 * WB + 3 * BH, IW, BH, "Elements");
    butt11->callback(visibility_interactive_cb, (void *)"show_elements");
    Fl_Button *butt12 = new Fl_Button(ll2, 3 * WB + 4 * BH, IW, BH, "Points");
    butt12->callback(visibility_interactive_cb, (void *)"show_points");
    Fl_Button *butt13 = new Fl_Button(ll2, 3 * WB + 5 * BH, IW, BH, "Lines");
    butt13->callback(visibility_interactive_cb, (void *)"show_lines");
    Fl_Button *butt14 = new Fl_Button(ll2, 3 * WB + 6 * BH, IW, BH, "Surfaces");
    butt14->callback(visibility_interactive_cb, (void *)"show_surfaces");
    Fl_Button *butt15 = new Fl_Button(ll2, 3 * WB + 7 * BH, IW, BH, "Volumes");
    butt15->callback(visibility_interactive_cb, (void *)"show_volumes");
    
    group[2]->end();
  }
  o->end();

  win->resizable(o);
  win->size_range(width, 9 * BH + 6 * WB, width);

  {
    Fl_Button *o1 = new Fl_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Save");
    o1->callback(visibility_save_cb);

    Fl_Button *o2 = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o2->callback(hide_cb, (void *)win);
  }

  win->position(CTX.vis_position[0], CTX.vis_position[1]);
  win->end();
}

void visibilityWindow::show(bool redrawOnly)
{
  if(win->shown() && redrawOnly)
    win->redraw();
  else
    win->show();
}


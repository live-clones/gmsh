// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <FL/Fl_Input.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GUI.h"
#include "fieldWindow.h"
#include "shortcutWindow.h"
#include "GModel.h"
#include "PView.h"
#include "Callbacks.h"
#include "GmshMessage.h"
#include "Field.h"
#include "GeoStringInterface.h"
#include "Context.h"

extern Context_T CTX;

fieldWindow::fieldWindow(int fontsize) : _fontsize(fontsize)
{
  int width0 = 34 * _fontsize + WB;
  int height0 = 13 * BH + 5 * WB;
  int width = (CTX.field_size[0] < width0) ? width0 : CTX.field_size[0];
  int height = (CTX.field_size[1] < height0) ? height0 : CTX.field_size[1];

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Fields");
  win->box(GMSH_WINDOW_BOX);

  int x = WB, y = WB, w = (int)(1.5 * BB), h = height - 2 * WB - 3 * BH;

  Fl_Menu_Button *new_btn = new Fl_Menu_Button(x, y, w, BH, "New");
  FieldManager &fields = *GModel::current()->getFields();

  std::map<std::string, FieldFactory*>::iterator it;
  for(it = fields.map_type_name.begin(); it != fields.map_type_name.end(); it++)
    new_btn->add(it->first.c_str());
  new_btn->callback(view_field_new_cb);

  y += BH;
  browser = new Fl_Hold_Browser(x, y + WB, w, h - 2 * WB);
  browser->callback(view_field_browser_cb);

  y += h; 
  delete_btn = new Fl_Button(x, y, w, BH, "Delete");
  delete_btn->callback(view_field_delete_cb, this);

  y += BH;
  put_on_view_btn = new Fl_Menu_Button(x, y, w, BH, "Put on view");
  put_on_view_btn->callback(view_field_put_on_view_cb, this);

  x += w + WB;
  y = WB;
  w = width - x - WB;
  h = height - y - WB;
  editor_group = new Fl_Group(x, y, w, h);
    
  title = new Fl_Box(x, y, w, BH, "field_name");
  title->labelfont(FL_BOLD);
  title->labelsize(18);
  
  y += BH + WB;
  h -= BH + WB;
  Fl_Tabs *tabs = new Fl_Tabs(x, y , w, h);
  y += BH;
  h -= BH;
  x += WB;
  w -= 2 * WB;

  Fl_Group *options_tab = new Fl_Group(x, y, w, h, "Options");
  
  options_scroll = new Fl_Scroll(x, y, w, h - BH - 2 * WB);
  options_scroll->end();
  
  Fl_Button *apply_btn = new Fl_Return_Button
    (x + w - BB, y + h - BH - WB, BB, BH, "Apply");
  apply_btn->callback(view_field_apply_cb, this);
  
  Fl_Button *revert_btn = new Fl_Button
    (x + w - 2 * BB - WB, y + h - BH - WB, BB, BH, "Revert");
  revert_btn->callback(view_field_revert_cb, this);
  
  background_btn = new Fl_Check_Button
    (x, y + h - BH - WB, (int)(1.5 * BB), BH, "Background mesh size");
  options_tab->end();

  Fl_Group *help_tab = new Fl_Group(x, y, w, h, "Help");
  help_display = new Fl_Browser(x, y + WB, w, h - 2 * WB);
  help_tab->end();

  tabs->end();

  editor_group->end();

  win->resizable(new Fl_Box((int)(1.5 * BB) + 2 * WB, BH + 2 * WB, 
                            width - 3 * WB - (int)(1.5 * BB),
                            height - 3 * BH - 5 * WB));
  editor_group->resizable(tabs);
  tabs->resizable(options_tab);
  options_tab->resizable(new Fl_Box(3 * BB + 4 * WB, BH + 2 * WB,
                                    width - 9 * WB - 5 * BB, 
                                    height - 3 * BH - 5 * WB));
  win->size_range(width0, height0);
  win->position(CTX.field_position[0], CTX.field_position[1]);
  win->end();

  loadFieldViewList();
  editField(NULL);
}

void fieldWindow::loadFieldViewList()
{
  put_on_view_btn->clear();
  put_on_view_btn->add("New view");
  put_on_view_btn->activate();
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    std::ostringstream s;
    s << "View [" << i << "]";
    put_on_view_btn->add(s.str().c_str());
  }
}

void fieldWindow::loadFieldList()
{
  FieldManager &fields = *GModel::current()->getFields();
  Field *selected_field = (Field*)editor_group->user_data();
  browser->clear();
  int i_entry = 0;
  for(FieldManager::iterator it = fields.begin(); it != fields.end(); it++){
    i_entry++;
    Field *field = it->second;
    std::ostringstream sstream;
    if(it->first == fields.background_field)
      sstream << "@b";
    sstream << it->first << " " << field->get_name();
    browser->add(sstream.str().c_str(), field);
    if(it->second == selected_field)
      browser->select(i_entry);
  }
}

void fieldWindow::saveFieldOptions()
{
  std::list<Fl_Widget*>::iterator input = options_widget.begin();
  Field *f = (Field*)editor_group->user_data();
  std::ostringstream sstream;
  int i;
  char a;
  sstream.precision(16);
  for(std::map<std::string, FieldOption*>::iterator it = f->options.begin();
      it != f->options.end(); it++){
    FieldOption *option = it->second;
    sstream.str("");
    switch(option->get_type()){
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH:
      sstream << "\"" << ((Fl_Input*)*input)->value() << "\"";
      break;
    case FIELD_OPTION_INT:
      sstream << (int)((Fl_Value_Input*)*input)->value();
      break;
    case FIELD_OPTION_DOUBLE:
      sstream << ((Fl_Value_Input*)*input)->value();
      break;
    case FIELD_OPTION_BOOL:
      sstream << (bool)((Fl_Check_Button*)*input)->value();
      break;
    case FIELD_OPTION_LIST:
      {
        sstream << "{";
        std::istringstream istream(((Fl_Input*)*input)->value());
        while(istream >> i){
          sstream << i;
          if(istream >> a){
            if(a != ',')
              Msg::Error("Unexpected character \'%c\' while parsing option "
                         "'%s' of field \'%s\'", a, it->first.c_str(), f->id);
            sstream << ", ";
          }
        }
        sstream << "}";
      }
      break;
    }
    if((*input)->changed()){
      add_field_option(f->id, it->first.c_str(), sstream.str().c_str(), 
                       CTX.filename);
      (*input)->clear_changed();
    }
    input++;
  }
  int is_bg_field = background_btn->value();
  FieldManager &fields = *GModel::current()->getFields();
  if(is_bg_field && fields.background_field != f->id){
    set_background_field(f->id, CTX.filename);
    loadFieldList();
  }
  if(!is_bg_field && fields.background_field == f->id){
    set_background_field(-1, CTX.filename);
    loadFieldList();
  }
}

void fieldWindow::loadFieldOptions()
{
  Field *f = (Field*)editor_group->user_data();
  std::list<Fl_Widget*>::iterator input = options_widget.begin();
  for(std::map<std::string, FieldOption*>::iterator it = f->options.begin();
      it != f->options.end(); it++){
    FieldOption *option = it->second;
    std::ostringstream vstr;
    std::list<int>::iterator list_it;
    switch(option->get_type()){
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH:
      ((Fl_Input*)(*input))->value(option->string().c_str());
      break;
    case FIELD_OPTION_INT:
    case FIELD_OPTION_DOUBLE:
      ((Fl_Value_Input*)(*input))->value(option->numerical_value());
      break;
    case FIELD_OPTION_BOOL:
      ((Fl_Check_Button*)(*input))->value((int)option->numerical_value());
      break;
    case FIELD_OPTION_LIST:
      vstr.str("");
      for(list_it = option->list().begin(); list_it != option->list().end();
          list_it++){
	if(list_it!=option->list().begin())
	  vstr << ", ";
	vstr << *list_it;
      }
      ((Fl_Input*)(*input))->value(vstr.str().c_str());
      break;
    }
    (*input)->clear_changed();
    input++;
  }
  background_btn->value(GModel::current()->getFields()->background_field == f->id);
}

void fieldWindow::editField(Field *f)
{
  editor_group->user_data(f);
  put_on_view_btn->deactivate();
  delete_btn->deactivate();
  if(f == NULL){
    selected_id = -1;
    editor_group->hide();
    loadFieldList();
    return;
  }
  selected_id = f->id;
  editor_group->show();
  editor_group->user_data(f);
  title->label(f->get_name());
  options_scroll->clear();
  options_widget.clear();
  options_scroll->begin();
  int x = options_scroll->x();
  int yy = options_scroll->y() + WB;
  help_display->clear();
  add_multiline_in_browser(help_display, "", f->get_description().c_str(), 100);
  help_display->add("\n");
  help_display->add("@b@cOptions");
  for(std::map<std::string, FieldOption*>::iterator it = f->options.begin(); 
      it != f->options.end(); it++){
    Fl_Widget *input;
    help_display->add(("@b" + it->first).c_str());
    help_display->add(("@i" + it->second->get_type_name()).c_str());
    add_multiline_in_browser
      (help_display, "", it->second->get_description().c_str(), 100);
    switch(it->second->get_type()){
    case FIELD_OPTION_INT:
    case FIELD_OPTION_DOUBLE:
      input = new Fl_Value_Input(x, yy, IW, BH, it->first.c_str());
      break;
    case FIELD_OPTION_BOOL:
      input = new Fl_Check_Button(x, yy, BH, BH, it->first.c_str());
      break;
    case FIELD_OPTION_PATH:
      {
        Fl_Button *b = new Fl_Button(x, yy, BH, BH, "S");
        input = new Fl_Input(x + WB + BH, yy, IW - WB - BH, BH, it->first.c_str());
        b->callback(view_field_select_file_cb, input);
      }
      break;
    case FIELD_OPTION_STRING:
      input = new Fl_Input(x, yy, IW, BH, it->first.c_str());
      break;
    case FIELD_OPTION_LIST:
    default:
      input = new Fl_Input(x, yy, IW, BH, it->first.c_str());
      break;
    }
    input->align(FL_ALIGN_RIGHT);
    options_widget.push_back(input);
    yy += WB + BH;
  }
  options_scroll->end();
  loadFieldOptions();
  options_scroll->damage(1);
  put_on_view_btn->activate();
  delete_btn->activate();
  loadFieldList();
}

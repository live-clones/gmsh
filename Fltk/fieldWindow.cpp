// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include <sstream>
#include <FL/Fl_Input.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/fl_draw.H>
#include "FlGui.h"
#include "drawContext.h"
#include "fieldWindow.h"
#include "paletteWindow.h"
#include "fileDialogs.h"
#include "GmshDefines.h"
#include "GModel.h"
#include "PView.h"
#include "GmshMessage.h"
#include "Field.h"
#include "scriptStringInterface.h"
#include "StringUtils.h"
#include "Options.h"
#include "Context.h"

void field_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->fields->win->show();
  FlGui::instance()->fields->editField(nullptr);
}

static void field_delete_cb(Fl_Widget *w, void *data)
{
  Field *f = (Field *)FlGui::instance()->fields->editor_group->user_data();
  scriptDeleteField(f->id, GModel::current()->getFileName());
  FlGui::instance()->fields->editField(nullptr);
}

static void field_new_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_Button *mb = ((Fl_Menu_Button *)w);
  FieldManager *fields = GModel::current()->getFields();
  int id = fields->newId();
  scriptAddField(id, mb->text(), GModel::current()->getFileName());
  if((*fields)[id]) FlGui::instance()->fields->editField((*fields)[id]);
}

static void field_apply_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->fields->saveFieldOptions();
}

static void field_browser_cb(Fl_Widget *w, void *data)
{
  int selected = FlGui::instance()->fields->browser->value();
  if(!selected) { FlGui::instance()->fields->editField(nullptr); }
  Field *f = (Field *)FlGui::instance()->fields->browser->data(selected);
  FlGui::instance()->fields->editField(f);
}

static void field_put_on_view_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_Button *mb = ((Fl_Menu_Button *)w);
  Field *field = (Field *)FlGui::instance()->fields->editor_group->user_data();
  field->update();
  if(mb->value() == 0)
    field->putOnNewView();
  else if(mb->value() - 1 < (int)PView::list.size())
    field->putOnView(PView::list[mb->value() - 1]);
  FlGui::instance()->updateViews(mb->value() == 0, true);
  drawContext::global()->draw();
}

static void field_callback_cb(Fl_Widget *w, void *data)
{
  FieldCallback *cb = (FieldCallback *)data;
  cb->run();
}

static void field_select_file_cb(Fl_Widget *w, void *data)
{
  Fl_Input *input = (Fl_Input *)data;
  int ret = fileChooser(FILE_CHOOSER_SINGLE, "Choose", "", input->value());
  if(ret) {
    input->value(fileChooserGetName(0).c_str());
    input->set_changed();
  }
}

fieldWindow::fieldWindow(int deltaFontSize) : _deltaFontSize(deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width0 = 34 * FL_NORMAL_SIZE + WB;
  int height0 = 12 * BH + 4 * WB;
  int width = (CTX::instance()->fieldSize[0] < width0) ?
                width0 :
                CTX::instance()->fieldSize[0];
  int height = (CTX::instance()->fieldSize[1] < height0) ?
                 height0 :
                 CTX::instance()->fieldSize[1];

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Size fields");
  win->box(GMSH_WINDOW_BOX);

  int x = WB, y = WB, w = (int)(1.5 * BB), h = height - 2 * WB - 3 * BH;

  Fl_Menu_Button *new_btn = new Fl_Menu_Button(x, y, w, BH, "New");
  FieldManager &fields = *GModel::current()->getFields();

  for(auto it = fields.mapTypeName.begin(); it != fields.mapTypeName.end(); it++)
    new_btn->add(it->first.c_str());
  new_btn->callback(field_new_cb);

  y += BH;
  browser = new Fl_Hold_Browser(x, y + WB, w, h - 2 * WB);
  browser->callback(field_browser_cb);

  y += h;
  delete_btn = new Fl_Button(x, y, w, BH, "Delete");
  delete_btn->callback(field_delete_cb, this);

  y += BH;
  put_on_view_btn = new Fl_Menu_Button(x, y, w, BH, "Visualize");
  put_on_view_btn->callback(field_put_on_view_cb, this);

  x += w + WB;
  y = WB;
  w = width - x - WB;
  h = height - y - WB;
  empty_message = new Fl_Box(x, y, w, h,
                             "Create a new field\n\n"
                             "- or -\n\nSelect a field in the browser");
  empty_message->align(FL_ALIGN_CENTER);

  editor_group = new Fl_Group(x, y, w, h);

  title = new Fl_Box(x, y, w, BH, "field_name");
  title->labelfont(FL_BOLD);
  title->labelsize(FL_NORMAL_SIZE + 3);

  y += BH + WB;
  h -= BH + WB;
  Fl_Tabs *tabs = new Fl_Tabs(x, y, w, h);
  y += BH;
  h -= BH;
  x += WB;
  w -= 2 * WB;

  Fl_Group *options_tab = new Fl_Group(x, y, w, h, "Options");

  options_scroll = new Fl_Scroll(x, y + WB, w, h - BH - 3 * WB);
  options_scroll->end();

  Fl_Button *apply_btn =
    new Fl_Return_Button(x + w - BB, y + h - BH - WB, BB, BH, "Apply");
  apply_btn->callback(field_apply_cb, this);

  background_btn = new Fl_Round_Button(x, y + h - BH - WB, w - BB - WB, BH,
                                       "Set as background field");
  options_tab->end();

  Fl_Group *help_tab = new Fl_Group(x, y, w, h, "Help");
  help_display = new Fl_Help_View(x, y + WB, w, h - 2 * WB);
  help_display->textfont(FL_HELVETICA);
  help_display->textsize(FL_NORMAL_SIZE);
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
  win->position(CTX::instance()->fieldPosition[0],
                CTX::instance()->fieldPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;

  loadFieldViewList();
  editField(nullptr);
}

void fieldWindow::loadFieldViewList()
{
  put_on_view_btn->clear();
  put_on_view_btn->add("Create new view");
  put_on_view_btn->activate();
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    std::ostringstream s;
    s << "Put on View [" << i << "]";
    put_on_view_btn->add(s.str().c_str());
  }
}

void fieldWindow::loadFieldList()
{
  FieldManager &fields = *GModel::current()->getFields();
  Field *selected_field = (Field *)editor_group->user_data();
  browser->clear();
  int i_entry = 0;
  for(auto it = fields.begin(); it != fields.end(); it++) {
    i_entry++;
    Field *field = it->second;
    std::ostringstream sstream;
    if(it->first == fields.getBackgroundField()) sstream << "@b";
    sstream << it->first << " " << field->getName();
    browser->add(sstream.str().c_str(), field);
    if(it->second == selected_field) browser->select(i_entry);
  }
}

void fieldWindow::saveFieldOptions()
{
  auto input = options_widget.begin();
  Field *f = (Field *)editor_group->user_data();
  std::ostringstream sstream;
  int i;
  char a;
  double d;
  sstream.precision(16);
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    FieldOption *option = it->second;
    if(option->isDeprecated()) continue;
    sstream.str("");
    switch(option->getType()) {
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH:
      sstream << "\"" << ((Fl_Input *)*input)->value() << "\"";
      break;
    case FIELD_OPTION_INT:
      sstream << (int)((Fl_Value_Input *)*input)->value();
      break;
    case FIELD_OPTION_DOUBLE:
      sstream << ((Fl_Value_Input *)*input)->value();
      break;
    case FIELD_OPTION_BOOL:
      sstream << (bool)((Fl_Check_Button *)*input)->value();
      break;
    case FIELD_OPTION_LIST: {
      sstream << "{";
      std::istringstream istream(((Fl_Input *)*input)->value());
      while(istream >> i) {
        sstream << i;
        if(istream >> a) {
          if(a != ',')
            Msg::Error("Unexpected character \'%c\' while parsing option "
                       "'%s' of field \'%d\'",
                       a, it->first.c_str(), f->id);
          sstream << ", ";
        }
      }
      sstream << "}";
    } break;
    case FIELD_OPTION_LIST_DOUBLE: {
      sstream << "{";
      std::istringstream istream(((Fl_Input *)*input)->value());
      while(istream >> d) {
        sstream << d;
        if(istream >> a) {
          if(a != ',')
            Msg::Error("Unexpected character \'%c\' while parsing option "
                       "'%s' of field \'%d\'",
                       a, it->first.c_str(), f->id);
          sstream << ", ";
        }
      }
      sstream << "}";
    } break;
    }
    if((*input)->changed()) {
      scriptAddFieldOption(f->id, it->first, sstream.str(),
                           GModel::current()->getFileName());
      (*input)->clear_changed();
    }
    input++;
  }
  int is_bg_field = background_btn->value();
  FieldManager &fields = *GModel::current()->getFields();
  if(is_bg_field && fields.getBackgroundField() != f->id) {
    scriptSetBackgroundField(f->id, GModel::current()->getFileName());
    loadFieldList();
  }
  if(!is_bg_field && fields.getBackgroundField() == f->id) {
    scriptSetBackgroundField(-1, GModel::current()->getFileName());
    loadFieldList();
  }
}

void fieldWindow::loadFieldOptions()
{
  Field *f = (Field *)editor_group->user_data();
  auto input = options_widget.begin();
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    FieldOption *option = it->second;
    if(option->isDeprecated()) continue;
    std::ostringstream vstr;
    switch(option->getType()) {
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH:
      ((Fl_Input *)(*input))->value(option->string().c_str());
      break;
    case FIELD_OPTION_INT:
    case FIELD_OPTION_DOUBLE:
      ((Fl_Value_Input *)(*input))->value(option->numericalValue());
      break;
    case FIELD_OPTION_BOOL:
      ((Fl_Check_Button *)(*input))->value((int)option->numericalValue());
      break;
    case FIELD_OPTION_LIST:
      vstr.str("");
      for(auto it = option->list().begin(); it != option->list().end(); it++) {
        if(it != option->list().begin()) vstr << ", ";
        vstr << *it;
      }
      ((Fl_Input *)(*input))->value(vstr.str().c_str());
      break;
    case FIELD_OPTION_LIST_DOUBLE:
      vstr.str("");
      vstr.precision(16);
      for(auto it = option->listdouble().begin(); it != option->listdouble().end();
          it++) {
        if(it != option->listdouble().begin()) vstr << ", ";
        vstr << *it;
      }
      ((Fl_Input *)(*input))->value(vstr.str().c_str());
      break;
    }
    (*input)->clear_changed();
    input++;
  }
  if(dynamic_cast<BoundaryLayerField *>(f)) {
    background_btn->value(0);
    background_btn->deactivate();
    background_btn->tooltip(
      "Boundary layer fields cannot be assigned in the "
      "graphical user interface: edit the file directly.");
  }
  else {
    background_btn->value(
      GModel::current()->getFields()->getBackgroundField() == f->id);
    background_btn->activate();
    background_btn->tooltip(
      "Only a single field can be set as background field.\n"
      "To combine multiple fields use the Min or Max fields.");
  }
}

void fieldWindow::editField(Field *f)
{
  editor_group->user_data(f);
  put_on_view_btn->deactivate();
  delete_btn->deactivate();
  if(f == nullptr) {
    selected_id = -1;
    editor_group->hide();
    empty_message->show();
    loadFieldList();
    return;
  }

  FL_NORMAL_SIZE -= _deltaFontSize;

  selected_id = f->id;
  empty_message->hide();
  editor_group->show();
  editor_group->user_data(f);
  title->label(f->getName());
  options_scroll->clear();
  options_widget.clear();
  options_scroll->begin();
  int xx = options_scroll->x();
  int yy = options_scroll->y();

  std::string help = f->getDescription();
  ConvertToHTML(help);
  if(!f->options.empty())
    help += std::string("<p><center><b>Options</b></center>");
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    if(it->second->isDeprecated()) continue;
    Fl_Widget *input;
    help += std::string("<p><b>") + it->first + "</b>";
    help += " (<em>" + it->second->getTypeName() + "</em>): ";
    help += it->second->getDescription();
    switch(it->second->getType()) {
    case FIELD_OPTION_INT:
    case FIELD_OPTION_DOUBLE:
      input = new Fl_Value_Input(xx, yy, IW, BH, it->first.c_str());
      input->align(FL_ALIGN_RIGHT);
      break;
    case FIELD_OPTION_BOOL:
      input = new Fl_Check_Button(xx, yy, 2 * BB, BH, it->first.c_str());
      input->type(FL_TOGGLE_BUTTON);
      break;
    case FIELD_OPTION_PATH: {
      input = new Fl_Input(xx, yy, IW, BH, it->first.c_str());
      input->align(FL_ALIGN_RIGHT);
      int tw = (int)fl_width(it->first.c_str());
      Fl_Button *b = new Fl_Button(xx + IW + tw + 2 * WB, yy, BB, BH, "Choose");
      b->callback(field_select_file_cb, input);
    } break;
    case FIELD_OPTION_STRING:
      input = new Fl_Input(xx, yy, IW, BH, it->first.c_str());
      input->align(FL_ALIGN_RIGHT);
      break;
    case FIELD_OPTION_LIST:
    case FIELD_OPTION_LIST_DOUBLE:
    default:
      input = new Fl_Input(xx, yy, IW, BH, it->first.c_str());
      input->align(FL_ALIGN_RIGHT);
      break;
    }
    options_widget.push_back(input);
    yy += BH;
  }
  if(!f->callbacks.empty())
    help += std::string("<p><center><b>Actions</b></center>");
  for(auto it = f->callbacks.begin(); it != f->callbacks.end(); it++) {
    Fl_Widget *btn;
    help += std::string("<p><b>") + it->first + "</b>: ";
    help += it->second->getDescription();
    btn = new Fl_Button(xx, yy, IW, BH, it->first.c_str());
    btn->callback(field_callback_cb, it->second);
    yy += BH;
  }
  help_display->value(help.c_str());
  options_scroll->end();

  FL_NORMAL_SIZE += _deltaFontSize;

  loadFieldOptions();
  options_scroll->damage(1);
  put_on_view_btn->activate();
  delete_btn->activate();
  loadFieldList();
}

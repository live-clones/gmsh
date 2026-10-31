// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Jonathan Lambrechts
//

#include <sstream>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Input.H>
#include <algorithm>
#include <FL/fl_draw.H>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "FlGui.h"
#include "drawContext.h"
#include "fieldWindow.h"
#include "paletteWindow.h"
#include "fileDialogs.h"
#include "GModel.h"
#include "PView.h"
#include "GmshMessage.h"
#include "scriptStringInterface.h"
#include "StringUtils.h"
#include "Options.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

void field_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->fields->win->show();
  FlGui::instance()->fields->editField(nullptr);
}

#if defined(HAVE_MESH)

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
  if(!field) return;
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
    input->value(fileChooserGetName(1).c_str());
    input->set_changed();
  }
}

static void field_help_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->fields->toggleHelp(); }

static void field_resized_cb(void *data)
{ FlGui::instance()->fields->layout(); }

#endif

fieldWindow::fieldWindow(int deltaFontSize)
  : _deltaFontSize(deltaFontSize), _helpOpen(false)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  // as narrow as the option window: the fields on top, the one chosen below
  int width0 = TW;
  int height0 = 20 * BH;
  int width = std::max(CTX::instance()->fieldSize[0], width0);
  int height = std::max(CTX::instance()->fieldSize[1], height0);

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Size fields", CTX::instance()->fieldOffset);
  win->box(GMSH_WINDOW_BOX);

#if defined(HAVE_MESH)
  int x = WB, y = WB, w = (width - 4 * WB) / 3;

  Fl_Menu_Button *new_btn = new Fl_Menu_Button(x, y, w, BH, "New");
  FieldManager &fields = *GModel::current()->getFields();

  for(auto it = fields.mapTypeName.begin(); it != fields.mapTypeName.end(); it++)
    new_btn->add(it->first.c_str());
  new_btn->callback(field_new_cb);

  delete_btn = new Fl_Button(x + w + WB, y, w, BH, "Delete");
  delete_btn->callback(field_delete_cb, this);

  put_on_view_btn = new Fl_Menu_Button(
    x + 2 * (w + WB), y, width - 2 * WB - 2 * (w + WB), BH, "Visualize");
  put_on_view_btn->callback(field_put_on_view_cb, this);

  y += BH + WB;
  fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
  int hb = 5 * (fl_height() + 2) + 4;
  browser = new Fl_Hold_Browser(x, y, width - 2 * WB, hb);
  browser->callback(field_browser_cb);

  y += hb + WB;
  w = width - 2 * WB;
  int h = height - y - WB;
  empty_message = new Fl_Box(x, y, w, h,
                             "Create a new field\n\n"
                             "- or -\n\nSelect a field in the list");
  empty_message->align(FL_ALIGN_CENTER);

  editor_group = new Fl_Group(x, y, w, h);

  title = new Fl_Box(x, y, w, BH, "field_name");
  title->labelfont(FL_BOLD);
  title->labelsize(FL_NORMAL_SIZE + 3);
  title->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

  y += BH + WB;
  h -= BH + WB;
  options_scroll = new Fl_Scroll(x, y, w, h - BH - WB);
  options_scroll->type(Fl_Scroll::VERTICAL);
  options_group = new Fl_Group(x, y, w, 0);
  options_group->end();
  help_header = new Fl_Button(x, y, w, BH);
  help_header->box(FL_FLAT_BOX);
  help_header->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  help_header->labelfont(FL_BOLD);
  help_header->clear_visible_focus();
  help_header->callback(field_help_cb);
  // in full, in the flow of the options
  help = new Fl_Box(x, y, w, BH);
  help->align(FL_ALIGN_WRAP | FL_ALIGN_TOP | FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  help->hide();
  options_scroll->end();

  Fl_Button *apply_btn =
    new Fl_Return_Button(x + w - BB, y + h - BH, BB, BH, "Apply");
  apply_btn->callback(field_apply_cb, this);

  background_btn = new Fl_Round_Button(x, y + h - BH, w - BB - WB, BH,
                                       "Set as background field");

  // the options take the room, Apply stays at the bottom right
  editor_group->resizable(new Fl_Box(x + IW, y, w - IW - BB - WB, h - BH - WB));
  editor_group->end();

  // the buttons and the list widen, the editor takes the height
  win->resizable(new Fl_Box(2 * WB, y, width - 4 * WB, h - BH - WB));
  // the least height leaves three rows of field options
  ((paletteWindow *)win)->sizeRange(width0, 7 * WB + 6 * BH + hb);
  ((paletteWindow *)win)->whenResized(field_resized_cb, nullptr);

#endif

  win->end();

  FL_NORMAL_SIZE += deltaFontSize;

  loadFieldViewList();
  editField(nullptr);
}

void fieldWindow::toggleHelp()
{
  _helpOpen = !_helpOpen;
  layout();
}

void fieldWindow::layout()
{
#if defined(HAVE_MESH)
  // the help under the options, kept where it was scrolled to
  Fl_Scroll *s = options_scroll;
  int ypos = s->yposition();
  s->scroll_to(0, 0);
  int x = s->x(), w = s->w() - Fl::scrollbar_size() - WB;
  int y = options_group->y() + options_group->h();
  help_header->copy_label(_helpOpen ? "@-22> Help" : "@-2> Help");
  help_header->resize(x, y, w, BH);
  if(_helpOpen) {
    help->resize(x, y + BH, w, wrappedHeight(help, w));
    help->show();
  }
  else {
    help->hide();
    help->resize(x, y, w, 0);
  }
  int end = help->visible() ? help->y() + help->h() : y + BH;
  s->scroll_to(0, std::min(ypos, std::max(0, end - s->y() - s->h())));
  s->init_sizes();
  s->redraw();
#endif
}

void fieldWindow::loadFieldViewList()
{
#if defined(HAVE_MESH)
  put_on_view_btn->clear();
  put_on_view_btn->add("Create new view");
  // only for a field being edited
  if(editor_group->user_data())
    put_on_view_btn->activate();
  else
    put_on_view_btn->deactivate();
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    std::ostringstream s;
    s << "Put on View [" << i << "]";
    put_on_view_btn->add(s.str().c_str());
  }
#endif
}

void fieldWindow::loadFieldList()
{
#if defined(HAVE_MESH)
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
#endif
}

void fieldWindow::saveFieldOptions()
{
#if defined(HAVE_MESH)
  auto input = options_widget.begin();
  Field *f = (Field *)editor_group->user_data();
  std::ostringstream sstream;
  int i;
  char a;
  double d;
  sstream.precision(16);
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    FieldOption *option = it->second;
    if(!option) continue;
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
      scriptAddFieldOption(f->id, it->first, sstream.str(), option->getType(),
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
#endif
}

void fieldWindow::loadFieldOptions()
{
#if defined(HAVE_MESH)
  Field *f = (Field *)editor_group->user_data();
  auto input = options_widget.begin();
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    FieldOption *option = it->second;
    if(!option) continue;
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
#endif
}

void fieldWindow::editField(Field *f)
{
#if defined(HAVE_MESH)
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
  options_scroll->scroll_to(0, 0);
  options_group->clear();
  options_widget.clear();
  options_group->begin();
  int xx = options_group->x() + WB;
  int yy = options_group->y();

  std::string str = f->getDescription();
  if(!f->options.empty()) str += "\n\nOptions:";
  for(auto it = f->options.begin(); it != f->options.end(); it++) {
    FieldOption *option = it->second;
    if(!option) continue;
    if(option->isDeprecated()) continue;
    Fl_Widget *input;
    str += "\n\n" + it->first + " (" + option->getTypeName() +
           "): " + option->getDescription();
    switch(option->getType()) {
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
  if(!f->callbacks.empty()) str += "\n\nActions:";
  for(auto it = f->callbacks.begin(); it != f->callbacks.end(); it++) {
    Fl_Widget *btn;
    str += "\n\n" + it->first + ": " + it->second->getDescription();
    btn = new Fl_Button(xx, yy, IW, BH, it->first.c_str());
    btn->callback(field_callback_cb, it->second);
    yy += BH;
  }
  options_group->end();
  // its children are placed: only the box of the group changes
  options_group->Fl_Widget::resize(options_group->x(), options_group->y(),
                                   options_group->w(),
                                   yy - options_group->y() + WB);
  // a label, where '@' would start a symbol
  ReplaceSubStringInPlace("@", "@@", str);
  help->copy_label(str.c_str());

  FL_NORMAL_SIZE += _deltaFontSize;

  loadFieldOptions();
  layout();
  put_on_view_btn->activate();
  delete_btn->activate();
  loadFieldList();
#endif
}

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cctype>
#include <cstdlib>
#include <functional>
#include <fstream>
#include <map>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include "FlGui.h"
#include "hintInput.h"
#include "graphicWindow.h"
#include "windowPlacement.h"
#include "editorWindow.h"
#include "Context.h"
#include "GmshMessage.h"
#include "OS.h"
#include "StringUtils.h"
#include "ScriptStyles.h"

// a help text with the key of a shortcut, as this platform names it
static std::string withKey(const char *text, char key)
{
#if defined(__APPLE__)
  return std::string(text) + " (Cmd+" + key + ")";
#else
  return std::string(text) + " (Ctrl+" + key + ")";
#endif
}

// the window of an editor, which tells it when it is activated, and closes
// with Cmd+W (Ctrl+W)
class editorFrame : public Fl_Double_Window {
public:
  std::function<void()> activated;
  editorFrame(int w, int h) : Fl_Double_Window(w, h) {}
  int handle(int event) override
  {
    if((event == FL_FOCUS || event == FL_ENTER) && activated) activated();
    // closed as the tools are (not by Escape, which would be easy to press
    // while typing)
    if(event == FL_SHORTCUT && Fl::test_shortcut(FL_COMMAND | 'w')) {
      do_callback();
      return 1;
    }
    return Fl_Double_Window::handle(event);
  }
};

class editorWindow {
private:
  std::string _fileName;
  editorFrame *_win;
  Fl_Text_Editor *_editor;
  Fl_Text_Buffer *_text, *_style;
  hintInput *_find, *_line;
  bool _modified;
  // the file as it was last read or written here
  std::string _read;
  // the colors of the styles, those of the light or the dark scheme
  Fl_Text_Display::Style_Table_Entry _styles[6];
  void _title()
  {
    std::string name =
      SplitFileName(_fileName)[1] + SplitFileName(_fileName)[2];
    _win->copy_label((name + (_modified ? " *" : "")).c_str());
  }
  void _restyle()
  {
    char *text = _text->text();
    _style->text(GetScriptStyles(_fileName, text).c_str());
    free(text);
  }
  static void _modified_cb(int pos, int inserted, int deleted, int restyled,
                           const char *deletedText, void *data)
  {
    editorWindow *e = (editorWindow *)data;
    if(!inserted && !deleted) return;
    e->_restyle();
    if(!e->_modified) {
      e->_modified = true;
      e->_title();
    }
  }
  static void _save_cb(Fl_Widget *w, void *data)
  { ((editorWindow *)data)->save(); }
  static void _reload_cb(Fl_Widget *w, void *data)
  {
    editorWindow *e = (editorWindow *)data;
    if(!e->save()) return;
    geometry_reload_cb(nullptr, nullptr);
  }
  // a field focused by its shortcut, its text selected
  static void _focus(Fl_Input *field)
  {
    field->take_focus();
    field->insert_position(0, field->size());
  }
  static void _find_cb(Fl_Widget *w, void *data)
  {
    editorWindow *e = (editorWindow *)data;
    if(w != e->_find) { // the shortcut
      _focus(e->_find);
      return;
    }
    // the next one on Enter; as the text is typed, the first one from the
    // match being extended
    bool enter = Fl::event() == FL_KEYBOARD && (Fl::event_key() == FL_Enter ||
                                                Fl::event_key() == FL_KP_Enter);
    e->find(!enter);
  }
  static void _line_cb(Fl_Widget *w, void *data)
  {
    editorWindow *e = (editorWindow *)data;
    if(w != e->_line) { // the shortcut
      _focus(e->_line);
      return;
    }
    e->goToLine(atoi(e->_line->value()));
  }
  static void _close_cb(Fl_Widget *w, void *data)
  {
    editorWindow *e = (editorWindow *)data;
    if(e->_modified) {
      switch(fl_choice("Save the changes to '%s'?", "Cancel", "Save", "Discard",
                       e->_fileName.c_str())) {
      case 0: return;
      case 1:
        if(!e->save()) return;
        break;
      default: e->load(); break;
      }
    }
    e->_win->hide();
  }

public:
  editorWindow(const std::string &fileName)
    : _fileName(fileName), _modified(false)
  {
    int width = 48 * FL_NORMAL_SIZE, height = 36 * FL_NORMAL_SIZE;
    Fl_Group::current(nullptr);
    _win = new editorFrame(width, height);
    _win->activated = [this] { refresh(); };
    _win->box(GMSH_WINDOW_BOX);
    _win->callback(_close_cb, this);

    // the buttons, then the fields to find a text and to go to a line, the
    // space between them taking what the width of the window adds, as the
    // tool bar of the messages
    int bh = BH - 4, wb = WB / 2, bb = BB - 3 * WB, top = bh + 2 * wb;
    Fl_Group *bar = new Fl_Group(0, 0, width, top);
    bar->box(GMSH_SIMPLE_TOP_BOX);
    Fl_Button *save = new Fl_Button(wb, wb, bb, bh, "Save");
    save->shortcut(FL_COMMAND | 's');
    save->copy_tooltip(withKey("Save the file", 'S').c_str());
    save->callback(_save_cb, this);
    int rw = 2 * bb;
    Fl_Button *reload =
      new Fl_Button(wb + bb + WB, wb, rw, bh, "Save and reload");
    reload->shortcut(FL_COMMAND | 'r');
    reload->copy_tooltip(
      withKey("Save the file, then read the model again", 'R').c_str());
    reload->callback(_reload_cb, this);
    for(Fl_Button *b : {save, reload}) {
      b->labelsize(FL_NORMAL_SIZE - 1);
      b->box(FL_THIN_UP_BOX);
    }
    int lw = (int)(1.3 * BB), sw = 2 * BB;
    int lx = width - wb - lw, sx = lx - WB - sw, left = wb + bb + 2 * WB + rw;
    Fl_Box *space = new Fl_Box(left, wb, std::max(1, sx - WB - left), bh);
    static std::string findHelp =
      withKey("Find the text: the first one as it is typed, the next one on "
              "Enter",
              'F');
    _find = searchBox(sx, wb, sw, bh, "Find", findHelp.c_str(), _find_cb);
    _find->user_data(this);
    _find->textsize(FL_NORMAL_SIZE - 1);
    _line = new hintInput(lx, wb, lw, bh, nullptr, "Go to line");
    _line->box(FL_DOWN_BOX);
    _line->textsize(FL_NORMAL_SIZE - 1);
    _line->copy_tooltip(
      withKey("Go to the line, as an error gives it", 'L').c_str());
    _line->when(FL_WHEN_ENTER_KEY_ALWAYS);
    _line->callback(_line_cb, this);
    // (the shortcuts of the fields)
    Fl_Button *find = new Fl_Button(0, 0, 0, 0);
    find->shortcut(FL_COMMAND | 'f');
    find->callback(_find_cb, this);
    Fl_Button *line = new Fl_Button(0, 0, 0, 0);
    line->shortcut(FL_COMMAND | 'l');
    line->callback(_line_cb, this);
    bar->resizable(space);
    bar->end();

    _text = new Fl_Text_Buffer();
    _style = new Fl_Text_Buffer();
    _text->tab_distance(4);
    _editor = new Fl_Text_Editor(0, top, width, height - top);
    _editor->box(GMSH_SIMPLE_TOP_BOX);
    _editor->buffer(_text);
    _editor->tab_nav(0); // Tab inserts a tab
    _editor->highlight_data(_style, _styles, 6, StylePlain, nullptr, nullptr);
    _text->add_modify_callback(_modified_cb, this);
    _win->resizable(_editor);
    // (not narrower than the buttons and the fields, which keep their width)
    _win->size_range(left + WB + sw + WB + lw + wb, 4 * BH);
    _win->end();
    colors();
    load();
  }
  // the colors of the light or the dark scheme, the font of the text
  void colors()
  {
#if defined(WIN32) // FL_SCREEN seems to be too tiny on most Windows setups
    Fl_Font font = FL_COURIER, bold = FL_COURIER_BOLD;
#else
    Fl_Font font = FL_SCREEN, bold = FL_SCREEN_BOLD;
#endif
    Fl_Fontsize size = FL_NORMAL_SIZE;
    bool dark = CTX::instance()->guiDark;
    Fl_Color comment =
      dark ? fl_rgb_color(0x6a, 0x99, 0x55) : fl_rgb_color(0x00, 0x80, 0x00);
    Fl_Color string =
      dark ? fl_rgb_color(0xce, 0x91, 0x78) : fl_rgb_color(0xa3, 0x15, 0x15);
    Fl_Color number =
      dark ? fl_rgb_color(0xb5, 0xce, 0xa8) : fl_rgb_color(0x09, 0x86, 0x58);
    Fl_Color word =
      dark ? fl_rgb_color(0x56, 0x9c, 0xd6) : fl_rgb_color(0x00, 0x50, 0xc0);
    Fl_Color option =
      dark ? fl_rgb_color(0xc5, 0x86, 0xc0) : fl_rgb_color(0x8a, 0x3f, 0xb0);
    Fl_Text_Display::Style_Table_Entry styles[6] = {
      {FL_FOREGROUND_COLOR, font, size},
      {comment, font, size},
      {string, font, size},
      {number, font, size},
      {word, bold, size},
      {option, font, size}};
    for(int i = 0; i < 6; i++) _styles[i] = styles[i];
    _editor->textfont(font);
    _editor->textsize(size);
    _editor->color(FL_BACKGROUND2_COLOR);
    _editor->textcolor(FL_FOREGROUND_COLOR);
    _editor->cursor_color(FL_FOREGROUND_COLOR);
    _editor->linenumber_font(font);
    _editor->linenumber_size(size - 2);
    _editor->linenumber_bgcolor(FL_BACKGROUND_COLOR);
    _editor->linenumber_fgcolor(FL_INACTIVE_COLOR);
    fl_font(font, size - 2);
    _editor->linenumber_width((int)fl_width("00000") + 4);
    _editor->redraw();
  }
  // the file read again if it changed on disk (the graphical interface adds
  // to the scripts) and not here
  void refresh()
  {
    if(!_modified && onDisk() != _read) load();
  }
  // the file as it is on disk
  std::string onDisk() const
  {
    std::ifstream in(_fileName, std::ios::binary);
    std::stringstream s;
    if(in) s << in.rdbuf();
    return s.str();
  }
  // the file read again, the cursor where it was
  void load()
  {
    int pos = _editor->insert_position();
    _read = onDisk();
    _text->text(_read.c_str());
    _editor->insert_position(std::min(pos, _text->length()));
    // (an undo would not go before what was read)
    _text->canUndo(0);
    _text->canUndo(1);
    _modified = false;
    _title();
  }
  // the file written: false if it could not be, or if it changed on disk
  // since it was read (as when the graphical interface added to a script) and
  // is not to be overwritten
  bool save()
  {
    if(!_modified) return true;
    if(onDisk() != _read &&
       fl_choice("'%s' changed on disk since it was read here: overwrite it "
                 "with the text of the editor?",
                 "Cancel", "Overwrite", nullptr, _fileName.c_str()) != 1)
      return false;
    std::ofstream out(_fileName, std::ios::binary);
    char *text = _text->text();
    if(out) out << text;
    std::string written(text);
    free(text);
    if(!out) {
      Msg::Error("Could not write file '%s'", _fileName.c_str());
      return false;
    }
    _read = written;
    _modified = false;
    _title();
    return true;
  }
  // the next place of the text of the field after the cursor, or from the
  // start of the selection (the match being extended) if again; from the
  // start once the end is reached
  void find(bool again)
  {
    const char *what = _find->value();
    if(!what[0]) return;
    int found, pos = _editor->insert_position(), start, end;
    if(again && _text->selection_position(&start, &end)) pos = start;
    if(!_text->search_forward(pos, what, &found) &&
       !_text->search_forward(0, what, &found)) {
      fl_beep();
      return;
    }
    end = found + (int)strlen(what);
    _text->select(found, end);
    _editor->insert_position(end);
    _editor->show_insert_position();
  }
  // the cursor at the start of a line, the line selected
  void goToLine(int line)
  {
    if(line < 1) return;
    int start = _text->skip_lines(0, line - 1);
    _text->select(start, _text->line_end(start));
    _editor->insert_position(start);
    _editor->show_insert_position();
    _editor->take_focus();
  }
  void show()
  {
    if(!_win->shown()) centerWindow(_win);
    _win->show();
    _editor->take_focus();
  }
};

void editFile(const std::string &fileName)
{
  std::string prog = CTX::instance()->editor;
  if(!prog.empty()) {
    // (the name quoted: it may have spaces)
    std::string file = "\"" + FixWindowsPath(fileName) + "\"";
    SystemCall(ReplaceSubString("%s", file, FixWindowsPath(prog)));
    return;
  }
  // one window for each file, kept
  static std::map<std::string, editorWindow *> editors;
  editorWindow *&e = editors[fileName];
  if(!e)
    e = new editorWindow(fileName);
  else {
    e->colors();
    e->refresh();
  }
  e->show();
}

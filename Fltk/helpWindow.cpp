// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <sstream>
#include <algorithm>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Color_Chooser.H>
#include "FlGui.h"
#include "helpWindow.h"
#include "paletteWindow.h"
#include "CommandLine.h"
#include "StringUtils.h"
#include "OS.h"
#include "Options.h"
#include "Parser.h"
#include "Context.h"
#include "drawContext.h"

static const char *help_link(Fl_Widget *w, const char *uri)
{
  fl_open_uri(uri);
  return 0;
}

struct opt_data{
  std::string category;
  int index;
  std::string name;
};

static void interactive_cb(Fl_Widget* w, void* data)
{
  if(!data) return;
  Fl_Value_Input *v = (Fl_Value_Input*)w;
  opt_data *d = (opt_data*)data;
  double val = v->value();
  NumberOption(GMSH_SET|GMSH_GUI, d->category.c_str(), d->index,
               d->name.c_str(), val);
  drawContext::global()->draw();
}

double numberOrStringOptionChooser(const std::string &category, int index,
                                   const std::string &name, bool isNumber,
                                   const std::string &title,
                                   bool isInteractive, double minimum,
                                   double maximum, double step)
{
  double valn = 0.;
  std::string vals = "";
  if(isNumber)
    NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), valn);
  else
    StringOption(GMSH_GET, category.c_str(), index, name.c_str(), vals);

  int nn = (isInteractive ? 2 : 3);
  int width = nn * BB + (nn + 1) * WB, height = 2 * BH + 3 * WB;
  std::string t = title;
  if(t.empty()) t = (isNumber ? "Number Chooser" : "String Chooser");
  Fl_Window *win = new paletteWindow(width, height, false, t.c_str());
  win->set_modal();
  win->hotspot(win);
  Fl_Value_Input *number = 0;
  Fl_Input *string = 0;
  if(isNumber){
    number = new Fl_Value_Input(WB, WB, width - 2 * WB, BH);
    number->value(valn);
    if(isInteractive){
      static opt_data d;
      d.category = category;
      d.index = index;
      d.name = name;
      number->minimum(minimum);
      number->maximum(maximum);
      number->step(step);
      number->callback(interactive_cb, (void*)&d);
      number->when(FL_WHEN_RELEASE);
    }
  }
  else{
    string = new Fl_Input(WB, WB, width - 2 * WB, BH);
    string->value(vals.c_str());
  }
  Fl_Button *ok = new Fl_Return_Button
    (width - nn * BB - nn * WB, 2 * WB + BH, BB, BH, "OK");
  Fl_Button *def = new Fl_Button
    (width - (nn - 1) * BB - (nn - 1) * WB, 2 * WB + BH, BB, BH, "Default");
  Fl_Button *cancel = 0;
  if(!isInteractive)
    cancel = new Fl_Button
      (width - BB - WB, 2 * WB + BH, BB, BH, "Cancel");
  win->end();
  win->show();
  if(number) number->take_focus();
  if(string) string->take_focus();
  bool done = false;
  while(win->shown()){
    if(done) break;
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == win || o == cancel) {
        done = true;
        break;
      }
      if(o == ok){
        if(isNumber){
          valn = number->value();
          NumberOption(GMSH_SET|GMSH_GUI, category.c_str(), index,
                       name.c_str(), valn);
        }
        else{
          vals = string->value();
          StringOption(GMSH_SET|GMSH_GUI, category.c_str(), index,
                       name.c_str(), vals);
        }
        done = true;
        break;
      }
      if(o == def){
        if(isNumber){
          NumberOption(GMSH_GET_DEFAULT, category.c_str(), index,
                       name.c_str(), valn);
          number->value(valn);
          if(isInteractive) number->do_callback();
        }
        else{
          StringOption(GMSH_GET_DEFAULT, category.c_str(), index,
                       name.c_str(), vals);
          string->value(vals.c_str());
        }
        break;
      }
    }
  }
  delete win;

  if(isNumber){
    NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), valn);
    return valn;
  }
  else
    return 0.;
}

static void colorOptionChooser(const std::string &category, int index,
                               const std::string &name)
{
  unsigned int col;
  ColorOption(GMSH_GET, category.c_str(), index, name.c_str(), col);
  uchar r = CTX::instance()->unpackRed(col);
  uchar g = CTX::instance()->unpackGreen(col);
  uchar b = CTX::instance()->unpackBlue(col);
  if(fl_color_chooser("Color Chooser", r, g, b, 1)){
    col = CTX::instance()->packColor(r, g, b, 255);
    ColorOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(), col);
  }
}

static void editOption(const std::string &type, const std::string &cat,
                       const std::string &name)
{
  std::string category = cat;
  int index = 0;
  std::string::size_type p1 = cat.find('['), p2 = cat.find(']');
  if(p1 != std::string::npos && p2 != std::string::npos){
    category = cat.substr(0, p1);
    std::string num = cat.substr(p1 + 1, p2 - p1 - 1);
    index = atoi(num.c_str());
  }

  if(type == "number")
    numberOrStringOptionChooser(category, index, name, true);
  else if(type == "string")
    numberOrStringOptionChooser(category, index, name, false);
  else if(type == "color")
    colorOptionChooser(category, index, name);
}

static void browser_cb(Fl_Widget *w, void *data)
{
  if(Fl::event_clicks()){
    // edit value
    for(int i = 1; i <= FlGui::instance()->help->browser->size(); i++) {
      if(FlGui::instance()->help->browser->selected(i)) {
        const char *text = FlGui::instance()->help->browser->text(i);
        const char *data = (const char*)FlGui::instance()->help->browser->data(i);
        if(data){
          std::string option(text), type(data), c1, c2;
          std::string::size_type p1 = std::string::npos, p2 = p1;
          p1 = option.find_first_of('.');
          if(p1 != std::string::npos){
            c1 = option.substr(0, p1);
            p2 = option.find_first_of(' ', p1);
            if(p2 != std::string::npos)
              c2 = option.substr(p1 + 1, p2 - p1 - 1);
          }
          if(type == "color"){
            if(c2.size() > 6) c2 = c2.substr(6);
            else c2 = "";
          }
          if(c1.size() && c2.size()){
            editOption(type, c1, c2);
            int top = FlGui::instance()->help->browser->topline();
            help_options_cb(0, 0);
            FlGui::instance()->help->browser->topline(top);
            FlGui::instance()->help->browser->select(i);
            drawContext::global()->draw();
          }
        }
        break;
      }
    }
  }
  else{
    // copy to clipboard
    std::string buff;
    for(int i = 1; i <= FlGui::instance()->help->browser->size(); i++) {
      if(FlGui::instance()->help->browser->selected(i)) {
        const char *c = FlGui::instance()->help->browser->text(i);
        if(strlen(c) > 5 && c[0] == '@')
          buff += std::string(&c[5]);
        else
          buff += std::string(c);
        buff += "\n";
      }
    }
    Fl::copy(buff.c_str(), buff.size(), 0);
    Fl::copy(buff.c_str(), buff.size(), 1);
  }
}

void help_options_cb(Fl_Widget *w, void *data)
{
  std::vector<std::string> s0;
  int diff = FlGui::instance()->help->modified->value();
  int help = FlGui::instance()->help->showhelp->value();
  std::string search = FlGui::instance()->help->search->value();
  std::transform(search.begin(), search.end(), search.begin(), ::tolower);

  PrintOptions(0, GMSH_FULLRC, diff, help, 0, &s0);
  PrintParserSymbols(help, s0);

  int top = FlGui::instance()->help->browser->topline();
  FlGui::instance()->help->browser->clear();
  for(unsigned int i = 0; i < s0.size(); i++){
    std::string::size_type sep = s0[i].rfind('\0');
    void *d = 0;
    if(sep != std::string::npos){
      std::string tmp = s0[i].substr(sep + 1);
      if(tmp == "number") d = (void*)"number";
      else if(tmp == "string") d = (void*)"string";
      else if(tmp == "color") d = (void*)"color";
    }
    if(search.empty()){
      FlGui::instance()->help->browser->add(s0[i].c_str(), d);
    }
    else{
      std::string tmp(s0[i]);
      std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
      if(tmp.find(search) != std::string::npos)
        FlGui::instance()->help->browser->add(s0[i].c_str(), d);
    }
  }
  FlGui::instance()->help->browser->topline(top);
}

helpWindow::helpWindow()
{
  {
    int width = 28 * FL_NORMAL_SIZE;
    int height = 18 * BH;

    about = new paletteWindow
      (width, height, CTX::instance()->nonModalWindows ? true : false, "About Gmsh");
    about->box(GMSH_WINDOW_BOX);

    Fl_Help_View *o = new Fl_Help_View(0, 0, width, height);
    o->textfont(FL_HELVETICA);
    o->textsize(FL_NORMAL_SIZE);
    o->box(FL_FLAT_BOX);
    std::ostringstream sstream;
    sstream << "<center><h3>Gmsh</h3><br>version " << GetGmshVersion()
            << "<p>Copyright (C) 1997-2014"
            << "<br>Christophe Geuzaine and Jean-Francois Remacle"
            << "<p><a href=\"http://geuz.org/gmsh/doc/CREDITS.txt\">Credits</a> "
            << "and <a href=\"http://geuz.org/gmsh/doc/LICENSE.txt\">licensing "
            << "information</a>"
            << "<p>Please send all questions and bug reports to "
            << "<a href=\"mailto:gmsh@geuz.org\">gmsh@geuz.org</a></center>"
            << "<ul>"
            << "<li><i>GUI toolkit:</i> FLTK "
            << FL_MAJOR_VERSION << "." << FL_MINOR_VERSION << "." << FL_PATCH_VERSION
            << "<li><i>Build OS:</i> " << GetGmshBuildOS()
            << "<li><i>Build date:</i> " << GetGmshBuildDate()
            << "<li><i>Build host:</i> " << GetGmshBuildHost()
            << "<li><i>Build options:</i>" << GetGmshBuildOptions()
            << "<li><i>Packaged by:</i> " << GetGmshPackager()
            << "</ul>"
            << "<center>Visit <a href=\"http://geuz.org/gmsh/\">http://geuz.org/gmsh/</a> "
            << "for more information</center>";
    o->value(sstream.str().c_str());
    o->link(help_link);
    about->position(Fl::x() + Fl::w()/2 - width / 2,
                    Fl::y() + Fl::h()/2 - height / 2);
    about->end();
  }

  {
    int width = 40 * FL_NORMAL_SIZE;
    int height = 18 * BH;

    basic = new paletteWindow
      (width, height, CTX::instance()->nonModalWindows ? true : false,
       "Keyboard and Mouse Usage");
    basic->box(GMSH_WINDOW_BOX);

    Fl_Help_View *o = new Fl_Help_View(0, 0, width, height);
    o->textfont(FL_HELVETICA);
    o->textsize(FL_NORMAL_SIZE - 1);
    o->box(FL_FLAT_BOX);

    std::string s;
    s += "<h3>Keyboard Shortcuts</h3>";
    s += "<table border=1>";
    {
      std::vector<std::pair<std::string, std::string> > s0 = GetShortcutsUsage();
      for(unsigned int i = 0; i < s0.size(); i++)
        s += "<tr><td>" + s0[i].first + "</td><td>" + s0[i].second + "</td></tr>";
    }
    s += "</table>";

    s += "<h3>Mouse Actions</h3>";
    s += "<table border=1>";
    {
      std::vector<std::pair<std::string, std::string> > s0 = GetMouseUsage();
      for(unsigned int i = 0; i < s0.size(); i++)
        s += "<tr><td>" + s0[i].first + "</td><td>" + s0[i].second + "</td></tr>";
    }
    s += "</table>";
    s += "For a 2 button mouse, Middle button = Shift+Left button.<p>";
    s += "For a 1 button mouse, Middle button = Shift+Left button, "
         "Right button = Alt+Left button.";


    s += "<h3>Command Line Switches</h3>";
    s += "<table border=1>";
    {
      std::vector<std::pair<std::string, std::string> > s0 = GetUsage();
      for(unsigned int i = 0; i < s0.size(); i++)
        if(s0[i].first.size() && s0[i].second.size())
          s += "<tr><td>" + s0[i].first + "</td><td>" + s0[i].second + "</td></tr>";
        else if(s0[i].first.size() && s0[i].second.empty())
          s += "</table>" + s0[i].first + "<table border=1>";
    }
    s += "</table>";

    o->value(s.c_str());

    basic->resizable(o);
    basic->position(Fl::x() + Fl::w()/2 - width / 2,
                    Fl::y() + Fl::h()/2 - height / 2);
    basic->end();
  }

  {
    int width = 40 * FL_NORMAL_SIZE;
    int height = 18 * BH;

    options = new paletteWindow
      (width, height, CTX::instance()->nonModalWindows ? true : false,
       "Current Options and Worskspace");
    options->box(GMSH_WINDOW_BOX);

    int BW = (width - 4 * WB) / 3;

    modified = new Fl_Check_Button
      (WB, WB, BW, BH, "Only show modified");
    modified->type(FL_TOGGLE_BUTTON);
    modified->callback(help_options_cb);
    modified->tooltip("Show only values different from defaults");

    showhelp = new Fl_Check_Button
      (2 * WB + BW, WB, BW, BH, "Show help");
    showhelp->type(FL_TOGGLE_BUTTON);
    showhelp->callback(help_options_cb);
    showhelp->tooltip("Show help strings");

    Fl_Group* o = new Fl_Group(3 * WB + 2 * BW, WB, BW, BH);
    o->tooltip("Filter values");
    o->box(FL_DOWN_BOX);
    o->color(FL_BACKGROUND2_COLOR);
    search = new Fl_Input
      (3 * WB + 2 * BW + BH, WB + 2, BW - BH - 2, BH - 4, "@gmsh_search");
    search->box(FL_FLAT_BOX);
    search->callback(help_options_cb);
    search->when(FL_WHEN_CHANGED);
    search->take_focus();
    o->resizable(search);
    o->end();

    browser = new Fl_Browser(0, BH + 2 * WB, width, height - BH - 2 * WB);
    browser->box(GMSH_SIMPLE_TOP_BOX);
    browser->textfont(FL_SCREEN);
    browser->textsize(FL_NORMAL_SIZE - 2);
    browser->type(FL_MULTI_BROWSER);
    browser->callback(browser_cb);
    browser->tooltip("Double-click to edit value");

    options->resizable(browser);
    options->position(Fl::x() + Fl::w()/2 - width / 2,
                      Fl::y() + Fl::h()/2 - height / 2);
    options->size_range(width, height);
    options->end();
  }

}

// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <sstream>
#include <algorithm>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include "FlGui.h"
#include "helpWindow.h"
#include "paletteWindow.h"
#include "CommandLine.h"
#include "StringUtils.h"
#include "OS.h"
#include "Options.h"
#include "Context.h"

static const char *help_link(Fl_Widget *w, const char *uri)
{
  std::string prog = FixWindowsPath(CTX::instance()->webBrowser);
  SystemCall(ReplaceSubString("%s", uri, prog));
  return 0;
}

static void copy_cb(Fl_Widget *w, void *data)
{
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
  // bof bof bof
  Fl::copy(buff.c_str(), buff.size(), 0);
  Fl::copy(buff.c_str(), buff.size(), 1);
}

void help_options_cb(Fl_Widget *w, void *data)
{
  std::vector<std::string> s0;
  int diff = FlGui::instance()->help->modified->value();
  int help = FlGui::instance()->help->showhelp->value();
  std::string search = FlGui::instance()->help->search->value();
  std::transform(search.begin(), search.end(), search.begin(), ::tolower);

  PrintOptions(0, GMSH_FULLRC, diff, help, 0, &s0);
  FlGui::instance()->help->browser->clear();
  for(unsigned int i = 0; i < s0.size(); i++){
    if(search.empty()){
      FlGui::instance()->help->browser->add(s0[i].c_str(), 0);
    }
    else{
      std::string tmp(s0[i]);
      std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
      if(tmp.find(search) != std::string::npos)
        FlGui::instance()->help->browser->add(s0[i].c_str(), 0);
    }
  }
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
            << "<p>Copyright (C) 1997-2013"
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
       "Current Options");
    options->box(GMSH_WINDOW_BOX);

    int BW = (width - 4 * WB) / 3;

    modified = new Fl_Check_Button
      (WB, WB, BW, BH, "Show modified");
    modified->type(FL_TOGGLE_BUTTON);
    modified->callback(help_options_cb);
    modified->tooltip("Show options with values different from defaults");

    showhelp = new Fl_Check_Button
      (2 * WB + BW, WB, BW, BH, "Show help");
    showhelp->type(FL_TOGGLE_BUTTON);
    showhelp->callback(help_options_cb);
    showhelp->tooltip("Show help string for each option");

    Fl_Group* o = new Fl_Group(3 * WB + 2 * BW, WB, BW, BH);
    o->tooltip("Filter options");
    o->box(FL_DOWN_BOX);
    o->color(FL_BACKGROUND2_COLOR);
    search = new Fl_Input
      (3 * WB + 2 * BW + 25, WB + 2, BW - 27, BH - 4, "@search");
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
    browser->callback(copy_cb);

    options->resizable(browser);
    options->position(Fl::x() + Fl::w()/2 - width / 2,
                      Fl::y() + Fl::h()/2 - height / 2);
    options->size_range(about->w(), about->h());
    options->end();
  }

}

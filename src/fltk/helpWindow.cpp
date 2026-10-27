// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <algorithm>
#include <string>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_SVG_Image.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/filename.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "inputValue.h"
#include "helpWindow.h"
#include "hintInput.h"
#include "paletteWindow.h"
#include "CommandLine.h"
#include "StringUtils.h"
#include "OS.h"
#include "Options.h"
#include "Context.h"
#include "drawContext.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_PETSC)
#include "petsc.h"
#endif

#if defined(HAVE_OCC)
#include "Standard_Version.hxx"
#endif

#if defined(HAVE_MED)
#include <med.h>
#endif

static const char *help_link(Fl_Widget *w, const char *uri)
{
  fl_open_uri(uri);
  return nullptr;
}

struct opt_data {
  std::string category;
  int index;
  std::string name;
};

static void interactive_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  inputValueFloat *v = (inputValueFloat *)w;
  opt_data *d = (opt_data *)data;
  double val = v->value();
  NumberOption(GMSH_SET | GMSH_GUI, d->category.c_str(), d->index,
               d->name.c_str(), val);
  drawContext::global()->draw();
}

double numberOrStringOptionChooser(const std::string &category, int index,
                                   const std::string &name, bool isNumber,
                                   const std::string &title, bool isInteractive,
                                   double minimum, double maximum, double step)
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
  inputValueFloat *number = nullptr;
  Fl_Input *string = nullptr;
  if(isNumber) {
    number = new inputValueFloat(WB, WB, width - 2 * WB, BH);
    number->value(valn);
    if(isInteractive) {
      static opt_data d;
      d.category = category;
      d.index = index;
      d.name = name;
      number->minimum(minimum);
      number->maximum(maximum);
      if(CTX::instance()->inputScrolling) number->step(step, 1);
      number->callback(interactive_cb, (void *)&d);
      number->when(FL_WHEN_RELEASE);
    }
  }
  else {
    string = new Fl_Input(WB, WB, width - 2 * WB, BH);
    string->value(vals.c_str());
  }
  Fl_Button *ok =
    new Fl_Return_Button(width - nn * BB - nn * WB, 2 * WB + BH, BB, BH, "OK");
  Fl_Button *def = new Fl_Button(width - (nn - 1) * BB - (nn - 1) * WB,
                                 2 * WB + BH, BB, BH, "Default");
  Fl_Button *cancel = nullptr;
  if(!isInteractive)
    cancel = new Fl_Button(width - BB - WB, 2 * WB + BH, BB, BH, "Cancel");
  win->end();
  win->show();
  if(number) number->take_focus();
  if(string) string->take_focus();
  bool done = false;
  while(win->shown()) {
    if(done) break;
    Fl::wait();
    for(;;) {
      Fl_Widget *o = Fl::readqueue();
      if(!o) break;
      if(o == win || o == cancel) {
        done = true;
        break;
      }
      if(o == ok) {
        if(isNumber) {
          valn = number->value();
          NumberOption(GMSH_SET | GMSH_GUI, category.c_str(), index,
                       name.c_str(), valn);
        }
        else {
          vals = string->value();
          StringOption(GMSH_SET | GMSH_GUI, category.c_str(), index,
                       name.c_str(), vals);
        }
        done = true;
        break;
      }
      if(o == def) {
        if(isNumber) {
          NumberOption(GMSH_GET_DEFAULT, category.c_str(), index, name.c_str(),
                       valn);
          number->value(valn);
          if(isInteractive) number->do_callback();
        }
        else {
          StringOption(GMSH_GET_DEFAULT, category.c_str(), index, name.c_str(),
                       vals);
          string->value(vals.c_str());
        }
        break;
      }
    }
  }
  delete win;

  if(isNumber) {
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
  if(fl_color_chooser("Color Chooser", r, g, b, 1)) {
    col = CTX::instance()->packColor(r, g, b, 255);
    ColorOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
                col);
  }
}

static void editOption(const std::string &type, const std::string &cat,
                       const std::string &name)
{
  std::string category = cat;
  int index = 0;
  std::string::size_type p1 = cat.find('['), p2 = cat.find(']');
  if(p1 != std::string::npos && p2 != std::string::npos) {
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
  if(Fl::event_clicks()) {
    // edit value
    for(int i = 1; i <= FlGui::instance()->help->browser->size(); i++) {
      if(FlGui::instance()->help->browser->selected(i)) {
        const char *text = FlGui::instance()->help->browser->text(i);
        const char *data =
          (const char *)FlGui::instance()->help->browser->data(i);
        if(data) {
          std::string option(text), type(data), c1, c2;
          std::string::size_type p1 = std::string::npos, p2 = p1;
          p1 = option.find_first_of('.');
          if(p1 != std::string::npos) {
            c1 = option.substr(0, p1);
            p2 = option.find_first_of(' ', p1);
            if(p2 != std::string::npos) c2 = option.substr(p1 + 1, p2 - p1 - 1);
          }
          if(type == "color") {
            if(c2.size() > 6)
              c2 = c2.substr(6);
            else
              c2 = "";
          }
          if(c1.size() && c2.size()) {
            editOption(type, c1, c2);
            int top = FlGui::instance()->help->browser->topline();
            help_options_cb(nullptr, nullptr);
            FlGui::instance()->help->browser->topline(top);
            FlGui::instance()->help->browser->select(i);
            drawContext::global()->draw();
          }
        }
        break;
      }
    }
  }
  else {
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
  FlGui::instance()->help->filter.set(FlGui::instance()->help->search);

  PrintOptions(0, GMSH_FULLRC, diff, help, nullptr, &s0);
#if defined(HAVE_PARSER)
  PrintParserSymbols(help, s0);
#endif

  int top = FlGui::instance()->help->browser->topline();
  FlGui::instance()->help->browser->clear();
  for(std::size_t i = 0; i < s0.size(); i++) {
    std::string::size_type sep = s0[i].rfind('\0');
    void *d = nullptr;
    if(sep != std::string::npos) {
      std::string tmp = s0[i].substr(sep + 1);
      if(tmp == "number")
        d = (void *)"number";
      else if(tmp == "string")
        d = (void *)"string";
      else if(tmp == "color")
        d = (void *)"color";
    }
    if(s0[i].size() > 256)
      s0[i].resize(256);

    if(FlGui::instance()->help->filter.matches(s0[i]))
      FlGui::instance()->help->browser->add(s0[i].c_str(), d);
  }
  FlGui::instance()->help->browser->topline(top);
}

// the colours of the help texts, which follow the colour scheme
static std::string hexColor(Fl_Color c)
{
  unsigned char r, g, b;
  Fl::get_color(c, r, g, b);
  char buf[16];
  sprintf(buf, "#%02x%02x%02x", r, g, b);
  return buf;
}

static std::string linkColor()
{ return CTX::instance()->guiDark ? "#4daafc" : "#005fb8"; }

static std::string mutedColor()
{
  return hexColor(
    fl_color_average(FL_FOREGROUND_COLOR, FL_BACKGROUND2_COLOR, 0.6f));
}

// the logo: the three facets of utils/icons/gmsh.svg and its shadow, the
// Gaussian blur of the original (which the SVG renderer of FLTK does not
// draw) emulated by a stack of translucent copies of the shadow triangle,
// each offset a bit further out with rounded corners
static const char *logoSvg =
  R"svg(<svg xmlns="http://www.w3.org/2000/svg" viewBox="280 210 800 780">
<defs>
<linearGradient id="side" gradientUnits="userSpaceOnUse" x1="1078.3" y1="1022.66" x2="615.57" y2="143.02"><stop offset="0" stop-color="#001000"/><stop offset="1" stop-color="#000000"/></linearGradient>
<linearGradient id="bottom" gradientUnits="userSpaceOnUse" gradientTransform="matrix(0.7216,0,0,0.7216,196.24,60.99)" x1="1356.44" y1="1220.72" x2="-206.54" y2="1114.72"><stop offset="0" stop-color="#000000"/><stop offset="1" stop-color="#ffffff"/></linearGradient>
</defs>
<g transform="matrix(0.884,0,0,0.884,79.18,110.35)">
<g transform="matrix(0.7216,0,0,0.7216,196.24,82.87)" fill="#000">
<path fill-opacity="0.0301" d="M 673.59,205.66 L 1178.44,1171.39 L 167.54,1171.51 Z"/>
<path fill-opacity="0.0487" d="M 673.59,185.63 L 1193.78,1180.68 L 152.18,1180.80 Z"/>
<path fill-opacity="0.0802" d="M 673.60,165.60 L 1209.12,1189.97 L 136.83,1190.10 Z"/>
<path fill-opacity="0.1058" d="M 673.61,145.56 L 1224.45,1199.26 L 121.47,1199.39 Z"/>
<path fill-opacity="0.1138" d="M 673.62,125.53 L 1239.79,1208.54 L 106.12,1208.68 Z"/>
<path fill-opacity="0.1022" d="M 677.74,113.36 L 1251.57,1211.03 A 4.64,4.64 0 0 1 1247.46,1217.83 L 98.44,1217.97 A 4.64,4.64 0 0 1 94.33,1211.17 L 669.51,113.36 A 4.64,4.64 0 0 1 677.74,113.36 Z"/>
<path fill-opacity="0.0776" d="M 685.97,109.06 L 1259.81,1206.73 A 13.93,13.93 0 0 1 1247.46,1227.12 L 98.44,1227.26 A 13.93,13.93 0 0 1 86.10,1206.86 L 661.29,109.05 A 13.93,13.93 0 0 1 685.97,109.06 Z"/>
<path fill-opacity="0.05" d="M 694.21,104.76 L 1268.04,1202.43 A 23.22,23.22 0 0 1 1247.46,1236.41 L 98.44,1236.54 A 23.22,23.22 0 0 1 77.87,1202.54 L 653.06,104.74 A 23.22,23.22 0 0 1 694.21,104.76 Z"/>
<path fill-opacity="0.0271" d="M 702.44,100.45 L 1276.27,1198.12 A 32.51,32.51 0 0 1 1247.46,1245.70 L 98.44,1245.83 A 32.51,32.51 0 0 1 69.64,1198.23 L 644.83,100.43 A 32.51,32.51 0 0 1 702.44,100.45 Z"/>
<path fill-opacity="0.0188" d="M 710.67,96.15 L 1284.50,1193.82 A 41.80,41.80 0 0 1 1247.46,1254.99 L 98.45,1255.12 A 41.80,41.80 0 0 1 61.41,1193.92 L 636.60,96.11 A 41.80,41.80 0 0 1 710.67,96.15 Z"/>
</g>
<path fill="url(#side)" d="m 682.32,145.79 0.06,684.52 414.02,107.56 z"/>
<path fill="#f7f7f7" d="M 682.32,145.79 267.27,937.97 682.38,830.31 Z"/>
<path fill="url(#bottom)" d="m 1096.4,937.87 -829.13,0.1 415.11,-107.66 z"/>
</g></svg>)svg";

static std::string aboutText()
{
  std::ostringstream sstream;
  sstream
    << "<body link=\"" << linkColor() << "\">"
    << "<h1 align=center>Gmsh</h1>"
    << "<center><font color=\"" << mutedColor() << "\">version "
    << GetGmshVersion() << "</font>"
    << "<p>Copyright (C) 1997-2026"
    << "<br>Christophe Geuzaine and Jean-Francois Remacle"
    << "<p><a href=\"https://gmsh.info\">gmsh.info</a> &nbsp;&middot;&nbsp; "
    << "<a href=\"https://gmsh.info/CREDITS.txt\">Credits</a> "
       "&nbsp;&middot;&nbsp; "
    << "<a href=\"https://gmsh.info/LICENSE.txt\">License</a> "
       "&nbsp;&middot;&nbsp; "
    << "<a href=\"https://gitlab.onelab.info/gmsh/gmsh/issues\">Issues</a>"
    << "</center><p>"
    << "<table>";
  std::vector<std::pair<std::string, std::string>> rows;
  rows.push_back(std::make_pair("Build OS", GetGmshBuildOS()));
  rows.push_back(std::make_pair("Build date", GetGmshBuildDate()));
  rows.push_back(std::make_pair("Build host", GetGmshBuildHost()));
  rows.push_back(
    std::make_pair("FLTK version", std::to_string(FL_MAJOR_VERSION) + "." +
                                     std::to_string(FL_MINOR_VERSION) + "." +
                                     std::to_string(FL_PATCH_VERSION)));
#if defined(HAVE_PETSC)
  rows.push_back(std::make_pair("PETSc version",
                                std::to_string(PETSC_VERSION_MAJOR) + "." +
                                  std::to_string(PETSC_VERSION_MINOR) + "." +
                                  std::to_string(PETSC_VERSION_SUBMINOR) +
#if defined(PETSC_USE_COMPLEX)
                                  " (complex arithmetic)"
#else
                                  " (real arithmetic)"
#endif
                                ));
#endif
#if defined(HAVE_OCC)
  rows.push_back(
    std::make_pair("OCC version", std::to_string(OCC_VERSION_MAJOR) + "." +
                                    std::to_string(OCC_VERSION_MINOR) + "." +
                                    std::to_string(OCC_VERSION_MAINTENANCE)));
#endif
#if defined(HAVE_MED)
  rows.push_back(
    std::make_pair("MED version", std::to_string(MED_NUM_MAJEUR) + "." +
                                    std::to_string(MED_NUM_MINEUR) + "." +
                                    std::to_string(MED_NUM_RELEASE)));
#endif
  rows.push_back(std::make_pair("Packaged by", GetGmshPackager()));
  rows.push_back(std::make_pair("Build options", GetGmshBuildOptions()));
  for(std::size_t i = 0; i < rows.size(); i++)
    sstream << "<tr><td><font color=\"" << mutedColor() << "\">"
            << ReplaceSubString(" ", "&nbsp;", rows[i].first)
            << "</font></td><td>" << rows[i].second << "</td></tr>";
  sstream << "</table>";
  return sstream.str();
}

// a table of two columns, its rows shaded alternately, filtered by the
// search box
static std::string
usageTable(const std::vector<std::pair<std::string, std::string>> &rows,
           const searchFilter &filter)
{
  std::string shade = hexColor(
    fl_color_average(FL_BACKGROUND2_COLOR, FL_FOREGROUND_COLOR, 0.94f));
  // 96%: a gap between the text and the scrollbar
  std::string s = "<table width=96%>";
  int n = 0;
  for(std::size_t i = 0; i < rows.size(); i++) {
    if(rows[i].first.empty()) continue;
    if(rows[i].second.empty()) { // a title in the list of switches
      s += "</table><p>" + rows[i].first + "<table width=96%>";
      n = 0;
      continue;
    }
    if(!filter.matches(rows[i].first) && !filter.matches(rows[i].second))
      continue;
    s += std::string("<tr") + (n++ % 2 ? "" : " bgcolor=\"" + shade + "\"") +
         "><td width=30%>" + rows[i].first + "</td><td>" + rows[i].second +
         "</td></tr>";
  }
  return s + "</table>";
}

static std::string usageText(const searchFilter &filter)
{
  std::string s = "<body link=\"" + linkColor() + "\">";
  s += "<h3>Keyboard shortcuts</h3>" + usageTable(GetShortcutsUsage(), filter);
  s += "<p><h3>Mouse actions</h3>" + usageTable(GetMouseUsage(), filter);
  s += "<p>With a two-button mouse, the middle button is Shift+Left; with a "
       "one-button mouse, the middle button is Shift+Left and the right "
       "button Alt+Left.";
  s += "<p><h3>Command line switches</h3>" + usageTable(GetUsage(), filter);
  return s;
}

static void help_usage_cb(Fl_Widget *w, void *data)
{
  helpWindow *help = FlGui::instance()->help;
  help->usageFilter.set(help->basicSearch);
  help->basicView->value(usageText(help->usageFilter).c_str());
}

void helpWindow::resetText()
{
  aboutView->value(aboutText().c_str());
  basicView->value(usageText(usageFilter).c_str());
}

helpWindow::helpWindow()
{
  {
    int width = 30 * FL_NORMAL_SIZE;
    int logo = 7 * FL_NORMAL_SIZE;
    int height = 21 * BH + logo + WB;

    about = new paletteWindow(width, height,
                              CTX::instance()->nonModalWindows ? true : false,
                              "About Gmsh");
    about->box(GMSH_WINDOW_BOX);
    // on the background of the lists, as the options and workspace, the
    // window showing on both sides of the text as a margin
    about->color(FL_BACKGROUND2_COLOR);

    Fl_Box *logoBox = new Fl_Box(0, 2 * WB, width, logo);
    Fl_SVG_Image *logoImage = new Fl_SVG_Image(nullptr, logoSvg);
    logoImage->resize(logo, logo);
    logoBox->image(logoImage);

    aboutView = new Fl_Help_View(WB, logo + 2 * WB, width - 2 * WB,
                                 height - logo - 2 * WB);
    aboutView->textfont(FL_HELVETICA);
    aboutView->textsize(FL_NORMAL_SIZE);
    aboutView->box(FL_FLAT_BOX);
    aboutView->color(FL_BACKGROUND2_COLOR);
    aboutView->link(help_link);
    about->end();
  }

  {
    int width = 40 * FL_NORMAL_SIZE;
    int height = 18 * BH;

    basic = new paletteWindow(width, height,
                              CTX::instance()->nonModalWindows ? true : false,
                              "Keyboard and Mouse Usage");
    basic->box(GMSH_WINDOW_BOX);
    basic->color(FL_BACKGROUND2_COLOR);

    basicSearch = searchBox(WB, WB, width - 2 * WB, BH, "Search usage",
                            "Show only the entries matching the regular\n"
                            "expression, whatever the case",
                            help_usage_cb);

    basicView =
      new Fl_Help_View(WB, BH + 2 * WB, width - 2 * WB, height - BH - 2 * WB);
    basicView->textfont(FL_HELVETICA);
    basicView->textsize(FL_NORMAL_SIZE - 1);
    basicView->box(FL_FLAT_BOX);
    basicView->color(FL_BACKGROUND2_COLOR);
    basic->resizable(basicView);
    basic->end();
  }

  resetText();

  {
    int width = 40 * FL_NORMAL_SIZE;
    int height = 18 * BH;

    options = new paletteWindow(width, height,
                                CTX::instance()->nonModalWindows ? true : false,
                                "Current Options and Workspace");
    options->box(GMSH_WINDOW_BOX);

    int BW = (width - 4 * WB) / 3;

    modified = new Fl_Check_Button(WB, WB, BW, BH, "Only show modified");
    modified->type(FL_TOGGLE_BUTTON);
    modified->callback(help_options_cb);
    modified->tooltip("Show only values different from defaults");

    showhelp = new Fl_Check_Button(2 * WB + BW, WB, BW, BH, "Show help");
    showhelp->type(FL_TOGGLE_BUTTON);
    showhelp->callback(help_options_cb);
    showhelp->tooltip("Show help strings");

    search =
      searchBox(3 * WB + 2 * BW, WB, BW, BH, "Search options and workspace",
                "Show only the options and variables matching the regular\n"
                "expression, whatever the case",
                help_options_cb);
    // search->take_focus(); cannot call this here - it triggers show() on Linux
    // in fltk 1.3.3

    browser = new Fl_Browser(0, BH + 2 * WB, width, height - 2 * BH - 4 * WB);
    browser->box(GMSH_SIMPLE_TOP_BOX);
#if defined(WIN32) // FL_SCREEN seems to be too tiny on most Windows setups
    browser->textfont(FL_COURIER);
#else
    browser->textfont(FL_SCREEN);
#endif
    browser->textsize(FL_NORMAL_SIZE - 2);
    browser->type(FL_MULTI_BROWSER);
    browser->callback(browser_cb);
    browser->tooltip("Double-click to edit value; selected lines are copied "
                     "to the clipboard");

    {
      Fl_Group *g = new Fl_Group(0, height - BH - WB, width, BH);
      Fl_Group *g2 = new Fl_Group(0, height - BH - WB, BB, BH);
      g->resizable(g2);
      g2->end();
      Fl_Return_Button *o = new Fl_Return_Button(
        width - BB - WB, height - BH - WB, BB, BH, "Update");
      o->callback(help_options_cb);
      g->end();
    }

    options->resizable(browser);
    options->size_range(width, height);
    options->end();
  }
}

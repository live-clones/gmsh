// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <FL/Fl_Help_View.H>
#include "FlGui.h"
#include "aboutWindow.h"
#include "paletteWindow.h"
#include "CommandLine.h"
#include "StringUtils.h"
#include "OS.h"
#include "Context.h"

static const char *help_link(Fl_Widget *w, const char *uri)
{
  std::string prog = FixWindowsPath(CTX::instance()->webBrowser);
  SystemCall(ReplaceSubString("%s", uri, prog));
  return 0;
}

aboutWindow::aboutWindow()
{
  int width = 26 * FL_NORMAL_SIZE;
  int height = 17 * BH;

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "About Gmsh");
  win->box(GMSH_WINDOW_BOX);

  Fl_Help_View *o = new Fl_Help_View(0, 0, width, height);
  o->textfont(FL_HELVETICA);
  o->textsize(FL_NORMAL_SIZE);
  o->box(FL_FLAT_BOX);
  std::ostringstream sstream;
  sstream << "<center><h3>Gmsh</h3><br>version " << GetGmshVersion()
          << "<p>Copyright (C) 1997-2011"
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

  win->position(Fl::x() + Fl::w()/2 - width / 2,
                Fl::y() + Fl::h()/2 - height / 2);
  win->end();
}

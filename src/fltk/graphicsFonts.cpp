// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Enumerations.H>
#include "graphicsFonts.h"

Fl_Menu_Item menu_font_names[] = {
  {"Times-Roman", 0, nullptr, (void *)FL_TIMES},
  {"Times-Bold", 0, nullptr, (void *)FL_TIMES_BOLD},
  {"Times-Italic", 0, nullptr, (void *)FL_TIMES_ITALIC},
  {"Times-BoldItalic", 0, nullptr, (void *)FL_TIMES_BOLD_ITALIC},
  {"Helvetica", 0, nullptr, (void *)FL_HELVETICA},
  {"Helvetica-Bold", 0, nullptr, (void *)FL_HELVETICA_BOLD},
  {"Helvetica-Oblique", 0, nullptr, (void *)FL_HELVETICA_ITALIC},
  {"Helvetica-BoldOblique", 0, nullptr, (void *)FL_HELVETICA_BOLD_ITALIC},
  {"Courier", 0, nullptr, (void *)FL_COURIER},
  {"Courier-Bold", 0, nullptr, (void *)FL_COURIER_BOLD},
  {"Courier-Oblique", 0, nullptr, (void *)FL_COURIER_ITALIC},
  {"Courier-BoldOblique", 0, nullptr, (void *)FL_COURIER_BOLD_ITALIC},
  {"Symbol", 0, nullptr, (void *)FL_SYMBOL},
  {"ZapfDingbats", 0, nullptr, (void *)FL_ZAPF_DINGBATS},
  {"Screen", 0, nullptr, (void *)FL_SCREEN},
  {nullptr}};

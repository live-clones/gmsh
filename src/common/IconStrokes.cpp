// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "IconStrokes.h"

const char *IconStrokes(const std::string &name)
{
  if(name == "sidebar")
    return "<rect x='3' y='4' width='18' height='16' rx='2'/>"
           "<path d='M9 4v16'/>";
  if(name == "models")
    return "<path d='M12 3 2 8l10 5 10-5z'/><path d='m2 12 10 5 10-5'/>"
           "<path d='m2 16 10 5 10-5'/>";
  if(name == "quick")
    return "<path d='M21 4h-7M10 4H3M21 12h-9M8 12H3M21 20h-5M12 20H3'/>"
           "<path d='M14 2v4M8 10v4M16 18v4'/>";
  if(name == "cube")
    return "<path d='M12 3l8 4.5v9L12 21l-8-4.5v-9z'/>"
           "<path d='m4 7.5 8 4.5 8-4.5M12 12v9'/>";
  if(name == "rotate")
    return "<path d='M21 12a9 9 0 1 1-3-6.7'/><path d='M21 3v6h-6'/>";
  // (a loop, as the repeat of a player: two arrows around a cycle)
  if(name == "loop")
    return "<path d='M17 2l4 4-4 4'/><path d='M3 11V9a3 3 0 0 1 3-3h15'/>"
           "<path d='M7 22l-4-4 4-4'/><path d='M21 13v2a3 3 0 0 1-3 3H3'/>";
  if(name == "query")
    return "<circle cx='12' cy='12' r='8'/>"
           "<path d='M22 12h-4M6 12H2M12 6V2M12 22v-4'/>";
  if(name == "measure")
    return "<path d='M3 15 15 3l6 6L9 21z'/>"
           "<path d='m7 11 2 2M10 8l2 2M13 5l2 2'/>";
  if(name == "rewind")
    return "<path d='M19 20 9 12l10-8z'/><path d='M5 19V5'/>";
  if(name == "back") return "<path d='m15 18-6-6 6-6'/>";
  if(name == "play") return "<path d='M6 3l14 9-14 9z'/>";
  if(name == "pause")
    return "<rect x='6' y='4' width='4' height='16' rx='1'/>"
           "<rect x='14' y='4' width='4' height='16' rx='1'/>";
  if(name == "forward") return "<path d='m9 18 6-6-6-6'/>";
  if(name == "gear")
    return "<circle cx='12' cy='12' r='3'/><circle cx='12' cy='12' r='7'/>"
           "<path d='M19 12h3M5 12H2M12 5V2M12 22v-3'/>"
           "<path d='m16.95 16.95 2.12 2.12M7.05 7.05 4.93 4.93'/>"
           "<path d='m16.95 7.05 2.12-2.12M7.05 16.95l-2.12 2.12'/>";
  if(name == "search")
    return "<circle cx='11' cy='11' r='7'/><path d='m21 21-4.3-4.3'/>";
  if(name == "graph")
    return "<path d='M3 3v18h18'/><path d='m7 15 4-5 3 3 6-7'/>";
  if(name == "eye")
    return "<path d='M2 12s3.5-7 10-7 10 7 10 7-3.5 7-10 7-10-7-10-7z'/>"
           "<circle cx='12' cy='12' r='3'/>";
  return "";
}

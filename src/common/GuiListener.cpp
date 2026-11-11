// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GuiListener.h"

static guiListener *_listener = nullptr;
static void (*_fontEngineMaker)(const std::string &) = nullptr;

guiListener *Gui()
{
  static guiListener none;
  return (_listener && _listener->running()) ? _listener : &none;
}

void SetGuiListener(guiListener *listener) { _listener = listener; }

void SetFontEngineMaker(void (*maker)(const std::string &))
{ _fontEngineMaker = maker; }

void MakeFontEngine(const std::string &engine)
{
  if(_fontEngineMaker) _fontEngineMaker(engine);
}

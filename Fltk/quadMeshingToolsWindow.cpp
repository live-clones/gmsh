// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "quadMeshingToolsWindow.h"
#include "gmshCrossFields.h"
#include "paletteWindow.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Context.h"
#include "Generator.h"

#if defined(HAVE_QUADMESHINGTOOLS)
#include "quad_meshing_tools.h"
#endif

static void qmt_crossfield_cb(Fl_Widget *w, void *data)
{
  // int status = computeCrossField(GModel::current());
  drawContext::global()->draw();
}

quadMeshingToolsWindow::quadMeshingToolsWindow(int deltaFontSize) {
  FL_NORMAL_SIZE -= deltaFontSize;
  int width = 3 * IW + 4 * WB;
  int height = 24 * BH;
  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Quad meshing tools");
  win->box(GMSH_WINDOW_BOX);

  /* Text information display */
  int y = WB;
  int x = 2 * WB;
  box = new Fl_Box(x, y, width - 4 * WB, BH);
  box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  y += BH;

  {
    y += BH / 2;
    Fl_Box *b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
    b->box(FL_ENGRAVED_FRAME);
    b->labeltype(FL_NO_LABEL);
  }

  { /* Cross field box */
    y += BH;
    Fl_Box *b =
      new Fl_Box(x - WB, y, width, BH, "1. Generation of cross-field");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    push[0] = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Generate");
    push[0]->callback(qmt_crossfield_cb);
  }

  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

void quadMeshingToolsWindow::show(bool redrawOnly) {
  if(win->shown() && redrawOnly)
    win->redraw();
  else {
    win->show();
  }
}

void quadmeshingtools_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char *)data;
  if(str && !strcmp(str, "redraw_only"))
    FlGui::instance()->quadmeshingtools->show(true);
  else
    FlGui::instance()->quadmeshingtools->show(false);
}

// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "messageWindow.h"
#include "shortcutWindow.h"
#include "Callbacks.h"
#include "GmshMessage.h"
#include "Context.h"

extern Context_T CTX;

messageWindow::messageWindow(int fontsize)
  : _fontsize(fontsize)
{
  int width = CTX.msg_size[0];
  int height = CTX.msg_size[1];

  win = new dialogWindow
    (width, height, CTX.non_modal_windows, "Message Console");
  win->box(GMSH_WINDOW_BOX);

  browser = new Fl_Browser(0, 0, width, height - 2 * WB - BH);
  browser->box(FL_FLAT_BOX);
  browser->textfont(FL_COURIER);
  browser->textsize(_fontsize - 1);
  browser->type(FL_MULTI_BROWSER);
  browser->callback(message_copy_cb);

  {
    butt = new Fl_Check_Button
      (width - 4 * BB - 4 * WB, height - BH - WB, BB, BH, "Auto scroll");
    butt->type(FL_TOGGLE_BUTTON);
    butt->callback(message_auto_scroll_cb);
  }
  {
    Fl_Return_Button *o = new Fl_Return_Button
      (width - 3 * BB - 3 * WB, height - BH - WB, BB, BH, "Clear");
    o->callback(message_clear_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Save");
    o->callback(message_save_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void *)win);
  }

  win->resizable(new Fl_Box(1, 1, 4, 4));
  win->size_range(WB + 100 + 3 * BB + 4 * WB, 100);

  win->position(CTX.msg_position[0], CTX.msg_position[1]);
  win->end();
}

void messageWindow::add(const char *msg)
{
  browser->add(msg, 0);
  if(CTX.msg_auto_scroll)
    browser->bottomline(browser->size());
}

void messageWindow::save(const char *filename)
{
  FILE *fp = fopen(filename, "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", filename);
    return;
  }

  Msg::StatusBar(2, true, "Writing '%s'", filename);
  for(int i = 1; i <= browser->size(); i++) {
    const char *c = browser->text(i);
    if(c[0] == '@')
      fprintf(fp, "%s\n", &c[5]);
    else
      fprintf(fp, "%s\n", c);
  }
  Msg::StatusBar(2, true, "Wrote '%s'", filename);
  fclose(fp);
}

void messageWindow::show(bool redrawOnly)
{
  if(win->shown() && redrawOnly)
    win->redraw();
  else
    win->show();
}

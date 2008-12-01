// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "visibilityWindow.h"
#include "shortcutWindow.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

// derive our own browser, that reacts differently to the Enter key
class visBrowser : public Fl_Browser{
  int handle(int event)
  {
    if(event == FL_KEYBOARD){
      switch(Fl::event_key()) {
      case FL_Enter:
      case FL_KP_Enter:
        visibility_ok_cb(NULL, NULL);
        return 1;
      }
    }
    return Fl_Browser::handle(event);
  }
 public:
  visBrowser(int x, int y, int w , int h, const char* c = 0)
    : Fl_Browser(x, y, w, h, c){}
};

visibilityWindow::visibilityWindow(int fontsize) 
  : _fontsize(fontsize)
{
  static int cols[5] = {15, 95, 95, 180, 0};
  static Fl_Menu_Item type_table[] = {
    {"Elementary entities", 0, (Fl_Callback *) visibility_cb},
    {"Physical groups", 0, (Fl_Callback *) visibility_cb},
    {"Mesh partitions", 0, (Fl_Callback *) visibility_cb},
    {0}
  };

  int width = cols[0] + cols[1] + cols[2] + cols[3] + 6 * WB;
  int height = 18 * BH;
  int brw = width - 4 * WB;

  win = new dialogWindow
    (width, height, CTX.non_modal_windows, "Visibility");
  win->box(GMSH_WINDOW_BOX);

  type = new Fl_Choice(WB, WB, (width - 3 * WB) / 2, BH);
  type->menu(type_table);
  
  butt[0] = new Fl_Check_Button
    (WB + (width - 3 * WB) / 2 + WB, WB, (width - 3 * WB) / 2, BH, 
     "Set visibility recursively");
  butt[0]->type(FL_TOGGLE_BUTTON);
  butt[0]->value(1);

  Fl_Tabs *o = new Fl_Tabs
    (WB, 2 * WB + BH, width - 2 * WB, height - 4 * WB - 2 * BH);
  {
    group[0] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 3 * BH, "Browser");

    Fl_Button *o0 = new Fl_Button
      (2 * WB, 3 * WB + 2 * BH, cols[0], BH/2, "*");
    o0->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);
    o0->tooltip("Select/unselect all");
    o0->callback(visibility_sort_cb, (void *)"*");

    Fl_Button *o1 = new Fl_Button
      (2 * WB, 3 * WB + 2 * BH + BH/2, cols[0], BH - BH/2, "-");
    o1->tooltip("Invert selection");
    o1->callback(visibility_sort_cb, (void *)"-");

    Fl_Button *o2 = new Fl_Button
      (2 * WB + cols[0], 3 * WB + 2 * BH, cols[1], BH, "Type");
    o2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o2->tooltip("Sort by type");
    o2->callback(visibility_sort_cb, (void *)"type");

    Fl_Button *o3 = new Fl_Button
      (2 * WB + cols[0] + cols[1], 3 * WB + 2 * BH, cols[2], BH, "Number");
    o3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o3->tooltip("Sort by number");
    o3->callback(visibility_sort_cb, (void *)"number");

    Fl_Button *o4 = new Fl_Button
      (2 * WB + cols[0] + cols[1] + cols[2], 3 * WB + 2 * BH, cols[3], BH, "Name");
    o4->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o4->tooltip("Sort by name");
    o4->callback(visibility_sort_cb, (void *)"name");

    Fl_Button *o5 = new Fl_Button
      (width - 4 * WB, 3 * WB + 2 * BH, 2 * WB, BH, "+");
    o5->tooltip("Add parameter name for first selected item");
    o5->callback(visibility_sort_cb, (void *)"+");

    {
      Fl_Group *o = new Fl_Group
        (2 * WB, 3 * WB + 3 * BH, brw, height - 7 * WB - 5 * BH);
      
      browser = new visBrowser
        (2 * WB, 3 * WB + 3 * BH, brw, height - 7 * WB - 5 * BH);
      browser->type(FL_MULTI_BROWSER);
      browser->column_widths(cols);
      
      o->end();
      Fl_Group::current()->resizable(o);
    }

    push[0] = new Fl_Button
      (width - 2 * BB - 3 * WB, height - 2 * BH - 3 * WB, BB, BH, "Delete");
    push[0]->callback(visibility_delete_cb);

    Fl_Return_Button *b1 = new Fl_Return_Button
      (width - 1 * BB - 2 * WB, height - 2 * BH - 3 * WB, BB, BH, "Apply");
    b1->callback(visibility_ok_cb);

    group[0]->end();
    Fl_Group::current()->resizable(group[0]);
  }
  {
    group[1] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 2 * BH, "Numeric input");
    group[1]->resizable(NULL);

    for(int i = 0; i < 6; i++){
      input[i] = new Fl_Input
        (width / 2 - WB / 2 - IW, 3 * WB + (i + 2) * BH, IW, BH);
      input[i]->align(FL_ALIGN_LEFT);
      input[i]->value("*");

      Fl_Button *o1 = new Fl_Button
        (width / 2 + WB / 2, 3 * WB + (i + 2) * BH, BB, BH, "Show");
      o1->callback(visibility_number_cb, (void *)(100+i));

      Fl_Button *o2 = new Fl_Button
        (width / 2 + WB / 2 + BB + WB, 3 * WB + (i + 2) * BH, BB, BH, "Hide");
      o2->callback(visibility_number_cb, (void *)i);
    }

    input[0]->label("Node");
    input[0]->tooltip("Enter node number, or *");

    input[1]->label("Element");
    input[1]->tooltip("Enter element number, or *");

    input[2]->label("Point");
    input[2]->tooltip("Enter point number, or *");

    input[3]->label("Line");
    input[3]->tooltip("Enter line number, or *");

    input[4]->label("Surface");
    input[4]->tooltip("Enter surface number, or *");

    input[5]->label("Volume");
    input[5]->tooltip("Enter volume number, or *");

    group[1]->end();
  }
  {
    group[2] = new Fl_Group
      (WB, 2 * WB + 2 * BH, width - 2 * WB, height - 4 * WB - 2 * BH, "Interactive");
    group[2]->resizable(NULL);

    int ll = width/2 - BH - WB - IW;

    Fl_Box *b2 = new Fl_Box
      (FL_NO_BOX, ll, 3 * WB + 2 * BH, IW, BH, "Hide with the mouse:");
    b2->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);

    Fl_Button *butt1 = new Fl_Button(ll, 3 * WB + 3 * BH, IW, BH, "Elements");
    butt1->callback(visibility_interactive_cb, (void *)"hide_elements");
    Fl_Button *butt2 = new Fl_Button(ll, 3 * WB + 4 * BH, IW, BH, "Points");
    butt2->callback(visibility_interactive_cb, (void *)"hide_points");
    Fl_Button *butt3 = new Fl_Button(ll, 3 * WB + 5 * BH, IW, BH, "Lines");
    butt3->callback(visibility_interactive_cb, (void *)"hide_lines");
    Fl_Button *butt4 = new Fl_Button(ll, 3 * WB + 6 * BH, IW, BH, "Surfaces");
    butt4->callback(visibility_interactive_cb, (void *)"hide_surfaces");
    Fl_Button *butt5 = new Fl_Button(ll, 3 * WB + 7 * BH, IW, BH, "Volumes");
    butt5->callback(visibility_interactive_cb, (void *)"hide_volumes");

    Fl_Button *butt6 = new Fl_Button
      (ll + IW + WB, 3 * WB + 3 * BH, 2 * BH, 5*BH, "Show\nAll");
    butt6->callback(visibility_interactive_cb, (void *)"show_all");

    int ll2 = ll + IW + WB + 2*BH + WB;

    Fl_Box *b12 = new Fl_Box
      (FL_NO_BOX, ll2, 3 * WB + 2 * BH, IW, BH, "Show with the mouse:");
    b12->align(FL_ALIGN_INSIDE|FL_ALIGN_CENTER);

    Fl_Button *butt11 = new Fl_Button(ll2, 3 * WB + 3 * BH, IW, BH, "Elements");
    butt11->callback(visibility_interactive_cb, (void *)"show_elements");
    Fl_Button *butt12 = new Fl_Button(ll2, 3 * WB + 4 * BH, IW, BH, "Points");
    butt12->callback(visibility_interactive_cb, (void *)"show_points");
    Fl_Button *butt13 = new Fl_Button(ll2, 3 * WB + 5 * BH, IW, BH, "Lines");
    butt13->callback(visibility_interactive_cb, (void *)"show_lines");
    Fl_Button *butt14 = new Fl_Button(ll2, 3 * WB + 6 * BH, IW, BH, "Surfaces");
    butt14->callback(visibility_interactive_cb, (void *)"show_surfaces");
    Fl_Button *butt15 = new Fl_Button(ll2, 3 * WB + 7 * BH, IW, BH, "Volumes");
    butt15->callback(visibility_interactive_cb, (void *)"show_volumes");
    
    group[2]->end();
  }
  o->end();

  win->resizable(o);
  win->size_range(width, 9 * BH + 6 * WB, width);

  {
    Fl_Button *o1 = new Fl_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Save");
    o1->callback(visibility_save_cb);

    Fl_Button *o2 = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o2->callback(cancel_cb, (void *)win);
  }

  win->position(CTX.vis_position[0], CTX.vis_position[1]);
  win->end();
}

void visibilityWindow::show(bool redrawOnly)
{
  if(win->shown() && redrawOnly)
    win->redraw();
  else
    win->show();
}


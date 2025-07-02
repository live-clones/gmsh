// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <string.h>
#include <FL/Fl.H>
#include <algorithm>
#include "FlGui.h"
#include "paletteWindow.h"
#include "optionWindow.h"
#include "GamePad.h"
#include "gamepadWindow.h"
#include "Context.h"

// handler (listen to gamepad or other names pipes
static void gamepadWindow_handler(void *data)
{
  if(CTX::instance()->gamepad && CTX::instance()->gamepad->active) {
    gamepadWindow *gmpd_win = (gamepadWindow *)data;
    GamePad *pad = CTX::instance()->gamepad;
    for(int i = 0; i < std::min(13, GP_BUTTONS); i++)
      gmpd_win->gamepad.butt[i]->value(pad->button[i]);
    for(int i = 0; i < std::min(9, GP_AXES); i++)
      gmpd_win->gamepad.axe[i]->value(pad->axe[i]);
    Fl::add_timeout(gmpd_win->frequency, gamepadWindow_handler, data);
    gmpd_win->gamepad.mapping[16]->value(pad->axe_map[1]);
  }
}

static void gamepad_update_cb(Fl_Widget *w)
{
  gamepadWindow *gmpd_win = FlGui::instance()->options->gmpdoption;
  GamePad *pad = CTX::instance()->gamepad;
  for(int i = 0; i < std::min(8, GP_BUTTONS); i++)
    pad->button_map[i] = gmpd_win->gamepad.mapping[i]->value();
  for(int i = 0; i < std::min(7, GP_AXES); i++)
    pad->axe_map[i] = gmpd_win->gamepad.mapping[10 + i]->value();
}

gamepadWindow::gamepadWindow()
{
  if(!CTX::instance()->gamepad) return;

  frequency = CTX::instance()->gamepad->frequency;

  //  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 34 * FL_NORMAL_SIZE + WB;
  int height = 15 * BH + 4 * WB;
  int L = FL_NORMAL_SIZE;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false);
  win->box(GMSH_WINDOW_BOX);
  win->label("Gamepad Configuration Tool (in work)");

  Fl_Box *bt =
    new Fl_Box(FL_NO_BOX, L, L - .3 * BH, IW, BH, "Gamepad buttons:");
  bt->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

  gamepad.butt[0] = new Fl_Check_Button(L, L + BH, BH, WB, "0");
  gamepad.butt[1] = new Fl_Check_Button(L + 1 * BB * .35, L + BH, BH, WB, "1");
  gamepad.butt[2] = new Fl_Check_Button(L + 2 * BB * .35, L + BH, BH, WB, "2");
  gamepad.butt[3] = new Fl_Check_Button(L + 3 * BB * .35, L + BH, BH, WB, "3");
  gamepad.butt[4] = new Fl_Check_Button(L + 4 * BB * .35, L + BH, BH, WB, "4");
  gamepad.butt[5] = new Fl_Check_Button(L + 5 * BB * .35, L + BH, BH, WB, "5");
  gamepad.butt[6] = new Fl_Check_Button(L + 6 * BB * .35, L + BH, BH, WB, "6");
  gamepad.butt[7] = new Fl_Check_Button(L + 7 * BB * .35, L + BH, BH, WB, "7");
  gamepad.butt[8] = new Fl_Check_Button(L + 8 * BB * .35, L + BH, BH, WB, "8");
  gamepad.butt[9] = new Fl_Check_Button(L + 9 * BB * .35, L + BH, BH, WB, "9");
  gamepad.butt[10] =
    new Fl_Check_Button(L + 10 * BB * .35, L + BH, BH, WB, "10");
  gamepad.butt[11] =
    new Fl_Check_Button(L + 11 * BB * .35, L + BH, BH, WB, "11");
  gamepad.butt[12] =
    new Fl_Check_Button(L + 12 * BB * .35, L + BH, BH, WB, "12");
  for(int i = 0; i < 13; i++) gamepad.butt[i]->deactivate();

  Fl_Box *bta = new Fl_Box(FL_NO_BOX, L, L + 1.7 * BH, IW, BH, "Gamepad axes:");
  bta->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

  gamepad.axe[0] = new Fl_Check_Button(L, L + 3. * BH, BH, WB, "0");
  gamepad.axe[1] =
    new Fl_Check_Button(L + 1 * BB * .4, L + 3. * BH, BH, WB, "1");
  gamepad.axe[2] =
    new Fl_Check_Button(L + 2 * BB * .4, L + 3. * BH, BH, WB, "2");
  gamepad.axe[3] =
    new Fl_Check_Button(L + 3 * BB * .4, L + 3. * BH, BH, WB, "3");
  gamepad.axe[4] =
    new Fl_Check_Button(L + 4 * BB * .4, L + 3. * BH, BH, WB, "4");
  gamepad.axe[5] =
    new Fl_Check_Button(L + 5 * BB * .4, L + 3. * BH, BH, WB, "5");
  gamepad.axe[6] =
    new Fl_Check_Button(L + 6 * BB * .4, L + 3. * BH, BH, WB, "6");
  gamepad.axe[7] =
    new Fl_Check_Button(L + 7 * BB * .4, L + 3. * BH, BH, WB, "7");
  gamepad.axe[8] =
    new Fl_Check_Button(L + 8 * BB * .4, L + 3. * BH, BH, WB, "8");
  for(int i = 0; i < 9; i++) gamepad.axe[i]->deactivate();

  Fl_Box *btt1 = new Fl_Box(FL_NO_BOX, L, L + 3.7 * BH, IW, BH, "Preferences:");
  btt1->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
  Fl_Box *btt2 = new Fl_Box(FL_NO_BOX, L, L + 4.7 * BH, IW, BH, "Action Axes:");
  btt2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
  Fl_Box *btt3 = new Fl_Box(FL_NO_BOX, L + width / 2 + BH / 2, L + 4.7 * BH, IW,
                            BH, "Action buttons:");
  btt3->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

  GamePad *pad = CTX::instance()->gamepad;

  gamepad.mapping[0] =
    new Fl_Value_Input(L + width / 2 + BH / 2, L + 5.7 * BH, IW / 5, BH, "1:1");
  gamepad.mapping[1] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 6.7 * BH,
                                          IW / 5, BH, "permute axes");
  gamepad.mapping[2] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 7.7 * BH,
                                          IW / 5, BH, "reset/invers up axis");
  gamepad.mapping[3] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 8.7 * BH,
                                          IW / 5, BH, "change nav-mode");
  gamepad.mapping[4] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 9.7 * BH,
                                          IW / 5, BH, "(*) move head");
  gamepad.mapping[5] =
    new Fl_Value_Input(L + width / 2 + BH / 2, L + 10.7 * BH, IW / 5, BH, " ");
  gamepad.mapping[6] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 11.7 * BH,
                                          IW / 5, BH, "walk / swimm");
  gamepad.mapping[7] =
    new Fl_Value_Input(L + width / 2 + BH / 2, L + 12.7 * BH, IW / 5, BH, " ");
  gamepad.mapping[8] = new Fl_Value_Input(L + width / 2 + BH / 2, L + 13.7 * BH,
                                          IW / 5, BH, "1:1 ; reset speed");

  for(int i = 0; i < 9; i++) {
    gamepad.mapping[i]->align(FL_ALIGN_RIGHT);
    gamepad.mapping[i]->callback(gamepad_update_cb);
    gamepad.mapping[i]->value(pad->button_map[i]);
  }

  gamepad.mapping[10] = new Fl_Value_Input(L, L + 5.7 * BH, IW / 5, BH,
                                           "head right/left with button (*)");
  gamepad.mapping[11] = new Fl_Value_Input(L, L + 6.7 * BH, IW / 5, BH,
                                           "head up/down with button (*)");
  gamepad.mapping[12] =
    new Fl_Value_Input(L, L + 7.7 * BH, IW / 5, BH, "turn left/right");
  gamepad.mapping[13] =
    new Fl_Value_Input(L, L + 8.7 * BH, IW / 5, BH, "for/backward or up/down ");
  gamepad.mapping[14] =
    new Fl_Value_Input(L, L + 9.7 * BH, IW / 5, BH, "move aside left/right");
  gamepad.mapping[15] =
    new Fl_Value_Input(L, L + 10.7 * BH, IW / 5, BH, "move up/down");
  gamepad.mapping[16] =
    new Fl_Value_Input(L, L + 11.7 * BH, IW / 5, BH, "speed up/slow down");

  for(int i = 0; i < 7; i++) {
    gamepad.mapping[10 + i]->align(FL_ALIGN_RIGHT);
    gamepad.mapping[10 + i]->callback(gamepad_update_cb);
    gamepad.mapping[10 + i]->value(pad->axe_map[i]);
  }

  // add external reader for gamepad events
  if(CTX::instance()->gamepad && CTX::instance()->gamepad->active) {
    Fl::add_timeout(frequency, gamepadWindow_handler, (void *)this);
  }

  win->position(CTX::instance()->optPosition[0],
                CTX::instance()->optPosition[1]);
  win->end();
}

// $Id: XCursor.cpp,v 1.3 2001-01-08 08:03:41 geuzaine Exp $

#include <X11/cursorfont.h>

#include "xcontext.h"

extern XContext_T XCTX ;

#define MAIN_CURSOR     0 
#define DIAL_CURSOR     1
#define DIAL_CW_CURSOR  2
#define DIAL_CCW_CURSOR 3
#define DIAL_RES_CURSOR 4
#define QUESTION_CURSOR 5
#define DOWN_CURSOR     6
#define UP_CURSOR       7
#define UP_DOWN_CURSOR  8
#define CLOCK_CURSOR    9
#define PENCIL_CURSOR  10
#define ARROW_HAND_CURSOR  11

static Cursor CursorTable[32];

void SetCursor(Window window, int cursor){
  static int init = 0;

  if (!init) {
    init = 1;
    CursorTable[MAIN_CURSOR]      = XCreateFontCursor(XCTX.display,XC_top_left_arrow);
    CursorTable[DIAL_CURSOR]      = XCreateFontCursor(XCTX.display,XC_draft_small);
    CursorTable[DIAL_CW_CURSOR]   = XCreateFontCursor(XCTX.display,XC_exchange);
    CursorTable[DIAL_CCW_CURSOR]  = XCreateFontCursor(XCTX.display,XC_exchange);
    CursorTable[DIAL_RES_CURSOR]  = XCreateFontCursor(XCTX.display,XC_circle);
    CursorTable[QUESTION_CURSOR]  = XCreateFontCursor(XCTX.display,XC_question_arrow);
    CursorTable[DOWN_CURSOR]      = XCreateFontCursor(XCTX.display,XC_sb_down_arrow);
    CursorTable[UP_CURSOR]        = XCreateFontCursor(XCTX.display,XC_sb_up_arrow);
    CursorTable[UP_DOWN_CURSOR]   = XCreateFontCursor(XCTX.display,XC_sb_v_double_arrow);
    CursorTable[CLOCK_CURSOR]     = XCreateFontCursor(XCTX.display,XC_watch);
    CursorTable[PENCIL_CURSOR]    = XCreateFontCursor(XCTX.display,XC_pencil);
    CursorTable[ARROW_HAND_CURSOR]= XCreateFontCursor(XCTX.display,XC_draft_large);
  }
  
  XDefineCursor(XCTX.display, window, CursorTable[cursor]);
}


// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TREE_ICONS_H
#define TREE_ICONS_H

#include <FL/Fl_Pixmap.H>

#define TREE_ICON_RIGHT(col)                                                   \
  "11 11 2 1", ". c None", col, "...@.......", "...@@......", "...@@@.....",   \
    "...@@@@....", "...@@@@@...", "...@@@@@@..", "...@@@@@...", "...@@@@....", \
    "...@@@.....", "...@@......", "...@......."

#define TREE_ICON_DOWN(col)                                                    \
  "11 11 2 1", ".  c None", col, "...........", "...........", "...........",  \
    "@@@@@@@@@@@", ".@@@@@@@@@.", "..@@@@@@@..", "...@@@@@...", "....@@@....", \
    ".....@.....", "...........", "..........."

#define TREE_ICON_PLUS(col)                                                    \
  "11 11 3 1", col, "# c #323232", "@ c #000000", "###########",               \
    "#.........#", "#.........#", "#....@....#", "#....@....#", "#..@@@@@..#", \
    "#....@....#", "#....@....#", "#.........#", "#.........#", "###########"

#define TREE_ICON_MINUS(col)                                                   \
  "11 11 3 1", col, "#	c #323232", "@	c #000000", "###########",             \
    "#.........#", "#.........#", "#.........#", "#.........#", "#..@@@@@..#", \
    "#.........#", "#.........#", "#.........#", "#.........#", "###########"

#if defined(__APPLE__)
static const char *const open_xpm_light[] = {TREE_ICON_RIGHT("@ c #444444")};
static const char *const close_xpm_light[] = {TREE_ICON_DOWN("@ c #444444")};
static const char *const open_xpm_dark[] = {TREE_ICON_RIGHT("@ c #222222")};
static const char *const close_xpm_dark[] = {TREE_ICON_DOWN("@ c #222222")};
#else
static const char *const open_xpm_light[] = {TREE_ICON_PLUS(". c #fefefe")};
static const char *const close_xpm_light[] = {TREE_ICON_MINUS(". c #fefefe")};
static const char *const open_xpm_dark[] = {TREE_ICON_PLUS(". c #bbbbbb")};
static const char *const close_xpm_dark[] = {TREE_ICON_MINUS(". c #bbbbbb")};
#endif

static Fl_Pixmap open_pixmap_light(open_xpm_light);
static Fl_Pixmap close_pixmap_light(close_xpm_light);
static Fl_Pixmap open_pixmap_dark(open_xpm_dark);
static Fl_Pixmap close_pixmap_dark(close_xpm_dark);

#endif

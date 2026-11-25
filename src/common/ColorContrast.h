// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef COLOR_CONTRAST_H
#define COLOR_CONTRAST_H

// Colours made readable, the same in the graphical interface and in the web
// page, which draw them with their own toolkits. Colours are 0xrrggbb, but
// for NotePaperColor(), which takes and gives them packed as CTX colours.

// the relative luminance of a colour, and the contrast of two colours, from 1
// to 21 (WCAG 2)
double ColorLuminance(unsigned int rgb);
double ColorContrast(unsigned int a, unsigned int b);

// black or white, whichever reads better on a colour
unsigned int ContrastingColor(unsigned int rgb);

// a colour chosen by the user, e.g. the highlight of a ONELAB parameter, often
// that of entities in the model, as the background of a field: the colour
// itself, no brighter than the text fg in dark mode
unsigned int ReadableFillColor(unsigned int rgb, unsigned int fg, bool dark);

// the same colour as a text: as is in light mode, light in dark mode, in both
// cases moved further from the background, of the same hue, until it reads on
// the backgrounds bg1 and bg2 (a contrast of 4.5, WCAG AA)
unsigned int ReadableTextColor(unsigned int rgb, unsigned int bg1,
                               unsigned int bg2, bool dark);

// the paper of a note pinned on the scene: the colour of the mark it hangs
// from (General.Color.Query), lightened over a light background and darkened
// over a dark one; colours packed as CTX::packColor(), and whether the
// background is dark
unsigned int NotePaperColor(unsigned int mark, unsigned int bg, bool *dark);

#endif

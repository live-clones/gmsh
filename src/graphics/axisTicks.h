// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef AXIS_TICKS_H
#define AXIS_TICKS_H

#include <string>
#include <vector>

// Where an axis is labelled, and with what: the value, where it falls along
// the axis (0 at the start, 1 at the end) and the text.
struct axisTick {
  double v, t;
  std::string label;
};

// The power of ten the labels of a range are worth writing over (0 for
// none), and how it is written: with a multiplication sign and superscript
// digits on screen, as TeX in a TeX picture, in plain ASCII in the other
// vector pictures, whose fonts have neither.
int axisSharedExponent(double min, double max);
std::string axisMultiplier(int exp);

// v divided by 10^exp with that many decimals, and how many decimals three
// significant digits of it call for
std::string axisNumber(double v, int decimals, int exp);
int axisDecimals(double v, int exp);

// keep every k-th of these labels, the last one always, k the smallest that
// lets them fit along an axis of the given length in pixels
void axisThinTicks(std::vector<axisTick> &ticks, double length, double fontH,
                   bool horizontal);

// The labels of a linear axis spanning [min, max] over `length' pixels, the
// text `fontH' pixels high and written side by side when `horizontal'. With
// no format, the values are round numbers of a step of 1, 2 or 5 times a
// power of ten, as fine as the labels allow, and the ends of the range are
// added; `divisions', when positive, says about how many labels are wanted.
// Otherwise they are `divisions' equal steps printed with that format, as
// many as fit. `multiplier' comes back with the power of ten they share.
// `labelEnds' asks for the ends of the range themselves to be labelled,
// which a colour scale wants and a graph, whose frame shows where the axis
// stops, does not.
void makeAxisTicks(double min, double max, double length, double fontH,
                   bool horizontal, const std::string &format, int divisions,
                   bool labelEnds, std::vector<axisTick> &ticks,
                   std::string &multiplier);

#endif

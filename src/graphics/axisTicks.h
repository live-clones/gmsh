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
  // a subdivision of a logarithmic axis: a shorter mark, and no number
  bool minor = false;
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

// v as a number on a logarithmic axis: three significant digits times a
// power of ten, written the way the multiplier is, or plainly while that
// stays short (1000 rather than 10^3, 0.002 rather than 2x10^-3) unless
// `powers'. Whether a range is worth writing that way is decided once for
// all of its labels: 10^-4 next to 0.01 reads as two different scales.
std::string axisLogNumber(double v, bool powers = false);
bool axisLogPowers(double min, double max);

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
// `labelEnds' asks for the ends of the range themselves to be labelled, as
// the round values alone never say what the range is.
void makeAxisTicks(double min, double max, double length, double fontH,
                   bool horizontal, const std::string &format, int divisions,
                   bool labelEnds, std::vector<axisTick> &ticks,
                   std::string &multiplier);

// The labels of a logarithmic axis spanning [min, max], both positive, laid
// out by their logarithm. With no format, they are the decades of the range,
// or every second, fifth... one of them when that many labels do not fit,
// with the 1-2-5 or the nine subdivisions of a decade when the range is
// short enough to tell them apart; the next finer division is marked without
// a number. A range too short for a power of ten to fall in it is labelled
// like a linear one, which is what it looks like. The other arguments are
// those of makeAxisTicks(), and `multiplier' comes back empty unless the
// labels are linear ones.
void makeLogAxisTicks(double min, double max, double length, double fontH,
                      bool horizontal, const std::string &format,
                      int divisions, bool labelEnds,
                      std::vector<axisTick> &ticks, std::string &multiplier);

#endif

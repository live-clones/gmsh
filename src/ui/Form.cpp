// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>

#include "Form.h"

namespace Ui {

  double Field::getNumber() const { return readNumber ? readNumber() : 0.; }
  void Field::setNumber(double v)
  {
    if(writeNumber) writeNumber(v);
  }
  std::string Field::getText() const { return readText ? readText() : ""; }
  void Field::setText(const std::string &v)
  {
    if(writeText) writeText(v);
  }
  bool Field::getFlag() const { return getNumber() != 0.; }
  void Field::setFlag(bool v) { setNumber(v ? 1. : 0.); }
  Colour Field::getColour() const { return readColour ? readColour() : Colour(); }
  void Field::setColour(Colour v)
  {
    if(writeColour) writeColour(v);
  }
  void Field::getVector(double &x, double &y, double &z) const
  {
    x = y = z = 0.;
    if(readVector) readVector(x, y, z);
  }
  void Field::setVector(double x, double y, double z)
  {
    if(writeVector) writeVector(x, y, z);
  }

  // --- raising and lowering one of the numbers a colour map is computed from

  void ColourMap::adjust(const Parameter &p, bool up) const
  {
    if(!parameter || !setParameter) return;
    double v = parameter(p.name);
    if(p.toggle) {
      setParameter(p.name, v != 0. ? 0. : 1.);
      return;
    }
    v += up ? p.step : -p.step;
    if(p.most > p.least) {
      if(p.wraps) {
        // past an end it comes back by a period, once
        if(v > p.most) v -= p.period;
        if(v < p.least) v += p.period;
      }
      else {
        if(v > p.most) v = p.most;
        if(v < p.least) v = p.least;
      }
    }
    setParameter(p.name, v);
  }

  // --- hue, saturation and value
  //
  // The hexcone, the hue running over six sectors; all three from 0 to 255.

  void toHsv(const Colour &c, int &h, int &s, int &v)
  {
    double r = c.r / 255., g = c.g / 255., b = c.b / 255.;
    double most = std::max(r, std::max(g, b));
    double least = std::min(r, std::min(g, b));
    double range = most - least;
    double hue = 0.;
    if(range > 0.) {
      if(most == r)
        hue = (g - b) / range;
      else if(most == g)
        hue = 2. + (b - r) / range;
      else
        hue = 4. + (r - g) / range;
      if(hue < 0.) hue += 6.;
    }
    h = (int)(hue / 6. * 255.);
    s = (int)((most > 0. ? range / most : 0.) * 255.);
    v = (int)(most * 255.);
  }

  Colour fromHsv(int h, int s, int v, unsigned char alpha)
  {
    double hue = 6. * h / 255., sat = s / 255., val = v / 255.;
    double r = val, g = val, b = val;
    if(sat > 0.) {
      if(hue >= 6.) hue = 0.;
      int sector = (int)hue;
      double f = hue - sector;
      double p = val * (1. - sat);
      double q = val * (1. - sat * f);
      double t = val * (1. - sat * (1. - f));
      switch(sector) {
      case 0: r = val; g = t; b = p; break;
      case 1: r = q; g = val; b = p; break;
      case 2: r = p; g = val; b = t; break;
      case 3: r = p; g = q; b = val; break;
      case 4: r = t; g = p; b = val; break;
      default: r = val; g = p; b = q; break;
      }
    }
    return Colour((unsigned char)(r * 255. + .5), (unsigned char)(g * 255. + .5),
                  (unsigned char)(b * 255. + .5), alpha);
  }


} // namespace Ui

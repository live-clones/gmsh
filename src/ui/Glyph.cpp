// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The pictures FLTK drew as symbols in the released Gmsh, point for point.

#include <cmath>

#include "Glyph.h"

namespace Ui {

  namespace {

    const double _pi = 3.14159265358979323846;

    Stroke _stroke(Stroke::Kind kind, std::vector<double> points,
                   double width = 1.)
    {
      Stroke s;
      s.kind = kind;
      s.points = points;
      s.width = width;
      return s;
    }

    // an arc of the circle about x, y, from start to end in degrees,
    // counterclockwise on the screen from three o'clock, as FLTK's fl_arc()
    std::vector<double> _arc(double x, double y, double r, double start,
                             double end)
    {
      std::vector<double> points;
      int n = (int)std::ceil(std::fabs(end - start) / 15.);
      if(n < 2) n = 2;
      for(int i = 0; i <= n; i++) {
        double a = (start + (end - start) * i / n) * _pi / 180.;
        points.push_back(x + r * std::cos(a));
        points.push_back(y - r * std::sin(a));
      }
      return points;
    }

    // turned by degrees about the middle, as fl_rotate() does
    std::vector<double> _turned(const std::vector<double> &p, double degrees)
    {
      double a = degrees * _pi / 180., c = std::cos(a), s = std::sin(a);
      std::vector<double> q(p.size());
      for(std::size_t i = 0; i + 1 < p.size(); i += 2) {
        q[i] = c * p[i] + s * p[i + 1];
        q[i + 1] = -s * p[i] + c * p[i + 1];
      }
      return q;
    }

    std::vector<Glyph> _make()
    {
      std::vector<Glyph> all;
      auto add = [&all](const std::string &name, const std::string &text,
                        std::vector<Stroke> strokes) {
        Glyph g;
        g.name = name;
        g.text = text;
        g.strokes = strokes;
        all.push_back(g);
      };
      const Stroke::Kind L = Stroke::Line, O = Stroke::Loop, F = Stroke::Fill;

      add("play", "\xe2\x96\xb6", {_stroke(O, {-0.3, 0.8, 0.5, 0.0, -0.3, -0.8})});
      add("pause", "\xe2\x80\x96",
          {_stroke(O, {-0.8, -0.8, -0.3, -0.8, -0.3, 0.8, -0.8, 0.8}),
           _stroke(O, {0.0, -0.8, 0.5, -0.8, 0.5, 0.8, 0.0, 0.8})});
      add("rewind", "\xe2\x8f\xae",
          {_stroke(O, {-0.8, -0.8, -0.3, -0.8, -0.3, 0.8, -0.8, 0.8}),
           _stroke(O, {-0.3, 0.0, 0.5, -0.8, 0.5, 0.8})});
      std::vector<double> head = {0.0, 0.8, 0.8, 0.0, 0.0, -0.8};
      std::vector<double> bar = {-0.8, 0.8, -0.3, 0.8, -0.3, -0.8, -0.8, -0.8};
      add("forward", "\xe2\x96\xb8", {_stroke(O, head), _stroke(O, bar)});
      add("back", "\xe2\x97\x82",
          {_stroke(O, _turned(head, 180.)), _stroke(O, _turned(bar, 180.))});

      add("rotate", "\xe2\x86\xbb",
          {_stroke(L, _arc(0.0, -0.1, 0.7, 0.0, 270.0)),
           _stroke(F, {0.5, 0.6, -0.1, 0.9, -0.1, 0.3})});

      // a crosshair over a target: the point of the model a query asks about
      add("query", "\xe2\x8c\x96",
          {_stroke(L, _arc(0.0, 0.0, 0.45, 0.0, 360.0)),
           _stroke(O, {-0.9, 0.0, -0.2, 0.0}), _stroke(O, {0.2, 0.0, 0.9, 0.0}),
           _stroke(O, {0.0, -0.9, 0.0, -0.2}),
           _stroke(O, {0.0, 0.2, 0.0, 0.9})});

      // a ruler: the line a measurement draws between the two points it is
      // given, its ends and its graduations
      add("measure", "\xe2\x86\x94",
          {_stroke(O, {-0.75, 0.55, 0.75, -0.55}),
           _stroke(O, {-0.90, 0.35, -0.60, 0.75}),
           _stroke(O, {0.60, -0.75, 0.90, -0.35}),
           _stroke(O, {-0.38, 0.28, -0.29, 0.40}),
           _stroke(O, {0.00, 0.00, 0.09, 0.12}),
           _stroke(O, {0.38, -0.28, 0.46, -0.15})});

      add("models", "\xe2\x89\xa1",
          {_stroke(O, {-0.8, -0.7, 0.8, -0.7}), _stroke(O, {-0.8, -0.2, 0.8, -0.2}),
           _stroke(O, {-0.8, 0.3, 0.8, 0.3}), _stroke(O, {-0.8, 0.8, 0.8, 0.8})});

      {
        std::vector<Stroke> gear = {_stroke(L, _arc(0., 0., 0.5, 0., 360.), 3.)};
        const double w = 0.12, h1 = 0.5, h2 = 1.05;
        for(int i = 1; i <= 8; i++)
          gear.push_back(
            _stroke(F, _turned({h1, -w, h2, -w, h2, w, h1, w}, 45. * i)));
        add("gear", "\xe2\x9a\x99", gear);
      }

      add("graph", "\xe2\x86\x97",
          {_stroke(L, {-0.8, -0.8, -0.8, 0.8, 0.8, 0.8}),
           _stroke(L, {-0.8, 0.3, -0.2, -0.2, 0.3, 0.1, 0.8, -0.4})});

      {
        const double e = 0.5;
        add("search", "\xe2\x8c\x95",
            {_stroke(F, {.6 - e, .33, 1.2 - e, .93, .93 - e, 1.2, .33 - e, .6}),
             _stroke(O, _arc(0 - e, 0, .6, 0., 360.), 2.)});
      }

      {
        Stroke red = _stroke(F, {-0.8, -0.8, -0.3, -0.8, -0.3, 0.8, -0.8, 0.8});
        red.colour = Colour(255, 0, 0);
        Stroke green = _stroke(F, {-0.3, -0.8, 0.2, -0.8, 0.2, 0.8, -0.3, 0.8});
        green.colour = Colour(0, 255, 0);
        Stroke blue = _stroke(F, {0.2, -0.8, 0.7, -0.8, 0.7, 0.8, 0.2, 0.8});
        blue.colour = Colour(0, 0, 255);
        add("colormap", "\xe2\x96\xa6", {red, green, blue});
      }
      return all;
    }

  } // namespace

  const std::vector<Glyph> &glyphs()
  {
    static const std::vector<Glyph> all = _make();
    return all;
  }

  const Glyph *glyph(const std::string &name)
  {
    for(const auto &g : glyphs())
      if(g.name == name) return &g;
    return nullptr;
  }

} // namespace Ui

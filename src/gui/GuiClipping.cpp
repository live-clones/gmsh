// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include "GuiClipping.h"
#include "GuiDeclare.h"
#include "Context.h"
#include "Options.h"
#include "drawContext.h"
#include "sceneHost.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

using namespace Ui;
using namespace Declare;

namespace {

  std::vector<int *> _masks()
  {
    std::vector<int *> m = {&CTX::instance()->geom.clip,
                            &CTX::instance()->mesh.clip};
#if defined(HAVE_POST)
    for(PView *v : PView::list) m.push_back(&v->getOptions()->clip);
#endif
    return m;
  }

  void _targets(std::vector<std::string> &names, std::vector<int> &values)
  {
    names = {"Geometry", "Mesh"};
    for(std::size_t i = 2; i < _masks().size(); i++)
      names.push_back("View [" + std::to_string(i - 2) + "]");
    for(std::size_t i = 0; i < names.size(); i++) values.push_back((int)i);
  }

  std::string _name(int plane, int coefficient)
  {
    return "Clip" + std::to_string(plane) + "ABCD"[coefficient];
  }

  void _set(int plane, int coefficient, double v)
  {
    NumberOption(GMSH_SET | GMSH_GUI, "General", 0,
                 _name(plane, coefficient).c_str(), v);
  }

  // the face towards -x is plane 0, the one towards +x plane 3
  double _centre(int axis)
  {
    return (-CTX::instance()->clipPlane[axis][3] +
            CTX::instance()->clipPlane[axis + 3][3]) / 2.;
  }
  double _size(int axis)
  {
    return CTX::instance()->clipPlane[axis][3] +
           CTX::instance()->clipPlane[axis + 3][3];
  }
  void _setBox(int axis, double centre, double size)
  {
    for(int j = 0; j < 3; j++) {
      _set(axis, j, j == axis ? 1. : 0.);
      _set(axis + 3, j, j == axis ? -1. : 0.);
    }
    _set(axis, 3, -centre + size / 2.);
    _set(axis + 3, 3, centre + size / 2.);
  }

} // namespace

Form GuiClipping::build()
{
  CTX *ctx = CTX::instance();
  double span = 0.;
  for(int i = 0; i < 3; i++)
    span = std::max(span, std::max(std::fabs(ctx->min[i]),
                                   std::fabs(ctx->max[i])));
  span *= 1.5;
  double fine = ctx->inputScrolling ? .01 : 0.;
  double coarse = ctx->inputScrolling ? span / 200. : 0.;

  auto chosen = [this](int i) { return (*_masks()[i] & (1 << plane)) != 0; };
  auto choose = [this](int i, bool on) {
    int bits = pane() == "Box" ? 0x3f : (1 << plane);
    int &mask = *_masks()[i];
    mask = on ? (mask | bits) : (mask & ~bits);
    update(false);
  };
  Field targets = chooseFrom(_targets, chosen, choose, true).fills().sized(7.);

  auto tab = [this](const std::string &name) {
    if(name == "Box")
      for(int *mask : _masks()) *mask = (*mask & (1 << plane)) ? 0x3f : 0;
    update(false);
  };
  auto moved = [this]() { update(true); };
  auto coefficient = [&](int j, double bound, double step) {
    return number(std::string(1, "ABCD"[j]), "General." + _name(plane, j))
      .tip("A * X + B * Y + C * Z + D = 0")
      .within(-bound, bound, step)
      .onChanged(moved);
  };
  Item planes = vbox(
    {choice("", &plane,
            {"Plane 0", "Plane 1", "Plane 2", "Plane 3", "Plane 4", "Plane 5"},
            {0, 1, 2, 3, 4, 5})
       .sized(11.)
       .onChanged([this]() { reload(); }),
     hbox({button("-", [this]() { invert(); })
             .tip("Invert orientation")
             .sized(1.)
             .tall(4),
           vbox({coefficient(0, 1., fine), coefficient(1, 1., fine),
                 coefficient(2, 1., fine), coefficient(3, span, coarse)})},
          0.)});

  auto box = [&](int axis, bool size) {
    return number((size ? "D" : "") + std::string(1, "XYZ"[axis]),
                  [=]() { return size ? _size(axis) : _centre(axis); },
                  [=](double v) {
                    _setBox(axis, size ? _centre(axis) : v,
                            size ? v : _size(axis));
                  })
      .within(-span, span, coarse)
      .onChanged(moved);
  };

  auto changed = [this]() { update(false); };
  auto notCapping = [ctx]() { return !ctx->clipCapping; };
  auto whole = [ctx]() {
    return !ctx->clipCapping && ctx->clipWholeElements;
  };

  return {"clipping", "Clipping",
          hbox({targets,
                vbox({tabs({{"Planes", planes},
                            {"Box", vbox({hbox({box(0, false), box(0, true)}),
                                          hbox({box(1, false), box(1, true)}),
                                          hbox({box(2, false), box(2, true)})})}},
                           tab),
                      check("Cap volumes", "General.ClipCapping")
                        .onChanged([this, ctx]() {
                          capping = ctx->clipCapping;
                          update(false);
                        }),
                      check("Keep whole elements", "General.ClipWholeElements")
                        .enabledWhen(notCapping)
                        .onChanged([this, ctx]() {
                          wholeElements = ctx->clipWholeElements;
                          update(false);
                        }),
                      check("Only draw volume layer", "General.ClipOnlyDrawIntersectingVolume")
                        .enabledWhen(whole)
                        .onChanged(changed),
                      check("Only clip volume elements", "General.ClipOnlyVolume")
                        .enabledWhen(whole)
                        .onChanged(changed),
                      hbox({gap(), button("Reset", [this]() { reset(); })})})})};
}

void GuiClipping::update(bool still)
{
  CTX *ctx = CTX::instance();
  if(pane() == "Box")
    for(int axis = 0; axis < 3; axis++)
      _setBox(axis, _centre(axis), _size(axis));

  // the context holds what is drawn with, which differs while a value is chosen
  if(!adjusting) {
    capping = ctx->clipCapping;
    wholeElements = ctx->clipWholeElements;
  }
  if(capping && wholeElements) {
    wholeElements = 0;
    double off = 0.;
    NumberOption(GMSH_SET | GMSH_GUI, "General", 0, "ClipWholeElements", off);
  }

  // while the value is chosen OpenGL alone clips: whole element mode and
  // capping walk every 3D element, and wait until it settles
  adjusting = still;
  ctx->clipCapping = still ? 0 : capping;
  ctx->clipWholeElements = still ? 0 : wholeElements;
  ctx->drawBBox = still ? 1 : 0;
  drawContext::global()->draw();
  if(still && Scene::host().later) {
    int token = ++settles;
    Scene::host().later(0.5, [this, token]() {
      if(token == settles)
        update(Scene::host().buttonDown && Scene::host().buttonDown());
    });
  }
}

void GuiClipping::invert()
{
  for(int j = 0; j < 4; j++)
    _set(plane, j, -CTX::instance()->clipPlane[plane][j]);
  update(false);
}

void GuiClipping::reset()
{
  for(int *mask : _masks()) *mask = 0;
  double v;
  for(int p = 0; p < 6; p++)
    for(int j = 0; j < 4; j++)
      NumberOption(GMSH_SET_DEFAULT | GMSH_GUI, "General", 0,
                   _name(p, j).c_str(), v);
  reload();
  drawContext::global()->draw();
}

#endif

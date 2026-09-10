// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "axisTicks.h"
#include "drawContext.h"
#include "Context.h"
#include "GmshDefines.h"

int axisSharedExponent(double min, double max)
{
  double mag = std::max(fabs(min), fabs(max));
  if(mag <= 0.) return 0;
  int e = (int)floor(log10(mag));
  return (e >= 5 || e <= -4) ? e : 0;
}

std::string axisMultiplier(int exp)
{
  if(!exp) return "";
  char str[64];
  if(CTX::instance()->printing) {
    int f = CTX::instance()->print.fileFormat;
    if(f == FORMAT_TEX) {
      sprintf(str, "$\\times 10^{%d}$", exp);
      return str;
    }
    if(f == FORMAT_PS || f == FORMAT_EPS || f == FORMAT_PDF ||
       f == FORMAT_SVG || f == FORMAT_TIKZ) {
      sprintf(str, "x10^%d", exp);
      return str;
    }
  }
  const char *sup[10] = {"⁰", "¹", "²", "³", "⁴",
                         "⁵", "⁶", "⁷", "⁸", "⁹"};
  std::string s = "×10";
  if(exp < 0) s += "⁻";
  sprintf(str, "%d", abs(exp));
  for(const char *c = str; *c; c++) s += sup[*c - '0'];
  return s;
}

std::string axisNumber(double v, int decimals, int exp)
{
  double m = exp ? v / pow(10., exp) : v;
  char str[64];
  sprintf(str, "%.*f", decimals, m);
  // no "-0.00"
  bool zero = true;
  for(const char *c = str; *c; c++)
    if(*c >= '1' && *c <= '9') zero = false;
  if(zero && str[0] == '-') return std::string(str + 1);
  return str;
}

int axisDecimals(double v, int exp)
{
  double m = fabs(exp ? v / pow(10., exp) : v);
  if(m == 0.) return 0;
  return std::max(0, 2 - (int)floor(log10(m)));
}

namespace {
  // the label of an end of the range: with the decimals of the step when
  // they print it exactly, with three significant digits otherwise
  std::string endLabel(double v, int stepDecimals, int exp, double range)
  {
    double m = exp ? v / pow(10., exp) : v;
    double scale = pow(10., stepDecimals);
    if(fabs(m * scale - floor(m * scale + 0.5)) < 1.e-6 * range / pow(10., exp))
      return axisNumber(v, stepDecimals, exp);
    return axisNumber(v, std::max(stepDecimals, axisDecimals(v, exp)), exp);
  }

  bool ticksFit(const std::vector<axisTick> &ticks, double length,
                const std::vector<double> &widths, double fontH,
                bool horizontal)
  {
    for(std::size_t i = 1; i < ticks.size(); i++) {
      double gap = (ticks[i].t - ticks[i - 1].t) * length;
      double need = horizontal ?
                      0.5 * (widths[i] + widths[i - 1]) + 0.6 * fontH :
                      1.3 * fontH;
      if(gap < need) return false;
    }
    return true;
  }

  double labelWidth(const std::string &s)
  {
    return drawContext::global()->getStringWidth(s.c_str());
  }
} // namespace

void axisThinTicks(std::vector<axisTick> &ticks, double length, double fontH,
                   bool horizontal)
{
  if(ticks.empty()) return;
  std::vector<double> widths(ticks.size());
  for(std::size_t i = 0; i < ticks.size(); i++)
    widths[i] = labelWidth(ticks[i].label);
  int n = (int)ticks.size();
  for(int k = 1; k < n; k++) {
    std::vector<axisTick> kept;
    std::vector<double> kw;
    for(int i = 0; i < n; i += k) {
      kept.push_back(ticks[i]);
      kw.push_back(widths[i]);
    }
    if(kept.back().t != ticks.back().t) {
      kept.push_back(ticks.back());
      kw.push_back(widths.back());
    }
    if(ticksFit(kept, length, kw, fontH, horizontal)) {
      ticks = kept;
      return;
    }
    // the last two may be what collides: without the one before the last
    if(kept.size() > 2) {
      kept.erase(kept.end() - 2);
      kw.erase(kw.end() - 2);
      if(ticksFit(kept, length, kw, fontH, horizontal)) {
        ticks = kept;
        return;
      }
    }
  }
  axisTick last = ticks.back();
  ticks.clear();
  ticks.push_back(last);
}

void makeAxisTicks(double min, double max, double length, double fontH,
                   bool horizontal, const std::string &format, int divisions,
                   bool labelEnds, std::vector<axisTick> &ticks,
                   std::string &multiplier)
{
  ticks.clear();
  multiplier.clear();
  bool automatic = format.empty();
  char str[128];

  if(min >= max) {
    // an empty range, or one given the other way round: its two ends
    int exp = automatic ? axisSharedExponent(min, max) : 0;
    multiplier = axisMultiplier(exp);
    for(int i = 0; i < 2; i++) {
      axisTick tk;
      tk.v = i ? max : min;
      tk.t = i ? 1. : 0.;
      if(automatic)
        tk.label = endLabel(tk.v, 0, exp, fabs(min - max));
      else {
        sprintf(str, format.c_str(), tk.v);
        tk.label = str;
      }
      ticks.push_back(tk);
    }
    if(min == max) ticks.resize(1);
    return;
  }

  if(!automatic) {
    // the divisions of the range, as many as fit
    int n = std::max(1, divisions);
    for(int i = 0; i < n + 1; i++) {
      axisTick tk;
      tk.t = (double)i / n;
      tk.v = min + tk.t * (max - min);
      sprintf(str, format.c_str(), tk.v);
      tk.label = str;
      ticks.push_back(tk);
    }
    axisThinTicks(ticks, length, fontH, horizontal);
    return;
  }

  int exp = axisSharedExponent(min, max);
  multiplier = axisMultiplier(exp);
  double r = max - min;

  // the ends of the range are always labelled
  std::vector<axisTick> ends(2);
  ends[0].v = min; ends[0].t = 0.; ends[0].label = endLabel(min, 0, exp, r);
  ends[1].v = max; ends[1].t = 1.; ends[1].label = endLabel(max, 0, exp, r);
  std::vector<double> endWidths(2);
  for(int i = 0; i < 2; i++) endWidths[i] = labelWidth(ends[i].label);
  if(!ticksFit(ends, length, endWidths, fontH, horizontal)) {
    // room for one label only: the middle of the range
    axisTick mid;
    mid.v = 0.5 * (min + max);
    mid.t = 0.5;
    mid.label = axisNumber(mid.v, axisDecimals(mid.v, exp), exp);
    ticks.push_back(mid);
    return;
  }

  // the round steps that span the range, from coarse to fine; a step whose
  // labels do not fit is dropped, and among those that do the one giving
  // about `divisions' of them wins, or the finest when nothing is asked
  std::vector<double> steps;
  const int mant[3] = {5, 2, 1};
  for(int k = (int)ceil(log10(r)); k >= (int)floor(log10(r)) - 2; k--)
    for(int j = 0; j < 3; j++) {
      double st = mant[j] * pow(10., k);
      if(r / st >= 1.5 && r / st <= 12.) steps.push_back(st);
    }

  std::vector<axisTick> best = labelEnds ? ends : std::vector<axisTick>();
  int bestScore = -1;
  for(std::size_t si = 0; si < steps.size(); si++) {
    double st = steps[si];
    int decimals = std::max(0, -(int)floor(log10(st / pow(10., exp)) + 1e-9));
    std::vector<axisTick> cand;
    double w0 = 0., w1 = 0.;
    axisTick last;
    if(labelEnds) {
      cand.push_back(ends[0]);
      cand[0].label = endLabel(min, decimals, exp, r);
      w0 = labelWidth(cand[0].label);
      last = ends[1];
      last.label = endLabel(max, decimals, exp, r);
      w1 = labelWidth(last.label);
    }
    // a round value too close to an end for both labels gives way
    for(double v = ceil(min / st) * st; v < max + 1.e-9 * r; v += st) {
      if(v < min - 1.e-9 * r) continue;
      axisTick tk;
      tk.v = v;
      tk.t = (v - min) / r;
      if(tk.t < 0.) tk.t = 0.;
      if(tk.t > 1.) tk.t = 1.;
      tk.label = axisNumber(v, decimals, exp);
      if(labelEnds) {
        if(tk.t <= 0. || tk.t >= 1.) continue;
        double w = labelWidth(tk.label);
        double need0 = horizontal ? 0.5 * (w + w0) + 0.6 * fontH : 1.3 * fontH;
        double need1 = horizontal ? 0.5 * (w + w1) + 0.6 * fontH : 1.3 * fontH;
        if(tk.t * length < need0 || (1. - tk.t) * length < need1) continue;
      }
      cand.push_back(tk);
    }
    if(labelEnds) cand.push_back(last);
    if(cand.empty()) continue;
    std::vector<double> widths(cand.size());
    for(std::size_t i = 0; i < cand.size(); i++)
      widths[i] = labelWidth(cand[i].label);
    if(!ticksFit(cand, length, widths, fontH, horizontal)) continue;
    if(divisions <= 0) { // the finest that fits
      best = cand;
      bestScore = 0;
      continue;
    }
    // as close as possible to the number of labels asked for, the coarser
    // step winning a tie
    int score = abs((int)cand.size() - divisions);
    if(bestScore < 0 || score < bestScore) {
      best = cand;
      bestScore = score;
    }
  }
  ticks = best;
}

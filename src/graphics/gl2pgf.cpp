// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Sebastian Eiser

#include <stdlib.h>
#include <stdio.h>
#include "GmshConfig.h"
#include "PixelBuffer.h"
#include "OS.h"
#include "Context.h"
#include "PView.h"
#include "PViewData.h"
#include "Numeric.h"
#include "Options.h"
#include "StringUtils.h"
#include "gl2png.h"

static int assembleColmapStr(const int num, const int intType, int &samples,
                             std::string &ret)
{
  GmshColorTable *ct = GetColorTable(num); // i
  ret.assign("\\pgfplotsset{\ncolormap={gmshcolormap}{%% note: "
             "Only needed once if colorbars do not change\n");

  samples = (int)opt_view_nb_iso(num, GMSH_GET, 0);
  double step = 0.;
  switch(intType) {
  case 2:
    samples = 64;
    break; // continuous is approximated by 64 samples
  case 3:
    break; // filled (sampled colorbar)
  case 1:
    break; // iso lines
  case 4: // numericals
  default: return 1;
  }
  step = (double)(1. * ct->size) / (samples - 1.);
  int r, g, b, a;
  unsigned int idx;
  char tmp[265];
  for(unsigned int j = 0; j < (unsigned int)samples - 1; j++ /*j+=4*/) {
    idx = (unsigned int)j * step;
    // printf("j=%d, idx=%d step=%f\n", j, idx, step);
    r = CTX::instance()->unpackRed(ct->table[idx]);
    g = CTX::instance()->unpackGreen(ct->table[idx]);
    b = CTX::instance()->unpackBlue(ct->table[idx]);
    a = CTX::instance()->unpackAlpha(ct->table[idx]);
    if(a != 255)
      Msg::Warning("PGF export does not handle transparent colormaps");

    sprintf(tmp, "rgb255=(%d,%d,%d) ", r, g, b);
    ret.append(tmp);

    if(intType != 2) // sampled
      // reinsert, because then the end color is interpreted correctly
      // for shader=flat mean
      ret.append(tmp);
  }
  // endpoint
  r = CTX::instance()->unpackRed(ct->table[ct->size - 1]);
  g = CTX::instance()->unpackGreen(ct->table[ct->size - 1]);
  b = CTX::instance()->unpackBlue(ct->table[ct->size - 1]);
  sprintf(tmp, "rgb255=(%d,%d,%d) ", r, g, b);
  ret.append(tmp);
  if(intType != 2) // sampled
    // reinsert, because then the end color is interpreted correctly
    // for shader=flat mean
    ret.append(tmp);

  ret.append("}\n}%%\n");

  return 0;
}

static int assembleColbarStr(const int num, const int intType,
                             const int samples, std::string &ret)
{
  double cbmin, cbmax;
  cbmin = opt_view_min(num, GMSH_GET, 0);
  cbmax = opt_view_max(num, GMSH_GET, 0);
  int rangeType = (int)opt_view_range_type(num, GMSH_GET, 0);
  char tmp[265];
  switch(rangeType) {
  case 2: {
    cbmin = opt_view_custom_min(num, GMSH_GET, 0);
    cbmax = opt_view_custom_max(num, GMSH_GET, 0);
    break;
  }
  case 1: // default
  case 3: // per time step FIXME
  default: break;
  }
  ret.assign("\tcolorbar style={\n\t\t%%width=0.5cm, "
             "%% adjust width of colorbar\n"
             "\t\t%%height=6cm,%% adjust height of colorbar,\n");
  if(intType != 2) { // sampled
    sprintf(tmp, "\t\tsamples=%d,\n", samples + 1);
    ret.append(tmp);
  }

  int scaleType = (int)opt_view_scale_type(num, GMSH_GET, 0);
  int horizontal = (int)opt_print_pgf_horiz_bar(0, GMSH_GET, 0);
  // 1 linear
  // 2 log
  // 3 double log ???
  if(scaleType == 2) { // log
    // see
    // http://tex.stackexchange.com/questions/23750/log-color-bar-meta-data-in-pgfplot
    if(horizontal)
      sprintf(tmp, "\t\txticklabel={$10^{\\pgfmathparse{\\tick}"
                   "\\pgfmathprintnumber\\pgfmathresult}$},\n");
    else
      sprintf(tmp, "\t\tyticklabel={$10^{\\pgfmathparse{\\tick}"
                   "\\pgfmathprintnumber\\pgfmathresult}$},\n");
    ret.append(tmp);
  }

  ret.append("\t}]\n\t  %% a dummy plot for the colorbar (invisible):\n");
  if(scaleType == 2) { // log
    cbmin = log10(cbmin);
    cbmax = log10(cbmax);
  }
  sprintf(
    tmp,
    "\t  \\addplot[point meta min=%f,"
    "point meta max=%f, update limits=false, draw=none, colorbar source]\n\t"
    "coordinates{(1,1)};\n",
    cbmin, cbmax);
  ret.append(tmp);
  return 0;
}

static int assemblePostAxis(const int num, const int intType, std::string &ret)
{
  int horizontal = (int)opt_print_pgf_horiz_bar(0, GMSH_GET, 0);
  std::string post_var;
  char tmp[265];
  post_var = PView::list[num]->getData()->getName();

  if(!post_var.empty()) {
    sprintf(tmp, "\ttitle={%s},\n", post_var.c_str());
    ret.assign(tmp);
  }
  ret.append("\tcolorbar,\n\tcolormap name=gmshcolormap,\n");
  if(horizontal) {
    ret.append("\tcolorbar horizontal,\n");
  }
  else {
    ret.append("\tcolorbar right, %% or left...\n");
  }
  if(intType == 3) { // sampled
    ret.append("\tcolorbar sampled,\n");
  }
  else if(intType == 1) {
    ret.append("\tcolorbar sampled line,\n");
  }
  return 0;
}

static int getMinMaxOfAxis(const int num, double result[8][3])
{
  double xmin, xmax, ymin, ymax, zmin, zmax;
  // axes ranges
  if(!(int)opt_general_axes_auto_position(0, GMSH_GET, 0)) {
    // needs to get manual axes set
    xmin = opt_general_axes_xmin(0, GMSH_GET, 0);
    xmax = opt_general_axes_xmax(0, GMSH_GET, 0);
    ymin = opt_general_axes_ymin(0, GMSH_GET, 0);
    ymax = opt_general_axes_ymax(0, GMSH_GET, 0);
    zmin = opt_general_axes_zmin(0, GMSH_GET, 0);
    zmax = opt_general_axes_zmax(0, GMSH_GET, 0);
    fprintf(stderr, "General axes non auto, using\n");
    fprintf(stderr, "x=(%f,%f), y=(%f,%f), z=(%f,%f)\n", xmin, xmax, ymin, ymax,
            zmin, zmax);
  }
  else if(num >= 0 && !(int)opt_view_axes_auto_position(num, GMSH_GET, 0)) {
    // needs to get manual axes set
    xmin = opt_view_axes_xmin(num, GMSH_GET, 0);
    xmax = opt_view_axes_xmax(num, GMSH_GET, 0);
    ymin = opt_view_axes_ymin(num, GMSH_GET, 0);
    ymax = opt_view_axes_ymax(num, GMSH_GET, 0);
    zmin = opt_view_axes_zmin(num, GMSH_GET, 0);
    zmax = opt_view_axes_zmax(num, GMSH_GET, 0);
    fprintf(stderr, "View axes non auto, using:\n");
    fprintf(stderr, "x=(%f,%f), y=(%f,%f), z=(%f,%f)\n", xmin, xmax, ymin, ymax,
            zmin, zmax);
  }
  else { // default
    xmin = CTX::instance()->min[0];
    xmax = CTX::instance()->max[0];
    ymin = CTX::instance()->min[1];
    ymax = CTX::instance()->max[1];
    zmin = CTX::instance()->min[2];
    zmax = CTX::instance()->max[2];
    fprintf(stderr, "Axes auto, using:\n");
    fprintf(stderr, "x=(%f,%f), y=(%f,%f), z=(%f,%f)\n", xmin, xmax, ymin, ymax,
            zmin, zmax);
  }
  result[0][0] = result[1][0] = result[2][0] = result[3][0] = xmin;
  result[4][0] = result[5][0] = result[6][0] = result[7][0] = xmax;

  result[0][1] = result[1][1] = result[4][1] = result[5][1] = ymin;
  result[2][1] = result[3][1] = result[6][1] = result[7][1] = ymax;

  result[0][2] = result[2][2] = result[4][2] = result[6][2] = zmin;
  result[1][2] = result[3][2] = result[5][2] = result[7][2] = zmax;
  // result = {
  //     { xmin, ymin, zmin}, // origin
  //     { xmin, ymin, zmax}, // y end
  //     { xmin, ymax, zmin}, // y end z end
  //     { xmin, ymax, zmax}, // y end z end
  //     { xmax, ymin, zmin}, // x end
  //     { xmax, ymin, zmax}, // x end y end
  //     { xmax, ymax, zmin}, // x end y end z end
  //     { xmax, ymax, zmax} // x end  z end
  // };
  return 0;
}

static int assemble2d(const int num, const int exportAxis, std::string &axisstr,
                      std::string &plotstr, double *eulerAngles)
{
  double axPts[8][3];
  double factor = 1.;
  double xmin, xmax, ymin, ymax;

  axisstr.append("\taxis equal image, %% use png aspect ratio\n");

  if(exportAxis) {
    getMinMaxOfAxis(num, axPts);
    std::string xlab, ylab, zlab;
    xlab = CTX::instance()->axesLabel[0];
    ylab = CTX::instance()->axesLabel[1];
    zlab = CTX::instance()->axesLabel[2];
    if(xlab.empty()) xlab = "x";
    if(ylab.empty()) ylab = "y";
    if(zlab.empty()) zlab = "z";

    fprintf(stderr, "Euler two dim: 0:%f, 1:%f, 2:%f\n", eulerAngles[0],
            eulerAngles[1], eulerAngles[2]);
    int r0 = (int)(eulerAngles[0] + 0.5);
    int r1 = (int)(eulerAngles[1] + 0.5);
    int r2 = (int)(eulerAngles[2] + 0.5);
    if(r0 % 90 != 0 || r1 % 90 != 0 || r2 % 90 != 0) {
      fprintf(stderr, "Euler two dim: 0:%d, 1:%d, 2:%d\n", r0, r1, r2);
      Msg::Error("Please select a plane view (X, Y, Z)");
      return 1;
    }
    if(r0 % 180 == 0 && r1 % 360 == 0 && r2 % 180 == 0) {
      // xy
      xmin = axPts[0][0];
      xmax = axPts[4][0];
      ymin = axPts[0][1];
      ymax = axPts[2][1];
      if(r2 == 180) axisstr.append("\tx dir=reverse,\n");
      if((r2 == 180 && abs(r0) < 1) || (r0 == 180 && abs(r2) < 1))
        axisstr.append("\ty dir=reverse,\n");
      axisstr.append("\txlabel={" + xlab + "},\n");
      axisstr.append("\tylabel={" + ylab + "},\n");
    }
    else if(r0 % 180 == 0 && r1 % 360 == 0 && (r2 == 90 || r2 == 270)) {
      // yx
      xmin = axPts[0][1];
      xmax = axPts[2][1];
      ymin = axPts[0][0];
      ymax = axPts[4][0];
      if(r2 == 90) axisstr.append("\tx dir=reverse,\n");
      if(r2 == 270 || (r2 == 90 && r0 == 180))
        axisstr.append("\ty dir=reverse,\n");
      axisstr.append("\txlabel={" + ylab + "},\n");
      axisstr.append("\tylabel={" + xlab + "},\n");
    }
    else if((r0 == 90 || r0 == 270) && r1 % 360 == 0 &&
            (r2 == 90 || r2 == 270)) {
      xmin = axPts[0][1];
      xmax = axPts[2][1];
      ymin = axPts[0][2];
      ymax = axPts[1][2];
      if(r2 == 90) axisstr.append("\tx dir=reverse,\n");
      if(r0 == 90) axisstr.append("\ty dir=reverse,\n");
      // yz
      axisstr.append("\txlabel={" + ylab + "},\n");
      axisstr.append("\tylabel={" + zlab + "},\n");
    }
    else if(r0 % 360 == 0 && (r1 == 90 || r1 == 270) && r2 % 180 == 0) {
      // zy
      xmin = axPts[0][2];
      xmax = axPts[1][2];
      ymin = axPts[0][1];
      ymax = axPts[2][1];
      if(r1 == 270) axisstr.append("\tx dir=reverse,\n");
      if(r2 == 180) axisstr.append("\ty dir=reverse,\n");
      axisstr.append("\txlabel={" + zlab + "},\n");
      axisstr.append("\tylabel={" + ylab + "},\n");
    }
    else if((r0 == 90 || r0 == 270) && r1 % 360 == 0 && r2 % 180 == 0) {
      // xz
      xmin = axPts[0][0];
      xmax = axPts[4][0];
      ymin = axPts[0][2];
      ymax = axPts[1][2];
      if(r2 == 180) // x dir=reverse
        axisstr.append("\tx dir=reverse,\n");
      if(r0 == 90) axisstr.append("\ty dir=reverse,\n");
      axisstr.append("\txlabel={" + xlab + "},\n");
      axisstr.append("\tylabel={" + zlab + "},\n");
    }
    else if(r0 % 360 == 0 && (r1 == 90 || r1 == 270) &&
            (r2 == 90 || r2 == 270)) {
      if(r1 == 270) axisstr.append("\tx dir=reverse,\n");
      if(r2 == 270) axisstr.append("\ty dir=reverse,\n");
      // zx
      xmin = axPts[0][2];
      xmax = axPts[1][2];
      ymin = axPts[0][0];
      ymax = axPts[4][0];
      axisstr.append("\txlabel={" + zlab + "},\n");
      axisstr.append("\tylabel={" + xlab + "},\n");
    }
    else {
      Msg::Error("Cannot infer orientation from Euler angles...");
      // this should not happen
      // error=true;
      return 2;
    }
    if(fabs(xmax - xmin) < 1e-8 || fabs(ymax - ymin) < 1e-8) {
      Msg::Error(
        "I inferred x (%f) or y (%f) dimension to be zero. Cannot produce.",
        fabs(xmax - xmin), fabs(ymax - ymin));
      return 3;
    }

    double diagonal[3] = {xmax - xmin, ymax - ymin, 0};
    double minlen = norm3(diagonal);
    std::string suffix;
    if(minlen < 1e-5) {
      factor = 1e6;
      suffix.assign(" / $\\mu$m");
    }
    else if(minlen < 0.01) {
      factor = 1e3;
      suffix.assign(" / mm");
    }
    else if(minlen > 1e6) {
      factor = 1e-6;
      suffix.assign(" / Mm");
    }
    else if(minlen > 1000) {
      factor = 1e-3;
      suffix.assign(" / Km");
    }
    if(factor != 1) {
      char tmp[265];
      sprintf(tmp,
              "The pgf output has been rescaled in order to please "
              "the TeX number precision/range. Rescaling your results by "
              "a factor %g",
              factor);
      Msg::Warning(tmp);
      // sprintf(tmp, "$\\times 10^{%d}$},",(int)(log10(factor)+0.5));
      // std::string repl = tmp;
      // replace two labels
      std::size_t foundy = axisstr.rfind("},");
      if(foundy != std::string::npos)
        axisstr.insert(foundy, suffix);
      else
        return 4;

      std::size_t foundx = axisstr.rfind("},", foundy);
      if(foundx != std::string::npos)
        axisstr.insert(foundx, suffix);
      else
        return 4;
    }
    // axis options
    axisstr.append("\tenlargelimits=false, %% tight axis, use xmin=<val>, ");
    axisstr.append("xmax=<val> for custom bounding box\n");
    axisstr.append("\taxis on top,\n\tscale only axis,\n");
  }
  else {
    // no axis
    xmin = 0, xmax = 1, ymin = 0, ymax = 1;
    axisstr.append("\thide axis,\n");
  }
  char tmp[265];
  sprintf(tmp, "\t  \\addplot graphics[xmin=%f, xmax=%f, ymin=%f, ymax=%f]\n",
          xmin * factor, xmax * factor, ymin * factor, ymax * factor);

  plotstr.assign(tmp);

  return 0;
}

static int assemble3d(const int num, const int exportAxis, std::string &axisstr,
                      std::string &plotstr, double *eulerAngles, int *viewport,
                      double *proj, double *model, int ypix, int xpix)
{
  if(exportAxis) {
    axisstr.append("\tenlargelimits=false, %% tight axis, use xmin=<val>, ");
    axisstr.append("xmax=<val> for custom bounding box\n");
    axisstr.append("\tgrid=both,\n\tminor tick num=1,\n");
    std::string xlab, ylab, zlab;
    xlab = CTX::instance()->axesLabel[0];
    ylab = CTX::instance()->axesLabel[1];
    zlab = CTX::instance()->axesLabel[2];
    if(xlab.empty()) xlab = "x";
    if(ylab.empty()) ylab = "y";
    if(zlab.empty()) zlab = "z";
    axisstr.append("\txlabel={" + xlab + "}, %%\n\tylabel={" + ylab +
                   "},\n\tzlabel={" + zlab + "},\n");

    axisstr.append("\tzlabel style={rotate=-90},\n"); // bug?
  }
  else {
    if(opt_general_orthographic(0, GMSH_GET, 0) == 0) {
      Msg::Warning("Axes are not orthogonal, but because you do not want "
                   "any axes, I'll continue with a 2d picture.");
      return assemble2d(num, 0, axisstr, plotstr, eulerAngles);
    }
    if(CTX::instance()->camera) {
      Msg::Warning("Camera output not supported, but since you do not want "
                   "any axes, I'll continue with a 2d picture.");
      return assemble2d(num, 0, axisstr, plotstr, eulerAngles);
    }
    axisstr.append("\thide axis,\n");
  }

  if(opt_general_orthographic(0, GMSH_GET, 0) == 0 && exportAxis) {
    Msg::Warning("Cannot produce output if axes are not orthogonal.");
    Msg::Error("Please switch to orthographic projection mode "
               "('Alt + o') and retry if you want to output axes.");
    return 1;
  }

  double axPts[8][3];
  getMinMaxOfAxis(num, axPts);
  double factor = 1.;
  // requires the pixel coordinates of the axis ends (actually any four
  // points with all different x/y/z <pixX, pixY> would suffice)
  double axViewPt[8][3];
  std::vector<int> acceptableAnchors;
  std::vector<int> masked;

  bool reorder = false;
  double minlen = 0.;
  std::string suffix;
  for(unsigned int j = 0; j < 8; j++) {
    // project the 8 axis end points to pixel coordinates,
    // accept if they are in the screen range.

    gluProject(axPts[j][0], axPts[j][1], axPts[j][2], model, proj, viewport,
               &axViewPt[j][0], &axViewPt[j][1], &axViewPt[j][2]);
    // printf("x=%f, y=%f, z=%f\n", axPts[j][0], axPts[j][1], axPts[j][2]);
    // printf("xprn=%f, yprn=%f, zprn=%f\n",
    //        axViewPt[j][0], axViewPt[j][1], axViewPt[j][2]);
    if((int)(axViewPt[j][0] + 0.5) <= xpix &&
       (int)(axViewPt[j][1] + 0.5) <= ypix) {
      acceptableAnchors.push_back(j);
    }
    else
      masked.push_back(j);
    if(j > 0) {
      // respecting TeXs range limts (1e-4 relative precision)
      minlen = norm3(axPts[j]);
      // fprintf(stderr,"j=%d, vec length %f:\n", j, minlen);
      if(minlen < 1e-5) {
        factor = 1e6;
        suffix.assign("/$\\mu$m");
      }
      else if(minlen < 0.01) {
        factor = 1e3;
        suffix.assign("/mm");
      }
      else if(minlen > 1e6) {
        factor = 1e-6;
        suffix.assign("/Mm");
      }
      else if(minlen > 1000) {
        factor = 1e-3;
        suffix.assign("/Km");
      }
    }
    if(j == 1 && acceptableAnchors.size() == 2) {
      // precaution: if the first two coordinates are accepted, a
      // division by zero can occur in pgfplots
      // furthermore, four points with equal x=xmin leads to
      // singular system in pgfplots
      reorder = true;
      acceptableAnchors.pop_back();
    }
  }
  if(reorder) acceptableAnchors.push_back(1);

  if(acceptableAnchors.size() < 4) {
    Msg::Error("Unable to calculate anchors for pgf output. "
               "Make sure the entire scene is visible or adjust "
               "the axes min/max values to fit inside your screen.");
    return 2;
  }
  if(factor != 1) {
    char tmp[265];
    sprintf(tmp,
            "The pgf output has been rescaled in order to please "
            "the TeX number precision/range. Rescaling your results by "
            "a factor %g",
            factor);
    Msg::Warning(tmp);
    // replace three labels
    if(exportAxis) {
      // xlabel={x<>}, %%
      // ylabel={y<>},
      // zlabel={z<>},
      // zlabel style={rotate=-90},
      std::size_t foundrot = axisstr.rfind("},");
      std::size_t foundz = axisstr.rfind("},", foundrot - 1);
      if(foundz != std::string::npos)
        axisstr.insert(foundz, suffix);
      else
        return 4;
      std::size_t foundy = axisstr.rfind("},", foundz);
      if(foundy != std::string::npos)
        axisstr.insert(foundy, suffix);
      else
        return 4;

      std::size_t foundx = axisstr.rfind("},", foundy);
      if(foundx != std::string::npos)
        axisstr.insert(foundx, suffix);
      else
        return 4;
    }
  }

  char tmp[265];
  plotstr.assign("\t  \\addplot3[surf] graphics[debug=false,%%=visual,\n");
  plotstr.append("\t    points={%%\n");

  unsigned int j = 0;
  for(auto it = acceptableAnchors.begin();
      it != acceptableAnchors.end(); ++it, j++) {
    sprintf(tmp, "\t    (%f,%f,%f)", factor * axPts[*it][0],
            factor * axPts[*it][1], factor * axPts[*it][2]);
    plotstr.append(tmp);
    if(j > 3) {
      plotstr.append("%%");
    }
    // ypix-y syntax for easier debugging w/ e.g. gimp pixel
    sprintf(tmp, " => (%d, %d-%d)\n", (int)(axViewPt[*it][0] + 0.5), ypix,
            ypix - (int)(axViewPt[*it][1] + 0.5));
    plotstr.append(tmp);
  }
  for(auto it = masked.begin(); it != masked.end();
      ++it) {
    sprintf(tmp, "\t    (%f,%f,%f)", factor * axPts[*it][0],
            factor * axPts[*it][1], factor * axPts[*it][2]);
    plotstr.append(tmp);
    plotstr.append(" %% out of pixel range, discarded\n");
  }
  plotstr.append("\t    }]\n");
  return 0;
}

int print_pgf(const std::string &name, const int num, const int cnt,
              PixelBuffer *buffer, double *eulerAngles, int *viewport,
              double *proj, double *model)
{
  int ypix = buffer->getHeight();
  int xpix = buffer->getWidth();

  std::string base = SplitFileName(name)[1];
  std::string path = SplitFileName(name)[0];
  std::string pngfilen = path + base + ".png";
  std::string pgffilen = path + base + ".pgf";
  std::string texfilen = path + base + ".tex";
  FILE *fp = Fopen(pngfilen.c_str(), "wb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", pngfilen.c_str());
    return 1;
  }
  create_png(fp, buffer, 100);
  fclose(fp);

  // write pgf
  int twoDim = (int)opt_print_pgf_two_dim(0, GMSH_GET, 0);
  int exportAxis = (int)opt_print_pgf_export_axis(0, GMSH_GET, 0);
  if(cnt > 1)
    Msg::Warning("PGF colorbar output works only with a single visible "
                 "scale. Consider disabling all but one. I can only create a "
                 "single colorbar. Colorbar will be suppressed");

  int samples;
  std::string colmap_s, colbar_s, post_axis_s;
  // color map
  if(cnt == 1) { // one post processing view scale visible
    int intType = (int)opt_view_intervals_type(num, GMSH_GET, 0);
    if(assembleColmapStr(num, intType, samples, colmap_s) != 0) {
      Msg::Error("Unable to assemble colormap for PGF output");
      return 1;
    }
    if(assemblePostAxis(num, intType, post_axis_s) != 0) {
      Msg::Error("Unable to assemble post processing axis for PGF output");
      return 1;
    }
    if(assembleColbarStr(num, intType, samples, colbar_s) != 0) {
      Msg::Error("Unable to assemble colorbar for PGF output");
      return 1;
    }
  }
  else {
    colbar_s.assign("\t]\n"); // close axis without colorbar and dummy plot
  }

  std::string axis_s, plot_s;
  axis_s.assign("\\begin{tikzpicture}\n\\begin{axis}[\n\twidth=.5\\linewidth,"
                "%% set figure width here\n");
  if(twoDim) {
    if(assemble2d(num, exportAxis, axis_s, plot_s, eulerAngles) != 0) {
      return 1;
    }
  }
  else { // 3d
    if(assemble3d(num, exportAxis, axis_s, plot_s, eulerAngles, viewport, proj,
                  model, ypix, xpix) != 0) {
      return 1;
    }
  }
  char tmp[265];
  sprintf(tmp, "\t    {%s.png};\n", base.c_str());
  plot_s.append(tmp);

  fp = Fopen(pgffilen.c_str(), "wb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", pgffilen.c_str());
    return 1;
  }
  fprintf(fp, "%s", colmap_s.c_str());
  fprintf(fp, "%s", axis_s.c_str());
  fprintf(fp, "%s", post_axis_s.c_str());
  fprintf(fp, "%s", colbar_s.c_str());
  fprintf(fp, "%s", plot_s.c_str());
  fprintf(fp, "\\end{axis}\n\\end{tikzpicture}%%\n");
  fclose(fp);

  if(twoDim) {
    // try to trim the png...
    char tmp[2048];
    if(system(nullptr)) {
      std::string pngname = name;
      pngname.replace(pngname.end() - 3, pngname.end(), "png");
      sprintf(tmp, "convert -trim %s %s", pngname.c_str(), pngname.c_str());
      Msg::Info("Running:");
      Msg::Info(tmp);
      int ret = system(tmp);
      Msg::Info("Conversion returned value %d", ret);
      if(ret == 0) // success
        Msg::Info("Automatic trim successful.");
      else {
        Msg::Warning("Cannot automatically trim output png.");
        sprintf(tmp,
                "One should now manually crop the margins, using e.g."
                "gimp or `convert -trim %s %s` to get rid of any remaining"
                "margins.",
                pngfilen.c_str(), pngfilen.c_str());
        Msg::Warning(tmp);
      }
    }
    else {
      Msg::Warning("Cannot automatically trim output png.");
      sprintf(tmp,
              "One should now manually crop the margins, using e.g."
              "gimp or `convert -trim %s %s` to get rid of any remaining"
              "margins.",
              pngfilen.c_str(), pngfilen.c_str());
      Msg::Warning(tmp);
    }
  }

  // try to add transparency, do not(!) crop otherwise the transformation
  // matrix is wrong!!!!
  if(!twoDim) {
    char tmp[2048];
    if(system(nullptr)) {
      std::string pngname = name;
      pngname.replace(pngname.end() - 3, pngname.end(), "png");
      sprintf(tmp, "convert -transparent white %s %s", pngname.c_str(),
              pngname.c_str());
      Msg::Info("Running:");
      Msg::Info(tmp);
      int ret = system(tmp);
      Msg::Info("Conversion returned value %d", ret);
      if(ret == 0) // success
        Msg::Info("Automatic transparent white background successful.");
      else {
        Msg::Warning("Cannot automatically add transparency to png.");
        sprintf(tmp,
                "One should now manually add a transparent layer in "
                "order to not obstruct the axis. e.g. using gimp or "
                "convert -transparent white %s %s`.",
                pngfilen.c_str(), pngfilen.c_str());
        Msg::Warning(tmp);
      }
    }
    else { // exit (EXIT_FAILURE);
      Msg::Warning("Cannot automatically add transparency to output png.");
      sprintf(tmp,
              "One should now manually add a transparent layer in "
              "order to not obstruct the axis. e.g. using gimp or "
              "`convert -transparent white %s %s`.",
              pngfilen.c_str(), pngfilen.c_str());
      Msg::Warning(tmp);
    }
  }

  // try to write a helper tex file just in case it does not exist
  fp = Fopen(texfilen.c_str(), "r");
  if(fp) {
    fclose(fp);
    Msg::Info("File '%s' exists, please add '\\input{%s}' by yourself.",
              texfilen.c_str(), pgffilen.c_str());
  }
  else {
    fp = Fopen(texfilen.c_str(), "w");
    fprintf(fp, "\\documentclass{article}\n\\usepackage{pgfplots}\n"
                "\\pgfplotsset{compat=1.8}\n\\begin{document}\n");
    fprintf(fp, "\n\\input{%s}\n", pgffilen.c_str());
    fprintf(fp, "\n\\end{document}\n");
    fclose(fp);
  }
  return 0;
}

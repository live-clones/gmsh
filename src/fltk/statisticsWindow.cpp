// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "statisticsWindow.h"
#include "paletteWindow.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "adaptiveData.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#include "Context.h"
#include "OS.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#endif

enum QM_HISTO {
  QMH_SICN_XY,
  QMH_SICN_3D,
  QMH_GAMMA_XY,
  QMH_GAMMA_3D,
  QMH_SIGE_XY,
  QMH_SIGE_3D
};

void statistics_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->stats->show();
}

static void statistics_update_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->stats->compute(true);
}

static void statistics_histogram_cb(Fl_Widget *w, void *data)
{
  QM_HISTO qmh = *(QM_HISTO *)data;
  bool visibleOnly = FlGui::instance()->stats->visible->value() ? true : false;

  std::vector<double> x, y;

  if(qmh == QMH_SICN_XY) {
    for(int i = 0; i < 101; i++) {
      x.push_back((double)(2 * i - 100) / 100);
      y.push_back(FlGui::instance()->stats->quality[0][i]);
    }
    new PView("SICN", "# Elements", x, y);
  }
  else if(qmh == QMH_GAMMA_XY) {
    for(int i = 0; i < 101; i++) {
      x.push_back((double)i / 100);
      y.push_back(FlGui::instance()->stats->quality[1][i]);
    }
    new PView("Gamma", "# Elements", x, y);
  }
  else if(qmh == QMH_SIGE_XY) {
    for(int i = 0; i < 101; i++) {
      x.push_back((double)(2 * i - 100) / 100);
      y.push_back(FlGui::instance()->stats->quality[2][i]);
    }
    new PView("SIGE", "# Elements", x, y);
  }
  else {
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(visibleOnly && !entities[i]->getVisibility()) continue;
      if(entities[i]->dim() < 2) continue;
      for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
        MElement *e = entities[i]->getMeshElement(j);
        if(qmh == QMH_SICN_3D)
          d[e->getNum()].push_back(e->minSICNShapeMeasure());
        else if(qmh == QMH_GAMMA_3D)
          d[e->getNum()].push_back(e->gammaShapeMeasure());
        else if(qmh == QMH_SIGE_3D)
          d[e->getNum()].push_back(e->minSIGEShapeMeasure());
      }
    }
    std::string name = (qmh == QMH_SICN_3D)  ? "SICN" :
                       (qmh == QMH_GAMMA_3D) ? "Gamma" :
                       (qmh == QMH_SIGE_3D)  ? "SIGE" :
                                               "";
    new PView(name, "ElementData", GModel::current(), d);
  }

  FlGui::instance()->updateViews(true, true);
  drawContext::global()->draw();
}

statisticsWindow::statisticsWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int num = 0;
  int width = 26 * FL_NORMAL_SIZE;
  int height = 6 * WB + 19 * BH;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Statistics");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    {
      group[0] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Geometry");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 1 * BH, IW, BH, "Points");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 2 * BH, IW, BH, "Curves");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 3 * BH, IW, BH, "Surfaces");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 4 * BH, IW, BH, "Volumes");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 5 * BH, IW, BH, "Physical groups");
      group[0]->end();
    }
    {
      group[1] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Mesh");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 1 * BH, IW, BH, "Nodes");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 2 * BH, IW, BH, "Points");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 3 * BH, IW, BH, "Lines");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 4 * BH, IW, BH, "Triangles");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadrangles");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 6 * BH, IW, BH, "Tetrahedra");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 7 * BH, IW, BH, "Hexahedra");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 8 * BH, IW, BH, "Prisms");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 9 * BH, IW, BH, "Pyramids");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 10 * BH, IW, BH, "Trihedra");

      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 11 * BH, IW, BH, "Time for 1D mesh");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 12 * BH, IW, BH, "Time for 2D mesh");
      value[num++] =
        new Fl_Output(2 * WB, 2 * WB + 13 * BH, IW, BH, "Time for 3D mesh");

      value[num] = new Fl_Output(2 * WB, 2 * WB + 14 * BH, IW, BH, "SICN");
      value[num]->tooltip("~ signed inverse condition number");
      num++;
      value[num] = new Fl_Output(2 * WB, 2 * WB + 15 * BH, IW, BH, "Gamma");
      value[num]->tooltip(
        "~ inscribed_radius / circumscribed_radius (simplices)");
      num++;
      value[num] = new Fl_Output(2 * WB, 2 * WB + 16 * BH, IW, BH, "SIGE");
      value[num]->tooltip("~ signed inverse error on gradient FE solution");
      num++;

      for(int i = 0; i < 3; i++) {
        int ww = 3 * FL_NORMAL_SIZE;
        new Fl_Box(FL_NO_BOX, width - 3 * ww - 2 * WB, 2 * WB + (14 + i) * BH,
                   ww, BH, "Plot");
        butt[2 * i] = new Fl_Button(width - 2 * ww - 2 * WB,
                                    2 * WB + (14 + i) * BH, ww, BH, "X-Y");
        butt[2 * i + 1] = new Fl_Button(width - ww - 2 * WB,
                                        2 * WB + (14 + i) * BH, ww, BH, "3D");
      }
      static const QM_HISTO qmh0 = QMH_SICN_XY, qmh1 = QMH_SICN_3D,
                            qmh2 = QMH_GAMMA_XY, qmh3 = QMH_GAMMA_3D,
                            qmh4 = QMH_SIGE_XY, qmh5 = QMH_SIGE_3D;
      butt[0]->callback(statistics_histogram_cb, (void *)&qmh0);
      butt[1]->callback(statistics_histogram_cb, (void *)&qmh1);
      butt[2]->callback(statistics_histogram_cb, (void *)&qmh2);
      butt[3]->callback(statistics_histogram_cb, (void *)&qmh3);
      butt[4]->callback(statistics_histogram_cb, (void *)&qmh4);
      butt[5]->callback(statistics_histogram_cb, (void *)&qmh5);

      visible =
        new Fl_Check_Button(2 * WB, 2 * WB + 17 * BH + WB, width - 4 * WB, BH,
                            "Compute statistics for visible entities only");

      group[1]->end();
    }
    {
      group[2] = new Fl_Group(WB, WB + BH, width - 2 * WB,
                              height - 3 * WB - 2 * BH, "Post-processing");
      // the data as given, and the elements the adaptive views are refined
      // into
      int cw = 8 * FL_NORMAL_SIZE;
      new Fl_Box(2 * WB, 2 * WB + 1 * BH, cw, BH, "Data");
      new Fl_Box(3 * WB + cw, 2 * WB + 1 * BH, cw, BH, "Adapted");
      const char *rows[11] = {"Views",     "Points",      "Lines",
                              "Triangles", "Quadrangles", "Tetrahedra",
                              "Hexahedra", "Prisms",      "Pyramids",
                              "Trihedra",  "Strings"};
      for(int r = 0; r < 11; r++)
        value[num++] = new Fl_Output(2 * WB, 2 * WB + (r + 2) * BH, cw, BH);
      for(int r = 0; r < 11; r++) {
        value[num] = new Fl_Output(3 * WB + cw, 2 * WB + (r + 2) * BH, cw, BH);
        value[num++]->tooltip("The elements of the adaptive views as last "
                              "refined (they are refined when drawn), with "
                              "those refined apart where clipping planes cut");
        // (apart from the fields, which are greyed out when empty)
        Fl_Box *b = new Fl_Box(3 * WB + 2 * cw, 2 * WB + (r + 2) * BH,
                               width - 5 * WB - 2 * cw, BH, rows[r]);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      }
      group[2]->end();
    }
    o->end();
  }

  for(int i = 0; i < num; i++) {
    value[i]->align(FL_ALIGN_RIGHT);
    value[i]->value(nullptr);
  }

  {
    memUsage = new Fl_Box(WB, height - BH - WB, width / 2, BH, "");
    memUsage->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    Fl_Return_Button *o =
      new Fl_Return_Button(width - BB - WB, height - BH - WB, BB, BH, "Update");
    o->callback(statistics_update_cb);
  }

  win->position(CTX::instance()->statPosition[0],
                CTX::instance()->statPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

#if defined(HAVE_POST)
// the points, lines, triangles, quadrangles, tetrahedra, hexahedra, prisms,
// pyramids and trihedra of a view; for model-based data, those that have data
// at the step shown (the model may have more: e.g. a view of the part of a
// partitioned mesh a process computed, in the model of all the parts)
static void countViewElements(PView *p, double count[9])
{
  PViewData *data = p->getData();
  if(!dynamic_cast<PViewDataGModel *>(data)) {
    count[0] += data->getNumPoints();
    count[1] += data->getNumLines();
    count[2] += data->getNumTriangles();
    count[3] += data->getNumQuadrangles();
    count[4] += data->getNumTetrahedra();
    count[5] += data->getNumHexahedra();
    count[6] += data->getNumPrisms();
    count[7] += data->getNumPyramids();
    count[8] += data->getNumTrihedra();
    return;
  }
  int step = p->getOptions()->timeStep;
  if(!data->hasTimeStep(step)) step = data->getFirstNonEmptyTimeStep();
  if(!data->hasTimeStep(step)) return;
  for(int ent = 0; ent < data->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
      if(data->skipElement(step, ent, ele)) continue;
      switch(data->getType(step, ent, ele)) {
      case TYPE_PNT: count[0]++; break;
      case TYPE_LIN: count[1]++; break;
      case TYPE_TRI: count[2]++; break;
      case TYPE_QUA: count[3]++; break;
      case TYPE_TET: count[4]++; break;
      case TYPE_HEX: count[5]++; break;
      case TYPE_PRI: count[6]++; break;
      case TYPE_PYR: count[7]++; break;
      case TYPE_TRIH: count[8]++; break;
      }
    }
  }
}
#endif

void statisticsWindow::compute(bool elementQuality)
{
  int num = 0;
  static double s[50];
  static char label[50][256];

#if defined(HAVE_MESH)
  bool visibleOnly = visible->value() ? true : false;
  if(elementQuality)
    GetStatistics(s, quality, visibleOnly);
  else
    GetStatistics(s, nullptr, visibleOnly);
#else
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 100; j++)
      quality[i][j] = 0;
#endif

  // geom
  sprintf(label[num], "%g", s[0]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[1]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[2]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[3]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[45]);
  value[num]->value(label[num]);
  num++;

  // mesh
  sprintf(label[num], "%g", s[4]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[5]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[6]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[7]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[8]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[9]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[10]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[11]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[12]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[13]);
  value[num]->value(label[num]);
  num++;

  sprintf(label[num], "%g", s[14]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[15]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[16]);
  value[num]->value(label[num]);
  num++;

  if(!elementQuality) {
    for(int i = 0; i < 6; i += 2) butt[i]->deactivate();
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]);
    num++;
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]);
    num++;
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]);
    num++;
  }
  else {
    for(int i = 0; i < 6; i += 2) butt[i]->activate();
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[18], s[19], s[20]);
    value[num]->activate();
    value[num]->value(label[num]);
    num++;
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[21], s[22], s[23]);
    value[num]->activate();
    value[num]->value(label[num]);
    num++;
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[24], s[25], s[26]);
    value[num]->activate();
    value[num]->value(label[num]);
    num++;
  }

  // post (the views here, not in GetStatistics(), which the options reading
  // the numbers of mesh elements call)
#if defined(HAVE_POST)
  s[27] = PView::list.size();
  for(auto p : PView::list) {
    countViewElements(p, &s[28]);
    s[37] += p->getData()->getNumStrings2D() + p->getData()->getNumStrings3D();
  }
#endif
  sprintf(label[num], "%g", s[27]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[28]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[29]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[30]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[31]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[32]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[33]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[34]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[35]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[36]);
  value[num]->value(label[num]);
  num++;
  sprintf(label[num], "%g", s[37]);
  value[num]->value(label[num]);
  num++;

#if defined(HAVE_POST)
  // the elements of the adaptive views, as last refined (they are refined
  // when they are used, as drawn, not here), with those refined apart where
  // the clipping planes cut them (see PView::refineClipLayer())
  double a[10] = {0.};
  for(auto p : PView::list) {
    bool refined = false;
    for(adaptiveData *ad :
        {p->getData()->getAdaptiveData(), p->getClipAdaptiveData()}) {
      PViewData *d = ad ? ad->getData() : nullptr;
      if(!d) continue;
      refined = true;
      a[1] += d->getNumPoints();
      a[2] += d->getNumLines();
      a[3] += d->getNumTriangles();
      a[4] += d->getNumQuadrangles();
      a[5] += d->getNumTetrahedra();
      a[6] += d->getNumHexahedra();
      a[7] += d->getNumPrisms();
      a[8] += d->getNumPyramids();
      a[9] += d->getNumTrihedra();
    }
    if(refined) a[0] += 1;
  }
  // (empty and greyed out if no view is refined)
  for(int r = 0; r < 10; r++) {
    sprintf(label[num], "%g", a[r]);
    value[num]->value(a[0] ? label[num] : nullptr);
    if(a[0])
      value[num]->activate();
    else
      value[num]->deactivate();
    num++;
  }
#else
  num += 10;
#endif
  value[num]->value(nullptr); // (no strings in the refined data)
  value[num]->deactivate();
  num++;

  static char mem[256];
  std::size_t m = GetMemoryUsage();
  if(m) {
    sprintf(mem, "Memory usage: %gMB", m / 1024. / 1024.);
    memUsage->label(mem);
  }
}

void statisticsWindow::show()
{
  if(!win->shown()) compute(false);

  for(int i = 0; i < 3; i++) group[i]->hide();

  if(GModel::current()->getMeshStatus(true) > 0)
    group[1]->show();
  else if(PView::list.size())
    group[2]->show();
  else
    group[0]->show();

  win->show();
}

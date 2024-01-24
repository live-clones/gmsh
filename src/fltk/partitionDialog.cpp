// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Stephen Guzik
//   Anthony Royer
//

#include <limits>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "GModel.h"
#include "drawContext.h"
#include "Options.h"
#include "Context.h"
#include "fileDialogs.h"

#if defined(HAVE_MESH) && defined(HAVE_METIS)

#include "meshPartition.h"

// Forward declarations of some callbacks
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data);
void partition_defaults_cb(Fl_Widget *widget, void *data);
void partition_partition_cb(Fl_Widget *widget, void *data);
void partition_cancel_cb(Fl_Widget *widget, void *data);
void partition_opt_booleans_cb(Fl_Widget *widget, void *data);
void partition_select_groups_cb(Fl_Widget *widget, void *data);

// Pointers to required widgets
struct PartitionDialog {
  Fl_Window *window;
  // Group 0
  Fl_Choice *choicePartitioner;
  Fl_Value_Input *inputNumPartition;
  Fl_Check_Button *setGhostCells;
  Fl_Check_Button *setTopology;
  Fl_Check_Button *setPhysical;
  // Group 1
  Fl_Choice *choiceMetisAlg;
  Fl_Toggle_Button *toggleButtonAdvMetis;
  // Group 2
  Fl_Choice *choiceEdgeMatch;
  Fl_Choice *choiceRefineAlg;
  // weight
  Fl_Value_Input *inputTriWeight;
  Fl_Value_Input *inputQuaWeight;
  Fl_Value_Input *inputTetWeight;
  Fl_Value_Input *inputPriWeight;
  Fl_Value_Input *inputPyrWeight;
  Fl_Value_Input *inputHexWeight;

  void write_all_options()
  {
    // Group 0
    CTX::instance()->mesh.numPartitions =
      static_cast<int>(inputNumPartition->value());
    CTX::instance()->mesh.partitionCreateGhostCells = setGhostCells->value();
    CTX::instance()->mesh.partitionCreateTopology = setTopology->value();
    CTX::instance()->mesh.partitionCreatePhysicals = setPhysical->value();

    // Group 1
    CTX::instance()->mesh.metisAlgorithm = choiceMetisAlg->value() + 1;

    // Group 2
    CTX::instance()->mesh.metisEdgeMatching = choiceEdgeMatch->value() + 1;
    CTX::instance()->mesh.metisRefinementAlgorithm =
      choiceRefineAlg->value() + 1;

    CTX::instance()->mesh.partitionTriWeight = (int)inputTriWeight->value();
    CTX::instance()->mesh.partitionQuaWeight = (int)inputQuaWeight->value();
    CTX::instance()->mesh.partitionTetWeight = (int)inputTetWeight->value();
    CTX::instance()->mesh.partitionPriWeight = (int)inputPriWeight->value();
    CTX::instance()->mesh.partitionPyrWeight = (int)inputPyrWeight->value();
    CTX::instance()->mesh.partitionHexWeight = (int)inputHexWeight->value();
  }
  void read_all_options()
  {
    // Group 0
    inputNumPartition->value(CTX::instance()->mesh.numPartitions);
    setGhostCells->value(CTX::instance()->mesh.partitionCreateGhostCells);
    setTopology->value(CTX::instance()->mesh.partitionCreateTopology);
    setPhysical->value(CTX::instance()->mesh.partitionCreatePhysicals);

    // Group 2
    choiceMetisAlg->value(CTX::instance()->mesh.metisAlgorithm - 1);

    // Group 3
    choiceEdgeMatch->value(CTX::instance()->mesh.metisEdgeMatching - 1);
    choiceRefineAlg->value(CTX::instance()->mesh.metisRefinementAlgorithm - 1);

    inputTriWeight->value(CTX::instance()->mesh.partitionTriWeight);
    inputQuaWeight->value(CTX::instance()->mesh.partitionQuaWeight);
    inputTetWeight->value(CTX::instance()->mesh.partitionTetWeight);
    inputPriWeight->value(CTX::instance()->mesh.partitionPriWeight);
    inputPyrWeight->value(CTX::instance()->mesh.partitionPyrWeight);
    inputHexWeight->value(CTX::instance()->mesh.partitionHexWeight);

    // Call all callbacks to ensure consistent options
    partition_opt_num_partitions_cb(inputNumPartition, this);
  }
};

// Match several locations that provide a partition number
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog *>(data);
  unsigned val = 0;
  if(widget == dlg->inputNumPartition) {
    val = static_cast<unsigned>(dlg->inputNumPartition->value());
  }

  dlg->choiceMetisAlg->value((val <= 8) ? 0 : 1);
}

void partition_defaults_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog *>(data);
  dlg->read_all_options();
  partition_select_groups_cb(dlg->choicePartitioner, data);
}

void partition_partition_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog *>(data);

  // Write all options
  dlg->write_all_options();

  // Partition the mesh
  int ier =
    GModel::current()->partitionMesh(CTX::instance()->mesh.numPartitions);

  // Update the screen
  if(!ier) {
    opt_mesh_zone_definition(0, GMSH_SET, 2.); // Define zone by partition
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->mesh.changed = ENT_ALL;
    FlGui::instance()->resetVisibility();
    drawContext::global()->draw();
  }
}

void partition_cancel_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog *>(data);
  dlg->window->hide();
  Fl::delete_widget(dlg->window);
}

// Select groups to display
void partition_select_groups_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog *>(data);
  // If this callback was made by the "Advanced" toggle buttons, set the label

  if(dlg->toggleButtonAdvMetis == widget) {
    dlg->toggleButtonAdvMetis->label((dlg->toggleButtonAdvMetis->value()) ?
                                       "Advanced @-28->" :
                                       "Advanced @-22->");
  }

  // Get the groups
  Fl_Widget *const *g = dlg->window->array();
  int y = g[0]->h();
  g[1]->show();
  y += g[1]->h();
  if(dlg->toggleButtonAdvMetis->value()) {
    g[2]->show();
    y += g[2]->h();
  }
  else {
    g[2]->hide();
  }

  // Reset the vertical position of all widgets in group 6
  {
    int yG = y;
    g[3]->position(g[3]->x(), yG);
    Fl_Widget *o = static_cast<Fl_Group *>(g[3])->child(0);
    o->position(o->x(), yG);
    yG += WB + o->h();
    o = static_cast<Fl_Group *>(g[3])->child(1);
    o->position(o->x(), yG);
    o = static_cast<Fl_Group *>(g[3])->child(2);
    o->position(o->x(), yG);
    yG += WB + o->h();
  }
  y += g[3]->h();

  dlg->window->size(dlg->window->w(), y);
  dlg->window->redraw();
}

void partition_dialog()
{
  static PartitionDialog dlg;

  static Fl_Menu_Item partitionTypeMenu[] = {{"Metis", 0, nullptr, nullptr},
                                             {nullptr}};

  static Fl_Menu_Item metisAlgMenu[] = {{"Recursive", 0, nullptr, nullptr},
                                        {"K-way", 0, nullptr, nullptr},
                                        {nullptr}};

  static Fl_Menu_Item metisEdgeMatchingMenu[] = {
    {"Random", 0, nullptr, nullptr},
    {"Sorted heavy-edge", 0, nullptr, nullptr},
    {nullptr}};

  static Fl_Menu_Item metisRefineAlgMenu[] = {
    {"FM-based cut", 0, nullptr, nullptr},
    {"Greedy", 0, nullptr, nullptr},
    {"Two-sided node FM", 0, nullptr, nullptr},
    {"One-sided node FM", 0, nullptr, nullptr},
    {nullptr}};

  // This will be resized based on groups that are displayed
  const int h = 8 * WB + 5 * BH + 4;
  const int w = 3 * BB + IW + 3 * WB; // Window width
  int y = 0;

  dlg.window = new paletteWindow(
    w, h, CTX::instance()->nonModalWindows ? true : false, "Partition");
  dlg.window->box(GMSH_WINDOW_BOX);
  dlg.window->callback((Fl_Callback *)partition_cancel_cb, &dlg);

  // Main options group [0]
  {
    const int GH = 3 * BH + 2 + 5 * WB;
    y += WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Partitioner
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Partitioner");
      dlg.choicePartitioner = o;
      o->menu(partitionTypeMenu);
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
#if !defined(HAVE_METIS)
      o->mode(1, FL_MENU_INACTIVE);
#endif
      o->align(FL_ALIGN_RIGHT);
    }
    // Number of partitions
    {
      Fl_Value_Input *const o =
        new Fl_Value_Input(2 * WB + 2 * BB, y, IW, BH, "Number of\nPartitions");
      dlg.inputNumPartition = o;
      o->minimum(0);
      o->maximum(std::numeric_limits<unsigned short>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    // Booleans options
    {
      Fl_Check_Button *const o = new Fl_Check_Button(2 * WB + 2 * BB, y, 2 * BB,
                                                     BH, "Create ghost cells");
      dlg.setGhostCells = o;
    }
    {
      Fl_Check_Button *const o =
        new Fl_Check_Button(WB, y, 2 * BB, BH, "Create partition topology");
      dlg.setTopology = o;
    }
    y += BH + WB;
    {
      Fl_Check_Button *const o =
        new Fl_Check_Button(WB, y, 2 * BB, BH, "Create physical groups");
      dlg.setPhysical = o;
    }
    y += BH + WB;
    // Box (line)
    {
      Fl_Box *o = new Fl_Box(WB, y, w - 2 * WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    g->end();
    g->show();
  }
  const int yMain = y;

  // Metis options group [1]
  y = yMain;
  {
    const int GH = BH + WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Algorithm");
      dlg.choiceMetisAlg = o;
      o->menu(metisAlgMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Advanced Button
    {
      Fl_Toggle_Button *const o =
        new Fl_Toggle_Button(w - (WB + BB), y, BB, BH, "Advanced @-22->");
      dlg.toggleButtonAdvMetis = o;
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Metis advanced option group [2]
  {
    const int GH = 2 + WB + 3 * (BH + WB) + 2;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line)
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2 * WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB + 1; // +1 for multiline label
    // Edge matching algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Edge matching");
      dlg.choiceEdgeMatch = o;
      o->menu(metisEdgeMatchingMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Refinement algorithm
    {
      Fl_Choice *const o =
        new Fl_Choice(2 * WB + 2 * BB, y, BB, BH, "Refinement\nalgorithm");
      dlg.choiceRefineAlg = o;
      o->menu(metisRefineAlgMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1; // +1 for multiline label
    // element weights - line 1
    {
      Fl_Value_Input *const o =
        new Fl_Value_Input(WB, y, 2 * BB / 3, BH, "Triangle");
      dlg.inputTriWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input(
        2 * WB + (w / 3 - WB), y, 2 * BB / 3, BH, "Tetrahedron");
      dlg.inputTetWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input(3 * WB + 2 * (w / 3 - WB), y,
                                                   2 * BB / 3, BH, "Prism");
      dlg.inputPriWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += 2 + WB + BH + 1;
    // element weights - line 2
    {
      Fl_Value_Input *const o =
        new Fl_Value_Input(WB, y, 2 * BB / 3, BH, "Quadrangle");
      dlg.inputQuaWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input(
        2 * WB + (w / 3 - WB), y, 2 * BB / 3, BH, "Hexahedron");
      dlg.inputHexWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Value_Input *const o = new Fl_Value_Input(3 * WB + 2 * (w / 3 - WB), y,
                                                   2 * BB / 3, BH, "Pyramid");
      dlg.inputPyrWeight = o;
      o->minimum(-1);
      o->maximum(std::numeric_limits<int>::max());
      if(CTX::instance()->inputScrolling) o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1; // +1 for multiline label
    g->end();
    g->hide();
  }

  // Dialog termination group [3]
  {
    const int GH = 2 + BH + 2 * WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line) [0]
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2 * WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    // Defaults Button [1]
    {
      Fl_Button *const o = new Fl_Button(WB, y, BB, BH, "Defaults");
      o->callback((Fl_Callback *)partition_defaults_cb, &dlg);
    }
    // Partition Button [2]
    {
      Fl_Return_Button *const o =
        new Fl_Return_Button(w - (WB + BB), y, BB, BH, "Partition");
      o->callback((Fl_Callback *)partition_partition_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->show();
  }

  dlg.window->end();
  dlg.window->hotspot(dlg.window);

  dlg.read_all_options();
  // Set the groups to be initally displayed
  dlg.read_all_options();
  partition_select_groups_cb(dlg.window, &dlg);
  dlg.window->show();
}

#else

void partition_dialog()
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
}

#endif

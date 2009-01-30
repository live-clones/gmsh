// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Stephen Guzik
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
#include "GUI.h"
#include "paletteWindow.h"
#include "GModel.h"
#include "Draw.h"
#include "Options.h"
#include "meshPartition.h"
#include "Context.h"

#if defined(HAVE_CHACO) || defined(HAVE_METIS)

// Forward declarations of some callbacks
void partition_opt_chaco_globalalg_cb(Fl_Widget *widget, void *data);
void partition_opt_architecture_cb(Fl_Widget *widget, void *data);
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data);
void partition_opt_spectralcheck_cb(Fl_Widget *widget, void *data);
void partition_select_groups_cb(Fl_Widget *widget, void *data);

// Pointers to required widgets
struct PartitionDialog
{
  Fl_Window *window;
  // Group 0
  Fl_Choice *choicePartitioner;
  Fl_Value_Input *inputNumPartition;
  // Group 1
  Fl_Choice *choiceChacoAlg;
  Fl_Toggle_Button *toggleButtonAdvChaco;
  // Group 2
  Fl_Choice *choiceArchitecture;
  Fl_Value_Input *inputNumPartition1;
  Fl_Value_Input *inputNumPartition2;
  Fl_Value_Input *inputNumPartition3;
  Fl_Choice *choiceDivisions;
  Fl_Value_Input *inputVMax;
  Fl_Choice *choiceEigensolver;
  Fl_Value_Input *inputEigtol;
  Fl_Choice *choiceLocalAlgorithm;
  Fl_Value_Input *inputSeed;
  Fl_Check_Button *checkButtonRefPart;
  Fl_Check_Button *checkButtonIntVert;
  Fl_Check_Button *checkButtonRefMap;
  Fl_Check_Button *checkButtonTermProp;
  // Group 3
  Fl_Choice *choiceMetisAlg;
  Fl_Toggle_Button *toggleButtonAdvMetis;
  // Group 4
  Fl_Choice *choiceEdgeMatch;
  Fl_Choice *choiceRefineAlg;
  void write_all_options()
  {
    // Group 0
    CTX::instance()->mesh.partition_options.partitioner = choicePartitioner->value() + 1;
    CTX::instance()->mesh.partition_options.num_partitions =
      static_cast<int>(inputNumPartition->value());

    // Group 1
    CTX::instance()->mesh.partition_options.global_method = choiceChacoAlg->value() + 1;

    // Group 2
    CTX::instance()->mesh.partition_options.architecture = choiceArchitecture->value();
    switch(CTX::instance()->mesh.partition_options.architecture) {
    case 0:
      CTX::instance()->mesh.partition_options.ndims_tot =
        static_cast<int>(inputNumPartition1->value());
      break;
    case 3:
      CTX::instance()->mesh.partition_options.mesh_dims[2] =
        static_cast<int>(inputNumPartition3->value());
    case 2:
      CTX::instance()->mesh.partition_options.mesh_dims[1] =
        static_cast<int>(inputNumPartition2->value());
    case 1:
      CTX::instance()->mesh.partition_options.mesh_dims[0] =
        static_cast<int>(inputNumPartition1->value());
      break;
    }
    CTX::instance()->mesh.partition_options.ndims = choiceDivisions->value() + 1;
    CTX::instance()->mesh.partition_options.vmax = static_cast<int>(inputVMax->value());
    CTX::instance()->mesh.partition_options.rqi_flag = choiceEigensolver->value();
    CTX::instance()->mesh.partition_options.eigtol = inputEigtol->value();
    CTX::instance()->mesh.partition_options.local_method = choiceLocalAlgorithm->value() + 1;
    CTX::instance()->mesh.partition_options.seed = static_cast<long>(inputSeed->value());
    CTX::instance()->mesh.partition_options.refine_partition = checkButtonRefPart->value();
    CTX::instance()->mesh.partition_options.internal_vertices = checkButtonIntVert->value();
    CTX::instance()->mesh.partition_options.refine_map = checkButtonRefMap->value();
    CTX::instance()->mesh.partition_options.terminal_propogation =
      checkButtonTermProp->value();
  
    // Group 3
    CTX::instance()->mesh.partition_options.algorithm = choiceMetisAlg->value() + 1;

    // Group 4
    CTX::instance()->mesh.partition_options.edge_matching = choiceEdgeMatch->value() + 1;
    CTX::instance()->mesh.partition_options.refine_algorithm = choiceRefineAlg->value() + 1;
  }
  void read_all_options()
  {
    // Group 0
    choicePartitioner->value(CTX::instance()->mesh.partition_options.partitioner - 1);
    inputNumPartition->value(CTX::instance()->mesh.partition_options.num_partitions);

    // Group 1
    choiceChacoAlg->value(CTX::instance()->mesh.partition_options.global_method - 1);

    // Group 2
    choiceArchitecture->value(CTX::instance()->mesh.partition_options.architecture);
    switch(CTX::instance()->mesh.partition_options.architecture) {
    case 0:
      inputNumPartition1->value(CTX::instance()->mesh.partition_options.ndims_tot);
      break;
    case 1:
      inputNumPartition1->value(CTX::instance()->mesh.partition_options.mesh_dims[0]);
      break;
    }
    inputNumPartition2->value(CTX::instance()->mesh.partition_options.mesh_dims[1]);
    inputNumPartition3->value(CTX::instance()->mesh.partition_options.mesh_dims[2]);
    choiceDivisions->value(CTX::instance()->mesh.partition_options.ndims - 1);
    inputVMax->value(CTX::instance()->mesh.partition_options.vmax);
    choiceEigensolver->value(CTX::instance()->mesh.partition_options.rqi_flag);
    inputEigtol->value(CTX::instance()->mesh.partition_options.eigtol);
    choiceLocalAlgorithm->value(CTX::instance()->mesh.partition_options.local_method - 1);
    inputSeed->value(CTX::instance()->mesh.partition_options.seed);
    checkButtonRefPart->value(CTX::instance()->mesh.partition_options.refine_partition);
    checkButtonIntVert->value(CTX::instance()->mesh.partition_options.internal_vertices);
    checkButtonRefMap->value(CTX::instance()->mesh.partition_options.refine_map);
    checkButtonTermProp->value(CTX::instance()->mesh.partition_options.terminal_propogation);
  
    // Group 3
    choiceMetisAlg->value(CTX::instance()->mesh.partition_options.algorithm - 1);

    // Group 4
    choiceEdgeMatch->value(CTX::instance()->mesh.partition_options.edge_matching - 1);
    choiceRefineAlg->value(CTX::instance()->mesh.partition_options.refine_algorithm - 1);

    // Call all callbacks to ensure consistent options
    partition_opt_chaco_globalalg_cb(choiceChacoAlg, this);
    partition_opt_architecture_cb(choiceArchitecture, this);
    partition_opt_num_partitions_cb(inputNumPartition, this);
    partition_opt_spectralcheck_cb(choiceDivisions, this);
  }
};

// Chaco option considerations based on the global algorithm
void partition_opt_chaco_globalalg_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  unsigned opt = dlg->choiceChacoAlg->value();
  if(opt == 0) {
    dlg->choiceLocalAlgorithm->value(0);
    dlg->choiceLocalAlgorithm->deactivate();
  }
  else {
    dlg->choiceLocalAlgorithm->activate();
  }
  if(opt == 1) {
    dlg->choiceEigensolver->value(1);
    dlg->choiceEigensolver->activate();
    if(dlg->choiceDivisions->value() != 0 &&
       dlg->checkButtonTermProp->value())
      dlg->choiceDivisions->value(0);
  }
  else {
    dlg->choiceEigensolver->deactivate();
  }
}

// Chaco option considerations based on the architecture
void partition_opt_architecture_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  switch(static_cast<int>(dlg->choiceArchitecture->value())) {
  case 0:
    dlg->inputNumPartition1->maximum(31);
    dlg->inputNumPartition2->deactivate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 1:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->deactivate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 2:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->activate();
    dlg->inputNumPartition3->deactivate();
    break;
  case 3:
    dlg->inputNumPartition1->maximum(std::numeric_limits<int>::max());
    dlg->inputNumPartition2->activate();
    dlg->inputNumPartition3->activate();
    break;
  }
  // Set topology dimensions from main number of partitions
  partition_opt_num_partitions_cb(dlg->inputNumPartition, data);
}

// Match several locations that provide a partition number
void partition_opt_num_partitions_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  unsigned val = 0;
  if(widget == dlg->inputNumPartition) {
    val = static_cast<unsigned>(dlg->inputNumPartition->value());
    switch(static_cast<int>(dlg->choiceArchitecture->value())) {
    case 0:
      {
        unsigned y = 0;
        unsigned x = val;
        while(x >>= 1) ++y;
        dlg->inputNumPartition1->value(y);
      }
      break;
    case 1:
    case 2:
    case 3:
      dlg->inputNumPartition1->value(val);
      dlg->inputNumPartition2->value(1);
      dlg->inputNumPartition3->value(1);
      break;
    }
  }
  else {
    switch(static_cast<int>(dlg->choiceArchitecture->value())) {
    case 0:
      {
        unsigned x = static_cast<unsigned>(dlg->inputNumPartition1->value());
        val = 1 << x;
      }
      break;
    case 1:
      val = static_cast<unsigned>(dlg->inputNumPartition1->value());
      break;
    case 2:
      val = static_cast<unsigned>
        (dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value());
      break;
    case 3:
      val = static_cast<unsigned>
        (dlg->inputNumPartition1->value()*dlg->inputNumPartition2->value()*
         dlg->inputNumPartition3->value());
      break;
    }
    dlg->inputNumPartition->value(val);
  }
  switch(dlg->choicePartitioner->value()) {
  case 0:
    if(val <= 3) {
      dlg->choiceDivisions->value(0);
      dlg->choiceDivisions->mode(1, FL_MENU_INACTIVE);
      dlg->choiceDivisions->mode(2, FL_MENU_INACTIVE);
    }
    else if(val <= 7) {
      if(dlg->choiceDivisions->value() > 1) dlg->choiceDivisions->value(1);
      dlg->choiceDivisions->mode(1, 0);
      dlg->choiceDivisions->mode(2, FL_MENU_INACTIVE);
    }
    else {
      dlg->choiceDivisions->mode(1, 0);
      dlg->choiceDivisions->mode(2, 0);
    }
    break;
  case 1:
    dlg->choiceMetisAlg->value((val <= 8) ? 0: 1);
    break;
  }
}

// Option considerations for the Chaco spectral algorithm
void partition_opt_spectralcheck_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  if(dlg->choiceChacoAlg->value() == 1) {
    if(widget == dlg->choiceDivisions && dlg->choiceDivisions->value() != 0)
      dlg->checkButtonTermProp->value(0);
    else if(widget == dlg->checkButtonTermProp)
      dlg->choiceDivisions->value(0);
  }
}

void partition_defaults_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  CTX::instance()->mesh.partition_options.setDefaults();
  dlg->read_all_options();
  partition_select_groups_cb(dlg->choicePartitioner, data);
}

void partition_partition_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);

  // Write all options
  dlg->write_all_options();

  // Partition the mesh
  int ier = PartitionMesh(GModel::current(), CTX::instance()->mesh.partition_options);

  // Update the screen
  if(!ier) {
    opt_mesh_zone_definition(0, GMSH_SET, 1.);  // Define zone by partition
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->mesh.changed = ENT_ALL;
    Draw();
  }
}

void partition_cancel_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  dlg->window->hide();
  Fl::delete_widget(dlg->window);
}

// Select groups to display
void partition_select_groups_cb(Fl_Widget *widget, void *data)
{
  PartitionDialog *dlg = static_cast<PartitionDialog*>(data);
  // If this callback was made by the "Advanced" toggle buttons, set the label
  if(dlg->toggleButtonAdvChaco == widget) {
    dlg->toggleButtonAdvChaco->label((dlg->toggleButtonAdvChaco->value()) ?
                                     "Advanced @-28->" : "Advanced @-22->");
  }
  else if(dlg->toggleButtonAdvMetis == widget) {
    dlg->toggleButtonAdvMetis->label((dlg->toggleButtonAdvMetis->value()) ?
                                     "Advanced @-28->" : "Advanced @-22->");
  }

  // Get the groups
  Fl_Widget *const *g = dlg->window->array();
  int y = g[0]->h();
  switch(dlg->choicePartitioner->value()) {
  case 0:
    g[1]->show();
    y += g[1]->h();
    if(dlg->toggleButtonAdvChaco->value()) {
      g[2]->show();
      y += g[2]->h();
    }
    else g[2]->hide();
    g[3]->hide();
    g[4]->hide();
    break;
  case 1:
    g[3]->show();
    y += g[3]->h();
    if(dlg->toggleButtonAdvMetis->value()) {
      g[4]->show();
      y += g[4]->h();
    }
    else g[4]->hide();
    g[1]->hide();
    g[2]->hide();
    break;
  }
  // Reset the vertical position of all widgets in group 6
  {
    int yG = y;
    g[5]->position(g[5]->x(), yG);
    Fl_Widget *o = static_cast<Fl_Group*>(g[5])->child(0);
    o->position(o->x(), yG);
    yG += WB + o->h();
    o = static_cast<Fl_Group*>(g[5])->child(1);
    o->position(o->x(), yG);
    o = static_cast<Fl_Group*>(g[5])->child(2);
    o->position(o->x(), yG);
    yG += WB + o->h();
  }
  y += g[5]->h();
  // Resize and redraw the window
  dlg->window->size(dlg->window->w(), y);
  dlg->window->redraw();
}

void partition_dialog()
{
  static PartitionDialog dlg;

  static Fl_Menu_Item partitionTypeMenu[] = {
    {"Chaco", 0, 0, 0},
    {"Metis", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chacoAlgMenu[] = {
    {"Multilevel-KL", 0, 0, 0},
    {"Spectral", 0, 0, 0},
    {"Inertial", 0, 0, 0, FL_MENU_INACTIVE},
    {"Linear", 0, 0, 0},
    {"Random", 0, 0, 0},
    {"Scattered", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisAlgMenu[] = {
    {"Recursive", 0, 0, 0},
    {"K-way", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoArchitectureMenu[] = {
    {"Hypercube", 0, 0, 0},
    {"1-D Mesh", 0, 0, 0},
    {"2-D Mesh", 0, 0, 0},
    {"3-D Mesh", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoLocalMethodMenu[] = {
    {"Kernighan-Lin", 0, 0, 0},
    {"None", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoEigSolMenu[] = {
    {"Lanczos", 0, 0, 0},
    {"Multilevel RQI/Symmlq", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item chachoDivisionsMenu[] = {
    {"Bisection", 0, 0, 0},
    {"Quadrisection", 0, 0, 0},
    {"Octasection", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisEdgeMatchingMenu[] = {
    {"Random", 0, 0, 0},
    {"Heavy-edge", 0, 0, 0},
    {"Sorted heavy-edge", 0, 0, 0},
    {0}
  };

  static Fl_Menu_Item metisRefineAlgMenu[] = {
    {"Random", 0, 0, 0},
    {"Greedy", 0, 0, 0},
    {"Random (Min. Conn.)", 0, 0, 0},
    {0}
  };

  const int h = 6 * WB + 3 * BH + 4;    // This will be resized based on groups
                                        // that are displayed
  const int w = 3 * BB + IW + 3 * WB;   // Window width
  int y = 0;

  dlg.window = new paletteWindow
    (w, h, CTX::instance()->non_modal_windows ? true : false, "Partitioner Options");
  dlg.window->box(GMSH_WINDOW_BOX);
  dlg.window->callback((Fl_Callback *)partition_cancel_cb, &dlg);

  // Main options group [0]
  {
    const int GH = BH + 2 + 3*WB;
    y += WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Partitioner
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Partitioner");
      dlg.choicePartitioner = o;
      o->menu(partitionTypeMenu);
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
#if !defined(HAVE_CHACO)
      o->mode(0, FL_MENU_INACTIVE);
#endif
#if !defined(HAVE_METIS)
      o->mode(1, FL_MENU_INACTIVE);
#endif
      o->align(FL_ALIGN_RIGHT);
    }
    // Number of partitions
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Number of\nPartitions");
      dlg.inputNumPartition = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    // Box (line)
    { Fl_Box* o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    g->end();
    g->show();
  }
  const int yMain = y;

  // Chaco options group [1]
  {
    const int GH = BH + WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, IW, BH, "Global Algorithm");
      dlg.choiceChacoAlg = o;
      o->menu(chacoAlgMenu);
      o->callback((Fl_Callback *)partition_opt_chaco_globalalg_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Advanced Button
    {
      Fl_Toggle_Button *const o = new Fl_Toggle_Button
        (w - (WB + BB), y, BB, BH, "Advanced @-22->");
      dlg.toggleButtonAdvChaco = o;
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Chaco advanced options group [2]
  {
    const int GH = 2 + WB + 5*(BH + WB) + BH + 6;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line)
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB + 1;  // +1 for multiline label
    // Architecture
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Architecture");
      dlg.choiceArchitecture = o;
      o->menu(chachoArchitectureMenu);
      o->callback((Fl_Callback *)partition_opt_architecture_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Mesh_dim1
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW/3, BH);
      dlg.inputNumPartition1 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Mesh_dim2
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + IW/3, y, IW/3, BH);
      dlg.inputNumPartition2 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Mesh_dim3
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB + 2*IW/3, y, IW/3, BH);
      dlg.inputNumPartition3 = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->callback((Fl_Callback *)partition_opt_num_partitions_cb, &dlg);
      o->step(1);
    }
    // Label
    {
      Fl_Box *const o = new Fl_Box
        (2*WB + 2*BB + IW, y, 0, BH, "Topology\ndimensions");
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    // Divisions
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Divisions");
      dlg.choiceDivisions = o;
      o->copy(chachoDivisionsMenu);
      o->callback((Fl_Callback *)partition_opt_spectralcheck_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    // Vmax
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Max. vertices in\ncoarse graph");
      dlg.inputVMax = o;
      o->minimum(2);
      o->maximum(std::numeric_limits<double>::max());
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 2;  // +2 for multiline labels
    // Eigensolver
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Eigensolver");
      dlg.choiceEigensolver = o;
      o->menu(chachoEigSolMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Eigtol
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Eigensolver\ntolerance");
      dlg.inputEigtol = o;
      o->minimum(std::numeric_limits<double>::min());
      o->maximum(std::numeric_limits<double>::max());
      o->step(5.E-3);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1;  // +1 for multiline label
    // Local method
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Local algorithm");
      dlg.choiceLocalAlgorithm = o;
      o->menu(chachoLocalMethodMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Seed
    {
      Fl_Value_Input *const o = new Fl_Value_Input
        (2*WB + 2*BB, y, IW, BH, "Seed");
      dlg.inputSeed = o;
      o->minimum(1);
      o->maximum(std::numeric_limits<int>::max());
      o->step(1);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    // Parameters
    {
      Fl_Check_Button *const o = new Fl_Check_Button
        (WB, y, 2*WB, BH, "Refine partition");
      dlg.checkButtonRefPart = o;
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button
        (2*WB + 2*BB, y, 2*WB, BH, "Internal vertices");
      dlg.checkButtonIntVert = o;
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH;
    {
      Fl_Check_Button *const o = new Fl_Check_Button
        (WB, y, 2*WB, BH, "Refine map");
      dlg.checkButtonRefMap = o;
      o->align(FL_ALIGN_RIGHT);
    }
    {
      Fl_Check_Button *const o = new Fl_Check_Button
        (2*WB + 2*BB, y, 2*WB, BH, "Terminal propogation");
      dlg.checkButtonTermProp = o;
      o->callback((Fl_Callback *)partition_opt_spectralcheck_cb, &dlg);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Metis options group [3]
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
      Fl_Toggle_Button *const o = new Fl_Toggle_Button
        (w - (WB + BB), y, BB, BH, "Advanced @-22->");
      dlg.toggleButtonAdvMetis = o;
      o->callback((Fl_Callback *)partition_select_groups_cb, &dlg);
    }
    y += BH + WB;
    g->end();
    g->hide();
  }

  // Metis advanced option group [4]
  {
    const int GH = 2 + WB + (BH + WB) + 2;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line)
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB + 1;  // +1 for multiline label
    // Edge matching algorithm
    {
      Fl_Choice *const o = new Fl_Choice(WB, y, BB, BH, "Edge matching");
      dlg.choiceEdgeMatch = o;
      o->menu(metisEdgeMatchingMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    // Refinement algorithm
    {
      Fl_Choice *const o = new Fl_Choice
        (2*WB + 2*BB, y, BB, BH, "Refinement\nalgorithm");
      dlg.choiceRefineAlg = o;
      o->menu(metisRefineAlgMenu);
      o->align(FL_ALIGN_RIGHT);
    }
    y += BH + WB + 1;  // +1 for multiline label
    g->end();
    g->hide();
  }
  
  // Dialog termination group [5]
  {
    const int GH = 2 + BH + 2*WB;
    Fl_Group *g = new Fl_Group(0, y, w, GH);
    // Box (line) [0]
    {
      Fl_Box *const o = new Fl_Box(WB, y, w - 2*WB, 2);
      o->box(FL_ENGRAVED_FRAME);
      o->labeltype(FL_NO_LABEL);
    }
    y += 2 + WB;
    // Defaults Button [1]
    {
      Fl_Button *const o = new Fl_Button
         (WB, y, BB, BH, "Defaults");
      o->callback((Fl_Callback *)partition_defaults_cb, &dlg);
    }
    // Partition Button [2]
    {
      Fl_Return_Button *const o = new Fl_Return_Button
        (w - (WB + BB), y, BB, BH, "Partition");
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
  partition_select_groups_cb(dlg.window, &dlg);
  dlg.window->show();
}

#else

void partition_dialog()
{
  Msg::Error("Gmsh has to be compiled with METIS or CHACO support to partition meshes");
}

#endif

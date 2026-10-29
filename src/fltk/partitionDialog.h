// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PARTITION_DIALOG_H
#define PARTITION_DIALOG_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Check_Button.H>

// The partitioning of the mesh: a tool window built once, which stays open so
// that partitions can be tried one after the other
class partitionWindow {
public:
  Fl_Window *win;
  // the least width of the window
  int width;
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

public:
  partitionWindow(int deltaFontSize = 0);
  ~partitionWindow()
  {
    if(win) Fl::delete_widget(win);
  }
  void write_all_options();
  void read_all_options();
  void show();
};

void partition_dialog();

#endif

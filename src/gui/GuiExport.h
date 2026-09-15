// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_EXPORT_H
#define GMSH_GUI_EXPORT_H

#include <functional>
#include <string>
#include <vector>

#include "GuiDialog.h"

// What an output format asks before the file is written, described once
// as a form and asked through whichever interface is up.

namespace Export {

  // Ask what the format takes, for the file of that name. `entry` is the
  // name of the line of the export chooser that was picked, for the two
  // pairs of lines that share a format and not a question: a POS file of
  // mesh statistics is not a POS file of views, and the X3D of a mesh is not
  // the X3D of a view. One of Gui::ExportCancelled, ExportGoAhead or
  // ExportDone.
  int askOptions(int format, const std::string &fileName,
                 const std::string &entry = "");

} // namespace Export

// The window that asks: one dialog for every format, described afresh for
// each question by the `fill` it is given. OK answers ExportDone when the
// form writes the file itself, ExportGoAhead otherwise; Cancel puts the
// options back to what they were when the window opened.
class GuiExport : public GuiDialog {
public:
  int ask(const std::string &title,
          const std::function<void(Ui::Form &, int &answer)> &fill);

protected:
  Ui::Form build() override;

private:
  std::string _title;
  std::function<void(Ui::Form &, int &)> _fill;
  int _answer = -1;
  // what the fields were worth when the window opened, for Cancel
  std::vector<Ui::Field> _fields;
  std::vector<double> _numbers;
  std::vector<std::string> _texts;
  bool _remembered = false;
};

#endif

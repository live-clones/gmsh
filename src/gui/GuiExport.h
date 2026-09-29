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


namespace Export {

  // entry names the line of the chooser picked, for the pairs of lines sharing
  // a format: a POS file of mesh statistics is not a POS file of views
  int askOptions(int format, const std::string &fileName,
                 const std::string &entry = "");

} // namespace Export

// one dialog for every format, described afresh by the fill it is given; Cancel
// puts the options back
class GuiExport : public GuiDialog {
public:
  int ask(const std::string &title, const std::function<Ui::Item()> &fill);

protected:
  Ui::Form build() override;

private:
  std::string _title;
  std::function<Ui::Item()> _fill;
  int _answer = -1;
  std::vector<Ui::Field> _fields;
  std::vector<double> _numbers;
  std::vector<std::string> _texts;
  bool _remembered = false;
};

#endif

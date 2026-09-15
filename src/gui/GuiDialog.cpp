// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <utility>

#include "GuiDialog.h"
#include "Gui.h"
#include "GmshMessage.h"

GuiDialog::~GuiDialog() { Gui::instance().dropForm(_form); }

void GuiDialog::refill()
{
  _retired = std::move(_form);
  _form = build();
  _form.tabbed = _tabbed;
}

void GuiDialog::show()
{
  if(Msg::GetThreadNum() > 0) return;
  load();
  refill();
  Gui::instance().showForm(_form, true);
}

void GuiDialog::hide() { Gui::instance().showForm(_form, false); }

bool GuiDialog::visible() const { return Gui::instance().formVisible(_form); }

void GuiDialog::reload()
{
  if(Msg::GetThreadNum() > 0) return;
  load();
  Gui::instance().reloadForm(_form);
}

void GuiDialog::rebuild()
{
  if(Msg::GetThreadNum() > 0) return;
  load();
  refill();
  Gui::instance().rebuildForm(_form);
}

void GuiTabbed::show(const std::string &pane)
{
  // the pane first: what load() reads may depend on it
  if(pane.size()) setPane(pane);
  GuiDialog::show();
}

std::string GuiTabbed::pane() const { return Gui::instance().formPane(form()); }

void GuiTabbed::setPane(const std::string &pane)
{
  Gui::instance().setFormPane(form(), pane);
}

#endif

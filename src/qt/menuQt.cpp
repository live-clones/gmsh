// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cctype>

#include "qtCommon.h"

#include <QAction>
#include <QCursor>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>

// The menus are QMenus made from the description. The shortcut is written
// after a tab, which Qt shows as one without making it one: the keys are read
// by the main window, off Sources::keys, as in the other interfaces. What is
// on and what is greyed is read again as each menu opens.

void qtLater(const std::function<void()> &what)
{
  QTimer::singleShot(0, [what]() {
    if(what) what();
  });
}

// --- keys

bool qtUiKey(int k, Qt::KeyboardModifiers m, const QString &text, int &key,
             unsigned &mods)
{
  mods = 0;
  // on macOS Qt calls Command Control: either is Ui's Command
  if(m & (Qt::ControlModifier | Qt::MetaModifier)) mods |= Ui::ModCommand;
  if(m & Qt::ShiftModifier) mods |= Ui::ModShift;
  if(m & Qt::AltModifier) mods |= Ui::ModAlt;
  key = 0;
  if(k >= Qt::Key_F1 && k <= Qt::Key_F12)
    key = Ui::KeyF1 + (k - Qt::Key_F1);
  else {
    switch(k) {
    case Qt::Key_Left: key = Ui::KeyLeft; break;
    case Qt::Key_Right: key = Ui::KeyRight; break;
    case Qt::Key_Up: key = Ui::KeyUp; break;
    case Qt::Key_Down: key = Ui::KeyDown; break;
    case Qt::Key_Escape: key = Ui::KeyEscape; break;
    case Qt::Key_Home: key = Ui::KeyHome; break;
    case Qt::Key_PageUp: key = Ui::KeyPageUp; break;
    case Qt::Key_PageDown: key = Ui::KeyPageDown; break;
    case Qt::Key_Delete:
    case Qt::Key_Backspace: key = Ui::KeyDelete; break;
    default: break;
    }
  }
  if(key) return true;
  if(k >= Qt::Key_A && k <= Qt::Key_Z) {
    key = 'A' + (k - Qt::Key_A);
    return true;
  }
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one)
  if(text.size() == 1) {
    ushort c = text[0].unicode();
    if(c > ' ' && c < 127) {
      key = c;
      mods &= ~Ui::ModShift;
      return true;
    }
  }
  if(k > ' ' && k < 127) {
    key = k;
    mods &= ~Ui::ModShift;
    return true;
  }
  return false;
}

// --- menus

namespace {

  // "&" marks the letter that opens the entry
  QString _label(const Ui::MenuItem &it)
  {
    std::string out;
    bool marked = false;
    for(char c : it.label) {
      if(c == '&') {
        out += "&&";
        continue;
      }
      if(!marked && it.mnemonic &&
         std::tolower((unsigned char)c) ==
           std::tolower((unsigned char)it.mnemonic)) {
        out += '&';
        marked = true;
      }
      out += c;
    }
    std::string shortcut = it.shortcut.label();
    if(shortcut.size()) out += "\t" + shortcut;
    return qtString(out);
  }

  // the switches and the greying of the entries of one menu, read as it opens
  struct entryState {
    QAction *action;
    std::function<bool()> enabled, checked;
  };

} // namespace

void qtFillMenu(QMenu *menu, const std::vector<Ui::MenuItem> &items)
{
  std::vector<entryState> *states = new std::vector<entryState>;
  QObject::connect(menu, &QObject::destroyed, [states]() { delete states; });
  QObject::connect(menu, &QMenu::aboutToShow, [states]() {
    for(auto &e : *states) {
      e.action->setEnabled(e.enabled ? e.enabled() : true);
      if(e.checked) e.action->setChecked(e.checked());
    }
  });
  for(const auto &it : items) {
    if(it.kind == Ui::MenuItem::Submenu) {
      QMenu *sub = menu->addMenu(_label(it));
      qtFillMenu(sub, it.children);
      states->push_back({sub->menuAction(), it.enabled, nullptr});
    }
    else {
      QAction *a = menu->addAction(_label(it));
      if(it.kind == Ui::MenuItem::Toggle) {
        a->setCheckable(true);
        a->setChecked(it.checked && it.checked());
      }
      a->setEnabled(it.enabled ? it.enabled() : true);
      std::function<void()> what = it.action;
      QObject::connect(a, &QAction::triggered, [what]() {
        qtLater([what]() {
          if(what) what();
          qtRefreshBar();
        });
      });
      states->push_back(
        {a, it.enabled,
         it.kind == Ui::MenuItem::Toggle ? it.checked : std::function<bool()>()});
    }
    if(it.dividerAfter) menu->addSeparator();
  }
}

void qtRefreshMenuBar(QMainWindow *window)
{
  static unsigned built = 0;
  static bool ever = false;
  if(!window || !qtSources().menuBar) return;
  unsigned generation =
    qtSources().menuGeneration ? qtSources().menuGeneration() : 0;
  if(ever && generation == built) return;
  ever = true;
  built = generation;
  QMenuBar *bar = window->menuBar();
  bar->clear();
  for(const auto &it : qtSources().menuBar()) {
    if(it.kind != Ui::MenuItem::Submenu) continue;
    QMenu *menu = bar->addMenu(_label(it));
    qtFillMenu(menu, it.children);
  }
}

void qtPopupMenu(const std::vector<Ui::MenuItem> &items)
{
  if(items.empty()) return;
  QMenu *menu = new QMenu;
  menu->setAttribute(Qt::WA_DeleteOnClose);
  qtFillMenu(menu, items);
  menu->popup(QCursor::pos());
}

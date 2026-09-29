// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef QT_COMMON_H
#define QT_COMMON_H

// signals, slots and emit are words Gmsh uses: Qt's are spelled out
#if !defined(QT_NO_KEYWORDS)
#define QT_NO_KEYWORDS
#endif

#include <functional>
#include <string>
#include <vector>

#include <QString>
#include <QtCore/qnamespace.h>

#include "Backend.h"
#include "Tree.h"

class QWidget;
class QMainWindow;
class QMenu;
class QTreeWidget;
class QTreeWidgetItem;

// What the files of the Qt 6 interface share: the descriptions it was handed,
// the menus, the widget of a field, the tree, and the scene the main window
// holds. Written without Q_OBJECT, so that nothing goes through moc: every
// connection is to a lambda. Nothing here calls Gmsh but the scene.

const Ui::Backend::Sources &qtSources();
const Ui::Backend::Host &qtHost();

inline QString qtString(const std::string &s)
{
  return QString::fromUtf8(s.c_str(), (int)s.size());
}
inline std::string qtString(const QString &s) { return s.toUtf8().toStdString(); }

// run once the event being handled is over: what it does may open a window,
// start a picking or build the widget it came from again
void qtLater(const std::function<void()> &what);

// held anywhere: the scene, and a value dragged in a dialog, ask
bool qtButtonDown();

// --- keys: false for a key Ui::Shortcut has no name for
bool qtUiKey(int qtKey, Qt::KeyboardModifiers qtMods, const QString &text,
             int &key, unsigned &mods);
// a key nothing took, in any window: the shortcuts of Sources::keys
bool qtMainKey(int qtKey, Qt::KeyboardModifiers qtMods, const QString &text);

// --- menus: every entry runs its action with qtLater()

void qtFillMenu(QMenu *menu, const std::vector<Ui::MenuItem> &items);
// the bar of the main window, made again when the description changed
void qtRefreshMenuBar(QMainWindow *window);
// at the pointer
void qtPopupMenu(const std::vector<Ui::MenuItem> &items);

// --- the size of the font of the interface, in pixels, which the widths the
// descriptions give are in
double qtEm();
int qtPx(double em);

// --- the widget of one field, bound to the place its value lives; `after`
// is what the holder does once the user changed something
QWidget *qtFieldWidget(const Ui::Field &field,
                       const std::function<void()> &after);
void qtRefreshField(QWidget *widget);
void qtRebindField(QWidget *widget, const Ui::Field &field);
QWidget *qtButtonWidget(const Ui::Button &button,
                        const std::function<void()> &after);

// --- a tree whose lines are fields (Tree.h): the modules, and a Hierarchy
// field, whose lines are switches

class treeQt {
public:
  treeQt(const Ui::Tree &tree, bool picks, const std::function<void()> &after);
  ~treeQt();
  QTreeWidget *widget() { return _view; }
  void setTree(const Ui::Tree &tree) { _tree = tree; }
  void refresh(bool rebuild);
  void open(const std::string &path, bool open);
  bool isOpen(const std::string &path) const;

private:
  Ui::Tree _tree;
  bool _picks;
  std::function<void()> _after;
  QTreeWidget *_view;
  unsigned _built;
  bool _everBuilt, _firstBuild, _quiet;
  std::vector<std::pair<std::string, bool> > _wanted;
  void _build();
  void _branch(QTreeWidgetItem *parent, const std::string &path);
  void _fill(QTreeWidgetItem *item);
  QTreeWidgetItem *_find(const std::string &path) const;
};

// --- the described forms, see dialogQt.cpp: each a QDockWidget, floating or
// docked in the main window

void qtShowForm(const Ui::Form &form, bool show);
bool qtFormVisible(const Ui::Form &form);
std::string qtFormPane(const Ui::Form &form);
void qtSetFormPane(const Ui::Form &form, const std::string &pane);
void qtReloadForm(const Ui::Form &form);
void qtDropForm(const Ui::Form &form);
void qtFormOptionChanged(const std::string &name);
void qtFormsClosingDown();
void qtSetMainWindow(QMainWindow *window);
QMainWindow *qtMainWindow();

// --- the scene, see SceneQt.cpp

QWidget *qtSceneWidget();
void qtSceneRedraw();
void qtSceneSize(int &width, int &height);
void qtSceneNewWindow();
void qtSceneDestroy();
void qtSceneStartTimers();
bool qtSceneDrawing();

void qtRefreshBar();

#endif

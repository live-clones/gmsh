// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_COMMON_H
#define IMGUI_COMMON_H

#include "GmshConfig.h"

#include <functional>
#include <string>
#include <vector>

#include "Backend.h"
#include "Form.h"
#include "Menu.h"

struct GLFWwindow;
struct ImFont;
class sceneView;

// What the files of the Dear ImGui interface share: the descriptions it was
// handed, the menus, the widget of a field, the tree, the forms, the file
// chooser and the scene the main window holds. Dear ImGui and GLFW, nothing
// else; nothing here calls Gmsh but the scene.

const Ui::Backend::Sources &imguiSources();
const Ui::Backend::Host &imguiHost();

// what the interface says of itself, to the console through the host
enum imguiLevel { imguiDebug = 0, imguiInfo, imguiWarning, imguiError };
void imguiReport(int level, const char *format, ...);

// a frame is not re-entrant: what may open a window, start a picking or pump
// frames of its own runs once the frame being built is over
void imguiLater(const std::function<void()> &what);
bool imguiInFrame();
// the frames that follow are drawn, the scene with them for the second
void imguiRequestFrame();
void imguiRequestRedraw();
// the loop woken up, from another thread too
void imguiWake();
// the scale of the interface, and what is left of it once the framebuffer's
// is taken out
float imguiUiScale();
float imguiStyleScale();
// a question or a file chooser being answered: the rest is disabled
bool imguiModal();

// --- the fonts, see fontsImGui.cpp: the one of the interface, and the line
// of the font over its em; the bold face for the headings, the slanted one
// for the words of prose that are, the one of fixed width for code; null
// without one
std::string imguiLoadFont(float &line);
ImFont *imguiBoldFont();
ImFont *imguiItalicFont();
ImFont *imguiFixedFont();

// --- menus: an entry runs its action with imguiLater()
void imguiMenu(const std::vector<Ui::MenuItem> &items);
void imguiDrawMenuBar();

// --- one described field, drawn where the cursor is: for the forms and for
// the lines of the tree; tall and indent as the form placed it
void imguiField(const Ui::Field &f, float width, float tall = 0.f,
                float indent = 0.f);
// what the forms borrow of the fields: a tab bar as wide as asked, the side
// of a check box, the height of prose in that width
bool imguiBeginTabBar(const char *id, float width);
float imguiCheckBoxSide();
float imguiProseHeight(const Ui::Field &f, float room);

// --- the tree of the modules, in a panel of its own
void imguiDrawTree();
void imguiShowTree(bool show);
bool imguiTreeShown();
void imguiOpenTreeItem(const std::string &path, bool open);
bool imguiTreeItemOpen(const std::string &path);

// --- the described forms, see dialogImGui.cpp: a window each, what they are
// made of asked at every frame
void imguiShowForm(const Ui::Form &form, bool show);
bool imguiFormVisible(const Ui::Form &form);
std::string imguiFormPane(const Ui::Form &form);
void imguiSetFormPane(const Ui::Form &form, const std::string &pane);
void imguiDropForm(const Ui::Form &form);
void imguiDrawForms();

// --- a file chooser on std::filesystem, the same on every platform; shown by
// the main window, which pumps frames until the user has chosen: from an
// action run with imguiLater()
class fileChooserImGui {
public:
  enum Mode { Open, Save };
  // naming the formats is what tells an exported view which flavour of a
  // shared extension was wanted
  struct format {
    std::string name, pattern;
  };

private:
  struct entry {
    std::string name;
    bool isDir;
    entry(const std::string &n, bool d) : name(n), isDir(d) {}
  };

  Mode _mode;
  std::string _title;
  std::string _directory;
  // the directory as it is being typed
  char _where[1024];
  char _fileName[1024];
  char _filter[256];
  std::vector<format> _formats;
  int _chosen;
  std::vector<entry> _entries;
  int _selected;
  bool _active, _done, _accepted;
  bool _needRescan, _hidden;
  std::string _message;

  void _rescan();

public:
  fileChooserImGui();
  // a pattern is a space separated list of extensions ("*.geo *.msh"), empty
  // for all
  void begin(Mode mode, const std::string &title,
             const std::vector<format> &formats,
             const std::string &initialName);
  int chosen() const { return _formats.size() > 1 ? _chosen : -1; }
  bool active() const { return _active; }
  bool done() const { return _done; }
  bool accepted() const { return _accepted; }
  std::string result() const;
  void finish() { _active = false; }
  void draw();
};

// --- the scene, see SceneImGui.cpp: its views on GuiPanes, started with the
// main window; placed in the central node, or alone in it in full screen
void imguiSceneStart(GLFWwindow *main);
void imguiSceneStop();
void imguiScenePlace(int x, int y, int w, int h, bool fullscreen);
// the pointer, unless outside the scene, from the state of Dear ImGui
void imguiScenePointer(bool outside);
// the views asked for drawn, all of them put on the window
void imguiSceneDraw();
// the graphic windows of their own
void imguiSceneWindows();
void imguiSceneRedraw();
void imguiSceneNewWindow();

#endif

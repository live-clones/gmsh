// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GUI_LISTENER_H
#define GUI_LISTENER_H

#include <string>

class drawContext;

// What the core tells a graphical user interface, if one runs, and asks it.
// The interface registers itself (SetGuiListener(): the FLTK graphical user
// interface in FlGui.cpp, the web page in webApp.cpp) and Gui() gives it, or a
// listener that does nothing. The core calls it, so that it knows nothing of
// a toolkit: the option functions of Options.cpp when an option is set for the
// interface (GMSH_GUI), the readers when a model or views came in, a script
// for the windows; what they ask is where the scene is, and what the desktop
// looks like.
class guiListener {
public:
  virtual ~guiListener() {}
  // the interface runs
  virtual bool running() { return false; }
  // the scene of the current window, whose point of view the options
  // General.Rotation/Quaternion/Translation/Scale are; null without one
  virtual drawContext *scene() { return nullptr; }
  // the desktop is dark (1) or light (0), or does not say (-1)
  virtual int desktopDark() { return -1; }
  // an option set for the interface (num is the view for an option of the
  // views), or all of them set again: the widgets that show them follow
  virtual void optionChanged(const std::string &category, int num,
                             const std::string &name)
  {
  }
  virtual void optionsChanged() {}
  // the sizes and places of the windows stored in the options, about to be
  // saved
  virtual void beforeOptionsSaved() {}
  // what the options that follow changed
  virtual void backgroundImageChanged() {}
  virtual void floatingToolsChanged() {}
  virtual void colorSchemeChanged() {}
  virtual void openglModeChanged() {} // the double buffer, antialiasing...
  virtual void shadersChanged() {}
  virtual void tooltipsChanged() {}
  virtual void mouseSelectionChanged() {}
  virtual void graphicSizeChanged() {}
  virtual void messageFontSizeChanged() {}
  virtual void menuAttachedChanged() {}
  virtual void menuWidthChanged() {}
  virtual void sceneTransformChanged() {} // the rotation, translation, scale
  virtual void clippingChanged() {}
  virtual void lightChanged() {}
  virtual void snapChanged() {}
  virtual void animationChanged() {}
  virtual void viewTimeStepChanged(int num) {}
  virtual void viewRenamed(int num) {}
  virtual void viewVisibilityChanged(int num) {}
  virtual void viewOpenedOrClosed(int num) {}
  virtual void viewColorMapChanged(int num) {} // -1: of all the views
  // views came or went (numberChanged) or changed, the mesh size fields
  // changed, the entities of the model changed, the ONELAB parameters changed
  virtual void viewsChanged(bool numberChanged) {}
  virtual void fieldsChanged() {}
  virtual void entitiesChanged() {}
  virtual void parametersChanged() {}
  // what a script or a solver asks: a module of the tree opened, the current
  // window set by its index, or split ('h', 'v', or 'u' to unsplit)
  virtual void openModule(const std::string &name) {}
  virtual void setCurrentWindow(int index) {}
  virtual void splitCurrentWindow(char how, double ratio) {}
};

// the listener of the interface that runs, or one that does nothing
guiListener *Gui();
void SetGuiListener(guiListener *listener);

// The engine that draws text, chosen by name (General.GraphicsFontEngine): a
// build with engines gives the function that makes them at startup (the FLTK
// build, see GmshGlobal.cpp), whether or not its interface runs, as a batch
// run draws too
void SetFontEngineMaker(void (*maker)(const std::string &engine));
void MakeFontEngine(const std::string &engine);

#endif

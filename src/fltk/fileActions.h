// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILE_ACTIONS_H
#define FILE_ACTIONS_H

#include <string>

class Fl_Menu_;

// What the File and Help menus of the FLTK graphical user interface do (see
// menuBar() in Actions.cpp and the table of fltkActions.cpp), and the reading
// and saving of the script and the mesh from the modules

// a new project: an empty script, made in a dialog
void fileNew();
// a project opened, or files merged into it, chosen in a dialog
void fileOpen();
void fileMerge();
// the recent file of index i (General.RecentFile<i>) opened
void fileOpenRecent(int i);
// the recent files as the submenu under path (File/Open Recent): the second
// one, the file opened before the current one, has a shortcut
void addRecentFiles(Fl_Menu_ *m, const std::string &path);
// the project cleared, then its file read again
void fileClear();
// the file of the project renamed, or deleted (then cleared)
void fileRename();
void fileDelete();
// the project exported in a format chosen in a dialog, with its options
void fileExport();
// the mesh saved in the default format (Mesh.Format) under the default name
void saveMesh();
// the options saved next to the model (.opt), or as the defaults of the user
void saveModelOptions();
void saveDefaultOptions();
// the session and the options saved as asked, then the interface closed (or
// the program ended)
void fileQuit();
// the watch pattern asked, then the files matching it merged
void fileWatch();
// the files matching the watch pattern that are not read yet merged
void mergeWatchedFiles();
// a remote Gmsh (the GmshRemote client of the ONELAB server): started,
// asked to merge a file, cleared, stopped
void remoteStart();
void remoteMerge();
void remoteClear();
void remoteStop();
// the script read again (through the ONELAB check when there is a solver)
void reloadScript();
// the script in the editor
void editScript();
// the project cleared and read again, solvers included
void reloadProject();
// the documentation in the browser, the keyboard and mouse usage, the current
// options and the workspace, and the about window
void helpOnline();
void helpKeys();
void helpCurrentOptions();
void helpAbout();

#endif

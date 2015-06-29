#ifndef _ONELAB_WINDOW_H_
#define _ONELAB_WINDOW_H_

class Fl_Window;
class Fl_Check_Button;
class Fl_Input;
class Fl_Choice;
class Fl_Browser;
class Fl_Button;

class onelabWindow{
 private:
  Fl_Check_Button *_listenOnUNIX, *_listenOnTCP, *_listenOnUDT;
  Fl_Input *_sockUNIX, *_sockTCP, *_sockUDT;

  Fl_Choice *_solvers;
  Fl_Browser *_clients;

  Fl_Check_Button *_useRemoteServer;
  Fl_Input *_remoteServer;
  Fl_Button *_connectRemoteServer;

 public:
  Fl_Window *win;

  onelabWindow(int deltaFontSize=0);
  void refresh();
  void refreshServers();
  void rebuildSolverList();
  void refreshRemoteServer();
};

void onelab2_cb(Fl_Widget *w, void *data);
#endif

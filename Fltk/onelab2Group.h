#ifndef _ONELAB2_GROUP_H_
#define _ONELAB2_GROUP_H_

#include <vector>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Input.H>
#include "NetworkUtils.h"
#include "onelab.h"

class viewButton;

class onelabGroup : public Fl_Group{
private:
  Fl_Input *server_ip, *server_port;
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  int _gearOptionsStart, _gearOptionsEnd;
  std::vector<Fl_Widget*> _treeWidgets;
  std::vector<char*> _treeStrings;
  bool _stop;
  int _baseWidth, _indent;
  int _minWindowWidth, _minWindowHeight;
  double _widgetLabelRatio;
  std::set<std::string> _manuallyClosed;
  bool _enableTreeWidgetResize;

  Fl_Widget *_addParameterWidget(onelab::parameter &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::number &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::string &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::function &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::region &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c);
  void _computeWidths();
  void _addMenu(const std::string &path, Fl_Callback *callback, void *data);
  void _addSolverMenu(int num);
  void _addViewMenu(int num);
  std::set<std::string> _getClosedGmshMenus();
  void _addGmshMenus();

public:
  onelabGroup(int x, int y, int w, int h, const char *l=0);
  ~onelabGroup();
  void updateGearMenu();
  void rebuildSolverList();
  void rebuildTree(bool deleteWidgets){} // useless in ONELAB2 ?
  void enableTreeWidgetResize(bool value){ _enableTreeWidgetResize = value; }
  void clearTree(bool deleteWidgets=true);
  void openTreeItem(const std::string &name);
  void createRemoteTree(bool keepLocal=true);
  UInt32 getServerIP() {return ip4_inet_pton(server_ip->value());}
  UInt16 getServerPort() {return (UInt16)strtoul(server_port->value(), NULL, 0);}
  bool useServer();
  void useServer(bool);
  bool isBusy();
  int getMinWindowWidth(){ return _minWindowWidth; }
  int getMinWindowHeight(){ return _minWindowHeight; }
  //template <class T> void addParameter(T &p);
  void addParameter(onelab::parameter &p);
  void updateParameter(onelab::parameter &p);
  void updateParameter(onelab::number &p);
  void updateParameter(onelab::string &p);
  void removeParameter(onelab::parameter &p);
  std::string getPath(Fl_Tree_Item *item);
  void insertInManuallyClosed(const std::string &path)
  {
    _manuallyClosed.insert(path);
  }
  void removeFromManuallyClosed(const std::string &path)
  {
    _manuallyClosed.erase(path);
  }
  bool isManuallyClosed(const std::string &path)
  {
    return _manuallyClosed.find(path) != _manuallyClosed.end();
  }
  viewButton *getViewButton(int num);
};

void connect_cb(Fl_Widget *w, void *arg);
void onelab_cb(Fl_Widget *w, void *data);
inline void onelab_cb(void *data) {onelab_cb(0, data);}
void solver_cb(Fl_Widget *w, void *data);
void solver_batch_cb(Fl_Widget *w, void *data);
#endif

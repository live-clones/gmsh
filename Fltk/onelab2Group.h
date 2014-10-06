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

class onelab2Group : public Fl_Group{
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

public:
  onelab2Group(int x, int y, int w, int h, const char *l=0);
  ~onelab2Group();
  void clearTree(bool deleteWidgets=true);
  void createRemoteTree(bool keepLocal=true);
  UInt32 getServerIP() {return ip4_inet_pton(server_ip->value());}
  UInt16 getServerPort() {return (UInt16)strtoul(server_port->value(), NULL, 0);}
  template <class T> void addParameter(T &p);
  void updateParameter(onelab::parameter &p);
  void updateParameter(onelab::number &p);
  void updateParameter(onelab::string &p);
  void removeParameter(onelab::parameter &p);
  std::string getPath(Fl_Tree_Item *item);
};

void connect_cb(Fl_Widget *w, void *arg);
#endif

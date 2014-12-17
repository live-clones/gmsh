#include "onelab2Group.h"

#include "FlGui.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Item.H>
#include "inputRange.h"
#include "outputRange.h"
#include "inputRegion.h"
#include "drawContext.h"
#include "viewButton.h"
#include "solverButton.h"

#include "Gmsh.h"
#include "onelabUtils.h"
#include "OnelabDatabase.h"
#include "Options.h"
#include "Context.h"

static void initializeLoops()
{
  onelabUtils::initializeLoop("1");
  onelabUtils::initializeLoop("2");
  onelabUtils::initializeLoop("3");

  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);
}

static bool incrementLoops()
{
  bool ret = (onelabUtils::incrementLoop("3") ||
    onelabUtils::incrementLoop("2") ||
    onelabUtils::incrementLoop("1"));

  //Define ONELAB parameter indicating whether or not in a loop
  onelab::number n("0Metamodel/Loop",ret?1:0);
  n.setVisible(false);
  onelab::server::instance()->set(n);

  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree(false);

  return ret;
}

static void updateGraphs()
{
  bool redraw = false;
  for(int i = 0; i < 18; i++){
    std::ostringstream tmp;
    tmp << i;
    bool ret = onelabUtils::updateGraph(tmp.str());
    redraw = redraw || ret;
  }
  if(redraw){
    // don't delete the widgets, as this is called in widget callbacks
    FlGui::instance()->updateViews(true, false);
    drawContext::global()->draw();
  }
}

void connect_cb(Fl_Widget *w, void *arg)
{
  if(!arg) return;
  onelabGroup *obj = (onelabGroup *)arg;
  if(strcmp(w->label(), "Connect") == 0) {
    if(!obj->useServer()) return;
    obj->clearTree();
    GmshNetworkClient *cli = OnelabDatabase::instance()->useAsNetworkClient(obj->getServerIP(), obj->getServerPort());
    cli->setCallback(obj);
    w->label("Disconnect");
  }
  else {
    obj->clearTree();
    OnelabDatabase::instance()->useAsClient()->setCallback(obj);
    w->label("Connect");
  }
}

void useserver_cb(Fl_Widget *w, void *arg)
{
  if(!arg) return;
  Fl_Check_Button *checkbox = (Fl_Check_Button *)w;
  onelabGroup *obj = (onelabGroup *)arg;
  obj->useServer(checkbox->value() == 1);
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;

  std::string action((const char*)data);

  if(action == "refresh"){
    updateGraphs();
    return;
  }

  if(action == "stop"){
    // TODO
    return;
  }

  if(action == "kill"){
    // TODO
    return;
  }

  if(FlGui::instance()->onelab->isBusy()){
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  Msg::Info("Try to %s", action.c_str());
  
  if(action == "reset"){
    //TODO resetDb(true);
    action = "check";
  }

  Msg::ResetErrorCounter();

  //TODO FlGui::instance()->onelab->setButtonMode("", "stop");

  if(action == "compute") initializeLoops();

  do{
    //OnelabDatabase::instance()->run("Gmsh", action);
    OnelabDatabase::instance()->run(action);
  } while(action == "compute"
          //&& !FlGui::instance()->onelab->stop()
          && incrementLoops());
}


void solver_cb(Fl_Widget *w, void *data)
{
  if(!FlGui::instance()->onelab) return;

  int num = (intptr_t)data;
  if(num >= 0){
    std::string name = opt_solver_name(num, GMSH_GET, "");
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    std::string host = opt_solver_remote_login(num, GMSH_GET, "");
    OnelabDatabase::instance()->run("initialize", name);
  }
  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else{
    if(CTX::instance()->solverToRun >= 0){
      onelab_cb(0, (void*)"reset");
      onelabUtils::setFirstComputationFlag(true);
    }
    else if(num >= 0) {
      onelab_cb(0, (void*)"check");
    }
    else {
      onelab_cb(0, (void*)"refresh");
    }
    FlGui::instance()->onelab->updateGearMenu();
  }
}
void solver_batch_cb(Fl_Widget *w, void *data)
{
  // TODO
}

static bool getFlColor(const std::string &str, Fl_Color &c)
{
  if(str == "1"){
    c = FL_YELLOW;
    return true;
  }
  int r, g, b;
  if(str.size() && GetRGBForString(str.c_str(), r, g, b)){
    c = fl_color_cube(r * (FL_NUM_RED - 1) / 255,
                      g * (FL_NUM_GREEN - 1) / 255,
                      b * (FL_NUM_BLUE - 1) / 255);
    return true;
  }
  c = FL_BLACK;
  return false;
}

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x, y, w, h, l), _stop(false), _enableTreeWidgetResize(false)
{
  int col = FL_BACKGROUND2_COLOR;
  color(col);

  box(GMSH_SIMPLE_RIGHT_BOX);
  int dx = Fl::box_dx(box());
  int dy = Fl::box_dy(box());
  int dw = Fl::box_dw(box());
  int dh = Fl::box_dh(box());

  _tree = new Fl_Tree(x + dx, y + dy + 6*BH, w - dw, h - dh - BH - 2 * WB - 6*BH);
  _tree->color(col);
  // TODO _tree->callback(onelab_tree_cb);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);
  _tree->box(FL_FLAT_BOX);
  _tree->scrollbar_size(std::max(10, FL_NORMAL_SIZE - 2));
  _tree->end();

  int BB2 = BB / 2 + 4;
  _butt[0] = new Fl_Button(x + w - 3 * WB - 3 * BB2, y + h - WB - BH, BB2, BH, "Check");
  _butt[0]->callback(onelab_cb, (void*)"check");

  _butt[1] = new Fl_Button(x + w - 2 * WB - 2 * BB2, y + h - WB - BH, BB2, BH, "Run");
  _butt[1]->callback(onelab_cb, (void*)"compute");

  Fl_Check_Button *useServer = new Fl_Check_Button(x+WB, y, w-2*WB, BH, "Use a remote server");
  useServer->callback(useserver_cb, this);
  /*Fl_Box *ip_lbl = */new Fl_Box(x+WB , y+BH, w-2*WB, BH, "Server IP address:");
  server_ip = new Fl_Input(x+WB, y+2*BH, w-2*WB, BH, "");
  server_ip->value("127.0.0.1");
  server_ip->readonly(true);
  /*Fl_Box *port_lbl = */new Fl_Box(x+WB , y+3*BH, w-2*WB, BH, "Server port:");
  server_port = new Fl_Input(x+WB, y+4*BH, w-2*WB, BH, "");
  server_port->value("1148");
  server_port->readonly(true);
  Fl_Button *connect_btn = new Fl_Button(x+WB, y+5*BH, w-2*WB, BH, "Connect");
  connect_btn->callback(connect_cb, this);

  _computeWidths();
  _widgetLabelRatio = 0.48;
  OnelabDatabase::instance()->useAsClient()->setCallback(this);
}
onelabGroup::~onelabGroup()
{
  Fl::delete_widget(_tree);
}

void onelabGroup::clearTree(bool deleteWidgets)
{
  _tree->clear();
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  std::vector<Fl_Widget*> delWidgets;
  std::vector<char*> delStrings;
  if(deleteWidgets){
    delWidgets = _treeWidgets;
    delStrings = _treeStrings;
    _treeWidgets.clear();
    _treeStrings.clear();
   }
  FlGui::check();
  if(deleteWidgets){
    for(unsigned int i = 0; i < delWidgets.size(); i++)
      Fl::delete_widget(delWidgets[i]);
    for(unsigned int i = 0; i < delStrings.size(); i++)
      free(delStrings[i]);
  }
}

void onelabGroup::openTreeItem(const std::string &name)
{
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if(n && n->has_children()){
    n->open();
    _tree->redraw();
  }
}

void onelabGroup::updateGearMenu()
{
  return; // TODO
  Fl_Menu_Item* menu = (Fl_Menu_Item*)_gear->menu();
  int values[8] = {CTX::instance()->solver.autoSaveDatabase,
                   CTX::instance()->solver.autoArchiveOutputFiles,
                   CTX::instance()->solver.autoCheck,
                   CTX::instance()->solver.autoMesh,
                   CTX::instance()->solver.autoMergeFile,
                   CTX::instance()->solver.autoShowViews,
                   CTX::instance()->solver.autoShowLastStep,
                   CTX::instance()->solver.showInvisibleParameters};
  for(int i = 0; i < 8; i++){
    int idx = _gearOptionsStart - 1 + i;
    if(values[i])
      menu[idx].set();
    else
      menu[idx].clear();
  }
}

void onelabGroup::rebuildSolverList()
{
  updateGearMenu();

  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < NUM_SOLVERS; i++){
    if(opt_solver_name(i, GMSH_GET, "").size()){
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(unsigned int i = 0; i < NUM_SOLVERS; i++){
    if(i < names.size()){
      onelab::server::citer it = onelab::server::instance()->findClient(names[i]);
      if(it != onelab::server::instance()->lastClient())
        it->second->setIndex(i);
      opt_solver_name(i, GMSH_SET, names[i]);
      opt_solver_executable(i, GMSH_SET, exes[i]);
      opt_solver_remote_login(i, GMSH_SET, hosts[i]);
    }
    else{
      opt_solver_name(i, GMSH_SET, "");
      opt_solver_executable(i, GMSH_SET, "");
      opt_solver_remote_login(i, GMSH_SET, "");
    }
  }

  //TODO setButtonVisibility();
  rebuildTree(true);
}
bool onelabGroup::useServer() {return !server_ip->readonly();}
void onelabGroup::useServer(bool use=false)
{
  server_ip->readonly(!use);
  server_port->readonly(!use);
}

void onelabGroup::addParameter(onelab::parameter &p)
{
  if(!p.getVisible() || CTX::instance()->solver.showInvisibleParameters) return;
  bool highlight = false;
  Fl_Color c;
  if(getFlColor(p.getAttribute("Highlight"), c)) highlight = true;
  Fl_Tree_Item *n = _tree->add(p.getName().c_str());
  n->labelsize(FL_NORMAL_SIZE + 4);
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  ww *= _widgetLabelRatio; // FIXME CHANGE THIS
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Widget *widget = _addParameterWidget(p, ww, hh, n, highlight, c);
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  widget->copy_label(p.getShortName().c_str());
  std::string help = p.getLabel().size() ? p.getLabel() : p.getShortName();
  if(p.getHelp().size()) help += ":\n" + p.getHelp();
  widget->copy_tooltip(help.c_str());
  n->widget(grp);
  _tree->end();
  _tree->redraw();
}
Fl_Widget *onelabGroup::_addParameterWidget(onelab::parameter &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  int type = p.getAttributeType();
  if(type == onelab::number::attributeType())
      return _addParameterWidget(*(onelab::number *)&p, ww, hh, n, highlight, c);
  if(type == onelab::string::attributeType())
      return _addParameterWidget(*(onelab::string *)&p, ww, hh, n, highlight, c);
  if(type == onelab::region::attributeType())
      return _addParameterWidget(*(onelab::region *)&p, ww, hh, n, highlight, c);
  if(type == onelab::function::attributeType())
      return _addParameterWidget(*(onelab::function *)&p, ww, hh, n, highlight, c);
  return NULL;
}

template<class T>
static void autoCheck(const T &pold, const T &pnew, bool force=false)
{
  if(onelabUtils::getFirstComputationFlag()){
    if(pold.getValue() != pnew.getValue())
      onelabUtils::setFirstComputationFlag(false);
  }

  if((CTX::instance()->solver.autoCheck && pnew.getAttribute("AutoCheck") != "0") ||
     pnew.getAttribute("AutoCheck") == "1"){
    if(force || pold.getValue() != pnew.getValue())
      onelab_cb(0, (void*)"check");
  }
}

template <class T>
static void setGmshOption(T &n)
{
  std::string opt = n.getAttribute("GmshOption");
  if(opt.empty()) return;
  /*if(opt == "ResetDatabase"){ // special option to reset the onelab db
    resetDb(false);
    FlGui::instance()->rebuildTree(false);
    return;
  }
  if(opt == "Reset"){ // reset db + models except current one
    resetDb(false);
    for(int i = PView::list.size() - 1; i >= 0; i--)
      delete PView::list[i];
    for(int i = GModel::list.size() - 1; i >= 0; i--)
      if(GModel::list[i] != GModel::current()) delete GModel::list[i];
    FlGui::instance()->rebuildTree(false);
    return;
  }*/
  std::string::size_type dot = opt.find('.');
  if(dot == std::string::npos) return;
  GmshSetOption(opt.substr(0, dot), opt.substr(dot + 1), n.getValue());
  drawContext::global()->draw();
}

// callback for number
static void onelab_number_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  OnelabDatabase::instance()->get(numbers, name);
  if(numbers.size()){
    inputRange *o = (inputRange*)w;
    onelab::number old = numbers[0];
    if(o->doCallbackOnValues()){
      numbers[0].setValue(o->value());
      numbers[0].setMin(o->minimum());
      numbers[0].setMax(o->maximum());
      numbers[0].setStep(o->step());
      numbers[0].setChoices(o->choices());
    }
    o->doCallbackOnValues(true);
    numbers[0].setAttribute("Loop", o->loop());
    numbers[0].setAttribute("Graph", o->graph());
    setGmshOption(numbers[0]);
    OnelabDatabase::instance()->set(numbers[0], std::string("localGUI"));
    updateGraphs();
    autoCheck(old, numbers[0]);
  }
}
static void onelab_number_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  OnelabDatabase::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Choice *o = (Fl_Choice*)w;
    std::vector<double> choices = numbers[0].getChoices();
    onelab::number old = numbers[0];
    if(o->value() < (int)choices.size()) numbers[0].setValue(choices[o->value()]);
    setGmshOption(numbers[0]);
    OnelabDatabase::instance()->set(numbers[0], std::string("localGUI"));
    autoCheck(old, numbers[0]);
  }
}
static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::number> numbers;
  OnelabDatabase::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Check_Button *o = (Fl_Check_Button*)w;
    onelab::number old = numbers[0];
    numbers[0].setValue(o->value());
    setGmshOption(numbers[0]);
    OnelabDatabase::instance()->set(numbers[0], std::string("localGUI"));
    autoCheck(old, numbers[0]);
  }
}
// add a parameter number to the tree
Fl_Widget *onelabGroup::_addParameterWidget(onelab::number &p, int ww, int hh, Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()){
    Fl_Choice *but = new Fl_Choice(1, 1, ww, hh);
    std::vector<Fl_Menu_Item> menu;
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::map<double, std::string>::iterator it = labels.begin();
        it != labels.end(); it++){
      char *str = strdup(it->second.c_str());
      _treeStrings.push_back(str);
      Fl_Menu_Item menuItem = {str, 0, 0, 0, 0};
      if(highlight) menuItem.labelcolor(c);
      menu.push_back(menuItem);
    }
    Fl_Menu_Item it = {0};
    menu.push_back(it);
    but->copy(&menu[0]);
    for(unsigned int i = 0; i < p.getChoices().size(); i++){
      if(p.getValue() == p.getChoices()[i]){
        but->value(i);
        break;
      }
    }
    but->callback(onelab_number_choice_cb, (void*)path);
    but->align(FL_ALIGN_RIGHT);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 &&
     p.getChoices()[0] == 0 && p.getChoices()[1] == 1){
    n->labelsize(FL_NORMAL_SIZE + 2);
    Fl_Check_Button *but = new Fl_Check_Button(1, 1, ww / _widgetLabelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(_tree->color());
    but->value(p.getValue());
    but->callback(onelab_number_check_button_cb, (void*)path);
    if(highlight) but->color(c);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // non-editable value
  if(p.getReadOnly()){
    outputRange *but = new outputRange(1, 1, ww, hh);
    //TODO but->callback(onelab_number_output_range_cb, (void*)path);
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT);
    but->graph(p.getAttribute("Graph"));
    if(highlight) but->color(c);
    return but;
  }

  // general number input
  inputRange *but = new inputRange(1, 1, ww, hh, onelab::parameter::maxNumber(),
                                   p.getAttribute("ReadOnlyRange") == "1");
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void*)path);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->color(c);
  return but;
}
// callback for string
static void onelab_string_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char*)data);
  std::vector<onelab::string> strings;
  OnelabDatabase::instance()->get(strings, name);
  if(strings.size()){
    Fl_Input_Choice *o = (Fl_Input_Choice*)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
    std::string choices;
    for(int i = 0; i < o->menubutton()->menu()->size(); i++){
      if(o->menubutton()->menu()[i].flags & FL_MENU_TOGGLE){
        if(o->menubutton()->menu()[i].flags & FL_MENU_VALUE)
          choices += "1";
        else
          choices += "0";
      }
    }
    if(choices.size())
      strings[0].setAttribute("MultipleSelection", choices);
    //setGmshOption(strings[0]);
    OnelabDatabase::instance()->set(strings[0], "localGUI");
    autoCheck(old, strings[0]);
  }
}
// add parameter string to tree
Fl_Widget *onelabGroup::_addParameterWidget(onelab::string &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // macro button
  if(p.getAttribute("Macro") == "Gmsh"){
    Fl_Button *but = new Fl_Button(1, 1, ww / _widgetLabelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(_tree->color());
    but->selection_color(_tree->color());
    but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    //TODO but->callback(onelab_string_button_cb, (void*)path);
    if(highlight) but->color(c);
    return but;
  }

  // non-editable value
  if(p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, ww, hh);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // simple string (no menu)
  if(p.getChoices().empty() && p.getKind() != "file"){
    Fl_Input *but = new Fl_Input(1, 1, ww, hh);
    but->value(p.getValue().c_str());
    //TODO but->callback(onelab_string_input_cb, (void*)path);
    but->when(FL_WHEN_ENTER_KEY);
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  // general string input
  Fl_Input_Choice *but = new Fl_Input_Choice(1, 1, ww, hh);
  std::string multipleSelection = p.getAttribute("MultipleSelection");
  if(multipleSelection.size())
    ;//but->menubutton()->callback(multiple_selection_menu_cb, but);
  std::vector<Fl_Menu_Item> menu;
  for(unsigned int j = 0; j < p.getChoices().size(); j++){
    char *str = strdup(p.getChoices()[j].c_str());
    _treeStrings.push_back(str);
    bool divider = (p.getKind() == "file" &&
                    j == p.getChoices().size() - 1);
    int choice = multipleSelection.size() ? FL_MENU_TOGGLE : 0;
    if(multipleSelection.size() > j && multipleSelection[j] == '1')
      choice |= FL_MENU_VALUE;
    Fl_Menu_Item it = {str, 0, 0, 0, divider ? FL_MENU_DIVIDER : choice};
    menu.push_back(it);
  }
  //if(p.getKind() == "file"){
  //  Fl_Menu_Item it = {"Choose...", 0, onelab_input_choice_file_chooser_cb, (void*)n};
  //  menu.push_back(it);
  //  Fl_Menu_Item it2 = {"Edit...", 0, onelab_input_choice_file_edit_cb, (void*)n};
  //  menu.push_back(it2);
  //  if(GuessFileFormatFromFileName(p.getValue()) >= 0){
  //    Fl_Menu_Item it3 = {"Merge...", 0, onelab_input_choice_file_merge_cb, (void*)n};
  //    menu.push_back(it3);
  //  }
  //}
  Fl_Menu_Item it = {0};
  menu.push_back(it);
  but->menubutton()->copy(&menu[0]);
  but->value(p.getValue().c_str());
  but->callback(onelab_string_input_choice_cb, (void*)path);
  but->input()->when(FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT);
  if(highlight) but->input()->color(c);
  return but;
}
Fl_Widget *onelabGroup::_addParameterWidget(onelab::region &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  char *path = strdup(getPath(n).c_str());
  _treeStrings.push_back(path);

  // non-editable value
  if(p.getReadOnly()){
    inputRegion *but = new inputRegion(1, 1, ww, hh, true);
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }

  inputRegion *but = new inputRegion(1, 1, ww, hh, false);
  but->value(p.getValue());
  but->align(FL_ALIGN_RIGHT);
  //TODO but->callback(onelab_region_input_cb, (void*)path);
  if(highlight) but->color(c);
  return but;
}

Fl_Widget *onelabGroup::_addParameterWidget(onelab::function &p, int ww, int hh,
                                            Fl_Tree_Item *n, bool highlight, Fl_Color c)
{
  // non-editable value
  if(1 || p.getReadOnly()){
    Fl_Output *but = new Fl_Output(1, 1, ww, hh);
    but->value("TODO function");
    but->align(FL_ALIGN_RIGHT);
    if(highlight) but->color(c);
    return but;
  }
}

void onelabGroup::updateParameter(onelab::parameter &p)
{
  int type = p.getAttributeType();
  if(type == onelab::number::attributeType())
      return updateParameter(*(onelab::number *)&p);
  if(type == onelab::string::attributeType())
      return updateParameter(*(onelab::string *)&p);
}
void onelabGroup::updateParameter(onelab::number &p)
{
  Fl_Tree_Item *n = _tree->find_item(p.getName().c_str());
  if(!n) {
    addParameter(p);
    return;
  }
  Fl_Group *grp = (Fl_Group *)n->widget();
  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()){
    Fl_Choice *but = (Fl_Choice *)grp->child(0);
    //std::vector<Fl_Menu_Item> menu;
    //std::map<double, std::string> labels(p.getValueLabels());
    //for(std::map<double, std::string>::iterator it = labels.begin();
    //    it != labels.end(); it++){
    //  char *str = strdup(it->second.c_str());
    //  _treeStrings.push_back(str);
    //  Fl_Menu_Item menuItem = {str, 0, 0, 0, 0};
    //  if(highlight) menuItem.labelcolor(c);
    //  menu.push_back(menuItem);
    //}
    //Fl_Menu_Item it = {0};
    //menu.push_back(it);
    //but->copy(&menu[0]);
    for(unsigned int i = 0; i < p.getChoices().size(); i++){
      if(p.getValue() == p.getChoices()[i]){
        but->value(i);
        break;
      }
    }
    return;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 &&
     p.getChoices()[0] == 0 && p.getChoices()[1] == 1){
    Fl_Check_Button *but = (Fl_Check_Button *)grp->child(0);
    but->value(p.getValue());
    return;
  }

  // non-editable value FIXME
  if(p.getReadOnly()){
    outputRange *but = (outputRange *)grp->child(0);;
    but->value(p.getValue());
    but->graph(p.getAttribute("Graph"));
    return;
  }

  // general number input
  inputRange *but = (inputRange *)grp->child(0);
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
}
void onelabGroup::updateParameter(onelab::string &p)
{
  Fl_Tree_Item *n = _tree->find_item(p.getName().c_str());
  if(!n) {
    addParameter(p);
    return;
  }
  Fl_Group *grp = (Fl_Group *)n->widget();
  // macro button
  if(p.getAttribute("Macro") == "Gmsh"){
    return;
  }

  // non-editable value FIXME
  if(p.getReadOnly()){
    Fl_Output *but = (Fl_Output *)grp->child(0);
    but->value(p.getValue().c_str());
    return;
  }

  // simple string (no menu)
  if(p.getChoices().empty() && p.getKind() != "file"){
    Fl_Input *but = (Fl_Input *)grp->child(0);
    but->value(p.getValue().c_str());
    return;
  }

  // general string input TODO
  Fl_Input_Choice *but = (Fl_Input_Choice *)grp->child(0);
  but->value(p.getValue().c_str());
}

void onelabGroup::removeParameter(onelab::parameter &p)
{
  Fl_Tree_Item *n = _tree->find_item(p.getName().c_str());
  _tree->remove(n);
}

void onelabGroup::_computeWidths()
{
  _baseWidth = (int)(_tree->w() - _tree->marginleft());
  _indent = (int)(_tree->connectorwidth() / 2. + _tree->openicon()->w() / 2.);
}

bool onelabGroup::isBusy()
{
  std::string s(_butt[1]->label());
  if(s == "Run") return false;
  return true;
}

std::string onelabGroup::getPath(Fl_Tree_Item *item)
{
  if(!item){
    Msg::Error("No item for path");
    return "";
  }
  char path[1024];
  if(_tree->item_pathname(path, sizeof(path), item)){
    Msg::Error("Could not get path for item");
    return "";
  }
  return std::string(path);
}

void onelabGroup::_addMenu(const std::string &path, Fl_Callback *callback, void *data)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  _tree->begin();
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Button *but = new Fl_Button(1, 1, ww, hh);
  but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  but->callback(callback, data);
  but->box(FL_FLAT_BOX);
  but->color(_tree->color());
  but->selection_color(_tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  std::string label = path;
  std::string::size_type last = path.find_last_of('/');
  if(last != std::string::npos) label = path.substr(last + 1);
  but->copy_label(label.c_str());
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addSolverMenu(int num)
{
  std::ostringstream path;
  path << "0Modules/Solver/Solver" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new solverButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addViewMenu(int num)
{
  std::ostringstream path;
  path << "0Modules/Post-processing/View" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  int ww = _baseWidth - (n->depth() + 1) * _indent;
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new viewButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(0);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

viewButton *onelabGroup::getViewButton(int num)
{
  char tmp[256];
  sprintf(tmp, "0Modules/Post-processing/View%d", num);
  Fl_Tree_Item *n = _tree->find_item(tmp);
  if(n){
    Fl_Group *grp = (Fl_Group*)n->widget();
    return (viewButton*)grp->child(0);
  }
  return 0;
}

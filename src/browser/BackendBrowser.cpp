// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_BROWSER)

#include <cstdio>
#include <map>
#include <string>
#include <vector>

#include "Backend.h"
#include "httpServer.h"
#include "page.h"
#include "OS.h"

// The chrome in a web page.
//
// It is a demonstration and a test of the structure, and it says so: what is
// being found out is whether the descriptions of src/gui survive being written
// down and sent to another process. Three things had to be true for this to
// work at all, and all three are properties of the arrangement rather than of
// this file:
//
//   the descriptions are handed over rather than fetched, so that asking for
//   one across a boundary is possible at all -- that is Sources;
//
//   what a menu entry does and what a field is worth are reached through the
//   description, so they can be given a number here and called back by that
//   number from a page that holds no pointers;
//
//   and the 3D scene is not the chrome's, so a chrome that cannot draw one
//   still shows the model -- in a window of its own, from src/scene.
//
// What it is not: a good interface. It polls twice a second, it draws no 3D,
// and a value is written back a whole field at a time. Something meant to be
// used would push over a socket and send what changed.

namespace {

  // --- writing a description down
  //
  // Everything a page is told is text, and everything it may do is a number.
  // A pointer cannot cross, so what a menu entry runs and what a field is
  // bound to are put in a table here and named by their place in it.

  std::string _quoted(const std::string &say)
  {
    std::string out = "\"";
    for(char c : say) {
      if(c == '"' || c == '\\') {
        out += '\\';
        out += c;
      }
      else if(c == '\n')
        out += "\\n";
      else if((unsigned char)c < 0x20)
        continue;
      else
        out += c;
    }
    return out + "\"";
  }

  class browserBackend : public Ui::Backend {
  public:
    std::string name() override { return "a web page"; }

    void setSources(const Sources &sources) override { _sources = sources; }
    void setHost(const Host &host) override { _host = host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      _port = Browser::listen(8010);
      if(!_port) return false;
      printf("Gmsh is at http://127.0.0.1:%d/\n", _port);
      fflush(stdout);
      return true;
    }

    void destroy() override
    {
      Browser::stop();
      _going = false;
    }

    int runLoop() override
    {
      while(_going) {
        _turn();
        SleepInSeconds(0.01);
      }
      return 0;
    }

    void check(bool rateLimited) override { _turn(); }
    bool ready() override { return false; }
    void wait(double seconds, bool force) override
    {
      _turn();
      SleepInSeconds(seconds < 0. || seconds > 0.05 ? 0.05 : seconds);
    }

    void postFromThread(const std::function<void()> &what) override
    {
      // there is no other thread here: a page asks, and the answer is written
      // between two turns of the loop
      what();
    }

    // --- what a page cannot do
    //
    // A question that stops everything needs a loop of its own, and this
    // chrome has no way of holding one open across a request. They are
    // answered as if the user had given up, and said so once.

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      _cannot("ask for a value");
      return false;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one, const std::string &two) override
    {
      _cannot("ask a question");
      return 0;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names, int *chosen) override
    {
      _cannot("choose a file");
      return false;
    }

    // --- what it does do

    void addMessage(const std::string &text, int level) override
    {
      _messages.push_back(text);
      if(_messages.size() > 500) _messages.erase(_messages.begin());
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      lines = _messages;
    }

    void refreshBar() override {}
    void sceneMessage(const std::string &, const std::string &) override {}
    void showForm(int form, bool show) override { _shown[form] = show; }
    bool formVisible(int form) override
    {
      auto it = _shown.find(form);
      return it != _shown.end() && it->second;
    }
    void showConsole(bool show) override { _console = show; }
    bool consoleVisible() override { return _console; }
    void refreshTree(bool rebuild) override {}
    void openTreeItem(const std::string &name, bool open) override {}
    void setSolverButtonMode(const std::string &, const std::string &) override
    {
    }
    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &key) override
    {
    }
    void windowAction(const std::string &what) override {}

    // the page draws the scene, from pictures of it: no window of its own
    bool showsScene() override { return true; }

    bool supports(const std::string &what) override
    {
      // one page: nothing to split, bring to the front, or detach
      return false;
    }

  private:
    Sources _sources;
    Host _host;
    int _port = 0;
    bool _going = true;
    bool _console = false;
    std::map<int, bool> _shown;
    std::vector<std::string> _messages;
    // what the page may ask for, by number: rebuilt every time the state is
    // written, since a description is only true at the moment it is drawn
    std::vector<std::function<void()> > _actions;
    std::vector<Ui::Field> _fields;
    std::vector<std::string> _saidCannot;
    // Which branches of the tree are unfolded. It is the chrome's to keep --
    // it is what the user did, not what the model says -- and it is what lets
    // the children of a branch be asked for only when they are wanted, which
    // is what a described tree is a model rather than a list for.
    std::map<std::string, bool> _open;

    void _cannot(const std::string &what)
    {
      for(const auto &said : _saidCannot)
        if(said == what) return;
      _saidCannot.push_back(what);
      if(_host.error)
        _host.error("A page cannot " + what + " yet: it takes a loop of its "
                    "own, and this chrome has none");
    }

    // one turn: answer whatever has arrived, then let the application do what
    // it has to -- which is where the scene in its own window is drawn
    void _turn()
    {
      Browser::serve([this](const Browser::Ask &ask, std::string &type) {
        return _answer(ask, type);
      });
      if(_host.tick) _host.tick();
    }

    static std::string _valueOf(const std::string &body, const std::string &key)
    {
      std::string want = key + "=";
      std::string::size_type at = body.find(want);
      if(at == std::string::npos) return "";
      at += want.size();
      std::string::size_type end = body.find('&', at);
      std::string raw = body.substr(at, end == std::string::npos ?
                                          std::string::npos : end - at);
      // what the page escaped
      std::string out;
      for(std::size_t i = 0; i < raw.size(); i++) {
        if(raw[i] == '+')
          out += ' ';
        else if(raw[i] == '%' && i + 2 < raw.size()) {
          out += (char)strtol(raw.substr(i + 1, 2).c_str(), nullptr, 16);
          i += 2;
        }
        else
          out += raw[i];
      }
      return out;
    }

    std::string _answer(const Browser::Ask &ask, std::string &type)
    {
      if(ask.path == "/") {
        type = "text/html; charset=utf-8";
        return browserPage;
      }
      // A picture of the 3D scene. A page cannot be handed an OpenGL context,
      // so the scene is drawn on this side and the picture crosses; what the
      // pointer does over it comes back through /pointer.
      if(ask.path.compare(0, 6, "/scene") == 0) {
        if(!_host.sceneImage) return "";
        int w = 0, h = 0;
        std::string picture = _host.sceneImage(w, h);
        type = "image/bmp";
        return picture;
      }
      if(ask.path == "/pointer") {
        if(_host.scenePointer)
          _host.scenePointer(atof(_valueOf(ask.body, "x").c_str()),
                             atof(_valueOf(ask.body, "y").c_str()),
                             atoi(_valueOf(ask.body, "b").c_str()),
                             atoi(_valueOf(ask.body, "w").c_str()),
                             atof(_valueOf(ask.body, "d").c_str()),
                             _valueOf(ask.body, "s") == "1",
                             _valueOf(ask.body, "c") == "1",
                             _valueOf(ask.body, "a") == "1");
        return "{}";
      }
      if(ask.path == "/choose") {
        int id = atoi(_valueOf(ask.body, "id").c_str());
        int at = atoi(_valueOf(ask.body, "i").c_str());
        if(id >= 0 && id < (int)_fields.size()) {
          Ui::Field &f = _fields[id];
          if(f.choose) f.choose(at, _valueOf(ask.body, "v") != "0");
          if(f.changed) f.changed();
        }
        return "{}";
      }
      if(ask.path == "/close") {
        int form = atoi(_valueOf(ask.body, "form").c_str());
        _shown[form] = false;
        if(_host.formWasClosed) _host.formWasClosed(form);
        return "{}";
      }
      if(ask.path == "/key") {
        std::string said = _valueOf(ask.body, "k");
        if(_host.sceneKey && said.size()) _host.sceneKey(said[0]);
        return "{}";
      }
      if(ask.path == "/size") {
        if(_host.sceneResize)
          _host.sceneResize(atoi(_valueOf(ask.body, "w").c_str()),
                            atoi(_valueOf(ask.body, "h").c_str()));
        return "{}";
      }
      if(ask.path == "/state") return _state();
      if(ask.path == "/do") {
        int id = atoi(_valueOf(ask.body, "id").c_str());
        if(id >= 0 && id < (int)_actions.size() && _actions[id])
          _actions[id]();
        return "{}";
      }
      if(ask.path == "/set") {
        int id = atoi(_valueOf(ask.body, "id").c_str());
        std::string said = _valueOf(ask.body, "v");
        if(id >= 0 && id < (int)_fields.size()) _write(_fields[id], said);
        return "{}";
      }
      if(ask.path == "/open") {
        std::string path = _valueOf(ask.body, "path");
        _open[path] = _valueOf(ask.body, "v") == "1";
        return "{}";
      }
      if(ask.path == "/pick") {
        std::string path = _valueOf(ask.body, "path");
        if(_sources.tree.node) {
          Ui::Node node = _sources.tree.node(path);
          if(node.pick) node.pick(_valueOf(ask.body, "v") == "1");
        }
        return "{}";
      }
      if(ask.path == "/pane") {
        int form = atoi(_valueOf(ask.body, "form").c_str());
        int pane = atoi(_valueOf(ask.body, "i").c_str());
        if(_sources.setFormPane) _sources.setFormPane(form, pane);
        return "{}";
      }
      return "{}";
    }

    void _write(Ui::Field &f, const std::string &said)
    {
      switch(f.kind) {
      case Ui::Check: f.setFlag(said == "1"); break;
      case Ui::Integer:
      case Ui::Number: f.setNumber(atof(said.c_str())); break;
      case Ui::Choice: {
        std::vector<std::string> labels;
        std::vector<int> values;
        if(f.dynamicChoices) f.dynamicChoices(labels, values);
        if(labels.empty()) labels = f.choices;
        int at = -1;
        for(std::size_t i = 0; i < labels.size(); i++)
          if(labels[i] == said) at = (int)i;
        if(at >= 0 && f.getText().empty())
          f.setNumber(at);
        else
          f.setText(said);
      } break;
      default: f.setText(said); break;
      }
      if(f.changed) f.changed();
    }

    // --- the state, written down
    //
    // The whole of what the page draws, asked of the description afresh: what
    // a menu says depends on what is loaded, and what a field is worth is only
    // true at the moment it is read.

    std::string _menu(const std::vector<Ui::MenuItem> &items)
    {
      std::string out = "[";
      for(std::size_t i = 0; i < items.size(); i++) {
        const Ui::MenuItem &it = items[i];
        if(i) out += ",";
        out += "{\"label\":" + _quoted(it.label);
        out += ",\"key\":" + _quoted(it.shortcut.label());
        out += ",\"enabled\":";
        out += (it.enabled && !it.enabled()) ? "false" : "true";
        out += ",\"checked\":";
        out += (it.kind == Ui::MenuItem::Toggle && it.checked && it.checked()) ?
                 "true" : "false";
        out += ",\"divider\":";
        out += it.dividerAfter ? "true" : "false";
        if(it.kind == Ui::MenuItem::Submenu) {
          out += ",\"children\":" + _menu(it.children);
          out += ",\"id\":-1";
        }
        else {
          _actions.push_back(it.action);
          out += ",\"id\":" + std::to_string((int)_actions.size() - 1);
        }
        out += "}";
      }
      return out + "]";
    }

    const char *_kindOf(const Ui::Field &f)
    {
      switch(f.kind) {
      case Ui::Check: return "check";
      case Ui::Choice: return "choice";
      case Ui::Action: return "action";
      case Ui::Label: return "label";
      case Ui::Output: return "output";
      case Ui::List: return "list";
      default: return "text";
      }
    }

    std::string _field(const Ui::Field &f)
    {
      std::string out = "{\"label\":" + _quoted(f.label);
      out += ",\"kind\":\"" + std::string(_kindOf(f)) + "\"";
      if(f.kind == Ui::Action) {
        _actions.push_back(f.changed);
        out += ",\"id\":" + std::to_string((int)_actions.size() - 1);
        return out + "}";
      }
      if(f.kind == Ui::List) {
        // What it holds and which of them are on. It is what the option
        // window puts down its left side -- the categories it is showing --
        // and what the visibility panel lists.
        std::vector<std::string> labels;
        std::vector<int> values;
        if(f.dynamicChoices)
          f.dynamicChoices(labels, values);
        else if(f.list && f.itemLabel)
          for(std::size_t i = 0; i < f.list->size(); i++)
            labels.push_back(f.itemLabel((int)i));
        else
          labels = f.choices;
        out += ",\"items\":[";
        for(std::size_t i = 0; i < labels.size(); i++)
          out += (i ? "," : "") + _quoted(labels[i]);
        out += "],\"on\":[";
        bool first = true;
        for(std::size_t i = 0; i < labels.size(); i++)
          if(f.chosen && f.chosen((int)i)) {
            out += (first ? "" : ",") + std::to_string(i);
            first = false;
          }
        out += "]";
        _fields.push_back(f);
        out += ",\"id\":" + std::to_string((int)_fields.size() - 1);
        return out + "}";
      }
      std::string said;
      if(f.kind == Ui::Check)
        said = f.getFlag() ? "1" : "0";
      else if(f.kind == Ui::Integer || f.kind == Ui::Number) {
        char number[64];
        snprintf(number, sizeof(number), "%g", f.getNumber());
        said = number;
      }
      else
        said = f.getText();
      if(f.kind == Ui::Choice) {
        std::vector<std::string> labels;
        std::vector<int> values;
        if(f.dynamicChoices)
          f.dynamicChoices(labels, values);
        else
          labels = f.choices;
        // A choice bound to a number says which of them it is on by its
        // place and not by its text; what a page shows is the text, and it
        // is read back the same way.
        int at = (int)f.getNumber();
        if(said.empty() && at >= 0 && at < (int)labels.size())
          said = labels[at];
        out += ",\"choices\":[";
        for(std::size_t i = 0; i < labels.size(); i++)
          out += (i ? "," : "") + _quoted(labels[i]);
        out += "]";
      }
      out += ",\"value\":" + _quoted(said);
      _fields.push_back(f);
      out += ",\"id\":" + std::to_string((int)_fields.size() - 1);
      return out + "}";
    }

    std::string _form(int which)
    {
      Ui::Form form = _sources.form(which);
      int pane = _sources.formPane ? _sources.formPane(which) : 0;
      std::string out = "{\"id\":" + std::to_string(which);
      out += ",\"title\":" + _quoted(form.title);
      out += ",\"pane\":" + std::to_string(pane);
      out += ",\"tabs\":[";
      for(std::size_t i = 0; i < form.panes.size(); i++)
        out += (i ? "," : "") + _quoted(form.panes[i].label);
      out += "],\"side\":[";
      {
        bool one = true;
        for(const auto &f : form.side) {
          if(f.visible && !f.visible()) continue;
          if(!one) out += ",";
          one = false;
          out += _field(f);
        }
      }
      out += "],\"fields\":[";
      bool first = true;
      auto say = [&](const std::vector<Ui::Field> &fields) {
        for(const auto &f : fields) {
          if(f.visible && !f.visible()) continue;
          if(f.kind == Ui::Spacer) continue;
          if(!first) out += ",";
          first = false;
          out += _field(f);
        }
      };
      say(form.header);
      if(pane >= 0 && pane < (int)form.panes.size()) {
        say(form.panes[pane].fields);
        for(const auto &section : form.panes[pane].sections) say(section.fields);
        say(form.panes[pane].beside);
      }
      say(form.footer);
      for(const auto &b : form.buttons) {
        if(!first) out += ",";
        first = false;
        _actions.push_back(b.action);
        out += "{\"label\":" + _quoted(b.label) + ",\"kind\":\"action\"";
        out += ",\"id\":" + std::to_string((int)_actions.size() - 1) + "}";
      }
      return out + "]}";
    }

    // One line of the tree and, if it is unfolded, what is under it. Nothing
    // below a folded branch is ever asked of the description.
    std::string _line(const Ui::Tree &tree, const std::string &path, int depth)
    {
      Ui::Node node = tree.node(path);
      bool branch = !tree.children(path).empty();
      auto said = _open.find(path);
      // the commands are unfolded to begin with, as they are in the tree this
      // stands in for; everything under them is folded
      bool open = said != _open.end() ? said->second : (depth < 1);
      std::string label = node.label;
      if(label.empty() && !node.hasField)
        label = path.substr(path.find_last_of('/') + 1);
      std::string out = "{\"path\":" + _quoted(path);
      out += ",\"label\":" + _quoted(label);
      out += ",\"depth\":" + std::to_string(depth);
      out += ",\"branch\":";
      out += branch ? "true" : "false";
      out += ",\"open\":";
      out += open ? "true" : "false";
      if(node.tooltip.size()) out += ",\"help\":" + _quoted(node.tooltip);
      if(node.picked)
        out += ",\"picked\":" + std::string(node.picked() ? "true" : "false");
      if(node.hasField) out += ",\"field\":" + _field(node.field);
      if(node.pressed) {
        _actions.push_back(node.pressed);
        out += ",\"id\":" + std::to_string((int)_actions.size() - 1);
      }
      out += "}";
      if(branch && open)
        for(const auto &child : tree.children(path))
          out += "," + _line(tree, child, depth + 1);
      return out;
    }

    std::string _tree()
    {
      const Ui::Tree &tree = _sources.tree;
      if(!tree.children) return "[]";
      std::string out = "[";
      bool first = true;
      for(const auto &root : tree.children("")) {
        if(!first) out += ",";
        first = false;
        out += _line(tree, root, 0);
      }
      return out + "]";
    }

    // the row of little buttons along the bottom
    std::string _bar()
    {
      if(!_sources.barButtons) return "[]";
      std::vector<Ui::BarButton> buttons = _sources.barButtons();
      std::string out = "[";
      for(std::size_t i = 0; i < buttons.size(); i++) {
        const Ui::BarButton &b = buttons[i];
        if(i) out += ",";
        out += "{\"label\":" + _quoted(b.label.size() ? b.label : b.glyph);
        out += ",\"help\":" + _quoted(b.tooltip);
        out += ",\"on\":";
        out += (b.on && b.on()) ? "true" : "false";
        out += ",\"enabled\":";
        out += (b.enabled && !b.enabled()) ? "false" : "true";
        if(b.menu) {
          out += ",\"children\":" + _menu(b.menu());
          out += ",\"id\":-1";
        }
        else {
          std::function<void(bool, bool)> what = b.action;
          _actions.push_back([what]() {
            if(what) what(false, false);
          });
          out += ",\"id\":" + std::to_string((int)_actions.size() - 1);
        }
        out += "}";
      }
      return out + "]";
    }

    std::string _state()
    {
      _actions.clear();
      _fields.clear();
      std::string out = "{\"menuGen\":";
      out += std::to_string(_sources.menuGeneration ? _sources.menuGeneration() :
                                                      0);
      out += ",\"menus\":";
      out += _sources.menuBar ? _menu(_sources.menuBar()) : "[]";
      out += ",\"tree\":" + _tree();
      out += ",\"bar\":" + _bar();
      out += ",\"forms\":[";
      bool first = true;
      int forms = _sources.numForms ? _sources.numForms() : 0;
      for(int i = 0; i < forms; i++) {
        if(!formVisible(i)) continue;
        if(!first) out += ",";
        first = false;
        out += _form(i);
      }
      out += "],\"status\":";
      Ui::BarMessage said;
      if(_sources.barMessage) said = _sources.barMessage();
      out += _quoted(said.text);
      // and what the console holds, which is where everything Gmsh says goes
      // once an interface is up
      out += ",\"messages\":[";
      std::size_t from = _messages.size() > 200 ? _messages.size() - 200 : 0;
      for(std::size_t i = from; i < _messages.size(); i++)
        out += (i > from ? "," : "") + _quoted(_messages[i]);
      out += "]";
      return out + "}";
    }
  };

  browserBackend *_the = nullptr;

} // namespace

Ui::Backend *makeUiBackend()
{
  if(!_the) _the = new browserBackend();
  return _the;
}

#endif

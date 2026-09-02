// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_BROWSER)

#include <cstdio>
#include <cstdlib>
#include <map>
#include <random>
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
      // The port it answers on. It is looked for from 8010 up, so that two
      // of these do not fight over one; something driving it from outside --
      // the bench that photographs the interfaces -- says which it wants.
      int wanted = 8010;
      if(const char *said = getenv("GMSH_BROWSER_PORT")) {
        int n = atoi(said);
        if(n > 0 && n < 65536) wanted = n;
      }
      // And the word that has to come with every request. Without one, any
      // page anyone visits could drive this: a plain POST goes out to another
      // origin without asking permission first, and the port is a short list
      // to try. The word is in the address the user is given, so their page
      // has it and nobody else's does.
      _token = getenv("GMSH_BROWSER_TOKEN") ? getenv("GMSH_BROWSER_TOKEN") :
                                              _madeUp();
      _port = Browser::listen(wanted);
      if(!_port) return false;
      printf("Gmsh is at http://127.0.0.1:%d/?k=%s\n", _port, _token.c_str());
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
    void showForm(int form, bool show) override { _shown[form] = show; }
    bool formVisible(int form) override
    {
      auto it = _shown.find(form);
      return it != _shown.end() && it->second;
    }
    void drawTooltip(const std::string &text) override { _tip = text; }
    void showConsole(bool show) override { _console = show; }
    bool consoleVisible() override { return _console; }
    void refreshTree(bool rebuild) override {}
    // which branches of the tree are unfolded is the page's own business --
    // nothing else knows what it has drawn -- so this is where it is kept,
    // and Gmsh asking for one is the same as the page asking
    void openTreeItem(const std::string &name, bool open) override
    {
      _open[name] = open;
    }
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
    // what the scene says is under the pointer, said next to it
    std::string _tip;
    // and where the page says it has put its windows
    std::string _where;
    // the word that has to come with every request
    std::string _token;
    // what was last said down the event stream, and when; and when the page
    // last asked for something, which is what says whether anything is going
    // on at all
    std::string _told;
    bool _toldScene = false;
    double _lastTold = 0.;
    double _lastAsked = 0.;
    std::map<int, bool> _shown;
    std::vector<std::string> _messages;
    // What the page may ask for, by number: rebuilt every time the state is
    // written, since a description is only true at the moment it is drawn.
    //
    // A number alone would not do. It is a place in these lists, and the
    // lists are made again at every state: between the moment the page reads
    // one and the moment it sends it back, a view may have been added or a
    // window opened, and the same number would then be a different field --
    // a value typed into one would land in another. So each one carries what
    // it stood for, and a number that no longer stands for that is refused
    // rather than obeyed.
    std::vector<std::function<void()> > _actions;
    std::vector<unsigned> _actionNames;
    std::vector<Ui::Field> _fields;
    std::vector<unsigned> _fieldNames;
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
      _tell();
      if(_host.tick) _host.tick();
    }

    // What the page is told, and when.
    //
    // Nothing is worked out while nobody is listening. Whether anything has
    // changed can only be found out by writing the state down and looking at
    // it -- a description is asked, it does not announce itself -- so that is
    // done ten times a second while something is going on and twice when
    // nothing is, rather than every turn of the loop. What it costs is a
    // fortieth of what asking the page to ask cost, and the page itself is
    // left alone entirely.
    void _tell()
    {
      if(!Browser::listeners()) return;
      double now = TimeOfDay();
      double every = (now - _lastAsked < 2.) ? 0.1 : 0.5;
      if(now - _lastTold < every) return;
      _lastTold = now;
      std::string said = _state();
      if(said != _told) {
        _told = said;
        Browser::push("state", said);
      }
      // and whether the picture is worth coming for. It stays worth it until
      // the page has been to fetch it, so it is only said once.
      bool moved = _host.sceneMoved && _host.sceneMoved();
      if(moved && !_toldScene) Browser::push("scene", "1");
      _toldScene = moved;
    }

    static std::string _valueOf(const std::string &body, const std::string &key)
    {
      // At the start of a field and nowhere else: a key looked for anywhere
      // in the text finds itself inside the value of another one.
      std::string want = key + "=";
      std::string::size_type at = 0;
      while(true) {
        at = body.find(want, at);
        if(at == std::string::npos) return "";
        if(at == 0 || body[at - 1] == '&' || body[at - 1] == '?') break;
        at += want.size();
      }
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

    // Short, stable, and enough to tell one field from another: FNV-1a over
    // what the thing is called.
    static unsigned _nameOf(const std::string &what)
    {
      unsigned h = 2166136261u;
      for(std::size_t i = 0; i < what.size(); i++) {
        h ^= (unsigned char)what[i];
        h *= 16777619u;
      }
      return h;
    }

    // hand out a number for something to do, with what it was
    std::string _actionId(const std::function<void()> &what,
                          const std::string &called)
    {
      _actions.push_back(what);
      _actionNames.push_back(_nameOf(called));
      return ",\"id\":" + std::to_string((int)_actions.size() - 1) +
             ",\"h\":" + std::to_string(_actionNames.back());
    }

    std::string _fieldId(const Ui::Field &f)
    {
      _fields.push_back(f);
      _fieldNames.push_back(_nameOf(_kindOf(f) + std::string(":") + f.label));
      return ",\"id\":" + std::to_string((int)_fields.size() - 1) +
             ",\"h\":" + std::to_string(_fieldNames.back());
    }

    // and what the page sent back: the same thing, or nothing at all
    std::function<void()> *_actionAsked(const Browser::Ask &ask)
    {
      int id = atoi(_valueOf(ask.body, "id").c_str());
      if(id < 0 || id >= (int)_actions.size() ||
         id >= (int)_actionNames.size())
        return nullptr;
      unsigned said = (unsigned)strtoul(_valueOf(ask.body, "h").c_str(),
                                        nullptr, 10);
      if(said != _actionNames[id]) return nullptr;
      return &_actions[id];
    }

    Ui::Field *_fieldAsked(const Browser::Ask &ask)
    {
      int id = atoi(_valueOf(ask.body, "id").c_str());
      if(id < 0 || id >= (int)_fields.size() || id >= (int)_fieldNames.size())
        return nullptr;
      unsigned said = (unsigned)strtoul(_valueOf(ask.body, "h").c_str(),
                                        nullptr, 10);
      if(said != _fieldNames[id]) return nullptr;
      return &_fields[id];
    }

    // a word nobody else can guess, for the address the user is given
    static std::string _madeUp()
    {
      std::random_device chance;
      std::string out;
      for(int i = 0; i < 24; i++) out += "0123456789abcdef"[chance() & 0xf];
      return out;
    }

    // Whether this request may be answered at all.
    //
    // Two things are asked of it. It has to carry the word that was in the
    // address, which a page that was not given that address does not have.
    // And if it says which page it comes from -- a browser says so whenever
    // one origin asks something of another -- that page has to be this one.
    // Either alone would do; both cost nothing.
    bool _mayAsk(const Browser::Ask &ask)
    {
      if(ask.origin.size()) {
        std::string mine = "http://127.0.0.1:" + std::to_string(_port);
        std::string also = "http://localhost:" + std::to_string(_port);
        if(ask.origin != mine && ask.origin != also) return false;
      }
      if(_token.empty()) return true;
      std::string said = _valueOf(ask.body, "k");
      if(said.empty()) said = _valueOf(ask.path, "k");
      return said == _token;
    }

    std::string _answer(const Browser::Ask &ask, std::string &type)
    {
      if(!_mayAsk(ask)) {
        type = "text/plain";
        return "no";
      }
      // something is going on: look more often for a while
      if(ask.path != "/scene" && ask.path.compare(0, 6, "/scene") != 0 &&
         ask.path.compare(0, 7, "/events") != 0)
        _lastAsked = TimeOfDay();
      // what comes before the question mark: the page and the pictures are
      // asked for with the word in the address, so the path carries a query
      std::string path = ask.path.substr(0, ask.path.find('?'));
      if(path == "/") {
        type = "text/html; charset=utf-8";
        return browserPage;
      }
      // A picture of the 3D scene. A page cannot be handed an OpenGL context,
      // so the scene is drawn on this side and the picture crosses; what the
      // pointer does over it comes back through /pointer.
      if(ask.path.compare(0, 6, "/scene") == 0) {
        if(!_host.sceneImage) return "";
        int w = 0, h = 0;
        // An empty answer means "you already have this one"; the page keeps
        // the picture it is showing. It asks with "force" when it has just
        // done something, since what an action changes is its business and
        // not the scene's.
        bool always = ask.path.find("force") != std::string::npos;
        std::string picture = _host.sceneImage(w, h, always);
        type = "image/bmp";
        return picture;
      }
      if(path == "/pointer") {
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
      if(path == "/choose") {
        int at = atoi(_valueOf(ask.body, "i").c_str());
        Ui::Field *f = _fieldAsked(ask);
        if(f) {
          if(f->choose) f->choose(at, _valueOf(ask.body, "v") != "0");
          if(f->changed) f->changed();
        }
        return "{}";
      }
      // The one connection that is never answered: what Gmsh has to say goes
      // down it, from _tell(), for as long as the page holds it open.
      if(ask.path.compare(0, 7, "/events") == 0) {
        type = "text/event-stream";
        _told = _state();
        _toldScene = false;
        return _told;
      }
      if(path == "/where") {
        // Where the page put things. Nothing outside a page can know that,
        // and something photographing one window of it -- the bench that puts
        // the interfaces side by side -- has to be told where to cut.
        if(ask.body.size()) { _where = ask.body; return "{}"; }
        return _where;
      }
      if(path == "/close") {
        int form = atoi(_valueOf(ask.body, "form").c_str());
        _shown[form] = false;
        if(_host.formWasClosed) _host.formWasClosed(form);
        return "{}";
      }
      if(path == "/key") {
        // "j", not "k": "k" is the word that says the request may be asked
        // at all
        std::string said = _valueOf(ask.body, "j");
        if(_host.sceneKey && said.size()) _host.sceneKey(said[0]);
        return "{}";
      }
      if(path == "/size") {
        if(_host.sceneResize)
          _host.sceneResize(atoi(_valueOf(ask.body, "w").c_str()),
                            atoi(_valueOf(ask.body, "h").c_str()));
        return "{}";
      }
      if(path == "/state") return _state();
      if(path == "/do") {
        std::function<void()> *what = _actionAsked(ask);
        if(!what) return "{\"did\":false}";
        if(*what) (*what)();
        return "{\"did\":true}";
      }
      if(path == "/set") {
        Ui::Field *f = _fieldAsked(ask);
        if(f) _write(*f, _valueOf(ask.body, "v"));
        return "{}";
      }
      if(path == "/open") {
        std::string path = _valueOf(ask.body, "path");
        _open[path] = _valueOf(ask.body, "v") == "1";
        return "{}";
      }
      if(path == "/pick") {
        std::string path = _valueOf(ask.body, "path");
        if(_sources.tree.node) {
          Ui::Node node = _sources.tree.node(path);
          if(node.pick) node.pick(_valueOf(ask.body, "v") == "1");
        }
        return "{}";
      }
      if(path == "/pane") {
        int form = atoi(_valueOf(ask.body, "form").c_str());
        int pane = atoi(_valueOf(ask.body, "i").c_str());
        bool moved = _sources.formPane && _sources.formPane(form) != pane;
        if(_sources.setFormPane) _sources.setFormPane(form, pane);
        // the user picked this pane: it may have something to start, which is
        // how moving to the Line tab of the elementary window asks for a start
        // point rather than leaving the tool that was running
        if(moved && _sources.form) {
          Ui::Form said = _sources.form(form);
          if(pane >= 0 && pane < (int)said.panes.size() &&
             said.panes[pane].chosen)
            said.panes[pane].chosen();
        }
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
        if(f.dynamicChoices)
          f.dynamicChoices(labels, values);
        else {
          labels = f.choices;
          values = f.values;
        }
        int at = -1;
        for(std::size_t i = 0; i < labels.size(); i++)
          if(labels[i] == said) at = (int)i;
        if(at >= 0 && at < (int)values.size())
          f.setNumber(values[at]);
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
          out += _actionId(it.action, "menu:" + it.label);
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
      case Ui::Menu: return "menu";
      case Ui::Hierarchy: return "hierarchy";
      default: return "text";
      }
    }

    std::string _field(const Ui::Field &f)
    {
      std::string out = "{\"label\":" + _quoted(f.label);
      out += ",\"kind\":\"" + std::string(_kindOf(f)) + "\"";
      if(f.kind == Ui::Action) {
        out += _actionId(f.changed, "action:" + f.label);
        return out + "}";
      }
      if(f.kind == Ui::Hierarchy) {
        // A field that is a tree of its own -- the visibility window shows
        // the model entity under entity -- said the way the modules tree is
        // said, since it is the same kind of thing.
        out += ",\"lines\":";
        out += f.hierarchy ? _treeOf(*f.hierarchy) : "[]";
        out += _fieldId(f);
        return out + "}";
      }
      if(f.kind == Ui::List || f.kind == Ui::Menu) {
        // What it holds and which of them are on. It is what the option
        // window puts down its left side -- the categories it is showing --
        // and what the visibility panel lists. A menu is the same thing shut:
        // a list of what one may pick, none of it on.
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
        out += _fieldId(f);
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
        else {
          labels = f.choices;
          values = f.values;
        }
        // A choice that says what each of its entries stands for is on the
        // one whose value it holds, and not on the one whose text it holds:
        // what a page shows is the text either way, and it is read back the
        // same way. This is the rule the other interfaces follow.
        if(values.size()) {
          int at = (int)f.getNumber();
          said.clear();
          for(std::size_t i = 0; i < values.size() && i < labels.size(); i++)
            if(values[i] == at) said = labels[i];
        }
        out += ",\"choices\":[";
        for(std::size_t i = 0; i < labels.size(); i++)
          out += (i ? "," : "") + _quoted(labels[i]);
        out += "]";
      }
      out += ",\"value\":" + _quoted(said);
      out += _fieldId(f);
      return out + "}";
    }

    // The layout a field carries, which is most of what a description says
    // about how a window looks: what shares a line, what is written before
    // rather than after, what has a rule over it.
    std::string _layout(const Ui::Field &f)
    {
      std::string out;
      if(f.sameRow) out += ",\"sameRow\":true";
      if(f.labelBefore) out += ",\"before\":true";
      if(f.rule) out += ",\"rule\":true";
      if(f.wraps) out += ",\"wraps\":true";
      if(f.disclosure) out += ",\"fold\":true";
      if(f.packed) out += ",\"packed\":true";
      if(f.widthEm > 0.) out += ",\"em\":" + std::to_string(f.widthEm);
      if(f.rows > 1) out += ",\"rows\":" + std::to_string(f.rows);
      if(f.tooltip.size()) out += ",\"help\":" + _quoted(f.tooltip);
      if(f.enabled && !f.enabled()) out += ",\"off\":true";
      return out;
    }

    std::string _fieldList(const std::vector<Ui::Field> &fields)
    {
      std::string out = "[";
      bool first = true;
      for(const auto &f : fields) {
        if(f.visible && !f.visible()) continue;
        if(!first) out += ",";
        first = false;
        // a spacer says where a run of packed fields ends, which a page can
        // say with a gap that grows
        if(f.kind == Ui::Spacer) {
          out += "{\"kind\":\"gap\"";
          out += _layout(f);
          out += "}";
          continue;
        }
        std::string one = _field(f);
        one.insert(one.size() - 1, _layout(f));
        out += one;
      }
      return out + "]";
    }

    // One pane, as it is laid out: its own fields, then the titled sections
    // under them, then whatever sits on the line of its button.
    std::string _pane(const Ui::Pane &p)
    {
      std::string out = "{\"label\":" + _quoted(p.label);
      out += ",\"columns\":" + std::to_string(p.columns);
      // a long pane scrolls rather than making the window as tall as it is
      out += ",\"scrolls\":";
      out += p.scrolling ? "true" : "false";
      out += ",\"fields\":" + _fieldList(p.fields);
      out += ",\"sections\":[";
      bool first = true;
      for(const auto &section : p.sections) {
        if(section.visible && !section.visible()) continue;
        if(!first) out += ",";
        first = false;
        out += "{\"label\":" + _quoted(section.label);
        out += ",\"columns\":" + std::to_string(section.columns);
        out += ",\"fields\":" + _fieldList(section.fields);
        // a section acts as well as holds: the high-order window generates
        // from one of its sections and regularizes from the other
        out += ",\"button\":" + _quoted(section.buttonLabel);
        if(section.button) {
          _actions.push_back(section.button);
          _actionNames.push_back(_nameOf("pane:" + section.label));
          out += ",\"buttonId\":" + std::to_string((int)_actions.size() - 1);
          out += ",\"buttonH\":" + std::to_string(_actionNames.back());
        }
        out += "}";
      }
      out += "],\"beside\":" + _fieldList(p.beside);
      out += ",\"button\":" + _quoted(p.buttonLabel);
      if(p.button) {
        _actions.push_back(p.button);
        _actionNames.push_back(_nameOf("pane:" + p.label));
        out += ",\"buttonId\":" + std::to_string((int)_actions.size() - 1);
        out += ",\"buttonH\":" + std::to_string(_actionNames.back());
      }
      return out + "}";
    }

    std::string _form(int which)
    {
      Ui::Form form = _sources.form(which);
      int pane = _sources.formPane ? _sources.formPane(which) : 0;
      std::string out = "{\"id\":" + std::to_string(which);
      out += ",\"title\":" + _quoted(form.title);
      out += ",\"pane\":" + std::to_string(pane);
      out += ",\"tabbed\":";
      out += form.tabbed ? "true" : "false";
      // What the tabs are, and which family each belongs to: a window with
      // more panes than fit across one row wears two rows of them.
      out += ",\"tabs\":[";
      for(std::size_t i = 0; i < form.panes.size(); i++) {
        if(i) out += ",";
        out += "{\"label\":" + _quoted(form.panes[i].label);
        out += ",\"group\":" + _quoted(form.panes[i].group);
        out += ",\"on\":";
        out += (form.panes[i].visible && !form.panes[i].visible()) ? "false" :
                                                                     "true";
        out += "}";
      }
      out += "],\"side\":" + _fieldList(form.side);
      out += ",\"sideEm\":" + std::to_string(form.sideEm > 0. ? form.sideEm
                                                              : 8.);
      out += ",\"header\":" + _fieldList(form.header);
      // The panes to show: the one that is picked, or all of them one under
      // another for a window that is one long form rather than a set of tabs.
      out += ",\"panes\":[";
      if(form.tabbed) {
        if(pane >= 0 && pane < (int)form.panes.size())
          out += _pane(form.panes[pane]);
      }
      else {
        bool first = true;
        for(const auto &q : form.panes) {
          if(q.visible && !q.visible()) continue;
          if(!first) out += ",";
          first = false;
          out += _pane(q);
        }
      }
      out += "],\"footer\":" + _fieldList(form.footer);
      out += ",\"buttons\":[";
      for(std::size_t i = 0; i < form.buttons.size(); i++) {
        const auto &b = form.buttons[i];
        if(i) out += ",";
        out += "{\"label\":" + _quoted(b.label);
        out += _actionId(b.action, "button:" + b.label) + "}";
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
      if(node.pressed) out += _actionId(node.pressed, "tree:" + path);
      out += "}";
      if(branch && open)
        for(const auto &child : tree.children(path))
          out += "," + _line(tree, child, depth + 1);
      return out;
    }

    std::string _treeOf(const Ui::Tree &tree)
    {
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

    std::string _tree() { return _treeOf(_sources.tree); }

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
          out += _actionId([what]() { if(what) what(false, false); },
                           "bar:" + (b.label.size() ? b.label : b.glyph));
        }
        out += "}";
      }
      return out + "]";
    }

    std::string _state()
    {
      _actions.clear();
      _fields.clear();
      _actionNames.clear();
      _fieldNames.clear();
      std::string out = "{\"menuGen\":";
      out += std::to_string(_sources.menuGeneration ? _sources.menuGeneration() :
                                                      0);
      out += ",\"menus\":";
      out += _sources.menuBar ? _menu(_sources.menuBar()) : "[]";
      out += ",\"tip\":" + _quoted(_tip);
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

// The one this file offers, made once. Saying so here rather than being asked
// for by name from the shared side is what lets every chrome that was compiled
// in be there at once, and lets the choice be a word one types.
namespace {
  struct offeringBrowser {
    offeringBrowser()
    {
      Ui::offer("browser", []() -> Ui::Backend * {
        if(!_the) _the = new browserBackend();
        return _the;
      });
    }
  };
  offeringBrowser _offeringBrowser;
}


#endif

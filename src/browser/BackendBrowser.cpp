// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <random>
#include <string>
#include <vector>

#include "Backend.h"
#include "Console.h"
#include "Glyph.h"
#include "httpServer.h"
#include "OS.h"
// page.html, as bytes: made by src/browser/CMakeLists.txt
#include "browserPage.h"

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#endif

#if defined(WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

// the interface in a web page: the descriptions are sent to another process,
// which holds no pointers -- what an entry does and what a field is worth are
// given a number here; the scene is drawn in a window of its own and the page
// shows pictures of it

namespace {

  // the key a browser names, as Ui::Shortcut says it; 0 for one no shortcut
  // could name
  int _uiKey(const std::string &name)
  {
    if(name.size() == 1) {
      unsigned char c = (unsigned char)name[0];
      if(c > ' ' && c < 127) return toupper(c);
      return 0;
    }
    if(name.size() >= 2 && name[0] == 'F') {
      int n = atoi(name.c_str() + 1);
      if(n >= 1 && n <= 12 && name == "F" + std::to_string(n))
        return Ui::KeyF1 + n - 1;
    }
    if(name == "Escape") return Ui::KeyEscape;
    if(name == "ArrowLeft") return Ui::KeyLeft;
    if(name == "ArrowRight") return Ui::KeyRight;
    if(name == "ArrowUp") return Ui::KeyUp;
    if(name == "ArrowDown") return Ui::KeyDown;
    if(name == "Home") return Ui::KeyHome;
    if(name == "PageUp") return Ui::KeyPageUp;
    if(name == "PageDown") return Ui::KeyPageDown;
    if(name == "Delete") return Ui::KeyDelete;
    return 0;
  }

  // a wait hands the page back to the browser when Gmsh runs inside it, or
  // nothing would be drawn nor clicked meanwhile
  void _pause(double seconds)
  {
#if defined(__EMSCRIPTEN__)
    emscripten_sleep((unsigned int)(seconds * 1000.));
#else
    SleepInSeconds(seconds);
#endif
  }

  // --- writing a description down: everything a page is told is text, and everything it may do is a number, its place in a table here

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
      else if(c == '\t')
        // the tab separates the columns of a line of a list
        out += "\\t";
      else if(c == '\r')
        out += "\\r";
      else if((unsigned char)c < 0x20)
        continue;
      else
        out += c;
    }
    return out + "\"";
  }

  // a picture of Glyph.h as the page draws it, in the colour of the text of
  // the button it is put in; empty for a name no glyph has
  std::string _svg(const std::string &name)
  {
    const Ui::Glyph *g = Ui::glyph(name);
    if(!g) return "";
    std::string out = "<svg viewBox='-1.1 -1.1 2.2 2.2' width='1em' "
                      "height='1em' style='vertical-align:-0.15em'>";
    for(const Ui::Stroke &k : g->strokes) {
      std::string d;
      char at[64];
      for(std::size_t i = 0; i + 1 < k.points.size(); i += 2) {
        snprintf(at, sizeof(at), "%s%.3f %.3f", i ? " L" : "M", k.points[i],
                 k.points[i + 1]);
        d += at;
      }
      if(k.kind != Ui::Stroke::Line) d += " Z";
      std::string ink = "currentColor";
      if(k.colour.a) {
        snprintf(at, sizeof(at), "rgb(%d,%d,%d)", k.colour.r, k.colour.g,
                 k.colour.b);
        ink = at;
      }
      snprintf(at, sizeof(at), "%g", k.width);
      out += "<path d='" + d + "' fill='" +
             (k.kind == Ui::Stroke::Fill ? ink : std::string("none")) +
             "' stroke='" + ink + "' stroke-width='" + at +
             "' vector-effect='non-scaling-stroke' stroke-linejoin='round'/>";
    }
    return out + "</svg>";
  }

  class backendBrowser : public Ui::Backend {
  public:
    std::string name() override { return "a web page"; }

    void setSources(const Sources &sources) override { _sources = sources; }
    void setHost(const Host &host) override { _host = host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
#if defined(__EMSCRIPTEN__)
      // inside the page, which alone can ask: no address, and no word to guard
      // it with
      _port = Browser::listen(0);
      return true;
#else
      // looked for from 8010 up, so that two of these do not fight; the bench
      // says which it wants
      int wanted = 8010;
      if(const char *said = getenv("GMSH_BROWSER_PORT")) {
        int n = atoi(said);
        if(n > 0 && n < 65536) wanted = n;
      }
      // without the word any page anyone visits could drive this: a plain POST
      // goes out to another origin without asking
      _token = getenv("GMSH_BROWSER_TOKEN") ? getenv("GMSH_BROWSER_TOKEN") :
                                              _madeUp();
      _port = Browser::listen(wanted);
      if(!_port) return false;
      printf("Gmsh is at http://127.0.0.1:%d/?k=%s\n", _port, _token.c_str());
      fflush(stdout);
      return true;
#endif
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
        _pause(0.01);
      }
      return 0;
    }

    void check(bool rateLimited) override { _turn(); }
    bool ready() override { return false; }
    void wait(double seconds, bool force) override
    {
      _turn();
      _pause(seconds < 0. || seconds > 0.05 ? 0.05 : seconds);
    }

    void postFromThread(const std::function<void()> &what) override
    {
      what();
    }

    // --- the windows that must be answered before anything else goes on: a page cannot be stopped, so the ask is put into the state and _hold() serves the page, and nothing else, until the answer comes back

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      _asking = Asking();
      _asking.kind = "value";
      _asking.title = question;
      _asking.hint = hint;
      _asking.readOnly = readOnly;
      _asking.value = value;
      if(!_hold()) return false;
      value = _asking.value;
      return true;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one, const std::string &two) override
    {
      _asking = Asking();
      _asking.kind = "question";
      _asking.title = question;
      _asking.zero = zero;
      _asking.one = one;
      _asking.two = two;
      if(!_hold()) return 0;
      return _asking.chose;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names, int *chosen) override
    {
      _asking = Asking();
      _asking.kind = "file";
      _asking.title = title;
      _asking.mode = mode;
      _asking.formats = formats;
      _asking.names = names;
      if(!_hold()) return false;
      names = _asking.names;
      if(names.empty()) return false;
      if(chosen) *chosen = _asking.chose;
      return true;
    }

    // --- what it does do

    void addMessage(const std::string &text, int level) override
    {
      if(_said.add(text, level)) _dirty = true;
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      lines = _said.texts();
    }

    void refreshBar() override { _dirty = true; }
    void refreshMenus() override { _dirty = true; }
    void reloadForm(const Ui::Form &) override { _dirty = true; }
    void rebuildForm(const Ui::Form &) override { _dirty = true; }
    void optionChanged(const std::string &) override { _dirty = true; }

    // --- the forms, by the name of their dialog

    void showForm(const Ui::Form &which, bool show) override
    {
      _dirty = true;
      _state(which).shown = show;
    }
    bool formVisible(const Ui::Form &which) override
    {
      auto it = _forms.find(&which);
      return it != _forms.end() && it->second.shown;
    }
    std::string formPane(const Ui::Form &which) override
    {
      auto it = _forms.find(&which);
      return it == _forms.end() ? "" : it->second.pane;
    }
    void setFormPane(const Ui::Form &which, const std::string &pane) override
    {
      _dirty = true;
      _state(which).pane = pane;
    }
    void dropForm(const Ui::Form &which) override
    {
      _dirty = true;
      _forms.erase(&which);
    }
    void showConsole(bool show) override
    {
      _dirty = true;
      _console = show;
    }
    bool consoleVisible() override { return _console; }
    void refreshTree(bool rebuild) override { _dirty = true; }
    // which branches are unfolded is the page's own business: kept here, and
    // Gmsh asking for one is the same as the page asking
    void openTreeItem(const std::string &name, bool open) override
    {
      _dirty = true;
      _open[name] = open;
    }
    bool treeItemOpen(const std::string &name) override
    {
      auto it = _open.find(name);
      return it != _open.end() && it->second;
    }
    void setSolverButtonMode(const std::string &, const std::string &) override
    {
    }
    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &key) override
    {
    }
    void windowAction(const std::string &what) override {}

    bool showsScene() override { return true; }

    bool supports(const std::string &what) override
    {
      return false;
    }

  private:
    Sources _sources;
    Host _host;
    int _port = 0;
    bool _going = true;
    bool _console = false;
    std::string _where;
    std::string _token;
    std::string _told;
    bool _dirty = true;
    bool _toldScene = false;
    double _lastTold = 0.;
    struct formState {
      const Ui::Form *form = nullptr;
      bool shown = false;
      // the pane showing, by its label
      std::string pane;
    };
    std::map<const Ui::Form *, formState> _forms;
    std::map<const Ui::Form *, formState>::iterator _formNamed(const std::string &id)
    {
      for(auto it = _forms.begin(); it != _forms.end(); ++it)
        if(it->first->id == id) return it;
      return _forms.end();
    }
    formState &_state(const Ui::Form &which)
    {
      formState &state = _forms[&which];
      state.form = &which;
      return state;
    }
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console _said{500};
    // rebuilt every time the state is written: a number is a place in these
    // lists, so each carries what it stood for, and one that no longer stands
    // for that is refused
    std::vector<std::function<void()> > _actions;
    std::vector<unsigned> _actionNames;
    std::vector<Ui::Field> _fields;
    std::vector<unsigned> _fieldNames;
    // the interface's to keep: the children of a branch are asked for only when
    // wanted
    bool _mapHelp = false;
    std::map<std::string, bool> _open;

    // what the page is being asked when something has stopped Gmsh
    struct Asking {
      bool open = false;
      std::string kind; // "file", "value" or "question"
      std::string title, hint;
      int mode = 0; // a file: Open, Create or OpenSeveral
      bool readOnly = false;
      std::vector<FileFormat> formats;
      std::vector<std::string> names; // what to start from, then what was said
      std::string value; // a value: the same
      std::string zero, one, two; // a question: what its buttons say
      bool answered = false;
      bool said = false; // answered, rather than given up on
      int chose = -1; // which format, or which button
    };
    Asking _asking;

    // only the page is served meanwhile; requests that would change something
    // are refused, so that a click cannot start a second ask under the first
    bool _hold()
    {
      _asking.open = true;
      _asking.answered = false;
      double seen = TimeOfDay();
      while(!_asking.answered) {
        Browser::serve([this](const Browser::Ask &ask, std::string &type) {
          return _answer(ask, type);
        });
        _dirty = true;
        _tell();
        // a page never opened, or closed while the window was up, must not stop
        // Gmsh for ever: given up on
        if(Browser::listeners())
          seen = TimeOfDay();
        else if(TimeOfDay() - seen > 20.)
          break;
        _pause(0.02);
      }
      _asking.open = false;
      _lastTold = 0.;
      _tell();
      return _asking.said;
    }

    // subdirectories first, files after
    std::string _files(const std::string &where)
    {
      // in full: what the page writes in its path bar is where one really is
      std::string dir = where;
      char here[4096];
#if defined(WIN32) && !defined(__CYGWIN__)
      std::string cwd = _getcwd(here, sizeof(here)) ? here : ".";
      bool full = dir.size() > 1 && (dir[1] == ':' || dir[0] == '\\');
#else
      std::string cwd = getcwd(here, sizeof(here)) ? here : ".";
      bool full = dir.size() && dir[0] == '/';
#endif
      if(dir.empty())
        dir = cwd;
      else if(!full)
        dir = cwd + "/" + dir;
      if(dir.size() > 1 && (dir[dir.size() - 1] == '/' ||
                            dir[dir.size() - 1] == '\\'))
        dir.resize(dir.size() - 1);
      std::vector<std::string> dirs, files;
#if defined(WIN32) && !defined(__CYGWIN__)
      WIN32_FIND_DATAA found;
      HANDLE h = FindFirstFileA((dir + "\\*").c_str(), &found);
      if(h != INVALID_HANDLE_VALUE) {
        do {
          std::string name = found.cFileName;
          if(name == "." || name == "..") continue;
          if(found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            dirs.push_back(name);
          else
            files.push_back(name);
        } while(FindNextFileA(h, &found));
        FindClose(h);
      }
#else
      if(DIR *d = opendir(dir.c_str())) {
        while(struct dirent *it = readdir(d)) {
          std::string name = it->d_name;
          if(name == "." || name == "..") continue;
          struct stat about;
          if(stat((dir + "/" + name).c_str(), &about)) continue;
          if(S_ISDIR(about.st_mode))
            dirs.push_back(name);
          else
            files.push_back(name);
        }
        closedir(d);
      }
#endif
      std::sort(dirs.begin(), dirs.end());
      std::sort(files.begin(), files.end());
      std::string out = "{\"dir\":" + _quoted(dir) + ",\"entries\":[";
      bool first = true;
      for(const auto &name : dirs) {
        out += first ? "" : ",";
        first = false;
        out += "{\"name\":" + _quoted(name) + ",\"dir\":true}";
      }
      for(const auto &name : files) {
        out += first ? "" : ",";
        first = false;
        out += "{\"name\":" + _quoted(name) + ",\"dir\":false}";
      }
      return out + "]}";
    }

    std::string _ask()
    {
      if(!_asking.open) return "null";
      std::string out = "{\"kind\":" + _quoted(_asking.kind);
      out += ",\"title\":" + _quoted(_asking.title);
      if(_asking.kind == "file") {
        out += ",\"mode\":" + std::to_string(_asking.mode);
        out += ",\"start\":" +
               _quoted(_asking.names.empty() ? std::string() : _asking.names[0]);
        out += ",\"formats\":[";
        for(std::size_t i = 0; i < _asking.formats.size(); i++) {
          out += i ? "," : "";
          out += "{\"name\":" + _quoted(_asking.formats[i].name);
          out += ",\"pattern\":" + _quoted(_asking.formats[i].pattern) + "}";
        }
        out += "]";
      }
      else if(_asking.kind == "value") {
        out += ",\"value\":" + _quoted(_asking.value);
        out += ",\"hint\":" + _quoted(_asking.hint);
        out += ",\"readOnly\":";
        out += _asking.readOnly ? "true" : "false";
      }
      else {
        out += ",\"buttons\":[" + _quoted(_asking.zero);
        if(_asking.one.size()) out += "," + _quoted(_asking.one);
        if(_asking.two.size()) out += "," + _quoted(_asking.two);
        out += "]";
      }
      return out + "}";
    }

    // answer what has arrived, then let the application tick: the scene in its
    // own window is drawn there
    void _turn()
    {
      Browser::serve([this](const Browser::Ask &ask, std::string &type) {
        return _answer(ask, type);
      });
      _tell();
      if(_host.tick) _host.tick();
    }

    // nothing is worked out while nobody listens or nothing changed; a slow
    // look every few seconds catches a change nobody said
    void _tell()
    {
      if(!Browser::listeners()) return;
      double now = TimeOfDay();
      bool look = now - _lastTold > 5.;
      if(_dirty || look) {
        _lastTold = now;
        std::string said = _state();
        if(said != _told) {
          if(!_dirty) fprintf(stderr, "The page changed without being told\n");
          _told = said;
          Browser::push("state", said);
        }
        _dirty = false;
      }
      // worth coming for until the page has fetched it: said once
      bool moved = _host.sceneMoved && _host.sceneMoved();
      if(moved && !_toldScene) Browser::push("scene", "1");
      _toldScene = moved;
    }

    static std::string _valueOf(const std::string &body, const std::string &key)
    {
      // at the start of a field: a key looked for anywhere finds itself inside
      // another value
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

    // the lines of a list, as the page is told them
    static std::size_t _lines(const Ui::Field &f)
    {
      std::vector<std::string> labels;
      std::vector<int> values;
      if(f.dynamicChoices) {
        f.dynamicChoices(labels, values);
        return labels.size();
      }
      if(f.list && f.itemLabel) return f.list->size();
      return f.choices.size();
    }

    // FNV-1a over the name
    static unsigned _nameOf(const std::string &what)
    {
      unsigned h = 2166136261u;
      for(std::size_t i = 0; i < what.size(); i++) {
        h ^= (unsigned char)what[i];
        h *= 16777619u;
      }
      return h;
    }

    std::string _actionId(const std::function<void()> &what,
                          const std::string &called)
    {
      _actions.push_back(what);
      _actionNames.push_back(_nameOf(called));
      return ",\"id\":" + std::to_string((int)_actions.size() - 1) +
             ",\"h\":" + std::to_string(_actionNames.back());
    }

    // red, green and blue, or hue, saturation and value; the fourth is the
    // alpha
    static int _channelOf(const Ui::ColourMap &map, int i, int channel,
                          bool hsv)
    {
      Ui::Colour c = map.colour(i);
      if(channel == 3) return c.a;
      if(!hsv) return channel == 0 ? c.r : (channel == 1 ? c.g : c.b);
      int h, sat, v;
      Ui::toHsv(c, h, sat, v);
      return channel == 0 ? h : (channel == 1 ? sat : v);
    }

    static void _setChannelOf(const Ui::ColourMap &map, int i, int channel,
                              int value, bool hsv)
    {
      Ui::Colour c = map.colour(i);
      if(channel == 3) { c.a = (unsigned char)value; }
      else if(!hsv) {
        if(channel == 0) c.r = (unsigned char)value;
        else if(channel == 1) c.g = (unsigned char)value;
        else c.b = (unsigned char)value;
      }
      else {
        int h, sat, v;
        Ui::toHsv(c, h, sat, v);
        if(channel == 0) h = value;
        else if(channel == 1) sat = value;
        else v = value;
        c = Ui::fromHsv(h, sat, v, c.a);
      }
      map.setColour(i, c);
    }

    std::string _fieldId(const Ui::Field &f)
    {
      _fields.push_back(f);
      _fieldNames.push_back(_nameOf(_kindOf(f) + std::string(":") + f.label));
      return ",\"id\":" + std::to_string((int)_fields.size() - 1) +
             ",\"h\":" + std::to_string(_fieldNames.back());
    }

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

    static std::string _madeUp()
    {
      std::random_device chance;
      std::string out;
      for(int i = 0; i < 24; i++) out += "0123456789abcdef"[chance() & 0xf];
      return out;
    }

    // it has to carry the word of the address, and if it says which page it
    // comes from, that page has to be this one
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
      if(ask.path != "/scene" && ask.path.compare(0, 6, "/scene") != 0 &&
         ask.path.compare(0, 7, "/events") != 0) {
        _dirty = true;
      }
      // the page and the pictures are asked for with the word in the address
      std::string path = ask.path.substr(0, ask.path.find('?'));
      if(path == "/") {
        type = "text/html; charset=utf-8";
        return std::string((const char *)browserPage, sizeof(browserPage));
      }
      // the scene is drawn on this side; what the pointer does over the picture
      // comes back through /pointer
      if(ask.path.compare(0, 6, "/scene") == 0) {
        if(!_host.sceneImage) return "";
        int w = 0, h = 0;
        // empty means "you already have this one"; "force" after an action,
        // since what it changes is the page's business
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
        if(f && f->choose) {
          // a list of several says every line chosen, "set=1,4,5", since a
          // click may choose some and let others go
          if(_valueOf(ask.body, "all") == "1") {
            std::vector<bool> on(_lines(*f), false);
            std::string set = _valueOf(ask.body, "set");
            for(std::size_t p = 0; p < set.size();) {
              std::size_t end = set.find(',', p);
              int i = atoi(set.substr(p, end - p).c_str());
              if(i >= 0 && i < (int)on.size()) on[i] = true;
              if(end == std::string::npos) break;
              p = end + 1;
            }
            for(std::size_t i = 0; i < on.size(); i++) f->choose((int)i, on[i]);
          }
          else
            f->choose(at, _valueOf(ask.body, "v") != "0");
        }
        if(f && f->changed) f->changed();
        return "{}";
      }
      // never answered: what Gmsh has to say goes down it, from _tell()
      if(ask.path.compare(0, 7, "/events") == 0) {
        type = "text/event-stream";
        _told = _state();
        _toldScene = false;
        return _told;
      }
      if(path == "/where") {
        // where the page put things, for the bench photographing one window of
        // it
        if(ask.body.size()) { _where = ask.body; return "{}"; }
        return _where;
      }
      if(path == "/close") {
        auto it = _formNamed(_valueOf(ask.body, "form"));
        if(it == _forms.end()) return "{}";
        it->second.shown = false;
        if(_host.formWasClosed && it->second.form)
          _host.formWasClosed(*it->second.form);
        return "{}";
      }
      if(path == "/key") {
        // "j", not "k": "k" is the word that says the request may be asked at
        // all
        std::string name = _valueOf(ask.body, "j");
        int key = _uiKey(name);
        unsigned mods = (unsigned)atoi(_valueOf(ask.body, "m").c_str());
        // a digit or a mark is the one typed, whatever key gives it on this
        // keyboard (Shift, on a French one)
        if(name.size() == 1 && !isalpha((unsigned char)name[0]))
          mods &= ~Ui::ModShift;
        if(key && _sources.keys) {
          for(const Ui::KeyBinding &k : _sources.keys()) {
            if(!k.shortcut.matches(key, mods)) continue;
            if(k.action) k.action();
            if(k.spent) break;
          }
        }
        return "{}";
      }
      if(path == "/console") {
        // the bar over the lines: the filter, Clear, Autoscroll
        if(ask.body.find("filter=") != std::string::npos)
          _said.setFilter(_valueOf(ask.body, "filter"));
        if(_valueOf(ask.body, "clear") == "1") _said.clear();
        std::string follow = _valueOf(ask.body, "follow");
        if(follow.size()) _said.setAutoScroll(follow == "1");
        _dirty = true;
        return "{}";
      }
      if(path == "/size") {
        if(_host.sceneResize)
          _host.sceneResize(atoi(_valueOf(ask.body, "w").c_str()),
                            atoi(_valueOf(ask.body, "h").c_str()));
        return "{}";
      }
      if(path == "/state") return _state();
      if(path == "/files") return _files(_valueOf(ask.body, "dir"));
      if(path == "/answer") {
        if(!_asking.open) return "{}";
        _asking.said = _valueOf(ask.body, "ok") == "1";
        _asking.chose = atoi(_valueOf(ask.body, "chose").c_str());
        if(_asking.said && _asking.kind == "file") {
          _asking.names.clear();
          std::string said = _valueOf(ask.body, "names");
          std::string::size_type at = 0;
          while(at <= said.size()) {
            std::string::size_type end = said.find('\n', at);
            std::string one =
              said.substr(at, end == std::string::npos ? std::string::npos :
                                                         end - at);
            if(one.size()) _asking.names.push_back(one);
            if(end == std::string::npos) break;
            at = end + 1;
          }
        }
        if(_asking.said && _asking.kind == "value")
          _asking.value = _valueOf(ask.body, "value");
        _asking.answered = true;
        return "{}";
      }
      // nothing else may happen while a window that must be answered is up
      if(_asking.open) return "{}";
      if(path == "/do") {
        std::function<void()> *what = _actionAsked(ask);
        if(!what) return "{\"did\":false}";
        if(*what) (*what)();
        return "{\"did\":true}";
      }
      if(path == "/map") {
        // painting a channel, choosing a ready made map, turning to hue and
        // saturation, or moving a number through adjust()
        Ui::Field *f = _fieldAsked(ask);
        if(!f || f->kind != Ui::ColorMap || f->map.empty()) return "{}";
        const Ui::ColourMap &map = f->map;
        const std::string op = _valueOf(ask.body, "op");
        const bool hsv = map.hsv && map.hsv();
        if(op == "paint") {
          int channel = atoi(_valueOf(ask.body, "c").c_str());
          int from = atoi(_valueOf(ask.body, "from").c_str());
          int to = atoi(_valueOf(ask.body, "to").c_str());
          int value = atoi(_valueOf(ask.body, "v").c_str());
          int entries = map.size();
          if(from > to) std::swap(from, to);
          if(from < 0) from = 0;
          if(to >= entries) to = entries - 1;
          if(channel < 0 || channel > 3) channel = 0;
          if(value < 0) value = 0;
          if(value > 255) value = 255;
          for(int i = from; i <= to; i++)
            _setChannelOf(map, i, channel, value, hsv);
          _mapHelp = false;
        }
        else if(op == "press") {
          // as Ui::Shortcut::label() says it
          const std::string k = _valueOf(ask.body, "k");
          int presets = map.numPresets ? map.numPresets() : 0;
          int preset = -1;
          // the digits, the digits with Control, then the first five function
          // keys
          if(k.size() == 1 && k[0] >= '0' && k[0] <= '9')
            preset = k[0] - '0';
          else if(k.size() == 6 && k.compare(0, 5, "Ctrl+") == 0 &&
                  k[5] >= '0' && k[5] <= '9')
            preset = 10 + (k[5] - '0');
          else if(k.size() == 2 && k[0] == 'F' && k[1] >= '1' && k[1] <= '7')
            preset = 20 + (k[1] - '1');
          if(preset >= 0) {
            if(map.choosePreset && preset < presets) map.choosePreset(preset);
          }
          else if(k == "M") {
            if(map.setHsv) map.setHsv(!hsv);
          }
          else if(k == "H") {
            _mapHelp = !_mapHelp;
            return "{}";
          }
          else if(k == "R") {
            if(map.choosePreset && map.preset) map.choosePreset(map.preset());
          }
          else if(k == "Ctrl+C") {
            if(map.copy) map.copy();
            return "{}";
          }
          else if(k == "Ctrl+V") {
            if(map.paste) map.paste();
          }
          else {
            std::vector<Ui::ColourMap::Parameter> knobs =
              map.parameters ? map.parameters() :
                               std::vector<Ui::ColourMap::Parameter>();
            bool did = false;
            for(std::size_t i = 0; i < knobs.size() && !did; i++) {
              if(!knobs[i].up.empty() && knobs[i].up.label() == k) {
                map.adjust(knobs[i], true);
                did = true;
              }
              else if(!knobs[i].down.empty() && knobs[i].down.label() == k) {
                map.adjust(knobs[i], false);
                did = true;
              }
            }
            if(!did) return "{}";
          }
        }
        else
          return "{}";
        if(f->changed) f->changed();
        return "{}";
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
        std::string pane = _valueOf(ask.body, "l");
        auto it = _formNamed(_valueOf(ask.body, "form"));
        if(it == _forms.end()) return "{}";

        bool moved = it->second.pane != pane;
        it->second.pane = pane;
        // picked by the user: it may have something to start
        if(moved && it->second.form) {
          const Ui::Tabs *tabs = _tabsWith(it->second.form->content, pane);
          if(tabs && tabs->chosen) {
            std::function<void(const std::string &)> chosen = tabs->chosen;
            chosen(pane);
          }
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
      case Ui::Direction: {
        double x = 0., y = 0., z = 0.;
        if(sscanf(said.c_str(), "%lf,%lf,%lf", &x, &y, &z) == 3)
          f.setVector(x, y, z);
      } break;
      case Ui::Color: {
        // "#rrggbb": the alpha is kept
        if(said.size() == 7 && said[0] == '#') {
          unsigned long v = strtoul(said.c_str() + 1, nullptr, 16);
          Ui::Colour was = f.getColour();
          f.setColour(Ui::Colour((unsigned char)((v >> 16) & 0xff),
                                 (unsigned char)((v >> 8) & 0xff),
                                 (unsigned char)(v & 0xff), was.a));
        }
      } break;
      case Ui::Choice: {
        std::vector<std::string> labels;
        std::vector<int> values;
        Ui::choices(f, labels, values);
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
      // the page says a value once it is chosen: Enter, or the field left
      if(f.done)
        f.done();
      else if(f.changed)
        f.changed();
    }

    // --- the state, written down: asked of the description afresh, since what it says is only true at the moment it is read

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
      case Ui::Prose: return "prose";
      case Ui::Color: return "colour";
      case Ui::Direction: return "direction";
      case Ui::ColorMap: return "colormap";
      default: return "text";
      }
    }

    std::string _field(const Ui::Field &f)
    {
      std::string out = "{\"label\":" + _quoted(f.label);
      out += ",\"kind\":\"" + std::string(_kindOf(f)) + "\"";
      if(f.kind == Ui::Action) {
        out += _actionId(f.changed, "action:" + f.label);
        if(f.isDefault) out += ",\"byDefault\":true";
        return out + "}";
      }
      if(f.kind == Ui::Prose) {
        // a page of prose
        out += ",\"page\":[";
        std::vector<Ui::Line> page = f.prose ? f.prose() : std::vector<Ui::Line>();
        for(std::size_t i = 0; i < page.size(); i++) {
          const Ui::Line &l = page[i];
          out += i ? ",{" : "{";
          if(l.centred) out += "\"centred\":true,";
          if(l.bullet) out += "\"bullet\":true,";
          if(l.heading) out += "\"heading\":true,";
          out += "\"words\":[";
          for(std::size_t j = 0; j < l.words.size(); j++) {
            const Ui::Words &word = l.words[j];
            out += j ? ",{" : "{";
            out += "\"text\":" + _quoted(word.text);
            if(word.italic) out += ",\"italic\":true";
            if(word.follow)
              out += _actionId(word.follow, "follow:" + word.text);
            out += "}";
          }
          out += "]}";
        }
        out += "]";
        out += _fieldId(f);
        return out + "}";
      }
      if(f.kind == Ui::ColorMap) {
        // what it takes to draw a colour map, not a picture of it
        const Ui::ColourMap &map = f.map;
        if(map.empty()) {
          out += ",\"empty\":true";
          out += _fieldId(f);
          return out + "}";
        }
        std::string of;
        double least = 0., most = 0.;
        map.about(of, least, most);
        out += ",\"of\":" + _quoted(of);
        out += ",\"least\":" + std::to_string(least);
        out += ",\"most\":" + std::to_string(most);
        bool hsv = map.hsv && map.hsv();
        out += ",\"hsv\":";
        out += hsv ? "true" : "false";
        out += ",\"presets\":" +
               std::to_string(map.numPresets ? map.numPresets() : 0);
        out += ",\"preset\":" + std::to_string(map.preset ? map.preset() : 0);
        out += ",\"keys\":";
        out += _mapHelp ? "true" : "false";
        // four bytes apiece in hexadecimal, sent whole
        static const char digits[] = "0123456789abcdef";
        int entries = map.size();
        std::string said;
        said.reserve((std::size_t)entries * 8);
        for(int i = 0; i < entries; i++) {
          Ui::Colour c = map.colour(i);
          unsigned char channel[4] = {c.r, c.g, c.b, c.a};
          for(int k = 0; k < 4; k++) {
            said += digits[channel[k] >> 4];
            said += digits[channel[k] & 15];
          }
        }
        out += ",\"entries\":\"" + said + "\"";
        // the page presses the numbers by their place in this list and lets the
        // description do the arithmetic
        out += ",\"knobs\":[";
        std::vector<Ui::ColourMap::Parameter> knobs =
          map.parameters ? map.parameters() :
                           std::vector<Ui::ColourMap::Parameter>();
        for(std::size_t i = 0; i < knobs.size(); i++) {
          out += i ? ",{" : "{";
          out += "\"name\":" + _quoted(knobs[i].name);
          out += ",\"up\":" + _quoted(knobs[i].up.label());
          out += ",\"down\":" +
                 _quoted(knobs[i].down.empty() ? std::string() :
                                                 knobs[i].down.label());
          out += "}";
        }
        out += "]";
        out += _fieldId(f);
        return out + "}";
      }
      if(f.kind == Ui::Direction) {
        // the direction itself: the page draws the disc
        double x = 0., y = 0., z = 0.;
        f.getVector(x, y, z);
        out += ",\"x\":" + std::to_string(x);
        out += ",\"y\":" + std::to_string(y);
        out += ",\"z\":" + std::to_string(z);
        out += _fieldId(f);
        return out + "}";
      }
      if(f.kind == Ui::Hierarchy) {
        out += ",\"lines\":";
        out += f.hierarchy ? _treeOf(*f.hierarchy) : "[]";
        out += _fieldId(f);
        return out + "}";
      }
      if(f.kind == Ui::List || f.kind == Ui::Menu) {
        std::vector<std::string> labels;
        std::vector<int> values;
        Ui::choices(f, labels, values);
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
        if(f.multiple) out += ",\"several\":true";
        if(f.isCode) out += ",\"code\":true";
        if(f.columnsEm.size()) {
          out += ",\"cols\":[";
          for(std::size_t i = 0; i < f.columnsEm.size(); i++)
            out += (i ? "," : "") + std::to_string(f.columnsEm[i]);
          out += "]";
        }
        out += _fieldId(f);
        return out + "}";
      }
      std::string said;
      if(f.kind == Ui::Check)
        said = f.getFlag() ? "1" : "0";
      else if(f.kind == Ui::Color) {
        Ui::Colour c = f.getColour();
        char hex[16];
        snprintf(hex, sizeof(hex), "#%02x%02x%02x", c.r, c.g, c.b);
        said = hex;
        out += ",\"alpha\":" + std::to_string((int)c.a);
      }
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
        Ui::choices(f, labels, values);
        // on the entry whose value it holds; the page shows and reads back the
        // text
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

    std::string _layout(const Ui::Field &f)
    {
      std::string out;
      if(f.labelBefore) out += ",\"before\":true";
      if(f.wraps) out += ",\"wraps\":true";
      if(f.align == Ui::Centre) out += ",\"align\":\"center\"";
      if(f.align == Ui::Right) out += ",\"align\":\"right\"";
      if(f.disclosure) out += ",\"fold\":true";
      if(f.packed) out += ",\"packed\":true";
      if(f.widthEm > 0.) out += ",\"em\":" + std::to_string(f.widthEm);
      // two halves fill exactly one field
      if(f.widthShare > 0.)
        out += ",\"share\":" + std::to_string(f.widthShare);
      if(f.rows > 1) out += ",\"rows\":" + std::to_string(f.rows);
      if(f.slider && f.maximum > f.minimum) {
        out += ",\"slider\":true";
        out += ",\"least\":" + std::to_string(f.minimum);
        out += ",\"most\":" + std::to_string(f.maximum);
        if(f.step > 0.) out += ",\"step\":" + std::to_string(f.step);
      }
      if(f.tooltip.size()) out += ",\"help\":" + _quoted(f.tooltip);
      if(f.enabled && !f.enabled()) out += ",\"off\":true";
      return out;
    }

    // whether the pane is somewhere under this item
    static bool _holds(const Ui::Item &it, const std::string &pane)
    {
      if(it.kind == Ui::Item::ATabs) {
        for(const auto &t : it.tabs->tabs)
          if(t.first == pane || _holds(t.second, pane)) return true;
      }
      else if(it.kind == Ui::Item::ABox)
        for(const auto &i : it.box->items)
          if(_holds(i, pane)) return true;
      return false;
    }

    static const Ui::Tabs *_tabsWith(const Ui::Item &it,
                                     const std::string &pane)
    {
      if(it.kind == Ui::Item::ATabs) {
        for(const auto &t : it.tabs->tabs) {
          if(t.first == pane) return it.tabs.get();
          if(const Ui::Tabs *found = _tabsWith(t.second, pane)) return found;
        }
      }
      else if(it.kind == Ui::Item::ABox)
        for(const auto &i : it.box->items)
          if(const Ui::Tabs *found = _tabsWith(i, pane)) return found;
      return nullptr;
    }

    // the tree of a form: a box with its items, tabs with their panes
    // -- the others are not asked for what they hold -- a rule, a heading;
    // empty for what is left out
    std::string _item(const Ui::Item &it, const std::string &pane)
    {
      switch(it.kind) {
      case Ui::Item::AField: {
        const Ui::Field &f = it.field;
        if(f.visible && !f.visible()) return "";
        if(f.kind == Ui::Spacer) return "{\"kind\":\"gap\"" + _layout(f) + "}";
        std::string one = _field(f);
        one.insert(one.size() - 1, _layout(f));
        return one;
      }
      case Ui::Item::ABox: {
        const Ui::Box &b = *it.box;
        if(b.visible && !b.visible()) return "";
        std::string out = "{\"kind\":\"box\"";
        if(b.direction == Ui::Box::Across) out += ",\"across\":true";
        if(b.padding == 0.) out += ",\"flush\":true";
        if(b.grid) out += ",\"grid\":true";
        if(b.scrolling) out += ",\"scrolls\":true";
        out += ",\"items\":[";
        bool first = true;
        for(const auto &i : b.items) {
          std::string one = _item(i, pane);
          if(one.empty()) continue;
          if(!first) out += ",";
          first = false;
          out += one;
        }
        return out + "]}";
      }
      case Ui::Item::ATabs: {
        const Ui::Tabs &t = *it.tabs;
        std::size_t on = 0;
        for(std::size_t i = 0; i < t.tabs.size(); i++)
          if(t.tabs[i].first == pane || _holds(t.tabs[i].second, pane)) on = i;
        std::string out = "{\"kind\":\"tabs\",\"tabs\":[";
        for(std::size_t i = 0; i < t.tabs.size(); i++)
          out += (i ? "," : "") + _quoted(t.tabs[i].first);
        // every pane, so that the page can stack them and take the tallest
        out += "],\"on\":" + std::to_string(on) + ",\"panes\":[";
        for(std::size_t i = 0; i < t.tabs.size(); i++) {
          std::string one = _item(t.tabs[i].second, pane);
          out += (i ? "," : "") + (one.empty() ? std::string("null") : one);
        }
        return out + "]}";
      }
      case Ui::Item::AHeading:
        return "{\"kind\":\"heading\",\"text\":" + _quoted(it.text) + "}";
      case Ui::Item::ARule: return "{\"kind\":\"rule\"}";
      default: return "";
      }
    }

    std::string _form(const std::string &which, const formState &state)
    {
      Ui::Form form = state.form ? *state.form : Ui::Form();
      std::string out = "{\"id\":" + _quoted(which);
      out += ",\"name\":" + _quoted(which);
      out += ",\"title\":" + _quoted(form.title);
      out += ",\"pane\":" + _quoted(state.pane);
      // what a list that fills the window is measured against
      out += ",\"leastRows\":" + std::to_string(form.leastRows);
      std::string content = _item(form.content, state.pane);
      out += ",\"content\":" + (content.empty() ? "null" : content);
      return out + "}";
    }

    // nothing below a folded branch is asked of the description
    std::string _line(const Ui::Tree &tree, const std::string &path, int depth)
    {
      Ui::Node node = tree.node(path);
      bool branch = !tree.children(path).empty();
      auto said = _open.find(path);
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
        bool on = b.on && b.on();
        std::string picture = _svg((on && b.glyphOn.size()) ? b.glyphOn : b.glyph);
        if(picture.size()) out += ",\"glyph\":" + _quoted(picture);
        out += ",\"on\":";
        out += on ? "true" : "false";
        if(on && b.onColour) {
          Ui::Colour c = b.onColour();
          char tint[16];
          snprintf(tint, sizeof(tint), "#%02x%02x%02x", c.r, c.g, c.b);
          out += ",\"tint\":" + _quoted(tint);
        }
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
      out += ",\"font\":";
      int points = _sources.settings ? _sources.settings().fontSize : 13;
      out += std::to_string(points > 0 ? points : 13);
      out += ",\"ask\":" + _ask();
      out += ",\"tree\":" + _tree();
      out += ",\"bar\":" + _bar();
      out += ",\"forms\":[";
      bool first = true;
      for(const auto &it : _forms) {
        if(!it.second.shown) continue;
        if(!first) out += ",";
        first = false;
        out += _form(it.first->id, it.second);
      }
      out += "],\"status\":";
      Ui::BarMessage said;
      if(_sources.barMessage) said = _sources.barMessage();
      out += _quoted(said.text);
      out += ",\"messages\":[";
      std::vector<const Ui::Console::Line *> shown = _said.shown();
      std::size_t from = shown.size() > 200 ? shown.size() - 200 : 0;
      for(std::size_t i = from; i < shown.size(); i++)
        out += (i > from ? "," : "") + _quoted(shown[i]->text);
      out += "],\"console\":{\"filter\":" + _quoted(_said.filter());
      out += ",\"follow\":";
      out += _said.autoScroll() ? "true" : "false";
      out += ",\"look\":" + _quoted(_svg(Ui::Console::filterGlyph()));
      out += ",\"tip\":" + _quoted(Ui::Console::filterTip());
      out += ",\"save\":{\"label\":" + _quoted(Ui::Console::saveLabel());
      out += ",\"help\":" + _quoted(Ui::Console::saveTip());
      std::function<void()> save = _sources.saveMessages;
      out += _actionId([save]() { if(save) save(); }, "console:save") + "}";
      out += ",\"clear\":{\"label\":" + _quoted(Ui::Console::clearLabel());
      out += ",\"help\":" + _quoted(Ui::Console::clearTip()) + "}";
      out += ",\"autoScroll\":" + _quoted(Ui::Console::autoScrollLabel());
      out += "}";
      return out + "}";
    }
  };

  backendBrowser *_the = nullptr;

} // namespace

// made once
namespace {
  struct offeringBrowser {
    offeringBrowser()
    {
      Ui::offer("browser", []() -> Ui::Backend * {
        if(!_the) _the = new backendBrowser();
        return _the;
      });
    }
  };
  offeringBrowser _offeringBrowser;
}

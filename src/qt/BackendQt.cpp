// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_QT)

#include <algorithm>
#include <atomic>
#include <clocale>
#include <cstdio>
#include <string>
#include <vector>

#include "qtCommon.h"

#include <QAbstractEventDispatcher>
#include <QApplication>
#include <QClipboard>
#include <QCloseEvent>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDropEvent>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollBar>
#include <QSplitter>
#include <QStatusBar>
#include <QStyleHints>
#include <QSurfaceFormat>
#include <QTimer>
#include <QToolButton>
#include <QTreeWidget>
#include <QVBoxLayout>

// The Qt 6 interface: one QMainWindow -- the menu bar, the tree down the left,
// the scene and the console under it, the bar along the bottom -- and a dock
// widget for each described form (dialogQt.cpp). The loop is Qt's, turned by
// hand, so that check() and wait() can turn it from inside the mesher, and a
// question can run a loop of its own.

// the lines the console said, which it forgets when it is cleared
void qtForgetMessages();

namespace {

  // --- the buttons held, counted for the whole application

  int _buttonsDown = 0;

  class buttonWatch : public QObject {
  public:
    bool eventFilter(QObject *o, QEvent *e) override
    {
      if(e->type() == QEvent::MouseButtonPress)
        _buttonsDown++;
      else if(e->type() == QEvent::MouseButtonRelease && _buttonsDown > 0)
        _buttonsDown--;
      return QObject::eventFilter(o, e);
    }
  };

  // --- the console, with what to do with its lines

  class console : public QPlainTextEdit {
  public:
    void contextMenuEvent(QContextMenuEvent *e) override
    {
      QMenu *menu = createStandardContextMenu();
      menu->addSeparator();
      QObject::connect(menu->addAction("Save Messages As..."),
                       &QAction::triggered, []() {
                         if(qtSources().saveMessages)
                           qtLater(qtSources().saveMessages);
                       });
      QObject::connect(menu->addAction("Clear Messages"), &QAction::triggered,
                       [this]() {
                         clear();
                         qtForgetMessages();
                       });
      menu->exec(e->globalPos());
      delete menu;
    }
  };

  // --- the main window

  class mainWindow : public QMainWindow {
  public:
    QSplitter *side = nullptr, *split = nullptr;
    QWidget *treeBox = nullptr, *footer = nullptr;
    console *messages = nullptr;
    QWidget *buttons = nullptr;
    QPushButton *message = nullptr;
    QProgressBar *progress = nullptr;
    qtTree *tree = nullptr;
    std::string barBuilt, footerBuilt;
    std::vector<std::string> lines;
    bool fullscreen = false, treeWas = true, consoleWas = true;
    bool closing = false;

    void keyPressEvent(QKeyEvent *e) override
    {
      if(!qtMainKey(e->key(), e->modifiers(), e->text()))
        QMainWindow::keyPressEvent(e);
    }
    void closeEvent(QCloseEvent *e) override
    {
      if(closing) {
        e->accept();
        return;
      }
      e->ignore();
      std::function<void()> quit = qtHost().quitting;
      if(quit) qtLater(quit);
    }
    void dragEnterEvent(QDragEnterEvent *e) override
    {
      if(e->mimeData()->hasUrls()) e->acceptProposedAction();
    }
    void dropEvent(QDropEvent *e) override
    {
      std::vector<std::string> paths;
      for(const QUrl &u : e->mimeData()->urls())
        if(u.isLocalFile()) paths.push_back(qtString(u.toLocalFile()));
      std::function<void(const std::vector<std::string> &)> open =
        qtHost().filesDropped;
      if(open && paths.size()) qtLater([open, paths]() { open(paths); });
    }
  };

  mainWindow *_w = nullptr;
  bool _running = false;
  std::atomic<int> _locked(0);
  QElapsedTimer _clock;
  qint64 _lastCheck = -1000000;
  bool _dark = false;

  void _consoleFont(int size)
  {
    if(!_w) return;
    QFont f = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    if(size > 0) f.setPointSize(size);
    _w->messages->setFont(f);
  }

  void _refreshFooter()
  {
    if(!_w) return;
    std::vector<Ui::Button> row = qtSources().tree.footer ?
                                    qtSources().tree.footer() :
                                    std::vector<Ui::Button>();
    std::string shape;
    for(const auto &b : row)
      shape += b.label + (b.on && b.on() ? "+" : "") +
               (b.enabled && !b.enabled() ? "-" : "") + ";";
    if(shape == _w->footerBuilt) return;
    _w->footerBuilt = shape;
    QLayout *h = _w->footer->layout();
    while(QLayoutItem *it = h->takeAt(0)) {
      if(it->widget()) it->widget()->deleteLater();
      delete it;
    }
    for(const auto &b : row)
      h->addWidget(qtButtonWidget(b, []() {
        qtLater([]() {
          if(_w && _w->tree) _w->tree->refresh(false);
          _refreshFooter();
        });
      }));
    _w->footer->setVisible(!row.empty());
  }

  void _fullscreen(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    if(on) {
      _w->treeWas = _w->treeBox->isVisible();
      _w->consoleWas = _w->messages->isVisible();
      _w->showFullScreen();
    }
    else
      _w->showNormal();
    // nothing but the scene
    _w->menuBar()->setVisible(!on);
    _w->statusBar()->setVisible(!on);
    _w->treeBox->setVisible(!on && _w->treeWas);
    _w->messages->setVisible(!on && _w->consoleWas);
  }

  // "*.geo", "*.{geo,msh}", "*.*" as Qt writes a filter
  QString _patterns(const std::string &said)
  {
    std::string all = said, out;
    for(char &c : all)
      if(c == ';' || c == '\t') c = ' ';
    std::size_t at = 0;
    while(at < all.size()) {
      std::size_t end = all.find(' ', at);
      std::string one = all.substr(at, end == std::string::npos ? end : end - at);
      at = end == std::string::npos ? all.size() : end + 1;
      if(one.empty()) continue;
      if(one == "*.*") one = "*";
      std::size_t open = one.find('{'), close = one.find('}');
      if(open != std::string::npos && close != std::string::npos && close > open) {
        std::string head = one.substr(0, open), tail = one.substr(close + 1);
        std::string inside = one.substr(open + 1, close - open - 1);
        std::size_t k = 0;
        while(k <= inside.size()) {
          std::size_t comma = inside.find(',', k);
          std::string part =
            inside.substr(k, comma == std::string::npos ? std::string::npos :
                                                          comma - k);
          out += (out.size() ? " " : "") + head + part + tail;
          if(comma == std::string::npos) break;
          k = comma + 1;
        }
      }
      else
        out += (out.size() ? " " : "") + one;
    }
    return qtString(out);
  }

  // --- the backend

  class backendQt : public Ui::Backend {
  public:
    std::string name() override { return std::string("Qt ") + qVersion(); }

    void setSources(const Sources &sources) override { _sources = sources; }
    const Sources &sources() const { return _sources; }
    void setHost(const Host &host) override { _host = host; }
    const Host &host() const { return _host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(_w) return true;
      if(!qApp) {
        // the scene is drawn with the shader pipeline: OpenGL 3.2 and up, in
        // contexts that share what they can
        QSurfaceFormat format;
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
        format.setDepthBufferSize(24);
        format.setStencilBufferSize(8);
        QSurfaceFormat::setDefaultFormat(format);
        QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
#if defined(HAVE_GTK)
        // Qt's GTK theme loads GTK 3, which cannot live in a process GTK 4
        // is linked into: the portal's reads the same desktop settings. It
        // is chosen from the name of the desktop, which the portal's falls
        // back on too: that name is kept from Qt while it starts
        QByteArray theme = qgetenv("QT_QPA_PLATFORMTHEME");
        static const char *names[] = {"XDG_CURRENT_DESKTOP", "DESKTOP_SESSION",
                                      "XDG_SESSION_DESKTOP", "GDMSESSION",
                                      "GNOME_DESKTOP_SESSION_ID"};
        std::vector<QByteArray> desktop;
        bool hide = theme.isEmpty() || theme.contains("gtk");
        for(const char *n : names) desktop.push_back(qgetenv(n));
        if(hide) {
          qputenv("QT_QPA_PLATFORMTHEME", "xdgdesktopportal");
          for(const char *n : names) qunsetenv(n);
        }
#endif
        QCoreApplication::setApplicationName("Gmsh");
        QGuiApplication::setDesktopFileName("info.gmsh.gmsh");
        // Qt keeps them: they have to live as long as it does
        static int count = 1;
        static char name[] = "gmsh";
        static char *args[] = {name, nullptr};
        new QApplication(count, args);
#if defined(HAVE_GTK)
        for(std::size_t i = 0; hide && i < desktop.size(); i++)
          if(desktop[i].size()) qputenv(names[i], desktop[i]);
#endif
        // the numbers are read and written the C way: Qt took the locale of
        // the environment, and a decimal comma with it
        setlocale(LC_NUMERIC, "C");
        qApp->installEventFilter(new buttonWatch);
        _clock.start();
      }
      if(QGuiApplication::platformName().isEmpty()) {
        if(_host.error) _host.error("Could not open a display");
        return false;
      }
      _build();
      qtSceneStartTimers();
      return true;
    }

    void destroy() override
    {
      _running = false;
      if(!_w) return;
      qtFormsClosingDown();
      qtSceneDestroy();
      mainWindow *w = _w;
      _w = nullptr;
      delete w->tree;
      w->tree = nullptr;
      qtSetMainWindow(nullptr);
      w->closing = true;
      w->close();
      delete w;
      QCoreApplication::processEvents();
    }

    int runLoop() override
    {
      _running = true;
      while(_running && _w)
        QCoreApplication::processEvents(QEventLoop::WaitForMoreEvents);
      return 0;
    }

    void check(bool rateLimited) override
    {
      if(!_w || _locked > 0 || qtSceneDrawing()) return;
      double rate = _sources.settings ? _sources.settings().refreshRate : 0.;
      qint64 now = _clock.elapsed();
      if(rateLimited && rate > 0. && now - _lastCheck < 1000. / rate) return;
      _lastCheck = now;
      QCoreApplication::processEvents();
    }

    bool ready() override { return _w != nullptr; }

    void wait(double seconds, bool force) override
    {
      if(!_w || qtSceneDrawing()) return;
      if(!force && _locked > 0) return;
      if(seconds == 0.) {
        QCoreApplication::processEvents();
        return;
      }
      // a timer wakes the wait up when nothing else does
      if(seconds > 0.) QTimer::singleShot((int)(seconds * 1000.), []() {});
      QCoreApplication::processEvents(QEventLoop::WaitForMoreEvents);
    }

    void lock() override { _locked++; }
    void unlock() override { _locked--; }
    int locked() override { return _locked; }

    void postFromThread(const std::function<void()> &what) override
    {
      QMetaObject::invokeMethod(qApp, [what]() { what(); }, Qt::QueuedConnection);
    }

    void copyText(const std::string &text) override
    {
      QApplication::clipboard()->setText(qtString(text));
      QApplication::clipboard()->setText(qtString(text), QClipboard::Selection);
    }

    void beep() override { QApplication::beep(); }

    // --- messages, the bar

    void addMessage(const std::string &text, int level) override
    {
      if(!_w) return;
      _w->lines.push_back(text);
      static const char *light[] = {"#1a4fa0", nullptr, "#a05a00", "#b00000",
                                    "#707070"};
      static const char *dark[] = {"#8ab4f8", nullptr, "#f0b060", "#ff7070",
                                   "#a0a0a0"};
      // on the colour the console is drawn on, whatever the option says
      bool onDark = _w->messages->palette().color(QPalette::Base).lightness() < 128;
      const char *ink = (level >= 0 && level <= 4) ?
                          (onDark ? dark[level] : light[level]) :
                          nullptr;
      QTextCharFormat format;
      if(ink) format.setForeground(QColor(ink));
      QTextCursor cursor(_w->messages->document());
      cursor.movePosition(QTextCursor::End);
      if(!_w->messages->document()->isEmpty()) cursor.insertBlock();
      cursor.insertText(qtString(text), format);
      _w->messages->verticalScrollBar()->setValue(
        _w->messages->verticalScrollBar()->maximum());
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(_w) lines = _w->lines;
    }

    void refreshBar() override { qtRefreshBar(); }

    void optionChanged(const std::string &name) override
    {
      qtFormOptionChanged(name);
    }

    int numWindows() override { return _w ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(_w && which == 0) _w->setWindowTitle(qtString(title));
    }

    // --- the questions that stop everything

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      QString ask = qtString(question);
      if(hint.size()) ask += "\n" + qtString(hint);
      if(readOnly || hint.size() || value.find('\n') != std::string::npos) {
        // several lines: a little editor, or what is shown
        QDialog d(_w);
        d.setWindowTitle("Gmsh");
        QVBoxLayout *v = new QVBoxLayout(&d);
        QLabel *say = new QLabel(ask);
        say->setWordWrap(true);
        v->addWidget(say);
        QPlainTextEdit *text = new QPlainTextEdit(qtString(value));
        text->setReadOnly(readOnly);
        text->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
        text->setMinimumSize(500, readOnly ? 300 : 120);
        v->addWidget(text);
        QDialogButtonBox *buttons = new QDialogButtonBox(
          readOnly ? QDialogButtonBox::Close :
                     QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        QObject::connect(buttons, &QDialogButtonBox::accepted, &d, &QDialog::accept);
        QObject::connect(buttons, &QDialogButtonBox::rejected, &d, &QDialog::reject);
        v->addWidget(buttons);
        bool ok = d.exec() == QDialog::Accepted && !readOnly;
        if(ok) value = qtString(text->toPlainText());
        return ok;
      }
      bool ok = false;
      QString said = QInputDialog::getText(_w, "Gmsh", ask, QLineEdit::Normal,
                                           qtString(value), &ok);
      if(ok) value = qtString(said);
      return ok;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      QMessageBox box(_w);
      box.setWindowTitle("Gmsh");
      box.setText(qtString(question));
      QPushButton *said[3] = {nullptr, nullptr, nullptr};
      const std::string *labels[3] = {&zero, &one, &two};
      for(int i = 0; i < 3; i++)
        if(labels[i]->size())
          said[i] = box.addButton(qtString(*labels[i]), QMessageBox::ActionRole);
      // Return presses the second, or the only one, as fl_choice() has it
      if(said[1])
        box.setDefaultButton(said[1]);
      else if(said[0])
        box.setDefaultButton(said[0]);
      if(said[0]) box.setEscapeButton(said[0]);
      box.exec();
      for(int i = 0; i < 3; i++)
        if(said[i] && box.clickedButton() == said[i]) return i;
      return 0;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      QStringList filters;
      for(const auto &f : formats) {
        QString p = _patterns(f.pattern);
        filters << (f.name.size() ? qtString(f.name) + " (" + p + ")" : p);
      }
      QString joined = filters.join(";;");
      QString from = names.empty() ? QString() : qtString(names[0]);
      QString chosen = filters.isEmpty() ? QString() : filters[0];
      std::vector<std::string> out;
      if(mode == Create) {
        QString name =
          QFileDialog::getSaveFileName(_w, qtString(title), from, joined, &chosen);
        if(name.size()) out.push_back(qtString(name));
      }
      else if(mode == OpenSeveral) {
        for(const QString &name : QFileDialog::getOpenFileNames(
              _w, qtString(title), from, joined, &chosen))
          out.push_back(qtString(name));
      }
      else {
        QString name =
          QFileDialog::getOpenFileName(_w, qtString(title), from, joined, &chosen);
        if(name.size()) out.push_back(qtString(name));
      }
      // several formats may share an extension: the one picked is said
      if(chosenFormat) *chosenFormat = (int)filters.indexOf(chosen);
      if(out.empty()) return false;
      names = out;
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      _dark = dark;
      QGuiApplication::styleHints()->setColorScheme(dark ? Qt::ColorScheme::Dark :
                                                           Qt::ColorScheme::Light);
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    {
      qtShowForm(form, show);
    }
    bool formVisible(const Ui::Form &form) override
    {
      return qtFormVisible(form);
    }
    std::string formPane(const Ui::Form &form) override
    {
      return qtFormPane(form);
    }
    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      qtSetFormPane(form, pane);
    }
    void reloadForm(const Ui::Form &form) override { qtReloadForm(form); }
    void rebuildForm(const Ui::Form &form) override { qtReloadForm(form); }
    void dropForm(const Ui::Form &form) override { qtDropForm(form); }

    void refreshMenus() override { qtRefreshMenuBar(_w); }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &) override
    {
      qtPopupMenu(items);
    }

    void refreshTree(bool rebuild) override
    {
      if(!_w || !_w->tree) return;
      _w->tree->setTree(_sources.tree);
      _w->tree->refresh(rebuild);
      _refreshFooter();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(_w && _w->tree) _w->tree->open(name, open);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return _w && _w->tree && _w->tree->isOpen(name);
    }

    void showTree() override
    {
      if(_w) _w->treeBox->setVisible(true);
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      _refreshFooter();
    }

    void showConsole(bool show) override
    {
      if(_w) _w->messages->setVisible(show);
    }

    bool consoleVisible() override
    {
      return _w && _w->messages->isVisible();
    }

    // --- the interface as a whole

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      if(what == "new")
        qtSceneNewWindow();
      else if(what == "split_h")
        qtSceneSplit('h', .5);
      else if(what == "split_v")
        qtSceneSplit('v', .5);
      else if(what == "split_u")
        qtSceneSplit('u', 0.);
      else if(what == "minimize")
        _w->showMinimized();
      else if(what == "zoom") {
        if(_w->isMaximized())
          _w->showNormal();
        else
          _w->showMaximized();
      }
      else if(what == "fullscreen")
        _fullscreen(!_w->fullscreen);
      else if(what == "front") {
        _w->raise();
        _w->activateWindow();
      }
      else if(what == "show_hide_tree")
        _w->treeBox->setVisible(!_w->treeBox->isVisible());
      else if(what == "copy")
        qtSceneCopy();
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    bool supports(const std::string &what) override
    {
      // the tree is a pane of the main window, never a window of its own
      return what != "attach_detach";
    }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      qtSceneSize(l.sceneWidth, l.sceneHeight);
      if(_w->treeBox->isVisible()) l.treeWidth = _w->treeBox->width();
      if(_w->messages->isVisible()) l.consoleHeight = _w->messages->height();
      l.treeDetached = 0;
      return l;
    }

    void setSceneSize(int width, int height) override
    {
      if(!_w) return;
      int sw = 0, sh = 0;
      qtSceneSize(sw, sh);
      int ww = _w->width(), wh = _w->height();
      if(width >= 0) ww += width - sw;
      if(height >= 0) wh += height - sh;
      _w->resize(ww, wh);
    }

    void setConsoleFontSize(int size) override { _consoleFont(size); }

    void setTreeWidth(int width) override
    {
      if(!_w || width < 0) return;
      QList<int> sizes = _w->side->sizes();
      if(sizes.size() == 2) {
        int all = sizes[0] + sizes[1];
        _w->side->setSizes({width, std::max(1, all - width)});
      }
    }

    void enableTooltips(bool on) override {}

  private:
    Sources _sources;
    Host _host;

    void _build()
    {
      const Settings set = _sources.settings();
      _dark = set.darkScheme;
      if(set.darkScheme)
        QGuiApplication::styleHints()->setColorScheme(Qt::ColorScheme::Dark);
      if(set.fontSize > 0) {
        QFont f = QApplication::font();
        f.setPointSize(set.fontSize);
        QApplication::setFont(f);
      }
      _w = new mainWindow;
      _w->setWindowTitle("Gmsh");
      _w->setAcceptDrops(true);
      _w->setDockNestingEnabled(true);
      qtSetMainWindow(_w);

      // the tree, and the buttons of the solver under it
      _w->treeBox = new QWidget;
      QVBoxLayout *tv = new QVBoxLayout(_w->treeBox);
      tv->setContentsMargins(0, 0, 0, 0);
      tv->setSpacing(2);
      _w->tree = new qtTree(_sources.tree, false, []() {
        qtLater([]() {
          if(_w && _w->tree) _w->tree->refresh(false);
        });
      });
      tv->addWidget(_w->tree->widget(), 1);
      _w->footer = new QWidget;
      QHBoxLayout *fh = new QHBoxLayout(_w->footer);
      fh->setContentsMargins(4, 2, 4, 4);
      tv->addWidget(_w->footer);
      _w->treeBox->setVisible(set.showModuleMenu);

      // the scene over the console
      _w->messages = new console;
      _w->messages->setReadOnly(true);
      _w->messages->setLineWrapMode(QPlainTextEdit::NoWrap);
      _consoleFont(set.consoleFontSize);
      _w->split = new QSplitter(Qt::Vertical);
      _w->split->addWidget(qtSceneWidget());
      _w->split->addWidget(_w->messages);
      _w->split->setStretchFactor(0, 1);
      _w->split->setStretchFactor(1, 0);
      _w->split->setChildrenCollapsible(false);

      _w->side = new QSplitter(Qt::Horizontal);
      _w->side->addWidget(_w->treeBox);
      _w->side->addWidget(_w->split);
      _w->side->setStretchFactor(0, 0);
      _w->side->setStretchFactor(1, 1);
      _w->setCentralWidget(_w->side);

      // the bar: the buttons, the message one presses to show the messages,
      // the progress of what runs
      QStatusBar *bar = _w->statusBar();
      bar->setSizeGripEnabled(true);
      _w->buttons = new QWidget;
      QHBoxLayout *bh = new QHBoxLayout(_w->buttons);
      bh->setContentsMargins(0, 0, 0, 0);
      bh->setSpacing(0);
      bar->addWidget(_w->buttons);
      _w->message = new QPushButton;
      _w->message->setFlat(true);
      _w->message->setStyleSheet("text-align: left; padding: 0 6px;");
      _w->message->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
      QObject::connect(_w->message, &QPushButton::clicked, []() {
        if(qtSources().barPressed) qtLater(qtSources().barPressed);
      });
      bar->addWidget(_w->message, 1);
      _w->progress = new QProgressBar;
      _w->progress->setRange(0, 1000);
      _w->progress->setFixedWidth(200);
      _w->progress->setTextVisible(true);
      _w->progress->hide();
      bar->addPermanentWidget(_w->progress);

      qtRefreshMenuBar(_w);
      _refreshFooter();
      qtRefreshBar();

      int treeWidth = set.treeWidth > 50 ? set.treeWidth : 300;
      int w = (set.sceneWidth > 100 ? set.sceneWidth : 700) + treeWidth;
      int sceneHeight = set.sceneHeight > 100 ? set.sceneHeight : 600;
      int consoleHeight = set.consoleHeight > 0 ? set.consoleHeight : 150;
      _w->resize(w, sceneHeight + consoleHeight + 60);
      _w->side->setSizes({treeWidth, w - treeWidth});
      _w->split->setSizes({sceneHeight, consoleHeight});
      _w->show();
    }
  };

  backendQt *_the = nullptr;

} // namespace

void qtForgetMessages()
{
  if(_w) _w->lines.clear();
}

bool qtButtonDown() { return _buttonsDown > 0; }

void qtRefreshBar()
{
  if(!_w || !qtSources().barButtons) return;
  std::vector<Ui::BarButton> bar = qtSources().barButtons();
  std::string shape;
  for(const auto &b : bar)
    shape += b.label + "|" + b.labelOn + (b.gapBefore ? "^" : "") +
             (b.menu ? "v" : "") + ";";
  QHBoxLayout *h = (QHBoxLayout *)_w->buttons->layout();
  if(shape != _w->barBuilt) {
    _w->barBuilt = shape;
    while(QLayoutItem *it = h->takeAt(0)) {
      if(it->widget()) it->widget()->deleteLater();
      delete it;
    }
    for(std::size_t i = 0; i < bar.size(); i++) {
      if(bar[i].gapBefore && i) h->addSpacing(qtPx(.6));
      QToolButton *b = new QToolButton;
      b->setAutoRaise(true);
      b->setText(qtString(bar[i].label));
      if(bar[i].widthEm > 0.) b->setMinimumWidth(qtPx(bar[i].widthEm));
      std::size_t k = i;
      QObject::connect(b, &QToolButton::clicked, [k]() {
        std::vector<Ui::BarButton> now = qtSources().barButtons();
        if(k >= now.size()) return;
        const Ui::BarButton &one = now[k];
        if(one.menu) {
          qtPopupMenu(one.menu());
          return;
        }
        Qt::KeyboardModifiers m = QGuiApplication::keyboardModifiers();
        bool reverse = (m & Qt::ShiftModifier) != 0;
        bool sync = (m & Qt::ControlModifier) != 0;
        std::function<void(bool, bool)> what = one.action;
        qtLater([what, reverse, sync]() {
          if(what) what(reverse, sync);
          qtRefreshBar();
        });
      });
      h->addWidget(b);
    }
  }
  std::size_t i = 0;
  for(int k = 0; k < h->count() && i < bar.size(); k++) {
    QToolButton *b = dynamic_cast<QToolButton *>(h->itemAt(k)->widget());
    if(!b) continue;
    const Ui::BarButton &one = bar[i++];
    bool on = one.on && one.on();
    std::string label = (on && one.labelOn.size()) ? one.labelOn : one.label;
    b->setText(qtString(label));
    b->setEnabled(one.enabled ? one.enabled() : true);
    if(one.tooltip.size() && qtSources().settings().tooltips)
      b->setToolTip(qtString(one.tooltip));
    QString style;
    if(one.alert && one.alert())
      style = "QToolButton { background: #b02020; color: white; }";
    else if(on && one.onColour) {
      Ui::Colour c = one.onColour();
      style = QString("QToolButton { background: rgb(%1,%2,%3); color: %4; }")
                .arg(c.r)
                .arg(c.g)
                .arg(c.b)
                .arg((c.r * 299 + c.g * 587 + c.b * 114) / 1000 > 140 ? "black" :
                                                                      "white");
    }
    else if(on)
      style = "QToolButton { font-weight: bold; }";
    if(b->styleSheet() != style) b->setStyleSheet(style);
  }
  if(qtSources().barMessage) {
    Ui::BarMessage m = qtSources().barMessage();
    _w->message->setText(qtString(m.text));
    QString colour = m.weight == Ui::MessageError   ? "color: #c03030;" :
                     m.weight == Ui::MessageWarning ? "color: #b07000;" :
                                                      "";
    _w->message->setStyleSheet("text-align: left; padding: 0 6px;" + colour);
    // the progress of what has finished stays said, at nought or at the end
    bool going = m.running && m.fraction > 0. && m.fraction < 1.;
    _w->progress->setVisible(going);
    if(going) {
      _w->progress->setValue((int)(1000. * m.fraction));
      _w->progress->setFormat(qtString(m.progressText));
    }
  }
  if(qtSources().barTooltip && qtSources().settings().tooltips)
    _w->message->setToolTip(qtString(qtSources().barTooltip()));
}

bool qtMainKey(int qtKey, Qt::KeyboardModifiers qtMods, const QString &text)
{
  switch(qtKey) {
  case Qt::Key_Shift:
  case Qt::Key_Control:
  case Qt::Key_Alt:
  case Qt::Key_Meta:
  case Qt::Key_AltGr:
  case Qt::Key_Super_L:
  case Qt::Key_Super_R: return false;
  default: break;
  }
  int key = 0;
  unsigned mods = 0;
  if(!qtUiKey(qtKey, qtMods, text, key, mods)) return false;
  if(key == Ui::KeyEscape && _w && _w->fullscreen) {
    _fullscreen(false);
    return true;
  }
  if(!qtSources().keys) return false;
  bool taken = false;
  for(const Ui::KeyBinding &k : qtSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    taken = true;
    if(k.action) qtLater(k.action);
    if(k.spent) break;
  }
  if(taken) qtLater([]() { qtRefreshBar(); });
  return taken;
}

const Ui::Backend::Sources &qtSources()
{
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

const Ui::Backend::Host &qtHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

// made once
namespace {
  struct offeringQt {
    offeringQt()
    {
      Ui::offer("qt", []() -> Ui::Backend * {
        if(!_the) _the = new backendQt();
        return _the;
      });
    }
  };
  offeringQt _offeringQt;
} // namespace

#endif

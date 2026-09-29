// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <clocale>
#include <cstdio>
#include <string>
#include <vector>

#include "qtCommon.h"
#include "Console.h"

#include <QAbstractEventDispatcher>
#include <QApplication>
#include <QClipboard>
#include <QCloseEvent>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDockWidget>
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
#include <QLineEdit>
#include <QCheckBox>
#include <QScrollBar>
#include <QSplitter>
#include <QStatusBar>
#include <QStyleHints>
#include <QSurfaceFormat>
#include <QTimer>
#include <QToolButton>
#include <QTreeWidget>
#include <QVBoxLayout>

#if defined(HAVE_DLOPEN)
#include <dlfcn.h>
#endif

// The Qt 6 interface: one QMainWindow -- the menu bar, the tree down the left,
// the scene and the console under it, the bar along the bottom -- and a dock
// widget for each described form (dialogQt.cpp). The loop is Qt's, turned by
// hand, so that check() and wait() can turn it from inside the mesher, and a
// question can run a loop of its own.

// the lines the console said, which it forgets when it is cleared
void qtClearConsole();

namespace {

  // GTK 4 in the process already: whoever brought it, it is there before Qt
  bool _gtk4Loaded()
  {
#if defined(HAVE_DLOPEN)
    typedef unsigned (*version)();
    version major = (version)dlsym(RTLD_DEFAULT, "gtk_get_major_version");
    return major && major() == 4;
#else
    return false;
#endif
  }

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
                       []() { qtClearConsole(); });
      menu->exec(e->globalPos());
      delete menu;
    }
  };

  // --- the main window

  class mainWindow : public QMainWindow {
  public:
    QSplitter *split = nullptr;
    // the tree and the buttons under it, in a dock of its own: docked on the
    // left, or floating -- detached -- as a window of its own
    QDockWidget *treeDock = nullptr;
    QWidget *treeBox = nullptr, *footer = nullptr;
    console *messages = nullptr;
    // the bar over the lines, and the lines as a whole
    QWidget *consoleBox = nullptr;
    QLineEdit *filter = nullptr;
    QCheckBox *follow = nullptr;
    treeQt *tree = nullptr;
    std::string footerBuilt;
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console said;
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

  // --- the console: a line in its colour, the lines again when the filter
  // changed, the bar over them

  void _consoleLine(const std::string &text, int level, bool follow)
  {
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
    if(follow && _w->said.autoScroll())
      _w->messages->verticalScrollBar()->setValue(
        _w->messages->verticalScrollBar()->maximum());
  }

  void _refillConsole()
  {
    _w->messages->clear();
    for(const Ui::Console::Line *l : _w->said.shown())
      _consoleLine(l->text, l->level, false);
    if(_w->said.autoScroll())
      _w->messages->verticalScrollBar()->setValue(
        _w->messages->verticalScrollBar()->maximum());
  }

  QWidget *_consoleBox()
  {
    QWidget *box = new QWidget;
    QVBoxLayout *v = new QVBoxLayout(box);
    v->setContentsMargins(0, 0, 0, 0);
    v->setSpacing(0);
    QWidget *bar = new QWidget;
    QHBoxLayout *h = new QHBoxLayout(bar);
    h->setContentsMargins(2, 2, 2, 2);
    h->setSpacing(4);
    bool tips = qtSources().settings().tooltips;
    _w->filter = new QLineEdit;
    _w->filter->setClearButtonEnabled(true);
    _w->filter->setFixedWidth(qtPx(15.));
    QIcon look = qtGlyph(Ui::Console::filterGlyph(),
                         box->palette().text().color());
    if(!look.isNull()) _w->filter->addAction(look, QLineEdit::LeadingPosition);
    if(tips) _w->filter->setToolTip(Ui::Console::filterTip());
    QObject::connect(_w->filter, &QLineEdit::textChanged, [](const QString &t) {
      if(_w && _w->said.setFilter(qtString(t))) _refillConsole();
    });
    h->addWidget(_w->filter);
    QPushButton *save = new QPushButton(Ui::Console::saveLabel());
    save->setAutoDefault(false);
    if(tips) save->setToolTip(Ui::Console::saveTip());
    QObject::connect(save, &QPushButton::clicked, []() {
      if(qtSources().saveMessages) qtLater(qtSources().saveMessages);
    });
    h->addWidget(save);
    QPushButton *clear = new QPushButton(Ui::Console::clearLabel());
    clear->setAutoDefault(false);
    if(tips) clear->setToolTip(Ui::Console::clearTip());
    QObject::connect(clear, &QPushButton::clicked, []() { qtClearConsole(); });
    h->addWidget(clear);
    _w->follow = new QCheckBox(Ui::Console::autoScrollLabel());
    _w->follow->setChecked(_w->said.autoScroll());
    QObject::connect(_w->follow, &QCheckBox::toggled, [](bool on) {
      if(!_w) return;
      _w->said.setAutoScroll(on);
      if(on)
        _w->messages->verticalScrollBar()->setValue(
          _w->messages->verticalScrollBar()->maximum());
    });
    h->addWidget(_w->follow);
    h->addStretch(1);
    v->addWidget(bar);
    v->addWidget(_w->messages, 1);
    return box;
  }

  void _refreshFooter()
  {
    if(!_w) return;
    std::vector<Ui::Button> row = qtSources().tree.footer ?
                                    qtSources().tree.footer() :
                                    std::vector<Ui::Button>();
    std::string shape = Ui::signature(row);
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

  // the tree floating as a window of its own, where it was last, or docked
  // again on the left
  void _detachTree(bool detached)
  {
    if(!_w || detached == _w->treeDock->isFloating()) return;
    if(!detached) {
      _w->treeDock->setFloating(false);
      return;
    }
    const Ui::Backend::Settings set = qtSources().settings();
    int width = _w->treeDock->width();
    int h = set.treeHeight > 0 ? set.treeHeight : 600;
    int x = set.treeX, y = set.treeY;
    _w->treeDock->setFloating(true);
    _w->treeDock->show();
    // once it is a window: Qt gives a floating dock the size it had
    qtLater([width, h, x, y]() {
      if(!_w || !_w->treeDock->isFloating()) return;
      if(qtPlacesWindows() && (x > 0 || y > 0))
        _w->treeDock->setGeometry(x, y, width, h);
      else
        _w->treeDock->resize(width, h);
    });
  }

  void _fullscreen(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    if(on) {
      _w->treeWas = _w->treeDock->isVisible();
      _w->consoleWas = _w->consoleBox->isVisible();
      _w->showFullScreen();
    }
    else
      _w->showNormal();
    // nothing but the scene
    _w->menuBar()->setVisible(!on);
    _w->statusBar()->setVisible(!on);
    _w->treeDock->setVisible(!on && _w->treeWas);
    _w->consoleBox->setVisible(!on && _w->consoleWas);
  }

  // as Qt writes a filter: the patterns separated by blanks
  QString _patterns(const Ui::Backend::FileFormat &f)
  {
    std::string out;
    for(const auto &p : f.patterns()) out += (out.size() ? " " : "") + p;
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
        // Qt's GTK theme loads GTK 3, which cannot live in a process GTK 4
        // is already in (the GTK interface, for one): the portal's reads the
        // same desktop settings. It is chosen from the name of the desktop,
        // which the portal's falls back on too: that name is kept from Qt
        // while it starts
        QByteArray theme = qgetenv("QT_QPA_PLATFORMTHEME");
        static const char *names[] = {"XDG_CURRENT_DESKTOP", "DESKTOP_SESSION",
                                      "XDG_SESSION_DESKTOP", "GDMSESSION",
                                      "GNOME_DESKTOP_SESSION_ID"};
        std::vector<QByteArray> desktop;
        bool hide = _gtk4Loaded() && (theme.isEmpty() || theme.contains("gtk"));
        for(const char *n : names) desktop.push_back(qgetenv(n));
        if(hide) {
          qputenv("QT_QPA_PLATFORMTHEME", "xdgdesktopportal");
          for(const char *n : names) qunsetenv(n);
        }
        QCoreApplication::setApplicationName("Gmsh");
        QGuiApplication::setDesktopFileName("info.gmsh.gmsh");
        // Qt keeps them: they have to live as long as it does
        static int count = 1;
        static char name[] = "gmsh";
        static char *args[] = {name, nullptr};
        new QApplication(count, args);
        for(std::size_t i = 0; hide && i < desktop.size(); i++)
          if(desktop[i].size()) qputenv(names[i], desktop[i]);
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
      if(_w->said.add(text, level)) _consoleLine(text, level, true);
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(_w) lines = _w->said.texts();
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
        QString p = _patterns(f);
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
      if(_w) _w->treeDock->setVisible(true);
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      _refreshFooter();
    }

    void showConsole(bool show) override
    {
      if(_w) _w->consoleBox->setVisible(show);
    }

    bool consoleVisible() override
    {
      return _w && _w->consoleBox->isVisible();
    }

    // --- the interface as a whole

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      if(what == "new")
        qtSceneNewWindow();
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
        _w->treeDock->setVisible(!_w->treeDock->isVisible());
      else if(what == "attach_detach")
        _detachTree(!_w->treeDock->isFloating());
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    void detachTree(bool detached) override { _detachTree(detached); }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      qtSceneSize(l.sceneWidth, l.sceneHeight);
      if(qtPlacesWindows()) {
        QPoint at = _w->pos();
        l.sceneX = at.x();
        l.sceneY = at.y();
        qtFormPosition(l.dialogX, l.dialogY);
      }
      bool floating = _w->treeDock->isFloating();
      if(_w->treeDock->isVisible() && !floating)
        l.treeWidth = _w->treeDock->width();
      if(_w->consoleBox->isVisible())
        l.consoleHeight = _w->consoleBox->height();
      l.treeDetached = floating ? 1 : 0;
      if(floating && qtPlacesWindows()) {
        QRect g = _w->treeDock->geometry();
        l.treeX = g.x();
        l.treeY = g.y();
        l.treeHeight = g.height();
      }
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
      if(!_w || width < 0 || _w->treeDock->isFloating()) return;
      _w->resizeDocks({_w->treeDock}, {width}, Qt::Horizontal);
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
      _w->tree = new treeQt(_sources.tree, false, []() {
        qtLater([]() {
          if(_w && _w->tree) _w->tree->refresh(false);
        });
      });
      tv->addWidget(_w->tree->widget(), 1);
      _w->footer = new QWidget;
      QHBoxLayout *fh = new QHBoxLayout(_w->footer);
      fh->setContentsMargins(4, 2, 4, 4);
      tv->addWidget(_w->footer);

      // the scene over the console
      _w->messages = new console;
      _w->messages->setReadOnly(true);
      _w->messages->setLineWrapMode(QPlainTextEdit::NoWrap);
      _consoleFont(set.consoleFontSize);
      _w->consoleBox = _consoleBox();
      _w->split = new QSplitter(Qt::Vertical);
      _w->split->addWidget(qtSceneWidget());
      _w->split->addWidget(_w->consoleBox);
      _w->split->setStretchFactor(0, 1);
      _w->split->setStretchFactor(1, 0);
      _w->split->setChildrenCollapsible(false);

      _w->setCentralWidget(_w->split);
      _w->treeDock = new QDockWidget("Gmsh", _w);
      _w->treeDock->setObjectName("gmshTree");
      // it goes back with the menu or a double click on its title; closed, it
      // could not be had back
      _w->treeDock->setFeatures(QDockWidget::DockWidgetMovable |
                                QDockWidget::DockWidgetFloatable);
      _w->treeDock->setAllowedAreas(Qt::LeftDockWidgetArea |
                                    Qt::RightDockWidgetArea);
      _w->treeDock->setWidget(_w->treeBox);
      // docked, a pane beside the scene with nothing over it
      _w->treeDock->setTitleBarWidget(new QWidget);
      QObject::connect(_w->treeDock, &QDockWidget::topLevelChanged,
                       [](bool floating) {
                         if(!_w) return;
                         QWidget *was = _w->treeDock->titleBarWidget();
                         _w->treeDock->setTitleBarWidget(floating ? nullptr :
                                                                    new QWidget);
                         if(was) was->deleteLater();
                       });
      _w->addDockWidget(Qt::LeftDockWidgetArea, _w->treeDock);
      _w->treeDock->setVisible(set.showModuleMenu);

      // the bar: the buttons, the message one presses to show the messages,
      // the progress of what runs
      QStatusBar *bar = _w->statusBar();
      bar->setSizeGripEnabled(true);
      bar->addWidget(qtMakeBar(), 1);

      qtRefreshMenuBar(_w);
      _refreshFooter();
      qtRefreshBar();

      int treeWidth = set.treeWidth > 50 ? set.treeWidth : 300;
      int w = (set.sceneWidth > 100 ? set.sceneWidth : 700) + treeWidth;
      int sceneHeight = set.sceneHeight > 100 ? set.sceneHeight : 600;
      int consoleHeight = set.consoleHeight > 0 ? set.consoleHeight : 150;
      _w->resize(w, sceneHeight + consoleHeight + 60);
      _w->resizeDocks({_w->treeDock}, {treeWidth}, Qt::Horizontal);
      _w->split->setSizes({sceneHeight, consoleHeight});
      if(qtPlacesWindows() && (set.sceneX > 0 || set.sceneY > 0))
        _w->move(set.sceneX, set.sceneY);
      _w->show();
      if(set.detachedTree) _detachTree(true);
    }
  };

  backendQt *_the = nullptr;

} // namespace

void qtClearConsole()
{
  if(!_w) return;
  _w->said.clear();
  _w->messages->clear();
}

bool qtButtonDown() { return _buttonsDown > 0; }

bool qtPlacesWindows()
{
  return !QGuiApplication::platformName().startsWith("wayland");
}

namespace {

  // a bar, of the main window or of a graphic window of its own
  struct barQt {
    QWidget *box = nullptr, *buttons = nullptr;
    QPushButton *message = nullptr;
    QProgressBar *progress = nullptr;
    std::string built;
  };

  std::vector<barQt *> &_bars()
  {
    static std::vector<barQt *> bars;
    return bars;
  }

  void _refreshBar(barQt *said, const std::vector<Ui::BarButton> &bar)
  {
    std::string shape = Ui::signature(bar);
    QHBoxLayout *h = (QHBoxLayout *)said->buttons->layout();
    if(shape != said->built) {
      said->built = shape;
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
      std::string glyph = (on && one.glyphOn.size()) ? one.glyphOn : one.glyph;
      b->setEnabled(one.enabled ? one.enabled() : true);
      if(one.tooltip.size() && qtSources().settings().tooltips)
        b->setToolTip(qtString(one.tooltip));
      QString style;
      QColor ink = b->palette().buttonText().color();
      if(one.alert && one.alert()) {
        style = "QToolButton { background: #b02020; color: white; }";
        ink = Qt::white;
      }
      else if(on && one.onColour) {
        Ui::Colour c = one.onColour();
        bool light = (c.r * 299 + c.g * 587 + c.b * 114) / 1000 > 140;
        style = QString("QToolButton { background: rgb(%1,%2,%3); color: %4; }")
                  .arg(c.r)
                  .arg(c.g)
                  .arg(c.b)
                  .arg(light ? "black" : "white");
        ink = light ? Qt::black : Qt::white;
      }
      else if(on)
        style = "QToolButton { font-weight: bold; }";
      if(b->styleSheet() != style) b->setStyleSheet(style);
      // the picture when there is one, the label otherwise
      QIcon picture = qtGlyph(glyph, ink);
      std::string shown = label + "|" + glyph + "|" + qtString(ink.name());
      if(b->property("gmshShown").toString() != qtString(shown)) {
        b->setProperty("gmshShown", qtString(shown));
        if(picture.isNull()) {
          b->setIcon(QIcon());
          b->setText(qtString(label));
        }
        else {
          b->setText("");
          b->setIcon(picture);
          b->setIconSize(QSize(qtPx(1.), qtPx(1.)));
        }
      }
    }
    if(qtSources().barMessage) {
      Ui::BarMessage m = qtSources().barMessage();
      said->message->setText(qtString(m.text));
      QString colour = m.weight == Ui::MessageError   ? "color: #c03030;" :
                       m.weight == Ui::MessageWarning ? "color: #b07000;" :
                                                        "";
      said->message->setStyleSheet("text-align: left; padding: 0 6px;" +
                                   colour);
      // the progress of what has finished stays said, at nought or at the end
      bool going = m.running && m.fraction > 0. && m.fraction < 1.;
      said->progress->setVisible(going);
      if(going) {
        said->progress->setValue((int)(1000. * m.fraction));
        said->progress->setFormat(qtString(m.progressText));
      }
    }
    if(qtSources().barTooltip && qtSources().settings().tooltips)
      said->message->setToolTip(qtString(qtSources().barTooltip()));
  }

} // namespace

QWidget *qtMakeBar()
{
  barQt *said = new barQt;
  said->box = new QWidget;
  QHBoxLayout *row = new QHBoxLayout(said->box);
  row->setContentsMargins(0, 0, 0, 0);
  row->setSpacing(0);
  said->buttons = new QWidget;
  QHBoxLayout *bh = new QHBoxLayout(said->buttons);
  bh->setContentsMargins(0, 0, 0, 0);
  bh->setSpacing(0);
  row->addWidget(said->buttons);
  said->message = new QPushButton;
  said->message->setFlat(true);
  said->message->setStyleSheet("text-align: left; padding: 0 6px;");
  said->message->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
  QObject::connect(said->message, &QPushButton::clicked, []() {
    if(qtSources().barPressed) qtLater(qtSources().barPressed);
  });
  row->addWidget(said->message, 1);
  said->progress = new QProgressBar;
  said->progress->setRange(0, 1000);
  said->progress->setFixedWidth(200);
  said->progress->setTextVisible(true);
  said->progress->hide();
  row->addWidget(said->progress);
  _bars().push_back(said);
  // forgotten with the window it is in
  QObject::connect(said->box, &QObject::destroyed, [said]() {
    std::vector<barQt *> &all = _bars();
    all.erase(std::remove(all.begin(), all.end(), said), all.end());
    delete said;
  });
  if(qtSources().barButtons) _refreshBar(said, qtSources().barButtons());
  return said->box;
}

void qtRefreshBar()
{
  if(!_w || !qtSources().barButtons) return;
  std::vector<Ui::BarButton> bar = qtSources().barButtons();
  for(barQt *said : _bars()) _refreshBar(said, bar);
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

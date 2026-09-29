// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "qtCommon.h"
#include "Layout.h" // Ui::fills()

#include <QCloseEvent>
#include <QDockWidget>
#include <QFrame>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QTabWidget>
#include <QTimer>
#include <QVBoxLayout>

// A described form as Qt layouts, the way the page writes it as flex and grid
// (render(), lines(), cellOf() and cell() of src/browser/page.html, which
// this follows function for function, as the GTK interface does): a box down
// is its lines, one across a line, a grid one QGridLayout for its rows, tabs a
// QTabWidget. What grows is what the page's flex rules say grows; the rest of
// a line is left empty at its end. Each form is a QDockWidget: floating, or
// docked down the side of the main window, as the user drags it.

namespace {

  const double LineGap = 8. / 13., CellGap = 6. / 13., LinePad = 2. / 13.,
               GridRowGap = 4. / 13., PanePad = 6. / 13.;

  bool _gap(const Ui::Item &it)
  {
    return it.kind == Ui::Item::AField && it.field.kind == Ui::Spacer;
  }

  int _leastPx(int rows) { return rows * (qtPx(1.15) + 12); }

  void _fieldsOf(const Ui::Item &it, std::vector<const Ui::Field *> &out)
  {
    if(!Ui::shown(it)) return;
    if(it.kind == Ui::Item::AField) {
      if(it.field.kind != Ui::Spacer) out.push_back(&it.field);
    }
    else if(it.kind == Ui::Item::ABox)
      for(const auto &i : it.box->items) _fieldsOf(i, out);
    else if(it.kind == Ui::Item::ATabs)
      for(const auto &t : it.tabs->tabs) _fieldsOf(t.second, out);
  }

  void _tabsOf(const Ui::Item &it, std::vector<const Ui::Tabs *> &out)
  {
    if(!Ui::shown(it)) return;
    if(it.kind == Ui::Item::ABox)
      for(const auto &i : it.box->items) _tabsOf(i, out);
    else if(it.kind == Ui::Item::ATabs) {
      out.push_back(it.tabs.get());
      for(const auto &t : it.tabs->tabs) _tabsOf(t.second, out);
    }
  }

  double _widestEm(const Ui::Item &it)
  {
    if(!Ui::shown(it)) return 0.;
    if(it.kind == Ui::Item::ATabs) {
      double most = 0.;
      for(const auto &t : it.tabs->tabs)
        most = std::max(most, _widestEm(t.second));
      return most;
    }
    if(it.kind != Ui::Item::ABox) {
      if(it.kind != Ui::Item::AField) return 0.;
      if(it.field.widthEm > 0.) return it.field.widthEm;
      return _gap(it) ? 2. : 10.;
    }
    std::vector<double> each;
    for(const auto &i : it.box->items)
      if(Ui::shown(i)) each.push_back(_widestEm(i));
    if(it.box->direction == Ui::Box::Down) {
      double most = 0.;
      for(double w : each) most = std::max(most, w);
      return most;
    }
    double sum = 0.;
    for(double w : each) sum += w;
    return sum + LineGap * (each.size() > 1 ? each.size() - 1 : 0);
  }

  QVBoxLayout *_column(QWidget *w)
  {
    QVBoxLayout *v = new QVBoxLayout(w);
    v->setContentsMargins(0, 0, 0, 0);
    v->setSpacing(0);
    return v;
  }

  // a dock widget tells when the user closes it
  class formDock : public QDockWidget {
  public:
    std::function<void()> closing;
    formDock(const QString &title, QWidget *parent) : QDockWidget(title, parent)
    {
    }
    void closeEvent(QCloseEvent *e) override
    {
      QDockWidget::closeEvent(e);
      if(closing) closing();
    }
    void keyPressEvent(QKeyEvent *e) override
    {
      if(e->key() == Qt::Key_Escape && e->modifiers() == Qt::NoModifier) {
        close();
        return;
      }
      // what nothing in the dialog took is Gmsh's, as in the main window
      if(qtMainKey(e->key(), e->modifiers(), e->text())) return;
      QDockWidget::keyPressEvent(e);
    }
  };

} // namespace

class dialogQt {
public:
  const Ui::Form *which = nullptr;
  Ui::Form panel;
  formDock *dock = nullptr;
  QWidget *content = nullptr;
  std::string built;
  std::string pane;
  bool forcePane = false, building = false, dropping = false;
  // put where the options say the first time it floats
  bool placed = false;
  struct tabsMade {
    QTabWidget *tabs;
    std::vector<std::string> labels;
  };
  std::vector<tabsMade> tabs;
  std::vector<QWidget *> fields;
  std::set<std::string> options;
  std::vector<QLabel *> before;
  QTimer *tick = nullptr;

  ~dialogQt();
  void build();
  void reshape();
  void refresh();
  void show();
  void hide();
  bool shown() const { return dock && dock->isVisible(); }
  void applyPane();

private:
  void _render(const Ui::Item &item, QVBoxLayout *into, bool inside);
  void _lines(const std::vector<std::vector<const Ui::Item *> > &rows,
              QVBoxLayout *into, int columns, bool flush, bool inside);
  QWidget *_cellOf(const Ui::Item &item, bool column, int holds, bool &grows);
  QWidget *_cell(const Ui::Field &f, int holds, bool &grows);
  QWidget *_field(const Ui::Field &f);
};

namespace {

  std::map<const Ui::Form *, dialogQt *> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogQt *> dialogs;
    return dialogs;
  }

  bool _closingDown = false;
  QMainWindow *_main = nullptr;

  dialogQt *_find(const Ui::Form *which)
  {
    auto it = _dialogs().find(which);
    return it == _dialogs().end() ? nullptr : it->second;
  }

  std::set<const Ui::Form *> _pending;

  void _askReshape(const Ui::Form *which)
  {
    if(_pending.empty())
      QTimer::singleShot(0, []() {
        std::set<const Ui::Form *> now;
        now.swap(_pending);
        for(const Ui::Form *w : now)
          if(dialogQt *d = _find(w))
            if(d->shown()) d->reshape();
      });
    _pending.insert(which);
  }

} // namespace

dialogQt::~dialogQt()
{
  dropping = true;
  delete tick;
  if(dock) {
    dock->closing = nullptr;
    delete dock;
  }
}

QWidget *dialogQt::_field(const Ui::Field &f)
{
  const Ui::Form *form = which;
  QWidget *w = qtFieldWidget(f, [form]() { _askReshape(form); });
  if(!w) return nullptr;
  fields.push_back(w);
  if(f.option.size()) options.insert(f.option);
  return w;
}

QWidget *dialogQt::_cell(const Ui::Field &f, int holds, bool &grows)
{
  QWidget *box = new QWidget;
  QHBoxLayout *h = new QHBoxLayout(box);
  h->setContentsMargins(0, 0, 0, 0);
  h->setSpacing(qtPx(CellGap));
  grows = (f.kind == Ui::List || f.kind == Ui::Hierarchy ||
           f.kind == Ui::Prose || f.kind == Ui::ColorMap) &&
          !(f.widthEm > 0.) && !(f.widthShare > 0.);
  if(f.kind == Ui::Spacer) {
    // eats what is left of the line, never less than two em
    box->setMinimumWidth(qtPx(f.widthEm > 0. ? f.widthEm : 2.));
    grows = true;
    return box;
  }
  if(f.kind == Ui::Label) {
    QWidget *say = _field(f);
    if(f.widthEm > 0.) say->setFixedWidth(qtPx(f.widthEm));
    if(f.align != Ui::Left || f.wraps) grows = true;
    h->addWidget(say, 1);
    return box;
  }
  if(f.kind == Ui::Check && f.disclosure) {
    // a disclosure is a button at the end of its line
    grows = true;
    h->addStretch(1);
    h->addWidget(_field(f));
    return box;
  }
  QWidget *what = _field(f);
  if(!what) return box;
  bool value = f.kind == Ui::Text || f.kind == Ui::Integer ||
               f.kind == Ui::Number || f.kind == Ui::Output ||
               f.kind == Ui::Color || (f.kind == Ui::Choice && !f.multiple);
  int wide = -1;
  if(f.widthEm > 0.)
    wide = qtPx(f.widthEm);
  else if(f.widthShare > 0.)
    wide = qtPx(10. * f.widthShare);
  else if(value) {
    double em = 10. / std::max(1, holds);
    if(f.kind == Ui::Choice && holds > 1) em += 1.8;
    wide = qtPx(em);
  }
  if(f.kind == Ui::Action || f.kind == Ui::Menu ||
     (f.kind == Ui::Choice && f.multiple)) {
    if(wide > 0) what->setFixedWidth(wide);
    if(f.rows > 1 && f.hangs)
      what->setSizePolicy(what->sizePolicy().horizontalPolicy(),
                          QSizePolicy::Expanding);
    h->addWidget(what);
    return box;
  }
  if(f.kind == Ui::ColorMap) {
    if(wide > 0) what->setMinimumWidth(wide);
    what->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    grows = true;
    h->addWidget(what);
    return box;
  }
  QLabel *say = nullptr;
  if(f.label.size() && f.kind != Ui::Check) {
    say = new QLabel(qtString(f.label));
    say->setAlignment((f.labelBefore ? Qt::AlignRight : Qt::AlignLeft) |
                      Qt::AlignVCenter);
    if(f.alert) say->setStyleSheet("color: #b00000;");
  }
  if(f.kind == Ui::List || f.kind == Ui::Hierarchy) {
    if(wide > 0) what->setMinimumWidth(wide);
    what->setSizePolicy(grows ? QSizePolicy::Expanding : QSizePolicy::Preferred,
                        !f.rows ? QSizePolicy::Expanding : QSizePolicy::Preferred);
    h->addWidget(what, 1);
    if(say) h->addWidget(say);
    return box;
  }
  if(wide > 0) what->setFixedWidth(wide);
  std::vector<QWidget *> after;
  for(const Ui::Button &b : f.trailing) {
    const Ui::Form *form = which;
    after.push_back(qtButtonWidget(b, [form]() { _askReshape(form); }));
  }
  if(f.labelBefore) {
    // the names before their fields line up, as wide as the widest
    if(say) {
      before.push_back(say);
      h->addWidget(say);
    }
    h->addWidget(what, f.kind == Ui::Prose ? 1 : 0);
    for(QWidget *b : after) h->addWidget(b);
  }
  else {
    h->addWidget(what, f.kind == Ui::Prose ? 1 : 0);
    for(QWidget *b : after) h->addWidget(b);
    if(say) h->addWidget(say);
  }
  return box;
}

QWidget *dialogQt::_cellOf(const Ui::Item &item, bool column, int holds,
                           bool &grows)
{
  if(column && Ui::fills(item)) {
    QWidget *aside = new QWidget;
    aside->setFixedWidth(qtPx(_widestEm(item)));
    QVBoxLayout *v = _column(aside);
    _render(item, v, true);
    grows = false;
    return aside;
  }
  if(item.kind == Ui::Item::ABox || item.kind == Ui::Item::ATabs) {
    // what is left of the line
    QWidget *box = new QWidget;
    QVBoxLayout *v = _column(box);
    _render(item, v, true);
    grows = true;
    return box;
  }
  return _cell(item.field, holds, grows);
}

void dialogQt::_lines(const std::vector<std::vector<const Ui::Item *> > &rows,
                      QVBoxLayout *into, int columns, bool flush, bool inside)
{
  QGridLayout *grid = nullptr;
  int gridRow = 0;
  int pad = qtPx(LinePad);
  for(const auto &row : rows) {
    bool grows = false, spaced = false, others = false;
    int holds = 0;
    for(const Ui::Item *i : row) {
      if(Ui::fills(*i))
        grows = true;
      else if(!_gap(*i))
        others = true;
      if(_gap(*i)) spaced = true;
      if(i->kind == Ui::Item::AField) {
        const Ui::Field &f = i->field;
        if(f.kind != Ui::Label && f.kind != Ui::Spacer &&
           f.kind != Ui::Action && f.kind != Ui::List &&
           f.kind != Ui::Hierarchy && f.kind != Ui::Check &&
           f.kind != Ui::ColorMap && !(f.widthEm > 0.) &&
           !(f.widthShare > 0.))
          holds++;
      }
    }
    bool column = grows && others;

    // runs of packed fields are one thing each
    std::vector<QWidget *> parts;
    std::vector<bool> partGrows;
    {
      QWidget *run = nullptr;
      QHBoxLayout *runLayout = nullptr;
      bool said = false;
      for(const Ui::Item *i : row) {
        bool g = false;
        QWidget *one = _cellOf(*i, column, holds, g);
        bool packed = i->kind == Ui::Item::AField && i->field.packed &&
                      !_gap(*i) && !i->field.disclosure;
        if(packed) {
          if(!run) {
            run = new QWidget;
            runLayout = new QHBoxLayout(run);
            runLayout->setContentsMargins(0, 0, 0, 0);
            runLayout->setSpacing(0);
            parts.push_back(run);
            partGrows.push_back(false);
          }
          if(said) runLayout->addSpacing(qtPx(LineGap));
          said = !i->field.label.empty();
          runLayout->addWidget(one);
          continue;
        }
        said = false;
        run = nullptr;
        parts.push_back(one);
        // with a gap on the line each cell takes what it needs, the gap the
        // rest
        partGrows.push_back(spaced ? _gap(*i) : g);
      }
    }

    if(columns > 1 && !grows) {
      if(!grid) {
        QWidget *holder = new QWidget;
        grid = new QGridLayout(holder);
        grid->setHorizontalSpacing(qtPx(LineGap));
        grid->setVerticalSpacing(qtPx(GridRowGap));
        grid->setContentsMargins(inside ? 0 : pad, pad, inside ? 0 : pad, pad);
        into->addWidget(holder);
        gridRow = 0;
      }
      for(std::size_t k = 0; k < parts.size(); k++) {
        // the last field of a line runs on to the end of the grid
        int span = (k + 1 == parts.size()) ? std::max(1, columns - (int)k) : 1;
        grid->addWidget(parts[k], gridRow, (int)k, 1, span,
                        Qt::AlignLeft | Qt::AlignVCenter);
      }
      grid->setColumnStretch(columns, 1);
      gridRow++;
      continue;
    }
    grid = nullptr;
    QWidget *lineWidget = new QWidget;
    QHBoxLayout *line = new QHBoxLayout(lineWidget);
    line->setSpacing(flush ? 0 : qtPx(LineGap));
    line->setContentsMargins(inside ? 0 : pad, pad, inside ? 0 : pad, pad);
    bool anyGrows = false;
    for(std::size_t k = 0; k < parts.size(); k++) {
      bool stretch = partGrows[k];
      anyGrows = anyGrows || stretch;
      bool tall = grows && (row[std::min(k, row.size() - 1)]->kind !=
                              Ui::Item::AField ||
                            Ui::fills(*row[std::min(k, row.size() - 1)]));
      line->addWidget(parts[k], stretch ? 1 : 0,
                      tall ? Qt::Alignment() : Qt::AlignVCenter);
    }
    // what no cell takes is left at the end of the line
    if(!anyGrows) line->addStretch(1);
    if(grows && panel.leastRows > 0 && !column)
      lineWidget->setMinimumHeight(_leastPx(panel.leastRows));
    into->addWidget(lineWidget, grows ? 1 : 0);
  }
}

void dialogQt::_render(const Ui::Item &item, QVBoxLayout *into, bool inside)
{
  if(!Ui::shown(item)) return;
  switch(item.kind) {
  case Ui::Item::ATabs: {
    QTabWidget *t = new QTabWidget;
    std::size_t at = tabs.size();
    tabs.push_back(tabsMade());
    tabs[at].tabs = t;
    bool fills = false;
    for(const auto &one : item.tabs->tabs) {
      QWidget *page = new QWidget;
      QVBoxLayout *v = _column(page);
      int pad = qtPx(PanePad);
      v->setContentsMargins(pad, pad, pad, pad);
      _render(one.second, v, false);
      if(Ui::fills(one.second))
        fills = true;
      else
        v->addStretch(1);
      t->addTab(page, qtString(one.first.size() ? one.first : "·"));
      tabs[at].labels.push_back(one.first);
    }
    if(panel.leastRows > 0) t->setMinimumHeight(_leastPx(panel.leastRows));
    QObject::connect(t, &QTabWidget::currentChanged, [this, at](int n) {
      if(building || n < 0 || n >= (int)tabs[at].labels.size()) return;
      std::string label = tabs[at].labels[(std::size_t)n];
      bool moved = pane != label;
      pane = label;
      std::vector<const Ui::Tabs *> all;
      _tabsOf(panel.content, all);
      if(!moved || at >= all.size() || !all[at]->chosen) return;
      std::function<void(const std::string &)> chosen = all[at]->chosen;
      qtLater([chosen, label]() { chosen(label); });
    });
    into->addWidget(t, fills ? 1 : 0);
  } break;
  case Ui::Item::AHeading: {
    QLabel *h = new QLabel(qtString(item.text));
    QFont bold = h->font();
    bold.setBold(true);
    h->setFont(bold);
    h->setContentsMargins(0, qtPx(.5), 0, qtPx(.2));
    into->addWidget(h);
  } break;
  case Ui::Item::ARule: {
    QFrame *r = new QFrame;
    r->setFrameShape(QFrame::HLine);
    r->setFrameShadow(QFrame::Sunken);
    into->addSpacing(qtPx(.3));
    into->addWidget(r);
    into->addSpacing(qtPx(.3));
  } break;
  case Ui::Item::AField:
    if(_gap(item))
      into->addStretch(1);
    else
      _lines({{&item}}, into, 0, false, inside);
    break;
  case Ui::Item::ABox: {
    const Ui::Box &b = *item.box;
    if(b.scrolling) {
      QScrollArea *scroll = new QScrollArea;
      scroll->setWidgetResizable(true);
      scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      scroll->setFrameShape(QFrame::NoFrame);
      scroll->setMinimumHeight(panel.leastRows > 0 ? _leastPx(panel.leastRows) :
                                                     qtPx(8.));
      QWidget *main = new QWidget;
      QVBoxLayout *v = _column(main);
      Ui::Item plain = item;
      plain.box = std::make_shared<Ui::Box>(b);
      plain.box->scrolling = false;
      _render(plain, v, inside);
      v->addStretch(1);
      scroll->setWidget(main);
      // as wide as what it holds, which never scrolls across
      scroll->setMinimumWidth(main->sizeHint().width() + qtPx(1.2));
      into->addWidget(scroll, 1);
      break;
    }
    if(b.direction == Ui::Box::Across || b.grid) {
      std::vector<std::vector<const Ui::Item *> > rows;
      if(b.direction == Ui::Box::Across) {
        rows.emplace_back();
        for(const auto &i : b.items)
          if(Ui::shown(i)) rows.back().push_back(&i);
      }
      else
        for(const auto &i : b.items) {
          if(!Ui::shown(i)) continue;
          if(i.kind == Ui::Item::ABox && i.box->direction == Ui::Box::Across &&
             !i.box->grid && !i.box->scrolling) {
            rows.emplace_back();
            for(const auto &j : i.box->items)
              if(Ui::shown(j)) rows.back().push_back(&j);
          }
          else
            rows.push_back({&i});
        }
      int columns = 0;
      if(b.grid)
        for(const auto &r : rows) columns = std::max(columns, (int)r.size());
      _lines(rows, into, b.grid ? std::max(1, columns) : 0, b.padding == 0.,
             inside);
      break;
    }
    for(const auto &i : b.items) _render(i, into, inside);
  } break;
  default: break;
  }
}

void dialogQt::applyPane()
{
  if(!forcePane || pane.empty()) return;
  forcePane = false;
  building = true;
  for(auto &t : tabs)
    for(std::size_t k = 0; k < t.labels.size(); k++) {
      if(t.labels[k] != pane) continue;
      t.tabs->setCurrentIndex((int)k);
      // and the tabs the pane's are in, for tabs under tabs
      for(QWidget *w = t.tabs->parentWidget(); w; w = w->parentWidget())
        for(auto &o : tabs)
          for(int j = 0; j < o.tabs->count(); j++)
            if(o.tabs->widget(j) == w) o.tabs->setCurrentIndex(j);
    }
  building = false;
}

void dialogQt::build()
{
  building = true;
  panel = *which;
  built = Ui::signature(panel, true);
  if(!dock) {
    dock = new formDock(qtString(panel.title), _main);
    dock->setObjectName(qtString("gmsh-" + panel.id));
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    const Ui::Form *form = which;
    dock->closing = [form]() {
      dialogQt *d = _find(form);
      if(!d || _closingDown || d->dropping) return;
      // closing a dialog undoes what it leaves behind
      if(d->panel.closed) qtLater(d->panel.closed);
    };
    if(_main) {
      _main->addDockWidget(Qt::RightDockWidgetArea, dock);
      dock->setFloating(true);
    }
    dock->hide();
  }
  dock->setWindowTitle(qtString(panel.title));
  tabs.clear();
  fields.clear();
  options.clear();
  before.clear();
  QWidget *old = content;
  content = new QWidget;
  QVBoxLayout *v = _column(content);
  int pad = qtPx(5. / 13.);
  v->setContentsMargins(pad, pad, pad, pad);
  content->setMinimumWidth(qtPx(12.));
  _render(panel.content, v, false);
  if(!Ui::fills(panel.content)) v->addStretch(1);
  // the names before their fields as wide as the widest
  int widest = 0;
  for(QLabel *l : before) widest = std::max(widest, l->sizeHint().width());
  for(QLabel *l : before) l->setMinimumWidth(widest);
  dock->setWidget(content);
  // the old widgets go once the event that asked for this is over: one of
  // them may be the button whose signal is running
  if(old) old->deleteLater();
  forcePane = true;
  building = false;
  applyPane();
}

void dialogQt::refresh()
{
  applyPane();
  std::vector<const Ui::Field *> now;
  _fieldsOf(panel.content, now);
  for(std::size_t i = 0; i < fields.size(); i++) {
    if(i < now.size()) qtRebindField(fields[i], *now[i]);
    qtRefreshField(fields[i]);
  }
}

void dialogQt::reshape()
{
  if(!which) return;
  Ui::Form now = *which;
  if(!dock || Ui::signature(now, true) != built) {
    build();
    refresh();
    return;
  }
  panel = now;
  refresh();
}

void dialogQt::show()
{
  Ui::Form now = *which;
  if(!dock || Ui::signature(now, true) != built) build();
  panel = now;
  forcePane = true;
  refresh();
  bool first = !dock->isVisible();
  dock->show();
  if(first && dock->isFloating()) dock->adjustSize();
  if(first && dock->isFloating() && !placed) {
    placed = true;
    const Ui::Backend::Settings set = qtSources().settings();
    if(qtPlacesWindows() && (set.dialogX > 0 || set.dialogY > 0))
      dock->move(set.dialogX, set.dialogY);
  }
  dock->raise();
  if(dock->isFloating()) dock->activateWindow();
  if(panel.refreshEvery > 0. && !tick) {
    tick = new QTimer;
    const Ui::Form *form = which;
    QObject::connect(tick, &QTimer::timeout, [form]() {
      dialogQt *d = _find(form);
      if(d && d->shown()) d->reshape();
    });
    tick->start((int)(panel.refreshEvery * 1000.));
  }
}

void dialogQt::hide()
{
  if(!dock || !dock->isVisible()) return;
  dock->hide();
  if(!_closingDown && !dropping && panel.closed) qtLater(panel.closed);
}

// --- what the backend asks

namespace {
  dialogQt *_dialog(const Ui::Form &form)
  {
    dialogQt *d = _find(&form);
    if(d) return d;
    d = new dialogQt;
    d->which = &form;
    _dialogs()[&form] = d;
    return d;
  }
} // namespace

void qtShowForm(const Ui::Form &form, bool show)
{
  if(!show) {
    if(dialogQt *d = _find(&form)) d->hide();
    return;
  }
  _dialog(form)->show();
}

bool qtFormPosition(int &x, int &y)
{
  for(auto &it : _dialogs())
    if(it.second->shown() && it.second->dock->isFloating()) {
      QPoint at = it.second->dock->pos();
      x = at.x();
      y = at.y();
      return true;
    }
  return false;
}

bool qtFormVisible(const Ui::Form &form)
{
  dialogQt *d = _find(&form);
  return d && d->shown();
}

std::string qtFormPane(const Ui::Form &form)
{
  dialogQt *d = _find(&form);
  return d ? d->pane : "";
}

void qtSetFormPane(const Ui::Form &form, const std::string &pane)
{
  dialogQt *d = _dialog(form);
  d->pane = pane;
  d->forcePane = true;
  if(d->shown()) d->applyPane();
}

void qtReloadForm(const Ui::Form &form)
{
  dialogQt *d = _find(&form);
  if(d && d->shown()) d->reshape();
}

void qtDropForm(const Ui::Form &form)
{
  auto it = _dialogs().find(&form);
  if(it == _dialogs().end()) return;
  dialogQt *d = it->second;
  _dialogs().erase(it);
  _pending.erase(&form);
  delete d;
}

void qtFormOptionChanged(const std::string &name)
{
  for(auto &it : _dialogs()) {
    dialogQt *d = it.second;
    if(d->shown() && d->options.count(name)) d->refresh();
  }
}

void qtFormsClosingDown()
{
  _closingDown = true;
  for(auto &it : _dialogs()) delete it.second;
  _dialogs().clear();
  _pending.clear();
}

void qtSetMainWindow(QMainWindow *window) { _main = window; }

QMainWindow *qtMainWindow() { return _main; }

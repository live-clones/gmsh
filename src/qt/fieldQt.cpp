// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory>

#include "qtCommon.h"
#include "MapEditor.h"

#include <QApplication>
#include <QCheckBox>
#include <QColorDialog>
#include <QComboBox>
#include <QFontDatabase>
#include <QFontMetricsF>
#include <QFontInfo>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QSlider>
#include <QToolButton>
#include <QTreeWidget>
#include <QWheelEvent>

// The widget of one field. Each carries its binding -- a copy of the field,
// and what the holder does after a change -- as a child object, so that it
// goes with it: a change the user makes is written through the field, then
// told, then `after` runs; a refresh reads the field and puts the value back,
// quietly.

double qtEm()
{
  int px = QFontInfo(QApplication::font()).pixelSize();
  return px > 1 ? px : 14.;
}

int qtPx(double em) { return (int)std::floor(em * qtEm() + 0.5); }

namespace {

  struct binding : public QObject {
    Ui::Field field;
    std::function<void()> after;
    QWidget *outer = nullptr, *inner = nullptr;
    // the number of a slider
    QLineEdit *number = nullptr;
    bool quiet = false;
    std::string was, shown;
    std::vector<std::string> labels;
    std::vector<int> values;
    bool dragging = false;
    Ui::MapEditor mapEdit;
    treeQt *tree = nullptr;
    binding(QWidget *parent) : QObject(parent) {}
    ~binding() { delete tree; }
  };

  binding *_of(QWidget *w)
  {
    return w ? (binding *)w->property("gmshField").value<void *>() : nullptr;
  }

  // a change the user made: the done() of a choosing that ended, the
  // changed() of a step, then what the holder does; nothing of b is touched
  // afterwards
  void _told(binding *b, bool ends)
  {
    if(b->quiet) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    if(f.done && ends)
      f.done();
    else if(f.changed)
      f.changed();
    if(after) after();
  }

  void _doneAnyway(binding *b)
  {
    if(b->quiet || !b->field.done) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    f.done();
    if(after) after();
  }

  std::string _joined(const std::vector<std::string> &labels)
  {
    std::string s;
    for(const auto &l : labels) s += l + '\n';
    return s;
  }

  // with the decimals of its step when values are dragged
  std::string _number(const Ui::Field &f, double v)
  {
    return Ui::numberText(v, qtSources().settings().inputScrolling ? f.step : 0.);
  }

  void _numberWrite(binding *b, const std::string &said, bool ends)
  {
    double v = 0.;
    if(!Ui::readNumber(said, v)) {
      qtRefreshField(b->outer);
      return;
    }
    v = Ui::bounded(b->field, v);
    b->field.setNumber(v);
    b->shown = _number(b->field, v);
    _told(b, ends);
  }

  // a number that scrolls with the wheel, when it has a step
  class numberEdit : public QLineEdit {
  public:
    binding *b = nullptr;
    void wheelEvent(QWheelEvent *e) override
    {
      const Ui::Field &f = b->field;
      if(!(f.step > 0.) || !qtSources().settings().inputScrolling ||
         !isEnabled()) {
        QLineEdit::wheelEvent(e);
        return;
      }
      int dy = e->angleDelta().y();
      if(!dy) return;
      double v = Ui::bounded(f, f.getNumber() + (dy > 0 ? 1. : -1.) * f.step);
      b->field.setNumber(v);
      qtRefreshField(b->outer);
      _told(b, false);
      e->accept();
    }
    void focusOutEvent(QFocusEvent *e) override
    {
      QLineEdit::focusOutEvent(e);
      std::string now = qtString(text());
      if(b && !b->quiet && now != b->shown) _numberWrite(b, now, true);
    }
  };

  numberEdit *_numberEdit(binding *b)
  {
    numberEdit *e = new numberEdit;
    e->b = b;
    e->setMinimumWidth(qtPx(2.));
    QObject::connect(e, &QLineEdit::returnPressed, [b, e]() {
      if(b->quiet) return;
      std::string now = qtString(e->text());
      // Enter says the value is the one, even as it was
      if(now == b->shown)
        _doneAnyway(b);
      else
        _numberWrite(b, now, true);
    });
    return e;
  }

  class textEdit : public QLineEdit {
  public:
    binding *b = nullptr;
    void focusOutEvent(QFocusEvent *e) override
    {
      QLineEdit::focusOutEvent(e);
      if(!b || b->quiet || !b->field.commitsWhenDone) return;
      std::string now = qtString(text());
      if(now == b->shown) return;
      b->shown = now;
      b->field.setText(now);
      _told(b, true);
    }
  };

  // --- the disc of a direction

  class discWidget : public QWidget {
  public:
    binding *b = nullptr;
    int side;
    discWidget(int s) : side(s) { setFixedSize(s, s); }
    void paintEvent(QPaintEvent *) override
    {
      double x = 0., y = 0., z = 0.;
      b->field.getVector(x, y, z);
      double length = std::sqrt(x * x + y * y + z * z);
      if(length > 0.) {
        x /= length;
        y /= length;
      }
      QPainter p(this);
      p.setRenderHint(QPainter::Antialiasing);
      QColor ink = palette().color(isEnabled() ? QPalette::WindowText :
                                                 QPalette::PlaceholderText);
      p.setPen(ink);
      double r = .5 * side - 3., cx = .5 * width(), cy = .5 * height();
      p.drawEllipse(QPointF(cx, cy), r, r);
      p.fillRect(QRectF(cx + r * x - 3., cy - r * y - 3., 6., 6.), ink);
    }
    void at(QPointF pos)
    {
      if(!isEnabled()) return;
      double r = .5 * side - 3.;
      double xx = (pos.x() - .5 * width()) / r, yy = -(pos.y() - .5 * height()) / r;
      double norm = std::sqrt(xx * xx + yy * yy);
      if(norm > 1.) {
        xx /= norm;
        yy /= norm;
        norm = 1.;
      }
      b->field.setVector(xx, yy, std::sqrt(std::max(0., 1. - norm * norm)));
      update();
      _told(b, false);
    }
    void mousePressEvent(QMouseEvent *e) override { at(e->position()); }
    void mouseMoveEvent(QMouseEvent *e) override
    {
      if(e->buttons()) at(e->position());
    }
    void mouseReleaseEvent(QMouseEvent *) override { _doneAnyway(b); }
  };

  // --- the colour map, drawn into the table itself

  class mapWidget : public QWidget {
  public:
    binding *b = nullptr;
    mapWidget()
    {
      setFocusPolicy(Qt::StrongFocus);
      setMouseTracking(true);
      setMinimumSize(qtPx(10.), qtPx(8.));
    }
    double line() const { return fontMetrics().height(); }
    // what Ui::MapEditor::picture() says, drawn
    void paintEvent(QPaintEvent *) override
    {
      const Ui::ColourMap &map = b->field.map;
      if(map.empty()) return;
      Ui::MapEditor::Picture pic =
        b->mapEdit.picture(map, width(), height(), line());
      QPainter p(this);
      QColor ink = palette().color(QPalette::WindowText);
      p.fillRect(rect(), palette().color(QPalette::Base));
      for(const auto &x : pic.boxes)
        p.fillRect(QRectF(x.x, x.y, x.w, x.h),
                   QColor(x.colour.r, x.colour.g, x.colour.b));
      for(const auto &x : pic.segments) {
        p.setPen(x.ink ? ink : QColor(x.colour.r, x.colour.g, x.colour.b));
        p.drawLine(QPointF(x.x0, x.y0), QPointF(x.x1, x.y1));
      }
      p.setPen(ink);
      for(const auto &x : pic.texts) {
        QFont f = font();
        f.setPointSizeF(f.pointSizeF() * x.scale);
        p.setFont(f);
        QFontMetricsF m(f);
        double left = x.right ? x.x - m.horizontalAdvance(x.text.c_str()) : x.x;
        p.drawText(QPointF(left, x.y + m.ascent()), x.text.c_str());
      }
    }
    void paint(QPointF pos, int button, Qt::KeyboardModifiers m = {})
    {
      const Ui::ColourMap &map = b->field.map;
      if(map.empty() || map.size() < 2 || width() < 1) return;
      int entry = 0, value = 0;
      bool onWedge = false;
      Ui::MapEditor::at(map, pos.x(), pos.y(), width(), height(), line(), entry,
                        value, onWedge);
      Ui::MapEditor::Answer said;
      if(button >= 0) {
        unsigned mods = 0;
        if(m & Qt::ControlModifier) mods |= Ui::ModCommand;
        if(m & Qt::ShiftModifier) mods |= Ui::ModShift;
        if(m & Qt::AltModifier) mods |= Ui::ModAlt;
        said = b->mapEdit.press(map, entry, value, button, mods, onWedge);
      }
      else
        said = b->mapEdit.drag(map, entry, value);
      update();
      if(said == Ui::MapEditor::Changed) _told(b, false);
    }
    void mousePressEvent(QMouseEvent *e) override
    {
      paint(e->position(),
            e->button() == Qt::RightButton  ? 2 :
            e->button() == Qt::MiddleButton ? 1 :
                                              0,
            e->modifiers());
    }
    void mouseMoveEvent(QMouseEvent *e) override
    {
      if(e->buttons() && b->mapEdit.drawing()) paint(e->position(), -1);
    }
    void mouseReleaseEvent(QMouseEvent *) override { b->mapEdit.release(); }
    void enterEvent(QEnterEvent *) override { setFocus(); }
    void keyPressEvent(QKeyEvent *e) override
    {
      const Ui::ColourMap &map = b->field.map;
      int key = 0;
      unsigned mods = 0;
      if(map.empty() || !qtUiKey(e->key(), e->modifiers(), e->text(), key, mods)) {
        QWidget::keyPressEvent(e);
        return;
      }
      Ui::MapEditor::Answer said = b->mapEdit.key(map, key, mods);
      if(said == Ui::MapEditor::NotMine) {
        QWidget::keyPressEvent(e);
        return;
      }
      update();
      if(said == Ui::MapEditor::Changed) _told(b, true);
    }
  };

  // --- a page of prose, as a label of rich text

  std::string _escaped(const std::string &text)
  {
    return qtString(qtString(text).toHtmlEscaped());
  }

  void _prose(binding *b)
  {
    std::vector<Ui::Line> page =
      b->field.prose ? b->field.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page) {
      for(const Ui::Words &w : l.words) said += w.text + (w.italic ? "/" : "|");
      said += '\n';
    }
    if(said == b->was) return;
    b->was = said;
    std::vector<std::function<void()> > *follow =
      new std::vector<std::function<void()> >;
    std::string html;
    bool list = false;
    for(const Ui::Line &l : page) {
      std::string m;
      for(const Ui::Words &w : l.words) {
        std::string t = _escaped(w.text);
        if(w.italic) t = "<i>" + t + "</i>";
        if(w.follow) {
          t = "<a href=\"" + std::to_string(follow->size()) + "\">" + t + "</a>";
          follow->push_back(w.follow);
        }
        m += t;
      }
      if(l.bullet) {
        if(!list) html += "<ul style=\"margin:0\">";
        list = true;
        html += "<li>" + m + "</li>";
        continue;
      }
      if(list) html += "</ul>";
      list = false;
      if(m.empty()) m = "&nbsp;";
      if(l.heading) m = "<span style=\"font-size:x-large;font-weight:600\">" + m + "</span>";
      html += std::string("<p style=\"margin:0\"") +
              (l.centred ? " align=\"center\"" : "") + ">" + m + "</p>";
    }
    if(list) html += "</ul>";
    QLabel *label = (QLabel *)b->inner;
    label->setText(qtString(html));
    // the links of the page before this one are dropped with it
    QObject::disconnect(label, &QLabel::linkActivated, nullptr, nullptr);
    std::shared_ptr<std::vector<std::function<void()> > > kept(follow);
    QObject::connect(label, &QLabel::linkActivated, [kept](const QString &uri) {
      int i = uri.toInt();
      if(i >= 0 && i < (int)kept->size()) qtLater((*kept)[(std::size_t)i]);
    });
  }

  QWidget *_listLine(const Ui::Field &f, const std::string &label)
  {
    QWidget *line = new QWidget;
    QHBoxLayout *h = new QHBoxLayout(line);
    h->setContentsMargins(4, 0, 4, 0);
    h->setSpacing(0);
    std::size_t at = 0, column = 0;
    while(true) {
      std::size_t tab = label.find('\t', at);
      std::string part = label.substr(at, tab == std::string::npos ?
                                             std::string::npos :
                                             tab - at);
      QLabel *l = new QLabel(qtString(part));
      if(column < f.columnsEm.size() && f.columnsEm[column] > 0. &&
         tab != std::string::npos)
        l->setFixedWidth(qtPx(f.columnsEm[column]));
      h->addWidget(l, tab == std::string::npos ? 1 : 0);
      if(tab == std::string::npos) break;
      at = tab + 1;
      column++;
    }
    return line;
  }

  void _setSwatch(QPushButton *b, const Ui::Colour &c)
  {
    b->setStyleSheet(QString("QPushButton { background-color: rgb(%1,%2,%3); "
                             "border: 1px solid palette(mid); }")
                       .arg(c.r)
                       .arg(c.g)
                       .arg(c.b));
  }

} // namespace

QWidget *qtFieldWidget(const Ui::Field &f, const std::function<void()> &after)
{
  QWidget *outer = nullptr;
  binding *b = nullptr;
  auto bind = [&](QWidget *o, QWidget *in) {
    outer = o;
    b = new binding(o);
    b->field = f;
    b->after = after;
    b->outer = o;
    b->inner = in;
    o->setProperty("gmshField", QVariant::fromValue((void *)b));
  };
  switch(f.kind) {
  case Ui::Text:
    if(f.dynamicChoices) {
      QComboBox *c = new QComboBox;
      c->setEditable(true);
      c->setInsertPolicy(QComboBox::NoInsert);
      c->setMinimumContentsLength(1);
      c->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
      bind(c, c->lineEdit());
      binding *bb = b;
      QObject::connect(c->lineEdit(), &QLineEdit::textEdited,
                       [bb](const QString &t) {
                         if(bb->quiet || bb->field.commitsWhenDone) return;
                         bb->shown = qtString(t);
                         bb->field.setText(bb->shown);
                         _told(bb, false);
                       });
      QObject::connect(c->lineEdit(), &QLineEdit::editingFinished, [bb, c]() {
        if(bb->quiet) return;
        std::string now = qtString(c->currentText());
        if(now == bb->shown) return;
        bb->shown = now;
        bb->field.setText(now);
        _told(bb, true);
      });
      QObject::connect(c, &QComboBox::textActivated, [bb](const QString &t) {
        if(bb->quiet) return;
        bb->shown = qtString(t);
        bb->field.setText(bb->shown);
        _told(bb, true);
      });
    }
    else {
      textEdit *e = new textEdit;
      e->setMinimumWidth(qtPx(2.));
      bind(e, e);
      e->b = b;
      binding *bb = b;
      QObject::connect(e, &QLineEdit::textEdited, [bb](const QString &t) {
        if(bb->quiet || bb->field.commitsWhenDone) return;
        bb->shown = qtString(t);
        bb->field.setText(bb->shown);
        _told(bb, false);
      });
      QObject::connect(e, &QLineEdit::returnPressed, [bb, e]() {
        if(bb->quiet) return;
        if(!bb->field.commitsWhenDone) {
          _doneAnyway(bb);
          return;
        }
        bb->shown = qtString(e->text());
        bb->field.setText(bb->shown);
        _told(bb, true);
      });
    }
    break;
  case Ui::Integer:
  case Ui::Number:
    if(f.slider && f.maximum > f.minimum) {
      // the number at the left end and the scale beside it, as the page has
      // it; the scale in a thousand steps
      QWidget *box = new QWidget;
      QHBoxLayout *h = new QHBoxLayout(box);
      h->setContentsMargins(0, 0, 0, 0);
      h->setSpacing(2);
      QSlider *s = new QSlider(Qt::Horizontal);
      s->setRange(0, 1000);
      bind(box, s);
      b->number = _numberEdit(b);
      b->number->setFixedWidth(qtPx(3.6));
      h->addWidget(b->number);
      h->addWidget(s, 1);
      binding *bb = b;
      QObject::connect(s, &QSlider::valueChanged, [bb](int k) {
        if(bb->quiet) return;
        const Ui::Field &g = bb->field;
        double v = g.minimum + (g.maximum - g.minimum) * k / 1000.;
        if(g.step > 0.) v = g.minimum + std::floor((v - g.minimum) / g.step + .5) * g.step;
        v = Ui::bounded(g, v);
        bb->field.setNumber(v);
        bb->shown = _number(g, v);
        bb->quiet = true;
        bb->number->setText(qtString(bb->shown));
        bb->quiet = false;
        _told(bb, !bb->dragging);
      });
      QObject::connect(s, &QSlider::sliderPressed, [bb]() { bb->dragging = true; });
      QObject::connect(s, &QSlider::sliderReleased, [bb]() {
        bb->dragging = false;
        _doneAnyway(bb);
      });
    }
    else {
      numberEdit *e = new numberEdit;
      e->setMinimumWidth(qtPx(2.));
      bind(e, e);
      e->b = b;
      binding *bb = b;
      QObject::connect(e, &QLineEdit::returnPressed, [bb, e]() {
        if(bb->quiet) return;
        std::string now = qtString(e->text());
        if(now == bb->shown)
          _doneAnyway(bb);
        else
          _numberWrite(bb, now, true);
      });
    }
    break;
  case Ui::Check:
    if(f.disclosure) {
      QToolButton *t = new QToolButton;
      t->setCheckable(true);
      t->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
      bind(t, t);
      binding *bb = b;
      QObject::connect(t, &QToolButton::toggled, [bb](bool on) {
        if(bb->quiet) return;
        bb->field.setFlag(on);
        _told(bb, true);
      });
    }
    else {
      QCheckBox *c = new QCheckBox(qtString(f.label));
      bind(c, c);
      binding *bb = b;
      QObject::connect(c, &QCheckBox::toggled, [bb](bool on) {
        if(bb->quiet) return;
        bb->field.setFlag(on);
        _told(bb, true);
      });
    }
    break;
  case Ui::Choice:
    if(f.multiple) {
      QToolButton *t = new QToolButton;
      t->setText(qtString(f.label));
      t->setPopupMode(QToolButton::InstantPopup);
      QMenu *m = new QMenu(t);
      t->setMenu(m);
      bind(t, t);
    }
    else {
      QComboBox *c = new QComboBox;
      c->setMinimumContentsLength(1);
      c->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
      bind(c, c);
      binding *bb = b;
      QObject::connect(c, &QComboBox::activated, [bb](int i) {
        if(bb->quiet || i < 0 || i >= (int)bb->labels.size()) return;
        if(bb->values.empty())
          bb->field.setText(bb->labels[(std::size_t)i]);
        else if(i < (int)bb->values.size())
          bb->field.setNumber(bb->values[(std::size_t)i]);
        _told(bb, true);
      });
    }
    break;
  case Ui::Label: {
    QLabel *l = new QLabel;
    l->setAlignment((f.align == Ui::Centre ? Qt::AlignHCenter :
                     f.align == Ui::Right  ? Qt::AlignRight :
                                             Qt::AlignLeft) |
                    (f.wraps ? Qt::AlignTop : Qt::AlignVCenter));
    if(f.wraps) {
      l->setWordWrap(true);
      l->setMaximumWidth(qtPx(26.));
    }
    if(f.heading) {
      QFont bold = l->font();
      bold.setBold(true);
      l->setFont(bold);
    }
    if(f.alert) l->setStyleSheet("color: #b00000;");
    bind(l, l);
  } break;
  case Ui::Output: {
    QLineEdit *e = new QLineEdit;
    e->setReadOnly(true);
    e->setMinimumWidth(qtPx(2.));
    bind(e, e);
  } break;
  case Ui::Prose: {
    QLabel *l = new QLabel;
    l->setWordWrap(true);
    l->setTextFormat(Qt::RichText);
    l->setMinimumWidth(qtPx(10.));
    bind(l, l);
  } break;
  case Ui::Action: {
    QPushButton *p = new QPushButton(qtString(f.label));
    if(f.isDefault) p->setDefault(true);
    else p->setAutoDefault(false);
    if(f.alert) p->setStyleSheet("color: #b00000;");
    bind(p, p);
    binding *bb = b;
    QObject::connect(p, &QPushButton::clicked, [bb]() {
      Ui::Field g = bb->field;
      std::function<void()> after = bb->after;
      qtLater([g, after]() {
        if(g.changed) g.changed();
        if(after) after();
      });
    });
  } break;
  case Ui::Color: {
    QPushButton *p = new QPushButton;
    p->setAutoDefault(false);
    bind(p, p);
    binding *bb = b;
    QObject::connect(p, &QPushButton::clicked, [bb, p]() {
      Ui::Colour c = bb->field.getColour();
      QColor was(c.r, c.g, c.b, c.a);
      QColor now = QColorDialog::getColor(was, p, "Color Chooser",
                                          QColorDialog::ShowAlphaChannel);
      if(!now.isValid()) return;
      bb->field.setColour(Ui::Colour((unsigned char)now.red(),
                                     (unsigned char)now.green(),
                                     (unsigned char)now.blue(),
                                     (unsigned char)now.alpha()));
      qtRefreshField(bb->outer);
      _told(bb, true);
    });
  } break;
  case Ui::Direction: {
    discWidget *d = new discWidget(
      std::max(qtPx(2.9), qtPx(1.45 * std::max(2, f.rows))));
    bind(d, d);
    d->b = b;
  } break;
  case Ui::ColorMap: {
    mapWidget *m = new mapWidget;
    bind(m, m);
    m->b = b;
  } break;
  case Ui::Hierarchy: {
    Ui::Tree none;
    treeQt *t = new treeQt(f.hierarchy ? *f.hierarchy : none, true, after);
    QWidget *view = (QWidget *)t->widget();
    if(f.rows) view->setMinimumHeight(qtPx(1.45 * f.rows));
    bind(view, view);
    b->tree = t;
  } break;
  case Ui::Menu: {
    QToolButton *t = new QToolButton;
    t->setText(qtString(f.label));
    t->setPopupMode(QToolButton::InstantPopup);
    QMenu *m = new QMenu(t);
    t->setMenu(m);
    bind(t, t);
    binding *bb = b;
    // the list is made when the button is opened
    QObject::connect(m, &QMenu::aboutToShow, [bb, m]() {
      m->clear();
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(bb->field, labels, values);
      for(std::size_t i = 0; i < labels.size(); i++) {
        QAction *a = m->addAction(qtString(labels[i]));
        int k = (int)i;
        QObject::connect(a, &QAction::triggered, [bb, k]() {
          Ui::Field g = bb->field;
          std::function<void()> after = bb->after;
          qtLater([g, k, after]() {
            if(g.choose) g.choose(k, true);
            if(g.done)
              g.done();
            else if(g.changed)
              g.changed();
            if(after) after();
          });
        });
      }
    });
  } break;
  case Ui::List: {
    QListWidget *l = new QListWidget;
    l->setSelectionMode(!f.choose    ? QAbstractItemView::NoSelection :
                        f.multiple   ? QAbstractItemView::ExtendedSelection :
                                       QAbstractItemView::SingleSelection);
    if(f.isCode) l->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    l->setMinimumHeight(f.rows ? qtPx(1.45 * f.rows) : qtPx(5.));
    bind(l, l);
    binding *bb = b;
    QObject::connect(l, &QListWidget::itemSelectionChanged, [bb, l]() {
      if(bb->quiet || !bb->field.choose) return;
      Ui::Field g = bb->field;
      for(int i = 0; i < l->count(); i++) g.choose(i, l->item(i)->isSelected());
      _told(bb, true);
    });
    // a line one clicks is one to be rid of
    QObject::connect(l, &QListWidget::itemClicked, [bb, l](QListWidgetItem *it) {
      if(bb->quiet || bb->field.choose || !bb->field.removeItem) return;
      int i = l->row(it);
      Ui::Field g = bb->field;
      std::function<void()> after = bb->after;
      qtLater([g, i, after]() {
        g.removeItem(i);
        if(g.changed) g.changed();
        if(after) after();
      });
    });
  } break;
  case Ui::Spacer: break;
  }
  if(!outer) return nullptr;
  if(f.tooltip.size() && qtSources().settings().tooltips)
    outer->setToolTip(qtString(f.tooltip));
  qtRefreshField(outer);
  return outer;
}

void qtRebindField(QWidget *widget, const Ui::Field &field)
{
  binding *b = _of(widget);
  if(!b || b->field.kind != field.kind) return;
  b->field = field;
  if(b->tree && field.hierarchy) b->tree->setTree(*field.hierarchy);
}

void qtRefreshField(QWidget *widget)
{
  binding *b = _of(widget);
  if(!b) return;
  const Ui::Field &f = b->field;
  b->quiet = true;
  switch(f.kind) {
  case Ui::Text:
  case Ui::Output: {
    QLineEdit *e = (QLineEdit *)b->inner;
    std::string value = f.getText();
    bool typing = f.kind == Ui::Text && e->hasFocus() &&
                  qtString(e->text()) != b->shown;
    if(!typing) {
      if(qtString(e->text()) != value) e->setText(qtString(value));
      b->shown = value;
    }
    if(f.kind == Ui::Text && f.dynamicChoices) {
      QComboBox *c = (QComboBox *)b->outer;
      std::vector<std::string> labels;
      std::vector<int> values;
      f.dynamicChoices(labels, values);
      if(_joined(labels) != b->was) {
        b->was = _joined(labels);
        QString keep = c->currentText();
        c->clear();
        for(const auto &l : labels) c->addItem(qtString(l));
        c->setEditText(keep);
      }
    }
  } break;
  case Ui::Integer:
  case Ui::Number: {
    QLineEdit *e = b->number ? b->number : (QLineEdit *)b->inner;
    std::string value = _number(f, f.getNumber());
    bool typing = e->hasFocus() && qtString(e->text()) != b->shown;
    if(!typing) {
      if(qtString(e->text()) != value) e->setText(qtString(value));
      b->shown = value;
    }
    if(b->number && !b->dragging && f.maximum > f.minimum)
      ((QSlider *)b->inner)
        ->setValue((int)std::floor(1000. * (f.getNumber() - f.minimum) /
                                     (f.maximum - f.minimum) +
                                   .5));
  } break;
  case Ui::Check:
    if(f.disclosure) {
      QToolButton *t = (QToolButton *)b->inner;
      bool on = f.getFlag();
      t->setChecked(on);
      t->setText(qtString(f.label) + (on ? " ▴" : " ▾"));
    }
    else
      ((QCheckBox *)b->inner)->setChecked(f.getFlag());
    break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    if(f.multiple) {
      QMenu *m = ((QToolButton *)b->inner)->menu();
      if(_joined(labels) != b->was) {
        b->was = _joined(labels);
        m->clear();
        for(std::size_t k = 0; k < labels.size(); k++) {
          QAction *a = m->addAction(qtString(labels[k]));
          a->setCheckable(true);
          int i = (int)k;
          binding *bb = b;
          QObject::connect(a, &QAction::toggled, [bb, i](bool on) {
            if(bb->quiet) return;
            if(bb->field.choose) bb->field.choose(i, on);
            _told(bb, true);
          });
        }
      }
      QList<QAction *> actions = m->actions();
      for(int k = 0; k < actions.size(); k++)
        actions[k]->setChecked(f.chosen && f.chosen(k));
      break;
    }
    QComboBox *c = (QComboBox *)b->inner;
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      c->clear();
      for(const auto &l : labels) c->addItem(qtString(l));
    }
    b->labels = labels;
    b->values = values;
    int which = -1;
    std::string current = values.empty() ? f.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(values.empty()) {
        if(labels[k] == current) which = (int)k;
      }
      else if(k < values.size() && values[k] == (int)f.getNumber())
        which = (int)k;
    }
    if(which < 0 && labels.size() && !values.empty()) which = 0;
    if(c->currentIndex() != which) c->setCurrentIndex(which);
  } break;
  case Ui::Label: {
    std::string value = f.getText();
    if(value.empty()) value = f.label;
    QLabel *l = (QLabel *)b->inner;
    if(qtString(l->text()) != value) l->setText(qtString(value));
  } break;
  case Ui::Prose: _prose(b); break;
  case Ui::Action: break;
  case Ui::Color: _setSwatch((QPushButton *)b->inner, f.getColour()); break;
  case Ui::Direction:
  case Ui::ColorMap: b->inner->update(); break;
  case Ui::Hierarchy:
    if(b->tree) b->tree->refresh(false);
    break;
  case Ui::Menu: ((QToolButton *)b->inner)->setText(qtString(f.label)); break;
  case Ui::List: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    QListWidget *l = (QListWidget *)b->inner;
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      l->clear();
      for(const auto &label : labels) {
        QListWidgetItem *it = new QListWidgetItem(l);
        if(f.columnsEm.size() && label.find('\t') != std::string::npos) {
          QWidget *line = _listLine(f, label);
          it->setSizeHint(line->sizeHint());
          l->setItemWidget(it, line);
        }
        else
          it->setText(qtString(label));
      }
    }
    if(f.chosen)
      for(int k = 0; k < l->count(); k++) l->item(k)->setSelected(f.chosen(k));
  } break;
  case Ui::Spacer: break;
  }
  if(f.enabled) b->outer->setEnabled(f.enabled());
  b->quiet = false;
}

QWidget *qtButtonWidget(const Ui::Button &button,
                        const std::function<void()> &after)
{
  std::string label = button.label;
  if(label.empty() && button.menu) label = "▾";
  if(label.empty()) label = button.glyph;
  QPushButton *w = new QPushButton(qtString(label));
  w->setAutoDefault(false);
  if(button.tooltip.size() && qtSources().settings().tooltips)
    w->setToolTip(qtString(button.tooltip));
  if(button.on && button.on()) {
    QFont bold = w->font();
    bold.setBold(true);
    w->setFont(bold);
  }
  if(button.enabled) w->setEnabled(button.enabled());
  Ui::Button b = button;
  QObject::connect(w, &QPushButton::clicked, [b, after]() {
    if(b.menu) {
      qtPopupMenu(b.menu());
      return;
    }
    std::function<void()> what = b.action;
    qtLater([what, after]() {
      if(what) what();
      if(after) after();
    });
  });
  return w;
}

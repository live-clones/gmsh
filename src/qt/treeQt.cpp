// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include "qtCommon.h"

#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QTreeWidget>

// The tree as a QTreeWidget: a branch is filled the first time it is opened,
// so that what is asked of the description is what is shown; a line with a
// field holds its widget. A node is its path, kept in the item, which is what
// survives a rebuild.

namespace {

  const int PathRole = Qt::UserRole, FilledRole = Qt::UserRole + 1;

  std::string _path(QTreeWidgetItem *item)
  {
    return qtString(item->data(0, PathRole).toString());
  }

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

} // namespace

qtTree::qtTree(const Ui::Tree &tree, bool picks,
               const std::function<void()> &after)
  : _tree(tree), _picks(picks), _after(after), _built(0), _everBuilt(false),
    _firstBuild(true), _quiet(false)
{
  _view = new QTreeWidget;
  _view->setHeaderHidden(true);
  _view->setColumnCount(1);
  _view->setIndentation(qtPx(1.1));
  _view->setContextMenuPolicy(Qt::CustomContextMenu);
  _view->setSelectionMode(QAbstractItemView::NoSelection);
  _view->setFocusPolicy(Qt::NoFocus);
  _view->header()->setStretchLastSection(true);

  QObject::connect(_view, &QTreeWidget::itemExpanded, [this](QTreeWidgetItem *it) {
    _fill(it);
    if(!_quiet && _tree.setClosed) _tree.setClosed(_path(it), false);
  });
  QObject::connect(_view, &QTreeWidget::itemCollapsed,
                   [this](QTreeWidgetItem *it) {
                     if(!_quiet && _tree.setClosed) _tree.setClosed(_path(it), true);
                   });
  // a line without a widget of its own is pressed where it is written
  QObject::connect(_view, &QTreeWidget::itemClicked,
                   [this](QTreeWidgetItem *it, int) {
                     if(_quiet || _picks || !_tree.node) return;
                     if(_view->itemWidget(it, 0)) return;
                     Ui::Node node = _tree.node(_path(it));
                     if(!node.pressed) return;
                     std::function<void()> what = node.pressed, after = _after;
                     qtLater([what, after]() {
                       what();
                       if(after) after();
                     });
                   });
  QObject::connect(_view, &QTreeWidget::itemChanged,
                   [this](QTreeWidgetItem *it, int) {
                     if(_quiet || !_picks || !_tree.node) return;
                     Ui::Node node = _tree.node(_path(it));
                     if(node.pick) node.pick(it->checkState(0) == Qt::Checked);
                     if(_after) _after();
                   });
  QObject::connect(_view, &QWidget::customContextMenuRequested,
                   [this](const QPoint &at) {
                     QTreeWidgetItem *it = _view->itemAt(at);
                     if(!it || !_tree.node) return;
                     Ui::Node node = _tree.node(_path(it));
                     if(node.menu) qtPopupMenu(node.menu());
                   });
  refresh(true);
}

qtTree::~qtTree()
{
  // the view is its holder's, which deletes it
}

QTreeWidgetItem *qtTree::_find(const std::string &path) const
{
  QString p = qtString(path);
  std::vector<QTreeWidgetItem *> todo;
  for(int i = 0; i < _view->topLevelItemCount(); i++)
    todo.push_back(_view->topLevelItem(i));
  while(!todo.empty()) {
    QTreeWidgetItem *it = todo.back();
    todo.pop_back();
    if(it->data(0, PathRole).toString() == p) return it;
    for(int i = 0; i < it->childCount(); i++) todo.push_back(it->child(i));
  }
  return nullptr;
}

void qtTree::_fill(QTreeWidgetItem *item)
{
  if(item->data(0, FilledRole).toBool()) return;
  item->setData(0, FilledRole, true);
  _branch(item, _path(item));
}

void qtTree::_branch(QTreeWidgetItem *parent, const std::string &path)
{
  if(!_tree.children || !_tree.node) return;
  bool commands = qtSources().settings().showModuleMenu;
  bool was = _quiet;
  _quiet = true;
  for(const std::string &child : _tree.children(path)) {
    if(path.empty() && child == "0Modules" && !commands && !_picks) continue;
    Ui::Node node = _tree.node(child);
    std::string label = _labelOf(node, child);
    QTreeWidgetItem *it = parent ? new QTreeWidgetItem(parent) :
                                   new QTreeWidgetItem(_view);
    it->setData(0, PathRole, qtString(child));
    bool branch = !_tree.children(child).empty();
    if(node.tooltip.size() && qtSources().settings().tooltips)
      it->setToolTip(0, qtString(node.tooltip));
    if(node.highlight.a)
      it->setBackground(0, QColor(node.highlight.r, node.highlight.g,
                                  node.highlight.b, node.highlight.a));
    if(_picks) {
      it->setText(0, qtString(label));
      it->setFlags(it->flags() | Qt::ItemIsUserCheckable);
      it->setCheckState(0, node.picked && node.picked() ? Qt::Checked :
                                                          Qt::Unchecked);
    }
    else if(!branch && node.hasField) {
      // the widget, and the name one presses after it
      QWidget *row = new QWidget;
      QHBoxLayout *h = new QHBoxLayout(row);
      h->setContentsMargins(0, 1, 0, 1);
      h->setSpacing(qtPx(.45));
      QWidget *w = qtFieldWidget(node.field, _after);
      if(w) {
        if(node.field.kind != Ui::Check && node.field.kind != Ui::Action)
          w->setFixedWidth(qtPx(8.));
        h->addWidget(w);
      }
      if(node.label.size()) {
        if(node.pressed) {
          QPushButton *name = new QPushButton(qtString(label));
          name->setFlat(true);
          name->setStyleSheet("text-align: left;");
          std::function<void()> what = node.pressed, after = _after;
          QObject::connect(name, &QPushButton::clicked, [what, after]() {
            qtLater([what, after]() {
              what();
              if(after) after();
            });
          });
          h->addWidget(name, 1);
        }
        else
          h->addWidget(new QLabel(qtString(label)), 1);
      }
      else
        h->addStretch(1);
      row->setProperty("gmshTreeField", QVariant::fromValue((void *)w));
      _view->setItemWidget(it, 0, row);
    }
    else
      it->setText(0, qtString(label));
    if(node.enabled && !node.enabled()) it->setDisabled(true);
    if(branch) {
      it->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
      // as the FLTK tree has it: the modules folded under their root -- a
      // branch is made when first opened, so always -- the rest open unless
      // the description folds it; the tree of a field folded
      bool open = !node.closed && !(_tree.closed && _tree.closed(child)) &&
                  !_picks &&
                  child.compare(0, 9, "0Modules/") != 0;
      for(auto w = _wanted.begin(); w != _wanted.end(); ++w)
        if(w->first == child) {
          open = w->second;
          _wanted.erase(w);
          break;
        }
      if(open) {
        _fill(it);
        it->setExpanded(true);
      }
    }
  }
  _quiet = was;
}

void qtTree::_build()
{
  // what was open stays open
  std::vector<QTreeWidgetItem *> todo;
  for(int i = 0; i < _view->topLevelItemCount(); i++)
    todo.push_back(_view->topLevelItem(i));
  while(!todo.empty()) {
    QTreeWidgetItem *it = todo.back();
    todo.pop_back();
    if(it->childCount() || it->data(0, FilledRole).toBool()) {
      std::string path = _path(it);
      bool asked = false;
      for(auto &w : _wanted)
        if(w.first == path) asked = true;
      if(!asked) _wanted.push_back(std::make_pair(path, it->isExpanded()));
    }
    for(int i = 0; i < it->childCount(); i++) todo.push_back(it->child(i));
  }
  _quiet = true;
  _view->clear();
  _branch(nullptr, "");
  _quiet = false;
  _firstBuild = false;
  _wanted.clear();
}

void qtTree::refresh(bool rebuild)
{
  unsigned generation = _tree.generation ? _tree.generation() : 0;
  if(rebuild || !_everBuilt || generation != _built) {
    _everBuilt = true;
    _built = generation;
    _build();
  }
  if(!_tree.node) return;
  _quiet = true;
  std::vector<QTreeWidgetItem *> todo;
  for(int i = 0; i < _view->topLevelItemCount(); i++)
    todo.push_back(_view->topLevelItem(i));
  while(!todo.empty()) {
    QTreeWidgetItem *it = todo.back();
    todo.pop_back();
    for(int i = 0; i < it->childCount(); i++) todo.push_back(it->child(i));
    Ui::Node node = _tree.node(_path(it));
    if(QWidget *row = _view->itemWidget(it, 0)) {
      QWidget *w = (QWidget *)row->property("gmshTreeField").value<void *>();
      if(w) {
        qtRebindField(w, node.field);
        qtRefreshField(w);
      }
    }
    if(_picks)
      it->setCheckState(0, node.picked && node.picked() ? Qt::Checked :
                                                          Qt::Unchecked);
    it->setDisabled(node.enabled ? !node.enabled() : false);
  }
  _quiet = false;
}

void qtTree::open(const std::string &path, bool open)
{
  if(open) {
    std::size_t at = 0;
    while((at = path.find('/', at + 1)) != std::string::npos)
      if(QTreeWidgetItem *up = _find(path.substr(0, at))) up->setExpanded(true);
  }
  if(QTreeWidgetItem *it = _find(path)) {
    it->setExpanded(open);
    return;
  }
  for(auto &w : _wanted)
    if(w.first == path) {
      w.second = open;
      return;
    }
  _wanted.push_back(std::make_pair(path, open));
}

bool qtTree::isOpen(const std::string &path) const
{
  if(QTreeWidgetItem *it = _find(path)) return it->isExpanded();
  for(auto &w : _wanted)
    if(w.first == path) return w.second;
  return false;
}

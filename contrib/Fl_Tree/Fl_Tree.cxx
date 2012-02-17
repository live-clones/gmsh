#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <FL/Fl_Tree.H>

#define SCROLL_W 15

//////////////////////
// Fl_Tree.cxx
//////////////////////
//
// Fl_Tree -- This file is part of the Fl_Tree widget for FLTK
// Copyright (C) 2009 by Greg Ercolano.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
// USA.
//

/// \mainpage Fl_Tree Widget
///
/// \image html tree-simple-screenshot.png
///
/// \code
///     Fl_Tree                                         // Top level widget
///        |--- Fl_Tree_Item                            // Items in the tree
///        |--- Fl_Tree_Prefs                           // Preferences for the tree
///                  |--- Fl_Tree_Connector (enum)      // Connection modes
///                  |--- Fl_Tree_Select (enum)         // Selection modes
///                  |--- Fl_Tree_Sort (enum)           // Sort behavior
///
/// \endcode
///
/// \b Overview
/// <P>
/// This is a hierarchical 'tree' browser widget that presents its data
/// in a hierarchy. Nodes can optionally be open/closed, and items can
/// be individually created, deleted, sorted, and attributes customized
/// for different fonts and colors.
///
/// The simple way to define a tree:
/// \code
///    Fl_Tree tree(X,Y,W,H);
///    tree.begin();
///      tree.add("Flintstones/Fred");
///      tree.add("Flintstones/Wilma");
///      tree.add("Flintstones/Pebbles");
///      tree.add("Simpsons/Homer");
///      tree.add("Simpsons/Marge");
///      tree.add("Simpsons/Bart");
///      tree.add("Simpsons/Lisa");
///    tree.end();
/// \endcode
///
/// Items can also be FLTK widgets, instead of just simple labels (default).
///
/// Fl_Tree derives from FLTK's Fl_Group, so that if FLTK widgets are added
/// to the tree, they become children of the group.
///
/// Each item in the tree is an Fl_Tree_Item, which has customizable
/// values for setting the font, color, and other attributes on a per-item
/// basis.
///
/// Each tree contains an instance of the Fl_Tree_Prefs class, which handles
/// global preferences for the tree, and the default values used for newly
/// created items in the tree.
///
/// By default, when items are added to the tree, they're added in the order created.
/// Sorting can be specified with the Fl_Tree::sortorder() method.
///
///     \image html tree-elements.png
///

// INTERNAL: scroller callback
static void scroll_cb(Fl_Widget*,void *data) {
    ((Fl_Tree*)data)->redraw();
}

// INTERNAL: Parse elements from path
//    Path="/aa/bb"
//    Return: arr[0]="aa", arr[1]="bb", arr[2]=0
//    Caller must: free(arr[0]); free(arr);
//
static char **parse_path(const char *path) {
    while ( *path == '/' ) path++;	// skip leading '/' 
    // First pass: identify, null terminate, and count separators
    int seps = 1;			// separator count (1: first item)
    int arrsize = 1;			// array size (1: first item)
    char *save = strdup(path);		// make copy we can modify
    char *s = save;
    while ( ( s = strchr(s, '/') ) ) {
	while ( *s == '/' ) { *s++ = 0; seps++; }
	if ( *s ) { arrsize++; }
    }
    arrsize++;				// (room for terminating NULL) 
    // Second pass: create array, save nonblank elements
    char **arr = (char**)malloc(sizeof(char*) * arrsize);
    int t = 0;
    s = save;
    while ( seps-- > 0 ) {
        if ( *s ) { arr[t++] = s; }	// skips empty fields, eg. '//'
        s += (strlen(s) + 1);
    }
    arr[t] = 0;
    return(arr);
}

// INTERNAL: Recursively descend tree hierarchy, accumulating total child count
static int find_total_children(Fl_Tree_Item *item, int count=0) {
    count++;
    for ( int t=0; t<item->children(); t++ ) {
	count = find_total_children(item->child(t), count);
    }
    return(count);
}

/// Constructor.
Fl_Tree::Fl_Tree(int X, int Y, int W, int H, const char *L) : Fl_Group(X,Y,W,H,L) { 
    _root = new Fl_Tree_Item(_prefs);
    _root->parent(0);				// we are root of tree
    _root->label("ROOT");
    _item_clicked = 0;
    box(FL_DOWN_BOX);
    color(FL_WHITE);
    when(FL_WHEN_CHANGED);
    _vscroll = new Fl_Scrollbar(0,0,0,0);	// will be resized by draw()
    _vscroll->hide();
    _vscroll->type(FL_VERTICAL);
    _vscroll->step(1);
    _vscroll->callback(scroll_cb, (void*)this);
    end();
}

/// Destructor.
Fl_Tree::~Fl_Tree() {
    if ( _root ) { delete _root; _root = 0; }
}

/// Adds a new item, given a 'menu style' path, eg: "/Parent/Child/item".
/// Any parent nodes that don't already exist are created automatically.
/// Adds the item based on the value of sortorder().
/// \returns the child item created, or 0 on error.
///
Fl_Tree_Item* Fl_Tree::add(const char *path) {
    if ( ! _root ) {					// Create root if none
	_root = new Fl_Tree_Item(_prefs);
	_root->parent(0);
	_root->label("ROOT");
    }
    char **arr = parse_path(path);
    Fl_Tree_Item *item = _root->add(_prefs, arr);
    free((void*)arr[0]);
    free((void*)arr);
    return(item);
}

/// Inserts a new item above the specified Fl_Tree_Item, with the label set to 'name'.
/// \returns the item that was added, or 0 if 'above' could not be found.
/// 
Fl_Tree_Item* Fl_Tree::insert_above(Fl_Tree_Item *above, const char *name) {
    return(above->insert_above(_prefs, name));
}

/// Find the item, given a menu style path, eg: "/Parent/Child/item".
///
/// There is both a const and non-const version of this method.
/// Const version allows pure const methods to use this method 
/// to do lookups without causing compiler errors.
/// \returns the item, or 0 if not found.
///
Fl_Tree_Item *Fl_Tree::find_item(const char *path) {
    if ( ! _root ) return(0);
    char **arr = parse_path(path);
    Fl_Tree_Item *item = _root->find_item(arr);
    free((void*)arr[0]);
    free((void*)arr);
    return(item);
}

/// A const version of Fl_Tree::find_item(const char *path)
const Fl_Tree_Item *Fl_Tree::find_item(const char *path) const {
    if ( ! _root ) return(0);
    char **arr = parse_path(path);
    const Fl_Tree_Item *item = _root->find_item(arr);
    free((void*)arr[0]);
    free((void*)arr);
    return(item);
}

/// Standard FLTK draw() method, handles draws the tree widget.
void Fl_Tree::draw() {
    // Let group draw box+label but *NOT* children.
    // *We* handle drawing children ourselves by calling each item's draw()
    //
    Fl_Group::draw_box();
    Fl_Group::draw_label();
    if ( ! _root ) return;
    int cx = x() + Fl::box_dx(box());
    int cy = y() + Fl::box_dy(box());
    int cw = w() - Fl::box_dw(box());
    int ch = h() - Fl::box_dh(box());
    // These valued changed during drawing
    // 'Y' will be the lowest point on the tree
    int X = cx + _prefs.marginleft();
    int Y = cy + _prefs.margintop() - (_vscroll->visible() ? _vscroll->value() : 0);
    int W = cw - _prefs.marginleft();		// - _prefs.marginright();
    int Ysave = Y;
    fl_push_clip(cx,cy,cw,ch);
    {
        fl_font(_prefs.labelfont(), _prefs.labelsize());
        _root->draw(X, Y, W, this, _prefs);
    }
    fl_pop_clip();
    // Should we show vertical scrollbar?
    int ydiff = (Y+_prefs.margintop())-Ysave;		// ydiff=size of tree
    int ytoofar = (cy+ch) - Y;				// ytoofar -- scrolled beyond bottom (eg. stow)

    //printf("ydiff=%d ch=%d Ysave=%d ytoofar=%d value=%d\n",
    //int(ydiff),int(ch),int(Ysave),int(ytoofar), int(_vscroll->value()));

    if ( ytoofar > 0 ) ydiff += ytoofar;
    if ( Ysave<cy || ydiff > ch || int(_vscroll->value()) > 1 ) {
        _vscroll->visible();
	int sx = x()+w()-Fl::box_dx(box())-SCROLL_W;
	int sy = y()+Fl::box_dy(box());
	int sw = SCROLL_W;
	int sh = h()-Fl::box_dh(box());
	_vscroll->show();
	_vscroll->range(0.0,ydiff-ch);
	_vscroll->resize(sx,sy,sw,sh);
	_vscroll->slider_size(float(ch)/float(ydiff));
    } else {
        _vscroll->Fl_Slider::value(0);
        _vscroll->hide();
    }
    fl_push_clip(cx,cy,cw,ch);
        Fl_Group::draw_children();
    fl_pop_clip();
}

/// Standard FLTK event handler for this widget.
int Fl_Tree::handle(int e) {
    static Fl_Tree_Item *lastselect = 0;
    int changed = 0;
    int ret = Fl_Group::handle(e);
    if ( ! _root ) return(ret);
    switch ( e ) {
	case FL_PUSH: {
	    lastselect = 0;
	    item_clicked(0);	// assume no item was clicked
	    Fl_Tree_Item *o = _root->find_clicked();
	    if ( o ) {
		ret |= 1;					// handled
	        if ( Fl::event_button() == FL_LEFT_MOUSE ) {
		    // Was collapse icon clicked?
		    if ( o->event_on_collapse_icon(_prefs) ) {
			o->open_toggle();
			redraw();
		    }
		    // Item's label clicked?
		    else if ( o->event_on_label(_prefs) && 
			      (!o->widget() || !Fl::event_inside(o->widget())) &&
			      callback() &&
			      (!_vscroll->visible() || !Fl::event_inside(_vscroll)) ) {
			item_clicked(o);			// save item clicked
			// Handle selection behavior
			switch ( _prefs.selectmode() ) {
			    case FL_TREE_SELECT_NONE: {		// no selection changes
			        break;
			    }
			    case FL_TREE_SELECT_SINGLE: {
				changed = select_only(o);
			        break;
			    }
			    case FL_TREE_SELECT_MULTI: {
			        int state = Fl::event_state();
			        if ( state & FL_SHIFT ) {
				    if ( ! o->is_selected() ) {
					o->select();		// add to selection
					changed = 1;		// changed
				    }
				} else if ( state & FL_CTRL ) {
				    changed = 1;		// changed
				    o->select_toggle();		// toggle selection state
				    lastselect = o;		// save we toggled it (prevents oscillation)
				} else {
				    changed = select_only(o);
				}
			        break;
			    }
			}
			if ( changed ) {
			    redraw();				// make change(s) visible
			    if ( when() & FL_WHEN_CHANGED ) {
				set_changed();
				do_callback((Fl_Widget*)this, user_data());	// item callback
			    }
			}
		    }
		}
	    }
	    break;
	}
	case FL_DRAG: {
	    Fl_Tree_Item *o = _root->find_clicked();
	    if ( o ) {
		ret |= 1;				// handled
		// Item's label clicked?
		if ( o->event_on_label(_prefs) && 
			  (!o->widget() || !Fl::event_inside(o->widget())) &&
			  callback() &&
			  (!_vscroll->visible() || !Fl::event_inside(_vscroll)) ) {
		    item_clicked(o);			// save item clicked
		    // Handle selection behavior
		    switch ( _prefs.selectmode() ) {
			case FL_TREE_SELECT_NONE: {	// no selection changes
			    break;
			}
			case FL_TREE_SELECT_SINGLE: {
			    changed = select_only(o);
			    break;
			}
			case FL_TREE_SELECT_MULTI: {
			    int state = Fl::event_state();
			    if ( state & FL_CTRL ) {
				if ( lastselect != o ) {// not already toggled from last microdrag?
				    changed = 1;	// changed
				    o->select_toggle();	// toggle selection
				    lastselect = o;	// save we toggled it (prevents oscillation)
				    redraw();		// make change(s) visible
				}
			    } else {
				changed = 1;		// changed
				o->select();		// select this
				redraw();		// make change(s) visible
			    }
			    break;
			}
		    }
		    if ( changed ) {
			redraw();				// make change(s) visible
			if ( when() & FL_WHEN_CHANGED ) {
			    set_changed();
			    do_callback((Fl_Widget*)this, user_data());	// item callback
			}
		    }
		}
	    }
	}
	case FL_RELEASE: {
	    if ( Fl::event_button() == FL_LEFT_MOUSE ) {
		ret |= 1;
	    }
	    break;
	}
    }
    return(ret);
}

/// Deselect item and all its children.
///     If item is NULL, root() is used.
///     Handles calling redraw() if anything was changed.
///     Returns count of how many items were in the 'selected' state,
///     ie. how many items were "changed".
///
int Fl_Tree::deselect_all(Fl_Tree_Item *item) {
    item = item ? item : root();		// NULL? use root()
    int count = item->deselect_all();
    if ( count ) redraw();			// anything changed? cause redraw
    return(count);
}

/// Select only this item.
///     If item is NULL, root() is used.
///     Handles calling redraw() if anything was changed.
///     Returns how many items were changed, if any.
///
int Fl_Tree::select_only(Fl_Tree_Item *selitem) {
    selitem = selitem ? selitem : root();		// NULL? use root()
    int changed = 0;
    for ( Fl_Tree_Item *item = first(); item; item = item->next() ) {
        if ( item == selitem ) {
	    if ( item->is_selected() ) continue;	// don't count if already selected
	    item->select();
	    ++changed;
	} else {
	    if ( item->is_selected() ) {
	       item->deselect();
	       ++changed;
	    }
        }
    }
    if ( changed ) redraw();				// anything changed? redraw
    return(changed);
}

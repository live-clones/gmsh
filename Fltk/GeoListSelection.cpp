
//
// Geo & OCC
// GMSH
//
#include <GmshConfig.h>
#include <GmshDefines.h>
#include <GmshMessage.h>
#include "GModel.h" 

#ifdef HAVE_FLTK
//
// GMSH-FLTK
//
#include <FlGui.h>
#include <openglWindow.h>
#include <drawContext.h>
//
// FLTK
//
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Double_Window.H>
//
#endif
/**
A GUI for selection of entity as an alternative the current keyboard usage.
It mimics the the keyboard while the entities are selected from a window Tree-List
It can be used for any : Physical groups, split curve, transformation, etc, any 
process that require selection of Geo-Entities.
We did not enclude the selection of elements, even though it also doable in the same way.
Elements manipulation may still be done through the visibility windows.
Author : Samy Mukadi, PhD P.Eng., Edmonton, AB, Canada, 
Date   : Sept 06/2019
***/
namespace GeoListSelection { 
	//
	static Fl_Window * win;
	static Fl_Tree* treeLeft, *treeRight, *treeStatus;
	static Fl_Box * boxTitle;
	Fl_Button * buttonR;
	Fl_Button * buttonA;
	Fl_Button * buttonUndo;
	Fl_Tile* splitPane;
	static std::string RoutineStatus;
	bool useTempTree = true; // useful for undoing selection
	//
	static void _add_vertex ( GVertex *gv, Fl_Tree *tree, Fl_Tree_Item *parent )
	{
		std::ostringstream vertex;
		vertex << "Point " << gv->tag ();
		Fl_Tree_Item *node = parent->add ( tree->prefs (), vertex.str ().c_str () );
		node->user_data ( ( void * ) gv );
		//node->close ();
	}

	static void _add_edge ( GEdge *ge, Fl_Tree *tree, Fl_Tree_Item *parent )
	{
		std::ostringstream edge;
		edge << "Curve " << ge->tag ();
		Fl_Tree_Item *node = parent->add ( tree->prefs (), edge.str ().c_str () );
		node->user_data ( ( void * ) ge );
		node->close ();
		if ( ge->getBeginVertex () ) _add_vertex ( ge->getBeginVertex (), tree, node );
		if ( ge->getEndVertex () ) _add_vertex ( ge->getEndVertex (), tree, node );
	}

	static void _add_face ( GFace *gf, Fl_Tree *tree, Fl_Tree_Item *parent )
	{
		std::ostringstream face;
		face << "Surface " << gf->tag ();
		Fl_Tree_Item *node = parent->add ( tree->prefs (), face.str ().c_str () );
		node->user_data ( ( void * ) gf );
		node->close ();
		std::vector<GEdge *> const &edges = gf->edges ();
		for ( std::vector<GEdge *>::const_iterator it = edges.begin ();
			it != edges.end (); it++ )
			_add_edge ( *it, tree, node );
	}

	static void _add_region ( GRegion *gr, Fl_Tree *tree, Fl_Tree_Item *parent )
	{
		std::ostringstream region;
		region << "Volume " << gr->tag ();
		Fl_Tree_Item *node = parent->add ( tree->prefs (), region.str ().c_str () );
		node->user_data ( ( void * ) gr );
		node->close ();
		std::vector<GFace *> faces = gr->faces ();
		for ( std::vector<GFace *>::iterator it = faces.begin (); it != faces.end (); it++ )
			_add_face ( *it, tree, node );
	}

	void rebuildSelectTree ( GModel* model, Fl_Tree *tree ) {

		Fl_Tree_Item *elementary = tree->root (); // add ( "Elementary entities" );
		//
		int type = FlGui::instance ()->currentSectionType;
		//
		if ( type == ENT_ALL || type == ENT_VOLUME )
			for ( GModel::riter it = model->firstRegion (); it != model->lastRegion (); it++ )
				_add_region ( *it, tree, elementary );
		//
		if ( type == ENT_ALL || type == ENT_SURFACE )
			for ( GModel::fiter it = model->firstFace (); it != model->lastFace (); it++ )
				_add_face ( *it, tree, elementary );
		//
		if ( type == ENT_ALL || type == ENT_CURVE )
			for ( GModel::eiter it = model->firstEdge (); it != model->lastEdge (); it++ )
				_add_edge ( *it, tree, elementary );
		//
		if ( type == ENT_ALL || type == ENT_POINT )
			for ( GModel::viter it = model->firstVertex (); it != model->lastVertex (); it++ )
				_add_vertex ( *it, tree, elementary );
		//
		elementary->open ();
	}

	void getEntitySelectedFromTree ( Fl_Tree *tree, int type, bool multiple,
		std::map<int, std::vector<GEntity*>>& entities ) {
		//
		if ( type == ENT_ALL || type == ENT_POINT ||
			type == ENT_CURVE || type == ENT_SURFACE || type == ENT_VOLUME ) {
			for ( Fl_Tree_Item *selectedItem = treeLeft->first_selected_item (); selectedItem;
				selectedItem = treeLeft->next_selected_item ( selectedItem, FL_Down ) ) {
				GEntity* ge = ( GEntity* ) selectedItem->user_data ();
				if ( ge ) {
					entities[ge->dim ()].push_back ( ge );
					if ( !multiple )return;
				}
			}
		}
		//
	}

	void TreeSelectionCBCallBack ( Fl_Widget *widget, void *object ) {
		//
		Fl_Tree *tree = ( Fl_Tree* ) widget;
		if ( !tree )return;
		Fl_Tree_Item *item = ( Fl_Tree_Item* ) tree->callback_item ();
		if ( !item ) return;
		GEntity * ge = ( GEntity * ) item->user_data ();
		if ( !ge ) return;
		//
		switch ( tree->callback_reason () ) {
		case FL_TREE_REASON_SELECTED: {
			if ( ge ) ge->setSelection ( 1 );
			drawContext::global ()->draw ();
		}break;
		case FL_TREE_REASON_DESELECTED: {
			if ( ge ) ge->setSelection ( 0 );
			drawContext::global ()->draw ();
		}break;
		case FL_TREE_REASON_OPENED:
		case FL_TREE_REASON_CLOSED:
		default:
			break;
		}
	}

	template<class T>
	static void insertEntities ( std::vector<T*>& dst, std::vector<GEntity*>& src ) {
		for ( auto value : src ) {
			dst.push_back ( ( T* ) value );
		}
	}

	void addSelectedEntities ( std::map<int, std::vector<GEntity*>>& entities ) {
		//
		auto gui = FlGui::instance ();
		if ( entities.find ( 0 ) != entities.end () )insertEntities ( gui->selectedVertices, entities[0] );
		if ( entities.find ( 1 ) != entities.end () )insertEntities ( gui->selectedEdges, entities[1] );
		if ( entities.find ( 2 ) != entities.end () )insertEntities ( gui->selectedFaces, entities[2] );
		if ( entities.find ( 3 ) != entities.end () )insertEntities ( gui->selectedRegions, entities[3] );
	}

	void buttonAcceptSelectionCB () {
		//
		//  Just accept and store into Left-tree at the top
		//
		std::map<int, std::vector<GEntity*>> entities;
		int type = FlGui::instance ()->currentSectionType;
		FlGui::instance ()->getCurrentOpenglWindow ()->endSelection;
		FlGui::instance ()->getCurrentOpenglWindow ()->quitSelection;
		//
		if ( type == ENT_ALL || type == ENT_POINT ||
			type == ENT_CURVE || type == ENT_SURFACE || type == ENT_VOLUME ) {
			for ( Fl_Tree_Item *selectedItem = treeLeft->first_selected_item (); selectedItem;
				selectedItem = treeLeft->next_selected_item ( selectedItem, FL_Down ) ) {
				GEntity* ge = ( GEntity* ) selectedItem->user_data ();
				if ( ge ) {
					entities[ge->dim ()].push_back ( ge );
					std::stringstream ss;
					ss << ( treeRight->root ()->children () + 1 ) << ") " << selectedItem->label ();
					auto item = treeRight->add ( ss.str ().c_str () );
					if ( !item ) continue;
					item->user_data ( selectedItem->user_data () );
					//
					//	if ( !multiple )break;
				}
			}
			//
			//  add intermediate selections
			//
		}
		treeRight->redraw ();
		treeStatus->redraw ();
	}

	void buttonApplyCurrentCB () {
		//
		if ( !useTempTree ) {
			buttonAcceptSelectionCB ();
		}
		//
		//  add intermediate selections from the Top treePane
		//
		std::map<int, std::vector<GEntity*>> entities;
		for ( int n = 0; n < treeRight->root ()->children (); n++ ) {
			auto item = treeRight->root ()->child ( n );
			GEntity* ge = ( GEntity* ) item->user_data ();
			entities[ge->dim ()].push_back ( ge );
			std::stringstream ss;
			std::string str = item->label ();
			int pos = str.find ( ")" ) + 1;
			str = str.substr ( pos );
			ss << ( treeStatus->root ()->children () + 1 ) << ") " << str;
			item = treeStatus->add ( ss.str ().c_str () );
			if ( !item ) continue;
			item->user_data ( item->user_data () );
		}
		addSelectedEntities ( entities );
		//
		//  Response :: Mimic the keyboard event 'l', lowercase 'L'
		//
		FlGui::instance ()->getCurrentOpenglWindow ()->tryGuiSelectionAction = true;
		Fl::selection ( *FlGui::instance ()->getCurrentOpenglWindow (), "l", 1 );
		//
		treeRight->root ()->clear_children ();
		treeStatus->redraw ();
		treeRight->redraw ();
	}

	void buttonRemoveCallBack ( Fl_Widget *w, void *object ) {
		Fl_Tree* tree = ( Fl_Tree* ) ( object );
		if ( !tree )return;
		for ( Fl_Tree_Item *selectedItem = treeLeft->first_selected_item (); selectedItem;
			selectedItem = treeLeft->next_selected_item ( selectedItem, FL_Down ) ) {
			GEntity* ge = ( GEntity* ) selectedItem->user_data ();
			if ( ge ) ge->setSelection ( 0 );
			tree->remove ( selectedItem );
		}
		tree->redraw ();
	}

	void CloseCleanQuit () {
		FlGui::instance ()->getCurrentOpenglWindow ()->quitSelection = true;
		Fl::selection ( *FlGui::instance ()->getCurrentOpenglWindow (), "q", 1 );
		treeRight->root ()->clear_children ();
		treeLeft->root ()->clear_children ();
		treeStatus->root ()->clear_children ();
		win->hide ();
	}

	void buttonExecuteCB ( Fl_Widget *w, void *object ) {
		//
		Fl_Tree* tree = ( Fl_Tree* ) ( object );
		if ( !tree )return;
		//
		int type = FlGui::instance ()->currentSectionType;
		std::map<int, std::vector<GEntity*>> entities;
		getEntitySelectedFromTree ( tree, type, true, entities );
		addSelectedEntities ( entities );
		//
		//  Execute :: Mimic the keyboard event 'e'
		//
		FlGui::instance ()->getCurrentOpenglWindow ()->endSelection = true;
		Fl::selection ( *FlGui::instance ()->getCurrentOpenglWindow (), "e", 1 );
		//
	}

	void reset () {
		if ( !useTempTree ) {
			treeRight->hide ();
			treeStatus->resize ( treeStatus->x (), boxTitle->y () + boxTitle->h (), treeStatus->w (), splitPane->h () );
			buttonR->deactivate ();
			buttonUndo->deactivate ();
		}
		else {
			buttonUndo->activate ();
			buttonR->activate ();
			treeRight->show ();
			int HH = ( int ) ( 0.4*splitPane->h () );
			treeRight->resize ( treeStatus->x (), boxTitle->y () + boxTitle->h (), treeStatus->w (), HH );
			treeStatus->resize ( treeStatus->x (), treeRight->y () + treeRight->h (), treeStatus->w (), splitPane->h () - HH );
		}
	}

	void ChangeOption ( Fl_Widget *wButton ) {
		Fl_Check_Button* checkButton = ( Fl_Check_Button * ) ( wButton );
		useTempTree = checkButton->value ();
		reset ();
		win->redraw ();
	}

	void ShowMessage () {
		static const char* message =
			"Step 0. Select Entity From the Left. \n"
			"Step 1. Move it to the right pressing the button ->\n"
			"Step 2. Apply To accept all the choices from Step 1.\n"
			"Step 3. Execute to get the results.\n"
			"Quit or Repeat from 0-3, if more is needed.";
		fl_message ( message );
	}

	void ShowCloseMessage () {
		int res = fl_choice ( "Close and Quit?", "NO", "YES", 0 );
		if ( res == 1 ) {
			CloseCleanQuit ();
		}
	}

	void createSelectionWindow ( GModel* model, int type ) {
		//
		// We just do for geometry. 
		// The other is for mesh and views can work with the Visibility window,
		// As we do not see any usefullness of it here.
		// However, it could be implemented in the same as for geometry, by creating
		// "Fl_tree_item" for each MElement belonging to the parent geometry 
		//
		if ( type > 3 )return;
		//
		std::string status = FlGui::instance ()->getCurrentOpenglWindow ()->screenMessage[0];
		// std::string status = Msg::GetStatusGl ();
		//int pos = status.find ( '\n' );
		//status = status.substr ( 0, pos );
		const char* statusGl = status.c_str ();
		if ( win ) {
			treeRight->root ()->clear_children ();
			treeLeft->root ()->clear_children ();
			rebuildSelectTree ( model, treeLeft );
			boxTitle->copy_label ( statusGl );
			//
			//  Status to clenUp when Callback changes
			//  No need to close the window.
			//
			//if ( RoutineStatus.compare ( Msg::StatusRoutine () ) ) {
				//RoutineStatus = Msg::StatusRoutine ();
				//treeStatus->root ()->clear_children ();
			//}
			if ( !win->visible () ) {
				win->show ();
			}
			else {
				treeRight->redraw ();
				treeLeft->redraw ();
				treeStatus->redraw ();
			}
			return;
		}
		//
		int width = 380, height = 450;
		int x = 0, y = 0;
		win = new Fl_Window ( width, height, "Geometry Selection" );
		win->callback ( ( Fl_Callback* ) ShowCloseMessage );
		//
		win->set_non_modal ();
		win->box ( FL_FLAT_BOX );
		win->resizable ( win );
		//
		boxTitle = new Fl_Box ( x, y, width, 50 );
		boxTitle->copy_label ( statusGl );
		boxTitle->box ( FL_FLAT_BOX );
		boxTitle->color ( 19 );
		boxTitle->labelsize ( 14 );
		y = boxTitle->y () + boxTitle->h ();
		//
		{
			//
			// Geometry Entity Listing
			//
			int w = 150;
			//
			height -= y;
			Fl_Group * boxGroup1 = new Fl_Group ( x, y, width, height - 30 );
			boxGroup1->begin ();
			splitPane = new Fl_Tile ( x, y, width, boxGroup1->h () );
			splitPane->begin ();
			//
			// Left
			//
			treeLeft = new Fl_Tree ( x, y, w, splitPane->h () );
			treeLeft->root ()->label ( "Simple Geom" );
			treeLeft->marginleft ( 2 );
			//
			treeLeft->callback ( ( Fl_Callback* ) TreeSelectionCBCallBack );
			//treeLeft->item_draw_mode ( FL_TREE_ITEM_DRAW_LABEL_AND_WIDGET );
			treeLeft->selectmode ( FL_TREE_SELECT_MULTI );
			treeLeft->marginleft ( 2 );
			rebuildSelectTree ( model, treeLeft );
			//
			x = treeLeft->w () + treeLeft->x ();
			Fl_Group * boxGroupC = new Fl_Group ( x, y, 80, splitPane->h () );
			boxGroupC->begin ();

			x = boxGroupC->x () + 2;
			// HELP
			Fl_Button* helpButton = new Fl_Button ( x, boxGroupC->y (), 76, 20, "??" );
			helpButton->callback ( ( Fl_Callback* ) ShowMessage );
			helpButton->tooltip ( "Show usage message." );
			helpButton->labelfont ( FL_BOLD );
			helpButton->labelsize ( 15 );
			helpButton->labelcolor ( fl_rgb_color ( 0, 180, 0 ) );
			//  Undo
			buttonUndo = new Fl_Button ( x, helpButton->y () + helpButton->h () + 10, 76, 20, "Undo('u')" );
			buttonUndo->copy_tooltip ( "Remove the Temporary Selected entity, from Right pane" );
			// Step 1.
			buttonR = new Fl_Button ( x, buttonUndo->y () + buttonUndo->h () + 40, 76, 20, "1. - >" );
			buttonR->copy_tooltip ( "Move Into the Temporary Selection" );
			// Step 2.
			buttonA = new Fl_Button ( x, buttonR->y () + buttonR->h () + 5, 76, 20, "2. Apply('e')" );
			buttonA->copy_tooltip (
				"Accept & Apply the Temporary the Selection.\n"
				"That selection will become history.\n" );
			// Step 3.
			Fl_Button* butt = new Fl_Button ( x, buttonA->y () + buttonA->h () + 5, 76, 20 , "3. Execute 'e'" );
			butt->callback ( ( Fl_Callback* ) buttonExecuteCB, treeLeft );
			butt->tooltip ( "Executes for the current the selections" );

			boxGroupC->end ();
			//
			x = boxGroupC->w () + boxGroupC->x ();
			Fl_Group * boxGroupR = new Fl_Group ( x, y, width - x, splitPane->h () );
			boxGroupR->begin ();
			Fl_Tile* splitPaneR = new Fl_Tile ( x, y, width - x, splitPane->h () );
			splitPaneR->begin ();
			//
			//  Right - TOP
			//
			double ratio = 0.4;
			int HH = ( int ) ( ratio*splitPane->h () );
			treeRight = new Fl_Tree ( x, y, splitPaneR->w (), HH );
			treeRight->root ()->label ( "Temp Selection" );
			treeRight->callback ( ( Fl_Callback* ) TreeSelectionCBCallBack );
			//treeRight->item_draw_mode ( FL_TREE_ITEM_DRAW_LABEL_AND_WIDGET );
			treeRight->selectmode ( FL_TREE_SELECT_MULTI );
			treeRight->marginleft ( 0 );
			//
			//  Right - Bottom
			//
			y = treeRight->y () + treeRight->h ();
			treeStatus = new Fl_Tree ( x, y, splitPaneR->w (), splitPane->h () - HH );
			treeStatus->root ()->label ( "Selection History" );
			treeStatus->callback ( ( Fl_Callback* ) TreeSelectionCBCallBack );
			//treeStatus->item_draw_mode ( FL_TREE_ITEM_DRAW_LABEL_AND_WIDGET );
			treeStatus->selectmode ( FL_TREE_SELECT_MULTI );
			treeStatus->marginleft ( 0 );
			//
			splitPaneR->end ();
			boxGroupR->end ();
			//
			splitPane->resizable ( treeLeft );
			splitPane->end ();
			boxGroup1->end ();
			//
			static Fl_Tree* trees[] = { treeLeft, treeRight, treeStatus };
			buttonR->callback ( ( Fl_Callback* ) buttonAcceptSelectionCB, ( void* ) trees );
			buttonA->callback ( ( Fl_Callback* ) buttonApplyCurrentCB, ( void* ) treeStatus );
			buttonUndo->callback ( ( Fl_Callback* ) buttonRemoveCallBack, ( void* ) treeRight );
			//
			// Bottom
			//
			x = boxGroup1->x ();
			y = boxGroup1->y () + boxGroup1->h ();
			HH = 30;
			auto boxGroup2 = new Fl_Group ( x, y, width, HH );
			boxGroup2->begin ();
			//
			y += 5;
			int wt = 90;
			//
			Fl_Check_Button* checkButton = new Fl_Check_Button ( x + 10, y, wt, 20, "Use Step 1" );
			checkButton->callback ( ( Fl_Callback* ) ChangeOption );
			checkButton->value ( useTempTree );
			checkButton->tooltip (
				"Use Step 1 for undo possibility. Eitherwise,\n"
				"Just Combine Step 1 into Step 2, no-Undo" );
			checkButton->value ( 1 );
			//
			x = width - (wt + 5);
			butt = new Fl_Return_Button ( x, y, wt, 20 );
			butt->copy_label ( "Quit 'q'" );
			butt->callback ( ( Fl_Callback* ) CloseCleanQuit, win );
			butt->tooltip ( "Finish and Quit the window" );
			//
			boxGroup2->end ();
			//
		}
		//
		win->end ();
		win->show ();
	}
}

void showSelectionWindow ( GModel* model, int type ) {

#if defined(HAVE_FLTK)
	struct MSGINFO {
		GModel* model;
		int type;
		static	void message ( MSGINFO * msg ) {
			GeoListSelection::createSelectionWindow ( msg->model, msg->type );
			GeoListSelection::reset ();
		}
	};

	MSGINFO* msg = new MSGINFO ();
	msg->model = model;
	msg->type = type;
	// 
	// We run on the main thread
	//
	Fl::awake ( ( Fl_Awake_Handler ) MSGINFO::message, msg );
	Fl::awake ();
#endif
}

void closeSelectionWindow () {
#if defined(HAVE_FLTK)
	if ( GeoListSelection::win ) {
		GeoListSelection::CloseCleanQuit ();
	}
#endif
}
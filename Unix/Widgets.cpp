/* $Id: Widgets.cpp,v 1.28 2000-12-29 14:04:29 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"
#include "Mesh.h"
#include "Context.h"
#include "XContext.h"
#include "Info.h"
#include "Widgets.h"
#include "Help.h"

extern Context_T   CTX ;
extern XContext_T  XCTX ;

/* hardcoded this one, since it is required for the motion handling */

static char DrawingAreaTranslations[] = "#replace\n\
~s ~m ~a <Key>Return:DrawingAreaInput() ManagerParentActivate()\n\
<Key>Return:DrawingAreaInput() ManagerGadgetSelect()\n\
<Key>osfActivate:DrawingAreaInput() ManagerParentActivate()\n\
<Key>osfCancel:DrawingAreaInput() ManagerParentCancel()\n\
<Key>osfHelp:DrawingAreaInput() ManagerGadgetHelp()\n\
<Key>space:DrawingAreaInput() ManagerGadgetSelect()\n\
<Key>osfSelect:DrawingAreaInput() ManagerGadgetSelect()\n\
<KeyDown>:DrawingAreaInput() ManagerGadgetKeyInput()\n\
<KeyUp>:DrawingAreaInput()\n\
<BtnMotion>:DrawingAreaInput() ManagerGadgetButtonMotion()\n\
<Motion>:DrawingAreaInput() ManagerGadgetButtonMotion()\n\
<Btn1Down>:DrawingAreaInput() ManagerGadgetArm()\n\
<Btn1Up>:DrawingAreaInput() ManagerGadgetActivate()\n\
<Btn2Down>:DrawingAreaInput() ManagerGadgetDrag()\n\
<BtnDown>:DrawingAreaInput()\n\
<BtnUp>:DrawingAreaInput()";

/* ------------------------------------------------------------------------ 
    MENU WINDOW
   ------------------------------------------------------------------------ */

void CreateWidgets_M(Widgets_T *w){
  int   i, n ;
  Arg   arg[10] ;

  /* menu shell */
  w->M.shell = 
    XtVaAppCreateShell("Gmsh", "gmshMW", applicationShellWidgetClass, XCTX.display, 
                       XmNvisual, XCTX.gui.visual,
                       XmNcolormap, XCTX.gui.colormap,
                       NULL);
  
  /* menu main window */
  i=0;
  w->M.containerWin = XmCreateMainWindow(w->M.shell, "McontainerWin", arg, i);
  XtManageChild(w->M.containerWin);
  
  /* menu bar */
  i=0;
  w->M.menuBar = XmCreateMenuBar(w->M.containerWin, "MmenuBar", arg, i);
  XtManageChild(w->M.menuBar);

  /* file menu */
  i=0;
  w->M.filePane = XmCreatePulldownMenu(w->M.menuBar, "MfilePane", arg, i);
                                        
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Open")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-o)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>o:"); i++;
  w->M.fileButt[0] = XmCreatePushButton(w->M.filePane, "MfileButt0", arg, i);
  XtManageChild(w->M.fileButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Merge")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-m)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>m:"); i++;
  w->M.fileButt[1] = XmCreatePushButton(w->M.filePane, "MfileButt1", arg, i);
  XtManageChild(w->M.fileButt[1]);

  i=0;
  w->M.fileSep[0] = XmCreateSeparator(w->M.filePane, "MfileSep0", arg, i);
  XtManageChild(w->M.fileSep[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Save Mesh")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-s)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>s:"); i++;
  w->M.fileButt[2] = XmCreatePushButton(w->M.filePane, "MfileButt2", arg, i);
  XtManageChild(w->M.fileButt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Save as")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-p)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>p:"); i++;
  w->M.fileButt[3] = XmCreatePushButton(w->M.filePane, "MfileButt3", arg, i);
  XtManageChild(w->M.fileButt[3]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Save Options as")); i++;
  w->M.fileButt[4] = XmCreatePushButton(w->M.filePane, "MfileButt4", arg, i);
  XtManageChild(w->M.fileButt[4]);

  i=0;
  w->M.fileSep[1] = XmCreateSeparator(w->M.filePane, "MfileSep1", arg, i);
  XtManageChild(w->M.fileSep[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Reload All Views")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-l)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>l:"); i++;
  w->M.fileButt[5] = XmCreatePushButton(w->M.filePane, "MfileButt6", arg, i);
  XtManageChild(w->M.fileButt[5]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Remove All Views")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-r)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>r:"); i++;
  w->M.fileButt[6] = XmCreatePushButton(w->M.filePane, "MfileButt7", arg, i);
  XtManageChild(w->M.fileButt[6]);

  i=0;
  w->M.fileSep[2] = XmCreateSeparator(w->M.filePane, "MfileSep2", arg, i);
  XtManageChild(w->M.fileSep[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Quit")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(C-q)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Ctrl<Key>q:"); i++;
  w->M.fileButt[7] = XmCreatePushButton(w->M.filePane, "MfileButt8", arg, i);
  XtManageChild(w->M.fileButt[7]);

  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->M.filePane); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("File")); i++;
  w->M.fileCascade = XmCreateCascadeButton(w->M.menuBar, "MfileCascade", arg, i);
  XtManageChild(w->M.fileCascade);

  /* module menu */
  i=0;
  w->M.modulePane = XmCreatePulldownMenu(w->M.menuBar, "MmodulePane", arg, i);
                                        
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Geometry")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(g)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "<Key>g:"); i++;
  w->M.moduleButt[0] = XmCreatePushButton(w->M.modulePane, "MmoduleButt0", arg, i);
  XtManageChild(w->M.moduleButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Mesh")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(m)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "<Key>m:"); i++;
  w->M.moduleButt[1] = XmCreatePushButton(w->M.modulePane, "MmoduleButt1", arg, i);
  XtManageChild(w->M.moduleButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Post Processing")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(p)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "<Key>p:"); i++;
  w->M.moduleButt[2] = XmCreatePushButton(w->M.modulePane, "MmoduleButt2", arg, i);
  XtManageChild(w->M.moduleButt[2]);

  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->M.modulePane); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Module")); i++;
  w->M.moduleCascade = XmCreateCascadeButton(w->M.menuBar, "MmoduleCascade", arg, i);
  XtManageChild(w->M.moduleCascade);

  /* option menu */
  i=0;
  w->M.optionPane = XmCreatePulldownMenu(w->M.menuBar, "MoptionPane", arg, i);
                                        
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Geometry Options")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-g)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>g:"); i++;
  w->M.optionButt[0] = XmCreatePushButton(w->M.optionPane, "MoptionButt0", arg, i);
  XtManageChild(w->M.optionButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Mesh Options")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-m)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>m:"); i++;
  w->M.optionButt[1] = XmCreatePushButton(w->M.optionPane, "MoptionButt1", arg, i);
  XtManageChild(w->M.optionButt[1]);


  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Post Processing Options")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-p)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>p:"); i++;
  w->M.optionButt[2] = XmCreatePushButton(w->M.optionPane, "MoptionButt2", arg, i);
  XtManageChild(w->M.optionButt[2]);

  i=0;
  w->M.optionSep[0] = XmCreateSeparator(w->M.optionPane, "MoptionSep0", arg, i);
  XtManageChild(w->M.optionSep[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("General Options")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-o)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>o:"); i++;
  w->M.optionButt[3] = XmCreatePushButton(w->M.optionPane, "MoptionButt3", arg, i);
  XtManageChild(w->M.optionButt[3]);

  i=0;
  w->M.optionSep[1] = XmCreateSeparator(w->M.optionPane, "MoptionSep1", arg, i);
  XtManageChild(w->M.optionSep[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Viewport")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-v)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>v:"); i++;
  w->M.optionButt[4] = XmCreatePushButton(w->M.optionPane, "MoptionButt4", arg, i);
  XtManageChild(w->M.optionButt[4]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Statistics")); i++;
  XtSetArg(arg[i], XmNacceleratorText, XmStringCreateSimple("(S-i)")); i++;
  XtSetArg(arg[i], XmNaccelerator, "Shift<Key>i:"); i++;
  w->M.optionButt[5] = XmCreatePushButton(w->M.optionPane, "MoptionButt5", arg, i);
  XtManageChild(w->M.optionButt[5]);

  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->M.optionPane); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Options")); i++;
  w->M.optionCascade = XmCreateCascadeButton(w->M.menuBar, "MoptionCascade", arg, i);
  XtManageChild(w->M.optionCascade);

  /* help menu */
  i=0;
  w->M.helpPane = XmCreatePulldownMenu(w->M.menuBar, "MhelpPane", arg, i);
                                        
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Short Help")); i++;
  w->M.helpButt[0] = XmCreatePushButton(w->M.helpPane, "MhelpButt0", arg, i);
  XtManageChild(w->M.helpButt[0]);

  i=0;
  w->M.helpSep[0] = XmCreateSeparator(w->M.helpPane, "MhelpSep0", arg, i);
  XtManageChild(w->M.helpSep[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("About...")); i++;
  w->M.helpButt[1] = XmCreatePushButton(w->M.helpPane, "MhelpButt1", arg, i);
  XtManageChild(w->M.helpButt[1]);

  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->M.helpPane); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("?")); i++;
  w->M.helpCascade = XmCreateCascadeButton(w->M.menuBar, "MhelpCascade", arg, i);
  XtManageChild(w->M.helpCascade);

  /* menu frame */
  
  i=0;
  w->M.menuFrame = XmCreateFrame(w->M.containerWin, "MmenuFrame", arg, i);
  XtManageChild(w->M.menuFrame);

  /* menu form */
  
  i=0;
  XtSetArg(arg[i], XmNresizable, False); i++;  
  XtSetArg(arg[i], XmNresizePolicy, XmRESIZE_NONE); i++;
  /* pour eviter des redimensionnements intempestifs sous HP */
  w->M.menuForm = XmCreateForm(w->M.menuFrame, "MmenuForm", arg, i);
  XtManageChild(w->M.menuForm);

  /* module butt */
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(" ")); i++;
  w->M.modButt = XmCreateLabel(w->M.menuForm, "MmodButt", arg, i);
  XtManageChild(w->M.modButt);

  i=0;
  w->M.modPop = XmCreatePopupMenu(w->M.modButt, "MmodPop", arg, i);
  XtUnmanageChild(w->M.modPop);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Geometry")); i++;
  w->M.geomButt = XmCreatePushButton(w->M.modPop, "MgeomButt", arg, i);
  XtManageChild(w->M.geomButt);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Mesh")); i++;
  w->M.meshButt = XmCreatePushButton(w->M.modPop, "MmeshButt", arg, i);
  XtManageChild(w->M.meshButt);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Post Processing")); i++;
  w->M.postButt = XmCreatePushButton(w->M.modPop, "MpostButt", arg, i);
  XtManageChild(w->M.postButt);

  /* navigation arrows */

  i=0;
  XtSetArg(arg[i], XmNarrowDirection, XmARROW_LEFT); i++;
  w->M.navigButt[0] = XmCreateArrowButton(w->M.menuForm, "MnavigButt0", arg, i);
  XtManageChild(w->M.navigButt[0]);

  i=0;
  XtSetArg(arg[i], XmNarrowDirection, XmARROW_RIGHT); i++;
  w->M.navigButt[1] = XmCreateArrowButton(w->M.menuForm, "MnavigButt1", arg, i);
  XtManageChild(w->M.navigButt[1]);

  /* default button */

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("No View Loaded")); i++;
  w->M.defaultButt = XmCreateLabel(w->M.menuForm, "MdefaultButt", arg, i);
  XtUnmanageChild(w->M.defaultButt);

  /* buttons */
  
  for(n=0 ; n<NB_BUTT_MAX ; n++){
    i=0;
    w->M.pushButt[n] = XmCreatePushButton(w->M.menuForm, "MpushButtn", arg, i);
    XtUnmanageChild(w->M.pushButt[n]);

    i=0;
    w->M.toggleButt[n] = XmCreateToggleButton(w->M.menuForm, "MtoggleButtn", arg, i);
    XtUnmanageChild(w->M.toggleButt[n]);

    i=0;
    w->M.popMenu[n] = XmCreatePopupMenu(w->M.toggleButt[n], "MpopMenun", arg, i);
    XtUnmanageChild(w->M.popMenu[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Reload")); i++;
    w->M.reloadButt[n] = XmCreatePushButton(w->M.popMenu[n], "MreloadButtn", arg, i);
    XtManageChild(w->M.reloadButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Remove")); i++;
    w->M.removeButt[n] = XmCreatePushButton(w->M.popMenu[n], "MremoveButtn", arg, i);
    XtManageChild(w->M.removeButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Duplicate")); i++;
    w->M.duplicateButt[n] = XmCreatePushButton(w->M.popMenu[n], "MduplicateButtn", arg, i);
    XtManageChild(w->M.duplicateButt[n]);

    i=0;
    w->M.popSep[0][n] = XmCreateSeparator(w->M.popMenu[n], "MpopSep0n", arg, i);
    XtManageChild(w->M.popSep[0][n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Lighting")); i++;
    w->M.lightButt[n] = XmCreateToggleButton(w->M.popMenu[n], "MlightButtn", arg, i);
    XtManageChild(w->M.lightButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Show Elements")); i++;
    w->M.elementButt[n] = XmCreateToggleButton(w->M.popMenu[n], "MelementButtn", arg, i);
    XtManageChild(w->M.elementButt[n]);

    i=0;
    w->M.popSep[1][n] = XmCreateSeparator(w->M.popMenu[n], "MpopSep1n", arg, i);
    XtManageChild(w->M.popSep[1][n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Scale, Range and Intervals")); i++;
    w->M.scaleButt[n] = XmCreatePushButton(w->M.popMenu[n], "MscaleButtn", arg, i);
    XtManageChild(w->M.scaleButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Colors")); i++;
    w->M.colorButt[n] = XmCreatePushButton(w->M.popMenu[n], "McolorButtn", arg, i);
    XtManageChild(w->M.colorButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Offset")); i++;
    w->M.offsetButt[n] = XmCreatePushButton(w->M.popMenu[n], "MoffsetButtn", arg, i);
    XtManageChild(w->M.offsetButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Vector Display")); i++;
    w->M.vectorButt[n] = XmCreatePushButton(w->M.popMenu[n], "MvectorButtn", arg, i);
    XtManageChild(w->M.vectorButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Time Step")); i++;
    w->M.timeStepButt[n] = XmCreatePushButton(w->M.popMenu[n], "MtimeStepButtn", arg, i);
    XtManageChild(w->M.timeStepButt[n]);

    i=0;
    w->M.popSep[2][n] = XmCreateSeparator(w->M.popMenu[n], "MpopSep2n", arg, i);
    XtManageChild(w->M.popSep[2][n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Export as Background Mesh")); i++;
    w->M.exportBGMButt[n] = XmCreatePushButton(w->M.popMenu[n], "MexportBGMButtn", arg, i);
    XtManageChild(w->M.exportBGMButt[n]);

    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Apply as Current Background Mesh")); i++;
    w->M.applyBGMButt[n] = XmCreatePushButton(w->M.popMenu[n], "MapplyBGMButtn", arg, i);
    XtManageChild(w->M.applyBGMButt[n]);
  }

}


/* ------------------------------------------------------------------------ 
    GRAPHIC WINDOW
   ------------------------------------------------------------------------ */

void CreateWidgets_G(Widgets_T *w){  
  int   i;
  Arg   arg[10];

  /* graphic shell */
  w->G.shell = 
    XtVaAppCreateShell("Gmsh graphics", "gmshGW", applicationShellWidgetClass, XCTX.display, 
                       XmNvisual,XCTX.gui.visual,
                       XmNcolormap,XCTX.gui.colormap,
                       NULL);
  
  /* container form */
  i=0;
  // We want glw to be able to force the size of the container win
  //XtSetArg(arg[i], XmNresizable, False); i++;  
  //XtSetArg(arg[i], XmNresizePolicy, XmRESIZE_NONE); i++;
  XtSetArg(arg[i], XmNwidth, 700); i++;  
  XtSetArg(arg[i], XmNheight, 525); i++;
  w->G.containerForm = XmCreateForm(w->G.shell, "GcontainerForm", arg, i);
  XtManageChild(w->G.containerForm);

  /* opengl drawing area */
  i=0;
  XtSetArg(arg[i], XmNcolormap, XCTX.glw.colormap); i++;
  XtSetArg(arg[i], GLwNvisualInfo, XCTX.glw.visinfo); i++;
  XtSetArg(arg[i], GLwNinstallColormap, True); i++;

  w->G.glw = GLwCreateMDrawingArea(w->G.containerForm, "glw", arg, i);
  XtManageChild(w->G.glw);

  /* overlay opengl drawing area */
  if(CTX.overlay){
    i=0;
    XtSetArg(arg[i], XmNcolormap, XCTX.glo.colormap); i++;
    XtSetArg(arg[i], GLwNvisualInfo, XCTX.glo.visinfo); i++;
    XtSetArg(arg[i], GLwNinstallColormap, True); i++;    
    w->G.glo = GLwCreateMDrawingArea(w->G.containerForm, "glo", arg, i);
    XtManageChild(w->G.glo);
  }    

  /* bottom */

  i=0;
  XtSetArg(arg[i], XmNresizable, False); i++;  
  XtSetArg(arg[i], XmNresizePolicy, XmRESIZE_NONE); i++;
  w->G.bottomForm = XmCreateForm(w->G.containerForm, "GbottomForm", arg, i);
  XtManageChild(w->G.bottomForm);

  /* buttons de gauche: X Y Z 1 Geometry Abort Play Stop */

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("X")); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[0] = XmCreatePushButton(w->G.bottomForm, "GButt0", arg, i);
  XtManageChild(w->G.Butt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Y")); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[1] = XmCreatePushButton(w->G.bottomForm, "GButt1", arg, i);
  XtManageChild(w->G.Butt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Z")); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[2] = XmCreatePushButton(w->G.bottomForm, "GButt2", arg, i);
  XtManageChild(w->G.Butt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("1:1")); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[3] = XmCreatePushButton(w->G.bottomForm, "GButt3", arg, i);
  XtManageChild(w->G.Butt[3]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("?")); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[4] = XmCreatePushButton(w->G.bottomForm, "GButt4", arg, i);
  XtManageChild(w->G.Butt[4]);

  i=0;
  XtSetArg(arg[i], XmNlabelType, XmPIXMAP); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[5] = XmCreatePushButton(w->G.bottomForm, "GButt5", arg, i);
  XtManageChild(w->G.Butt[5]);

  i=0;
  XtSetArg(arg[i], XmNlabelType, XmPIXMAP); i++;
  XtSetArg(arg[i], XmNtraversalOn, False); i++;
  w->G.Butt[6] = XmCreatePushButton(w->G.bottomForm, "GButt6", arg, i);
  XtManageChild(w->G.Butt[6]);
  XtSetSensitive(w->G.Butt[6],0);

  /* 3 textes au milieu */

  i=0;
  //XtSetArg(arg[i], XmNresizable, False); i++;  
  //XtSetArg(arg[i], XmNresizePolicy, XmRESIZE_NONE); i++;
  w->G.textForm = XmCreateForm(w->G.bottomForm, "GtextForm", arg, i);
  XtManageChild(w->G.textForm);

  i=0;
  XtSetArg(arg[i], XmNalignment, XmALIGNMENT_BEGINNING); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(" ")); i++;
  w->G.selectLabel = XmCreateLabel(w->G.textForm, "GselectLabel", arg, i);
  XtManageChild(w->G.selectLabel);

  i=0;
  XtSetArg(arg[i], XmNalignment, XmALIGNMENT_BEGINNING); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(" ")); i++;
  w->G.infoLabel = XmCreateLabel(w->G.textForm, "GinfoLabel", arg, i);
  XtManageChild(w->G.infoLabel);

  i=0;
  XtSetArg(arg[i], XmNalignment, XmALIGNMENT_BEGINNING); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(" ")); i++;
  w->G.statusLabel = XmCreateLabel(w->G.textForm, "GstatusLabel", arg, i);
  XtManageChild(w->G.statusLabel);

}


/* ------------------------------------------------------------------------ 
    COMMAND WINDOW
   ------------------------------------------------------------------------ */

void CreateWidgets_C(Widgets_T *w){
  int   i;
  Arg   arg[10];

  w->C.shell =
    XtVaAppCreateShell("Gmsh commands", "gmshCW", applicationShellWidgetClass, XCTX.display,
                       XmNvisual,XCTX.gui.visual,
                       XmNcolormap,XCTX.gui.colormap,
                       NULL);

  i=0;
  XtSetArg(arg[i], XmNpromptString, XmStringCreateSimple("")); i++;
  w->C.command = XmCreateCommand(w->C.shell, "Ccommand", arg, i);
  XtManageChild(w->C.command);

  w->C.commandList = XmCommandGetChild(w->C.command, XmDIALOG_HISTORY_LIST);
  w->C.commandText = XmCommandGetChild(w->C.command, XmDIALOG_COMMAND_TEXT);
}


/* ------------------------------------------------------------------------ 
    ERROR DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_ED(Widgets_T *w){
  int     i;
  Arg     arg[10];
  Widget  tmp ;

  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Warning")); i++;
  XtSetArg(arg[i], XmNmessageString, XmStringCreateSimple("File exists")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->ED.saveAsDialog = XmCreateWarningDialog(w->M.shell, "EDsaveAsDialog", arg, i);

  tmp = XmMessageBoxGetChild(w->ED.saveAsDialog, XmDIALOG_HELP_BUTTON); 
  XtUnmanageChild(tmp);

}


/* ------------------------------------------------------------------------ 
    FILE DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_FD(Widgets_T *w){
  int     i;
  Arg     arg[10];
  Widget  tmp ;

  /* open */
  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Open")); i++;
  XtSetArg(arg[i], XmNnoMatchString, XmStringCreateSimple("[ NONE ]")); i++;
  XtSetArg(arg[i], XmNdirMask, XmStringCreateSimple("*.geo")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->FD.openDialog = XmCreateFileSelectionDialog(w->M.shell, "FDopenDialog", arg, i);
  XtUnmanageChild(w->FD.openDialog);
  
  /* merge */
  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Merge")); i++;
  XtSetArg(arg[i], XmNnoMatchString, XmStringCreateSimple("[ NONE ]")); i++;
  XtSetArg(arg[i], XmNdirMask, XmStringCreateSimple("*.[pm][os][sh]")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->FD.mergeDialog = XmCreateFileSelectionDialog(w->M.shell, "FDmergeDialog", arg, i);
  XtUnmanageChild(w->FD.mergeDialog);

  /* save as */

  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Save")); i++;
  XtSetArg(arg[i], XmNnoMatchString, XmStringCreateSimple("[ NONE ]")); i++;
  XtSetArg(arg[i], XmNdirMask, XmStringCreateSimple("*")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++; /* + pratique qd on sauve des animations */
  w->FD.saveAsDialog = XmCreateFileSelectionDialog(w->M.shell, "FDsaveAsDialog", arg, i);
  XtUnmanageChild(w->FD.saveAsDialog);

  i=0;
  w->FD.saveAsFrame[0] = XmCreateFrame(w->FD.saveAsDialog, "FDsaveAsFrame0", arg, i);
  XtManageChild(w->FD.saveAsFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Format")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->FD.saveAsFrame[1] = XmCreateLabel(w->FD.saveAsFrame[0], "FDsaveAsFrame1", arg, i);
  XtManageChild(w->FD.saveAsFrame[1]);

  i=0 ;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  XtSetArg(arg[i], XmNspacing, 0); i++;
  w->FD.saveAsRowCol = XmCreateRowColumn(w->FD.saveAsFrame[0], "FDsaveAsRowCol", arg, i);
  XtManageChild(w->FD.saveAsRowCol);

  /* save as - type */ 
  i=0;
  w->FD.saveAsPane[0] = XmCreatePulldownMenu(w->FD.saveAsRowCol, "FDsaveAsPane0", arg, i);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("By Extension")); i++;
  w->FD.saveAsButt[0] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt0", arg, i);
  XtManageChild(w->FD.saveAsButt[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("GEO")); i++;
  w->FD.saveAsButt[1] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt1", arg, i);
  XtManageChild(w->FD.saveAsButt[1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("MSH")); i++;
  w->FD.saveAsButt[2] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt2", arg, i);
  XtManageChild(w->FD.saveAsButt[2]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("UNV")); i++;
  w->FD.saveAsButt[3] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt3", arg, i);
  XtManageChild(w->FD.saveAsButt[3]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("GREF")); i++;
  w->FD.saveAsButt[4] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt4", arg, i);
  XtManageChild(w->FD.saveAsButt[4]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("EPS Simple Sort")); i++;
  w->FD.saveAsButt[5] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt5", arg, i);
  XtManageChild(w->FD.saveAsButt[5]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("EPS Accurate Sort")); i++;
  w->FD.saveAsButt[6] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt6", arg, i);
  XtManageChild(w->FD.saveAsButt[6]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("XPM")); i++;
  w->FD.saveAsButt[7] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt7", arg, i);
  XtManageChild(w->FD.saveAsButt[7]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("JPEG")); i++;
  w->FD.saveAsButt[8] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt8", arg, i);
  XtManageChild(w->FD.saveAsButt[8]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("GIF")); i++;
  w->FD.saveAsButt[9] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt9", arg, i);
  XtManageChild(w->FD.saveAsButt[9]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("GIF Dithered")); i++;
  w->FD.saveAsButt[10] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt10", arg, i);
  XtManageChild(w->FD.saveAsButt[10]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("GIF Transparent")); i++;
  w->FD.saveAsButt[11] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt11", arg, i);
  XtManageChild(w->FD.saveAsButt[11]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("PPM")); i++;
  w->FD.saveAsButt[12] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt12", arg, i);
  XtManageChild(w->FD.saveAsButt[12]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("UCB YUV")); i++;
  w->FD.saveAsButt[13] = XmCreatePushButton(w->FD.saveAsPane[0], "MsaveAsButt13", arg, i);
  XtManageChild(w->FD.saveAsButt[13]);

  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->FD.saveAsPane[0]); i++;
  XtSetArg(arg[i], XmNspacing, 0); i++;
  w->FD.saveAsMenu[0] = XmCreateOptionMenu(w->FD.saveAsRowCol, "FDsaveAsMenu0", arg, i);
  XtManageChild(w->FD.saveAsMenu[0]);

  /* save options as */
  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Save Options")); i++;
  XtSetArg(arg[i], XmNnoMatchString, XmStringCreateSimple("[ NONE ]")); i++;
  XtSetArg(arg[i], XmNdirMask, XmStringCreateSimple("*.[gp][eo][os]")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->FD.saveOptionsAsDialog = XmCreateFileSelectionDialog(w->M.shell, "FDsaveOptionsAsDialog", arg, i);
  XtUnmanageChild(w->FD.saveOptionsAsDialog);

  tmp = XmFileSelectionBoxGetChild(w->FD.openDialog, XmDIALOG_HELP_BUTTON); 
  XtUnmanageChild(tmp);
  tmp = XmFileSelectionBoxGetChild(w->FD.mergeDialog, XmDIALOG_HELP_BUTTON);
  XtUnmanageChild(tmp);
  tmp = XmFileSelectionBoxGetChild(w->FD.saveAsDialog, XmDIALOG_HELP_BUTTON);
  XtUnmanageChild(tmp);
  tmp = XmFileSelectionBoxGetChild(w->FD.saveOptionsAsDialog, XmDIALOG_HELP_BUTTON);
  XtUnmanageChild(tmp);

}


/* ------------------------------------------------------------------------ 
    OPTIONS DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_OD(Widgets_T *w){
  int   i, n;
  Arg   arg[10];
  char  label[32];

  /* Geometry */
  
  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Geometry Options")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.geomDialog = XmCreateTemplateDialog(w->M.shell, "ODgeomDialog", arg, i);
  XtUnmanageChild(w->OD.geomDialog);

  i=0;
  w->OD.geomRowCol = XmCreateRowColumn(w->OD.geomDialog, "ODgeomRowCol", arg, i);
  XtManageChild(w->OD.geomRowCol);

  /* Geometry - Visible */

  i=0;
  w->OD.geomVisibleFrame[0] = XmCreateFrame(w->OD.geomRowCol, "ODgeomVisibleFrame0", arg, i);
  XtManageChild(w->OD.geomVisibleFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Global Visibility")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.geomVisibleFrame[1] = XmCreateLabel(w->OD.geomVisibleFrame[0], "ODgeomVisibleFrame1", arg, i);
  XtManageChild(w->OD.geomVisibleFrame[1]);
  
  i=0;
  w->OD.geomVisibleRowCol = XmCreateRowColumn(w->OD.geomVisibleFrame[0], "ODgeomVisibleRowCol", arg, i);
  XtManageChild(w->OD.geomVisibleRowCol);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.geomVisibleCheck = XmCreateSimpleCheckBox(w->OD.geomVisibleRowCol, "ODgeomVisibleCheck", arg, i);
  XtManageChild(w->OD.geomVisibleCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Points")); i++;
  XtSetArg(arg[i], XmNset, CTX.geom.points?True:False); i++;
  w->OD.geomVisibleButt[0] = XmCreateToggleButton(w->OD.geomVisibleCheck, "ODgeomVisibleButt0", arg, i);
  XtManageChild(w->OD.geomVisibleButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Lines")); i++;
  XtSetArg(arg[i], XmNset, CTX.geom.lines?True:False); i++;
  w->OD.geomVisibleButt[1] = XmCreateToggleButton(w->OD.geomVisibleCheck, "ODgeomVisibleButt1", arg, i);
  XtManageChild(w->OD.geomVisibleButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Surfaces")); i++;
  XtSetArg(arg[i], XmNset, CTX.geom.surfaces?True:False); i++;
  w->OD.geomVisibleButt[2] = XmCreateToggleButton(w->OD.geomVisibleCheck, "ODgeomVisibleButt2", arg, i);
  XtManageChild(w->OD.geomVisibleButt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Volumes")); i++;
  XtSetArg(arg[i], XmNset, CTX.geom.volumes?True:False); i++;
  w->OD.geomVisibleButt[3] = XmCreateToggleButton(w->OD.geomVisibleCheck, "ODgeomVisibleButt3", arg, i);
  XtManageChild(w->OD.geomVisibleButt[3]);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.geomVisibleTypeCheck = XmCreateRadioBox(w->OD.geomVisibleRowCol, "ODgeomVisibleTypeCheck", arg, i);
  XtManageChild(w->OD.geomVisibleTypeCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Entities")); i++;
  XtSetArg(arg[i], XmNset, True); i++;
  w->OD.geomVisibleTypeButt[0] = XmCreateToggleButton(w->OD.geomVisibleTypeCheck, "ODgeomVisibleTypeButt0", arg, i);
  XtManageChild(w->OD.geomVisibleTypeButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Labels")); i++;
  XtSetArg(arg[i], XmNset, False); i++;
  w->OD.geomVisibleTypeButt[1] = XmCreateToggleButton(w->OD.geomVisibleTypeCheck, "ODgeomVisibleTypeButt1", arg, i);
  XtManageChild(w->OD.geomVisibleTypeButt[1]);


  /* Geometry - Visible by Number */

  i=0;
  w->OD.geomVisibleByNumFrame[0] = XmCreateFrame(w->OD.geomRowCol, "ODgeomVisibleByNumFrame0", arg, i);
  XtManageChild(w->OD.geomVisibleByNumFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Visibility by Entity Number")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.geomVisibleByNumFrame[1] = XmCreateLabel(w->OD.geomVisibleByNumFrame[0], "ODgeomVisibleByNumFrame1", arg, i);
  XtManageChild(w->OD.geomVisibleByNumFrame[1]);
  
  i=0;
  w->OD.geomVisibleByNumRowCol = XmCreateRowColumn(w->OD.geomVisibleByNumFrame[0], "ODgeomVisibleByNumRowCol", arg, i);
  XtManageChild(w->OD.geomVisibleByNumRowCol);

  i=0;
  XtSetArg(arg[i], XmNvalue, "*"); i++;
  w->OD.geomVisibleByNumText = XmCreateTextField(w->OD.geomVisibleByNumRowCol, "ODgeomVisibleByNumText", arg, i);
  XtManageChild(w->OD.geomVisibleByNumText);

  /* Geometry - normals */
   
  i=0;
  w->OD.geomNormalsFrame[0] = XmCreateFrame(w->OD.geomRowCol, "ODgeomNormalsFrame0", arg, i);
  XtManageChild(w->OD.geomNormalsFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Normals")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.geomNormalsFrame[1] = XmCreateLabel(w->OD.geomNormalsFrame[0], "ODgeomNormalsFrame1", arg, i);
  XtManageChild(w->OD.geomNormalsFrame[1]);

  i=0;
  w->OD.geomNormalsRowCol = XmCreateRowColumn(w->OD.geomNormalsFrame[0], "ODgeomNormalsRowCol", arg, i);
  XtManageChild(w->OD.geomNormalsRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
  XtSetArg(arg[i], XmNvalue, CTX.geom.normals); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.geomNormalsScale = XmCreateScale(w->OD.geomNormalsRowCol, "ODgeomNormalsScale", arg, i);
  XtManageChild(w->OD.geomNormalsScale);
  
  i=0;
  sprintf(label, "%g", CTX.geom.normals);
  XtSetArg(arg[i], XmNvalue, label); i++;
  w->OD.geomNormalsText = XmCreateTextField(w->OD.geomNormalsRowCol, "ODgeomNormalsText", arg, i);
  XtManageChild(w->OD.geomNormalsText);

  /* Geometry - tangents */
   
  i=0;
  w->OD.geomTangentsFrame[0] = XmCreateFrame(w->OD.geomRowCol, "ODgeomTangentsFrame0", arg, i);
  XtManageChild(w->OD.geomTangentsFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Tangents")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.geomTangentsFrame[1] = XmCreateLabel(w->OD.geomTangentsFrame[0], "ODgeomTangentsFrame1", arg, i);
  XtManageChild(w->OD.geomTangentsFrame[1]);

  i=0;
  w->OD.geomTangentsRowCol = XmCreateRowColumn(w->OD.geomTangentsFrame[0], "ODgeomTangentsRowCol", arg, i);
  XtManageChild(w->OD.geomTangentsRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
  XtSetArg(arg[i], XmNvalue, CTX.geom.tangents); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.geomTangentsScale = XmCreateScale(w->OD.geomTangentsRowCol, "ODgeomTangentsScale", arg, i);
  XtManageChild(w->OD.geomTangentsScale);
  
  i=0;
  sprintf(label, "%g", CTX.geom.tangents);
  XtSetArg(arg[i], XmNvalue, label); i++;
  w->OD.geomTangentsText = XmCreateTextField(w->OD.geomTangentsRowCol, "ODgeomTangentsText", arg, i);
  XtManageChild(w->OD.geomTangentsText);

  /* Mesh */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Mesh Options")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.meshDialog = XmCreateTemplateDialog(w->M.shell, "ODmeshDialog", arg, i);
  XtUnmanageChild(w->OD.meshDialog);

  i=0;
  w->OD.meshRowCol = XmCreateRowColumn(w->OD.meshDialog, "ODmeshRowCol", arg, i);
  XtManageChild(w->OD.meshRowCol);


  /* Mesh - algo */
  
  i=0;
  w->OD.meshAlgoFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshAlgoFrame0", arg, i);
  XtManageChild(w->OD.meshAlgoFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Algorithm")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshAlgoFrame[1] = XmCreateLabel(w->OD.meshAlgoFrame[0], "ODmeshAlgoFrame1", arg, i);
  XtManageChild(w->OD.meshAlgoFrame[1]);
  
  i=0;
  w->OD.meshAlgoRowCol = XmCreateRowColumn(w->OD.meshAlgoFrame[0], "ODmeshAlgoRowCol", arg, i);
  XtManageChild(w->OD.meshAlgoRowCol);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.meshAlgoCheck = XmCreateSimpleCheckBox(w->OD.meshAlgoRowCol, "ODmeshAlgoCheck", arg, i);
  XtManageChild(w->OD.meshAlgoCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Degree 2")); i++;
  XtSetArg(arg[i], XmNset, (CTX.mesh.degree==2)?True:False); i++;
  w->OD.meshAlgoButt[0] = XmCreateToggleButton(w->OD.meshAlgoCheck, "ODmeshAlgoButt0", arg, i);
  XtManageChild(w->OD.meshAlgoButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Anisotropic")); i++;
  XtSetArg(arg[i], XmNset, (CTX.mesh.algo==DELAUNAY_NEWALGO)?True:False); i++;
  w->OD.meshAlgoButt[1] = XmCreateToggleButton(w->OD.meshAlgoCheck, "ODmeshAlgoButt1", arg, i);
  XtManageChild(w->OD.meshAlgoButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Interactive")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.interactive?True:False); i++;
  w->OD.meshAlgoButt[2] = XmCreateToggleButton(w->OD.meshAlgoCheck, "ODmeshAlgoButt2", arg, i);
  XtManageChild(w->OD.meshAlgoButt[2]);

  /* Mesh - smoothing */

  i=0;
  w->OD.meshSmoothingFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshSmoothingFrame0", arg, i);
  XtManageChild(w->OD.meshSmoothingFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Smoothing")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshSmoothingFrame[1] = XmCreateLabel(w->OD.meshSmoothingFrame[0], "ODmeshSmoothingFrame1", arg, i);
  XtManageChild(w->OD.meshSmoothingFrame[1]);

  i=0;
  w->OD.meshSmoothingRowCol = XmCreateRowColumn(w->OD.meshSmoothingFrame[0], "ODmeshSmoothingRowCol", arg, i);
  XtManageChild(w->OD.meshSmoothingRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 2); i++;
  XtSetArg(arg[i], XmNvalue, CTX.mesh.nb_smoothing); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.meshSmoothingScale = XmCreateScale(w->OD.meshSmoothingRowCol, "ODmeshSmoothingScale", arg, i);
  XtManageChild(w->OD.meshSmoothingScale);
  
  i=0;
  sprintf(label, "%d", CTX.mesh.nb_smoothing);
  XtSetArg(arg[i], XmNvalue, label); i++;
  w->OD.meshSmoothingText = XmCreateTextField(w->OD.meshSmoothingRowCol, "ODmeshSmoothingText", arg, i);
  XtManageChild(w->OD.meshSmoothingText);

  /* Mesh - Visible */

  i=0;
  w->OD.meshVisibleFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshVisibleFrame0", arg, i);
  XtManageChild(w->OD.meshVisibleFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Global Visibility")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshVisibleFrame[1] = XmCreateLabel(w->OD.meshVisibleFrame[0], "ODmeshVisibleFrame1", arg, i);
  XtManageChild(w->OD.meshVisibleFrame[1]);
  
  i=0;
  w->OD.meshVisibleRowCol = XmCreateRowColumn(w->OD.meshVisibleFrame[0], "ODmeshVisibleRowCol", arg, i);
  XtManageChild(w->OD.meshVisibleRowCol);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.meshVisibleCheck = XmCreateSimpleCheckBox(w->OD.meshVisibleRowCol, "ODmeshVisibleCheck", arg, i);
  XtManageChild(w->OD.meshVisibleCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Points")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.points?True:False); i++;
  w->OD.meshVisibleButt[0] = XmCreateToggleButton(w->OD.meshVisibleCheck, "ODmeshVisibleButt0", arg, i);
  XtManageChild(w->OD.meshVisibleButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Lines")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.lines?True:False); i++;
  w->OD.meshVisibleButt[1] = XmCreateToggleButton(w->OD.meshVisibleCheck, "ODmeshVisibleButt1", arg, i);
  XtManageChild(w->OD.meshVisibleButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Surfaces")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.surfaces?True:False); i++;
  w->OD.meshVisibleButt[2] = XmCreateToggleButton(w->OD.meshVisibleCheck, "ODmeshVisibleButt2", arg, i);
  XtManageChild(w->OD.meshVisibleButt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Volumes")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.volumes?True:False); i++;
  w->OD.meshVisibleButt[3] = XmCreateToggleButton(w->OD.meshVisibleCheck, "ODmeshVisibleButt3", arg, i);
  XtManageChild(w->OD.meshVisibleButt[3]);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.meshVisibleTypeCheck = XmCreateRadioBox(w->OD.meshVisibleRowCol, "ODmeshVisibleTypeCheck", arg, i);
  XtManageChild(w->OD.meshVisibleTypeCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Entities")); i++;
  XtSetArg(arg[i], XmNset, True); i++;
  w->OD.meshVisibleTypeButt[0] = XmCreateToggleButton(w->OD.meshVisibleTypeCheck, "ODmeshVisibleTypeButt0", arg, i);
  XtManageChild(w->OD.meshVisibleTypeButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Labels")); i++;
  XtSetArg(arg[i], XmNset, False); i++;
  w->OD.meshVisibleTypeButt[1] = XmCreateToggleButton(w->OD.meshVisibleTypeCheck, "ODmeshVisibleTypeButt1", arg, i);
  XtManageChild(w->OD.meshVisibleTypeButt[1]);


  /* Mesh - Visible by Number */

  i=0;
  w->OD.meshVisibleByNumFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshVisibleByNumFrame0", arg, i);
  XtManageChild(w->OD.meshVisibleByNumFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Visibility")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshVisibleByNumFrame[1] = XmCreateLabel(w->OD.meshVisibleByNumFrame[0], "ODmeshVisibleByNumFrame1", arg, i);
  XtManageChild(w->OD.meshVisibleByNumFrame[1]);
  
  i=0;
  w->OD.meshVisibleByNumRowCol = XmCreateRowColumn(w->OD.meshVisibleByNumFrame[0], "ODmeshVisibleByNumRowCol", arg, i);
  XtManageChild(w->OD.meshVisibleByNumRowCol);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.meshVisibleByNumCheck = XmCreateRadioBox(w->OD.meshVisibleByNumRowCol, "ODmeshVisibleByNumCheck", arg, i);
  XtManageChild(w->OD.meshVisibleByNumCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("By Entity")); i++;
  XtSetArg(arg[i], XmNset, True); i++;
  w->OD.meshVisibleByNumButt[0] = XmCreateToggleButton(w->OD.meshVisibleByNumCheck, "ODmeshVisibleByNumButt0", arg, i);
  XtManageChild(w->OD.meshVisibleByNumButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("By Quality")); i++;
  XtSetArg(arg[i], XmNset, False); i++;
  w->OD.meshVisibleByNumButt[1] = XmCreateToggleButton(w->OD.meshVisibleByNumCheck, "ODmeshVisibleByNumButt1", arg, i);
  XtManageChild(w->OD.meshVisibleByNumButt[1]);

  i=0;
  XtSetArg(arg[i], XmNvalue, "*"); i++;
  w->OD.meshVisibleByNumText = XmCreateTextField(w->OD.meshVisibleByNumRowCol, "ODmeshVisibleByNumText", arg, i);
  XtManageChild(w->OD.meshVisibleByNumText);

  /* Mesh - aspect */

  i=0;
  w->OD.meshAspectFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshAspectFrame0", arg, i);
  XtManageChild(w->OD.meshAspectFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Aspect")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshAspectFrame[1] = XmCreateLabel(w->OD.meshAspectFrame[0], "ODmeshAspectFrame1", arg, i);
  XtManageChild(w->OD.meshAspectFrame[1]);
  
  i=0;
  w->OD.meshAspectCheck = XmCreateRadioBox(w->OD.meshAspectFrame[0], "ODmeshAspectCheck", arg, i);
  XtManageChild(w->OD.meshAspectCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Wireframe")); i++;
  XtSetArg(arg[i], XmNset, (!CTX.mesh.hidden)?True:False); i++;
  w->OD.meshAspectButt[0] = XmCreateToggleButton(w->OD.meshAspectCheck, "ODmeshAspectButt0", arg, i);
  XtManageChild(w->OD.meshAspectButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Hidden Lines")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.hidden?True:False); i++;
  w->OD.meshAspectButt[1] = XmCreateToggleButton(w->OD.meshAspectCheck, "ODmeshAspectButt1", arg, i);
  XtManageChild(w->OD.meshAspectButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Solid")); i++;
  XtSetArg(arg[i], XmNset, CTX.mesh.shade?True:False); i++;
  w->OD.meshAspectButt[2] = XmCreateToggleButton(w->OD.meshAspectCheck, "ODmeshAspectButt2", arg, i);
  XtManageChild(w->OD.meshAspectButt[2]);
  
  /* Mesh - explode */

  i=0;
  w->OD.meshExplodeFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshExplodeFrame0", arg, i);
  XtManageChild(w->OD.meshExplodeFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Explode")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshExplodeFrame[1] = XmCreateLabel(w->OD.meshExplodeFrame[0], "ODmeshExplodeFrame1", arg, i);
  XtManageChild(w->OD.meshExplodeFrame[1]);

  i=0;
  w->OD.meshExplodeRowCol = XmCreateRowColumn(w->OD.meshExplodeFrame[0], "ODmeshExplodeRowCol", arg, i);
  XtManageChild(w->OD.meshExplodeRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 2); i++;
  XtSetArg(arg[i], XmNvalue, (int)100*CTX.mesh.explode); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.meshExplodeScale = XmCreateScale(w->OD.meshExplodeRowCol, "ODmeshExplodeScale", arg, i);
  XtManageChild(w->OD.meshExplodeScale);
  
  i=0;
  sprintf(label, "%g", CTX.mesh.explode);
  XtSetArg(arg[i], XmNvalue, label); i++;
  w->OD.meshExplodeText = XmCreateTextField(w->OD.meshExplodeRowCol, "ODmeshExplodeText", arg, i);
  XtManageChild(w->OD.meshExplodeText);

  /* Mesh - normals */
   
  i=0;
  w->OD.meshNormalsFrame[0] = XmCreateFrame(w->OD.meshRowCol, "ODmeshNormalsFrame0", arg, i);
  XtManageChild(w->OD.meshNormalsFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Normals")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.meshNormalsFrame[1] = XmCreateLabel(w->OD.meshNormalsFrame[0], "ODmeshNormalsFrame1", arg, i);
  XtManageChild(w->OD.meshNormalsFrame[1]);

  i=0;
  w->OD.meshNormalsRowCol = XmCreateRowColumn(w->OD.meshNormalsFrame[0], "ODmeshNormalsRowCol", arg, i);
  XtManageChild(w->OD.meshNormalsRowCol);

  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
  XtSetArg(arg[i], XmNvalue, CTX.mesh.normals); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.meshNormalsScale = XmCreateScale(w->OD.meshNormalsRowCol, "ODmeshNormalsScale", arg, i);
  XtManageChild(w->OD.meshNormalsScale);
  
  i=0;
  sprintf(label, "%g", CTX.mesh.normals);
  XtSetArg(arg[i], XmNvalue, label); i++;
  w->OD.meshNormalsText = XmCreateTextField(w->OD.meshNormalsRowCol, "ODmeshNormalsText", arg, i);
  XtManageChild(w->OD.meshNormalsText);


  /* Post */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Post Options")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.postDialog = XmCreateTemplateDialog(w->M.shell, "ODpostDialog", arg, i);
  XtUnmanageChild(w->OD.postDialog);

  i=0;
  w->OD.postRowCol = XmCreateRowColumn(w->OD.postDialog, "ODpostRowCol", arg, i);
  XtManageChild(w->OD.postRowCol);

  /* Post - link */

  i=0;
  w->OD.postLinkFrame[0] = XmCreateFrame(w->OD.postRowCol, "ODpostLinkFrame0", arg, i);
  XtManageChild(w->OD.postLinkFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Links")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.postLinkFrame[1] = XmCreateLabel(w->OD.postLinkFrame[0], "ODpostLinkFrame1", arg, i);
  XtManageChild(w->OD.postLinkFrame[1]);
  
  i=0;
  w->OD.postLinkRowCol = XmCreateRowColumn(w->OD.postLinkFrame[0], "ODpostLinkRowCol", arg, i);
  XtManageChild(w->OD.postLinkRowCol);

  i=0;
  w->OD.postLinkCheck = XmCreateRadioBox(w->OD.postLinkRowCol, "ODpostLinkCheck", arg, i);
  XtManageChild(w->OD.postLinkCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("No Links")); i++;
  XtSetArg(arg[i], XmNset, CTX.post.link?False:True); i++;
  w->OD.postLinkButt[0] = XmCreateToggleButton(w->OD.postLinkCheck, "ODpostLinkButt0", arg, i);
  XtManageChild(w->OD.postLinkButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Link Visible Views")); i++;
  XtSetArg(arg[i], XmNset, (CTX.post.link==1)?True:False); i++;
  w->OD.postLinkButt[1] = XmCreateToggleButton(w->OD.postLinkCheck, "ODpostLinkButt1", arg, i);
  XtManageChild(w->OD.postLinkButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Link All Views")); i++;
  XtSetArg(arg[i], XmNset, (CTX.post.link==2)?True:False); i++;
  w->OD.postLinkButt[2] = XmCreateToggleButton(w->OD.postLinkCheck, "ODpostLinkButt2", arg, i);
  XtManageChild(w->OD.postLinkButt[2]);

  /* post - anim */
  i=0;
  w->OD.postAnimFrame[0] = XmCreateFrame(w->OD.postRowCol, "ODpostAnimFrame0", arg, i);
  XtManageChild(w->OD.postAnimFrame[0]);
  
  i=0;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Animation Delay")); i++;
  w->OD.postAnimFrame[1] = XmCreateLabel(w->OD.postAnimFrame[0], "ODpostAnimFrame1", arg, i);
  XtManageChild(w->OD.postAnimFrame[1]);
  
  i=0;
  w->OD.postAnimFrameRowCol = XmCreateRowColumn(w->OD.postAnimFrame[0], "ODpostAnimFrameRowCol", arg, i);
  XtManageChild(w->OD.postAnimFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 1); i++;
  XtSetArg(arg[i], XmNshowValue, True); i++;
  XtSetArg(arg[i], XmNvalue, CTX.post.anim_delay/1.e5); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.postAnimScale = XmCreateScale(w->OD.postAnimFrameRowCol, "ODpostAnimScale", arg, i);
  XtManageChild(w->OD.postAnimScale);


  /* Miscellaneous */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("General Options")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.miscDialog = XmCreateTemplateDialog(w->M.shell, "ODmiscDialog", arg, i);
  XtUnmanageChild(w->OD.miscDialog);

  i=0;
  w->OD.miscRowCol = XmCreateRowColumn(w->OD.miscDialog, "ODmiscRowCol", arg, i);
  XtManageChild(w->OD.miscRowCol);

  /* misc - Misc */
  
  i=0;
  w->OD.miscMiscFrame[0] = XmCreateFrame(w->OD.miscRowCol, "ODmiscMiscFrame0", arg, i);
  XtManageChild(w->OD.miscMiscFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Miscellaneous")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.miscMiscFrame[1] = XmCreateLabel(w->OD.miscMiscFrame[0], "ODmiscMiscFrame1", arg, i);
  XtManageChild(w->OD.miscMiscFrame[1]);
  
  i=0;
  w->OD.miscMiscCheck = XmCreateSimpleCheckBox(w->OD.miscMiscFrame[0], "ODmiscMiscCheck", arg, i);
  XtManageChild(w->OD.miscMiscCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Show Moving Axes")); i++;
  XtSetArg(arg[i], XmNset, CTX.axes?True:False); i++;
  w->OD.miscMiscButt[0] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt0", arg, i);
  XtManageChild(w->OD.miscMiscButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Show Small Axes")); i++;
  XtSetArg(arg[i], XmNset, CTX.small_axes?True:False); i++;
  w->OD.miscMiscButt[1] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt1", arg, i);
  XtManageChild(w->OD.miscMiscButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Enable Fast Redraw")); i++;
  XtSetArg(arg[i], XmNset, CTX.fast?True:False); i++;
  w->OD.miscMiscButt[2] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt2", arg, i);
  XtManageChild(w->OD.miscMiscButt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Use Display Lists")); i++;
  XtSetArg(arg[i], XmNset, CTX.display_lists?True:False); i++;
  w->OD.miscMiscButt[3] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt3", arg, i);
  XtManageChild(w->OD.miscMiscButt[3]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Enable Alpha Blending")); i++;
  XtSetArg(arg[i], XmNset, CTX.alpha?True:False); i++;
  w->OD.miscMiscButt[4] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt4", arg, i);
  XtManageChild(w->OD.miscMiscButt[4]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Trackball Rotation Mode")); i++;
  XtSetArg(arg[i], XmNset, CTX.useTrackball?True:False); i++;
  w->OD.miscMiscButt[5] = XmCreateToggleButton(w->OD.miscMiscCheck, "ODmiscMiscButt5", arg, i);
  XtManageChild(w->OD.miscMiscButt[5]);

  /* misc - colorscheme */

  i=0;
  w->OD.miscColorSchemeFrame[0] = XmCreateFrame(w->OD.miscRowCol, "ODmiscColorSchemeFrame0", arg, i);
  XtManageChild(w->OD.miscColorSchemeFrame[0]);
  
  i=0;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Predefined Color Schemes")); i++;
  w->OD.miscColorSchemeFrame[1] = XmCreateLabel(w->OD.miscColorSchemeFrame[0], "ODmiscColorSchemeFrame1", arg, i);
  XtManageChild(w->OD.miscColorSchemeFrame[1]);
  
  i=0;
  w->OD.miscColorSchemeFrameRowCol = XmCreateRowColumn(w->OD.miscColorSchemeFrame[0], "ODmiscColorSchemeFrameRowCol", arg, i);
  XtManageChild(w->OD.miscColorSchemeFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 2); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
  XtSetArg(arg[i], XmNshowValue, True); i++;
  XtSetArg(arg[i], XmNvalue, CTX.color.id); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.miscColorSchemeScale = XmCreateScale(w->OD.miscColorSchemeFrameRowCol, "ODmiscColorSchemeScale", arg, i);
  XtManageChild(w->OD.miscColorSchemeScale);

  /* misc - projection */
  
  i=0;
  w->OD.miscProjFrame[0] = XmCreateFrame(w->OD.miscRowCol, "ODmiscProjFrame0", arg, i);
  XtManageChild(w->OD.miscProjFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Projection")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.miscProjFrame[1] = XmCreateLabel(w->OD.miscProjFrame[0], "ODmiscProjFrame1", arg, i);
  XtManageChild(w->OD.miscProjFrame[1]);
  
  i=0;
  w->OD.miscProjCheck = XmCreateRadioBox(w->OD.miscProjFrame[0], "ODmiscProjCheck", arg, i);
  XtManageChild(w->OD.miscProjCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Orthographic")); i++;
  XtSetArg(arg[i], XmNset, CTX.ortho?True:False); i++;
  w->OD.miscProjButt[0] = XmCreateToggleButton(w->OD.miscProjCheck, "ODmiscProjButt0", arg, i);
  XtManageChild(w->OD.miscProjButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Perspective")); i++;
  XtSetArg(arg[i], XmNset, CTX.ortho?False:True); i++;
  w->OD.miscProjButt[1] = XmCreateToggleButton(w->OD.miscProjCheck, "ODmiscProjButt1", arg, i);
  XtManageChild(w->OD.miscProjButt[1]);


  /* misc - light position */
  i=0;
  w->OD.miscLightFrame[0] = XmCreateFrame(w->OD.miscRowCol, "ODmiscLightFrame0", arg, i);
  XtManageChild(w->OD.miscLightFrame[0]);
  
  i=0;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Light Position")); i++;
  w->OD.miscLightFrame[1] = XmCreateLabel(w->OD.miscLightFrame[0], "ODmiscLightFrame1", arg, i);
  XtManageChild(w->OD.miscLightFrame[1]);
  
  i=0;
  w->OD.miscLightFrameRowCol = XmCreateRowColumn(w->OD.miscLightFrame[0], "ODmiscLightFrameRowCol", arg, i);
  XtManageChild(w->OD.miscLightFrameRowCol);

  for(n=0 ; n<3 ; n++){
    i=0;
    XtSetArg(arg[i], XmNminimum, -25); i++;
    XtSetArg(arg[i], XmNmaximum, 25); i++;
    XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
    XtSetArg(arg[i], XmNshowValue, False); i++;
    XtSetArg(arg[i], XmNvalue, (int)25*CTX.light_position[0][n]); i++;
    XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
    w->OD.miscLightScale[n] = XmCreateScale(w->OD.miscLightFrameRowCol, "ODmiscLightScalen", arg, i);
    XtManageChild(w->OD.miscLightScale[n]);
  }

  /* misc - shininess */
  i=0;
  w->OD.miscShineFrame[0] = XmCreateFrame(w->OD.miscRowCol, "ODmiscShineFrame0", arg, i);
  XtManageChild(w->OD.miscShineFrame[0]);
  
  i=0;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Shininess")); i++;
  w->OD.miscShineFrame[1] = XmCreateLabel(w->OD.miscShineFrame[0], "ODmiscShineFrame1", arg, i);
  XtManageChild(w->OD.miscShineFrame[1]);
  
  i=0;
  w->OD.miscShineFrameRowCol = XmCreateRowColumn(w->OD.miscShineFrame[0], "ODmiscShineFrameRowCol", arg, i);
  XtManageChild(w->OD.miscShineFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 25); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 0); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNvalue, (int)25*CTX.shine); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->OD.miscShineScale = XmCreateScale(w->OD.miscShineFrameRowCol, "ODmiscShineScale", arg, i);
  XtManageChild(w->OD.miscShineScale);

  /* Viewport */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Viewport")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.viewportDialog = XmCreateTemplateDialog(w->M.shell, "ODviewportDialog", arg, i);
  XtUnmanageChild(w->OD.viewportDialog);

  i=0;
  w->OD.viewportRowCol = XmCreateRowColumn(w->OD.viewportDialog, "ODviewportRowCol", arg, i);
  XtManageChild(w->OD.viewportRowCol);

  /* viewport - rotate */
  
  i=0;
  w->OD.viewportFrame[0][0] = XmCreateFrame(w->OD.viewportRowCol, "ODviewportFrame00", arg, i);
  XtManageChild(w->OD.viewportFrame[0][0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Rotation")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.viewportFrame[1][0] = XmCreateLabel(w->OD.viewportFrame[0][0], "ODviewportFrame10", arg, i);
  XtManageChild(w->OD.viewportFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 3); i++;
  w->OD.viewportFrameRowCol[0] = XmCreateRowColumn(w->OD.viewportFrame[0][0], "ODviewportFrameRowCol0", arg, i);
  XtManageChild(w->OD.viewportFrameRowCol[0]);

  i=0;
  sprintf(label, "%g", CTX.r[0]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[0][0] = XmCreateTextField(w->OD.viewportFrameRowCol[0], "ODviewportText00", arg, i);
  XtManageChild(w->OD.viewportText[0][0]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.rlock[0]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("x-lock")); i++;
  w->OD.viewportLockButt[0][0] = XmCreateToggleButton(w->OD.viewportFrameRowCol[0], "ODviewportLockButt00", arg, i);
  XtManageChild(w->OD.viewportLockButt[0][0]);

  i=0;
  sprintf(label, "%g", CTX.r[1]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[0][1] = XmCreateTextField(w->OD.viewportFrameRowCol[0], "ODviewportText01", arg, i);
  XtManageChild(w->OD.viewportText[0][1]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.rlock[1]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("y-lock")); i++;
  w->OD.viewportLockButt[0][1] = XmCreateToggleButton(w->OD.viewportFrameRowCol[0], "ODviewportLockButt00", arg, i);
  XtManageChild(w->OD.viewportLockButt[0][1]);

  i=0;
  sprintf(label, "%g", CTX.r[2]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[0][2] = XmCreateTextField(w->OD.viewportFrameRowCol[0], "ODviewportText02", arg, i);
  XtManageChild(w->OD.viewportText[0][2]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.rlock[2]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("z-lock")); i++;
  w->OD.viewportLockButt[0][2] = XmCreateToggleButton(w->OD.viewportFrameRowCol[0], "ODviewportLockButt02", arg, i);
  XtManageChild(w->OD.viewportLockButt[0][2]);


  /* viewport - translate */
  
  i=0;
  w->OD.viewportFrame[0][1] = XmCreateFrame(w->OD.viewportRowCol, "ODviewportFrame01", arg, i);
  XtManageChild(w->OD.viewportFrame[0][1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Translation")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.viewportFrame[1][1] = XmCreateLabel(w->OD.viewportFrame[0][1], "ODviewportFrame11", arg, i);
  XtManageChild(w->OD.viewportFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 3); i++;
  w->OD.viewportFrameRowCol[1] = XmCreateRowColumn(w->OD.viewportFrame[0][1], "ODviewportFrameRowCol1", arg, i);
  XtManageChild(w->OD.viewportFrameRowCol[1]);

  i=0;
  sprintf(label, "%g", CTX.t[0]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[1][0] = XmCreateTextField(w->OD.viewportFrameRowCol[1], "ODviewportText10", arg, i);
  XtManageChild(w->OD.viewportText[1][0]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.tlock[0]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("x-lock")); i++;
  w->OD.viewportLockButt[1][0] = XmCreateToggleButton(w->OD.viewportFrameRowCol[1], "ODviewportLockButt10", arg, i);
  XtManageChild(w->OD.viewportLockButt[1][0]);

  i=0;
  sprintf(label, "%g", CTX.t[1]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[1][1] = XmCreateTextField(w->OD.viewportFrameRowCol[1], "ODviewportText11", arg, i);
  XtManageChild(w->OD.viewportText[1][1]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.tlock[1]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("y-lock")); i++;
  w->OD.viewportLockButt[1][1] = XmCreateToggleButton(w->OD.viewportFrameRowCol[1], "ODviewportLockButt00", arg, i);
  XtManageChild(w->OD.viewportLockButt[1][1]);

  i=0;
  sprintf(label, "%g", CTX.t[2]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[1][2] = XmCreateTextField(w->OD.viewportFrameRowCol[1], "ODviewportText12", arg, i);
  XtManageChild(w->OD.viewportText[1][2]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.tlock[2]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("z-lock")); i++;
  w->OD.viewportLockButt[1][2] = XmCreateToggleButton(w->OD.viewportFrameRowCol[1], "ODviewportLockButt12", arg, i);
  XtManageChild(w->OD.viewportLockButt[1][2]);


  /* viewport - scale */
  
  i=0;
  w->OD.viewportFrame[0][2] = XmCreateFrame(w->OD.viewportRowCol, "ODviewportFrame02", arg, i);
  XtManageChild(w->OD.viewportFrame[0][2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Scale")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.viewportFrame[1][2] = XmCreateLabel(w->OD.viewportFrame[0][2], "ODviewportFrame12", arg, i);
  XtManageChild(w->OD.viewportFrame[1][2]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 3); i++;
  w->OD.viewportFrameRowCol[2] = XmCreateRowColumn(w->OD.viewportFrame[0][2], "ODviewportFrameRowCol2", arg, i);
  XtManageChild(w->OD.viewportFrameRowCol[2]);

  i=0;
  sprintf(label, "%g", CTX.s[0]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[2][0] = XmCreateTextField(w->OD.viewportFrameRowCol[2], "ODviewportText20", arg, i);
  XtManageChild(w->OD.viewportText[2][0]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.slock[0]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("x-lock")); i++;
  w->OD.viewportLockButt[2][0] = XmCreateToggleButton(w->OD.viewportFrameRowCol[2], "ODviewportLockButt20", arg, i);
  XtManageChild(w->OD.viewportLockButt[2][0]);

  i=0;
  sprintf(label, "%g", CTX.s[1]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[2][1] = XmCreateTextField(w->OD.viewportFrameRowCol[2], "ODviewportText21", arg, i);
  XtManageChild(w->OD.viewportText[2][1]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.slock[1]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("y-lock")); i++;
  w->OD.viewportLockButt[2][1] = XmCreateToggleButton(w->OD.viewportFrameRowCol[2], "ODviewportLockButt20", arg, i);
  XtManageChild(w->OD.viewportLockButt[2][1]);

  i=0;
  sprintf(label, "%g", CTX.s[2]);
  XtSetArg(arg[i], XmNvalue, label); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->OD.viewportText[2][2] = XmCreateTextField(w->OD.viewportFrameRowCol[2], "ODviewportText22", arg, i);
  XtManageChild(w->OD.viewportText[2][2]);
  i=0;
  XtSetArg(arg[i], XmNset, CTX.slock[2]); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("z-lock")); i++;
  w->OD.viewportLockButt[2][2] = XmCreateToggleButton(w->OD.viewportFrameRowCol[2], "ODviewportLockButt22", arg, i);
  XtManageChild(w->OD.viewportLockButt[2][2]);

  /* Info */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Statistics")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Update")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->OD.infoDialog = XmCreateTemplateDialog(w->M.shell, "ODinfoDialog", arg, i);
  XtUnmanageChild(w->OD.infoDialog);

  i=0;
  w->OD.infoRowCol = XmCreateRowColumn(w->OD.infoDialog, "ODinfoRowCol", arg, i);
  XtManageChild(w->OD.infoRowCol);

  /* info - geom */

  i=0;
  w->OD.infoFrame[0][0] = XmCreateFrame(w->OD.infoRowCol, "ODinfoFrame00", arg, i);
  XtManageChild(w->OD.infoFrame[0][0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Geometry")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.infoFrame[1][0] = XmCreateLabel(w->OD.infoFrame[0][0], "ODinfoFrame10", arg, i);
  XtManageChild(w->OD.infoFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.infoFrameRowCol[0] = XmCreateRowColumn(w->OD.infoFrame[0][0], "ODinfoFrameRowCol0", arg, i);
  XtManageChild(w->OD.infoFrameRowCol[0]);
  
  for(n=0 ; n<NB_INFO_GEOM ; n++){    
    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(txt_info[n])); i++;
    w->OD.infoKeyLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[0], "ODinfoKeyLabel", arg, i);
    XtManageChild(w->OD.infoKeyLabel[n]);
  }
  for(n=0 ; n<NB_INFO_GEOM ; n++){
    i=0;
    w->OD.infoValueLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[0], "ODinfoValueLabel", arg, i);
    XtManageChild(w->OD.infoValueLabel[n]);
  }

  /* info - mesh */

  i=0;
  w->OD.infoFrame[0][1] = XmCreateFrame(w->OD.infoRowCol, "ODinfoFrame01", arg, i);
  XtManageChild(w->OD.infoFrame[0][1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Mesh")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.infoFrame[1][1] = XmCreateLabel(w->OD.infoFrame[0][1], "ODinfoFrame11", arg, i);
  XtManageChild(w->OD.infoFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.infoFrameRowCol[1] = XmCreateRowColumn(w->OD.infoFrame[0][1], "ODinfoFrameRowCol1", arg, i);
  XtManageChild(w->OD.infoFrameRowCol[1]);
  
  for(n=NB_INFO_GEOM ; n<NB_INFO_GEOM+NB_INFO_MESH ; n++){    
    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(txt_info[n])); i++;
    w->OD.infoKeyLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[1], "ODinfoKeyLabel", arg, i);
    XtManageChild(w->OD.infoKeyLabel[n]);
  }
  for(n=NB_INFO_GEOM ; n<NB_INFO_GEOM+NB_INFO_MESH ; n++){
    i=0;
    w->OD.infoValueLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[1], "ODinfoValueLabel", arg, i);
    XtManageChild(w->OD.infoValueLabel[n]);
  }

  /* info - post */

  i=0;
  w->OD.infoFrame[0][2] = XmCreateFrame(w->OD.infoRowCol, "ODinfoFrame02", arg, i);
  XtManageChild(w->OD.infoFrame[0][2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Post Processing")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->OD.infoFrame[1][2] = XmCreateLabel(w->OD.infoFrame[0][2], "ODinfoFrame12", arg, i);
  XtManageChild(w->OD.infoFrame[1][2]);

  i=0;
  XtSetArg(arg[i], XmNpacking, XmPACK_COLUMN); i++;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->OD.infoFrameRowCol[2] = XmCreateRowColumn(w->OD.infoFrame[0][2], "ODinfoFrameRowCol2", arg, i);
  XtManageChild(w->OD.infoFrameRowCol[2]);
  
  for(n=NB_INFO_GEOM+NB_INFO_MESH ; n<NB_INFO_MAX ; n++){    
    i=0;
    XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple(txt_info[n])); i++;
    w->OD.infoKeyLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[2], "ODinfoKeyLabel", arg, i);
    XtManageChild(w->OD.infoKeyLabel[n]);
  }
  for(n=NB_INFO_GEOM+NB_INFO_MESH ; n<NB_INFO_MAX ; n++){    
    i=0;
    w->OD.infoValueLabel[n] = XmCreateLabel(w->OD.infoFrameRowCol[2], "ODinfoValueLabel", arg, i);
    XtManageChild(w->OD.infoValueLabel[n]);
  }

}


/* ------------------------------------------------------------------------ 
    HELP DIALOGS
   ------------------------------------------------------------------------ */

char TextAbout[1024];

void CreateWidgets_HD(Widgets_T *w){
  int     i;
  Arg     arg[10];
  Widget  tmp ;

  /* keys */
  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Short Help")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->HD.keysDialog = XmCreateTemplateDialog(w->M.shell, "HDkeysDialog", arg, i);
  XtUnmanageChild(w->HD.keysDialog);

  i=0;
  XtSetArg(arg[i], XmNeditable, False); i++;
  XtSetArg(arg[i], XmNeditMode, XmMULTI_LINE_EDIT); i++;
  XtSetArg(arg[i], XmNcolumns, 66); i++;
  XtSetArg(arg[i], XmNrows, 25); i++;
  XtSetArg(arg[i], XmNvalue, txt_help); i++;
  w->HD.keysText = XmCreateScrolledText(w->HD.keysDialog, "HDkeysText", arg, i);
  XtManageChild(w->HD.keysText);
  

  /* about */
  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("About Gmsh")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  XtSetArg(arg[i], XmNmessageString, XmStringCreateLtoR(TextAbout,XmFONTLIST_DEFAULT_TAG)); i++;
  w->HD.aboutDialog = XmCreateInformationDialog(w->M.shell, "HDaboutDialog", arg, i);
  XtUnmanageChild(w->HD.aboutDialog);

  tmp = XmMessageBoxGetChild(w->HD.aboutDialog, XmDIALOG_HELP_BUTTON);
  XtUnmanageChild(tmp);
  tmp = XmMessageBoxGetChild(w->HD.aboutDialog, XmDIALOG_CANCEL_BUTTON);
  XtUnmanageChild(tmp);

}

/* ------------------------------------------------------------------------ 
    GEOMETRY DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_GD(Widgets_T *w){
  int   i;
  Arg   arg[10];
  
  /* Parameter */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Add Parameter")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Add")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.paramDialog = XmCreateTemplateDialog(w->M.shell, "GDparamDialog", arg, i);
  XtUnmanageChild(w->GD.paramDialog);

  i=0;
  w->GD.paramRowCol = XmCreateRowColumn(w->GD.paramDialog, "ODparamRowCol", arg, i);
  XtManageChild(w->GD.paramRowCol);

  /* param - name */
  
  i=0;
  w->GD.paramFrame[0][0] = XmCreateFrame(w->GD.paramRowCol, "GDparamFrame00", arg, i);
  XtManageChild(w->GD.paramFrame[0][0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Name")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.paramFrame[1][0] = XmCreateLabel(w->GD.paramFrame[0][0], "GDparamFrame10", arg, i);
  XtManageChild(w->GD.paramFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.paramFrameRowCol[0] = XmCreateRowColumn(w->GD.paramFrame[0][0], "ODparamFrameRowCol0", arg, i);
  XtManageChild(w->GD.paramFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  w->GD.paramText[0] = XmCreateTextField(w->GD.paramFrameRowCol[0], "GDparamText0", arg, i);
  XtManageChild(w->GD.paramText[0]);

  /* param - value */
  
  i=0;
  w->GD.paramFrame[0][1] = XmCreateFrame(w->GD.paramRowCol, "GDparamFrame01", arg, i);
  XtManageChild(w->GD.paramFrame[0][1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Value")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.paramFrame[1][1] = XmCreateLabel(w->GD.paramFrame[0][1], "GDparamFrame11", arg, i);
  XtManageChild(w->GD.paramFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.paramFrameRowCol[1] = XmCreateRowColumn(w->GD.paramFrame[0][1], "ODparamFrameRowCol1", arg, i);
  XtManageChild(w->GD.paramFrameRowCol[1]); 

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  w->GD.paramText[1] = XmCreateTextField(w->GD.paramFrameRowCol[1], "GDparamText1", arg, i);
  XtManageChild(w->GD.paramText[1]);
  

  /* Point */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Add Point")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Add")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.pointDialog = XmCreateTemplateDialog(w->M.shell, "GDpointDialog", arg, i);
  XtUnmanageChild(w->GD.pointDialog);

  i=0;
  w->GD.pointRowCol = XmCreateRowColumn(w->GD.pointDialog, "ODpointRowCol", arg, i);
  XtManageChild(w->GD.pointRowCol);

  /* point - coords */
  
  i=0;
  w->GD.pointFrame[0][0] = XmCreateFrame(w->GD.pointRowCol, "GDpointFrame00", arg, i);
  XtManageChild(w->GD.pointFrame[0][0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Coordinates")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.pointFrame[1][0] = XmCreateLabel(w->GD.pointFrame[0][0], "GDpointFrame10", arg, i);
  XtManageChild(w->GD.pointFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.pointFrameRowCol[0] = XmCreateRowColumn(w->GD.pointFrame[0][0], "ODpointFrameRowCol0", arg, i);
  XtManageChild(w->GD.pointFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.pointText[0] = XmCreateTextField(w->GD.pointFrameRowCol[0], "GDpointText0", arg, i);
  XtManageChild(w->GD.pointText[0]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.pointText[1] = XmCreateTextField(w->GD.pointFrameRowCol[0], "GDpointText1", arg, i);
  XtManageChild(w->GD.pointText[1]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.pointText[2] = XmCreateTextField(w->GD.pointFrameRowCol[0], "GDpointText2", arg, i);
  XtManageChild(w->GD.pointText[2]);

  /* point - char length */
  
  i=0;
  w->GD.pointFrame[0][1] = XmCreateFrame(w->GD.pointRowCol, "GDpointFrame01", arg, i);
  XtManageChild(w->GD.pointFrame[0][1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Characteristc Length")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.pointFrame[1][1] = XmCreateLabel(w->GD.pointFrame[0][1], "GDpointFrame11", arg, i);
  XtManageChild(w->GD.pointFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.pointFrameRowCol[1] = XmCreateRowColumn(w->GD.pointFrame[0][1], "ODpointFrameRowCol1", arg, i);
  XtManageChild(w->GD.pointFrameRowCol[1]); 
  
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.pointText[3] = XmCreateTextField(w->GD.pointFrameRowCol[1], "GDpointText3", arg, i);
  XtManageChild(w->GD.pointText[3]);


  /* Rotation */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Current Rotation")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.rotDialog = XmCreateTemplateDialog(w->M.shell, "GDrotDialog", arg, i);
  XtUnmanageChild(w->GD.rotDialog);

  i=0;
  w->GD.rotRowCol = XmCreateRowColumn(w->GD.rotDialog, "ODrotRowCol", arg, i);
  XtManageChild(w->GD.rotRowCol);

  /* rot - axis point */
  
  i=0;
  w->GD.rotFrame[0][0] = XmCreateFrame(w->GD.rotRowCol, "GDrotFrame00", arg, i);
  XtManageChild(w->GD.rotFrame[0][0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Axis Point")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.rotFrame[1][0] = XmCreateLabel(w->GD.rotFrame[0][0], "GDrotFrame10", arg, i);
  XtManageChild(w->GD.rotFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.rotFrameRowCol[0] = XmCreateRowColumn(w->GD.rotFrame[0][0], "ODrotFrameRowCol0", arg, i);
  XtManageChild(w->GD.rotFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[0] = XmCreateTextField(w->GD.rotFrameRowCol[0], "GDrotText0", arg, i);
  XtManageChild(w->GD.rotText[0]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[1] = XmCreateTextField(w->GD.rotFrameRowCol[0], "GDrotText1", arg, i);
  XtManageChild(w->GD.rotText[1]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[2] = XmCreateTextField(w->GD.rotFrameRowCol[0], "GDrotText2", arg, i);
  XtManageChild(w->GD.rotText[2]);

  /* rot - direction */
  
  i=0;
  w->GD.rotFrame[0][1] = XmCreateFrame(w->GD.rotRowCol, "GDrotFrame01", arg, i);
  XtManageChild(w->GD.rotFrame[0][1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Direction")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.rotFrame[1][1] = XmCreateLabel(w->GD.rotFrame[0][1], "GDrotFrame11", arg, i);
  XtManageChild(w->GD.rotFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.rotFrameRowCol[1] = XmCreateRowColumn(w->GD.rotFrame[0][1], "ODrotFrameRowCol1", arg, i);
  XtManageChild(w->GD.rotFrameRowCol[1]); 
  
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[3] = XmCreateTextField(w->GD.rotFrameRowCol[1], "GDrotText3", arg, i);
  XtManageChild(w->GD.rotText[3]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[4] = XmCreateTextField(w->GD.rotFrameRowCol[1], "GDrotText4", arg, i);
  XtManageChild(w->GD.rotText[4]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[5] = XmCreateTextField(w->GD.rotFrameRowCol[1], "GDrotText5", arg, i);
  XtManageChild(w->GD.rotText[5]);

  /* rot - angle */
  
  i=0;
  w->GD.rotFrame[0][2] = XmCreateFrame(w->GD.rotRowCol, "GDrotFrame02", arg, i);
  XtManageChild(w->GD.rotFrame[0][2]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Angle")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.rotFrame[1][2] = XmCreateLabel(w->GD.rotFrame[0][2], "GDrotFrame12", arg, i);
  XtManageChild(w->GD.rotFrame[1][2]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.rotFrameRowCol[2] = XmCreateRowColumn(w->GD.rotFrame[0][2], "ODrotFrameRowCol2", arg, i);
  XtManageChild(w->GD.rotFrameRowCol[2]); 
  
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.rotText[6] = XmCreateTextField(w->GD.rotFrameRowCol[2], "GDrotText6", arg, i);
  XtManageChild(w->GD.rotText[6]);


  /* Translation */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Current Translation")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.tranDialog = XmCreateTemplateDialog(w->M.shell, "GDtranDialog", arg, i);
  XtUnmanageChild(w->GD.tranDialog);

  i=0;
  w->GD.tranFrame[0] = XmCreateFrame(w->GD.tranDialog, "GDtranFrame0", arg, i);
  XtManageChild(w->GD.tranFrame[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Vector")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.tranFrame[1] = XmCreateLabel(w->GD.tranFrame[0], "GDtranFrame1", arg, i);
  XtManageChild(w->GD.tranFrame[1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.tranFrameRowCol = XmCreateRowColumn(w->GD.tranFrame[0], "ODtranFrameRowCol", arg, i);
  XtManageChild(w->GD.tranFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.tranText[0] = XmCreateTextField(w->GD.tranFrameRowCol, "GDtranText0", arg, i);
  XtManageChild(w->GD.tranText[0]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.tranText[1] = XmCreateTextField(w->GD.tranFrameRowCol, "GDtranText1", arg, i);
  XtManageChild(w->GD.tranText[1]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.tranText[2] = XmCreateTextField(w->GD.tranFrameRowCol, "GDtranText2", arg, i);
  XtManageChild(w->GD.tranText[2]);


  /* Dilatation */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Current Dilatation")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.dilatDialog = XmCreateTemplateDialog(w->M.shell, "GDdilatDialog", arg, i);
  XtUnmanageChild(w->GD.dilatDialog);

  i=0;
  w->GD.dilatRowCol = XmCreateRowColumn(w->GD.dilatDialog, "ODdilatRowCol", arg, i);
  XtManageChild(w->GD.dilatRowCol);

  /* dilat - coords */
  
  i=0;
  w->GD.dilatFrame[0][0] = XmCreateFrame(w->GD.dilatRowCol, "GDdilatFrame00", arg, i);
  XtManageChild(w->GD.dilatFrame[0][0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Vector")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.dilatFrame[1][0] = XmCreateLabel(w->GD.dilatFrame[0][0], "GDdilatFrame10", arg, i);
  XtManageChild(w->GD.dilatFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.dilatFrameRowCol[0] = XmCreateRowColumn(w->GD.dilatFrame[0][0], "ODdilatFrameRowCol0", arg, i);
  XtManageChild(w->GD.dilatFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.dilatText[0] = XmCreateTextField(w->GD.dilatFrameRowCol[0], "GDdilatText0", arg, i);
  XtManageChild(w->GD.dilatText[0]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.dilatText[1] = XmCreateTextField(w->GD.dilatFrameRowCol[0], "GDdilatText1", arg, i);
  XtManageChild(w->GD.dilatText[1]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.dilatText[2] = XmCreateTextField(w->GD.dilatFrameRowCol[0], "GDdilatText2", arg, i);
  XtManageChild(w->GD.dilatText[2]);

  /* dilat - factor */
  
  i=0;
  w->GD.dilatFrame[0][1] = XmCreateFrame(w->GD.dilatRowCol, "GDdilatFrame01", arg, i);
  XtManageChild(w->GD.dilatFrame[0][1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Factor")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.dilatFrame[1][1] = XmCreateLabel(w->GD.dilatFrame[0][1], "GDdilatFrame11", arg, i);
  XtManageChild(w->GD.dilatFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.dilatFrameRowCol[1] = XmCreateRowColumn(w->GD.dilatFrame[0][1], "ODdilatFrameRowCol1", arg, i);
  XtManageChild(w->GD.dilatFrameRowCol[1]); 
  
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.dilatText[3] = XmCreateTextField(w->GD.dilatFrameRowCol[1], "GDdilatText3", arg, i);
  XtManageChild(w->GD.dilatText[3]);

  /* Symmetry */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Current Symmetry")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->GD.symmDialog = XmCreateTemplateDialog(w->M.shell, "GDsymmDialog", arg, i);
  XtUnmanageChild(w->GD.symmDialog);

  i=0;
  w->GD.symmFrame[0] = XmCreateFrame(w->GD.symmDialog, "GDsymmFrame0", arg, i);
  XtManageChild(w->GD.symmFrame[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Plane")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->GD.symmFrame[1] = XmCreateLabel(w->GD.symmFrame[0], "GDsymmFrame1", arg, i);
  XtManageChild(w->GD.symmFrame[1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->GD.symmFrameRowCol = XmCreateRowColumn(w->GD.symmFrame[0], "ODsymmFrameRowCol", arg, i);
  XtManageChild(w->GD.symmFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.symmText[0] = XmCreateTextField(w->GD.symmFrameRowCol, "GDsymmText0", arg, i);
  XtManageChild(w->GD.symmText[0]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.symmText[1] = XmCreateTextField(w->GD.symmFrameRowCol, "GDsymmText1", arg, i);
  XtManageChild(w->GD.symmText[1]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.symmText[2] = XmCreateTextField(w->GD.symmFrameRowCol, "GDsymmText2", arg, i);
  XtManageChild(w->GD.symmText[2]);
  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  XtSetArg(arg[i], XmNcolumns, 10); i++;
  w->GD.symmText[3] = XmCreateTextField(w->GD.symmFrameRowCol, "GDsymmText3", arg, i);
  XtManageChild(w->GD.symmText[3]);

}

/* ------------------------------------------------------------------------ 
    MESH DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_MD(Widgets_T *w){
  int   i;
  Arg   arg[10];

  /* Characteristic length */
  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Characteristic Length")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->MD.charLengthDialog = XmCreateTemplateDialog(w->M.shell, "MDcharLengthDialog", arg, i);
  XtUnmanageChild(w->MD.charLengthDialog);

  i=0;
  w->MD.charLengthFrame[0] = XmCreateFrame(w->MD.charLengthDialog, "MDcharLengthFrame0", arg, i);
  XtManageChild(w->MD.charLengthFrame[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Value")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->MD.charLengthFrame[1] = XmCreateLabel(w->MD.charLengthFrame[0], "MDcharLengthFrame1", arg, i);
  XtManageChild(w->MD.charLengthFrame[1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->MD.charLengthFrameRowCol = XmCreateRowColumn(w->MD.charLengthFrame[0], "MDcharLengthFrameRowCol", arg, i);
  XtManageChild(w->MD.charLengthFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  w->MD.charLengthText = XmCreateTextField(w->MD.charLengthFrameRowCol, "MDcharLengthText", arg, i);
  XtManageChild(w->MD.charLengthText);

  /* Transfinite Line */

  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Transfinite Line")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->MD.trsfLineDialog = XmCreateTemplateDialog(w->M.shell, "MDtrsfLineDialog", arg, i);
  XtUnmanageChild(w->MD.trsfLineDialog);

  i=0;
  w->MD.trsfLineRowCol = XmCreateRowColumn(w->MD.trsfLineDialog, "MDtrsfLineRowCol", arg, i);
  XtManageChild(w->MD.trsfLineRowCol);

  /* trsf line  - type */
  
  i=0;
  w->MD.trsfLineFrame[0][0] = XmCreateFrame(w->MD.trsfLineRowCol, "MDtrsfLineFrame00", arg, i);
  XtManageChild(w->MD.trsfLineFrame[0][0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Type")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->MD.trsfLineFrame[1][0] = XmCreateLabel(w->MD.trsfLineFrame[0][0], "MDtrsfLineFrame10", arg, i);
  XtManageChild(w->MD.trsfLineFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->MD.trsfLineFrameRowCol[0] = XmCreateRowColumn(w->MD.trsfLineFrame[0][0], "MDtrsfLineFrameRowCol0", arg, i);
  XtManageChild(w->MD.trsfLineFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNvalue, "Power 1.0"); i++;
  w->MD.trsfLineText[0] = XmCreateTextField(w->MD.trsfLineFrameRowCol[0], "MDtrsfLineText0", arg, i);
  XtManageChild(w->MD.trsfLineText[0]);

  /* trsf line - nb pts */
  
  i=0;
  w->MD.trsfLineFrame[0][1] = XmCreateFrame(w->MD.trsfLineRowCol, "MDtrsfLineFrame01", arg, i);
  XtManageChild(w->MD.trsfLineFrame[0][1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Number of Points")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->MD.trsfLineFrame[1][1] = XmCreateLabel(w->MD.trsfLineFrame[0][1], "MDtrsfLineFrame11", arg, i);
  XtManageChild(w->MD.trsfLineFrame[1][1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->MD.trsfLineFrameRowCol[1] = XmCreateRowColumn(w->MD.trsfLineFrame[0][1], "MDtrsfLineFrameRowCol1", arg, i);
  XtManageChild(w->MD.trsfLineFrameRowCol[1]); 
  
  i=0;
  XtSetArg(arg[i], XmNvalue, "2"); i++;
  w->MD.trsfLineText[1] = XmCreateTextField(w->MD.trsfLineFrameRowCol[1], "MDtrsfLineText1", arg, i);
  XtManageChild(w->MD.trsfLineText[1]);

  /* Transfinite Volume */
  i=0;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Transfinite Volume")); i++;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Ok")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->MD.trsfVolumeDialog = XmCreateTemplateDialog(w->M.shell, "MDtrsfVolumeDialog", arg, i);
  XtUnmanageChild(w->MD.trsfVolumeDialog);

  i=0;
  w->MD.trsfVolumeFrame[0] = XmCreateFrame(w->MD.trsfVolumeDialog, "MDtrsfVolumeFrame0", arg, i);
  XtManageChild(w->MD.trsfVolumeFrame[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Number")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->MD.trsfVolumeFrame[1] = XmCreateLabel(w->MD.trsfVolumeFrame[0], "MDtrsfVolumeFrame1", arg, i);
  XtManageChild(w->MD.trsfVolumeFrame[1]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->MD.trsfVolumeFrameRowCol = XmCreateRowColumn(w->MD.trsfVolumeFrame[0], "MDtrsfVolumeFrameRowCol", arg, i);
  XtManageChild(w->MD.trsfVolumeFrameRowCol);

  i=0;
  XtSetArg(arg[i], XmNvalue, ""); i++;
  w->MD.trsfVolumeText = XmCreateTextField(w->MD.trsfVolumeFrameRowCol, "MDtrsfVolumeText", arg, i);
  XtManageChild(w->MD.trsfVolumeText);

}

/* ------------------------------------------------------------------------ 
    POST PROCESSING DIALOGS
   ------------------------------------------------------------------------ */

void CreateWidgets_PD(Widgets_T *w){
  int     i, n;
  Arg     arg[10];
  Widget  tmp;

  /* Offset */
  i=0;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->PD.offsetDialog = XmCreateTemplateDialog(w->M.shell, "PDoffsetDialog", arg, i);
  XtUnmanageChild(w->PD.offsetDialog);

  i=0;
  w->PD.offsetRowCol = XmCreateRowColumn(w->PD.offsetDialog, "PDoffsetRowCol", arg, i);
  XtManageChild(w->PD.offsetRowCol);


  /* Offset mode */
  i=0;
  w->PD.offsetFrame[0][0] = XmCreateFrame(w->PD.offsetRowCol, "ODoffsetFrame00", arg, i);
  XtManageChild(w->PD.offsetFrame[0][0]);
  
  i=0;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Offset Mode")); i++;
  w->PD.offsetFrame[1][0] = XmCreateLabel(w->PD.offsetFrame[0][0], "PDoffsetFrame10", arg, i);
  XtManageChild(w->PD.offsetFrame[1][0]);
  
  i=0;
  w->PD.offsetFrameRowCol[0] = XmCreateRowColumn(w->PD.offsetFrame[0][0], "PDoffsetFrameRowCol0", arg, i);
  XtManageChild(w->PD.offsetFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;  
  w->PD.offsetModeCheck = XmCreateRadioBox(w->PD.offsetFrameRowCol[0], "PDoffsetModeCheck", arg, i);
  XtManageChild(w->PD.offsetModeCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Translation")); i++;
  w->PD.offsetModeButt[0] = XmCreateToggleButton(w->PD.offsetModeCheck, "PDoffsetModeButt0", arg, i);
  XtManageChild(w->PD.offsetModeButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Raise")); i++;
  w->PD.offsetModeButt[1] = XmCreateToggleButton(w->PD.offsetModeCheck, "PDoffsetModeButt1", arg, i);
  XtManageChild(w->PD.offsetModeButt[1]);
  
  /* Offset sliders and text fields */

  for(n=1 ; n<4 ; n++){
    i=0;
    w->PD.offsetFrame[0][n] = XmCreateFrame(w->PD.offsetRowCol, "ODoffsetFrame0n", arg, i);
    XtManageChild(w->PD.offsetFrame[0][n]);

    i=0;
    XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
    w->PD.offsetFrame[1][n] = XmCreateLabel(w->PD.offsetFrame[0][n], "PDoffsetFrame1n", arg, i);
    XtManageChild(w->PD.offsetFrame[1][n]);

    i=0;
    w->PD.offsetFrameRowCol[n] = XmCreateRowColumn(w->PD.offsetFrame[0][n], "PDoffsetFrameRowColn", arg, i);
    XtManageChild(w->PD.offsetFrameRowCol[n]);
  
    i=0;
    XtSetArg(arg[i], XmNminimum, -100); i++;
    XtSetArg(arg[i], XmNmaximum, 100); i++;
    XtSetArg(arg[i], XmNdecimalPoints, 2); i++;
    XtSetArg(arg[i], XmNshowValue, False); i++;
    XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
    w->PD.offsetScale[n-1] = XmCreateScale(w->PD.offsetFrameRowCol[n], "PDoffsetScalen", arg, i);
    XtManageChild(w->PD.offsetScale[n-1]);
    
    i=0;
    w->PD.offsetText[n-1] = XmCreateTextField(w->PD.offsetFrameRowCol[n], "PDoffsetTextn", arg, i);
    XtManageChild(w->PD.offsetText[n-1]);
  }
  
  XtVaSetValues(w->PD.offsetFrame[1][1], XmNlabelString, XmStringCreateSimple("X"), NULL);
  XtVaSetValues(w->PD.offsetFrame[1][2], XmNlabelString, XmStringCreateSimple("Y"), NULL);
  XtVaSetValues(w->PD.offsetFrame[1][3], XmNlabelString, XmStringCreateSimple("Z"), NULL);


  /* TimeStep */
  i=0;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->PD.timeStepDialog = XmCreateTemplateDialog(w->M.shell, "PDtimeStepDialog", arg, i);
  XtUnmanageChild(w->PD.timeStepDialog);

  i=0;
  w->PD.timeStepFrame[0] = XmCreateFrame(w->PD.timeStepDialog, "ODtimeStepFrame0", arg, i);
  XtManageChild(w->PD.timeStepFrame[0]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Time Step")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.timeStepFrame[1] = XmCreateLabel(w->PD.timeStepFrame[0], "PDtimeStepFrame1", arg, i);
  XtManageChild(w->PD.timeStepFrame[1]);
  
  i=0;
  w->PD.timeStepFrameRowCol = XmCreateRowColumn(w->PD.timeStepFrame[0], "PDtimeStepRowCol", arg, i);
  XtManageChild(w->PD.timeStepFrameRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->PD.timeStepScale = XmCreateScale(w->PD.timeStepFrameRowCol, "PDtimeStepScale", arg, i);
  XtManageChild(w->PD.timeStepScale);
  
  i=0;
  w->PD.timeStepText = XmCreateTextField(w->PD.timeStepFrameRowCol, "PDtimeStepText", arg, i);
  XtManageChild(w->PD.timeStepText);

  /* Scale */
  i=0;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->PD.scaleDialog = XmCreateTemplateDialog(w->M.shell, "PDscaleDialog", arg, i);
  XtUnmanageChild(w->PD.scaleDialog);

  i=0;
  w->PD.scaleRowCol = XmCreateRowColumn(w->PD.scaleDialog, "PDscaleRowCol", arg, i);
  XtManageChild(w->PD.scaleRowCol);

  /* Scale - bar */
  i=0;
  w->PD.scaleFrame[0][0] = XmCreateFrame(w->PD.scaleRowCol, "ODscaleFrame00", arg, i);
  XtManageChild(w->PD.scaleFrame[0][0]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Scale Bar")); i++;  
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.scaleFrame[1][0] = XmCreateLabel(w->PD.scaleFrame[0][0], "PDscaleFrame10", arg, i);
  XtManageChild(w->PD.scaleFrame[1][0]);
  
  i=0;
  w->PD.scaleFrameRowCol[0] = XmCreateRowColumn(w->PD.scaleFrame[0][0], "PDscaleFrameRowCol0", arg, i);
  XtManageChild(w->PD.scaleFrameRowCol[0]);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->PD.scaleCheck = XmCreateSimpleCheckBox(w->PD.scaleFrameRowCol[0], "PDscaleCheck", arg, i);
  XtManageChild(w->PD.scaleCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Show")); i++;
  w->PD.scaleShowButt = XmCreateToggleButton(w->PD.scaleCheck, "PDscaleShowButt", arg, i);
  XtManageChild(w->PD.scaleShowButt);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Transparency")); i++;
  w->PD.scaleTransButt = XmCreateToggleButton(w->PD.scaleCheck, "PDscaleTransButt", arg, i);
  XtManageChild(w->PD.scaleTransButt);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Time Display")); i++;
  w->PD.scaleTimeButt = XmCreateToggleButton(w->PD.scaleCheck, "PDscaleTimeButt", arg, i);
  XtManageChild(w->PD.scaleTimeButt);

  for(n=0 ; n<2 ; n++){
    i=0;
    XtSetArg(arg[i], XmNvalue, "0.00000000000000000001e-1"); i++; /* lesstif bug */
    w->PD.scaleText[n] = XmCreateTextField(w->PD.scaleFrameRowCol[0], "PDscaleTextn", arg, i);
    XtManageChild(w->PD.scaleText[n]);
  }

  /* Scale - range */
  i=0;
  w->PD.scaleFrame[0][1] = XmCreateFrame(w->PD.scaleRowCol, "ODscaleFrame01", arg, i);
  XtManageChild(w->PD.scaleFrame[0][1]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Value Range")); i++;  
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.scaleFrame[1][1] = XmCreateLabel(w->PD.scaleFrame[0][1], "PDscaleFrame11", arg, i);
  XtManageChild(w->PD.scaleFrame[1][1]);
  
  i=0;
  w->PD.scaleFrameRowCol[1] = XmCreateRowColumn(w->PD.scaleFrame[0][1], "PDscaleFrameRowCol1", arg, i);
  XtManageChild(w->PD.scaleFrameRowCol[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Custom")); i++;
  w->PD.scaleRangeButt = XmCreateToggleButton(w->PD.scaleFrameRowCol[1], "PDscaleRangeButt", arg, i);
  XtManageChild(w->PD.scaleRangeButt);

  for(n=0 ; n<2 ; n++){
    i=0;
    XtSetArg(arg[i], XmNvalue, "0.00000000000000000001e-1"); i++; /* lesstif bug */
    w->PD.scaleRangeText[n] = XmCreateTextField(w->PD.scaleFrameRowCol[1], "PDscaleRangeTextn", arg, i);
    XtManageChild(w->PD.scaleRangeText[n]);
  }

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->PD.scaleTypeCheck = XmCreateRadioBox(w->PD.scaleFrameRowCol[1], "PDscaleTypeCheck", arg, i);
  XtManageChild(w->PD.scaleTypeCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Linear")); i++;
  w->PD.scaleTypeButt[0] = XmCreateToggleButton(w->PD.scaleTypeCheck, "PDscaleTypeButt0", arg, i);
  XtManageChild(w->PD.scaleTypeButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Logarithmic")); i++;
  w->PD.scaleTypeButt[1] = XmCreateToggleButton(w->PD.scaleTypeCheck, "PDscaleTypeButt1", arg, i);
  XtManageChild(w->PD.scaleTypeButt[1]);


  /* Scale - intervals */
  i=0;
  w->PD.scaleFrame[0][2] = XmCreateFrame(w->PD.scaleRowCol, "ODscaleFrame02", arg, i);
  XtManageChild(w->PD.scaleFrame[0][2]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Intervals")); i++;  
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.scaleFrame[1][2] = XmCreateLabel(w->PD.scaleFrame[0][2], "PDscaleFrame12", arg, i);
  XtManageChild(w->PD.scaleFrame[1][2]);
  
  i=0;
  w->PD.scaleFrameRowCol[2] = XmCreateRowColumn(w->PD.scaleFrame[0][2], "PDscaleFrameRowCol2", arg, i);
  XtManageChild(w->PD.scaleFrameRowCol[2]);

  i=0;
  XtSetArg(arg[i], XmNminimum, 1); i++;
  XtSetArg(arg[i], XmNmaximum, 100); i++;
  XtSetArg(arg[i], XmNvalue, 15); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->PD.scaleIntervalsScale = XmCreateScale(w->PD.scaleFrameRowCol[2], "PDscaleIntervalsScale", arg, i);
  XtManageChild(w->PD.scaleIntervalsScale);
  
  i=0;
  w->PD.scaleIntervalsText = XmCreateTextField(w->PD.scaleFrameRowCol[2], "PDscaleIntervalsText", arg, i);
  XtManageChild(w->PD.scaleIntervalsText);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->PD.scaleIntervalsCheck = XmCreateRadioBox(w->PD.scaleFrameRowCol[2], "PDscaleIntervalsCheck", arg, i);
  XtManageChild(w->PD.scaleIntervalsCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Iso")); i++;
  w->PD.scaleIntervalsButt[0] = XmCreateToggleButton(w->PD.scaleIntervalsCheck, "PDscaleIntervalsButt0", arg, i);
  XtManageChild(w->PD.scaleIntervalsButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Filled Iso")); i++;
  w->PD.scaleIntervalsButt[1] = XmCreateToggleButton(w->PD.scaleIntervalsCheck, "PDscaleIntervalsButt1", arg, i);
  XtManageChild(w->PD.scaleIntervalsButt[1]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Continous")); i++;
  w->PD.scaleIntervalsButt[2] = XmCreateToggleButton(w->PD.scaleIntervalsCheck, "PDscaleIntervalsButt2", arg, i);
  XtManageChild(w->PD.scaleIntervalsButt[2]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Numeric")); i++;
  w->PD.scaleIntervalsButt[3] = XmCreateToggleButton(w->PD.scaleIntervalsCheck, "PDscaleIntervalsButt3", arg, i);
  XtManageChild(w->PD.scaleIntervalsButt[3]);

  /* Color */
  i=0;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->PD.colorDialog = XmCreateTemplateDialog(w->M.shell, "PDcolorDialog", arg, i);
  XtUnmanageChild(w->PD.colorDialog);

  i=0;
  w->PD.colorFrame[0][0] = XmCreateFrame(w->PD.colorDialog, "ODcolorFrame00", arg, i);
  XtManageChild(w->PD.colorFrame[0][0]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Colors")); i++;  
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.colorFrame[1][0] = XmCreateLabel(w->PD.colorFrame[0][0], "PDcolorFrame10", arg, i);
  XtManageChild(w->PD.colorFrame[1][0]);

  i=0;
  /* hardcoded this one, since its is required for the motion handling */
  XtSetArg(arg[i], XmNtranslations, XtParseTranslationTable(DrawingAreaTranslations)); i++;
  w->PD.colorDrawingArea = XmCreateDrawingArea(w->PD.colorFrame[0][0], "PDcolorDrawingArea", arg, i);
  XtManageChild(w->PD.colorDrawingArea);


  /* Vectors */
  i=0;
  XtSetArg(arg[i], XmNokLabelString, XmStringCreateSimple("Apply")); i++;
  XtSetArg(arg[i], XmNcancelLabelString, XmStringCreateSimple("Cancel")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, False); i++;
  w->PD.vectorDialog = XmCreateTemplateDialog(w->M.shell, "PDvectorDialog", arg, i);
  XtUnmanageChild(w->PD.vectorDialog);

  i=0;
  w->PD.vectorRowCol = XmCreateRowColumn(w->PD.vectorDialog, "PDvectorRowCol", arg, i);
  XtManageChild(w->PD.vectorRowCol);

  /* vector - type */

  i=0;
  w->PD.vectorFrame[0][0] = XmCreateFrame(w->PD.vectorRowCol, "ODvectorFrame00", arg, i);
  XtManageChild(w->PD.vectorFrame[0][0]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Vector Display Type")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.vectorFrame[1][0] = XmCreateLabel(w->PD.vectorFrame[0][0], "PDvectorFrame10", arg, i);
  XtManageChild(w->PD.vectorFrame[1][0]);

  i=0;
  XtSetArg(arg[i], XmNnumColumns, 2); i++;
  w->PD.vectorTypeCheck = XmCreateRadioBox(w->PD.vectorFrame[0][0], "PDvectorTypeCheck", arg, i);
  XtManageChild(w->PD.vectorTypeCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Line")); i++;
  w->PD.vectorTypeButt[0] = XmCreateToggleButton(w->PD.vectorTypeCheck, "PDvectorTypeButt0", arg, i);
  XtManageChild(w->PD.vectorTypeButt[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Arrow")); i++;
  w->PD.vectorTypeButt[1] = XmCreateToggleButton(w->PD.vectorTypeCheck, "PDvectorTypeButt1", arg, i);
  XtManageChild(w->PD.vectorTypeButt[1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Pyramid")); i++;
  w->PD.vectorTypeButt[2] = XmCreateToggleButton(w->PD.vectorTypeCheck, "PDvectorTypeButt2", arg, i);
  XtManageChild(w->PD.vectorTypeButt[2]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Cone")); i++;
  w->PD.vectorTypeButt[3] = XmCreateToggleButton(w->PD.vectorTypeCheck, "PDvectorTypeButt3", arg, i);
  XtManageChild(w->PD.vectorTypeButt[3]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Displacement")); i++;
  w->PD.vectorTypeButt[4] = XmCreateToggleButton(w->PD.vectorTypeCheck, "PDvectorTypeButt4", arg, i);
  XtManageChild(w->PD.vectorTypeButt[4]);

  /* vector - scale */
  
  i=0;
  w->PD.vectorFrame[0][1] = XmCreateFrame(w->PD.vectorRowCol, "ODvectorFrame01", arg, i);
  XtManageChild(w->PD.vectorFrame[0][1]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Scale")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.vectorFrame[1][1] = XmCreateLabel(w->PD.vectorFrame[0][1], "PDvectorFrame11", arg, i);
  XtManageChild(w->PD.vectorFrame[1][1]);
  
  i=0;
  w->PD.vectorScaleRowCol = XmCreateRowColumn(w->PD.vectorFrame[0][1], "PDvectorFrameRowCol1", arg, i);
  XtManageChild(w->PD.vectorScaleRowCol);
  
  i=0;
  XtSetArg(arg[i], XmNminimum, 0); i++;
  XtSetArg(arg[i], XmNmaximum, 500); i++;
  XtSetArg(arg[i], XmNdecimalPoints, 2); i++;
  XtSetArg(arg[i], XmNshowValue, False); i++;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->PD.vectorScaleScale = XmCreateScale(w->PD.vectorScaleRowCol, "PDvectorScaleScale", arg, i);
  XtManageChild(w->PD.vectorScaleScale);
  
  i=0;
  w->PD.vectorScaleText = XmCreateTextField(w->PD.vectorScaleRowCol, "PDvectorScaleText", arg, i);
  XtManageChild(w->PD.vectorScaleText);

  /* vector - location */

  i=0;
  w->PD.vectorFrame[0][2] = XmCreateFrame(w->PD.vectorRowCol, "ODvectorFrame02", arg, i);
  XtManageChild(w->PD.vectorFrame[0][2]);
  
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Location")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.vectorFrame[1][2] = XmCreateLabel(w->PD.vectorFrame[0][2], "PDvectorFrame12", arg, i);
  XtManageChild(w->PD.vectorFrame[1][2]);

  i=0;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  w->PD.vectorLocationCheck = XmCreateRadioBox(w->PD.vectorFrame[0][2], "PDvectorLocationCheck", arg, i);
  XtManageChild(w->PD.vectorLocationCheck);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("COG")); i++;
  w->PD.vectorLocationButt[0] = XmCreateToggleButton(w->PD.vectorLocationCheck, "PDvectorLocationButt0", arg, i);
  XtManageChild(w->PD.vectorLocationButt[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Vertex")); i++;
  w->PD.vectorLocationButt[1] = XmCreateToggleButton(w->PD.vectorLocationCheck, "PDvectorLocationButt1", arg, i);
  XtManageChild(w->PD.vectorLocationButt[1]);


  /* export BGM  */
  i=0 ;
  XtSetArg(arg[i], XmNdialogTitle, XmStringCreateSimple("Export BGM")); i++;
  XtSetArg(arg[i], XmNnoMatchString, XmStringCreateSimple("[ NONE ]")); i++;
  XtSetArg(arg[i], XmNdirMask, XmStringCreateSimple("*")); i++;
  XtSetArg(arg[i], XmNautoUnmanage, True); i++;
  w->PD.exportBGMDialog = XmCreateFileSelectionDialog(w->M.shell, "FDexportBGMDialog", arg, i);
  XtUnmanageChild(w->PD.exportBGMDialog);

  tmp = XmFileSelectionBoxGetChild(w->PD.exportBGMDialog, XmDIALOG_HELP_BUTTON);
  XtUnmanageChild(tmp);

  i=0;
  w->PD.exportBGMFrame[0] = XmCreateFrame(w->PD.exportBGMDialog, "FDexportBGMFrame0", arg, i);
  XtManageChild(w->PD.exportBGMFrame[0]);

  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("Options")); i++;
  XtSetArg(arg[i], XmNchildType, XmFRAME_TITLE_CHILD); i++;
  w->PD.exportBGMFrame[1] = XmCreateLabel(w->PD.exportBGMFrame[0], "FDexportBGMFrame1", arg, i);
  XtManageChild(w->PD.exportBGMFrame[1]);

  i=0 ;
  XtSetArg(arg[i], XmNorientation, XmHORIZONTAL); i++;
  XtSetArg(arg[i], XmNspacing, 0); i++;
  w->PD.exportBGMRowCol = XmCreateRowColumn(w->PD.exportBGMFrame[0], "FDexportBGMRowCol", arg, i);
  XtManageChild(w->PD.exportBGMRowCol);

  /* export BGM - method */
  i=0;
  w->PD.exportBGMPane = XmCreatePulldownMenu(w->PD.exportBGMRowCol, "FDexportBGMPane", arg, i);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("h: error (%)")); i++;
  w->PD.exportBGMButt[0] = XmCreatePushButton(w->PD.exportBGMPane, "MexportBGMButt0", arg, i);
  XtManageChild(w->PD.exportBGMButt[0]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("h: elements")); i++;
  w->PD.exportBGMButt[1] = XmCreatePushButton(w->PD.exportBGMPane, "MexportBGMButt1", arg, i);
  XtManageChild(w->PD.exportBGMButt[1]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("p: error (%)")); i++;
  w->PD.exportBGMButt[2] = XmCreatePushButton(w->PD.exportBGMPane, "MexportBGMButt2", arg, i);
  XtManageChild(w->PD.exportBGMButt[2]);
  i=0;
  XtSetArg(arg[i], XmNlabelString, XmStringCreateSimple("p: elements")); i++;
  w->PD.exportBGMButt[3] = XmCreatePushButton(w->PD.exportBGMPane, "MexportBGMButt3", arg, i);
  XtManageChild(w->PD.exportBGMButt[3]);
  i=0;
  XtSetArg(arg[i], XmNsubMenuId, w->PD.exportBGMPane); i++;
  XtSetArg(arg[i], XmNspacing, 0); i++;
  w->PD.exportBGMMenu = XmCreateOptionMenu(w->PD.exportBGMRowCol, "FDexportBGMMenu", arg, i);
  XtManageChild(w->PD.exportBGMMenu);

  /* export BGM - constraint */
  i=0;
  w->PD.exportBGMText = XmCreateTextField(w->PD.exportBGMRowCol, "FDexportBGMText", arg, i);
  XtManageChild(w->PD.exportBGMText);

  
}



/* ------------------------------------------------------------------------ 
    C r e a t e W i d g e t s
   ------------------------------------------------------------------------ */

void CreateWidgets (Widgets_T *w){
  CreateWidgets_M(w); /* menu win */
  CreateWidgets_G(w); /* graphic win */
  if(CTX.command_win) CreateWidgets_C(w); /* command win */

  CreateWidgets_ED(w); /* error dialogs */
  CreateWidgets_FD(w); /* file dialogs */
  CreateWidgets_OD(w); /* option dialogs */
  CreateWidgets_HD(w); /* help dialogs */
  CreateWidgets_GD(w); /* geometry dialogs */
  CreateWidgets_MD(w); /* mesh dialogs */
  CreateWidgets_PD(w); /* post dialogs */
}



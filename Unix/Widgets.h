/* $Id: Widgets.h,v 1.10 2000-12-20 12:17:13 geuzaine Exp $ */
#ifndef _WIDGETS_H_
#define _WIDGETS_H_

#define NB_BUTT_MAX  50 

/* check Info.h */
#define NB_INFO_GEOM   4
#define NB_INFO_MESH   14
#define NB_INFO_POST   5
#define NB_INFO_MAX    23

/* Holder for all Widgets */

typedef struct {

  /* menu window */

  struct {
    Widget   shell, containerWin ; 
    Widget   menuBar ;
    Widget     fileCascade, filePane, fileButt[10], fileSep[3] ;
    Widget     moduleCascade, modulePane, moduleButt[3] ;
    Widget     optionCascade, optionPane, optionButt[6], optionSep[2] ;
    Widget     helpCascade, helpPane, helpButt[2], helpSep[1] ;
    Widget   menuFrame, menuForm ;
    Widget     modButt, modPop, geomButt, meshButt, postButt ;
    Widget     navigButt[2]; 
    Widget     defaultButt ;
    Widget     pushButt     [NB_BUTT_MAX] ;
    Widget     toggleButt   [NB_BUTT_MAX] ;
    Widget     popMenu      [NB_BUTT_MAX] ;
    Widget     popSep    [3][NB_BUTT_MAX] ;
    Widget     lightButt    [NB_BUTT_MAX] ;
    Widget     elementButt  [NB_BUTT_MAX] ;
    Widget     offsetButt   [NB_BUTT_MAX] ;
    Widget     timeStepButt [NB_BUTT_MAX] ;
    Widget     scaleButt    [NB_BUTT_MAX] ;
    Widget     colorButt    [NB_BUTT_MAX] ;
    Widget     vectorButt   [NB_BUTT_MAX] ;
    Widget     exportBGMButt[NB_BUTT_MAX] ;
    Widget     applyBGMButt [NB_BUTT_MAX] ;
    Widget     reloadButt   [NB_BUTT_MAX] ;
    Widget     removeButt   [NB_BUTT_MAX] ;
    Widget     duplicateButt[NB_BUTT_MAX] ;
  } M;

  /* graphic window */

  struct {
    Widget   shell, containerForm ;
    Widget   drawForm ;
    Widget     glw, glo ; 
    Widget   bottomForm ;
    Widget     Butt[7] ;
    Widget     textForm, infoLabel, selectLabel, statusLabel ;
  } G;

  /* command window */

  struct {
    Widget   shell ;
    Widget   command, commandList, commandText ; 
  } C;


  /* error dialogs */

  struct {
    Widget   saveAsDialog ;
  } ED;

  /* file dialogs */

  struct {
    Widget   openDialog ;
    Widget   mergeDialog ;
    Widget   saveAsDialog ;
    Widget     saveAsFrame[2], saveAsRowCol ;
    Widget     saveAsPane[3], saveAsButt[20], saveAsMenu[3] ;
    Widget   saveOptionsAsDialog ;
  } FD;

  /* options dialogs */

  struct {
    Widget   geomDialog, geomRowCol ;
    Widget   geomVisibleFrame[2], geomVisibleRowCol ;
    Widget     geomVisibleTypeCheck, geomVisibleTypeButt[2] ;
    Widget     geomVisibleCheck, geomVisibleButt[4] ;
    Widget   geomVisibleByNumFrame[2], geomVisibleByNumRowCol ;
    Widget     geomVisibleByNumText ;
    Widget   geomNormalsFrame[2], geomNormalsRowCol ;
    Widget     geomNormalsScale, geomNormalsText ;
    Widget   geomTangentsFrame[2], geomTangentsRowCol ;
    Widget     geomTangentsScale, geomTangentsText ;

    Widget   meshDialog, meshRowCol;
    Widget   meshAlgoFrame[2], meshAlgoRowCol  ;
    Widget     meshAlgoCheck, meshAlgoButt[4] ;
    Widget   meshSmoothingFrame[2], meshSmoothingRowCol  ;
    Widget     meshSmoothingScale, meshSmoothingText ;
    Widget   meshVisibleFrame[2], meshVisibleRowCol ;
    Widget     meshVisibleTypeCheck, meshVisibleTypeButt[2] ;
    Widget     meshVisibleCheck, meshVisibleButt[4] ;
    Widget   meshVisibleByNumFrame[2], meshVisibleByNumRowCol ;
    Widget     meshVisibleByNumCheck, meshVisibleByNumButt[4];
    Widget     meshVisibleByNumText ;
    Widget   meshAspectFrame[2] ;
    Widget     meshAspectCheck, meshAspectButt[3] ;
    Widget   meshExplodeFrame[2], meshExplodeRowCol ;
    Widget     meshExplodeScale, meshExplodeText ;
    Widget   meshNormalsFrame[2], meshNormalsRowCol ;
    Widget     meshNormalsScale, meshNormalsText ;

    Widget   postDialog, postRowCol;
    Widget   postLinkFrame[2], postLinkRowCol  ;
    Widget     postLinkCheck, postLinkButt[3] ;
    Widget   postAnimFrame[2] ;
    Widget     postAnimFrameRowCol, postAnimScale ;

    Widget   miscDialog, miscRowCol ; 
    Widget   miscMiscFrame[2] ;
    Widget     miscMiscCheck, miscMiscButt[6] ;
    Widget   miscColorSchemeFrame[2] ;
    Widget     miscColorSchemeFrameRowCol, miscColorSchemeScale ;
    Widget   miscProjFrame[2] ;
    Widget     miscProjCheck, miscProjButt[2] ;
    Widget   miscLightFrame[2] ;
    Widget     miscLightFrameRowCol, miscLightScale[3] ;
    Widget   miscShineFrame[2] ;
    Widget     miscShineFrameRowCol, miscShineScale ;

    Widget   viewportDialog, viewportRowCol ;
    Widget     viewportFrame[2][3], viewportFrameRowCol[3] ;
    Widget     viewportText[3][3], viewportLockButt[3][3] ;

    Widget   infoDialog, infoRowCol ;
    Widget     infoFrame[2][3], infoFrameRowCol[3] ;
    Widget     infoKeyLabel[NB_INFO_MAX], infoValueLabel[NB_INFO_MAX] ;

  } OD;

  /* help dialogs */

  struct {
    Widget   keysDialog, keysText ;

    Widget   aboutDialog ;
  } HD;

  /* geometry dialogs */

  struct {
    Widget   paramDialog, paramRowCol ;
    Widget   paramFrame[2][2], paramFrameRowCol[2], paramText[2] ;

    Widget   pointDialog, pointRowCol ;
    Widget   pointFrame[2][2], pointFrameRowCol[2], pointText[4] ;

    Widget   rotDialog, rotRowCol ;
    Widget   rotFrame[2][3], rotFrameRowCol[3], rotText[7] ;
    
    Widget   tranDialog ;
    Widget   tranFrame[2], tranFrameRowCol, tranText[3] ;

    Widget   dilatDialog, dilatRowCol ;
    Widget   dilatFrame[2][2], dilatFrameRowCol[2], dilatText[4] ;

    Widget   symmDialog, symmRowCol ;
    Widget   symmFrame[2], symmFrameRowCol, symmText[4] ;
  } GD;

  /* mesh dialogs */

  struct {
    Widget   charLengthDialog ;
    Widget   charLengthFrame[2], charLengthFrameRowCol, charLengthText ;

    Widget   trsfLineDialog, trsfLineRowCol ;
    Widget   trsfLineFrame[2][2], trsfLineFrameRowCol[2], trsfLineText[2] ;

    Widget   trsfVolumeDialog ;
    Widget   trsfVolumeFrame[2], trsfVolumeFrameRowCol, trsfVolumeText ;
  } MD;

  /* post dialogs */

  struct {
    Widget   offsetDialog, offsetRowCol ;
    Widget   offsetFrame[2][4], offsetFrameRowCol[4] ;
    Widget   /* 1 */ offsetModeCheck, offsetModeButt[2] ;
    Widget   /* 2 */ offsetText[3], offsetScale[3] ;
    
    Widget   timeStepDialog ;
    Widget   timeStepFrame[2], timeStepFrameRowCol ;
    Widget   timeStepText, timeStepScale ;
    
    Widget   scaleDialog, scaleRowCol ;
    Widget   scaleFrame[2][4], scaleFrameRowCol[4] ;
    Widget   /* 1 */ scaleCheck, scaleShowButt, scaleTransButt, scaleTimeButt, scaleText[2] ;
    Widget   /* 2 */ scaleRangeButt, scaleRangeText[2], scaleTypeCheck, 
                     scaleTypeButt[2] ;
    Widget   /* 3 */ scaleIntervalsCheck, scaleIntervalsButt[4], 
                     scaleIntervalsScale, scaleIntervalsText ;

    Widget   colorDialog, colorRowCol ;
    Widget   colorFrame[2][4] ;
    Widget   /* 1 */ colorDrawingArea ;

    Widget   vectorDialog, vectorRowCol ;
    Widget   vectorFrame[2][3];
    Widget   /* 1 */ vectorTypeCheck, vectorTypeButt[5];
    Widget   /* 2 */ vectorScaleRowCol, vectorScaleScale, vectorScaleText ;
    Widget   /* 3 */ vectorLocationCheck, vectorLocationButt[2];

    Widget   exportBGMDialog ;
    Widget   exportBGMFrame[2], exportBGMRowCol ;
    Widget   exportBGMPane, exportBGMButt[4], exportBGMMenu ;
    Widget   exportBGMText ;
  } PD;


  /* tooltips */    

  struct {
    Widget   shell; 
    Widget   tooltip_lbl;
  } tooltip;


} Widgets_T;



void CreateWidgets(Widgets_T *w);

#endif


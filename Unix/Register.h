#ifndef _REGISTER_H_
#define _REGISTER_H_

void InitCb(Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *cb);
void ResizeCb(Widget w,XtPointer client_data, GLwDrawingAreaCallbackStruct *cb);
void ExposeCb(Widget w,XtPointer client_data, GLwDrawingAreaCallbackStruct *cb);

void RegisterCallbacks(Widgets_T *w);

void ActualizeContextCb (Widget w, XtPointer client_data, XtPointer call_data);

void ExposeCb(Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *call_data);
void InitCb  (Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *call_data);
void InputCb (Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *call_data);
void ResizeCb(Widget w, XtPointer client_data, GLwDrawingAreaCallbackStruct *call_data);

void ColorBarResizeCb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cb);
void ColorBarExposeCb(Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cb);
void ColorBarInputCb (Widget w, XtPointer client_data, XmDrawingAreaCallbackStruct *cb);

void ExitCb             (Widget w, XtPointer client_data, XtPointer call_data);
void ManageCb           (Widget w, XtPointer client_data, XtPointer call_data);
void PreviousContextCb  (Widget w, XtPointer client_data, XtPointer call_data);
void NextContextCb      (Widget w, XtPointer client_data, XtPointer call_data);
void ActualizeContextCb (Widget w, XtPointer client_data, XtPointer call_data);
void DrawAboutCb        (Widget w, XtPointer client_data, XtPointer call_data);
void CurrentInfoCb      (Widget w, XtPointer client_data, XtPointer call_data);
void CurrentViewportCb  (Widget w, XtPointer client_data, XtPointer call_data);
void CurrentViewCb      (Widget w, XtPointer client_data, XtPointer call_data);
void SwapViewCb         (Widget w, XtPointer client_data, XtPointer call_data);
void DuplicateViewCb    (Widget w, XtPointer client_data, XtPointer call_data);
void ReloadViewCb       (Widget w, XtPointer client_data, XtPointer call_data);
void ReloadAllViewsCb   (Widget w, XtPointer client_data, XtPointer call_data);
void RemoveViewCb       (Widget w, XtPointer client_data, XtPointer call_data);
void RemoveAllViewsCb   (Widget w, XtPointer client_data, XtPointer call_data);

void OptionsCb          (Widget w, XtPointer client_data, XtPointer call_data);
void FileCb             (Widget w, XtPointer client_data, XtPointer call_data);
void GeomCb             (Widget w, XtPointer client_data, XtPointer call_data);
void MeshCb             (Widget w, XtPointer client_data, XtPointer call_data);
void PostDialogCb       (Widget w, XtPointer client_data, XtPointer call_data);
void PostCb             (Widget w, XtPointer client_data, XtPointer call_data);

void PopupHandler       (Widget w, Widget pw, XEvent *event, Boolean *ctd);


/* special GL callback registering */

#define register_GLexpose_cb(w, func, arg)                      \
        XtAddCallback((w), GLwNexposeCallback,                  \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      
                                                        
#define register_GLresize_cb(w, func, arg)                      \
        XtAddCallback((w), GLwNresizeCallback,                  \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      

#define register_GLinput_cb(w, func, arg)                       \
        XtAddCallback((w), GLwNinputCallback,                   \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      
                                                        
#define register_GLinit_cb(w, func, arg)                        \
        XtAddCallback((w), GLwNginitCallback,                   \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      
                                                        
/* classic motif callback registering */
                                                        
#define register_help_cb(w, func, arg)                          \
        XtAddCallback((w), XmNhelpCallback,                     \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      

#define register_expose_cb(w, func, arg)                        \
        XtAddCallback((w), XmNexposeCallback,                   \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      
                                                        
#define register_resize_cb(w, func, arg)                        \
        XtAddCallback((w), XmNresizeCallback,                   \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      

#define register_input_cb(w, func, arg)                         \
        XtAddCallback((w), XmNinputCallback,                    \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      
                                                        
#define register_activate_cb(w, func, arg)                      \
        XtAddCallback((w), XmNactivateCallback,                 \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      

#define register_remove_cb(w, func, arg)                        \
        XtRemoveCallback((w), XmNactivateCallback,              \
                (XtCallbackProc) (func),                        \
                (XtPointer) (arg))                      

#define register_activate_cb_list(w, list)              \
        XtAddCallbacks((w), XmNactivateCallback,        \
                (XtCallbackList)(list))

#define register_valchg_cb(w, func, arg)                \
        XtAddCallback((w), XmNvalueChangedCallback,     \
                (XtCallbackProc) (func),                \
                (XtPointer) (arg))

#define register_valchg_cb_list(w, list)                \
        XtAddCallbacks((w), XmNvalueChangedCallback,    \
                (XtCallbackList)(list))

#define register_ok_cb(w, func, arg)            \
        XtAddCallback((w), XmNokCallback,       \
                (XtCallbackProc) (func),        \
                (XtPointer) (arg))

#define register_cancel_cb(w, func, arg)        \
        XtAddCallback((w), XmNcancelCallback,   \
                (XtCallbackProc) (func),        \
                (XtPointer) (arg))

#define register_apply_cb(w, func, arg) \
        XtAddCallback((w), XmNapplyCallback,    \
                (XtCallbackProc) (func),        \
                (XtPointer) (arg))

#define register_drag_cb(w, func, arg)          \
        XtAddCallback((w), XmNdragCallback,     \
                (XtCallbackProc) (func),        \
                (XtPointer) (arg))

/* event loop  */

#define register_popup_ev(parent, w)                            \
        XtAddEventHandler((parent), ButtonPressMask,            \
                          False,                                \
                          (XtEventHandler)PopupHandler, \
                          (XtPointer)(w))

#endif

/* $Id: CbPost.h,v 1.4 2000-11-26 15:43:48 geuzaine Exp $ */
#ifndef _CB_POST_H_
#define _CB_POST_H_

#define  POST_LINK                                 1
#define  POST_OFFSET                               2
#define  POST_TIME_STEP                            3
#define  POST_SCALE                                4
#define  POST_VECTOR                               5
#define  POST_EXPORT_BGM                           6
#define  POST_APPLY_BGM                            7
#define  POST_LIGHT                                8
#define  POST_COLOR                                9
#define  POST_ELEMENT                              10

#define  POST_OFFSET_TRANSLATE                     403
#define  POST_OFFSET_RAISE                         404
#define  POST_OFFSET_X_TEXT                        405
#define  POST_OFFSET_Y_TEXT                        406
#define  POST_OFFSET_Z_TEXT                        407
#define  POST_OFFSET_X_SCALE                       408
#define  POST_OFFSET_Y_SCALE                       409
#define  POST_OFFSET_Z_SCALE                       410

#define  POST_TIME_STEP_TEXT                       417
#define  POST_TIME_STEP_SCALE                      418

#define  POST_SCALE_SHOW                           421
#define  POST_SCALE_TRANSPARENCY                   422
#define  POST_SCALE_FORMAT                         423
#define  POST_SCALE_LABEL                          424
#define  POST_SCALE_FORCE_RANGE                    425
#define  POST_SCALE_MIN                            426
#define  POST_SCALE_MAX                            427
#define  POST_SCALE_TYPE_LIN                       428
#define  POST_SCALE_TYPE_LOG                       429
#define  POST_SCALE_INTERVALS_TYPE_ISO             430
#define  POST_SCALE_INTERVALS_TYPE_DISCRETE        431
#define  POST_SCALE_INTERVALS_TYPE_CONTINUOUS      432
#define  POST_SCALE_INTERVALS_TYPE_NUMERIC         433
#define  POST_SCALE_INTERVALS_SCALE                434
#define  POST_SCALE_INTERVALS_TEXT                 435
#define  POST_SCALE_TIME                           436

#define  POST_COLOR_REPLOT                         440

#define  POST_VECTOR_TYPE_SEGMENT                  450
#define  POST_VECTOR_TYPE_ARROW                    451
#define  POST_VECTOR_TYPE_PYRAMID                  452
#define  POST_VECTOR_TYPE_CONE                     453
#define  POST_VECTOR_TYPE_DISPLACEMENT             454
#define  POST_VECTOR_SCALE_TEXT                    455
#define  POST_VECTOR_SCALE_SCALE                   456
#define  POST_VECTOR_LOCATION_COG                  457
#define  POST_VECTOR_LOCATION_VERTEX               458
                                                    
#define  POST_EXPORT_BGM_METHOD_H_ERROR            461
#define  POST_EXPORT_BGM_METHOD_H_ELEMENTS         462
#define  POST_EXPORT_BGM_METHOD_P_ERROR            463
#define  POST_EXPORT_BGM_METHOD_P_ELEMENTS         464
#define  POST_EXPORT_BGM_CONSTRAINT                465
#define  POST_EXPORT_BGM_CREATE                    466

void MarkAllViewsChanged (int action);

#endif

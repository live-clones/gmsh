
DefineConstant[ Val_Rint = {0.15, Min 0.2, Max 1, Step 0.1,
                            Path "Parameters/Geometry/1",
                            Label "Internal shell radius (m)"} ];

DefineConstant[ Val_Rext = {0.25, Min Val_Rint, Max 0.5, Step 0.1,
                            Path "Parameters/Geometry/2",
                            Label "External shell radius (m)"}];

AIR = 100;
AIR_INF = 101;
AIR_GAP = 102;
MAGNET = 103;
CORE = 104;
LINE_INF = 105;
LINE_X = 106;

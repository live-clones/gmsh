
View "ten_segment_bar" {
VL(0.0,0.0,0.0,0.1,0.0,0.0){0,0.00,0, 0,0.31,0};
VL(0.1,0.0,0.0,0.2,0.0,0.0){0,0.31,0, 0,0.59,0};
VL(0.2,0.0,0.0,0.3,0.0,0.0){0,0.59,0, 0,0.81,0};
VL(0.3,0.0,0.0,0.4,0.0,0.0){0,0.81,0, 0,0.95,0};
VL(0.4,0.0,0.0,0.5,0.0,0.0){0,0.95,0, 0,0.99,0};
VL(0.5,0.0,0.0,0.6,0.0,0.0){0,0.99,0, 0,0.95,0};
VL(0.6,0.0,0.0,0.7,0.0,0.0){0,0.95,0, 0,0.81,0};
VL(0.7,0.0,0.0,0.8,0.0,0.0){0,0.81,0, 0,0.59,0};
VL(0.8,0.0,0.0,0.9,0.0,0.0){0,0.59,0, 0,0.31,0};
VL(0.9,0.0,0.0,1.0,0.0,0.0){0,0.31,0, 0,0.00,0};
};

// bounding boxes are only computes when a new point is added, or
// after a file is merged. Neither happened here, so we need to force
// it.
BoundingBox;

nFrames = 100;
nIter   = 2 ;
For iter In {1:nIter}
    For frame In {1:nFrames}
        View[0].DisplacementFactor = Sin(2*Pi*frame/nFrames);
        View[0].VectorType = 5;
        Sleep 0.01;
        Draw;
    EndFor
EndFor

Delete View[0];

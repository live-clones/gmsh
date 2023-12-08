Include "../../tutorials/t5.geo";

// split window 50%-50% horizontally and change the rotation;
// rotation/translation/scale options are applied to the current subwindow (the
// last one created)
SplitCurrentWindowHorizontal 0.5;
General.Trackball = 0;
General.RotationX = -90;
General.RotationY = 0;
General.RotationZ = -90;

// split the current subwindow into two parts, vertically and change the
// rotation
SplitCurrentWindowVertical 0.5;
General.RotationX = -90;
General.RotationY = 0;
General.RotationZ = 180;

// change the current window to the original one (subwindows are indexed
// starting from 0; new subwindows created by splitCurrentWindow() are appended
// at the end), and adjust rotation
SetCurrentWindow 0;
General.RotationX = -75;
General.RotationY = 25;

// mesh the model
Mesh 2;

// redraw
Draw;

// save all subwindows into a composite PNG
Print.CompositeWindows = 1;
Save "img_composite.png";

// restore single window and print it
UnsplitWindow;
Save "img_single.png";

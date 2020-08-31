Include "../../tutorial/t5.geo";

// split 50%-50% horizontally
SplitCurrentWindowHorizontal 0.5;

// set the right subwindow (subwindows are indexed starting from 0; new
// subwindows created by Split are appended at the end) as current window
SetCurrentWindow 1;

// rotation/translation/scale options are applied to the current subwindow
General.Trackball = 0;
General.RotationX = -90;
General.RotationY = 0;
General.RotationZ = -90;

// split the current subwindow into two parts, vertically
SplitCurrentWindowVertical 0.5;

// set the newly created subwindow as the current one and change rotation
SetCurrentWindow 2;
General.RotationX = -90;
General.RotationY = 0;
General.RotationZ = 180;

// mesh the model
Mesh 2;

// redraw
Draw;

// save all subwindows into a composite PNG
Print.CompositeWindows = 1;
Save "img.png";

// restore single window
UnsplitWindow;

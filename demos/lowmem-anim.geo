// Define some general options

General.Trackball = 0; // use Euler angles
General.RotationX = 30;
General.RotationY = 10;
General.RotationZ = -15;

// One can use View.XXX instead of View[YYY].XXX to define general
// View options!

View.ShowElement = 1;
View.ColorTable = {Red,Green,Blue};

// Let's load the views one by one:

For i In {1:4}

  If (i==1)
    // we force the bounding box to be the one of the first view:
    MergeWithBoundingBox "../tutorial/view1.pos";
  EndIf
  If (i>1)
    // we merge the other views using the same bounding box as the
    // first one:
    Merge Sprintf("../tutorial/view%g.pos",i);
  EndIf

  Draw;

  Print Sprintf("out%g.png",i);

  // and we delete the view:
  Delete View[0];

EndFor

// Why do we have to play such a game with the bounding box? 

// If you don't load a geometry or a mesh at the same time as the
// views, the bounding box is only computed at the end of the loading
// of the main model file (the .geo). This is because a view should
// normally NOT affect the bounding box of a scene, except if the .geo
// file is indeed a view... So, without the MergeWithBoundingBox, the
// bounding box is indeed undefined (well, set to some stupid default
// value) when we want to draw our views (since this happens before
// the main file (the script) is completely read)...

// One solution would be to define dummy geometry points in the
// script. This is not general since we may not know beforehand the
// bounding box of the view. The correct way to handle this is to use
// MergeWithBounding box, which forces the computation of the bounding
// box.

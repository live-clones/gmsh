@format
@code{
/********************************************************************* 
 *
 *  Gmsh tutorial 9
 * 
 *  Post-Processing, Plugins
 *
 *********************************************************************/

// Plugins can be added to Gmsh in order to extend its
// capabilities. For example, post-processing plugins can modify a
// view, or create a new view based on previously loaded
// views. Several default plugins are statically linked into Gmsh,
// e.g. CutMap, CutPlane, CutSphere, Skin, Transform or Smooth.

// Let's load a three-dimensional scalar view

Include "view3.pos" ;

// Plugins can be controlled in the same way as other options in
// Gmsh. For example, the CutMap plugin (which extracts an isovalue
// surface from a 3D scalar view) can either be called from the
// graphical interface (right click on the view button, then
// Plugins->CutMap), or from the command file:

Plugin(CutMap).A = 0.67 ; // iso-value level
Plugin(CutMap).iView = 0 ; // source view is View[0]
Plugin(CutMap).Run ; 

// The following runs the CutPlane plugin:

Plugin(CutPlane).A = 0 ; 
Plugin(CutPlane).B = 0.2 ; 
Plugin(CutPlane).C = 1 ; 
Plugin(CutPlane).D = 0 ; 
Plugin(CutPlane).Run ; 

View[0].Light = 1;
View[0].IntervalsType = 2;
View[0].NbIso = 6;
View[0].SmoothNormals = 1;

View[1].IntervalsType = 2;

View[2].IntervalsType = 2;
Draw;
}
@end format

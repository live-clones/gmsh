/*****
This example shows the possibility of inserting embedded points "by hand"
on general surfaces, including periodic ones (this was not possible before
this release.
*****/

//+
SetFactory("OpenCASCADE");
Cylinder(1) = {-0.5, 0, 0, 1, 0, 0, 0.5, 2*Pi};
//+
Point(3) = {0, .5, 0, .0001};

Point {3} In Surface {1};
//+
Point(4) = {-.5, 0, 0, .0001};
Point {4} In Surface {3};
//+
Characteristic Length {2, 1} = 0.1;

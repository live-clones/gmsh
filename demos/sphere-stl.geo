
// include an STL triangulation as the representation of the surface 1

Merge "sphere-surf.stl";

// define a volume using that surface

Surface Loop(2) = {1};
Volume(3) = {2};

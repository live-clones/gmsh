// discrete geometry: an STL triangulation classified into surfaces, with
// parametrizations and a volume
Merge "../../tutorials/t13_data.stl";
ClassifySurfaces{40 * Pi / 180, 1, 1, Pi};
CreateGeometry;
Surface Loop(1) = Surface{:};
Volume(1) = {1};
General.Trackball = 0;
General.RotationX = 300; General.RotationZ = 20;

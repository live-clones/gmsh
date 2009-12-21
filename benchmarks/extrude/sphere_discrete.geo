//Merge "sphere_boundary_layer.msh";
Merge "sphere.stl";
CreateTopology;

out[] = Extrude{
 Surface{1}; Layers{5, 0.1}; Recombine;
};

//the volume of the boundary layer is created
//with the extrusion

//here we create the volume of the inside of the sphere
Surface Loop(100)={1};
Volume(101)={100};

// Example of "Virtual topology" using mesh compounds to avoid enforcing small
// elements: see

// https://github.com/mkraska/CalculiX-Examples/tree/master/CAD/OnshapeTutorial

Merge "part.step";

Compound Curve {63,64};
Compound Curve {65,66};
Compound Surface {23,25};
Compound Surface {9,24,26};
Compound Surface {21};
Compound Surface {22};

// Set definitions
Physical Surface("support") = {5};
Physical Surface("load") = {17};
Physical Volume("part") = {1};

// Mesh control and meshing
Mesh.CharacteristicLengthMax = 7;

classif = DefineNumber[1, Choices{0,1},
  Name "Parameters/Magic reclassification on original surfaces?"];
order = DefineNumber[1, Choices{1="First order",2="Second order"},
  Name "Parameters/Element order"];

Mesh.CompoundClassify = classif;
Mesh.ElementOrder = order;
Mesh.HighOrderOptimize = 1;

// refine the mesh of the compound parts to improve the geometrical location of
// compound mesh nodes (which are located on the *mesh* of the compound parts)
Mesh.CompoundCharacteristicLengthFactor = 0.3;

If(classif && order > 1)
  Error("High-order mesh not compatible with magic reclassification :-)");
EndIf

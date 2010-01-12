Merge "car_body.stl";

ll = 0.1; // antenna length
lc1 = ll / 10; // element size on antenna

p1 = newp;
Point(p1) = { -0.000210105 , 0.000769998 , 1.30307 , lc1 };
p2 = newp;
Point(p2) = { -0.000210105 , 0.000769998 , 1.30307 + ll , lc1 };
l1 = newl;
Line(l1) = { p1 , p2 }; 

Mesh 2;
Coherence Mesh;
Save "car_body_with_antenna.msh";

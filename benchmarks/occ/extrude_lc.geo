SetFactory("Built-in");
p1 = newp;
Point(p1) = { 0, 0, 0.0, 1 };
p2 = newp;
Point(p2) = { 10, 0, 0.0, 2 };
l1 = newl;
Line(l1) = { p1, p2 };
s1 = news;
out[] = Extrude { 0, 15, 0} {Line{ l1 };};
s1 = out[1];
Color Yellow { Surface{ s1 }; }
View "comments" {T3(2, 18, 0, TextAttributes("Align", "Center", "Font", "Helvetica")){ "Built-in" };};

SetFactory("OpenCASCADE");
p3 = newp;
Point(p3) = { 15, 0, 0.0, 1 };
p4 = newp;
Point(p4) = { 25, 0, 0.0, 2 };
l2 = newl;
Line(l2) = { p3, p4 };
s2 = news;
out[] = Extrude { 0, 15, 0} {Line{ l2 };};
s2 = out[1];
Color LightYellow { Surface{ s2 }; }
View "comments" {T3(20, 18, 0, TextAttributes("Align", "Center", "Font", "Helvetica")){ "OpenCASCADE" };};

//Mesh 2;

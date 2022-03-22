SetFactory("OpenCASCADE");
p1 = newp; Point(p1) = {0, 0, 0};
l[] = Extrude{1, 0, 0} { Point{p1}; Layers{10}; };

s[] = Extrude{0, 1, 0} { Line{l[1]};
  Layers{10}; Recombine;
};

// explicit periodic constraint to store node correspondence on the extruded
// entity, even for a structured mesh
Periodic Line{s[0]} = {l[1]} Translate{0, 1, 0};

SetFactory("OpenCASCADE");
Sphere(1) = {0,0,0, 1};
b() = Parametric BoundingBox Surface{1};

For t In {0 : 1 : 0.25/2}
  u = b(0) + t * (b(2) - b(0));
  //v = b(1) + t * (b(3) - b(1));
  v = (b(1) + b(3)) / 2;
  n() = Normal Surface{1} Parametric{u, v};
  Printf("uv=(%g,%g) normal=(%g,%g,%g) ", u, v, n(0), n(1), n(2));
EndFor

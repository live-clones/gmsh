SetFactory("OpenCASCADE");

Sphere(1) = {0,0,0, 1};

// get parameter bounds of surface 1
b() = Parametric BoundingBox Surface{1};

// evaluate normal to surface 1 for a few parameter values
For t In {0 : 1 : 0.25/2}
  u = b(0) + t * (b(2) - b(0));
  v = (b(1) + b(3)) / 2;
  n() = Normal Surface{1} Parametric{u, v};
  Printf("sphere uv=(%g,%g) normal=(%g,%g,%g) ", u, v, n(0), n(1), n(2));
EndFor

// evaluate normal to surface 2 at one corner point
Rectangle(2) = {2,0,0, 1, 1};
uv() = Parametric Point{4} In Surface{2};
n() = Normal Surface{2} Parametric{uv(0), uv(1)};
Printf("rectangle uv=(%g,%g) normal=(%g,%g,%g) ", uv(0), uv(1), n(0), n(1), n(2));

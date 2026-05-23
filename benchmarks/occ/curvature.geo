SetFactory("OpenCASCADE");
Sphere(1)={0,0,0,2};
c0 = Curvature Curve{2} Parametric{0.1};
c1 = Curvature Curve{2} Parametric{0.2};
c2 = Curvature Surface{1} Parametric{0.23, 1.65};
Printf("Curvatures: %g %g %g", c0, c1, c2);

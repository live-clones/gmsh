// Delete with the discrete CAD modeler: a volume alone, a volume with the
// surfaces no other volume uses (Recursive), a surface that bounds no volume
// (with its curves and points); a surface that bounds a volume is left alone
SetFactory("Discrete");

Box(1) = {0, 0, 0, 1, 1, 1};
Sphere(2) = {3, 0, 0, 0.5};
Rectangle(10) = {0, 3, 0, 1, 1};

Macro Check
  v() = Volume{:}; s() = Surface{:}; c() = Curve{:};
  If(#v() != nv || #s() != ns || #c() != nc)
    Error("%g volumes, %g surfaces and %g curves instead of %g, %g and %g",
          #v(), #s(), #c(), nv, ns, nc);
  EndIf
Return

nv = 2; ns = 9; nc = 18;
Call Check;

Delete { Surface{1}; }
Call Check;

Recursive Delete { Volume{2}; }
nv = 1; ns = 7; nc = 16;
Call Check;

Delete { Surface{10}; }
ns = 6; nc = 12;
Call Check;

Delete { Volume{1}; }
nv = 0;
Call Check;

Mesh.MeshSizeMax = 0.2;

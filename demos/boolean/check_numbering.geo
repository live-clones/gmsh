SetFactory("OpenCASCADE");

DefineConstant[
  w = {0.05, Name "Width"}
  N = {10, Name "Number of disks"}
  R = {0.002, Name "Disk radius"}
];

Rectangle(1) = {-3*w, w, 0, 6*w, w, 0};
Rectangle(2) = {-3*w, 0., 0, w, w, 0};
Translate {2*w, 0, 0} { Duplicata { Surface{2}; } }
Translate {w, 0, 0} { Duplicata { Surface{3}; } }
Translate {2*w, 0, 0} { Duplicata { Surface{4}; } }

Rectangle(6) = {-6*w, 0, 0, 12*w, 5*w, 0};

b() = {};
For i In {1:N}
  s = news; b() += s; Disk(s) = {-w-R, 2*R*i, 0, R};
EndFor

Printf("disk tags: ", b());

c() = BooleanFragments{ Surface{1:6}; Delete; }{ Surface{b()}; Delete; };

Printf("all tags (disk tags should be unchanged!): ", c());

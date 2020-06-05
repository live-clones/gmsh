SetFactory("OpenCASCADE");
r=1;
pC=newp; Point(pC)={0,0,0};
clearance=news;
Rectangle(clearance)={-0.5*r,-0.5*r,0,r,r};
points()+={pC};
surfaces()+=clearance;
Point{1} In Surface {1};
Extrude{0,0,1}{ Point{1}; Surface{1};
  Layers{2};
}
BooleanFragments{ Curve{:}; Delete; }{ Volume{:}; Delete; }

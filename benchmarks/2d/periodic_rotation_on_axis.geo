p01=newp; Point(p01) = {0, 0, 0};
p1=newp; Point(p1) = {0.0005, 0, 0};
p1b=newp; Point(p1b) = {0.0005*Cos(2*Pi/3), 0.0005*Sin(2*Pi/3), 0};
p02=newp; Point(p02) = {0, 0, 0.0008};
p2=newp; Point(p2) = {0.0005, 0, 0.0008};
p2b=newp; Point(p2b) = {0.0005*Cos(2*Pi/3), 0.0005*Sin(2*Pi/3), 0.0008};


l1=newl; Line(l1) = {p1, p2};
l1b=newl; Line(l1b) = {p1b, p2b};
l2=newl; Circle(l2)= {p1, p01, p1b};
l2b=newl; Circle(l2b)= {p2, p02, p2b};

s1=newll;
s1=news;
Line Loop(s1)= {l1, l2b, -l1b, -l2};
Surface(s1)= {s1};

l0=newl; Line(l0) = {p01, p02};

l011=newl; Line(l011) = {p01, p1};
l011b=newl; Line(l011b) = {p01, p1b};

l022=newl; Line(l022) = {p02, p2};
l022b=newl; Line(l022b) = {p02, p2b};

s2=newll;
s2=news;
Line Loop(s2)= {l0, l022, -l1, -l011};
Surface(s2)= {s2};
//Plane Surface(s2)= {s2};

s2b=newll;
s2b=news;
Line Loop(s2b)= {l0, l022b, -l1b, -l011b};
Surface(s2b)= {s2b};
//Plane Surface(s2b)= {s2b};

//Periodic Line {l1b, l011b, l022b} = {l1, l011, l022};

// Periodic Surface seems to work properly only with Surfaces (meshing problem with Plane Surface)
Periodic Surface s2b {Boundary{Surface{s2b};}} = s2 {Boundary{Surface{s2};}};

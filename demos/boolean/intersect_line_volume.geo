
SetFactory("OpenCASCADE");

Geometry.LineNumbers = 1;

xw_ = 0.1; yw_ = 0.1;
s_wire = news;
Rectangle(news) = {-xw_, -yw_, 0.,  xw_,  yw_, 0.};
l_wire[] = Abs(Boundary{Surface{s_wire};});
Delete{ Surface{s_wire}; } // Surface s_wire is deleted to keep only its boundary
Printf("init: l_wire[] = ", l_wire[]);

DefineConstant[
  flag_Symmetry_X = { 0, Choices{0,1}, Name "Symmetry X0-plane" }
  flag_Symmetry_Y = { 0, Choices{0,1}, Name "Symmetry Y0-plane" }
  flag_Symmetry_Z = { 0, Choices{0,1}, Name "Symmetry Z0-plane" }
];

dx = 0.4; dy = 0.4; dz = 0.4;
x_min_ = (flag_Symmetry_X)? 0. : -dx/2;
y_min_ = (flag_Symmetry_Y)? 0. : -dy/2;
z_min_ = (flag_Symmetry_Z)? 0. : -dz/2;

v_box=newv;
Block(newv) = {x_min_, y_min_, z_min_,  dx/2, dy/2, dz/2};


l_wire[] = BooleanIntersection { Line{l_wire[]}; Delete; }{ Volume{v_box}; };
SyncModel;
Printf("after intersection: new l_wire[] = ", l_wire[]);

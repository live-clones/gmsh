
Merge "linkrods.step";

xmin = General.MinX;
xmax = General.MaxX;
ymin = General.MinY;
ymax = General.MaxY;
zmin = General.MinZ;
zmax = General.MaxZ;

lc = 1;
l = Sqrt((xmax - xmin)^2 + (ymax - ymin)^2 + (zmax - zmin)^2) / 5;
Point(10001) = { xmin - l, ymin - l, zmin - l, lc};
Point(10002) = { xmax + l, ymin - l, zmin - l, lc};
Point(10003) = { xmax + l, ymax + l, zmin - l, lc};
Point(10004) = { xmin - l, ymax + l, zmin - l, lc};

Line(10001) = {10004, 10003};
Line(10002) = {10003, 10002};
Line(10003) = {10002, 10001};
Line(10004) = {10001, 10004};
Line Loop(10005) = {10002, 10003, 10004, 10001};
Plane Surface(10006) = {10005};
tmp[] = Extrude {0, 0, (zmax - zmin) + 2 * l} {
  Surface{10006};
};

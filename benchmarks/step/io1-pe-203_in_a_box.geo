
Merge "io1-pe-203.step";

xmin = General.MinX;
xmax = General.MaxX;
ymin = General.MinY;
ymax = General.MaxY;
zmin = General.MinZ;
zmax = General.MaxZ;

l = Sqrt((xmax - xmin)^2 + (ymax - ymin)^2 + (zmax - zmin)^2) / 5;
lc = l;

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
Extrude {0, 0, (zmax - zmin) + 2 * l} {
  Surface{10006};
}
tmp[] = Extrude {0, 0, (zmax - zmin) + 2 * l} {
  Surface{10006};
};
Delete { Volume{tmp[1]}; }

//created in the gui:
Surface Loop(10029) = {10027,10006,10015,10019,10023,10028};
Surface Loop(10030) = {21,22,23,24,25,1,2,3,27,26,6,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,28,29};
Volume(10031) = {10029,10030};


Merge "A319.brep";

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
tmp[] = Extrude {0, 0, (zmax - zmin) + 2 * l} {
  Surface{10006};
};
Delete { Volume{tmp[1]}; }

Characteristic Length{1:1000} = lc / 20;

//created in the gui:
Surface Loop(10029) = {10028,10015,10006,10019,10023,10027};
Surface Loop(10030) = {36,82,72,65,40,46,37,43,42,39,38,41,49,45,48,47,44,35,34,19,13,12,31,29,11,30,10,7,8,9,21,22,23,15,20,18,16,14,17,25,24,27,28,26,33,32,62,56,50,58,54,71,1,6,66,57,68,53,55,61,69,64,4,52,5,51,2,3,67,63,60,70,59,81,78,79,83,75,80,73,74,77,76};
Volume(10031) = {10029,10030};

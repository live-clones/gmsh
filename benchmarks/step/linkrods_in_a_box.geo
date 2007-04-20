
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

Delete { Volume{tmp[1]}; }
  	 
Surface Loop(10029) = {10027,10006,10015,10019,10023,10028}; 	 
Surface Loop(10030) = {7,9,10,11,8,6,28,26,36,15,2,4,5,12,3,1,13,24,23,14,
		       16,22,21,18,20,37,34,19,17,35,31,33,32,30,29,27,25}; 	 
Volume(10031) = {10029,10030}; 	 
  	 
//Mesh.CharacteristicLengthFactor = 0.3;

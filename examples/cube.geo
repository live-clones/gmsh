lcar1 = .0275;

length = 0.25;
height = 1.0;
depth = 0.25;

Point(newp) = {length/2,height/2,depth,lcar1}; /* Point      1 */
Point(newp) = {length/2,height/2,0,lcar1}; /* Point      2 */
Point(newp) = {-length/2,height/2,depth,lcar1}; /* Point      3 */
Point(newp) = {-length/2,-height/2,depth,lcar1}; /* Point      4 */
Point(newp) = {length/2,-height/2,depth,lcar1}; /* Point      5 */
Point(newp) = {length/2,-height/2,0,lcar1}; /* Point      6 */
Point(newp) = {-length/2,height/2,0,lcar1}; /* Point      7 */
Point(newp) = {-length/2,-height/2,0,lcar1}; /* Point      8 */
Line(1) = {3,1};
Line(2) = {3,7};
Line(3) = {7,2};
Line(4) = {2,1};
Line(5) = {1,5};
Line(6) = {5,4};
Line(7) = {4,8};
Line(8) = {8,6};
Line(9) = {6,5};
Line(10) = {6,2};
Line(11) = {3,4};
Line(12) = {8,7};
Line Loop(13) = {-6,-5,-1,11};
Plane Surface(14) = {13};
Line Loop(15) = {4,5,-9,10};
Plane Surface(16) = {15};
Line Loop(17) = {-3,-12,8,10};
Plane Surface(18) = {17};
Line Loop(19) = {7,12,-2,11};
Plane Surface(20) = {19};
Line Loop(21) = {-4,-3,-2,1};
Plane Surface(22) = {21};
Line Loop(23) = {8,9,6,7};
Plane Surface(24) = {23};

Surface Loop(25) = {14,24,-18,22,16,-20};
Complex Volume(26) = {25};

n = 21;

/*
sizex = 4;
sizey = 6;
sizez = 4;
*/
sizex = n*length;
sizey = n*height;
sizez = n*depth;

sizex = 9;
sizey = 33;
sizez = 9;


Transfinite Line {2,4,9,7} = sizez;
Transfinite Line {11,5,10,12} = sizey;
Transfinite Line {3,1,6,8} = sizex;

Transfinite Surface {14} = {5,4,3,1};
Transfinite Surface {16} = {6,2,1,5};
Transfinite Surface {18} = {6,2,7,8};
Transfinite Surface {20} = {3,7,8,4};
Transfinite Surface {22} = {3,7,2,1};
Transfinite Surface {24} = {4,8,6,5};

Recombine Surface {14,16,18,20,22,24};

Transfinite Volume {26} = {3,7,2,1,4,8,6,5};

Physical Surface(200) = {14,16,18,20,24};

Physical Volume(100) = {26};
/*
Mesh.use_cut_plane = 1;
Mesh.cut_planea = 0;
Mesh.cut_planeb = 0;
Mesh.cut_planec = 1;
Mesh.cut_planed = -0.125;
*/
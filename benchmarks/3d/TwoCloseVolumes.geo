
// this tests the ability of the Delaunay to mesh close but not
// connected volumes (should not have to change the surface mesh on
// one vol to accomodate the surface mesh on the other)


dlx = 0.01;

//Data:

x0_1 = 0.0 ; y0_1 = 0.0 ; z0_1 = 0.0 ;
lx1 = 2.0;
ly1 = 3.0;
lz1 = 4.0;

x0_2 = x0_1 + lx1 + dlx; y0_2 = 0.0 ; z0_2 = 0.0 ;
lx2 = 1.5;
ly2 = 3.0;
lz2 = 4.0;

le1 = lx1/5.0;
le2 = lx2/5.0; 

//First Volume_________________________________________________________________________________
p0 = 0; l0 = 0; ll0 = 0; ps0 = 0;
p0_1 = p0; l0_1 = l0; ll0_1 = ll0; ps0_1 = ps0;


lx = lx1; ly = ly1; lz = lz1;
x0 = x0_1; y0 = y0_1; z0 = z0_1; 
x1 = x0 + lx; y1 = y0 + ly; z1 = z0 + lz;

//Points:
Point(1+p0) = {x0, y0, z0, le1};
Point(2+p0) = {x1, y0, z0, le1} ;
Point(3+p0) = {x1, y1, z0, le1} ;
Point(4+p0) = {x0, y1, z0, le1} ;

Point(5+p0) = {x0, y0, z1, le1};
Point(6+p0) = {x1, y0, z1, le1} ;
Point(7+p0) = {x1, y1, z1, le1} ;
Point(8+p0) = {x0, y1, z1, le1} ;

//Lines:
Line(1+l0) = {1+p0,2+p0} ;
Line(2+l0) = {2+p0,3+p0} ;
Line(3+l0) = {3+p0,4+p0} ;
Line(4+l0) = {4+p0,1+p0} ;

Line(5+l0) = {5+p0,6+p0} ;
Line(6+l0) = {6+p0,7+p0} ;
Line(7+l0) = {7+p0,8+p0} ;
Line(8+l0) = {8+p0,5+p0} ;

Line(9+l0) = {1+p0,5+p0} ;
Line(10+l0) = {2+p0,6+p0} ;
Line(11+l0) = {3+p0,7+p0} ;
Line(12+l0) = {4+p0,8+p0} ;

//Line Loop:
Line Loop(1+ll0) = {-(4+l0),-(3+l0),-(2+l0),-(1+l0)} ;
Line Loop(2+ll0) = {5+l0,6+l0,7+l0,8+l0} ;
Line Loop(3+ll0) = {1+l0,10+l0,-(5+l0),-(9+l0)} ;
Line Loop(4+ll0) = {2+l0,11+l0,-(6+l0),-(10+l0)} ;
Line Loop(5+ll0) = {3+l0,12+l0,-(7+l0),-(11+l0)} ;
Line Loop(6+ll0) = {4+l0,9+l0,-(8+l0),-(12+l0)} ;


//Surfaces:
Plane Surface(1+ps0) = {1+ll0} ;
Plane Surface(2+ps0) = {2+ll0} ;
Plane Surface(3+ps0) = {3+ll0} ;
Plane Surface(4+ps0) = {4+ll0} ;
Plane Surface(5+ps0) = {5+ll0} ;
Plane Surface(6+ps0) = {6+ll0} ;

//Volume
Surface Loop(1) = {1+ps0,2+ps0,3+ps0,4+ps0,5+ps0,6+ps0} ;
Volume(1) = {1} ;


//Second Volume_________________________________________________________________________________
p0 = 8 + p0_1; l0 = 12 + l0_1; ll0 = 6 + ll0_1; ps0 = 6 + ps0_1;
p0_2 = p0; l0_2 = l0; ll0_2 = ll0; ps0_2 = ps0;


lx = lx2; ly = ly2; lz = lz2;
x0 = x0_2; y0 = y0_2; z0 = z0_2; 
x1 = x0 + lx; y1 = y0 + ly; z1 = z0 + lz;



//Points:
Point(1+p0) = {x0, y0, z0, le2};
Point(2+p0) = {x1, y0, z0, le2} ;
Point(3+p0) = {x1, y1, z0, le2} ;
Point(4+p0) = {x0, y1, z0, le2} ;

Point(5+p0) = {x0, y0, z1, le2};
Point(6+p0) = {x1, y0, z1, le2} ;
Point(7+p0) = {x1, y1, z1, le2} ;
Point(8+p0) = {x0, y1, z1, le2} ;

//Lines:
Line(1+l0) = {1+p0,2+p0} ;
Line(2+l0) = {2+p0,3+p0} ;
Line(3+l0) = {3+p0,4+p0} ;
Line(4+l0) = {4+p0,1+p0} ;

Line(5+l0) = {5+p0,6+p0} ;
Line(6+l0) = {6+p0,7+p0} ;
Line(7+l0) = {7+p0,8+p0} ;
Line(8+l0) = {8+p0,5+p0} ;

Line(9+l0) = {1+p0,5+p0} ;
Line(10+l0) = {2+p0,6+p0} ;
Line(11+l0) = {3+p0,7+p0} ;
Line(12+l0) = {4+p0,8+p0} ;

//Line loop:
Line Loop(1+ll0) = {-(4+l0),-(3+l0),-(2+l0),-(1+l0)} ;
Line Loop(2+ll0) = {5+l0,6+l0,7+l0,8+l0} ;
Line Loop(3+ll0) = {1+l0,10+l0,-(5+l0),-(9+l0)} ;
Line Loop(4+ll0) = {2+l0,11+l0,-(6+l0),-(10+l0)} ;
Line Loop(5+ll0) = {3+l0,12+l0,-(7+l0),-(11+l0)} ;
Line Loop(6+ll0) = {4+l0,9+l0,-(8+l0),-(12+l0)} ;

//Surfaces:
Plane Surface(1+ps0) = {1+ll0} ;
Plane Surface(2+ps0) = {2+ll0} ;
Plane Surface(3+ps0) = {3+ll0} ;
Plane Surface(4+ps0) = {4+ll0} ;
Plane Surface(5+ps0) = {5+ll0} ;
Plane Surface(6+ps0) = {6+ll0} ;


//Volume
Surface Loop(2) = {1+ps0,2+ps0,3+ps0,4+ps0,5+ps0,6+ps0} ;
Volume(2) = {2} ;





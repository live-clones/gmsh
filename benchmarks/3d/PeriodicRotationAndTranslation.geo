lc = 1.0;
R = 5;
R_rotation = 15;

Point(1) = {0, 0, 0, lc};
Point(2) = {R, 0, 0, lc};
Point(3) = {-R, 0, 0, lc};
Point(4) = {0, R, 0, lc};
Point(5) = {0, -R, 0, lc};
Circle(1) = {4, 1, 3};
Circle(2) = {3, 1, 5};
Circle(3) = {5, 1, 2};
Circle(4) = {2, 1, 4};

Line Loop(5) = {1, 2, 3, 4};
Plane Surface(6) = {5};

Extrude {0, 0, 1} {
  Surface{6};
}

Extrude {{0, 1, 0}, {-R_rotation, 0, 0}, Pi/4} {
  Surface{6};
}

Periodic Surface 28 {8, 9, 10, 11} = 6 {1, 2, 3, 4} ;
Periodic Surface 50 {30, 31, 32, 33} = 6 {1, 2, 3, 4} ;

//Periodic Surface {50} = {6} Rotate { {0, 1, 0}, {-R_rotation, 0, 0}, Pi/3} ;

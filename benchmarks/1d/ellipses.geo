Point(1) = {0,0,0,1};
Point(2) = {10,0,0,1};
Point(3) = {0,4.6,0,1};
Point(4) = {5,4,0,1};

//1/4
Ellipsis(1) = {2,1,2,3};

//1er bout
Ellipsis(2) = {2,1,2,4};

//2eme bout
Ellipsis(3) = {4,1,2,3};


Translate{1,0,0}{ Duplicata {Line{1} ;} }
Delete{ Line{1}; }

Rotate { {0,0,1},{0,0,0},3.14/4 } {
  Duplicata { Line{4}; }
}
Rotate { {0,0,1},{0,0,0},3.14/4 } {
  Duplicata { Line{2}; }
}
Rotate { {0,0,1},{0,0,0},3.14/4 } {
  Duplicata { Line{3}; }
}


Point(400) = {5,2,0,1};
Ellipsis(100) = {2,1,2,400};
Ellipsis(200) = {400,1,2,3};

Rotate { {4,3,1},{1,1,1},3.14/3.6 } {
  Duplicata { Line{6}; }
}
Rotate { {4,3,1},{1,1,1},3.14/3.6 } {
  Duplicata { Line{7}; }
}
Rotate { {4,3,1},{1,1,1},3.14/3.6 } {
  Duplicata { Line{100}; }
}
Rotate { {4,3,1},{1,1,1},3.14/3.6 } {
  Duplicata { Line{200}; }
}

//axe principal specifie dans le quadrant oppose

Point(300) = {-9,1,0,1};
Point(500) = {-1,4,0,1};

Ellipsis(300) = {500,1,2,300};

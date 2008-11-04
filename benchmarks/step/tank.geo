//Mesh.CharacteristicLengthFactor = 0.2 ;
Merge "tank.brep";

Transfinite Line {55,56} = 10 ;
Transfinite Line {54,26,-24} = 20 Using Progression 1;
Transfinite Surface {19} = {21,20,36,35} ;

Transfinite Line {25,53,39} = 63 ;
Transfinite Line {23,27} = 3 ;
Transfinite Line {22,21,19,6} = 13 ;
Transfinite Line {20} = 11 ;
Transfinite Surface {7} = {18:21} ;

Transfinite Line {5,7,18,28} = 5 ;
Transfinite Line {17,37,1,14,29,8} = 13 ;
Transfinite Surface {2} = {1,5,6,2};
Transfinite Surface {6} = {2,6,13,7};
Transfinite Surface {13} = {7,13,14,11};
Transfinite Surface {8} = {11,14,1,5};

Transfinite Line {2, 16, 9, 4, 69, 91, 73, 71,81} = 20;
Transfinite Line {3, 15, 30, 10, 70, 72, 90, 92} = 13;
Transfinite Surface {1} = {1,2,3,4};
Transfinite Surface {3} = {2,7,8,3};
Transfinite Surface {9} = {7,11,12,8};
Transfinite Surface {5} = {12,11,1,4};

Transfinite Line {31, 11, 35, 57, 93, 96, 104, 106,41,42} = 13;
Transfinite Line {13, 12, 36, 32, 95, 94, 97, 105} = 10;

Transfinite Line {34, 58, 59, 33, 108, 109, 110, 107} = 5;

Transfinite Line {46, 44, 68, 66} = 13;
Transfinite Line {45, 47, 43, 67} = 5;

Transfinite Surface {16} = {17,16,29,30};
Transfinite Surface {15} = {29,16,15,28};
Transfinite Surface {27} = {28,15,27,39};
Transfinite Surface {26} = {39,27,30,17};

Transfinite Surface {29} = {30,29,41,42};
Transfinite Surface {28} = {29,28,40,41};
Transfinite Surface {40} = {28,39,51,40};
Transfinite Surface {39} = {39,30,42,51};

Transfinite Line {51, 79, 52, 77, 98, 100, 62, 86, 102, 63, 87, 103, 84, 60, 38, 40, 65, 89, 75, 49} = 20;

Transfinite Line {80, 61, 64, 78, 50, 48} = 10;

Transfinite Surface {17} = {18,31,32,19};
Transfinite Surface {18} = {20,19,34,33};
Transfinite Surface {31} = {19,32,45,34};
Transfinite Surface {32} = {36,20,33,46};

Transfinite Surface {24} = {33,34,26,25};
Transfinite Surface {36} = {46,33,25,37};
Transfinite Surface {23} = {25,21,35,37};
Transfinite Surface {25} = {31,18,26,38};
Transfinite Surface {37} = {26,34,45,38};


Transfinite Surface {14} = {21,25,26,18} ;

Transfinite Surface {38} = {31,38,50,43} ;
Transfinite Surface {30} = {31,32,44,43} ;
Transfinite Surface {43} = {32,44,55,45} ;
Transfinite Surface {46} = {50,38,45,55} ;

Transfinite Surface {33} = {35,36,47,48} ;
Transfinite Surface {35} = {35,48,49,37} ;
Transfinite Surface {44} = {36,47,56,46} ;
Transfinite Surface {45} = {46,56,49,37} ;

Transfinite Surface {41} = {40,53,52,41} ;
Transfinite Surface {42} = {41,42,54,52} ;
Transfinite Surface {48} = {53,40,51,57} ;
Transfinite Surface {47} = {57,54,42,51} ;

Transfinite Surface {12} = {4,9,24,12} ;
Transfinite Surface {20} = {24,12,8,22} ;
Transfinite Surface {4} = {4,9,10,3} ;
Transfinite Surface {10} = {10,3,22,8} ;

Recombine Surface{1:52};

Mesh.Smoothing = 10;

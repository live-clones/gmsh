////////////////////////////////////////////////
//                                            //
// TENSILE TEST SPECIMEN                      //
//                                            //
// I. J. Sanchez - 25-11-04                   //
//                                            //
////////////////////////////////////////////////
//Reference point
//---------------
x0 = 0;
y0 = 0;
z0 = 0;

//Characteristics lengths for mesh
//--------------------------------
h1 = 1;
h2 = 1;
h3 = 1;
h = 5;

//Charasteristics lengths for geometry:
//-----------------------------------------------
L_main_tr = 8;
L_main = 20;

L_ext_tr = 20;
L_ext = 22;

R_1 = 3;

/////////////////////////////////////////////////
//                                             //
//             !---L_main----!                 //
//    _________               _________        //
//   !         !_____________!    !    !       //
//   !                !           !    !       //
//   !                !           !    !       //
//   !          ______!______     !    !       //
//   !_________!R_1   !      !____!____!       //
//                    !           !            //
//   !---------!      !           !            //
//       L_ext        !           !            //
//                L_main_tr       !            //
//                             L_ext_tr        //
//					       //
/////////////////////////////////////////////////

//Some lengths useful for mesh:
//-----------------------------
L_m = 2;

//Points definitions:
//--------------------------------------------------------------------------------------
Point(1)  = { x0,                              y0 + L_main_tr/2,           z0,  h1    };

Point(2)  = { x0 + L_m,                        y0 + L_main_tr/2,           z0,  h2    };
Point(3)  = { x0 + L_main/2 - R_1,             y0 + L_main_tr/2 + R_1,     z0,  h     };
Point(4)  = { x0 + L_main/2 - R_1,             y0 + L_main_tr/2,           z0,  h3    };
Point(5)  = { x0 + L_main/2,                   y0 + L_main_tr/2 + R_1,     z0,  h3    };
Point(6)  = { x0 + L_main/2,                   y0 + L_ext_tr/2,            z0,  h     };
Point(7)  = { x0 + L_main/2 + L_ext,           y0 + L_ext_tr/2,            z0,  h     };

Point(21)  = {-x0 - L_main/2 - L_ext,          y0 + L_ext_tr/2,           z0,  h      };
Point(22)  = {-x0 - L_main/2,                  y0 + L_ext_tr/2,           z0,  h      };
Point(23)  = {-x0 - L_main/2,                  y0 + L_main_tr/2 + R_1,    z0,  h3     };
Point(24)  = {-x0 - L_main/2 + R_1,            y0 + L_main_tr/2,          z0,  h3     };
Point(25)  = {-x0 - L_main/2 + R_1,            y0 + L_main_tr/2 + R_1,    z0,  h      };
Point(26)  = {-x0 - L_m,                       y0 + L_main_tr/2,          z0,  h2     };

Point(30)  = {-x0 - L_main/2 - L_ext,          y0,                        z0,  h     };
Point(31)  = { x0 + L_main/2 + L_ext,          y0,                        z0,  h     };

//Lines and circles definitions:
//------------------------------
Line(1) = {31,7};
Line(2) = {7,6};
Line(3) = {6,5};
Line(4) = {4,2};
Line(5) = {2,1};
Line(6) = {1,26};
Line(7) = {26,24};
Line(8) = {23,22};
Line(9) = {22,21};
Line(10) = {21,30};
Line(11) = {30,31};
Circle(12) = {5,3,4};
Circle(13) = {24,25,23};

//Line loop definition:
//------------------------------
Line Loop(14) = {2,3,12,4,5,6,7,13,8,9,10,11,1};

//Surface definition:
//------------------------------
Plane Surface(15) = {14};

//Extruding geometry
//----------------------------
e[] = Extrude Surface {15, {1,0,0}, {x0,y0,z0}, Pi/2}; ;
e[] = Extrude Surface {e[0], {1,0,0}, {x0,y0,z0}, Pi/2}; ;
e[] = Extrude Surface {e[0], {1,0,0}, {x0,y0,z0}, Pi/2}; ;
e[] = Extrude Surface {e[0], {1,0,0}, {x0,y0,z0}, Pi/2}; ;

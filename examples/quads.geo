l = .3;
Point(1) = {-2,-1,0,l};
Point(2) = {-2,1,0,l};
Point(3) = {0,-1,0,l};
Point(4) = {0,1,0,l};
Point(5) = {-3,-2,0,l};
Point(6) = {-3,2,0,l};
Point(7) = {1,-2,0,l};
Point(8) = {1,2,0,l};

Line(1) = {6,8};
Line(2) = {8,7};
Line(3) = {7,5};
Line(4) = {5,6};
Line(5) = {2,1};
Line(6) = {1,3};
Line(7) = {3,4};
Line(8) = {4,2};

Line Loop(9) = {5,6,7,8};
Plane Surface(10) = {9};

Line Loop(11) = {2,3,4,1};
Plane Surface(12) = {11,9};

/* this will try to produce quadrangles for surfaces 10 and 12 */

Recombine Surface {10,12} ;


/* For surface 10, we force a structured mesh (transfinite meshing) */

/* We force the number of points on the lines 5,6,7,8 to be 10 and 5 */
Transfinite Line {5,7} = 10 ;
Transfinite Line {6,8} = 5 ;

/* we define transfinite interpolation on surface 10, determined by the 
   ordering of the for ***vertices*** 1,3,2,4  */
Transfinite Surface {10} = {1,3,4,2} ;

/*
   result :
  
   Surface 10 should be made entirely of quads
   Surface 12 should be mixed tri/quad

   comments :

   Transfinite surfaces can only have 3 or 4 sides

   to have a specified repartion of the nodes for transfinite lines :
   
   Transfinite Line {X} = Y Using Power Z ;
   Transfinite Line {X} = Y Using Bump Z ;

*/

lc = 0.05 ;
lc = 0.1 ;


/* Point      1 */
Point(newp) = {0,0,0,lc};
/* Point      2 */
Point(newp) = {1,0,0,lc};
/* Point      3 */
Point(newp) = {0.5,0,0,lc};
/* Point      4 */
Point(newp) = {0.5,0.5,0,lc};
/* Point      5 */
Point(newp) = {1,0.5,0,lc};
/* Point      6 */
Point(newp) = {1,1,0,lc};
/* Point      7 */
Point(newp) = {0,1,0,lc};
Delete {
 Point(2);
}
Line(1) = Liste[3,4];
Line(2) = Liste[4,5];
Line(3) = Liste[5,6];
Line(4) = Liste[6,7];
Line(5) = Liste[7,1];
Line(6) = Liste[1,3];

Loop(7) = {5,6,1,2,3,4};
Plane Surface(8) = {7};


Air = 1111 ;
CL0 = 2222 ;
CL1 = 3333 ;

Physical Volume (Air) = Liste[8] ;
Physical Surface (CL0) = Liste[1,2] ;
Physical Surface (CL1) = Liste[4,5] ;

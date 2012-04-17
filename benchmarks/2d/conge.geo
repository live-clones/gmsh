unit = 1.0e-02 ;

e1 =  4.5 * unit ;
e2 =  6.0 * unit / 2.0 ;
e3 =  5.0 * unit / 2.0 ;
h1 =  5.0 * unit ;
h2 = 10.0 * unit ;
h3 =  5.0 * unit ;
h4 =  2.0 * unit ;
h5 =  4.5 * unit ;
R1 =  1.0 * unit ;
R2 =  1.5 * unit ;
r  =  1.0 * unit ;
ccos = (-h5*R1+e2* (h5*h5+e2*e2-R1*R1)^0.5) / (h5*h5+e2*e2) ;
ssin = ( 1.0 - ccos*ccos )^0.5 ;

Lc1 = 0.003 ;
Lc2 = 0.003 ;

Point(1) = { -e1-e2, 0.0  , 0.0 , Lc1};
Point(2) = { -e1-e2, h1   , 0.0 , Lc1};
Point(3) = { -e3-r , h1   , 0.0 , Lc2};
Point(4) = { -e3-r , h1+r , 0.0 , Lc2};
Point(5) = { -e3   , h1+r , 0.0 , Lc2};
Point(6) = { -e3   , h1+h2, 0.0 , Lc1};
Point(7) = {  e3   , h1+h2, 0.0 , Lc1};
Point(8) = {  e3   , h1+r , 0.0 , Lc2};
Point(9) = {  e3+r , h1+r , 0.0 , Lc2};
Point(10)= {  e3+r , h1   , 0.0 , Lc2};
Point(11)= {  e1+e2, h1   , 0.0 , Lc1};
Point(12)= {  e1+e2, 0.0  , 0.0 , Lc1};
Point(13)= {  e2   , 0.0  , 0.0 , Lc1};

Point(14)= {  R1 / ssin , h5+R1*ccos, 0.0 , Lc2};
Point(15)= {  0.0       , h5        , 0.0 , Lc2};
Point(16)= { -R1 / ssin , h5+R1*ccos, 0.0 , Lc2};
Point(17)= { -e2        , 0.0       , 0.0 , Lc1};

Point(18)= { -R2  , h1+h3   , 0.0 , Lc2};
Point(19)= { -R2  , h1+h3+h4, 0.0 , Lc2};
Point(20)= {  0.0 , h1+h3+h4, 0.0 , Lc2};
Point(21)= {  R2  , h1+h3+h4, 0.0 , Lc2};
Point(22)= {  R2  , h1+h3   , 0.0 , Lc2};
Point(23)= {  0.0 , h1+h3   , 0.0 , Lc2};

Point(24)= {  0 , h1+h3+h4+R2, 0.0 , Lc2};
Point(25)= {  0 , h1+h3-R2,    0.0 , Lc2};

Line(1)  = {1 ,17};    /* ux=uy=0 */
Line(2)  = {17,16};
Circle(3) = {14,15,16};
Line(4)  = {14,13};
Line(5)  = {13,12};    /* ux=uy=0 */
Line(6)  = {12,11};
Line(7)  = {11,10};
Circle(8) = { 8, 9,10};
Line(9)  = { 8, 7};
Line(10) = { 7, 6};    /* T=10000 N */
Line(11) = { 6, 5};
Circle(12) = { 3, 4, 5};
Line(13) = { 3, 2};
Line(14) = { 2, 1};

Line(15) = {18,19};
Circle(16) = {21,20,24};
Circle(17) = {24,20,19};
Circle(18) = {18,23,25};
Circle(19) = {25,23,22};
Line(20) = {21,22};

Line Loop(21) = {17,-15,18,19,-20,16};
Plane Surface(22) = {21};
Line Loop(23) = {11,-12,13,14,1,2,-3,4,5,6,7,-8,9,10};
Plane Surface(24) = {23,21};

Physical Line(24) = {9,1,2,3,4,5,6,7,8,11};
Physical Line(25) = {12,13,14,15,16,17,18,19,20,10};
Physical Surface(26) = {24};
Physical Line(27) = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 14, 13, 12, 11};
Physical Line(28) = {17, 16, 20, 19, 18, 15};
//Recombine Surface {24, 22};
Mesh.RecombinationAlgorithm=1;
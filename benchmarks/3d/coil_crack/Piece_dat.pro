mm = 1e-3;

//Piece
Rup = 64*mm/2 ;
Rdwn = 121*mm/2 ;
Rc = 84*mm/2;
R10 = 10 * mm ;

h1 = 5*mm ;
h2 = 15*mm ;
h3 = 20*mm ;

//Defect
//   length x width x depth (mm)
//A  0.4 x 0.2 x 0.1
//B  1 x 0.2 x 0.1
//C  2 x 0.2 x 0.1
//D  1 x 0.4 x 0.2
//E  2 x 0.4 x 0.2

length = 1. * mm ;
depth = 0.1 * mm ;//Shape: half disk
width = 2 * depth ;

//Box
xBox1 = Rdwn*1.5 ;
xBox2 = -xBox1 ;
yBox1 = 2.5*h3 ;
yBox2 = -h3 ;

L = (Rdwn-Rc)/2 ;

//--------------------------------------------------------
//Physical geometry

PIECE = 3000; 
SKINPIECE = 3001 ;
SKINPIECEWCRACK = 3002 ;
CRACK = 3333; 

AIR = 4000 ;
SURFACEGH0 = 4001 ;

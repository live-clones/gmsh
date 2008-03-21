/********************************************************************* 
 *
 *  Blennerhassett Arch Bridge
 *  gmsh input file for Tie Cable Anchorage Local Model.
 *  
 *
 *  UNITS: INCHES
 *
 *  FILE NAME: TieAnchor.geo
 *  MADE BY: RW					DATE: 1/05/2003
 *
 *********************************************************************/
//
// ____________
// MESH OPTIONS
// Anisotropic 2D mesh generator:
Mesh.Algorithm = 2 ;
// Force a n-step Laplacian smoothing of the mesh:
Mesh.Smoothing = 20 ;
// Show construction of 2D mesh in realtime (with 2D anisotropic)
//Mesh.Interactive = 1;
//
// _________________
// MESHING CONSTANTS
//
// Characteristic Lengths (mesh densities)
lcCoarse = 12 ;
lcMed = 6 ;
lcFine = 3 ;
lcVFine = 2 ;
lcXFine = 1 ;
//
// ______________________
// GEOMETRICAL PARAMETERS
xinit = 0 ;						// ORIGIN: Located at bot. flange of tie at intersection of 
zinit = 0 ;						// tie web west with line of action of lower lateral bracing
yinit = 0 ;						// and CL Floorbeam
Dtie = 85.625 ;						// depth of tie
yFlBot = yinit ;					// y-position CL Bot. Flange
yFlTop = yFlBot+Dtie ;					// y-position CL Top Flange
zWebWest = zinit ;					// z-position Web West
zWebEast = zWebWest-49 ;				// z-position Web East
thetaN = 90-63.6999 ;					// North cable inclination WRT vertical (degrees)
thetaS = -thetaN ;					// South cable inclination WRT vertical (degrees)
							// positive theta = cable leans towards North
zCableN = (zWebEast-zWebWest)/2+4 ;			// z-position CL North cable WRT CL tie
zCableS = (zWebEast-zWebWest)/2-4 ;			// z-position CL South cable WRT CL tie
DiaCable = 12.; // 7.0625;				// cable Diameter
ClearanceCable = 0.; // 0.5;				// required clearance between cable and hole
							// <<WARNING>> varying clearance or diameter can
							// cause mesh to crash... check mesh after changing.
							// if crashes, check mesh densities at hole & bot. flange
ClearanceAnchPlateY = 8.75;				// y-clearance btwn CL Top Flange & bot. of Anchor Plate
ClearanceDiaph = 3.375;					// required clearance between hole/anchorage and diaph
hAnchGuss = 7.75 ;					// y-dimension height of Anchorage Web "gusset" bracing
wRingPlatez = 4;					// width of ring-plate around hole in Bot Flange
wRingPlatex = 6;					// width of ring-plate around hole in Bot Flange
wAnchPlate = 22 ;					// width of Anchor End-Plate (and hole in webs)
hAnchPlate = 23 ;					// height of Anchor End-Plate (and hole in webs)
xCableN = xinit-22.125 ;				// x-position CL North cable anchorage at anchor-point
xCableS = xinit+22.125 ;				// x-position CL South cable anchorage at anchor-point
yCableN = yFlBot+63.5625 ;				// y-position North cable anchor point at bot of anchorage webs 
yCableS = yCableN ;					// y-position South cable anchor point at bot of anchorage webs 
holeWidth = DiaCable+ClearanceCable;  			// width of minor axis of hole in bot. flange
holeLength = holeWidth/(Cos(thetaN*Pi/180));		// length of major axis of hole in bot. flange
//
dLLB=24.375 ;						// depth of Lower Lateral Bracing
//
//
//
/********************************************************************* 
 *
 *  STANDARD FUNCTIONS
 *
 *********************************************************************/
//
// ____________________________
// FUNCTION: ConvertPolarToCart
// Converts polar coordinates to cartesian
// input r, theta
// output x,y
//
Function ConvertPolarToCart
FCTx = FCTr*Cos(FCTtheta*Pi/180) ;
FCTy = FCTr*Sin(FCTtheta*Pi/180) ;
Return
//
// ____________________________
// FUNCTION: ConvertCartToPolar
// Converts Cartesian coordinates to Polar
// input x,y
// output r, theta
//
Function ConvertCartToPolar
FCTr = Hypot(FCTx,FCTy) ;
FCTtheta = Atan(FCTy/FCTx) * 180/Pi ;
Return
//
// ____________________________
// FUNCTION: ComputePointOnLine
// Computes the point at which two lines intersect
// WARNING: function will crash if line is vertical (slope = infinity)
// input x1,y1 input x2,y2 input x3
// output y3
//
Function ComputePointOnLine
FCTb = (FCTy1-FCTy2)/(FCTx1-FCTx2) ;
FCTa = FCTy1-FCTb1*FCTx1 ;
FCTy3 = FCTa + FCTb*FCTx3 ;
Return
//
//
// ______________________
// FUNCTION: IsectLines2d
// Computes the point at which two lines intersect
// WARNING: function will crash if lines are parallel or vertical (slope = infinity)
// input x1,y1 input x2,y2 input u1,v1 input u2,v2
// output xi,yi
// if (x1-xi)*(xi-x2)>=0 AND (u1-xi)*(xi-u2)>=0 
//    AND (y1-yi)*(yi-y2)>=0 AND (v1-yi)*(yi-v2)>=0 
//
Function IsectLines2d
FCTb1 = (FCTy2-FCTy1)/(FCTx2-FCTx1) ;
FCTb2 = (FCTv2-FCTv1)/(FCTu2-FCTu1) ;
FCTa1 = FCTy1-FCTb1*FCTx1 ;
FCTa2 = FCTv1-FCTb2*FCTu1 ;
FCTxi = -(FCTa1-FCTa2)/(FCTb1-FCTb2) ;
FCTyi = FCTa1+FCTb1*FCTxi ;
Return
//
//
// ______________________________
// FUNCTION: ComputePointRotation
// Computes coordinates of a Point after rotation through angle theta
// input x1,y1, theta
// output x2,y2
// NOTE: x1,y1,x2,y2 represent distances from the "pivot point"
//
Function ComputePointRotation
FCTr = Hypot(FCTx1,FCTy1) ;
FCTthetaInit = Atan(FCTy1/FCTx1) * 180/Pi ;
FCTx2 = FCTr * Cos((FCTthetaInit+FCTtheta)*Pi/180) ;
FCTy2 = FCTr * Sin((FCTthetaInit+FCTtheta)*Pi/180) ;
Return
//
//
//
/********************************************************************* 
 *
 *  GENERATE MESH
 *
 *********************************************************************/
//
//
//
//
//
/********************************************************************* 
 *
 *  TIE WEB EAST
 *
 *********************************************************************/
//
lc101000 = lcCoarse;
lc101000Med = lcMed;
lc101000Fine = lcFine;
lc101000VFine = lcVFine;
// ______
// POINTS
//
// Interface Bot. Flange 
p101100=newp;	Point(p101100) = {xinit-1.3*Dtie,	yinit,			zWebEast,	lc101000};	c101100[]={Point{p101100}};
p101108=newp;	Point(p101108) = {xinit-8.375,		c101100[1],		c101100[2],	lc101000Fine};	c101108[]={Point{p101108}};
p101110=newp;	Point(p101110) = {xinit,		c101100[1],		c101100[2],	lc101000Fine};	c101110[]={Point{p101110}};
p101112=newp;	Point(p101112) = {xinit+8.375,		c101100[1],		c101100[2],	lc101000Fine};	c101112[]={Point{p101112}};
p101125=newp;	Point(p101125) = {xinit+1.3*Dtie,	c101100[1],		c101100[2],	lc101000};	c101125[]={Point{p101125}};
//
p101210=newp;	Point(p101210) = {c101110[0],		c101100[1]+8.8125,	c101100[2],	lc101000Fine};	c101210[]={Point{p101210}};
//
p101410=newp;	Point(p101410) = {c101110[0],		yFlTop-8.8125,		c101100[2],	lc101000Fine};	c101410[]={Point{p101410}};
//
// Interface top flange
p101500=newp;	Point(p101500) = {c101100[0],		yFlTop,			c101100[2],	lc101000};	c101500[]={Point{p101500}};
p101508=newp;	Point(p101508) = {c101108[0],		c101500[1],		c101100[2],	lc101000Fine};	c101508[]={Point{p101508}};
p101510=newp;	Point(p101510) = {c101110[0],		c101500[1],		c101100[2],	lc101000Fine};	c101510[]={Point{p101510}};
p101512=newp;	Point(p101512) = {c101112[0],		c101500[1],		c101100[2],	lc101000Fine};	c101512[]={Point{p101512}};
p101525=newp;	Point(p101525) = {c101125[0],		c101500[1],		c101100[2],	lc101000};	c101525[]={Point{p101525}};
//
// Anchorage end-plate North
p121000=newp;	Point(p121000) = {xCableN-wAnchPlate/2,	yCableN-hAnchGuss,	c101100[2],	lc101000VFine};	c121000[]={Point{p121000}};
p121005=newp;	Point(p121005) = {xCableN-7,		c121000[1],		c101100[2],	lc101000VFine};	c121005[]={Point{p121005}};
p121015=newp;	Point(p121015) = {xCableN+7,		c121000[1],		c101100[2],	lc101000VFine};	c121015[]={Point{p121015}};
p121020=newp;	Point(p121020) = {xCableN+wAnchPlate/2,	c121000[1],		c101100[2],	lc101000VFine};	c121020[]={Point{p121020}};
//
p121200=newp;	Point(p121200) = {c121000[0],		yCableN,		c101100[2],	lc101000VFine};	c121200[]={Point{p121200}};
p121205=newp;	Point(p121205) = {c121005[0],		c121200[1],		c101100[2],	lc101000VFine};	c121205[]={Point{p121205}};
p121215=newp;	Point(p121215) = {c121015[0],		c121200[1],		c101100[2],	lc101000VFine};	c121215[]={Point{p121215}};
p121220=newp;	Point(p121220) = {c121020[0],		c121200[1],		c101100[2],	lc101000VFine};	c121220[]={Point{p121220}};
//
p121300=newp;	Point(p121300) = {c121000[0],		yCableN+(hAnchPlate-hAnchGuss),		c101100[2],	lc101000VFine};	c121300[]={Point{p121300}};
p121305=newp;	Point(p121305) = {c121005[0],		c121300[1],		c101100[2],	lc101000VFine};	c121305[]={Point{p121305}};
p121315=newp;	Point(p121315) = {c121015[0],		c121300[1],		c101100[2],	lc101000VFine};	c121315[]={Point{p121315}};
p121320=newp;	Point(p121320) = {c121020[0],		c121300[1],		c101100[2],	lc101000VFine};	c121320[]={Point{p121320}};
//
// Anchorage end-plate South
p122000=newp;	Point(p122000) = {xCableS-wAnchPlate/2,	c121000[1],		c101100[2],	lc101000VFine};	c122000[]={Point{p122000}};
p122005=newp;	Point(p122005) = {xCableS-7,		c122000[1],		c101100[2],	lc101000VFine};	c122005[]={Point{p122005}};
p122015=newp;	Point(p122015) = {xCableS+7,		c122000[1],		c101100[2],	lc101000VFine};	c122015[]={Point{p122015}};
p122020=newp;	Point(p122020) = {xCableS+wAnchPlate/2,	c122000[1],		c101100[2],	lc101000VFine};	c122020[]={Point{p122020}};
//
p122200=newp;	Point(p122200) = {c122000[0],		c121200[1],		c101100[2],	lc101000VFine};	c122200[]={Point{p122200}};
p122205=newp;	Point(p122205) = {c122005[0],		c122200[1],		c101100[2],	lc101000VFine};	c122205[]={Point{p122205}};
p122215=newp;	Point(p122215) = {c122015[0],		c122200[1],		c101100[2],	lc101000VFine};	c122215[]={Point{p122215}};
p122220=newp;	Point(p122220) = {c122020[0],		c122200[1],		c101100[2],	lc101000VFine};	c122220[]={Point{p122220}};
//
p122300=newp;	Point(p122300) = {c122000[0],		c121300[1],		c101100[2],	lc101000VFine};	c122300[]={Point{p122300}};
p122305=newp;	Point(p122305) = {c122005[0],		c122300[1],		c101100[2],	lc101000VFine};	c122305[]={Point{p122305}};
p122315=newp;	Point(p122315) = {c122015[0],		c122300[1],		c101100[2],	lc101000VFine};	c122315[]={Point{p122315}};
p122320=newp;	Point(p122320) = {c122020[0],		c122300[1],		c101100[2],	lc101000VFine};	c122320[]={Point{p122320}};
//
//
// _____
// LINES
// Horizontal Lines
L101100=newl;	Line(L101100) = {p101100, p101108};
L101108=newl;	Line(L101108) = {p101108, p101110};
L101110=newl;	Line(L101110) = {p101110, p101112};
L101112=newl;	Line(L101112) = {p101112, p101125};
//
L101500=newl;	Line(L101500) = {p101500, p101508};
L101508=newl;	Line(L101508) = {p101508, p101510};
L101510=newl;	Line(L101510) = {p101510, p101512};
L101512=newl;	Line(L101512) = {p101512, p101525};
// Vertical Lines
L201100=newl;	Line(L201100) = {p101100, p101500};
L201108=newl;	Line(L201108) = {p101108, p101508};
L201110=newl;	Line(L201110) = {p101110, p101210};
L201210=newl;	Line(L201210) = {p101210, p101410};
L201410=newl;	Line(L201410) = {p101410, p101510};
L201112=newl;	Line(L201112) = {p101112, p101512};
L201125=newl;	Line(L201125) = {p101125, p101525};
//
// Anchorage end-plate North
L121000=newl;	Line(L121000) = {p121000, p121005};
L121005=newl;	Line(L121005) = {p121005, p121015};
L121015=newl;	Line(L121015) = {p121015, p121020};
L121200=newl;	Line(L121200) = {p121200, p121205};
L121215=newl;	Line(L121215) = {p121215, p121220};
L121300=newl;	Line(L121300) = {p121300, p121305};
L121305=newl;	Line(L121305) = {p121305, p121315};
L121315=newl;	Line(L121315) = {p121315, p121320};
//
L221000=newl;	Line(L221000) = {p121000, p121200};
L221200=newl;	Line(L221200) = {p121200, p121300};
L221005=newl;	Line(L221005) = {p121005, p121205};
L221205=newl;	Line(L221205) = {p121205, p121305};
L221015=newl;	Line(L221015) = {p121015, p121215};
L221215=newl;	Line(L221215) = {p121215, p121315};
L221020=newl;	Line(L221020) = {p121020, p121220};
L221220=newl;	Line(L221220) = {p121220, p121320};
//
// Anchorage end-plate South
L122000=newl;	Line(L122000) = {p122000, p122005};
L122005=newl;	Line(L122005) = {p122005, p122015};
L122015=newl;	Line(L122015) = {p122015, p122020};
L122200=newl;	Line(L122200) = {p122200, p122205};
L122215=newl;	Line(L122215) = {p122215, p122220};
L122300=newl;	Line(L122300) = {p122300, p122305};
L122305=newl;	Line(L122305) = {p122305, p122315};
L122315=newl;	Line(L122315) = {p122315, p122320};
//
L222000=newl;	Line(L222000) = {p122000, p122200};
L222200=newl;	Line(L222200) = {p122200, p122300};
L222005=newl;	Line(L222005) = {p122005, p122205};
L222205=newl;	Line(L222205) = {p122205, p122305};
L222015=newl;	Line(L222015) = {p122015, p122215};
L222215=newl;	Line(L222215) = {p122215, p122315};
L222020=newl;	Line(L222020) = {p122020, p122220};
L222220=newl;	Line(L222220) = {p122220, p122320};
//
// __________
// LINE LOOPS
//
// 
LL101001=newl;	Line Loop(LL101001) =	{L101100,L201108,-L101500,-L201100};
LL101002=newl;	Line Loop(LL101002) =	{L101108,L201110,L201210,L201410,-L101508,-L201108};
LL101003=newl;	Line Loop(LL101003) =	{L101110,L201112,-L101510,-L201410,-L201210,-L201110};
LL101004=newl;	Line Loop(LL101004) =	{L101112,L201125,-L101512,-L201112};
//
// Anchorage end-plate North
LL121001=newl;	Line Loop(LL121001) =	{L121000,L221005,-L121200,-L221000};
LL121002=newl;	Line Loop(LL121002) =	{L121005,L221015,L221215,-L121305,-L221205,-L221005};
LL121003=newl;	Line Loop(LL121003) =	{L121015,L221020,-L121215,-L221015};
LL121004=newl;	Line Loop(LL121004) =	{L121200,L221205,-L121300,-L221200};
LL121005=newl;	Line Loop(LL121005) =	{L121215,L221220,-L121315,-L221215};
LL121010=newl;	Line Loop(LL121010) =	{L121000,L121005,L121015,L221020,L221220,-L121315,-L121305,-L121300,-L221200,-L221000};
//
// Anchorage end-plate South
LL122001=newl;	Line Loop(LL122001) =	{L122000,L222005,-L122200,-L222000};
LL122002=newl;	Line Loop(LL122002) =	{L122005,L222015,L222215,-L122305,-L222205,-L222005};
LL122003=newl;	Line Loop(LL122003) =	{L122015,L222020,-L122215,-L222015};
LL122004=newl;	Line Loop(LL122004) =	{L122200,L222205,-L122300,-L222200};
LL122005=newl;	Line Loop(LL122005) =	{L122215,L222220,-L122315,-L222215};
LL122010=newl;	Line Loop(LL122010) =	{L122000,L122005,L122015,L222020,L222220,-L122315,-L122305,-L122300,-L222200,-L222000};
//
// ________
// SURFACES
PS101001=news;	Plane Surface(PS101001) =	{LL101001,LL121010};
PS101002=news;	Plane Surface(PS101002) =	{LL101002};
PS101003=news;	Plane Surface(PS101003) =	{LL101003};
PS101004=news;	Plane Surface(PS101004) =	{LL101004,LL122010};
//
// Anchorage end-plates
PS121001=news;	Plane Surface(PS121001) =	{LL121001};
PS121002=news;	Plane Surface(PS121002) =	{LL121002};
PS121003=news;	Plane Surface(PS121003) =	{LL121003};
PS121004=news;	Plane Surface(PS121004) =	{LL121004};
PS121005=news;	Plane Surface(PS121005) =	{LL121005};
//
PS122001=news;	Plane Surface(PS122001) =	{LL122001};
PS122002=news;	Plane Surface(PS122002) =	{LL122002};
PS122003=news;	Plane Surface(PS122003) =	{LL122003};
PS122004=news;	Plane Surface(PS122004) =	{LL122004};
PS122005=news;	Plane Surface(PS122005) =	{LL122005};
//
//
/********************************************************************* 
 *
 *  TIE WEB WEST
 *
 *********************************************************************/
//
lc102000 = lcCoarse;
lc102000Med = lcMed;
lc102000Fine = lcFine;
lc102000VFine = lcVFine;
lc102000XFine = lcXFine;
// ______
// POINTS
//
// Interface Bot. Flange 
p102100=newp;	Point(p102100) = {c101100[0],		c101100[1],		zWebWest,	lc102000};	c102100[]={Point{p102100}};
p102105=newp;	Point(p102105) = {c101110[0]-16,	c102100[1],		c102100[2],	lc102000Fine};	c102105[]={Point{p102105}};
p102108=newp;	Point(p102108) = {c101110[0]-8.375,	c102100[1],		c102100[2],	lc102000Fine};	c102108[]={Point{p102108}};
p102110=newp;	Point(p102110) = {c101110[0],		c102100[1],		c102100[2],	lc102000Fine};	c102110[]={Point{p102110}};
p102112=newp;	Point(p102112) = {c101110[0]+8.375,	c102100[1],		c102100[2],	lc102000Fine};	c102112[]={Point{p102112}};
p102115=newp;	Point(p102115) = {c101110[0]+16,	c102100[1],		c102100[2],	lc102000Fine};	c102115[]={Point{p102115}};
p102120=newp;	Point(p102120) = {c102115[0]+16,	c102100[1],		c102100[2],	lc102000Fine};	c102120[]={Point{p102120}};
p102125=newp;	Point(p102125) = {c101125[0],		c102100[1],		c102100[2],	lc102000};	c102125[]={Point{p102125}};
//
p102210=newp;	Point(p102210) = {c102110[0],		c101210[1],		c102100[2],	lc102000Med};	c102210[]={Point{p102210}};
//
p102312=newp;	Point(p102312) = {c102112[0],		c101510[1]-dLLB,	c102100[2],	.5};	c102312[]={Point{p102312}};
p102314=newp;	Point(p102314) = {c102110[0]+9.3125,	c102312[1],		c102100[2],	.5};	c102314[]={Point{p102314}};
p102315=newp;	Point(p102315) = {c102314[0]+3.875,	c102312[1],		c102100[2],	lc102000Fine};	c102315[]={Point{p102315}};
p102317=newp;	Point(p102317) = {c102315[0]+15.625,	c102312[1],		c102100[2],	lc102000Fine};	c102317[]={Point{p102317}};
p102318=newp;	Point(p102318) = {c102317[0]+4.4375,	c102312[1],		c102100[2],	lc102000Fine};	c102318[]={Point{p102318}};
p102320=newp;	Point(p102320) = {c102110[0]+44.1875,	c102312[1],		c102100[2],	lc102000Fine};	c102320[]={Point{p102320}};
//
p102372=newp;	Point(p102372) = {c102112[0],		c102312[1]+6.3125,	c102100[2],	lc102000Fine};	c102372[]={Point{p102372}};
p102374=newp;	Point(p102374) = {c102110[0]+11.875,	c102372[1],		c102100[2],	lc102000Fine};	c102374[]={Point{p102374}};
p102375=newp;	Point(p102375) = {c102110[0]+14.0625,	c102372[1],		c102100[2],	lc102000Fine};	c102375[]={Point{p102375}};
p102376=newp;	Point(p102376) = {c102110[0]+16.3125,	c102372[1],		c102100[2],	lc102000Fine};	c102376[]={Point{p102376}};
p102377=newp;	Point(p102377) = {c102110[0]+31.9375,	c102372[1],		c102100[2],	lc102000Fine};	c102377[]={Point{p102377}};
p102378=newp;	Point(p102378) = {c102110[0]+36.375,	c102372[1],		c102100[2],	lc102000Fine};	c102378[]={Point{p102378}};
p102380=newp;	Point(p102380) = {c102110[0]+44.1875,	c102372[1],		c102100[2],	lc102000Fine};	c102380[]={Point{p102380}};
//
p102352=newp;	Point(p102352) = {c102112[0],		c102312[1]-6.3125,	c102100[2],	lc102000Fine};	c102352[]={Point{p102352}};
p102355=newp;	Point(p102355) = {c102110[0]+22,	c102352[1],		c102100[2],	lc102000Fine};	c102355[]={Point{p102355}};
p102357=newp;	Point(p102357) = {c102110[0]+25.6875,	c102352[1],		c102100[2],	lc102000Fine};	c102357[]={Point{p102357}};
p102358=newp;	Point(p102358) = {c102110[0]+30.1875,	c102352[1],		c102100[2],	lc102000Fine};	c102358[]={Point{p102358}};
p102360=newp;	Point(p102360) = {c102110[0]+44.1875,	c102352[1],		c102100[2],	lc102000Fine};	c102360[]={Point{p102360}};
//
p102410=newp;	Point(p102410) = {c102110[0],		c101410[1],		c102100[2],	lc102000Med};	c102410[]={Point{p102410}};
//
// Interface top flange
p102500=newp;	Point(p102500) = {c101100[0],		c101500[1],		c102100[2],	lc102000};	c102500[]={Point{p102500}};
p102505=newp;	Point(p102505) = {c102105[0],		c102500[1],		c102100[2],	lc102000Med};	c102505[]={Point{p102505}};
p102508=newp;	Point(p102508) = {c101110[0]-8.375,	c102500[1],		c102100[2],	lc102000Fine};	c102508[]={Point{p102508}};
p102510=newp;	Point(p102510) = {c101110[0],		c102500[1],		c102100[2],	lc102000Fine};	c102510[]={Point{p102510}};
p102512=newp;	Point(p102512) = {c101110[0]+8.375,	c102500[1],		c102100[2],	lc102000Fine};	c102512[]={Point{p102512}};
p102515=newp;	Point(p102515) = {c102115[0],		c102500[1],		c102100[2],	lc102000Med};	c102515[]={Point{p102515}};
p102518=newp;	Point(p102518) = {c102110[0]+20.375,	c102500[1],		c102100[2],	lc102000Med};	c102518[]={Point{p102518}};
p102525=newp;	Point(p102525) = {c101125[0],		c102500[1],		c102100[2],	lc102000};	c102525[]={Point{p102525}};
//
// Anchorage end-plate North
p135000=newp;	Point(p135000) = {c121000[0],		c121000[1],		c102100[2],	lc102000VFine};	c135000[]={Point{p135000}};
p135005=newp;	Point(p135005) = {c121005[0],		c121005[1],		c102100[2],	lc102000VFine};	c135005[]={Point{p135005}};
p135015=newp;	Point(p135015) = {c121015[0],		c121015[1],		c102100[2],	lc102000VFine};	c135015[]={Point{p135015}};
p135020=newp;	Point(p135020) = {c121020[0],		c121020[1],		c102100[2],	lc102000VFine};	c135020[]={Point{p135020}};
//
p135200=newp;	Point(p135200) = {c121200[0],		c121200[1],		c102100[2],	lc102000VFine};	c135200[]={Point{p135200}};
p135205=newp;	Point(p135205) = {c121205[0],		c121205[1],		c102100[2],	lc102000VFine};	c135205[]={Point{p135205}};
p135215=newp;	Point(p135215) = {c121215[0],		c121215[1],		c102100[2],	lc102000VFine};	c135215[]={Point{p135215}};
p135220=newp;	Point(p135220) = {c121220[0],		c121220[1],		c102100[2],	lc102000VFine};	c135220[]={Point{p135220}};
//
p135300=newp;	Point(p135300) = {c121300[0],		c121300[1],		c102100[2],	lc102000VFine};	c135300[]={Point{p135300}};
p135305=newp;	Point(p135305) = {c121305[0],		c121305[1],		c102100[2],	lc102000VFine};	c135305[]={Point{p135305}};
p135315=newp;	Point(p135315) = {c121315[0],		c121315[1],		c102100[2],	lc102000VFine};	c135315[]={Point{p135315}};
p135320=newp;	Point(p135320) = {c121320[0],		c121320[1],		c102100[2],	lc102000VFine};	c135320[]={Point{p135320}};
//
// Anchorage end-plate South
p136000=newp;	Point(p136000) = {c122000[0],		c122000[1],		c102100[2],	.5};	c136000[]={Point{p136000}};
p136005=newp;	Point(p136005) = {c122005[0],		c122005[1],		c102100[2],	lc102000VFine};	c136005[]={Point{p136005}};
p136015=newp;	Point(p136015) = {c122015[0],		c122015[1],		c102100[2],	lc102000VFine};	c136015[]={Point{p136015}};
p136020=newp;	Point(p136020) = {c122020[0],		c122020[1],		c102100[2],	lc102000VFine};	c136020[]={Point{p136020}};
//
p136200=newp;	Point(p136200) = {c122200[0],		c122200[1],		c102100[2],	lc102000VFine};	c136200[]={Point{p136200}};
p136205=newp;	Point(p136205) = {c122205[0],		c122205[1],		c102100[2],	lc102000VFine};	c136205[]={Point{p136205}};
p136215=newp;	Point(p136215) = {c122215[0],		c122215[1],		c102100[2],	lc102000VFine};	c136215[]={Point{p136215}};
p136220=newp;	Point(p136220) = {c122220[0],		c122220[1],		c102100[2],	lc102000VFine};	c136220[]={Point{p136220}};
//
p136300=newp;	Point(p136300) = {c122300[0],		c122300[1],		c102100[2],	lc102000VFine};	c136300[]={Point{p136300}};
p136305=newp;	Point(p136305) = {c122305[0],		c122305[1],		c102100[2],	lc102000VFine};	c136305[]={Point{p136305}};
p136315=newp;	Point(p136315) = {c122315[0],		c122315[1],		c102100[2],	lc102000VFine};	c136315[]={Point{p136315}};
p136320=newp;	Point(p136320) = {c122320[0],		c122320[1],		c102100[2],	lc102000VFine};	c136320[]={Point{p136320}};
//
//
// _____
// LINES
// Horizontal Lines
L102100=newl;	Line(L102100) = {p102100, p102105};
L102105=newl;	Line(L102105) = {p102105, p102108};
L102108=newl;	Line(L102108) = {p102108, p102110};
L102110=newl;	Line(L102110) = {p102110, p102112};
L102112=newl;	Line(L102112) = {p102112, p102115};
L102115=newl;	Line(L102115) = {p102115, p102120};
L102120=newl;	Line(L102120) = {p102120, p102125};
//
L102312=newl;	Line(L102312) = {p102312, p102314};
L102314=newl;	Line(L102314) = {p102314, p102315};
L102315=newl;	Line(L102315) = {p102315, p102317};
L102317=newl;	Line(L102317) = {p102317, p102318};
L102318=newl;	Line(L102318) = {p102318, p102320};
//
L102352=newl;	Line(L102352) = {p102352, p102355};
L102355=newl;	Line(L102355) = {p102355, p102357};
L102357=newl;	Line(L102357) = {p102357, p102358};
L102358=newl;	Line(L102358) = {p102358, p102360};
//
L102372=newl;	Line(L102372) = {p102372, p102374};
L102374=newl;	Line(L102374) = {p102374, p102375};
L102375=newl;	Line(L102375) = {p102375, p102376};
L102376=newl;	Line(L102376) = {p102376, p102377};
L102377=newl;	Line(L102377) = {p102377, p102378};
L102378=newl;	Line(L102378) = {p102378, p102380};
//
L102500=newl;	Line(L102500) = {p102500, p102505};
L102505=newl;	Line(L102505) = {p102505, p102508};
L102508=newl;	Line(L102508) = {p102508, p102510};
L102510=newl;	Line(L102510) = {p102510, p102512};
L102512=newl;	Line(L102512) = {p102512, p102515};
L102515=newl;	Line(L102515) = {p102515, p102518};
L102518=newl;	Line(L102518) = {p102518, p102525};
//
// Vertical Lines
L202100=newl;	Line(L202100) = {p102100, p102500};
//
L202108=newl;	Line(L202108) = {p102108, p102508};
//
L202110=newl;	Line(L202110) = {p102110, p102210};
L202210=newl;	Line(L202210) = {p102210, p102410};
L202410=newl;	Line(L202410) = {p102410, p102510};
//
L202112=newl;	Line(L202112) = {p102112, p102352};
L202352=newl;	Line(L202352) = {p102352, p102312};
L202312=newl;	Line(L202312) = {p102312, p102372};
L202372=newl;	Line(L202372) = {p102372, p102512};
//
L202360=newl;	Line(L202360) = {p102360, p102320};
L202320=newl;	Line(L202320) = {p102320, p102380};
//
L202125=newl;	Line(L202125) = {p102125, p102525};
//
// Anchorage end-plate North
L135000=newl;	Line(L135000) = {p135000, p135005};
L135005=newl;	Line(L135005) = {p135005, p135015};
L135015=newl;	Line(L135015) = {p135015, p135020};
L135200=newl;	Line(L135200) = {p135200, p135205};
L135215=newl;	Line(L135215) = {p135215, p135220};
L135300=newl;	Line(L135300) = {p135300, p135305};
L135305=newl;	Line(L135305) = {p135305, p135315};
L135315=newl;	Line(L135315) = {p135315, p135320};
//
L235000=newl;	Line(L235000) = {p135000, p135200};
L235200=newl;	Line(L235200) = {p135200, p135300};
L235005=newl;	Line(L235005) = {p135005, p135205};
L235205=newl;	Line(L235205) = {p135205, p135305};
L235015=newl;	Line(L235015) = {p135015, p135215};
L235215=newl;	Line(L235215) = {p135215, p135315};
L235020=newl;	Line(L235020) = {p135020, p135220};
L235220=newl;	Line(L235220) = {p135220, p135320};
//
// Anchorage end-plate South
L136000=newl;	Line(L136000) = {p136000, p102314};
L136314=newl;	Line(L136314) = {p102314, p136005};
L136005=newl;	Line(L136005) = {p136005, p102355};
L136355=newl;	Line(L136355) = {p102355, p136015};
L136015=newl;	Line(L136015) = {p136015, p136020};
//
L136200=newl;	Line(L136200) = {p136200, p102375};
L136375=newl;	Line(L136375) = {p102375, p136205};
L136215=newl;	Line(L136215) = {p136215, p136220};
//
L136300=newl;	Line(L136300) = {p136300, p136305};
L136305=newl;	Line(L136305) = {p136305, p136315};
L136315=newl;	Line(L136315) = {p136315, p136320};
//
L236000=newl;	Line(L236000) = {p136000, p102374};
L236374=newl;	Line(L236374) = {p102374, p136200};
L236200=newl;	Line(L236200) = {p136200, p136300};
//
L236005=newl;	Line(L236005) = {p136005, p102315};
L236315=newl;	Line(L236315) = {p102315, p136205};
L236205=newl;	Line(L236205) = {p136205, p102376};
L236376=newl;	Line(L236376) = {p102376, p136305};
//
L236015=newl;	Line(L236015) = {p136015, p102357};
L236357=newl;	Line(L236357) = {p102357, p136215};
L236215=newl;	Line(L236215) = {p136215, p102317};
L236317=newl;	Line(L236317) = {p102317, p102377};
L236377=newl;	Line(L236377) = {p102377, p136315};
//
L236020=newl;	Line(L236020) = {p136020, p102358};
L236358=newl;	Line(L236358) = {p102358, p136220};
L236220=newl;	Line(L236220) = {p136220, p102318};
L236318=newl;	Line(L236318) = {p102318, p102378};
L236378=newl;	Line(L236378) = {p102378, p136320};
//
// __________
// LINE LOOPS
//
// 
LL102001=newl;	Line Loop(LL102001) =	{L102100,L102105,L202108,-L102505,-L102500,-L202100};
LL102002=newl;	Line Loop(LL102002) =	{L102108,L202110,L202210,L202410,-L102508,-L202108};
LL102003=newl;	Line Loop(LL102003) =	{L102110,L202112,L202352,L202312,L202372,-L102510,-L202410,-L202210,-L202110};
LL102004=newl;	Line Loop(LL102004) =	{L102112,L102115,L102120,L202125,-L102518,-L102515,-L102512,-L202372,L102372,
					L236374,L236200,L136300,L136305,L136315,-L236378,L102378,-L202320,-L202360,
					-L102358,-L236020,-L136015,-L136355,-L102352,-L202112};
//
LL102011=newl;	Line Loop(LL102011) =	{L102352,-L136005,-L136314,-L102312,-L202352};
LL102012=newl;	Line Loop(LL102012) =	{L102358,L202360,-L102318,-L236220,-L236358};
LL102013=newl;	Line Loop(LL102013) =	{L102312,-L136000,L236000,-L102372,-L202312};
LL102014=newl;	Line Loop(LL102014) =	{L102318,L202320,-L102378,-L236318};
//
// Anchorage end-plate North
LL135001=newl;	Line Loop(LL135001) =	{L135000,L235005,-L135200,-L235000};
LL135002=newl;	Line Loop(LL135002) =	{L135005,L235015,L235215,-L135305,-L235205,-L235005};
LL135003=newl;	Line Loop(LL135003) =	{L135015,L235020,-L135215,-L235015};
LL135004=newl;	Line Loop(LL135004) =	{L135200,L235205,-L135300,-L235200};
LL135005=newl;	Line Loop(LL135005) =	{L135215,L235220,-L135315,-L235215};
LL135010=newl;	Line Loop(LL135010) =	{L135000,L135005,L135015,L235020,L235220,-L135315,-L135305,-L135300,-L235200,-L235000};
//
// Anchorage end-plate South
LL136001=newl;	Line Loop(LL136001) =	{L136000,L102314,L236315,-L136375,-L102374,-L236000};
LL136002=newl;	Line Loop(LL136002) =	{L136314,L236005,-L102314};
LL136003=newl;	Line Loop(LL136003) =	{L136005,L102355,L236357,L236215,-L102315,-L236005};
LL136004=newl;	Line Loop(LL136004) =	{L136355,L236015,-L102355};
LL136005=newl;	Line Loop(LL136005) =	{L136015,L236020,-L102357,-L236015};
LL136006=newl;	Line Loop(LL136006) =	{L102357,L236358,-L136215,-L236357};
LL136007=newl;	Line Loop(LL136007) =	{L136375,L236205,-L102375};
LL136008=newl;	Line Loop(LL136008) =	{L102315,L236317,-L102376,-L236205,-L236315};
LL136009=newl;	Line Loop(LL136009) =	{L102317,L236318,-L102377,-L236317};
LL136010=newl;	Line Loop(LL136010) =	{L136215,L236220,-L102317,-L236215};
LL136011=newl;	Line Loop(LL136011) =	{L136200,L102375,L236376,-L136300,-L236200};
LL136012=newl;	Line Loop(LL136012) =	{L102376,L236377,-L136305,-L236376};
LL136013=newl;	Line Loop(LL136013) =	{L102377,L236378,-L136315,-L236377};
LL136014=newl;	Line Loop(LL136014) =	{L102374,-L136200,-L236374};
//
// ________
// SURFACES
PS102001=news;	Plane Surface(PS102001) =	{LL102001,LL135010};
PS102002=news;	Plane Surface(PS102002) =	{LL102002};
PS102003=news;	Plane Surface(PS102003) =	{LL102003};
PS102004=news;	Plane Surface(PS102004) =	{LL102004};
//
PS102011=news;	Plane Surface(PS102011) =	{LL102011};
PS102012=news;	Plane Surface(PS102012) =	{LL102012};
PS102013=news;	Plane Surface(PS102013) =	{LL102013};
PS102014=news;	Plane Surface(PS102014) =	{LL102014};
//
// Anchorage end-plates
PS135001=news;	Plane Surface(PS135001) =	{LL135001};
PS135002=news;	Plane Surface(PS135002) =	{LL135002};
PS135003=news;	Plane Surface(PS135003) =	{LL135003};
PS135004=news;	Plane Surface(PS135004) =	{LL135004};
PS135005=news;	Plane Surface(PS135005) =	{LL135005};
//
PS136001=news;	Plane Surface(PS136001) =	{LL136001};
PS136002=news;	Plane Surface(PS136002) =	{LL136002};
PS136003=news;	Plane Surface(PS136003) =	{LL136003};
PS136004=news;	Plane Surface(PS136004) =	{LL136004};
PS136005=news;	Plane Surface(PS136005) =	{LL136005};
PS136006=news;	Plane Surface(PS136006) =	{LL136006};
PS136007=news;	Plane Surface(PS136007) =	{LL136007};
PS136008=news;	Plane Surface(PS136008) =	{LL136008};
PS136009=news;	Plane Surface(PS136009) =	{LL136009};
PS136010=news;	Plane Surface(PS136010) =	{LL136010};
PS136011=news;	Plane Surface(PS136011) =	{LL136011};
PS136012=news;	Plane Surface(PS136012) =	{LL136012};
PS136013=news;	Plane Surface(PS136013) =	{LL136013};
PS136014=news;	Plane Surface(PS136014) =	{LL136014};
//

//
/********************************************************************* 
 *
 *  TIE FLANGE TOP
 *
 *********************************************************************/
//
lc103000 = lcCoarse;
lc103000Med = lcMed;
lc103000Fine = lcFine;
lc103000VFine = lcVFine;
// ______
// POINTS
//
// Interface East Web 
p103100=p101500;	c103100[]={Point{p103100}};
p103108=p101508;	c103108[]={Point{p103108}};
p103110=p101510;	c103110[]={Point{p103110}};
p103112=p101512;	c103112[]={Point{p103112}};
p103125=p101525;	c103125[]={Point{p103125}};
//
p103200=newp;	Point(p103200) = {c102500[0],		c103100[1],		c103100[2]+6.5,		lc103000};	c103200[]={Point{p103200}};
p103205=newp;	Point(p103205) = {c102505[0],		c103100[1],		c103200[2],		lc103000Med};	c103205[]={Point{p103205}};
p103210=newp;	Point(p103210) = {c102510[0],		c103100[1],		c103200[2],		lc103000Fine};	c103210[]={Point{p103210}};
p103215=newp;	Point(p103215) = {c102515[0],		c103100[1],		c103200[2],		lc103000Med};	c103215[]={Point{p103215}};
p103225=newp;	Point(p103225) = {c102525[0],		c103100[1],		c103200[2],		lc103000};	c103225[]={Point{p103225}};
//
p103290=newp;	Point(p103290) = {c103215[0],		c103100[1],		zinit-13.8125,		lc103000};	c103290[]={Point{p103290}};
//
p103300=newp;	Point(p103300) = {c102500[0],		c103100[1],		c102500[2]-6.5,		lc103000};	c103300[]={Point{p103300}};
p103305=newp;	Point(p103305) = {c102505[0],		c103100[1],		c103300[2],		lc103000Med};	c103305[]={Point{p103305}};
p103310=newp;	Point(p103310) = {c102510[0],		c103100[1],		c103300[2],		lc103000Fine};	c103310[]={Point{p103310}};
//p103315=newp;	Point(p103315) = {c102515[0],		c103100[1],		c103300[2],		lc103000Med};	c103315[]={Point{p103315}};
p103315=newp;	Point(p103315) = {c103310[0]+17.125,	c103100[1],		c103300[2],		lc103000Med};	c103315[]={Point{p103315}};
p103325=newp;	Point(p103325) = {c102525[0],		c103100[1],		c103300[2],		lc103000};	c103325[]={Point{p103325}};
// Interface West Web 
p103400=p102500;	c103400[]={Point{p103400}};
p103405=p102505;	c103405[]={Point{p103405}};
p103408=p102508;	c103408[]={Point{p103408}};
p103410=p102510;	c103410[]={Point{p103410}};
p103412=p102512;	c103412[]={Point{p103412}};
p103415=p102515;	c103415[]={Point{p103415}};
p103418=p102518;	c103418[]={Point{p103418}};
p103425=p102525;	c103425[]={Point{p103425}};
//
// Center Point for transition curve of gusset plate
p103990=newp;	Point(p103990) = {c103110[0]+40,	c103100[1],		c103410[2]-13.8125,	lc103000};	c103990[]={Point{p103990}};
//
// North Hole for Cable
p103600=newp;	Point(p103600) = {xCableN-(yFlTop-yCableN)*Tan(thetaN*Pi/180),	yFlTop,	zCableN,		lc103000VFine};	c103600[]={Point{p103600}};
p103601=newp;	Point(p103601) = {c103600[0],			c103600[1],		c103600[2]+holeWidth/2,	lc103000VFine};	c103601[]={Point{p103601}};
p103602=newp;	Point(p103602) = {c103600[0]+holeLength/2,	c103600[1],		c103600[2],		lc103000VFine};	c103602[]={Point{p103602}};
p103603=newp;	Point(p103603) = {c103600[0],			c103600[1],		c103600[2]-holeWidth/2,	lc103000VFine};	c103603[]={Point{p103603}};
p103604=newp;	Point(p103604) = {c103600[0]-holeLength/2,	c103600[1],		c103600[2],		lc103000VFine};	c103604[]={Point{p103604}};
p103701=newp;	Point(p103701) = {c103601[0],			c103601[1],		c103601[2]+wRingPlatez,	lc103000VFine};	c103701[]={Point{p103701}};
p103702=newp;	Point(p103702) = {c103602[0]+wRingPlatex,	c103602[1],		c103602[2],		lc103000VFine};	c103702[]={Point{p103702}};
p103703=newp;	Point(p103703) = {c103603[0],			c103603[1],		c103603[2]-wRingPlatez,	lc103000VFine};	c103703[]={Point{p103703}};
p103704=newp;	Point(p103704) = {c103604[0]-wRingPlatex,	c103604[1],		c103604[2],		lc103000VFine};	c103704[]={Point{p103704}};
//
// South Hole for Cable
p103800=newp;	Point(p103800) = {xCableS-(yFlTop-yCableS)*Tan(thetaS*Pi/180),	yFlTop,	zCableS,		lc103000VFine};	c103800[]={Point{p103800}};
p103801=newp;	Point(p103801) = {c103800[0],			c103800[1],		c103800[2]-holeWidth/2,	lc103000VFine};	c103801[]={Point{p103801}};
p103802=newp;	Point(p103802) = {c103800[0]-holeLength/2,	c103800[1],		c103800[2],		lc103000VFine};	c103802[]={Point{p103802}};
p103803=newp;	Point(p103803) = {c103800[0],			c103800[1],		c103800[2]+holeWidth/2,	lc103000VFine};	c103803[]={Point{p103803}};
p103804=newp;	Point(p103804) = {c103800[0]+holeLength/2,	c103800[1],		c103800[2],		lc103000VFine};	c103804[]={Point{p103804}};
p103901=newp;	Point(p103901) = {c103801[0],			c103801[1],		c103801[2]-wRingPlatez,	lc103000VFine};	c103901[]={Point{p103901}};
p103902=newp;	Point(p103902) = {c103802[0]-wRingPlatex,	c103802[1],		c103802[2],		lc103000VFine};	c103902[]={Point{p103902}};
p103903=newp;	Point(p103903) = {c103803[0],			c103803[1],		c103803[2]+wRingPlatez,	lc103000VFine};	c103903[]={Point{p103903}};
p103904=newp;	Point(p103904) = {c103804[0]+wRingPlatex,	c103804[1],		c103804[2],		lc103000VFine};	c103904[]={Point{p103904}};
//
// _____
// LINES
// Horizontal Lines
L103100=L101500;
L103108=L101508;
L103110=L101510;
L103112=L101512;
//
L103200=newl;	Line(L103200) = {p103200, p103205};
L103205=newl;	Line(L103205) = {p103205, p103210};
L103210=newl;	Line(L103210) = {p103210, p103215};
L103215=newl;	Line(L103215) = {p103215, p103225};
//
L103300=newl;	Line(L103300) = {p103300, p103305};
L103305=newl;	Line(L103305) = {p103305, p103310};
L103310=newl;	Line(L103310) = {p103310, p103315};
L103315=newl;	Line(L103315) = {p103315, p103325};
//
L103400=L102500;
L103405=L102505;
L103408=L102508;
L103410=L102510;
L103412=L102512;
L103415=L102515;
L103418=L102518;
//
// Vertical Lines
L203100=newl;	Line(L203100) = {p103100, p103200};
L203200=newl;	Line(L203200) = {p103200, p103300};
L203300=newl;	Line(L203300) = {p103300, p103400};
//
L203205=newl;	Line(L203205) = {p103205, p103305};
L203305=newl;	Line(L203305) = {p103305, p103405};
//
L203110=newl;	Line(L203110) = {p103110, p103210};
L203210=newl;	Line(L203210) = {p103210, p103310};
L203310=newl;	Line(L203310) = {p103310, p103410};
//
L203215=newl;	Line(L203215) = {p103215, p103290};
L203290=newl;	Circle(L203290) = {p103290, p103990, p103315};
L203315=newl;	Circle(L203315) = {p103315, p103990, p103418};
//
L203125=newl;	Line(L203125) = {p103125, p103225};
L203225=newl;	Line(L203225) = {p103225, p103325};
L203325=newl;	Line(L203325) = {p103325, p103425};
//
// North Hole for Cable
L103601=newl;	Ellipse(L103601) = {p103601, p103600,p103602,p103602};
L103602=newl;	Ellipse(L103602) = {p103602, p103600,p103602,p103603};
L103603=newl;	Ellipse(L103603) = {p103603, p103600,p103604,p103604};
L103604=newl;	Ellipse(L103604) = {p103604, p103600,p103604,p103601};
L103701=newl;	Ellipse(L103701) = {p103701, p103600,p103702,p103702};
L103702=newl;	Ellipse(L103702) = {p103702, p103600,p103702,p103703};
L103703=newl;	Ellipse(L103703) = {p103703, p103600,p103704,p103704};
L103704=newl;	Ellipse(L103704) = {p103704, p103600,p103704,p103701};
// radii
L103711=newl;	Line(L103711) = {p103601, p103701};
L103712=newl;	Line(L103712) = {p103602, p103702};
L103713=newl;	Line(L103713) = {p103603, p103703};
L103714=newl;	Line(L103714) = {p103604, p103704};
//
// South Hole for Cable
L103801=newl;	Ellipse(L103801) = {p103801, p103800,p103802,p103802};
L103802=newl;	Ellipse(L103802) = {p103802, p103800,p103802,p103803};
L103803=newl;	Ellipse(L103803) = {p103803, p103800,p103804,p103804};
L103804=newl;	Ellipse(L103804) = {p103804, p103800,p103804,p103801};
L103901=newl;	Ellipse(L103901) = {p103901, p103800,p103902,p103902};
L103902=newl;	Ellipse(L103902) = {p103902, p103800,p103902,p103903};
L103903=newl;	Ellipse(L103903) = {p103903, p103800,p103904,p103904};
L103904=newl;	Ellipse(L103904) = {p103904, p103800,p103904,p103901};
// radii
L103911=newl;	Line(L103911) = {p103801, p103901};
L103912=newl;	Line(L103912) = {p103802, p103902};
L103913=newl;	Line(L103913) = {p103803, p103903};
L103914=newl;	Line(L103914) = {p103804, p103904};
//
// __________
// LINE LOOPS
//
// 
LL103001=newl;	Line Loop(LL103001) =	{L103100,L103108,L203110,-L103205,-L103200,-L203100};
LL103002=newl;	Line Loop(LL103002) =	{L103110,L103112,L203125,-L103215,-L103210,-L203110};
//
LL103003=newl;	Line Loop(LL103003) =	{L103200,L203205,-L103300,-L203200};
LL103004=newl;	Line Loop(LL103004) =	{L103205,L203210,-L103305,-L203205};
LL103005=newl;	Line Loop(LL103005) =	{L103210,L203215,L203290,-L103310,-L203210};
LL103006=newl;	Line Loop(LL103006) =	{L103215,L203225,-L103315,-L203290,-L203215};
//
LL103007=newl;	Line Loop(LL103007) =	{L103300,L203305,-L103400,-L203300};
LL103008=newl;	Line Loop(LL103008) =	{L103305,L203310,-L103408,-L103405,-L203305};
LL103009=newl;	Line Loop(LL103009) =	{L103310,L203315,-L103415,-L103412,-L103410,-L203310};
LL103010=newl;	Line Loop(LL103010) =	{L103315,L203325,-L103418,-L203315};
//
// North Hole for Cable
LL103601=newl;	Line Loop(LL103601) =	{L103601,L103602,L103603,L103604};
// North Ringplate
LL103701=newl;	Line Loop(LL103701) =	{L103701,L103702,L103703,L103704};
LL103702=newl;	Line Loop(LL103702) =	{L103601,L103712,-L103701,-L103711};
LL103703=newl;	Line Loop(LL103703) =	{L103602,L103713,-L103702,-L103712};
LL103704=newl;	Line Loop(LL103704) =	{L103603,L103714,-L103703,-L103713};
LL103705=newl;	Line Loop(LL103705) =	{L103604,L103711,-L103704,-L103714};
//
// South Hole for Cable
LL103801=newl;	Line Loop(LL103801) =	{L103801,L103802,L103803,L103804};
// South Ringplate
LL103901=newl;	Line Loop(LL103901) =	{L103901,L103902,L103903,L103904};
LL103902=newl;	Line Loop(LL103902) =	{L103801,L103912,-L103901,-L103911};
LL103903=newl;	Line Loop(LL103903) =	{L103802,L103913,-L103902,-L103912};
LL103904=newl;	Line Loop(LL103904) =	{L103803,L103914,-L103903,-L103913};
LL103905=newl;	Line Loop(LL103905) =	{L103804,L103911,-L103904,-L103914};
//
// ________
// SURFACES
PS103001=news;	Plane Surface(PS103001) =	{LL103001};
PS103002=news;	Plane Surface(PS103002) =	{LL103002};
PS103003=news;	Plane Surface(PS103003) =	{LL103003,LL103701};
PS103004=news;	Plane Surface(PS103004) =	{LL103004};
PS103005=news;	Plane Surface(PS103005) =	{LL103005};
PS103006=news;	Plane Surface(PS103006) =	{LL103006,LL103901};
PS103007=news;	Plane Surface(PS103007) =	{LL103007};
PS103008=news;	Plane Surface(PS103008) =	{LL103008};
PS103009=news;	Plane Surface(PS103009) =	{LL103009};
PS103010=news;	Plane Surface(PS103010) =	{LL103010};
//
//North Hole for Cable
PS103702=news;	Plane Surface(PS103702) =	{LL103702};
PS103703=news;	Plane Surface(PS103703) =	{LL103703};
PS103704=news;	Plane Surface(PS103704) =	{LL103704};
PS103705=news;	Plane Surface(PS103705) =	{LL103705};
//
//North Hole for Cable
PS103902=news;	Plane Surface(PS103902) =	{LL103902};
PS103903=news;	Plane Surface(PS103903) =	{LL103903};
PS103904=news;	Plane Surface(PS103904) =	{LL103904};
PS103905=news;	Plane Surface(PS103905) =	{LL103905};
//
//
//
/********************************************************************* 
 *
 *  TIE FLANGE TOP, GUIDE PIPE NORTH
 *
 *********************************************************************/
//
// ______
// POINTS
//
// MID OF STIFFENERS (FINS)
c103751[] = Translate {-2*Sin(thetaN*Pi/180),2*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103701}; } } ; p103751 = c103751[0];
c103752[] = Translate {-2*Sin(thetaN*Pi/180),2*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103702}; } } ; p103752 = c103752[0];
c103753[] = Translate {-2*Sin(thetaN*Pi/180),2*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103703}; } } ; p103753 = c103753[0];
c103754[] = Translate {-2*Sin(thetaN*Pi/180),2*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103704}; } } ; p103754 = c103754[0];
//
// TOP OF STIFFENERS (FINS)
c103760[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103600}; } } ; p103760 = c103760[0];
c103761[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103601}; } } ; p103761 = c103761[0];
c103762[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103602}; } } ; p103762 = c103762[0];
c103763[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103603}; } } ; p103763 = c103763[0];
c103764[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103604}; } } ; p103764 = c103764[0];
//
// END OF PIPE (SLICE PARALLEL TO RIB FLANGE) (DEPRECATED)
//
//c103770[] = Translate {-36*Sin(thetaN*Pi/180),36*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103600}; } } ; p103770 = c103770[0];
//c103771[] = Translate {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103761}; } } ; p103771 = c103771[0];
//c103772[] = Translate {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103762}; } } ; p103772 = c103772[0];
//c103773[] = Translate {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103763}; } } ; p103773 = c103773[0];
//c103774[] = Translate {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103764}; } } ; p103774 = c103774[0];
//
//
// END OF PIPE (SLICE ORTHOGONAL TO PIPE AXIS)
//
If (thetaN < 0)
	c103780[] = Translate	{-36*Sin(thetaN*Pi/180),
				36*Cos(thetaN*Pi/180),
				0} 
				{Duplicata { Point {p103600}; } } ; p103780 = c103780[0];
	c103781[] = Translate	{-30*Sin(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180),
				0} 
				{Duplicata { Point {p103761}; } } ; p103781 = c103781[0];
	c103782[] = Translate	{-30*Sin(thetaN*Pi/180) + DiaCable/2*Sin(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180) - DiaCable/2*Cos(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				0} 
				{Duplicata { Point {p103762}; } } ; p103782 = c103782[0];
	c103783[] = Translate	{-30*Sin(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180),
				0} {Duplicata { Point {p103763}; } } ; p103783 = c103783[0];
	c103784[] = Translate	{-30*Sin(thetaN*Pi/180) - DiaCable/2*Sin(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180) + DiaCable/2*Cos(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				0} {Duplicata { Point {p103764}; } } ; p103784 = c103784[0];
	c103790[] = Translate	{-48*Sin(thetaN*Pi/180),48*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103600}; } } ; p103790 = c103790[0];
EndIf
If (thetaN > 0)
	c103780[] = Translate	{-36*Sin(thetaN*Pi/180),
				36*Cos(thetaN*Pi/180),
				0} 
				{Duplicata { Point {p103600}; } } ; p103780 = c103780[0];
	c103781[] = Translate	{-30*Sin(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180),
				0} 
				{Duplicata { Point {p103761}; } } ; p103781 = c103781[0];
	c103782[] = Translate	{-30*Sin(thetaN*Pi/180) - DiaCable/2*Sin(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180) + DiaCable/2*Cos(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				0} {Duplicata { Point {p103762}; } } ; p103782 = c103782[0];
	c103783[] = Translate	{-30*Sin(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180),
				0} {Duplicata { Point {p103763}; } } ; p103783 = c103783[0];
	c103784[] = Translate	{-30*Sin(thetaN*Pi/180) + DiaCable/2*Sin(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				30*Cos(thetaN*Pi/180) - DiaCable/2*Cos(thetaN*Pi/180)*Tan(thetaN*Pi/180),
				0} {Duplicata { Point {p103764}; } } ; p103784 = c103784[0];
	c103790[] = Translate	{-48*Sin(thetaN*Pi/180),48*Cos(thetaN*Pi/180),0} {Duplicata { Point {p103600}; } } ; p103790 = c103790[0];
EndIf
//
// _____
// LINES
// 
L103751=newl; Line(L103751) = {p103701, p103751};
L103752=newl; Line(L103752) = {p103702, p103752};
L103753=newl; Line(L103753) = {p103703, p103753};
L103754=newl; Line(L103754) = {p103704, p103754};
//
L103761=newl; Line(L103761) = {p103751, p103761};
L103762=newl; Line(L103762) = {p103752, p103762};
L103763=newl; Line(L103763) = {p103753, p103763};
L103764=newl; Line(L103764) = {p103754, p103764};
//
L103771=newl; Line(L103771) = {p103761, p103601};
L103772=newl; Line(L103772) = {p103762, p103602};
L103773=newl; Line(L103773) = {p103763, p103603};
L103774=newl; Line(L103774) = {p103764, p103604};
// radii
L103781=L103711;
L103782=L103712;
L103783=L103713;
L103784=L103714;
// ellipse at end of pipe
L103791=newl; Ellipse(L103791) = {p103781,p103780,p103782,p103782};
L103792=newl; Ellipse(L103792) = {p103782,p103780,p103782,p103783};
L103793=newl; Ellipse(L103793) = {p103783,p103780,p103784,p103784};
L103794=newl; Ellipse(L103794) = {p103784,p103780,p103784,p103781};
// 
// connect ellipses with lines along axis of pipe
L103795=newl; Line(L103795) = {p103761,p103781};
L103796=newl; Line(L103796) = {p103762,p103782};
L103797=newl; Line(L103797) = {p103763,p103783};
L103798=newl; Line(L103798) = {p103764,p103784};
//
// ellipse at tip of stiffeners (fins)
L103651=newl; Ellipse(L103651) = {p103761,p103760,p103762,p103762};
L103652=newl; Ellipse(L103652) = {p103762,p103760,p103762,p103763};
L103653=newl; Ellipse(L103653) = {p103763,p103760,p103764,p103764};
L103654=newl; Ellipse(L103654) = {p103764,p103760,p103764,p103761};
//Ld103651[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103601}; } } ; L103651 = Ld103651[0];
//Ld103652[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103602}; } } ; L103652 = Ld103652[0];
//Ld103653[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103603}; } } ; L103653 = Ld103653[0];
//Ld103654[] = Translate {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103604}; } } ; L103654 = Ld103654[0];
//
// ellipse at end of pipe parallel to flange (deprecated)
//Ld103661[] = Translate {-36*Sin(thetaN*Pi/180),36*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103601}; } } ; L103661 = Ld103661[0];
//Ld103662[] = Translate {-36*Sin(thetaN*Pi/180),36*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103602}; } } ; L103662 = Ld103662[0];
//Ld103663[] = Translate {-36*Sin(thetaN*Pi/180),36*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103603}; } } ; L103663 = Ld103663[0];
//Ld103664[] = Translate {-36*Sin(thetaN*Pi/180),36*Cos(thetaN*Pi/180),0} {Duplicata { Line {L103604}; } } ; L103664 = Ld103664[0];
//
// connectivity member at free end of pipe
L103671=newl; Line(L103671) = {p103780,p103790};
//
// __________
// LINE LOOPS
//
LL103701=newl; Line Loop(LL103701) = {L103751,L103761,L103771,L103781};
LL103702=newl; Line Loop(LL103702) = {L103752,L103762,L103772,L103782};
LL103703=newl; Line Loop(LL103703) = {L103753,L103763,L103773,L103783};
LL103704=newl; Line Loop(LL103704) = {L103754,L103764,L103774,L103784};
// BASE of guide pipe
LL103601=newl; Line Loop(LL103601) = {L103601,-L103772,-L103651,L103771};
LL103602=newl; Line Loop(LL103602) = {L103602,-L103773,-L103652,L103772};
LL103603=newl; Line Loop(LL103603) = {L103603,-L103774,-L103653,L103773};
LL103604=newl; Line Loop(LL103604) = {L103604,-L103771,-L103654,L103774};
// end of guide pipe
LL103661=newl; Line Loop(LL103661) = {L103651,L103796,-L103791,-L103795};
LL103662=newl; Line Loop(LL103662) = {L103652,L103797,-L103792,-L103796};
LL103663=newl; Line Loop(LL103663) = {L103653,L103798,-L103793,-L103797};
LL103664=newl; Line Loop(LL103664) = {L103654,L103795,-L103794,-L103798};
//
// ________
// SURFACES
PS103751=news; Plane Surface(PS103751) = {LL103701};
PS103752=news; Plane Surface(PS103752) = {LL103702};
PS103753=news; Plane Surface(PS103753) = {LL103703};
PS103754=news; Plane Surface(PS103754) = {LL103704};
//
// BASE of guide pipe
PSpipe103601=news; Ruled Surface(PSpipe103601) = {LL103601};
PSpipe103602=news; Ruled Surface(PSpipe103602) = {LL103602};
PSpipe103603=news; Ruled Surface(PSpipe103603) = {LL103603};
PSpipe103604=news; Ruled Surface(PSpipe103604) = {LL103604};
// end of guide pipe
PSpipe103661=news; Ruled Surface(PSpipe103661) = {LL103661};
PSpipe103662=news; Ruled Surface(PSpipe103662) = {LL103662};
PSpipe103663=news; Ruled Surface(PSpipe103663) = {LL103663};
PSpipe103664=news; Ruled Surface(PSpipe103664) = {LL103664};
//
//
// __________
// EXTRUSIONS
//Extrude Line { L103651, {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103651 = news-1;
//Extrude Line { L103652, {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103652 = news-1;
//Extrude Line { L103653, {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103653 = news-1;
//Extrude Line { L103654, {-30*Sin(thetaN*Pi/180),30*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103654 = news-1;
//
//Extrude Line { L103601, {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103601 = news-1;
//Extrude Line { L103602, {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103602 = news-1;
//Extrude Line { L103603, {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103603 = news-1;
//Extrude Line { L103604, {-6*Sin(thetaN*Pi/180),6*Cos(thetaN*Pi/180),0} } {Recombine;}; PSpipe103604 = news-1;
//
//
//
//
//
/********************************************************************* 
 *
 *  TIE FLANGE TOP, GUIDE PIPE SOUTH
 *
 *********************************************************************/
//
// ______
// POINTS
//
// MID OF STIFFENERS (FINS)
c103951[] = Translate {-2*Sin(thetaS*Pi/180),2*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103901}; } } ; p103951 = c103951[0];
c103952[] = Translate {-2*Sin(thetaS*Pi/180),2*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103902}; } } ; p103952 = c103952[0];
c103953[] = Translate {-2*Sin(thetaS*Pi/180),2*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103903}; } } ; p103953 = c103953[0];
c103954[] = Translate {-2*Sin(thetaS*Pi/180),2*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103904}; } } ; p103954 = c103954[0];
//
// TOP OF STIFFENERS (FINS)
c103960[] = Translate {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103800}; } } ; p103960 = c103960[0];
c103961[] = Translate {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103801}; } } ; p103961 = c103961[0];
c103962[] = Translate {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103802}; } } ; p103962 = c103962[0];
c103963[] = Translate {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103803}; } } ; p103963 = c103963[0];
c103964[] = Translate {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103804}; } } ; p103964 = c103964[0];
//
//
// END OF PIPE (SLICE ORTHOGONAL TO PIPE AXIS)
//
If (thetaS < 0)
	c103980[] = Translate	{-36*Sin(thetaS*Pi/180),
				36*Cos(thetaS*Pi/180),
				0} 
				{Duplicata { Point {p103800}; } } ; p103980 = c103980[0];
	c103981[] = Translate	{-30*Sin(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180),
				0} 
				{Duplicata { Point {p103961}; } } ; p103981 = c103981[0];
	c103982[] = Translate	{-30*Sin(thetaS*Pi/180) + DiaCable/2*Sin(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180) - DiaCable/2*Cos(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				0} 
				{Duplicata { Point {p103962}; } } ; p103982 = c103982[0];
	c103983[] = Translate	{-30*Sin(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180),
				0} {Duplicata { Point {p103963}; } } ; p103983 = c103983[0];
	c103984[] = Translate	{-30*Sin(thetaS*Pi/180) - DiaCable/2*Sin(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180) + DiaCable/2*Cos(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				0} {Duplicata { Point {p103964}; } } ; p103984 = c103984[0];
	c103990[] = Translate	{-48*Sin(thetaS*Pi/180),48*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103800}; } } ; p103990 = c103990[0];
EndIf
If (thetaS > 0)
	c103980[] = Translate	{-36*Sin(thetaS*Pi/180),
				36*Cos(thetaS*Pi/180),
				0} 
				{Duplicata { Point {p103800}; } } ; p103980 = c103980[0];
	c103981[] = Translate	{-30*Sin(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180),
				0} 
				{Duplicata { Point {p103961}; } } ; p103981 = c103981[0];
	c103982[] = Translate	{-30*Sin(thetaS*Pi/180) - DiaCable/2*Sin(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180) + DiaCable/2*Cos(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				0} {Duplicata { Point {p103962}; } } ; p103982 = c103982[0];
	c103983[] = Translate	{-30*Sin(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180),
				0} {Duplicata { Point {p103963}; } } ; p103983 = c103983[0];
	c103984[] = Translate	{-30*Sin(thetaS*Pi/180) + DiaCable/2*Sin(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				30*Cos(thetaS*Pi/180) - DiaCable/2*Cos(thetaS*Pi/180)*Tan(thetaS*Pi/180),
				0} {Duplicata { Point {p103964}; } } ; p103984 = c103984[0];
	c103990[] = Translate	{-48*Sin(thetaS*Pi/180),48*Cos(thetaS*Pi/180),0} {Duplicata { Point {p103800}; } } ; p103990 = c103990[0];
EndIf
//
// _____
// LINES
// 
L103951=newl; Line(L103951) = {p103901, p103951};
L103952=newl; Line(L103952) = {p103902, p103952};
L103953=newl; Line(L103953) = {p103903, p103953};
L103954=newl; Line(L103954) = {p103904, p103954};
//
L103961=newl; Line(L103961) = {p103951, p103961};
L103962=newl; Line(L103962) = {p103952, p103962};
L103963=newl; Line(L103963) = {p103953, p103963};
L103964=newl; Line(L103964) = {p103954, p103964};
//
L103971=newl; Line(L103971) = {p103961, p103801};
L103972=newl; Line(L103972) = {p103962, p103802};
L103973=newl; Line(L103973) = {p103963, p103803};
L103974=newl; Line(L103974) = {p103964, p103804};
// radii
L103981=L103911;
L103982=L103912;
L103983=L103913;
L103984=L103914;
// ellipse at end of pipe
L103991=newl; Ellipse(L103991) = {p103981,p103980,p103982,p103982};
L103992=newl; Ellipse(L103992) = {p103982,p103980,p103982,p103983};
L103993=newl; Ellipse(L103993) = {p103983,p103980,p103984,p103984};
L103994=newl; Ellipse(L103994) = {p103984,p103980,p103984,p103981};
// 
// connect ellipses with lines along axis of pipe
L103995=newl; Line(L103995) = {p103961,p103981};
L103996=newl; Line(L103996) = {p103962,p103982};
L103997=newl; Line(L103997) = {p103963,p103983};
L103998=newl; Line(L103998) = {p103964,p103984};
//
// ellipse at tip of stiffeners (fins)
L103851=newl; Ellipse(L103851) = {p103961,p103960,p103962,p103962};
L103852=newl; Ellipse(L103852) = {p103962,p103960,p103962,p103963};
L103853=newl; Ellipse(L103853) = {p103963,p103960,p103964,p103964};
L103854=newl; Ellipse(L103854) = {p103964,p103960,p103964,p103961};
//
// connectivity member at free end of pipe
L103871=newl; Line(L103871) = {p103980,p103990};
//
// __________
// LINE LOOPS
//
LL103901=newl; Line Loop(LL103901) = {L103951,L103961,L103971,L103981};
LL103902=newl; Line Loop(LL103902) = {L103952,L103962,L103972,L103982};
LL103903=newl; Line Loop(LL103903) = {L103953,L103963,L103973,L103983};
LL103904=newl; Line Loop(LL103904) = {L103954,L103964,L103974,L103984};
// BASE of guide pipe
LL103801=newl; Line Loop(LL103801) = {L103801,-L103972,-L103851,L103971};
LL103802=newl; Line Loop(LL103802) = {L103802,-L103973,-L103852,L103972};
LL103803=newl; Line Loop(LL103803) = {L103803,-L103974,-L103853,L103973};
LL103804=newl; Line Loop(LL103804) = {L103804,-L103971,-L103854,L103974};
// end of guide pipe
LL103861=newl; Line Loop(LL103861) = {L103851,L103996,-L103991,-L103995};
LL103862=newl; Line Loop(LL103862) = {L103852,L103997,-L103992,-L103996};
LL103863=newl; Line Loop(LL103863) = {L103853,L103998,-L103993,-L103997};
LL103864=newl; Line Loop(LL103864) = {L103854,L103995,-L103994,-L103998};
//
// ________
// SURFACES
PS103951=news; Plane Surface(PS103951) = {LL103901};
PS103952=news; Plane Surface(PS103952) = {LL103902};
PS103953=news; Plane Surface(PS103953) = {LL103903};
PS103954=news; Plane Surface(PS103954) = {LL103904};
//
// BASE of guide pipe
PSpipe103801=news; Ruled Surface(PSpipe103801) = {LL103801};
PSpipe103802=news; Ruled Surface(PSpipe103802) = {LL103802};
PSpipe103803=news; Ruled Surface(PSpipe103803) = {LL103803};
PSpipe103804=news; Ruled Surface(PSpipe103804) = {LL103804};
//
// end of guide pipe
PSpipe103861=news; Ruled Surface(PSpipe103861) = {LL103861};
PSpipe103862=news; Ruled Surface(PSpipe103862) = {LL103862};
PSpipe103863=news; Ruled Surface(PSpipe103863) = {LL103863};
PSpipe103864=news; Ruled Surface(PSpipe103864) = {LL103864};
//
//
// __________
// EXTRUSIONS
//
//Extrude Line { L103801, {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} } {Recombine;}; PSpipe103801 = news-1;
//Extrude Line { L103802, {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} } {Recombine;}; PSpipe103802 = news-1;
//Extrude Line { L103803, {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} } {Recombine;}; PSpipe103803 = news-1;
//Extrude Line { L103804, {-6*Sin(thetaS*Pi/180),6*Cos(thetaS*Pi/180),0} } {Recombine;}; PSpipe103804 = news-1;
//
//
//
//
/********************************************************************* 
 *
 *  TIE FLANGE BOT
 *
 *********************************************************************/
//
lc104000 = lcCoarse;
lc104000Med = lcMed;
lc104000Fine = lcFine;
// ______
// POINTS
//
// Interface East Web 
p104100=p101100;	c104100[]={Point{p104100}};
p104108=p101108;	c104108[]={Point{p104108}};
p104110=p101110;	c104110[]={Point{p104110}};
p104112=p101112;	c104112[]={Point{p104112}};
p104125=p101125;	c104125[]={Point{p104125}};
//
p104200=newp;	Point(p104200) = {c102500[0],		c104100[1],		c103100[2]+6.5,	lc103000};	c104200[]={Point{p104200}};
p104205=newp;	Point(p104205) = {c102505[0],		c104100[1],		c103200[2],	lc103000Med};	c104205[]={Point{p104205}};
p104210=newp;	Point(p104210) = {c102510[0],		c104100[1],		c103200[2],	lc103000Fine};	c104210[]={Point{p104210}};
p104215=newp;	Point(p104215) = {c102515[0],		c104100[1],		c103200[2],	lc103000Med};	c104215[]={Point{p104215}};
p104225=newp;	Point(p104225) = {c102525[0],		c104100[1],		c103200[2],	lc103000};	c104225[]={Point{p104225}};
//
p104300=newp;	Point(p104300) = {c102500[0],		c104100[1],		c102500[2]-6.5,	lc103000};	c104300[]={Point{p104300}};
p104305=newp;	Point(p104305) = {c102505[0],		c104100[1],		c103300[2],	lc103000Med};	c104305[]={Point{p104305}};
p104310=newp;	Point(p104310) = {c102510[0],		c104100[1],		c103300[2],	lc103000Fine};	c104310[]={Point{p104310}};
p104320=newp;	Point(p104320) = {c104215[0],		c104100[1],		c103300[2],	lc103000Med};	c104320[]={Point{p104320}};
p104325=newp;	Point(p104325) = {c102525[0],		c104100[1],		c103300[2],	lc103000};	c104325[]={Point{p104325}};
// Interface West Web 
p104400=p102100;	c104400[]={Point{p104400}};
p104405=p102105;	c104405[]={Point{p104405}};
p104408=p102108;	c104408[]={Point{p104408}};
p104410=p102110;	c104410[]={Point{p104410}};
p104412=p102112;	c104412[]={Point{p104412}};
p104415=p102115;	c104415[]={Point{p104415}};
p104420=p102120;	c104420[]={Point{p104420}};
p104425=p102125;	c104425[]={Point{p104425}};
//
// _____
// LINES
// Horizontal Lines
L104100=L101100;
L104108=L101108;
L104110=L101110;
L104112=L101112;
//
L104200=newl;	Line(L104200) = {p104200, p104205};
L104205=newl;	Line(L104205) = {p104205, p104210};
L104210=newl;	Line(L104210) = {p104210, p104215};
L104215=newl;	Line(L104215) = {p104215, p104225};
//
L104300=newl;	Line(L104300) = {p104300, p104305};
L104305=newl;	Line(L104305) = {p104305, p104310};
L104310=newl;	Line(L104310) = {p104310, p104320};
L104320=newl;	Line(L104320) = {p104320, p104325};
//
L104400=L102100;
L104405=L102105;
L104408=L102108;
L104410=L102110;
L104412=L102112;
L104415=L102115;
L104420=L102120;
//
// Vertical Lines
L204100=newl;	Line(L204100) = {p104100, p104200};
L204200=newl;	Line(L204200) = {p104200, p104300};
L204300=newl;	Line(L204300) = {p104300, p104400};
//
L204205=newl;	Line(L204205) = {p104205, p104305};
L204305=newl;	Line(L204305) = {p104305, p104405};
//
L204110=newl;	Line(L204110) = {p104110, p104210};
L204210=newl;	Line(L204210) = {p104210, p104310};
L204310=newl;	Line(L204310) = {p104310, p104410};
//
L204220=newl;	Line(L204220) = {p104215, p104320};
L204320=newl;	Line(L204320) = {p104320, p104415};
//
L204125=newl;	Line(L204125) = {p104125, p104225};
L204225=newl;	Line(L204225) = {p104225, p104325};
L204325=newl;	Line(L204325) = {p104325, p104425};
//
// __________
// LINE LOOPS
//
// 
LL104001=newl;	Line Loop(LL104001) =	{L104100,L104108,L204110,-L104205,-L104200,-L204100};
LL104002=newl;	Line Loop(LL104002) =	{L104110,L104112,L204125,-L104215,-L104210,-L204110};
//
LL104003=newl;	Line Loop(LL104003) =	{L104200,L204205,-L104300,-L204200};
LL104004=newl;	Line Loop(LL104004) =	{L104205,L204210,-L104305,-L204205};
LL104005=newl;	Line Loop(LL104005) =	{L104210,L204220,-L104310,-L204210};
LL104006=newl;	Line Loop(LL104006) =	{L104215,L204225,-L104320,-L204220};
//
LL104007=newl;	Line Loop(LL104007) =	{L104300,L204305,-L104400,-L204300};
LL104008=newl;	Line Loop(LL104008) =	{L104305,L204310,-L104408,-L104405,-L204305};
LL104009=newl;	Line Loop(LL104009) =	{L104310,L204320,-L104412,-L104410,-L204310};
LL104010=newl;	Line Loop(LL104010) =	{L104320,L204325,-L104420,-L104415,-L204320};
//
// ________
// SURFACES
PS104001=news;	Plane Surface(PS104001) =	{LL104001};
PS104002=news;	Plane Surface(PS104002) =	{LL104002};
PS104003=news;	Plane Surface(PS104003) =	{LL104003};
PS104004=news;	Plane Surface(PS104004) =	{LL104004};
PS104005=news;	Plane Surface(PS104005) =	{LL104005};
PS104006=news;	Plane Surface(PS104006) =	{LL104006};
PS104007=news;	Plane Surface(PS104007) =	{LL104007};
PS104008=news;	Plane Surface(PS104008) =	{LL104008};
PS104009=news;	Plane Surface(PS104009) =	{LL104009};
PS104010=news;	Plane Surface(PS104010) =	{LL104010};
//
/********************************************************************* 
 *
 *  FLOORBEAM TOP FLANGE
 *
 *********************************************************************/
//
lc106000 = lcCoarse;
lc106000Med = lcMed;
lc106000Fine = lcFine;
// ______
// POINTS
//
// Interface East Web 
p106100=p103405;	c106100[]={Point{p106100}};
p106118=p103408;	c106118[]={Point{p106118}};
p106120=p103410;	c106120[]={Point{p106120}};
p106122=p103412;	c106122[]={Point{p106122}};
p106140=p103415;	c106140[]={Point{p106140}};
//
p106151=newp;	Point(p106151) = {c106120[0],		c106100[1]+.02*8,	c106120[2]+8,		lc106000};	c106151[]={Point{p106151}};
//
p106200=newp;	Point(p106200) = {c106100[0],		c106100[1]+.02*35.375,	c106100[2]+35.375,	lc106000};	c106200[]={Point{p106200}};
p106220=newp;	Point(p106220) = {c106120[0],		c106200[1],		c106200[2],		lc106000Med};	c106220[]={Point{p106220}};
p106240=newp;	Point(p106240) = {c106140[0],		c106200[1],		c106200[2],		lc106000};	c106240[]={Point{p106240}};
//
p106251=newp;	Point(p106251) = {c106120[0]-6.5,	c106100[1]+.02*(45.25),	c106100[2]+45.25,	lc106000Fine};	c106251[]={Point{p106251}};
p106252=newp;	Point(p106252) = {c106120[0],		c106251[1],		c106251[2],		lc106000Fine};	c106252[]={Point{p106252}};
p106253=newp;	Point(p106253) = {c106120[0]+6.5,	c106251[1],		c106251[2],		lc106000Fine};	c106253[]={Point{p106253}};
//
p106300=newp;	Point(p106300) = {c106100[0],		c106100[1]+.02*52.25,	c106100[2]+52.25,	lc106000};	c106300[]={Point{p106300}};
p106310=newp;	Point(p106310) = {c106120[0]-12,	c106300[1],		c106300[2],		lc106000};	c106310[]={Point{p106310}};
p106315=newp;	Point(p106315) = {c106120[0]-6.5,	c106300[1],		c106300[2],		lc106000Fine};	c106315[]={Point{p106315}};
p106320=newp;	Point(p106320) = {c106120[0],		c106300[1],		c106300[2],		lc106000Med};	c106320[]={Point{p106320}};
p106325=newp;	Point(p106325) = {c106120[0]+6.5,	c106300[1],		c106300[2],		lc106000Fine};	c106325[]={Point{p106325}};
p106330=newp;	Point(p106330) = {c106120[0]+12,	c106300[1],		c106300[2],		lc106000};	c106330[]={Point{p106330}};
p106340=newp;	Point(p106340) = {c106140[0],		c106300[1],		c106300[2],		lc106000};	c106340[]={Point{p106340}};
//
p106351=newp;	Point(p106351) = {c106120[0]-6.5,	c106100[1]+.02*(59.25),	c106300[2]+7,		lc106000Fine};	c106351[]={Point{p106351}};
p106352=newp;	Point(p106352) = {c106120[0],		c106351[1],		c106351[2],		lc106000Med};	c106352[]={Point{p106352}};
p106353=newp;	Point(p106353) = {c106120[0]+6.5,	c106351[1],		c106351[2],		lc106000Fine};	c106353[]={Point{p106353}};
//
p106361=newp;	Point(p106361) = {c106120[0]-6.5,	c106300[1]+.02*(134),	c106300[2]+134,		lc106000Fine};	c106361[]={Point{p106361}};
p106362=newp;	Point(p106362) = {c106120[0],		c106361[1],		c106361[2],		lc106000Med};	c106362[]={Point{p106362}};
p106363=newp;	Point(p106363) = {c106120[0]+6.5,	c106361[1],		c106361[2],		lc106000Fine};	c106363[]={Point{p106363}};
//
p106400=newp;	Point(p106400) = {c106300[0],		c106300[1]+.02*141,	c106300[2]+141,		lc106000};	c106400[]={Point{p106400}};
p106410=newp;	Point(p106410) = {c106310[0],		c106400[1],		c106400[2],		lc106000Med};	c106410[]={Point{p106410}};
p106415=newp;	Point(p106415) = {c106320[0]-6.5,	c106400[1],		c106400[2],		lc106000Fine};	c106415[]={Point{p106415}};
p106420=newp;	Point(p106420) = {c106320[0],		c106400[1],		c106400[2],		lc106000Med};	c106420[]={Point{p106420}};
p106425=newp;	Point(p106425) = {c106320[0]+6.5,	c106400[1],		c106400[2],		lc106000Fine};	c106425[]={Point{p106425}};
p106430=newp;	Point(p106430) = {c106330[0],		c106400[1],		c106400[2],		lc106000Med};	c106430[]={Point{p106430}};
p106440=newp;	Point(p106440) = {c106340[0],		c106400[1],		c106400[2],		lc106000};	c106440[]={Point{p106440}};
//
p106451=newp;	Point(p106451) = {c106120[0]-6.5,	c106300[1]+.02*(148),	c106400[2]+7,		lc106000Fine};	c106451[]={Point{p106451}};
p106452=newp;	Point(p106452) = {c106120[0],		c106451[1],		c106451[2],		lc106000Med};	c106452[]={Point{p106452}};
p106453=newp;	Point(p106453) = {c106120[0]+6.5,	c106451[1],		c106451[2],		lc106000Fine};	c106453[]={Point{p106453}};
//
p106500=newp;	Point(p106500) = {c106100[0],		c106400[1]+.02*12,	c106400[2]+12,		lc106000Med};	c106500[]={Point{p106500}};
p106520=newp;	Point(p106520) = {c106120[0],		c106500[1],		c106500[2],		lc106000Med};	c106520[]={Point{p106520}};
p106540=newp;	Point(p106540) = {c106140[0],		c106500[1],		c106500[2],		lc106000Med};	c106540[]={Point{p106540}};
//
// _____
// LINES
// Horizontal Lines
L106100=L102505;
L106118=L102508;
L106120=L102510;
L106122=L102512;
//
L106200=newl;	Line(L106200) = {p106200, p106220};
L106220=newl;	Line(L106220) = {p106220, p106240};
//
L106251=newl;	Line(L106251) = {p106251, p106252};
L106252=newl;	Line(L106252) = {p106252, p106253};
//
L106300=newl;	Line(L106300) = {p106300, p106310};
L106310=newl;	Line(L106310) = {p106310, p106315};
L106315=newl;	Line(L106315) = {p106315, p106320};
L106320=newl;	Line(L106320) = {p106320, p106325};
L106325=newl;	Line(L106325) = {p106325, p106330};
L106330=newl;	Line(L106330) = {p106330, p106340};
//
L106351=newl;	Line(L106351) = {p106351, p106352};
L106352=newl;	Line(L106352) = {p106352, p106353};
//
L106361=newl;	Line(L106361) = {p106361, p106362};
L106362=newl;	Line(L106362) = {p106362, p106363};
//
L106400=newl;	Line(L106400) = {p106400, p106410};
L106410=newl;	Line(L106410) = {p106410, p106415};
L106415=newl;	Line(L106415) = {p106415, p106420};
L106420=newl;	Line(L106420) = {p106420, p106425};
L106425=newl;	Line(L106425) = {p106425, p106430};
L106430=newl;	Line(L106430) = {p106430, p106440};
//
L106451=newl;	Line(L106451) = {p106451, p106452};
L106452=newl;	Line(L106452) = {p106452, p106453};
//
L106500=newl;	Line(L106500) = {p106500, p106520};
L106520=newl;	Line(L106520) = {p106520, p106540};
// Vertical Lines
L206100=newl;	Line(L206100) = {p106100, p106200};
L206200=newl;	Line(L206200) = {p106200, p106300};
L206300=newl;	Line(L206300) = {p106300, p106400};
L206400=newl;	Line(L206400) = {p106400, p106500};
//
L206120=newl;	Line(L206120) = {p106120, p106151};
L206151=newl;	Line(L206151) = {p106151, p106220};
L206220=newl;	Line(L206220) = {p106220, p106252};
L206252=newl;	Line(L206252) = {p106252, p106320};
L206320=newl;	Line(L206320) = {p106320, p106352};
L206352=newl;	Line(L206352) = {p106352, p106362};
L206362=newl;	Line(L206362) = {p106362, p106420};
L206420=newl;	Line(L206420) = {p106420, p106452};
L206452=newl;	Line(L206452) = {p106452, p106520};
//
L206140=newl;	Line(L206140) = {p106140, p106240};
L206240=newl;	Line(L206240) = {p106240, p106340};
L206340=newl;	Line(L206340) = {p106340, p106440};
L206440=newl;	Line(L206440) = {p106440, p106540};
//
L206251=newl;	Line(L206251) = {p106251, p106315};
L206315=newl;	Line(L206315) = {p106315, p106351};
//
L206253=newl;	Line(L206253) = {p106253, p106325};
L206325=newl;	Line(L206325) = {p106325, p106353};
//
L206361=newl;	Line(L206361) = {p106361, p106415};
L206415=newl;	Line(L206415) = {p106415, p106451};
//
L206363=newl;	Line(L206363) = {p106363, p106425};
L206425=newl;	Line(L206425) = {p106425, p106453};
//
// __________
// LINE LOOPS
//
// 
LL106001=newl;	Line Loop(LL106001) =	{L106100,L106118,L206120,L206151,-L106200,-L206100};
LL106002=newl;	Line Loop(LL106002) =	{L106120,L106122,L206140,-L206151,-L106220,-L206120};
LL106003=newl;	Line Loop(LL106003) =	{L106200,L206220,-L106251,L206251,-L106310,-L106300,-L206200};
LL106004=newl;	Line Loop(LL106004) =	{L106220,L206240,-L106330,-L106325,-L206253,-L106252,-L206220};
LL106005=newl;	Line Loop(LL106005) =	{L106300,L106310,L206315, L106351,L206352,-L106361,L206361,-L106410,-L106400,-L206300};
LL106006=newl;	Line Loop(LL106006) =	{L106325,L106330,L206340,-L106430,-L106425,-L206363,-L106362,-L206352,L106352,-L206325};
LL106007=newl;	Line Loop(LL106007) =	{L106400,L106410,L206415,L106451,L206452,-L106500,-L206400};
LL106008=newl;	Line Loop(LL106008) =	{L106425,L106430,L206440,-L106520,-L206452,L106452,-L206425};
//
LL106011=newl;	Line Loop(LL106011) =	{L106251,L206252,-L106315,-L206251};
LL106012=newl;	Line Loop(LL106012) =	{L106252,L206253,-L106320,-L206252};
LL106013=newl;	Line Loop(LL106013) =	{L106315,L206320,-L106351,-L206315};
LL106014=newl;	Line Loop(LL106014) =	{L106320,L206325,-L106352,-L206320};
//
LL106021=newl;	Line Loop(LL106021) =	{L106361,L206362,-L106415,-L206361};
LL106022=newl;	Line Loop(LL106022) =	{L106362,L206363,-L106420,-L206362};
LL106023=newl;	Line Loop(LL106023) =	{L106415,L206420,-L106451,-L206415};
LL106024=newl;	Line Loop(LL106024) =	{L106420,L206425,-L106452,-L206420};
//
// ________
// SURFACES
PS106001=news;	Plane Surface(PS106001) =	{LL106001};
PS106002=news;	Plane Surface(PS106002) =	{LL106002};
PS106003=news;	Plane Surface(PS106003) =	{LL106003};
PS106004=news;	Plane Surface(PS106004) =	{LL106004};
PS106005=news;	Plane Surface(PS106005) =	{LL106005};
PS106006=news;	Plane Surface(PS106006) =	{LL106006};
PS106007=news;	Plane Surface(PS106007) =	{LL106007};
PS106008=news;	Plane Surface(PS106008) =	{LL106008};
//
PS106011=news;	Plane Surface(PS106011) =	{LL106011};
PS106012=news;	Plane Surface(PS106012) =	{LL106012};
PS106013=news;	Plane Surface(PS106013) =	{LL106013};
PS106014=news;	Plane Surface(PS106014) =	{LL106014};
//
PS106021=news;	Plane Surface(PS106021) =	{LL106021};
PS106022=news;	Plane Surface(PS106022) =	{LL106022};
PS106023=news;	Plane Surface(PS106023) =	{LL106023};
PS106024=news;	Plane Surface(PS106024) =	{LL106024};
//
/********************************************************************* 
 *
 *  FLOORBEAM BOT FLANGE
 *
 *********************************************************************/
//
lc107000 = lcCoarse;
lc107000Med = lcMed;
lc107000Fine = lcFine;
// ______
// POINTS
//
// Interface East Web 
p107100=p104405;	c107100[]={Point{p107100}};
p107118=p104408;	c107118[]={Point{p107118}};
p107120=p104410;	c107120[]={Point{p107120}};
p107122=p104412;	c107122[]={Point{p107122}};
p107140=p104415;	c107140[]={Point{p107140}};
//
p107151=newp;	Point(p107151) = {c107120[0],		c107100[1],		c107100[2]+8,		lc107000};	c107151[]={Point{p107151}};
//
p107200=newp;	Point(p107200) = {c107100[0],		c107100[1],		c107100[2]+35.375,	lc107000};	c107200[]={Point{p107200}};
p107220=newp;	Point(p107220) = {c107120[0],		c107100[1],		c107200[2],		lc107000Med};	c107220[]={Point{p107220}};
p107240=newp;	Point(p107240) = {c107140[0],		c107100[1],		c107200[2],		lc107000};	c107240[]={Point{p107240}};
//
p107300=newp;	Point(p107300) = {c107100[0],		c107100[1],		c106300[2],		lc107000};	c107300[]={Point{p107300}};
p107310=newp;	Point(p107310) = {c107120[0]-12,	c107100[1],		c107300[2],		lc107000};	c107310[]={Point{p107310}};
p107320=newp;	Point(p107320) = {c107120[0],		c107100[1],		c107300[2],		lc107000Med};	c107320[]={Point{p107320}};
p107330=newp;	Point(p107330) = {c107120[0]+12,	c107100[1],		c107300[2],		lc107000};	c107330[]={Point{p107330}};
p107340=newp;	Point(p107340) = {c107140[0],		c107100[1],		c107300[2],		lc107000};	c107340[]={Point{p107340}};
//
p107400=newp;	Point(p107400) = {c107300[0],		c107100[1],		c106400[2],		lc107000};	c107400[]={Point{p107400}};
p107410=newp;	Point(p107410) = {c107310[0],		c107100[1],		c107400[2],		lc107000Med};	c107410[]={Point{p107410}};
p107420=newp;	Point(p107420) = {c107320[0],		c107100[1],		c107400[2],		lc107000Med};	c107420[]={Point{p107420}};
p107430=newp;	Point(p107430) = {c107330[0],		c107100[1],		c107400[2],		lc107000Med};	c107430[]={Point{p107430}};
p107440=newp;	Point(p107440) = {c107340[0],		c107100[1],		c107400[2],		lc107000};	c107440[]={Point{p107440}};
//
p107500=newp;	Point(p107500) = {c107100[0],		c107100[1],		c106500[2],		lc107000};	c107500[]={Point{p107500}};
p107520=newp;	Point(p107520) = {c107120[0],		c107100[1],		c107500[2],		lc107000Med};	c107520[]={Point{p107520}};
p107540=newp;	Point(p107540) = {c107140[0],		c107100[1],		c107500[2],		lc107000};	c107540[]={Point{p107540}};
//
// _____
// LINES
// Horizontal Lines
L107100=L102105;
L107118=L102108;
L107120=L102110;
L107122=L102112;
//
L107200=newl;	Line(L107200) = {p107200, p107220};
L107220=newl;	Line(L107220) = {p107220, p107240};
//
L107300=newl;	Line(L107300) = {p107300, p107310};
L107310=newl;	Line(L107310) = {p107310, p107320};
L107320=newl;	Line(L107320) = {p107320, p107330};
L107330=newl;	Line(L107330) = {p107330, p107340};
//
L107400=newl;	Line(L107400) = {p107400, p107410};
L107410=newl;	Line(L107410) = {p107410, p107420};
L107420=newl;	Line(L107420) = {p107420, p107430};
L107430=newl;	Line(L107430) = {p107430, p107440};
//
L107500=newl;	Line(L107500) = {p107500, p107520};
L107520=newl;	Line(L107520) = {p107520, p107540};
// Vertical Lines
L207100=newl;	Line(L207100) = {p107100, p107200};
L207200=newl;	Line(L207200) = {p107200, p107300};
L207300=newl;	Line(L207300) = {p107300, p107400};
L207400=newl;	Line(L207400) = {p107400, p107500};
//
L207120=newl;	Line(L207120) = {p107120, p107151};
L207151=newl;	Line(L207151) = {p107151, p107220};
L207220=newl;	Line(L207220) = {p107220, p107320};
L207320=newl;	Line(L207320) = {p107320, p107420};
L207420=newl;	Line(L207420) = {p107420, p107520};
//
L207140=newl;	Line(L207140) = {p107140, p107240};
L207240=newl;	Line(L207240) = {p107240, p107340};
L207340=newl;	Line(L207340) = {p107340, p107440};
L207440=newl;	Line(L207440) = {p107440, p107540};
//
// __________
// LINE LOOPS
//
// 
LL107001=newl;	Line Loop(LL107001) =	{L107100,L107118,L207120,L207151,-L107200,-L207100};
LL107002=newl;	Line Loop(LL107002) =	{L107120,L107122,L207140,-L207151,-L107220,-L207120};
LL107003=newl;	Line Loop(LL107003) =	{L107200,L207220,-L107310,-L107300,-L207200};
LL107004=newl;	Line Loop(LL107004) =	{L107220,L207240,-L107330,-L107320,-L207220};
LL107005=newl;	Line Loop(LL107005) =	{L107300,L107310,L207320,-L107410,-L107400,-L207300};
LL107006=newl;	Line Loop(LL107006) =	{L107320,L107330,L207340,-L107430,-L107420,-L207320};
LL107007=newl;	Line Loop(LL107007) =	{L107400,L107410,L207420,-L107500,-L207400};
LL107008=newl;	Line Loop(LL107008) =	{L107420,L107430,L207440,-L107520,-L207420};
//
// ________
// SURFACES
PS107001=news;	Plane Surface(PS107001) =	{LL107001};
PS107002=news;	Plane Surface(PS107002) =	{LL107002};
PS107003=news;	Plane Surface(PS107003) =	{LL107003};
PS107004=news;	Plane Surface(PS107004) =	{LL107004};
PS107005=news;	Plane Surface(PS107005) =	{LL107005};
PS107006=news;	Plane Surface(PS107006) =	{LL107006};
PS107007=news;	Plane Surface(PS107007) =	{LL107007};
PS107008=news;	Plane Surface(PS107008) =	{LL107008};
//
/********************************************************************* 
 *
 *  FLOORBEAM WEB
 *
 *********************************************************************/
//
lc105000 = lcCoarse;
lc105000Med = lcMed;
lc105000Fine = lcFine;
// ______
// POINTS
//
// Interface Bot Fl
p105110=p107120;	c105110[]={Point{p105110}};
p105115=p107151;	c105115[]={Point{p105115}};
p105120=p107220;	c105120[]={Point{p105120}};
p105130=p107320;	c105130[]={Point{p105130}};
p105140=p107420;	c105140[]={Point{p105140}};
p105150=p107520;	c105150[]={Point{p105150}};
//
p105210=p106120;	c105210[]={Point{p105210}};
p105215=newp;	Point(p105215) = {c105110[0],		c106151[1]-dLLB-6.3125,	c106151[2],	lc105000Fine};	c105215[]={Point{p105215}};
p105220=newp;	Point(p105220) = {c105110[0],		c105215[1],		c106220[2],	lc105000Fine};	c105220[]={Point{p105220}};
//
p105315=newp;	Point(p105315) = {c105110[0],		c106151[1]-dLLB,	c106151[2],	lc105000Fine};	c105315[]={Point{p105315}};
p105320=newp;	Point(p105320) = {c105110[0],		c106220[1]-dLLB,	c106220[2],	lc105000Fine};	c105320[]={Point{p105320}};
//
p105415=newp;	Point(p105415) = {c105110[0],		c106151[1]-dLLB+6.3125,	c106151[2],	lc105000Fine};	c105415[]={Point{p105415}};
p105420=newp;	Point(p105420) = {c105110[0],		c105415[1],		c106220[2],	lc105000Fine};	c105420[]={Point{p105420}};
//
p105510=p106120;	c105510[]={Point{p105510}};
p105515=p106151;	c105515[]={Point{p105515}};
p105520=p106220;	c105520[]={Point{p105520}};
p105525=p106252;	c105525[]={Point{p105525}};
p105530=p106320;	c105530[]={Point{p105530}};
p105532=p106352;	c105532[]={Point{p105532}};
p105538=p106362;	c105538[]={Point{p105538}};
p105540=p106420;	c105540[]={Point{p105540}};
p105548=p106452;	c105548[]={Point{p105548}};
p105550=p106520;	c105550[]={Point{p105550}};
//
// Floorbeam Support point at west face
p203000=newp;	Point(p203000) = {c105150[0],		(c105150[1]+c105550[1])/2,		c105150[2],	lc105000Med};	c203000[]={Point{p203000}};

//
// _____
// LINES
// Horizontal Lines
L105110=L207120;
L105115=L207151;
L105120=L207220;
L105130=L207320;
L105140=L207420;
//
L105215=newl;	Line(L105215) = {p105215, p105220};
L105315=newl;	Line(L105315) = {p105315, p105320};
L105415=newl;	Line(L105415) = {p105415, p105420};
//
L105510=L206120;
L105515=L206151;
L105520=L206220;
L105525=L206252;
L105530=L206320;
L105532=L206352;
L105538=L206362;
L105540=L206420;
L105545=L206452;
//
// Vertical Lines
L205110=L202110;
L205210=L202210;
L205410=L202410;
//
L205115=newl;	Line(L205115) = {p105115, p105215};
L205215=newl;	Line(L205215) = {p105215, p105315};
L205315=newl;	Line(L205315) = {p105315, p105415};
L205415=newl;	Line(L205415) = {p105415, p105515};
//
L205220=newl;	Line(L205220) = {p105220, p105320};
L205320=newl;	Line(L205320) = {p105320, p105420};
//
L205130=newl;	Line(L205130) = {p105130, p105530};
L205140=newl;	Line(L205140) = {p105140, p105540};
L205150=newl;	Line(L205150) = {p105150, p203000};
L303000=newl;	Line(L303000) = {p203000, p105550};
//
// __________
// LINE LOOPS
//
// 
LL105001=newl;	Line Loop(LL105001) =	{L205110,L205210,L205410,L105510,-L205415,-L205315,-L205215,-L205115,-L105110};
LL105002=newl;	Line Loop(LL105002) =	{L205115,L105215,L205220,L205320,-L105415,L205415,L105515,L105520,L105525,-L205130,-L105120,-L105115};
LL105003=newl;	Line Loop(LL105003) =	{L205130,L105530,L105532,L105538,-L205140,-L105130};
LL105004=newl;	Line Loop(LL105004) =	{L205140,L105540,L105545,-L303000,-L205150,-L105140};
LL105005=newl;	Line Loop(LL105005) =	{L205215,L105315,-L205220,-L105215};
LL105006=newl;	Line Loop(LL105006) =	{L205315,L105415,-L205320,-L105315};
//
// ________
// SURFACES
PS105001=news;	Plane Surface(PS105001) =	{LL105001};
PS105002=news;	Plane Surface(PS105002) =	{LL105002};
PS105003=news;	Plane Surface(PS105003) =	{LL105003};
PS105004=news;	Plane Surface(PS105004) =	{LL105004};
PS105005=news;	Plane Surface(PS105005) =	{LL105005};
PS105006=news;	Plane Surface(PS105006) =	{LL105006};
//
/********************************************************************* 
 *
 *  FLOORBEAM STIFFENERS
 *
 *********************************************************************/
//
lc111000 = lcCoarse;
lc111000Med = lcMed;
lc111000Fine = lcFine;
// ______
// POINTS
//
// 
p111100=p107320;	c111100[]={Point{p111100}};
p111110=p107330;	c111110[]={Point{p111110}};
p111500=p106320;	c111500[]={Point{p111500}};
p111510=p106330;	c111510[]={Point{p111510}};
//
p112100=p107320;	c112100[]={Point{p112100}};
p112110=p107310;	c112110[]={Point{p112110}};
p112500=p106320;	c112500[]={Point{p112500}};
p112510=p106310;	c112510[]={Point{p112510}};
//
p113100=p107420;	c113100[]={Point{p113100}};
p113110=p107430;	c113110[]={Point{p113110}};
p113500=p106420;	c113500[]={Point{p113500}};
p113510=p106430;	c113510[]={Point{p113510}};
//
p114100=p107420;	c114100[]={Point{p114100}};
p114110=p107410;	c114110[]={Point{p114110}};
p114500=p106420;	c114500[]={Point{p114500}};
p114510=p106410;	c114510[]={Point{p114510}};
//
// _____
// LINES
// 
L111100=L107320;
L111500=L106320;
L111550=L106325;
L211100=L205130;
L211110=newl;	Line(L211110) = {p111110, p111510};
//
L112100=L107310;
L112500=L106310;
L112550=L106315;
L212100=L205130;
L212110=newl;	Line(L212110) = {p112110, p112510};
//
L113100=L107420;
L113500=L106420;
L113550=L106425;
L213100=L205140;
L213110=newl;	Line(L213110) = {p113110, p113510};
//
L114100=L107410;
L114500=L106410;
L114550=L106415;
L214100=L205140;
L214110=newl;	Line(L214110) = {p114110, p114510};
//
//
// __________
// LINE LOOPS
//
// 
LL111100=newl;	Line Loop(LL111100) =	{L111100,L211110,-L111550,-L111500,-L211100};
LL112100=newl;	Line Loop(LL112100) =	{L112100,L212100,-L112550,-L112500,-L212110};
LL113100=newl;	Line Loop(LL113100) =	{L113100,L213110,-L113550,-L113500,-L213100};
LL114100=newl;	Line Loop(LL114100) =	{L114100,L214100,-L114550,-L114500,-L214110};
//
// ________
// SURFACES
PS111100=news;	Plane Surface(PS111100) =	{LL111100};
PS112100=news;	Plane Surface(PS112100) =	{LL112100};
PS113100=news;	Plane Surface(PS113100) =	{LL113100};
PS114100=news;	Plane Surface(PS114100) =	{LL114100};
//
/********************************************************************* 
 *
 *  LOWER LATERAL BRACING BOT FLANGE
 *
 *********************************************************************/
//
lc117000 = lcCoarse;
lc117000Med = lcMed;
lc117000Fine = lcFine;
// ______
// POINTS
//
// 
p117100=newp;	Point(p117100) = {c102510[0]+37.25,	c102320[1]+17.5625*.02,	c102320[2]+17.5625,	lc117000};	c117100[]={Point{p117100}};
p117110=newp;	Point(p117110) = {c102510[0]+74.375,	c102320[1]+48*.02,	c102320[2]+48,		lc117000};	c117110[]={Point{p117110}};
p117200=newp;	Point(p117200) = {c102510[0]+23.9375,	c102320[1]+33.8125*.02,	c102320[2]+33.8125,	lc117000};	c117200[]={Point{p117200}};
p117210=newp;	Point(p117210) = {c102510[0]+61.125,	c102320[1]+64.25*.02,	c102320[2]+64.25,	lc117000};	c117210[]={Point{p117210}};
//
// _____
// LINES
// 
L117100=newl;	Line(L117100) = {p117100, p117200};
L117110=newl;	Line(L117110) = {p117110, p117210};
L217100=newl;	Line(L217100) = {p117100, p117110};
L217200=newl;	Line(L217200) = {p117200, p117210};
//
//
// __________
// LINE LOOPS
//
// 
LL117100=newl;	Line Loop(LL117100) =	{L117100,L217200,-L117110,-L217100};
//
// ________
// SURFACES
PS117100=news;	Plane Surface(PS117100) =	{LL117100};
//
/********************************************************************* 
 *
 *  LOWER LATERAL BRACING TOP FLANGE
 *
 *********************************************************************/
//
lc118000 = lcCoarse;
lc118000Med = lcMed;
lc118000Fine = lcFine;
// ______
// POINTS
//
// 
p118100=newp;	Point(p118100) = {c117100[0],		c117100[1]+dLLB,	c117100[2],		lc118000};	c118100[]={Point{p118100}};
p118110=newp;	Point(p118110) = {c117110[0],		c117110[1]+dLLB,	c117110[2],		lc118000};	c118110[]={Point{p118110}};
p118200=newp;	Point(p118200) = {c117200[0],		c117200[1]+dLLB,	c117200[2],		lc118000};	c118200[]={Point{p118200}};
p118210=newp;	Point(p118210) = {c117210[0],		c117210[1]+dLLB,	c117210[2],		lc118000};	c118210[]={Point{p118210}};
//
// _____
// LINES
// 
L118100=newl;	Line(L118100) = {p118100, p118200};
L118110=newl;	Line(L118110) = {p118110, p118210};
L218100=newl;	Line(L218100) = {p118100, p118110};
L218200=newl;	Line(L218200) = {p118200, p118210};
//
//
// __________
// LINE LOOPS
//
// 
LL118100=newl;	Line Loop(LL118100) =	{L118100,L218200,-L118110,-L218100};
//
// ________
// SURFACES
PS118100=news;	Plane Surface(PS118100) =	{LL118100};
//
/********************************************************************* 
 *
 *  LOWER LATERAL BRACING EAST WEB
 *
 *********************************************************************/
//
lc115000 = lcCoarse;
lc115000Med = lcMed;
lc115000Fine = lcFine;
// ______
// POINTS
//
// 
p115100=p118100;	c115100[]={Point{p115100}};
p115110=p118110;	c115110[]={Point{p115110}};
p115200=p117100;	c115200[]={Point{p115200}};
p115210=p117110;	c115210[]={Point{p115210}};
//
// _____
// LINES
// 
L115100=L218100;
L115200=L217100;
L215100=newl;	Line(L215100) = {p115100, p115200};
L215110=newl;	Line(L215110) = {p115110, p115210};
//
//
// __________
// LINE LOOPS
//
// 
LL115100=newl;	Line Loop(LL115100) =	{L115100,L215110,-L115200,-L215100};
//
// ________
// SURFACES
PS115100=news;	Plane Surface(PS115100) =	{LL115100};
//
//
/********************************************************************* 
 *
 *  LOWER LATERAL BRACING WEST WEB
 *
 *********************************************************************/
//
lc116000 = lcCoarse;
lc116000Med = lcMed;
lc116000Fine = lcFine;
// ______
// POINTS
//
// 
p116100=p118200;	c116100[]={Point{p116100}};
p116110=p118210;	c116110[]={Point{p116110}};
p116200=p117200;	c116200[]={Point{p116200}};
p116210=p117210;	c116210[]={Point{p116210}};
//
// _____
// LINES
// 
L116100=L218200;
L116200=L217200;
L216100=newl;	Line(L216100) = {p116100, p116200};
L216110=newl;	Line(L216110) = {p116110, p116210};
//
//
// __________
// LINE LOOPS
//
// 
LL116100=newl;	Line Loop(LL116100) =	{L116100,L216110,-L116200,-L216100};
//
// ________
// SURFACES
PS116100=news;	Plane Surface(PS116100) =	{LL116100};
//
/********************************************************************* 
 *
 *  GUSSET BOT
 *
 *********************************************************************/
//
lc108000 = lcCoarse;
lc108000Med = lcMed;
lc108000Fine = lcFine;
// ______
// POINTS
//
// 
p108101=p105315;	c108101[]={Point{p108101}};
p108102=p105320;	c108102[]={Point{p108102}};
p108103=newp;	Point(p108103) = {c105110[0]+22.6875,	c108102[1],		c108102[2],		lc118000};	c108103[]={Point{p108103}};
p108104=p117200;	c108104[]={Point{p108104}};
p108105=p117100;	c108105[]={Point{p108105}};
p108106=newp;	Point(p108106) = {c105110[0]+43.6875,	c102320[1]+16*.02,	c102320[2]+9.6875,		lc118000};	c108106[]={Point{p108106}};
p108107=p102320;	c108107[]={Point{p108107}};
p108108=p102318;	c108108[]={Point{p108108}};
p108109=p102317;	c108109[]={Point{p108109}};
p108110=p102315;	c108110[]={Point{p108110}};
p108111=p102314;	c108111[]={Point{p108111}};
p108112=p102312;	c108112[]={Point{p108112}};
//
// _____
// LINES
// 
L108101=L105315;
L108102=newl;	Line(L108102) = {p108102, p108103};
L108103=newl;	Line(L108103) = {p108103, p108104};
L108104=-L117100;
L108105=newl;	Line(L108105) = {p108105, p108106};
L108106=newl;	Line(L108106) = {p108106, p108107};
L108107=-L102318;
L108108=-L102317;
L108109=-L102315;
L108110=-L102314;
L108111=-L102312;
L108112=newl;	Line(L108112) = {p108112, p108101};
//
//
// __________
// LINE LOOPS
//
// 
LL108100=newl;	Line Loop(LL108100) =	{L108101,L108102,L108103,L108104,L108105,L108106,L108107,L108108,L108109,L108110,L108111,L108112};
//
// ________
// SURFACES
PS108100=news;	Plane Surface(PS108100) =	{LL108100};
//
/********************************************************************* 
 *
 *  GUSSET TOP
 *
 *********************************************************************/
//
lc109000 = lcCoarse;
lc109000Med = lcMed;
lc109000Fine = lcFine;
// ______
// POINTS
//
// 
p109101=p106140;	c109101[]={Point{p109101}};
p109102=p106240;	c109102[]={Point{p109102}};
p109103=newp;	Point(p109103) = {c108103[0],		c108103[1]+dLLB,	c108103[2],		lc118000};	c109103[]={Point{p109103}};
p109104=p118200;	c109104[]={Point{p109104}};
p109105=p118100;	c109105[]={Point{p109105}};
p109106=newp;	Point(p109106) = {c105110[0]+38.5,	c108106[1]+dLLB,	c102320[2]+16,		lc118000};	c109106[]={Point{p109106}};
p109107=newp;	Point(p109107) = {c105110[0]+24.8125,	c102515[1]+4.75*.02,	c102320[2]+4.75,	lc118000};	c109107[]={Point{p109107}};
p109108=p102518;	c109108[]={Point{p109108}};
//
p109200=p103990; // center of circular transition curve
//
// _____
// LINES
// 
L109101=L206140;
L109102=newl;	Line(L109102) = {p109102, p109103};
L109103=newl;	Line(L109103) = {p109103, p109104};
L109104=-L118100;
L109105=newl;	Line(L109105) = {p109105, p109106};
L109106=newl;	Line(L109106) = {p109106, p109107};
L109107=newl;	Circle(L109107) = {p109107, p109200, p109108};
L109108=-L102515;
//
//
// __________
// LINE LOOPS
//
// 
LL109100=newl;	Line Loop(LL109100) =	{L109101,L109102,L109103,L109104,L109105,L109106,L109107,L109108};
//
// ________
// SURFACES
PS109100=news;	Plane Surface(PS109100) =	{LL109100};
//
//
/********************************************************************* 
 *
 *  TIE DIAPHRAGM
 *
 *********************************************************************/
//
lc110000 = lcCoarse;
lc110000Med = lcMed;
lc110000Fine = lcFine;
// ______
// POINTS
//
// 
p110210=p104210;	c110210[]={Point{p110210}};
p110310=p104310;	c110310[]={Point{p110310}};
p110120=p101210;	c110120[]={Point{p110120}};
p110420=p102210;	c110420[]={Point{p110420}};
p110140=p101410;	c110140[]={Point{p110140}};
p110440=p102410;	c110440[]={Point{p110440}};
p110250=p103210;	c110250[]={Point{p110250}};
p110350=p103310;	c110350[]={Point{p110350}};
//
// Hole
p110601=newp;	Point(p110601) = {c110210[0],		c110210[1]+15.875-10,	c110120[2]+6.75+6,	lc110000Med};	c110601[]={Point{p110601}};
p110602=newp;	Point(p110602) = {c110210[0],		c110210[1]+15.875+6-10,	c110120[2]+6.75+6,	lc110000Med};	c110602[]={Point{p110602}};
p110603=newp;	Point(p110603) = {c110210[0],		c110210[1]+15.875+6-10,	c110120[2]+6.75,	lc110000Med};	c110603[]={Point{p110603}};
p110604=newp;	Point(p110604) = {c110210[0],		c110601[1]+39+3,	c110120[2]+6.75,	lc110000Med};	c110604[]={Point{p110604}};
p110605=newp;	Point(p110605) = {c110210[0],		c110601[1]+39+3,	c110120[2]+6.75+6,	lc110000Med};	c110605[]={Point{p110605}};
p110606=newp;	Point(p110606) = {c110210[0],		c110601[1]+39+6+3,	c110120[2]+6.75+6,	lc110000Med};	c110606[]={Point{p110606}};
p110607=newp;	Point(p110607) = {c110210[0],		c110601[1]+39+6+3,	c110420[2]-6.75-6,	lc110000Med};	c110607[]={Point{p110607}};
p110608=newp;	Point(p110608) = {c110210[0],		c110601[1]+39+3,	c110420[2]-6.75-6,	lc110000Med};	c110608[]={Point{p110608}};
p110609=newp;	Point(p110609) = {c110210[0],		c110601[1]+39+3,	c110420[2]-6.75,	lc110000Med};	c110609[]={Point{p110609}};
p110610=newp;	Point(p110610) = {c110210[0],		c110210[1]+15.875+6-10,	c110420[2]-6.75,	lc110000Med};	c110610[]={Point{p110610}};
p110611=newp;	Point(p110611) = {c110210[0],		c110210[1]+15.875+6-10,	c110420[2]-6.75-6,	lc110000Med};	c110611[]={Point{p110611}};
p110612=newp;	Point(p110612) = {c110210[0],		c110210[1]+15.875-10,	c110420[2]-6.75-6,	lc110000Med};	c110612[]={Point{p110612}};
//
// _____
// LINES
// 
L110101=-L204210;
L110102=newl;	Line(L110102) = {p110210, p110120};
L110103=L201210;
L110104=newl;	Line(L110104) = {p110140, p110250};
L110105=L203210;
L110106=newl;	Line(L110106) = {p110350, p110440};
// 107 obsoleted 2/23/04
L110108=-L202210;
L110109=newl;	Line(L110109) = {p110420, p110310};
//
// Hole
L110601=newl;	Line(L110601) = {p110612, p110601};
L110602=newl;	Circle(L110602) = {p110601,p110602,p110603};
L110603=newl;	Line(L110603) = {p110603, p110604};
L110604=newl;	Circle(L110604) = {p110604,p110605,p110606};
L110605=newl;	Line(L110605) = {p110606, p110607};
L110606=newl;	Circle(L110606) = {p110607,p110608,p110609};
L110607=newl;	Line(L110607) = {p110609, p110610};
L110608=newl;	Circle(L110608) = {p110610,p110611,p110612};
//
//
// __________
// LINE LOOPS
//
// 
LL110101=newl;	Line Loop(LL110101) =	{L110101,L110102,L110103,L110104,L110105,L110106,L110108,L110109};
LL110102=newl;	Line Loop(LL110102) =	{L110601,L110602,L110603,L110604,L110605,L110606,L110607,L110608};
//
// ________
// SURFACES
PS110101=news;	Plane Surface(PS110101) =	{LL110101,LL110102};
//
//
/********************************************************************* 
 *
 *  NORTH ANCHORAGE WEBS
 *
 *********************************************************************/
//
// ______
// POINTS
//
// North Anchorage North Web
p119000=p121005;	c119000[]={Point{p119000}};
p119005=newp;	Point(p119005) = {c119000[0],		c119000[1],		c119000[2]+5.5,		lc101000VFine};	c119005[]={Point{p119005}};
p119035=newp;	Point(p119035) = {c119000[0],		c119000[1],		c119000[2]+43.5,	lc101000VFine};	c119035[]={Point{p119035}};
p119040=p135005;	c119040[]={Point{p119040}};
//
p119105=newp;	Point(p119105) = {c119000[0],		c119000[1]+hAnchGuss-3,	c119005[2],		lc101000VFine};	c119105[]={Point{p119105}};
p119110=newp;	Point(p119110) = {c119000[0],		c119105[1],		c119005[2]+3,		lc101000VFine};	c119110[]={Point{p119110}};
p119130=newp;	Point(p119130) = {c119000[0],		c119105[1],		c119035[2]-3,		lc101000VFine};	c119130[]={Point{p119130}};
p119135=newp;	Point(p119135) = {c119000[0],		c119105[1],		c119035[2],		lc101000VFine};	c119135[]={Point{p119135}};
//
p119200=p121205;	c119200[]={Point{p119200}};
p119210=newp;	Point(p119210) = {c119000[0],		c119200[1],		c119110[2],		lc101000VFine};	c119210[]={Point{p119210}};
p119213=newp;	Point(p119213) = {c119000[0],		c119200[1],		c119110[2]+11,		lc101000VFine};	c119213[]={Point{p119213}};
p119215=newp;	Point(p119215) = {c119000[0],		c119200[1],		c119210[2]+14.5,	lc101000VFine};	c119215[]={Point{p119215}};
p119225=newp;	Point(p119225) = {c119000[0],		c119200[1],		c119215[2]+11,		lc101000VFine};	c119225[]={Point{p119225}};
p119227=newp;	Point(p119227) = {c119000[0],		c119200[1],		c119215[2]+14.5,	lc101000VFine};	c119227[]={Point{p119227}};
p119230=newp;	Point(p119230) = {c119000[0],		c119200[1],		c119130[2],		lc101000VFine};	c119230[]={Point{p119230}};
p119240=p135205;	c119240[]={Point{p119240}};
//
p119300=p121305;	c119300[]={Point{p119300}};
p119301=newp;	Point(p119301) = {c119000[0],		c119300[1],		c119300[2]+.5,		lc101000VFine};	c119301[]={Point{p119301}};
p119315=newp;	Point(p119315) = {c119000[0],		c119300[1],		c119215[2],		lc101000VFine};	c119315[]={Point{p119315}};
p119325=newp;	Point(p119325) = {c119000[0],		c119300[1],		c119225[2],		lc101000VFine};	c119325[]={Point{p119325}};
p119339=newp;	Point(p119339) = {c119000[0],		c119300[1],		c135305[2]-.5,		lc101000VFine};	c119339[]={Point{p119339}};
p119340=p135305;	c119340[]={Point{p119340}};
// 
// North Anchorage South Web
p120000=p121015;	c120000[]={Point{p120000}};
p120005=newp;	Point(p120005) = {c120000[0],		c120000[1],		c120000[2]+5.5,		lc101000VFine};	c120005[]={Point{p120005}};
p120035=newp;	Point(p120035) = {c120000[0],		c120000[1],		c120000[2]+43.5,	lc101000VFine};	c120035[]={Point{p120035}};
p120040=p135015;	c120040[]={Point{p120040}};
//
p120105=newp;	Point(p120105) = {c120000[0],		c120000[1]+hAnchGuss-3,	c120005[2],		lc101000VFine};	c120105[]={Point{p120105}};
p120110=newp;	Point(p120110) = {c120000[0],		c120105[1],		c120005[2]+3,		lc101000VFine};	c120110[]={Point{p120110}};
p120130=newp;	Point(p120130) = {c120000[0],		c120105[1],		c120035[2]-3,		lc101000VFine};	c120130[]={Point{p120130}};
p120135=newp;	Point(p120135) = {c120000[0],		c120105[1],		c120035[2],		lc101000VFine};	c120135[]={Point{p120135}};
//
p120200=p121215;	c120200[]={Point{p120200}};
p120210=newp;	Point(p120210) = {c120000[0],		c120200[1],		c120110[2],		lc101000VFine};	c120210[]={Point{p120210}};
p120213=newp;	Point(p120213) = {c120000[0],		c120200[1],		c120210[2]+11,		lc101000VFine};	c120213[]={Point{p120213}};
p120215=newp;	Point(p120215) = {c120000[0],		c120200[1],		c120210[2]+14.5,	lc101000VFine};	c120215[]={Point{p120215}};
p120225=newp;	Point(p120225) = {c120000[0],		c120200[1],		c120215[2]+11,		lc101000VFine};	c120225[]={Point{p120225}};
p120227=newp;	Point(p120227) = {c120000[0],		c120200[1],		c120215[2]+14.5,	lc101000VFine};	c120227[]={Point{p120227}};
p120230=newp;	Point(p120230) = {c120000[0],		c120200[1],		c120130[2],		lc101000VFine};	c120230[]={Point{p120230}};
p120240=p135215;	c120240[]={Point{p120240}};
//
p120300=p121315;	c120300[]={Point{p120300}};
p120301=newp;	Point(p120301) = {c120000[0],		c120300[1],		c121315[2]+.5,		lc101000VFine};	c120301[]={Point{p120301}};
p120315=newp;	Point(p120315) = {c120000[0],		c120300[1],		c120215[2],		lc101000VFine};	c120315[]={Point{p120315}};
p120325=newp;	Point(p120325) = {c120000[0],		c120300[1],		c120225[2],		lc101000VFine};	c120325[]={Point{p120325}};
p120339=newp;	Point(p120339) = {c120000[0],		c120300[1],		c135315[2]-.5,		lc101000VFine};	c120339[]={Point{p120339}};
p120340=p135315;	c120340[]={Point{p120340}};
// 
// Anchorage end-plates East
Rotate{{0.0,0.0,1}, {xCableN,yCableN,zCableN}, thetaN*Pi/180} {
  Point{p121000}; Point{p121005}; Point{p121015}; Point{p121020};
  Point{p121200}; Point{p121205}; Point{p121215}; Point{p121220};
  Point{p121300}; Point{p121305}; Point{p121315}; Point{p121320};
  }
//
// Anchorage end-plates West
Rotate{{0.0,0.0,1}, {xCableN,yCableN,zCableN}, thetaN*Pi/180} {
  Point{p135000}; Point{p135005}; Point{p135015}; Point{p135020};
  Point{p135200}; Point{p135205}; Point{p135215}; Point{p135220};
  Point{p135300}; Point{p135305}; Point{p135315}; Point{p135320};
  }
//
// North Anchorage Webs
Rotate{{0.0,0.0,1}, {xCableN,yCableN,zCableN}, thetaN*Pi/180} {
  Point{p119005}; Point{p119035}; 
  Point{p119105}; Point{p119110}; Point{p119130}; Point{p119135};
  Point{p119210}; Point{p119213}; Point{p119215}; Point{p119227}; Point{p119225}; Point{p119230}; 
  Point{p119301}; Point{p119315}; Point{p119325}; Point{p119339}; 
  }
Rotate{{0.0,0.0,1}, {xCableN,yCableN,zCableN}, thetaN*Pi/180} {
  Point{p120005}; Point{p120035}; 
  Point{p120105}; Point{p120110}; Point{p120130}; Point{p120135};
  Point{p120210}; Point{p120213}; Point{p120215}; Point{p120225}; Point{p120227}; Point{p120230}; 
  Point{p120301}; Point{p120315}; Point{p120325}; Point{p120339}; 
  }
//
// _____
// LINES
// 
// North Web
L119000=newl;	Line(L119000) = {p119000, p119005};
L119035=newl;	Line(L119035) = {p119035, p119040};
L119105=newl;	Circle(L119105) = {p119105, p119110, p119210};
L119135=newl;	Circle(L119135) = {p119230, p119130, p119135};
L119200=newl;	Line(L119200) = {p119200, p119210};
L119210=newl;	Line(L119210) = {p119210, p119213};
L119213=newl;	Line(L119213) = {p119213, p119215};
L119215=newl;	Line(L119215) = {p119215, p119225};
L119225=newl;	Line(L119225) = {p119225, p119227};
L119227=newl;	Line(L119227) = {p119227, p119230};
L119230=newl;	Line(L119230) = {p119230, p119240};
L119300=newl;	Line(L119300) = {p119300, p119301};
L119301=newl;	Line(L119301) = {p119301, p119315};
L119315=newl;	Line(L119315) = {p119315, p119325};
L119325=newl;	Line(L119325) = {p119325, p119339};
L119339=newl;	Line(L119339) = {p119339, p119340};
//
L219000=L221005;
L219005=newl;	Line(L219005) = {p119005, p119105};
L219035=newl;	Line(L219035) = {p119035, p119135};
L219040=L235005;
L219200=L221205;
L219215=newl;	Line(L219215) = {p119215, p119315};
L219225=newl;	Line(L219225) = {p119225, p119325};
L219240=L235205;
//
// South Web
L120000=newl;	Line(L120000) = {p120000, p120005};
L120035=newl;	Line(L120035) = {p120035, p120040};
L120105=newl;	Circle(L120105) = {p120105, p120110, p120210};
L120135=newl;	Circle(L120135) = {p120230, p120130, p120135};
L120200=newl;	Line(L120200) = {p120200, p120210};
L120210=newl;	Line(L120210) = {p120210, p120213};
L120213=newl;	Line(L120213) = {p120213, p120215};
L120215=newl;	Line(L120215) = {p120215, p120225};
L120225=newl;	Line(L120225) = {p120225, p120227};
L120227=newl;	Line(L120227) = {p120227, p120230};
L120230=newl;	Line(L120230) = {p120230, p120240};
L120300=newl;	Line(L120300) = {p120300, p120301};
L120301=newl;	Line(L120301) = {p120301, p120315};
L120315=newl;	Line(L120315) = {p120315, p120325};
L120325=newl;	Line(L120325) = {p120325, p120339};
L120339=newl;	Line(L120339) = {p120339, p120340};
//
L220000=L221015;
L220005=newl;	Line(L220005) = {p120005, p120105};
L220035=newl;	Line(L220035) = {p120035, p120135};
L220040=L235015;
L220200=L221215;
L220215=newl;	Line(L220215) = {p120215, p120315};
L220225=newl;	Line(L220225) = {p120225, p120325};
L220240=L235215;
//
//
// __________
// LINE LOOPS
//
// North Web 
LL119101=newl;	Line Loop(LL119101) =	{L119000,L219005,L119105,-L119200,-L219000};
LL119102=newl;	Line Loop(LL119102) =	{L119035,L219040,-L119230,L119135,-L219035};
LL119103=newl;	Line Loop(LL119103) =	{L119200,L119210,L119213,L219215,-L119301,-L119300,-L219200};
LL119104=newl;	Line Loop(LL119104) =	{L119215,L219225,-L119315,-L219215};
LL119105=newl;	Line Loop(LL119105) =	{L119225,L119227,L119230,L219240,-L119339,-L119325,-L219225};
//
// South Web 
LL120101=newl;	Line Loop(LL120101) =	{L120000,L220005,L120105,-L120200,-L220000};
LL120102=newl;	Line Loop(LL120102) =	{L120035,L220040,-L120230,L120135,-L220035};
LL120103=newl;	Line Loop(LL120103) =	{L120200,L120210,L120213,L220215,-L120301,-L120300,-L220200};
LL120104=newl;	Line Loop(LL120104) =	{L120215,L220225,-L120315,-L220215};
LL120105=newl;	Line Loop(LL120105) =	{L120225,L120227,L120230,L220240,-L120339,-L120325,-L220225};
//
// ________
// SURFACES
//
// North Web
PS119101=news;	Plane Surface(PS119101) =	{LL119101};
PS119102=news;	Plane Surface(PS119102) =	{LL119102};
PS119103=news;	Plane Surface(PS119103) =	{LL119103};
PS119104=news;	Plane Surface(PS119104) =	{LL119104};
PS119105=news;	Plane Surface(PS119105) =	{LL119105};
//
// South Web
PS120101=news;	Plane Surface(PS120101) =	{LL120101};
PS120102=news;	Plane Surface(PS120102) =	{LL120102};
PS120103=news;	Plane Surface(PS120103) =	{LL120103};
PS120104=news;	Plane Surface(PS120104) =	{LL120104};
PS120105=news;	Plane Surface(PS120105) =	{LL120105};
//
//
/********************************************************************* 
 *
 *  SOUTH ANCHORAGE WEBS
 *
 *********************************************************************/
//
// ______
// POINTS
//
// South Anchorage North Web
p133000=p122005;	c133000[]={Point{p133000}};
p133005=newp;	Point(p133005) = {c133000[0],		c133000[1],		c133000[2]+5.5,		lc101000VFine};	c133005[]={Point{p133005}};
p133035=newp;	Point(p133035) = {c133000[0],		c133000[1],		c133000[2]+43.5,	lc101000VFine};	c133035[]={Point{p133035}};
p133040=p136005;	c133040[]={Point{p133040}};
//
p133105=newp;	Point(p133105) = {c133000[0],		c133000[1]+hAnchGuss-3,	c133005[2],		lc101000VFine};	c133105[]={Point{p133105}};
p133110=newp;	Point(p133110) = {c133000[0],		c133105[1],		c133005[2]+3,		lc101000VFine};	c133110[]={Point{p133110}};
p133130=newp;	Point(p133130) = {c133000[0],		c133105[1],		c133035[2]-3,		lc101000VFine};	c133130[]={Point{p133130}};
p133135=newp;	Point(p133135) = {c133000[0],		c133105[1],		c133035[2],		lc101000VFine};	c133135[]={Point{p133135}};
p133140=p102315;	c133140[]={Point{p133140}};
//
p133200=p122205;	c133200[]={Point{p133200}};
p133210=newp;	Point(p133210) = {c133000[0],		c133200[1],		c133110[2],		lc101000VFine};	c133210[]={Point{p133210}};
p133213=newp;	Point(p133213) = {c133000[0],		c133200[1],		c133210[2]+3,		lc101000VFine};	c133213[]={Point{p133213}};
p133215=newp;	Point(p133215) = {c133000[0],		c133200[1],		c133210[2]+6.5,		lc101000VFine};	c133215[]={Point{p133215}};
p133225=newp;	Point(p133225) = {c133000[0],		c133200[1],		c133215[2]+11,		lc101000VFine};	c133225[]={Point{p133225}};
p133227=newp;	Point(p133227) = {c133000[0],		c133200[1],		c133215[2]+14.5,	lc101000VFine};	c133227[]={Point{p133227}};
p133230=newp;	Point(p133230) = {c133000[0],		c133200[1],		c133130[2],		lc101000VFine};	c133230[]={Point{p133230}};
p133240=p136205;	c133240[]={Point{p133240}};
//
p133250=p102376;	c133250[]={Point{p133250}};
//p133260=p102377;	c133260[]={Point{p133260}};
//
p133300=p122305;	c133300[]={Point{p133300}};
p133301=newp;	Point(p133301) = {c133000[0],		c133300[1],		c133300[2]+.5,		lc101000VFine};	c133301[]={Point{p133301}};
p133315=newp;	Point(p133315) = {c133000[0],		c133300[1],		c133215[2],		lc101000VFine};	c133315[]={Point{p133315}};
p133325=newp;	Point(p133325) = {c133000[0],		c133300[1],		c133225[2],		lc101000VFine};	c133325[]={Point{p133325}};
p133339=newp;	Point(p133339) = {c133000[0],		c133300[1],		c136305[2]-.5,		lc101000VFine};	c133339[]={Point{p133339}};
p133340=p136305;	c133340[]={Point{p133340}};
// 
// South Anchorage South Web
p134000=p122015;	c134000[]={Point{p134000}};
p134005=newp;	Point(p134005) = {c134000[0],		c134000[1],		c134000[2]+5.5,		lc101000VFine};	c134005[]={Point{p134005}};
p134035=newp;	Point(p134035) = {c134000[0],		c134000[1],		c134000[2]+43.5,	lc101000VFine};	c134035[]={Point{p134035}};
p134040=p136015;	c134040[]={Point{p134040}};
//
p134105=newp;	Point(p134105) = {c134000[0],		c134000[1]+hAnchGuss-3,	c134005[2],		lc101000VFine};	c134105[]={Point{p134105}};
p134110=newp;	Point(p134110) = {c134000[0],		c134105[1],		c134005[2]+3,		lc101000VFine};	c134110[]={Point{p134110}};
p134130=newp;	Point(p134130) = {c134000[0],		c134105[1],		c134035[2]-3,		lc101000VFine};	c134130[]={Point{p134130}};
p134135=newp;	Point(p134135) = {c134000[0],		c134105[1],		c134035[2],		lc101000VFine};	c134135[]={Point{p134135}};
//
p134200=p122215;	c134200[]={Point{p134200}};
p134210=newp;	Point(p134210) = {c134000[0],		c134200[1],		c134110[2],		lc101000VFine};	c134210[]={Point{p134210}};
p134213=newp;	Point(p134213) = {c134000[0],		c134200[1],		c134210[2]+3,		lc101000VFine};	c134213[]={Point{p134213}};
p134215=newp;	Point(p134215) = {c134000[0],		c134200[1],		c134210[2]+6.5,		lc101000VFine};	c134215[]={Point{p134215}};
p134225=newp;	Point(p134225) = {c134000[0],		c134200[1],		c134215[2]+11,		lc101000VFine};	c134225[]={Point{p134225}};
p134227=newp;	Point(p134227) = {c134000[0],		c134200[1],		c134215[2]+14.5,	lc101000VFine};	c134227[]={Point{p134227}};
p134230=newp;	Point(p134230) = {c134000[0],		c134200[1],		c134130[2],		lc101000VFine};	c134230[]={Point{p134230}};
p134240=p136215;	c134240[]={Point{p134240}};
//
p134300=p122315;	c134300[]={Point{p134300}};
p134301=newp;	Point(p134301) = {c134000[0],		c134300[1],		c134300[2]+.5,		lc101000VFine};	c134301[]={Point{p134301}};
p134315=newp;	Point(p134315) = {c134000[0],		c134300[1],		c134215[2],		lc101000VFine};	c134315[]={Point{p134315}};
p134325=newp;	Point(p134325) = {c134000[0],		c134300[1],		c134225[2],		lc101000VFine};	c134325[]={Point{p134325}};
p134339=newp;	Point(p134339) = {c134000[0],		c134300[1],		c134240[2]-.5,		lc101000VFine};	c134339[]={Point{p134339}};
p134340=p136315;	c134340[]={Point{p134340}};
//
// Anchorage end-plate East
Rotate{{0.0,0.0,1}, {xCableS,yCableS,zCableS}, thetaS*Pi/180} {
  Point{p122000}; Point{p122005}; Point{p122015}; Point{p122020};
  Point{p122200}; Point{p122205}; Point{p122215}; Point{p122220};
  Point{p122300}; Point{p122305}; Point{p122315}; Point{p122320};
  }
//
// Anchorage end-plate West
Rotate{{0.0,0.0,1}, {xCableS,yCableS,zCableS}, thetaS*Pi/180} {
  Point{p136000}; Point{p136005}; Point{p136015}; Point{p136020};
  Point{p136200}; Point{p136205}; Point{p136215}; Point{p136220};
  Point{p136300}; Point{p136305}; Point{p136315}; Point{p136320};
  }
//
// South Anchorage Webs
Rotate{{0.0,0.0,1}, {xCableS,yCableS,zCableS}, thetaS*Pi/180} {
  Point{p133005}; Point{p133035}; 
  Point{p133105}; Point{p133110}; Point{p133130}; Point{p133135};
  Point{p133210}; Point{p133213}; Point{p133215}; Point{p133225}; Point{p133227}; Point{p133230}; 
  Point{p133301}; Point{p133315}; Point{p133325}; Point{p133339}; 
  }
Rotate{{0.0,0.0,1}, {xCableS,yCableS,zCableS}, thetaS*Pi/180} {
  Point{p134005}; Point{p134035}; 
  Point{p134105}; Point{p134110}; Point{p134130}; Point{p134135};
  Point{p134210}; Point{p134213}; Point{p134215}; Point{p134225}; Point{p134227}; Point{p134230}; 
  Point{p134301}; Point{p134315}; Point{p134325}; Point{p134339}; 
  }
//
// _____
// LINES
// 
// North Web
L133000=newl;	Line(L133000) = {p133000, p133005};
L133035=newl;	Line(L133035) = {p133035, p133040};
L133105=newl;	Circle(L133105) = {p133105, p133110, p133210};
L133135=newl;	Circle(L133135) = {p133230, p133130, p133135};
L133200=newl;	Line(L133200) = {p133200, p133210};
L133210=newl;	Line(L133210) = {p133210, p133213};
L133213=newl;	Line(L133213) = {p133213, p133215};
L133215=newl;	Line(L133215) = {p133215, p133225};
L133225=newl;	Line(L133225) = {p133225, p133227};
L133227=newl;	Line(L133227) = {p133227, p133230};
L133230=newl;	Line(L133230) = {p133230, p133240};
L133300=newl;	Line(L133300) = {p133300, p133301};
L133301=newl;	Line(L133301) = {p133301, p133315};
L133315=newl;	Line(L133315) = {p133315, p133325};
L133325=newl;	Line(L133325) = {p133325, p133339};
L133339=newl;	Line(L133339) = {p133339, p133340};
//
L233000=L222005;
L233005=newl;	Line(L233005) = {p133005, p133105};
L233035=newl;	Line(L233035) = {p133035, p133135};
L233040=L236005;
L233140=L236315;
L233200=L222205;
L233215=newl;	Line(L233215) = {p133215, p133315};
L233225=newl;	Line(L233225) = {p133225, p133325};
L233240=L236205;
L233250=L236376;
//
// South Web
L134000=newl;	Line(L134000) = {p134000, p134005};
L134035=newl;	Line(L134035) = {p134035, p134040};
L134105=newl;	Circle(L134105) = {p134105, p134110, p134210};
L134135=newl;	Circle(L134135) = {p134230, p134130, p134135};
L134200=newl;	Line(L134200) = {p134200, p134210};
L134210=newl;	Line(L134210) = {p134210, p134213};
L134213=newl;	Line(L134213) = {p134213, p134215};
L134215=newl;	Line(L134215) = {p134215, p134225};
L134225=newl;	Line(L134225) = {p134225, p134227};
L134227=newl;	Line(L134227) = {p134227, p134230};
L134230=newl;	Line(L134230) = {p134230, p134240};
L134300=newl;	Line(L134300) = {p134300, p134301};
L134301=newl;	Line(L134301) = {p134301, p134315};
L134315=newl;	Line(L134315) = {p134315, p134325};
L134325=newl;	Line(L134325) = {p134325, p134339};
L134339=newl;	Line(L134339) = {p134339, p134340};
//
L234000=L222015;
L234005=newl;	Line(L234005) = {p134005, p134105};
L234035=newl;	Line(L234035) = {p134035, p134135};
L234040=L236015;
L234140=L236357;
L234200=L222215;
L234215=newl;	Line(L234215) = {p134215, p134315};
L234225=newl;	Line(L234225) = {p134225, p134325};
L234240=L236215;
L234250=L236317;
L234260=L236377;
//
//
// __________
// LINE LOOPS
//
// North Web 
LL133101=newl;	Line Loop(LL133101) =	{L133000,L233005,L133105,-L133200,-L233000};
LL133102=newl;	Line Loop(LL133102) =	{L133035,L233040,L233140,-L133230,L133135,-L233035};
LL133103=newl;	Line Loop(LL133103) =	{L133200,L133210,L133213,L233215,-L133301,-L133300,-L233200};
LL133104=newl;	Line Loop(LL133104) =	{L133215,L233225,-L133315,-L233215};
LL133105=newl;	Line Loop(LL133105) =	{L133225,L133227,L133230,L233240,L233250,-L133339,-L133325,-L233225};
//
// South Web 
LL134101=newl;	Line Loop(LL134101) =	{L134000,L234005,L134105,-L134200,-L234000};
LL134102=newl;	Line Loop(LL134102) =	{L134035,L234040,L234140,-L134230,L134135,-L234035};
LL134103=newl;	Line Loop(LL134103) =	{L134200,L134210,L134213,L234215,-L134301,-L134300,-L234200};
LL134104=newl;	Line Loop(LL134104) =	{L134215,L234225,-L134315,-L234215};
LL134105=newl;	Line Loop(LL134105) =	{L134225,L134227,L134230,L234240,L234250,L234260,-L134339,-L134325,-L234225};
//
// ________
// SURFACES
//
// North Web
PS133101=news;	Plane Surface(PS133101) =	{LL133101};
PS133102=news;	Plane Surface(PS133102) =	{LL133102};
PS133103=news;	Plane Surface(PS133103) =	{LL133103};
PS133104=news;	Plane Surface(PS133104) =	{LL133104};
PS133105=news;	Plane Surface(PS133105) =	{LL133105};
//
// South Web
PS134101=news;	Plane Surface(PS134101) =	{LL134101};
PS134102=news;	Plane Surface(PS134102) =	{LL134102};
PS134103=news;	Plane Surface(PS134103) =	{LL134103};
PS134104=news;	Plane Surface(PS134104) =	{LL134104};
PS134105=news;	Plane Surface(PS134105) =	{LL134105};
//
//
/********************************************************************* 
 *
 *  NORTH ANCHORAGE FLANGES
 *
 *********************************************************************/
//
// ______
// POINTS
//
// North Anchorage North Top Flange
p123000=p119301;	c123000[]={Point{p123000}};
p123015=p119315;	c123015[]={Point{p123015}};
p123025=p119325;	c123025[]={Point{p123025}};
p123040=p119339;	c123040[]={Point{p123040}};
p123100=newp;	Point(p123100) = {c121300[0],		c121300[1],		c123000[2],		lc101000VFine};	c123100[]={Point{p123100}};
p123115=newp;	Point(p123115) = {c123100[0],		c123100[1],		c123015[2],		lc101000VFine};	c123115[]={Point{p123115}};
p123125=newp;	Point(p123125) = {c123100[0],		c123100[1],		c123025[2],		lc101000VFine};	c123125[]={Point{p123125}};
p123140=newp;	Point(p123140) = {c135300[0],		c135300[1],		c123040[2],		lc101000VFine};	c123140[]={Point{p123140}};
//
// North Anchorage North Bot Flange
p124000=p119200;	c124000[]={Point{p124000}};
p124010=p119210;	c124010[]={Point{p124010}};
p124013=p119213;	c124013[]={Point{p124013}};
p124015=p119215;	c124015[]={Point{p124015}};
p124025=p119225;	c124025[]={Point{p124025}};
p124027=p119227;	c124027[]={Point{p124027}};
p124030=p119230;	c124030[]={Point{p124030}};
p124040=p119240;	c124040[]={Point{p124040}};
p124100=p121200;	c124100[]={Point{p124100}};
p124113=newp;	Point(p124113) = {c124100[0],		c124100[1],		c124013[2],		lc101000VFine};	c124113[]={Point{p124113}};
p124115=newp;	Point(p124115) = {c124100[0],		c124100[1],		c124015[2],		lc101000VFine};	c124115[]={Point{p124115}};
p124125=newp;	Point(p124125) = {c124100[0],		c124100[1],		c124025[2],		lc101000VFine};	c124125[]={Point{p124125}};
p124127=newp;	Point(p124127) = {c124100[0],		c124100[1],		c124027[2],		lc101000VFine};	c124127[]={Point{p124127}};
p124140=p135200;	c124140[]={Point{p124140}};
//
// North Anchorage South Top Flange
p125000=p120301;	c125000[]={Point{p125000}};
p125015=p120315;	c125015[]={Point{p125015}};
p125025=p120325;	c125025[]={Point{p125025}};
p125040=p120339;	c125040[]={Point{p125040}};
p125100=newp;	Point(p125100) = {c121320[0],		c121320[1],		c125000[2],		lc101000VFine};	c125100[]={Point{p125100}};
p125115=newp;	Point(p125115) = {c125100[0],		c125100[1],		c125015[2],		lc101000VFine};	c125115[]={Point{p125115}};
p125125=newp;	Point(p125125) = {c125100[0],		c125100[1],		c125025[2],		lc101000VFine};	c125125[]={Point{p125125}};
p125140=newp;	Point(p125140) = {c135320[0],		c135320[1],		c125040[2],		lc101000VFine};	c125140[]={Point{p125140}};
//
// North Anchorage South Bot Flange
p126000=p120200;	c126000[]={Point{p126000}};
p126010=p120210;	c126010[]={Point{p126010}};
p126013=p120213;	c126013[]={Point{p126013}};
p126015=p120215;	c126015[]={Point{p126015}};
p126025=p120225;	c126025[]={Point{p126025}};
p126027=p120227;	c126027[]={Point{p126027}};
p126030=p120230;	c126030[]={Point{p126030}};
p126040=p120240;	c126040[]={Point{p126040}};
p126100=p121220;	c126100[]={Point{p126100}};
p126113=newp;	Point(p126113) = {c126100[0],		c126100[1],		c126013[2],		lc101000VFine};	c126113[]={Point{p126113}};
p126115=newp;	Point(p126115) = {c126100[0],		c126100[1],		c126015[2],		lc101000VFine};	c126115[]={Point{p126115}};
p126125=newp;	Point(p126125) = {c126100[0],		c126100[1],		c126025[2],		lc101000VFine};	c126125[]={Point{p126125}};
p126127=newp;	Point(p126127) = {c126100[0],		c126100[1],		c126027[2],		lc101000VFine};	c126127[]={Point{p126127}};
p126140=p135220;	c126140[]={Point{p126140}};
//
// North Anchorage Flanges
Rotate{{0.0,0.0,1}, {xCableN,yCableN,zCableN}, thetaN*Pi/180} {
  Point{p123100}; Point{p123115}; Point{p123125}; Point{p123140};
  Point{p125100}; Point{p125115}; Point{p125125}; Point{p125140};
  }
//
// _____
// LINES
// 
// North Anchorage North Top Flange
L123000=L119301;
L123015=L119315;
L123025=L119325;
L123100=newl;	Line(L123100) = {p123100, p123115};
L123115=newl;	Line(L123115) = {p123115, p123125};
L123125=newl;	Line(L123125) = {p123125, p123140};
//
L223000=newl;	Line(L223000) = {p123000, p123100};
L223015=newl;	Line(L223015) = {p123015, p123115};
L223025=newl;	Line(L223025) = {p123025, p123125};
L223040=newl;	Line(L223040) = {p123040, p123140};
// 
// North Anchorage North Bot Flange
L124000=L119200;
L124010=L119210;
L124013=L119213;
L124015=L119215;
L124025=L119225;
L124027=L119227;
L124030=L119230;
L124100=newl;	Line(L124100) = {p124100, p124113};
L124113=newl;	Line(L124113) = {p124113, p124115};
L124115=newl;	Line(L124115) = {p124115, p124125};
L124125=newl;	Line(L124125) = {p124125, p124127};
L124127=newl;	Line(L124127) = {p124127, p124140};
//
L224000=L121200;
L224013=newl;	Line(L224013) = {p124013, p124113};
L224015=newl;	Line(L224015) = {p124015, p124115};
L224025=newl;	Line(L224025) = {p124025, p124125};
L224027=newl;	Line(L224027) = {p124027, p124127};
L224040=L135200;
// 
// North Anchorage South Top Flange
L125000=L120301;
L125015=L120315;
L125025=L120325;
L125100=newl;	Line(L125100) = {p125100, p125115};
L125115=newl;	Line(L125115) = {p125115, p125125};
L125125=newl;	Line(L125125) = {p125125, p125140};
//
L225000=newl;	Line(L225000) = {p125000, p125100};
L225015=newl;	Line(L225015) = {p125015, p125115};
L225025=newl;	Line(L225025) = {p125025, p125125};
L225040=newl;	Line(L225040) = {p125040, p125140};
// 
// North Anchorage South Bot Flange
L126000=L120200;
L126010=L120210;
L126013=L120213;
L126015=L120215;
L126025=L120225;
L126027=L120227;
L126030=L120230;
L126100=newl;	Line(L126100) = {p126100, p126113};
L126113=newl;	Line(L126113) = {p126113, p126115};
L126115=newl;	Line(L126115) = {p126115, p126125};
L126125=newl;	Line(L126125) = {p126125, p126127};
L126127=newl;	Line(L126127) = {p126127, p126140};
//
L226000=L121215;
L226013=newl;	Line(L226013) = {p126013, p126113};
L226015=newl;	Line(L226015) = {p126015, p126115};
L226025=newl;	Line(L226025) = {p126025, p126125};
L226027=newl;	Line(L226027) = {p126027, p126127};
L226040=L135215;
//
//
// __________
// LINE LOOPS
//
// North Anchorage North Top Flange
LL123101=newl;	Line Loop(LL123101) =	{L123000,L223015,-L123100,-L223000};
LL123102=newl;	Line Loop(LL123102) =	{L123015,L223025,-L123115,-L223015};
LL123103=newl;	Line Loop(LL123103) =	{L123025,L223040,-L123125,-L223025};
//
// North Anchorage North Bot Flange
LL124101=newl;	Line Loop(LL124101) =	{L124000,L124010,L224013,-L124100,L224000};
LL124102=newl;	Line Loop(LL124102) =	{L124013,L224015,-L124113,-L224013};
LL124103=newl;	Line Loop(LL124103) =	{L124015,L224025,-L124115,-L224015};
LL124104=newl;	Line Loop(LL124104) =	{L124025,L224027,-L124125,-L224025};
LL124105=newl;	Line Loop(LL124105) =	{L124027,L124030,-L224040,-L124127,-L224027};
//
// North Anchorage South Top Flange
LL125101=newl;	Line Loop(LL125101) =	{L125000,L225015,-L125100,-L225000};
LL125102=newl;	Line Loop(LL125102) =	{L125015,L225025,-L125115,-L225015};
LL125103=newl;	Line Loop(LL125103) =	{L125025,L225040,-L125125,-L225025};
//
// North Anchorage South Bot Flange
LL126101=newl;	Line Loop(LL126101) =	{L126000,L126010,L226013,-L126100,-L226000};
LL126102=newl;	Line Loop(LL126102) =	{L126013,L226015,-L126113,-L226013};
LL126103=newl;	Line Loop(LL126103) =	{L126015,L226025,-L126115,-L226015};
LL126104=newl;	Line Loop(LL126104) =	{L126025,L226027,-L126125,-L226025};
LL126105=newl;	Line Loop(LL126105) =	{L126027,L126030,L226040,-L126127,-L226027};
//
// ________
// SURFACES
//
// North Anchorage North Top Flange
PS123101=news;	Plane Surface(PS123101) =	{LL123101};
PS123102=news;	Plane Surface(PS123102) =	{LL123102};
PS123103=news;	Plane Surface(PS123103) =	{LL123103};
//
// North Anchorage North Bot Flange
PS124101=news;	Plane Surface(PS124101) =	{LL124101};
PS124102=news;	Plane Surface(PS124102) =	{LL124102};
PS124103=news;	Plane Surface(PS124103) =	{LL124103};
PS124104=news;	Plane Surface(PS124104) =	{LL124104};
PS124105=news;	Plane Surface(PS124105) =	{LL124105};
//
// North Anchorage South Top Flange
PS125101=news;	Plane Surface(PS125101) =	{LL125101};
PS125102=news;	Plane Surface(PS125102) =	{LL125102};
PS125103=news;	Plane Surface(PS125103) =	{LL125103};
//
// North Anchorage South Bot Flange
PS126101=news;	Plane Surface(PS126101) =	{LL126101};
PS126102=news;	Plane Surface(PS126102) =	{LL126102};
PS126103=news;	Plane Surface(PS126103) =	{LL126103};
PS126104=news;	Plane Surface(PS126104) =	{LL126104};
PS126105=news;	Plane Surface(PS126105) =	{LL126105};
//
//
//
/********************************************************************* 
 *
 *  SOUTH ANCHORAGE FLANGES
 *
 *********************************************************************/
//
// ______
// POINTS
//
// South Anchorage North Top Flange
p137000=p133301;	c137000[]={Point{p137000}};
p137015=p133315;	c137015[]={Point{p137015}};
p137025=p133325;	c137025[]={Point{p137025}};
p137040=p133339;	c137040[]={Point{p137040}};
p137100=newp;	Point(p137100) = {c122300[0],		c122300[1],		c137000[2],		lc101000VFine};	c137100[]={Point{p137100}};
p137115=newp;	Point(p137115) = {c137100[0],		c137100[1],		c137015[2],		lc101000VFine};	c137115[]={Point{p137115}};
p137125=newp;	Point(p137125) = {c137100[0],		c137100[1],		c137025[2],		lc101000VFine};	c137125[]={Point{p137125}};
p137140=newp;	Point(p137140) = {c136300[0],		c136300[1],		c137040[2],		lc101000VFine};	c137140[]={Point{p137140}};
//
// South Anchorage North Bot Flange
p138000=p133200;	c138000[]={Point{p138000}};
p138010=p133210;	c138010[]={Point{p138010}};
p138013=p133213;	c138013[]={Point{p138013}};
p138015=p133215;	c138015[]={Point{p138015}};
p138025=p133225;	c138025[]={Point{p138025}};
p138027=p133227;	c138027[]={Point{p138027}};
p138030=p133230;	c138030[]={Point{p138030}};
p138040=p133240;	c138040[]={Point{p138040}};
p138100=p122200;	c138100[]={Point{p138100}};
p138113=newp;	Point(p138113) = {c138100[0],		c138100[1],		c138013[2],		lc101000VFine};	c138113[]={Point{p138113}};
p138115=newp;	Point(p138115) = {c138100[0],		c138100[1],		c138015[2],		lc101000VFine};	c138115[]={Point{p138115}};
p138125=newp;	Point(p138125) = {c138100[0],		c138100[1],		c138025[2],		lc101000VFine};	c138125[]={Point{p138125}};
p138127=newp;	Point(p138127) = {c138100[0],		c138100[1],		c138027[2],		lc101000VFine};	c138127[]={Point{p138127}};
p138140=p136200;	c138140[]={Point{p138140}};
//
// South Anchorage South Top Flange
p139000=p134301;	c139000[]={Point{p139000}};
p139015=p134315;	c139015[]={Point{p139015}};
p139025=p134325;	c139025[]={Point{p139025}};
p139040=p134339;	c139040[]={Point{p139040}};
p139100=newp;	Point(p139100) = {c122320[0],		c122320[1],		c139000[2],		lc101000VFine};	c139100[]={Point{p139100}};
p139115=newp;	Point(p139115) = {c139100[0],		c139100[1],		c139015[2],		lc101000VFine};	c139115[]={Point{p139115}};
p139125=newp;	Point(p139125) = {c139100[0],		c139100[1],		c139025[2],		lc101000VFine};	c139125[]={Point{p139125}};
p139140=newp;	Point(p139140) = {c136320[0],		c136320[1],		c139040[2],		lc101000VFine};	c139140[]={Point{p139140}};
//
// South Anchorage South Bot Flange
p140000=p134200;	c140000[]={Point{p140000}};
p140010=p134210;	c140010[]={Point{p140010}};
p140013=p134213;	c140013[]={Point{p140013}};
p140015=p134215;	c140015[]={Point{p140015}};
p140025=p134225;	c140025[]={Point{p140025}};
p140027=p134227;	c140027[]={Point{p140027}};
p140030=p134230;	c140030[]={Point{p140030}};
p140040=p134240;	c140040[]={Point{p140040}};
p140100=p122220;	c140100[]={Point{p140100}};
p140113=newp;	Point(p140113) = {c140100[0],		c140100[1],		c140013[2],		lc101000VFine};	c140113[]={Point{p140113}};
p140115=newp;	Point(p140115) = {c140100[0],		c140100[1],		c140015[2],		lc101000VFine};	c140115[]={Point{p140115}};
p140125=newp;	Point(p140125) = {c140100[0],		c140100[1],		c140025[2],		lc101000VFine};	c140125[]={Point{p140125}};
p140127=newp;	Point(p140127) = {c140100[0],		c140100[1],		c140027[2],		lc101000VFine};	c140127[]={Point{p140127}};
p140140=p136220;	c126140[]={Point{p140140}};
//
// South Anchorage Flanges
Rotate{{0.0,0.0,1}, {xCableS,yCableS,zCableS}, thetaS*Pi/180} {
  Point{p137100}; Point{p137115}; Point{p137125}; Point{p137140};
  Point{p139100}; Point{p139115}; Point{p139125}; Point{p139140};
  }
//
// _____
// LINES
// 
// South Anchorage North Top Flange
L137000=L133301;
L137015=L133315;
L137025=L133325;
L137100=newl;	Line(L137100) = {p137100, p137115};
L137115=newl;	Line(L137115) = {p137115, p137125};
L137125=newl;	Line(L137125) = {p137125, p137140};
//
L237000=newl;	Line(L237000) = {p137000, p137100};
L237015=newl;	Line(L237015) = {p137015, p137115};
L237025=newl;	Line(L237025) = {p137025, p137125};
L237040=newl;	Line(L237040) = {p137040, p137140};
// 
// South Anchorage North Bot Flange
L138000=L133200;
L138010=L133210;
L138013=L133213;
L138015=L133215;
L138025=L133225;
L138027=L133227;
L138030=L133230;
L138100=newl;	Line(L138100) = {p138100, p138113};
L138113=newl;	Line(L138113) = {p138113, p138115};
L138115=newl;	Line(L138115) = {p138115, p138125};
L138125=newl;	Line(L138125) = {p138125, p138127};
L138127=newl;	Line(L138127) = {p138127, p138140};
//
L238000=L122200;
L238013=newl;	Line(L238013) = {p138013, p138113};
L238015=newl;	Line(L238015) = {p138015, p138115};
L238025=newl;	Line(L238025) = {p138025, p138125};
L238027=newl;	Line(L238027) = {p138027, p138127};
L238040=L136200;
L238045=L136375;
// 
// South Anchorage South Top Flange
L139000=L134301;
L139015=L134315;
L139025=L134325;
L139100=newl;	Line(L139100) = {p139100, p139115};
L139115=newl;	Line(L139115) = {p139115, p139125};
L139125=newl;	Line(L139125) = {p139125, p139140};
//
L239000=newl;	Line(L239000) = {p139000, p139100};
L239015=newl;	Line(L239015) = {p139015, p139115};
L239025=newl;	Line(L239025) = {p139025, p139125};
L239040=newl;	Line(L239040) = {p139040, p139140};
// 
// South Anchorage South Bot Flange
L140000=L134200;
L140010=L134210;
L140013=L134213;
L140015=L134215;
L140025=L134225;
L140027=L134227;
L140030=L134230;
L140100=newl;	Line(L140100) = {p140100, p140113};
L140113=newl;	Line(L140113) = {p140113, p140115};
L140115=newl;	Line(L140115) = {p140115, p140125};
L140125=newl;	Line(L140125) = {p140125, p140127};
L140127=newl;	Line(L140127) = {p140127, p140140};
//
L240000=L122215;
L240013=newl;	Line(L240013) = {p140013, p140113};
L240015=newl;	Line(L240015) = {p140015, p140115};
L240025=newl;	Line(L240025) = {p140025, p140125};
L240027=newl;	Line(L240027) = {p140027, p140127};
L240040=L136215;
//
//
// __________
// LINE LOOPS
//
// South Anchorage North Top Flange
LL137101=newl;	Line Loop(LL137101) =	{L137000,L237015,-L137100,-L237000};
LL137102=newl;	Line Loop(LL137102) =	{L137015,L237025,-L137115,-L237015};
LL137103=newl;	Line Loop(LL137103) =	{L137025,L237040,-L137125,-L237025};
//
LL138101=newl;	Line Loop(LL138101) =	{L138000,L138010,L238013,-L138100,L238000};
LL138102=newl;	Line Loop(LL138102) =	{L138013,L238015,-L138113,-L238013};
LL138103=newl;	Line Loop(LL138103) =	{L138015,L238025,-L138115,-L238015};
LL138104=newl;	Line Loop(LL138104) =	{L138025,L238027,-L138125,-L238025};
LL138105=newl;	Line Loop(LL138105) =	{L138027,L138030,-L238045,-L238040,-L138127,-L238027};
//
// North Anchorage South Top Flange
LL139101=newl;	Line Loop(LL139101) =	{L139000,L239015,-L139100,-L239000};
LL139102=newl;	Line Loop(LL139102) =	{L139015,L239025,-L139115,-L239015};
LL139103=newl;	Line Loop(LL139103) =	{L139025,L239040,-L139125,-L239025};
//
// North Anchorage South Bot Flange
LL140101=newl;	Line Loop(LL140101) =	{L140000,L140010,L240013,-L140100,-L240000};
LL140102=newl;	Line Loop(LL140102) =	{L140013,L240015,-L140113,-L240013};
LL140103=newl;	Line Loop(LL140103) =	{L140015,L240025,-L140115,-L240015};
LL140104=newl;	Line Loop(LL140104) =	{L140025,L240027,-L140125,-L240025};
LL140105=newl;	Line Loop(LL140105) =	{L140027,L140030,L240040,-L140127,-L240027};
//
// ________
// SURFACES
//
// South Anchorage North Top Flange
PS137101=news;	Plane Surface(PS137101) =	{LL137101};
PS137102=news;	Plane Surface(PS137102) =	{LL137102};
PS137103=news;	Plane Surface(PS137103) =	{LL137103};
//
// South Anchorage North Bot Flange
PS138101=news;	Plane Surface(PS138101) =	{LL138101};
PS138102=news;	Plane Surface(PS138102) =	{LL138102};
PS138103=news;	Plane Surface(PS138103) =	{LL138103};
PS138104=news;	Plane Surface(PS138104) =	{LL138104};
PS138105=news;	Plane Surface(PS138105) =	{LL138105};
//
// South Anchorage South Top Flange
PS139101=news;	Plane Surface(PS139101) =	{LL139101};
PS139102=news;	Plane Surface(PS139102) =	{LL139102};
PS139103=news;	Plane Surface(PS139103) =	{LL139103};
//
// South Anchorage South Bot Flange
PS140101=news;	Plane Surface(PS140101) =	{LL140101};
PS140102=news;	Plane Surface(PS140102) =	{LL140102};
PS140103=news;	Plane Surface(PS140103) =	{LL140103};
PS140104=news;	Plane Surface(PS140104) =	{LL140104};
PS140105=news;	Plane Surface(PS140105) =	{LL140105};
//
//
/********************************************************************* 
 *
 *  NORTH ANCHORAGE STIFFENERS
 *
 *********************************************************************/
//
// ______
// POINTS
//
// North Anchorage North-East Stiffener
p127315=p123015;	c127315[]={Point{p127315}};
p127325=p123115;	c127325[]={Point{p127325}};
p127415=p124015;	c127415[]={Point{p127415}};
p127425=p124115;	c127425[]={Point{p127425}};
//
// North Anchorage North-West Stiffener
p128315=p123025;	c128315[]={Point{p128315}};
p128325=p123125;	c128325[]={Point{p128325}};
p128415=p124025;	c128415[]={Point{p128415}};
p128425=p124125;	c128425[]={Point{p128425}};
//
// North Anchorage South-East Stiffener
p129315=p125015;	c129315[]={Point{p129315}};
p129325=p125115;	c129325[]={Point{p129325}};
p129415=p126015;	c129415[]={Point{p129415}};
p129425=p126115;	c129425[]={Point{p129425}};
//
// North Anchorage South-West Stiffener
p130315=p125025;	c130315[]={Point{p130315}};
p130325=p125125;	c130325[]={Point{p130325}};
p130415=p126025;	c130415[]={Point{p130415}};
p130425=p126125;	c130425[]={Point{p130425}};
//
// _____
// LINES
// 
// North Anchorage North-East Stiffener
L127315=L223015;
L127415=L224015;
L227415=L219215;
L227425=newl;	Line(L227425) = {p127425, p127325};
// 
// North Anchorage North-West Stiffener
L128315=L223025;
L128415=L224025;
L228415=L219225;
L228425=newl;	Line(L228425) = {p128425, p128325};
// 
// North Anchorage South-East Stiffener
L129315=L225015;
L129415=L226015;
L229415=L220215;
L229425=newl;	Line(L229425) = {p129425, p129325};
// 
// North Anchorage South-West Stiffener
L130315=L225025;
L130415=L226025;
L230415=L220225;
L230425=newl;	Line(L230425) = {p130425, p130325};
//
//
// __________
// LINE LOOPS
//
// 
LL127101=newl;	Line Loop(LL127101) =	{L127415,L227425,-L127315,-L227415};
LL128101=newl;	Line Loop(LL128101) =	{L128415,L228425,-L128315,-L228415};
LL129101=newl;	Line Loop(LL129101) =	{L129415,L229425,-L129315,-L229415};
LL130101=newl;	Line Loop(LL130101) =	{L130415,L230425,-L130315,-L230415};
//
// ________
// SURFACES
//
// 
PS127101=news;	Plane Surface(PS127101) =	{LL127101};
PS128101=news;	Plane Surface(PS128101) =	{LL128101};
PS129101=news;	Plane Surface(PS129101) =	{LL129101};
PS130101=news;	Plane Surface(PS130101) =	{LL130101};
//
//
//
/********************************************************************* 
 *
 *  SOUTH ANCHORAGE STIFFENERS
 *
 *********************************************************************/
//
// ______
// POINTS
//
// South Anchorage North-East Stiffener
p141315=p137015;	c141315[]={Point{p141315}};
p141325=p137115;	c141325[]={Point{p141325}};
p141415=p138015;	c141415[]={Point{p141415}};
p141425=p138115;	c141425[]={Point{p141425}};
//
// South Anchorage North-West Stiffener
p142315=p137025;	c142315[]={Point{p142315}};
p142325=p137125;	c142325[]={Point{p142325}};
p142415=p138025;	c142415[]={Point{p142415}};
p142425=p138125;	c142425[]={Point{p142425}};
//
// South Anchorage South-East Stiffener
p143315=p139015;	c143315[]={Point{p143315}};
p143325=p139115;	c143325[]={Point{p143325}};
p143415=p140015;	c143415[]={Point{p143415}};
p143425=p140115;	c143425[]={Point{p143425}};
//
// South Anchorage South-West Stiffener
p144315=p139025;	c144315[]={Point{p144315}};
p144325=p139125;	c144325[]={Point{p144325}};
p144415=p140025;	c144415[]={Point{p144415}};
p144425=p140125;	c144425[]={Point{p144425}};
//
// _____
// LINES
// 
// South Anchorage North-East Stiffener
L141315=L237015;
L141415=L238015;
L241415=L233215;
L241425=newl;	Line(L241425) = {p141425, p141325};
// 
// South Anchorage North-West Stiffener
L142315=L237025;
L142415=L238025;
L242415=L233225;
L242425=newl;	Line(L242425) = {p142425, p142325};
// 
// South Anchorage South-East Stiffener
L143315=L239015;
L143415=L240015;
L243415=L234215;
L243425=newl;	Line(L243425) = {p143425, p143325};
// 
// South Anchorage South-West Stiffener
L144315=L239025;
L144415=L240025;
L244415=L234225;
L244425=newl;	Line(L244425) = {p144425, p144325};
//
//
// __________
// LINE LOOPS
//
// 
LL141101=newl;	Line Loop(LL141101) =	{L141415,L241425,-L141315,-L241415};
LL142101=newl;	Line Loop(LL142101) =	{L142415,L242425,-L142315,-L242415};
LL143101=newl;	Line Loop(LL143101) =	{L143415,L243425,-L143315,-L243415};
LL144101=newl;	Line Loop(LL144101) =	{L144415,L244425,-L144315,-L244415};
//
// ________
// SURFACES
//
// 
PS141101=news;	Plane Surface(PS141101) =	{LL141101};
PS142101=news;	Plane Surface(PS142101) =	{LL142101};
PS143101=news;	Plane Surface(PS143101) =	{LL143101};
PS144101=news;	Plane Surface(PS144101) =	{LL144101};
//
//
/********************************************************************* 
 *
 *  PHYSICAL ENTITIES (ALSO MORE P.E.'S AT END)
 *
 *********************************************************************/
//
//
// ____________
// TIE WEB EAST
TieWebE=500101;		Physical Surface(TieWebE) =	{ PS101001,PS101004 }; 
TieWebEL=500102;	Physical Surface(TieWebEL) =	{ PS101002,PS101003 }; 
AnchNepE=500103;	Physical Surface(AnchNepE) =	{ PS121001,PS121002,PS121003,PS121004,PS121005 };
AnchSepE=500104;	Physical Surface(AnchSepE) =	{ PS122001,PS122002,PS122003,PS122004,PS122005 };
//
// ____________
// TIE WEB WEST
TieWebW=500105;		Physical Surface(TieWebW) =	{ PS102001,PS102004 }; 
TieWebWL=500106;	Physical Surface(TieWebWL) =	{ PS102002,PS102003 }; 
TieWebWG=500107;	Physical Surface(TieWebWG) =	{ PS102011,PS102012,PS102013,PS102014 };
AnchNepW=500108;	Physical Surface(AnchNepW) =	{ PS135001,PS135002,PS135003,PS135004,PS135005 };
AnchSepW=500109;	Physical Surface(AnchSepW) =	{ PS136004,PS136005,PS136011,PS136012,PS136013,PS136014 };
AnchSepWG=500110;	Physical Surface(AnchSepWG) =	{ PS136001,PS136002,PS136003,PS136006,PS136008,PS136009,PS136010 };
// ______________
// TIE FLANGE TOP
TieFlT=500111;		Physical Surface(TieFlT) =	{ PS103003,PS103006 }; 
TieFlTL=500112;		Physical Surface(TieFlTL) =	{ PS103001,PS103002,PS103007,PS103010 }; 
TieFlTR=500113;		Physical Surface(TieFlTR) =	{ PS103702,PS103703,PS103704,PS103705,PS103902,PS103903,PS103904,PS103905 }; 
TieFlTLG=500114;	Physical Surface(TieFlTLG) =	{ PS103008,PS103009 }; 
TieFlTG=500115;		Physical Surface(TieFlTG) =	{ PS103004,PS103005 }; 
//
// ______________
// TIE FLANGE BOT
TieFlB=500116;		Physical Surface(TieFlB) =	{ PS104003,PS104006 }; 
TieFlBL=500117;		Physical Surface(TieFlBL) =	{ PS104001,PS104002,PS104007,PS104010 }; 
TieFlBLG=500118;	Physical Surface(TieFlBLG) =	{ PS104008,PS104009 }; 
TieFlBG=500119;		Physical Surface(TieFlBG) =	{ PS104004,PS104005 }; 
//
// ____________________
// FLOORBEAM TOP FLANGE
FbFlT=500201;		Physical Surface(FbFlT) =	{ PS106003,PS106004,PS106005,PS106006,PS106007,PS106008 }; 
FbFlTG=500202;		Physical Surface(FbFlTG) =	{ PS106001,PS106002 }; 
brg1=500203;		Physical Surface(brg1) =	{ PS106011,PS106012,PS106013,PS106014 }; 
brg2=500204;		Physical Surface(brg2) =	{ PS106021,PS106022,PS106023,PS106024 }; 
//
// ____________________
// FLOORBEAM BOT FLANGE
FbFlB=500205;		Physical Surface(FbFlB) =	{ PS107003,PS107004,PS107005,PS107006,PS107007,PS107008 }; 
FbFlBG=500206;		Physical Surface(FbFlBG) =	{ PS107001,PS107002 }; 
//
// _____________
// FLOORBEAM WEB
FbWeb=500207;		Physical Surface(FbWeb) =	{ PS105002,PS105003,PS105004 }; 
FbWebL=500208;		Physical Surface(FbWebL) =	{ PS105001 }; 
FbWebG=500209;		Physical Surface(FbWebG) =	{ PS105005,PS105006 }; 
//
// ____________________
// FLOORBEAM STIFFENERS
FbStif=500210;		Physical Surface(FbStif) =	{ PS111100,PS112100,PS113100,PS114100 }; 
//
// ________________________________
// LOWER LATERAL BRACING BOT FLANGE
LatFlT=500301;		Physical Surface(LatFlT) =	{ PS117100 }; 
//
// ________________________________
// LOWER LATERAL BRACING TOP FLANGE
LatFlB=500302;		Physical Surface(LatFlB) =	{ PS118100 }; 
//
// ______________________________
// LOWER LATERAL BRACING EAST WEB
LatWebE=500303;		Physical Surface(LatWebE) =	{ PS115100 }; 
//
// ______________________________
// LOWER LATERAL BRACING WEST WEB
LatWebW=500304;		Physical Surface(LatWebW) =	{ PS116100 }; 
//
// __________
// GUSSET TOP
GussT=500401;		Physical Surface(GussT) =	{ PS108100 }; 
//
// __________
// GUSSET BOT
GussB=500402;		Physical Surface(GussB) =	{ PS109100 }; 
//
// _____________
// TIE DIAPHRAGM
TieDiaph=500501;	Physical Surface(TieDiaph) =	{ PS110101 }; 
//
// ____________________
// NORTH ANCHORAGE WEBS
AncNWebN=500601;	Physical Surface(AncNWebN) =	{ PS119101,PS119102,PS119103,PS119104,PS119105 }; 
AncNWebS=500602;	Physical Surface(AncNWebS) =	{ PS120101,PS120102,PS120103,PS120104,PS120105 }; 
//
// ____________________
// SOUTH ANCHORAGE WEBS
AncSWebN=500603;	Physical Surface(AncSWebN) =	{ PS133101,PS133102,PS133103,PS133104,PS133105 }; 
AncSWebS=500604;	Physical Surface(AncSWebS) =	{ PS134101,PS134102,PS134103,PS134104,PS134105 }; 
//
// _______________________
// NORTH ANCHORAGE FLANGES
AncNFlTN=500605;	Physical Surface(AncNFlTN) =	{ PS123101,PS123102,PS123103 }; 
AncNFlBN=500606;	Physical Surface(AncNFlBN) =	{ PS124101,PS124105 }; 
AncNFlTS=500607;	Physical Surface(AncNFlTS) =	{ PS125101,PS125102,PS125103 }; 
AncNFlBS=500608;	Physical Surface(AncNFlBS) =	{ PS126101,PS126105 }; 
//
// _______________________
// SOUTH ANCHORAGE FLANGES
AncSFlTN=500609;	Physical Surface(AncSFlTN) =	{ PS137101,PS137102,PS137103 }; 
AncSFlBN=500610;	Physical Surface(AncSFlBN) =	{ PS138101,PS138105 }; 
AncSFlTS=500611;	Physical Surface(AncSFlTS) =	{ PS139101,PS139102,PS139103 }; 
AncSFlBS=500612;	Physical Surface(AncSFlBS) =	{ PS140101,PS140105 }; 
//
// __________________________
// NORTH ANCHORAGE STIFFENERS
AncNStNE=500613;	Physical Surface(AncNStNE) =	{ PS127101 }; 
AncNStNW=500614;	Physical Surface(AncNStNW) =	{ PS128101 }; 
AncNStSE=500615;	Physical Surface(AncNStSE) =	{ PS129101 }; 
AncNStSW=500616;	Physical Surface(AncNStSW) =	{ PS130101 }; 
//
// __________________________
// SOUTH ANCHORAGE STIFFENERS
AncSStNE=500617;	Physical Surface(AncSStNE) =	{ PS141101 }; 
AncSStNW=500618;	Physical Surface(AncSStNW) =	{ PS142101 }; 
AncSStSE=500619;	Physical Surface(AncSStSE) =	{ PS143101 }; 
AncSStSW=500620;	Physical Surface(AncSStSW) =	{ PS144101 }; 
//
//
//
/********************************************************************* 
 *
 *  STRUDL MODEL ATTACHMENTS
 *
 *********************************************************************/
//
// ______
// POINTS
//
// North Cable Anchor Point
p207000=newp;	Point(p207000) = {xCableN,		yCableN,		zCableN,		lcMed};	c207000[]={Point{p207000}};
PtAncN=500701;	Physical Point(PtAncN) = { p207000 };
RigAncN=500702;	Physical Line(RigAncN) = {	L124015,L124115,L224015,L224025,
						L126015,L126115,L226015,L226025 };
//
// South Cable Anchor Point
p208000=newp;	Point(p208000) = {xCableS,		yCableS,		zCableS,		lcMed};	c208000[]={Point{p208000}};
PtAncS=500703;	Physical Point(PtAncS) = { p208000 };
RigAncS=500704;	Physical Line(RigAncS) = {	L138015,L138115,L238015,L238025,
						L140015,L140115,L240015,L240025 };
//
// North end Tie rigid body and support
p201000=newp;	Point(p201000) = {c101100[0],	(c103100[1]+c104100[1])/2,	(c103100[2]+c103400[2])/2,	lcMed};	c201000[]={Point{p201000}};
p201001=newp;	Point(p201001) = {-10.4583333333333*12,		c201000[1],	c201000[2],			lcMed};	c201001[]={Point{p201001}};
L201000=newl;	Line(L201000) = {p201000, p201001};
MbSpTN=500801;	Physical Line(MbSpTN) = {L201000};
RigTN=500802;	Physical Line(RigTN) = {	L203100,L203200,L203300,
						L202100,
						L204100,L204200,L204300,
						L201100 };
//
// South end Tie rigid body and support
p202000=newp;	Point(p202000) = {c103125[0],	(c103125[1]+c104125[1])/2,	(c103100[2]+c103425[2])/2,	lcMed};	c202000[]={Point{p202000}};
p202001=newp;	Point(p202001) = {10.4583333333333*12,		c202000[1],	c202000[2],			lcMed};	c202001[]={Point{p202001}};
L202000=newl;	Line(L202000) = {p202000, p202001};
MbSpTS=500901;	Physical Line(MbSpTS) = {L202000};
RigTS=500902;	Physical Line(RigTS) = {	L203125,L203225,L203325,
						L202125,
						L204125,L204225,L204325,
						L201125 };
//
// West end FB rigid body and support
// p203000 is defined above with FB web (p105000's)
p203001=newp;	Point(p203001) = {c203000[0],		c203000[1]+6*.01,		c203000[2]+6,		lcMed};	c203001[]={Point{p203001}};
L203000=newl;	Line(L203000) = {p203000, p203001};
MbSpFBW=501001;	Physical Line(MbSpFBW) = {L203000};
RigFBW=501002;	Physical Line(RigFBW) = {	L106500,L106520,
						L205150,L303000,
						L107500,L107520 };
//
// South-West end Lower Lateral Bracing rigid body and support
p205000=newp;	Point(p205000) = {xinit+67.75,	(c117100[1]+c118100[1])/2,	zinit+56.125,		lcMed};	c205000[]={Point{p205000}};
p205001=newp;	Point(p205001) = {xinit+753,	c102510[1]+.02*617.375,		zinit+617.375,		lcMed};	c205001[]={Point{p205001}};
L205000=newl;	Line(L205000) = {p205000, p205001};
MbSpLLBS=501101;	Physical Line(MbSpLLBS) = {L205000};
RigLLBS=501102;	Physical Line(RigLLBS) = {	L117110,L118110,L215110,L216110 };
//
//
// ______________
// SUPPORT POINTS
PtSpTN=501201;		Physical Point(PtSpTN) =	{ p201001 }; 
PtSpTS=501202;		Physical Point(PtSpTS) =	{ p202001 }; 
PtSpFBW=501203;		Physical Point(PtSpFBW) =	{ p203001 }; 
PtSpLLBS=501204;	Physical Point(PtSpLLBS) =	{ p205001 }; 
//
PtMTN=501301;		Physical Point(PtMTN) =		{ p201000 }; 
PtMTS=501302;		Physical Point(PtMTS) =		{ p202000 }; 
PtMFBW=501303;		Physical Point(PtMFBW) =	{ p203000 }; 
PtMLLBS=501304;		Physical Point(PtMLLBS) =	{ p205000 }; 
//
// ________
// Bearings
RigBrg1=501401;		Physical Line(RigBrg1) =		{ L106251,L106252,L206253,L206325,-L106352,-L106351,-L206315,-L206251 }; 
PtBrg1=501402;		Physical Point(PtBrg1) =		{ p106320 }; 
RigBrg2=501403;		Physical Line(RigBrg2) =		{ L106361,L106362,L206363,L206425,-L106452,-L106451,-L206415,-L206361 }; 
PtBrg2=501404;		Physical Point(PtBrg2) =		{ p106420 }; 
//
//
//
/********************************************************************* 
 *
 *  MORE PHYSICAL ENTITIES
 *
 *********************************************************************/
//
//
// _________________
// GUIDE PIPES NORTH
GuidePipeN=501501;		Physical Surface(GuidePipeN) =		{ PSpipe103601,PSpipe103602,PSpipe103603,PSpipe103604,
									  PSpipe103661,PSpipe103662,PSpipe103663,PSpipe103664 }; 
RigidGuidePipeN=501502;		Physical Line(RigidGuidePipeN) =	{ L103791,L103792,L103793,L103794 }; 
PtLoadGuidePipeN=501503;	Physical Point(PtLoadGuidePipeN) =	{ p103790 }; 
PtMstrGuidePipeN=501504;	Physical Point(PtMstrGuidePipeN) =	{ p103780 }; 
MbGuidePipeN=501505;		Physical Line(MbGuidePipeN) =		{ L103671 }; 
GuidePipeFinsN=501506;		Physical Surface(GuidePipeFinsN) =	{ PS103751,PS103752,PS103753,PS103754 }; 
//
// _________________
// GUIDE PIPES SOUTH
GuidePipeS=501601;		Physical Surface(GuidePipeS) =		{ PSpipe103801,PSpipe103802,PSpipe103803,PSpipe103804,
									  PSpipe103861,PSpipe103862,PSpipe103863,PSpipe103864 }; 
RigidGuidePipeS=501602;		Physical Line(RigidGuidePipeS) =	{ L103991,L103992,L103993,L103994 }; 
PtLoadGuidePipeS=501603;	Physical Point(PtLoadGuidePipeS) =	{ p103990 }; 
PtMstrGuidePipeS=501604;	Physical Point(PtMstrGuidePipeS) =	{ p103980 }; 
MbGuidePipeS=501605;		Physical Line(MbGuidePipeS) =		{ L103871 }; 
GuidePipeFinsS=501606;		Physical Surface(GuidePipeFinsS) =	{ PS103951,PS103952,PS103953,PS103954 }; 
//
// _____________________
// ANCHOR BEARING PLATES
RigidAnchorN=501701;		Physical Surface(RigidAnchorN) =	{ PS124102,PS124103,PS124104,PS126102,PS126103,PS126104 }; 
RigidAnchorS=501801;		Physical Surface(RigidAnchorS) =	{ PS138102,PS138103,PS138104,PS140102,PS140103,PS140104 }; 

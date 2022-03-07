
// Set global parameters

DOM_SIZE          = 1000. ;
TRANS_LAYER_THICK = 5. ;
TRANS_LAYER_DIVS = 8 ;

// ------------------ // ------------------------------------------------------------------------------- //
centreMeshFactor = 30; // default = 1, increase the factor to get a rougher mesh around the circle centre //
// ------------------ // ------------------------------------------------------------------------------- //

// the mesh sizes are computed to satisfy two constraints (number of elements across interphase thickness (8) and
// number of elements on the circle arc (480))
centreMeshSize = 5.36688745;
outerMeshSize = 5.36688745;
innerMeshSize = 5.23598776;

// Lists of bubble center coordinates (x,y) and bubble radii

bubble_xs[] = { 0. } ;
bubble_ys[] = { 0. } ;
bubble_rs[] = { 200. } ;

// Definition of a macro generating a bubble and its interphase layer

Macro GenerateBubble

	pp = newp ;
	Point( pp   ) = { xc     , yc     , 0. , lc_centre} ;
	Point( pp+1 ) = { xc + rp, yc     , 0. , lc_inner} ;
	Point( pp+2 ) = { xc     , yc + rp, 0. , lc_inner} ;
	Point( pp+3 ) = { xc - rp, yc     , 0. , lc_inner} ;
	Point( pp+4 ) = { xc     , yc - rp, 0. , lc_inner} ;
	Point( pp+5 ) = { xc + rp + wt, yc          , 0. , lc_outer} ;
	Point( pp+6 ) = { xc          , yc + rp + wt, 0. , lc_outer} ;
	Point( pp+7 ) = { xc - rp - wt, yc          , 0. , lc_outer} ;
	Point( pp+8 ) = { xc          , yc - rp - wt, 0. , lc_outer} ;
	lp = newl ;
	Circle( lp   ) = { pp+1 , pp , pp+2 } ;
	Circle( lp+1 ) = { pp+2 , pp , pp+3 } ;
	Circle( lp+2 ) = { pp+3 , pp , pp+4 } ;
	Circle( lp+3 ) = { pp+4 , pp , pp+1 } ;
	lt = newl ;
	Circle( lt   ) = { pp+5 , pp , pp+6 } ;
	Circle( lt+1 ) = { pp+6 , pp , pp+7 } ;
	Circle( lt+2 ) = { pp+7 , pp , pp+8 } ;
	Circle( lt+3 ) = { pp+8 , pp , pp+5 } ;
	Line( lt+4 ) = { pp+1 , pp+5 } ;
	Line( lt+5 ) = { pp+2 , pp+6 } ;
	Line( lt+6 ) = { pp+3 , pp+7 } ;
	Line( lt+7 ) = { pp+4 , pp+8 } ;
	llp = newll ;
	Line Loop( llp ) = { lp:(lp+3) } ;
	llt = newll ;
	Line Loop( llt   ) = { lt:(lt+3) } ;
	Line Loop( llt+1 ) = { lt  , -(lt+5), -lp    , lt+4 } ;
	Line Loop( llt+2 ) = { lt+1, -(lt+6), -(lp+1), lt+5 } ;
	Line Loop( llt+3 ) = { lt+2, -(lt+7), -(lp+2), lt+6 } ;
	Line Loop( llt+4 ) = { lt+3, -(lt+4), -(lp+3), lt+7 } ;
	sp = news ;
	Plane Surface( sp ) = { llp } ;
	st = news ;
	Plane Surface( st   ) = { llt+1 } ;
	Plane Surface( st+1 ) = { llt+2 } ;
	Plane Surface( st+2 ) = { llt+3 } ;
	Plane Surface( st+3 ) = { llt+4 } ;

        Transfinite Line{ lp:(lp+3) } = 61; //Ceil[ ( ( nd + 1 ) * Pi  * rp ) / ( 2. * wt ) ] ;        Transfinite Line{ -lt:-(lt+3) } = 61; //Ceil[ ( ( nd + 1 ) * Pi  * rp ) / ( 2. * wt ) ] ;
        Transfinite Line{ lt+4, -(lt+5), lt+6, -(lt+7) } = 5; //( nd + 1 ) ;
        Transfinite Surface{ st:(st+3) } ;
        Recombine Surface{ st:(st+3) } ;
        Hide { Line{ (lt+4):(lt+7) } ; }
        Recursive Hide { Line{ lt:(lt+3) } ; }

    // embed centre point into circle surface to get a rougher mesh size
	Point{ pp } In Surface{ sp };

	bubble_surfs[]     += { sp } ;
	interphase_surfs[] += { st:(st+3) } ;
	interphase_edges[] += { lt:(lt+3) } ;
	interphase_loops[] += { llt } ;

Return

// Domain construction

xd  = DOM_SIZE / 2.  ;
yd  = DOM_SIZE / 2.  ;
lcd = DOM_SIZE / 100. ;
pd = newp ;
Point( pd   ) = {  xd,  yd, 0., lcd } ;
Point( pd+1 ) = { -xd,  yd, 0., lcd } ;
Point( pd+2 ) = { -xd, -yd, 0., lcd } ;
Point( pd+3 ) = {  xd, -yd, 0., lcd } ;
ld = newl ;
Line( ld   ) = { pd   , pd+1 } ;
Line( ld+1 ) = { pd+1 , pd+2 } ;
Line( ld+2 ) = { pd+2 , pd+3 } ;
Line( ld+3 ) = { pd+3 , pd   } ;
lld = newll ;
Line Loop( lld ) = { ld:(ld+3) } ;

// Generate bubbles => ready storage lists

bubble_surfs[]	   = {} ;
interphase_surfs[] = {} ;
interphase_edges[] = {} ;
interphase_loops[] = {} ;

// Generate bubbles => Loop on bubbles
For i_bubble In { 0:(#bubble_xs[] - 1) }

	// Generate bubbles => set bubble parameter
	xc = bubble_xs[ i_bubble ] ;
	yc = bubble_ys[ i_bubble ] ;
	rp = bubble_rs[ i_bubble ] ;
	wt = TRANS_LAYER_THICK ;
	nd = TRANS_LAYER_DIVS ;
	lc_centre = centreMeshFactor * centreMeshSize;
	lc_inner = innerMeshSize;
	lc_outer = outerMeshSize;

	// Generate bubbles => Call macro
	Call GenerateBubble ;

EndFor

// Finalize domain surface accounting for the holes created
// by the particles and their transition layers

sd = news ;
Plane Surface( sd ) = { lld, interphase_loops[] } ;

//Recombine Surface{ bubble_surfs[], sd } ;

// Coloring

Recursive Color Gray { Surface{ bubble_surfs[] } ; }
Recursive Color SkyBlue { Surface{ interphase_surfs[] } ; }
Recursive Color DarkBlue { Surface{ sd } ; }

// Physical tags

Physical Surface( "bubbles", 1000 ) = { bubble_surfs[] } ;
Physical Surface( "interphase layers", 2000 ) = { interphase_surfs[] } ;
Physical Surface( "medium", 3000 ) = { sd } ;

Mesh.Algorithm = 8;
Mesh.SubdivisionAlgorithm = 1;
Mesh.RecombinationAlgorithm = 1;
Mesh.RecombineAll = 1;
Mesh.RecombineOptimizeTopology = 25;

MeshAlgorithm Surface {24} = 5;

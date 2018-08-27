
Geometry.OldRuledSurface = 1; // old-style OK
// Geometry.OldRuledSurface = 0; // new-style

// example of a bad ruled surface interpolation

//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.AutoCoherence = 1;


Point (newp) = {0, 0.042, 0.0};
center = newp-1;

Point (newp) = {0, 0.072, 0.0};
top = newp-1;

Point (newp) = {0.0308972, 0.042, 0.008279};
bot1 = newp-1;

Point (newp) = {0.0315, 0.042, 0.0037};
bot2 = newp-1;

Point (newp) = {0.0315, 0.042, 0.0};
bot3 = newp-1;

Point (newp) = {0.0278075, 0.042, 0.00745098};
ax1 = newp-1;

Point (newp) = {0.02835, 0.042, 0.00333};
ax2 = newp-1;

Point (newp) = {0.02835, 0.042, 0.0};
ax3 = newp-1;

Ellipse (newl) = {top, center, ax1, bot1};
ellip1 = newl-1;

Ellipse (newl) = {top, center, ax2, bot2};
ellip2 = newl-1;

Ellipse (newl) = {top, center, ax3, bot3};
ellip3 = newl-1;

Line (newl) = {bot1, bot2};
botline1 = newl-1;

Line (newl) = {bot2, bot3};
botline2 = newl-1;


Transfinite Line {ellip1, ellip2, ellip3} = 70;
Transfinite Line {botline1, botline2} = 8;



Line Loop (newll) = {ellip1, botline1, -ellip2};
Line Loop (newll) = {ellip2, botline2, -ellip3};
loops[] += {newll-2, newll-1};
Surface (news) = loops[0];
Surface (news) = loops[1];

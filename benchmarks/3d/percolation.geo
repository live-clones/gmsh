
sphere_dist = 0.05; // spheres don't touch
// sphere_dist = 0; // spheres touch

lc = 0.5;

xdim = 5;
ydim = 5;
zdim = 5;

Point(1) = {-1,-1,-Cos(45),lc};
Point(2) = {xdim,-1,-Cos(45),lc};
Point(3) = {xdim,ydim,-Cos(45),lc};
Point(4) = {-1,ydim,-Cos(45),lc};
Line (1) = {1,2};
Line (2) = {2,3};
Line (3) = {3,4};
Line (4) = {4,1};
Line Loop(1) = {1,2,3,4};
Plane Surface(1) = {1};

Extrude {0, 0, -1} { Surface{1}; } // lower electrode
aa[] = Extrude {0, 0, zdim - 1 + 2 * Cos(45)} { Surface{1}; } ;
Extrude {0, 0, 1} { Surface{aa[0]}; } // top electrode

Delete{ Volume{aa[1]}; } // this volume is wrong: we will be carving holes in it

Function newsphere
  rr = 0.5-sphere_dist;
  a = newp; 
  b = newl;
  c = newll; 
  d = news; 
  e = newsl; 
  f = newv; 
  Point(a) = {i,j,k,lc};
  Point(a+1) = {i,j+rr,k,lc};
  Point(a+2) = {i,j-rr,k,lc};
  Point(a+3) = {i+rr,j,k,lc};
  Point(a+4) = {i-rr,j,k,lc};
  Point(a+5) = {i,j,k+rr,lc};
  Point(a+6) = {i,j,k-rr,lc};
  Circle(b) = {a+5,a,a+3};
  Circle(b+1) = {a+3,a,a+6};
  Circle(b+2) = {a+6,a,a+4};
  Circle(b+3) = {a+4,a,a+5};
  Circle(b+4) = {a+1,a,a+6};
  Circle(b+5) = {a+6,a,a+2};
  Circle(b+6) = {a+2,a,a+5};
  Circle(b+7) = {a+5,a,a+1};
  Circle(b+8) = {a+1,a,a+3};
  Circle(b+9) = {a+3,a,a+2};
  Circle(b+10) = {a+2,a,a+4};
  Circle(b+11) = {a+4,a,a+1};
  Line Loop(c) = {b+5,-(b+9),b+1}; Ruled Surface(d) = {c};
  Line Loop(c+1) = {b+9,b+6,b}; Ruled Surface(d+1) = {c+1};
  Line Loop(c+2) = {b+6,-(b+3),-(b+10)}; Ruled Surface(d+2) = {c+2};
  Line Loop(c+3) = {b+10,-(b+2),b+5}; Ruled Surface(d+3) = {c+3};
  Line Loop(c+4) = {b+11,b+4,b+2}; Ruled Surface(d+4) = {c+4};
  Line Loop(c+5) = {b+4,-(b+1),-(b+8)}; Ruled Surface(d+5) = {c+5};
  Line Loop(c+6) = {b+8,-b,b+7}; Ruled Surface(d+6) = {c+6};
  Line Loop(c+7) = {b+7,-(b+11),b+3}; Ruled Surface(d+7) = {c+7};
  Surface Loop(e) = {d+1,-(d+4),-(d+3),d+2,d,(d+6),-(d+5),-(d+7)}; 
  Volume(f) = e;
  holes[] += e; 
Return

//random distribution
For i In {0:xdim-1:1}
  For j In {0:ydim-1:1}
    For k In {0:zdim-1:1}
      num = Fmod(Rand(1), 1);
      If(num >= 0.5) num = 1; EndIf
      If(num < 0.5) num = 0; EndIf
      array[i*ydim*zdim + j*zdim + k] = num;
    EndFor
  EndFor
EndFor

//remove isolated particles
For i In {1:xdim-2:1}
  For j In {1:ydim-2:1}
    For k In {1:zdim-2:1}
      If (array[i*ydim*zdim + j*zdim + k] == 1)
	If (array[(i+1)*ydim*zdim + j*zdim + k] == 0 &&
	    array[(i+1)*ydim*zdim + (j+1)*zdim + k] == 0 &&
	    array[(i+1)*ydim*zdim + (j-1)*zdim + k] == 0 &&
	    array[(i-1)*ydim*zdim + j*zdim + k] == 0 &&
	    array[(i-1)*ydim*zdim + (j+1)*zdim + k] == 0 &&
	    array[(i-1)*ydim*zdim + (j-1)*zdim + k] == 0 &&
	    array[(i)*ydim*zdim + (j+1)*zdim + k] == 0 &&
	    array[(i)*ydim*zdim + (j-1)*zdim + k] == 0 &&
	    
	    array[(i+1)*ydim*zdim + j*zdim + (k-1)] == 0 &&
	    array[(i+1)*ydim*zdim + (j+1)*zdim + (k-1)] == 0 &&
	    array[(i+1)*ydim*zdim + (j-1)*zdim + (k-1)] == 0 &&
	    array[(i-1)*ydim*zdim + j*zdim + (k-1)] == 0 &&
	    array[(i-1)*ydim*zdim + (j+1)*zdim + (k-1)] == 0 &&
	    array[(i-1)*ydim*zdim + (j-1)*zdim + (k-1)] == 0 &&
	    array[(i)*ydim*zdim + (j+1)*zdim + (k-1)] == 0 &&
	    array[(i)*ydim*zdim + (j-1)*zdim + (k-1)] == 0 &&
	    array[i*ydim*zdim + j*zdim + (k-1)]  == 0 &&
	    
	    array[(i+1)*ydim*zdim + j*zdim + (k+1)] == 0 &&
	    array[(i+1)*ydim*zdim + (j+1)*zdim + (k+1)] == 0 &&
	    array[(i+1)*ydim*zdim + (j-1)*zdim + (k+1)] == 0 &&
	    array[(i-1)*ydim*zdim + j*zdim + (k+1)] == 0 &&
	    array[(i-1)*ydim*zdim + (j+1)*zdim + (k+1)] == 0 &&
	    array[(i-1)*ydim*zdim + (j-1)*zdim + (k+1)] == 0 &&
	    array[(i)*ydim*zdim + (j+1)*zdim + (k+1)] == 0 &&
	    array[(i)*ydim*zdim + (j-1)*zdim + (k+1)] == 0 &&
	    array[i*ydim*zdim + j*zdim + (k+1)]  ==  0)
	  array[i*ydim*zdim + j*zdim + k] = 0;
        EndIf
      EndIf
    EndFor
  EndFor
EndFor

For i In {0:xdim-1:1}
  For j In {0:ydim-1:1}
    For k In {0:zdim-1:1}
      //Printf("array[%g][%g][%g] = %g", i, j, k,array[i*ydim*zdim + j*zdim + k]);
      If (array[i*ydim*zdim + j*zdim + k] == 1) 
	Call newsphere;
      EndIf
    EndFor
  EndFor
EndFor

// volume between electrodes with spheres carved out
c = newsl; Surface Loop(c) = {43,-1,35,39,48,47};
v = newv; Volume(v) = {c, holes[]};

Coherence; // make sure duplicate nodes are removed when sphere_dist=0

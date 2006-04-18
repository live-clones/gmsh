lc=0.25;
//dimensions
xdim=5;
ydim=5;
zdim=5;
//electrodes

a=newp; Point(a) = {-1, -1, -Cos(45),lc};
a=newp; Point(a) = {xdim, -1, -Cos(45),lc};
a=newp; Point(a) = {xdim, ydim, -Cos(45),lc};
a=newp; Point(a) = {-1, ydim, -Cos(45),lc};
b1=newl; Line (b1) = {a-3,a-2};
b2=newl; Line (b2) = {a-2,a-1};
b3=newl; Line (b3) = {a-1,a};
b4=newl; Line (b4) = {a,a-3};
c=newll; Line Loop(c) = {b1,b2,b3,b4};
ss=news; Plane Surface(ss) = {c};

Extrude {0,0,-1} { Surface{ss}; } //lower electrode
aa[] = Extrude {0,0,zdim-1+2*Cos(45)} { Surface{ss}; } ;
Extrude {0,0,1} { Surface{aa[0]}; } // top electrode

Delete{ Volume{aa[1]}; } // this volume is wrong: we will be carving holes in it

//functions
Function newsphere
rr = Cos(45)-0.05;
a=newp; Point(a) = {i,j,k,lc};
a=newp; Point(a) = {i,j+ rr,k,lc};
a=newp; Point(a) = {i,j- rr,k,lc};
a=newp; Point(a) = {i+rr,j,k,lc};
a=newp; Point(a) = {i-rr,j,k,lc};
a=newp; Point(a) = {i,j,k+rr,lc};
a=newp; Point(a) = {i,j,k-rr,lc};
b=newl; Circle(b) = {a-1,a-6,a-3};
b=newl; Circle(b) = {a-3,a-6,a};
b=newl; Circle(b) = {a,a-6,a-2};
b=newl; Circle(b) = {a-2,a-6,a-1};
b=newl; Circle(b) = {a-5,a-6,a};
b=newl; Circle(b) = {a,a-6,a-4};
b=newl; Circle(b) = {a-4,a-6,a-1};
b=newl; Circle(b) = {a-1,a-6,a-5};
b=newl; Circle(b) = {a-5,a-6,a-3};
b=newl; Circle(b) = {a-3,a-6,a-4};
b=newl; Circle(b) = {a-4,a-6,a-2};
b=newl; Circle(b) = {a-2,a-6,a-5};
c=newll; Line Loop(c) = {b-6,-(b-2),b-10};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-2,b-5,(b-11)};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-5,-(b-8),-(b-1)};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-1,-(b-9),b-6};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b,b-7,(b-9)};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-7,-(b-10),-(b-3)};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-3,-(b-11),b-4};
d=news; Ruled Surface(d) = {c};
c=newll; Line Loop(c) = {b-4,-b,b-8};
d=news; Ruled Surface(d) = {c};
e=newsl; Surface Loop(e) = {(d-14),-(d-8),-(d-10),(d-12),(d-2),(d-4),-(d-6),-d};
vv=newv; Volume(vv)={e};

holes[]+=e; 

Return

//random distribution
For i In {0:xdim-1:1}
For j In {0:ydim-1:1}
For k In {0:zdim-1:1}
num=Fmod(Rand(1), 1);
If (num>=0.5) num=1; EndIf
If (num<0.5) num=0; EndIf
array[i*ydim*zdim + j*zdim + k] =num;
EndFor
EndFor
EndFor

//remove isolated particles
For i In {1:xdim-2:1}
For j In {1:ydim-2:1}
For k In {1:zdim-2:1}
If (array[i*ydim*zdim + j*zdim + k]==1)
	If (
	array[(i+1)*ydim*zdim + j*zdim + k]==0 &&
	array[(i+1)*ydim*zdim + (j+1)*zdim + k]==0 &&
	array[(i+1)*ydim*zdim + (j-1)*zdim + k]==0 &&
	array[(i-1)*ydim*zdim + j*zdim + k]==0 &&
	array[(i-1)*ydim*zdim + (j+1)*zdim + k]==0 &&
	array[(i-1)*ydim*zdim + (j-1)*zdim + k]==0 &&
	array[(i)*ydim*zdim + (j+1)*zdim + k]==0 &&
	array[(i)*ydim*zdim + (j-1)*zdim + k]==0 &&

	array[(i+1)*ydim*zdim + j*zdim + (k-1)]==0 &&
	array[(i+1)*ydim*zdim + (j+1)*zdim + (k-1)]==0 &&
	array[(i+1)*ydim*zdim + (j-1)*zdim + (k-1)]==0 &&
	array[(i-1)*ydim*zdim + j*zdim + (k-1)]==0 &&
	array[(i-1)*ydim*zdim + (j+1)*zdim + (k-1)]==0 &&
	array[(i-1)*ydim*zdim + (j-1)*zdim + (k-1)]==0 &&
	array[(i)*ydim*zdim + (j+1)*zdim + (k-1)]==0 &&
	array[(i)*ydim*zdim + (j-1)*zdim + (k-1)]==0 &&
	array[i*ydim*zdim + j*zdim + (k-1)] ==0 &&

	array[(i+1)*ydim*zdim + j*zdim + (k+1)]==0 &&
	array[(i+1)*ydim*zdim + (j+1)*zdim + (k+1)]==0 &&
	array[(i+1)*ydim*zdim + (j-1)*zdim + (k+1)]==0 &&
	array[(i-1)*ydim*zdim + j*zdim + (k+1)]==0 &&
	array[(i-1)*ydim*zdim + (j+1)*zdim + (k+1)]==0 &&
	array[(i-1)*ydim*zdim + (j-1)*zdim + (k+1)]==0 &&
	array[(i)*ydim*zdim + (j+1)*zdim + (k+1)]==0 &&
	array[(i)*ydim*zdim + (j-1)*zdim + (k+1)]==0 &&
	array[i*ydim*zdim + j*zdim + (k+1)] ==0)
		array[i*ydim*zdim + j*zdim + k]=0;
EndIf
EndIf

EndFor
EndFor
EndFor

//check
For i In {0:xdim-1:1}
For j In {0:ydim-1:1}
For k In {0:zdim-1:1}
//Printf("array[%g][%g][%g] = %g", i, j, k,array[i*ydim*zdim + j*zdim + k]);
If (array[i*ydim*zdim + j*zdim + k]==1) 
	Call newsphere;
EndIf
EndFor
EndFor
EndFor

c = newsl; Surface Loop(c) = {45,-6,37,41,50,49};
v = newv; Volume(v) = {c, holes[]};


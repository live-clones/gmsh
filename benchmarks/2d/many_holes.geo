Point(1) = {0,0,0,10};
Point(2) = {1473.175,0,0,10};
Point(3) = {0,1473.75,0,10};

Circle (1) = {2,1,3};
Line (2) = {1,2};
Line (3) = {1,3};

Line Loop(10) = {1,-3,2};

//Définition d'une fonction créatrice d'un cercle

Function TubeHole

 p1 = newp; Point(p1) = {x,y,0,4};
 p2 = newp; Point(p2) = {x+r,y,0,4};
 p3 = newp; Point(p3) = {x,y+r,0,4};
 p4 = newp; Point(p4) = {x-0.71*r,y-0.71*r,0,4};

c1 = newreg; Circle(c1) = {p2,p1,p3};
c2 = newreg; Circle(c2) = {p3,p1,p4};
c3 = newreg; Circle(c3) = {p4,p1,p2};

Line Loop(10+K) = {c1,c2,c3};


Return

r=11.3;
y=0;
K=0;

For J In {1:46}
 x=0;
 y+=31.353;
 For I In {1:46}
  x+=31.353;
  If ((x*x+y*y)<1960000)
   K+=1;
   Call TubeHole;
  EndIf
 EndFor
EndFor

Plane Surface (20) = {10,11:(10+K)};

//Physical Surface (30) = {20};


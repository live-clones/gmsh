radius = 1e3;
lc = .05*radius;
Point(1) = {0.0,0.0,0.0,lc};
Point(4) = {-1*radius,0,0.0,lc};
Point(5) = {0,-1*radius,0.0,lc};
Point(7) = {0,0,1*radius,lc};

Circle(3) = {4,1,5};
Circle(7) = {5,1,7};
Circle(10) = {7,1,4};

Line Loop(15) = {10,3,7};
Ruled Surface(16) = {15} In Sphere{1};

 
N=50;
lc1 = 0.05*radius;
teta_c = 3*Pi/2-Pi/4;
lambda_c = 2.2*Pi/6;
R = 1*Pi/9;
radius2 = 1.1*radius;

For i In {0:N-1}
	alpha = i*2*Pi/N;
	lambda = lambda_c+R*Sin(alpha);
	teta = teta_c+R*Cos(alpha);
	Point(8+i) = {radius2*Cos(lambda)*Cos(teta), radius2*Cos(lambda)*Sin(teta), radius2*Sin(lambda), lc1};
	Line(i+13) = {1, 8+i};
EndFor

pp[] = Intersect Line {13:N+12} Surface {16};

Spline(1000) = {pp[], pp[0]};

Delete { Surface{16}; }
//Hide { Line{13:N+12}; Point{8:N+7}; }

Line Loop(16001) = {-1000};

//Ruled Surface(20000) = {15};
Ruled Surface(20000) = {15,16001} In Sphere{1};


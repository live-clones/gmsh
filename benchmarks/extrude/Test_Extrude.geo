s = 0.04;
Radius = 0.5;

Point(1) = { 0.0 , 0.0 , 0.0 , s};
Point(2) = { Radius , 0.0 , 0.0 , s};
Point(3) = { 0.0 , Radius , 0.0 , s};
Point(4) = { -Radius ,0.0 , 0.0 , s};
Point(5) = {0.0 , -Radius , 0.0 , s};

Circle(1) = {2, 1, 3};
Circle(2) = {3, 1, 4};
Circle(3) = {4, 1, 5};
Circle(4) = {5, 1, 2};

Point(6) = { -10 , -10 , 0.0 , 1};
Point(7) = { -10 , 10 , 0.0 , 1};
Point(8) = { 10 , 10 , 0.0 , 1};
Point(9) = { 10 , -10 , 0.0 , 1};

Line(5)={6,7};
Line(6)={7,8};
Line(7)={8,9};
Line(8)={9,6};

Line Loop(1)={5,6,7,8};

ll = 0.01;
NN =100;

ex1[] = Extrude { Line {1};
	Layers{{NN},{ll}};
	Recombine;
};

ex2[] = Extrude { Line {2};
	Layers{{NN},{ll}};
	Recombine;
};

ex3[] = Extrude { Line {3};
	Layers{{NN},{ll}};
	Recombine;
};

ex4[] = Extrude { Line {4};
	Layers{{NN},{ll}};
	Recombine;
};

Line Loop(2)={ex1[0], ex2[0], ex3[0], ex4[0]};

Plane Surface(1) = {1,2};
Line Loop(25) = {1, 2, 3, 4};
Plane Surface(26) = {25};

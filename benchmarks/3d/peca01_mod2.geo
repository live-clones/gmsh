

// peça 01 - manual do protec ( desenho de maquinas )

// extraido do exemplo contido na pagina 6-9
View "comments" {
     T2( 10, 15,0){"peça01 - created on Ter Ago 20 20:10:00 2004"};
     T2(450,-10,0){"Copyright (C) sas"};
     T3(8.75,15,3,0){"R2"};
     T3(66.25,15,3,0){"R3"};
};

// pontos   ************************

       mm = 3;
Point( 1) = { 0.0,   0.0,  0.0, mm};
Point( 2) = {22.5,   0.0,  0.0, mm};
Point( 3) = {52.5,   0.0,  0.0, mm};
Point( 4) = {75.0,   0.0,  0.0, mm};
Point( 5) = { 0.0,   0.0,  6.0, mm};
     
       c1 = 18.42121597166108;
       c2 = 56.57878402833891; 
Point( 6) = {  c1,   0.0,  6.0, mm};
Point( 7) = {  c2,   0.0,  6.0, mm};
Point( 8) = {75.0,   0.0,  6.0, mm};
Point( 9) = {37.5,   0.0, 15.0, mm};
Point(10) = {37.5,   0.0, 20.0, mm};

Point(11) = { 5.25, 15.0, 0.0, mm}; // pontos base do furo r2
Point(12) = {12.25, 15.0, 0.0, mm};
Point(13) = { 8.75, 11.5, 0.0, mm};
Point(14) = { 8.75, 18.5, 0.0, mm};
Point(15) = { 5.25, 15.0, 6.0, mm}; 
Point(16) = {12.25, 15.0, 6.0, mm};
Point(17) = { 8.75, 11.5, 6.0, mm};
Point(18) = { 8.75, 18.5, 6.0, mm};

Point(19) = {62.75, 15.0, 0.0, mm}; // pontos base do furo r3
Point(20) = {69.75, 15.0, 0.0, mm};
Point(21) = {66.25, 11.5, 0.0, mm};
Point(22) = {66.25, 18.5, 0.0, mm};
Point(23) = {62.75, 15.0, 6.0, mm};
Point(24) = {69.75, 15.0, 6.0, mm};
Point(25) = {66.25, 11.5, 6.0, mm};
Point(26) = {66.25, 18.5, 6.0, mm};

Translate{ 0.0, 30.0, 0.0} { Duplicata{ Point{1,2,3,4,5,6,7,8,9,10}; } }
// gerando ate o ponto 36

// pontos auxiliares - centro dos furos 
Point(100) = {37.50,  0.0, 0.0, mm}; // centro r1 - face em y =  0
Point(101) = {37.50, 30.0, 0.0, mm}; // centro r1 - face em y = 30
Point(102) = { 8.75, 15.0, 0.0, mm}; // centro r2
Point(103) = {66.25, 15.0, 0.0, mm}; // centro r3
Point(104) = { 8.75, 15.0, 6.0, mm};
Point(105) = {66.25, 15.0, 6.0, mm};

// linhas *****************************

Line(1) = { 1, 2};        // face em y = 0
Circle(2) = { 2, 100, 9}; 
Circle(3) = { 9, 100, 3};
Line(4) = {3, 4};
Line(5) = {4, 8};
Line(6) = {8, 7};
Circle(7) = { 7, 100, 10};
Circle(8) = {10, 100,  6};
Line(9) = {6, 5};
Line(10) = {5, 1};

Translate{ 0.0, 30.0, 0.0} { Duplicata{ Line{1,2,3,4,5,6,7,8,9,10}; } } // face em y = 30
// com essa operação geramos mais 10 linhas, portanto ...

Circle(21) = {11,102,13};
Circle(22) = {13,102,12};
Circle(23) = {12,102,14};
Circle(24) = {14,102,11};

Translate{ 0.0, 0.0, 6.0} { Duplicata{ Line{21,22,23,24}; } }
// linhas 25 a 28 

Circle(29) = {19,103,21};
Circle(30) = {21,103,20};
Circle(31) = {20,103,22};
Circle(32) = {22,103,19};

Translate{ 0.0, 0.0, 6.0} { Duplicata{ Line{29,30,31,32}; } }
// linhas 33 a 36
 
// linhas especiais - considerar quando associar a normal a superficie
Line(37) = {15,11}; // em r2
Line(38) = {17,13};
Line(39) = {16,12};
Line(40) = {18,14};

Line(41) = {23,19}; // em r3
Line(42) = {25,21};
Line(43) = {24,20};
Line(44) = {26,22};

Line(45) = {31, 5}; // proximo a r2
Line(46) = {27, 1};
Line(47) = {32, 6};
Line(48) = {28, 2};

Line(49) = {36,10}; // no centro da peça 
Line(50) = {35, 9};

Line(51) = {33, 7}; // proximo a r3
Line(52) = {29, 3};
Line(53) = {34, 8};
Line(54) = {30, 4};  

// superficies **********************************

// surperficies curvas 

Line Loop(55) = {25,38,-21,-37}; // para furo r2
Line Loop(56) = {26,39,-22,-38};
Line Loop(57) = {27,40,-23,-39};
Line Loop(58) = {28,37,-24,-40};
Ruled Surface(59) = {55}; // superficie cont. r2 
Ruled Surface(60) = {56}; // superficie cont. r2 
Ruled Surface(61) = {57}; // superficie cont. r2 
Ruled Surface(62) = {58}; // superficie cont. r2 

Line Loop(60) = {33,42,-29,-41}; // para furo r3
Line Loop(61) = {34,43,-30,-42};
Line Loop(62) = {35,44,-31,-43};
Line Loop(63) = {36,41,-32,-44};
Ruled Surface(64) = {60}; // superficie cont. r3
Ruled Surface(65) = {61}; // superficie cont. r3
Ruled Surface(66) = {62}; // superficie cont. r3
Ruled Surface(67) = {63}; // superficie cont. r3

Line Loop(65) = {25,26,27,28}; // linha na superf. (z = 6) furo r2
Line Loop(66) = {21,22,23,24}; // idem quando z = 0.

Line Loop(67) = {33,34,35,36}; // linha na superf. (z = 6) furo r3
Line Loop(68) = {29,30,31,32}; // idem quando z = 0.

Line Loop(69) = {47,-8,-49,18}; // para r1 (r = 20) proxim a r2
Line Loop(70) = {49,-7,-51,17}; // idem - proximo a r3

Line Loop(71) = {12,50,-2,-48}; // para r1 (r = 15) proxim a r2
Line Loop(72) = {13,52,-3,-50}; // idem - proximo a r3

Ruled Surface(73) = {69}; // conjunto surf. em r = 20
Ruled Surface(74) = {70}; 

// caso se deseje a composição {69,70} gera a 
// superficie curva exterior para o raio = 20 

Ruled Surface(75) = {71}; // conjunto surf. em r = 15
Ruled Surface(76) = {72};

// superficies planas - sem furos.

Line Loop(77) = {-45,-10,46,20};
Plane Surface(78) = {77}; // prox r2 (x = 0) 

Line Loop(79) =  {1,2,3,4,5,6,7,8,9,10};
Plane Surface(80) = {79}; // plano em (y = 0)

Line Loop(81) = {53,-5,-54,15};
Plane Surface(82) = {81}; // plano em (x = 75)
 
Line Loop(83) = {-20,-19,-18,-17,-16,-15,-14,-13,-12,-11};
Plane Surface(84) = {83}; // plano em (y = 30)

// superficies planas - com furos
// importante notar que nao ha a necessidade do vetor normal de 
// orientação dos loops de linhas estarem direcionados para a 
// superficie em questao - um exemplo deste fato e o easymesh
// para malhas bidimensionais. Portanto 

Line Loop(85) = {45,-9,-47,19}; // superf em r2 (z=6)
// a linha relacionada ao furo ja fora executada em line loop(65)
Plane Surface(86) = {85,65};

Line Loop(87) = {11,48,-1,-46}; // superf em r2 (z=0)
Plane Surface(88) = {87,66};

Line Loop(89) = {51,-6,-53,16}; // superf em r3 (z=6)
Plane Surface(90) = {89,67};

Line Loop(91) = {14,54,-4,-52}; // superf em r3 (z=0)
Plane Surface(92) = {91,68};

// aqui houve uma tentativa de execução de malha, para o caso 2d houve
// uma falha ..., nao sei ao certo o que aconteceu,mas me parece que o 
// gmsh 1.54.1 nao segue executar malhas sobre superficies curvas ?!

// relacao das superficies:
//                          59 -- furo R2
//                          64 -- furo R3
//         CURVAS        73,74 -- superficie com raio 20 mm
//                       75,76 --    ...      .. raio 15 mm
                         
//                          78 -- plano em x = 0
//         PLANAS           80 --    ...   y = 0
//                          82 --    ...   x = 75
//                          84 --    ...   y = 30
                          
//                          86 --    ...   z = 6 p/R2
//                          88 --    ...   z = 0

//                          90 --    ...   z = 6 p/R3
//                          92 --    ...   z = 0


// definido as superficies fisicas
Physical Surface(1) = {59};
Physical Surface(2) = {64};
Physical Surface(3) = {73};
Physical Surface(4) = {74};
Physical Surface(5) = {75};
Physical Surface(6) = {76};
Physical Surface(7) = {78};
Physical Surface(8) = {80};
Physical Surface(9) = {82};
Physical Surface(10) = {84};
Physical Surface(11) = {86};
Physical Surface(12) = {88};
Physical Surface(13) = {90};
Physical Surface(14) = {92};

// volumes ***************************
Surface Loop(93) = {73,86,78,84,74,80,88,75,76,92,82,90,67,64,65,66,-62,-59,-60,-61};
Volume(94) = {93};

Physical Volume(1) = {94};

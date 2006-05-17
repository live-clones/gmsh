

a_1 = 1;
a_2 = 2;
a_3 = 3;
a_4 = 4;
a_5 = 5;

Printf("this is my data file") > "aa.dat";

For i In {1:5}
Printf("a = %g", a~{i}) >> "aa.dat";
EndFor


Printf("Hey, this is it!") >> "aa.dat";


scale=1000;

clc1=3/scale;
clc2=1/scale;
clc3=1/scale;
clc4=10/scale;

rad1=52/scale;

cp1_1=newp; Point(cp1_1)={rad1,0,0,clc1};
cp1_2=newp; Point(cp1_2)={-rad1,0,0,clc1};
cp1_3=newp; Point(cp1_3)={0,rad1,0,clc1};
cp1_4=newp; Point(cp1_4)={0,-rad1,0,clc1};
cp1_5=newp; Point(cp1_5)={0,0,rad1,clc1};
cp1_6=newp; Point(cp1_6)={0,0,-rad1,clc1};
cp1_m=newp; Point(cp1_m)={0,0,0,clc1};

cbow1_1=newl; Circle(cbow1_1)={cp1_1,cp1_m,cp1_3};
cbow1_2=newl; Circle(cbow1_2)={cp1_2,cp1_m,cp1_3};
cbow1_3=newl; Circle(cbow1_3)={cp1_1,cp1_m,cp1_4};
cbow1_4=newl; Circle(cbow1_4)={cp1_2,cp1_m,cp1_4};
cbow1_5=newl; Circle(cbow1_5)={cp1_5,cp1_m,cp1_3};
cbow1_6=newl; Circle(cbow1_6)={cp1_6,cp1_m,cp1_3};
cbow1_7=newl; Circle(cbow1_7)={cp1_5,cp1_m,cp1_4};
cbow1_8=newl; Circle(cbow1_8)={cp1_6,cp1_m,cp1_4};
cbow1_9=newl; Circle(cbow1_9)={cp1_1,cp1_m,cp1_5};
cbow1_10=newl; Circle(cbow1_10)={cp1_2,cp1_m,cp1_5};
cbow1_11=newl; Circle(cbow1_11)={cp1_1,cp1_m,cp1_6};
cbow1_12=newl; Circle(cbow1_12)={cp1_2,cp1_m,cp1_6};

lloop1_1 = newreg; Line Loop(lloop1_1) = {-cbow1_1,cbow1_9,cbow1_5}; qsurf1_1 = news; Ruled Surface(qsurf1_1)={lloop1_1}; 
lloop1_2 = newreg; Line Loop(lloop1_2) = {-cbow1_1,cbow1_11,cbow1_6}; qsurf1_2 = news; Ruled Surface(qsurf1_2)={lloop1_2}; 
lloop1_3 = newreg; Line Loop(lloop1_3) = {-cbow1_8,-cbow1_11,cbow1_3}; qsurf1_3 = news; Ruled Surface(qsurf1_3)={lloop1_3}; 
lloop1_4 = newreg; Line Loop(lloop1_4) = {cbow1_7,-cbow1_3,cbow1_9}; qsurf1_4 = news; Ruled Surface(qsurf1_4)={lloop1_4}; 
lloop1_5 = newreg; Line Loop(lloop1_5) = {-cbow1_5,-cbow1_10,cbow1_2}; qsurf1_5 = news; Ruled Surface(qsurf1_5)={lloop1_5}; 
lloop1_6 = newreg; Line Loop(lloop1_6) = {cbow1_6,-cbow1_2,cbow1_12}; qsurf1_6 = news; Ruled Surface(qsurf1_6)={lloop1_6}; 
lloop1_7 = newreg; Line Loop(lloop1_7) = {-cbow1_4,cbow1_10,cbow1_7}; qsurf1_7 = news; Ruled Surface(qsurf1_7)={lloop1_7}; 
lloop1_8 = newreg; Line Loop(lloop1_8) = {-cbow1_8,-cbow1_12,cbow1_4}; qsurf1_8 = news; Ruled Surface(qsurf1_8)={lloop1_8}; 

spheresloop1=news; Surface Loop(spheresloop1) = {qsurf1_1,qsurf1_2,qsurf1_3,qsurf1_4,qsurf1_5,qsurf1_6,qsurf1_7,qsurf1_8};

rad2=57/scale;

cp2_1=newp; Point(cp2_1)={rad2,0,0,clc2};
cp2_2=newp; Point(cp2_2)={-rad2,0,0,clc2};
cp2_3=newp; Point(cp2_3)={0,rad2,0,clc2};
cp2_4=newp; Point(cp2_4)={0,-rad2,0,clc2};
cp2_5=newp; Point(cp2_5)={0,0,rad2,clc2};
cp2_6=newp; Point(cp2_6)={0,0,-rad2,clc2};
cp2_m=newp; Point(cp2_m)={0,0,0,clc2};

cbow2_1=newl; Circle(cbow2_1)={cp2_1,cp2_m,cp2_3};
cbow2_2=newl; Circle(cbow2_2)={cp2_2,cp2_m,cp2_3};
cbow2_3=newl; Circle(cbow2_3)={cp2_1,cp2_m,cp2_4};
cbow2_4=newl; Circle(cbow2_4)={cp2_2,cp2_m,cp2_4};
cbow2_5=newl; Circle(cbow2_5)={cp2_5,cp2_m,cp2_3};
cbow2_6=newl; Circle(cbow2_6)={cp2_6,cp2_m,cp2_3};
cbow2_7=newl; Circle(cbow2_7)={cp2_5,cp2_m,cp2_4};
cbow2_8=newl; Circle(cbow2_8)={cp2_6,cp2_m,cp2_4};
cbow2_9=newl; Circle(cbow2_9)={cp2_1,cp2_m,cp2_5};
cbow2_10=newl; Circle(cbow2_10)={cp2_2,cp2_m,cp2_5};
cbow2_11=newl; Circle(cbow2_11)={cp2_1,cp2_m,cp2_6};
cbow2_12=newl; Circle(cbow2_12)={cp2_2,cp2_m,cp2_6};

lloop2_1 = newreg; Line Loop(lloop2_1) = {-cbow2_1,cbow2_9,cbow2_5}; qsurf2_1 = news; Ruled Surface(qsurf2_1)={lloop2_1}; 
lloop2_2 = newreg; Line Loop(lloop2_2) = {-cbow2_1,cbow2_11,cbow2_6}; qsurf2_2 = news; Ruled Surface(qsurf2_2)={lloop2_2}; 
lloop2_3 = newreg; Line Loop(lloop2_3) = {-cbow2_8,-cbow2_11,cbow2_3}; qsurf2_3 = news; Ruled Surface(qsurf2_3)={lloop2_3}; 
lloop2_4 = newreg; Line Loop(lloop2_4) = {cbow2_7,-cbow2_3,cbow2_9}; qsurf2_4 = news; Ruled Surface(qsurf2_4)={lloop2_4}; 
lloop2_5 = newreg; Line Loop(lloop2_5) = {-cbow2_5,-cbow2_10,cbow2_2}; qsurf2_5 = news; Ruled Surface(qsurf2_5)={lloop2_5}; 
lloop2_6 = newreg; Line Loop(lloop2_6) = {cbow2_6,-cbow2_2,cbow2_12}; qsurf2_6 = news; Ruled Surface(qsurf2_6)={lloop2_6}; 
lloop2_7 = newreg; Line Loop(lloop2_7) = {-cbow2_4,cbow2_10,cbow2_7}; qsurf2_7 = news; Ruled Surface(qsurf2_7)={lloop2_7}; 
lloop2_8 = newreg; Line Loop(lloop2_8) = {-cbow2_8,-cbow2_12,cbow2_4}; qsurf2_8 = news; Ruled Surface(qsurf2_8)={lloop2_8}; 

spheresloop2=news; Surface Loop(spheresloop2) = {qsurf2_1,qsurf2_2,qsurf2_3,qsurf2_4,qsurf2_5,qsurf2_6,qsurf2_7,qsurf2_8};

rad3=59/scale;

cp3_1=newp; Point(cp3_1)={rad3,0,0,clc3};
cp3_2=newp; Point(cp3_2)={-rad3,0,0,clc3};
cp3_3=newp; Point(cp3_3)={0,rad3,0,clc3};
cp3_4=newp; Point(cp3_4)={0,-rad3,0,clc3};
cp3_5=newp; Point(cp3_5)={0,0,rad3,clc3};
cp3_6=newp; Point(cp3_6)={0,0,-rad3,clc3};
cp3_m=newp; Point(cp3_m)={0,0,0,clc3};

cbow3_1=newl; Circle(cbow3_1)={cp3_1,cp3_m,cp3_3};
cbow3_2=newl; Circle(cbow3_2)={cp3_2,cp3_m,cp3_3};
cbow3_3=newl; Circle(cbow3_3)={cp3_1,cp3_m,cp3_4};
cbow3_4=newl; Circle(cbow3_4)={cp3_2,cp3_m,cp3_4};
cbow3_5=newl; Circle(cbow3_5)={cp3_5,cp3_m,cp3_3};
cbow3_6=newl; Circle(cbow3_6)={cp3_6,cp3_m,cp3_3};
cbow3_7=newl; Circle(cbow3_7)={cp3_5,cp3_m,cp3_4};
cbow3_8=newl; Circle(cbow3_8)={cp3_6,cp3_m,cp3_4};
cbow3_9=newl; Circle(cbow3_9)={cp3_1,cp3_m,cp3_5};
cbow3_10=newl; Circle(cbow3_10)={cp3_2,cp3_m,cp3_5};
cbow3_11=newl; Circle(cbow3_11)={cp3_1,cp3_m,cp3_6};
cbow3_12=newl; Circle(cbow3_12)={cp3_2,cp3_m,cp3_6};

lloop3_1 = newreg; Line Loop(lloop3_1) = {-cbow3_1,cbow3_9,cbow3_5}; qsurf3_1 = news; Ruled Surface(qsurf3_1)={lloop3_1}; 
lloop3_2 = newreg; Line Loop(lloop3_2) = {-cbow3_1,cbow3_11,cbow3_6}; qsurf3_2 = news; Ruled Surface(qsurf3_2)={lloop3_2}; 
lloop3_3 = newreg; Line Loop(lloop3_3) = {-cbow3_8,-cbow3_11,cbow3_3}; qsurf3_3 = news; Ruled Surface(qsurf3_3)={lloop3_3}; 
lloop3_4 = newreg; Line Loop(lloop3_4) = {cbow3_7,-cbow3_3,cbow3_9}; qsurf3_4 = news; Ruled Surface(qsurf3_4)={lloop3_4}; 
lloop3_5 = newreg; Line Loop(lloop3_5) = {-cbow3_5,-cbow3_10,cbow3_2}; qsurf3_5 = news; Ruled Surface(qsurf3_5)={lloop3_5}; 
lloop3_6 = newreg; Line Loop(lloop3_6) = {cbow3_6,-cbow3_2,cbow3_12}; qsurf3_6 = news; Ruled Surface(qsurf3_6)={lloop3_6}; 
lloop3_7 = newreg; Line Loop(lloop3_7) = {-cbow3_4,cbow3_10,cbow3_7}; qsurf3_7 = news; Ruled Surface(qsurf3_7)={lloop3_7}; 
lloop3_8 = newreg; Line Loop(lloop3_8) = {-cbow3_8,-cbow3_12,cbow3_4}; qsurf3_8 = news; Ruled Surface(qsurf3_8)={lloop3_8}; 

spheresloop3=news; Surface Loop(spheresloop3) = {qsurf3_1,qsurf3_2,qsurf3_3,qsurf3_4,qsurf3_5,qsurf3_6,qsurf3_7,qsurf3_8};

rad4=400/scale;

cp4_1=newp; Point(cp4_1)={rad4,0,0,clc4};
cp4_2=newp; Point(cp4_2)={-rad4,0,0,clc4};
cp4_3=newp; Point(cp4_3)={0,rad4,0,clc4};
cp4_4=newp; Point(cp4_4)={0,-rad4,0,clc4};
cp4_5=newp; Point(cp4_5)={0,0,rad4,clc4};
cp4_6=newp; Point(cp4_6)={0,0,-rad4,clc4};
cp4_m=newp; Point(cp4_m)={0,0,0,clc4};

cbow4_1=newl; Circle(cbow4_1)={cp4_1,cp4_m,cp4_3};
cbow4_2=newl; Circle(cbow4_2)={cp4_2,cp4_m,cp4_3};
cbow4_3=newl; Circle(cbow4_3)={cp4_1,cp4_m,cp4_4};
cbow4_4=newl; Circle(cbow4_4)={cp4_2,cp4_m,cp4_4};
cbow4_5=newl; Circle(cbow4_5)={cp4_5,cp4_m,cp4_3};
cbow4_6=newl; Circle(cbow4_6)={cp4_6,cp4_m,cp4_3};
cbow4_7=newl; Circle(cbow4_7)={cp4_5,cp4_m,cp4_4};
cbow4_8=newl; Circle(cbow4_8)={cp4_6,cp4_m,cp4_4};
cbow4_9=newl; Circle(cbow4_9)={cp4_1,cp4_m,cp4_5};
cbow4_10=newl; Circle(cbow4_10)={cp4_2,cp4_m,cp4_5};
cbow4_11=newl; Circle(cbow4_11)={cp4_1,cp4_m,cp4_6};
cbow4_12=newl; Circle(cbow4_12)={cp4_2,cp4_m,cp4_6};

lloop4_1 = newreg; Line Loop(lloop4_1) = {-cbow4_1,cbow4_9,cbow4_5}; qsurf4_1 = news; Ruled Surface(qsurf4_1)={lloop4_1}; 
lloop4_2 = newreg; Line Loop(lloop4_2) = {-cbow4_1,cbow4_11,cbow4_6}; qsurf4_2 = news; Ruled Surface(qsurf4_2)={lloop4_2}; 
lloop4_3 = newreg; Line Loop(lloop4_3) = {-cbow4_8,-cbow4_11,cbow4_3}; qsurf4_3 = news; Ruled Surface(qsurf4_3)={lloop4_3}; 
lloop4_4 = newreg; Line Loop(lloop4_4) = {cbow4_7,-cbow4_3,cbow4_9}; qsurf4_4 = news; Ruled Surface(qsurf4_4)={lloop4_4}; 
lloop4_5 = newreg; Line Loop(lloop4_5) = {-cbow4_5,-cbow4_10,cbow4_2}; qsurf4_5 = news; Ruled Surface(qsurf4_5)={lloop4_5}; 
lloop4_6 = newreg; Line Loop(lloop4_6) = {cbow4_6,-cbow4_2,cbow4_12}; qsurf4_6 = news; Ruled Surface(qsurf4_6)={lloop4_6}; 
lloop4_7 = newreg; Line Loop(lloop4_7) = {-cbow4_4,cbow4_10,cbow4_7}; qsurf4_7 = news; Ruled Surface(qsurf4_7)={lloop4_7}; 
lloop4_8 = newreg; Line Loop(lloop4_8) = {-cbow4_8,-cbow4_12,cbow4_4}; qsurf4_8 = news; Ruled Surface(qsurf4_8)={lloop4_8}; 

spheresloop4=news; Surface Loop(spheresloop4) = {qsurf4_1,qsurf4_2,qsurf4_3,qsurf4_4,qsurf4_5,qsurf4_6,qsurf4_7,qsurf4_8};

svol1=newv; Volume(svol1)={spheresloop1};
Physical Volume(1)={svol1};

svol2=newv; Volume(svol2)={spheresloop2,spheresloop1};
Physical Volume(2)={svol2};

svol3=newv; Volume(svol3)={spheresloop3,spheresloop2};
Physical Volume(3)={svol3};

svol4=newv; Volume(svol4)={spheresloop4,spheresloop3};
Physical Volume(4)={svol4};

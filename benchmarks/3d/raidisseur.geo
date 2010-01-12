
x = 0; y = 0; z = 0; ep = 0.025; l = 0.4; r = 0.1; h = 6.5; lc = 1;

p1 = newp; Point(p1) = {x, y, z, lc};
p2 = newp; Point(p2) = {x, y + ep, z, lc};
l1 = newl; Line(l1) = {p1, p2};
tmp1[] = Extrude {l, 0, 0} { Line{l1}; };
tmp2[] = Extrude {{0, 0, 1}, {x+l, y+ep+r/2, 0}, Pi/4} { Line{tmp1[0]}; };
tmp3[] = Extrude {l/4, l/4, 0} { Line{tmp2[0]}; };
tmp4[] = Extrude {{0, 0, 1}, {x+l+l/2, y+ep+r/2, 0}, -Pi/4} { Line{tmp3[0]}; };
tmp5[] = Extrude {l/4, 0, 0} { Line{tmp4[0]}; };
tmp6[] = Extrude {{0, 0, 1}, {x+l+l/2+l/4, y+ep+r/2, 0}, -Pi/4} { Line{tmp5[0]}; };
tmp7[] = Extrude {l/4, -l/4, 0} { Line{tmp6[0]}; };
tmp8[] = Extrude {{0, 0, 1}, {x+l+l+l/4, y+ep+r/2, 0}, Pi/4} { Line{tmp7[0]}; };
tmp9[] = Extrude {l, 0, 0} { Line{tmp8[0]}; };

p3 = newp; Point(p3) = {x,y-ep,z,lc};
l2 = newl; Line(l2) = {p1,p3};
tmp10[] = Extrude {l, 0, 0} { Line{l2}; };
tmp11[] = Extrude {l+l/4, 0, 0} { Line{tmp10[0]}; };
tmp12[] = Extrude {l, 0, 0} { Line{tmp11[0]}; };

tmp13[] = Extrude {-l/4, 0, 0} { Line{l2}; };
tmp14[] = Extrude {l/4, 0, 0} { Line{tmp12[0]}; };

Extrude {0,0,h} {
  Surface{tmp1[1],tmp2[1],tmp3[1],tmp4[1],tmp5[1],
      tmp6[1],tmp7[1],tmp8[1],tmp9[1],tmp10[1],tmp11[1],tmp12[1],
      tmp13[1], tmp14[1]}; 
}

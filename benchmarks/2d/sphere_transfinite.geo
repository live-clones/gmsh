 x = 0;
 y = 0;
 z = 0;
 r = 1;

 aufl = 5;

 p1 = newp; Point(p1) = {x, y, z, 0.2} ;
 p2 = newp; Point(p2) = {x+r,y, z, 0.2} ;
 p3 = newp; Point(p3) = {x, y+r,z, 0.2} ;
 p4 = newp; Point(p4) = {x, y, z+r, 0.2} ;
 p5 = newp; Point(p5) = {x-r,y, z, 0.2} ;
 p6 = newp; Point(p6) = {x, y-r,z, 0.2} ;
 p7 = newp; Point(p7) = {x, y, z-r, 0.2} ;

 c1 = newreg; Circle(c1) = {p2,p1,p7};
 c2 = newreg; Circle(c2) = {p7,p1,p5};
 c3 = newreg; Circle(c3) = {p5,p1,p4};
 c4 = newreg; Circle(c4) = {p4,p1,p2};
 c5 = newreg; Circle(c5) = {p2,p1,p3};
 c6 = newreg; Circle(c6) = {p3,p1,p5};
 c7 = newreg; Circle(c7) = {p5,p1,p6};
 c8 = newreg; Circle(c8) = {p6,p1,p2};
 c9 = newreg; Circle(c9) = {p7,p1,p3};
 c10 = newreg; Circle(c10) = {p3,p1,p4};
 c11 = newreg; Circle(c11) = {p4,p1,p6};
 c12 = newreg; Circle(c12) = {p6,p1,p7};

 l1 = newreg; Line Loop(l1) = {c5,c10,c4};
 l2 = newreg; Line Loop(l2) = {c9,-c5,c1};
 l3 = newreg; Line Loop(l3) = {c12,-c8,-c1};
 l4 = newreg; Line Loop(l4) = {c8,-c4,c11};
 l5 = newreg; Line Loop(l5) = {-c10,c6,c3};
 l6 = newreg; Line Loop(l6) = {-c11,-c3,c7};
 l7 = newreg; Line Loop(l7) = {-c2,-c7,-c12};
 l8 = newreg; Line Loop(l8) = {-c6,-c9,c2};

 s1 = newreg; Surface(newreg) = {-l1};
 s2 = newreg; Surface(newreg) = {-l2};
 s3 = newreg; Surface(newreg) = {-l3};
 s4 = newreg; Surface(newreg) = {-l4};
 s5 = newreg; Surface(newreg) = {-l5};
 s6 = newreg; Surface(newreg) = {-l6};
 s7 = newreg; Surface(newreg) = {-l7};
 s8 = newreg; Surface(newreg) = {-l8};

 Transfinite Line {c5,c10,c4} = aufl Using Progression 1.0;
 Transfinite Line {c9,-c5,c1} = aufl Using Progression 1.0;
 Transfinite Line {c12,-c8,-c1} = aufl Using Progression 1.0;
 Transfinite Line {c8,-c4,c11} = aufl Using Progression 1.0;
 Transfinite Line {-c10,c6,c3} = aufl Using Progression 1.0;
 Transfinite Line {-c11,-c3,c7} = aufl Using Progression 1.0;
 Transfinite Line {-c2,-c7,-c12} = aufl Using Progression 1.0;
 Transfinite Line {-c6,-c9,c2} = aufl Using Progression 1.0;

 Transfinite Surface {s1} = {p4,p3,p2};
 Transfinite Surface {s2} = {p7,p3,p2};
 Transfinite Surface {s3} = {p7,p6,p2};
 Transfinite Surface {s4} = {p4,p6,p2};
 Transfinite Surface {s5} = {p4,p5,p3};
 Transfinite Surface {s6} = {p4,p6,p5};
 Transfinite Surface {s7} = {p7,p6,p5};
 Transfinite Surface {s8} = {p7,p3,p5};

 Recombine Surface {s1};
 Recombine Surface {s2};
 Recombine Surface {s3};
 Recombine Surface {s4};
 Recombine Surface {s5};
 Recombine Surface {s6};
 Recombine Surface {s7};
 Recombine Surface {s8};

 Physical Surface(100) = {s1,s2,s3,s4,s5,s6,s7,s8};

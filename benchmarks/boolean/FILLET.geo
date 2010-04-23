L = 100;
H = 30;
Z = 10;
OCCShape("Box",{0,0,0,L,H,Z},"none");
R = 4;

OCCShape("Fillet",{1:12,R},"none");

OCCShape("Cone",{0*L/2,H/2,-Z,0,0,1,.3*R,2*R,3*Z},"Fuse");
OCCShape("Fillet",{1,R},"none");
OCCShape("Fillet",{14,R/8},"none");
OCCShape("Cone",{0.99*L/2,H/2,-Z,0,0,1,.3*R,2*R,3*Z},"Fuse");
OCCShape("Fillet",{1,R},"none");
OCCShape("Fillet",{83,R/8},"none");
OCCShape("Cone",{0.99*L,H/2,-Z,0,0,1,3*R,.2*R,3*Z},"Cut");


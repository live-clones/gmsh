Merge "aorta2.stl";
CreateTopology;

Merge "aortaRADIUS2.bgm";


out[] = Extrude{Surface{1}; Layers{4, 1.5}; Using Index[0]; Using View[0]; };

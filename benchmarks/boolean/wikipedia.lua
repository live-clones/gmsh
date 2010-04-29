
-- from http://en.wikipedia.org/wiki/Constructive_solid_geometry

R = 1.0;
s = .8;
t = 1.35;
myModel = GModel();
myModel:addBlock({-R,-R,-R},{R,R,R});

myTool = GModel();
myTool:addSphere(0,0,0,R*t);

myModel:computeIntersection(myTool,0);

myTool2 = GModel();
myTool2:addCylinder({-2*R,0,0},{2*R,0,0},R*s);

myTool3 = GModel();
myTool3:addCylinder({0,-2*R,0},{0,2*R,0},R*s);

myModel2 = GModel();
myModel2:addCylinder({0,0,-2*R},{0,0,2*R},R*s);
myModel2:computeUnion(myTool2,0);
myModel2:computeUnion(myTool3,0);

myModel:computeDifference(myModel2,0);
myModel:setAsCurrent();


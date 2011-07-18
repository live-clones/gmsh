#!/usr/bin/env python

from gmshpy import *

# from http://en.wikipedia.org/wiki/Constructive_solid_geometry

R = 1.4;
s = .7;
t = 1.25;
myModel = GModel();
myModel.addBlock([-R,-R,-R],[R,R,R]);

myTool = GModel();
myTool.addSphere(0,0,0,R*t);

myModel.computeBooleanIntersection(myTool);

myTool2 = GModel();
myTool2.addCylinder([-2*R,0,0],[2*R,0,0],R*s);

myTool3 = GModel();
myTool3.addCylinder([0,-2*R,0],[0,2*R,0],R*s);

myModel2 = GModel();
myModel2.addCylinder([0,0,-2*R],[0,0,2*R],R*s);
myModel2.computeBooleanUnion(myTool2);
myModel2.computeBooleanUnion(myTool3);

myModel.computeBooleanDifference(myModel2);

myModel.setAsCurrent();

#myModel.mesh(3);
#myModel.save("wikipedia.msh");
myModel.save("wikipedia.brep");

FlGui.instance();
FlGui.run();

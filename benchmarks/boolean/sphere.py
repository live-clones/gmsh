from dgpy import *
from gmshpy import *

GmshSetOption('Mesh', 'CharacteristicLengthFactor', 0.9)

R = 0.3;
myModel = GModel();
myModel.addSphere(0.5,0.5,0.5,R);

myModel.setAsCurrent();

myModel.mesh(2);
myModel.save("sphere.stl");

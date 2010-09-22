options = gmshOptions()
options:initOptions()
options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 0.9grep -IIr)

R = 1.0;
myModel = GModel();
myModel:addSphere(0,0,0,R);

myModel:setAsCurrent();

myModel:mesh(2);

options = gmshOptions()
options:initOptions()
options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 0.9);

R = 1.0;
myModel = GModel();
myModel:addSphere(0,0,0,R);

myModel:setAsCurrent();

--myModel:mesh(2);

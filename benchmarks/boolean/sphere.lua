
options = gmshOptions()
options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 0.6)

myTool = GModel();
myTool:addSphere(0.0,0.0,0.0,1);

myTool:mesh(1)
myTool:mesh(2)
myTool:save('sphere.msh')
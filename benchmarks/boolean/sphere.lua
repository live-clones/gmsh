
options = gmshOptions()
options:numberSet('Mesh', 0, 'CharacteristicLengthFactor', 1.5)

myTool = GModel();
myTool:addSphere(0.0,0.0,0.0,1);

myTool:mesh(1)
myTool:mesh(2)
myTool:save('sphere.msh')

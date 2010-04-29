
g = GModel()
v1 = g:addVertex(0, 0, 0, 1)
v2 = g:addVertex(1, 0, 0, 1)
e1 = g:addLine(v1, v2)

dir = fullMatrix(2,3)
dir:set(0,0, 0);
dir:set(0,1, 0);
dir:set(0,2, 0);
dir:set(1,0, 0);
dir:set(1,1, 1);
dir:set(1,2, 0);
f1 = g:extrude(e1, dir)


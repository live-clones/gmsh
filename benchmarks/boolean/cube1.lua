
g = GModel()
v1 = g:addVertex(0, 0, 0, 1)
v2 = g:addVertex(1, 0, 0, 1)
e1 = g:addLine(v1, v2)
f1 = g:extrude(e1, {0,0,0}, {0,1,0})
r1 = g:extrude(f1, {0,0,0}, {0,0,1})


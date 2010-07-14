
g = GModel()
v1 = g:addVertex(0, 0, 0, .1)
v2 = g:addVertex(1, 0, 0, .1)
v3 = g:addVertex(1, 1, 0, .1)
v4 = g:addVertex(0, 3, 1, .1)
v5 = g:addVertex(2, 3, 0, .1)
v6 = g:addVertex(-2, 3, 0, .1)
v7 = g:addVertex(-1, 3, 0, .1)

--v11 = g:addVertex(2.5, 2.5, 0, .1)
--v12 = g:addVertex(2.6, 2.5, 0, .1)
--v13 = g:addVertex(2.6, 2.6, 0, .1)
--v14 = g:addVertex(2.5, 2.6, 0, .1)


e7 = g:addBezier (v2,v1, {{v3:x(),v3:y(),0},{v4:x(),v4:y(),0},{v5:x(),v5:y(),0},{v6:x(),v6:y(),0},{v7:x(),v7:y(),0}}); 							   
--e8 = g:addLine (v2,v1);

v221 = g:addVertex(0, 0, 10, .1)
v121 = g:addVertex(1, 0, 10, .1)
e17 = g:addBezier (v121,v221, {{v3:x()+1,v3:y(),10},{v4:x(),v4:y()+2,10},{v5:x(),v5:y()-3,10},{v6:x(),v6:y(),10},{v7:x(),v7:y(),10}}); 							   

--e11 = g:addLine (v11,v12);
--e12 = g:addLine (v12,v13);
--e13 = g:addLine (v13,v14);
--e14 = g:addLine (v14,v11);


g:addRuledFaces ({{e7},{e17}})
--g:addFace ({e7,e8},{{0,0,0}})
--g:addFace ({e11,e12,e13,e14})

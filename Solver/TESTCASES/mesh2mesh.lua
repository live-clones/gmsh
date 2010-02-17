-- initial condition
function initial_condition( xyz , f )
  for i=0,xyz:size1()-1 do
    x = xyz:get(i,0)
    y = xyz:get(i,1)
    z = xyz:get(i,2)
    f:set (i, 0, math.exp(-100*((x-0.2)^2 +(y-0.3)^2)))
    f:set (i, 1, math.exp(-100*((x-0.4)^2 +(y-0.3)^2)))
    f:set (i, 2, math.exp(-100*((x+0.2)^2 +(y-0.3)^2)))
  end
end

dimension = 2
order1 = 1
order2 = 2

model1 = GModel()
model2 = GModel()
-- load a mesh
model1:load('square1.msh')
-- load another mesh
model2:load('square2.msh');

-- create 2 groups related to the 2 models with different orders
groups1 = dgGroupCollection  (model1 , dimension, order1)
groups1:buildGroupsOfInterfaces()
groups2 = dgGroupCollection  (model2 , dimension, order2)
groups2:buildGroupsOfInterfaces()

-- create 2 solutions
solution1 = dgDofContainer(groups1, 3);
solution2 = dgDofContainer(groups2, 3);

-- apply initial solution to solution1
solution1:L2Projection(functionLua(3,'initial_condition',{'XYZ'}):getName())
-- save the stuff
solution1:exportMsh('solution1');

-- this is the function that interpolates solution1
F = functionMesh2Mesh(solution1)

-- project solution 1 onto mesh 2
solution2:L2Projection(F:getName())
-- save the stuff
solution2:exportMsh('solution2');



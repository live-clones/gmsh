/*****************************      
A cube with a hole   
*****************************/      
  
Point(1) = {0.0,0.0,0.0,.1};
Extrude Point {1, {1,0.0,0} };
Extrude Line {1, {0.0,0.0,1} };
Extrude Surface {5, {0,1,0} };
  
Point(100) = {0.3,0.3,0.3,.1};
Extrude Point {100, {.4,0.0,0} };
Extrude Line {28, {0,0.4,0} };
Extrude Surface {32, {0,0.,0.4} };
 
Surface Loop(55) = {-26,5,-14,-18,-22,-27};
Surface Loop(56) = {-41,32,-45,-49,-53,-54};
Volume(57) = {55,56};
//Volume(57) = {55};

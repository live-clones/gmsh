/*****************************  
Another Way to generate
a cube  
*****************************/  
Point(1) = {0.0,0.0,0.0,.2};          
Extrude Point {1, {1,0.0,0} };               
Extrude Line {1, {0.0,0.0,1} };
Extrude Surface {5, {0,1,0} };

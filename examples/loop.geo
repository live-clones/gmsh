/*
This is a very simple control sequense
with 2 imbricated loops
*/

t = 0.0;
For (1:10)
  x = 0.0;
  For (1:10:2)
    Point(newp) = {t,x,0,.1};
    x = x + 0.1;  
  EndFor
  t = t + 0.1;  
EndFor

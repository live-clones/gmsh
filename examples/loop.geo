/*
This is a very simple control sequense
with 2 imbricated loops
*/

For t In {0:1:0.1}
  For x In {0:0.5:0.1}
    Point(newp) = {t,x,0,.1};
  EndFor
EndFor

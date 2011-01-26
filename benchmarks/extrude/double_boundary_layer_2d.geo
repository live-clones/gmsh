Point(1) =  {0,0,0,0.1}; 
Point(2) =  {1,0,0,0.1}; 
Line(1) = {1, 2}; 

tmp1[] = Extrude { Line{1}; Layers{5, 0.1}; Recombine; Using Index[0]; };
tmp2[] = Extrude { Line{-1}; Layers{5, 0.1}; Recombine; Using Index[1]; };

/*

  (10)---6-----(9)

   8             7

  (1)----1-----(2)
 
   3            4

  (5)----2-----(6)


 */

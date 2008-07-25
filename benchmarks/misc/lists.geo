
a = 1;
Printf("a = %g", a);

Printf("Deleting a");
Delete a;
Printf("a = %g  <--- should produce an error", a);

b[] = {1,2,3};

Printf("b = %g %g %g", b[{0:2}]);

Printf("b[b[0]] = %g", b[b[0]]);

c[{1,2,3}] = {5,6,7} ;

c[0] = 4 ;

Printf("c = %g %g %g %g", c[]);

c[{0:3}] = {-1,-2,-3,-4} ;

Printf("c = %g %g %g %g", c[]);

c[{b[]}] = {8,9,10} ;

Printf("c = %g %g %g %g", c[]);

Include "errcheck.geo" ;

undefined = 999;

Include "errcheck.geo" ;

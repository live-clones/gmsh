
// this tests that we can still load as many views as we want.
// (even if only 100 are allowed in the GUI)

View.Visible = 0;

For i In {1:250}

Printf("i=%g", i);
Merge "../../tutorial/view1.pos" ;
Merge "../../tutorial/view2.pos" ;

EndFor

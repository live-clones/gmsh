
// this tests that we can still load as many views as we want.
// (even if only 100 are allowed in the GUI)

View.Visible = 0;

For i In {1:250}

Include "../../tutorial/view1.pos" ;
Include "../../tutorial/view2.pos" ;

EndFor

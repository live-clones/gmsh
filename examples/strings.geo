

Include "../tutorial/view1.pos" ;

View[0].Name = "gloups.prout" ;

General.Trackball = 0 ;

For num In {1:2}

  General.RotationX += 10 ;

  Print Strcat( Strprefix(Strdup(View[0].Name)) , Sprintf("-%g.jpg", num) ) ;

  Draw ;

EndFor


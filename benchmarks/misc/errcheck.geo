defined=0;

For i In {1:4}

defined++;

Printf("defined = %g", defined);

If (defined == 4)
  undefined++;
  Printf("undefined = %g!", undefined);
EndIf

EndFor


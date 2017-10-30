DefineConstant[
  a = {1, Name "var1", Label "Master variable", ServerAction "Reset var3"}
  b = {a*2, Name "var2", Label "Slave (x 2) variable", ReadOnly 1}
  c = {a*2, Name "var3", Label "Editable slave (x 2) variable"}
  d = {a*2, Name "var4", Label "Standard (x 2) variable"}
  e = {1, Name "var5", Label "Another master", ServerAction "Reset  var6,  var7 space "}
  f = {e, Name "var6", Label "Another slave (copy)"}
  g = {e, Name "var7 space", Label "Another slave (copy)"}
];

Printf("a=%g b=%g c=%g d=%g", a, b, c, d);

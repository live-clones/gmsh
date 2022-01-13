Merge "tutorials/t1.geo";
Merge "tutorials/view1.pos";

DefineConstant
[
 m1 = {"script_convert_to_mm.geo", Name "Actions/Set views in mm",
   Macro "GmshMergeFile", AutoCheck 0}
 m2 = {"script_convert_to_m.geo", Name "Actions/Set views in m",
   Macro "GmshMergeFile", AutoCheck 0}
 m3 = {"script_show_lines.geo", Name "Actions/Toggle line display",
   Macro "GmshMergeFile", AutoCheck 0, Highlight "Pink"}
 m4 = {"script_mesh_model.geo", Name "Actions/Mesh model",
   Macro "GmshMergeFile", AutoCheck 0}
 m5 = {"script_save_mesh.geo", Name "Actions/Save mesh",
   Macro "GmshMergeFile", AutoCheck 0}
 m6 = {"script_save_as_png.geo", Name "Actions/Save as PNG",
       Macro "GmshMergeFile", AutoCheck 0},

 m61 = {"Printf('hello I just parsed the Print command');", Name "Parse a command directly!",
        Macro "GmshParseString", AutoCheck 0},

 m62 = {"Printf('hello I just resetted the DB');", Name "Reset the DataBase!",
        Macro "GmshParseString", GmshOption "ResetDatabase", Highlight "Red", AutoCheck 0},

 m71 = {Mesh.NbTriangles, Name "Nb triangles",
   ReadOnly 1 },

 m7 = {Geometry.Curves, Name "Options/Show curves?", Choices {0,1},
   GmshOption "Geometry.Curves", AutoCheck 0, Highlight "Pink"}
 m8 = {Geometry.CurveNumbers, Name "Options/Show curve numbers?", Choices {0,1},
   GmshOption "Geometry.CurveNumbers", AutoCheck 0}
 m9 = {Geometry.CurveWidth, Name "Options/Curve Width", Min 0.1, Max 7, Step 0.5,
       GmshOption "Geometry.CurveWidth", AutoCheck 0, Highlight "LightGreen"}
 m9b = {Mesh.PointNumbers, Name "Options/Mesh point numbers", Choices{0,1},
        GmshOption "Mesh.PointNumbers", AutoCheck 0, Highlight "LightGreen"}

 n0 = {3,
   Name "Test widgets/Numbers/Number"}
 n01 = {3, Min 1, Max 4, Step 1,
   Name "Test widgets/Numbers/Number (with range and loop 1 selected)", Loop 1}
 n1 = {3, ReadOnly 1,
   Name "Test widgets/Numbers/Number (read only)"}
 n12 = {3, ReadOnlyRange 1, Min 1, Max 4, Step 1,
   Name "Test widgets/Numbers/Number (read only range)"}
 n2 = {3, Choices{1, 2, 3, 4},
   Name "Test widgets/Numbers/Number (with choices)"}
 n3 = {1, Choices{0,1},
   Name "Test widgets/Numbers/Number (with binary choice) - Show String Options?"},
 n4 = {1, Choices{0,1},
   Name "Test widgets/Numbers/Number (with binary choice) (read only)", ReadOnly 1},
 n5 = {3, Choices{1 = "One",
     2 = "Two",
     3 = "Three",
     4 = "Go!!"},
   Name "Test widgets/Numbers/Number (with enumeration)"},
 n6 = {1, Choices{1 = StrChoice(n5 == 3, "One when n5 is 3", "One"),
     2 = "Two",
     3 = "Three",
     4 = "Go!!"},
   Name "Test widgets/Numbers/Number (with enumeration) (read only range)", ReadOnlyRange 1}
 n7 = {1, Choices{1 = "One",
     2 = "Two",
     3 = "Three",
     4 = "Go!!"},
   Name "Test widgets/Numbers/Number (with enumeration) (read only)", ReadOnly 1}
];

If(n3) // test define/undefine
  DefineConstant[
    s0 = {"a",
      Name "Test widgets/Strings/String"}
    s1 = {"a", ReadOnly 1,
      Name "Test widgets/Strings/String (read only)"}
    s2 = {"a", Choices {"a","b","c"},
      Name "Test widgets/Strings/String with choices"}
    s20 = {"a, c", Choices {"a","b","c"}, MultipleSelection "101",
      Name "Test widgets/Strings/String with multiple selection"}
    s3 = {"a.txt", Choices{"a.txt","b.txt","c.txt"}, Kind "file",
      Name "Test widgets/Strings/File"}
    s4 = {"a.txt", Kind "file", Macro "GmshMergeFile",
      Name "Test widgets/Strings/Macro"}
  ];
EndIf
If(!n3)
  UndefineConstant[ "Test widgets/Strings/s0",
    "Test widgets/Strings/s1",
    "Test widgets/Strings/s2",
    "Test widgets/Strings/s20",
    "Test widgets/Strings/s3",
    "Test widgets/Strings/s4"];
EndIf

pp1 = DefineNumber[0.1, Name "Inline definitions/number"];
ss1 = DefineString["my string", Name "Inline definitions/string"];

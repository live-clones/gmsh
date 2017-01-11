aa[] = {10,2,3};

bb1[] = List[aa];
bb2[] = List[aa[]];
bb3[] = List[{1,2,4}];

Printf("", bb1[]);
Printf("", bb2[]);
Printf("", bb3[]);

DefineConstant[
  ll[] = {bb1[], Name "my list"}
];
Printf("my list = ", ll[]);

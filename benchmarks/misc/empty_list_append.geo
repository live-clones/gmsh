// this is optional: you can actually append to a non-existent list:
// it will create a new list
aa[] = {};           Printf("aa size = %g", #aa[]);
aa[] += 0;           Printf("aa size = %g", #aa[]);
aa[] += {1,2,3};     Printf("aa size = %g", #aa[]);

// this does not append: it adds the items in aa[] to the items
// indexed by aa[]!
aa[{aa[]}] += aa[];  Printf("aa size = %g", #aa[]);

// this appends aa[] to itself
aa[] += aa[];        Printf("aa size = %g", #aa[]);


For i In {1 : #aa[]}
  Printf("aa[%g] = %g", i-1, aa[i-1]);
EndFor

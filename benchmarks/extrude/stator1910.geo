Geometry.AutoCoherence=0;

s=1;
lc =0.004;
mm=1.e-3;

R = 40.*mm;
r = 9.5*mm;

nbr_tooth = 72;
nbr_gap = 12;
NodLin = 24;   
teta_vide = 1/40;
teta_tooth = 5*Pi/180-teta_vide;
teta_gap = teta_vide/2;

insc=150;

Point(1) = {0,0,0,lc}; Point(2) = {r,0,0,lc/1.5}; Point(3) = {12.5e-3,0,0,lc}; 
Point(4) = {17.5e-3,0,-1e-3,lc}; Point(5) = {35e-3,0,-1e-3,lc}; Point(6) = {37e-3,0,-4e-3,lc/4}; 
Point(7) = {38e-3,0,-4e-3,lc/4}; Point(8) = {12.5e-3,0,1e-3,lc}; Point(9) = {17.5e-3,0,1e-3,lc};
Point(10) = {35e-3,0,1e-3,lc}; Point(11) = {R,0,1e-3,lc}; Point(12) = {r,0,4e-3,lc/1.5};
Point(13) = {12.5e-3,0,4e-3,lc}; Point(14) = {12.5e-3,0,3e-3,lc}; Point(15) = {17.5e-3,0,3e-3,lc};
Point(16) = {35e-3,0,3e-3,lc}; Point(17) = {R,0,3e-3,lc}; Point(18) = {17.5e-3,0,5e-3,lc};
Point(19) = {35e-3,0,5e-3,lc}; Point(20) = {37e-3,0,8e-3,lc/4}; Point(21) = {38e-3,0,8e-3,lc/4};

Line(1) = {2,3}; Line(2) = {3,8}; Line(3) = {8,9}; Line(4) = {9,10}; Line(5) = {10,11};
Line(6) = {11,17}; Line(7) = {17,16}; Line(8) = {16,15}; Line(9) = {15,14}; Line(10) = {14,13};
Line(11) = {13,12}; Line(12) = {12,2}; Line(13) = {10,6}; Line(14) = {6,7}; Line(15) = {7,11};
Line(16) = {16,20}; Line(17) = {20,21}; Line(18) = {21,17}; Line(19) = {9,4}; Line(20) = {4,5};
Line(21) = {5,10}; Line(22) = {15,18}; Line(23) = {18,19}; Line(24) = {19,16};

Line Loop(1) = {9,10,11,12,1,2,3,4,5,6,7,8};
Plane Surface(2) = {1};
Line Loop(3) = {-15,-14,-13,5};
Plane Surface(4) = {3};
Line Loop(5) = {7,16,17,18};
Plane Surface(6) = {5};
Line Loop(7) = {-21,-20,-19,4};
Plane Surface(8) = {7};
Line Loop(9) = {8,22,23,24};
Plane Surface(10) = {9};

V_corp      = 1e6;
V_dent      = 2e6;
V_PZT_lower = 3e6;
V_PZT_upper = 4e6;
N_          = 100;

V_100dent   = 123456;


// Sector 1 ______________________________________________________________


i_sect = 1;

Extrude Surface {2, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_corp, 1};                           // corp   
  };
Extrude Surface {4, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                        // pas de dent
  };
Extrude Surface {6, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                        // pas de dent
  };
Extrude Surface {8, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1 ,V_PZT_lower + N_*(i_sect-1), 1 };     // PZT_lower
  };
Extrude Surface {10, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1 };     // PZT_upper 
  };

Extrude Surface {86, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1 ,V_corp, 1 };                                // corp
  };
Extrude Surface {108, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1 };                             // pas de dent
  };
Extrude Surface {130, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1 };                             // pas de dent
  };
Extrude Surface {152, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1};            // PZT_lower
  };
Extrude Surface {174, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1};            //  PZT_upper 
  };

L_sec=(Pi/12-teta_vide)*R; 
l_vide=teta_vide*R/L_sec;
l_dent=teta_tooth*R/L_sec;

For i In {0:4}
  ListVol1[i]=V_corp ;   // corp
  ListVol2[i]=V_dent+i; //  dents ou vides : V_dent<-dent, V_dent+1<-vide ...
  ListVol3[i]=V_PZT_lower + N_*(i_sect-1);   // PZT_lower        
  ListVol4[i]=V_PZT_upper + N_*(i_sect-1);   // PZT_upper
  ListExt[i]=1;
EndFor

ListDiv[0]=l_dent;
For i In {1:3}
  If ( !Modulo(i,2) )
    ListDiv[i]=l_dent+ListDiv[i-1];
  EndIf
  If ( Modulo(i,2) )
    ListDiv[i]=l_vide+ListDiv[i-1];
  EndIf
EndFor
ListDiv[4]=1;

Extrude Surface {86+insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol1[{0:4}], ListDiv[{0:4}] }; 
  };
Extrude Surface {108+insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol2[{0:4}], ListDiv[{0:4}] }; 
  };
Extrude Surface {130+insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol2[{0:4}], ListDiv[{0:4}] };
  };
Extrude Surface {152+insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol3[{0:4}], ListDiv[{0:4}] };
  };
Extrude Surface {174+insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol4[{0:4}], ListDiv[{0:4}] };
  };

Extrude Surface {86+2*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1 ,V_corp, 1 };                                // corp
  };
Extrude Surface {108+2*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1 };                             // pas de dent
  };
Extrude Surface {130+2*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1};                              // pas de dent
  };
Extrude Surface {152+2*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1};                            // PZT_lower
  };
Extrude Surface {174+2*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1};                            //  PZT_upper 
  };

Extrude Surface {86+3*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_corp, 1};                          // corp   
  };
Extrude Surface {108+3*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                       // pas de dent
  };
Extrude Surface {130+3*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                       // pas de dent
  };
Extrude Surface {152+3*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1 };    // PZT_lower
  };
Extrude Surface {174+3*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1 };    // PZT_upper 
  };


// Sector 2..n ______________________________________________________________

For i_sect In {2:NodLin}

Extrude Surface {86+((i_sect-2)*5+4)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_corp, 1};                          // corp   
  };
Extrude Surface {108+((i_sect-2)*5+4)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                       // pas de dent
  };
Extrude Surface {130+((i_sect-2)*5+4)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                       // pas de dent
  };
Extrude Surface {152+((i_sect-2)*5+4)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1 };   // PZT_lower
  };
Extrude Surface {174+((i_sect-2)*5+4)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1 };   // PZT_upper 
  };


Extrude Surface {86+((i_sect-2)*5+5)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_corp, 1 };                                // corp
  };
Extrude Surface {108+((i_sect-2)*5+5)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1 };                             // pas de dent
  };
Extrude Surface {130+((i_sect-2)*5+5)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1};                              // pas de dent
  };
Extrude Surface {152+((i_sect-2)*5+5)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1};            // PZT_lower
  };
Extrude Surface {174+((i_sect-2)*5+5)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1};            //  PZT_upper 
  };

For i In {0:4}
  ListVol4[i] = V_PZT_lower + N_*(i_sect-1);   // PZT_lower
  ListVol5[i] = V_PZT_upper + N_*(i_sect-1);   // PZT_upper
EndFor

Extrude Surface {86+((i_sect-2)*5+6)*insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol1[{0:4}], ListDiv[{0:4}] }; 
  };
Extrude Surface {108+((i_sect-2)*5+6)*insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol2[{0:4}], ListDiv[{0:4}] }; 
  };
Extrude Surface {130+((i_sect-2)*5+6)*insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol2[{0:4}], ListDiv[{0:4}] };
  };
Extrude Surface {152+((i_sect-2)*5+6)*insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol3[{0:4}], ListDiv[{0:4}] };
  };
Extrude Surface {174+((i_sect-2)*5+6)*insc, {0,0,1}, {0,0,0}, Pi/12-teta_vide}{
  Recombine ; Layers {  ListExt[{0:4}] , ListVol4[{0:4}], ListDiv[{0:4}] };
  };

Extrude Surface {86+((i_sect-2)*5+7)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_corp, 1 };                             // corp
  };
Extrude Surface {108+((i_sect-2)*5+7)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1 };                             // pas de dent
  };
Extrude Surface {130+((i_sect-2)*5+7)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_100dent, 1};                              // pas de dent
  };
Extrude Surface {152+((i_sect-2)*5+7)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1};                              // PZT_lower
  };
Extrude Surface {174+((i_sect-2)*5+7)*insc, {0,0,1}, {0,0,0}, teta_vide/2 -teta_gap/2 }{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1};                          //  PZT_upper 
  };

Extrude Surface {86+((i_sect-2)*5+8)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_corp, 1};                 // corp   
  };
Extrude Surface {108+((i_sect-2)*5+8)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                 // pas de dent
  };
Extrude Surface {130+((i_sect-2)*5+8)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_100dent, 1};                 // pas de dent
  };
Extrude Surface {152+((i_sect-2)*5+8)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_lower + N_*(i_sect-1), 1 };                // PZT_lower
  };
Extrude Surface {174+((i_sect-2)*5+8)*insc, {0,0,1}, {0,0,0}, teta_gap/2}{
  Recombine ; Layers { 1, V_PZT_upper + N_*(i_sect-1), 1 };                // PZT_upper 
  };

EndFor 

Coherence;


// Extruding finished !!! __________________________________________________________________


PZTplus  = 1000;
PZTminus = 2000;
Corp = 3000; 

ElectrodeUpper = 1001;
ElectrodeLower = 1002;
Masse = 1003;

Inner_Cylinder = 1009;
Point99 =  1010;
Point101 = 1011;

For i In {0:2}
   ListDent[i]=V_dent+i*2;
EndFor
Physical Volume(Corp) = {V_corp, ListDent[{0:2}]};


i_plus[{1:12}]={1,2,  5,6,  9,10,    13,14,    17,18,    21,22}; //  (++)(--)(++)(--)(++)(--)(++)(--)(++)(--)(++)(--)
i_minus[{1:12}]={  3,4,  7,8,   11,12,    15,16,    19,20,    23,24};   
For i In {1:12}  
      ListPZT_upper_plus[i] = V_PZT_upper + N_*(i_plus[i]-1); 
      ListPZT_upper_minus[i] = V_PZT_upper + N_*(i_minus[i]-1);
EndFor

i_plus[{1:12}]= {1,  4,5,  8,9,    12,13,    16,17,    20,21,   24};// +)(--)(++)(--)(++)(--)(++)(--)(++)(--)(++)(--)(+
i_minus[{1:12}] = { 2,3,  6,7,  10,11,    14,15,    18,19,    22,23};  
For i In {1:12}  
      ListPZT_lower_plus[i] = V_PZT_lower + N_*(i_plus[i]-1); 
      ListPZT_lower_minus[i] = V_PZT_lower + N_*(i_minus[i]-1);
EndFor

Physical Volume(PZTplus)  = {  ListPZT_lower_plus[{1:12}],  ListPZT_upper_plus[{1:12}] } ; 
Physical Volume(PZTminus) = {  ListPZT_lower_minus[{1:12}], ListPZT_upper_minus[{1:12}] } ;


For i In {1:NodLin*5}  // taking into account the gaps,...
  List_Electrode_Upper[i] = 169+(i-1)*insc;
  List_Electrode_Lower[i] = 143+(i-1)*insc;
EndFor

i_upper_plus[{1:48}] ={2:9,    22:29,    42:49,    62:69,    82:89,    102:109};
i_upper_minus[{1:48}]={   12:19,    32:39,    52:59,    72:79,    92:99,     112:119};
i_lower_plus[{1:48}]={1,2,3,4,   17:24,    37:44,    57:64,    77:84,    97:104,     117,118,119,120};
i_lower_minus[{1:48}]={      7:14,    27:34,    47:54,    67:74,    87:94,     107:114};

Physical Surface (ElectrodeUpper) = { List_Electrode_Upper[{i_upper_plus[{1:48}]}], List_Electrode_Upper[{i_upper_minus[{1:48}]}] } ;
Physical Surface (ElectrodeLower) = { List_Electrode_Lower[{i_lower_plus[{1:48}]}], List_Electrode_Lower[{i_lower_minus[{1:48}]}] } ;

For i In {1:NodLin*5}  // taking into account the gaps,...
  List_Emasse_upper[i]=85+(i-1)*insc;
  List_Emasse_lower[i]=69+(i-1)*insc;
EndFor
Physical Surface (Masse)  = { List_Emasse_upper[{1:120}], List_Emasse_lower[{1:120}] } ;

For i In {1:NodLin*5}
  List_IC[i]=53+(i-1)*insc;
EndFor
Physical Surface (Inner_Cylinder)  =  { List_IC[{1:120}] };

//Physical Point (Point99) = {};  







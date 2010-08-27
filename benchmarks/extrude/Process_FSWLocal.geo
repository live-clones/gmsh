// ===========================================================================//
//                                                                            //
//  Parametrised Model for 3D Thermo-Fluid Modelling of FSW                   //
//                                                                            //
//  Description:                                                              //
//  ...                                                                       //
//                                                                            //
// ===========================================================================//
// -- GMSH parameters ----------------------------------------------------------
Geometry.ScalingFactor = 1.0;
Mesh.Smoothing = 1;
Mesh.CharacteristicLengthExtendFromBoundary = 1;
Mesh.MshFileVersion = 1;
Mesh.ScalingFactor = 1.0;
// ---------------------------------------------------------------------------//
//   Model parameters                                                         //
// ---------------------------------------------------------------------------//
tool_diameter               = 0.024;
tool_length1                = 0.03;
tool_length2                = 0.005;
shoulder_diameter           = 0.02;
probe_thread_inner_diameter_top = 0.008;
probe_thread_outer_diameter_top = 0.01;
probe_thread_inner_diameter_bottom = 0.008;
probe_thread_outer_diameter_bottom = 0.01;
probe_length                = 0.005;
shoulder_scroll_depth       = 0.003;
layer_thickness1            = shoulder_scroll_depth;
layer_thickness2            = 0.001;
layer_thickness3            = 0.0005;
layer_thickness4            = 0.0005;
layer_thickness5            = 0.0008;
workpiece_thickness         = 0.006;
workpiece_diameter          = 0.06;
refined_mesh_extension      = 0.005;
refined_mesh_extension2     = 0.01;
contact_layer_thickness     = 0.0001;
backplate_thickness         = 0.0189;
backplate_refinement1       = 0.001;
backplate_refinement2       = 0.005;
tool_temperature1           = 0.15 * (0.03 + 0.005 );
tool_temperature2           = 0.5 * (0.03 + 0.005 );
//
tool_radius               = tool_diameter/2.0; 
shoulder_radius           = shoulder_diameter/2.0;
probe_thread_inner_radius_top = probe_thread_inner_diameter_top/2.0;
probe_thread_outer_radius_top = probe_thread_outer_diameter_top/2.0;
probe_thread_inner_radius_bottom = probe_thread_inner_diameter_bottom/2.0;
probe_thread_outer_radius_bottom = probe_thread_outer_diameter_bottom/2.0;
workpiece_radius          = workpiece_diameter/2.0;
//
// ---------------------------------------------------------------------------//
//   Offset factors                                                           //
// ---------------------------------------------------------------------------//
offset_factor1 = 0.2;
offset1        = offset_factor1 * layer_thickness2;
offset_factor2 = 0.6;
offset2        = offset_factor2 * layer_thickness3;
offset_factor3 = 0.2;
offset3        = offset_factor3 * layer_thickness3;
offset_factor4 = 0.2;
offset4        = offset_factor4 * layer_thickness4;
offset_on_axis_factor = 0.2;
offset_on_axis = probe_thread_inner_radius_top * offset_on_axis_factor;
//
// ---------------------------------------------------------------------------//
//   Mesh Parameters                                                          //
// ---------------------------------------------------------------------------//
// -- Number of elements along edges -------------------------------------------
number_of_elements_through_thickness_of_boundary_layer   = 10;
number_of_elements_through_thickness_of_transition_layer = 3;
number_of_elements_along_shoulder_radius                 = 16;
number_of_elements_along_probe                           = 16;
number_of_elements_along_probe_radius                    = 10;
number_of_elements_along_small_blocks                    = 4;
number_of_elements_through_workpiece_thickness           = 15;
number_of_elements_along_workpiece_width                 = 10;
number_of_elements_through_contact_thickness             = 1;
number_of_elements_through_backplate_thickness           = 10;
number_of_elements_along_backplate_width                 = 25;
number_of_elements_along_shoulder_shaft                  = 40;
number_of_elements_along_tool_top_shaft                  = 15;
number_of_elements_along_tool_top_radius                 = 15;
number_of_elements_along_top_refinement_zone             = 25;
number_of_elements_between_probe_bottom_bl_and_wp_bottom = 6;
number_of_elements_along_central_cylinder_radius         = 3;
number_of_elements_along_one_third_circumference         = 12;
number_of_elements_along_backplate_edges                 = 20;
number_of_elements_along_backplate_refinement1           = 5;
number_of_elements_along_backplate_refinement2           = 10;
number_of_elements_through_outer_workpiece_thickness     = 5;
number_of_elements_along_lower_tool_section              = 5;
number_of_elements_along_middle_tool_radius              = 5;
number_of_elements_along_middle_tool_section             = 5;
number_of_elements_along_upper_tool_section              = 8;
//
// -- convert to number of nodes -----------------------------------------------
bl1 = number_of_elements_through_thickness_of_boundary_layer + 1;
bl2 = number_of_elements_through_thickness_of_transition_layer + 1;
n1  = number_of_elements_along_shoulder_radius + 1;
n1b = n1 - number_of_elements_along_small_blocks;
n2  = number_of_elements_along_probe + 1;
n2b = n2 - number_of_elements_along_small_blocks;
n3  = number_of_elements_along_probe_radius + 1;
n3b = n3 - number_of_elements_along_small_blocks;
n4  = number_of_elements_along_small_blocks + 1;
n5  = number_of_elements_through_workpiece_thickness + 1;
n6  = number_of_elements_along_workpiece_width + 1;
n7  = number_of_elements_through_contact_thickness + 1;
n8  = number_of_elements_through_backplate_thickness + 1;
n9  = number_of_elements_along_backplate_width + 1;
n10 = number_of_elements_along_shoulder_shaft + 1;
n11 = number_of_elements_along_tool_top_shaft + 1;
n12 = n10 + n11 + 2;
n13 = number_of_elements_along_tool_top_radius + 1;
n14 = n9 - n6 + 1  ;
n15 = number_of_elements_along_top_refinement_zone + 1;
n16 = number_of_elements_between_probe_bottom_bl_and_wp_bottom + 1;
n17 = number_of_elements_along_central_cylinder_radius + 1;
n18 = number_of_elements_along_one_third_circumference;
n19 = number_of_elements_along_backplate_edges + 1;
n20 = number_of_elements_along_backplate_refinement1 + 1;
n21 = number_of_elements_along_backplate_refinement2 + 1;
n22 = number_of_elements_through_outer_workpiece_thickness + 1;
n23 = number_of_elements_along_lower_tool_section + 1;
n24 = number_of_elements_along_middle_tool_radius + 1;
n25 = number_of_elements_along_middle_tool_section + 1;
n26 = number_of_elements_along_upper_tool_section + 1;
//
// -- Bias factors -------------------------------------------------------------
no_bias = 1.0;
bl1_bias = 0.8;
bl_trans_bias = 0.9;
bl2_bias = 0.8;
bp_cl_bias = 0.8;
bp_h_bias = 0.95;
bp_v_bias = 0.7;
wp_h_bias = 0.6;
tool_v_bias = 0.95;
tool_top_v_bias = tool_v_bias;
tool_axis_v_bias = tool_v_bias;

// -- Other --------------------------------------------------------------------
h = 0.00001;
//
// ---------------------------------------------------------------------------//
//   Coordinates                                                              //
// ---------------------------------------------------------------------------//
// -- X ------------------------------------------------------------------------
x0  = 0.0;
xa =  x0 + offset_on_axis;
x1  = x0 + probe_thread_inner_radius_top;
x2  = x0 + probe_thread_outer_radius_top;
x3  = x1 + layer_thickness3;
x4  = x0 + probe_thread_inner_radius_bottom - layer_thickness3;
x5  = x0 + shoulder_radius;
x6  = tool_radius;
x7  = workpiece_radius;
x8  = x5 + layer_thickness1;
x9  = x5 + layer_thickness2;
x10 = x5 - layer_thickness2;
x11 = shoulder_radius + refined_mesh_extension;
x12 = probe_thread_outer_radius_top + refined_mesh_extension;
x13 = x3 + offset2;
x14 = x9 - offset1;
x15 = x3 - offset3;
x16 = x0 + probe_thread_inner_radius_bottom;
x17 = x0 + probe_thread_outer_radius_bottom;
// - intermediate -
d1 = probe_thread_inner_radius_top;
d3 = probe_thread_inner_radius_bottom;
d2 = probe_thread_outer_radius_top;
d4 = probe_thread_outer_radius_bottom;
p  = probe_length;
//
//
// -- Y ------------------------------------------------------------------------
y0  = 0.0;
y1  = y0  - workpiece_thickness;
y2  = y0  - probe_length;
y3  = y1  - contact_layer_thickness;
y4  = y3  - backplate_thickness;
y5  = y0  + tool_length1;
y6  = y5  + tool_length2;
y7  = y0  - layer_thickness2;
y8  = y0  - layer_thickness1;
y9  = y2  + layer_thickness4;
y10 = y2  - layer_thickness4;
y11 = y2  - layer_thickness5;
y12 = y7  + offset1;
y13 = y10 + offset4;
y14 = y3  - backplate_refinement1; 
y15 = y3  - backplate_refinement2; 
y16 = y0  + tool_temperature1;
y17 = y0  + tool_temperature2;
//
x18 = d3*(-y8)/p+d1*(p-(-y8))/p;  
x19 = d3*(-y9)/p+d1*(p-(-y9))/p;  
x20 = d4*(-y7)/p+d2*(p-(-y7))/p;  
x21 = d4*(-y8)/p+d2*(p-(-y8))/p;  
x22 = x18 + layer_thickness3;
x23 = x19 + layer_thickness3;  
x24 = x16 + layer_thickness3; 
x25 = d3*(-y7)/p+d1*(p-(-y7))/p + layer_thickness3 + offset2;  
x26 = d3*(-y10)/p+d1*(p-(-y10))/p; // p38
x27 = d3*(-y13)/p+d1*(p-(-y13))/p + layer_thickness3 - offset3; // p37
x28 = d3*(-y11)/p+d1*(p-(-y11))/p; // p22
x29 = shoulder_radius + refined_mesh_extension2;
//
// -- Z ------------------------------------------------------------------------
z0  = 0.0;
//
// ---------------------------------------------------------------------------//
//   Points                                                                   //
// ---------------------------------------------------------------------------//
Point(1)  = { xa,  y6,  z0, h };
Point(2)  = { x6,  y6,  z0, h };
Point(3)  = { x6,  y5,  z0, h };
Point(4)  = { x5,  y5,  z0, h };
Point(5)  = { x5,  y0,  z0, h };
Point(6)  = { x1,  y0,  z0, h };
Point(7)  = { x16, y2,  z0, h };
Point(8)  = { xa,  y2,  z0, h };
Point(9)  = { x7,  y0,  z0, h };
Point(10) = { x7,  y1,  z0, h };
Point(11) = { xa,  y1,  z0, h };
Point(12) = { x7,  y3,  z0, h };
Point(13) = { xa,  y3,  z0, h };
Point(14) = { x7,  y4,  z0, h };
Point(15) = { xa,  y4,  z0, h };
Point(16) = { x5,  y8,  z0, h };
Point(17) = { x8,  y0,  z0, h };
Point(18) = { x2,  y0,  z0, h };
Point(19) = { x21, y8,  z0, h };
Point(20) = { x18, y8,  z0, h };
Point(21) = { x17, y2,  z0, h };
Point(22) = { x28, y11, z0, h };
Point(23) = { xa,  y11, z0, h };
Point(24) = { x11, y0,  z0, h };
Point(25) = { x12, y1,  z0, h };
Point(26) = { x9,  y0,  z0, h };
Point(27) = { x14, y12, z0, h };
Point(28) = { x5,  y7,  z0, h };
Point(29) = { x10, y7,  z0, h };
Point(30) = { x10, y0,  z0, h };
Point(31) = { x20, y7,  z0, h };
Point(32) = { x25, y7,  z0, h };
Point(33) = { x22, y8,  z0, h };
Point(34) = { x24, y2,  z0, h };
Point(35) = { x23, y9,  z0, h };
Point(36) = { x19, y9,  z0, h };
Point(37) = { x27, y13, z0, h };
Point(38) = { x26, y10, z0, h };
Point(39) = { x4,  y10, z0, h };
Point(40) = { x4,  y2,  z0, h };
Point(41) = { xa,  y10, z0, h };

Point(42)  = { x0,  y6,  z0, h };
Point(43)  = { x0,  y2,  z0, h };
Point(44)  = { x0,  y1,  z0, h };
Point(45)  = { x0,  y3,  z0, h };
Point(46)  = { x0,  y4,  z0, h };
Point(47)  = { x0,  y11, z0, h };
Point(48)  = { x0,  y10, z0, h };
//
// ---------------------------------------------------------------------------//
//   Lines                                                                    //
// ---------------------------------------------------------------------------//
Line(1)     = {  1,  2 };
Line(2)     = {  2,  3 };
Line(3)     = {  3,  4 };
Line(5)     = {  5, 26 };
Line(6)     = { 26, 17 };
Line(7)     = { 17, 24 };
Line(9)     = {  9, 10 };
Line(10)    = { 10, 12 };
Line(14)    = { 13, 11 };
Line(15)    = { 11, 25 };
Line(18)    = {  8, 41 };
Line(19)    = { 41, 23 };
Line(20)    = { 23, 11 };
Line(21)    = { 26, 27 };
Line(22)    = { 27, 28 };
Line(23)    = { 28,  5 };
Line(24)    = { 28, 16 };
Line(25)    = { 28, 29 };
Line(26)    = {  5, 30 };
Line(27)    = { 30, 18 };
Line(28)    = { 18,  6 };
Line(29)    = {  6, 20 };
Line(30)    = { 20, 36 };
Line(31)    = { 36,  7 };
Line(32)    = {  7, 40 };
Line(33)    = { 40,  8 };
Line(34)    = { 39, 41 };
Line(35)    = { 39, 38 };
Line(36)    = {  7, 38 };
Line(37)    = { 38, 22 };
Line(38)    = { 29, 30 };
Line(39)    = { 16, 19 };
Line(40)    = { 19, 31 };
Line(41)    = { 31, 18 };
Line(42)    = { 31, 32 };
Line(43)    = { 32, 33 };
Line(44)    = { 33, 19 };
Line(45)    = { 33, 20 };
Line(46)    = { 33, 35 };
Line(47)    = { 35, 36 };
Line(48)    = {  7, 34 };
Line(49)    = { 34, 35 };
Line(50)    = { 34, 37 };
Line(51)    = { 37, 38 };
Line(52)    = { 19, 21 };
Line(53)    = { 22, 23 };
Line(54)    = { 24, 25 };
Circle(55)  = { 17,  5, 16 };
Ellipse(56) = { 21,  40, 34, 22 };
Line(57)    = { 29, 31 };
Line(59)    = { 40, 39 };
Line(60)    = { 34, 21 };
//
Line(101) = {1,42};
Line(103) = {43,48};
Line(104) = {48,47};
Line(105) = {47,44};
Line(106) = {44,45};
Line(108) = {46,15};
Line(109) = {45,13};
Line(110) = {44,11};
Line(111) = {47,23};
Line(112) = {48,41};
Line(113) = {43,8};
//
// ---------------------------------------------------------------------------//
//   Surfaces                                                                 //
// ---------------------------------------------------------------------------//
Line Loop(63)      = { 7, 54, -15, -20, -53, -56, -52, -39, -55 };
Plane Surface(64)  = { 63 };
Line Loop(71)      = { 53, -19, -34, 35, 37 };
Plane Surface(72)  = { 71 };
Line Loop(73)      = { 34, -18, -33, 59 };
Plane Surface(74)  = { 73 };
Line Loop(75)      = { 35, -36, 32, 59 };
Plane Surface(76)  = { 75 };
Line Loop(77)      = { 37, -56, -60, 50, 51 };
Plane Surface(78)  = { 77 };
Line Loop(79)      = { 50, 51, -36, 48 };
Plane Surface(80)  = { 79 };
Line Loop(81)      = { 49, 47, 31, 48 };
Plane Surface(82)  = { 81 };
Line Loop(83)      = { 60, -52, -44, 46, -49 };
Plane Surface(84)  = { 83 };
Line Loop(85)      = { 46, 47, -30, -45 };
Plane Surface(86)  = { 85 };
Line Loop(87)      = { 45, -29, -28, -41, 42, 43 };
Plane Surface(88)  = { 87 };
Line Loop(89)      = { 44, 40, 42, 43 };
Plane Surface(90)  = { 89 };
Line Loop(91)      = { 39, 40, -57, -25, 24 };
Plane Surface(92)  = { 91 };
Line Loop(93)      = { 57, 41, -27, -38 };
Plane Surface(94)  = { 93 };
Line Loop(95)      = { 25, 38, -26, -23 };
Plane Surface(96)  = { 95 };
Line Loop(97)      = { 22, 23, 5, 21 };
Plane Surface(98)  = { 97 };
Line Loop(99)      = { 55, -24, -22, -21, 6 };
Plane Surface(100) = { 99 };
//
Line Loop(116) = {113,18,-112,-103};
Plane Surface(117) = {116};
Line Loop(118) = {112,19,-111,-104};
Plane Surface(119) = {118};
Line Loop(120) = {111,20,-110,-105};
Plane Surface(121) = {120};
Line Loop(122) = {110,-14,-109,-106};
Plane Surface(123) = {122};
// -- Modified Contact and Backing plate ----------------
Point(49) = { x29, y0,  z0, h};
Point(50) = { x29, y1,  z0, h};
Point(51) = { x29, y3,  z0, h};
Point(52) = { x12, y3,  z0, h};
Point(53) = { x0,  y14, z0, h};
Point(54) = { xa,  y14, z0, h};
Point(55) = { x12, y14, z0, h};
Point(56) = { x29, y15, z0, h};
Point(57) = { x0,  y15, z0, h};
Point(58) = { xa,  y15, z0, h};
Line(125) = {24, 49};
Line(126) = {49, 9};
Line(127) = {45, 53};
Line(128) = {53, 57};
Line(129) = {13, 54};
Line(130) = {54, 58};
Line(131) = {13, 52};
Line(132) = {52, 51};
Line(133) = {25, 50};
Line(134) = {50, 49};
Line(135) = {50, 51};
Line(136) = {25, 52};
Line(137) = {52, 55};
Line(138) = {55, 54};
Line(139) = {54, 53};
Line(140) = {55, 56};
Line(141) = {51, 56};
Line(142) = {56, 58};
Line(143) = {58, 57};
Line(144) = {57, 46};
Line(145) = {58, 15};
Line(146) = {56, 14};
Line(147) = {14, 15};
Line(148) = {14, 12};
Line(149) = {10, 50};
Line(150) = {51, 12};
Line Loop(151) = {15, 136, -131, 14};
Plane Surface(152) = {151};
Line Loop(153) = {136, 132, -135, -133};
Plane Surface(154) = {153};
Line Loop(155) = {133, 134, -125, 54};
Plane Surface(156) = {155};
Line Loop(157) = {131, 137, 138, -129};
Plane Surface(158) = {157};
Line Loop(159) = {109, 129, 139, -127};
Plane Surface(160) = {159};
Line Loop(161) = {128, -143, -130, 139};
Plane Surface(162) = {161};
Line Loop(163) = {142, -130, -138, 140};
Plane Surface(164) = {163};
Line Loop(165) = {140, -141, -132, 137};
Plane Surface(166) = {165};
Line Loop(167) = {135, 150, -10, 149};
Plane Surface(168) = {167};
Line Loop(169) = {143, 144, 108, -145};
Plane Surface(170) = {169};
Line Loop(173) = {146, 148, -150, 141};
Plane Surface(174) = {173};
Line Loop(175) = {126, 9, 149, 134};
Plane Surface(176) = {175};
Line Loop(177) = {147, -145, -142, 146};
Plane Surface(178) = {177};
// -- modified TOOL --------------------------
Point(60) = {x0, y16, z0, h};
Point(61) = {xa, y16, z0, h};
Point(62) = {x5, y16, z0, h};
Point(63) = {x5, y17, z0, h};
Point(64) = {xa, y17, z0, h};
Point(65) = {x0, y17, z0, h};
Line(179) = {43, 60};
Line(180) = {8, 61};
Line(181) = {5, 62};
Line(182) = {62, 63};
Line(183) = {61, 64};
Line(184) = {60, 65};
Line(185) = {63, 4};
Line(186) = {64, 1};
Line(187) = {65, 42};
Line(188) = {65, 64};
Line(189) = {64, 63};
Line(190) = {60, 61};
Line(191) = {61, 62};
Line Loop(192) = {179, 190, -180, -113};
Plane Surface(193) = {192};
Line Loop(194) = {180, 191, -181, 26, 27, 28, 29, 30, 31, 32, 33};
Plane Surface(195) = {194};
Line Loop(196) = {190, 183, -188, -184};
Plane Surface(197) = {196};
Line Loop(198) = {189, -182, -191, 183};
Plane Surface(199) = {198};
Line Loop(200) = {189, 185, -3, -2, -1, -186};
Plane Surface(201) = {200};
Line Loop(202) = {188, 186, 101, -187};
Plane Surface(203) = {202};
// ---------------------------------------------------------------------------//
//   Mapped Mesh Definition                                                   //
// ---------------------------------------------------------------------------//
// -- across boundary layer ----------------------------------------------------
Transfinite Line { -5, 23, 38, 41, 45, 47, -48, -36, -59, -18 } = bl1 Using Progression bl1_bias;
Transfinite Line {-21, 22 }  = bl1       Using Progression bl1_bias;
Transfinite Line { 55 }      = 2*bl1 - 1 Using Progression no_bias;
Transfinite Line { 51,-50 }  = bl1       Using Progression bl1_bias;
Transfinite Line { 56 }      = 2*bl1 - 1 Using Progression no_bias;
// -- across transition layer --------------------------------------------------
Transfinite Line { -6, -24, 40, -44, -60, -37, -19 } = bl2 Using Progression bl2_bias; 
Transfinite Line { 42, 43 }  = bl2 Using Progression no_bias;
Transfinite Line { 29, 28 }  = bl2 Using Progression no_bias;
Transfinite Line { 42, 43 }  = bl2 Using Progression no_bias;
// -- probe --------------------------------------------------------------------
Transfinite Line { 52 }      = n2  Using Progression no_bias;
Transfinite Line { 30, 46 }  = n2b Using Progression no_bias;
Transfinite Line { 31, 49 }  = n4  Using Progression no_bias;
// -- shoulder -----------------------------------------------------------------
Transfinite Line {-39 }      = n1  Using Progression bl_trans_bias;
Transfinite Line { 27, 57 }  = n1b Using Progression no_bias;
Transfinite Line {-25,-26 }  = n4  Using Progression bl1_bias;
// -- probe bottom -------------------------------------------------------------
Transfinite Line { 53 }      = n3  Using Progression no_bias;
Transfinite Line { 34, 33 }  = n3b Using Progression no_bias;
Transfinite Line {-32, 35 }  = n4  Using Progression bl1_bias;
// -- wp -----------------------------------------------------------------------
Transfinite Line {  54 }     = n5  Using Progression no_bias;
// -- contact ------------------------------------------------------------------
Transfinite Line { 10, 14 }  = n7  Using Progression no_bias;
// -- bp -----------------------------------------------------------------------

// -- tool ---------------------------------------------------------------------
Transfinite Line {  2 }      = n11 Using Progression tool_top_v_bias;
Transfinite Line { 1, 3 }    = n13 Using Progression no_bias;
// -- refinement zone ----------------------------------------------------------
Transfinite Line { 15, 131, 138, 142 } = n15 Using Progression no_bias;
Transfinite Line {  7 }      = n15 Using Progression no_bias;
// -- remaining elements under tool --------------------------------------------
Transfinite Line { 20 }      = n16 Using Progression no_bias;
//
Transfinite Line { 101, 113, 112, 111, 110, 109, 108, 139, 143 } = n17 Using Progression no_bias;
Transfinite Line { 106, 136, 135 }     = n7  Using Progression no_bias;
Transfinite Line { 105 }     = n16 Using Progression no_bias;
Transfinite Line {-104 }     = bl2 Using Progression bl2_bias;
Transfinite Line {-103 }     = bl1 Using Progression bl1_bias;
//
Transfinite Line {127, 129, 137, 141} = n20 Using Progression no_bias;
Transfinite Line {128, 130, 140, 132, 133, 125 } = n21 Using Progression no_bias;
Transfinite Line {144, 145}  = n19 Using Progression no_bias;
Transfinite Line {-146, 147, 148} = n19 Using Progression bp_v_bias;
Transfinite Line {134, 9}    = n22 Using Progression no_bias;
Transfinite Line {-126, 149, -150} = n19 Using Progression bp_h_bias;
//
Transfinite Line {190, 188}      = n17 Using Progression no_bias;
Transfinite Line {180, 179, 181} = n23 Using Progression no_bias;
Transfinite Line {182, 183, 184} = n25 Using Progression no_bias;
Transfinite Line {191, 189}      = n24 Using Progression no_bias;
Transfinite Line {185, 186, 187} = n26 Using Progression no_bias;
//
// -- Mapped Mesh Surfaces -----------------------------------------------------
Transfinite Surface {  74 }  = { 39, 40,  8, 41 };
Transfinite Surface {  72 }  = { 22, 38, 41, 23 };
Transfinite Surface {  76 }  = { 38,  7, 40, 39 };
Transfinite Surface {  80 }  = {  7, 38, 37, 34 };
Transfinite Surface {  78 }  = { 21, 34, 38, 22 };
Transfinite Surface {  82 }  = { 34, 35, 36,  7 };
Transfinite Surface {  86 }  = { 35, 33, 20, 36 };
Transfinite Surface {  84 }  = { 21, 19, 33, 34 };
Transfinite Surface {  90 }  = { 19, 31, 32, 33 };
Transfinite Surface {  88 }  = { 31, 18, 20, 33 };
Transfinite Surface {  94 }  = { 29, 30, 18, 31 };
Transfinite Surface {  92 }  = { 28, 31, 19, 16 };
Transfinite Surface {  96 }  = { 28,  5, 30, 29 };
Transfinite Surface {  98 }  = { 26,  5, 28, 27 };
Transfinite Surface { 100 }  = { 17, 26, 28, 16 };
//
Transfinite Surface { 117 } = {  8, 43, 48, 41 };
Transfinite Surface { 119 } = { 41, 48, 47, 23 };
Transfinite Surface { 121 } = { 23, 47, 44, 11 };
Transfinite Surface { 123 } = { 11, 44, 45, 13 };

Transfinite Surface {176} = {9, 49, 50, 10};
Transfinite Surface {168} = {12, 10, 50, 51};
Transfinite Surface {154} = {52, 51, 50, 25};
Transfinite Surface {152} = {13, 52, 25, 11};
Transfinite Surface {160} = {13, 45, 53, 54};
Transfinite Surface {158} = {54, 55, 52, 13};
Transfinite Surface {166} = {52, 55, 56, 51};
Transfinite Surface {164} = {55, 54, 58, 56};
Transfinite Surface {162} = {54, 53, 57, 58};
Transfinite Surface {170} = {57, 46, 15, 58};
 
Transfinite Surface {203} = {65, 64, 1, 42};
Transfinite Surface {197} = {60, 61, 64, 65};
Transfinite Surface {199} = {61, 62, 63, 64};
Transfinite Surface {193} = {43, 8, 61, 60};


//
// -- Recombine Surface (Quadrilateral Elements) -------------------------------
Recombine Surface { 64, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100 };
Recombine Surface { 117, 119, 121, 123 };
Recombine Surface {170, 162, 164, 166, 158, 160, 154, 156, 176, 168, 174, 178, 152};
Recombine Surface {193, 197, 199, 203};

// // -- Extrude (Revolve around Y-axis) ------------------------------------------
// -- BP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{178, 174, 170, 162, 164, 166, 158, 160}; Layers{ n18 }; Recombine;
}
// -- Contact
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{123, 152, 154, 168}; Layers{ n18 }; Recombine;
}
// -- WP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{176, 156, 64, 100, 98, 78, 72, 74, 76, 80, 90, 88,117,119,121}; Layers{ n18 }; Recombine;
}
// -- Probe
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{86, 84, 82}; Layers{ n18 }; Recombine;
}
// -- Shoulder
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{94, 96, 92}; Layers{ n18 }; Recombine;
}
// -- Tool
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{195, 193, 199, 197, 203, 201}; Layers{ n18 }; Recombine;
}
// -- BP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{247, 225, 264, 281, 303, 325, 347, 364}; Layers{ n18 }; Recombine;
}
// -- Contact --
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{381, 403, 425, 447}; Layers{ n18 }; Recombine;
}
// -- WP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{469, 491, 538, 565, 587, 812, 795, 778, 663, 641, 614, 707, 685, 761, 729}; Layers{ n18 }; Recombine;
}
// -- Probe
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{861, 883, 834}; Layers{ n18 }; Recombine;
}
// -- Shoulder
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{905, 954, 927}; Layers{ n18 }; Recombine;
}
// Tool
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1011, 1028, 1067, 1050, 1084, 1116}; Layers{ n18 }; Recombine;
}
// -- BP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1138, 1160, 1177, 1194, 1216, 1238, 1260, 1277}; Layers{ n18 }; Recombine;
}
// -- Contact
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1294, 1316, 1338, 1360}; Layers{ n18 }; Recombine;
}
// -- WP
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1382, 1404, 1451, 1478, 1500, 1725, 1703, 1627, 1600, 1517, 1534, 1551, 1573, 1671, 1649}; Layers{ n18 }; Recombine;
}
// -- Probe
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1796, 1752, 1774}; Layers{ n18 }; Recombine;
}
// -- Shoulder
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1818, 1845, 1867}; Layers{ n18 }; Recombine;
}
// -- Tool
Extrude {{0, 1, 0}, {0, 0, 0}, 2*Pi/3} {
  Surface{1924, 1941, 1958, 1980, 1997, 2029}; Layers{ n18 }; Recombine;
}
//
// ---------------------------------------------------------------------------//
//   Physical Geometry                                                        //
// ---------------------------------------------------------------------------//
// -- VOLUMES ------------------------------------------------------------------
// -- Backplate ----------------------------------------------------------------
Physical Volume(1000) = {79, 80, 3, 41, 40, 2, 1, 81, 42, 45, 44, 5, 6, 46, 7, 86, 47, 43, 82, 85, 84, 83, 8, 4};
// -- Contact ------------------------------------------------------------------
Physical Volume(2000) = {11, 10, 51, 89, 88, 50, 49, 87, 48, 9, 90, 51, 12};
// -- Tool ---------------------------------------------------------------------
Physical Volume(3000) = {39, 77, 78, 117, 36, 76, 115, 75, 38, 114, 37, 116, 112, 113, 74, 35, 73, 34};
// -- Workpiece ----------------------------------------------------------------
Physical Volume(4000) = {91, 52, 13, 53, 92, 14, 93, 15, 54, 27, 100, 57, 98, 99, 101, 58, 61, 62,18, 19, 26, 63, 64, 60, 59, 102, 25, 103, 104, 105, 20, 21, 22,66, 65, 23, 24, 97, 96, 55, 56, 94, 95, 16, 17};
// -- Probe Thread -------------------------------------------------------------
Physical Volume(5000) = {68, 108, 30, 29, 28, 106, 107, 69, 67};
// -- Shoulder Scroll ----------------------------------------------------------
Physical Volume(6000) = {32, 31, 33, 111, 109, 110, 72, 70, 71};
//
// -- SURFACES -----------------------------------------------------------------
// -- Probe Bottom Surface -----------------------------------------------------
Physical Surface(3100) = {1568, 2501, 658, 769, 1542, 2480, 1666, 2522, 680};
// -- Tool Top -----------------------------------------------------------------
Physical Surface(3200) = {1111, 2766, 2024, 1082, 2739, 1995};
// -- Tool Lower Section -------------------------------------------------------
Physical Surface(3220) = {2683, 974, 1887, 1020, 2696, 1933};
// -- Tool Upper Section -------------------------------------------------------
Physical Surface(3240) = {2720, 1037, 1967, 1956, 1065, 2711};
// -- Probe Exit Surface -------------------------------------------------------
Physical Surface(3300) = {1618, 1648, 2426, 2543, 605, 706};
// -- Shoulder Scroll Top Surface ----------------------------------------------
Physical Surface(3400) = {922, 900, 1813, 1862, 2663, 2620};
// -- Shoulder Scroll Link Surface ---------------------------------------------
Physical Surface(3700) = {1690, 2404, 748};
// -- Probe Link Surface -------------------------------------------------------
Physical Surface(3800) = {744, 1686, 2400};
// -- Probe Side Surface -------------------------------------------------------
Physical Surface(3900) = {2560, 1791, 829, 878, 2603, 1769};
// -- InletOutlet (WP) ---------------------------------------------------------
Physical Surface(4100) = {2246, 1373, 460};
// -- WP Top -------------------------------------------------------------------
Physical Surface(4300) = {2242, 456, 1369, 1399, 486, 2271, 2289, 505, 1418};
Physical Surface(4350) = {582, 564, 1495, 1477, 2347, 2364};
// -- Shoulder Scroll Bottom Surface -------------------------------------------
Physical Surface(4500) = {533, 1446, 2317};
// -- Shoulder Scroll Outside Surface ------------------------------------------
Physical Surface(4600) = {1465, 1491, 578, 552, 2360, 2335};
//
//
// ===========================================================================//
//   End of File                                                              //
// ===========================================================================/

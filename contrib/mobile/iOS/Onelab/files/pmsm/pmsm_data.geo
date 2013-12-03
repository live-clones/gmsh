// Permanent magnet synchronous machine
// Example of Prof. Dr. Mauricio Valencia Ferreira da Luz (Florianopolis, August 23, 2010)

// Modified and customised for Onelab by Ruth V. Sabariego (February, 2013)

mm = 1e-3 ;
deg2rad = Pi/180 ;

pp = "Input/Constructive parameters/";

DefineConstant[
  NbrPolesInModel = { 1, Choices {1="1", 2="2", 4="4", 8="8"},
    Name "Input/20Number of poles in FE model",
    Highlight "Blue", Visible 1},
  InitialRotorAngle_deg = {7.5,
    Name "Input/21Start rotor angle [deg]",
    Highlight "AliceBlue"}
] ;

//--------------------------------------------------------------------------------

InitialRotorAngle = InitialRotorAngle_deg*deg2rad ; // initial rotor angle, 0 if aligned

//------------------------------------------------
//------------------------------------------------
NbrPolesTot = 8 ; // number of poles in complete cross-section
NbrPolePairs = NbrPolesTot/2 ;

SymmetryFactor = NbrPolesTot/NbrPolesInModel ;
Flag_Symmetry = (SymmetryFactor==1)?0:1 ;

NbrSectTot = NbrPolesTot ; // number of "rotor teeth"
NbrSect = NbrSectTot*NbrPolesInModel/NbrPolesTot ; // number of "rotor teeth" in FE model
//--------------------------------------------------------------------------------

//------------------------------------------------
// Stator
//------------------------------------------------
NbrSectTotStator  = 24; // number of stator teeth
NbrSectStator   = NbrSectTotStator*NbrPolesInModel/NbrPolesTot; // number of stator teeth in FE model
//--------------------------------------------------------------------------------

DefineConstant[
  lm = {2.352*mm , Name StrCat[pp, "Magnet height [m]"], Closed 0}
];

Th_magnet = 32.67 *deg2rad ;  // angle in degrees 0 < Th_magnet < 45

//--------------------------------------------------------------------------------

rRext = 25.6*mm;
rR1 = 10.5*mm;
rR2 = (rRext-lm); //23.243e-03;
rR3 = (rRext-0.7389*lm); //23.862e-03;
rR4 = (rRext-0.72278*lm); //23.9e-03;
rR5 = rRext; //25.6e-03;

//Gap = rS1-rR5;
DefineConstant[
  AxialLength = {35*mm,  Name StrCat[pp, "Axial length [m]"], Closed 1},
  Gap = {(26.02-25.6)*mm, Name StrCat[pp, "Airgap width [m]"], Closed 0}
];

rS1 = rR5 + Gap;     //rS1 = 26.02*mm;
rS2 = rS1 + 0.6*mm;  //rS2 = 26.62*mm;
rS3 = rS2 + 0.34*mm; //rS3 = 26.96*mm;
rS4 = rS3 + 11.2*mm; //rS4 = 38.16*mm;
rS5 = rS4 + 0.11*mm; //rS5 = 38.27*mm;
rS6 = rS5 + 1.75*mm; //rS6 = 40.02*mm;
rS7 = rS6 + 5.98*mm; //rS7 = 46.00*mm;

rB1  = rR5+Gap/3;
rB1b = rB1;
rB2  = rR5+Gap*2/3;


A0 =  45 * deg2rad ; // with this choice, axis A of stator is at 30 degrees with regard to horizontal axis
A1 =   0 * deg2rad ; // Rotor initial aligned position, current position in angRot

sigma_fe = 0. ; // laminated steel
DefineConstant[
  mur_fe = {1000, Name StrCat[pp, "Relative permeability for linear case"]},
  b_remanent = {1.2, Name StrCat[pp, "Remanent induction [T]"] }
];

rpm_nominal = 500 ;
Inominal = 3.9 ; // Nominal current
Tnominal = 2.5 ; // Nominal torque

// ----------------------------------------------------
// Numbers for physical regions in .geo and .pro files
// ----------------------------------------------------
// Rotor
ROTOR_FE     = 1000 ;
ROTOR_AIR    = 1001 ;
ROTOR_AIRGAP = 1002 ;
ROTOR_MAGNET = 1010 ; // Index for first Magnet (1/8 model->1; full model->8)

ROTOR_BND_MOVING_BAND = 1100 ; // Index for first line (1/8 model->1; full model->8)
ROTOR_BND_A0 = 1200 ;
ROTOR_BND_A1 = 1201 ;
SURF_INT     = 1202 ;

// Stator
STATOR_FE     = 2000 ;
STATOR_AIR    = 2001 ;
STATOR_AIRGAP = 2002 ;

STATOR_BND_MOVING_BAND = 2100 ;// Index for first line (1/8 model->1; full model->8)
STATOR_BND_A0          = 2200 ;
STATOR_BND_A1          = 2201 ;

STATOR_IND = 2300 ; //Index for first Ind (1/8 model->3; full model->24)
STATOR_IND_AP = STATOR_IND + 1 ; STATOR_IND_BM = STATOR_IND + 2 ;STATOR_IND_CP = STATOR_IND + 3 ;
STATOR_IND_AM = STATOR_IND + 4 ; STATOR_IND_BP = STATOR_IND + 5 ;STATOR_IND_CM = STATOR_IND + 6 ;

SURF_EXT = 3000 ; // outer boundary


MOVING_BAND = 9999 ;

NICEPOS = 111111 ;

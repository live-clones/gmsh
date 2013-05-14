//
// Circuit for Permanent Magnet Synchronous Generator - cbmag
//

Group{
  // Dummy numbers for circuit definition
  R1 = #55551 ;
  R2 = #55552 ;
  R3 = #55553 ;

  Input1 = #10001 ;
  Input2 = #10002 ;
  Input3 = #10003 ;
  Input4 = #10004 ;

  Resistance_Cir  = Region[{R1, R2, R3}];
  DomainZ_Cir = Region[ {Resistance_Cir} ];

  DomainSource_Cir = Region[ {} ] ;
  If(Flag_SrcType_Stator>1)
    DomainSource_Cir += Region[ {Input1, Input2, Input3} ] ;
  EndIf

  DomainZt_Cir    = Region[ {DomainZ_Cir, DomainSource_Cir} ];
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------

Function {
  // Open circuit - load - short circuit
  DefineConstant[ ZR = {200,
      Choices{1e-8, 200, 1e8}, Label "Load resistance",  Path "Input/", Highlight "AliceBlue"} ];
  Resistance[#{R1, R2, R3}]  = ZR ;
}

// --------------------------------------------------------------------------

Constraint {

  If (SymmetryFactor<8)
    If(Flag_SrcType_Stator==0)
      { Name ElectricalCircuit ; Type Network ;
        Case Circuit1 {
          { Region Stator_Ind_Ap ; Branch {100,102} ; }
          { Region Stator_Ind_Am ; Branch {103,102} ; }
          { Region R1            ; Branch {103,100} ; }
        }
        Case Circuit2 {
          { Region Stator_Ind_Bp ; Branch {200,202} ; }
          { Region Stator_Ind_Bm ; Branch {203,202} ; }
          { Region R2            ; Branch {203,200} ; }
        }
        Case Circuit3 {
          { Region Stator_Ind_Cp ; Branch {300,302} ; }
          { Region Stator_Ind_Cm ; Branch {303,302} ; }
          { Region R3            ; Branch {303,300} ; }
        }
      }
    EndIf
    If (Flag_SrcType_Stator==2)
      { Name ElectricalCircuit ; Type Network ;
        Case Circuit1 {
          { Region Input1        ; Branch {100,101} ; }
          { Region Stator_Ind_Ap ; Branch {101,102} ; }
          { Region Stator_Ind_Am ; Branch {103,102} ; }
          { Region R1            ; Branch {103,100} ; }
        }
        Case Circuit2 {
          { Region Input2        ; Branch {200,201} ; }
          { Region Stator_Ind_Bp ; Branch {201,202} ; }
          { Region Stator_Ind_Bm ; Branch {203,202} ; }
          { Region R2            ; Branch {203,200} ; }
        }
        Case Circuit3 {
          { Region Input3        ; Branch {300,301} ; }
          { Region Stator_Ind_Cp ; Branch {301,302} ; }
          { Region Stator_Ind_Cm ; Branch {303,302} ; }
          { Region R3            ; Branch {303,300} ; }
        }
      }
    EndIf
  EndIf

  If(SymmetryFactor==8)
    If(Flag_SrcType_Stator==0) // Only one physical region in geo allow per branch
      { Name ElectricalCircuit ; Type Network ;
        Case Circuit1 {
          { Region PhaseA        ; Branch {100,102} ; }
          { Region R1            ; Branch {102,100} ; }
        }
        Case Circuit2 {
          { Region PhaseB        ; Branch {200,202} ; }
          { Region R2            ; Branch {202,200} ; }
        }
        Case Circuit3 {
          { Region PhaseC        ; Branch {300,302} ; }
          { Region R3            ; Branch {302,300} ; }
        }
      }
    EndIf
    If(Flag_SrcType_Stator==2) // Only one physical region in geo allow per branch
      { Name ElectricalCircuit ; Type Network ;
        Case Circuit1 {
          { Region Input1        ; Branch {100,101} ; }
          { Region PhaseA        ; Branch {101,102} ; }
          { Region R1            ; Branch {102,100} ; }
        }
        Case Circuit2 {
          { Region Input2        ; Branch {200,201} ; }
          { Region PhaseB        ; Branch {201,202} ; }
          { Region R2            ; Branch {202,200} ; }
        }
        Case Circuit3 {
          { Region Input3        ; Branch {300,301} ; }
          { Region PhaseC        ; Branch {302,301} ; }
          { Region R3            ; Branch {302,300} ; }
        }
      }
    EndIf
  EndIf
}


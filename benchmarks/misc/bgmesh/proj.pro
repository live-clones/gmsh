// Moronic getdp input file to create some test post-proessing maps

Group {
  Omega = Region[ {1} ];
}

Function {
  Fct[] = (Sin[Pi*(X[]+1)]+1) * 0.4 + 0.05 ;
}

Jacobian {
  { Name JVol ; Case { { Region All ; Jacobian Vol ; } } }
  { Name JSur ; Case { { Region All ; Jacobian Sur ; } } }
}

Integration {
  { Name I1 ;
    Case { {Type Gauss ;
            Case { { GeoElement Line        ; NumberOfPoints  4 ; }
                   { GeoElement Triangle    ; NumberOfPoints  12 ; }
                   { GeoElement Quadrangle  ; NumberOfPoints  4 ; }
                   { GeoElement Tetrahedron ; NumberOfPoints  15 ; }
                   { GeoElement Hexahedron  ; NumberOfPoints  34 ; }
                   { GeoElement Prism       ; NumberOfPoints  9 ; } 
                   { GeoElement Pyramid     ; NumberOfPoints  8 ; } }
           }
         }
  }
}

FunctionSpace {
  { Name Proj ; Type Form0 ; 
    BasisFunction {
      { Name sn ; NameOfCoef phin ; Function BF_Node ;
        Support Omega ; Entity NodesOf[ All ] ; }
    }
  }
}

Formulation {
  { Name Proj ; Type FemEquation ;
    Quantity { 
      { Name v ; Type Local ; NameOfSpace Proj ; }
    }
    Equation {
      Galerkin { [ Dof{v} , {v} ] ;  In Omega ; Jacobian JVol ; Integration I1 ; }
      Galerkin { [ -Fct[] , {v} ] ;  In Omega ; Jacobian JVol ; Integration I1 ; }
    }
  }

}

Resolution {
  { Name Proj ;
    System {
      { Name Proj ; NameOfFormulation Proj ; Type Complex; Frequency 1; }
    }
    Operation { 
      Generate Proj ; Solve Proj ; SaveSolution Proj ;
    }
  }

}

PostProcessing {
  { Name Proj ; NameOfFormulation Proj  ;
    Quantity {
      { Name v ; Value { Term { [ {v} ] ; In Omega ; } } }
      { Name v3 ; Value { Term { [ Vector[0,{v},0] ] ; In Omega ; } } }
    }
  }

}

PostOperation v UsingPost Proj {
  Print[ v , OnElementsOf Omega , File "proj.pos" ] ;
}

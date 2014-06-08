Include "Functions.inc";

/* physical numbers */

Include "PhysNum.inc";


Geometry.LineWidth = 2;
Geometry.AutoCoherence = 0;




Printf("****************************************** Stator *********************************************");

//Include "StatorSector.inc";
Include "Stator3kW.inc";
Include "Stator.inc";






Printf("******************************************* Rotor *********************************************");

//Include "RotorSector.inc";
Include "Rotor3kW.inc";
Include "Rotor.inc";




Printf("**************************************** Moving Band ******************************************");

Printf("Rotor airgap layer : physical region %g", RotorAirgapLayer);
mmm = newreg; Plane Surface(mmm) = {OuterMB_,InnerMB_};
Physical Surface(MB) = {mmm};






Include "Functions.geo";

/* physical numbers */

Include "PhysNum.geo";


Geometry.LineWidth = 2;
Geometry.AutoCoherence = 0;




Printf("****************************************** Stator *********************************************");

//Include "StatorSector.geo";
Include "Stator3kW.geo";
Include "Stator.geo";






Printf("******************************************* Rotor *********************************************");

//Include "RotorSector.geo";
Include "Rotor3kW.geo";
Include "Rotor.geo";




Printf("**************************************** Moving Band ******************************************");

Printf("Rotor airgap layer : physical region %g", RotorAirgapLayer);
mmm = newreg; Plane Surface(mmm) = {OuterMB_,InnerMB_};
Physical Surface(MB) = {mmm};






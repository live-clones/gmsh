

NbrSect_ = NbrSect; NbrLine_ = NbrLine; L_[]=L[];

Printf("Copy lines");
Call CopyLines;

LineLoop_[] = LineLoop2[] ; NbrLines_ = NbrLines2; PhysNum_ = StatorConductor; dPhysNum_ = 1; 
Printf("Stator conductors : physical ssurfaces %g to %g", PhysNum_, PhysNum_+(NbrSect-1)*dPhysNum_);
Call CopySlot;


LineLoop_[] = LineLoop3[] ; NbrLines_ = NbrLines3; PhysNum_ = StatorSlotOpening; dPhysNum_ = 0; 
Printf("Stator slot openings : physical surface %g", PhysNum_);
Call CopySlot;


Printf("OuterAirgap : line loop %g", newreg);
LineLoop_[] = LineLoop1[] ; NbrLines_ = NbrLines1; OuterAirgap = newreg; Call ConnectLine; 


Printf("OuterMB : line loop %g / physical line %g", newreg, OuterMB);
LineLoop_[] = LineLoop4[] ; NbrLines_ = NbrLines4; OuterMB_ = newreg; Call ConnectLine; 

Physical Line(OuterMB) = {KK_[{0:NbrLines_*NbrSect_-1}]};


Printf("OuterStator : line loop %g / physical line %g", newreg, OuterStator);
LineLoop_[] = LineLoop5[] ; NbrLines_ = NbrLines5; OuterStator_ = newreg; Call ConnectLine; 

Physical Line(OuterStator) = {KK_[{0:NbrLines_*NbrSect_-1}]};



Printf("InnerStatorIron : line loop %g", newreg);
LineLoop_[] = LineLoop6[] ; NbrLines_ = NbrLines6; InnerStator = newreg; Call ConnectLine; 

Printf("Stator airgap layer : physical surface %g", StatorAirgapLayer);
mmm = newreg; Plane Surface(mmm) = {OuterAirgap,OuterMB_};
Physical Surface(StatorAirgapLayer) = {mmm};

Printf("Stator iron : physical surface %g", StatorIron);
mmm = newreg; Plane Surface(mmm) = {OuterStator_,InnerStator};
Physical Surface(StatorIron) = {mmm};






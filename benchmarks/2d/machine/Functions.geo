Function CopySlot

  For t_ In {1:NbrSect_}
    dt_ = (t_-1)*NbrLine_;
    For j_ In {0:NbrLines_-1}
      KK_[j_] = ((LineLoop_[j_]>0)?1:-1) * (L_[Fabs(LineLoop_[j_])+dt_]);
//  Printf("KK %g %g", j_, KK_[j_]);
    EndFor
    ll_ = newreg; Line Loop(newreg) = {KK_[{0:NbrLines_-1}]};
    lll_= newreg; Plane Surface(newreg) = {ll_};
    Physical Surface(PhysNum_+(t_-1)*dPhysNum_) = {lll_};

    geuz[t_-1]=lll_;

  EndFor

Return


Function ConnectLine

  ii_ = -1;
  For t_ In {1:NbrSect_}
    dt_ = (t_-1)*NbrLine_;
    For j_ In {0:NbrLines_-1}
      ii_++; KK_[ii_] = ((LineLoop_[j_]>0)?1:-1) * (L_[Fabs(LineLoop_[j_])+dt_]);
//Printf("KK %g %g %g %g", t_, j_, ii_,KK_[ii_]);
    EndFor
  EndFor
       Printf("ConnectLine newreg %g", newreg);
  Line Loop(newreg) = {KK_[{0:NbrLines_*NbrSect_-1}]};

Return



Function CopyLines

  ii_=NbrLine_+1;
  For t_ In {1:NbrSect_-1}
    For i_ In {1:NbrLine_}
      L_[ii_] = newreg; ii_++;
      Rotate { {0,0,1},{0,0,0},2*Pi*t_/NbrSect_ } { Duplicata { Line{L_[i_]}; } }
    EndFor
  EndFor
  Coherence;

Return











Merge "capot.brep";

// curves 44 and 47 are very small - make a compound mesh with the
// neighboring curves
Compound Line{50,47};
Compound Line{44,46};

// mesh all surfaces as a single one
Compound Surface{1:18} ;

Physical Surface(100)={1:18};

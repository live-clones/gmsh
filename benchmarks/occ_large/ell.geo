SetFactory("OpenCASCADE");

Macro FCCUnitCell
  coeffs_1 = {1,-1,1,-1, 1,-1,1,-1,  1,-1, 0, 0, 0, 0};
  coeffs_2 = {1,1,-1,-1, 1,1,-1,-1,  0, 0, 1,-1, 0, 0};
  coeffs_3 = {1,1,1,1, -1,-1,-1,-1,  0, 0, 0, 0, 1, -1};

  size = #coeffs_1() - 1;

  For i In {0:size}
    center = {0.5*coeffs_1[i], 0.5*coeffs_2[i], 0.5*coeffs_3[i]};
    v = newv; Sphere(v) = {center(0),center(1), center(2), r};
    Dilate { {0.,0.,0.}, {1/aspect_ratio_31, 1/aspect_ratio_32, 1} } {
      Volume{v};
    }
    iVolumes() += v;
  EndFor

  // Box
  v_box = newreg; Box(v_box) = {-0.5/aspect_ratio_31,-0.5/aspect_ratio_32,-0.5,
                                1/aspect_ratio_31,1/aspect_ratio_32,1};

  BooleanIntersection{ Volume{v_box}; }{ Volume{iVolumes()}; Delete; }
Return

iVolumes() = {};
mVolume() = {};

cl = 0.1/2;
vf = 0.15;
fiber = 1;
matrix = 2;
nparticles = 4.;
r = (3.*vf/(nparticles*4.*Pi))^(1.0/3.0);

Mesh.CharacteristicLengthMin = cl;
Mesh.CharacteristicLengthMax = cl;

aspect_ratio_31 = 1/5;
aspect_ratio_32 = 1;

Call FCCUnitCell;

Coherence;

Save "ell.brep";

Merge "unit-cube.geo";

// before 2.8.5 this would lead to bad surface meshes (as the mean plane was not
// recomptuted in the GModel after the last importGeoInternals)
Translate{0,0,1}{
  Volume{1};
}
Mesh.CharacteristicLengthMin = 1;

// Plugin(FieldFromAmplitudePhase): u = a exp(i k phi) from a two-step
// amplitude (list data) and a scalar phase (model data), interpolated on the
// nodes of a quadrangle mesh read from MeshFile

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(HarmonicToTime).View = 0;
Plugin(HarmonicToTime).NumSteps = 2;
Plugin(HarmonicToTime).NumPeriods = 1;
Plugin(HarmonicToTime).Run; // view 4: two steps
Plugin(FieldFromAmplitudePhase).AmplitudeView = 4;
Plugin(FieldFromAmplitudePhase).PhaseView = 0;
Plugin(FieldFromAmplitudePhase).Wavenumber = 2;
Plugin(FieldFromAmplitudePhase).MeshFile =
  StrCat(CurrentDirectory, "data/quads.msh");
Plugin(FieldFromAmplitudePhase).Run;

// Plugin(HarmonicToTime): time series from two steps of scalar (model) and
// vector (list) node data on triangles and quadrangles, both time signs,
// several periods, zero frequency

Merge "data/square.msh"; // views 0-3: scalar, vector, tensor, cell
Plugin(HarmonicToTime).View = 0;
Plugin(HarmonicToTime).NumSteps = 8;
Plugin(HarmonicToTime).Run;
Plugin(HarmonicToTime).RealPart = 2;
Plugin(HarmonicToTime).ImaginaryPart = 0;
Plugin(HarmonicToTime).TimeSign = 1;
Plugin(HarmonicToTime).Frequency = 50;
Plugin(HarmonicToTime).NumPeriods = 2;
Plugin(HarmonicToTime).Run;
Plugin(HarmonicToTime).Frequency = 0;
Plugin(HarmonicToTime).NumSteps = 2;
Plugin(HarmonicToTime).Run;
Plugin(HarmonicToTime).Frequency = 1;
Plugin(HarmonicToTime).NumPeriods = 1;
Plugin(HarmonicToTime).TimeSign = -1;
Plugin(HarmonicToTime).NumSteps = 4;
Merge "data/quads.pos";
Plugin(HarmonicToTime).View = PostProcessing.NbViews - 3;
Plugin(HarmonicToTime).Run;

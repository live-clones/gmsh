// A box: its faces are what the volume command gathers.
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 1, 1};
//+
Surface Loop(2) = {4, 5, 1, 3, 6, 2};
//+
Surface Loop(3) = {4, 5, 1, 3, 6, 2};
//+
Surface Loop(4) = {1, 3, 5, 2, 4, 6};

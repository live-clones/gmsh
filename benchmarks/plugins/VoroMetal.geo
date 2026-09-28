// Plugin(VoroMetal): periodic Voronoi microstructure of 6 seeds in the unit
// cube, loaded as the model, with its files

Plugin(VoroMetal).SeedsFile = StrCat(CurrentDirectory, "data/vorometal_seeds.txt");
Plugin(VoroMetal).Run;

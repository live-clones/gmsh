// Merge this once you have a nice view of the model to generate the master
// 1024x1024 screenshot for the mobile app, as well as the scaled 128x128 thumbnail

Print.Width = 1014;
Print.Height = 1014;
Print.Background = 1;

model = AbsolutePath(General.FileName);
dir = DirName(model);
Save StrCat(dir, "infos_large.png");
SystemCall StrCat("convert -scale 128 ", dir, "infos_large.png ", dir, "infos.png");

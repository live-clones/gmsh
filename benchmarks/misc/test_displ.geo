Include "test_field.pos";
Include "test_displ.pos";

Plugin(Warp).View = 0;
Plugin(Warp).OtherView = 1;
Plugin(Warp).Factor = 1;
Plugin(Warp).Run;

View[0].ShowElement = 1;

Plugin(Skin).View = 0;
Plugin(Skin).Run;

View[0].Visible = 0;
View[1].Visible = 0;

View[2].ShowElement = 1;
View[2].Light = 1;

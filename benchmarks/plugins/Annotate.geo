// Plugin(Annotate): 2D and 3D strings with font, size and alignment, in place
// in list data and in a new view for model data

Merge "data/square.pos"; // views 0-3
Plugin(Annotate).View = 0;
Plugin(Annotate).Text = "2D text";
Plugin(Annotate).X = 20;
Plugin(Annotate).Y = 40;
Plugin(Annotate).Run;
Plugin(Annotate).Text = "3D text";
Plugin(Annotate).ThreeD = 1;
Plugin(Annotate).X = 0.5;
Plugin(Annotate).Y = 0.25;
Plugin(Annotate).Z = 0.1;
Plugin(Annotate).Font = "Times-Bold";
Plugin(Annotate).FontSize = 24;
Plugin(Annotate).Align = "Center";
Plugin(Annotate).Run;
Plugin(Annotate).View = 1;
Plugin(Annotate).Text = "right";
Plugin(Annotate).Align = "TopRight";
Plugin(Annotate).ThreeD = 0;
Plugin(Annotate).X = 300;
Plugin(Annotate).Run;

Merge "data/cube.msh"; // views 4-7, model data: new views 8 and 9
Plugin(Annotate).View = 4;
Plugin(Annotate).Text = "model";
Plugin(Annotate).Font = "Courier";
Plugin(Annotate).Align = "Left";
Plugin(Annotate).Run;
Plugin(Annotate).View = 7;
Plugin(Annotate).ThreeD = 1;
Plugin(Annotate).Run;

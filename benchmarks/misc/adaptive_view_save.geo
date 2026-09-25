// Merge a high-order view, adapt it, and save the refined view in MSH and VTU
// files (for readers that cannot handle high-order elements)

Merge "adaptive_view.pos";

View[0].AdaptVisualizationGrid = 1;
View[0].MaxRecursionLevel = 3;
View[0].TargetError = 1e-3;

PostProcessing.SaveAdapted = 1;
Save View[0] "adaptive_view_adapted.msh";
Save View[0] "adaptive_view_adapted.vtu";

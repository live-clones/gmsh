# Writes the .vtu files read by vtk_written.geo; run with ParaView's pvpython
# (or a python with the vtk module) in this directory.
import vtk
out = ""
def make(celltype, order, name, mode, compress):
    s = vtk.vtkCellTypeSource()
    s.SetCellType(celltype); s.SetCellOrder(order); s.SetBlocksDimensions(2, 2, 2)
    s.SetOutputPrecision(vtk.vtkAlgorithm.DOUBLE_PRECISION)
    s.Update()
    g = s.GetOutput()
    for a in [g.GetPointData().GetArrayName(i) for i in range(g.GetPointData().GetNumberOfArrays())]:
        g.GetPointData().RemoveArray(a)
    w = vtk.vtkXMLUnstructuredGridWriter(); w.SetFileName(out + name); w.SetInputData(g)
    w.SetDataMode(mode)
    if compress: w.SetCompressorTypeToZLib()
    else: w.SetCompressorTypeToNone()
    w.Write()
    print(name, g.GetNumberOfPoints(), g.GetNumberOfCells(), g.GetCellType(0))
make(vtk.VTK_LAGRANGE_TETRAHEDRON, 3, "vtk_tetrahedra_order3.vtu", vtk.vtkXMLWriter.Appended, True)
make(vtk.VTK_LAGRANGE_HEXAHEDRON, 3, "vtk_hexahedra_order3.vtu", vtk.vtkXMLWriter.Binary, False)
make(vtk.VTK_LAGRANGE_WEDGE, 2, "vtk_prisms_order2.vtu", vtk.vtkXMLWriter.Ascii, False)
make(vtk.VTK_QUADRATIC_PYRAMID, 2, "vtk_pyramids_order2.vtu", vtk.vtkXMLWriter.Appended, False)
make(vtk.VTK_LAGRANGE_HEXAHEDRON, 2, "vtk_hexahedra_order2.vtu", vtk.vtkXMLWriter.Ascii, False)

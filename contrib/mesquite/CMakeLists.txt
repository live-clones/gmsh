# This CMakeLists.txt has been adapted from the deal.ii integration of mesquite

set(MESQUITE_SRC
  Control/Mesquite_Instruction.cpp
  Control/Mesquite_InstructionQueue.cpp
  Control/Mesquite_IQInterface.cpp
  Control/Mesquite_Settings.cpp
  Control/Mesquite_SlaveBoundaryVertices.cpp
  Control/Mesquite_TerminationCriterion.cpp
  MappingFunction/Lagrange/Mesquite_HexLagrangeShape.cpp
  MappingFunction/Lagrange/Mesquite_QuadLagrangeShape.cpp
  MappingFunction/Lagrange/Mesquite_TetLagrangeShape.cpp
  MappingFunction/Lagrange/Mesquite_TriLagrangeShape.cpp
  MappingFunction/Linear/Mesquite_LinearHexahedron.cpp
  MappingFunction/Linear/Mesquite_LinearPrism.cpp
  MappingFunction/Linear/Mesquite_LinearPyramid.cpp
  MappingFunction/Linear/Mesquite_LinearQuadrilateral.cpp
  MappingFunction/Linear/Mesquite_LinearTetrahedron.cpp
  MappingFunction/Linear/Mesquite_LinearTriangle.cpp
  MappingFunction/Mesquite_MappingFunction.cpp
  MappingFunction/Mesquite_NodeSet.cpp
  MappingFunction/Mesquite_Sample.cpp
  Mesh/Mesquite_ArrayMesh.cpp
  Mesh/Mesquite_ElementPatches.cpp
  Mesh/Mesquite_ExtraData.cpp
  Mesh/Mesquite_GlobalPatch.cpp
  Mesh/Mesquite_IdealElements.cpp
  Mesh/Mesquite_MeshDecorator.cpp
  Mesh/Mesquite_MeshImpl.cpp
  Mesh/Mesquite_MeshImplData.cpp
  Mesh/Mesquite_MeshImplTags.cpp
  Mesh/Mesquite_MeshUtil.cpp
  Mesh/Mesquite_MeshWriter.cpp
  Mesh/Mesquite_MsqMeshEntity.cpp
  Mesh/Mesquite_MsqVertex.cpp
  # Mesh/Mesquite_ParallelHelper.cpp # commented because no MPI
  Mesh/Mesquite_ParallelHelperNoMPIStub.cpp
  Mesh/Mesquite_ParallelMeshImpl.cpp
  Mesh/Mesquite_PatchData.cpp
  Mesh/Mesquite_PatchIterator.cpp
  Mesh/Mesquite_PatchSet.cpp
  Mesh/Mesquite_TagVertexMesh.cpp
  Mesh/Mesquite_TopologyInfo.cpp
  Mesh/Mesquite_VertexPatches.cpp
  Misc/Mesquite_BoundedCylinderDomain.cpp
  Misc/Mesquite_ConicDomain.cpp
  Misc/Mesquite_CylinderDomain.cpp
  Misc/Mesquite_DomainClassifier.cpp
  Misc/Mesquite_DomainUtil.cpp
  Misc/Mesquite_EdgeIterator.cpp
  Misc/Mesquite_Exponent.cpp
  Misc/Mesquite_FileTokenizer.cpp
  Misc/Mesquite_MeshDomain1D.cpp
  Misc/Mesquite_MeshTransform.cpp
  Misc/Mesquite_MesquiteVersion.cpp
  Misc/Mesquite_MsqDebug.cpp
  Misc/Mesquite_MsqError.cpp
  Misc/Mesquite_MsqFPE.cpp
  Misc/Mesquite_MsqGeomPrim.cpp
  Misc/Mesquite_MsqHessian.cpp
  # Misc/Mesquite_MsqIBase.cpp # commented because does not compile
  Misc/Mesquite_MsqInterrupt.cpp
  Misc/Mesquite_MsqTimer.cpp # commented because does not compile
  Misc/Mesquite_PlanarDomain.cpp
  Misc/Mesquite_SimpleStats.cpp
  Misc/Mesquite_SphericalDomain.cpp
  Misc/Mesquite_Vector3D.cpp
  Misc/Mesquite_VtkTypeInfo.cpp
  Misc/Mesquite_XYPlanarDomain.cpp
  Misc/Mesquite_XYRectangle.cpp
  ObjectiveFunction/Mesquite_CompositeOFAdd.cpp
  ObjectiveFunction/Mesquite_CompositeOFMultiply.cpp
  ObjectiveFunction/Mesquite_CompositeOFScalarAdd.cpp
  ObjectiveFunction/Mesquite_CompositeOFScalarMultiply.cpp
  ObjectiveFunction/Mesquite_LInfTemplate.cpp
  ObjectiveFunction/Mesquite_LPtoPTemplate.cpp
  ObjectiveFunction/Mesquite_MaxTemplate.cpp
  ObjectiveFunction/Mesquite_ObjectiveFunction.cpp
  ObjectiveFunction/Mesquite_ObjectiveFunctionTemplate.cpp
  ObjectiveFunction/Mesquite_OFEvaluator.cpp
  ObjectiveFunction/Mesquite_PatchPowerMeanP.cpp
  ObjectiveFunction/Mesquite_PMeanPTemplate.cpp
  ObjectiveFunction/Mesquite_StdDevTemplate.cpp
  ObjectiveFunction/Mesquite_VarianceTemplate.cpp
  QualityAssessor/Mesquite_QualityAssessor.cpp
  QualityImprover/OptSolvers/Mesquite_ConjugateGradient.cpp
  QualityImprover/OptSolvers/Mesquite_FeasibleNewton.cpp
  QualityImprover/OptSolvers/Mesquite_NonGradient.cpp
  QualityImprover/OptSolvers/Mesquite_NonSmoothDescent.cpp
  QualityImprover/OptSolvers/Mesquite_QuasiNewton.cpp
  QualityImprover/OptSolvers/Mesquite_SteepestDescent.cpp
  QualityImprover/OptSolvers/Mesquite_TrustRegion.cpp
  QualityImprover/Mesquite_PatchSetUser.cpp
  QualityImprover/Mesquite_QualityImprover.cpp
  QualityImprover/Relaxation/Mesquite_LaplacianSmoother.cpp
  QualityImprover/Relaxation/Mesquite_Randomize.cpp
  QualityImprover/Relaxation/Mesquite_RelaxationSmoother.cpp
  QualityImprover/Relaxation/Mesquite_SmartLaplacianSmoother.cpp
  QualityImprover/Mesquite_VertexMover.cpp
  QualityMetric/Mesquite_AddQualityMetric.cpp
  QualityMetric/Mesquite_AveragingQM.cpp
  QualityMetric/Debug/Mesquite_CompareQM.cpp
  QualityMetric/Debug/Mesquite_NumericalQM.cpp
  QualityMetric/Mesquite_EdgeQM.cpp
  QualityMetric/Mesquite_ElementAvgQM.cpp
  QualityMetric/Mesquite_ElementMaxQM.cpp
  QualityMetric/Mesquite_ElementPMeanP.cpp
  QualityMetric/Mesquite_ElementQM.cpp
  QualityMetric/Mesquite_ElemSampleQM.cpp
  QualityMetric/Mesquite_MultiplyQualityMetric.cpp
  QualityMetric/Mesquite_PMeanPMetric.cpp
  QualityMetric/Mesquite_PowerQualityMetric.cpp
  QualityMetric/Mesquite_QualityMetric.cpp
  QualityMetric/Mesquite_ScalarAddQualityMetric.cpp
  QualityMetric/Mesquite_ScalarMultiplyQualityMetric.cpp
  QualityMetric/Shape/Mesquite_AspectRatioGammaQualityMetric.cpp
  QualityMetric/Shape/Mesquite_ConditionNumberQualityMetric.cpp
  QualityMetric/Shape/Mesquite_IdealWeightInverseMeanRatio.cpp
  QualityMetric/Shape/Mesquite_IdealWeightMeanRatio.cpp
  QualityMetric/Shape/Mesquite_VertexConditionNumberQualityMetric.cpp
  QualityMetric/Smoothness/Mesquite_EdgeLengthQualityMetric.cpp
  QualityMetric/Smoothness/Mesquite_EdgeLengthRangeQualityMetric.cpp
  QualityMetric/TMP/Mesquite_AffineMapMetric.cpp
  QualityMetric/TMP/Mesquite_AWQualityMetric.cpp
  QualityMetric/TMP/Mesquite_TargetMetricUtil.cpp
  QualityMetric/TMP/Mesquite_TMPQualityMetric.cpp
  QualityMetric/TMP/Mesquite_TQualityMetric.cpp
  QualityMetric/Untangle/Mesquite_UntangleBetaQualityMetric.cpp
  QualityMetric/Mesquite_VertexMaxQM.cpp
  QualityMetric/Mesquite_VertexPMeanP.cpp
  QualityMetric/Mesquite_VertexQM.cpp
  QualityMetric/Volume/Mesquite_EdgeLengthMetric.cpp
  QualityMetric/Volume/Mesquite_LocalSizeQualityMetric.cpp
  QualityMetric/Volume/Mesquite_SizeMetric.cpp
  TargetCalculator/Mesquite_CachingTargetCalculator.cpp
  TargetCalculator/Mesquite_IdealShapeTarget.cpp
  TargetCalculator/Mesquite_InverseMetricWeight.cpp
  TargetCalculator/Mesquite_JacobianCalculator.cpp
  TargetCalculator/Mesquite_LambdaConstant.cpp
  TargetCalculator/Mesquite_LambdaTarget.cpp
  TargetCalculator/Mesquite_LVQDTargetCalculator.cpp
  TargetCalculator/Mesquite_MetricWeight.cpp
  TargetCalculator/Mesquite_ReferenceMesh.cpp
  TargetCalculator/Mesquite_RefMeshTargetCalculator.cpp
  TargetCalculator/Mesquite_RefSizeTargetCalculator.cpp
  TargetCalculator/Mesquite_RemainingWeight.cpp
  TargetCalculator/Mesquite_TargetCalculator.cpp
  TargetCalculator/Mesquite_TargetReader.cpp
  TargetCalculator/Mesquite_TargetWriter.cpp
  TargetCalculator/Mesquite_TetDihedralWeight.cpp
  TargetCalculator/Mesquite_WeightCalculator.cpp
  TargetCalculator/Mesquite_WeightReader.cpp
  TargetMetric/Mesquite_AWMetric.cpp
  TargetMetric/Mesquite_AWMetricBarrier.cpp
  TargetMetric/Mesquite_AWMetricNonBarrier.cpp
  TargetMetric/Misc/Mesquite_InvTransBarrier.cpp
  TargetMetric/Misc/Mesquite_TMixed.cpp
  TargetMetric/Misc/Mesquite_TOffset.cpp
  TargetMetric/Misc/Mesquite_TPower2.cpp
  TargetMetric/Misc/Mesquite_TScale.cpp
  TargetMetric/Misc/Mesquite_TSquared.cpp
  TargetMetric/Misc/Mesquite_TSum.cpp
  TargetMetric/Shape/Mesquite_AWShape2DB1.cpp
  TargetMetric/Shape/Mesquite_AWShape2DNB1.cpp
  TargetMetric/Shape/Mesquite_AWShape2DNB2.cpp
  TargetMetric/Shape/Mesquite_TInverseMeanRatio.cpp
  TargetMetric/Shape/Mesquite_TShape2DNB2.cpp
  TargetMetric/Shape/Mesquite_TShape3DB2.cpp
  TargetMetric/Shape/Mesquite_TShapeB1.cpp
  TargetMetric/Shape/Mesquite_TShapeNB1.cpp
  TargetMetric/ShapeOrient/Mesquite_AWShapeOrientNB1.cpp
  TargetMetric/ShapeOrient/Mesquite_TShapeOrientB1.cpp
  TargetMetric/ShapeOrient/Mesquite_TShapeOrientB2.cpp
  TargetMetric/ShapeOrient/Mesquite_TShapeOrientNB1.cpp
  TargetMetric/ShapeOrient/Mesquite_TShapeOrientNB2.cpp
  TargetMetric/ShapeSize/Mesquite_AWShapeSizeB1.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize2DB2.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize2DNB1.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize2DNB2.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize3DB2.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize3DB4.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSize3DNB1.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSizeB1.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSizeB3.cpp
  TargetMetric/ShapeSize/Mesquite_TShapeSizeNB3.cpp
  TargetMetric/ShapeSizeOrient/Mesquite_AWShapeSizeOrientNB1.cpp
  TargetMetric/ShapeSizeOrient/Mesquite_TShapeSizeOrientB1.cpp
  TargetMetric/ShapeSizeOrient/Mesquite_TShapeSizeOrientB2.cpp
  TargetMetric/ShapeSizeOrient/Mesquite_TShapeSizeOrientNB1.cpp
  TargetMetric/Size/Mesquite_AWSizeB1.cpp
  TargetMetric/Size/Mesquite_AWSizeNB1.cpp
  TargetMetric/Size/Mesquite_TSizeB1.cpp
  TargetMetric/Size/Mesquite_TSizeNB1.cpp
  TargetMetric/Size/Mesquite_TTau.cpp
  TargetMetric/Mesquite_TMetric.cpp
  TargetMetric/Mesquite_TMetricBarrier.cpp
  TargetMetric/Mesquite_TMetricNonBarrier.cpp
  TargetMetric/Untangle/Mesquite_AWUntangleBeta.cpp
  TargetMetric/Untangle/Mesquite_TUntangle1.cpp
  TargetMetric/Untangle/Mesquite_TUntangleBeta.cpp
  TargetMetric/Untangle/Mesquite_TUntangleMu.cpp
  Wrappers/Mesquite_DeformingDomainWrapper.cpp
  Wrappers/Mesquite_LaplaceWrapper.cpp
  Wrappers/Mesquite_PaverMinEdgeLengthWrapper.cpp
  Wrappers/Mesquite_ShapeImprovementWrapper.cpp
  Wrappers/Mesquite_ShapeImprover.cpp
  Wrappers/Mesquite_SizeAdaptShapeWrapper.cpp
  Wrappers/Mesquite_UntangleWrapper.cpp
  Wrappers/Mesquite_ViscousCFDTetShapeWrapper.cpp
  Wrappers/Mesquite_Wrapper.cpp
)


# Mesquite requires some defines to compile
# we set them in this CMakeLists.txt and pass them to 
# the parent CMakeLists.txt via PARENT_SCOPE

FUNCTION(PREPEND var prefix)
  SET(listVar "")
  FOREACH(f ${ARGN})
    LIST(APPEND listVar "${prefix}/${f}")
  ENDFOREACH(f)
  SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

#check for specific functions
include (CheckFunctionExists)
CHECK_FUNCTION_EXISTS(times     HAVE_TIMES)
CHECK_FUNCTION_EXISTS(clock     HAVE_CLOCK)
CHECK_FUNCTION_EXISTS(cbrt      HAVE_CBRT)
CHECK_FUNCTION_EXISTS(vsnprintf HAVE_VSNPRINTF)
CHECK_FUNCTION_EXISTS(vsprintf  HAVE_VSPRINTF)
CHECK_FUNCTION_EXISTS(finite    HAVE_FINITE)
CHECK_FUNCTION_EXISTS(_Isfinite HAVE__ISFINITE)

IF(NOT HAVE_TIMES AND NOT HAVE_CLOCK)
  MESSAGE( FATAL_ERROR
    "\n***"
    "\n*** ERROR: Neither the function times nor the function clock could be found. At least one of these needs to exist or Mesquite cannot build properly."
    "\n***\n"
    )
ENDIF()

#check for header files
include (CheckIncludeFile)
CHECK_INCLUDE_FILE(ieeefp.h    MSQ_HAVE_IEEEFP_H)
CHECK_INCLUDE_FILE(ieeefp.h    MSQ_HAVE_STDINT_H)
CHECK_INCLUDE_FILE(inttypes.h  MSQ_HAVE_INTTYPES_H)
CHECK_INCLUDE_FILE(termios.h   HAVE_TERMIOS_H)
CHECK_INCLUDE_FILE(sys/ioctl.h HAVE_SYS_IOCTL_H)
CHECK_INCLUDE_FILE(dlfcn.h     HAVE_DLFCN_H)
CHECK_INCLUDE_FILE(fcntl.h     HAVE_FCNTL_H)

MACRO(MESQUITE_APPEND_DEFINE DEFINE_LIST DEFINE_NAME)
  IF(${DEFINE_NAME})
    SET( ${DEFINE_LIST} "${${DEFINE_LIST}} -D${DEFINE_NAME}" )
  ENDIF()
ENDMACRO()

set(MESQUITE_DEFINES "")
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES MSQ_TRAP_FPE )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES MSQ_ENABLE_DEBUG )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES NDEBUG )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES MSQ_USE_FUNCTION_TIMERS )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_TIMES )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_CLOCK )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_CBRT )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_VSNPRINTF )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_VSPRINTF )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_FINITE )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE__ISFINITE )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_IEEEFP_H )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_INTTYPES_H )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_TERMIOS_H )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_SYS_IOCTL_H )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_DLFCN_H )
MESQUITE_APPEND_DEFINE( MESQUITE_DEFINES HAVE_FCNTL_H )
# Share the mesquite defines to apply with the parent scope
set(MESQUITE_DEFINES ${MESQUITE_DEFINES} PARENT_SCOPE)
PREPEND(MESQUITE_SRC_PATHES contrib/mesquite ${MESQUITE_SRC})
set(MESQUITE_SRC_PATHES ${MESQUITE_SRC_PATHES} PARENT_SCOPE)


file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/mesquite "${MESQUITE_SRC};${HDR}")



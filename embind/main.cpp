#include <emscripten/bind.h>
using namespace emscripten;

// BOPAlgo
#include "BOPAlgo_Alerts.hxx"
#include "BOPAlgo_Algo.hxx"
#include "BOPAlgo_ArgumentAnalyzer.hxx"
#include "BOPAlgo_BOP.hxx"
#include "BOPAlgo_BuilderArea.hxx"
#include "BOPAlgo_BuilderFace.hxx"
#include "BOPAlgo_Builder.hxx"
#include "BOPAlgo_BuilderShape.hxx"
#include "BOPAlgo_BuilderSolid.hxx"
#include "BOPAlgo_CellsBuilder.hxx"
#include "BOPAlgo_CheckerSI.hxx"
#include "BOPAlgo_CheckResult.hxx"
#include "BOPAlgo_CheckStatus.hxx"
#include "BOPAlgo_GlueEnum.hxx"
#include "BOPAlgo_ListOfCheckResult.hxx"
#include "BOPAlgo_MakeConnected.hxx"
#include "BOPAlgo_MakePeriodic.hxx"
#include "BOPAlgo_MakerVolume.hxx"
#include "BOPAlgo_Operation.hxx"
#include "BOPAlgo_Options.hxx"
#include "BOPAlgo_PArgumentAnalyzer.hxx"
#include "BOPAlgo_PaveFiller.hxx"
#include "BOPAlgo_PBOP.hxx"
#include "BOPAlgo_PBuilder.hxx"
#include "BOPAlgo_PPaveFiller.hxx"
#include "BOPAlgo_PSection.hxx"
#include "BOPAlgo_PWireEdgeSet.hxx"
#include "BOPAlgo_RemoveFeatures.hxx"
#include "BOPAlgo_SectionAttribute.hxx"
#include "BOPAlgo_Section.hxx"
#include "BOPAlgo_ShellSplitter.hxx"
#include "BOPAlgo_Splitter.hxx"
#include "BOPAlgo_Tools.hxx"
#include "BOPAlgo_ToolsProvider.hxx"
#include "BOPAlgo_WireEdgeSet.hxx"
#include "BOPAlgo_WireSplitter.hxx"

// BRep
#include "BRep_Builder.hxx"
#include "BRep_Curve3D.hxx"
#include "BRep_CurveOn2Surfaces.hxx"
#include "BRep_CurveOnClosedSurface.hxx"
#include "BRep_CurveOnSurface.hxx"
#include "BRep_CurveRepresentation.hxx"
#include "BRep_GCurve.hxx"
#include "BRep_ListIteratorOfListOfCurveRepresentation.hxx"
#include "BRep_ListIteratorOfListOfPointRepresentation.hxx"
#include "BRep_ListOfCurveRepresentation.hxx"
#include "BRep_ListOfPointRepresentation.hxx"
#include "BRep_PointOnCurve.hxx"
#include "BRep_PointOnCurveOnSurface.hxx"
#include "BRep_PointOnSurface.hxx"
#include "BRep_PointRepresentation.hxx"
#include "BRep_PointsOnSurface.hxx"
#include "BRep_Polygon3D.hxx"
#include "BRep_PolygonOnClosedSurface.hxx"
#include "BRep_PolygonOnClosedTriangulation.hxx"
#include "BRep_PolygonOnSurface.hxx"
#include "BRep_PolygonOnTriangulation.hxx"
#include "BRep_TEdge.hxx"
#include "BRep_TFace.hxx"
#include "BRep_Tool.hxx"
#include "BRep_TVertex.hxx"

// BRepAlgoAPI
#include "BRepAlgoAPI_Algo.hxx"
#include "BRepAlgoAPI_BooleanOperation.hxx"
#include "BRepAlgoAPI_BuilderAlgo.hxx"
#include "BRepAlgoAPI_Check.hxx"
#include "BRepAlgoAPI_Common.hxx"
#include "BRepAlgoAPI_Cut.hxx"
#include "BRepAlgoAPI_Defeaturing.hxx"
#include "BRepAlgoAPI_Fuse.hxx"
#include "BRepAlgoAPI_Section.hxx"
#include "BRepAlgoAPI_Splitter.hxx"

// BRepBuilderAPI
#include "BRepBuilderAPI_BndBoxTreeSelector.hxx"
#include "BRepBuilderAPI_CellFilter.hxx"
#include "BRepBuilderAPI_Collect.hxx"
#include "BRepBuilderAPI_Collect.hxx"
#include "BRepBuilderAPI_Command.hxx"
#include "BRepBuilderAPI_Command.hxx"
#include "BRepBuilderAPI_Copy.hxx"
#include "BRepBuilderAPI_Copy.hxx"
#include "BRepBuilderAPI.hxx"
#include "BRepBuilderAPI_EdgeError.hxx"
#include "BRepBuilderAPI_FaceError.hxx"
#include "BRepBuilderAPI_FastSewing.hxx"
#include "BRepBuilderAPI_FastSewing.hxx"
#include "BRepBuilderAPI_FindPlane.hxx"
#include "BRepBuilderAPI_FindPlane.hxx"
#include "BRepBuilderAPI_GTransform.hxx"
#include "BRepBuilderAPI_GTransform.hxx"
#include "BRepBuilderAPI.hxx"
#include "BRepBuilderAPI_MakeEdge2d.hxx"
#include "BRepBuilderAPI_MakeEdge2d.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_MakePolygon.hxx"
#include "BRepBuilderAPI_MakePolygon.hxx"
#include "BRepBuilderAPI_MakeShape.hxx"
#include "BRepBuilderAPI_MakeShape.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_ModifyShape.hxx"
#include "BRepBuilderAPI_ModifyShape.hxx"
#include "BRepBuilderAPI_NurbsConvert.hxx"
#include "BRepBuilderAPI_NurbsConvert.hxx"
#include "BRepBuilderAPI_PipeError.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_ShapeModification.hxx"
#include "BRepBuilderAPI_ShellError.hxx"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepBuilderAPI_TransitionMode.hxx"
#include "BRepBuilderAPI_VertexInspector.hxx"
#include "BRepBuilderAPI_WireError.hxx"

// BRepFilletAPI
#include "BRepFilletAPI_LocalOperation.hxx"
#include "BRepFilletAPI_MakeChamfer.hxx"
#include "BRepFilletAPI_MakeFillet2d.hxx"
#include "BRepFilletAPI_MakeFillet.hxx"

// BRepLib
#include "BRepLib_CheckCurveOnSurface.hxx"
#include "BRepLib_Command.hxx"
#include "BRepLib_EdgeError.hxx"
#include "BRepLib_FaceError.hxx"
#include "BRepLib_FindSurface.hxx"
#include "BRepLib_FuseEdges.hxx"
#include "BRepLib.hxx"
#include "BRepLib_MakeEdge2d.hxx"
#include "BRepLib_MakeEdge.hxx"
#include "BRepLib_MakeFace.hxx"
#include "BRepLib_MakePolygon.hxx"
#include "BRepLib_MakeShape.hxx"
#include "BRepLib_MakeShell.hxx"
#include "BRepLib_MakeSolid.hxx"
#include "BRepLib_MakeVertex.hxx"
#include "BRepLib_MakeWire.hxx"
#include "BRepLib_ShapeModification.hxx"
#include "BRepLib_ShellError.hxx"
#include "BRepLib_WireError.hxx"

// BRepOffsetAPI
#include "BRepOffsetAPI_DraftAngle.hxx"
#include "BRepOffsetAPI_FindContigousEdges.hxx"
#include "BRepOffsetAPI_MakeDraft.hxx"
#include "BRepOffsetAPI_MakeEvolved.hxx"
#include "BRepOffsetAPI_MakeFilling.hxx"
#include "BRepOffsetAPI_MakeOffset.hxx"
#include "BRepOffsetAPI_MakeOffsetShape.hxx"
#include "BRepOffsetAPI_MakePipe.hxx"
#include "BRepOffsetAPI_MakePipeShell.hxx"
#include "BRepOffsetAPI_MakeThickSolid.hxx"
#include "BRepOffsetAPI_MiddlePath.hxx"
#include "BRepOffsetAPI_NormalProjection.hxx"
#include "BRepOffsetAPI_SequenceOfSequenceOfReal.hxx"
#include "BRepOffsetAPI_SequenceOfSequenceOfShape.hxx"
#include "BRepOffsetAPI_Sewing.hxx"
#include "BRepOffsetAPI_ThruSections.hxx"

// BRepPrimAPI
#include "BRepPrimAPI_MakeBox.hxx"
#include "BRepPrimAPI_MakeCone.hxx"
#include "BRepPrimAPI_MakeCylinder.hxx"
#include "BRepPrimAPI_MakeHalfSpace.hxx"
#include "BRepPrimAPI_MakeOneAxis.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include "BRepPrimAPI_MakeRevol.hxx"
#include "BRepPrimAPI_MakeRevolution.hxx"
#include "BRepPrimAPI_MakeSphere.hxx"
#include "BRepPrimAPI_MakeSweep.hxx"
#include "BRepPrimAPI_MakeTorus.hxx"
#include "BRepPrimAPI_MakeWedge.hxx"

// GC
#include "GC_MakeArcOfCircle.hxx"
#include "GC_MakeArcOfEllipse.hxx"
#include "GC_MakeArcOfHyperbola.hxx"
#include "GC_MakeArcOfParabola.hxx"
#include "GC_MakeCircle.hxx"
#include "GC_MakeConicalSurface.hxx"
#include "GC_MakeCylindricalSurface.hxx"
#include "GC_MakeEllipse.hxx"
#include "GC_MakeHyperbola.hxx"
#include "GC_MakeLine.hxx"
#include "GC_MakeMirror.hxx"
#include "GC_MakePlane.hxx"
#include "GC_MakeRotation.hxx"
#include "GC_MakeScale.hxx"
#include "GC_MakeSegment.hxx"
#include "GC_MakeTranslation.hxx"
#include "GC_MakeTrimmedCone.hxx"
#include "GC_MakeTrimmedCylinder.hxx"
#include "GC_Root.hxx"

// GCE2d
#include "GCE2d_MakeArcOfCircle.hxx"
#include "GCE2d_MakeArcOfEllipse.hxx"
#include "GCE2d_MakeArcOfHyperbola.hxx"
#include "GCE2d_MakeArcOfParabola.hxx"
#include "GCE2d_MakeCircle.hxx"
#include "GCE2d_MakeEllipse.hxx"
#include "GCE2d_MakeHyperbola.hxx"
#include "GCE2d_MakeLine.hxx"
#include "GCE2d_MakeMirror.hxx"
#include "GCE2d_MakeParabola.hxx"
#include "GCE2d_MakeRotation.hxx"
#include "GCE2d_MakeScale.hxx"
#include "GCE2d_MakeSegment.hxx"
#include "GCE2d_MakeTranslation.hxx"
#include "GCE2d_Root.hxx"

// Geom
#include "Geom_Axis1Placement.hxx"
#include "Geom_Axis2Placement.hxx"
#include "Geom_AxisPlacement.hxx"
#include "Geom_BezierCurve.hxx"
#include "Geom_BezierSurface.hxx"
#include "Geom_BoundedCurve.hxx"
#include "Geom_BoundedSurface.hxx"
#include "Geom_BSplineCurve.hxx"
#include "Geom_BSplineSurface.hxx"
#include "Geom_CartesianPoint.hxx"
#include "Geom_Circle.hxx"
#include "Geom_ConicalSurface.hxx"
#include "Geom_Conic.hxx"
#include "Geom_Curve.hxx"
#include "Geom_CylindricalSurface.hxx"
#include "Geom_Direction.hxx"
#include "Geom_ElementarySurface.hxx"
#include "Geom_Ellipse.hxx"
#include "Geom_Geometry.hxx"
#include "Geom_HSequenceOfBSplineSurface.hxx"
#include "Geom_Hyperbola.hxx"
#include "Geom_Line.hxx"
#include "Geom_OffsetCurve.hxx"
#include "Geom_OffsetSurface.hxx"
#include "Geom_OsculatingSurface.hxx"
#include "Geom_Parabola.hxx"
#include "Geom_Plane.hxx"
#include "Geom_Point.hxx"
#include "Geom_RectangularTrimmedSurface.hxx"
#include "Geom_SequenceOfBSplineSurface.hxx"
#include "Geom_SphericalSurface.hxx"
#include "Geom_Surface.hxx"
#include "Geom_SurfaceOfLinearExtrusion.hxx"
#include "Geom_SurfaceOfRevolution.hxx"
#include "Geom_SweptSurface.hxx"
#include "Geom_ToroidalSurface.hxx"
#include "Geom_Transformation.hxx"
#include "Geom_TrimmedCurve.hxx"
#include "Geom_UndefinedDerivative.hxx"
#include "Geom_UndefinedValue.hxx"
#include "Geom_Vector.hxx"
#include "Geom_VectorWithMagnitude.hxx"

// Geom2d
#include "Geom2d_AxisPlacement.hxx"
#include "Geom2d_BezierCurve.hxx"
#include "Geom2d_BoundedCurve.hxx"
#include "Geom2d_BSplineCurve.hxx"
#include "Geom2d_CartesianPoint.hxx"
#include "Geom2d_Circle.hxx"
#include "Geom2d_Conic.hxx"
#include "Geom2d_Curve.hxx"
#include "Geom2d_Direction.hxx"
#include "Geom2d_Ellipse.hxx"
#include "Geom2d_Geometry.hxx"
#include "Geom2d_Hyperbola.hxx"
#include "Geom2d_Line.hxx"
#include "Geom2d_OffsetCurve.hxx"
#include "Geom2d_Parabola.hxx"
#include "Geom2d_Point.hxx"
#include "Geom2d_Transformation.hxx"
#include "Geom2d_TrimmedCurve.hxx"
#include "Geom2d_UndefinedDerivative.hxx"
#include "Geom2d_UndefinedValue.hxx"
#include "Geom2d_Vector.hxx"
#include "Geom2d_VectorWithMagnitude.hxx"

// gp
#include "gp_Ax1.hxx"
#include "gp_Ax22d.hxx"
#include "gp_Ax2d.hxx"
#include "gp_Ax2.hxx"
#include "gp_Ax3.hxx"
#include "gp_Circ2d.hxx"
#include "gp_Circ.hxx"
#include "gp_Cone.hxx"
#include "gp_Cylinder.hxx"
#include "gp_Dir2d.hxx"
#include "gp_Dir.hxx"
#include "gp_Elips2d.hxx"
#include "gp_Elips.hxx"
#include "gp_EulerSequence.hxx"
#include "gp_GTrsf2d.hxx"
#include "gp_GTrsf.hxx"
#include "gp.hxx"
#include "gp_Hypr2d.hxx"
#include "gp_Hypr.hxx"
#include "gp_Lin2d.hxx"
#include "gp_Lin.hxx"
#include "gp_Mat2d.hxx"
#include "gp_Mat.hxx"
#include "gp_Parab2d.hxx"
#include "gp_Parab.hxx"
#include "gp_Pln.hxx"
#include "gp_Pnt2d.hxx"
#include "gp_Pnt.hxx"
#include "gp_Quaternion.hxx"
#include "gp_QuaternionNLerp.hxx"
#include "gp_QuaternionSLerp.hxx"
#include "gp_Sphere.hxx"
#include "gp_Torus.hxx"
#include "gp_Trsf2d.hxx"
#include "gp_TrsfForm.hxx"
#include "gp_Trsf.hxx"
#include "gp_TrsfNLerp.hxx"
#include "gp_Vec2d.hxx"
#include "gp_Vec.hxx"
#include "gp_VectorWithNullMagnitude.hxx"
#include "gp_XY.hxx"
#include "gp_XYZ.hxx"

// IGESControl
#include "IGESControl_ActorWrite.hxx"
#include "IGESControl_AlgoContainer.hxx"
#include "IGESControl_Controller.hxx"
#include "IGESControl_IGESBoundary.hxx"
#include "IGESControl_Reader.hxx"
#include "IGESControl_ToolContainer.hxx"
#include "IGESControl_Writer.hxx"

// STEPControl
#include "STEPControl_ActorRead.hxx"
#include "STEPControl_ActorWrite.hxx"
#include "STEPControl_Controller.hxx"
#include "STEPControl_Reader.hxx"
#include "STEPControl_StepModelType.hxx"
#include "STEPControl_Writer.hxx"

// TopExp
#include "TopExp_Explorer.hxx"
#include "TopExp.hxx"
#include "TopExp_Stack.hxx"

// TopoDS
#include "TopoDS_AlertWithShape.hxx"
#include "TopoDS_Builder.hxx"
#include "TopoDS_Compound.hxx"
#include "TopoDS_CompSolid.hxx"
#include "TopoDS_Edge.hxx"
#include "TopoDS_Face.hxx"
#include "TopoDS_FrozenShape.hxx"
#include "TopoDS_HShape.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Iterator.hxx"
#include "TopoDS_ListIteratorOfListOfShape.hxx"
#include "TopoDS_ListOfShape.hxx"
#include "TopoDS_LockedShape.hxx"
#include "TopoDS_Shape.hxx"
#include "TopoDS_Shell.hxx"
#include "TopoDS_Solid.hxx"
#include "TopoDS_TCompound.hxx"
#include "TopoDS_TCompSolid.hxx"
#include "TopoDS_TEdge.hxx"
#include "TopoDS_TFace.hxx"
#include "TopoDS_TShape.hxx"
#include "TopoDS_TShell.hxx"
#include "TopoDS_TSolid.hxx"
#include "TopoDS_TVertex.hxx"
#include "TopoDS_TWire.hxx"
#include "TopoDS_UnCompatibleShapes.hxx"
#include "TopoDS_Vertex.hxx"
#include "TopoDS_Wire.hxx"

// TopTools
#include "TopTools_Array1OfListOfShape.hxx"
#include "TopTools_Array1OfShape.hxx"
#include "TopTools_Array2OfShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfIntegerShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfOrientedShapeInteger.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfOrientedShapeShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeInteger.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeListOfInteger.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeListOfShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeReal.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeSequenceOfShape.hxx"
#include "TopTools_DataMapIteratorOfDataMapOfShapeShape.hxx"
#include "TopTools_DataMapOfIntegerListOfShape.hxx"
#include "TopTools_DataMapOfIntegerShape.hxx"
#include "TopTools_DataMapOfOrientedShapeInteger.hxx"
#include "TopTools_DataMapOfOrientedShapeShape.hxx"
#include "TopTools_DataMapOfShapeBox.hxx"
#include "TopTools_DataMapOfShapeInteger.hxx"
#include "TopTools_DataMapOfShapeListOfInteger.hxx"
#include "TopTools_DataMapOfShapeListOfShape.hxx"
#include "TopTools_DataMapOfShapeReal.hxx"
#include "TopTools_DataMapOfShapeSequenceOfShape.hxx"
#include "TopTools_DataMapOfShapeShape.hxx"
#include "TopTools_HArray1OfListOfShape.hxx"
#include "TopTools_HArray1OfShape.hxx"
#include "TopTools_HArray2OfShape.hxx"
#include "TopTools_HSequenceOfShape.hxx"
#include "TopTools.hxx"
#include "TopTools_IndexedDataMapOfShapeAddress.hxx"
#include "TopTools_IndexedDataMapOfShapeListOfShape.hxx"
#include "TopTools_IndexedDataMapOfShapeReal.hxx"
#include "TopTools_IndexedDataMapOfShapeShape.hxx"
#include "TopTools_IndexedMapOfOrientedShape.hxx"
#include "TopTools_IndexedMapOfShape.hxx"
#include "TopTools_ListIteratorOfListOfShape.hxx"
#include "TopTools_ListOfListOfShape.hxx"
#include "TopTools_ListOfShape.hxx"
#include "TopTools_LocationSet.hxx"
#include "TopTools_LocationSetPtr.hxx"
#include "TopTools_MapIteratorOfMapOfOrientedShape.hxx"
#include "TopTools_MapIteratorOfMapOfShape.hxx"
#include "TopTools_MapOfOrientedShape.hxx"
#include "TopTools_MapOfShape.hxx"
#include "TopTools_MutexForShapeProvider.hxx"
#include "TopTools_OrientedShapeMapHasher.hxx"
#include "TopTools_SequenceOfShape.hxx"
#include "TopTools_ShapeMapHasher.hxx"
#include "TopTools_ShapeSet.hxx"

#include "BRepBuilderAPI/BRepBuilderAPI_MakeEdge.hxx"
#include "BRepPrimAPI/BRepPrimAPI_MakeTorus.hxx"
#include "GC/GC_MakeArcOfCircle.hxx"
#include "GC/GC_MakeSegment.hxx"

#define Standard_EXPORT
#define Standard_NODISCARD
#define DEFINE_STANDARD_ALLOC

#define really_unparen(...) __VA_ARGS__
#define invoke(expr) expr
#define unparen(args) invoke(really_unparen args)

#define overloadedConstructor(baseClass, overloadedClass, parameterFull, parameterNames, parameterTypes) \
  struct overloadedClass : public baseClass { \
    overloadedClass(unparen(parameterFull)) : baseClass(unparen(parameterNames)) {} \
  }; \
  class_<overloadedClass, base<baseClass>>(#overloadedClass) \
    .constructor<unparen(parameterTypes)>();

EMSCRIPTEN_BINDINGS(opencascadejs) {
  #include "./BRep.h"
  #include "./BRepAlgoAPI.h"
  #include "./BRepBuilderAPI.h"
  #include "./BRepFilletAPI.h"
  #include "./BRepLib.h"
  #include "./BRepOffsetAPI.h"
  #include "./BRepPrimAPI.h"
  #include "./GC.h"
  #include "./GCE2d.h"
  #include "./Geom.h"
  #include "./Geom2d.h"
  #include "./gp.h"
  #include "./IGESControl.h"
  #include "./STEPControl.h"
  #include "./TopExp.h"
  #include "./TopoDS.h"
  #include "./TopTools.h"
}

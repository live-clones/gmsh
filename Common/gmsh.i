%module gmsh

// handle gracefully the arguments of gmshInitialize
%include argcargv.i
%apply (int ARGC, char **ARGV) { (int argc, char **argv) }

%{
  #include "gmsh.h"
%}

%include std_string.i
%include std_vector.i
%include std_pair.i

%template() std::pair<int, int>;
%template(IntVector) std::vector<int>;
%template(IntVectorVector) std::vector<std::vector<int> >;
%template(DoubleVector) std::vector<double>;
%template(DoubleVectorVector) std::vector<std::vector<double> >;
%template(StringVector) std::vector<std::string>;
%template(PairVector) std::vector<std::pair<int, int> >;
%template(PairVectorVector) std::vector<std::vector<std::pair<int, int> > >;

%rename(initialize)                         gmsh::initialize;
%rename(finalize)                           gmsh::finalize;
%rename(open)                               gmsh::open;
%rename(merge)                              gmsh::merge;
%rename(write)                              gmsh::write;
%rename(clear)                              gmsh::clear;
%rename(optionSetNumber)                    gmsh::option::setNumber;
%rename(optionGetNumber)                    gmsh::option::getNumber;
%rename(optionSetString)                    gmsh::option::setString;
%rename(optionGetString)                    gmsh::option::getString;
%rename(modelAdd)                           gmsh::model::add;
%rename(modelRemove)                        gmsh::model::remove;
%rename(modelList)                          gmsh::model::list;
%rename(modelSetCurrent)                    gmsh::model::setCurrent;
%rename(modelGetEntities)                   gmsh::model::getEntities;
%rename(modelGetPhysicalGroups)             gmsh::model::getPhysicalGroups;
%rename(modelGetEntitiesForPhysicalGroup)   gmsh::model::getEntitiesForPhysicalGroup;
%rename(modelAddPhysicalGroup)              gmsh::model::addPhysicalGroup;
%rename(modelSetPhysicalName)               gmsh::model::setPhysicalName;
%rename(modelGetPhysicalName)               gmsh::model::getPhysicalName;
%rename(modelGetBoundary)                   gmsh::model::getBoundary;
%rename(modelGetEntitiesInBoundingBox)      gmsh::model::getEntitiesInBoundingBox;
%rename(modelGetBoundingBox)                gmsh::model::getBoundingBox;
%rename(modelAddDiscreteEntity)             gmsh::model::addDiscreteEntity;
%rename(modelRemoveEntities)                gmsh::model::removeEntities;
%rename(modelMeshGenerate)                  gmsh::model::mesh::generate;
%rename(modelMeshGetLastEntityError)        gmsh::model::mesh::getLastEntityError;
%rename(modelMeshGetLastVertexError)        gmsh::model::mesh::getLastVertexError;
%rename(modelMeshGetVertices)               gmsh::model::mesh::getVertices;
%rename(modelMeshGetElements)               gmsh::model::mesh::getElements;
%rename(modelMeshSetVertices)               gmsh::model::mesh::setVertices;
%rename(modelMeshSetElements)               gmsh::model::mesh::setElements;
%rename(modelMeshGetVertex)                 gmsh::model::mesh::getVertex;
%rename(modelMeshGetElement)                gmsh::model::mesh::getElement;
%rename(modelMeshSetSize)                   gmsh::model::mesh::setSize;
%rename(modelMeshSetTransfiniteLine)        gmsh::model::mesh::setTransfiniteLine;
%rename(modelMeshSetTransfiniteSurface)     gmsh::model::mesh::setTransfiniteSurface;
%rename(modelMeshSetTransfiniteVolume)      gmsh::model::mesh::setTransfiniteVolume;
%rename(modelMeshSetRecombine)              gmsh::model::mesh::setRecombine;
%rename(modelMeshSetSmoothing)              gmsh::model::mesh::setSmoothing;
%rename(modelMeshSetReverse)                gmsh::model::mesh::setReverse;
%rename(modelMeshEmbed)                     gmsh::model::mesh::embed;
%rename(modelMeshFieldAdd)                  gmsh::model::mesh::field::add;
%rename(modelMeshFieldRemove)               gmsh::model::mesh::field::remove;
%rename(modelMeshFieldSetNumber)            gmsh::model::mesh::field::setNumber;
%rename(modelMeshFieldSetString)            gmsh::model::mesh::field::setString;
%rename(modelMeshFieldSetNumbers)           gmsh::model::mesh::field::setNumbers;
%rename(modelMeshFieldSetAsBackground)      gmsh::model::mesh::field::setAsBackground;
%rename(modelGeoAddPoint)                   gmsh::model::geo::addPoint;
%rename(modelGeoAddLine)                    gmsh::model::geo::addLine;
%rename(modelGeoAddCircleArc)               gmsh::model::geo::addCircleArc;
%rename(modelGeoAddEllipseArc)              gmsh::model::geo::addEllipseArc;
%rename(modelGeoAddSpline)                  gmsh::model::geo::addSpline;
%rename(modelGeoAddBSpline)                 gmsh::model::geo::addBSpline;
%rename(modelGeoAddBezier)                  gmsh::model::geo::addBezier;
%rename(modelGeoAddLineLoop)                gmsh::model::geo::addLineLoop;
%rename(modelGeoAddPlaneSurface)            gmsh::model::geo::addPlaneSurface;
%rename(modelGeoAddSurfaceFilling)          gmsh::model::geo::addSurfaceFilling;
%rename(modelGeoAddSurfaceLoop)             gmsh::model::geo::addSurfaceLoop;
%rename(modelGeoAddVolume)                  gmsh::model::geo::addVolume;
%rename(modelGeoExtrude)                    gmsh::model::geo::extrude;
%rename(modelGeoRevolve)                    gmsh::model::geo::revolve;
%rename(modelGeoTwist)                      gmsh::model::geo::twist;
%rename(modelGeoTranslate)                  gmsh::model::geo::translate;
%rename(modelGeoRotate)                     gmsh::model::geo::rotate;
%rename(modelGeoDilate)                     gmsh::model::geo::dilate;
%rename(modelGeoSymmetry)                   gmsh::model::geo::symmetry;
%rename(modelGeoCopy)                       gmsh::model::geo::copy;
%rename(modelGeoRemove)                     gmsh::model::geo::remove;
%rename(modelGeoRemoveAllDuplicates)        gmsh::model::geo::removeAllDuplicates;
%rename(modelGeoSynchronize)                gmsh::model::geo::synchronize;
%rename(modelGeoMeshSetTransfiniteLine)     gmsh::model::geo::mesh::setTransfiniteLine;
%rename(modelGeoMeshSetTransfiniteSurface)  gmsh::model::geo::mesh::setTransfiniteSurface;
%rename(modelGeoMeshSetTransfiniteVolume)   gmsh::model::geo::mesh::setTransfiniteVolume;
%rename(modelGeoMeshSetRecombine)           gmsh::model::geo::mesh::setRecombine;
%rename(modelGeoMeshSetSmoothing)           gmsh::model::geo::mesh::setSmoothing;
%rename(modelGeoMeshSetReverse)             gmsh::model::geo::mesh::setReverse;
%rename(modelGeoMeshSetSize)                gmsh::model::geo::mesh::setSize;
%rename(modelOccAddPoint)                   gmsh::model::occ::addPoint;
%rename(modelOccAddLine)                    gmsh::model::occ::addLine;
%rename(modelOccAddCircleArc)               gmsh::model::occ::addCircleArc;
%rename(modelOccAddCircle)                  gmsh::model::occ::addCircle;
%rename(modelOccAddEllipseArc)              gmsh::model::occ::addEllipseArc;
%rename(modelOccAddEllipse)                 gmsh::model::occ::addEllipse;
%rename(modelOccAddSpline)                  gmsh::model::occ::addSpline;
%rename(modelOccAddBezier)                  gmsh::model::occ::addBezier;
%rename(modelOccAddBSpline)                 gmsh::model::occ::addBSpline;
%rename(modelOccAddWire)                    gmsh::model::occ::addWire;
%rename(modelOccAddLineLoop)                gmsh::model::occ::addLineLoop;
%rename(modelOccAddRectangle)               gmsh::model::occ::addRectangle;
%rename(modelOccAddDisk)                    gmsh::model::occ::addDisk;
%rename(modelOccAddPlaneSurface)            gmsh::model::occ::addPlaneSurface;
%rename(modelOccAddSurfaceFilling)          gmsh::model::occ::addSurfaceFilling;
%rename(modelOccAddSurfaceLoop)             gmsh::model::occ::addSurfaceLoop;
%rename(modelOccAddVolume)                  gmsh::model::occ::addVolume;
%rename(modelOccAddSphere)                  gmsh::model::occ::addSphere;
%rename(modelOccAddBox)                     gmsh::model::occ::addBox;
%rename(modelOccAddCylinder)                gmsh::model::occ::addCylinder;
%rename(modelOccAddCone)                    gmsh::model::occ::addCone;
%rename(modelOccAddWedge)                   gmsh::model::occ::addWedge;
%rename(modelOccAddTorus)                   gmsh::model::occ::addTorus;
%rename(modelOccAddThruSections)            gmsh::model::occ::addThruSections;
%rename(modelOccAddThickSolid)              gmsh::model::occ::addThickSolid;
%rename(modelOccExtrude)                    gmsh::model::occ::extrude;
%rename(modelOccRevolve)                    gmsh::model::occ::revolve;
%rename(modelOccAddPipe)                    gmsh::model::occ::addPipe;
%rename(modelOccFillet)                     gmsh::model::occ::fillet;
%rename(modelOccBooleanUnion)               gmsh::model::occ::booleanUnion;
%rename(modelOccBooleanIntersection)        gmsh::model::occ::booleanIntersection;
%rename(modelOccBooleanDifference)          gmsh::model::occ::booleanDifference;
%rename(modelOccBooleanFragments)           gmsh::model::occ::booleanFragments;
%rename(modelOccTranslate)                  gmsh::model::occ::translate;
%rename(modelOccRotate)                     gmsh::model::occ::rotate;
%rename(modelOccDilate)                     gmsh::model::occ::dilate;
%rename(modelOccSymmetry)                   gmsh::model::occ::symmetry;
%rename(modelOccCopy)                       gmsh::model::occ::copy;
%rename(modelOccRemove)                     gmsh::model::occ::remove;
%rename(modelOccRemoveAllDuplicates)        gmsh::model::occ::removeAllDuplicates;
%rename(modelOccImportShapes)               gmsh::model::occ::importShapes;
%rename(modelOccSetMeshSize)                gmsh::model::occ::setMeshSize;
%rename(modelOccSynchronize)                gmsh::model::occ::synchronize;
%rename(viewAdd)                            gmsh::view::add;
%rename(viewRemove)                         gmsh::view::remove;
%rename(viewGetIndex)                       gmsh::view::getIndex;
%rename(viewGetTags)                        gmsh::view::getTags;
%rename(viewAddModelData)                   gmsh::view::addModelData;
%rename(viewAddListData)                    gmsh::view::addListData;
%rename(viewProbe)                          gmsh::view::probe;
%rename(viewWrite)                          gmsh::view::write;
%rename(pluginSetNumber)                    gmsh::plugin::setNumber;
%rename(pluginSetString)                    gmsh::plugin::setString;
%rename(pluginRun)                          gmsh::plugin::run;

%include "gmsh.h"

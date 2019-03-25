 /**
 * Project : Java Wrapping of Gmsh
 * Copyright : see Gmsh Copyright
 * License : see Gmsh License
 * Contrat number : internal Artenum development
 * Developed by: Artenum SARL
 * Creation : august 2011
 * authors : Benjamin JEANTY-RUARD - Artenum
 * Status : final
 */

package com.artenum.sample;

import org.geuz.gmsh.generated.EdgeVector;
import org.geuz.gmsh.generated.EdgeVectorOfVector;
import org.geuz.gmsh.generated.FaceVector;
import org.geuz.gmsh.generated.FaceVectorOfVector;
import org.geuz.gmsh.generated.GEdge;
import org.geuz.gmsh.generated.GEntity;
import org.geuz.gmsh.generated.GEntityVector;
import org.geuz.gmsh.generated.GFace;
import org.geuz.gmsh.generated.GModel;
import org.geuz.gmsh.generated.GRegion;
import org.geuz.gmsh.generated.GVertex;
import org.geuz.gmsh.generated.GVertexVector;
import org.geuz.gmsh.generated.IntVector;
import org.geuz.gmsh.generated.List_T;
import org.geuz.gmsh.generated.MLine;
import org.geuz.gmsh.generated.MPoint;
import org.geuz.gmsh.generated.MTetrahedron;
import org.geuz.gmsh.generated.MTriangle;
import org.geuz.gmsh.generated.RegionVector;
import org.geuz.gmsh.generated.WrapGmsh;

/**
 * This class is an example of use of Gmsh wrapping in Java.
 *
 * @author benjamin jeanty-ruard
 *
 */
public class EssaiGmsh_v1 {

    static {
        try {
            System.loadLibrary("WrapGmsh");
        } catch (final UnsatisfiedLinkError e) {
            System.err
                    .println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n"
                            + e);
            System.exit(1);
        }

    }

    public static void main(final String[] args) {

        // initialization of gmsh
        WrapGmsh.GmshInitialize(0, null);

        final GModel m = buildGeometry();

        export(m);

        accessElement(m);

        m.deleteMesh();
        m.delete();

        WrapGmsh.GmshFinalize();

    }

    /**
     * Shows methods used to access to different mesh elements.
     *
     * @param m
     *            is the GModel where the mesh is stored.
     */
    private static void accessElement(final GModel m) {
        // read mesh elements produced by m.mesh(3)
        System.out.println("$MeshFormat");
        System.out.println("2.2 0 8");
        System.out.println("$EndMeshFormat");
        System.out.println("$Nodes");
        // boolean which indicates if all elements are meshed
        final boolean all = m.noPhysicalGroups();
        System.out.println(m.indexMeshVertices(all, 0));

        final GEntityVector entities = new GEntityVector();
        m.getEntities(entities);
        for (int i = 0; i < entities.size(); i++) {
            for (int j = 0; j < entities.get(i).getMesh_vertices().size(); j++) {
                final int index = entities.get(i).getMesh_vertices().get(j).getIndex();

                // if index <0 then there is not physical
                if (index >= 0) {
                    final double x = entities.get(i).getMesh_vertices().get(j).x();
                    final double y = entities.get(i).getMesh_vertices().get(j).y();
                    final double z = entities.get(i).getMesh_vertices().get(j).z();

                    System.out.println(index + " " + x + " " + y + " " + z);

                }

            }
        }

        System.out.println("$EndNodes");
        System.out.println("$Elements");

        int iter = 1;

        // point
        final GVertexVector bindingsGetVertices = m.bindingsGetVertices();
        for (int indexVertex = 0; indexVertex < bindingsGetVertices.size(); indexVertex++) {
            final GVertex it = bindingsGetVertices.get(indexVertex);
            for (int k = 0; k < it.getPoints().size(); k++) {
                for (int j = 0; j < it.getPhysicals().size(); j++) {
                    final int physical = it.getPhysicals().get(j);

                    final MPoint mPt = it.getPoints().get(k);

                    final int type = mPt.getTypeForMSH();

                    final IntVector verts = new IntVector();

                    mPt.getVerticesIdForMSH(verts);

                    // 1 is the number of physical which is associated with the
                    // element.
                    // there is always 1 but it is possible to write several
                    // times the same line but with a different physical. This
                    // is the logical used by gmsh but in reality it is 2
                    // because there is the physical AND the elemnentary. For
                    // more information see the gmsh documentation
                    System.out.println(iter + " " + type + " 1 " + physical + " " + verts.get(0));

                    iter++;
                }
            }
        }

        // edges

        final EdgeVector bindingsGetEdges = m.bindingsGetEdges();
        for (int indexEdges = 0; indexEdges < bindingsGetEdges.size(); indexEdges++) {
            final GEdge it = bindingsGetEdges.get(indexEdges);
            for (int j = 0; j < it.getLines().size(); j++) {
                for (int k = 0; k < it.getPhysicals().size(); k++) {
                    final int physical = it.getPhysicals().get(k);

                    final MLine mLine = it.getLines().get(j);

                    final int type = mLine.getTypeForMSH();

                    final IntVector verts = new IntVector();

                    mLine.getVerticesIdForMSH(verts);
                    System.out.println(iter + " " + type + " 1 " + physical + " " + verts.get(0) + " " + verts.get(1));

                    iter++;
                }
            }
        }

        // triangles

        final FaceVector bindingsGetFaces = m.bindingsGetFaces();
        for (int indexFace = 0; indexFace < bindingsGetFaces.size(); indexFace++) {
            final GFace it = bindingsGetFaces.get(indexFace);
            for (int j = 0; j < it.getTriangles().size(); j++) {
                for (int k = 0; k < it.getPhysicals().size(); k++) {
                    final int physical = it.getPhysicals().get(k);

                    final MTriangle mTriangle = it.getTriangles().get(j);

                    final int type = mTriangle.getTypeForMSH();
                    final IntVector verts = new IntVector();
                    mTriangle.getVerticesIdForMSH(verts);
                    System.out.println(iter + " " + type + " 1 " + physical + " " + verts.get(0) + " " + verts.get(1)
                            + " " + verts.get(2));

                    iter++;

                }
            }
        }

        // tetrahedron

        final RegionVector bindingsGetRegions = m.bindingsGetRegions();

        for (int indexRegion = 0; indexRegion < bindingsGetRegions.size(); indexRegion++) {
            final GRegion it = bindingsGetRegions.get(indexRegion);
            for (int j = 0; j < it.getTetrahedra().size(); j++) {
                for (int k = 0; k < it.getPhysicals().size(); k++) {
                    final int physical = it.getPhysicals().get(k);

                    final MTetrahedron mTetrahedron = it.getTetrahedra().get(j);

                    final int type = mTetrahedron.getTypeForMSH();

                    final IntVector verts = new IntVector();
                    mTetrahedron.getVerticesIdForMSH(verts);
                    System.out.println(iter + " " + type + " 1 " + physical + " " + verts.get(0) + " " + verts.get(1)
                            + " " + verts.get(2) + " " + verts.get(3));

                    iter++;
                }
            }
        }
        System.out.println("$EndElements");
    }

    /**
     * This method export a geometry file, mesh it and export the generated mesh in gmsh file.
     *
     * @param m
     *            is the GModel where is stored the geometry and the mesh.
     */
    private static void export(final GModel m) {
        // write .geo file which contains the geomtry defined before
        m.writeGEO("test.geo");

        // mesh the geometry defined in the GModel m
        m.mesh(3);

        // write .msh file which contains informations about mesh in GModel m.
        m.writeMSH("meshtest.msh");
    }

    /**
     * Build a geometry and stores it in a GModel.
     *
     * @return a GModel which is a Gmsh object where is stored the geometry.
     */
    private static GModel buildGeometry() {
        // creation of GModel which stores all geometric elements and all mesh
        // elements
        final GModel m = new GModel();

        return m;
    }
}

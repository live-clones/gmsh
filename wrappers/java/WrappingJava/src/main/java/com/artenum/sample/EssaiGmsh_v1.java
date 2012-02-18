package com.artenum.sample;

import org.geuz.gmsh.generated.EdgeVector;
import org.geuz.gmsh.generated.EdgeVectorOfVector;
import org.geuz.gmsh.generated.FaceVector;
import org.geuz.gmsh.generated.FaceVectorOfVector;
import org.geuz.gmsh.generated.GEdge;
import org.geuz.gmsh.generated.GEntityVector;
import org.geuz.gmsh.generated.GFace;
import org.geuz.gmsh.generated.GModel;
import org.geuz.gmsh.generated.GRegion;
import org.geuz.gmsh.generated.GVertex;
import org.geuz.gmsh.generated.GVertexVector;
import org.geuz.gmsh.generated.GeoFactory;
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
                    .println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n" + e);
            System.exit(1);
        }
        
    }
    
    public static void main(final String[] args) {
        
        // initialization of gmsh
        WrapGmsh.GmshInitialize(0, null);
        
        // creation of GModel which stores all geometric elements and all mesh
        // elements
        final GModel m = new GModel();
        
        // creation of List which are used to define "physical property" for
        // some elements
        final List_T lst1 = WrapGmsh.List_Create(5, 5, 4);
        final List_T lst2 = WrapGmsh.List_Create(5, 5, 4);
        final List_T lst3 = WrapGmsh.List_Create(5, 5, 4);
        final List_T lst4 = WrapGmsh.List_Create(5, 5, 4);
        
        // outside tetrahedron
        
        final double x1 = 1.0;// x coordinate of first point
        final double y1 = 0.0;// y coordinate of first point
        final double z1 = 0.0;// z coordinate of first point
        
        final double lc1 = 0.05;// define mesh precision
        
        final double x2 = 0.0;
        final double y2 = 1.0;
        final double z2 = 0.0;
        
        final double lc2 = 0.05;
        
        final double x3 = 0.0;
        final double y3 = 0.0;
        final double z3 = 0.0;
        
        final double lc3 = 0.05;
        
        final double x4 = 0.0;
        final double y4 = 0.0;
        final double z4 = 1.0;
        
        final double lc4 = 0.05;
        
        // inside tetrahedron
        
        final double x5 = 0.9;
        final double y5 = 0.025;
        final double z5 = 0.025;
        
        final double lc5 = 0.05;
        
        final double x6 = 0.025;
        final double y6 = 0.9;
        final double z6 = 0.025;
        
        final double lc6 = 0.05;
        
        final double x7 = 0.025;
        final double y7 = 0.025;
        final double z7 = 0.025;
        
        final double lc7 = 0.05;
        
        final double x8 = 0.025;
        final double y8 = 0.025;
        final double z8 = 0.9;
        
        final double lc8 = 0.05;
        
        // hole between outside tetrahedron and inside tetrahedron
        
        final double x9 = 0.1;
        final double y9 = 0.0;
        final double z9 = 0.1;
        
        final double lc9 = 0.05;
        
        final double x10 = 0.4;
        final double y10 = 0.0;
        final double z10 = 0.1;
        
        final double lc10 = 0.01;
        
        final double x11 = 0.4;
        final double y11 = 0.0;
        final double z11 = 0.4;
        
        final double lc11 = 0.01;
        
        final double x12 = 0.1;
        final double y12 = 0.0;
        final double z12 = 0.4;
        
        final double lc12 = 0.01;
        
        final double x13 = 0.1;
        final double y13 = 0.025;
        final double z13 = 0.1;
        
        final double lc13 = 0.01;
        
        final double x14 = 0.4;
        final double y14 = 0.025;
        final double z14 = 0.1;
        
        final double lc14 = 0.01;
        
        final double x15 = 0.4;
        final double y15 = 0.025;
        final double z15 = 0.4;
        
        final double lc15 = 0.01;
        
        final double x16 = 0.1;
        final double y16 = 0.025;
        final double z16 = 0.4;
        
        final double lc16 = 0.01;
        
        // curved tetrahedron
        
        final double x17 = 0.0;
        final double y17 = 0.0;
        final double z17 = -2.0;
        
        final double lc17 = 0.1;
        
        final double x18 = 1.0;
        final double y18 = 0.0;
        final double z18 = -1.0;
        
        final double lc18 = 0.1;
        
        final double x19 = 0.0;
        final double y19 = 1.0;
        final double z19 = -1.0;
        
        final double lc19 = 0.1;
        
        final double x20 = 0.0;
        final double y20 = 0.0;
        final double z20 = -1.0;
        
        final double lc20 = 0.1;
        
        // inside sphere
        
        final double x21 = 0.7;
        final double y21 = 0.354;
        final double z21 = -1.354;
        
        final double lc21 = 0.1;
        
        final double x22 = 0.354;
        final double y22 = 0.008;
        final double z22 = -1.354;
        
        final double lc22 = 0.1;
        
        final double x23 = 0.008;
        final double y23 = 0.354;
        final double z23 = -1.354;
        
        final double lc23 = 0.1;
        
        final double x24 = 0.354;
        final double y24 = 0.7;
        final double z24 = -1.354;
        
        final double lc24 = 0.1;
        
        final double x25 = 0.354;
        final double y25 = 0.354;
        final double z25 = -1.008;
        
        final double lc25 = 0.1;
        
        final double x26 = 0.354;
        final double y26 = 0.354;
        final double z26 = -1.7;
        
        final double lc26 = 0.1;
        
        final double x27 = 0.354;
        final double y27 = 0.354;
        final double z27 = -1.354;
        
        final double lc27 = 0.1;
        
        // -----------------------------------------------------------------------//
        // declaration of variables
        // -----------------------------------------------------------------------//
        // variable used to define physical property of some elements (vertex,
        // edge, ...)
        int tag;
        
        // string used to define physical of some elements. It can be equal to
        // "Point", "Line", "Surface" or "Volume"
        final String str = "Point";
        final String str1 = "Line";
        final String str2 = "Surface";
        final String str3 = "Volume";
        
        // creation of GeoFactory used to create vertices, edges, faces, ...
        final GeoFactory gFact = new GeoFactory();
        
        // GVertex of outside tetrahedron
        GVertex v1;
        GVertex v2;
        GVertex v3;
        GVertex v4;
        
        // GVertex of inside tetrahedron
        GVertex v5;
        GVertex v6;
        GVertex v7;
        GVertex v8;
        
        // GVertex of hole between inside tetrahedron and outside tetrahedron
        GVertex v9;
        GVertex v10;
        GVertex v11;
        GVertex v12;
        GVertex v13;
        GVertex v14;
        GVertex v15;
        GVertex v16;
        
        // GVertex of curved tetrahedron
        final GVertex v17;
        final GVertex v18;
        final GVertex v19;
        final GVertex v20;
        
        // GVertex of inside sphere
        final GVertex v21;
        final GVertex v22;
        final GVertex v23;
        final GVertex v24;
        final GVertex v25;
        final GVertex v26;
        final GVertex v27;
        
        // GEdge of outside tetrahedorn
        GEdge e1;
        GEdge e2;
        GEdge e3;
        GEdge e4;
        GEdge e5;
        GEdge e6;
        
        // GEdge of inside tetrahedron
        GEdge e7;
        GEdge e8;
        GEdge e9;
        GEdge e10;
        GEdge e11;
        GEdge e12;
        
        // GEdge of hole between inside tetrahedron and outside tetrahedron
        GEdge e13;
        GEdge e14;
        GEdge e15;
        GEdge e16;
        GEdge e17;
        GEdge e18;
        GEdge e19;
        GEdge e20;
        GEdge e21;
        GEdge e22;
        GEdge e23;
        GEdge e24;
        
        // GEdge of curved tetrahedron
        final GEdge e25;
        final GEdge e26;
        final GEdge e27;
        final GEdge e28;
        final GEdge e29;
        final GEdge e30;
        
        // GEdge of inside sphere
        final GEdge e31;
        final GEdge e32;
        final GEdge e33;
        final GEdge e34;
        final GEdge e35;
        final GEdge e36;
        final GEdge e37;
        final GEdge e38;
        final GEdge e39;
        final GEdge e40;
        final GEdge e41;
        final GEdge e42;
        
        // GFace of outside tetrahdron
        GFace f1;
        GFace f2;
        GFace f3;
        GFace f4;
        
        // GFace of inside tetrahedron
        GFace f5;
        GFace f6;
        GFace f7;
        GFace f8;
        
        // GFace of hole between inside tetrahderon and outside tetrahedron
        GFace f9;
        GFace f10;
        GFace f11;
        GFace f12;
        
        // GFace of curved tetrahedron
        final GFace f15;
        final GFace f16;
        final GFace f17;
        final GFace f18;
        
        // GFace of inside sphere
        final GFace f19;
        final GFace f20;
        final GFace f21;
        final GFace f22;
        final GFace f23;
        final GFace f24;
        final GFace f25;
        final GFace f26;
        
        // vector of Gedge used by definition of faces of outside teterahedon
        final EdgeVector edg1 = new EdgeVector();
        final EdgeVector edg2 = new EdgeVector();
        final EdgeVector edg3 = new EdgeVector();
        final EdgeVector edg4 = new EdgeVector();
        
        // vector of Gedge used by definition of faces of inside teterahedon
        final EdgeVector edg5 = new EdgeVector();
        final EdgeVector edg6 = new EdgeVector();
        final EdgeVector edg7 = new EdgeVector();
        final EdgeVector edg8 = new EdgeVector();
        
        // vector of Gedge used by definition of faces of hole between inside
        // tetrahedron and outside teterahedon
        final EdgeVector edg9 = new EdgeVector();
        final EdgeVector edg10 = new EdgeVector();
        final EdgeVector edg11 = new EdgeVector();
        final EdgeVector edg12 = new EdgeVector();
        final EdgeVector edg13 = new EdgeVector();
        final EdgeVector edg14 = new EdgeVector();
        
        // vector of Gedge used by definition of faces of curved teterahedon
        final EdgeVector edg15 = new EdgeVector();
        final EdgeVector edg16 = new EdgeVector();
        final EdgeVector edg17 = new EdgeVector();
        final EdgeVector edg18 = new EdgeVector();
        
        // vector of Gedge used by definition of faces of inside sphere
        final EdgeVector edg19 = new EdgeVector();
        final EdgeVector edg20 = new EdgeVector();
        final EdgeVector edg21 = new EdgeVector();
        final EdgeVector edg22 = new EdgeVector();
        final EdgeVector edg23 = new EdgeVector();
        final EdgeVector edg24 = new EdgeVector();
        final EdgeVector edg25 = new EdgeVector();
        final EdgeVector edg26 = new EdgeVector();
        
        // vector of vector of Gedge used by definition of faces of outside
        // teterahedon
        final EdgeVectorOfVector edges1 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges2 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges3 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges4 = new EdgeVectorOfVector();
        
        // vector of vector of Gedge used by definition of faces of inside
        // teterahedon
        final EdgeVectorOfVector edges5 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges6 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges7 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges8 = new EdgeVectorOfVector();
        
        // vector of vector of Gedge used by definition of faces of hole between
        // inside tetrahedron and outside
        // teterahedon
        final EdgeVectorOfVector edges9 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges10 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges11 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges12 = new EdgeVectorOfVector();
        
        // vector of vector of Gedge used by definition of faces of curved
        // teterahedon
        final EdgeVectorOfVector edges15 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges16 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges17 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges18 = new EdgeVectorOfVector();
        
        // vector of vector of Gedge used by definition of faces of inside
        // sphere
        final EdgeVectorOfVector edges19 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges20 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges21 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges22 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges23 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges24 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges25 = new EdgeVectorOfVector();
        final EdgeVectorOfVector edges26 = new EdgeVectorOfVector();
        
        // outside tetrahedron minus inside tetrahedron
        GRegion r1;
        // GRegion of curved tetrahedre minus inside sphere
        final GRegion r2;
        
        // vector of GFace used to define the volume outside tetrahedron minus
        // inside tetrahedron minus hole between them
        final FaceVector fce1 = new FaceVector();
        // vector of GFace used to define the volume curved tetrahedron
        final FaceVector fce2 = new FaceVector();
        // vector of GFace used to define the volume inside sphere
        final FaceVector fce3 = new FaceVector();
        
        // vector of vector of GFace used to define the volume defined by the
        // outside tetrahedron minus the inside tetrahedron minus the hole
        // between them
        final FaceVectorOfVector faces1 = new FaceVectorOfVector();
        
        // vector of vector of GFace used to define the volume defined by the
        // curved tetrahedron minus the inside sphere
        final FaceVectorOfVector faces2 = new FaceVectorOfVector();
        
        // -----------------------------------------------------------------------//
        // creation of geometric elements
        // -----------------------------------------------------------------------//
        
        // // VERTEX
        
        // creation of vertices of outside tetrahedron
        v1 = gFact.addVertex(m, x1, y1, z1, lc1);
        v2 = gFact.addVertex(m, x2, y2, z2, lc2);
        v3 = gFact.addVertex(m, x3, y3, z3, lc3);
        v4 = gFact.addVertex(m, x4, y4, z4, lc4);
        
        // creation of vertices of inside tetrahedron
        v5 = gFact.addVertex(m, x5, y5, z5, lc5);
        v6 = gFact.addVertex(m, x6, y6, z6, lc6);
        v7 = gFact.addVertex(m, x7, y7, z7, lc7);
        v8 = gFact.addVertex(m, x8, y8, z8, lc8);
        
        // creation of vertices of hole between inside tetrahedron and inside
        // tetrahedron
        v9 = gFact.addVertex(m, x9, y9, z9, lc9);
        v10 = gFact.addVertex(m, x10, y10, z10, lc10);
        v11 = gFact.addVertex(m, x11, y11, z11, lc11);
        v12 = gFact.addVertex(m, x12, y12, z12, lc12);
        v13 = gFact.addVertex(m, x13, y13, z13, lc13);
        v14 = gFact.addVertex(m, x14, y14, z14, lc14);
        v15 = gFact.addVertex(m, x15, y15, z15, lc15);
        v16 = gFact.addVertex(m, x16, y16, z16, lc16);
        
        // creation of vertices of curved tetrahedron
        v17 = gFact.addVertex(m, x17, y17, z17, lc17);
        v18 = gFact.addVertex(m, x18, y18, z18, lc18);
        v19 = gFact.addVertex(m, x19, y19, z19, lc19);
        v20 = gFact.addVertex(m, x20, y20, z20, lc20);
        
        // creation of vertices of inside sphere
        v21 = gFact.addVertex(m, x21, y21, z21, lc21);
        v22 = gFact.addVertex(m, x22, y22, z22, lc22);
        v23 = gFact.addVertex(m, x23, y23, z23, lc23);
        v24 = gFact.addVertex(m, x24, y24, z24, lc24);
        v25 = gFact.addVertex(m, x25, y25, z25, lc25);
        v26 = gFact.addVertex(m, x26, y26, z26, lc26);
        v27 = gFact.addVertex(m, x27, y27, z27, lc27);
        
        // // definition of "physical property" for all points
        
        // 3 "physicals" for outside tetrahedron minus inside tetrahdron minus
        // hole between them
        
        // compute the first vertex tag
        tag = v1.tag();
        
        // add tag computed to first physical
        WrapGmsh.List_Add(lst1, tag);
        
        // add tag computed to second physical, so the first vertex own 2
        // physicals
        WrapGmsh.List_Add(lst2, tag);
        
        // add tag computed to second physical, so the first vertex own 3
        // physicals
        WrapGmsh.List_Add(lst3, tag);
        tag = v2.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v3.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v4.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v5.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v6.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v7.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v8.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v9.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v10.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v11.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v12.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v13.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v14.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v15.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = v16.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        
        // add all tags defines in the first physical in the GModel
        WrapGmsh.add_physical(str, lst1, m.getFileName());
        
        WrapGmsh.add_physical(str, lst2, m.getFileName());
        WrapGmsh.add_physical(str, lst3, m.getFileName());
        
        // delete what is in the List
        WrapGmsh.List_Reset(lst1);
        WrapGmsh.List_Reset(lst2);
        WrapGmsh.List_Reset(lst3);
        
        // same action about curved tetrahedron minus inside sphere
        tag = v17.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v18.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v19.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v20.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v21.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v22.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v23.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v24.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v25.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = v26.tag();
        WrapGmsh.List_Add(lst4, tag);
        
        WrapGmsh.add_physical(str, lst4, m.getFileName());
        WrapGmsh.List_Reset(lst4);
        
        // //LINE
        
        // creation of edges of outside tetrahedron
        e1 = gFact.addLine(m, v2, v1);
        e2 = gFact.addLine(m, v3, v1);
        e3 = gFact.addLine(m, v1, v4);
        e4 = gFact.addLine(m, v3, v2);
        e5 = gFact.addLine(m, v2, v4);
        e6 = gFact.addLine(m, v4, v3);
        
        // creation of edges of inside tetrahedron
        e7 = gFact.addLine(m, v5, v6);
        e8 = gFact.addLine(m, v5, v8);
        e9 = gFact.addLine(m, v5, v7);
        e10 = gFact.addLine(m, v6, v7);
        e11 = gFact.addLine(m, v7, v8);
        e12 = gFact.addLine(m, v6, v8);
        
        // creation of edges of hole between outside tetrahedron and insde
        // tetrahedron
        e13 = gFact.addLine(m, v9, v10);
        e14 = gFact.addLine(m, v10, v11);
        e15 = gFact.addLine(m, v11, v12);
        e16 = gFact.addLine(m, v9, v12);
        e17 = gFact.addLine(m, v12, v16);
        e18 = gFact.addLine(m, v11, v15);
        e19 = gFact.addLine(m, v10, v14);
        e20 = gFact.addLine(m, v9, v13);
        e21 = gFact.addLine(m, v13, v16);
        e22 = gFact.addLine(m, v13, v14);
        e23 = gFact.addLine(m, v14, v15);
        e24 = gFact.addLine(m, v15, v16);
        
        // creation of edges of curved tetrahedron
        e25 = gFact.addLine(m, v18, v20);
        e26 = gFact.addLine(m, v19, v20);
        
        // define a curved between v18 and v19, and v20 is the center
        e27 = gFact.addCircleArc(m, v18, v20, v19);
        e28 = gFact.addLine(m, v17, v20);
        e29 = gFact.addCircleArc(m, v17, v20, v19);
        e30 = gFact.addCircleArc(m, v17, v20, v18);
        
        // creation of edges of inside tetrahedron
        e31 = gFact.addCircleArc(m, v21, v27, v25);
        e32 = gFact.addCircleArc(m, v22, v27, v25);
        e33 = gFact.addCircleArc(m, v23, v27, v25);
        e34 = gFact.addCircleArc(m, v24, v27, v25);
        e35 = gFact.addCircleArc(m, v21, v27, v26);
        e36 = gFact.addCircleArc(m, v22, v27, v26);
        e37 = gFact.addCircleArc(m, v23, v27, v26);
        e38 = gFact.addCircleArc(m, v24, v27, v26);
        e39 = gFact.addCircleArc(m, v21, v27, v22);
        e40 = gFact.addCircleArc(m, v21, v27, v24);
        e41 = gFact.addCircleArc(m, v23, v27, v24);
        e42 = gFact.addCircleArc(m, v23, v27, v22);
        
        // // definition of physical for edges
        
        // definition of 3 physicals for outside tetrahedron minus inside
        // tetrahedron minus hole between them
        
        tag = e1.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e2.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e3.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e4.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e5.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e6.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e7.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e8.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e9.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e10.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e11.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e12.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e13.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e14.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e15.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e16.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e17.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e18.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e19.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e20.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e21.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e22.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e23.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = e24.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        
        WrapGmsh.add_physical(str1, lst1, m.getFileName());
        WrapGmsh.add_physical(str1, lst2, m.getFileName());
        WrapGmsh.add_physical(str1, lst3, m.getFileName());
        WrapGmsh.List_Reset(lst1);
        WrapGmsh.List_Reset(lst2);
        WrapGmsh.List_Reset(lst3);
        
        // same actions about curved tetrahedron minus inside sphere
        
        tag = e25.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e26.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e27.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e28.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e29.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e30.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e31.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e32.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e33.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e34.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e35.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e36.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e37.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e38.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e39.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e40.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e41.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = e42.tag();
        WrapGmsh.List_Add(lst4, tag);
        
        WrapGmsh.add_physical(str1, lst4, m.getFileName());
        WrapGmsh.List_Reset(lst4);
        
        // //FACE
        // // A face is defined by a vector of vector of edges because it is
        // possible to define faces with holes.
        
        // --------------------
        // definition of first face of outside tetrahedron
        edg1.add(e2);
        edg1.add(e3);
        edg1.add(e6);
        
        // definition of second face of outside tetrahedron
        edg2.add(e2);
        edg2.add(e4);
        edg2.add(e1);
        
        // definition of third face of outside tetrahedron
        edg3.add(e4);
        edg3.add(e5);
        edg3.add(e6);
        
        // definition of fourth face of outside tetrahedron
        edg4.add(e1);
        edg4.add(e5);
        edg4.add(e3);
        
        // --------------------
        // definition of first face of inside tetrahedron
        edg5.add(e8);
        edg5.add(e9);
        edg5.add(e11);
        
        // definition of second face of inside tetrahedron
        edg6.add(e10);
        edg6.add(e11);
        edg6.add(e12);
        
        // definition of third face of inside tetrahedron
        edg7.add(e7);
        edg7.add(e9);
        edg7.add(e10);
        
        // definition of fourth face of inside tetrahedron
        edg8.add(e7);
        edg8.add(e8);
        edg8.add(e12);
        
        // --------------------
        // definition of first face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg9.add(e16);
        edg9.add(e13);
        edg9.add(e14);
        edg9.add(e15);
        
        // definition of second face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg10.add(e16);
        edg10.add(e17);
        edg10.add(e20);
        edg10.add(e21);
        
        // definition of third face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg11.add(e15);
        edg11.add(e17);
        edg11.add(e18);
        edg11.add(e24);
        
        // definition of fourth face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg12.add(e14);
        edg12.add(e18);
        edg12.add(e19);
        edg12.add(e23);
        
        // definition of fifth face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg13.add(e13);
        edg13.add(e19);
        edg13.add(e20);
        edg13.add(e22);
        
        // definition of sixth face of hole between inside tetrahdron and
        // outside tetrahedron (it is a cube)
        edg14.add(e21);
        edg14.add(e22);
        edg14.add(e23);
        edg14.add(e24);
        
        // --------------------
        // definition of first face of curved tetrahdron
        edg15.add(e25);
        edg15.add(e28);
        edg15.add(e30);
        
        // definition of second face of curved tetrahdron
        edg16.add(e26);
        edg16.add(e28);
        edg16.add(e29);
        
        // definition of third face of curved tetrahdron
        edg17.add(e25);
        edg17.add(e26);
        edg17.add(e27);
        
        // definition of fourth face of curved tetrahdron
        edg18.add(e27);
        edg18.add(e29);
        edg18.add(e30);
        
        // --------------------
        // definition of first face of inside tetrahdron
        edg19.add(e31);
        edg19.add(e32);
        edg19.add(e39);
        
        // definition of second face of inside tetrahdron
        edg20.add(e32);
        edg20.add(e33);
        edg20.add(e42);
        
        // definition of third face of inside tetrahdron
        edg21.add(e33);
        edg21.add(e34);
        edg21.add(e41);
        
        // definition of fourth face of inside tetrahdron
        edg22.add(e34);
        edg22.add(e31);
        edg22.add(e40);
        
        // --------------------------
        // definition of first face of inside sphere
        edg23.add(e39);
        edg23.add(e35);
        edg23.add(e36);
        
        // definition of second face of inside sphere
        edg24.add(e35);
        edg24.add(e38);
        edg24.add(e40);
        
        // definition of third face of inside sphere
        edg25.add(e37);
        edg25.add(e38);
        edg25.add(e41);
        
        // definition of fourth face of inside sphere
        edg26.add(e36);
        edg26.add(e37);
        edg26.add(e42);
        
        // --------------------
        // definition of first face with hole of outside tetrahedron
        edges1.add(edg1);
        edges1.add(edg9);
        // definition of second face of outside tetrahedron
        edges2.add(edg2);
        // definition of third face of outside tetrahedron
        edges3.add(edg3);
        // definition of fourth face of outside tetrahedron
        edges4.add(edg4);
        
        // --------------------
        // definition of first face with hole of inside tetrahedron
        edges5.add(edg5);
        edges5.add(edg14);
        // definition of second face of inside tetrahedron
        edges6.add(edg6);
        // definition of third face of inside tetrahedron
        edges7.add(edg7);
        // definition of fourth face of inside tetrahedron
        edges8.add(edg8);
        
        // --------------------
        // definition of first face of hole between outside tetrahdron and
        // inside tetrahdron
        edges9.add(edg10);
        // definition of second face of hole between outside tetrahdron and
        // inside tetrahdron
        edges10.add(edg11);
        // definition of third face of hole between outside tetrahdron and
        // inside tetrahdron
        edges11.add(edg12);
        // definition of fourth face of hole between outside tetrahdron and
        // inside tetrahdron
        edges12.add(edg13);
        
        // --------------------
        // definition of first face of curved tetrahedron
        edges15.add(edg15);
        // definition of second face of curved tetrahedron
        edges16.add(edg16);
        // definition of third face of curved tetrahedron
        edges17.add(edg17);
        // definition of fourth face of curved tetrahedron
        edges18.add(edg18);
        
        // --------------------
        // definition of the first face of inside sphere
        edges19.add(edg19);
        // definition of the second face of inside sphere
        edges20.add(edg20);
        // definition of the third face of inside sphere
        edges21.add(edg21);
        // definition of the fourth face of inside sphere
        edges22.add(edg22);
        // definition of the fifith face of inside sphere
        edges23.add(edg23);
        // definition of the sixth face of inside sphere
        edges24.add(edg24);
        // definition of the seventh face of inside sphere
        edges25.add(edg25);
        // definition of the eighth face of inside sphere
        edges26.add(edg26);
        
        // creation of faces of outside tetrahedron
        f1 = gFact.addPlanarFace(m, edges1);
        f2 = gFact.addPlanarFace(m, edges2);
        f3 = gFact.addPlanarFace(m, edges3);
        f4 = gFact.addPlanarFace(m, edges4);
        
        // creation of faces of inside tetrahedron
        f5 = gFact.addPlanarFace(m, edges5);
        f6 = gFact.addPlanarFace(m, edges6);
        f7 = gFact.addPlanarFace(m, edges7);
        f8 = gFact.addPlanarFace(m, edges8);
        
        // creation of faces of hole betwxeen inside and outside tetrahdron
        f9 = gFact.addPlanarFace(m, edges9);
        f10 = gFact.addPlanarFace(m, edges10);
        f11 = gFact.addPlanarFace(m, edges11);
        f12 = gFact.addPlanarFace(m, edges12);
        
        // creation of faces of curved tetrahedron
        f15 = gFact.addPlanarFace(m, edges15);
        f16 = gFact.addPlanarFace(m, edges16);
        f17 = gFact.addPlanarFace(m, edges17);
	final FaceVector ruledFace1=gFact.addRuledFaces(m, edges18);
        f18 = ruledFace1.get(0);
        
        // creation of faces of curved tetrahedron
	final FaceVector ruledFace2=gFact.addRuledFaces(m, edges19);
	final FaceVector ruledFace3=gFact.addRuledFaces(m, edges20);
	final FaceVector ruledFace4=gFact.addRuledFaces(m, edges21);
	final FaceVector ruledFace5=gFact.addRuledFaces(m, edges22);
	final FaceVector ruledFace6=gFact.addRuledFaces(m, edges23);
	final FaceVector ruledFace7=gFact.addRuledFaces(m, edges24);
	final FaceVector ruledFace8=gFact.addRuledFaces(m, edges25);
	final FaceVector ruledFace9=gFact.addRuledFaces(m, edges26);
        f19 = ruledFace2.get(0);
        f20 = ruledFace3.get(0);
        f21 = ruledFace4.get(0);
        f22 = ruledFace5.get(0);
        f23 = ruledFace6.get(0);
        f24 = ruledFace7.get(0);
        f25 = ruledFace8.get(0);
        f26 = ruledFace9.get(0);
        
        // //definition of physical for faces
        
        // 3 physicals for the outside tetraherdon minus inside tetrahdron minus
        // hole between them
        
        tag = f1.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f2.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f3.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f4.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f5.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f6.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f7.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f8.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f9.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f10.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f11.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        tag = f12.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        
        WrapGmsh.add_physical(str2, lst1, m.getFileName());
        WrapGmsh.add_physical(str2, lst2, m.getFileName());
        WrapGmsh.add_physical(str2, lst3, m.getFileName());
        WrapGmsh.List_Reset(lst1);
        WrapGmsh.List_Reset(lst2);
        WrapGmsh.List_Reset(lst3);
        
        // same actions about curved tetrahedron minus inside sphere
        
        tag = f15.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f16.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f17.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f18.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f19.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f20.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f21.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f22.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f23.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f24.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f25.tag();
        WrapGmsh.List_Add(lst4, tag);
        tag = f26.tag();
        WrapGmsh.List_Add(lst4, tag);
        
        WrapGmsh.add_physical(str2, lst4, m.getFileName());
        WrapGmsh.List_Reset(lst4);
        
        // //VOLUME
        // //same approach as creation of faces but in a superior dimension
        
        // outside tetraheron
        fce1.add(f1);
        fce1.add(f2);
        fce1.add(f3);
        fce1.add(f4);
        
        // inside tetrahedron
        fce1.add(f5);
        fce1.add(f6);
        fce1.add(f7);
        fce1.add(f8);
        
        // hole between outside tetrahedron and inside tetrahdron
        fce1.add(f9);
        fce1.add(f10);
        fce1.add(f11);
        fce1.add(f12);
        
        // curved tetrahdron
        fce2.add(f15);
        fce2.add(f16);
        fce2.add(f17);
        fce2.add(f18);
        
        // inside sphere
        fce3.add(f19);
        fce3.add(f20);
        fce3.add(f21);
        fce3.add(f22);
        fce3.add(f23);
        fce3.add(f24);
        fce3.add(f25);
        fce3.add(f26);
        
        // outside tetrahedron minus inside tetrahedron minus hole between them
        faces1.add(fce1);
        
        // // curved tetrahedron minus inside sphere
        faces2.add(fce2);
        faces2.add(fce3);
        
        // outside tetrahedron minus inside tetrahedron minus hole between them
        r1 = gFact.addVolume(m, faces1);
        // // curved tetrahedron minus inside sphere
        r2 = gFact.addVolume(m, faces2);
        
        // //definition of physical for volumes
        
        // 3 "physicals" for the outside tetrhedron minus the inside tetrahdron
        // minus the hole between them.
        tag = r1.tag();
        WrapGmsh.List_Add(lst1, tag);
        WrapGmsh.List_Add(lst2, tag);
        WrapGmsh.List_Add(lst3, tag);
        
        WrapGmsh.add_physical(str3, lst1, m.getFileName());
        WrapGmsh.add_physical(str3, lst2, m.getFileName());
        WrapGmsh.add_physical(str3, lst3, m.getFileName());
        WrapGmsh.List_Reset(lst1);
        WrapGmsh.List_Reset(lst2);
        WrapGmsh.List_Reset(lst3);
        
        // // 1 "physical" for curved tetrahedron minus the inside sphere
        //
        tag = r2.tag();
        WrapGmsh.List_Add(lst4, tag);
        
        WrapGmsh.add_physical(str3, lst4, m.getFileName());
        WrapGmsh.List_Reset(lst4);
        
        // write .geo file which contains the geomtry defined before
        m.writeGEO("test.geo");
        
        // mesh the geometry defined in the GModel m
        m.mesh(3);
        
        // write .msh file which contains informations about mesh in GModel m.
        m.writeMSH("meshtest.msh");
        
        // read mesh elements produced by m.mesh(3)
        System.out.println("$MeshFormat");
        System.out.println("2.2 0 8");
        System.out.println("$EndMeshFormat");
        System.out.println("$Nodes");
        // boolean which indicates if all elements are meshed
        final boolean all = m.noPhysicalGroups();
        // number of nodes which is defined in mesh
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
        // number of elements which is defined in mesh
        //System.out.println(WrapGmsh.getNumElementsMSH(m, all, 0));
        
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
                    System.out.println(iter + " " + type + " 1 " + physical + " " + verts.get(0) + " " + verts.get(1) + " " + verts.get(2));
                    
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
                    System.out
                            .println(iter + " " + type + " 1 " + physical + " " + verts.get(0) + " " + verts.get(1) + " " + verts.get(2) + " " + verts.get(3));
                    
                    iter++;
                }
            }
        }
        System.out.println("$EndElements");
        
        WrapGmsh.GmshFinalize();
        
    }
    
}


/*
    (C) 2009 Mark van Doesburg, Technolution B.V.

    Distributed under GPL version 2
*/

#include <iterator>

/* OpenCASCADE ************************************************************/
#include <config.h>
#include <TopoDS.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Compound.hxx>

#include <BRepTools.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRep_Builder.hxx>
#include <GC_MakeEllipse.hxx>
#include <TopOpeBRep_DSFiller.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeBox.hxx>

/* Boolean operations */
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Section.hxx>

// NEW
#include <BRepFill_Filling.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <TopTools.hxx>
#include <ShapeFix_Solid.hxx>

#include "BRLFile.h"

#include "printing.h"

#define scale 1

////////////////////////////////////////////////////////////////////////////////
// Construct TopoDS from BRL-CAD data
////////////////////////////////////////////////////////////////////////////////
BRLTopo::BRLTopo(struct rt_arb_internal *arb)
{
    TopoDS_Vertex v[8];
    for(int i=0;i<8;i++)
        v[i]=BRepBuilderAPI_MakeVertex(
            gp_Pnt(
                scale*arb->pt[i][0],
                scale*arb->pt[i][1],
                scale*arb->pt[i][2]
            )
        );

    int arbn;
    if(!BRepTools::Compare(v[6],v[7]))
        arbn=8;
    else if(!BRepTools::Compare(v[4],v[5]))
        arbn=7;
    else if(!BRepTools::Compare(v[5],v[6]))
        arbn=6;
    else if(!BRepTools::Compare(v[0],v[3]))
        arbn=5;
    else
        arbn=4;

    switch(arbn) {
    case 8: {
        TopoDS_Edge e[12];
        for(int i=0;i<4;i++) { 
            e[i]=BRepBuilderAPI_MakeEdge(v[i],v[(i+1)%4]);
            e[i+4]=BRepBuilderAPI_MakeEdge(v[i+4],v[(i+1)%4+4]);
            e[i+8]=BRepBuilderAPI_MakeEdge(v[i],v[(i+4)%8]);
        }

        TopoDS_Wire w[6];
        w[0]=BRepBuilderAPI_MakeWire(e[0],e[1],e[2],e[3]);
        w[1]=BRepBuilderAPI_MakeWire(e[4],e[5],e[6],e[7]);
        w[2]=BRepBuilderAPI_MakeWire(e[0],e[9],e[4],e[8]);
        w[3]=BRepBuilderAPI_MakeWire(e[1],e[10],e[5],e[9]);
        w[4]=BRepBuilderAPI_MakeWire(e[2],e[11],e[6],e[10]);
        w[5]=BRepBuilderAPI_MakeWire(e[3],e[8],e[7],e[11]);

        BRep_Builder BB;
        TopoDS_Shell shell;
        BB.MakeShell(shell);
        for(int i=0;i<6;i++) {
            TopoDS_Face f=BRepBuilderAPI_MakeFace(w[i]);
            BB.Add(shell,i? f.Reversed():f);
        }
        TopoDS_Solid solid;
        BB.MakeSolid(solid);
        BB.Add(solid,shell);
        ShapeFix_Solid sf(solid);
        sf.Perform();
        shape=sf.Solid();
        } break;
    case 6: {
        TopoDS_Edge e[9];
        e[0]=BRepBuilderAPI_MakeEdge(v[0],v[1]);
        e[1]=BRepBuilderAPI_MakeEdge(v[1],v[2]);
        e[2]=BRepBuilderAPI_MakeEdge(v[2],v[3]);
        e[3]=BRepBuilderAPI_MakeEdge(v[3],v[0]);
        e[4]=BRepBuilderAPI_MakeEdge(v[0],v[4]);
        e[5]=BRepBuilderAPI_MakeEdge(v[1],v[4]);
        e[6]=BRepBuilderAPI_MakeEdge(v[2],v[6]);
        e[7]=BRepBuilderAPI_MakeEdge(v[3],v[6]);
        e[8]=BRepBuilderAPI_MakeEdge(v[4],v[6]);

        TopoDS_Wire w[5];
        w[0]=BRepBuilderAPI_MakeWire(e[0],e[1],e[2],e[3]);
        w[1]=BRepBuilderAPI_MakeWire(e[0],e[4],e[5]);
        w[2]=BRepBuilderAPI_MakeWire(e[2],e[6],e[7]);
        w[3]=BRepBuilderAPI_MakeWire(e[3],e[4],e[8],e[7]);
        w[4]=BRepBuilderAPI_MakeWire(e[1],e[5],e[8],e[6]);

        BRep_Builder BB;
#if 0
        TopoDS_Compound result;
        BB.MakeCompound(result);
        for(int i=0;i<5;i++) {
            BB.Add(result,BRepBuilderAPI_MakeFace(w[i]));
        }
        shape=result;
#else
        TopoDS_Shell shell;
        BB.MakeShell(shell);
        for(int i=0;i<5;i++) {
            TopoDS_Face f=BRepBuilderAPI_MakeFace(w[i]);
            BB.Add(shell,f); //i? f:f.Reversed());
        }
        TopoDS_Solid solid;
        BB.MakeSolid(solid);
        BB.Add(solid,shell);
        ShapeFix_Solid sf(solid);
        sf.Perform();
        shape=sf.Solid();
#endif
        } break;
    default:
        cerr << "Unhandled arb8 type n=" << arbn << '\n';
    }
}

BRLTopo::BRLTopo(struct rt_tgc_internal *tgc)
{
    /*  We use the same names as BRL-CAD, but use 4 vertices on the edges.
        These additional vertices have their letter repeated and the
        direction vector inverted.
     */
    gp_Pnt v(scale*tgc->v[0], scale*tgc->v[1], scale*tgc->v[2]);
    gp_Pnt a(
        scale*(v.Coord(1)+tgc->a[0]), 
        scale*(v.Coord(2)+tgc->a[1]), 
        scale*(v.Coord(3)+tgc->a[2]));
    gp_Pnt b(
        scale*(v.Coord(1)+tgc->b[0]), 
        scale*(v.Coord(2)+tgc->b[1]), 
        scale*(v.Coord(3)+tgc->b[2]));
    gp_Pnt aa(
        scale*(v.Coord(1)-tgc->a[0]), 
        scale*(v.Coord(2)-tgc->a[1]), 
        scale*(v.Coord(3)-tgc->a[2]));
    gp_Pnt bb(
        scale*(v.Coord(1)-tgc->b[0]), 
        scale*(v.Coord(2)-tgc->b[1]), 
        scale*(v.Coord(3)-tgc->b[2]));
    Handle(Geom_Ellipse) top;
    if(v.SquareDistance(a)<v.SquareDistance(b))
        top=GC_MakeEllipse(b, aa, v); 
    else
        top=GC_MakeEllipse(a, b, v); 
    TopoDS_Edge e_t[4];
    e_t[0]=BRepBuilderAPI_MakeEdge(top,a,b);
    e_t[1]=BRepBuilderAPI_MakeEdge(top,b,aa);
    e_t[2]=BRepBuilderAPI_MakeEdge(top,aa,bb);
    e_t[3]=BRepBuilderAPI_MakeEdge(top,bb,a);

    gp_Pnt h(
        scale*(v.Coord(1)+tgc->h[0]), 
        scale*(v.Coord(2)+tgc->h[1]), 
        scale*(v.Coord(3)+tgc->h[2]));
    gp_Pnt c(
        scale*(h.Coord(1)+tgc->c[0]), 
        scale*(h.Coord(2)+tgc->c[1]), 
        scale*(h.Coord(3)+tgc->c[2]));
    gp_Pnt d(
        scale*(h.Coord(1)+tgc->d[0]), 
        scale*(h.Coord(2)+tgc->d[1]), 
        scale*(h.Coord(3)+tgc->d[2]));
    gp_Pnt cc(
        scale*(h.Coord(1)-tgc->c[0]), 
        scale*(h.Coord(2)-tgc->c[1]), 
        scale*(h.Coord(3)-tgc->c[2]));
    gp_Pnt dd(
        scale*(h.Coord(1)-tgc->d[0]), 
        scale*(h.Coord(2)-tgc->d[1]), 
        scale*(h.Coord(3)-tgc->d[2]));
    Handle(Geom_Ellipse) bottom;
    if(h.SquareDistance(c)<h.SquareDistance(d))
        bottom=GC_MakeEllipse(d, cc, h); 
    else
        bottom=GC_MakeEllipse(c, d, h); 
    TopoDS_Edge e_b[4];
    e_b[0]=BRepBuilderAPI_MakeEdge(bottom,c,d);
    e_b[1]=BRepBuilderAPI_MakeEdge(bottom,d,cc);
    e_b[2]=BRepBuilderAPI_MakeEdge(bottom,cc,dd);
    e_b[3]=BRepBuilderAPI_MakeEdge(bottom,dd,c);

#if 1
    BRepOffsetAPI_ThruSections BB(Standard_True);
    BB.AddWire(BRepBuilderAPI_MakeWire(e_t[0],e_t[1],e_t[2],e_t[3]));
    BB.AddWire(BRepBuilderAPI_MakeWire(e_b[0],e_b[1],e_b[2],e_b[3]));
    BB.CheckCompatibility(Standard_False);
    shape=BB.Shape();
#else
    BRep_Builder BB;
    TopoDS_Compound result;
    BB.MakeCompound(result);
    for(int i=0;i<4;i++) {
        BB.Add(result,e_t[i]);
        BB.Add(result,e_b[i]);
    }
    shape=result;
#endif
}

BRLTopo::BRLTopo(struct rt_ell_internal *ell)
{
#if 0
    gp_Pnt v(ell->v[0], ell->v[1], ell->v[2]);
    gp_Pnt a(v.Coord(1)+ell->a[0], v.Coord(2)+ell->a[1], v.Coord(3)+ell->a[2]);
    gp_Pnt b(v.Coord(1)+ell->b[0], v.Coord(2)+ell->b[1], v.Coord(3)+ell->b[2]);
    gp_Pnt c(v.Coord(1)+ell->c[0], v.Coord(2)+ell->c[1], v.Coord(3)+ell->c[2]);
    gp_Pnt aa(v.Coord(1)-ell->a[0], v.Coord(2)-ell->a[1], v.Coord(3)-ell->a[2]);
    gp_Pnt bb(v.Coord(1)-ell->b[0], v.Coord(2)-ell->b[1], v.Coord(3)-ell->b[2]);
    gp_Pnt cc(v.Coord(1)-ell->c[0], v.Coord(2)-ell->c[1], v.Coord(3)-ell->c[2]);

    Handle(Geom_Ellipse) sect1=GC_MakeEllipse(a, b, v); 
    Handle(Geom_Ellipse) sect2=GC_MakeEllipse(a, c, v); 
    Handle(Geom_Ellipse) sect3=GC_MakeEllipse(b, c, v); 

    TopoDS_Edge e_ab[4];
    e_ab[0]=BRepBuilderAPI_MakeEdge(sect1,a,b);
    e_ab[1]=BRepBuilderAPI_MakeEdge(sect1,b,aa);
    e_ab[2]=BRepBuilderAPI_MakeEdge(sect1,aa,bb);
    e_ab[3]=BRepBuilderAPI_MakeEdge(sect1,bb,a);

    TopoDS_Edge e_ac[4];
    e_ac[0]=BRepBuilderAPI_MakeEdge(sect2,c,aa);
    e_ac[1]=BRepBuilderAPI_MakeEdge(sect2,a,c);
    e_ac[2]=BRepBuilderAPI_MakeEdge(sect2,aa,cc);
    e_ac[3]=BRepBuilderAPI_MakeEdge(sect2,cc,a); 

    TopoDS_Edge e_bc[4];
    e_bc[0]=BRepBuilderAPI_MakeEdge(sect3,b,c);
    e_bc[1]=BRepBuilderAPI_MakeEdge(sect3,c,bb);
    e_bc[2]=BRepBuilderAPI_MakeEdge(sect3,bb,cc);
    e_bc[3]=BRepBuilderAPI_MakeEdge(sect3,cc,b); 

    // FIXME, BRepFill_Filling?
    TopoDS_Solid sph=BRepPrimAPI_MakeSphere(v,ell->a[0]);
    TopoDS_Face init;
    for(TopExp_Explorer p(sph,TopAbs_FACE); p.More(); p.Next())
        init=TopoDS::Face(p.Current());
    BRepFill_Filling face1;
    //face1.LoadInitSurface(init);
    face1.Add(e_ab[0],GeomAbs_C0);
    face1.Add(e_ab[1],GeomAbs_C0);
    face1.Add(e_ac[0],GeomAbs_C0);
    face1.Add(e_ac[1],GeomAbs_C0);
    face1.Add(e_bc[0],GeomAbs_C0,false);
    face1.Build();

    BRepFill_Filling face2;
    //face2.LoadInitSurface(init);
    face2.Add(e_ab[2],GeomAbs_C0);
    face2.Add(e_ab[3],GeomAbs_C0);
    face2.Add(e_ac[2],GeomAbs_C0);
    face2.Add(e_ac[3],GeomAbs_C0);
    face2.Add(e_bc[2],GeomAbs_C0,false);
    face2.Build();

    BRepFill_Filling face3;
    //face3.LoadInitSurface(init);
    face3.Add(e_ab[2],GeomAbs_C0);
    face3.Add(e_ab[3],GeomAbs_C0);
    face3.Add(e_ac[0],GeomAbs_C0);
    face3.Add(e_ac[1],GeomAbs_C0);
    face3.Add(e_bc[1],GeomAbs_C0,false);
    face3.Build();

    BRepFill_Filling face4;
    //face4.LoadInitSurface(init);
    face4.Add(e_ab[0],GeomAbs_C0);
    face4.Add(e_ab[1],GeomAbs_C0);
    face4.Add(e_ac[2],GeomAbs_C0);
    face4.Add(e_ac[3],GeomAbs_C0);
    face4.Add(e_bc[3],GeomAbs_C0,false);
    face4.Build();

    BRep_Builder BB;
    TopoDS_Shell result;
    BB.MakeShell(result);
    BB.Add(result,face1.Face());
    BB.Add(result,face2.Face().Reversed());
    BB.Add(result,face3.Face());
    BB.Add(result,face4.Face().Reversed());

    shape=BRepBuilderAPI_MakeSolid(result);
#else
    /* FIXME, we only support spheres at the moment. */
    gp_Pnt v(scale*ell->v[0], scale*ell->v[1], scale*ell->v[2]);
    TopoDS_Solid sph=BRepPrimAPI_MakeSphere(v,scale*ell->a[0]);
    shape=sph;
#endif
}

////////////////////////////////////////////////////////////////////////////////
// Read the BRL-CAD file
////////////////////////////////////////////////////////////////////////////////
BRLFile::BRLFile(char *filename, int v)
{
    verbose=v;

    dbip = db_open(filename, "r");
    if(dbip==DBI_NULL)
        return;

    /* build a wdbp structure for convenient read/write */
    wdbp = wdb_dbopen(dbip, RT_WDB_TYPE_DB_DISK);
    if (db_dirbuild(dbip) < 0) {        /* create directory database contents */
        bu_log("Error building directory for %s\n", filename);
        exit(-1);
    }
}

int BRLFile::AddModel(char const *name)
{
    if(dbip==DBI_NULL)
        return 1;
    struct directory *dp=db_lookup(dbip, name, 1);
    if(dp == NULL)
        return 1;

    rt_init_resource( &rt_uniresource, 0, NULL );
    db_functree(dbip, dp, CsgCombine, CsgLeaf, &rt_uniresource, this);

    while(construction.size()>0) {
        Add(construction.front());
        construction.pop_front();
    }
    return 0;
}

TopoDS_Shape BRLFile::PerformBoolean(union tree *tp)
{
    TopoDS_Shape left, right, result;
    if(tp->tr_op==OP_UNION || tp->tr_op==OP_INTERSECT || tp->tr_op==OP_SUBTRACT
    ) {
        left=PerformBoolean(tp->tr_b.tb_left);
        right=PerformBoolean(tp->tr_b.tb_right);
    }

    if(verbose&BRL) {
        switch(tp->tr_op) {
        case OP_UNION:
        case OP_INTERSECT:
        case OP_SUBTRACT:
                cout<< "    Bool " << *tp;
                break;
        case OP_DB_LEAF:
            if(verbose&BRL)
                cout << "    Leaf " << tp->tr_l.tl_name;
            break;
        }
        cout << " remaining " << construction.size() << '\n';
    }

    switch(tp->tr_op) {
    case OP_UNION:    return BRepAlgoAPI_Fuse(left,right); 
    case OP_INTERSECT:return BRepAlgoAPI_Common(left,right);
    case OP_SUBTRACT: return BRepAlgoAPI_Cut(left,right);
    case OP_DB_LEAF:
        result=construction.back();
        construction.pop_back();
        return result;
    default:
        std::cerr << "Invalid boolean operation in " << __FUNCTION__ << '\n';
        return result;
    }
}

void BRLFile::CsgCombine(struct db_i *dbip, struct directory *dp, genptr_t ptr)
{
    BRLFile *that=(BRLFile*)ptr;

    struct rt_db_internal       ip;
    if(rt_db_get_internal(&ip, dp, dbip, NULL, &rt_uniresource)!=ID_COMBINATION
    ) {
        std::cerr << "Combination is not a combination in " 
            << __FUNCTION__ << '\n';
        exit(1);
    }

    struct rt_comb_internal *comb = (struct rt_comb_internal *)ip.idb_ptr;

    if(that->verbose&BRL) {
        std::cout << "Combine " << dp->d_namep << '\n';

        std::cout << *comb;
        std::cout << "    --------------------\n";
        std::cout << "    " << comb->tree << '\n';
    }

    that->construction.push_back(that->PerformBoolean(comb->tree));
}

void BRLFile::CsgLeaf(struct db_i *dbip, struct directory *dp, genptr_t ptr)
{
    BRLFile *that=(BRLFile*)ptr;

    if(that->verbose&BRL)
        std::cout << "Leaf " << dp->d_namep << '\n';

    struct rt_db_internal       ip;
    switch(rt_db_get_internal(&ip, dp, dbip, (fastf_t *)NULL, &rt_uniresource)){
    case ID_ARB8: {
        struct rt_arb_internal *arb=(struct rt_arb_internal *)ip.idb_ptr;
        if(that->verbose&BRL) {
            std::cout << "    ARB8\n";
            for(int i=0;i<8;i++) {
                std::cout << "    pt[" << i << "]=" << arb->pt[i] << '\n';
            } 
        }
        that->construction.push_front(BRLTopo(arb));
        } break;
    case ID_TGC: {
        struct rt_tgc_internal *tgc=(struct rt_tgc_internal *)ip.idb_ptr;
        if(that->verbose&BRL) {
            std::cout 
                << "    TGC\n"
                << "    v=" << tgc->v << '\n'
                << "    h=" << tgc->h << '\n'
                << "    a=" << tgc->a << '\n'
                << "    b=" << tgc->b << '\n'
                << "    c=" << tgc->c << '\n'
                << "    d=" << tgc->d << '\n';
        }
        that->construction.push_front(BRLTopo(tgc));
        } break;
    case ID_ELL: {
        struct rt_ell_internal *ell=(struct rt_ell_internal *)ip.idb_ptr;
        if(that->verbose&BRL) {
            std::cout << "    v=" << ell->v << '\n';
            std::cout << "    a=" << ell->a << '\n';
            std::cout << "    b=" << ell->b << '\n';
            std::cout << "    c=" << ell->c << '\n';
        }
        that->construction.push_front(BRLTopo(ell));
        } break;
    default:
        std::cout << "    Unhandled type " << 
            rt_db_get_internal(&ip, dp, dbip, (fastf_t *)NULL, &rt_uniresource) 
            << '\n';
    }
}

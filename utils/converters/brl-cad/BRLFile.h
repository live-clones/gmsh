/*
    (C) 2009 Mark van Doesburg, Technolution B.V.

    Distributed under GPL version 2
*/

#include "OCC_Connect.h"

/* BRL-CAD ************************************************************/
#include "common.h"
#include "vmath.h"              /* vector math macros */
#include "raytrace.h"           /* librt interface definitions */
#include "rtgeom.h"
#include "wdb.h"

class BRLTopo {
    TopoDS_Shape shape;
public:
    BRLTopo(TopoDS_Shape const &s) { shape=s; }
    BRLTopo(struct rt_arb_internal *arb);
    BRLTopo(struct rt_tgc_internal *tgc);
    BRLTopo(struct rt_ell_internal *ell);
    operator TopoDS_Shape&() { return shape; }
};

class BRLFile:public OCC_Connect {
    struct rt_wdb *wdbp;
    struct db_i *dbip;
    struct rt_db_internal ip;
    std::deque<BRLTopo> construction;
public:
    enum Verbose { Cutting=1, BRL=2 };
    BRLFile(char *filename,int v=0);
    int AddModel(char const *);
private:
    static void CsgCombine(struct db_i *, struct directory *, genptr_t);
    static void CsgLeaf(struct db_i *, struct directory *, genptr_t);
    TopoDS_Shape PerformBoolean(union tree*);
};


// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Mark van Doesburg, Technolution B.V.

#ifndef _OCC_CONNECT_H_
#define _OCC_CONNECT_H_

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
#include <set>

#include "GmshConfig.h"

#if defined(HAVE_OCC)

#if !defined(HAVE_NO_OCC_CONFIG_H)
#include <config.h>
#endif

#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_IndexedMapOfShape.hxx>

#include <BRep_Builder.hxx>
#include <LocOpe_SplitShape.hxx>

class OCC_Connect {
    struct LessThanIntegerSet {
        bool operator()(std::set<int> const &a, std::set<int> const &b) const;
    };
    typedef std::map<std::set<int>,std::set<int>,LessThanIntegerSet> mapping_t;

    class FaceCutters:public std::vector<TopoDS_Wire> {
        std::vector<TopoDS_Edge> edges;
        int rebuilt;
    public:
        FaceCutters(void) { rebuilt=0; }
        void Build(TopoDS_Face const &,TopoDS_Shape&,int);
        void Add(TopoDS_Edge const&);
    private:
        int FindConnectedEdge(int v, std::vector<int> &done,
            std::vector<std::vector<int> > &v_edge);
    };
    typedef std::map<int,FaceCutters> cutmap_t;

    std::deque<TopoDS_Shape> assembly;
protected:
    int verbose;

public:
    enum Verbose { Cutting=1, CuttingReject=4, CuttingIntermediate=8 };
    OCC_Connect(int v=0) { verbose=v; }
    int SaveBRep(char const *);
    void Connect(void);
    void Collect(void);
    void Add(TopoDS_Shape const &a) { assembly.push_back(a); }
    void Dump(std::ostream &) const;
    operator TopoDS_Shape(void) { return assembly.front(); }
private:
    void MergeVertices(TopoDS_Shape&,TopoDS_Shape&) const;
    void MergeEdges(TopoDS_Shape&,TopoDS_Shape&) const;
    void MergeFaces(TopoDS_Shape&) const;
    void PerformBoolean(union tree*);
    void Intersect(BRep_Builder &BB, TopoDS_Shape &target,
        TopoDS_Shape &shape, TopoDS_Shape &tool);
    bool CanMergeCurve(TopoDS_Edge edge1,TopoDS_Edge edge2) const;
    bool CanMergeFace(TopoDS_Face face1,TopoDS_Face face2) const;
    void PrintItemCount(TopoDS_Shape const &shape) const;
    cutmap_t SelectCuttingEdges(TopTools_IndexedMapOfShape &edges,
        TopTools_IndexedMapOfShape &faces);
};

#endif

#endif

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Mark van Doesburg, Technolution B.V.

#include "OCC_Connect.h"

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <iterator>

#if defined(HAVE_OCC)

#include <TopoDS.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Compound.hxx>

#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRep_ShapeIntersector.hxx>
#include <TopTools.hxx>

#include <BRepTools.hxx>
#include <BRepTools_ReShape.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepExtrema_ExtCC.hxx>
#include <BRepExtrema_ExtCF.hxx>
#include <BRepExtrema_ExtFF.hxx>
#include <BRepExtrema_ExtPF.hxx>
#include <BRepExtrema_ExtPC.hxx>
#include <BRep_Tool.hxx>
#include <BRepClass_FaceClassifier.hxx>

#include <IntTools_Context.hxx>

#include <BRepExtrema_DistShapeShape.hxx>
#include <BRepOffsetAPI_NormalProjection.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <BRepTools_Substitution.hxx>
#include <BRepAlgo_Loop.hxx>

#include <BRep_TEdge.hxx>
#include <TopoDS_TShape.hxx>
#include <ShapeFix_Edge.hxx>
#include <Geom_Surface.hxx>
#include <gce_MakeScale.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepBuilderAPI_Transform.hxx>


////////////////////////////////////////////////////////////////////////////////
// Printing routines
////////////////////////////////////////////////////////////////////////////////

static inline ostream &operator <<(ostream &o,const TopAbs_ShapeEnum &A)
{
    switch(A) {
    case TopAbs_COMPOUND: return o << "COMPOUND";
    case TopAbs_COMPSOLID: return o << "COMPSOLID";
    case TopAbs_SOLID: return o << "SOLID";
    case TopAbs_SHELL: return o << "SHELL";
    case TopAbs_FACE: return o << "FACE";
    case TopAbs_WIRE: return o << "WIRE";
    case TopAbs_EDGE: return o << "EDGE";
    case TopAbs_VERTEX: return o << "VERTEX";
    case TopAbs_SHAPE: return o << "SHAPE";
    default: return o << "Unknown";
    }
}

static inline ostream &operator <<(ostream &o,const TopAbs_State &A)
{
    switch(A) {
    case TopAbs_IN: return o << "IN";
    case TopAbs_OUT: return o << "OUT";
    case TopAbs_ON: return o << "ON";
    case TopAbs_UNKNOWN: return o << "UNKNOWN";
    default: return o << "Unknown";
    }
}

static inline ostream &operator <<(ostream &o,const gp_Pnt &p)
{
  return o << "(" << p.Coord(1) << "," << p.Coord(2) << "," << p.Coord(3) << ")";
}

static inline ostream &operator <<(ostream &o,const TopOpeBRep_P2Dstatus &A)
{
    switch(A) {
    case TopOpeBRep_P2DUNK: return o << "P2DUNK";
    case TopOpeBRep_P2DINT: return o << "P2DINT";
    case TopOpeBRep_P2DSGF: return o << "P2DSGF";
    case TopOpeBRep_P2DSGL: return o << "P2DSGL ";
    case TopOpeBRep_P2DNEW: return o << "P2DNEW ";
    default: return o << "Unknown";
    }
}

template <typename T>
static inline std::ostream &operator<<(std::ostream &out, std::set<T> const &a)
{
    std::copy(a.begin(),a.end(),std::ostream_iterator<T>(out," "));
    return out;
}

bool OCC_Connect::LessThanIntegerSet::operator()(std::set<int> const &a,
    std::set<int> const &b) const
{
    std::set<int>::const_iterator pa=a.begin(), pb=b.begin();
    for(; pa!=a.end() && pb!=b.end(); pa++, pb++ ) {
	if(*pa<*pb)
	    return 1;
	if(*pb<*pa)
	    return 0;
    }
    if(pb!=b.end())
	return 1;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// OCC_Connect
////////////////////////////////////////////////////////////////////////////////

int OCC_Connect::SaveBRep(char const *name)
{
    gp_Pnt center(0,0,0);
    gce_MakeScale transform(center, 0.001);
    BRepBuilderAPI_Transform scale(assembly.front(), transform.Value());
    BRep_Builder BB;
    TopoDS_Compound compound;
    BB.MakeCompound(compound);
    TopTools_ListOfShape p;
    for(p=scale.Modified(assembly.front());
	!p.IsEmpty();
	p.RemoveFirst()
    )
	BB.Add(compound,p.First());
    BRepTools::Write(compound, (char*)name);
    return 1;
}

void OCC_Connect::Dump(ostream &out) const
{
    BRepTools::Dump(assembly.front(),out);
}

void OCC_Connect::Connect(void)
{
    while(assembly.size()>1) {
        TopoDS_Compound result;
        BRep_Builder BB;
        BB.MakeCompound(result);
        Intersect(BB,result,assembly.front(),assembly.back());
        assembly.pop_front();
        assembly.pop_back();
        assembly.push_back(result);
    }
}

void OCC_Connect::Collect(void)
{
    TopoDS_Compound result;
    BRep_Builder BB;
    BB.MakeCompound(result);
    while(assembly.size()>0) {
        if(verbose&Cutting)
	    cout << "Adding item\n";
        BB.Add(result,assembly.front());
        assembly.pop_front();
    }
    assembly.push_back(result);
}

void OCC_Connect::FaceCutters::Add(TopoDS_Edge const &edge)
{
    edges.push_back(edge);
    rebuilt=0;
}

int OCC_Connect::FaceCutters::FindConnectedEdge(int v,
    std::vector<int> &done,
    std::vector<std::vector<int> > &v_edge
)  {
    int re_used=-1;
    for(std::vector<int>::iterator p=v_edge[v].begin();p!=v_edge[v].end(); p++){
        if(done[*p]) {
            re_used=*p;
            continue;
        }
        return *p;       // Found an unused edge
    }
    return re_used;
}

void dump(std::vector<std::pair<int,int> > const &e2v, std::ostream &out,
    const char *name="name")
{
    out << "graph " << name << " {\n";
    for(int e=0; e<e2v.size(); e++) {
      out << "    " << e2v[e].first << " -- " << e2v[e].second << "[label=" << e+1 << "]\n";
    }
    out << "}\n";
}

void FinishEdge(int edge,
    std::vector<std::set<int> > &v2e,
    std::vector<std::pair<int,int> > &e2v)
{
    int verbose=0;
    if(verbose)
      std::cout << "Finishing edge " << edge << "\n";

    int fv=e2v[edge].first;
    v2e[fv].erase(edge);
    while(v2e[fv].size()>1) {
	std::set<int>::iterator e=v2e[fv].begin();
	int nv=v2e.size();
	v2e.push_back(std::set<int>());
	v2e[nv].insert(*e);
	if(e2v[*e].first==fv)
	    e2v[*e].first=nv;
	else
	    e2v[*e].second=nv;
	if(verbose)
          std::cout << "Created vertex " << nv << "(" << fv << "), edge[" << *e
                    << "]=" << e2v[*e].first << " " << e2v[*e].second << "\n";
	v2e[fv].erase(*e);
    }

    int sv=e2v[edge].second;
    v2e[sv].erase(edge);
    while(v2e[sv].size()>1) {
	std::set<int>::iterator e=v2e[sv].begin();
	int nv=v2e.size();
	v2e.push_back(std::set<int>());
	v2e[nv].insert(*e);
	if(e2v[*e].first==sv)
	    e2v[*e].first=nv;
	else
	    e2v[*e].second=nv;
	if(verbose)
          std::cout << "Created vertex " << nv << "(" << sv << "), edge[" << *e <<
            "]=" << e2v[*e].first << " " << e2v[*e].second << "\n";
	v2e[sv].erase(*e);
    }
}

void OCC_Connect::FaceCutters::Build(TopoDS_Face const &face,
    TopoDS_Shape &result, int verbose)
{
    clear();

    /* First we create some data structures to access the topology */
    TopTools_IndexedMapOfShape vertices;
    std::vector<std::pair<int,int> > e2v;
    for(int i=0; i<edges.size(); i++) {
        TopExp::MapShapes(edges[i],TopAbs_VERTEX,vertices);
        TopoDS_Vertex v1, v2;
        TopExp::Vertices(edges[i],v1,v2);
        std::pair<int,int> t(vertices.FindIndex(v1),vertices.FindIndex(v2));
        e2v.push_back(t);
    }

    std::vector<std::set<int> > v2e;
    for(int e=0; e<e2v.size(); e++) {
        if(e2v[e].first>=v2e.size())
            v2e.resize(e2v[e].first+1);
        v2e[e2v[e].first].insert(e);
        if(e2v[e].second>=v2e.size())
            v2e.resize(e2v[e].second+1);
        v2e[e2v[e].second].insert(e);
    }

    std::set<int> open, odd;
    for(int i=0; i<v2e.size(); i++) {
        if(v2e[i].size()==0)
            continue;
        else if(v2e[i].size()==1)
            open.insert(i);
        else if(v2e[i].size()&1)
            odd.insert(i);
    }

    if(open.size()&1)
        std::cerr << "Inconsistent open loops\n";
    if(odd.size()&1)
        std::cerr << "Inconsistent odd loops\n";
    int first_edge=-1;
    for(;;) {
        int open_mode;
        std::set<int> current_vertices;
        for(int start=0; start<v2e.size(); start++) {
	    if(v2e[start].size()==1) {
		if(verbose&Cutting)
                  std::cout << "start open at " << start << "\n";
		current_vertices.insert(start);
		open_mode=1;
		break;
	    }
        }
        if(!current_vertices.size()) {
	    for(int start=0; start<v2e.size(); start++) {
		if(v2e[start].size()) {
		    if(verbose&Cutting)
                      std::cout << "start closed at " << start << "\n";
		    current_vertices.insert(start);
		    open_mode=0;
		    break;
		}
	    }
        }
        if(!current_vertices.size())
	    break;

        std::map<int,std::deque<int> > wires;
        std::set<int> processed_edges;
        do {
            std::set<int> next_vertices;
            for(std::set<int>::iterator v=current_vertices.begin();
                v!=current_vertices.end();
                v++
            ) {
                for(std::set<int>::iterator e=v2e[*v].begin() ;
                    e!=v2e[*v].end();
                    e++
                ) {
                    if(processed_edges.count(*e))
			continue;

		    int other=e2v[*e].first==*v?
			e2v[*e].second:e2v[*e].first;

		    if(open_mode) {
			if(v2e[other].size()==1) {
			    // Other is open end too, finish wire.
			    wires[*v].push_back(*e);
			    std::deque<int>::const_iterator p;
			    BRepBuilderAPI_MakeWire wire;
			    if(verbose&Cutting)
                                std::cout << "CUT Open wire:";
			    for(p=wires[*v].begin();
				p!=wires[*v].end();
				p++
			    ) {
				FinishEdge(*p, v2e, e2v);
				wire.Add(edges[*p]);
				if(verbose&Cutting)
                                    std::cout << ' ' << (*p)+1;
			    }
			    if(verbose&Cutting)
                                std::cout << "\n";
			    push_back(wire);
			    goto next_vertex;
			}
		    } else {
			if( current_vertices.count(other) ||
			    next_vertices.count(other)
			) {
                            if(verbose&Cutting)
                                std::cout << "CUT Closed wire:";
			    wires[*v].push_back(*e);
			    while(wires[other].front()
				==wires[*v].front()
			    ) {
				wires[other].pop_front();
				wires[*v].pop_front();
			    }

			    BRepBuilderAPI_MakeWire wire;
			    std::deque<int>::const_iterator p;
			    for(p=wires[other].begin();
				p!=wires[other].end();
				p++
			    ) {
				FinishEdge(*p, v2e, e2v);
				wire.Add(edges[*p]);
                                if(verbose&Cutting)
                                    std::cout << ' ' << (*p)+1;
			    }
			    std::deque<int>::reverse_iterator rp;
			    for(rp=wires[*v].rbegin();
				rp!=wires[*v].rend();
				rp++
			    ) {
				FinishEdge(*rp, v2e, e2v);
				wire.Add(edges[*rp]);
                                if(verbose&Cutting)
                                    std::cout << ' ' << (*rp)+1;
			    }
                            if(verbose&Cutting)
                                std::cout << "\n";
			    push_back(wire);
			    goto next_vertex;
			}
		    }
		    if(current_vertices.count(other)==0) {
			wires[other]=wires[*v];
			wires[other].push_back(*e);
			processed_edges.insert(*e);
			next_vertices.insert(other);
		    }
                }
            }
            current_vertices=next_vertices;
        } while(current_vertices.size());
        next_vertex: ;
    }

    if(size()>1 && verbose&CuttingIntermediate) {
        if(verbose&Cutting)
            std::cout << "Saving multiple cuts\n";
        BRep_Builder BB;
        TopoDS_Compound compound;
        BB.MakeCompound(compound);
        for(int i=0; i<edges.size(); i++)
            BB.Add(compound,edges[i]);
        BRepTools::Write(compound,"cutter.brep");
        ofstream out("cutter.dot",ios::trunc|ios::out);
        dump(e2v,out);
    }
}

inline OCC_Connect::cutmap_t OCC_Connect::SelectCuttingEdges(
    TopTools_IndexedMapOfShape &edges,
    TopTools_IndexedMapOfShape &faces)
{
    cutmap_t cutters;
    for(int face=1;face<=faces.Extent();face++) {
        for(int edge=1;edge<=edges.Extent();edge++) {
            TopoDS_Edge c_edge=TopoDS::Edge(edges(edge));
            TopoDS_Face c_face=TopoDS::Face(faces(face));

            if(BRep_Tool::Degenerated(c_edge)) {
                if(verbose&CuttingReject)
                    cout << "Rejected(" << __LINE__ << ") edge " << edge
                        << " in face " << face << endl;
                continue;
            }

            TopTools_IndexedMapOfShape already_there;
            TopExp::MapShapes(c_face,TopAbs_EDGE,already_there);
            if(already_there.Contains(c_edge)) {
                if(verbose&CuttingReject)
                    cout << "Rejected(" << __LINE__ << ") edge " << edge
                        << " in face " << face << endl;
                continue;
            }

            BRepExtrema_DistShapeShape dist(c_edge,c_face);
            double tol=BRep_Tool::Tolerance(c_face);
            if(dist.Value()>tol) {
                if(verbose&CuttingReject)
                    cout << "Rejected(" << __LINE__ << ") edge " << edge
                        << " in face " << face << endl;
                continue;
            }

            Standard_Real s, e;
            Handle(Geom_Curve) c3d=BRep_Tool::Curve(c_edge,s,e);
            if(c3d.IsNull()) {
                if(verbose&CuttingReject)
                    cout << "Rejected(" << __LINE__ << ") edge " << edge
                        << " in face " << face << endl;
                continue;
            }

            // FIXME, checking only the middle may be a bit optimistic.
            TopoDS_Vertex vm=BRepBuilderAPI_MakeVertex(c3d->Value((s+e)/2));
            BRepExtrema_DistShapeShape dist_mf(vm,c_face);
            if(dist_mf.Value()>tol) {
                if(verbose&CuttingReject)
                    cout << "Rejected(" << __LINE__ << ") edge " << edge
                        << " in face " << face << endl;
                continue;
            }

            if(verbose&Cutting)
		cout << "Accepted edge " << edge << " in face " << face << endl;

            // Add missing PCurve if necessary
            Handle_Geom2d_Curve c=BRep_Tool::CurveOnSurface(c_edge,c_face,s,e);
            if(c.IsNull()) {
                if(verbose&Cutting)
                    cout << "Adding missing PCurve\n";
                ShapeFix_Edge().FixAddPCurve(c_edge,c_face,false,1e-7);
            }
            cutters[face].Add(c_edge);
        }
    }
    return cutters;
}

void OCC_Connect::Intersect(BRep_Builder &BB, TopoDS_Shape &target,
    TopoDS_Shape &shape, TopoDS_Shape &tool)
{
    int t=0;
    /***************************************************************************
      	We start by splitting edges at all the edge-edge intersections.
	This may generate new vertices and edges.
    ***************************************************************************/
    MergeVertices(shape,tool);
    LocOpe_SplitShape splitter1(shape);
    LocOpe_SplitShape splitter2(tool);
    TopOpeBRep_ShapeIntersector intersector;
    for(intersector.InitIntersection(shape,tool);
	intersector.MoreIntersection();
	intersector.NextIntersection()
    ) {
	if(verbose&Cutting) {
	    cout << "++++++++++++++++++++++++++++++++++++++++"
		"++++++++++++++++++++++++++++++++++++++++\n";
	    intersector.DumpCurrent(1); cout << " --> ";
	    intersector.DumpCurrent(2); cout << '\n';
	}

	TopOpeBRep_EdgesIntersector &ee=intersector.ChangeEdgesIntersector();
	if( intersector.CurrentGeomShape(1).ShapeType()==TopAbs_EDGE &&
            intersector.CurrentGeomShape(2).ShapeType()==TopAbs_EDGE
        ) {
	    for(ee.InitPoint(); ee.MorePoint(); ee.NextPoint()) {
		TopOpeBRep_Point2d const &p=ee.Point();
		if(verbose&Cutting)
		    cout << "point loop " << p.Parameter(1) << '\n';
		TopoDS_Vertex vertex;
		if(p.IsVertex(1))
		    vertex=p.Vertex(1);
		else if(p.IsVertex(2))
		    vertex=p.Vertex(2);
		else
		    vertex=BRepBuilderAPI_MakeVertex(p.Value());
		if(!p.IsVertex(1)) {
		    TopoDS_Edge edge=TopoDS::Edge(ee.Edge(1));
		    if(!splitter1.CanSplit(edge)) {
			if(verbose&Cutting)
			    cout << "Cannot split 1\n";;
		    } else {
			if(verbose&Cutting)
			    cout << "splitting model 1\n";
			try { splitter1.Add(vertex,p.Parameter(1),edge); }
			catch(Standard_ConstructionError c) {
			    if(verbose&Cutting)
				cout << "Ooops \n";
			}
		    }
		}
		if(!p.IsVertex(2)) {
		    TopoDS_Edge edge=TopoDS::Edge(ee.Edge(2));
		    if(!splitter2.CanSplit(edge)) {
			if(verbose&Cutting)
			    cout << "Cannot split 2\n";;
		    } else {
			if(verbose&Cutting)
			    cout << "splitting model 2\n";
			try { splitter2.Add(vertex,p.Parameter(2),edge); }
			catch(Standard_ConstructionError c) {
			    if(verbose&Cutting)
				cout << "Ooops \n";
			}
		    }
		}
	    }
	}
    }

    /***************************************************************************
        Not all intersections seem to be caught, this is an attempt to catch
        some missing intersections. FIXME, this is almost certainly incomplete.
    ***************************************************************************/
    TopTools_IndexedMapOfShape edges, faces, vertices;
    vertices.Clear();
    TopExp::MapShapes(shape,TopAbs_VERTEX,vertices);
    TopExp::MapShapes(tool,TopAbs_VERTEX,vertices);

    edges.Clear();
    TopExp::MapShapes(shape,TopAbs_EDGE,edges);
    for(int e=1; e<=edges.Extent(); e++) {
        TopoDS_Edge edge=TopoDS::Edge(edges(e));
        TopoDS_Vertex o1, o2;
        TopExp::Vertices(edge,o1,o2);
        int skip1=vertices.FindIndex(o1);
        int skip2=vertices.FindIndex(o2);
        for(int v=1; v<=vertices.Extent(); v++) {
            if(v==skip1 || v==skip2)
                continue;
            TopoDS_Vertex vertex=TopoDS::Vertex(vertices(v));
            BRepExtrema_ExtPC distance(vertex,edge);
            if(!distance.IsDone())
                continue;
            double tolerance=std::max(BRep_Tool::Tolerance(edge),
				      BRep_Tool::Tolerance(vertex));
            for(int i=1;i<=distance.NbExt();i++) {
                if(distance.Value(i)<tolerance) {
                    try {
                        // No idea why this can fail
                        splitter1.Add(vertex,distance.Parameter(i),edge);
                    }
                    catch(Standard_ConstructionError c) {
                        if(verbose&Cutting) {
                            cout << "Adding vertex to edge failed\n";
                            TopoDS_Vertex v1, v2;
                            TopExp::Vertices(edge,v1,v2);
                            if(BRepTools::Compare(v1,vertex))
                                cout << "Merge v1\n";
                            if(BRepTools::Compare(v2,vertex))
                                cout << "Merge v2\n";
                            double d1=BRep_Tool::Pnt(v1).Distance(
                                BRep_Tool::Pnt(vertex));
                            double d2=BRep_Tool::Pnt(v2).Distance(
                                BRep_Tool::Pnt(vertex));
                            cout << "Adding " << i << " to edge " << e
                                << " distance=" << distance.Value(i)
                                << " parameter=" << distance.Parameter(i)
                                << " point=" << distance.Point(i)
                                << " dv1=" << d1
                                << " dv2=" << d2
                                << endl;
                            BRepTools::Dump(vertex,cout);
                            BRepTools::Dump(edge,cout);
                        }
                    }
                }
            }
        }
    }

    edges.Clear();
    TopExp::MapShapes(tool,TopAbs_EDGE,edges);
    for(int e=1; e<=edges.Extent(); e++) {
        TopoDS_Edge edge=TopoDS::Edge(edges(e));
        TopoDS_Vertex o1, o2;
        TopExp::Vertices(edge,o1,o2);
        int skip1=vertices.FindIndex(o1);
        int skip2=vertices.FindIndex(o2);
        for(int v=1; v<=vertices.Extent(); v++) {
            if(v==skip1 || v==skip2)
                continue;
            TopoDS_Vertex vertex=TopoDS::Vertex(vertices(v));
            BRepExtrema_ExtPC distance(vertex,edge);
            if(!distance.IsDone())
                continue;
            double tolerance=std::max(BRep_Tool::Tolerance(edge),
				      BRep_Tool::Tolerance(vertex));
            for(int i=1;i<=distance.NbExt();i++) {
                if(distance.Value(i)<tolerance) {
                    try {
                        splitter2.Add(vertex,distance.Parameter(i),edge);
                    }
                    catch(Standard_ConstructionError c) {
                        if(verbose&Cutting) {
                            cout << "Adding vertex to edge failed\n";
                            TopoDS_Vertex v1, v2;
                            TopExp::Vertices(edge,v1,v2);
                            if(BRepTools::Compare(v1,vertex))
                                cout << "Merge v1\n";
                            if(BRepTools::Compare(v2,vertex))
                                cout << "Merge v2\n";
                            double d1=BRep_Tool::Pnt(v1).Distance(
                                BRep_Tool::Pnt(vertex));
                            double d2=BRep_Tool::Pnt(v2).Distance(
                                BRep_Tool::Pnt(vertex));
                            cout << "Adding " << i << " to edge " << e
                                << " distance=" << distance.Value(i)
                                << " parameter=" << distance.Parameter(i)
                                << " point=" << distance.Point(i)
                                << " dv1=" << d1
                                << " dv2=" << d2
                                << endl;
                            BRepTools::Dump(vertex,cout);
                            BRepTools::Dump(edge,cout);
                        }
                    }
                }
            }
        }
    }

    /***************************************************************************
      	We need the shapes with all the edge-edge intersections to split
	all the faces. All vertices and edges which can be merged, will
	be merged.
    ***************************************************************************/
    TopoDS_Compound intermediate1;
    BB.MakeCompound(intermediate1);
    for(TopTools_ListIteratorOfListOfShape p(splitter1.DescendantShapes(shape));
	p.More();
	p.Next()
    ) {
	BB.Add(intermediate1,p.Value());
    }
    TopoDS_Compound intermediate2;
    BB.MakeCompound(intermediate2);
    for(TopTools_ListIteratorOfListOfShape p(splitter2.DescendantShapes(tool));
	p.More();
	p.Next()
    ) {
	BB.Add(intermediate2,p.Value());
    }
    if(verbose&Cutting) {
	cout << "Before merging vertices and edges\n";
	TopoDS_Compound t;
	BB.MakeCompound(t);
	BB.Add(t,intermediate1);
	BB.Add(t,intermediate2);
	PrintItemCount(t);
    }
    MergeVertices(intermediate1,intermediate2);
    MergeEdges(intermediate1,intermediate2);
    if(verbose&Cutting) {
	cout << "After merging vertices and edges\n";
	TopoDS_Compound t;
	BB.MakeCompound(t);
	BB.Add(t,intermediate1);
	BB.Add(t,intermediate2);
	PrintItemCount(t);
    }

    // Create the result
    TopoDS_Compound result;
    BB.MakeCompound(result);
    BB.Add(result,intermediate1);
    BB.Add(result,intermediate2);

    // Add any missing PCurves
    for(TopExp_Explorer face(result,TopAbs_FACE); face.More(); face.Next()) {
	for(TopExp_Explorer edge(face.Current(),TopAbs_EDGE);
	    edge.More();
	    edge.Next()
	) {
            Standard_Real s, e;
            TopoDS_Edge c_edge=TopoDS::Edge(edge.Current());
            TopoDS_Face c_face=TopoDS::Face(face.Current());
            Handle_Geom2d_Curve c=BRep_Tool::CurveOnSurface(c_edge,c_face,s,e);
            if(c.IsNull()) {
                if(verbose&Cutting)
                    cout << "Adding missing PCurve\n";
                ShapeFix_Edge().FixAddPCurve(c_edge,c_face,false,1e-7);
            }
	}
    }

    /***************************************************************************
	We determine which edges/wires are going to cut a face. To do this
	we create a map of FaceCutters which is indexed by the face number
	in the faces map. The FaceCutters generate the correct cutting wires.
    ***************************************************************************/
    int retry;
do {
    if(verbose&Cutting)
        std::cout << "STARTED CUTTING\n";
    retry=0;
    edges.Clear(); TopExp::MapShapes(result,TopAbs_EDGE,edges);
    faces.Clear(); TopExp::MapShapes(result,TopAbs_FACE,faces);
    cutmap_t cutters=SelectCuttingEdges(edges,faces);

    /***************************************************************************
	Apply all face splits stored in the map.
    ***************************************************************************/
    int cut_count=0;
    LocOpe_SplitShape splitter(result);
    for(cutmap_t::iterator f=cutters.begin(); f!=cutters.end(); f++) {
        TopoDS_Face const &face=TopoDS::Face(faces(f->first));
        FaceCutters &cutter=f->second;
        cut_count+=cutter.size();
	if(verbose&Cutting) {
            cout << "Cutting face " << f->first << " *************************\n";
	    BRepTools::Dump(face,cout);
        }
        cutter.Build(face,result,verbose);
        for(FaceCutters::iterator p=cutter.begin(); p!=cutter.end(); p++) {
            TopTools_IndexedMapOfShape edges;
            TopExp::MapShapes(*p,TopAbs_EDGE,edges);
            if(edges.Extent()<3 && BRep_Tool::IsClosed(*p)) {
                // FIXME This doesn't work.
                cout << "IGNORED Closed wire with less than three edges\n";
                continue;
            }
	    //BRepTools::Dump(*p,cout);
	    try {
                splitter.Add(*p,face);
	    }
            catch(Standard_ConstructionError c) {
                cout << "splitting the face failed\n";
                retry=1;
            }
        }
    }
    if(verbose&Cutting)
        cout << cut_count << " cuts in " << cutters.size() << " faces\n";

    // Create the final shape with the cutted faces.
    TopoDS_Compound cutted;
    BB.MakeCompound(cutted);
    int count=0;
    for(TopTools_ListIteratorOfListOfShape p(splitter.DescendantShapes(result));
	p.More();
	p.Next()
    ) {
	if(++count==1) {
            if(verbose&Cutting) {
                cout << "--------- " << count << " ---------------------------\n";
                BRepTools::Dump(p.Value(),cout);
            }
            BB.Add(cutted,p.Value());
        }
    }
    MergeFaces(cutted);
    result=cutted;
} while(0 && retry);
    target=result;
}

void OCC_Connect::MergeVertices(TopoDS_Shape &shape1,TopoDS_Shape &shape2) const
{
    TopTools_IndexedMapOfShape imap, omap;
    TopExp::MapShapes(shape1,TopAbs_VERTEX,imap);
    TopExp::MapShapes(shape2,TopAbs_VERTEX,imap);
    BRepTools_ReShape replacer;
    for(int i=0;i<imap.Extent();i++) {
        for(int j=0;j<omap.Extent();j++) {
	    TopoDS_Vertex orig=TopoDS::Vertex(imap(i+1));
	    TopoDS_Vertex repl=TopoDS::Vertex(omap(j+1));
            if(BRepTools::Compare(orig,repl)) {
		repl.Orientation(orig.Orientation());
		replacer.Replace(orig,repl);
		// FIXME, tolerance and point should be updated
                goto skip;
            }
        }
        omap.Add(imap(i+1));
    skip:;
    }
    TopoDS_Shape t=shape1;
    shape1=replacer.Apply(t);
    t=shape2;
    shape2=replacer.Apply(t);
}

bool OCC_Connect::CanMergeCurve(TopoDS_Edge edge1,TopoDS_Edge edge2) const
{
    if(BRep_Tool::Degenerated(edge1) && BRep_Tool::Degenerated(edge2))
	return 1;

    double tol=1e-7;

    Standard_Real s,e;
    Handle(Geom_Curve) curve=BRep_Tool::Curve(edge1,s,e);
    for(Standard_Real i=s;i<=e;i+=(e-s)/10) {
	TopoDS_Vertex v=BRepBuilderAPI_MakeVertex(curve->Value(i));
	double dist=BRepExtrema_DistShapeShape(edge2,v).Value();
	if(dist>tol)
	    return 0;
    }
    return 1;
}

void OCC_Connect::MergeEdges(TopoDS_Shape &shape1, TopoDS_Shape &shape2) const
{
    TopTools_IndexedMapOfShape imap, omap;
    TopExp::MapShapes(shape1,TopAbs_EDGE,imap);
    TopExp::MapShapes(shape2,TopAbs_EDGE,imap);
    BRepTools_ReShape replacer;
    for(int i=0;i<imap.Extent();i++) {
        for(int j=0;j<omap.Extent();j++) {
	    TopoDS_Edge orig=TopoDS::Edge(imap(i+1));
	    TopoDS_Edge repl=TopoDS::Edge(omap(j+1));

	    TopoDS_Vertex o1, o2, r1, r2;
	    TopExp::Vertices(orig,o1,o2,true);
	    TopExp::Vertices(repl,r1,r2,true);

	    if(o1.IsSame(o2)) {
		if(!BRep_Tool::Degenerated(orig)) {
		    if(verbose&Cutting) {
			cout << "Same vertex in edge\n";
			BRepTools::Dump(orig,cout);
		    }
		    replacer.Remove(orig);
		    goto skip;
		} else if(o1.IsSame(r1) && o1.IsSame(r2)
		    && CanMergeCurve(orig,repl)
		) {
		    if(verbose&Cutting) {
			cout << "Degenerated edge, replace " << i+1
			    << " with " << j+1 << '\n';
			BRepTools::Dump(orig,cout);
			BRepTools::Dump(repl,cout);
		    }
		    // FIXME, update tolerance
		    BRepTools::Dump(repl.Complemented(),cout);
		    replacer.Replace(orig,repl.Complemented());
		    goto skip;
		}
		cout << i+1 << " Degenerated\n";
	    }
	    if(o1.IsSame(r1) && o2.IsSame(r2) && CanMergeCurve(orig,repl))  {
                if(verbose&Cutting) {
                    cout << "Same order of vertices, replace " << i+1
                        << " with " << j+1 << '\n';
                    BRepTools::Dump(orig,cout);
                    BRepTools::Dump(repl,cout);
                }
		// FIXME, update tolerance
		replacer.Replace(orig,repl);
		goto skip;
            }
	    if(o1.IsSame(r2) && o2.IsSame(r1) && CanMergeCurve(orig,repl)) {
                if(verbose&Cutting) {
                    cout << "Reversed order of vertices, replace " << i+1
                        << " with " << j+1 << '\n';
                    BRepTools::Dump(orig,cout);
                    BRepTools::Dump(repl,cout);
                }
		// FIXME, update tolerance
		replacer.Replace(orig,repl.Complemented());
		goto skip;
            }
        }
        if(verbose&Cutting)
            cout << "Adding " << i+1 << " as " << omap.Extent()+1<<" to keep map\n";
        omap.Add(imap(i+1));
    skip:;
    }
    TopoDS_Shape t=shape1;
    shape1=replacer.Apply(t);
    t=shape2;
    shape2=replacer.Apply(t);
}

bool OCC_Connect::CanMergeFace(TopoDS_Face face1,TopoDS_Face face2) const
{
    // FIXME, this really does not work.
    return 1;

    double tol=1e-7;

    Handle(Geom_Surface) surface=BRep_Tool::Surface(face1);
    Standard_Real u1, u2, v1, v2;
    surface->Bounds(u1,u2,v1,v2);
    cout << "u1=" << u1 << " u2=" << u2 << " v1=" << v1 << " v2=" << v2 << endl;
    for(Standard_Real u=u1+(u2-u1)/10;u<u2;u+=(u2-u1)/10) {
        for(Standard_Real v=v1+(v2-v1)/10;v<v2;v+=(v2-v1)/10) {
            TopoDS_Vertex vtx=BRepBuilderAPI_MakeVertex(surface->Value(u,v));
            BRepExtrema_DistShapeShape dss(face2,vtx);
            dss.Perform();
#if 0
            double dist=dss.Value();
            if(dist>tol) {
                cout << "Distance=" << dist << " v=" << v << " u=" << u
                    << " pnt=" << surface->Value(u,v) << endl;
                BRepTools::Dump(face2,cout);
                return 0;
            }
#else
            dss.Dump(cout);
#endif
        }
    }
    return 1;
}

void OCC_Connect::MergeFaces(TopoDS_Shape &shape) const
{
    /***************************************************************************
        We must find faces which are the same. Since all edges are already
	merged, we know that faces which can be merged have identical edges.
    ***************************************************************************/
    TopTools_IndexedMapOfShape faces, edges;
    TopExp::MapShapes(shape,TopAbs_FACE,faces);
    TopExp::MapShapes(shape,TopAbs_EDGE,edges);
    mapping_t mapping;
    for(int i=0;i<faces.Extent();i++) {
        std::set<int> face_edges;
        for(TopExp_Explorer p(faces(i+1),TopAbs_EDGE); p.More(); p.Next()) {
            int edge=edges.FindIndex(p.Current());
            if(BRep_Tool::Degenerated(TopoDS::Edge(edges(edge)))) {
		cout << "Degenerate edge " << edge << " inserted a 0\n";
		face_edges.insert(0);
	    } else
		face_edges.insert(edge);
        }
        mapping[face_edges].insert(i+1);
    }

    if(verbose&Cutting) {
        for(mapping_t::iterator p=mapping.begin(); p!=mapping.end(); p++)
            cout << "edges [ " << p->first << "] in face"
                << (p->second.size()<2? " ":"s ") << "[ " << p->second << "]\n";
    }

    /***************************************************************************
        If two faces have an identical set of edges, they can be merged
	when the planes are never seperated by more than the tolerance.
    ***************************************************************************/
    BRepTools_ReShape replacer;
    for(mapping_t::iterator p=mapping.begin(); p!=mapping.end(); p++) {
        if(p->second.size()<2)
            continue;
        std::vector<int> uniq;
        for(std::set<int>::iterator q=p->second.begin();
            q!=p->second.end();
            q++
        ) {
            for(std::vector<int>::iterator r=uniq.begin(); r!=uniq.end(); r++) {
                TopoDS_Face orig=TopoDS::Face(faces(*q));
                TopoDS_Face repl=TopoDS::Face(faces(*r));
                if(verbose&Cutting)
                    cout << "Check face " << *q << " and " << *r << endl;
                if(CanMergeFace(orig,repl)) {
                    if(verbose&Cutting) {
                        cout << "replace face " << *q << " with " << *r << '\n';
                    }
                    repl.Orientation(orig.Orientation());
                    replacer.Replace(orig,repl);
                    // FIXME, tolerance should be updated
                    goto skip;
                }
            }
            uniq.push_back(*q);
        skip:;
        }
    }

    TopoDS_Shape t=shape;
    shape=replacer.Apply(t);
}

void OCC_Connect::PrintItemCount(TopoDS_Shape const &shape) const
{
    TopTools_IndexedMapOfShape imap;
    TopExp::MapShapes(shape,TopAbs_VERTEX,imap);
    cout << "Input map contains " << imap.Extent() << " vertices\n";
    imap.Clear();
    TopExp::MapShapes(shape,TopAbs_EDGE,imap);
    cout << "Input map contains " << imap.Extent() << " edges\n";
    imap.Clear();
    TopExp::MapShapes(shape,TopAbs_FACE,imap);
    cout << "Input map contains " << imap.Extent() << " faces\n";
    imap.Clear();
    TopExp::MapShapes(shape,TopAbs_SOLID,imap);
    cout << "Input map contains " << imap.Extent() << " solids\n";
    imap.Clear();
    TopExp::MapShapes(shape,TopAbs_COMPSOLID,imap);
    cout << "Input map contains " << imap.Extent() << " compsolids\n";
    imap.Clear();
    TopExp::MapShapes(shape,TopAbs_COMPOUND,imap);
    cout << "Input map contains " << imap.Extent() << " compounds\n";
}

#endif

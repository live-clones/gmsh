// Connected short collars, co-refined together in a spatially selected region.
// Contact endpoints split the propagation domain; no graph flood can go behind
// a finite barrier. The filtered MAT and previously deposited layers are fixed.
#include "MatPipeline.h"
#include "MatExtensionInternal.h"
#include "DiscreteCADArrangement.h"
#include "DiscreteCADMeshBoolean.h"
#include "DiscreteCADWinding.h"
#include "rtree.h"
#include "robustPredicates.h"
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <utility>

namespace matgmsh_native {
namespace {
using P = std::array<double, 3>;
using UV = std::array<double, 2>;
using Edge = std::pair<int, int>;
using Segment = std::array<double,6>;
P point(const Mesh &m, int i) { return {{m.xyz[3*i],m.xyz[3*i+1],m.xyz[3*i+2]}}; }
P add(P a, const P &b) { for(int k=0;k<3;k++) a[k]+=b[k];return a; }
P sub(P a, const P &b) { for(int k=0;k<3;k++) a[k]-=b[k];return a; }
P mul(P a, double s) { for(double &v:a)v*=s;return a; }
double dot(const P &a,const P &b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
P cross(const P &a,const P &b) {return {{a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]}};}
double norm(const P &a) {return std::sqrt(dot(a,a));}
P unit(P a) {double n=norm(a);return n>0.?mul(a,1./n):P{{0,0,0}};}
Edge key(int a,int b) {return std::minmax(a,b);}
Segment segment(P a,P b) {
  if(b<a)std::swap(a,b);
  return {{a[0],a[1],a[2],b[0],b[1],b[2]}};
}
P normal(const Mesh &m,int f) {return cross(sub(point(m,m.triangles[3*f+1]),point(m,m.triangles[3*f])),sub(point(m,m.triangles[3*f+2]),point(m,m.triangles[3*f])));}
double area(const Mesh &m,int f) {return .5*norm(normal(m,f));}
bool hasArea(const Mesh&m,int f) {
  P p[3];for(int k=0;k<3;k++)p[k]=point(m,m.triangles[3*f+k]);
  for(int i=0;i<3;i++) {
    int j=(i+1)%3;double a[2]={p[0][i],p[0][j]},b[2]={p[1][i],p[1][j]},c[2]={p[2][i],p[2][j]};
    if(robustPredicates::orient2d(a,b,c)!=0.)return true;
  }
  return false;
}
double pointRoundoff(const P&p) {
  P ulp;for(int k=0;k<3;k++){double x=std::abs(p[k]);ulp[k]=std::nextafter(x,std::numeric_limits<double>::infinity())-x;}
  return 8.*std::hypot(ulp[0],ulp[1],ulp[2]);
}
double areaRoundoff(const Mesh&m,int f) {
  P p[3];double d[3];for(int k=0;k<3;k++){p[k]=point(m,m.triangles[3*f+k]);d[k]=pointRoundoff(p[k]);}
  return .5*(d[0]*norm(sub(p[1],p[2]))+d[1]*norm(sub(p[2],p[0]))+
             d[2]*norm(sub(p[0],p[1]))+d[0]*d[1]+d[1]*d[2]+d[2]*d[0]);
}
int owner(const Mesh &m,int f) {return m.branch.empty()?0:m.branch[f];}
int parent(const Mesh &m,int f) {return m.parent.empty()?f:m.parent[f];}
using Uses = std::map<Edge,std::vector<int> >;
Uses incidence(const Mesh &m) {
  Uses e;
  for(int f=0;f<int(m.triangles.size()/3);f++)for(int k=0;k<3;k++)
    e[key(m.triangles[3*f+k],m.triangles[3*f+(k+1)%3])].push_back(f);
  return e;
}
void compact(Mesh &m) {
  std::vector<int> map(m.xyz.size()/3,-1);std::vector<double>x;
  for(int &v:m.triangles){if(map[v]<0){map[v]=int(x.size()/3);P p=point(m,v);x.insert(x.end(),p.begin(),p.end());}v=map[v];}
  m.xyz.swap(x);
}
// Barycentric coordinates on a known parent triangle, used only to transport
// the band's propagation coordinates through native Boolean lineage.
bool barycentric(const Mesh &m,int f,const P &p,std::array<double,3>&w) {
  P n=normal(m,f);int drop=0;
  for(int k=1;k<3;k++)if(std::abs(n[k])>std::abs(n[drop]))drop=k;
  const int i=(drop+1)%3,j=(drop+2)%3;
  P a=point(m,m.triangles[3*f]),b=point(m,m.triangles[3*f+1]),c=point(m,m.triangles[3*f+2]);
  double aa[2]={a[i],a[j]},bb[2]={b[i],b[j]},cc[2]={c[i],c[j]},pp[2]={p[i],p[j]};
  const double determinant=robustPredicates::orient2d(aa,bb,cc);
  if(determinant==0.)return false;
  w[0]=robustPredicates::orient2d(pp,bb,cc)/determinant;
  w[1]=robustPredicates::orient2d(aa,pp,cc)/determinant;
  w[2]=1.-w[0]-w[1];return true;
}
struct SkinQuery {
  const Mesh &mesh;
  double tolerance;
  RTree<std::size_t,double,3,double> tree;
  SkinQuery(const Mesh &m,double t):mesh(m),tolerance(t) {
    for(int f=0;f<int(m.triangles.size()/3);f++) {
      P lo=point(m,m.triangles[3*f]),hi=lo;
      for(int j=1;j<3;j++){P p=point(m,m.triangles[3*f+j]);for(int k=0;k<3;k++){lo[k]=std::min(lo[k],p[k]);hi[k]=std::max(hi[k],p[k]);}}
      tree.Insert(lo.data(),hi.data(),f);
    }
  }
  struct Search {const SkinQuery *query;P p;bool found=false;};
  static bool visit(std::size_t triangle,void *ctx) {
    const int f=static_cast<int>(triangle);
    Search &s=*static_cast<Search*>(ctx);const Mesh&m=s.query->mesh;
    P n=normal(m,f);double length=norm(n);if(!(length>0.))return true;
    P a=point(m,m.triangles[3*f]);double distance=dot(sub(s.p,a),n)/length;
    if(std::abs(distance)>s.query->tolerance)return true;
    std::array<double,3>w;
    if(!barycentric(m,f,s.p,w))return true;
    double scale=std::max({norm(sub(a,point(m,m.triangles[3*f+1]))),norm(sub(a,point(m,m.triangles[3*f+2]))),s.query->tolerance});
    double eps=4*s.query->tolerance/scale;
    if(*std::min_element(w.begin(),w.end())>=-eps){s.found=true;return false;}
    return true;
  }
  bool on(const P &p) {
    P lo=p,hi=p;for(int k=0;k<3;k++){lo[k]-=tolerance;hi[k]+=tolerance;}
    Search search{this,p,false};tree.Search(lo.data(),hi.data(),visit,&search);return search.found;
  }
  bool onEdge(const P&a,const P&b) {return on(a)&&on(b)&&on(mul(add(a,b),.5));}
  struct Envelope {const Mesh*skin;std::array<P,3>p;bool found=false;};
  static double distanceToTriangle(const Mesh&m,int f,const P&p) {
    P a=point(m,m.triangles[3*f]),n=unit(normal(m,f));
    double distance=dot(sub(p,a),n);P projected=sub(p,mul(n,distance));
    std::array<double,3>w;
    if(barycentric(m,f,projected,w)&&*std::min_element(w.begin(),w.end())>=0.)return std::abs(distance);
    double best=std::numeric_limits<double>::infinity();
    for(int k=0;k<3;k++) {
      P x=point(m,m.triangles[3*f+k]),d=sub(point(m,m.triangles[3*f+(k+1)%3]),x);
      double t=std::max(0.,std::min(1.,dot(sub(p,x),d)/dot(d,d)));
      best=std::min(best,norm(sub(p,add(x,mul(d,t)))));
    }
    return best;
  }
  static bool envelopeVisit(std::size_t face,void*data) {
    Envelope&e=*static_cast<Envelope*>(data);double radius=0.;
    for(const P&p:e.p)radius=std::max(radius,pointRoundoff(p));
    for(int k=0;k<3;k++)radius=std::max(radius,pointRoundoff(point(*e.skin,e.skin->triangles[3*face+k])));
    if(!std::isfinite(radius))return true;
    for(const P&p:e.p)if(distanceToTriangle(*e.skin,int(face),p)>radius)return true;
    e.found=true;return false;
  }
  bool inRoundoffEnvelope(const Mesh&m,int f) {
    Envelope e{&mesh,{{point(m,m.triangles[3*f]),point(m,m.triangles[3*f+1]),point(m,m.triangles[3*f+2])}},false};
    P lo=e.p[0],hi=lo;double pad=std::max(tolerance,pointRoundoff(e.p[0]));
    for(int k=0;k<3;k++){lo[k]-=pad;hi[k]+=pad;}
    tree.Search(lo.data(),hi.data(),envelopeVisit,&e);return e.found;
  }
};
// The exact cut of a binary64 mesh can lie an ulp outside an oblique binary64
// skin after coordinate export. This is an explicit numerical envelope, not
// exact containment: every outside descendant must fit near ONE common skin
// triangle (its neighborhood is convex), and its total area is capped per
// source triangle independently of the number of subdivisions. The stricter
// projection guard remains unchanged.
bool containedWithRoundoff(const Mesh&m,const Mesh&skin,SkinQuery&query,
                          DiscreteCADWinding&winding,std::string&error,double*outArea=nullptr) {
  Mesh soup=m;const int nv=int(m.xyz.size()/3),nf=int(m.triangles.size()/3);
  soup.xyz.insert(soup.xyz.end(),skin.xyz.begin(),skin.xyz.end());
  for(int v:skin.triangles)soup.triangles.push_back(v+nv);
  Mesh cut;std::vector<int>birth;
  if(!meshCoRefine(soup.xyz,soup.triangles,cut.xyz,cut.triangles,birth,error))return false;
  std::vector<double>covered(nf,0.),outside(nf,0.),roundoff(nf,0.);
  std::vector<int>descendants(nf,0);
  for(int f=0;f<int(birth.size());f++)if(birth[f]>=0&&birth[f]<nf&&hasArea(cut,f)) {
    int b=birth[f];double a=area(cut,f);P p=point(cut,cut.triangles[3*f]);
    P center=add(p,mul(add(sub(point(cut,cut.triangles[3*f+1]),p),sub(point(cut,cut.triangles[3*f+2]),p)),1./3));
    double w=std::abs(winding(center.data()));
    if(!std::isfinite(w)||w<=.5+1.e-5)w=std::abs(winding.exact(center.data()));
    if(!std::isfinite(w)||w<=.5+1.e-9) {
      if(!query.inRoundoffEnvelope(cut,f)){error="extension triangle "+std::to_string(b)+" leaves the skin beyond coordinate roundoff";return false;}
      outside[b]+=a;
    }
    descendants[b]++;covered[b]+=a;roundoff[b]+=areaRoundoff(cut,f);
  }
  double total=0.;
  for(int f=0;f<nf;f++) {
    if(!descendants[f]||std::abs(covered[f]-area(m,f))>1.e-8*area(m,f)+roundoff[f]+areaRoundoff(m,f)+1.e-24) {
      error="extension containment lost source triangle "+std::to_string(f);return false;
    }
    if(outside[f]>areaRoundoff(m,f)) {error="outside area exceeds source coordinate-roundoff budget for triangle "+std::to_string(f);return false;}
    total+=outside[f];
  }
  if(outArea)*outArea=total;return true;
}
bool onSegment(const P&p,const P&a,const P&b,double tolerance) {
  const P d=sub(b,a);const double d2=dot(d,d);
  if(!(d2>0.))return norm(sub(p,a))<=tolerance;
  const double t=dot(sub(p,a),d)/d2;
  return t>=-tolerance/std::sqrt(d2)&&t<=1.+tolerance/std::sqrt(d2)&&
    norm(sub(p,add(a,mul(d,t))))<=tolerance;
}
using Motion = std::array<P,3>;
enum Kind { Fixed, Material, Proposal };
struct Face {
  Kind kind=Fixed;
  int source=-1;
  Motion velocity{};
};
struct Collar {
  int a,b,root,branch;
  P start,end,tipA,tipB,tangent,outward;
  double edgeLength,step;
  std::vector<std::array<P,2> > contacts;
  UV uv(const P&p) const {
    const P d=sub(p,start);
    return {{dot(d,tangent)/edgeLength,dot(d,outward)/step}};
  }
  bool on(const Edge&e,const Mesh&m,const P&a,const P&b,double tolerance) const {
    return onSegment(point(m,e.first),a,b,tolerance)&&onSegment(point(m,e.second),a,b,tolerance);
  }
  bool rootEdge(const Edge&e,const Mesh&m,double t) const {return on(e,m,start,end,t);}
  bool seam(const Edge&e,const Mesh&m,double t) const {
    return on(e,m,start,tipA,t)||on(e,m,end,tipB,t);
  }
};
// Clip the whole triangle to a contact's transverse interval. Testing just
// its centroid would retain triangles crossing a finite obstacle's shadow.
bool pastContact(const std::array<UV,3>&triangle,const UV&a,const UV&b) {
  const double lo=std::min(a[0],b[0]),hi=std::max(a[0],b[0]);
  if(hi-lo<1.e-10)return false;
  std::vector<UV> polygon(triangle.begin(),triangle.end());
  for(int side=0;side<2;side++) {
    std::vector<UV> clipped;
    for(std::size_t i=0;i<polygon.size();i++) {
      UV p=polygon[i],q=polygon[(i+1)%polygon.size()];
      const double dp=side?hi-p[0]:p[0]-lo,dq=side?hi-q[0]:q[0]-lo;
      if(dp>=0.)clipped.push_back(p);
      if((dp>=0.)!=(dq>=0.)) {
        double t=dp/(dp-dq);
        clipped.push_back({{p[0]+t*(q[0]-p[0]),p[1]+t*(q[1]-p[1])}});
      }
    }
    polygon.swap(clipped);if(polygon.empty())return false;
  }
  double minU=std::numeric_limits<double>::max(),maxU=-minU;
  for(const UV&p:polygon){minU=std::min(minU,p[0]);maxU=std::max(maxU,p[0]);}
  // A triangle touching the side of the shadow only along an edge is outside.
  if(maxU-minU<1.e-10)return false;
  for(const UV&p:polygon) {
    double s=a[1]+(p[0]-a[0])*(b[1]-a[1])/(b[0]-a[0]);
    if(p[1]>s+1.e-7)return true;
  }
  return false;
}
// Carry velocity through native triangle lineage, rather than fitting a new
// vector field after every intersection. Existing geometry stays fixed.
bool refine(const Mesh&in,const std::vector<Face>&info,Mesh&out,
            std::vector<Face>&outInfo,std::vector<int>&mapping,
            std::string&error,const std::vector<int>*targets=nullptr) {
  std::vector<int>birth;
  if(!meshCoRefine(in.xyz,in.triangles,out.xyz,out.triangles,birth,error,&mapping,targets))return false;
  std::vector<int>triangles;triangles.reserve(out.triangles.size());
  for(int f=0;f<int(birth.size());f++) {
    if(!hasArea(out,f))continue;
    int b=birth[f];
    if(b<0||b>=int(info.size())){error="invalid open co-refinement lineage";return false;}
    Face face=info[b];
    for(int k=0;k<3;k++) {
      std::array<double,3>w;
      if(!barycentric(in,b,point(out,out.triangles[3*f+k]),w)){error="degenerate co-refinement parent";return false;}
      face.velocity[k]={{0,0,0}};
      for(int j=0;j<3;j++)face.velocity[k]=add(face.velocity[k],mul(info[b].velocity[j],w[j]));
    }
    outInfo.push_back(face);out.branch.push_back(owner(in,b));out.parent.push_back(parent(in,b));
    triangles.insert(triangles.end(),out.triangles.begin()+3*f,out.triangles.begin()+3*f+3);
  }
  out.triangles.swap(triangles);return true;
}
void addFace(Mesh&m,std::vector<Face>&info,int a,int b,int c,
             int branch,int parent,const Face&face) {
  m.triangles.insert(m.triangles.end(),{a,b,c});m.branch.push_back(branch);
  m.parent.push_back(parent);info.push_back(face);
}
int addPoint(Mesh&m,const P&p) {int i=int(m.xyz.size()/3);m.xyz.insert(m.xyz.end(),p.begin(),p.end());return i;}
void bounds(const Mesh&m,int f,P&lo,P&hi,double pad=0.) {
  lo=hi=point(m,m.triangles[3*f]);
  for(int j=1;j<3;j++)for(int k=0;k<3;k++) {
    double v=m.xyz[3*m.triangles[3*f+j]+k];lo[k]=std::min(lo[k],v);hi[k]=std::max(hi[k],v);
  }
  for(int k=0;k<3;k++){lo[k]-=pad;hi[k]+=pad;}
}
bool collect(std::size_t f,void*p) {static_cast<std::set<int>*>(p)->insert(int(f));return true;}
// Co-refine only triangles near a proposed collar. All source vertices stay in
// the index map so untouched triangles can be stitched by identity, not a weld.
bool growLayer(const Mesh&grown,const std::vector<Motion>&velocity,
               const Mesh&skin,SkinQuery&skinQuery,DiscreteCADWinding&winding,
               const Mesh&initial,const std::vector<FrontStatus>&roots,
               double step,double tolerance,Mesh&next,std::vector<Motion>&nextVelocity,
               std::vector<char>&contacted,std::size_t&cuts,std::size_t&splits,
               const std::set<Segment>&blocked,std::set<Segment>&rejected,
               std::map<int,std::string>&reasons,std::string&error) {
  const Uses edges=incidence(grown);
  Mesh soup;soup.xyz=grown.xyz;std::vector<Face>info;
  std::vector<Collar>collars;
  std::map<std::pair<int,int>,int>tips;
  std::map<std::pair<int,int>,std::pair<P,int> >motion;
  for(const auto&e:edges)if(e.second.size()==1) {
    int f=e.second[0];
    for(int v:{e.first.first,e.first.second})for(int k=0;k<3;k++)if(grown.triangles[3*f+k]==v) {
      auto&sum=motion[{owner(grown,f),v}];sum.first=add(sum.first,velocity[f][k]);sum.second++;
    }
  }
  for(auto&m:motion)m.second.first=mul(m.second.first,1./m.second.second);
  std::map<int,std::vector<int> >faceRoots;
  std::map<Edge,int>originalRoot;
  for(int i=0;i<int(roots.size());i++)originalRoot[key(roots[i].a,roots[i].b)]=i;
  const Uses initialEdges=incidence(initial);
  for(const auto&e:originalRoot)for(int f:initialEdges.at(e.first))faceRoots[f].push_back(e.second);
  for(const auto&e:edges)if(e.second.size()==1) {
    const int f=e.second[0];int a=-1,b=-1;
    for(int k=0;k<3;k++)if(key(grown.triangles[3*f+k],grown.triangles[3*f+(k+1)%3])==e.first) {
      a=grown.triangles[3*f+k];b=grown.triangles[3*f+(k+1)%3];break;
    }
    P x=point(grown,a),y=point(grown,b);
    if(skinQuery.onEdge(x,y)||blocked.count(segment(x,y)))continue;
    int root=-1;
    if(grown.parent[f]<-1)root=-2-grown.parent[f];
    else for(int r:faceRoots[grown.parent[f]]) {
      if(onSegment(x,point(initial,roots[r].a),point(initial,roots[r].b),tolerance)&&
         onSegment(y,point(initial,roots[r].a),point(initial,roots[r].b),tolerance)){root=r;break;}
    }
    if(root<0)continue;
    P da=motion[{owner(grown,f),a}].first,db=motion[{owner(grown,f),b}].first;
    P n=normal(grown,f),outward=unit(cross(sub(y,x),n));
    // A shadow side parallel to the characteristic creates no area. It is
    // left explicit, not silently declared a contact or pushed sideways.
    if(std::max(dot(da,outward),dot(db,outward))<=1.e-8)continue;
    Collar c{a,b,root,owner(grown,f),x,y,add(x,mul(da,step)),add(y,mul(db,step)),
             unit(sub(y,x)),outward,norm(sub(y,x)),step,{}};
    P n0=cross(sub(x,y),sub(c.tipA,y)),n1=cross(sub(c.tipA,y),sub(c.tipB,y));
    const bool valid0=norm(n0)>1.e-20*step*step,valid1=norm(n1)>1.e-20*step*step;
    if((!valid0&&!valid1)||(valid0&&dot(n0,n)<1.e-3*norm(n0)*norm(n))||
       (valid1&&dot(n1,n)<1.e-3*norm(n1)*norm(n)))continue;
    auto tip=[&](int v,const P&p) {
      auto id=std::make_pair(c.branch,v);auto it=tips.find(id);
      if(it!=tips.end())return it->second;
      int index=addPoint(soup,p);tips[id]=index;return index;
    };
    int ta=tip(a,c.tipA),tb=tip(b,c.tipB),ci=int(collars.size());collars.push_back(c);
    if(valid0)addFace(soup,info,b,a,ta,c.branch,-2-root,{Proposal,ci,{{db,da,da}}});
    if(valid1)addFace(soup,info,b,ta,tb,c.branch,-2-root,{Proposal,ci,{{db,da,db}}});
  }
  if(collars.empty()){error="no nonfolding front remains";return false;}
  SkinQuery grownQuery(grown,tolerance);
  std::set<int>nearGrown,nearSkin;
  const int proposalFaces=int(info.size());
  for(int f=0;f<proposalFaces;f++) {
    P lo,hi;bounds(soup,f,lo,hi,tolerance);
    grownQuery.tree.Search(lo.data(),hi.data(),collect,&nearGrown);
    skinQuery.tree.Search(lo.data(),hi.data(),collect,&nearSkin);
  }
  for(int f:nearGrown)addFace(soup,info,grown.triangles[3*f],grown.triangles[3*f+1],grown.triangles[3*f+2],
                             owner(grown,f),parent(grown,f),{Fixed,f,velocity[f]});
  std::map<int,int>skinVertex;
  for(int f:nearSkin) {
    int v[3];for(int k=0;k<3;k++) {
      int s=skin.triangles[3*f+k];auto it=skinVertex.find(s);
      if(it==skinVertex.end())it=skinVertex.insert({s,addPoint(soup,point(skin,s))}).first;
      v[k]=it->second;
    }
    addFace(soup,info,v[0],v[1],v[2],-1,-1,{Material,f,{}});
  }
  Mesh cut;std::vector<Face>cutInfo;std::vector<int>mapping;
  cuts++;
  if(!refine(soup,info,cut,cutInfo,mapping,error))return false;
  // Coplanar competing collars share two-dimensional cells. Their meeting
  // is the equal-normal-advance cut inside those cells, not both overlap boundaries.
  std::map<std::array<int,3>,std::vector<int> >coincident;
  for(int f=0;f<int(cutInfo.size());f++)if(cutInfo[f].kind==Proposal) {
    std::array<int,3>v{{cut.triangles[3*f],cut.triangles[3*f+1],cut.triangles[3*f+2]}};std::sort(v.begin(),v.end());
    coincident[v].push_back(f);
  }
  std::map<Edge,std::set<Edge> >overlapEdges;
  for(const auto&cell:coincident)for(int a:cell.second)for(int b:cell.second)
    if(cutInfo[a].source!=cutInfo[b].source)for(int k=0;k<3;k++)
      overlapEdges[key(cell.first[k],cell.first[(k+1)%3])].insert(key(cutInfo[a].source,cutInfo[b].source));
  // Find all sheet contacts simultaneously. Neighboring collar seams and
  // attachment roots are continuity constraints, not stopping barriers.
  const Uses cutEdges=incidence(cut);
  for(const auto&e:cutEdges) {
    std::set<int>which;
    for(int f:e.second)if(cutInfo[f].kind==Proposal)which.insert(cutInfo[f].source);
    for(int c:which) {
      const Collar&collar=collars[c];
      if(collar.rootEdge(e.first,cut,tolerance)||collar.seam(e.first,cut,tolerance))continue;
      bool obstacle=false;
      for(int f:e.second)if(cutInfo[f].kind==Fixed||cutInfo[f].kind==Material||
         (cutInfo[f].kind==Proposal&&cutInfo[f].source!=c&&!overlapEdges[e.first].count(key(c,cutInfo[f].source))))obstacle=true;
      if(obstacle)collars[c].contacts.push_back({{point(cut,e.first.first),point(cut,e.first.second)}});
    }
  }
  // A selective auxiliary plane through each finite contact endpoint cuts
  // only this collar. Shared input edges propagate the new nodes to neighbors.
  // The first co-refinement has already made all sheet contacts shared edges.
  Mesh constrained=cut;std::vector<Face>constraintInfo=cutInfo;
  std::vector<int>targets(cutInfo.size(),-1);
  std::vector<std::vector<P> >ends(collars.size());
  for(int c=0;c<int(collars.size());c++)for(const auto&contact:collars[c].contacts)for(const P&p:contact) {
    const double u=collars[c].uv(p)[0];bool present=false;
    for(const P&q:ends[c])if(std::abs(collars[c].uv(q)[0]-u)<1.e-9){present=true;break;}
    if(!present)ends[c].push_back(p);
  }
  for(int f=0;f<int(cutInfo.size());f++)if(cutInfo[f].kind==Proposal) {
    const int c=cutInfo[f].source;const Collar&collar=collars[c];
    double lo=1.e300,hi=-1.e300;
    for(int k=0;k<3;k++){double u=collar.uv(point(cut,cut.triangles[3*f+k]))[0];lo=std::min(lo,u);hi=std::max(hi,u);}
    for(const P&p:ends[c]) {
      const double u=collar.uv(p)[0];if(u<=lo+1.e-9||u>=hi-1.e-9)continue;
      const double size=4.*(step+collar.edgeLength);
      P d=mul(collar.outward,size),n=mul(unit(cross(collar.tangent,collar.outward)),size);
      // Include the actual contact point in the exact cutter plane. A
      // rectangle made only from rounded p +/- vectors need not contain p.
      int a=addPoint(constrained,p),b=addPoint(constrained,add(add(p,d),n));
      int v=addPoint(constrained,sub(add(p,d),n));
      addFace(constrained,constraintInfo,a,b,v,-1,-1,{Material,-1,{}});targets.push_back(f);
      splits++;
    }
  }
  for(const auto&cell:coincident)for(int f:cell.second)for(int g:cell.second) {
    int a=cutInfo[f].source,b=cutInfo[g].source;if(a>=b)continue;
    const Collar&ca=collars[a];const Collar&cb=collars[b];
    auto delta=[&](const P&p){return ca.uv(p)[1]-cb.uv(p)[1];};
    double lo=1.e300,hi=-1.e300;
    for(int k=0;k<3;k++){double d=delta(point(cut,cut.triangles[3*f+k]));lo=std::min(lo,d);hi=std::max(hi,d);}
    if(lo>=-1.e-10||hi<=1.e-10)continue;
    P n=sub(ca.outward,cb.outward);if(norm(n)<1.e-12)continue;
    P center=mul(add(ca.start,cb.start),.5);
    center=sub(center,mul(n,delta(center)*step/dot(n,n)));
    P axis{{1,0,0}};if(std::abs(unit(n)[0])>.8)axis={{0,1,0}};
    double size=8.*(step+ca.edgeLength+cb.edgeLength+norm(sub(ca.start,cb.start)));
    P u=mul(unit(cross(n,axis)),size),v=mul(unit(cross(n,u)),size);
    int i=addPoint(constrained,add(add(center,u),v));
    int j=addPoint(constrained,add(sub(center,u),v));
    int k=addPoint(constrained,sub(center,mul(v,2.)));
    addFace(constrained,constraintInfo,i,j,k,-1,-1,{Material,-1,{}});targets.push_back(f);splits++;
    addFace(constrained,constraintInfo,i,j,k,-1,-1,{Material,-1,{}});targets.push_back(g);splits++;
  }
  if(constraintInfo.size()!=cutInfo.size()) {
    Mesh refined;std::vector<Face>refinedInfo;std::vector<int>secondMap;cuts++;
    if(!refine(constrained,constraintInfo,refined,refinedInfo,secondMap,error,&targets))return false;
    for(int&i:mapping)i=secondMap[i];
    cut=std::move(refined);cutInfo=std::move(refinedInfo);
  }
  std::vector<char>keep(cutInfo.size(),0);
  for(int f=0;f<int(cutInfo.size());f++) {
    if(cutInfo[f].kind==Fixed){keep[f]=1;continue;}
    if(cutInfo[f].kind!=Proposal)continue;
    const Collar&c=collars[cutInfo[f].source];P center{{0,0,0}};std::array<UV,3>triangle;
    for(int k=0;k<3;k++){P p=point(cut,cut.triangles[3*f+k]);center=add(center,mul(p,1./3));triangle[k]=c.uv(p);}
    double w=std::abs(winding(center.data()));if(std::abs(w-.5)<1.e-5)w=std::abs(winding.exact(center.data()));
    if(w<=.5+1.e-9)continue;
    bool behind=false;
    for(const auto&contact:c.contacts)if(pastContact(triangle,c.uv(contact[0]),c.uv(contact[1]))){behind=true;break;}
    if(!behind)keep[f]=1;
  }
  coincident.clear();
  for(int f=0;f<int(cutInfo.size());f++)if(keep[f]&&cutInfo[f].kind==Proposal) {
    std::array<int,3>v{{cut.triangles[3*f],cut.triangles[3*f+1],cut.triangles[3*f+2]}};std::sort(v.begin(),v.end());
    coincident[v].push_back(f);
  }
  for(const auto&cell:coincident)if(cell.second.size()>1) {
    int winner=cell.second[0];
    P center{{0,0,0}};for(int v:cell.first)center=add(center,mul(point(cut,v),1./3));
    for(int f:cell.second)if(collars[cutInfo[f].source].uv(center)[1]<collars[cutInfo[winner].source].uv(center)[1])winner=f;
    for(int f:cell.second)if(f!=winner)keep[f]=0;
  }
  // Require a path to this collar's own root after characteristic clipping.
  const Uses selectedEdges=incidence(cut);
  std::vector<std::vector<int> >adj(cutInfo.size());std::vector<char>rooted(cutInfo.size(),0);std::queue<int>q;
  for(const auto&e:selectedEdges) {
    for(int a:e.second)if(keep[a]&&cutInfo[a].kind==Proposal) {
      int c=cutInfo[a].source;
      for(int b:e.second)if(keep[b]) {
        if(cutInfo[b].kind==Fixed&&collars[c].rootEdge(e.first,cut,tolerance)&&!rooted[a]){rooted[a]=1;q.push(a);}
        else if(cutInfo[b].kind==Proposal&&cutInfo[b].source==c&&a!=b)adj[a].push_back(b);
      }
    }
  }
  while(!q.empty()){int a=q.front();q.pop();for(int b:adj[a])if(!rooted[b]){rooted[b]=1;q.push(b);}}
  for(int f=0;f<int(keep.size());f++)if(cutInfo[f].kind==Proposal&&!rooted[f])keep[f]=0;
  // Merge coincident descendants by their shared indexed triangle. Existing
  // faces have priority. Never tolerance-weld independently rounded contacts.
  std::map<std::array<int,3>,int>unique;
  for(int pass=0;pass<2;pass++)for(int f=0;f<int(keep.size());f++)if(keep[f]&&((cutInfo[f].kind==Fixed)==(pass==0))) {
    std::array<int,3>v{{cut.triangles[3*f],cut.triangles[3*f+1],cut.triangles[3*f+2]}};std::sort(v.begin(),v.end());
    if(!unique.insert({v,f}).second)keep[f]=0;
  }
  std::vector<double>covered(grown.triangles.size()/3,0.),roundoff(covered.size(),0.);
  std::vector<int>descendants(covered.size(),0);
  next.xyz=cut.xyz;
  for(int f=0;f<int(grown.parent.size());f++)if(!nearGrown.count(f)) {
    next.triangles.insert(next.triangles.end(),{mapping[grown.triangles[3*f]],mapping[grown.triangles[3*f+1]],mapping[grown.triangles[3*f+2]]});
    next.branch.push_back(owner(grown,f));next.parent.push_back(parent(grown,f));nextVelocity.push_back(velocity[f]);
  }
  std::vector<int>nextCollar(next.parent.size(),-1);
  std::size_t added=0;
  for(int f=0;f<int(keep.size());f++)if(keep[f]) {
    if(cutInfo[f].kind==Fixed){descendants[cutInfo[f].source]++;covered[cutInfo[f].source]+=area(cut,f);roundoff[cutInfo[f].source]+=areaRoundoff(cut,f);}else added++;
    next.triangles.insert(next.triangles.end(),cut.triangles.begin()+3*f,cut.triangles.begin()+3*f+3);
    next.branch.push_back(cut.branch[f]);next.parent.push_back(cut.parent[f]);nextVelocity.push_back(cutInfo[f].velocity);
    nextCollar.push_back(cutInfo[f].kind==Proposal?cutInfo[f].source:-1);
  }
  for(int f:nearGrown)if(!descendants[f]||std::abs(covered[f]-area(grown,f))>1.e-8*area(grown,f)+1.e-24+roundoff[f]+areaRoundoff(grown,f)) {
    std::ostringstream why;why<<std::setprecision(17)<<"local co-refinement area mismatch for face "<<f
      <<" (parent "<<grown.parent[f]<<"): "<<covered[f]<<" / "<<area(grown,f);
    error=why.str();return false;
  }
  if(!added){error="no rooted collar survived contact selection";return false;}
  compact(next);
  if(!validateMesh(next,error))return false;
  std::vector<std::array<int,2> >intersections;
  if(!meshSelfIntersections(next.xyz,next.triangles,intersections,error,false))return false;
  if(!intersections.empty()) {
    error="local collar rejected after self-intersection";
    for(const auto&pair:intersections) {
      bool identified=false;
      for(int f:pair)if(nextCollar[f]>=0) {
        const Collar&c=collars[nextCollar[f]];rejected.insert(segment(c.start,c.end));
        reasons[c.root]=error;identified=true;
      }
      // A new cut can also expose an invalid subdivision of two old faces.
      // Reject only collars in that intersection's spatial neighborhood.
      if(!identified)for(int f:pair) {
        P lo,hi;bounds(next,f,lo,hi,tolerance);
        for(const Collar&c:collars) {
          P a=c.start,b=a;
          for(const P&p:{c.end,c.tipA,c.tipB})for(int k=0;k<3;k++){a[k]=std::min(a[k],p[k]);b[k]=std::max(b[k],p[k]);}
          bool overlap=true;for(int k=0;k<3;k++)if(b[k]<lo[k]||a[k]>hi[k])overlap=false;
          if(overlap){rejected.insert(segment(c.start,c.end));reasons[c.root]=error;}
        }
      }
    }
    return false;
  }
  if(!containedWithRoundoff(next,skin,skinQuery,winding,error))return false;
  // Only contacts present in the selected result count. A rejected competing
  // collar is not evidence that a stopped front completed its extension.
  for(const auto&e:selectedEdges)for(int f:e.second)if(keep[f]&&cutInfo[f].kind==Proposal) {
    const Collar&c=collars[cutInfo[f].source];
    if(c.rootEdge(e.first,cut,tolerance)||c.seam(e.first,cut,tolerance))continue;
    for(int g:e.second)if(keep[g]&&(cutInfo[g].kind==Fixed||
       (cutInfo[g].kind==Proposal&&cutInfo[g].source!=cutInfo[f].source)))contacted[c.root]|=2;
  }
  const Uses nextEdges=incidence(next);
  for(const auto&e:nextEdges) {
    bool onSkin=e.second.size()==1&&skinQuery.onEdge(point(next,e.first.first),point(next,e.first.second));
    bool junction=e.second.size()>2;
    if(onSkin||junction)for(int f:e.second)if(next.parent[f]<-1)contacted[-2-next.parent[f]]|=junction?2:1;
  }
  return true;
}
bool closedSkin(const Mesh&skin) {
  for(const auto&e:incidence(skin)){
    if(e.second.size()!=2)return false;
    int balance=0;for(int f:e.second)for(int j=0;j<3;j++)if(key(skin.triangles[3*f+j],skin.triangles[3*f+(j+1)%3])==e.first)balance+=skin.triangles[3*f+j]==e.first.first?1:-1;
    if(balance)return false;
  }return true;
}
} // namespace

bool validateExtensionContainment(const Mesh&m,const Mesh&skin,std::string&error,double*outArea) {
  if(!validateMesh(m,error)||!validateMesh(skin,error)||!closedSkin(skin))return false;
  double scale=0.;std::vector<P>x;std::vector<std::array<int,3> >t;
  for(int v=0;v<int(skin.xyz.size()/3);v++){P p=point(skin,v);x.push_back(p);scale=std::max(scale,pointRoundoff(p));}
  for(int f=0;f<int(skin.triangles.size()/3);f++)t.push_back({{skin.triangles[3*f],skin.triangles[3*f+1],skin.triangles[3*f+2]}});
  SkinQuery query(skin,scale);DiscreteCADWinding winding(x,t);
  return containedWithRoundoff(m,skin,query,winding,error,outArea);
}

bool extend(const Mesh&input,const Mesh&skin,const Options&options,Mesh&output,ExtensionReport&report,std::string&error) {
  output=input;report=ExtensionReport();error.clear();
  if(!validateMesh(input,error)||!validateMesh(skin,error))return false;
  if(!(options.thickness>0.)||!std::isfinite(options.thickness)||options.extensionLayers<1||options.extensionLayers>10000){error="invalid extension thickness or layer count";return false;}
  const double length=options.extensionLength>0.?options.extensionLength:3*options.thickness;
  if(!std::isfinite(length)||options.extensionLength<0.){error="invalid extension length";return false;}
  Uses uses=incidence(input);
  struct Front {int a,b,f;P outward;};std::vector<Front>fronts;
  std::map<std::pair<int,int>,P>directions;
  for(const auto&e:uses)if(e.second.size()==1){
    int f=e.second[0],a=-1,b=-1;
    for(int k=0;k<3;k++)if(key(input.triangles[3*f+k],input.triangles[3*f+(k+1)%3])==e.first){a=input.triangles[3*f+k];b=input.triangles[3*f+(k+1)%3];break;}
    P edge=sub(point(input,b),point(input,a)),outward=unit(cross(edge,normal(input,f)));
    fronts.push_back({a,b,f,outward});
    report.fronts.push_back({a,b,owner(input,f),"unresolved","not yet processed"});
    for(int v:{a,b})directions[{owner(input,f),v}]=add(directions[{owner(input,f),v}],mul(outward,norm(edge)));
  }
  if(fronts.empty()){report.complete=true;report.message="no free edges";return true;}
  if(!closedSkin(skin)){error="extension requires a closed consistently oriented material skin";for(auto&f:report.fronts)f.reason=error;return false;}
  // Same arc-length direction regularization as the standalone prototype:
  // (M + smoothing^2 L) d = M d0. Geometry is unchanged. Keys include the
  // branch so three sheets meeting at one vertex keep independent directions.
  std::map<std::pair<int,int>,int>ids;
  for(const auto&d:directions)ids[d.first]=int(ids.size());
  const int count=int(ids.size());
  Eigen::VectorXd mass=Eigen::VectorXd::Zero(count);
  Eigen::MatrixXd field=Eigen::MatrixXd::Zero(count,3);
  std::vector<Eigen::Triplet<double> >entries;
  const double smoothing=.5*options.thickness;
  for(const Front&f:fronts){
    int a=ids[{owner(input,f.f),f.a}],b=ids[{owner(input,f.f),f.b}];
    double length=norm(sub(point(input,f.a),point(input,f.b)));
    double weight=smoothing*smoothing/std::max(length,1.e-12*options.thickness);
    entries.emplace_back(a,a,weight);entries.emplace_back(b,b,weight);
    entries.emplace_back(a,b,-weight);entries.emplace_back(b,a,-weight);
    for(int id:{a,b}){mass[id]+=.5*length;for(int k=0;k<3;k++)field(id,k)+=.5*length*f.outward[k];}
  }
  for(int i=0;i<count;i++)entries.emplace_back(i,i,mass[i]);
  Eigen::SparseMatrix<double>system(count,count);system.setFromTriplets(entries.begin(),entries.end());
  Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> >solver(system);
  if(solver.info()!=Eigen::Success){error="boundary direction regularization failed";for(auto&s:report.fronts)s.reason=error;return false;}
  Eigen::MatrixXd solution=solver.solve(field);
  if(solver.info()!=Eigen::Success||!solution.allFinite()){error="boundary direction solve failed";for(auto&s:report.fronts)s.reason=error;return false;}
  for(auto&d:directions){int i=ids[d.first];d.second=P{{solution(i,0),solution(i,1),solution(i,2)}};}
  for(auto&d:directions)d.second=unit(d.second);
  // Keep a positive outward component for every incident front, by branch.
  // A junction is not frozen merely because its global boundary degree is >2.
  for(int pass=0;pass<24;pass++)for(const Front&f:fronts)for(int v:{f.a,f.b}){
    P &d=directions[{owner(input,f.f),v}];double deficit=.05-dot(d,f.outward);if(deficit>0.)d=unit(add(d,mul(f.outward,deficit)));
  }
  P lo=point(skin,0),hi=lo,limits{{0,0,0}};
  for(std::size_t i=0;i<skin.xyz.size()/3;i++){P p=point(skin,int(i));for(int k=0;k<3;k++){lo[k]=std::min(lo[k],p[k]);hi[k]=std::max(hi[k],p[k]);limits[k]=std::max(limits[k],std::abs(p[k]));}}
  for(double x:input.xyz)if(!std::isfinite(x)){error="nonfinite input coordinate";return false;}
  // Gmsh initializes its robust predicates at process startup. Update the
  // bounds for the exact Boolean kernel, including the planned extrapolation.
  for(int k=0;k<3;k++)limits[k]+=length;
  robustPredicates::exactinit(limits[0],limits[1],limits[2]);
  double tolerance=1.e-8*std::max(options.thickness,norm(sub(hi,lo)));
  SkinQuery query(skin,tolerance);
  std::vector<P>x;for(std::size_t i=0;i<skin.xyz.size()/3;i++)x.push_back(point(skin,int(i)));
  std::vector<std::array<int,3> >t;for(std::size_t i=0;i<skin.triangles.size();i+=3)t.push_back({{skin.triangles[i],skin.triangles[i+1],skin.triangles[i+2]}});
  DiscreteCADWinding winding(x,t);
  Mesh grown=input;
  const int originalFaces=int(input.triangles.size()/3);
  grown.parent.resize(originalFaces);if(grown.branch.empty())grown.branch.assign(originalFaces,0);
  std::vector<Motion>velocity(originalFaces);
  for(int f=0;f<originalFaces;f++) {
    grown.parent[f]=f;
    for(int k=0;k<3;k++)velocity[f][k]=directions[{owner(input,f),input.triangles[3*f+k]}];
  }
  for(auto&s:report.fronts)if(query.onEdge(point(input,s.a),point(input,s.b))){s.status="already_on_skin";s.reason.clear();}
  std::vector<char>contacted(fronts.size(),0);
  std::size_t cuts=0,splits=0,steps=0;
  std::string stopped;
  const double step=length/options.extensionLayers;
  std::set<Segment>blocked;
  std::map<int,std::string>localReasons;
  for(int layer=0;layer<options.extensionLayers;layer++) {
    bool committed=false;
    // Spatially reject conflicting collars, then recompute this simultaneous
    // layer. The previous layer remains untouched during each failed trial.
    // A bounded retry count prevents a pathological contact from monopolizing
    // the run; unresolved segments remain explicit in the final ledger.
    for(int attempt=0;attempt<4;attempt++) {
      Mesh next;std::vector<Motion>nextVelocity;std::string why;
      std::set<Segment>rejected;
      if(growLayer(grown,velocity,skin,query,winding,input,report.fronts,
                   step,tolerance,next,nextVelocity,contacted,cuts,splits,
                   blocked,rejected,localReasons,why)) {
        grown=std::move(next);velocity=std::move(nextVelocity);steps++;committed=true;break;
      }
      stopped=why;
      std::size_t previous=blocked.size();blocked.insert(rejected.begin(),rejected.end());
      if(blocked.size()==previous)break;
    }
    if(!committed)break;
    stopped.clear();
  }
  Uses finalEdges=incidence(grown);
  std::vector<char>unfinished(fronts.size(),0),onSkin(fronts.size(),0);
  std::vector<std::size_t>surviving(fronts.size(),0);
  for(int p:grown.parent)if(p<-1)surviving[-2-p]++;
  std::map<int,std::vector<int> >faceRoots;
  for(std::size_t r=0;r<fronts.size();r++)faceRoots[fronts[r].f].push_back(int(r));
  for(const auto&e:finalEdges)if(e.second.size()==1) {
    int f=e.second[0],label=grown.parent[f];P a=point(grown,e.first.first),b=point(grown,e.first.second);
    if(label<-1) {
      int r=-2-label;if(query.onEdge(a,b))onSkin[r]=1;else unfinished[r]=1;
    }
    else for(int r:faceRoots[label])if(onSegment(a,point(input,fronts[r].a),point(input,fronts[r].b),tolerance)&&
                                      onSegment(b,point(input,fronts[r].a),point(input,fronts[r].b),tolerance)&&!query.onEdge(a,b))unfinished[r]=1;
  }
  bool usefulContact=std::any_of(contacted.begin(),contacted.end(),[](char c){return c!=0;});
  // Preserve the former no-contact transaction: a length bound alone is not
  // progress worth replacing the reliable MAT. A partial finite contact may
  // retain useful layers even when its complete original edge is unresolved.
  output=usefulContact?std::move(grown):input;
  for(std::size_t i=0;i<fronts.size();i++) {
    auto&s=report.fronts[i];if(s.status=="already_on_skin")continue;
    if(usefulContact&&surviving[i]&&!unfinished[i]&&contacted[i]) {
      s.status=(contacted[i]&2)?"reached_sheet":"reached_skin";s.reason.clear();
    }
    else {
      s.status="unresolved";
      s.reason=localReasons.count(int(i))?localReasons[int(i)]:
        (stopped.empty()?"propagation bound reached with an interior free boundary":stopped);
    }
  }
  if(usefulContact)for(int&p:output.parent)p=p>=0?parent(input,p):-1;
  report.addedTriangles=usefulContact?std::count(output.parent.begin(),output.parent.end(),-1):0;
  report.complete=std::all_of(report.fronts.begin(),report.fronts.end(),[](const FrontStatus&s){return s.status!="unresolved";});
  report.message="connected fronts: "+std::to_string(steps)+" committed layers, "+std::to_string(cuts)+
    " local co-refinements, "+std::to_string(splits)+" contact constraints, "+
    std::to_string(blocked.size())+" locally rejected front segments; "+
    (report.complete?"all original free edges terminate at contacts":"partial extension; unresolved boundaries remain explicit");
  error.clear();return true;
}
} // namespace matgmsh_native

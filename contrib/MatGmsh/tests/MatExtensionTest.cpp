#include "MatPipeline.h"
#include "gmsh.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <stdexcept>

using namespace matgmsh_native;
namespace {
void check(bool condition,const char *message) {if(!condition)throw std::runtime_error(message);}
Mesh box() {
  Mesh m;
  m.xyz={-2,-2,-1, 2,-2,-1, 2,2,-1, -2,2,-1,
         -2,-2,1, 2,-2,1, 2,2,1, -2,2,1};
  m.triangles={0,2,1,0,3,2, 4,5,6,4,6,7,
               0,1,5,0,5,4, 1,2,6,1,6,5,
               2,3,7,2,7,6, 3,0,4,3,4,7};
  m.branch.assign(12,0);m.parent.resize(12);for(int i=0;i<12;i++)m.parent[i]=i;
  return m;
}
Mesh square() {
  Mesh m;m.xyz={-.5,-.5,0,.5,-.5,0,.5,.5,0,-.5,.5,0};
  m.triangles={0,1,2,0,2,3};m.branch={0,0};m.parent={0,1};return m;
}
double area(const Mesh&m) {
  double result=0.;
  for(std::size_t f=0;f<m.triangles.size();f+=3){double u[3],v[3],n[3];
    for(int k=0;k<3;k++){u[k]=m.xyz[3*m.triangles[f+1]+k]-m.xyz[3*m.triangles[f]+k];v[k]=m.xyz[3*m.triangles[f+2]+k]-m.xyz[3*m.triangles[f]+k];}
    n[0]=u[1]*v[2]-u[2]*v[1];n[1]=u[2]*v[0]-u[0]*v[2];n[2]=u[0]*v[1]-u[1]*v[0];result+=.5*std::sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  }return result;
}
void originalFacesPreserved(const Mesh&initial,const Mesh&output) {
  // Every original triangle must remain represented, including separate
  // seeded components; aggregate area alone would hide a lost original face.
  for(std::size_t i=0;i<initial.parent.size();i++){
    Mesh original;original.xyz=initial.xyz;
    original.triangles.assign(initial.triangles.begin()+3*i,initial.triangles.begin()+3*i+3);
    Mesh descendants;descendants.xyz=output.xyz;
    for(std::size_t j=0;j<output.parent.size();j++)if(output.parent[j]==initial.parent[i]){
      check(output.branch[j]==initial.branch[i],"co-refinement changed an original branch");
      descendants.triangles.insert(descendants.triangles.end(),output.triangles.begin()+3*j,output.triangles.begin()+3*j+3);
    }
    check(std::abs(area(original)-area(descendants))<1.e-8*area(original),"an original triangle lost area");
  }
}
void boxCompletion() {
  Mesh initial=square(),output;Options o;o.thickness=1.;o.extensionLayers=2;
  ExtensionReport r;std::string error;
  check(extend(initial,box(),o,output,r,error),error.c_str());
  for(const auto&f:r.fronts)std::cout<<f.status<<": "<<f.reason<<'\n';
  check(r.fronts.size()==4,"every square edge must be reported");
  check(r.complete,"square extension must reach the box skin");
  originalFacesPreserved(initial,output);
  check(std::abs(area(output)-16.)<1.e-8,"square extension must cover the box cross section");
  check(topology(output).components==1,"extension must remain connected");
  check(initial.xyz==square().xyz&&initial.triangles==square().triangles,"input changed");
}
void failedBandsRetainInput() {
  Mesh initial=square(),output;Options o;o.thickness=1.;o.extensionLength=.01;
  ExtensionReport r;std::string error;
  check(extend(initial,box(),o,output,r,error),error.c_str());
  check(!r.complete&&r.fronts.size()==4,"short extension must report unresolved fronts");
  check(std::all_of(r.fronts.begin(),r.fronts.end(),[](const FrontStatus&f){return f.status=="unresolved";}),"bound is not a completed contact");
  check(output.xyz==initial.xyz&&output.triangles==initial.triangles,"failed proposals must retain input exactly");
}
void junctionIsNotFree() {
  Mesh m;
  m.xyz={-1,-1,0, 0,-1,0, 1,-1,0, -1,1,0, 0,1,0, 1,1,0, 0,-1,.5, 0,1,.5};
  m.triangles={0,1,4,0,4,3, 1,2,5,1,5,4, 1,6,7,1,7,4};
  m.branch={0,0,0,0,1,1};m.parent={0,1,2,3,4,5};
  Mesh output;Options o;o.thickness=1.;o.extensionLength=.01;ExtensionReport r;std::string error;
  check(extend(m,box(),o,output,r,error),error.c_str());
  check(r.fronts.size()==9,"T complex must report all nine incidence-one edges");
  check(std::none_of(r.fronts.begin(),r.fronts.end(),[](const FrontStatus&f){return std::minmax(f.a,f.b)==std::minmax(1,4);}),"T junction is not a free edge");
  check(output.triangles==m.triangles&&output.xyz==m.xyz,"unresolved T must preserve shared identity");
}
void invalidSkinRetainsInput() {
  Mesh m=square(),skin=box(),out;skin.triangles.resize(skin.triangles.size()-3);skin.branch.pop_back();skin.parent.pop_back();
  Options o;ExtensionReport r;std::string error;
  check(!extend(m,skin,o,out,r,error),"open material skin must be rejected");
  check(out.xyz==m.xyz&&out.triangles==m.triangles,"rejected material must retain MAT");
  check(r.fronts.size()==4,"invalid material must still report initial fronts");
}
void firstSheetContact() {
  Mesh m;
  // Three edges of the horizontal sheet already touch the box. Its fourth
  // must stop at x=1, rather than continue to the skin at x=2.
  m.xyz={-2,-2,0, 0,-2,0, 0,2,0, -2,2,0,
          1,-2,-1, 1,2,-1, 1,2,1, 1,-2,1};
  m.triangles={0,1,2,0,2,3, 4,5,6,4,6,7};
  m.branch={0,0,1,1};m.parent={0,1,2,3};
  Mesh output;Options o;o.thickness=1.;o.extensionLayers=3;
  ExtensionReport r;std::string error;
  check(extend(m,box(),o,output,r,error),error.c_str());
  if(!r.complete)for(const auto&f:r.fronts)std::cout<<"contact test "<<f.a<<','<<f.b<<' '<<f.status<<": "<<f.reason<<'\n';
  check(r.complete,"a front meeting another full sheet must complete");
  originalFacesPreserved(m,output);
  check(std::count_if(r.fronts.begin(),r.fronts.end(),[](const FrontStatus&f){return f.status=="reached_sheet";})==1,"expected one sheet contact");
  check(topology(output).components==1&&topology(output).junctionEdges>0,"sheet contact must share native junction nodes");
  check(std::abs(area(output)-20.)<1.e-8,"extension must stop at first sheet, not at the more distant skin");
}
void finiteContactCannotBeBypassed() {
  Mesh m;
  m.xyz={-2,-2,0, 0,-2,0, 0,2,0, -2,2,0,
          1,-.5,-1, 1,.5,-1, 1,.5,1, 1,-.5,1};
  m.triangles={0,1,2,0,2,3, 4,5,6,4,6,7};
  m.branch={0,0,1,1};m.parent={0,1,2,3};
  Mesh output;Options o;o.thickness=1.;o.extensionLength=1.1;o.extensionLayers=1;
  ExtensionReport r;std::string error;
  check(extend(m,box(),o,output,r,error),error.c_str());
  auto front=std::find_if(r.fronts.begin(),r.fronts.end(),[](const FrontStatus&f){return f.branch==0&&std::minmax(f.a,f.b)==std::minmax(1,2);});
  check(front!=r.fronts.end()&&front->status=="unresolved","finite contact must not be bypassed by a graph flood");
  check(!r.complete,"unfinished pieces of a split front must remain explicit");
  originalFacesPreserved(m,output);
  bool advanced=false;
  // Clip every horizontal triangle to the open shadow x>1, |y|<.5.
  // Vertex/centroid tests alone miss triangles crossing this region.
  for(std::size_t f=0;f<output.branch.size();f++)if(output.branch[f]==0) {
    std::vector<std::array<double,2> >polygon;
    for(int k=0;k<3;k++) {
      int v=output.triangles[3*f+k];double x=output.xyz[3*v],y=output.xyz[3*v+1];
      advanced=advanced||x>1.e-6;polygon.push_back({{x,y}});
    }
    for(int side=0;side<3;side++) {
      auto distance=[&](const std::array<double,2>&p){return side==0?p[0]-1.-1.e-8:(side==1?p[1]+.5-1.e-8:.5-1.e-8-p[1]);};
      std::vector<std::array<double,2> >clipped;
      for(std::size_t j=0;j<polygon.size();j++) {
        auto a=polygon[j],b=polygon[(j+1)%polygon.size()];double da=distance(a),db=distance(b);
        if(da>=0.)clipped.push_back(a);
        if((da>=0.)!=(db>=0.)){double t=da/(da-db);clipped.push_back({{a[0]+t*(b[0]-a[0]),a[1]+t*(b[1]-a[1])}});}
      }
      polygon.swap(clipped);
    }
    double shadowArea=0.;
    for(std::size_t j=0;j<polygon.size();j++) {
      auto a=polygon[j],b=polygon[(j+1)%polygon.size()];shadowArea+=a[0]*b[1]-a[1]*b[0];
    }
    check(std::abs(shadowArea)<1.e-10,"finite contact shadow was bypassed");
  }
  check(advanced,"a partial contact must retain the safe continuation before it");
  check(r.addedTriangles>0,"partial front splitting must actually add triangles");
}
using XY=std::array<double,2>;
std::vector<XY> clipPolygon(const std::vector<XY>&polygon,int axis,double bound,int sign) {
  std::vector<XY>out;
  for(std::size_t k=0;k<polygon.size();k++) {
    XY a=polygon[k],b=polygon[(k+1)%polygon.size()];
    double da=sign*(a[axis]-bound),db=sign*(b[axis]-bound);
    if(da>=0.)out.push_back(a);
    if((da>=0.)!=(db>=0.)) {
      double t=da/(da-db);out.push_back({{a[0]+t*(b[0]-a[0]),a[1]+t*(b[1]-a[1])}});
    }
  }
  return out;
}
double polygonArea(const std::vector<XY>&polygon) {
  double a=0.;
  for(std::size_t k=0;k<polygon.size();k++) {
    const XY&p=polygon[k],&q=polygon[(k+1)%polygon.size()];a+=p[0]*q[1]-p[1]*q[0];
  }
  return .5*std::abs(a);
}
std::vector<XY> triangleXY(const Mesh&m,int f) {
  std::vector<XY>p;
  for(int k=0;k<3;k++) {
    int v=m.triangles[3*f+k];
    check(std::abs(m.xyz[3*v+2])<1.e-8,"planar continuation left its original plane");
    p.push_back({{m.xyz[3*v],m.xyz[3*v+1]}});
  }
  return p;
}
double shadowArea(const Mesh&m,int branch,double x,double halfWidth) {
  double a=0.;
  for(int f=0;f<int(m.branch.size());f++)if(m.branch[f]==branch) {
    auto p=clipPolygon(triangleXY(m,f),0,x+1.e-8,1);
    p=clipPolygon(p,1,-halfWidth+1.e-8,1);
    p=clipPolygon(p,1,halfWidth-1.e-8,-1);
    a+=polygonArea(p);
  }
  return a;
}
void appendRectangle(Mesh&m,double x0,double x1,double y0,double y1,int branch) {
  int v=int(m.xyz.size()/3),p=int(m.parent.size());
  m.xyz.insert(m.xyz.end(),{x0,y0,0.,x1,y0,0.,x1,y1,0.,x0,y1,0.});
  m.triangles.insert(m.triangles.end(),{v,v+1,v+2,v,v+2,v+3});
  m.branch.insert(m.branch.end(),2,branch);m.parent.insert(m.parent.end(),{p,p+1});
}
void coplanarGapJoins() {
  Mesh m,output;
  appendRectangle(m,-2.,-.5,-2.,2.,0);appendRectangle(m,.5,2.,-2.,2.,1);
  Options o;o.thickness=1.;o.extensionLength=1.2;o.extensionLayers=6;
  ExtensionReport r;std::string error;
  check(extend(m,box(),o,output,r,error),error.c_str());
  originalFacesPreserved(m,output);
  check(r.complete,"two coplanar fronts across a gap must complete");
  check(topology(output).components==1,"opposing coplanar fronts must share their joining edge");
  check(std::abs(area(output)-16.)<1.e-8,"coplanar continuation must cover the rectangle exactly once");
  check(std::count_if(r.fronts.begin(),r.fronts.end(),[](const FrontStatus&f){return f.status=="reached_sheet";})==2,
        "both coplanar fronts must report their two-incidence sheet contact");
  check(validateNoSelfIntersections(output,error),error.c_str());
  check(validateContainedInSkin(output,box(),error),error.c_str());
}
void finiteCavityCannotBeBypassed() {
  Mesh m,skin=box(),output;
  appendRectangle(m,-3.,-1.,-3.,3.,0);
  for(std::size_t v=0;v<skin.xyz.size()/3;v++) {
    skin.xyz[3*v]*=1.5;skin.xyz[3*v+1]*=1.5;
  }
  // An enclosed cavity is oriented towards the void: winding is zero inside.
  Mesh cavity=box();int offset=int(skin.xyz.size()/3);
  for(std::size_t v=0;v<cavity.xyz.size()/3;v++) {
    skin.xyz.push_back(.5+.25*cavity.xyz[3*v]);
    skin.xyz.push_back(.25*cavity.xyz[3*v+1]);
    skin.xyz.push_back(.5*cavity.xyz[3*v+2]);
  }
  for(int f=0;f<int(cavity.parent.size());f++) {
    skin.triangles.insert(skin.triangles.end(),{offset+cavity.triangles[3*f],
      offset+cavity.triangles[3*f+2],offset+cavity.triangles[3*f+1]});
    skin.branch.push_back(0);skin.parent.push_back(int(skin.parent.size()));
  }
  Options o;o.thickness=1.;o.extensionLength=6.;o.extensionLayers=2;
  ExtensionReport r;std::string error;
  check(extend(m,skin,o,output,r,error),error.c_str());
  originalFacesPreserved(m,output);
  // Two broad collars cross the cavity completely. Clipping each full
  // triangle detects re-entry behind it even when all centroids look safe.
  check(shadowArea(output,0,0.,.5)<1.e-8,"a finite cavity was bypassed after the first skin contact");
  double growth=0.;
  for(int f=0;f<int(output.parent.size());f++)
    growth+=polygonArea(clipPolygon(triangleXY(output,f),0,-1.+1.e-8,1));
  check(growth>.25&&r.addedTriangles>0,"cavity test must retain safe growth, not avoid it by total rollback");
  check(validateNoSelfIntersections(output,error),error.c_str());
  check(validateContainedInSkin(output,skin,error),error.c_str());
}
void finiteContactCompletesWithMoreLayers() {
  Mesh m;
  m.xyz={-2,-2,0,0,-2,0,0,2,0,-2,2,0,
          1,-.5,-1,1,.5,-1,1,.5,1,1,-.5,1};
  m.triangles={0,1,2,0,2,3,4,5,6,4,6,7};
  m.branch={0,0,1,1};m.parent={0,1,2,3};
  Mesh output;Options o;o.thickness=1.;o.extensionLength=3.;o.extensionLayers=3;
  ExtensionReport r;std::string error;
  check(extend(m,box(),o,output,r,error),error.c_str());
  originalFacesPreserved(m,output);
  check(r.complete,"split fronts must continue to completion when enough propagation is allowed");
  check(topology(output).components==1&&topology(output).junctionEdges>0,
        "completed finite contact must join the original sheets conformingly");
  check(shadowArea(output,0,1.,.5)<1.e-8,"later layers bypassed a previously stopped finite contact");
  check(r.addedTriangles>0,"completed split front must add a continuation");
  check(validateNoSelfIntersections(output,error),error.c_str());
  check(validateContainedInSkin(output,box(),error),error.c_str());
}
}
int main() {
  try {
    gmsh::initialize();gmsh::option::setNumber("General.Terminal",0);
    boxCompletion();failedBandsRetainInput();junctionIsNotFree();invalidSkinRetainsInput();firstSheetContact();finiteContactCannotBeBypassed();
    coplanarGapJoins();finiteContactCompletesWithMoreLayers();finiteCavityCannotBeBypassed();
    gmsh::finalize();std::cout<<"MatExtension: 9 tests passed\n";return 0;
  } catch(const std::exception&e) {std::cerr<<"MatExtension test: "<<e.what()<<'\n';gmsh::finalize();return 1;}
}

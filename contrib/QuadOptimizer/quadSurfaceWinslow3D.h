// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// Coupled Winslow proposals in nodal mean planes. CAD acceptance stays in V2.
#pragma once
#include "gmshLBFGS.h"
#include <array>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits>
#include <stdexcept>

namespace QuadOptimizer { namespace SurfaceWinslow3D {
using P = std::array<double, 3>;
using V = std::array<double, 2>;
inline P sub(const P &a, const P &b) { return {{a[0]-b[0],a[1]-b[1],a[2]-b[2]}}; }
inline P mul(const P &a, double x) { return {{a[0]*x,a[1]*x,a[2]*x}}; }
inline double dot(const P &a, const P &b) { return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
inline P cross(const P &a, const P &b) { return {{a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]}}; }
inline bool unit(P &p) { double n=std::sqrt(dot(p,p)); if(!(n>0.) || !std::isfinite(n)) return false; p=mul(p,1./n); return true; }
struct Frame { P u{},v{}; };
struct Term {
  std::array<std::size_t,3> vertex;
  std::array<V,3> gradient;
  Frame plane;
};
class Problem {
  std::vector<P> _points, _original;
  std::vector<Frame> _frames;
  std::vector<int> _offset;
  std::vector<Term> _terms;
  double _scale, _lambda;
  std::size_t _variables=0;
public:
  Problem(const std::vector<P> &points,
          const std::vector<std::vector<std::size_t>> &cells,
          const std::vector<bool> &fixed, double scale, double lambda)
    : _original(points), _frames(points.size()), _offset(points.size(),-1),
      _scale(scale), _lambda(lambda)
  {
    if(points.empty() || points.size()!=fixed.size() || !(scale>0.))
      throw std::invalid_argument("Invalid surface Winslow patch");
    for(const P &p:points) _points.push_back(mul(sub(p,points[0]),1./scale));
    std::vector<P> normals(points.size(), P{{0.,0.,0.}});
    std::vector<std::vector<std::size_t>> neighbors(points.size());
    const auto term = [&](const std::array<std::size_t,3> &ids,
                          const std::array<V,3> &ref, const Frame &plane) {
      const double bx=ref[1][0]-ref[0][0], by=ref[1][1]-ref[0][1];
      const double cx=ref[2][0]-ref[0][0], cy=ref[2][1]-ref[0][1];
      const double det=bx*cy-by*cx;
      Term t; t.vertex=ids; t.plane=plane;
      t.gradient[1]={{cy/det,-cx/det}}; t.gradient[2]={{-by/det,bx/det}};
      for(int j=0;j<2;++j) t.gradient[0][j]=-t.gradient[1][j]-t.gradient[2][j];
      _terms.push_back(t);
    };
    const std::array<V,4> square={V{{0.,0.}},V{{1.,0.}},V{{1.,1.}},V{{0.,1.}}};
    const double side=std::sqrt(2./std::sqrt(3.));
    const std::array<V,3> triangle={V{{0.,0.}},V{{side,0.}},V{{.5*side,.5*std::sqrt(3.)*side}}};
    const int corners[4][3]={{0,1,2},{2,3,0},{1,2,3},{3,0,1}};
    for(const auto &cell:cells) {
      if(cell.size()!=3 && cell.size()!=4) throw std::invalid_argument("Nonlinear surface element");
      for(auto v:cell) if(v>=points.size()) throw std::invalid_argument("Invalid surface vertex");
      P normal{{0.,0.,0.}};
      const P origin=_points[cell[0]];
      for(std::size_t i=0;i<cell.size();++i) {
        const auto a=cell[i],b=cell[(i+1)%cell.size()];
        const P n=cross(sub(_points[a],origin),sub(_points[b],origin));
        for(int j=0;j<3;++j) normal[j]+=n[j];
        neighbors[a].push_back(b); neighbors[b].push_back(a);
      }
      for(auto v:cell) for(int j=0;j<3;++j) normals[v][j]+=normal[j];
      if(!unit(normal)) continue;
      Frame plane; plane.u=sub(_points[cell[1]],origin);
      plane.u=sub(plane.u,mul(normal,dot(normal,plane.u)));
      if(!unit(plane.u)) continue;
      plane.v=cross(normal,plane.u);
      bool movable=false; for(auto v:cell) movable=movable || !fixed[v];
      if(!movable) continue;
      if(cell.size()==3) term({{cell[0],cell[1],cell[2]}},triangle,plane);
      else for(const auto &corner:corners)
        term({{cell[corner[0]],cell[corner[1]],cell[corner[2]]}},
             {{square[corner[0]],square[corner[1]],square[corner[2]]}},plane);
    }
    for(std::size_t i=0;i<points.size();++i) {
      if(fixed[i] || !unit(normals[i])) continue;
      P axis{{0.,0.,0.}};
      for(auto v:neighbors[i]) {
        P candidate=sub(_points[v],_points[i]);
        candidate=sub(candidate,mul(normals[i],dot(candidate,normals[i])));
        if(dot(candidate,candidate)>dot(axis,axis)) axis=candidate;
      }
      if(!unit(axis)) continue;
      _frames[i]={axis,cross(normals[i],axis)};
      _offset[i]=static_cast<int>(_variables); _variables+=2;
    }
  }
  std::size_t variables() const { return _variables; }
  std::vector<P> positions(const std::vector<double> &x, bool physical=false) const {
    auto points=physical?_original:_points;
    const double scale=physical?_scale:1.;
    for(std::size_t i=0;i<points.size();++i) if(_offset[i]>=0)
      for(int j=0;j<3;++j) points[i][j]+=scale*(x[_offset[i]]*_frames[i].u[j]+x[_offset[i]+1]*_frames[i].v[j]);
    return points;
  }
  double evaluate(const std::vector<double> &x,std::vector<double> &g) const {
    if(x.size()!=_variables) throw std::invalid_argument("Invalid surface Winslow variables");
    return evaluatePositions(positions(x), g);
  }
  double energyAtPhysical(const std::vector<P> &physical) const {
    std::vector<P> p; p.reserve(physical.size());
    for(const P &q:physical) p.push_back(mul(sub(q,_original[0]),1./_scale));
    std::vector<double> g; return evaluatePositions(p,g);
  }
  double evaluatePositions(const std::vector<P> &p,std::vector<double> &g) const {
    g.assign(_variables,0.); double energy=0.;
    for(const auto &t:_terms) {
      double a=0.,b=0.,c=0.,d=0.;
      for(int k=1;k<3;++k) {
        const P delta=sub(p[t.vertex[k]],p[t.vertex[0]]);
        const double u=dot(delta,t.plane.u), v=dot(delta,t.plane.v);
        a+=u*t.gradient[k][0]; b+=u*t.gradient[k][1];
        c+=v*t.gradient[k][0]; d+=v*t.gradient[k][1];
      }
      const double det=a*d-b*c, eps=1.e-6, root=std::hypot(det,eps);
      const double chi=det>0.?.5*(det+root):.5*eps*eps/(root-det);
      const double f=(a*a+b*b+c*c+d*d)/chi, volume=(det*det+1.)/chi;
      energy+=f+_lambda*volume;
      const double coeff=(f+_lambda*volume)*chi/root-2.*_lambda*det;
      const double da=(2.*a-coeff*d)/chi, db=(2.*b+coeff*c)/chi;
      const double dc=(2.*c+coeff*b)/chi, dd=(2.*d-coeff*a)/chi;
      for(int k=0;k<3;++k) {
        const auto v=t.vertex[k]; if(_offset[v]<0) continue;
        const double du=da*t.gradient[k][0]+db*t.gradient[k][1];
        const double dv=dc*t.gradient[k][0]+dd*t.gradient[k][1];
        const P grad{{du*t.plane.u[0]+dv*t.plane.v[0],du*t.plane.u[1]+dv*t.plane.v[1],du*t.plane.u[2]+dv*t.plane.v[2]}};
        g[_offset[v]]+=dot(grad,_frames[v].u); g[_offset[v]+1]+=dot(grad,_frames[v].v);
      }
    }
    return energy;
  }
  GmshLBFGS::Result solve(std::vector<double> &x,int iterations=60) const {
    x.assign(_variables,0.); GmshLBFGS::Options options;
    options.maxIterations=iterations; options.memory=10;
    options.gradientTolerance=1.e-6; options.functionTolerance=1.e-10;
    options.maxLineSearchSteps=20; options.verbose=0;
    return GmshLBFGS::minimize(x,[&](const std::vector<double>&q,std::vector<double>&g){return evaluate(q,g);},options);
  }
};
}} // namespace QuadOptimizer::SurfaceWinslow3D

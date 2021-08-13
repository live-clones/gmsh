// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#include "hblGecode.h"

/* HexMeshingTools includes */
#include "hblLogging.hpp"

/* QuadMeshingTools includes */
#include "cppUtils.h"
#include "geolog.h"
#include "OS.h"

// TODOMX / FIXME: ifdef around Gecode
//
/* Gecode includes */
#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/minimodel.hh>


/* - Loops */
#define F(_VAR,_NB) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR)
#define FC(_VAR,_NB,_COND) for(size_t _VAR = 0; _VAR < (size_t) _NB; ++_VAR) if (_COND)
#define RF(...) do {Logging::error(__VA_ARGS__); return false; } while(0)
#define RFC(_COND,...) do { if (_COND) {Logging::error(__VA_ARGS__); return false;} } while(0)

namespace hbl {
  using namespace Gecode;
  using std::vector;
  using std::pair;

  constexpr int FACTOR = 100; /* for effect similar to float constraints */

  struct PolygonReduction {
    vector<pair<id,int>> var_fixed;
    vector<pair<id,int>> var_shift;
  };

  bool reduce_polygon(const PolygonReduction& poly, 
      vector<PolygonReduction>& sub_polys,
      const vector<id>& valence_min) {
    sub_polys.push_back(poly);

    /* Ending condition */
    if (poly.var_shift.size() == 3) {
      return true;
    }

    /* Recursive call */
    F(i,poly.var_shift.size()) {
      id var = poly.var_shift[i].first;
      int shift = poly.var_shift[i].second;
      if ((int) valence_min[var] + shift > 1) continue;
      id iprev = (poly.var_shift.size()+i-1)%poly.var_shift.size();
      id inext = (poly.var_shift.size()+i+1)%poly.var_shift.size();
      PolygonReduction sub;
      sub.var_fixed = poly.var_fixed;
      sub.var_fixed.push_back({var,1-shift});
      FC(j,poly.var_shift.size(),j!=i) {
        if (j == iprev) {
          sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second-1});
        } else if (j == inext) {
          sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second-1});
        } else {
          sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second});
        }
      }
      bool okr = reduce_polygon(sub, sub_polys, valence_min);
    }

    return true;
  }

  // bool reduce_to_triangles(const PolygonReduction& poly, 
  //     vector<PolygonReduction>& intermediaryPolys,
  //     vector<PolygonReduction>& triangles, 
  //     const vector<id>& valence_min) {
  //   /* Ending condition */
  //   if (poly.var_shift.size() == 3) {
  //     triangles.push_back(poly);
  //     return true;
  //   } else {
  //     intermediaryPolys.push_back(poly);
  //   }

  //   /* Recursive call */
  //   F(i,poly.var_shift.size()) {
  //     id var = poly.var_shift[i].first;
  //     int shift = poly.var_shift[i].second;
  //     if (valence_min[var] + shift > 1) continue;
  //     id iprev = (poly.var_shift.size()+i-1)%poly.var_shift.size();
  //     id inext = (poly.var_shift.size()+i+1)%poly.var_shift.size();
  //     PolygonReduction sub;
  //     sub.var_fixed = poly.var_fixed;
  //     sub.var_fixed.push_back({var,1-shift});
  //     FC(j,poly.var_shift.size(),j!=i) {
  //       if (j == iprev) {
  //         sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second-1});
  //       } else if (j == inext) {
  //         sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second-1});
  //       } else {
  //         sub.var_shift.push_back({poly.var_shift[j].first,poly.var_shift[j].second});
  //       }
  //     }
  //     bool okr = reduce_to_triangles(sub, intermediaryPolys, triangles, valence_min);
  //   }

  //   return true;
  // }

#define MINIMIZE_VERSION

#ifdef MINIMIZE_VERSION
  class FindEdgeValences : public IntMinimizeSpace {
#else
    class FindEdgeValences : public Space {
#endif
    protected:
      IntVarArray n;
#ifdef MINIMIZE_VERSION
      IntVar objective;
#endif
      const size_t N;
      const vector<vector<id>>& polygons;
      const vector<double>& x_ideal;
      const vector<id2>& n_min_max;
      const std::vector<id>& n_priority;

    public:
#ifdef MINIMIZE_VERSION
      FindEdgeValences(size_t N_, 
          const vector<vector<id>>& polygons_,
          const vector<double>& x_ideal_,
          const vector<id2>& n_min_max_,
          const std::vector<id>& n_order_
          ) 
        // : n(*this, N_), objective(*this,0,N_*VAL_MAX*VAL_MAX*FACTOR*FACTOR), N(N_), polygons(polygons_),
        : n(*this, N_), objective(*this,0,int(std::min(long(N_*VAL_MAX*VAL_MAX*FACTOR*FACTOR), long(Gecode::Int::Limits::max)))), N(N_), polygons(polygons_),
        x_ideal(x_ideal_), n_min_max(n_min_max_), n_priority(n_order_)
      {
          debug("FindEdgeValences constructor, minimize INT version, with FACTOR = {}", FACTOR);
          std::cout << std::flush;
#else
      FindEdgeValences(size_t N_, 
          const vector<vector<id>>& polygons_,
          const vector<double>& x_ideal_,
          const vector<id2>& n_min_max_,
          const std::vector<id>& n_order_
          ) 
        : n(*this, N_), N(N_), polygons(polygons_), x_ideal(x_ideal_), n_min_max(n_min_max_), n_priority(n_order_)
      {
          debug("FindEdgeValences constructor, NO minimize version");
#endif

          /* Variables */
          vector<id> valence_min(N,1);
          F(i,N) {
            // int n_optimal = std::round(x_ideal[i]);
            // int nmin = VAL_MIN;
            // int nmax = VAL_MAX;
            // if (n_optimal <= 1) {
            //   nmin = 1;
            // } else {
            //   nmin = 2;
            // }
            // nmax = std::min(n_optimal+3,VAL_MAX);
            // // nmax = VAL_MAX; /* TODO debug */
            // valence_min[i] = nmin;
            // n[i] = IntVar(*this,nmin,nmax);

            if (n_min_max[i][0] > n_min_max[i][1]) {
              error("FindEdgeValences: issue in range, n_min_max[{}]={}", i, n_min_max[i]);
            }
            n[i] = IntVar(*this,n_min_max[i][0],n_min_max[i][1]);
          }

#ifdef MINIMIZE_VERSION
          /* Objective function to minimize */
          IntVarArray squares(*this,n.size());
          F(i,N) {
            int n_optimal = (int) std::round(double(FACTOR) * x_ideal[i]);
            squares[i] = expr(*this, (FACTOR * n[i] - n_optimal) * (FACTOR * n[i] - n_optimal));
          }
          rel(*this, objective == sum(squares));
#endif

          /* Constraints */
          size_t nbc = 0;
          size_t nbs = 0;

          /* Loop over polygons */
          for (size_t i = 0; i < polygons.size(); ++ i) {
            const vector<id>& vert = polygons[i];

            /* Loop over possible polygon reductions */
            PolygonReduction poly;
            F(j,vert.size()) poly.var_shift.push_back({vert[j],0});
            vector<PolygonReduction> sub_polys;
            reduce_polygon(poly, sub_polys, valence_min);
            F(j, sub_polys.size()) {
              const PolygonReduction& cpoly = sub_polys[j];
              int nfixed = cpoly.var_fixed.size();
              int nfree = cpoly.var_shift.size();

              /* Fixed variables during the reduction */
              IntVarArray fixed_vals(*this,nfixed);
              IntVar n_respected(*this,0,nfixed+1);
              if (nfixed > 0) {
                F(k,nfixed) {
                  int v = (int) cpoly.var_fixed[k].first;
                  int s = cpoly.var_fixed[k].second;
                  fixed_vals[k] = expr(*this, n[v] - s);
                }
                count(*this,fixed_vals,0,IRT_EQ,n_respected);
              }

              /* Remaining variables in the sub poly */
              IntVarArray vals(*this,cpoly.var_shift.size());
              F(k,cpoly.var_shift.size()) {
                int v = (int) cpoly.var_shift[k].first;
                int s = cpoly.var_shift[k].second;
                vals[k] = expr(*this, n[v] + s);
              }
              IntVar n_val1(*this,0,nfree+1);
              IntVar n_val2(*this,0,nfree+1);
              IntVar n_valN(*this,0,nfree+1);
              count(*this,vals,1,IRT_EQ,n_val1);
              count(*this,vals,2,IRT_EQ,n_val2);
              count(*this,vals,0,IRT_LQ,n_valN);


              if (nfixed > 0) {
                /* Half reify */
                BoolVar cond1 = expr(*this, n_respected == nfixed);
                Reify r1(cond1, RM_IMP);
                if (nfree == 3) { /* triangle */
                  rel(*this,n_val1,IRT_NQ,1,r1);
                  rel(*this,n_val1,IRT_NQ,2,r1);
                  nbc += 2;
                }
                rel(*this,n_val2,IRT_NQ,nfree-1,r1);
                rel(*this,n_valN,IRT_EQ,0,r1);
                nbc += 2;
              } else {
                if (nfree == 3) { /* triangle */
                  rel(*this,n_val1,IRT_NQ,1);
                  rel(*this,n_val1,IRT_NQ,2);
                  nbc += 2;
                }
                rel(*this,n_val2,IRT_NQ,nfree-1);
                rel(*this,n_valN,IRT_EQ,0);
                nbc += 2;
              }
            }
          }

          info("Gecode space stats: {} integer variables, {} trgl. constraints (from {} polygons)", N, nbc, polygons.size());

          /* Brancher */
          // TODO: think about what to use ...
          // branch(*this, n, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
          // branch(*this, n, INT_VAR_SIZE_MIN(), INT_VAL_SPLIT_MIN());
          // branch(*this, n, INT_VAR_SIZE_MIN(), INT_VAL_MAX());

          // branch(*this, n, INT_VAR_SIZE_MIN(), INT_VAL(&choose_value));

          branch(*this, n, INT_VAR_MERIT_MAX(&choose_variable), INT_VAL(&choose_value));
      }

      /* return closest value to x_ideal in input domain */
      static int choose_value(const Space& home, IntVar x, int i) {
        const FindEdgeValences& feb = static_cast<const FindEdgeValences&>(home);
        double ideal = feb.x_ideal[i];
        int val = -1;
        double dmin = DBL_MAX;
        IntVarValues values(x);
        while(values()) {
          double d = std::abs(double(values.val()) - ideal);
          if (d < dmin) {
            val = values.val();
            dmin = d;
          }
          ++values;
        }
        return val;
      }

      /* return a variable for branching */
      static int choose_variable(const Space& home, IntVar x, int i) {
        const FindEdgeValences& feb = static_cast<const FindEdgeValences&>(home);
        return int(feb.n_priority[i]);
      }

#ifdef MINIMIZE_VERSION
      FindEdgeValences(FindEdgeValences& s) : IntMinimizeSpace(s), N(s.N), objective(s.objective), polygons(s.polygons), 
      x_ideal(s.x_ideal), n_min_max(s.n_min_max), n_priority(s.n_priority) {
        n.update(*this, s.n);
        objective.update(*this, s.objective);
      }

      virtual IntMinimizeSpace* copy(void) {
        return new FindEdgeValences(*this);
      }

      virtual IntVar cost(void) const {
        return objective;
      }

      double get_cost() const {
        return double(objective.val()) / double(FACTOR);
      }

      void print_cost(void) const {
        info("cost: {}", double(objective.val()) / double(FACTOR));
      }
#else
      FindEdgeValences(FindEdgeValences& s) : Space(s), N(s.N), polygons(s.polygons), x_ideal(s.x_ideal),
          n_min_max(s.n_min_max), n_priority(s.n_priority) {
        n.update(*this, s.n);
      }

      virtual Space* copy(void) {
        return new FindEdgeValences(*this);
      }
#endif

      void print(void) const {
        std::cout << n << std::endl;
      }

      void extract_solution(vector<id>& slt) {
        slt.resize(n.size());
        F(i,slt.size()) slt[i] = (id) n[i].val();
      }

  };

  class CustomStop : public Search::Stop {
    public:
      bool use_second;
    protected:
      Search::TimeStop* ts1;
      Search::TimeStop* ts2;
    public:
      /// Initialize stop object
      CustomStop(unsigned int t1, unsigned t2) 
        : ts1(new Search::TimeStop(t1)), ts2(new Search::TimeStop(t2)), use_second(false) {}
      /// Test whether search must be stopped
      virtual bool stop(const Search::Statistics& s, const Search::Options& o) {
        return use_second ? ts2->stop(s,o) : ts1->stop(s,o);
      }
      /// Destructor
      ~CustomStop(void) {
        delete ts1; delete ts2;
      }
  };

  bool solve_with_gecode(
      size_t N,
      const std::vector<std::vector<id>>& polygons,
      const std::vector<double>& x_ideal,
      const std::vector<id2>& n_min_max,
      const std::vector<id>& n_priority,
      std::vector<id>& solution,
      bool& stopped,
      std::vector<double>& iterTime,
      double timeMaxInit,
      double timeMaxImprove)
  {
    debug("gecode solver ...");


    FindEdgeValences* m = new FindEdgeValences(N, polygons, x_ideal, n_min_max, n_priority);
    // m->print();

#ifdef MINIMIZE_VERSION
    unsigned long int tl_init_ms = timeMaxInit;
    unsigned long int tl_2d_ms = timeMaxImprove;

    Search::Options opt;
    Search::TimeStop ts(tl_init_ms);
    CustomStop cstop(tl_init_ms, tl_2d_ms);
    opt.stop = &cstop;
    info("branch and bound search (max time init: {}s, improve: {}s) ... ",
        tl_init_ms/1e3, tl_2d_ms/1e3);
    double t0 = Cpu();
    BAB<FindEdgeValences> e(m,opt);
    // info("dfs ...");
    // DFS<FindEdgeValences> e(m);
#else
    info("- DFS: ");
    DFS<FindEdgeValences> e(m);
#endif

    size_t nf = 0;
    bool found = false;
    double last_cost = 0;
    while (FindEdgeValences* s = e.next()) {
      // s->print();
      s->extract_solution(solution);
      found = true;
#ifdef MINIMIZE_VERSION
      double cost = s->get_cost();
      double t = Cpu()-t0;
      printf("(%.1f, %.1fsec), ", cost, t);
      fflush(stdout);
      last_cost = cost;
      cstop.use_second = true;
#endif
      nf += 1;
      iterTime.push_back(t);
      delete s;
      // break;
      // if (nf > 10) break;
    }
    stopped = e.stopped();
    double t = Cpu()-t0;
    printf("  done (nIter: %li, stopped: %i, %.1fsec)\n", nf, (int) stopped, t);

    delete m;

    return found;
  }

  bool solve_with_gecode_many_solutions(
      size_t N,
      const std::vector<std::vector<id>>& polygons,
      const std::vector<double>& x_ideal,
      const std::vector<id2>& n_min_max,
      size_t nb_slt_max,
      std::vector<std::vector<id>>& solutions) {
    solutions.clear();
    info("solve_with_gecode_many_solutions ...");
    info("model ...");
    vector<id> n_priority(N);
    for (size_t i = 0; i < N; ++i) n_priority[i] = i;
    FindEdgeValences* m = new FindEdgeValences(N,polygons,x_ideal,n_min_max,n_priority);

    info("dfs ...");
    DFS<FindEdgeValences> e(m);

// #ifdef MINIMIZE_VERSION
//     info("BAB ...");
//     BAB<FindEdgeValences> e(m);
// #else
//     info("dfs ...");
//     DFS<FindEdgeValences> e(m);
// #endif

    info("while loop ... nb_slt_max = {}", nb_slt_max);
    while (FindEdgeValences* s = e.next()) {
      vector<id> solution;
      s->extract_solution(solution);
      solutions.push_back(solution);
#ifdef MINIMIZE_VERSION
      s->print_cost();
#endif
      delete s;
      if (solutions.size() >= nb_slt_max) break;
    }

    delete m;

    info("found {} solutions", solutions.size());

    return true;
  }

}

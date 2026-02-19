// Copyright (C) 2008 Danil Kirsanov, MIT License
#ifndef GEODESIC_ALGORITHM_EXACT_20071231
#define GEODESIC_ALGORITHM_EXACT_20071231

#include "geodesic_constants_and_simple_functions.h"
#include "geodesic_memory.h"
#include "geodesic_algorithm_base.h"
#include "geodesic_algorithm_exact_elements.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include <assert.h>
#include <set>
#include <cstring>
#include "SVector3.h"

#include <cstddef>
#include "geodesic_mesh_elements.h"
#include <unordered_set>

#define GEODESIC_EPS 1e-10
#define GEODESIC_EPS_SNAP 1e-8
#define GEODESIC_EPSDIST 1e-8
#define MEAN_MULT 100
#define CIRCUM_MULT 100

namespace geodesic {

  class GeodesicAlgorithmExact : public GeodesicAlgorithmBase {
  public:
    GeodesicAlgorithmExact(geodesic::Mesh *mesh)
      : GeodesicAlgorithmBase(mesh),
        m_memory_allocator(mesh->edges().size(), mesh->edges().size()),
        m_edge_interval_lists(mesh->edges().size())
    {
      m_type = EXACT;

      for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
        m_edge_interval_lists[i].initialize(&mesh->edges()[i]);
      }
    };

    ~GeodesicAlgorithmExact() {};

    enum Strategy { NONE, ASTAR, FINDCIRCUMCENTER };

    void propagate(std::vector<SurfacePoint> &sources,
                   double min_propagation_distance,
                   std::vector<SurfacePoint> *stop_points, Strategy strategy,
                   bool Reuse = false);

    void
    propagate(std::vector<SurfacePoint> &sources,
              double min_propagation_distance =
                GEODESIC_INF, // propagation algorithm stops after reaching the
                              // certain distance from the source
              std::vector<SurfacePoint> *stop_points =
                NULL) // and after ensuring that all the stop_points are covered
    {
      propagate(sources, min_propagation_distance, stop_points, NONE);
    };

    unsigned best_source(
      SurfacePoint &point, // quickly find what source this point belongs to and
                           // what is the distance to this source
      double &best_source_distance);

    void
    trace_back(SurfacePoint &destination, // trace back piecewise-linear path
               std::vector<SurfacePoint> &path,
               unsigned source_index = std::numeric_limits<unsigned>::max());

    // void clearCallbacks()
    // {
    // 	m_modifiedMinDistance = nullptr;
    // 	m_modifiedStopConditions = nullptr;
    // }

    void propagateAStar(std::vector<SurfacePoint> &sources,
                        double min_propagation_distance = GEODESIC_INF,
                        std::vector<SurfacePoint> *stop_points = NULL)
    {
      propagate(sources, min_propagation_distance, stop_points, ASTAR);
    };

    // SurfacePoint propagateToCircumcenter(std::vector<SurfacePoint>& sources,
    // 									 double min_propagation_distance =
    // GEODESIC_INF);

    void propagateToCircumcenter(std::vector<SurfacePoint> &sources,
                                 double min_propagation_distance,
                                 SurfacePoint &circumcenter,
                                 double &circumradius)
    {
      if(sources.size() < 2 || sources.size() > 3) {
        std::cerr << "Error: propagateToCircumcenter requires exactly 3 sources"
                  << std::endl;
        return;
      }

      // std::cout << sources[0].base_element()->id() << " "
      //           << sources[1].base_element()->id() << " "
      //           << sources[2].base_element()->id() << std::endl;
      // std::cout << "Propagating to circumcenter" << std::endl;
      if(circumradius <= 0) circumradius = GEODESIC_INF;
      maxDistance = circumradius;

      circumcenter = SurfacePoint(nullptr, 0., 0., 0., UNDEFINED_POINT);
      circumradius = GEODESIC_INF;

      // m_circumradius = circumradius;
      // m_circumcenter = SurfacePoint(nullptr, 0., 0., 0., UNDEFINED_POINT);
      propagate(sources, min_propagation_distance, nullptr, FINDCIRCUMCENTER);

      // if(m_circumcenter.type() == UNDEFINED_POINT)
      //   std::cout << "Circumcenter not found" << std::endl;

      // if(m_circumcenter.size() == 0 || m_circumradius[0] == GEODESIC_INF ||
      //    m_circumcenter[0].type() == UNDEFINED_POINT) {
      // if (m_iterations > 250000) {
      // if(m_iterations > 1000) {
      if(false) {
        // if(true) {
        // if(m_circumcenter.size() == 0) {
        static int count = 0;
        std::ofstream posFile("intervals" + std::to_string(count++) + ".pos");
        posFile << "View \"Intervals\" {\n";
        for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
          list_pointer list = &m_edge_interval_lists[i];
          interval_pointer p = list->first();
          while(p) {
            edge_pointer edge = p->edge();
            vertex_pointer v0 = edge->v0();
            vertex_pointer v1 = edge->v1();
            double start = p->start();
            double stop = p->stop();
            double length = edge->length();
            double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
            double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
            double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
            double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
            double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
            double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
            // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
            // ","
            //         << y1 << "," << z1 << "){" << p->signal(start) << ","
            //         << p->signal(stop) << "};\n";
            // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
            // ","
            //         << y1 << "," << z1 << "){" << p->d() << "," << p->d()
            //         << "};\n";
            // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
            // ","
            //         << y1 << "," << z1 << "){" << p->min() << "," << p->min()
            //         << "};\n";
            posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 << ","
                    << y1 << "," << z1 << "){" << p->source_index() << ","
                    << p->source_index() << "};\n";
            p = p->next();
          }
        }
        for(size_t i = 0; i < m_sources.size(); ++i) {
          posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() << ","
                  << m_sources[i].z() << "){" << i << "};\n";
        }
        for(int i = 0; i < m_circumcenter.size(); ++i) {
          posFile << "SP(" << m_circumcenter[i].x() << ","
                  << m_circumcenter[i].y() << "," << m_circumcenter[i].z()
                  << "){" << -1 << "};\n";
        }
        for(auto it : m_possible_circumfaces) {
          auto vs = it->adjacent_vertices();
          posFile << "ST(" << vs[0]->x() << "," << vs[0]->y() << ","
                  << vs[0]->z() << "," << vs[1]->x() << "," << vs[1]->y() << ","
                  << vs[1]->z() << "," << vs[2]->x() << "," << vs[2]->y() << ","
                  << vs[2]->z() << "){-1,-1,-1};\n";
        }
        // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
        // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
        // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
        // "){1};\n";
        // }
        posFile << "};\n";
        posFile.close();
        // throw std::runtime_error("stop");
        // std::cerr << "Error: propagateToCircumcenter failed to find
        // circumcenter" << std::endl; throw
        // std::runtime_error("propagateToCircumcenter failed to find
        // circumcenter"); std::cout << "Warning: propagateToCircumcenter failed
        // to find circumcenter" << std::endl;
      }

      // int minIndex = -1;
      // double minD = 1e100;
      // for(int i = 0; i < m_circumcenter.size(); ++i) {
      //   if(m_circumradius[i] < minD &&
      //      m_circumradius[i] < (*m_queue.begin())->min() &&
      //      checkCircumcenter(m_circumcenter[i], m_circumradius[i])) {
      //     minIndex = i;
      //     minD = m_circumradius[i];
      //   }
      // }
      // if(minIndex > -1) {
      //   circumcenter = m_circumcenter[minIndex];
      //   circumradius = m_circumradius[minIndex];
      // }
      // else {
      //   // std::cout << m_sources[0].base_element()->id() << " "
      //   //           << m_sources[1].base_element()->id() << " "
      //   //           << m_sources[2].base_element()->id() << std::endl;
      //   circumcenter = SurfacePoint(nullptr, 0., 0., 0., UNDEFINED_POINT);
      //   circumradius = GEODESIC_INF;
      // }
      if(m_circumcenter.size() == 1) {
        circumcenter = m_circumcenter[0];
        circumradius = m_circumradius[0];
      }
      if(isnan(circumradius)) throw std::runtime_error("Error: radius is nan");
    }

    void propagateToCircumcenters(
      std::vector<SurfacePoint> &sources, double min_propagation_distance,
      std::vector<SurfacePoint> &circumcenters,
      std::vector<double> &circumradii, std::vector<int> &circumsources,
      double max_propagation_distance = GEODESIC_INF)
    {
      if(sources.size() < 3) {
        std::cerr
          << "Error: propagateToCircumcenter requires at least 3 sources"
          << std::endl;
        return;
      }

      // std::cout << sources[0].base_element()->id() << " "
      //           << sources[1].base_element()->id() << " "
      //           << sources[2].base_element()->id() << std::endl;
      // std::cout << "Propagating to circumcenter" << std::endl;
      maxDistance = max_propagation_distance;
      // m_circumradius = circumradius;
      // m_circumcenter = SurfacePoint(nullptr, 0., 0., 0., UNDEFINED_POINT);
      propagate(sources, min_propagation_distance, nullptr, FINDCIRCUMCENTER);

      // if(m_circumcenter.type() == UNDEFINED_POINT)
      //   std::cout << "Circumcenter not found" << std::endl;

      // if (m_circumradius == GEODESIC_INF || m_circumcenter.type() ==
      // UNDEFINED_POINT) if (m_iterations > 250000)
      // if(m_iterations > 500) {
      // if(true) {
      // if(false) {
      //   static int count = 0;
      //   std::ofstream posFile("intervals" + std::to_string(count++) +
      //   ".pos"); posFile << "View \"Intervals\" {\n"; for(unsigned i = 0; i <
      //   m_edge_interval_lists.size(); ++i) {
      //     list_pointer list = &m_edge_interval_lists[i];
      //     interval_pointer p = list->first();
      //     while(p) {
      //       edge_pointer edge = p->edge();
      //       vertex_pointer v0 = edge->v0();
      //       vertex_pointer v1 = edge->v1();
      //       double start = p->start();
      //       double stop = p->stop();
      //       double length = edge->length();
      //       double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
      //       double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
      //       double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
      //       double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
      //       double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
      //       double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
      //       // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
      //       <<
      //       // "," << y1 << "," << z1 << "){" << p->min() << "," << p->min()
      //       <<
      //       // "};\n";
      //       posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
      //       ","
      //               << y1 << "," << z1 << "){" << p->source_index() << ","
      //               << p->source_index() << "};\n";
      //       p = p->next();
      //     }
      //   }
      //   for(size_t i = 0; i < m_sources.size(); ++i) {
      //     posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
      //     ","
      //             << m_sources[i].z() << "){" << i << "};\n";
      //   }
      //   for(int i = 0; i < m_circumcenter.size(); ++i) {
      //     posFile << "SP(" << m_circumcenter[i].x() << ","
      //             << m_circumcenter[i].y() << "," << m_circumcenter[i].z()
      //             << "){" << -1 << "};\n";
      //   }
      //   // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
      //   // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
      //   // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
      //   // "){1};\n";
      //   // }
      //   posFile << "};\n";
      //   posFile.close();
      //
      //   // std::cerr << "Error: propagateToCircumcenter failed to find
      //   // circumcenter" << std::endl; throw
      //   // std::runtime_error("propagateToCircumcenter failed to find
      //   // circumcenter"); std::cout << "Warning: propagateToCircumcenter
      //   failed
      //   // to find circumcenter" << std::endl;
      // }

      circumcenters.clear();
      circumradii.clear();
      circumsources.clear();

      // std::cout << m_circumcenter.size() << std::endl;
      if(m_circumcenter.size() > sources.size() - 2) {
        std::vector<int> keep, skip;
        for(int i = 0; i < m_circumcenter.size(); ++i) {
          keep.clear();
          skip.clear();
          keep.push_back(i);
          for(int jndex = 0; jndex < keep.size(); ++jndex) {
            int j = keep[jndex];
            for(int k = 0; k < m_circumcenter.size(); ++k) {
              for(int jj = 0; jj < 3; ++jj) {
                for(int kk = 0; kk < 3; ++kk) {
                  if(m_circumsources[3 * j + jj] ==
                       m_circumsources[3 * k + kk] &&
                     m_circumsources[3 * j + (jj + 1) % 3] ==
                       m_circumsources[3 * k + (kk + 1) % 3]) {
                    skip.push_back(k);
                    break;
                  }
                }
              }
              auto it = std::find(skip.begin(), skip.end(), k);
              if(it != skip.end()) continue;

              bool added = false;
              for(int jj = 0; jj < 3; ++jj) {
                for(int kk = 0; kk < 3; ++kk) {
                  if(m_circumsources[3 * j + jj] !=
                       m_circumsources[3 * k + (kk + 1) % 3] ||
                     m_circumsources[3 * j + (jj + 1) % 3] !=
                       m_circumsources[3 * k + kk])
                    continue;
                  auto it = std::find(keep.begin(), keep.end(), k);
                  auto itt = std::find(skip.begin(), skip.end(), k);
                  if(it == keep.end() && itt == skip.end()) {
                    keep.push_back(k);
                    added = true;
                  }
                  break;
                }
                if(added) break;
              }
              if(added) --k;
            }
          }
          // std::cout << "keep: " << keep.size() << " vs " << sources.size()
          //           << std::endl;
          if(keep.size() == sources.size() - 2) {
            std::vector<SurfacePoint> cc;
            std::vector<double> cr;
            std::vector<size_t> cs;
            for(auto i : keep) {
              cc.push_back(m_circumcenter[i]);
              cr.push_back(m_circumradius[i]);
              cs.push_back(m_circumsources[3 * i]);
              cs.push_back(m_circumsources[3 * i + 1]);
              cs.push_back(m_circumsources[3 * i + 2]);
            }
            m_circumcenter = cc;
            m_circumradius = cr;
            m_circumsources = cs;
            break;
          }
        }
      }
      // std::cout << m_circumcenter.size() << std::endl;
      // while(m_circumcenter.size() > sources.size() - 2) {
      //   int maxIndex = 0;
      //   for(int i = 1; i < circumradii.size(); ++i) {
      //     if(m_circumradius[i] > m_circumradius[maxIndex]) maxIndex = i;
      //   }
      //   m_circumcenter.erase(m_circumcenter.begin() + maxIndex);
      //   m_circumradius.erase(m_circumradius.begin() + maxIndex);
      //   m_circumsources.erase(m_circumsources.begin() + 3 * maxIndex);
      //   m_circumsources.erase(m_circumsources.begin() + 3 * maxIndex);
      //   m_circumsources.erase(m_circumsources.begin() + 3 * maxIndex);
      // }

      if(m_circumcenter.size() == sources.size() - 2) {
        circumcenters.resize(sources.size() - 2);
        circumradii.resize(sources.size() - 2);
        circumsources.resize(3 * (sources.size() - 2));
        for(int i = 0; i < m_circumcenter.size(); ++i) {
          circumcenters[i] = m_circumcenter[i];
          circumradii[i] = m_circumradius[i];
          for(int j = 0; j < 3; ++j)
            circumsources[3 * i + j] = m_circumsources[3 * i + j];
        }
      }
      else {
        // std::cout << sources.size() << " vs " << m_circumcenter.size()
        //           << std::endl;
        // for(int i = 0; i < m_circumcenter.size(); ++i) {
        //   std::cout << m_circumsources[3 * i] << " "
        //             << m_circumsources[3 * i + 1] << " "
        //             << m_circumsources[3 * i + 2] << std::endl;
        // }
        if(true) {
          static int count = 0;
          std::ofstream posFile("notfound" + std::to_string(count++) + ".pos");
          posFile << "View \"Intervals\" {\n";
          for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
            list_pointer list = &m_edge_interval_lists[i];
            interval_pointer p = list->first();
            while(p) {
              edge_pointer edge = p->edge();
              vertex_pointer v0 = edge->v0();
              vertex_pointer v1 = edge->v1();
              double start = p->start();
              double stop = p->stop();
              double length = edge->length();
              double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
              double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
              double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
              double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
              double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
              double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
              // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
              // <<
              // "," << y1 << "," << z1 << "){" << p->min() << "," << p->min()
              // <<
              // "};\n";
              posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
                      << "," << y1 << "," << z1 << "){" << p->source_index()
                      << "," << p->source_index() << "};\n";
              p = p->next();
            }
          }
          for(size_t i = 0; i < m_sources.size(); ++i) {
            posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y()
                    << "," << m_sources[i].z() << "){" << i << "};\n";
          }
          for(int i = 0; i < m_circumcenter.size(); ++i) {
            posFile << "SP(" << m_circumcenter[i].x() << ","
                    << m_circumcenter[i].y() << "," << m_circumcenter[i].z()
                    << "){" << -1 << "};\n";
          }
          // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
          // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
          // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
          // "){1};\n";
          // }
          posFile << "};\n";
          posFile.close();

          // std::cerr << "Error: propagateToCircumcenter failed to find
          // circumcenter" << std::endl; throw
          // std::runtime_error("propagateToCircumcenter failed to find
          // circumcenter"); std::cout << "Warning: propagateToCircumcenter
          // failed to find circumcenter" << std::endl;
        }
        throw std::runtime_error("Error: Could not find circumcenters");
      }

      for(int i = 0; i < circumsources.size() / 3; ++i) {
        for(int j = 0; j < 3; ++j) {
          bool ok = false;
          for(int k = 0; k < sources.size(); ++k) {
            if(circumsources[3 * i + j] != k ||
               circumsources[3 * i + (j + 1) % 3] != (k + 1) % sources.size())
              continue;
            ok = true;
            break;
          }
          if(ok) continue;
          for(int k = 0; k < circumsources.size() / 3; ++k) {
            for(int jj = 0; jj < 3; ++jj) {
              if(circumsources[3 * i + j] !=
                   circumsources[3 * k + (jj + 1) % 3] ||
                 circumsources[3 * i + (j + 1) % 3] !=
                   circumsources[3 * k + jj])
                continue;
              ok = true;
              break;
            }
            if(ok) break;
          }
          if(!ok) {
            // for(int j = 0; j < circumsources.size() / 3; ++j)
            //   std::cout << circumsources[3 * j] << " "
            //             << circumsources[3 * j + 1] << " "
            //             << circumsources[3 * j + 2] << std::endl;
            if(true) {
              static int count = 0;
              std::ofstream posFile("notok" + std::to_string(count++) + ".pos");
              posFile << "View \"Intervals\" {\n";
              for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
                list_pointer list = &m_edge_interval_lists[i];
                interval_pointer p = list->first();
                while(p) {
                  edge_pointer edge = p->edge();
                  vertex_pointer v0 = edge->v0();
                  vertex_pointer v1 = edge->v1();
                  double start = p->start();
                  double stop = p->stop();
                  double length = edge->length();
                  double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
                  double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
                  double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
                  double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
                  double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
                  double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
                  // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," <<
                  // x1
                  // <<
                  // "," << y1 << "," << z1 << "){" << p->min() << "," <<
                  // p->min()
                  // <<
                  // "};\n";
                  posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
                          << "," << y1 << "," << z1 << "){" << p->source_index()
                          << "," << p->source_index() << "};\n";
                  p = p->next();
                }
              }
              for(size_t i = 0; i < m_sources.size(); ++i) {
                posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y()
                        << "," << m_sources[i].z() << "){" << i << "};\n";
              }
              for(int i = 0; i < m_circumcenter.size(); ++i) {
                posFile << "SP(" << m_circumcenter[i].x() << ","
                        << m_circumcenter[i].y() << "," << m_circumcenter[i].z()
                        << "){" << -1 << "};\n";
              }
              // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
              // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
              // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
              // "){1};\n";
              // }
              posFile << "};\n";
              posFile.close();

              // std::cerr << "Error: propagateToCircumcenter failed to find
              // circumcenter" << std::endl; throw
              // std::runtime_error("propagateToCircumcenter failed to find
              // circumcenter"); std::cout << "Warning: propagateToCircumcenter
              // failed to find circumcenter" << std::endl;
            }
            throw std::runtime_error("Error: Not ok triangulation");
          }
        }
      }
    }

    void findCircumcenter(Face *f, SurfacePoint &spCircumcenter,
                          std::vector<SurfacePoint> &circumCenters,
                          std::vector<double> &circumRadii,
                          std::vector<unsigned> &circumSources);
    bool checkCircumcenter(SurfacePoint &circumCenter, double &circumRadius);

    void print_statistics();
    void get_interval_lists(std::vector<IntervalList> *&lists)
    {
      lists = &m_edge_interval_lists;
    };

  private:
    typedef std::set<interval_pointer, Interval> IntervalQueue;

    void
    update_list_and_queue(list_pointer list,
                          IntervalWithStop *candidates, // up to two candidates
                          unsigned num_candidates);

    unsigned compute_propagated_parameters(
      double pseudo_x, double pseudo_y,
      double d, // parameters of the interval
      double start,
      double end, // start/end of the interval
      double alpha, // corner angle
      double L, // length of the new edge
      int source_index, unsigned depth,
      bool first_interval, // if it is the first interval on the edge
      bool last_interval, bool turn_left, bool turn_right,
      IntervalWithStop *candidates); // if it is the last interval on the edge

    void construct_propagated_intervals(
      bool invert, edge_pointer edge,
      face_pointer face, // constructs iNew from the rest of the data
      IntervalWithStop *candidates, unsigned &num_candidates,
      interval_pointer source_interval);

    double compute_positive_intersection(
      double start, double pseudo_x, double pseudo_y, double sin_alpha,
      double cos_alpha); // used in construct_propagated_intervals

    unsigned intersect_intervals(
      interval_pointer zero,
      IntervalWithStop *one); // intersecting two intervals with up
                              // to three intervals in the end

    interval_pointer best_first_interval(SurfacePoint &point,
                                         double &best_total_distance,
                                         double &best_interval_position,
                                         unsigned &best_source_index);

    bool (GeodesicAlgorithmExact::*m_check_stop_condition)();
    bool check_stop_points();
    bool check_circumcenter();
    bool check_stop_conditions();

    void clear()
    {
      m_memory_allocator.clear();
      m_queue.clear();
      removed_intervals.clear();
      // for(unsigned i=0; i<m_edge_interval_lists.size(); ++i)
      for(auto i : m_active_intervals_edges) {
        m_edge_interval_lists[i].clear();
      }
      // for(auto &intervals : m_edge_interval_lists) { intervals.clear(); }
      // std::fill(m_edge_interval_lists.begin(), m_edge_interval_lists.end(),
      //           IntervalList());
      m_active_intervals_edges.clear();
      m_propagation_distance_stopped = GEODESIC_INF;
    };

    list_pointer interval_list(edge_pointer e)
    {
      return &m_edge_interval_lists[e->id()];
    };

    void set_sources(std::vector<SurfacePoint> &sources)
    {
      m_sources.initialize(sources);
      m_sources_on_face.clear();
      // m_sources_on_face.resize(m_mesh->faces().size());
      for(unsigned i = 0; i < sources.size(); ++i) {
        if(sources[i].type() == FACE) {
          m_sources_on_face[sources[i].base_element()->id()].push_back(i);
        }
        else {
          auto adjFaces = sources[i].base_element()->adjacent_faces();
          for(unsigned j = 0; j < adjFaces.size(); ++j) {
            m_sources_on_face[adjFaces[j]->id()].push_back(i);
          }
        }
      }
    }

    void initialize_propagation_data();

    void list_edges_visible_from_source(
      MeshElementBase *p,
      std::vector<edge_pointer> &storage); // used in initialization

    long visible_from_source(SurfacePoint &point); // used in backtracing

    void best_point_on_the_edge_set(
      SurfacePoint &point, std::vector<edge_pointer> const &storage,
      std::vector<face_pointer> &incident_faces,
      interval_pointer &best_interval, double &best_total_distance,
      double &best_interval_position,
      unsigned forSourceIndex = std::numeric_limits<unsigned>::max(),
      unsigned depth = 0);

    void possible_traceback_edges(SurfacePoint &point,
                                  std::vector<edge_pointer> &storage,
                                  std::vector<face_pointer> &incident_faces,
                                  Interval *interval = nullptr);

    bool erase_from_queue(interval_pointer p);

    void (GeodesicAlgorithmExact::*m_compute_min)(Interval *p);
    void compute_min(Interval *p) { p->compute_min_distance(); };
    void compute_min_to_next_stop(Interval *p)
    {
      p->compute_min_distance_to(m_stop_vertices[m_next_stop_index]
#if METRIC
                                 ,
                                 m_mesh->minStretch
#endif
      );
    };
    void compute_min_to_other_source(Interval *p)
    {
      if(p->d() == GEODESIC_INF) return;
      p->compute_min_distance_to(&m_sources[1 - p->source_index()]
#if METRIC
                                 ,
                                 m_mesh->minStretch
#endif
      );
    };
    void compute_min_to_circumcenter(Interval *p)
    {
      // p->compute_min_distance_to_circumcenter(m_sources);

      p->compute_min_distance_to(&m_circumcenter_heuristic);
    };

    IntervalQueue m_queue; // interval queue
    std::unordered_set<interval_pointer> removed_intervals;

    MemoryAllocator<Interval>
      m_memory_allocator; // quickly allocate and deallocate intervals
    std::vector<IntervalList>
      m_edge_interval_lists; // every edge has its interval data
    std::unordered_set<unsigned> m_active_intervals_edges;

    enum MapType { OLD, NEW }; // used for interval intersection
    MapType map[5];
    double start[6];
    interval_pointer i_new[5];

    unsigned m_queue_max_size; // used for statistics
    unsigned m_iterations; // used for statistics

    SortedSources m_sources;
    // std::vector<std::vector<unsigned>> m_sources_on_face;
    std::unordered_map<unsigned, std::vector<unsigned>> m_sources_on_face;

    unsigned m_next_stop_index;
    // std::function<double(Interval*)> m_modifiedMinDistance = nullptr;
    // std::function<bool()> m_modifiedStopConditions = nullptr;

    double maxDistance;
    std::vector<SurfacePoint> m_circumcenter;
    std::vector<size_t> m_circumsources;
    SurfacePoint m_circumcenter_heuristic;
    double m_max_remaining_distance;
    std::vector<SurfacePoint> m_shortest_path;
    std::vector<double> m_circumradius;
    // std::map<Face *, std::array<bool, 3>> m_face_sources;
    std::unordered_set<Face *> m_possible_circumfaces;
    std::unordered_set<Interval *> m_current_intervals;
    // std::vector<Interval *> m_current_intervals;
    Strategy m_strategy;
  };

  inline void GeodesicAlgorithmExact::best_point_on_the_edge_set(
    SurfacePoint &point, std::vector<edge_pointer> const &storage,
    std::vector<face_pointer> &incident_faces, interval_pointer &best_interval,
    double &best_total_distance, double &best_interval_position,
    unsigned forSourceIndex, unsigned depth)
  {
    best_total_distance = 1e100;
    for(unsigned i = 0; i < storage.size(); ++i) {
      edge_pointer e = storage[i];
      list_pointer list = interval_list(e);

      double offset;
      double distance;
      interval_pointer interval;

      list->find_closest_point(&point, offset, distance,
                               //  interval);
                               interval, forSourceIndex, depth,
                               incident_faces[i]);

      if(distance > best_total_distance) continue;
      best_interval = interval;
      best_total_distance = distance;
      best_interval_position = offset;
    }
  }

  inline void GeodesicAlgorithmExact::possible_traceback_edges(
    SurfacePoint &point, std::vector<edge_pointer> &storage,
    std::vector<face_pointer> &incident_faces, Interval *interval)
  {
    storage.clear();
    incident_faces.clear();

    if(point.type() == VERTEX) {
      vertex_pointer v = static_cast<vertex_pointer>(point.base_element());
      for(unsigned i = 0; i < v->adjacent_faces().size(); ++i) {
        face_pointer f = v->adjacent_faces()[i];
        storage.push_back(f->opposite_edge(v));
        incident_faces.push_back(f);
      }
    }
    else if(point.type() == EDGE) {
      edge_pointer e = static_cast<edge_pointer>(point.base_element());
      for(unsigned i = 0; i < e->adjacent_faces().size(); ++i) {
        face_pointer f = e->adjacent_faces()[i];

        if(interval && i == 0 &&
           interval->direction() ==
             IntervalWithStop::DirectionType::FROM_FACE_1)
          continue;
        if(interval && i == 1 &&
           interval->direction() ==
             IntervalWithStop::DirectionType::FROM_FACE_0)
          continue;

        storage.push_back(f->next_edge(e, e->v0()));
        storage.push_back(f->next_edge(e, e->v1()));
        incident_faces.push_back(f);
        incident_faces.push_back(f);
      }
    }
    else {
      face_pointer f = static_cast<face_pointer>(point.base_element());
      storage.push_back(f->adjacent_edges()[0]);
      storage.push_back(f->adjacent_edges()[1]);
      storage.push_back(f->adjacent_edges()[2]);
      incident_faces.push_back(f);
      incident_faces.push_back(f);
      incident_faces.push_back(f);
    }
  }

  inline long GeodesicAlgorithmExact::visible_from_source(
    SurfacePoint &point) // negative if not visible
  {
    assert(point.type() != UNDEFINED_POINT);

    if(point.type() == EDGE) {
      edge_pointer e = static_cast<edge_pointer>(point.base_element());
      list_pointer list = interval_list(e);
      double position = std::min(point.distance(e->v0()), e->length());
      interval_pointer interval = list->covering_interval(position);
      // assert(interval);
      if(interval && interval->visible_from_source()) {
        return (long)interval->source_index();
      }
      else {
        return -1;
      }
    }
    else if(point.type() == FACE) {
      return -1;
    }
    else if(point.type() == VERTEX) {
      vertex_pointer v = static_cast<vertex_pointer>(point.base_element());
      for(unsigned i = 0; i < v->adjacent_edges().size(); ++i) {
        edge_pointer e = v->adjacent_edges()[i];
        list_pointer list = interval_list(e);

        double position = e->v0()->id() == v->id() ? 0.0 : e->length();
        interval_pointer interval = list->covering_interval(position);
        if(interval && interval->visible_from_source()) {
          return (long)interval->source_index();
        }
      }

      return -1;
    }

    assert(0);
    return 0;
  }

  inline double GeodesicAlgorithmExact::compute_positive_intersection(
    double start, double pseudo_x, double pseudo_y, double sin_alpha,
    double cos_alpha)
  {
    // assert(pseudo_y < 0);

    double denominator = sin_alpha * (pseudo_x - start) - cos_alpha * pseudo_y;
    if(denominator < 0.0) { return -1.0; }

    double numerator = -pseudo_y * start;

    if(numerator < 1e-30) { return 0.0; }

    if(denominator < 1e-30) { return -1.0; }

    return numerator / denominator;
  }

  inline void GeodesicAlgorithmExact::list_edges_visible_from_source(
    MeshElementBase *p, std::vector<edge_pointer> &storage)
  {
    // assert(p->type() != UNDEFINED_POINT);

    if(p->type() == FACE) {
      face_pointer f = static_cast<face_pointer>(p);
      for(unsigned i = 0; i < 3; ++i) {
        storage.push_back(f->adjacent_edges()[i]);
      }
    }
    else if(p->type() == EDGE) {
      edge_pointer e = static_cast<edge_pointer>(p);
      storage.push_back(e);
    }
    else // VERTEX
    {
      vertex_pointer v = static_cast<vertex_pointer>(p);
      for(unsigned i = 0; i < v->adjacent_edges().size(); ++i) {
        storage.push_back(v->adjacent_edges()[i]);
      }
    }
  }

  inline bool GeodesicAlgorithmExact::erase_from_queue(interval_pointer p)
  {
    if(p->min() < GEODESIC_INF / 10.0) // && p->min >= queue->begin()->first)
    {
      assert(m_queue.count(p) <= 1); // the set is unique

      IntervalQueue::iterator it = m_queue.find(p);

      if(it != m_queue.end()) {
        // removed_intervals.insert(p);
        m_queue.erase(it);
        m_memory_allocator.deallocate(p);
        return true;
      }
    }

    m_memory_allocator.deallocate(p);
    return false;
  }

  inline unsigned GeodesicAlgorithmExact::intersect_intervals(
    interval_pointer zero,
    IntervalWithStop
      *one) // intersecting two intervals with up to three intervals in the end
  {
    assert(zero->edge()->id() == one->edge()->id());
    // assert(zero->stop() > one->start() && zero->start() < one->stop());
    assert(one->min() < GEODESIC_INF / 10.0);

    double const local_epsilon =
      1e-1 * SMALLEST_INTERVAL_RATIO * one->edge()->length();

    unsigned N = 0;
    if(zero->min() > GEODESIC_INF / 10.0) {
      start[0] = zero->start();
      if(zero->start() < one->start() - local_epsilon) {
        map[0] = OLD;
        start[1] = one->start();
        map[1] = NEW;
        N = 2;
      }
      else {
        map[0] = NEW;
        N = 1;
      }

      if(zero->stop() > one->stop() + local_epsilon) {
        map[N] = OLD; //"zero" interval
        start[N++] = one->stop();
      }

      start[N + 1] = zero->stop();
      return N;
    }

    double const local_small_epsilon = 1e-8 * one->edge()->length();

    double D = zero->d() - one->d();
#if METRIC
    double x0 = zero->pseudo_x() * zero->edge()->stretch();
    double x1 = one->pseudo_x() * one->edge()->stretch();
#else
    double x0 = zero->pseudo_x();
    double x1 = one->pseudo_x();
#endif
    double R0 = x0 * x0 + zero->pseudo_y() * zero->pseudo_y();
    double R1 = x1 * x1 + one->pseudo_y() * one->pseudo_y();

    double inter[2]; // points of intersection
    int Ninter = 0; // number of the points of the intersection

    if(std::abs(D) < local_epsilon) // if d1 == d0, equation is linear
    {
      double denom = x1 - x0;
      if(std::abs(denom) > local_small_epsilon) {
        inter[0] = (R1 - R0) / (2. * denom); // one solution
        Ninter = 1;
      }
    }
    else {
      double D2 = D * D;
      double Q = 0.5 * (R1 - R0 - D2);
      double X = x0 - x1;

      double A = X * X - D2;
      double B = Q * X + D2 * x0;
      double C = Q * Q - D2 * R0;

      if(std::abs(A) < local_small_epsilon) // if A == 0, linear equation
      {
        if(std::abs(B) > local_small_epsilon) {
          inter[0] = -C / B; // one solution
          Ninter = 1;
        }
      }
      else {
        double det = B * B - A * C;
        if(det > local_small_epsilon * local_small_epsilon) // two roots
        {
          det = sqrt(det);
          if(A > 0.0) // make sure that the roots are ordered
          {
            inter[0] = (-B - det) / A;
            inter[1] = (-B + det) / A;
          }
          else {
            inter[0] = (-B + det) / A;
            inter[1] = (-B - det) / A;
          }

          if(inter[1] - inter[0] > local_small_epsilon) { Ninter = 2; }
          else {
            Ninter = 1;
          }
        }
        else if(det >= 0.0) // single root
        {
          inter[0] = -B / A;
          Ninter = 1;
        }
      }
    }
    //---------------------------find possible
    // intervals---------------------------------------
    double left = std::max(zero->start(),
                           one->start()); // define left and right boundaries of
                                          // the intersection of the intervals
    double right = std::min(zero->stop(), one->stop());

    double good_start[4]; // points of intersection within the (left, right)
                          // limits +"left" + "right"
    good_start[0] = left;
    int Ngood_start = 1; // number of the points of the intersection

    for(int i = 0; i < Ninter; ++i) // for all points of intersection
    {
#if METRIC
      double x = inter[i] / one->edge()->stretch();
#else
      double x = inter[i];
#endif
      if(x > left + local_epsilon && x < right - local_epsilon) {
        good_start[Ngood_start++] = x;
      }
    }
    good_start[Ngood_start++] = right;

    MapType mid_map[3];
    for(int i = 0; i < Ngood_start - 1; ++i) {
      double mid = (good_start[i] + good_start[i + 1]) * 0.5;
      mid_map[i] = zero->signal(mid) <= one->signal(mid) ? OLD : NEW;
    }

    //-----------------------------------output----------------------------------
    N = 0;
    if(zero->start() < left - local_epsilon) // additional "zero" interval
    {
      if(mid_map[0] == OLD) // first interval in the map is already the old one
      {
        good_start[0] = zero->start();
      }
      else {
        map[N] = OLD; //"zero" interval
        start[N++] = zero->start();
      }
    }

    for(long i = 0; i < Ngood_start - 1; ++i) // for all intervals
    {
      MapType current_map = mid_map[i];
      if(N == 0 || map[N - 1] != current_map) {
        map[N] = current_map;
        start[N++] = good_start[i];
      }
    }

    if(zero->stop() > one->stop() + local_epsilon) {
      if(N == 0 || map[N - 1] == NEW) {
        map[N] = OLD; //"zero" interval
        start[N++] = one->stop();
      }
    }

    start[0] =
      zero->start(); // just to make sure that epsilons do not damage anything
    // start[N] = zero->stop();

    return N;
  }

  inline void GeodesicAlgorithmExact::initialize_propagation_data()
  {
    // clear();

    IntervalWithStop candidate;
    std::vector<edge_pointer> edges_visible_from_source;
    for(unsigned i = 0; i < m_sources.size();
        ++i) // for all edges adjacent to the starting vertex
    {
      SurfacePoint *source = &m_sources[i];

      edges_visible_from_source.clear();
      list_edges_visible_from_source(source->base_element(),
                                     edges_visible_from_source);

      for(unsigned j = 0; j < edges_visible_from_source.size(); ++j) {
        edge_pointer e = edges_visible_from_source[j];
        candidate.initialize(e, source, i);
        // candidate.initialize(e, source, i, m_modifiedMinDistance);
        candidate.stop() = e->length();
        (this->*m_compute_min)(&candidate);
        // candidate.compute_min_distance(m_modifiedMinDistance);
        candidate.direction() = Interval::FROM_SOURCE;
        // std::cout << "y: " << candidate.pseudo_y() << std::endl;
        update_list_and_queue(interval_list(e), &candidate, 1);
      }
    }
  }

  inline void circumcenter(const double xA, const double yA, const double dA,
                           const double xB, const double yB, const double dB,
                           const double xC, const double yC, const double dC,
                           double *xP, double *yP, double *dP)
  {
    for(int i = 0; i < 4; ++i) dP[i] = GEODESIC_INF;

    double xa = xA, ya = yA, da = dA;
    double xb = xB, yb = yB, db = dB;
    double xc = xC, yc = yC, dc = dC;

    if(db < da) {
      std::swap(xa, xb);
      std::swap(ya, yb);
      std::swap(da, db);
    }
    if(dc < db) {
      std::swap(xb, xc);
      std::swap(yb, yc);
      std::swap(db, dc);
      if(db < da) {
        std::swap(xa, xb);
        std::swap(ya, yb);
        std::swap(da, db);
      }
    }

    xb -= xa;
    xc -= xa;
    yb -= ya;
    yc -= ya;
    db -= da;
    dc -= da;

    double E0x = xb, E0y = yb;
    double norm0 = sqrt(E0x * E0x + E0y * E0y);
    if(norm0 < GEODESIC_EPS) { return; }
    E0x /= norm0;
    E0y /= norm0;
    xb = norm0;
    yb = 0;

    double E1x = -E0y, E1y = E0x; // orthogonal vector
    double dotx = E0x * xc + E0y * yc;
    double doty = E1x * xc + E1y * yc;
    if(doty < -GEODESIC_EPS) {
      E1x = E0y;
      E1y = -E0x;
      doty = -doty;
    }
    xc = dotx;
    yc = doty;

    xc /= xb;
    yc /= xb;
    db /= xb;
    dc /= xb;

    if(yc < GEODESIC_EPS) { // Collinear sources
      double db_m_1 = db - 1;
      double db_p_1 = db + 1;
      double db2_m_1 = db_m_1 * db_p_1;
      double dc_m_xc = dc - xc;
      double dc_p_xc = dc + xc;
      double dc2_m_xc2 = dc_p_xc * dc_p_xc;
      double delta =
        -db2_m_1 * dc2_m_xc2 * (db_p_1 - dc_p_xc) * (db_m_1 - dc_m_xc);
      if(delta < -GEODESIC_EPS) { // No solution
        return;
      }

      double C = 2 * (db * xc - dc);
      std::vector<double> ys;
      if(delta < GEODESIC_EPS) { ys.push_back(0.); }
      else {
        double B = sqrt(delta);
        ys.push_back(+B / C);
        ys.push_back(-B / C);
      }

      double x = (dc * db2_m_1 - db * dc2_m_xc2) / C;
      for(int i = 0; i < ys.size(); ++i) {
        double y = ys[i];
        xP[i] = xb * (x * E0x + y * E1x) + xa;
        yP[i] = xb * (x * E0y + y * E1y) + ya;
        dP[i] = xb * (sqrt(x * x + y * y)) + da;
      }
      return;
    }

    if(dc < GEODESIC_EPS) { // Two lines
      double x = .5;
      double y = (xc * xc + yc * yc - xc) / (2 * yc);
      xP[0] = xb * (x * E0x + y * E1x) + xa;
      yP[0] = xb * (x * E0y + y * E1y) + ya;
      dP[0] = xb * (sqrt(x * x + y * y)) + da;
      return;
    }

    if(db < GEODESIC_EPS) { // One line and one hyperbola
      double x = .5;

      double yc2_m_dc2 = (yc - dc) * (yc + dc);
      double xc2_p_yc2_m_dc2 = xc * xc + yc2_m_dc2;
      double delta = xc2_p_yc2_m_dc2 * (xc2_p_yc2_m_dc2 + 1 - 2 * xc);
      if(delta < -GEODESIC_EPS) { // No solution
        return;
      }

      double A = yc * (xc - xc2_p_yc2_m_dc2);
      double C = -2 * yc2_m_dc2;
      std::vector<double> ys;
      if(delta < GEODESIC_EPS) { ys.push_back(A / C); }
      else {
        double B = dc * sqrt(delta);
        ys.push_back((A - B) / C);
        ys.push_back((A + B) / C);
      }

      for(size_t i = 0; i < ys.size(); ++i) {
        double y = ys[i];
        xP[i] = xb * (x * E0x + y * E1x) + xa;
        yP[i] = xb * (x * E0y + y * E1y) + ya;
        dP[i] = xb * (sqrt(x * x + y * y)) + da;
      }
      return;
    }

    // One hyperbola and one (line or hyperbola)

    double db_m_1 = db - 1;
    double db_p_1 = db + 1;
    double db2_m_1 = db_m_1 * db_p_1;
    double xb_xc_m_dc = xb * xc - dc;
    double xc2_p_yc2_m_dc2 = xc * xc + (yc - dc) * (yc + dc);
    double db_dc_m_xc = db * dc - xc;
    double dc_m_db_xc = dc - db * xc;
    double delta =
      xc2_p_yc2_m_dc2 * db2_m_1 * (db2_m_1 - 2 * db_dc_m_xc - xc2_p_yc2_m_dc2);

    if(delta < -GEODESIC_EPS) { // No solution
      return;
    }

    double A =
      xc * db_dc_m_xc * db2_m_1 + (db2_m_1 - db * dc_m_db_xc) * xc2_p_yc2_m_dc2;
    double C = 2 * (db2_m_1 * xc2_p_yc2_m_dc2 + db_dc_m_xc * db_dc_m_xc);

    std::vector<double> xs;
    if(delta < GEODESIC_EPS) { // one solution
      xs.push_back(A / C);
    }
    else { // two solutions
      double B = db * yc * sqrt(delta);
      xs.push_back((A + B) / C);
      xs.push_back((A - B) / C);
    }

    double a = 2 * dc_m_db_xc;
    double b = dc * db2_m_1 + db * xc2_p_yc2_m_dc2;
    double c = 2 * db * yc;
    for(int i = 0; i < xs.size(); ++i) {
      double x = xs[i];
      double y = (a * x + b) / c;
      xP[i] = xb * (x * E0x + y * E1x) + xa;
      yP[i] = xb * (x * E0y + y * E1y) + ya;
      dP[i] = xb * (sqrt(x * x + y * y)) + da;
    }
  }

  inline void GeodesicAlgorithmExact::propagate(
    std::vector<SurfacePoint> &sources,
    double
      min_propagation_distance, // propagation algorithm stops after reaching
                                // the certain distance from the source
    std::vector<SurfacePoint> *stop_points, Strategy strategy, bool Reuse)
  {
    m_strategy = strategy;
    set_stop_conditions(stop_points, min_propagation_distance);
    m_next_stop_index = 0;
    double GEODESIC_EPSBIAS = 0.;
    // double GEODESIC_EPSBIAS =
    //   (strategy == Strategy::FINDCIRCUMCENTER) ? 0. : 1e-8;

    m_compute_min = &GeodesicAlgorithmExact::compute_min;
    m_check_stop_condition = &GeodesicAlgorithmExact::check_stop_points;

    if(strategy == ASTAR && m_stop_vertices.size() != 0)
      m_compute_min = &GeodesicAlgorithmExact::compute_min_to_next_stop;

    if(strategy == FINDCIRCUMCENTER) {
      if(sources.size() != 3)
        std::runtime_error("Error: Can only find circumcenter for 3 sources");
      // if(sources.size() == 2)
      //   m_compute_min = &GeodesicAlgorithmExact::compute_min_to_other_source;
      // // m_compute_min = &GeodesicAlgorithmExact::compute_min;
      // // m_compute_min =
      // &GeodesicAlgorithmExact::compute_min_to_circumcenter; if(sources.size()
      // == 3)
      m_compute_min = &GeodesicAlgorithmExact::compute_min_to_circumcenter;

      m_check_stop_condition = &GeodesicAlgorithmExact::check_circumcenter;
      // m_circumcenter = SurfacePoint();
      m_circumcenter.clear();
      m_circumsources.clear();
      m_circumradius.clear();
      // if(sources.size() != 3) {
      //   throw std::runtime_error("Not 3 sources for a circumcenter search
      //   !");
      // }
      // if(sources.size() == 3) {
      SVector3 p0(sources[0].xyz(), sources[1].xyz());
      SVector3 p1(sources[0].xyz(), sources[2].xyz());
      double norm_p0 = norm(p0);
      double inv_norm_p0 = 1. / norm_p0;
      p0 *= inv_norm_p0;
      p1 *= inv_norm_p0;
      double p0_dot_p1 = dot(p0, p1);
      p1 -= p0_dot_p1 * p0;
      double norm_p1 = norm(p1);
      p1 *= 1. / norm_p1;
      // std::cout << norm_p0 << std::endl;
      // if(norm_p1 < 1e-12)
      //   throw std::runtime_error(
      //     "Sources too close while searching circumcenter");
      // SVector3 e0 = p0 * (1. / norm_p0);
      // SVector3 cross = crossprod(p0, p1);
      // double norm_cross = norm(cross);
      // // std::cout << "c: " << norm_cross << std::endl;
      if(norm_p1 < 1e-12) {
        SVector3 p(0., 0., 0.);
        for(auto s : sources) p += SVector3(s.xyz());
        p *= 1. / sources.size();
        m_circumcenter_heuristic =
          SurfacePoint(nullptr, p.x(), p.y(), p.z(), UNDEFINED_POINT);
        double distance = sources[0].distance(m_circumcenter_heuristic.xyz());
        maxDistance = MEAN_MULT * distance;
      }
      else {
        double x[4], y[4], d[4];
        circumcenter(0., 0., 0., 1., 0., 0., p0_dot_p1, norm_p1, 0., x, y, d);
        SVector3 c = SVector3(sources[0].xyz()) + x[0] * p0 * norm_p0 +
                     y[0] * p1 * norm_p0;
        m_circumcenter_heuristic =
          SurfacePoint(nullptr, c.x(), c.y(), c.z(), UNDEFINED_POINT);
        double distance = sources[0].distance(m_circumcenter_heuristic.xyz());
        maxDistance = CIRCUM_MULT * distance;
      }

      // }
      // else {
      //   SVector3 p(0., 0., 0.);
      //   for(auto s : sources) p += SVector3(s.xyz());
      //   p *= 1. / sources.size();
      //   m_circumcenter_heuristic =
      //     SurfacePoint(nullptr, p.x(), p.y(), p.z(), UNDEFINED_POINT);
      // }
      // m_circumradius = GEODESIC_INF;
      // m_face_sources.clear();
      m_possible_circumfaces.clear();
      m_current_intervals.clear();
    }

    if(Reuse) {
      SortedSources newSources;
      newSources.initialize(sources);
      int *old2new = new int[m_sources.size()]();
      for(int i = 0; i < newSources.size(); ++i) {
        for(int j = 0; j < m_sources.size(); ++j) {
          if(newSources[i].distance(m_sources[j].xyz()) > 1e-12) continue;
          old2new[j] = i + 1;
        }
      }
      bool *edgesToQueue = new bool[m_mesh->edges().size()]();
      for(auto list : m_edge_interval_lists) {
        // for (auto interval = list.first(); interval != NULL; interval =
        // interval->next())
        // {
        // 	if (interval->d() >= GEODESIC_INF)
        // 		continue;
        // 	if (old2new[interval->source_index()])
        // 	{
        // 		interval->source_index() = old2new[interval->source_index()]
        // - 1;
        // 	}
        // 	else
        // 	{
        // 		interval->d() = GEODESIC_INF;
        // 		interval->min() = GEODESIC_INF;
        // 		for (auto f: interval->edge()->adjacent_faces())
        // 		{
        // 			edgesToQueue[f->opposite_edge(interval->edge()->v0())->id()]
        // = true;
        // edgesToQueue[f->opposite_edge(interval->edge()->v1())->id()] =
        // true;
        // 		}
        // 	}
        // }

        interval_pointer previous = nullptr;
        interval_pointer interval = list.first();
        while(interval != nullptr)
        // for (auto interval = list.first(); interval != NULL; interval =
        // interval->next())
        {
          if(interval->d() >= GEODESIC_INF) {
            previous = interval;
            interval = interval->next();
            continue;
          }
          if(old2new[interval->source_index()]) {
            interval->source_index() = old2new[interval->source_index()] - 1;
            previous = nullptr;
            interval = interval->next();
            continue;
          }

          for(auto f : interval->edge()->adjacent_faces()) {
            edgesToQueue[interval->edge()->id()] = true;
            edgesToQueue[f->opposite_edge(interval->edge()->v0())->id()] = true;
            edgesToQueue[f->opposite_edge(interval->edge()->v1())->id()] = true;
          }
          if(previous) {
            previous->next() = interval->next();
            m_memory_allocator.deallocate(interval);
          }
          else {
            previous = interval;
            interval->d() = GEODESIC_INF;
            interval->min() = GEODESIC_INF;
          }
          interval = previous->next();
          // interval->d() = GEODESIC_INF;
          // interval->min() = GEODESIC_INF;
          // for (auto f: interval->edge()->adjacent_faces())
          // {
          // 	edgesToQueue[f->opposite_edge(interval->edge()->v0())->id()] =
          // true;
          // edgesToQueue[f->opposite_edge(interval->edge()->v1())->id()] =
          // true;
          // }
          // interval = interval->next();
        }
      }
      delete[] old2new;
      for(size_t i = 0; i < m_mesh->edges().size(); ++i) {
        if(!edgesToQueue[i]) continue;
        IntervalList *list = &m_edge_interval_lists[i];
        for(auto interval = list->first(); interval != NULL;
            interval = interval->next()) {
          if(interval->d() < GEODESIC_INF) m_queue.insert(interval);
        }
      }
      delete[] edgesToQueue;
      // {
      // 	FILE *ifile = fopen("intervalsBefore.pos", "w");
      // 	fprintf(ifile, "View \"Intervals\" {\n");
      // 	std::vector<geodesic::IntervalList> *lists;
      // 	get_interval_lists(lists);
      // 	for (size_t i = 0; i < m_mesh->edges().size(); ++i) {
      // 		auto e = &m_mesh->edges()[i];
      // 		auto list = (*lists)[i];
      // 		auto p = list.first();
      // 		SVector3 p0(e->v0()->xyz());
      // 		SVector3 p1(e->v0()->xyz(), e->v1()->xyz());
      // 		p1.normalize();
      // 		while (p != nullptr) {
      // 			SVector3 pStart = p0 + p->start()* p1;
      // 			SVector3 pStop = p0 + p->stop() * p1;
      // 			std::cout << "pStart=" << p->signal(p->start()) << " pStop="
      // << p->signal(p->stop()) << std::endl; 			fprintf(ifile,
      // "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n", 					pStart.x(),
      // pStart.y(), pStart.z(), 					pStop.x(), pStop.y(),
      // pStop.z(), 					p->signal(p->start()),
      // p->signal(p->stop()));
      // 					// (double) p->source_index(), (double)
      // p->source_index()); 			p = p->next();
      // 		}
      // 	}
      // 	fprintf(ifile, "};\n");
      // 	fclose(ifile);
      // }
    }
    else
      clear();

    set_sources(sources);
    initialize_propagation_data();

    clock_t start = clock();

    m_iterations = 0; // for statistics
    m_queue_max_size = 0;

    IntervalWithStop candidates[2];

    while(!m_queue.empty()) {
      // m_queue_max_size = std::max(m_queue.size(), m_queue_max_size);
      m_queue_max_size = std::max<int>(m_queue.size(), m_queue_max_size);

      unsigned const check_period = 10;
      if(++m_iterations % check_period ==
         0) // check if we covered all required vertices
      {
        if(check_stop_conditions()) { break; }
      }

      interval_pointer min_interval = *m_queue.begin();
      m_queue.erase(m_queue.begin());

      // auto it = removed_intervals.find(min_interval);
      // if(it != removed_intervals.end()) {
      //   removed_intervals.erase(it);
      //   m_memory_allocator.deallocate(min_interval);
      //   continue;
      // }

      edge_pointer edge = min_interval->edge();
      // list_pointer list = interval_list(edge);

      if(m_strategy == FINDCIRCUMCENTER)
        m_current_intervals.insert(min_interval);
      // m_current_intervals.push_back(min_interval);

      assert(min_interval->d() < GEODESIC_INF);

      bool const first_interval = min_interval->start() == 0.0;
      // bool const last_interval = min_interval->stop() == edge->length();
      bool const last_interval = min_interval->next() == NULL;

      // bool const turn_left = edge->v0()->saddle_or_boundary();
      // bool const turn_right = edge->v1()->saddle_or_boundary();
      bool const turn_left = true;
      bool const turn_right = true;

      for(unsigned i = 0; i < edge->adjacent_faces().size();
          ++i) // two possible faces to propagate
      {
        if(!edge->is_boundary()) // just in case, always propagate boundary
                                 // edges
        {
          if((i == 0 && min_interval->direction() == Interval::FROM_FACE_0) ||
             (i == 1 && min_interval->direction() == Interval::FROM_FACE_1)) {
            continue;
          }
        }

        face_pointer face =
          edge->adjacent_faces()[i]; // if we come from 1, go to 2

        // if(strategy == Strategy::FINDCIRCUMCENTER) {
        //   // if(m_face_sources.find(face) == m_face_sources.end())
        //   //   m_face_sources[face] = {false, false, false};
        //   // m_face_sources[face][min_interval->source_index()] = true;
        //
        //   m_current_intervals.insert(min_interval);
        //   m_possible_circumfaces.insert(face);
        //   // if (m_face_sources[face][0] && m_face_sources[face][1] &&
        //   // m_face_sources[face][2]) {
        //   // 	m_current_intervals.insert(min_interval);
        //   // 	m_possible_circumfaces.insert(face);
        //   // }
        // }
        //

        edge_pointer next_edge = face->next_edge(edge, edge->v0());
#if METRIC

        // double lengthCurrent = edge->length();
        // double lengthL = next_edge->length();
        // double lengthR = face->next_edge(edge, edge->v1())->length();
        double scaleL = face->opposite_edge(edge->v1())->stretch();
        double scaleCurrent = edge->stretch();
        double scaleR = face->next_edge(edge, edge->v1())->stretch();

        double mLengthCurrent = scaleCurrent * edge->length();
        double mLengthL = scaleL * next_edge->length();
        double mLengthR = scaleR * face->next_edge(edge, edge->v1())->length();
        if(mLengthCurrent + mLengthL < mLengthR ||
           mLengthCurrent + mLengthR < mLengthL ||
           mLengthL + mLengthR < mLengthCurrent) {
          std::cerr << "Warning: Triangle inequality violated" << std::endl;
          continue;
        }
        double mPseudoX = scaleCurrent * min_interval->pseudo_x();
        double mStart = scaleCurrent * min_interval->start();
        double mStop = scaleCurrent * min_interval->stop();
        double mAngle = acos((mLengthCurrent * mLengthCurrent +
                              mLengthL * mLengthL - mLengthR * mLengthR) /
                             (2 * mLengthCurrent * mLengthL));

        unsigned num_propagated = compute_propagated_parameters(
          mPseudoX, min_interval->pseudo_y(),
          min_interval->d() +
            GEODESIC_EPSBIAS *
              min_interval->min(), // parameters of the interval
          mStart,
          mStop, // start/end of the interval
          mAngle, // corner angle
          mLengthL, // length of the new edge
          min_interval->source_index(), min_interval->depth(),
          first_interval, // if it is the first interval on the edge
          last_interval, turn_left, turn_right,
          candidates); // if it is the last interval on the edge
#else
        unsigned num_propagated = compute_propagated_parameters(
          min_interval->pseudo_x(), min_interval->pseudo_y(),
          min_interval->d() +
            GEODESIC_EPSBIAS *
              min_interval->edge()->length(), // parameters of the interval
          min_interval->start(),
          min_interval->stop(), // start/end of the interval
          face->vertex_angle(edge->v0()), // corner angle
          next_edge->length(), // length of the new edge
          min_interval->source_index(), min_interval->depth(),
          first_interval, // if it is the first interval on the edge
          last_interval, turn_left, turn_right,
          candidates); // if it is the last interval on the edge
#endif
        // if(face->vertex_angle(edge->v0()) < 1e-12) {
        //   for(int i = 0; i < num_propagated; ++i) {
        //     candidates[i].d() += 1e-12;
        //   }
        // }
        bool propagate_to_right = true;

#if METRIC
        for(unsigned i = 0; i < num_propagated; ++i) {
          // std::cout << "pseudo y: " << candidates[i].pseudo_y() <<
          // std::endl;
          candidates[i].start() /= scaleL;
          candidates[i].stop() /= scaleL;
          candidates[i].pseudo_x() /= scaleL;
        }
#endif

        if(num_propagated) {
          if(abs(candidates[num_propagated - 1].stop() - next_edge->length()) >
             1e-10) {
            propagate_to_right = false;
          }

          bool const invert =
            next_edge->v0()->id() !=
            edge->v0()
              ->id(); // if the origins coinside, do not invert intervals

          construct_propagated_intervals(invert, // do not inverse
                                         next_edge, face, candidates,
                                         num_propagated, min_interval);

          update_list_and_queue(interval_list(next_edge), candidates,
                                num_propagated);
        }

        if(propagate_to_right) {
          // propogation to the right edge
          double length = edge->length();
          next_edge = face->next_edge(edge, edge->v1());

#if METRIC

          double mPseudoX = scaleCurrent * (length - min_interval->pseudo_x());
          double mStart = scaleCurrent * (length - min_interval->stop());
          double mStop = scaleCurrent * (length - min_interval->start());
          double mAngle = acos((mLengthCurrent * mLengthCurrent +
                                mLengthR * mLengthR - mLengthL * mLengthL) /
                               (2 * mLengthCurrent * mLengthR));

          num_propagated = compute_propagated_parameters(
            mPseudoX, min_interval->pseudo_y(),
            min_interval->d() +
              GEODESIC_EPSBIAS *
                min_interval->min(), // parameters of the interval
            mStart,
            mStop, // start/end of the interval
            mAngle, // corner angle
            mLengthR, // length of the new edge
            min_interval->source_index(), min_interval->depth(),
            last_interval, // if it is the first interval on the edge
            first_interval, turn_right, turn_left,
            candidates); // if it is the last interval on the edge

#else
          num_propagated = compute_propagated_parameters(
            length - min_interval->pseudo_x(), min_interval->pseudo_y(),
            min_interval->d() +
              GEODESIC_EPSBIAS *
                min_interval->edge()->length(), // parameters of the interval
            length - min_interval->stop(),
            length - min_interval->start(), // start/end of the interval
            face->vertex_angle(edge->v1()), // corner angle
            next_edge->length(), // length of the new edge
            min_interval->source_index(), min_interval->depth(),
            last_interval, // if it is the first interval on the edge
            first_interval, turn_right, turn_left,
            candidates); // if it is the last interval on the edge
#endif
          // if(face->vertex_angle(edge->v1()) < 1e-12) {
          //   for(int i = 0; i < num_propagated; ++i) {
          //     candidates[i].d() += 1e-12;
          //   }
          // }

#if METRIC
          for(unsigned i = 0; i < num_propagated; ++i) {
            // std::cout << "pseudo y: " << candidates[i].pseudo_y() <<
            // std::endl;
            candidates[i].start() /= scaleR;
            candidates[i].stop() /= scaleR;
            candidates[i].pseudo_x() /= scaleR;
          }
#endif

          if(num_propagated) {
            bool const invert =
              next_edge->v0()->id() !=
              edge->v1()
                ->id(); // if the origins coinside, do not invert intervals

            construct_propagated_intervals(invert, // do not inverse
                                           next_edge, face, candidates,
                                           num_propagated, min_interval);

            update_list_and_queue(interval_list(next_edge), candidates,
                                  num_propagated);
          }
        }
      }
    }

    m_propagation_distance_stopped =
      m_queue.empty() ? GEODESIC_INF : (*m_queue.begin())->min();
    clock_t stop = clock();
    m_time_consumed =
      (static_cast<double>(stop) - static_cast<double>(start)) / CLOCKS_PER_SEC;

    // if(m_iterations > 10000) {
    //   static int count = 0;
    //   std::cout << "Writing.." << std::endl;
    //   std::string st = "intervals" + std::to_string(count++) + ".pos";
    //   std::ofstream posFile(st);
    //   posFile << "View \"Intervals\" {\n";
    //   for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
    //     list_pointer list = &m_edge_interval_lists[i];
    //     interval_pointer p = list->first();
    //     while(p) {
    //       edge_pointer edge = p->edge();
    //       vertex_pointer v0 = edge->v0();
    //       vertex_pointer v1 = edge->v1();
    //       double start = p->start();
    //       double stop = p->stop();
    //       double length = edge->length();
    //       double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
    //       double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
    //       double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
    //       double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
    //       double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
    //       double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
    //       posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
    //       ","
    //               << y1 << "," << z1 << "){" << p->min() << "," << p->min()
    //               << "};\n";
    //       p = p->next();
    //     }
    //   }
    //   for(size_t i = 0; i < m_sources.size(); ++i) {
    //     posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
    //     ","
    //             << m_sources[i].z() << "){0};\n";
    //   }
    //   for(size_t i = 0; i < m_stop_vertices.size(); ++i) {
    //     posFile << "SP(" << m_stop_vertices[i]->x() << ","
    //             << m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z()
    //             << "){1};\n";
    //   }
    //   posFile << "};\n";
    //   posFile.close();
    //   std::cout << "Done writing." << std::endl;
    // }

    /*	for(unsigned i=0; i<m_edge_interval_lists.size(); ++i)
        {
            list_pointer list = &m_edge_interval_lists[i];
            interval_pointer p = list->first();
            assert(p->start() == 0.0);
            while(p->next())
            {
                assert(p->stop() == p->next()->start());
                assert(p->d() < GEODESIC_INF);
                p = p->next();
            }
        }*/
  }

  inline bool GeodesicAlgorithmExact::check_stop_points()
  {
    double queue_distance = (*m_queue.begin())->min();
    while(m_next_stop_index < m_stop_vertices.size()) {
      double best_total_distance = GEODESIC_INF, best_interval_position;
      unsigned best_source_index = std::numeric_limits<unsigned>::max();
      best_first_interval(*m_stop_vertices[m_next_stop_index],
                          best_total_distance, best_interval_position,
                          best_source_index);
      if(queue_distance <= best_total_distance + 1e-12)
      // if (queue_distance <= best_total_distance * 1.1)
      {
        return false;
      }

      ++m_next_stop_index;
      if(m_next_stop_index >= m_stop_vertices.size()) break;

      if(this->m_compute_min == &GeodesicAlgorithmExact::compute_min) continue;
      std::vector<Interval *> tmp(m_queue.begin(), m_queue.end());
      m_queue.clear();
      for(auto p : tmp) (this->*m_compute_min)(p);
      std::sort(tmp.begin(), tmp.end());
      auto it = m_queue.begin();
      for(auto i : tmp) it = m_queue.insert(it, i);
      queue_distance = (*m_queue.begin())->min();
    }
    return true;
  }

  inline bool GeodesicAlgorithmExact::check_circumcenter()
  {
    double queue_distance = (*m_queue.begin())->min();

    bool print = false;
    // if(m_sources[0].base_element()->id() == 7 &&
    //    m_sources[1].base_element()->id() == 30 &&
    //    m_sources[2].base_element()->id() == 8)
    //   print = true;

    // if(m_sources.size() != 2) {
    // for(int i = 0; i < m_circumcenter.size(); ++i) {
    //   // auto &spC = m_circumcenter[i];
    //   // std::vector<edge_pointer> possible_edges;
    //   // possible_traceback_edges(spC, possible_edges);
    //   // interval_pointer interval = 0ULL;
    //   // double total_distance, position;
    //   //
    //   // double o, d;
    //   // best_point_on_the_edge_set(spC, possible_edges, interval,
    //   //                            total_distance, position);
    //   //
    //   // if(spC.base_element()->type() == FACE &&
    //   //    m_sources_on_face.count(spC.base_element()->id())) {
    //   //   Face *f = (Face *)spC.base_element();
    //   //   std::vector<SurfacePoint> sourcesOnFace;
    //   //   for(auto i : m_sources_on_face[f->id()])
    //   //     sourcesOnFace.push_back(m_sources[i]);
    //   //   for(auto s : sourcesOnFace) {
    //   //     if(s.type() != FACE) continue;
    //   //     SVector3 v(spC.xyz(), s.xyz());
    //   //     d = norm(v);
    //   //     if(d < total_distance) {
    //   //       total_distance = d;
    //   //       interval = nullptr;
    //   //     }
    //   //   }
    //   // }
    //
    //   // if(abs(m_circumradius[i] - total_distance) > GEODESIC_EPSDIST) {
    //   if(!checkCircumcenter(m_circumcenter[i], m_circumradius[i])) {
    //     // std::cout << "erased" << std::endl;
    //     m_circumcenter.erase(m_circumcenter.begin() + i);
    //     m_circumradius.erase(m_circumradius.begin() + i);
    //     m_circumsources.erase(m_circumsources.begin() + 3 * i);
    //     m_circumsources.erase(m_circumsources.begin() + 3 * i);
    //     m_circumsources.erase(m_circumsources.begin() + 3 * i);
    //     --i;
    //   }
    // }
    // }

    // if(m_possible_circumfaces.size() > 0) std::cout << "check cir" <<
    // std::endl;
    // static int cc = 0;
    // if(m_possible_circumfaces.size())
    // std::cout << "check " << cc + m_possible_circumfaces.size() << std::endl;
    for(auto f : m_possible_circumfaces) {
      SurfacePoint spC = SurfacePoint();
      std::vector<SurfacePoint> circumcenters;
      std::vector<double> circumradii;
      std::vector<unsigned> circumsources;
      findCircumcenter(f, spC, circumcenters, circumradii, circumsources);
      // if(print) std::cout << circumcenters.size() << std::endl;
      for(size_t i = 0; i < circumcenters.size(); ++i) {
        if(isnan(circumradii[i]))
          throw std::runtime_error("Error: radii is nan");
        if(print) std::cout << "do we add" << std::endl;

        if(!checkCircumcenter(circumcenters[i], circumradii[i])) continue;

        m_circumcenter.push_back(circumcenters[i]);
        m_circumradius.push_back(circumradii[i]);
        m_circumsources.push_back(circumsources[3 * i]);
        m_circumsources.push_back(circumsources[3 * i + 1]);
        m_circumsources.push_back(circumsources[3 * i + 2]);
        // int j = 0;
        // for(; j < m_circumcenter.size(); ++j) {
        //   // std::cout << circumradii[j] << " " << m_circumsources[3 * j] <<
        //   " "
        //   //           << m_circumsources[3 * j + 1] << " "
        //   //           << m_circumsources[3 * j + 2] << " " << circumradii[i]
        //   //           << " " << circumsources[3 * i] << " "
        //   //           << circumsources[3 * i + 1] << " "
        //   //           << circumsources[3 * i + 2] << std::endl;
        //   if(m_circumsources[3 * j] != circumsources[3 * i] ||
        //      m_circumsources[3 * j + 1] != circumsources[3 * i + 1] ||
        //      m_circumsources[3 * j + 2] != circumsources[3 * i + 2])
        //     continue;
        //   // if(circumradii[i] - m_circumradius[j] < 1e-8) {
        //   // if(circumradii[i] < m_circumradius[j]) {
        //   if( // circumradii[i] < m_circumradius[j] &&
        //     checkCircumcenter(circumcenters[i], circumradii[i]) &&
        //     circumradii[i] < m_circumradius[j]) {
        //     if(print) std::cout << "add" << std::endl;
        //     m_circumradius[j] = circumradii[i];
        //     m_circumcenter[j] = circumcenters[i];
        //     // std::cout << "refound radius: " << circumradii[i] <<
        //     std::endl;
        //
        //     // if(m_sources.size() == 2) {
        //     //   std::vector<SurfacePoint> p;
        //     //   trace_back(circumcenters[i], m_shortest_path, 0);
        //     //   std::reverse(m_shortest_path.begin(),
        //     m_shortest_path.end());
        //     //   trace_back(circumcenters[i], p, 1);
        //     //   m_shortest_path.insert(m_shortest_path.end(), p.begin(),
        //     //   p.end()); m_max_remaining_distance = 0; for(unsigned ii = 0;
        //     ii
        //     //   < 2; ++ii) {
        //     //     double d, p;
        //     //     best_first_interval(circumcenters[i], d, p, ii);
        //     //     d += m_sources[1 - ii].distance(circumcenters[i].xyz());
        //     //     // double d =
        //     //     //
        //     m_circumcenter_heuristic.distance(circumcenters[i].xyz());
        //     //     if(d > m_max_remaining_distance) m_max_remaining_distance
        //     =
        //     //     d;
        //     //   }
        //     // }
        //   }
        //   break;
        // }
        // if(print) std::cout << "do we add" << std::endl;
        // if(print)
        //   std::cout << j << " vs " << m_circumcenter.size() << std::endl;
        // if(j == m_circumcenter.size() &&
        //    checkCircumcenter(circumcenters[i], circumradii[i])) {
        //   if(print) std::cout << "add" << std::endl;
        //   // std::cout << "dist = " << circumradii[i] << std::endl;
        //   m_circumcenter.push_back(circumcenters[i]);
        //   m_circumradius.push_back(circumradii[i]);
        //   // std::cout << "found radius: " << circumradii[i] << " "
        //   //           << circumsources[3 * i] << " " << circumsources[3 * i
        //   +
        //   //           1]
        //   //           << " " << circumsources[3 * i + 2] << std::endl;
        //   m_circumsources.push_back(circumsources[3 * i]);
        //   m_circumsources.push_back(circumsources[3 * i + 1]);
        //   m_circumsources.push_back(circumsources[3 * i + 2]);
        //
        //   // if(m_sources.size() == 2) {
        //   //   std::vector<SurfacePoint> p;
        //   //   trace_back(circumcenters[i], m_shortest_path, 0);
        //   //   std::reverse(m_shortest_path.begin(), m_shortest_path.end());
        //   //   trace_back(circumcenters[i], p, 1);
        //   //   m_shortest_path.insert(m_shortest_path.end(), p.begin(),
        //   //   p.end());
        //   //
        //   //   m_max_remaining_distance = 0;
        //   //   for(unsigned ii = 0; ii < 2; ++ii) {
        //   //     double d, p;
        //   //     best_first_interval(circumcenters[i], d, p, ii);
        //   //     d += m_sources[1 - ii].distance(circumcenters[i].xyz());
        //   //     // double d =
        //   //     //
        //   m_circumcenter_heuristic.distance(circumcenters[i].xyz());
        //   //     if(d > m_max_remaining_distance) m_max_remaining_distance =
        //   d;
        //   //   }
        //   // }
        // }
      }
    }
    // m_possible_circumfaces.clear();
    m_current_intervals.clear();

    // // if(m_iterations % 10000 == 0) {
    // if(false) {
    //   // if(true) {
    //   static int count = 0;
    //   std::ofstream posFile("iterations" + std::to_string(count++) + ".pos");
    //   posFile << "View \"Intervals\" {\n";
    //   for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
    //     list_pointer list = &m_edge_interval_lists[i];
    //     interval_pointer p = list->first();
    //     while(p) {
    //       edge_pointer edge = p->edge();
    //       vertex_pointer v0 = edge->v0();
    //       vertex_pointer v1 = edge->v1();
    //       double start = p->start();
    //       double stop = p->stop();
    //       double length = edge->length();
    //       double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
    //       double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
    //       double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
    //       double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
    //       double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
    //       double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
    //       // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," <<
    //       // x1
    //       // <<
    //       // "," << y1 << "," << z1 << "){" << p->min() << "," <<
    //       // p->min()
    //       // <<
    //       // "};\n";
    //       posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
    //       ","
    //               << y1 << "," << z1 << "){" << p->source_index() << ","
    //               << p->source_index() << "};\n";
    //       p = p->next();
    //     }
    //   }
    //   for(size_t i = 0; i < m_sources.size(); ++i) {
    //     posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
    //     ","
    //             << m_sources[i].z() << "){" << i << "};\n";
    //   }
    //   for(int i = 0; i < m_circumcenter.size(); ++i) {
    //     posFile << "SP(" << m_circumcenter[i].x() << ","
    //             << m_circumcenter[i].y() << "," << m_circumcenter[i].z() <<
    //             "){"
    //             << -1 << "};\n";
    //   }
    //   // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
    //   // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
    //   // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
    //   // "){1};\n";
    //   // }
    //   posFile << "};\n";
    //   posFile.close();
    //
    //   // std::cerr << "Error: propagateToCircumcenter failed to find
    //   // circumcenter" << std::endl; throw
    //   // std::runtime_error("propagateToCircumcenter failed to find
    //   // circumcenter"); std::cout << "Warning: propagateToCircumcenter
    //   // failed to find circumcenter" << std::endl;
    // }
    // if(queue_distance > maxDistance) return true;

    // if(m_sources.size() == 2) {
    //   if(queue_distance <= m_max_remaining_distance) return false;
    // }
    // else {
    // for(int i = 0; i < m_sources.size() - 2; ++i) {
    //   // std::cout << i << std::endl;
    //   if(i == m_circumcenter.size()) return false;
    //   // std::cout << i << " " << m_circumradius[i] << std::endl;
    //   if(queue_distance <= m_circumradius[i]) return false;
    // }
    // }

    int foundIndex = -1;
    double foundRadius = geodesic::GEODESIC_INF;
    for(int i = 0; i < m_circumcenter.size(); ++i) {
      if(queue_distance <= m_circumradius[i]) continue;
      if(!checkCircumcenter(m_circumcenter[i], m_circumradius[i])) {
        m_circumcenter.erase(m_circumcenter.begin() + i);
        m_circumradius.erase(m_circumradius.begin() + i);
        m_circumsources.erase(m_circumsources.begin() + 3 * i);
        m_circumsources.erase(m_circumsources.begin() + 3 * i);
        m_circumsources.erase(m_circumsources.begin() + 3 * i);
        --i;
        continue;
      }

      if(m_circumradius[i] < foundRadius) {
        foundIndex = i;
        foundRadius = m_circumradius[i];
      }
    }
    if(foundIndex > -1) {
      m_circumcenter = {m_circumcenter[foundIndex]};
      m_circumradius = {m_circumradius[foundIndex]};
    }

    // Stop after max distance reached
    if(queue_distance > maxDistance) {
      if(foundIndex == -1) {
        m_circumcenter.clear();
        m_circumradius.clear();
        m_circumsources.clear();
      }
      return true;
    }
    return foundIndex > -1;
  }

  inline bool GeodesicAlgorithmExact::check_stop_conditions()
  {
    double queue_distance = (*m_queue.begin())->min();
    if(queue_distance < stop_distance()) { return false; }

    // if (m_modifiedStopConditions)
    // {
    // 	return m_modifiedStopConditions();
    // }

    return (this->*m_check_stop_condition)();
  }

  inline void GeodesicAlgorithmExact::update_list_and_queue(
    list_pointer list,
    IntervalWithStop *candidates, // up to two candidates
    unsigned num_candidates)
  {
    assert(num_candidates <= 2);
    // assert(list->first() != NULL);
    edge_pointer edge = list->edge();
    m_active_intervals_edges.insert(edge->id());
    double const local_epsilon =
      1e+1 * SMALLEST_INTERVAL_RATIO * edge->length();

    if(list->first() == NULL) {
      interval_pointer *p = &list->first();
      IntervalWithStop *first;
      IntervalWithStop *second;

      if(num_candidates == 1) {
        first = candidates;
        second = candidates;
        (this->*m_compute_min)(first);
        // first->compute_min_distance(m_modifiedMinDistance);
      }
      else {
        if(candidates->start() <= (candidates + 1)->start()) {
          first = candidates;
          second = candidates + 1;
        }
        else {
          first = candidates + 1;
          second = candidates;
        }
        assert(first->stop() == second->start());

        (this->*m_compute_min)(first);
        (this->*m_compute_min)(second);
        // first->compute_min_distance(m_modifiedMinDistance);
        // second->compute_min_distance(m_modifiedMinDistance);
      }

      if(first->start() > 0.0) {
        *p = m_memory_allocator.allocate();
        (*p)->initialize(edge);
        p = &(*p)->next();
      }

      *p = m_memory_allocator.allocate();
      new(*p) geodesic::Interval(*first);
      // std::memcpy(*p,first,sizeof(Interval));
      m_queue.insert(*p);

      if(num_candidates == 2) {
        p = &(*p)->next();
        *p = m_memory_allocator.allocate();
        new(*p) geodesic::Interval(*second);
        // std::memcpy(*p,second,sizeof(Interval));
        m_queue.insert(*p);
      }

      if(second->stop() < edge->length()) {
        p = &(*p)->next();
        *p = m_memory_allocator.allocate();
        (*p)->initialize(edge);
        (*p)->start() = second->stop();
      }
      else {
        (*p)->next() = NULL;
      }
      return;
    }

    bool propagate_flag;

    for(unsigned i = 0; i < num_candidates; ++i) // for all new intervals
    {
      IntervalWithStop *q = &candidates[i];

      interval_pointer previous = NULL;

      interval_pointer p = list->first();
      assert(p->start() == 0.0);

      while(p != NULL && p->stop() - local_epsilon < q->start()) {
        p = p->next();
      }

      while(p != NULL &&
            p->start() <
              q->stop() - local_epsilon) // go through all old intervals
      {
        if(m_strategy == FINDCIRCUMCENTER && p->min() != GEODESIC_INF &&
           p->source_index() != q->source_index()) {
          // std::cout << "p=" << p->source_index()
          //           << " and q=" << q->source_index() << std::endl;
          for(auto f : p->edge()->adjacent_faces()) {
            m_possible_circumfaces.insert(f);
          }
        }

        unsigned const N = intersect_intervals(p, q); // interset two intervals

        bool isCurrent = false;
        if(m_strategy == FINDCIRCUMCENTER) {
          auto it = m_current_intervals.find(p);
          // auto it = std::find(m_current_intervals.begin(),
          //                     m_current_intervals.end(), p);
          isCurrent = it != m_current_intervals.end();
          if(isCurrent) m_current_intervals.erase(it);
        }

        if(N == 1) {
          if(map[0] == OLD) // if "p" is always better, we do not need to
                            // update anything)
          {
            if(isCurrent) m_current_intervals.insert(p);
            // if(isCurrent) m_current_intervals.push_back(p);

            if(previous) // close previous interval and put in into the queue
            {
              previous->next() = p;
              (this->*m_compute_min)(previous);
              // previous->compute_min_distance(m_modifiedMinDistance);
              m_queue.insert(previous);
              previous = NULL;
            }

            p = p->next();
          }
          else if(previous) // extend previous interval to cover everything;
                            // remove p
          {
            previous->next() = p->next();
            erase_from_queue(p);
            // m_memory_allocator.deallocate(p);

            p = previous->next();
          }
          else // p becomes "previous"
          {
            previous = p;
            interval_pointer next = p->next();
            erase_from_queue(p);
            // m_memory_allocator.deallocate(p);

            previous = m_memory_allocator.allocate();
            *previous = *q;
            // std::memcpy(previous,q,sizeof(Interval));

            previous->start() = start[0];
            previous->next() = next;

            p = next;
          }
          continue;
        }

        // update_flag = true;

        Interval swap(*p); // used for swapping information
        propagate_flag = erase_from_queue(p);
        // m_memory_allocator.deallocate(p);
        p = m_memory_allocator.allocate();
        *p = swap;

        for(unsigned j = 1; j < N; ++j) // no memory is needed for the first one
        {
          i_new[j] = m_memory_allocator.allocate(); // create new intervals
        }

        if(map[0] == OLD) // finish previous, if any
        {
          if(isCurrent) m_current_intervals.insert(p);
          // if(isCurrent) m_current_intervals.push_back(p);
          if(previous) {
            previous->next() = p;
            (this->*m_compute_min)(previous);
            // previous->compute_min_distance(m_modifiedMinDistance);
            m_queue.insert(previous);
            previous = NULL;
          }
          i_new[0] = p;
          p->next() = i_new[1];
          p->start() = start[0];
        }
        else if(previous) // extend previous interval to cover everything;
                          // remove p
        {
          i_new[0] = previous;
          previous->next() = i_new[1];
          m_memory_allocator.deallocate(p);
          previous = NULL;
        }
        else // p becomes "previous"
        {
          i_new[0] = p;
          *p = *q;
          // std::memcpy(p,q,sizeof(Interval));

          p->next() = i_new[1];
          p->start() = start[0];
        }

        assert(!previous);

        for(unsigned j = 1; j < N; ++j) {
          interval_pointer current_interval = i_new[j];

          if(map[j] == OLD) {
            if(isCurrent) m_current_intervals.insert(current_interval);
            // if(isCurrent) m_current_intervals.push_back(current_interval);
            *current_interval = swap;
            // std::memcpy(current_interval,&swap,sizeof(Interval));
          }
          else {
            *current_interval = *q;
            // std::memcpy(current_interval,q,sizeof(Interval));
          }

          if(j == N - 1) { current_interval->next() = swap.next(); }
          else {
            current_interval->next() = i_new[j + 1];
          }

          current_interval->start() = start[j];
        }

        for(unsigned j = 0; j < N;
            ++j) // find "min" and add the intervals to the queue
        {
          if(j == N - 1 && map[j] == NEW) { previous = i_new[j]; }
          else {
            interval_pointer current_interval = i_new[j];

            (this->*m_compute_min)(current_interval);
            // current_interval->compute_min_distance(m_modifiedMinDistance);
            // //compute minimal distance

            if(map[j] == NEW || (map[j] == OLD && propagate_flag)) {
              m_queue.insert(current_interval);
            }
          }
        }

        p = swap.next();
      }

      if(previous) // close previous interval and put in into the queue
      {
        (this->*m_compute_min)(previous);
        // previous->compute_min_distance(m_modifiedMinDistance);
        m_queue.insert(previous);
        previous = NULL;
      }
    }
  }

  inline unsigned GeodesicAlgorithmExact::compute_propagated_parameters(
    double pseudo_x, double pseudo_y,
    double d, // parameters of the interval
    double begin,
    double end, // start/end of the interval
    double alpha, // corner angle
    double L, // length of the new edge
    int source_index, unsigned depth,
    bool first_interval, // if it is the first interval on the edge
    bool last_interval, bool turn_left, bool turn_right,
    IntervalWithStop *candidates) // if it is the last interval on the edge
  {
    // assert(pseudo_y <= 0.0);
    // assert(d < GEODESIC_INF / 10.0);
    // assert(begin <= end);
    // assert(first_interval ? (begin == 0.0) : true);

    IntervalWithStop *p = candidates;

    p->source_index() = source_index;
    p->depth() = depth + 1;
    (p + 1)->source_index() = source_index;
    (p + 1)->depth() = depth + 1;

    if(std::abs(pseudo_y) <= 1e-30) // pseudo-source is on the edge
    {
      if(first_interval && pseudo_x <= 0.0) {
        p->start() = 0.0;
        p->stop() = L;
        p->d() = d - pseudo_x;
        p->pseudo_x() = 0.0;
        p->pseudo_y() = 0.0;
        return 1;
      }
      else if(last_interval && pseudo_x >= end) {
        p->start() = 0.0;
        p->stop() = L;
        p->d() = d + pseudo_x - end;
        p->pseudo_x() = end * cos(alpha);
        p->pseudo_y() = -end * sin(alpha);
        return 1;
      }
      else if(pseudo_x >= begin && pseudo_x <= end) {
        p->start() = 0.0;
        p->stop() = L;
        p->d() = d;
        p->pseudo_x() = pseudo_x * cos(alpha);
        p->pseudo_y() = -pseudo_x * sin(alpha);
        return 1;
      }
      else {
        return 0;
      }
    }

    double sin_alpha = sin(alpha);
    double cos_alpha = cos(alpha);

    // important: for the first_interval, this function returns zero only if
    // the new edge is "visible" from the source if the new edge can be
    // covered only after turn_over, the value is negative (-1.0)
    double L1 = compute_positive_intersection(begin, pseudo_x, pseudo_y,
                                              sin_alpha, cos_alpha);

    if(L1 < 0 || L1 >= L) {
      if(first_interval && turn_left) {
        p->start() = 0.0;
        p->stop() = L;
        p->d() = d + sqrt(pseudo_x * pseudo_x + pseudo_y * pseudo_y);
        p->pseudo_y() = 0.0;
        p->pseudo_x() = 0.0;
        return 1;
      }
      else {
        return 0;
      }
    }

    double L2 = compute_positive_intersection(end, pseudo_x, pseudo_y,
                                              sin_alpha, cos_alpha);

    if(L2 < 0 || L2 >= L) {
      p->start() = L1;
      p->stop() = L;
      p->d() = d;
      p->pseudo_x() = cos_alpha * pseudo_x + sin_alpha * pseudo_y;
      p->pseudo_y() = -sin_alpha * pseudo_x + cos_alpha * pseudo_y;

      return 1;
    }

    p->start() = L1;
    p->stop() = L2;
    p->d() = d;
    p->pseudo_x() = cos_alpha * pseudo_x + sin_alpha * pseudo_y;
    p->pseudo_y() = -sin_alpha * pseudo_x + cos_alpha * pseudo_y;
    assert(p->pseudo_y() <= 0.0);

    if(!(last_interval && turn_right)) { return 1; }
    else {
      p = candidates + 1;

      p->start() = L2;
      p->stop() = L;
      double dx = pseudo_x - end;
      p->d() = d + sqrt(dx * dx + pseudo_y * pseudo_y);
      p->pseudo_x() = end * cos_alpha;
      p->pseudo_y() = -end * sin_alpha;

      return 2;
    }
  }

  inline void GeodesicAlgorithmExact::construct_propagated_intervals(
    bool invert, edge_pointer edge,
    face_pointer face, // constructs iNew from the rest of the data
    IntervalWithStop *candidates, unsigned &num_candidates,
    interval_pointer source_interval) // up to two candidates
  {
    double edge_length = edge->length();
    double local_epsilon = 1e1 * SMALLEST_INTERVAL_RATIO * edge_length;

    // kill very small intervals in order to avoid precision problems
    if(num_candidates == 2) {
      double start = std::min(candidates->start(), (candidates + 1)->start());
      double stop = std::max(candidates->stop(), (candidates + 1)->stop());
      if(candidates->stop() - candidates->start() <
         local_epsilon) // kill interval 0
      {
        *candidates = *(candidates + 1);
        num_candidates = 1;
        candidates->start() = start;
        candidates->stop() = stop;
      }
      else if((candidates + 1)->stop() - (candidates + 1)->start() <
              local_epsilon) {
        num_candidates = 1;
        candidates->start() = start;
        candidates->stop() = stop;
      }
    }

    IntervalWithStop *first;
    IntervalWithStop *second;
    if(num_candidates == 1) {
      first = candidates;
      second = candidates;
    }
    else {
      if(candidates->start() <= (candidates + 1)->start()) {
        first = candidates;
        second = candidates + 1;
      }
      else {
        first = candidates + 1;
        second = candidates;
      }
      assert(first->stop() == second->start());
    }

    if(first->start() < local_epsilon) { first->start() = 0.0; }
    if(edge_length - second->stop() < local_epsilon) {
      second->stop() = edge_length;
    }

    // invert intervals if necessary; fill missing data and set pointers
    // correctly
    Interval::DirectionType direction =
      edge->adjacent_faces()[0]->id() == face->id() ? Interval::FROM_FACE_0 :
                                                      Interval::FROM_FACE_1;

    if(!invert) // in this case everything is straighforward, we do not have
                // to invert the intervals
    {
      for(unsigned i = 0; i < num_candidates; ++i) {
        IntervalWithStop *p = candidates + i;

        p->next() = (i == num_candidates - 1) ? NULL : candidates + i + 1;
        p->edge() = edge;
        p->direction() = direction;
        p->source_index() = source_interval->source_index();
        p->depth() = source_interval->depth() + 1;

        p->min() = 0.0; // it will be changed later on

        // assert(p->start() < p->stop());
      }
    }
    else // now we have to invert the intervals
    {
      for(unsigned i = 0; i < num_candidates; ++i) {
        IntervalWithStop *p = candidates + i;

        p->next() = (i == 0) ? NULL : candidates + i - 1;
        p->edge() = edge;
        p->direction() = direction;
        p->source_index() = source_interval->source_index();
        p->depth() = source_interval->depth() + 1;

        double length = edge_length;
        p->pseudo_x() = length - p->pseudo_x();

        double start = length - p->stop();
        p->stop() = length - p->start();
        p->start() = start;

        p->min() = 0;

        // assert(p->start() < p->stop());
        // assert(p->start() >= 0.0);
        // assert(p->stop() <= edge->length());
      }
    }
  }

  inline unsigned GeodesicAlgorithmExact::best_source(
    SurfacePoint &point, // quickly find what source this point belongs to and
                         // what is the distance to this source
    double &best_source_distance)
  {
    double best_interval_position;
    unsigned best_source_index = std::numeric_limits<unsigned>::max();

    best_first_interval(point, best_source_distance, best_interval_position,
                        best_source_index);

    return best_source_index;
  }

  inline interval_pointer GeodesicAlgorithmExact::best_first_interval(
    SurfacePoint &point, double &best_total_distance,
    double &best_interval_position, unsigned &best_source_index)
  {
    assert(point.type() != UNDEFINED_POINT);
    // std::cout << "point type: " << point.type() << std::endl;

    interval_pointer best_interval = NULL;
    best_total_distance = GEODESIC_INF;

    if(point.type() == EDGE) {
      edge_pointer e = static_cast<edge_pointer>(point.base_element());
      list_pointer list = interval_list(e);

      best_interval_position = point.distance(e->v0());
      best_interval = list->covering_interval(best_interval_position);
      if(best_interval &&
         (best_source_index == std::numeric_limits<unsigned>::max() ||
          best_source_index == best_interval->source_index())) {
        // assert(best_interval && best_interval->d() < GEODESIC_INF);
        best_total_distance = best_interval->signal(best_interval_position);
      }
    }
    else if(point.type() == FACE) {
      face_pointer f = static_cast<face_pointer>(point.base_element());
      for(unsigned i = 0; i < 3; ++i) {
        edge_pointer e = f->adjacent_edges()[i];
        list_pointer list = interval_list(e);

        double offset;
        double distance;
        interval_pointer interval;

        unsigned source_index = best_source_index;
        list->find_closest_point(&point, offset, distance, interval,
                                 source_index);

        if(interval && distance < best_total_distance) {
          best_interval = interval;
          best_total_distance = distance;
          best_interval_position = offset;
          // best_source_index = interval->source_index();
        }
      }

      // check for all sources that might be located inside this face
      SortedSources::sorted_iterator_pair local_sources = m_sources.sources(f);
      for(SortedSources::sorted_iterator it = local_sources.first;
          it != local_sources.second; ++it) {
        SurfacePointWithIndex *source = *it;
        if(best_source_index != std::numeric_limits<unsigned>::max() &&
           source->index() != best_source_index)
          continue;
        double distance = point.distance(source);
        if(distance < best_total_distance) {
          best_interval = NULL;
          best_total_distance = distance;
          best_interval_position = 0.0;
          best_source_index = source->index();
        }
      }
      if(best_interval) best_source_index = best_interval->source_index();
    }
    else if(point.type() == VERTEX) {
      // std::vector<edge_pointer> possible_edges;
      // possible_traceback_edges(point, possible_edges);
      // unsigned source_index = best_source_index;
      // best_point_on_the_edge_set(point, possible_edges, best_interval,
      //                            best_total_distance, best_interval_position,
      //                            source_index);

      vertex_pointer v = static_cast<vertex_pointer>(point.base_element());
      for(unsigned i = 0; i < v->adjacent_edges().size(); ++i) {
        edge_pointer e = v->adjacent_edges()[i];
        list_pointer list = interval_list(e);

        double position = e->v0()->id() == v->id() ? 0.0 : e->length();
        interval_pointer interval = list->covering_interval(position);
        if(!interval) continue;
        if(best_source_index != std::numeric_limits<unsigned>::max() &&
           interval->source_index() != best_source_index)
          continue;

        // if(best_interval != nullptr &&
        //    best_interval->depth() >= interval->depth())
        //   continue;
        double distance = interval->signal(position);
        //
        // std::cout << "\t" << interval->d() << " "
        //           << interval->stop() - interval->start() << std::endl;
        //
        if(distance < best_total_distance) {
          best_interval = interval;
          best_total_distance = distance;
          best_interval_position = position;
        }
      }
    }

    if(best_interval &&
       best_source_index == std::numeric_limits<unsigned>::max())
      best_source_index = best_interval->source_index();
    return best_interval;
  }

  inline void GeodesicAlgorithmExact::trace_back(
    SurfacePoint &destination, // trace back piecewise-linear path
    std::vector<SurfacePoint> &path, unsigned source_index)
  {
    // if(m_strategy == FINDCIRCUMCENTER &&
    //    destination.type() == UNDEFINED_POINT) {
    //   path = m_shortest_path;
    //   return;
    // }

    path.clear();
    double best_total_distance = geodesic::GEODESIC_INF;
    double best_interval_position = 0.;
    // std::cout << source_index << std::endl;
    interval_pointer best_interval = best_first_interval(
      destination, best_total_distance, best_interval_position, source_index);

    // if(true)
    if(best_total_distance >=
       GEODESIC_INF / 2.0) // unable to find the right path
    {
      // std::ofstream posFile("traceback_intervals.pos");
      // posFile << "View \"Traceback Intervals\" {\n";
      // for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
      //   list_pointer list = &m_edge_interval_lists[i];
      //   interval_pointer p = list->first();
      //   while(p) {
      //     edge_pointer edge = p->edge();
      //     vertex_pointer v0 = edge->v0();
      //     vertex_pointer v1 = edge->v1();
      //     double start = p->start();
      //     double stop = p->stop();
      //     double length = edge->length();
      //     double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
      //     double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
      //     double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
      //     double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
      //     double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
      //     double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
      //     posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
      //     ","
      //             << y1 << "," << z1 << "){" << p->signal(start) << ","
      //             << p->signal(stop) << "};\n";
      //     p = p->next();
      //   }
      // }
      // posFile << "SP(" << destination.x() << "," << destination.y() << ","
      //         << destination.z() << "){" << 10 << "};\n";
      // for(size_t i = 0; i < m_sources.size(); ++i) {
      //   posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
      //   ","
      //           << m_sources[i].z() << "){" << i << "};\n";
      // }
      // for(size_t i = 0; i < m_stop_vertices.size(); ++i) {
      //   posFile << "SP(" << m_stop_vertices[i]->x() << ","
      //           << m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z()
      //           << "){1};\n";
      // }
      // posFile << "};\n";
      // posFile.close();
      // std::cerr << "Warning: GeodesicAlgorithmExact::trace_back: cannot find
      // "
      //              "the right path"
      //           << std::endl;
      // // return;
    }

    path.push_back(destination);

    // std::cout << "ok" << std::endl;

    // std::cout << std::endl;
    double lastDistance = best_total_distance;
    // std::cout << std::setprecision(std::numeric_limits<double>::max_digits10)
    //           << lastDistance << " (" << best_interval->source_index() << ")
    //           "
    //           << std::endl;
    if(best_interval) // if we did not hit the face source immediately
    {
      if(best_interval->source_index() == std::numeric_limits<int>::max())
        throw std::runtime_error("Error: source is max");

      std::vector<edge_pointer> possible_edges;
      possible_edges.reserve(10);

      unsigned depth = std::numeric_limits<unsigned>::max();
      // std::cout << depth << std::endl;
      unsigned counter = 0;
      interval_pointer interval = nullptr;
      std::vector<face_pointer> incident_faces;
      while(
        visible_from_source(path.back()) <
        0) // while this point is not in the direct visibility of some source
           // (if we are inside the FACE, we obviously hit the source)
      {
        SurfacePoint &q = path.back();
        // std::cout << "oo " << q.base_element()->id() << " " << last
        //           << std::endl;
        // std::cout << "ok " << q.base_element()->id()
        // << " " << last
        //           << std::endl;

        double total_distance;
        double position = 0.;

        possible_traceback_edges(q, possible_edges, incident_faces, interval);
        interval = nullptr;
        best_point_on_the_edge_set(q, possible_edges, incident_faces, interval,
                                   total_distance, position, source_index,
                                   depth);

        if(!interval) {
          std::cout << "Could not find a trace back interval" << std::endl;
          throw std::runtime_error(
            "Error: Could not find a trace back interval");
        }

        // if(total_distance - lastDistance > 1e-9) {
        //   std::cout << std::setprecision(
        //                  std::numeric_limits<double>::max_digits10)
        //             << total_distance << " ( " <<
        //             best_interval->source_index()
        //             << " )" << " > " << lastDistance
        //             << ", diff = " << total_distance - lastDistance
        //
        //             << std::endl;
        //   // throw std::runtime_error(
        //   //   "Distance increased: " + std::to_string(total_distance) + " >
        //   " +
        //   //   std::to_string(lastDistance) + " (diff " +
        //   //   std::to_string(total_distance - lastDistance) + ")");
        // }
        lastDistance = total_distance;

        depth = interval->depth();
        // std::cout << depth << std::endl;
        // std::cout << q.x() << " " << q.y() << " " << q.z() << " " <<
        // q.type()
        //           << std::endl;
        // std::cout << total_distance << std::endl;
        // assert(total_distance < GEODESIC_INF);
        // source_index = interval->source_index();

        edge_pointer e = interval->edge();
        double local_epsilon = 1e5 * SMALLEST_INTERVAL_RATIO * e->length();
        // std::cout << "pos: " << position << " vs " << local_epsilon
        //           << std::endl;
        if(position < local_epsilon) { path.push_back(SurfacePoint(e->v0())); }
        else if(position > e->length() - local_epsilon) {
          path.push_back(SurfacePoint(e->v1()));
        }
        else {
          double normalized_position = position / e->length();
          path.push_back(SurfacePoint(e, normalized_position));
        }
        // std::cout << best_interval->source_index() << ": " << total_distance
        //           << "\n";
        if(++counter >= 1e8) {
          std::cout << "Could not trace back geodesic in less that " +
                         std::to_string(counter) + " steps"
                    << std::endl;
          std::ofstream posFile("traceback_intervals.pos");
          posFile << "View \"Traceback Intervals\" {\n";
          for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
            list_pointer list = &m_edge_interval_lists[i];
            interval_pointer p = list->first();
            while(p) {
              edge_pointer edge = p->edge();
              vertex_pointer v0 = edge->v0();
              vertex_pointer v1 = edge->v1();
              double start = p->start();
              double stop = p->stop();
              double length = edge->length();
              double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
              double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
              double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
              double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
              double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
              double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
              posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
                      << "," << y1 << "," << z1 << "){" << p->signal(start)
                      << "," << p->signal(stop) << "};\n";
              p = p->next();
            }
          }
          posFile << "SP(" << destination.x() << "," << destination.y() << ","
                  << destination.z() << "){" << 10 << "};\n";
          for(size_t i = 0; i < m_sources.size(); ++i) {
            posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y()
                    << "," << m_sources[i].z() << "){" << i << "};\n";
          }
          for(size_t i = 0; i < m_stop_vertices.size(); ++i) {
            posFile << "SP(" << m_stop_vertices[i]->x() << ","
                    << m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z()
                    << "){1};\n";
          }
          posFile << "};\n";
          posFile.close();

          throw std::runtime_error(
            "Error: Could not trace back geodesic in less that " +
            std::to_string(counter) + " steps");
        }
      }
    }

    if(source_index == std::numeric_limits<unsigned>::max())
      throw std::runtime_error("Error: std max");
    SurfacePoint &source = static_cast<SurfacePoint &>(m_sources[source_index]);
    if(path.back().distance(&source) > 0) { path.push_back(source); }
  }

  // // Linked
  // inline void GeodesicAlgorithmExact::trace_back(
  //   SurfacePoint &destination, // trace back piecewise-linear path
  //   std::vector<SurfacePoint> &path, unsigned source_index)
  // {
  //   if(m_strategy == FINDCIRCUMCENTER &&
  //      destination.type() == UNDEFINED_POINT) {
  //     path = m_shortest_path;
  //     return;
  //   }
  //
  //   path.clear();
  //   double best_total_distance;
  //   double best_interval_position;
  //   // std::cout << source_index << std::endl;
  //   interval_pointer best_interval = best_first_interval(
  //     destination, best_total_distance, best_interval_position,
  //     source_index);
  //
  //   if(best_total_distance >=
  //      GEODESIC_INF / 2.0) // unable to find the right path
  //   {
  //     std::ofstream posFile("traceback_intervals.pos");
  //     posFile << "View \"Traceback Intervals\" {\n";
  //     for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
  //       list_pointer list = &m_edge_interval_lists[i];
  //       interval_pointer p = list->first();
  //       while(p) {
  //         edge_pointer edge = p->edge();
  //         vertex_pointer v0 = edge->v0();
  //         vertex_pointer v1 = edge->v1();
  //         double start = p->start();
  //         double stop = p->stop();
  //         double length = edge->length();
  //         double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
  //         double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
  //         double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
  //         double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
  //         double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
  //         double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
  //         posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
  //         ","
  //                 << y1 << "," << z1 << "){" << p->edge()->id() << ","
  //                 << p->edge()->id() << "};\n";
  //         p = p->next();
  //       }
  //     }
  //     posFile << "SP(" << destination.x() << "," << destination.y() << ","
  //             << destination.z() << "){" << 10 << "};\n";
  //     for(size_t i = 0; i < m_sources.size(); ++i) {
  //       posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
  //       ","
  //               << m_sources[i].z() << "){" << i << "};\n";
  //     }
  //     for(size_t i = 0; i < m_stop_vertices.size(); ++i) {
  //       posFile << "SP(" << m_stop_vertices[i]->x() << ","
  //               << m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z()
  //               << "){1};\n";
  //     }
  //     posFile << "};\n";
  //     posFile.close();
  //     std::cerr << "Warning: GeodesicAlgorithmExact::trace_back: cannot find
  //     "
  //                  "the right path"
  //               << std::endl;
  //     // return;
  //   }
  //
  //   path.push_back(destination);
  //
  //   std::cout << "ok" << std::endl;
  //
  //   int last = -1, lastlast = -2;
  //
  //   if(best_interval) { std::cout << "best interval found" << std::endl; }
  //
  //   if(best_interval) // if we did not hit the face source immediately
  //   {
  //     std::vector<edge_pointer> possible_edges;
  //     possible_edges.reserve(10);
  //
  //     interval_pointer interval = best_interval;
  //     while(
  //       visible_from_source(path.back()) <
  //       0) // while this point is not in the direct visibility of some source
  //          // (if we are inside the FACE, we obviously hit the source)
  //     {
  //       SurfacePoint &q = path.back();
  //       std::cout << "oo " << q.base_element()->id() << " " << last
  //                 << std::endl;
  //       if(lastlast == q.base_element()->id()) throw
  //       std::runtime_error("err"); lastlast = last; last =
  //       q.base_element()->id(); std::cout << "ok " << q.base_element()->id()
  //       << " " << last
  //                 << std::endl;
  //
  //       double position;
  //       interval_pointer parent = interval->parent();
  //       if(!parent) {
  //         std::cout << "no parent !" << std::endl;
  //         std::cout << interval->direction() << std::endl;
  //         std::cout << path.size() << std::endl;
  //         // throw std::runtime_error("error no parent !");
  //         break;
  //       }
  //       if(interval == parent) {
  //         std::cout << "self parent !" << std::endl;
  //         throw std::runtime_error("error self parent !");
  //       }
  //       parent->compute_min_distance_to(&q, &position);
  //       position /= parent->edge()->length();
  //       path.push_back(SurfacePoint(parent->edge(), position));
  //       interval = parent;
  //
  //       // possible_traceback_edges(q, possible_edges);
  //       //
  //       // interval_pointer interval = 0ULL;
  //       // double total_distance;
  //       // double position = 0.;
  //       //
  //       // best_point_on_the_edge_set(q, possible_edges, interval,
  //       // total_distance,
  //       //                            position, source_index);
  //       //
  //       // // std::cout << q.x() << " " << q.y() << " " << q.z() << " " <<
  //       // q.type()
  //       // //           << std::endl;
  //       // // std::cout << total_distance << std::endl;
  //       // assert(total_distance < GEODESIC_INF);
  //       // // source_index = interval->source_index();
  //       //
  //       // edge_pointer e = interval->edge();
  //       // double local_epsilon = SMALLEST_INTERVAL_RATIO * e->length();
  //       // std::cout << "pos: " << position << " vs " << local_epsilon
  //       //           << std::endl;
  //       // if(position < local_epsilon) {
  //       path.push_back(SurfacePoint(e->v0()));
  //       // } else if(position > e->length() - local_epsilon) {
  //       //   path.push_back(SurfacePoint(e->v1()));
  //       // }
  //       // else {
  //       //   double normalized_position = position / e->length();
  //       //   path.push_back(SurfacePoint(e, normalized_position));
  //       // }
  //     }
  //   }
  //
  //   if(source_index == std::numeric_limits<unsigned>::max())
  //     throw std::runtime_error("error std max");
  //
  //   path.push_back(SurfacePoint(m_sources[source_index]));
  //
  //   // std::cout << path.size() << std::endl;
  //   // for(auto p : path) {
  //   //   std::cout << p.type() << std::endl;
  //   //   if(p.type() == FACE) continue;
  //   //   for(auto f : p.base_element()->adjacent_faces()) {
  //   //     std::cout << "\t" << f->id() << std::endl;
  //   //   }
  //   // }
  //
  //   if(true)
  //   // if(best_total_distance >=
  //   //    GEODESIC_INF / 2.0) // unable to find the right path
  //   {
  //     std::ofstream posFile("traceback_intervals_with_path.pos");
  //     posFile << "View \"Traceback Intervals\" {\n";
  //     for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
  //       list_pointer list = &m_edge_interval_lists[i];
  //       interval_pointer p = list->first();
  //       while(p) {
  //         edge_pointer edge = p->edge();
  //         vertex_pointer v0 = edge->v0();
  //         vertex_pointer v1 = edge->v1();
  //         double start = p->start();
  //         double stop = p->stop();
  //         double length = edge->length();
  //         double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
  //         double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
  //         double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
  //         double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
  //         double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
  //         double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
  //         posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
  //         ","
  //                 << y1 << "," << z1 << "){" << p->edge()->id() << ","
  //                 << p->edge()->id() << "};\n";
  //         p = p->next();
  //       }
  //     }
  //     posFile << "SP(" << destination.x() << "," << destination.y() << ","
  //             << destination.z() << "){" << 10 << "};\n";
  //     for(size_t i = 0; i < m_sources.size(); ++i) {
  //       posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
  //       ","
  //               << m_sources[i].z() << "){" << i << "};\n";
  //     }
  //     for(size_t i = 0; i < m_stop_vertices.size(); ++i) {
  //       posFile << "SP(" << m_stop_vertices[i]->x() << ","
  //               << m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z()
  //               << "){1};\n";
  //     }
  //     for(size_t i = 1; i < path.size(); ++i) {
  //       posFile << "SL(" << path[i - 1].x() << "," << path[i - 1].y() << ","
  //               << path[i - 1].z() << "," << path[i].x() << "," <<
  //               path[i].y()
  //               << "," << path[i].z() << "){"
  //               << path[i - 1].base_element()->id() << ","
  //               << path[i].base_element()->id() << "};\n";
  //     }
  //     posFile << "};\n";
  //     posFile.close();
  //     std::cerr << "Warning: GeodesicAlgorithmExact::trace_back: cannot find
  //     "
  //                  "the right path"
  //               << std::endl;
  //     // return;
  //   }
  // }

  inline void GeodesicAlgorithmExact::findCircumcenter(
    Face *f, SurfacePoint &spCircumcenter,
    std::vector<SurfacePoint> &circumCenters, std::vector<double> &circumRadii,
    std::vector<unsigned> &circumSources)
  {
    circumCenters.clear();
    circumRadii.clear();
    circumSources.clear();
    Vertex *vs[3] = {f->adjacent_vertices()[0], f->adjacent_vertices()[1],
                     f->adjacent_vertices()[2]};

    std::vector<Interval *> intervalToCheck;
    for(auto interval : m_current_intervals) {
      for(auto fc : interval->edge()->adjacent_faces()) {
        if(fc == f) {
          intervalToCheck.push_back(interval);
          break;
        }
      }
      // Vertex *v = interval->edge()->v0();
      // if(v != vs[0] && v != vs[1] && v != vs[2]) continue;
      // v = interval->edge()->v1();
      // if(v != vs[0] && v != vs[1] && v != vs[2]) continue;
      // intervalToCheck.push_back(interval);
    }
    if(intervalToCheck.size() == 0) return;
    // std::vector<unsigned> indicesToCheck(intervalToCheck.size());
    std::vector<unsigned> indicesToCheck;
    indicesToCheck.reserve(2 * intervalToCheck.size());
    // std::cout << "(" << vs[0]->x() << "," << vs[0]->y() << "," <<
    // vs[0]->z()
    //           << ") " << "(" << vs[1]->x() << "," << vs[1]->y() << ","
    //           << vs[1]->z() << ") " << "(" << vs[2]->x() << "," <<
    //           vs[2]->y()
    //           << "," << vs[2]->z() << ") " << std::endl;
    // double dx = vs[2]->x() - vs[1]->x();
    // double dy = vs[2]->y() - vs[1]->y();
    // double dz = vs[2]->z() - vs[1]->z();
    // double l0 = sqrt(dx * dx + dy * dy + dz * dz);
    // dx = vs[0]->x() - vs[2]->x();
    // dy = vs[0]->y() - vs[2]->y();
    // dz = vs[0]->z() - vs[2]->z();
    // double l1 = sqrt(dx * dx + dy * dy + dz * dz);
    // dx = vs[1]->x() - vs[0]->x();
    // dy = vs[1]->y() - vs[0]->y();
    // dz = vs[1]->z() - vs[0]->z();
    // double l2 = sqrt(dx * dx + dy * dy + dz * dz);

    double e0[3] = {vs[1]->x() - vs[0]->x(), vs[1]->y() - vs[0]->y(),
                    vs[1]->z() - vs[0]->z()};
    double e1[3] = {vs[2]->x() - vs[0]->x(), vs[2]->y() - vs[0]->y(),
                    vs[2]->z() - vs[0]->z()};
    double local_scale = sqrt(e0[0] * e0[0] + e0[1] * e0[1] + e0[2] * e0[2]);
    double inv_local_scale = 1. / local_scale;
    e0[0] *= inv_local_scale;
    e0[1] *= inv_local_scale;
    e0[2] *= inv_local_scale;
    e1[0] *= inv_local_scale;
    e1[1] *= inv_local_scale;
    e1[2] *= inv_local_scale;

    double norm0 = sqrt(e0[0] * e0[0] + e0[1] * e0[1] + e0[2] * e0[2]);

    double d = e1[0] * e0[0] + e1[1] * e0[1] + e1[2] * e0[2];
    e1[0] -= d * e0[0];
    e1[1] -= d * e0[1];
    e1[2] -= d * e0[2];
    double norm1 = sqrt(e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2]);
    if(norm1 < 1e-14) return;
    double inv_norm1 = 1. / norm1;
    e1[0] *= inv_norm1;
    e1[1] *= inv_norm1;
    e1[2] *= inv_norm1;

    const double pxs[3] = {0., norm0, d};
    // const double pxs[3] = {0., 1., d};
    const double pys[3] = {0., 0., norm1};
    const double rots[3] = {0., M_PI - atan2(norm1, norm0 - d),
                            -M_PI + atan2(norm1, d)};
    // const double rots[3] = {0., M_PI - atan2(norm1, 1. - d),
    //                         -M_PI + atan2(norm1, d)};
    // const double coss[3] = {cos(rots[0]), cos(rots[1]), cos(rots[2])};
    // const double sins[3] = {sin(rots[0]), sin(rots[1]), sin(rots[2])};
    const double coss[3] = {cos(rots[0]) * inv_local_scale,
                            cos(rots[1]) * inv_local_scale,
                            cos(rots[2]) * inv_local_scale};
    const double sins[3] = {sin(rots[0]) * inv_local_scale,
                            sin(rots[1]) * inv_local_scale,
                            sin(rots[2]) * inv_local_scale};
    // const double coss[3] = {1., -(l0 * l0 + l2 * l2 - l1 * l1) / (2 * l0 *
    // l2),
    //                         -(l1 * l1 + l2 * l2 - l0 * l0) / (2 * l1 * l2)};
    // const double sins[3] = {0., sqrt(1. - coss[1] * coss[1]),
    //                         -sqrt(1. - coss[2] * coss[2])};

    std::vector<unsigned> sourceIndices;
    std::vector<double> sourceXs;
    std::vector<double> sourceYs;
    std::vector<double> sourceDs;
    std::vector<Interval *> sourceIntervals;

    for(int j = 0; j < 3; ++j) {
      Edge *e = f->opposite_edge(vs[(j + 2) % 3]);
      bool swap = false;
      if(e->v0() == vs[j] && e->v1() == vs[(j + 1) % 3])
        swap = false;
      else if(e->v0() == vs[(j + 1) % 3] && e->v1() == vs[j])
        swap = true;

      // for(auto ee : f->adjacent_edges()) {
      //   if(ee->adjacent_vertices()[0] == vs[j] &&
      //      ee->adjacent_vertices()[1] == vs[(j + 1) % 3]) {
      //     e = ee;
      //     break;
      //   }
      //   if(ee->adjacent_vertices()[0] == vs[(j + 1) % 3] &&
      //      ee->adjacent_vertices()[1] == vs[j]) {
      //     e = ee;
      //     swap = true;
      //     break;
      //   }
      // }
      // if(e == nullptr) {
      //   std::cerr << "propagateToCircumcenter: edge not found" << std::endl;
      //   return;
      // }

      Interval *next = interval_list(e)->first();
      while(next != nullptr) {
        Interval *p = next;
        if(p->min() >= GEODESIC_INF) {
          next = p->next();
          continue;
        }
        // if(!computeSource[p->source_index()] &&
        //    computeInterval.find(p) == computeInterval.end()) {
        //   p = p->next();
        //   continue;
        // }

        double x = p->pseudo_x(), y = p->pseudo_y();
        if(swap) { x = e->length() - x; }

        if((p->direction() == IntervalWithStop::DirectionType::FROM_FACE_1 &&
            f == e->adjacent_faces()[0]) ||
           (p->direction() == IntervalWithStop::DirectionType::FROM_FACE_0 &&
            f == e->adjacent_faces()[1]) ||
           (p->direction() == IntervalWithStop::DirectionType::FROM_SOURCE)) {
          double px = x * coss[j] - y * sins[j] + pxs[j];
          double py = x * sins[j] + y * coss[j] + pys[j];

          auto it =
            std::find(intervalToCheck.begin(), intervalToCheck.end(), p);
          if(it != intervalToCheck.end()) {
            // indicesToCheck[it - intervalToCheck.begin()] =
            //   sourceIntervals.size();
            indicesToCheck.push_back(sourceIntervals.size());
          }

          sourceIndices.push_back(p->source_index());
          sourceXs.push_back(px);
          sourceYs.push_back(py);
          sourceDs.push_back(p->d() * inv_local_scale);
          sourceIntervals.push_back(p);
        }

        if((p->direction() == IntervalWithStop::DirectionType::FROM_FACE_0 &&
            f == p->edge()->adjacent_faces()[0]) ||
           (p->direction() == IntervalWithStop::DirectionType::FROM_FACE_1 &&
            f == p->edge()->adjacent_faces()[1]) ||
           (p->direction() == IntervalWithStop::DirectionType::FROM_SOURCE)) {
          double px = x * coss[j] + y * sins[j] + pxs[j];
          double py = x * sins[j] - y * coss[j] + pys[j];

          auto it =
            std::find(intervalToCheck.begin(), intervalToCheck.end(), p);
          if(it != intervalToCheck.end()) {
            // indicesToCheck[it - intervalToCheck.begin()] =
            //   sourceIntervals.size();
            indicesToCheck.push_back(sourceIntervals.size());
          }

          sourceIndices.push_back(p->source_index());
          sourceXs.push_back(px);
          sourceYs.push_back(py);
          sourceDs.push_back(p->d() * inv_local_scale);
          sourceIntervals.push_back(p);
        }
        next = p->next();
      }

      // Add a source at the vertices (saddle or boundary or through vertex)
      // if(vs[j]->saddle_or_boundary()) {
      {
        // SurfacePoint sp = SurfacePoint(f, vs[j]->x(), vs[j]->y(),
        // vs[j]->z(), geodesic::FACE);
        SurfacePoint sp = SurfacePoint(vs[j]);
        interval_pointer interval = 0ULL;
        double total_distance, position;
        // best_point_on_the_edge_set(sp,
        // 							{e},
        // 							interval,
        // 							total_distance,
        // 							position);
        IntervalList *list = interval_list(e);
        SurfacePoint *p = &sp;
        list->find_closest_point(p, position, total_distance, interval);
        if(total_distance >= GEODESIC_INF) continue;
        if(total_distance == 0.) continue;
        if(swap) position = e->length() - position;
        double px = position * coss[j] + pxs[j];
        double py = position * sins[j] + pys[j];

        // std::cout << "Saddle: " << interval->source_index() << std::endl;
        // double off, dist, x, y;
        // interval->edge()->local_coordinates(&sp, x, y);
        // std::cout << "x=" << x << " y=" << y << " " <<
        // interval->edge()->length() << std::endl;

        // std::cout << sourceIndices.size() << ": " <<
        // interval->source_index()
        // << " " << px << " " << py << " " << total_distance << " " <<
        // interval
        // << std::endl;

        auto it =
          std::find(intervalToCheck.begin(), intervalToCheck.end(), interval);
        if(it != intervalToCheck.end()) {
          // indicesToCheck[it - intervalToCheck.begin()] =
          // sourceIntervals.size();
          indicesToCheck.push_back(sourceIntervals.size());
        }

        sourceIndices.push_back(interval->source_index());
        sourceXs.push_back(px);
        sourceYs.push_back(py);
        sourceDs.push_back(total_distance * inv_local_scale);
        if(interval == nullptr)
          throw std::runtime_error("Error: interval is nullptr");
        sourceIntervals.push_back(interval);
      }
    }

    // std::cout << "type shit" << std::endl;

    // Add vertices on face
    Edge *e = nullptr;
    bool swap = false;
    for(auto ee : f->adjacent_edges()) {
      if(ee->adjacent_vertices()[0] == vs[0] &&
         ee->adjacent_vertices()[1] == vs[1]) {
        e = ee;
        break;
      }
      if(ee->adjacent_vertices()[0] == vs[1] &&
         ee->adjacent_vertices()[1] == vs[0]) {
        e = ee;
        swap = true;
        break;
      }
    }
    if(e == nullptr) {
      std::cerr << "propagateToCircumcenter: edge not found" << std::endl;
      return;
    }
    // for (size_t i = 0; i < m_sources.size(); ++i) {
    // 	if (m_sources[i].type() != FACE ||
    // 		m_sources[i].base_element() != f)
    // 		continue;

    if(m_sources_on_face.count(f->id())) {
      for(auto i : m_sources_on_face[f->id()]) {
        geodesic::SurfacePoint source = m_sources[i];
        if(source.type() != FACE || source.base_element() != f) continue;

        double dx, dy;
        e->local_coordinates(&source, dx, dy);
        if(swap) dx = e->length() - dx;
        double px = dx * coss[0];
        double py = dy * sins[0];

        // std::cout << sourceIndices.size() << ": " << i << " " << dx << " " <<
        // dy << " " << 0. << " nullptr" << std::endl;
        // TODO: manage vertices on a same face

        // indicesToCheck.push_back(sourceIndices.size());

        sourceIndices.push_back(i);
        sourceXs.push_back(px);
        sourceYs.push_back(py);
        sourceDs.push_back(0.);
        sourceIntervals.push_back(nullptr);
        // std::cout << "source type " << sources[i].type() << " and " <<
        // sources[i].base_element() << std::endl;
      }
    }

    // std::cout << "sourceIndices.size()=" << sourceIndices.size() <<
    // std::endl; std::cout << "sourceXs.size()=" << sourceXs.size() <<
    // std::endl; std::cout << "sourceYs.size()=" << sourceYs.size() <<
    // std::endl; std::cout << "sourceDs.size()=" << sourceDs.size() <<
    // std::endl; std::cout << "sourceIntervals.size()=" <<
    // sourceIntervals.size() << std::endl;

    circumCenters.clear();
    circumRadii.clear();
    circumSources.clear();

    // // Write circumcenters to a .pos file
    // FILE *circumFile = fopen("circumcenters.pos", "w");
    // fprintf(circumFile, "View \"Circumcenters\" {\n");

    // std::cout << "sourceIndices.size()=" << sourceIndices.size() <<
    // std::endl;

    std::vector<SurfacePoint> sourcesOnFace;
    if(m_sources_on_face.count(f->id())) {
      for(auto i : m_sources_on_face[f->id()])
        sourcesOnFace.push_back(m_sources[i]);
    }

    // std::cout << "Ref (" << pxs[0] << "," << pys[0] << ") (" << pxs[1] <<
    // ","
    //           << pys[1] << ") (" << pxs[2] << "," << pys[2] << std::endl;

    bool print = false;
    // if(m_sources[0].base_element()->id() == 7 &&
    //    m_sources[1].base_element()->id() == 30 &&
    //    m_sources[2].base_element()->id() == 8)
    //   print = true;
    std::vector<double> xVector, yVector, dVector, sourceXVector, sourceYVector;
    std::vector<Interval *> intervalVector;
    std::vector<int> indexVector;
    // for(unsigned ii = 0; ii < sourceindices.size(); ++ii) {
    //   unsigned jj = ii + 1;
    for(unsigned iii = 0; iii < indicesToCheck.size(); ++iii) {
      unsigned ii = indicesToCheck[iii];
      unsigned jj = 0;
      for(; jj < sourceIndices.size(); ++jj) {
        if(sourceIndices[ii] == sourceIndices[jj]) continue;

        // if(m_sources.size() == 2) {
        //   //   if(m_current_intervals.find(sourceIntervals[ii]) ==
        //   //        m_current_intervals.end() &&
        //   //      m_current_intervals.find(sourceIntervals[jj]) ==
        //   //        m_current_intervals.end())
        //   //   // if(std::find(m_current_intervals.begin(),
        //   //   // m_current_intervals.end(),
        //   //   //              sourceIntervals[ii]) ==
        //   m_current_intervals.end()
        //   //   &&
        //   //   //    std::find(m_current_intervals.begin(),
        //   //   //    m_current_intervals.end(),
        //   //   //              sourceIntervals[jj]) ==
        //   //   m_current_intervals.end())
        //   //   {
        //   //     std::cout << "QUIT" << std::endl;
        //   //     continue;
        //   //   }
        //
        //   double ux = sourceXs[jj] - sourceXs[ii];
        //   double uy = sourceYs[jj] - sourceYs[ii];
        //   for(int k = 0; k < 3; ++k) {
        //     double vx = pxs[(k + 1) % 3] - pxs[k];
        //     double vy = pys[(k + 1) % 3] - pys[k];
        //     double den = ux * vy - uy * vx;
        //     if(abs(den) < 1e-10) continue;
        //     double t =
        //       ((pxs[k] - sourceXs[ii]) * vy - (pys[k] - sourceYs[ii]) * vx) /
        //       den;
        //     double s =
        //       ((pxs[k] - sourceXs[ii]) * uy - (pys[k] - sourceYs[ii]) * ux) /
        //       den;
        //     if(t < -1e-10 || 1 + 1e-10 < t) continue;
        //     if(s < -1e-10 || 1 + 1e-10 < s) continue;
        //
        //     double distance =
        //       sourceDs[ii] + sourceDs[jj] + sqrt(ux * ux + uy * uy);
        //
        //     xVector.push_back(sourceXs[ii] + t * ux);
        //     yVector.push_back(sourceYs[ii] + t * uy);
        //     dVector.push_back(distance);
        //     intervalVector.push_back(sourceIntervals[ii]);
        //     intervalVector.push_back(sourceIntervals[jj]);
        //     intervalVector.push_back(nullptr);
        //     indexVector.push_back(sourceIndices[ii]);
        //     indexVector.push_back(sourceIndices[jj]);
        //     indexVector.push_back(-1);
        //
        //     sourceXVector.push_back(sourceXs[ii]);
        //     sourceXVector.push_back(sourceXs[jj]);
        //     sourceXVector.push_back(0.);
        //     sourceYVector.push_back(sourceYs[ii]);
        //     sourceYVector.push_back(sourceYs[jj]);
        //     sourceYVector.push_back(0.);
        //   }
        //
        //   // double x = sourceXs[jj] - sourceXs[ii];
        //   // double y = sourceYs[jj] - sourceYs[ii];
        //   // double l = sqrt(x * x + y * y);
        //   // double d = sourceDs[ii] + l + sourceDs[jj];
        //   // d = d / 2;
        //   // if(l < 1e-10) continue;
        //   // l = (d - sourceDs[ii]) / l;
        //   // if(l < 1e-10) continue;
        //   // if(1 - 1e-10 < l) continue;
        //   // x = sourceXs[ii] + l * x;
        //   // y = sourceYs[ii] + l * y;
        //   //
        //   // // std::cout << "from " << sourceXs[ii] << " " << sourceYs[ii]
        //   << "
        //   // "
        //   // //           << sourceDs[ii] << std::endl;
        //   // // std::cout << "from " << sourceXs[jj] << " " << sourceYs[jj]
        //   << "
        //   // "
        //   // //           << sourceDs[jj] << std::endl;
        //   // // std::cout << "Found " << x << " " << y << " " << d <<
        //   std::endl;
        //   // xVector.push_back(x);
        //   // yVector.push_back(y);
        //   // dVector.push_back(d);
        //   // intervalVector.push_back(sourceIntervals[ii]);
        //   // intervalVector.push_back(sourceIntervals[jj]);
        //   // intervalVector.push_back(nullptr);
        //   // indexVector.push_back(sourceIndices[ii]);
        //   // indexVector.push_back(sourceIndices[jj]);
        //   // indexVector.push_back(-1);
        //   //
        //   // sourceXVector.push_back(sourceXs[ii]);
        //   // sourceXVector.push_back(sourceXs[jj]);
        //   // sourceXVector.push_back(0.);
        //   // sourceYVector.push_back(sourceYs[ii]);
        //   // sourceYVector.push_back(sourceYs[jj]);
        //   // sourceYVector.push_back(0.);
        //   continue;
        // }

        for(unsigned kk = jj + 1; kk < sourceIndices.size(); ++kk) {
          if(sourceIndices[ii] == sourceIndices[kk] ||
             sourceIndices[jj] == sourceIndices[kk])
            continue;

          // if(m_current_intervals.find(sourceIntervals[ii]) ==
          //      m_current_intervals.end() &&
          //    m_current_intervals.find(sourceIntervals[jj]) ==
          //      m_current_intervals.end() &&
          //    m_current_intervals.find(sourceIntervals[kk]) ==
          //      m_current_intervals.end())
          //   // if(std::find(m_current_intervals.begin(),
          //   // m_current_intervals.end(),
          //   //              sourceIntervals[ii]) == m_current_intervals.end()
          //   &&
          //   //    std::find(m_current_intervals.begin(),
          //   //    m_current_intervals.end(),
          //   //              sourceIntervals[jj]) == m_current_intervals.end()
          //   &&
          //   //    std::find(m_current_intervals.begin(),
          //   //    m_current_intervals.end(),
          //   //              sourceIntervals[kk]) ==
          //   m_current_intervals.end()) continue;

          if(print)
            std::cout << ii << "(" << sourceIndices[ii] << ") " << jj << "("
                      << sourceIndices[jj] << ") " << kk << "("
                      << sourceIndices[kk] << std::endl;

          double xPs[4], yPs[4], dPs[4];
          circumcenter(sourceXs[ii], sourceYs[ii], sourceDs[ii], sourceXs[jj],
                       sourceYs[jj], sourceDs[jj], sourceXs[kk], sourceYs[kk],
                       sourceDs[kk], xPs, yPs, dPs);

          xVector.insert(xVector.end(), std::begin(xPs), std::end(xPs));
          yVector.insert(yVector.end(), std::begin(yPs), std::end(yPs));
          dVector.insert(dVector.end(), std::begin(dPs), std::end(dPs));
          for(int i = 0; i < 4; ++i) {
            intervalVector.push_back(sourceIntervals[ii]);
            intervalVector.push_back(sourceIntervals[jj]);
            intervalVector.push_back(sourceIntervals[kk]);
            indexVector.push_back(sourceIndices[ii]);
            indexVector.push_back(sourceIndices[jj]);
            indexVector.push_back(sourceIndices[kk]);
            sourceXVector.push_back(sourceXs[ii]);
            sourceXVector.push_back(sourceXs[jj]);
            sourceXVector.push_back(sourceXs[kk]);
            sourceYVector.push_back(sourceYs[ii]);
            sourceYVector.push_back(sourceYs[jj]);
            sourceYVector.push_back(sourceYs[kk]);
          }
        }
      }
    }

    for(int pi = 0; pi < xVector.size(); ++pi) {
      double xP = xVector[pi];
      double yP = yVector[pi];
      double dP = dVector[pi];

      // if(m_sources.size() != 2 && dP >= GEODESIC_INF) { continue; }
      if(dP >= GEODESIC_INF) { continue; }
      if(isnan(dP) || isnan(xP) || isnan(yP)) {
        // std::cout << "NaN in findcircumcenter !" << std::endl;
        continue;
      }

      // double GEODESIC_EPS = 1e-8;

      double denominator = ((pxs[1] - pxs[0]) * (pys[2] - pys[0]) -
                            (pxs[2] - pxs[0]) * (pys[1] - pys[0]));
      if(std::abs(denominator) < 1e-12) {
        // throw std::runtime_error("The triangle is degenerate!");
        std::cout << "Warning: the circumcenter is in a degenerate triangle"
                  << std::endl;
        continue;
      }
      double v = ((xP - pxs[0]) * (pys[2] - pys[0]) -
                  (pxs[2] - pxs[0]) * (yP - pys[0])) /
                 denominator;
      double w = ((pxs[1] - pxs[0]) * (yP - pys[0]) -
                  (xP - pxs[0]) * (pys[1] - pys[0])) /
                 denominator;

      // std::cout << v << " " << w << std::endl;
      // throw std::runtime_error("stop");
      if(print) std::cout << v << " " << w << std::endl;

      if(v < -GEODESIC_EPS_SNAP || w < -GEODESIC_EPS_SNAP ||
         1. - v - w < -GEODESIC_EPS_SNAP) {
        continue;
      }
      // if(v < 0.) v = 0.;
      // if(w < 0.) w = 0.;
      // if(1. - v - w < 0.) w = 1. - v;

      if(print) std::cout << v << " " << w << std::endl;

      SurfacePoint spC(f, v, w);

      static int count = 0;
      if(count == 30) throw std::runtime_error("Error: stop");
      if(print) {
        std::cout << "count=" << count << std::endl;
        std::ofstream posFile("test" + std::to_string(count++) + ".pos");
        posFile << "View \"Intervals\" {\n";
        for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
          list_pointer list = &m_edge_interval_lists[i];
          interval_pointer p = list->first();
          while(p) {
            edge_pointer edge = p->edge();
            vertex_pointer v0 = edge->v0();
            vertex_pointer v1 = edge->v1();
            double start = p->start();
            double stop = p->stop();
            double length = edge->length();
            double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
            double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
            double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
            double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
            double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
            double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
            // posFile << "SL(" << x0 << "," << y0 << "," << z0 << ","
            // << x1
            // <<
            // "," << y1 << "," << z1 << "){" << p->min() << "," <<
            // p->min()
            // <<
            // "};\n";
            posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 << ","
                    << y1 << "," << z1 << "){" << p->source_index() << ","
                    << p->source_index() << "};\n";
            p = p->next();
          }
        }
        for(size_t i = 0; i < m_sources.size(); ++i) {
          posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() << ","
                  << m_sources[i].z() << "){" << i << "};\n";
        }
        posFile << "SP(" << spC.x() << "," << spC.y() << "," << spC.z() << "){"
                << -1 << "};\n";
        // for (size_t i = 0; i < m_stop_vertices.size(); ++i) {
        // 	posFile << "SP(" << m_stop_vertices[i]->x() << "," <<
        // m_stop_vertices[i]->y() << "," << m_stop_vertices[i]->z() <<
        // "){1};\n";
        // }
        posFile << "};\n";
        posFile.close();
      }

      // double GEODESIC_EPS = 1e-12;
      if(v < GEODESIC_EPS_SNAP && w < GEODESIC_EPS_SNAP) {
        spC = SurfacePoint(vs[0]);
      }
      else if(w < GEODESIC_EPS_SNAP && 1. - v - w < GEODESIC_EPS_SNAP) {
        spC = SurfacePoint(vs[1]);
      }
      else if(1. - v - w < GEODESIC_EPS_SNAP && v < GEODESIC_EPS_SNAP) {
        spC = SurfacePoint(vs[2]);
      }
      else if(v < GEODESIC_EPS_SNAP) {
        for(auto ee : f->adjacent_edges()) {
          if(ee->adjacent_vertices()[0] == vs[2] &&
             ee->adjacent_vertices()[1] == vs[0]) {
            spC = SurfacePoint(ee, 1. - w);
            break;
          }
          if(ee->adjacent_vertices()[0] == vs[0] &&
             ee->adjacent_vertices()[1] == vs[2]) {
            spC = SurfacePoint(ee, w);
            break;
          }
        }
      }
      else if(w < GEODESIC_EPS_SNAP) {
        for(auto ee : f->adjacent_edges()) {
          if(ee->adjacent_vertices()[0] == vs[0] &&
             ee->adjacent_vertices()[1] == vs[1]) {
            spC = SurfacePoint(ee, v);
            break;
          }
          if(ee->adjacent_vertices()[0] == vs[1] &&
             ee->adjacent_vertices()[1] == vs[0]) {
            spC = SurfacePoint(ee, 1. - v);
            break;
          }
        }
      }
      else if(1. - v - w < GEODESIC_EPS_SNAP) {
        for(auto ee : f->adjacent_edges()) {
          if(ee->adjacent_vertices()[0] == vs[1] &&
             ee->adjacent_vertices()[1] == vs[2]) {
            spC = SurfacePoint(ee, 1. - v);
            break;
          }
          if(ee->adjacent_vertices()[0] == vs[2] &&
             ee->adjacent_vertices()[1] == vs[1]) {
            spC = SurfacePoint(ee, v);
            break;
          }
        }
      }

      if(print) std::cout << "ok" << v << " " << w << std::endl;

      // std::vector<edge_pointer> possible_edges;
      // possible_traceback_edges(spC, possible_edges);
      //
      // if(m_sources.size() == 2) {
      //   // double position, d0, d1;
      //   // Interval *interval;
      //   // best_point_on_the_edge_set(spC, possible_edges, interval, d0,
      //   // position,
      //   //                            0);
      //   // if(d0 >= GEODESIC_INF) continue;
      //   // // std::cout << "d0: " << d0 << std::endl;
      //   // // SVector3 p(spC.xyz(), m_sources[1].xyz());
      //   // // d0 += norm(p);
      //   // best_point_on_the_edge_set(spC, possible_edges, interval, d1,
      //   // position,
      //   //                            1);
      //   // if(d1 >= GEODESIC_INF) continue;
      //   // // std::cout << "d1: " << d1 << std::endl;
      //   // // p = SVector3(spC.xyz(), m_sources[0].xyz());
      //   // // d1 += norm(p);
      //   // // dP = (d0 > d1) ? d0 : d1;
      //   if(abs(dP - 52.6077) < 1e-5)
      //     // std::cout << dP << " vs " << d0 + d1 << std::endl;
      //     std::cout << dP << std::endl;
      //   // dP = d0 + d1;
      // }
      // else {
      //   interval_pointer interval = 0ULL;
      //   double total_distance, position;
      //   best_point_on_the_edge_set(spC, possible_edges, interval,
      //                              total_distance, position);
      //   double o, d;
      //
      //   for(auto s : sourcesOnFace) {
      //     if(s.type() != FACE) continue;
      //     SVector3 v(spC.xyz(), s.xyz());
      //     d = norm(v);
      //     if(d < total_distance) {
      //       total_distance = d;
      //       interval = nullptr;
      //     }
      //   }
      //
      //   if(print)
      //     std::cout << " Dist tot: " << total_distance - dP << " " << dP
      //               << std::endl;
      //   if(abs(dP - total_distance) > GEODESIC_EPSDIST) { continue; }
      //
      //   bool right_path = true;
      //   for(size_t i = 0; i < 3; ++i) {
      //     if(i == 2 && m_sources.size() == 2) break;
      //     Interval *interval = intervalVector[3 * pi + i];
      //     double off, dist, x, y;
      //
      //     SurfacePoint s = m_sources[indexVector[3 * pi + i]];
      //
      //     if(s.type() == FACE && s.base_element() == f) {
      //       SVector3 v(spC.xyz(), s.xyz());
      //       dist = norm(v);
      //     }
      //     else {
      //       interval->edge()->local_coordinates(&spC, x, y);
      //       interval->find_closest_point(x, y, off, dist);
      //     }
      //
      //     if(print)
      //       std::cout << "\tDist: " << dist - total_distance << " " << dist
      //                 << " " << indexVector[3 * pi + i] << std::endl;
      //     if(abs(dist - total_distance) > GEODESIC_EPSDIST) // TODO make more
      //     precise
      //     {
      //       right_path = false;
      //     }
      //   }
      //
      //   if(!right_path) { continue; }
      // }

      unsigned minSource = indexVector[3 * pi];
      unsigned midSource = indexVector[3 * pi + 1];
      unsigned maxSource = indexVector[3 * pi + 2];
      SVector3 s0(sourceXVector[3 * pi], sourceYVector[3 * pi], 0);
      SVector3 s1(sourceXVector[3 * pi + 1], sourceYVector[3 * pi + 1], 0);
      SVector3 s2(sourceXVector[3 * pi + 2], sourceYVector[3 * pi + 2], 0);
      SVector3 xy(xP, yP, 0);

      // if(m_sources.size() == 2) {
      //   if(minSource > midSource) {
      //     std::swap(minSource, midSource);
      //     std::swap(s0, s1);
      //   }
      // }
      // else {
      if(minSource > midSource) {
        std::swap(minSource, midSource);
        std::swap(s0, s1);
      }
      if(midSource > maxSource) {
        std::swap(midSource, maxSource);
        std::swap(s1, s2);
      }
      if(minSource > midSource) {
        std::swap(minSource, midSource);
        std::swap(s0, s1);
      }
      double sum = 0;

      SVector3 ps[3] = {s0 - xy, s1 - xy, s2 - xy};
      for(int j = 0; j < 3; ++j) {
        double cosTheta = dot(ps[j], ps[(j + 1) % 3]);
        SVector3 cp = crossprod(ps[j], ps[(j + 1) % 3]);
        double sinTheta = norm(cp);
        double angle = atan2(sinTheta, cosTheta);
        if(dot(cp, SVector3(0., 0., 1.)) < 0) angle = 2 * M_PI - angle;
        sum += angle;
      }
      // std::cout << sum << std::endl;
      if(sum > 2 * M_PI + 1e-3) { std::swap(midSource, maxSource); }
      // }

      // unsigned index = circumCenters.size();
      // for(size_t i = 0; i < circumCenters.size(); ++i) {
      //   if(circumSources[3 * i] == minSource &&
      //      circumSources[3 * i + 1] == midSource &&
      //      circumSources[3 * i + 2] == maxSource) {
      //     index = i;
      //     break;
      //   }
      // }
      // if(index == circumCenters.size()) {
      //   if(print) std::cout << "added" << std::endl;
      circumCenters.push_back(spC);
      circumRadii.push_back(dP * local_scale);
      // std::cout << dP << std::endl;
      circumSources.push_back(minSource);
      circumSources.push_back(midSource);
      circumSources.push_back(maxSource);
      // std::cout << minSource << " " << midSource << " " <<
      // maxSource
      //           << std::endl;
      // }
      // else if(dP < circumRadii[index]) {
      //   if(print) std::cout << "replaced" << std::endl;
      //   circumCenters[index] = spC;
      //   circumRadii[index] = dP;
      //   // std::cout << dP << std::endl;
      //   // std::cout << index << std::endl;
      // }
    }
  }

  inline bool
  GeodesicAlgorithmExact::checkCircumcenter(SurfacePoint &circumCenter,
                                            double &circumRadius)
  {
    bool print = false;
    // if(m_sources[0].base_element()->id() == 7 &&
    //    m_sources[1].base_element()->id() == 30 &&
    //    m_sources[2].base_element()->id() == 8)
    //   print = true;
    double d, p;
    unsigned source_index = std::numeric_limits<unsigned>::max();
    best_first_interval(circumCenter, d, p, source_index);
    if(d >= GEODESIC_INF) return false;

    std::vector<edge_pointer> possible_edges;
    std::vector<face_pointer> incident_faces;
    possible_traceback_edges(circumCenter, possible_edges, incident_faces);

    // if(m_sources.size() == 2) {
    //   double position, d0, d1;
    //   Interval *interval;
    //   best_point_on_the_edge_set(circumCenter, possible_edges, interval, d0,
    //                              position, 0);
    //   if(d0 >= GEODESIC_INF) return false;
    //   // std::cout << "d0: " << d0 << std::endl;
    //   // SVector3 p(spC.xyz(), m_sources[1].xyz());
    //   // d0 += norm(p);
    //   best_point_on_the_edge_set(circumCenter, possible_edges, interval, d1,
    //                              position, 1);
    //   if(d1 >= GEODESIC_INF) return false;
    //   // std::cout << "d1: " << d1 << std::endl;
    //   // p = SVector3(spC.xyz(), m_sources[0].xyz());
    //   // d1 += norm(p);
    //   // dP = (d0 > d1) ? d0 : d1;
    //   circumRadius = d0 + d1;
    //   return true;
    // }

    // interval_pointer interval = 0ULL;
    // double total_distance, position;
    // best_point_on_the_edge_set(circumCenter, possible_edges, interval,
    //                            total_distance, position);
    // double o, d;
    //
    // if(circumCenter.type() == FACE) {
    //   for(auto id : m_sources_on_face[circumCenter.base_element()->id()]) {
    //     SurfacePoint s = m_sources[id];
    //     if(s.type() != FACE) continue;
    //     SVector3 v(circumCenter.xyz(), s.xyz());
    //     d = norm(v);
    //     if(d < total_distance) {
    //       total_distance = d;
    //       interval = nullptr;
    //     }
    //   }
    // }
    //
    // // if(print)
    // //   std::cout << " Dist tot: " << total_distance - circumRadius << " "
    // //             << circumRadius << std::endl;
    // if(abs(circumRadius - total_distance) > GEODESIC_EPSDIST) { return false;
    // }
    //
    // bool right_path = true;
    // for(size_t i = 0; i < 3; ++i) {
    //   // if(i == 2 && m_sources.size() == 2) break;
    //   Interval *interval = intervalVector[3 * pi + i];
    //   double off, dist, x, y;
    //
    //   SurfacePoint s = m_sources[indexVector[3 * pi + i]];
    //
    //   if(s.type() == FACE && s.base_element() == f) {
    //     SVector3 v(circumCenter.xyz(), s.xyz());
    //     dist = norm(v);
    //   }
    //   else {
    //     interval->edge()->local_coordinates(&circumCenter, x, y);
    //     interval->find_closest_point(x, y, off, dist);
    //   }
    //
    //   // if(print)
    //   //   std::cout << "\tDist: " << dist - total_distance << " " << dist <<
    //   "
    //   //   "
    //   //             << indexVector[3 * pi + i] << std::endl;
    //   if(abs(dist - total_distance) > GEODESIC_EPSDIST) // TODO make more
    //   precise
    //   {
    //     right_path = false;
    //   }
    // }
    // if(!right_path) { return false; }
    //
    if(print) std::cout << "type " << circumCenter.type() << std::endl;

    double best_total_distances[3] = {GEODESIC_INF, GEODESIC_INF, GEODESIC_INF};
    for(unsigned i = 0; i < possible_edges.size(); ++i) {
      edge_pointer e = possible_edges[i];
      list_pointer list = interval_list(e);
      interval_pointer p = list->first();

      double x, y;
      e->local_coordinates(&circumCenter, x, y);

      while(p) {
        if(p->min() >= GEODESIC_INF) {
          p = p->next();
          continue;
        }

        double o, d;
        p->find_closest_point(x, y, o, d);
        unsigned idx = p->source_index();
        if(print) std::cout << idx << ": " << d << std::endl;
        if(d < best_total_distances[idx]) { best_total_distances[idx] = d; }
        p = p->next();
      }
    }

    std::vector<unsigned> facesId;
    if(circumCenter.type() == FACE)
      facesId.push_back(circumCenter.base_element()->id());
    else {
      for(auto f : circumCenter.base_element()->adjacent_faces())
        facesId.push_back(f->id());
    }
    for(auto id : facesId) {
      for(auto idx : m_sources_on_face[id]) {
        SurfacePoint s = m_sources[idx];
        // if(s.type() != FACE) continue;
        SVector3 v(circumCenter.xyz(), s.xyz());
        double d = norm(v);
        if(d < best_total_distances[idx]) { best_total_distances[idx] = d; }
      }
    }

    for(int i = 0; i < 3; ++i) {
      if(print) {
        std::cout << best_total_distances[i] << " vs " << circumRadius
                  << std::endl;
      }
      if(abs((best_total_distances[i] - circumRadius) / circumRadius) >
         GEODESIC_EPSDIST) {
        // static int count = 0;
        // std::ofstream posFile("intervals" + std::to_string(count++) +
        // ".pos"); posFile << "View \"Intervals\" {\n"; for(unsigned i = 0; i <
        // m_edge_interval_lists.size(); ++i) {
        //   list_pointer list = &m_edge_interval_lists[i];
        //   interval_pointer p = list->first();
        //   while(p) {
        //     edge_pointer edge = p->edge();
        //     vertex_pointer v0 = edge->v0();
        //     vertex_pointer v1 = edge->v1();
        //     double start = p->start();
        //     double stop = p->stop();
        //     double length = edge->length();
        //     double x0 = v0->x() + (v1->x() - v0->x()) * (start / length);
        //     double y0 = v0->y() + (v1->y() - v0->y()) * (start / length);
        //     double z0 = v0->z() + (v1->z() - v0->z()) * (start / length);
        //     double x1 = v0->x() + (v1->x() - v0->x()) * (stop / length);
        //     double y1 = v0->y() + (v1->y() - v0->y()) * (stop / length);
        //     double z1 = v0->z() + (v1->z() - v0->z()) * (stop / length);
        //     posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1 <<
        //     ","
        //             << y1 << "," << z1 << "){" << p->signal(start) << ","
        //             << p->signal(stop) << "};\n";
        //     // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
        //     <<
        //     // ","
        //     //         << y1 << "," << z1 << "){" << p->d() << "," << p->d()
        //     //         << "};\n";
        //     // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
        //     <<
        //     // ","
        //     //         << y1 << "," << z1 << "){" << p->min() << "," <<
        //     p->min()
        //     //         << "};\n";
        //     // posFile << "SL(" << x0 << "," << y0 << "," << z0 << "," << x1
        //     <<
        //     // ","
        //     //         << y1 << "," << z1 << "){" << p->source_index() << ","
        //     //         << p->source_index() << "};\n";
        //     p = p->next();
        //   }
        // }
        // for(size_t i = 0; i < m_sources.size(); ++i) {
        //   posFile << "SP(" << m_sources[i].x() << "," << m_sources[i].y() <<
        //   ","
        //           << m_sources[i].z() << "){" << i << "};\n";
        // }
        // posFile << "SP(" << circumCenter.x() << "," << circumCenter.y() <<
        // ","
        //         << circumCenter.z() << "){" << -1 << "};\n";
        // posFile << "};\n";
        // posFile.close();
        // throw std::runtime_error("stop");
        return false;
      }
    }

    return true;
  }

  inline void GeodesicAlgorithmExact::print_statistics()
  {
    GeodesicAlgorithmBase::print_statistics();

    unsigned interval_counter = 0;
    for(unsigned i = 0; i < m_edge_interval_lists.size(); ++i) {
      interval_counter += m_edge_interval_lists[i].number_of_intervals();
    }
    double intervals_per_edge =
      (double)interval_counter / (double)m_edge_interval_lists.size();

    double memory = m_edge_interval_lists.size() * sizeof(IntervalList) +
                    interval_counter * sizeof(Interval);

    std::cout << "uses about " << memory / 1e6 << "Mb of memory" << std::endl;
    std::cout << interval_counter << " total intervals, or "
              << intervals_per_edge << " intervals per edge" << std::endl;
    std::cout << "maximum interval queue size is " << m_queue_max_size
              << std::endl;
    std::cout << "number of interval propagations is " << m_iterations
              << std::endl;
  }

} // namespace geodesic

#endif // GEODESIC_ALGORITHM_EXACT_20071231

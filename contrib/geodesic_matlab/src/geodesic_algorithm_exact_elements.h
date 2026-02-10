// Copyright (C) 2008 Danil Kirsanov, MIT License
#ifndef GEODESIC_ALGORITHM_EXACT_ELEMENTS_20071231
#define GEODESIC_ALGORITHM_EXACT_ELEMENTS_20071231

#include "geodesic_constants_and_simple_functions.h"
#include "geodesic_memory.h"
#include "geodesic_mesh_elements.h"
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>

// #include <iostream>
// #include <fstream>
#include "SVector3.h"
// #define METRIC true

namespace geodesic {

  class Interval;
  class IntervalList;
  typedef Interval *interval_pointer;
  typedef IntervalList *list_pointer;

  class SurfacePointWithIndex : public SurfacePoint {
  public:
    unsigned index() { return m_index; };

    void initialize(SurfacePoint &p, unsigned index)
    {
      SurfacePoint::initialize(p);
      m_index = index;
    }

    bool operator()(SurfacePointWithIndex *x,
                    SurfacePointWithIndex *y) const // used for sorting
    {
      assert(x->type() != UNDEFINED_POINT && y->type() != UNDEFINED_POINT);

      if(x->type() != y->type()) { return x->type() < y->type(); }
      else {
        return x->base_element()->id() < y->base_element()->id();
      }
    }

  private:
    unsigned m_index;
  };

  class SortedSources : public std::vector<SurfacePointWithIndex> {
  private:
    typedef std::vector<SurfacePointWithIndex *> sorted_vector_type;

  public:
    typedef sorted_vector_type::iterator sorted_iterator;
    typedef std::pair<sorted_iterator, sorted_iterator> sorted_iterator_pair;

    sorted_iterator_pair sources(base_pointer mesh_element)
    {
      m_search_dummy.base_element() = mesh_element;

      return equal_range(m_sorted.begin(), m_sorted.end(), &m_search_dummy,
                         m_compare_less);
    }

    void initialize(
      std::vector<SurfacePoint> &sources) // we initialize the sources by copie
    {
      resize(sources.size());
      m_sorted.resize(sources.size());
      for(unsigned i = 0; i < sources.size(); ++i) {
        SurfacePointWithIndex &p = *(begin() + i);

        p.initialize(sources[i], i);
        m_sorted[i] = &p;
      }

      std::sort(m_sorted.begin(), m_sorted.end(), m_compare_less);
    };

    SurfacePointWithIndex &operator[](unsigned i)
    {
      assert(i < size());
      return *(begin() + i);
    }

  private:
    sorted_vector_type m_sorted;
    SurfacePointWithIndex m_search_dummy; // used as a search template
    SurfacePointWithIndex m_compare_less; // used as a compare functor
  };

  class Interval // interval of the edge
  {
  public:
    Interval()
      : m_start(0.), m_d(geodesic::GEODESIC_INF), m_pseudo_x(0.),
        m_pseudo_y(0.), m_min(geodesic::GEODESIC_INF), m_next(nullptr),
        m_edge(nullptr), m_source_index(0),
        m_direction(DirectionType::UNDEFINED_DIRECTION), m_depth(0) {};
    ~Interval() {};

    Interval(const Interval &other)
      : m_start(other.m_start), m_d(other.m_d), m_pseudo_x(other.m_pseudo_x),
        m_pseudo_y(other.m_pseudo_y), m_min(other.m_min), m_next(other.m_next),
        m_edge(other.m_edge), m_source_index(other.m_source_index),
        m_direction(other.m_direction), m_depth(other.m_depth) {};

    enum DirectionType {
      FROM_FACE_0,
      FROM_FACE_1,
      FROM_SOURCE,
      UNDEFINED_DIRECTION
    };

    double signal(double x) // geodesic distance function at point x
    {
      assert(x >= 0.0 && x <= m_edge->length());

      if(m_d == GEODESIC_INF) { return GEODESIC_INF; }
      else {
#if METRIC
        double dx = (x - m_pseudo_x) * edge()->stretch();
#else
        double dx = x - m_pseudo_x;
#endif
        if(m_pseudo_y == 0.0) { return m_d + std::abs(dx); }
        else {
          return m_d + sqrt(dx * dx + m_pseudo_y * m_pseudo_y);
        }
      }
    }

    double max_distance(double end)
    {
      if(m_d == GEODESIC_INF) { return GEODESIC_INF; }
      else {
        double a = std::abs(m_start - m_pseudo_x);
        double b = std::abs(end - m_pseudo_x);

        return a > b ? m_d + sqrt(a * a + m_pseudo_y * m_pseudo_y) :
                       m_d + sqrt(b * b + m_pseudo_y * m_pseudo_y);
      }
    }

    void compute_min_distance() // compute min, given c,d theta, start, end.
    {
      double m_stop = stop();
      assert(m_stop > m_start);

      if(m_d == GEODESIC_INF) {
        m_min = GEODESIC_INF;
        return;
      }

      if(m_start > m_pseudo_x) { m_min = signal(m_start); }
      else if(m_stop < m_pseudo_x) {
        m_min = signal(m_stop);
      }
      else {
        assert(m_pseudo_y <= 0);
        m_min = m_d - m_pseudo_y;
      }
    }

    void compute_min_distance_to(SurfacePoint *destination
#if METRIC
                                 ,
                                 double minStretch
#endif
    )
    {
      double x, y, offset, distance;
      edge()->local_coordinates(destination, x, y);

#if METRIC
      find_closest_point(x / edge()->stretch(), y, offset, distance);
      double d = x - offset;
      d = sqrt(d * d + y * y);
      distance += (minStretch - 1) * d;
#else
      find_closest_point(x, y, offset, distance);
#endif
      m_min = distance;
    }

    void compute_min_distance_to_circumcenter(SortedSources &sources)
    {
      double m_stop = stop();
      assert(m_stop > m_start);

      if(m_d == GEODESIC_INF) {
        m_min = GEODESIC_INF;
        return;
      }

      double position;
      if(m_start > m_pseudo_x) {
        position = m_start;
        m_min = signal(m_start);
      }
      else if(m_stop < m_pseudo_x) {
        position = m_stop;
        m_min = signal(m_stop);
      }
      else {
        position = m_pseudo_x;
        assert(m_pseudo_y <= 0);
        m_min = m_d - m_pseudo_y;
      }

      SurfacePoint point(edge(), position / edge()->length());
      double distance = m_min;
      for(int i = 0; i < 3; ++i) {
        if(i == source_index()) continue;
        double d = point.distance(sources[i].xyz());
        if(d > m_min)
          distance += d;
        else
          distance += m_min;
      }
      m_min = distance / 3.;
    }

    // compare two intervals in the queue
    bool operator()(interval_pointer const x, interval_pointer const y) const
    {
      if(x->min() != y->min()) { return x->min() < y->min(); }
      else if(x->start() != y->start()) {
        return x->start() < y->start();
      }
      else {
        return x->edge()->id() < y->edge()->id();
      }
    }

    double stop() // return the endpoint of the interval
    {
      return m_next ? m_next->start() : m_edge->length();
    }

    double hypotenuse(double a, double b) { return sqrt(a * a + b * b); }

    void
    find_closest_point(double const x, double const y, double &offset,
                       double &distance); // find the point on the interval that
                                          // is closest to the point (alpha, s)

    double &start() { return m_start; };
    double &d() { return m_d; };
    double &pseudo_x() { return m_pseudo_x; };
    double &pseudo_y() { return m_pseudo_y; };
    double &min() { return m_min; };
    interval_pointer &next() { return m_next; };
    edge_pointer &edge() { return m_edge; };
    DirectionType &direction() { return m_direction; };
    unsigned &depth() { return m_depth; };
    bool visible_from_source() { return m_direction == FROM_SOURCE; };
    unsigned &source_index() { return m_source_index; };

    void
    initialize(edge_pointer edge, SurfacePoint *point = NULL,
               unsigned source_index = std::numeric_limits<unsigned>::max());
    // unsigned source_index = 0,
    // const std::function<double(Interval*)> &modifiedMinDistance =
    // std::function<double(Interval*)>());

  protected:
    double m_start; // initial point of the interval on the edge
    double m_d; // distance from the source to the pseudo-source
    double m_pseudo_x; // coordinates of the pseudo-source in the local
                       // coordinate system
    double m_pseudo_y; // y-coordinate should be always negative
    double m_min; // minimum distance on the interval

    interval_pointer m_next; // pointer to the next interval in the list
    edge_pointer m_edge; // edge that the interval belongs to
    unsigned m_source_index; // the source it belongs to
    DirectionType m_direction; // where the interval is coming from
    unsigned m_depth;
  };

  struct IntervalWithStop : public Interval {
  public:
    double &stop() { return m_stop; };

  protected:
    double m_stop;
  };

  class IntervalList // list of the of intervals of the given edge
  {
  public:
    IntervalList() { m_first = NULL; };
    ~IntervalList() {};

    inline void clear() { m_first = NULL; };

    void initialize(edge_pointer e)
    {
      m_edge = e;
      m_first = NULL;
    };

    interval_pointer covering_interval(
      double offset) // returns the interval that covers the offset
    {
      assert(offset >= 0.0 && offset <= m_edge->length());

      interval_pointer p = m_first;
      while(p && p->stop() < offset) { p = p->next(); }

      return p; // && p->start() <= offset ? p : NULL;
    };

    void find_closest_point(
      SurfacePoint *point, double &offset, double &distance,
      // interval_pointer& interval)
      interval_pointer &interval,
      unsigned forSourceIndex = std::numeric_limits<unsigned>::max(),
      unsigned depth = 0)
    {
      interval_pointer p = m_first;
      offset = GEODESIC_INF;
      distance = GEODESIC_INF;
      interval = NULL;

      double x, y;
      m_edge->local_coordinates(point, x, y);

#if METRIC
      face_pointer f = nullptr;
      if(point->type() == FACE) {
        f = static_cast<face_pointer>(point->base_element());
      }
      else {
        f = edge()->adjacent_faces()[0];
        face_pointer ff = edge()->adjacent_faces()[1];
        auto faces = point->base_element()->adjacent_faces();
        for(int i = 0; i < faces.size(); i++) {
          if(f == faces[i]) break;
          if(ff == faces[i]) {
            f = ff;
            break;
          }
        }
      }

      Vertex *v0 = edge()->v0(), *v1 = edge()->v1(),
             *v2 = f->opposite_vertex(edge());
      // double x0 = 0, y0 = 0, x1 = v0->distance(v1), y1 = 0, x2, y2;
      double x1 = v0->distance(v1), x2, y2;
      m_edge->local_coordinates(v2, x2, y2);

      // double denominator = ((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
      double denominator = x1 * y2;
      if(std::abs(denominator) < 1e-10) {
        throw std::runtime_error("The triangle is degenerate!");
      }
      // double v = ((x - x0) * (y2 - y0) - (x2 - x0) * (y - y0)) / denominator;
      // double w = ((x1 - x0) * (y - y0) - (x - x0) * (y1 - y0)) / denominator;
      double v = (x * y2 - x2 * y) / denominator;
      double w = (x1 * y) / denominator;
      double u = 1.0 - v - w;

      // double lengthCurrent = x1;
      // double lengthL = sqrt((x2 - x0)*(x2 - x0) + (y2 - y0)*(y2 - y0));
      // double lengthR = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
      // double lengthL = sqrt(x2*x2 + y2*y2);
      // double lengthR = sqrt((x1 - x2)*(x1 - x2) + y2*y2);
      double scaleCurrent = edge()->stretch();
      double scaleL = f->opposite_edge(edge()->v1())->stretch();
      double scaleR = f->next_edge(edge(), edge()->v1())->stretch();

      double mLengthCurrent = scaleCurrent * x1;
      double mLengthL = scaleL * sqrt(x2 * x2 + y2 * y2);
      double mLengthR = scaleR * sqrt((x1 - x2) * (x1 - x2) + y2 * y2);
      // double mAngle = acos((mLengthCurrent*mLengthCurrent + mLengthL*mLengthL
      // - mLengthR*mLengthR)/(2*mLengthCurrent*mLengthL)); double mX =
      // cos(mAngle)*mLengthL; double mY = sin(mAngle)*mLengthL;
      double mX = (mLengthCurrent * mLengthCurrent + mLengthL * mLengthL -
                   mLengthR * mLengthR) /
                  (2 * mLengthCurrent);
      double mY = sqrt(mLengthL * mLengthL - mX * mX);

      // double mpX = u * x0 + v * mLengthCurrent + w * mX;
      // double mpY = u * y0 + v * y1 + w * mY;
      double mpX = v * mLengthCurrent + w * mX;
      double mpY = w * mY;
      mpX /= scaleCurrent;
#endif

      for(; p; p = p->next()) {
        if(p->min() >= GEODESIC_INF) continue;
        // std::cout << "\t\t" << p->depth() << std::endl;

        if(forSourceIndex != std::numeric_limits<unsigned>::max() &&
           forSourceIndex != p->source_index())
          continue;

        double o, d;
#if METRIC
        p->find_closest_point(mpX, mpY, o, d);
#else
        p->find_closest_point(x, y, o, d);
#endif
        if(d > distance) continue;

        distance = d;
        offset = o;
        interval = p;
      }
    };

    unsigned number_of_intervals()
    {
      interval_pointer p = m_first;
      unsigned count = 0;
      while(p) {
        ++count;
        p = p->next();
      }
      return count;
    }

    interval_pointer last()
    {
      interval_pointer p = m_first;
      if(p) {
        while(p->next()) { p = p->next(); }
      }
      return p;
    }

    double signal(double x)
    {
      interval_pointer interval = covering_interval(x);

      return interval ? interval->signal(x) : GEODESIC_INF;
    }

    interval_pointer &first() { return m_first; };
    edge_pointer &edge() { return m_edge; };

  private:
    interval_pointer m_first; // pointer to the first member of the list
    edge_pointer m_edge; // edge that owns this list
  };

  inline void Interval::find_closest_point(
    double const rs, double const hs, double &r,
    double &d_out) // find the point on the interval that is closest to the
                   // point (alpha, s)
  {
    if(m_d == GEODESIC_INF) {
      r = GEODESIC_INF;
      d_out = GEODESIC_INF;
      return;
    }

    double hc = -m_pseudo_y;
    double rc = m_pseudo_x;
    double end = stop();
    // std::cout << "x = " << rc << " y = " << hc << std::endl;

    double local_epsilon = SMALLEST_INTERVAL_RATIO * m_edge->length();
#if METRIC
    if(std::abs(hs + hc) < local_epsilon) {
      if(rs <= m_start) {
        r = m_start;
        d_out = signal(m_start) + std::abs(rs - m_start) * edge()->stretch();
      }
      else if(rs >= end) {
        r = end;
        d_out = signal(end) + fabs(end - rs) * edge()->stretch();
      }
      else {
        r = rs;
        d_out = signal(rs);
      }
    }
    else {
      double ri = (rs * hc + hs * rc) / (hs + hc);

      if(ri < m_start) {
        r = m_start;
        d_out =
          signal(m_start) + hypotenuse((m_start - rs) * edge()->stretch(), hs);
      }
      else if(ri > end) {
        r = end;
        d_out = signal(end) + hypotenuse((end - rs) * edge()->stretch(), hs);
      }
      else {
        r = ri;
        d_out = m_d + hypotenuse((rc - rs) * edge()->stretch(), hc + hs);
      }
    }

#else
    if(std::abs(hs + hc) < local_epsilon) {
      if(rs <= m_start) {
        r = m_start;
        d_out = signal(m_start) + std::abs(rs - m_start);
      }
      else if(rs >= end) {
        r = end;
        d_out = signal(end) + fabs(end - rs);
      }
      else {
        r = rs;
        d_out = signal(rs);
      }
    }
    else {
      double ri = (rs * hc + hs * rc) / (hs + hc);

      if(ri < m_start) {
        r = m_start;
        d_out = signal(m_start) + hypotenuse(m_start - rs, hs);
      }
      else if(ri > end) {
        r = end;
        d_out = signal(end) + hypotenuse(end - rs, hs);
      }
      else {
        r = ri;
        d_out = m_d + hypotenuse(rc - rs, hc + hs);
      }
    }
#endif
  }

  inline void Interval::initialize(edge_pointer edge, SurfacePoint *source,
                                   unsigned source_index)
  //  unsigned source_index,
  //  const std::function<double(Interval*)> &modifiedMinDistance)
  {
    m_next = NULL;
    // m_geodesic_previous = NULL;
    m_direction = UNDEFINED_DIRECTION;
    m_edge = edge;
    m_source_index = source_index;
    m_depth = 0;

    m_start = 0.0;
    // m_stop = edge->length();
    if(!source) {
      m_d = GEODESIC_INF;
      m_min = GEODESIC_INF;
      return;
    }
    m_d = 0;

    if(source->base_element()->type() == VERTEX) {
      if(source->base_element()->id() == edge->v0()->id()) {
        m_pseudo_x = 0.0;
        m_pseudo_y = 0.0;
        m_min = 0.0;
        return;
      }
      else if(source->base_element()->id() == edge->v1()->id()) {
        m_pseudo_x = stop();
        m_pseudo_y = 0.0;
        m_min = 0.0;
        return;
      }
    }

    edge->local_coordinates(source, m_pseudo_x, m_pseudo_y);

#if METRIC
    if(source->base_element()->type() == geodesic::FACE) {
      geodesic::Face *f = static_cast<geodesic::Face *>(source->base_element());
      geodesic::Vertex *v0 = edge->v0(), *v1 = edge->v1(),
                       *v2 = f->opposite_vertex(edge);
      // double x0 = 0, y0 = 0, x1 = v0->distance(v1), y1 = 0, x2, y2;
      double x1 = v0->distance(v1), x2, y2;
      edge->local_coordinates(v2, x2, y2);

      // double denominator = ((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
      double denominator = x1 * y2;
      if(std::abs(denominator) < 1e-10) {
        throw std::runtime_error("The triangle is degenerate!");
      }
      // double v = ((m_pseudo_x - x0) * (y2 - y0) - (x2 - x0) * (m_pseudo_y -
      // y0)) / denominator; double w = ((x1 - x0) * (m_pseudo_y - y0) -
      // (m_pseudo_x - x0) * (y1 - y0)) / denominator;
      double v = (m_pseudo_x * y2 - x2 * m_pseudo_y) / denominator;
      double w = x1 * m_pseudo_y / denominator;
      // double u = 1.0 - v - w;

      // double lengthCurrent = x1;
      // double lengthL = sqrt((x2 - x0)*(x2 - x0) + (y2 - y0)*(y2 - y0));
      // double lengthR = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
      // double lengthL = sqrt(x2*x2 + y2*y2);
      // double lengthR = sqrt((x1 - x2)*(x1 - x2) + y2*y2);
      double scaleCurrent = edge->stretch();
      double scaleL = f->opposite_edge(edge->v1())->stretch();
      double scaleR = f->opposite_edge(edge->v0())->stretch();

      double mLengthCurrent = scaleCurrent * x1;
      double mLengthL = scaleL * sqrt(x2 * x2 + y2 * y2);
      double mLengthR = scaleR * sqrt((x1 - x2) * (x1 - x2) + y2 * y2);
      // double angle = acos((lengthCurrent*lengthCurrent + lengthL*lengthL -
      // lengthR*lengthR)/(2*lengthCurrent*lengthL)); double mAngle =
      // acos((mLengthCurrent*mLengthCurrent + mLengthL*mLengthL -
      // mLengthR*mLengthR)/(2*mLengthCurrent*mLengthL)); double mX =
      // cos(mAngle)*mLengthL; double mY = sin(mAngle)*mLengthL; double mx1 =
      // mLengthCurrent;
      double mx2 = (mLengthCurrent * mLengthCurrent + mLengthL * mLengthL -
                    mLengthR * mLengthR) /
                   (2 * mLengthCurrent);
      double my2 = sqrt(mLengthL * mLengthL - mx2 * mx2);

      m_pseudo_x = (v * mLengthCurrent + w * mx2) / scaleCurrent;
      m_pseudo_y = w * my2;
    }
#endif

    m_pseudo_y = -m_pseudo_y;
  }

} // namespace geodesic

#endif // GEODESIC_ALGORITHM_EXACT_ELEMENTS_20071231

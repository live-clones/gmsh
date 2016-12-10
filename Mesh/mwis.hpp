#include "search.hpp"

#include <boost/iterator/counting_iterator.hpp>

#include <boost/graph/random.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <random>
#include <vector>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>
#include <iostream>

namespace mwis {

/**
 * A functor to calculate an upper bound to the maximum weight independent set
 * in a graph.
 *
 * A Lagrangian relaxation of the problem is used:
 *
 *   UB = min_{λ >= 0} max_{x_i \in {0, 1}}
 *           (\sum_{i \in V} x_iw_i) -
 *           \sum_{c \in C} λ_c(\sum_{i \in c} - 1)
 *
 * Where C is a set of cliques within the graph, such that if there is an edge
 * between two nodes in the graph, a clique that contains both nodes is present
 * in C.
 *
 * The set {{u, v} | (u, v) \in E} can always be used as the set of
 * cliques. However, using larger cliques can lead to better upper bounds.
 */
template<typename Graph, typename WeightMap>
class lagrangian_bound {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  typedef typename boost::property_map<
    Graph, boost::vertex_index_t>::type index_map;

  typedef boost::iterator_property_map<
    std::vector<bool>::iterator, index_map> selected_map_type;
  typedef boost::iterator_property_map<
    std::vector<std::vector<size_t>>::iterator, index_map> clique_map_type;
  typedef boost::iterator_property_map<
    typename std::vector<weight>::iterator, index_map> weight_map_type;

  const Graph &_graph;
  WeightMap _weight;
  size_t _max_size;

  std::vector<std::vector<vertex>> _clique_contents;

  std::vector<weight> _lambda, _gradient;

  std::vector<std::vector<size_t>> _clique_storage;
  std::vector<bool> _selected_storage;
  std::vector<weight> _effective_weight_storage;

  clique_map_type _cliques;
  selected_map_type _selected;
  weight_map_type _effective_weight;
public:
  typedef weight result_type;

  template<typename CliqueIterator>
  lagrangian_bound(const Graph &graph, WeightMap weight_map,
                   CliqueIterator clique_begin,
                   CliqueIterator clique_end,
                   size_t max_size = std::numeric_limits<size_t>::max()):
    _graph(graph), _weight(weight_map), _max_size(max_size) {
    auto vs = vertices(graph);
    size_t vertex_count = vs.second - vs.first;

    _clique_storage.resize(vertex_count);
    _selected_storage.resize(vertex_count);
    _effective_weight_storage.resize(vertex_count);

    index_map ids = boost::get(boost::vertex_index, graph);

    _cliques  = make_iterator_property_map(_clique_storage.begin(),   ids);
    _selected = make_iterator_property_map(_selected_storage.begin(), ids);
    _effective_weight = make_iterator_property_map(
      _effective_weight_storage.begin(), ids);

    size_t i = 0;
    for (CliqueIterator it = clique_begin; it != clique_end; it++, i++) {
      std::vector<vertex> to_add;
      for (const vertex &v : *it) {
        to_add.push_back(v);
        get(_cliques, v).push_back(i);
      }
      _clique_contents.push_back(to_add);
    }

    _lambda.resize(_clique_contents.size());
    _gradient.resize(_clique_contents.size());

    for (weight &v : _lambda) v = weight(0);
  }

  /**
   * Calculates an upper bound. This bound is always admissible, but may not be
   * optimal.
   *
   * Vertices in [solution_begin, solution_end) are all forced to be part of the
   * solution.
   *
   * Vertices in [rest_begin, rest_end) can be selected in any way to maximize
   * the objective functions.
   *
   * Vertices in neither range are assumed not to be part of the solution.
   */
  template<typename SolutionIterator,
           typename RestIterator>
  weight operator()(SolutionIterator solution_begin,
                    SolutionIterator solution_end,
                    RestIterator rest_begin,
                    RestIterator rest_end) {
    weight best(std::numeric_limits<weight>::max());

    std::set<size_t> selectable_cliques;
    for (RestIterator it = rest_begin; it != rest_end; it++) {
      const std::vector<size_t> cs = get(_cliques, *it);
      std::copy(cs.begin(), cs.end(),
                std::inserter(selectable_cliques, selectable_cliques.begin()));
    }

    /**
     * We can get away with very few steps, because the starting point is the
     * optimum that was found the last time the algorithm was used, and the
     * input does not usually change much between two calls (therefore, one
     * would expect the optima to be close to each other).
     */
    static const size_t n = 2;
    for (size_t i = 0; i < n; i++) {
      compute_weights(rest_begin, rest_end);

      if (_max_size == std::numeric_limits<size_t>::max())
        select(rest_begin, rest_end);
      else
        select(rest_begin, rest_end,
               _max_size - (size_t)std::distance(solution_begin,
                                                 solution_end));

      best = std::min(best, evaluate(rest_begin, rest_end,
                                     selectable_cliques.begin(),
                                     selectable_cliques.end()));

      if (i != n - 1) {
        compute_gradient(selectable_cliques.begin(), selectable_cliques.end());
        follow_gradient(selectable_cliques.begin(), selectable_cliques.end(),
                        weight(-1e-4 / 1));
      }
    }

    return best;
  }

  /**
   * For debugging purposes, displays any inconsistencies between the graph and
   * the sequence of cliques.
   *
   * (u, v) \in E <=> there is a clique which contains both u and v.
   */
  void check_consistency() {
    auto es = boost::edges(_graph);
    for (auto eit = es.first; eit != es.second; eit++) {
      bool found = false;

      vertex v = boost::source(*eit, _graph);
      vertex w = boost::target(*eit, _graph);

      const std::vector<size_t> &cliques_v = get(_cliques, v);
      const std::vector<size_t> &cliques_w = get(_cliques, w);

      for (size_t clique : cliques_v) {
        if (std::find(cliques_w.begin(), cliques_w.end(), clique) !=
            cliques_w.end()) {
          found = true;
          break;
        }
      }

      if (!found) {
        std::cout << "no shared clique between connected vertices: " <<
          v << " and " << w << "\n";
      }
    }

    for (const std::vector<vertex> &clique : _clique_contents) {
      for (vertex v : clique) {
        for (vertex w : clique) {
          if (v == w) continue;

          if (!edge(v, w, _graph).second) {
            std::cout << "no edge between " << v << " and " <<
              w << "\n";
          }
        }
      }
    }
  }
private:
  /**
   * Calculates the gradient according to which nodes are currently selected.
   */
  template<typename Iterator>
  void compute_gradient(Iterator cliques_begin, Iterator cliques_end) {
    for (Iterator it = cliques_begin; it != cliques_end; it++) {
      weight sum{1};
      for (const vertex &v : _clique_contents[*it]) {
        sum -= weight(get(_selected, v) ? 1 : 0);
      }

      _gradient[*it] = sum;
    }
  }

  /**
   * Calculates the effective weight of each node (w_i - \sum_{c, x \in c} λ_c).
   */
  template<typename Iterator>
  void compute_weights(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; it++) {
      weight result(get(_weight, *it));

      for (size_t clique : get(_cliques, *it))
        result -= _lambda[clique];

      put(_effective_weight, *it, result);
    }
  }

  /**
   * Update the Lagrange multipliers in accordance with the last computed
   * gradient, multiplied by scale.
   */
  template<typename Iterator>
  void follow_gradient(Iterator cliques_begin, Iterator cliques_end,
                       weight scale) {
    for (Iterator it = cliques_begin; it != cliques_end; it++) {
      weight cur(_lambda[*it]);
      weight grad(_gradient[*it]);
      _lambda[*it] = cur + scale * grad;
    }
  }

  /**
   * Iterates over the given range, and selects the subset of its nodes which have
   * a non-negative weight, so as to maximize the objective function.
   */
  template<typename Iterator>
  void select(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; it++) {
      vertex v = *it;
      put(_selected, v, get(_effective_weight, v) >= weight(0));
    }
  }

  /**
   * Iterates over the given range, and selects subset of its nodes which have
   * a non-negative weight, selecting at most n nodes.
   */
  template<typename Iterator>
  void select(Iterator begin, Iterator end, size_t n) {
    n = std::min((size_t)std::distance(begin, end), n);
    std::vector<vertex> largest(n);

    std::partial_sort_copy(
      begin, end,
      largest.begin(), largest.end(),
      [&](vertex a ,vertex b) {
        return get(_effective_weight, a) > get(_effective_weight, b);
      });

    for (Iterator it = begin; it != end; it++) {
      vertex v = *it;
      put(_selected, v, false);
    }

    for (vertex v : largest) {
      if (get(_effective_weight, v) <= weight(0))
        break;
      put(_selected, v, true);
    }
  }


  /**
   * Calculates the upper bound for the current values of the Lagrange
   * multipliers and the current selection of nodes.
   */
  template<typename Iterator, typename CliqueIterator>
  weight evaluate(Iterator begin, Iterator end,
                  CliqueIterator cliques_begin, CliqueIterator cliques_end) {
    weight result(0);
    for (CliqueIterator it = cliques_begin; it != cliques_end; it++) {
      result += _lambda[*it];
    }

    for (Iterator it = begin; it != end; it++) {
      if (get(_selected, *it))
        result += get(_effective_weight, *it);
    }

    return result;
  }
};

template<typename T>
struct max_bound {
  typedef T result_type;

  template<typename SolutionIter, typename RestIter>
  T operator()(SolutionIter solution_begin, SolutionIter solution_end,
               RestIter rest_begin, RestIter rest_end) {
    return std::numeric_limits<T>::max();
  }
};

template<typename Graph, typename WeightMap>
class state_change;

template<typename Graph, typename WeightMap>
class clique_assignment;

template<typename Graph, typename WeightMap>
struct state {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  typedef typename boost::property_map<
    Graph, boost::vertex_index_t>::type index_map;
  typedef boost::iterator_property_map<
    std::vector<std::vector<size_t>>::iterator, index_map> clique_map_type;

  const Graph &graph;
  WeightMap weight_map;

  std::vector<std::vector<vertex>> cliques;
  std::vector<size_t> clique_sizes;
   std::set<vertex> selectable;
  std::vector<bool> assigned;

  std::vector<std::vector<size_t>> clique_map_storage;
  clique_map_type clique_map;

  std::vector<vertex> solution;
  weight solution_value;

  template<typename CliqueIterator>
  state(const Graph &graph,
        WeightMap weight_map,
        CliqueIterator clique_begin,
        CliqueIterator clique_end):
    graph(graph), weight_map(weight_map),
    cliques(clique_begin, clique_end),
    clique_sizes(cliques.size()),
    selectable(vertices(graph).first, vertices(graph).second),
    assigned(cliques.size(), false),
    solution_value(0)
    {
      clique_map_storage.resize(num_vertices(graph));
      index_map id_map = get(boost::vertex_index, graph);
      clique_map = make_iterator_property_map(
        clique_map_storage.begin(), id_map);

      for (size_t i = 0; i < cliques.size(); i++)
        clique_sizes[i] = cliques[i].size();

      size_t id = 0;
      for (std::vector<vertex> &clique : cliques) {
        for (vertex v : clique)
          get(clique_map, v).push_back(id);

        std::sort(clique.begin(), clique.end(), [&](vertex a, vertex b) {
          return get(weight_map, a) > get(weight_map, b);
        });

        id++;
      }
    }
};

template<typename Graph, typename WeightMap>
class clique_assignment {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  size_t _id;
  vertex _vertex;
  bool _selected;

public:
  typedef state_change<Graph, WeightMap> result_type;
  typedef state<Graph, WeightMap> argument_type;

  clique_assignment(size_t id):
    _id(id), _selected(false)
    {}

  clique_assignment(size_t id, vertex vertex_id):
    _id(id), _vertex(vertex_id), _selected(true)
    {}

  state_change<Graph, WeightMap> operator()(
    const state<Graph, WeightMap> &state) const {
    std::vector<vertex> selected_vertex, removed;
    std::vector<size_t> assigned;

    weight new_weight(state.solution_value);

    if (_selected) {
      selected_vertex.push_back(_vertex);
      new_weight += get(state.weight_map, _vertex);

      auto edges = out_edges(_vertex, state.graph);
      for (auto eit = edges.first; eit != edges.second; eit++) {
        const vertex &other = target(*eit, state.graph);
        if (state.selectable.find(other) != state.selectable.end()) {
          removed.push_back(other);
        }
      }

      for (size_t i : get(state.clique_map, _vertex)) {
        if (!state.assigned[i]) assigned.push_back(i);
      }
    }
    else {
      for (vertex v : state.cliques[_id]) {
        if (state.selectable.find(v) != state.selectable.end())
          removed.push_back(v);
      }

      assigned.push_back(_id);
    }

    std::map<size_t, size_t> size_delta;
    for (vertex v : removed) {
      for (size_t clique : get(state.clique_map, v)) {
        size_delta[clique]++;
        if (size_delta[clique] == state.clique_sizes[clique]) {
          if (!state.assigned[clique])
            assigned.push_back(clique);
        }
      }
    }

    return state_change<Graph, WeightMap>(
      assigned,
      size_delta,
      selected_vertex, removed,
      state.solution_value, new_weight);
  }
};

template<typename Graph, typename WeightMap>
class state_change {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector<size_t> _assigned_id;
  std::map<size_t, size_t> _size_delta;
  std::vector<vertex> _selected;
  std::vector<vertex> _invalidated;
  weight _old_weight, _new_weight;
public:
  state_change() {}

  state_change(const std::vector<size_t> &assigned_id,
               const std::map<size_t, size_t> &size_delta,
               const std::vector<vertex> &selected,
               const std::vector<vertex> &invalidated,
               weight old_weight, weight new_weight):
    _assigned_id(assigned_id),
    _size_delta(size_delta),
    _selected(selected), _invalidated(invalidated),
    _old_weight(old_weight), _new_weight(new_weight)
    {}

  void apply(state<Graph, WeightMap> &state) const {
    for (size_t i : _assigned_id)
      state.assigned[i] = true;

    size_t old_size = state.solution.size();
    state.solution.resize(state.solution.size() + _selected.size());
    std::copy(_selected.begin(), _selected.end(),
              state.solution.begin() + old_size);

    for (vertex v : _selected)
      state.selectable.erase(v);

    state.solution_value = _new_weight;

    for (vertex v : _invalidated) {
      state.selectable.erase(v);
    }

    for (auto pair : _size_delta)
      state.clique_sizes[pair.first] -= pair.second;
  }

  void reverse(state<Graph, WeightMap> &state) const {
    for (size_t i : _assigned_id)
      state.assigned[i] = false;

    state.solution.resize(state.solution.size() - _selected.size());

    for (vertex v : _selected)
      state.selectable.insert(v);

    state.solution_value = _old_weight;

    for (vertex v : _invalidated) {
      state.selectable.insert(v);
    }

    for (auto pair : _size_delta)
      state.clique_sizes[pair.first] += pair.second;
  }
};

template<typename Graph, typename WeightMap>
struct visit_state {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  bool quiet;

  weight best_value;
  std::vector<vertex> best_solution;

  visit_state(bool quiet = true): quiet(quiet), best_value(0) {}

  void operator()(state<Graph, WeightMap> &state) {
    if (best_value < state.solution_value) {
      if (!quiet) {
        std::cout << "new best: " << state.solution_value <<
          " (" << state.solution.size() << ")\n";
      }

      best_value    = state.solution_value;
      best_solution = state.solution;
    }
  }
};

template<typename Graph, typename WeightMap, typename UpperBound>
class successor {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename std::vector<vertex>::iterator viterator;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  UpperBound &_bound;

  size_t _visited;
  weight *_best_weight;

  size_t _limit;
public:
  typedef clique_assignment<Graph, WeightMap> action_type;

  successor(UpperBound &bound, weight &best_weight,
            size_t limit = std::numeric_limits<size_t>::max()):
    _bound(bound), _visited(0), _best_weight(&best_weight), _limit(limit)
    {}

  template<typename OutputIterator>
  void operator()(state<Graph, WeightMap> &state, OutputIterator it) {
    if (_visited > 1000 * 1000 * 10)
      return;
    else
      _visited++;

    if (state.solution.size() == _limit)
      return;

    auto clique_begin = boost::make_counting_iterator<size_t>(0);
    auto clique_end   = boost::make_counting_iterator<size_t>(
      state.cliques.size());

    auto clique_it = std::min_element(
      clique_begin, clique_end, [&](size_t a, size_t b) {
        return clique_key(state, a) < clique_key(state, b);
      });

    if (clique_it == clique_end || state.assigned[*clique_it])
      return;

    std::vector<vertex> vertices;
    size_t id = *clique_it;
    for (vertex v : state.cliques[id]) {
      if (state.selectable.find(v) != state.selectable.end()) {
        vertices.push_back(v);
      }
    }

    if (vertices.size() > 0) {
      weight max(state.solution_value +
                 _bound(state.solution.begin(), state.solution.end(),
                        state.selectable.begin(), state.selectable.end()));
      if (max <= *_best_weight)
        return;
    }

    std::sort(vertices.begin(), vertices.end(),
              [&](vertex a, vertex b) {
                return vertex_regret(state, a) < vertex_regret(state, b);
              });

    for (vertex v : vertices)
      *it++ = clique_assignment<Graph, WeightMap>(id, v);

    *it++ = clique_assignment<Graph, WeightMap>(id);
  }

  std::tuple<int, size_t, weight>
  clique_key(state<Graph, WeightMap> &state,
             size_t id) {
    if (state.assigned[id]) {
      return std::make_tuple(1,
                             std::numeric_limits<size_t>::max(),
                             weight(0));
    }
    else if (state.clique_sizes[id] == 0) {
      return std::make_tuple(0, 0, weight(0));
    }
    else {
      vertex v = *std::find_if(
        state.cliques[id].begin(), state.cliques[id].end(), [&](vertex v) {
          return state.selectable.find(v) != state.selectable.end();
        });

      return std::make_tuple(id < 1361 ? 0 : 1,
                             state.clique_sizes[id],
                             -get(state.weight_map, v));
    }
  }

  weight vertex_regret(const state<Graph, WeightMap> &state, vertex v) {
    weight result(-get(state.weight_map, v));

    auto es = out_edges(v, state.graph);
    for (auto eit = es.first; eit != es.second; eit++) {
      vertex u = target(*eit, state.graph);
      if (state.selectable.find(u) == state.selectable.end())
        result += get(state.weight_map, u);
    }

    return result;
  }
};

template<typename Graph, typename WeightMap>
class evaluator {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector<std::vector<vertex>> _cliques;
  size_t _limit;
public:
  typedef weight result_type;
  typedef state<Graph, WeightMap> argument_type;

  template<typename Iterator>
  evaluator(Iterator begin, Iterator end, size_t limit):
    _cliques(begin, end), _limit(limit)
    {}

  weight operator()(state<Graph, WeightMap> &cur) const {
    visit_state<Graph, WeightMap> visitor;

    max_bound<weight> bound;
    successor<Graph, WeightMap, decltype(bound)>
      successor(bound, visitor.best_value, cur.solution.size() + _limit);

    visitor(cur);
    search::depth_limited_search(cur, visitor, successor, _limit);

    return visitor.best_value;
  }
};

template<typename Graph, typename WeightMap>
struct lns_state {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;

  const Graph &graph;
  WeightMap weight_map;

  std::vector<vertex> solution;

  lns_state(const Graph &graph, WeightMap weight_map,
            const std::vector<vertex> &solution):
    graph(graph), weight_map(weight_map), solution(solution)
    {}
};

template<typename Graph>
struct lns_fragment {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;

  std::set<vertex> vertices;

  lns_fragment(const std::set<vertex> &vertices):
    vertices(vertices)
    {}
};

/**
 * Behaves like a queue, but elements can only be inserted into the queue a
 * limited amount of times.
 */
template<typename T>
class limited_queue {
  std::queue<T> _queue;
  size_t _size, _max_size;
public:
  typedef T value_type;
  typedef typename std::queue<T>::size_type size_type;

  limited_queue(size_t max_size):
    _size(0), _max_size(max_size) {}

  void push(const T &t) {
    if (_size != _max_size) {
      _size++;
      _queue.push(t);
    }
  }

  void pop() { _queue.pop(); }

  T &top() { return _queue.front(); }
  const T &top() const { return _queue.front(); }

  size_type size() const { return _queue.size(); }

  bool empty() { return _queue.empty(); }
};

/**
 * A visitor for graph traversal algoritms which records the target of every
 * visited edge into a set.
 */
template<typename Graph, typename Tag>
class set_recorder : public boost::base_visitor<set_recorder<Graph, Tag>> {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::edge_descriptor edge;

  std::set<vertex> &_set;
public:
  typedef Tag event_filter;

  set_recorder(std::set<vertex> &set): _set(set) {}

  void operator()(edge e, const Graph &g) {
    _set.insert(boost::target(e, g));
  }
};

template<typename Graph, typename WeightMap>
lns_fragment<Graph> fragment_selector(const lns_state<Graph, WeightMap> &state) {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;

  if (boost::num_vertices(state.graph) == 0)
    return lns_fragment<Graph>(std::set<vertex>());

  std::random_device dev;
  std::mt19937 gen(dev());

  vertex v = boost::random_vertex(state.graph, gen);

  size_t neighborhood_size = std::uniform_int_distribution<size_t>(50, 80)(gen);

  std::set<vertex> set;
  set.insert(v);
  set_recorder<Graph, boost::on_black_target> recorder(set);

  limited_queue<vertex> queue(neighborhood_size);

  boost::breadth_first_search(
    state.graph, v,
    boost::buffer(queue).
    visitor(boost::make_bfs_visitor(recorder)));

  return lns_fragment<Graph>(set);
}

template<typename Graph>
class lns_assignment {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  std::vector<vertex> _vertices;
public:
  lns_assignment(const std::vector<vertex> &vertices): _vertices(vertices) {}

  template<typename WeightMap>
  void operator()(lns_state<Graph, WeightMap> &state,
                  const lns_fragment<Graph> &fragment) const {
    static int i = 0;
    std::cout << "\rsize: " << state.solution.size() << " " << i++;
    std::cout.flush();

    state.solution.erase(
      std::remove_if(
        state.solution.begin(), state.solution.end(),
        [&](vertex v) {
          return fragment.vertices.find(v) != fragment.vertices.end();
        }),
      state.solution.end());

    std::copy(_vertices.begin(), _vertices.end(),
              std::back_inserter(state.solution));
  }
};

template<typename Graph, typename WeightMap>
class lns_search {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector<std::vector<vertex>> _cliques;
public:
  typedef lns_assignment<Graph> result_type;
  typedef lns_state<Graph, WeightMap> first_argument_type;
  typedef lns_fragment<Graph> second_argument_type;

  template<typename Iterator>
  lns_search(Iterator begin, Iterator end): _cliques(begin, end) {}

  lns_assignment<Graph> operator()(const lns_state<Graph, WeightMap> &l_state,
                                   const lns_fragment<Graph> &fragment) const {
    state<Graph, WeightMap> search_state(l_state.graph, l_state.weight_map,
                                         _cliques.begin(), _cliques.end());

    std::vector<vertex> selected_vertex;
    std::set<vertex> removed;
    std::set<size_t> assigned;

    weight new_weight(0);

    for (vertex v : l_state.solution) {
      if (fragment.vertices.find(v) != fragment.vertices.end())
        continue;

      selected_vertex.push_back(v);

      new_weight += get(l_state.weight_map, v);

      auto edges = out_edges(v, l_state.graph);
      for (auto eit = edges.first; eit != edges.second; eit++) {
        const vertex &other = target(*eit, l_state.graph);
        removed.insert(other);
      }

      for (size_t i : get(search_state.clique_map, v))
        assigned.insert(i);
    }

    auto vs = boost::vertices(l_state.graph);
    for (auto it = vs.first; it != vs.second; it++) {
      vertex v = *it;
      if (fragment.vertices.find(v) == fragment.vertices.end())
        removed.insert(v);
    }

    std::map<size_t, size_t> size_delta;
    for (vertex v : removed) {
      for (size_t clique : get(search_state.clique_map, v)) {
        size_delta[clique]++;
        if (size_delta[clique] == search_state.clique_sizes[clique]) {
          assigned.insert(clique);
        }
      }
    }

    std::vector<size_t> assigned_v(assigned.begin(), assigned.end());
    std::vector<vertex> removed_v(removed.begin(), removed.end());

    state_change<Graph, WeightMap> delta(
      assigned_v, size_delta,
      selected_vertex, removed_v,
      weight(0), new_weight);

    delta.apply(search_state);

    lagrangian_bound<Graph, WeightMap>
      bound(l_state.graph, l_state.weight_map,
            _cliques.begin(), _cliques.end());

    visit_state<Graph, WeightMap> visitor;
    visitor.best_solution = l_state.solution;
    visitor.best_value = weight(0);
    for (vertex v : visitor.best_solution)
      visitor.best_value += get(l_state.weight_map, v);

    successor<Graph, WeightMap, decltype(bound)> successor(
      bound, visitor.best_value);

    search::depth_first_search(search_state, visitor, successor);

    std::vector<vertex> newly_selected;
    for (vertex v : visitor.best_solution) {
      if (fragment.vertices.find(v) != fragment.vertices.end())
        newly_selected.push_back(v);
    }

    return lns_assignment<Graph>(newly_selected);
  }
};

template<typename Graph, typename WeightMap>
class direct_evaluator {
public:
  typedef typename boost::property_traits<WeightMap>::value_type result_type;
  typedef state<Graph, WeightMap> argument_type;

private:
  result_type _bound;

public:
  direct_evaluator(result_type bound): _bound(bound) {}

  result_type operator()(const argument_type &state) const {
    return state.solution_value / _bound;
  }
};

template<typename Graph, typename OutputIterator>
void find_cliques(const Graph &graph, OutputIterator out) {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;

  std::set<std::pair<vertex, vertex>> visited_edges;

  auto es = edges(graph);
  for (auto eit = es.first; eit != es.second; eit++) {
    auto u = source(*eit, graph);
    auto v = target(*eit, graph);

    if (visited_edges.find(std::make_pair(u, v)) == visited_edges.end()) {
      std::vector<vertex> contents, candidates;

      auto connected_es = out_edges(u, graph);
      for (auto eit = connected_es.first; eit != connected_es.second; eit++) {
        auto new_v = target(*eit, graph);
        if (new_v != v && visited_edges.find(std::make_pair(u, new_v)) ==
            visited_edges.end()) {
          candidates.push_back(new_v);
        }
      }

      candidates.push_back(v);

      contents.push_back(u);

      while (!candidates.empty()) {
        vertex v = candidates.back();
        candidates.pop_back();

        contents.push_back(v);

        candidates.erase(
          std::remove_if(candidates.begin(), candidates.end(),
                         [&](vertex w) {
                           return visited_edges.find(std::make_pair(v, w)) ==
                             visited_edges.end();
                         }),
          candidates.end());
      }

      for (size_t i = 0; i < contents.size(); i++) {
        for (size_t j = 0; j < i; j++) {
          visited_edges.insert(std::make_pair(contents[i], contents[j]));
          visited_edges.insert(std::make_pair(contents[j], contents[i]));
        }
      }

      *out++ = contents;
    }
  }
}

}

template<typename Graph, typename WeightMap, typename OutputIterator>
void maximum_weight_independent_set(const Graph &graph, WeightMap weight_map,
                                    OutputIterator out) {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector<std::vector<vertex>> cliques;
  mwis::find_cliques(graph, std::back_inserter(cliques));

  mwis::lagrangian_bound<Graph, WeightMap> bound(
    graph, weight_map,
    cliques.begin(), cliques.end());

  bound.check_consistency();

  mwis::visit_state<Graph, WeightMap> visitor;
  mwis::successor<Graph, WeightMap, decltype(bound)> successor(
    bound, visitor.best_value);

  mwis::state<Graph, WeightMap> state(
    graph, weight_map,
    cliques.begin(), cliques.end());

  // search::depth_first_search(state, visitor, successor);
  // for (vertex v : visitor.best_solution)
  //   *out++ = v;

  auto vs = vertices(graph);
  weight root_bound(bound(vs.second, vs.second, vs.first, vs.second));

  mwis::direct_evaluator<Graph, WeightMap> direct_eval(root_bound);

  mwis::max_bound<weight> max_bound;
  mwis::successor<Graph, WeightMap, decltype(max_bound)>
    max_successor(max_bound, visitor.best_value);

  search::monte_carlo_tree_search(state, max_successor, direct_eval);
  std::cout << "\n";

  for (vertex v : state.solution)
    *out++ = v;

  // mwis::evaluator<Graph, WeightMap> eval(cliques.begin(), cliques.end(), 5);

  // visitor(state);
  // search::greedy_search(state, successor, eval);

  // mwis::lns_state<Graph, WeightMap> l_state(graph, weight_map, state.solution);
  // mwis::lns_fragment<Graph> (*l_selector)(const decltype(l_state)&) =
  //   mwis::fragment_selector<Graph, WeightMap>;
  // mwis::lns_search<Graph, WeightMap> l_search(cliques.begin(), cliques.end());

  // search::large_neighborhood_search(l_state, l_selector, l_search, 300);
  // std::cout << "\n";

  // for (vertex v : l_state.solution)
  //   *out++ = v;
}

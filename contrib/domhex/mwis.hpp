#include "search.hpp"

#include <boost/heap/fibonacci_heap.hpp>

#include <boost/graph/random.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <vector>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>
#include <iostream>

namespace mwis {

/**
 * A function object which compares two elements by looking up the values
 * associated to them in a property map, and comparing these using Comparator
 * (by default, using operator <).
 */
template<typename PropertyMap,
         typename Comparator = std::less<
           typename boost::property_traits<PropertyMap>::value_type> >
class compare_by_property {
  PropertyMap _map;
  Comparator _comparator;
public:
  typedef typename boost::property_traits<PropertyMap>::key_type argument_type;
  typedef argument_type first_argument_type;
  typedef argument_type second_argument_type;
  typedef bool result_type;

  compare_by_property(PropertyMap map,
                      Comparator comparator = Comparator()):
    _map(map), _comparator(comparator)  {}

  bool operator()(const argument_type &a, const argument_type &b) const {
    return _comparator(get(_map, a), get(_map, b));
  }
};

/**
 * Convenience function to create a property map comparator.
 */
template<typename PropertyMap,
         typename Comparator = std::less<
           typename boost::property_traits<PropertyMap>::value_type> >
compare_by_property<PropertyMap, Comparator>
make_property_map_comparator(PropertyMap map,
                             Comparator comparator = Comparator()) {
  return compare_by_property<PropertyMap, Comparator>(map, comparator);
}

/**
 * Function object that returns true iff an element belongs to a container.
 *
 * Elements are searched by ussing the find method on the container.
 */
template<typename Container, typename Key>
class container_membership_test {
  const Container &_container;
public:
  container_membership_test(const Container &container):
    _container(container)
    {}

  typedef Key argument_type;
  typedef bool result_type;

  bool operator()(const Key &arg) const {
    return _container.find(arg) != _container.end();
  }
};

template<typename T>
container_membership_test<std::set<T>, T> make_set_membership_test(
  const std::set<T> &container) {
  return container_membership_test<std::set<T>, T>(container);
}

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
    std::vector< std::vector<size_t> >::iterator, index_map> clique_map_type;
  typedef boost::iterator_property_map<
    typename std::vector<weight>::iterator, index_map> weight_map_type;

  const Graph &_graph;
  WeightMap _weight;
  size_t _max_size;

  std::vector< std::vector<vertex> > _clique_contents;

  std::vector<weight> _lambda, _gradient;

  std::vector< std::vector<size_t> > _clique_storage;
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
    size_t vertex_count = num_vertices(graph);

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
      for (typename std::vector<vertex>::const_iterator v_it = it->begin();
           v_it != it->end(); v_it++) {
        to_add.push_back(*v_it);
        get(_cliques, *v_it).push_back(i);
      }
      _clique_contents.push_back(to_add);
    }

    _lambda.resize(_clique_contents.size());
    _gradient.resize(_clique_contents.size());

    for (std::size_t i = 0; i < _lambda.size(); i++)
      _lambda[i] = weight(0);
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
    typedef typename boost::graph_traits<Graph>::edge_iterator edge_iterator;

    std::pair<edge_iterator, edge_iterator> es = boost::edges(_graph);
    for (edge_iterator eit = es.first; eit != es.second; eit++) {
      bool found = false;

      vertex v = boost::source(*eit, _graph);
      vertex w = boost::target(*eit, _graph);

      const std::vector<size_t> &cliques_v = get(_cliques, v);
      const std::vector<size_t> &cliques_w = get(_cliques, w);

      for (std::size_t i = 0; i < cliques_v.size(); i++) {
        std::size_t clique = cliques_v[i];
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

    for (std::size_t i = 0; i < _clique_contents.size(); i++) {
      const std::vector<vertex> &clique = _clique_contents[i];

      for (std::size_t j = 0; j < clique.size(); j++) {
        vertex v = clique[j];
        for (std::size_t k = j+1; k < clique.size(); k++) {
          vertex w = clique[k];

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

      const std::vector<vertex> &clique = _clique_contents[*it];
      for (std::size_t i = 0; i < clique.size(); i++) {
        sum -= weight(get(_selected, clique[i]) ? 1 : 0);
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

      const std::vector<std::size_t> &vertex_cliques = get(_cliques, *it);
      for (std::size_t i = 0; i < vertex_cliques.size(); i++) {
        result -= _lambda[vertex_cliques[i]];
      }

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
      make_property_map_comparator(_effective_weight,
                                   std::greater<weight>()));

    for (Iterator it = begin; it != end; it++) {
      vertex v = *it;
      put(_selected, v, false);
    }

    for (std::size_t i = 0; i < largest.size(); i++) {
      vertex v = largest[i];
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
private:
  class clique_size_comparator {
    const state &_state;
  public:
    typedef std::size_t argument_type;
    typedef std::size_t first_argument_type;
    typedef std::size_t second_argument_type;
    typedef bool result_type;

    clique_size_comparator(state &state): _state(state) {}

    bool operator()(std::size_t a, std::size_t b) const {
      return _state.clique_sizes[a] > _state.clique_sizes[b];
    }
  };
public:
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  typedef typename boost::property_map<
    Graph, boost::vertex_index_t>::type index_map;
  typedef boost::iterator_property_map<
    std::vector< std::vector<size_t> >::iterator, index_map> clique_map_type;

  typedef boost::heap::fibonacci_heap<
    std::size_t,
    boost::heap::compare< clique_size_comparator > > clique_queue_type;
  typedef typename clique_queue_type::handle_type clique_handle_type;

  const Graph &graph;
  WeightMap weight_map;

  std::vector< std::vector<vertex> > cliques;
  std::vector<size_t> clique_sizes;

  clique_queue_type clique_queue;
  std::vector<clique_handle_type> clique_handles;

  std::set<vertex> selectable;
  std::vector<bool> assigned;

  std::vector< std::vector<size_t> > clique_map_storage;
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
    clique_queue(clique_size_comparator(*this)),
    clique_handles(cliques.size()),
    selectable(vertices(graph).first, vertices(graph).second),
    assigned(cliques.size(), false),
    solution_value(0)
    {
      clique_map_storage.resize(num_vertices(graph));
      index_map id_map = get(boost::vertex_index, graph);
      clique_map = make_iterator_property_map(
        clique_map_storage.begin(), id_map);

      for (size_t i = 0; i < cliques.size(); i++) {
        clique_sizes[i] = cliques[i].size();
        clique_handles[i] = clique_queue.push(i);
      }

      size_t id = 0;

      for (std::size_t i = 0; i < cliques.size(); i++) {
        std::vector<vertex> &clique = cliques[i];

        for (std::size_t j = 0; j < clique.size(); j++)
          get(clique_map, clique[j]).push_back(id);

        std::sort(clique.begin(), clique.end(),
                  make_property_map_comparator(weight_map,
                                               std::greater<weight>()));

        id++;
      }
    }
};

template<typename Graph, typename WeightMap>
class clique_assignment {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::out_edge_iterator out_edge_iterator;
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

      removed.push_back(_vertex);

      std::pair<out_edge_iterator, out_edge_iterator> edges =
        out_edges(_vertex, state.graph);
      for (out_edge_iterator eit = edges.first; eit != edges.second; eit++) {
        const vertex &other = target(*eit, state.graph);
        if (state.selectable.find(other) != state.selectable.end()) {
          removed.push_back(other);
        }
      }

      const std::vector<std::size_t> &clique_ids = get(state.clique_map, _vertex);
      for (std::size_t i = 0; i < clique_ids.size(); i++) {
        std::size_t c_id = clique_ids[i];
        if (!state.assigned[c_id]) assigned.push_back(c_id);
      }
    }
    else {
      const std::vector<vertex> &clique = state.cliques[_id];
      for (std::size_t i = 0; i < clique.size(); i++) {
        vertex v = clique[i];
        if (state.selectable.find(v) != state.selectable.end())
          removed.push_back(v);
      }

      assigned.push_back(_id);
    }

    std::map<size_t, size_t> size_delta;
    for (std::size_t i = 0; i < removed.size(); i++) {
      vertex v = removed[i];

      const std::vector<std::size_t> &cliques = get(state.clique_map, v);
      for (std::size_t j = 0; j < cliques.size(); j++) {
        std::size_t clique = cliques[j];

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
    for (size_t i = 0; i < _assigned_id.size(); i++)
      state.assigned[_assigned_id[i]] = true;

    size_t old_size = state.solution.size();
    state.solution.resize(state.solution.size() + _selected.size());
    std::copy(_selected.begin(), _selected.end(),
              state.solution.begin() + old_size);

    for (std::size_t i = 0; i < _selected.size(); i++)
      state.selectable.erase(_selected[i]);

    state.solution_value = _new_weight;

    for (std::size_t i = 0; i < _invalidated.size(); i++) {
      state.selectable.erase(_invalidated[i]);
    }

    for (std::map<std::size_t, std::size_t>::const_iterator it = _size_delta.begin();
         it != _size_delta.end(); it++) {
      state.clique_sizes[it->first] -= it->second;

      /*
       * Priority queues (both std::priority_queue and boost::heap::*) are max
       * priority queues by default, so even though we are using a min priority
       * queue, "increasing" the key means moving towards the top of the queue.
       */
      state.clique_queue.increase(state.clique_handles[it->first]);
    }

    while (!state.clique_queue.empty() &&
           state.assigned[state.clique_queue.top()]) {
      state.clique_queue.pop();
    }
  }

  void reverse(state<Graph, WeightMap> &state) const {
    for (size_t i = 0; i < _assigned_id.size(); i++)
      state.assigned[_assigned_id[i]] = false;

    state.solution.resize(state.solution.size() - _selected.size());

    for (std::size_t i = 0; i < _selected.size(); i++)
      state.selectable.insert(_selected[i]);

    state.solution_value = _old_weight;

    for (std::size_t i = 0; i < _invalidated.size(); i++)
      state.selectable.insert(_invalidated[i]);

    for (std::map<std::size_t, std::size_t>::const_iterator it = _size_delta.begin();
         it != _size_delta.end(); it++) {
      state.clique_sizes[it->first] += it->second;

      /*
       * Priority queues (both std::priority_queue and boost::heap::*) are max
       * priority queues by default, so even though we are using a min priority
       * queue, "decreasing" the key means moving towards the bottom of the
       * queue.
       */
      if (state.clique_sizes[it->first] == it->second) {
        state.clique_handles[it->first] = state.clique_queue.push(it->first);
      }
      else {
        state.clique_queue.decrease(state.clique_handles[it->first]);
      }
    }
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

    if (state.clique_queue.empty())
      return;

    std::size_t id = state.clique_queue.top();

    std::vector<vertex> vertices;

    const std::vector<vertex> &clique = state.cliques[id];
    for (std::size_t i = 0; i < clique.size(); i++) {
      vertex v = clique[i];
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
              make_property_map_comparator(
                state.weight_map, std::greater<weight>()));

    for (std::size_t i = 0; i < vertices.size(); i++) {
      *it++ = clique_assignment<Graph, WeightMap>(id, vertices[i]);
    }

    *it++ = clique_assignment<Graph, WeightMap>(id);
  }
};

template<typename Graph, typename WeightMap>
class evaluator {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector< std::vector<vertex> > _cliques;
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
    successor<Graph, WeightMap, max_bound<weight> >
      successor(bound, visitor.best_value, cur.solution.size() + _limit);

    visitor(cur);
    search::depth_limited_search(cur, visitor, successor, _limit);

    return visitor.best_value;
  }
};

template<typename Graph, typename WeightMap>
struct lns_state {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::property_map<
    Graph, boost::vertex_index_t>::type index_map;
  typedef boost::iterator_property_map<
    std::vector<bool>::iterator, index_map> solution_map_type;

  const Graph &graph;
  WeightMap weight_map;

  std::vector<bool> solution_storage;
  solution_map_type solution;

  lns_state(const Graph &graph, WeightMap weight_map,
            const std::vector<vertex> &initial_solution):
    graph(graph), weight_map(weight_map),
    solution_storage(num_vertices(graph), false) {
    index_map ids = boost::get(boost::vertex_index, graph);
    solution = make_iterator_property_map(solution_storage.begin(), ids);

    for (std::size_t i = 0; i < initial_solution.size(); i++) {
      put(solution, initial_solution[i], true);
    }
  }
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
class set_recorder : public boost::base_visitor< set_recorder<Graph, Tag> > {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::edge_descriptor edge;

  std::set<vertex> &_set;
public:
  typedef Tag event_filter;

  set_recorder(std::set<vertex> &set): _set(set) {}

  void operator()(edge e, const Graph &g) {
    _set.insert(boost::target(e, g));
  }

  void operator()(vertex v, const Graph &g) {
    _set.insert(v);
  }
};

template<typename Graph, typename WeightMap>
lns_fragment<Graph> fragment_selector(const lns_state<Graph, WeightMap> &state) {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::vertex_iterator vertex_iterator;
  typedef typename boost::graph_traits<Graph>::out_edge_iterator out_edge_iterator;

  if (boost::num_vertices(state.graph) == 0)
    return lns_fragment<Graph>(std::set<vertex>());

  std::pair<vertex_iterator, vertex_iterator> vs = vertices(state.graph);

  vertex v = *(vs.first + (rand() % std::distance(vs.first, vs.second)));

  size_t neighborhood_size = 30 + rand() % 30;

  std::set<vertex> set;
  set.insert(v);
  set_recorder<Graph, boost::on_examine_vertex> recorder(set);

  limited_queue<vertex> queue(neighborhood_size);

  boost::breadth_first_search(
    state.graph, v,
    boost::buffer(queue).
    visitor(boost::make_bfs_visitor(recorder)));

  std::set<vertex> selectable_subset;
  for (typename std::set<vertex>::const_iterator it = set.begin();
       it != set.end(); it++) {
    std::pair<out_edge_iterator, out_edge_iterator> connected_es =
      out_edges(*it, state.graph);

    out_edge_iterator eit;
    for (eit = connected_es.first; eit != connected_es.second; eit++) {
      vertex v = target(*eit, state.graph);
      if (get(state.solution, v) && set.find(v) == set.end())
        break;
    }

    if (eit == connected_es.second) {
      selectable_subset.insert(*it);
    }
  }

  return lns_fragment<Graph>(selectable_subset);
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
    std::cout << "\rsize: " << i++;
    std::cout.flush();

    for (typename std::set<vertex>::const_iterator it =
           fragment.vertices.begin();
         it != fragment.vertices.end(); it++) {
      put(state.solution, *it, false);
    }

    for (std::size_t i = 0; i < _vertices.size(); i++) {
      put(state.solution, _vertices[i], true);
    }
  }
};

template<typename Graph, typename WeightMap>
class lns_search {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::vertex_iterator vertex_iterator;
  typedef typename boost::graph_traits<Graph>::out_edge_iterator out_edge_iterator;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  typedef typename boost::property_map<
    Graph, boost::vertex_index_t>::type index_map;
  typedef boost::iterator_property_map<
    std::vector< std::vector<size_t> >::iterator, index_map> clique_map_type;

  const Graph &_graph;

  std::vector< std::vector<vertex> > _clique_contents;

  std::vector< std::vector<std::size_t> > _clique_storage;
  clique_map_type _cliques;
public:
  typedef lns_assignment<Graph> result_type;
  typedef lns_state<Graph, WeightMap> first_argument_type;
  typedef lns_fragment<Graph> second_argument_type;

  template<typename Iterator>
  lns_search(const Graph &graph, Iterator begin, Iterator end):
    _graph(graph), _clique_contents(begin, end) {
    size_t vertex_count = num_vertices(graph);
    _clique_storage.resize(vertex_count);

    index_map ids = boost::get(boost::vertex_index, graph);
    _cliques = make_iterator_property_map(_clique_storage.begin(),ids);

    size_t i = 0;
    for (Iterator it = begin; it != end; it++, i++) {
      for (typename std::vector<vertex>::const_iterator v_it = it->begin();
           v_it != it->end(); v_it++) {
        get(_cliques, *v_it).push_back(i);
      }
    }
  }

  lns_assignment<Graph> operator()(const lns_state<Graph, WeightMap> &l_state,
                                   const lns_fragment<Graph> &fragment) const {

    std::set<std::size_t> clique_ids;

    weight best_value(0);
    std::vector<vertex> best_solution;

    for (typename std::set<vertex>::const_iterator it =
           fragment.vertices.begin();
         it != fragment.vertices.end(); it++) {
      const std::vector<size_t> cs = get(_cliques, *it);
      std::copy(cs.begin(), cs.end(),
                std::inserter(clique_ids, clique_ids.begin()));

      if (get(l_state.solution, *it)) {
        best_value += get(l_state.weight_map, *it);
        best_solution.push_back(*it);
      }
    }

    std::vector< std::vector<vertex> > selectable_cliques;
    for (std::set<std::size_t>::const_iterator it = clique_ids.begin();
         it != clique_ids.end(); it++) {
      std::vector<vertex> data = _clique_contents[*it];
      data.erase(
        std::remove_if(data.begin(), data.end(),
                       std::not1(make_set_membership_test(fragment.vertices))),
        data.end());

      if (data.size() != 0)
        selectable_cliques.push_back(data);
    }

    state<Graph, WeightMap> search_state(
      l_state.graph, l_state.weight_map,
      selectable_cliques.begin(),
      selectable_cliques.end());

    lagrangian_bound<Graph, WeightMap>
      bound(l_state.graph, l_state.weight_map,
            selectable_cliques.begin(),
            selectable_cliques.end());

    visit_state<Graph, WeightMap> visitor;
    visitor.best_solution = best_solution;
    visitor.best_value = best_value;

    successor<Graph, WeightMap, lagrangian_bound<Graph, WeightMap> > successor(
      bound, visitor.best_value);

    search::depth_first_search(search_state, visitor, successor);

    return lns_assignment<Graph>(visitor.best_solution);
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

/**
 * Function object that checks if there exisits an edge between a fixed vertex
 * (passed as a parameter to the constructor) and its argument.
 *
 * This is used in find_cliques.
 */
template<typename Graph>
class has_no_edge_test {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;

  const Graph &_graph;
  vertex _v;
public:
  typedef vertex argument_type;
  typedef bool result_type;

  has_no_edge_test(const Graph &graph, vertex v):
    _graph(graph), _v(v)
    {}

  bool operator()(vertex w) const {
    return !edge(_v, w, _graph).second;
  }
};

template<typename Graph, typename OutputIterator>
void find_cliques(const Graph &graph, OutputIterator out) {
  typedef typename boost::graph_traits<Graph>::vertex_descriptor vertex;
  typedef typename boost::graph_traits<Graph>::edge_iterator edge_iterator;
  typedef typename boost::graph_traits<Graph>::out_edge_iterator out_edge_iterator;

  std::set< std::pair<vertex, vertex> > visited_edges;

  std::pair<edge_iterator, edge_iterator> es = edges(graph);
  for (edge_iterator eit = es.first; eit != es.second; eit++) {
    vertex u = source(*eit, graph);
    vertex v = target(*eit, graph);

    if (visited_edges.find(std::make_pair(u, v)) == visited_edges.end()) {
      std::vector<vertex> contents, candidates;

      std::pair<out_edge_iterator, out_edge_iterator> connected_es =
        out_edges(u, graph);
      for (out_edge_iterator eit = connected_es.first;
           eit != connected_es.second; eit++) {
        vertex new_v = target(*eit, graph);
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
                         has_no_edge_test<Graph>(graph, v)),
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
  typedef typename boost::graph_traits<Graph>::vertex_iterator vertex_iterator;
  typedef typename boost::property_traits<WeightMap>::value_type weight;

  std::vector< std::vector<vertex> > cliques;
  mwis::find_cliques(graph, std::back_inserter(cliques));

  mwis::lagrangian_bound<Graph, WeightMap> bound(
    graph, weight_map,
    cliques.begin(), cliques.end());

  bound.check_consistency();

  mwis::visit_state<Graph, WeightMap> visitor;
  mwis::successor<Graph, WeightMap, mwis::lagrangian_bound<Graph, WeightMap> > successor(
    bound, visitor.best_value);

  mwis::state<Graph, WeightMap> state(
    graph, weight_map,
    cliques.begin(), cliques.end());

  std::pair<vertex_iterator, vertex_iterator> vs = vertices(graph);

#ifdef MWIS_MCTS
  weight root_bound(bound(vs.second, vs.second, vs.first, vs.second));

  mwis::direct_evaluator<Graph, WeightMap> direct_eval(root_bound);

  mwis::max_bound<weight> max_bound;
  mwis::successor<Graph, WeightMap, mwis::max_bound<weight> >
    max_successor(max_bound, visitor.best_value);

  search::monte_carlo_tree_search(state, max_successor, direct_eval);
  std::cout << "\n";

  for (std::size_t i = 0; i < state.solution.size(); i++)
    *out++ = state.solution[i];
#else
  mwis::evaluator<Graph, WeightMap> eval(cliques.begin(), cliques.end(), 5);

  visitor(state);
  search::greedy_search(state, successor, eval);

  mwis::lns_state<Graph, WeightMap> l_state(graph, weight_map, state.solution);
  mwis::lns_search<Graph, WeightMap> l_search(graph, cliques.begin(), cliques.end());

  search::large_neighborhood_search(
    l_state,
    mwis::fragment_selector<Graph, WeightMap>,
    l_search, 10);
  std::cout << "\n";

  for (vertex_iterator it = vs.first; it != vs.second; it++) {
    if (get(l_state.solution, *it))
      *out++ = *it;
  }
#endif
}

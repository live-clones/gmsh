#include <vector>
#include <queue>
#include <iterator>
#include <functional>
#include <algorithm>

#include <boost/functional.hpp>

#include "OS.h"

namespace search {

template<typename T>
struct successor_traits {
  typedef typename T::action_type action_type;
};

template<typename T>
struct action_traits {
  typedef typename boost::unary_traits<T>::result_type delta_type;
};

template<typename T>
struct evaluator_traits {
  typedef typename boost::unary_traits<T>::result_type score_type;
};

template<typename T>
struct selector_traits {
  typedef typename boost::unary_traits<T>::result_type fragment_type;
};

template<typename T>
struct search_traits {
  typedef typename boost::binary_traits<T>::result_type assignment_type;
};

template<typename State,
         typename Visitor,
         typename Successor>
void depth_first_search(State &init, Visitor &visit, Successor &fn) {
  typedef typename successor_traits<Successor>::action_type action;
  typedef typename action_traits<action>::delta_type delta;

  visit(init);

  std::vector<action> actions;
  fn(init, std::back_inserter(actions));

  for (typename std::vector<action>::const_iterator it = actions.begin();
       it != actions.end(); it++) {
    const action &action = *it;
    delta change(action(init));

    change.apply(init);
    depth_first_search(init, visit, fn);
    change.reverse(init);
  }
}

template<typename State,
         typename Visitor,
         typename Successor>
void depth_limited_search(State &init, Visitor &visit, Successor &fn,
                          size_t max_depth) {
  typedef typename successor_traits<Successor>::action_type action;
  typedef typename action_traits<action>::delta_type delta;

  visit(init);
  if (max_depth == 0) return;

  std::vector<action> actions;
  fn(init, std::back_inserter(actions));

  for (typename std::vector<action>::const_iterator it = actions.begin();
       it != actions.end(); it++) {
    const action &action = *it;
    delta change(action(init));

    change.apply(init);
    depth_limited_search(init, visit, fn, max_depth - 1);
    change.reverse(init);
  }
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Queue>
void tree_search(State &init, Visitor &visit, Successor &fn, Queue q) {
  typedef typename successor_traits<Successor>::action_type action;

  q.push(init);

  while (!q.empty()) {
    State s = q.top();
    q.pop();

    visit(s);

    std::vector<action> actions;
    fn(s, std::back_inserter(actions));

    for (typename std::vector<action>::const_iterator it = actions.begin();
       it != actions.end(); it++) {
      const action &action = *it;

      State to_add(s);
      action(s).apply(to_add);

      q.push(to_add);
    }
  }
}

template<typename State,
         typename Visitor,
         typename Successor>
void breadth_first_search(State &init, Visitor &visit, Successor &fn) {
  tree_search(init, visit, fn, std::queue<State>());
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Compare = std::less<State> >
void best_first_search(State &init, Visitor &visit, Successor &fn,
                       Compare c = Compare()) {
  tree_search(init, visit, fn, std::priority_queue<State, Compare>(c));
}

/**
 * At each step, the successor returned through fn which maximizes eval, until
 * reaching a node which has no successors.
 */
template<typename State,
         typename Successor,
         typename Evaluator>
void greedy_search(State &state, Successor &fn, Evaluator &eval) {
  typedef typename successor_traits<Successor>::action_type action;
  typedef typename action_traits<action>::delta_type delta;
  typedef typename evaluator_traits<Evaluator>::score_type score;

  while (true) {
    std::vector<action> actions;
    fn(state, std::back_inserter(actions));

    if (actions.empty()) return;

    if (actions.size() == 1) {
      actions[0](state).apply(state);
      continue;
    }

    std::vector<delta> changes(actions.size());

    typename std::vector<action>::const_iterator actions_it;
    typename std::vector<delta>::iterator changes_it;
    for (actions_it = actions.begin(), changes_it = changes.begin();
         actions_it != actions.end(); actions_it++, changes_it++) {
      const action &a = *actions_it;
      *changes_it = a(state);
    }

    std::vector<score> scores(actions.size());

    typename std::vector<score>::iterator scores_it;
    for (changes_it = changes.begin(), scores_it = scores.begin();
         changes_it != changes.end(); changes_it++, scores_it++) {
      const delta &delta = *changes_it;

      delta.apply(state);
      *scores_it = eval(state);
      delta.reverse(state);
    }

    typename std::vector<score>::iterator it =
      std::max_element(scores.begin(), scores.end());

    size_t index = std::distance(scores.begin(), it);
    changes[index].apply(state);
  }
}

template<typename State,
         typename Selector,
         typename Search>
void large_neighborhood_search(State &state, Selector &selector,
                               Search &search, std::size_t time_limit = 100) {
  typedef typename selector_traits<Selector>::fragment_type fragment;
  typedef typename search_traits<Search>::assignment_type assignment;

  /* TODO: Use a monotonic clock instead */
  double start = TimeOfDay();
  while (TimeOfDay() - start < time_limit) {
    fragment fragment(selector(state));
    assignment assignment(search(state, fragment));
    assignment(state, fragment);
  }
}

template<typename Score>
struct mcts_node {
  mcts_node():
    x_1(0), x_2(0), visit_count(0), children(0) {}

  Score x_1, x_2;
  size_t visit_count;

  std::vector<mcts_node> children;

  void update(Score score) {
    x_1 += score;
    x_2 += score*score;
    visit_count++;
  }

  Score ucb1(std::size_t n) const {
    if (visit_count == 0)
      return std::numeric_limits<Score>::max();
    else
      return (x_1/visit_count) + std::sqrt(2*std::log(Score(n))/visit_count);
  }

  class compare_by_ucb1 {
    std::size_t _n;
  public:
    compare_by_ucb1(std::size_t n): _n(n) {}

    bool operator()(const mcts_node<Score> &a, const mcts_node<Score> &b) const {
     return a.ucb1(_n) < b.ucb1(_n);
    }
  };

  struct compare_by_mean {
    bool operator()(const mcts_node<Score> &a, const mcts_node<Score> &b) const {
      return a.x_1 < b.x_1;
    }
  };

  std::size_t best_child(std::size_t n) const {
    typename std::vector<mcts_node>::iterator it =
      std::max_element(children.begin(), children.end(),
                       compare_by_ucb1(n));
    return std::distance(children.begin(), it);
  }

  std::size_t best_move(std::size_t n) const {
    typename std::vector<mcts_node>::iterator it =
      std::max_element(children.begin(), children.end(),
                       compare_by_mean());
    return std::distance(children.begin(), it);
  }
};

/**
 * Runs a single Monte Carlo Simulation as part of a Monte Carlo Tree Search.
 *
 * This operation is done as follows:
 *   1. Explore the tree of statistics (node being a pointer to its root), playing
 *      optimially according to those statistics, until reaching
 *      one of its leaves.
 *   2. Perform a completely random simulation, starting from the leaf found at
 *      the previous step.
 *   3. Update the statistics tree.
 */
template<typename State,
         typename Successor,
         typename Evaluator,
         typename Iterator>
void mcts_simulation(mcts_node<typename evaluator_traits<Evaluator>::score_type> *node,
                     State &state, Successor &fn, Evaluator &eval, size_t n,
                     Iterator action_begin, Iterator action_end) {
  typedef typename successor_traits<Successor>::action_type action;
  typedef typename action_traits<action>::delta_type delta;
  typedef typename evaluator_traits<Evaluator>::score_type score;

  std::vector<action> actions(action_begin, action_end);

  std::vector<mcts_node<score>*> ancestors;
  std::vector<delta> changes;

  ancestors.push_back(node);

  bool selection = true;

  while (!actions.empty()) {
    std::size_t i;

    if (selection && node->children.size() == 0) {
      node->children.resize(actions.size());

      i = rand() % actions.size();

      node = &node->children[i];
      ancestors.push_back(node);

      selection = false;
    }
    else if (selection) {
      i = node->best_child(n);
      node = &node->children[i];
      ancestors.push_back(node);
    }
    else {
      i = rand() % actions.size();
    }

    delta change = actions[i](state);
    changes.push_back(change);

    change.apply(state);

    actions.clear();
    fn(state, std::back_inserter(actions));
  }

  score result(eval(state));

  for (typename std::vector<mcts_node<score>*>::const_iterator it = ancestors.begin();
       it != ancestors.end(); it++) {
    (*it)->update(result);
  }

  for (typename std::vector<delta>::const_iterator it = changes.rbegin();
       it != changes.rend(); it++) {
    (*it).reverse(state);
  }
}

template<typename State,
         typename Successor,
         typename Evaluator>
void monte_carlo_tree_search(State &state, Successor &fn, Evaluator &eval) {
  typedef typename successor_traits<Successor>::action_type action;
  typedef typename evaluator_traits<Evaluator>::score_type score;

  std::vector<action> actions;

  while (true) {
    actions.clear();
    fn(state, std::back_inserter(actions));

    std::cout << "\rscore: " << eval(state);
    std::cout.flush();

    if (actions.empty())
      break;
    else if (actions.size() == 1) {
      actions[0](state).apply(state);
    }
    else {
      mcts_node<score> node;

      size_t i;

      /* TODO: Use a monotonic clock instead */
      double start = TimeOfDay();
      for (i = 0; (TimeOfDay() - start) < 1.0; i++) {
        mcts_simulation(&node, state, fn, eval, i,
                        actions.begin(), actions.end());
      }

      actions[node.best_move(i)](state).apply(state);
    }
  }
}

}

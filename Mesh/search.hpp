#include <vector>
#include <queue>
#include <iterator>
#include <functional>
#include <algorithm>
#include <chrono>

#include <boost/functional.hpp>

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
         typename Successor,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta = typename action_traits<Action>::delta_type>
void depth_first_search(State &init, Visitor &visit, Successor &fn) {
  visit(init);

  std::vector<Action> actions;
  fn(init, std::back_inserter(actions));

  for (const Action &action : actions) {
    Delta change(action(init));

    change.apply(init);
    depth_first_search(init, visit, fn);
    change.reverse(init);
  }
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta = typename action_traits<Action>::delta_type>
void depth_limited_search(State &init, Visitor &visit, Successor &fn,
                          size_t max_depth) {
  visit(init);
  if (max_depth == 0) return;

  std::vector<Action> actions;
  fn(init, std::back_inserter(actions));

  for (const Action &action : actions) {
    Delta change(action(init));

    change.apply(init);
    depth_limited_search(init, visit, fn, max_depth - 1);
    change.reverse(init);
  }
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Queue,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta = typename action_traits<Action>::delta_type>
void tree_search(State &init, Visitor &visit, Successor &fn, Queue q) {
  q.push(init);

  while (!q.empty()) {
    State s = q.top();
    q.pop();

    visit(s);

    std::vector<Action> actions;
    fn(s, std::back_inserter(actions));

    for (const Action &action : actions) {
      State to_add(s);
      action(s).apply(to_add);

      q.push(to_add);
    }
  }
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta = typename action_traits<Action>::delta_type>
void breadth_first_search(State &init, Visitor &visit, Successor &fn) {
  tree_search(init, visit, fn, std::queue<State>());
}

template<typename State,
         typename Visitor,
         typename Successor,
         typename Compare = std::less<State>,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta = typename action_traits<Action>::delta_type>
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
         typename Evaluator,
         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta  = typename action_traits<Action>::delta_type,
         typename Score  = typename evaluator_traits<Evaluator>::score_type>
void greedy_search(State &state, Successor &fn, Evaluator &eval) {
  while (true) {
    std::vector<Action> actions;
    fn(state, std::back_inserter(actions));

    if (actions.empty()) return;

    if (actions.size() == 1) {
      actions[0](state).apply(state);
      continue;
    }

    std::vector<Delta> changes(actions.size());
    std::transform(actions.begin(), actions.end(),
                   changes.begin(), [&](const Action &a) {
                     return a(state);
                   });

    std::vector<Score> scores(actions.size());
    std::transform(changes.begin(), changes.end(),
                   scores.begin(), [&](const Delta &delta) {
                     delta.apply(state);
                     auto result = eval(state);
                     delta.reverse(state);

                     return result;
                   });

    auto it = std::max_element(scores.begin(), scores.end());

    size_t index = std::distance(scores.begin(), it);
    changes[index].apply(state);
  }
}

template<typename State,
         typename Selector,
         typename Search,
         typename Fragment = typename selector_traits<Selector>::fragment_type,
         typename Assigment = typename search_traits<Search>::assignment_type>
void large_neighborhood_search(State &state, Selector &selector,
                               Search &search, size_t fragment_count = 100) {
  for (size_t i = 0; i < fragment_count; i++) {
    Fragment fragment(selector(state));
    Assigment assignment(search(state, fragment));
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

  std::size_t best_child(std::size_t n) const {
    auto it = std::max_element(children.begin(), children.end(),
                               [&](const mcts_node<Score> &a, const mcts_node<Score> &b) {
                                 return a.ucb1(n) < b.ucb1(n);
                               });

    return std::distance(children.begin(), it);
  }
};

/**
 * Runs a single Monte Carlo Simulation as part of a Monte Carlo Tree Search.
 *
 * This operation is done as follows:
 *   1. Explore the seach tree of statistics (described by node), playing
 *      optimially according to those statistics, until reaching
 *      one of its leaves.
 *   2. Perform a completely random simulation, starting from the leaf found at
 *      the previous step.
 *   3. Update the statistics tree.
 */
template<typename State,
         typename Successor,
         typename Evaluator,
         typename Iterator,

         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta  = typename action_traits<Action>::delta_type,
         typename Score  = typename evaluator_traits<Evaluator>::score_type>
void mcts_simulation(mcts_node<Score> *node,
                     State &state, Successor &fn, Evaluator &eval, size_t n,
                     Iterator action_begin, Iterator action_end) {
  std::vector<Action> actions(action_begin, action_end);

  std::vector<mcts_node<Score>*> ancestors;
  std::vector<Delta> changes;

  ancestors.push_back(node);

  bool explore = true;

  while (!actions.empty()) {
    std::size_t i;

    if (explore && node->children.size() == 0) {
      node->children.resize(actions.size());

      i = rand() % actions.size();

      node = &node->children[i];
      ancestors.push_back(node);

      explore = false;
    }
    else if (explore) {
      i = node->best_child(n);
      node = &node->children[i];
      ancestors.push_back(node);
    }
    else {
      i = rand() % actions.size();
    }

    Delta change = actions[i](state);
    changes.push_back(change);

    change.apply(state);

    actions.clear();
    fn(state, std::back_inserter(actions));
  }

  Score score(eval(state));

  for (mcts_node<Score> *node : ancestors)
    node->update(score);

  for (auto it = changes.rbegin(); it != changes.rend(); it++)
    (*it).reverse(state);
}

template<typename State,
         typename Successor,
         typename Evaluator,

         typename Action = typename successor_traits<Successor>::action_type,
         typename Delta  = typename action_traits<Action>::delta_type,
         typename Score  = typename evaluator_traits<Evaluator>::score_type>
void monte_carlo_tree_search(State &state, Successor &fn, Evaluator &eval) {
  std::vector<Action> actions;

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
      using namespace std::chrono;

      mcts_node<Score> node;

      size_t i;

      auto start = steady_clock::now();
      for (i = 0; (steady_clock::now() - start) < 1s; i++) {
        mcts_simulation(&node, state, fn, eval, i,
                        actions.begin(), actions.end());
      }

      actions[node.best_child(i)](state).apply(state);
    }
  }
}

}

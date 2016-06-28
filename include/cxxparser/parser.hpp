#pragma once

#include <type_traits>
#include <utility>

namespace cxxparser {

template <class Child, class Action>
struct action_t;

template <class Child, class Action>
action_t<Child, Action> action (Child && child, Action && act);


/**
 *  root class for 
 */
template <class T>
struct parser_t {

  template <class First ,class Last>
  bool operator() (First && first, Last const & last) {
    return static_cast<T &>(*this)(std::forward<First>(first), last);
  }

  template <class Action>
  action_t<T, Action> operator[] (Action && action) && {
    return action_t<T, Action>(static_cast<T &&>(std::move(*this)), std::forward<Action>(action));
  }
};

}

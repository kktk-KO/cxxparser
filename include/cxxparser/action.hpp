#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

template <class Child, class Action>
struct action_t : public parser_t<action_t<Child, Action>> {
  Child child;
  Action action;

  action_t (Child && child, Action && action)
  : child(std::forward<Child>(child)), action(std::forward<Action>(action)) {
  }

  template <class First ,class Last>
  bool operator() (First && first, Last const & last) {
    if (!child(std::forward<First>(first), last)) {
      return false;
    }
    action(child);
    return true;
  }
};


template <class Child, class Action>
action_t<Child, Action> action (Child && child, Action && act) {
  return action_t<Child, Action>(std::forward<Child>(child), std::forward<Action>(act));
}

}

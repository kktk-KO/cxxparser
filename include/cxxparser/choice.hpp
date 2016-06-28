#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

template <class Left, class Right>
struct choice_t : public parser_t<choice_t<Left, Right>> {
  Left left;
  Right right;

  choice_t (Left && left, Right && right)
  : left(std::forward<Left>(left)), right(std::forward<Right>(right)) {
  }

  template <class First ,class Last>
  bool operator() (First && first, Last const & last) {
    if (left(first, last)) { return true; }
    if (right(first, last)) { return true; }
    return false;
  }
};

template <class Left, class Right>
choice_t<Left, Right> choice (Left && left, Right && right) {
  return choice<Left, Right>(std::forward<Left>(left), std::forward<Right>(right));
}

template <class Left, class Right>
choice_t<Left, Right> operator| (parser_t<Left> && left, parser_t<Right> && right) {
  return choice_t<Left, Right>(
    static_cast<Left &&>(std::forward<parser_t<Left>>(left)),
    static_cast<Right &&>(std::forward<parser_t<Right>>(right))
  );
}

}

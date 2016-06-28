#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

template <class Left, class Right>
struct sequence_t : public parser_t<sequence_t<Left, Right>> {
  Left left;
  Right right;

  template <class First ,class Last>
  bool operator() (First && first, Last const & last) {
    auto tmp = first;
    if (!left(first, last) || !right(first, last)) {
      first = tmp;
      return false;
    }
    return true;
  }
};

template <class Left, class Right>
sequence_t<Left, Right> sequence (Left && left, Right && right) {
  return sequence<Left, Right>(std::forward<Left>(left), std::forward<Right>(right));
}

template <class Left, class Right>
sequence_t<Left, Right> operator>> (parser_t<Left> && left, parser_t<Right> && right) {
  return sequence_t<Left, Right>(
    static_cast<Left &&>(std::forward<parser_t<Left>>(left)),
    static_cast<Right &&>(std::forward<parser_t<Right>>(right))
  );
}

}

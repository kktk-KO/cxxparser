#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

struct char_fixed_t : public parser_t<char_fixed_t> {
  char value;

  char_fixed_t (char value) noexcept
  : value(value) {
  }

  template <class First,class Last>
  bool operator() (First && first, Last const & last) {
    if (first == last) { return false; }
    if (*first != value) { return false; }
    ++first;
    return true;
  }
};

char_fixed_t char_fixed (char value) noexcept {
  return char_fixed_t(value);
}

}

#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

struct char_any_t : public parser_t<char_any_t>{
  char value;

  char_any_t () noexcept {
  }

  template <class First,class Last>
  bool operator() (First && first, Last const & last) {
    if (first == last) { return false; }
    value = *first;
    ++first;
    return true;
  }
};

char_any_t char_any () noexcept {
  return char_any_t();
}

}

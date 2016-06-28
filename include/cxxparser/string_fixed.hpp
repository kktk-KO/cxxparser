#pragma once

#include <cxxparser/parser.hpp>

namespace cxxparser {

struct string_fixed_t : public parser_t<string_fixed_t>{
  char const * value;

  string_fixed_t (char const * value) noexcept
  : value(value) {
  }

  template <class First,class Last>
  bool operator() (First && first, Last const & last) {
    char const * first2 = value;
    auto tmp = first;
    while (first != last && (*first2 != '\0') && (*first == *first2)) {
      ++first;
      ++first2;
    }
    if (*first2 != '\0') {
      first = tmp;
      return false;
    }
    return true;
  }
};

string_fixed_t string_fixed (char const * value) noexcept {
  return string_fixed_t(value);
}

string_fixed_t string (char const * value) noexcept {
  return string_fixed_t(value);
}

}

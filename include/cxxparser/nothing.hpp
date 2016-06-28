#pragma once

namespace cxxparser {

struct nothing_t {

  template <class ... Args>
  void operator() (Args && ... args);

};

}

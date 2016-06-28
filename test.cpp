#include <cxxparser/cxxparser.hpp>

#include <string>
#include <iostream>

int main () {
  using namespace cxxparser;

  std::string line;
  std::getline(std::cin, line);
  auto term =
    string_fixed("aiueo")[([] (string_fixed_t const & t) { std::cout << "aaa" << std::endl; })] |
    string_fixed("bc");
  std::cout << term(line.begin(), line.end()) << std::endl;
}

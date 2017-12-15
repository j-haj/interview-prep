#include <iostream>
#include <vector>

#include "sort.h"

template <typename T>
void print_v(const std::vector<T>& v) {
  for (const auto& x : v) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main(int argc, char* argv[]) {

  std::vector<int> v {6, 5, 4, 3, 2, 1};
  std::cout << "The unsorted vector is: ";
  print_v(v);
  std::cout << "Attempting to sort...\n";
  mergesort(v.begin(), v.end());
  std::cout << "Sorting finished. The sorted vector is: ";
  print_v(v);
  return 0;
}

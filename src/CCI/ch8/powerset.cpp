#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::set<std::set<T>> powerset(const std::vector<T>& elements) {
  std::set<std::set<T>> result;
  for (int i = 0; i < (1 << elements.size()); ++i) {
    std::set<T> current_subset;
    for (int j = 0; j < elements.size(); ++j) {
      if (i & (1 << j)) current_subset.insert(elements[j]);
    }
    result.insert(current_subset);
  }
  return result;
}

template <typename T>
void set_printer(const std::set<T>& s) {
  std::cout << "set size: " << s.size() << ' ';
  for (const auto& x : s) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

template <typename T>
void print_subsets(const std::set<std::set<T>>& s) {
  for (const auto& x : s) {
    set_printer(x);
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v = {1, 2, 3, 4};
  auto subsets = powerset(v);
  print_subsets(subsets);

  return 0;
}

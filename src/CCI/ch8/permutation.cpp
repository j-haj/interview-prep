#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int fact_helper(int n, int agg) {
  if (n == 1) return agg;
  return fact_helper(n - 1, n * agg);
}

int factorial(int n) {
  if (n == 0) return 0;
  return fact_helper(n, 1);
}

void permutation_helper(std::string s, std::size_t idx, std::vector<std::string>& agg) {
  if (idx == s.size() - 1) {
    agg.push_back(s);
    return;
  }
  for (int i = idx; i < s.size(); ++i) {
    std::swap(s[idx], s[i]);
    permutation_helper(s, idx + 1, agg);
    std::swap(s[idx], s[i]);
  }
}

std::vector<std::string> permutation(std::string s) {
  std::vector<std::string> permutations;
  permutations.reserve(factorial(s.size()));
  permutation_helper(s, 0, permutations);
  return permutations;
}

template <typename T>
void print_v(const std::vector<T>& v) {
  for (const auto& x : v) {
    std::cout << x << '\n';
  }
}

int main(int argc, char* argv[]) {
  auto s = "abcd";
  auto result = permutation(s);
  print_v(result);
  std::cout << "Printed " << result.size() << '\n';
  return 0;
}

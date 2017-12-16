#include <iostream>
#include <string>
#include <vector>

int fact_helper(int n, int agg) {
  if (n == 1 || n == 0) return 1;
  return fact_helper(n - 1, n * agg);
}

int factorial(int n) {
  return fact_helper(n, 1);
}

/**
 * Recursively computes the permutations of `s`. `i` is the current "swap" index
 * and is used to swap each character of `s` after index `i`. After each swap is
 * made, recursively call `permutation_helper`
 *
 * @param s input string that is being permuted
 * @param i current swap index
 * @param perms a vector containing the permutations
 *
 * @note the result is return through `perms`
 */
void permutation_helper(std::string s, size_t i, std::vector<std::string>& perms) {
  if (i == s.size()) return;
  else if (i == s.size() - 2) {
    perms.push_back(s);
    std::swap(s[i], s[i+1]);
    perms.push_back(s);
    return;
  }
  for (size_t j = i; j < s.size(); ++j) {
    std::swap(s[i], s[j]);
    permutation_helper(s, i + 1, perms);
    std::swap(s[i], s[j]);
  }
}


/**
 * Computes permutations via the permutation helper function
 * `permutaiton_helper`
 *
 * @param s string used as the basis for the permutations
 */
std::vector<std::string> permutations(std::string s) {
  std::vector<std::string> perms;
  perms.reserve(factorial(s.size()));
  permutation_helper(s, 0, perms);
  return perms;
}

template <typename T>
void print_vector(const std::vector<T>& v) {
  for (const auto& x : v) {
    std::cout << x << '\n';
  }
}

int main(int argc, char* argv[]) {
  std::string s = "abcde";
  auto res = permutations("abcde");
  print_vector(res);
  std::cout << "Generated " << res.size() << " number of permutations\n"
            << "Expected " << factorial(s.size()) << " number of permutations\n";
  return 0;
}

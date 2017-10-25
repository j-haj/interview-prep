#include <iostream>
#include <random>
#include <vector>

/**
 * Generate a random integer between low and high
 *
 * @param low low end of distribution range
 * @param high high end of distribution range
 *
 * @returns randomly sample integer
 */
int random_int(int low, int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Returns a vector of size `n` with elements randomly picked from a uniform
 * distribution randing from -100 to 100.
 *
 * @param n size of vector returned
 *
 * @returns vector with `n` randomly chosen elements
 */
std::vector<int> random_sequence(const size_t n) {
  std::vector<int> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = random_int(-100, 100);
  }
  return v;
}

// Helper function that prints given vector
template <typename T>
void print_vector(const std::vector<T>& v) {
  std::cout << "[ ";
  for (auto& x : v) {
    std::cout << x << " ";
  }
  std::cout << "]\n";
}

template <typename T>
std::vector<T> max_subsequence(const std::vector<T>& v) {
  std::vector<T> partial_sums(v.size());
  for (size_t i = 0; i < v.size(); ++i) {
    partial_sums[i] = i == 0 ? v[i] : v[i] + partial_sums[i - 1];
  }
  // Find max sum
  size_t max_idx = 0;
  size_t min_idx = 0;
  T max_seen;
  T min_seen;
  for (size_t i = 0; i < partial_sums.size(); ++i) {
    
  }
}

int main(int argc, char* argv[]) {
  auto v = random_sequence(10);
  print_vector(v);
  return EXIT_SUCCESS;
}

#include <iostream>
#include <limits>
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
  if (v.size() == 1) { return v; }

  // Find max sum
  size_t max_idx = 0;
  size_t min_idx = 0;
  size_t current_min_idx = 0;
  T max_so_far {std::numeric_limits<T>::min()};
  T max_seen {std::numeric_limits<T>::min()};
  T prior_max_seen {std::numeric_limits<T>::min()};

  for (size_t i = 1; i < v.size(); ++i) {
    max_so_far = std::max(max_so_far, max_so_far + v[i]);
    prior_max_seen = max_seen;
    max_seen = std::max(max_seen, max_so_far);
    if (prior_max_seen != max_seen) {
      max_idx = i;
      min_idx = current_min_idx;
    }
  }

  return std::vector<T>(v.begin() + min_idx, v.begin() + max_idx);
}

int main(int argc, char* argv[]) {
  auto v = random_sequence(10);
  print_vector(v);
  auto res = max_subsequence(v);
  print_vector(res);
  return EXIT_SUCCESS;
}

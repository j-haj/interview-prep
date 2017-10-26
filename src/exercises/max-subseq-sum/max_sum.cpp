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
  std::vector<T> partial_sums(v.size());
  for (size_t i = 0; i < v.size(); ++i) {
    partial_sums[i] = i == 0 ? v[i] : v[i] + partial_sums[i - 1];
  }
  // Find max sum
  size_t max_idx = 0;
  size_t min_idx = 0;
  size_t min_sofar_idx = 0;
  T max_seen {std::numeric_limits<T>::max()};
  T min_seen {std::numeric_limits<T>::min()};
  T min_seen_sofar {std::numeric_limits<T>::min()};
  for (size_t i = 0; i < partial_sums.size(); ++i) {
    if (partial_sums[i] > max_seen) {
      max_idx = i;
      max_seen = partial_sums[i];
      if (i > min_sofar_idx) {
        min_seen = min_seen_sofar;
        min_idx = min_sofar_idx;
      }
    } else if (partial_sums[i] < min_seen) {
      min_sofar_idx = i;
      min_seen_sofar = partial_sums[i];
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

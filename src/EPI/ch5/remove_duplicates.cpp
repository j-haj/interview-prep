#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * Returns a vector of length at most `v.size()` with the same elements as `v`
 * but with duplicates removed. `v` is modified so that all unique elements come
 * first.
 *
 * Precondition: `v` should be sorted
 *
 * @param v sorted vector whose duplicate values should be removed
 *
 * @return a vector with the same elements as `v` but with no duplicates
 */
template <typename T>
std::vector<T> remove_duplicates(std::vector<T>& v) {
  T current_val {v[0]};
  size_t swap_idx {1};
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] != current_val && i > swap_idx) {
      current_val = v[i];
      std::swap(v[swap_idx], v[i]);
      ++swap_idx;
    }
  }
  return std::vector<T>(v.begin(), v.begin() + swap_idx);
}

/**
 * Returns a vector of length at most `v.size()` with the same elements as `v`
 * but with duplicates removed. `v` is modified so that all unique elements come
 * first.
 *
 * Precondition: `v` should be sorted
 *
 * @param v sorted vector whose duplicate values should be removed
 *
 * @return a vector with the same elements as `v` but with no duplicates
 */
template <typename T>
std::vector<T> copy_uniques(const std::vector<T>& v) {
  std::vector<T> tmp(v.size());
  bool is_first = true;
  T prior_val;
  size_t num_unique{0};
  auto tmp_last = std::copy_if(v.begin(), v.end(), tmp.begin(),
      [&](const T& val) {
        if (is_first) {
          prior_val = val;
          is_first = false;
          return true;
        }
        if (val != prior_val) {
          prior_val = val;
          return true;
        }
        return false;
      });
  return std::vector<T>(tmp.begin(), tmp_last);
}

// Helper function for printing std::vector
template <typename T>
std::string vec_to_str(const std::vector<T>& v) {
  std::stringstream ss;
  ss << "[ ";
  for (const auto& x : v) {
    ss << x << " ";
  }
  ss << "]";
  return ss.str();
}

int main(int argc, char* argv[]) {
  std::vector<int> v1 {1, 1, 1, 3, 4, 5, 5, 5, 8, 8, 10};
  auto v2 = copy_uniques(v1);
  std::cout << "Original vector: " << vec_to_str(v1) << '\n';

  std::cout << "Updated vector: " << vec_to_str(v2) << '\n';


  return EXIT_SUCCESS;
}

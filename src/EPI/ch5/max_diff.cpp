#include <iostream>
#include <limits>
#include <vector>

/**
 * Returns the maximum difference between the elements of
 * |values| where the lower value must come before the higher value.
 *
 * @param values vector of doubles
 *
 * @return maximum difference achievable in the vector
 */
double max_diff(const std::vector<double>& values) {
  double min = std::numeric_limits<double>::max();
  double diff{0.0};
  for (const auto& x : values) {
    auto cur_diff = x - min;
    diff = std::max(diff, cur_diff);
    min = std::min(x, min);
  }
  return diff;
}

/**
 * Returns the total max difference, defined as the sum of two max diffs that
 * must come from disjoint sub-vectors, of the given values.
 *
 * @param values vector of values used to compute the double max diff
 *
 * @return sum of two disjoint max diffs from within |values|
 */
double double_max_diff(const std::vector<double>& values) {
  std::vector<double> first_diff(values.size());
  double min = std::numeric_limits<double>::max();
  double diff{0};
  for (auto i = 0; i < values.size(); ++i) {
    diff = std::max(diff, values[i] - min);
    min = std::min(values[i], min);
    first_diff[i] = diff;
  }

  // Now iterate through |values| in reverse
  double max_tot_diff{0};
  double max_so_far = std::numeric_limits<double>::min();
  for (auto i = 0; i < values.size(); ++i) {
    max_so_far = std::max(max_so_far, values[values.size() - i - 1]);
    max_tot_diff = std::max(max_tot_diff,
        max_so_far - values[values.size() - i - 1] + first_diff[values.size() - i - 1]);
  }
  return max_tot_diff;
}

int main(int argc, char* argv[]) {

  std::vector<double> v1 {1.2, 3, 9.8, 0, 10.0};
  std::vector<double> v2 {1.1, 11.3, 0.2, 8.9};
  std::cout << "Max diff for v1 is " << max_diff(v1) << " expected is 10.0\n";
  std::cout << "Max diff for v2 is " << max_diff(v2) << " expected is 10.2\n";
  std::cout << "Max double diff for v1 is " << double_max_diff(v1) << " expected is 18.6\n";
  return EXIT_SUCCESS;
}

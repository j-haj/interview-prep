#include <cstddef>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
#include <sstream>

// Considerations:
// 1. What if the input is empty? should depend on context probably
// 2. What type of inputs should we expect? assume addable and comparable types
// 3. What if the input is large?
// 4. What is the input contains a single element? return that element

/**
 * Computes the maximal sum from a subsequence contained in `v`
 *
 * @param v vector of Ts whose maximal subsequence sum will be found
 * @return maximal subsequence sum
 */
template <typename T>
T max_subseq_sum(const std::vector<T>& v) {
  T max_seen {std::numeric_limits<T>::min()};
  T current_max {max_seen};
  for (const auto& x : v) {
    current_max = current_max == std::numeric_limits<T>::min() ? x : std::max(x, current_max + x);
    max_seen = std::max(current_max, max_seen);
  }
  return max_seen;
}

/**
 * Helper function that converts the given vector into a strin representation of
 * the form:
 *  [ x_1 x_2 ... x_n ]
 */
template <typename T>
std::string vec_to_str(const std::vector<T>& v) {
  std::ostringstream ss;
  ss << "[ ";
  for (const auto& x : v) {
    ss << x << ' ';
  }
  ss << ']';
  return ss.str();
}

// Test cases
void run_tests() {

  std::unordered_map<int, std::vector<int>> test_cases = {
    {1, {1}}, {6, {1, 2, 3}}, {12, {1, 9, -11, 3, 4, 5}},
    {-5, {-10, -5, -7, -8}}
  };
  for (const auto& test_case : test_cases) {
    auto expected = test_case.first;
    auto actual = max_subseq_sum(test_case.second);
    std::string result = expected == actual ? "[PASS] " : "[FAIL] ";
    std::cout << result << "Test case: " << vec_to_str(test_case.second)
              << "\n\tExpected: " << expected << "\n\tGot: " << actual << '\n';
  }
}

int main(int argc, char* argv[]) {
  run_tests();
  return 0;
}

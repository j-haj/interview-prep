#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>

bool is_reachable_helper(const std::vector<size_t>& v, const size_t pos) {
  const size_t moves = v[pos];
  if (moves + pos >= v.size() - 1) {
    return true;
  } else if (pos == v.size() - 1) {
    return false;
  }
  for (size_t i = 1; i <= moves; ++i) {
    bool local_res = is_reachable_helper(v, pos + i);
    if (local_res) {
      return true;
    }
  }
  return false;
}

bool is_reachable(const std::vector<size_t>& v) {
  return is_reachable_helper(v, 0);
}

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

void test_cases() {
  std::vector<size_t> v1{3, 3, 1, 0, 2, 0, 1};
  std::vector<size_t> v2{3, 2, 0, 0, 2, 0, 1};
  std::vector<size_t> v3{2, 4, 1, 1, 0, 2, 3};

  std::unordered_map<std::string, std::pair<std::vector<size_t>, bool>> test_cases {
    {vec_to_str(v1), {v1, true}},
    {vec_to_str(v2), {v2, false}},
    {vec_to_str(v3), {v3, true}}
  };
  for (const auto& test_case : test_cases) {
    const bool actual = is_reachable(test_case.second.first);
    const bool expected = test_case.second.second;
    const std::string actual_str = actual ? "true" : "false";
    const std::string expected_str = expected ? "true" : "false";
    std::string result = expected == actual ? "[PASS]" : "[FAIL]";
    std::cout << result << " for test case: " << test_case.first << '\n';
    std::cout << "\tExpected: " << expected_str << "\n\tActual: " << actual_str << '\n';
  }
}
int main(int argc, char* argv[]) {
  test_cases();
  return EXIT_SUCCESS;
}

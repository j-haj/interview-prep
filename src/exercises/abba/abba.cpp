#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>

std::string can_obtain(const std::string& initial, const std::string& target) {

  if (initial == target) {
    return "Possible";
  }
  auto loc = target.find(initial);
  std::string initial_rev(initial.rbegin(), initial.rend());
  auto loc_rev = target.find(initial_rev);
  if (loc == std::string::npos && loc_rev == std::string::npos) {
    return "Impossible";
  }

  auto result = can_obtain(initial + "A", target);
  if (result == "Possible") {
    return "Possible";
  }

  result = can_obtain(initial_rev + "B", target);
  return result;
}

void run_tests() {

  std::unordered_map<std::string, std::pair<std::string, std::string>> test_cases = {
    {"abb", std::make_pair("ab", "Impossible")},
    {"ababababb", std::make_pair("bbab", "Impossible")},
    {"BBBBABABBABBBBBBABABBBBBBBBABAABBBAA",
      std::make_pair("BBBBABABBBBBBA", "Possible")}
  };

  for (auto& x : test_cases) {
    auto target = x.first;
    std::string initial, expected;
    std::tie(initial, expected) = x.second;
    auto result = can_obtain(initial, target);
    std::string res_str = expected == result ? "[PASS]" : "[FAIL]";
    std::cout << res_str << " Test case: " << initial << " -> " << target
              << "\n\tActual: " << result << "\n\tExpected: " << expected << '\n';
  }
}

int main(int argc, char* argv[]) {

  run_tests();

  return EXIT_SUCCESS;
}

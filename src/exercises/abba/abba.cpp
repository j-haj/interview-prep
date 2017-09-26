#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>

std::string can_obtain(const std::string& initial, const std::string& target) {

  if (initial == target) {
    return "Possible";
  }
  auto loc = target.find(initial);
  if (loc == std::string::npos) {
    return "Impossible";
  }

  auto result = can_obtain(initial + "A", target);
  if (result == "Possible") {
    return "Possible";
  }

  std::string initial_rev(initial.rbegin(), initial.rend());
  result = can_obtain(initial_rev + "B", target);
  return result;
}

void run_tests() {

  std::unordered_map<std::pair<std::string, std::string>, std::string> test_cases = {
    {std::make_pair("ab", "abb"), "Impossible"},
    {std::make_pair("bbab", "ababababb"), "Impossible"},
    {std::make_pair("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"),
      "Possible"}
  };

  for (auto& x : test_cases) {
    std::string initial, target;
    std::tie(initial, target) = x.first;
    auto expected = x.second;
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

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

size_t size_of_longest_subseq(const std::string& s) {
  size_t max_seen = 0;
  auto tracker = std::set<char>();
  for (size_t i = 0; i < s.size(); ++i) {
    auto it = tracker.find(s[i]);
    if (it != tracker.end()) {
      // Found element -- need to start over
      if (tracker.size() > max_seen) {
        max_seen = tracker.size();
      }
      tracker.clear();
    } else {
      tracker.insert(s[i]);
    }
  }
  return max_seen;
}

void run_test_cases() {
  std::unordered_map<std::string, size_t> test_cases = {
    {"abab", 1},
    {"abc", 3},
    {"c", 1},
    {"abca", 3},
    {"ababc", 3},
    {"abcdaf", 5}
  };

  for (const auto& x : test_cases) {
    size_t actual = size_of_longest_subseq(x.first);
    size_t expected = x.second;
    std::string result = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << result << " Test case: " << x.first << '\n';
    std:: cout << "\tActual: " << actual << "\n\tExpected: " << expected << std::endl;
  }
}

int main(int argc, char* argv[]) {
  run_test_cases();
  return EXIT_SUCCESS;
}

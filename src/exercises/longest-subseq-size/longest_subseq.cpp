#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>

/**
 * Problem Description:
 * Find the longest subsequence with no repeating characters in the given
 * string.
 */
std::string longest_subsequence(const std::string& s) {
  auto tracker = std::set<char>();
  std::string max_subseq;
  std::string cur_subseq;

  for (auto c : s) {
    auto it = tracker.find(c);
    if (it != tracker.end()) {
      // Found repeat
      if (cur_subseq.size() > max_subseq.size()) {
        max_subseq = cur_subseq;
      }
      cur_subseq.erase(0, 1);
    } else {
      tracker.insert(c);
    }
    cur_subseq += c;
  }
  if (cur_subseq.size() > max_subseq.size()) {
    max_subseq = cur_subseq;
  }
  return max_subseq;
}

/**
 * Problem Description:
 * Determine the length of the longest subsequence with no
 * repeated characters. Note that we don't need to know the actual subsequence
 * in this case, only how long it is.
 */
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
    } else {
      tracker.insert(s[i]);
    }
  }
  // Check tracker size one last time
  if (tracker.size() > max_seen) {
    max_seen = tracker.size();
  }
  return max_seen;
}

void run_size_test_cases() {
  std::unordered_map<std::string, size_t> test_cases = {
    {"abab", 2},
    {"abc", 3},
    {"c", 1},
    {"abca", 3},
    {"ababc", 3},
    {"abcdaf", 5},
    {"", 0}
  };

  for (const auto& x : test_cases) {
    size_t actual = size_of_longest_subseq(x.first);
    size_t expected = x.second;
    std::string result = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << result << " Test case: " << x.first << '\n';
    std:: cout << "\tActual: " << actual << "\n\tExpected: " << expected << std::endl;
  }
}

void run_subseq_test_cases() {
  std::unordered_map<std::string, std::string> test_cases = {
    {"abab", "ab"},
    {"abc", "abc"},
    {"c", "c"},
    {"abca", "abc"},
    {"ababc", "abc"},
    {"abcdaf", "bcdaf"},
    {"", ""}
  };

  for (const auto& x : test_cases) {
    std::string actual = longest_subsequence(x.first);
    std::string expected = x.second;
    std::string result = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << result << " Test case: " << x.first << '\n';
    std:: cout << "\tActual: " << actual << "\n\tExpected: " << expected << std::endl;
  }
}

int main(int argc, char* argv[]) {
  std::cout << "Size tests\n";
  run_size_test_cases();
  std::cout << "\nSubsequence tests\n";
  run_subseq_test_cases();
  return EXIT_SUCCESS;
}

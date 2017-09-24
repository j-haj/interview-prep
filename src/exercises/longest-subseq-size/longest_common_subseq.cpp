#include <iostream>
#include <map>
#include <vector>

/**
 * Returns the longest common substring between two strings
 *
 * @param a first string
 * @param b seconds string
 *
 * @return longest shared string between a and b, empty string if they share no
 * common substring.
 */
std::string longest_common_substring(const std::string& a, const std::string& b) {
  std::vector<int> current_row(b.size());
  std::vector<int> prior_row(b.size());

  for (auto i = 0; i < a.size(); ++i) {
    for (auto j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) {
        if (i == 0 || j == 0) {
          current_row[j] = 1;
        } else {
          current_row[j] = prior_row[j - 1];
        }
      }
    }
    prior_row.swap(current_row);
  }
  for (auto& x : current_row) {
    std::cout << x << ",";
  }
  std::cout << std::endl;
  return "";
}

/**
 * Runs test cases
 */
void run_tests() {
  // Tests
  std::map<std::string, std::pair<std::string, std::string>> test_cases = {{"aba", std::make_pair("abab", "baba")}};

  // Run
  for (auto& x : test_cases) {
    auto expected = x.first;
    std::string lhs, rhs;
    std::tie(lhs, rhs) = x.second;
    auto actual = longest_common_substring(lhs, rhs);
    auto result = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << result << " Test case: (" << lhs << ", " << rhs << ")\n";
    std::cout << "\tActual: " << actual << "\n\tExpected: " << expected << '\n';
  }
}

// MAIN
int main(int argc, char* argv[]) {

  run_tests();

  return EXIT_SUCCESS;
}

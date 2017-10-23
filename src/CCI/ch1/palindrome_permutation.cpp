#include <iostream>
#include <string>
#include <unordered_map>

// Helper function for debugging
template <typename T, typename V>
void print_map(const std::unordered_map<T, V>& m) {
  std::cout << "{\n";
  for (const auto& x : m) {
    std::cout << "\t" << x.first << " : " << x.second << '\n';
  }
  std::cout << "}\n";
}

// Note: we don't actually need this for this problem but I'm leaving it in
/**
 * Determines if the given input is a palindrome.
 *
 * @param s candidate word
 *
 * @return `true` if input is a palindrome, `false` otherwise
 */
bool is_palindrome(const std::string& s) {
  const std::string rev_s(s.rbegin(), s.rend());
  return rev_s == s;
}

void test_is_palindrome() {
  const std::unordered_map<std::string, bool> test_cases = {
      {"racecar", true}, {"hello", false},
  };

  for (const auto& x : test_cases) {
    auto val = x.first;
    bool expected = x.second;
    bool actual = is_palindrome(val);
    std::string res = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << res << " test case: " << val << '\n';
    if (actual != expected) {
      std::cout << "\tExpect: " << expected << '\n';
      std::cout << "\tGot: " << actual << '\n';
    }
  }
}

/**
 * Determines if the given string can be permuted into a palindrome
 *
 * @param s input string
 *
 * @return `true` if the string can be permuted into a palindrome, `false`
 * otherwise.
 */
bool contains_palindrome(const std::string& s) {
  std::unordered_map<char, int> frequencies;

  // Get character frequencies
  for (const char c : s) {
    if (c == ' ') continue;
    auto p = frequencies.find(c);
    if (p != frequencies.end()) {
      const auto v = frequencies[c];
      frequencies[c] = v + 1;
    } else {
      frequencies.insert({c, 1});
    }
  }

  // Analyze characters - we can have at most one character with an odd
  // frequency only if the word has an odd number of characters
  int num_keys{0};
  int n_odd_frequencies{0};
  for (const auto& x : frequencies) {
    num_keys += x.second;
    if (x.second % 2 == 1) {
      ++n_odd_frequencies;
    }
    // Exit early if we know it is not a palindrome
    if (n_odd_frequencies > 1) break;
  }
  const bool even_keys = num_keys % 2 == 0;
  return (even_keys && (n_odd_frequencies == 0)) ||
         (!even_keys && (n_odd_frequencies == 1));
}

void test_contains_palindrome() {
  std::unordered_map<std::string, bool> test_cases = {
    {"taco cat", true},
    {"hello there", false},
    {"race car", true}
  };

  for (const auto& x : test_cases) {
    const auto test_case = x.first;
    const auto expected = x.second;
    const auto actual = contains_palindrome(test_case);
    std::string res = actual == expected ? "[PASS]" : "[FAIL]";

    std::cout << res << " for test case: " << test_case << '\n';
    if (actual != expected) {
      std::cout << "\tExpected: " << expected << '\n'
                << "\tGot: " << actual << '\n';
    }
  }
}

int main(int argc, char* argv[]) {
  test_is_palindrome();
  test_contains_palindrome();
  return EXIT_SUCCESS;
}

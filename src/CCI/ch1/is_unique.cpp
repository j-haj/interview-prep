#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

bool is_unique_nomap(const std::string& s) {
  std::vector<int> frequencies(26);
  const int offset = 97;
  for (const char& c : s) {
    int idx = static_cast<int>(std::tolower(c)) - offset;
    if (frequencies[idx] == 0) {
      frequencies[idx] = 1;
    } else {
      return false;
    }
  }
  return true;
}

bool is_unique(const std::string& s) {
  std::unordered_map<char, short> frequencies = std::unordered_map<char, short>();
  for (const char& c : s) {
    auto loc = frequencies.find(std::tolower(c));
    if (loc != frequencies.end()) {
      return false;
    } else {
      frequencies[std::tolower(c)] = 1;
    }
  }
  return true;
}

void run_tests() {
  std::unordered_map<std::string, bool> test_cases = {
    {"apple", false},
    {"orange", true},
    {"asdfghjklmqwerty", true},
    {"Alphabet", false}
  };

  for (const auto& p : test_cases) {
    auto word = p.first;
    auto expected_uniqueness = p.second;
    auto actual_uniqueness = is_unique(word);
    auto res = (expected_uniqueness == actual_uniqueness) ? "[PASS]" : "[FAIL]";
    std::cout << res << " word: " << word << '\n';
  }
}

void run_tests_nomap() {
  std::unordered_map<std::string, bool> test_cases = {
    {"apple", false},
    {"orange", true},
    {"asdfghjklmqwerty", true},
    {"Alphabet", false}
  };

  for (const auto& p : test_cases) {
    auto word = p.first;
    auto expected_uniqueness = p.second;
    auto actual_uniqueness = is_unique_nomap(word);
    auto res = (expected_uniqueness == actual_uniqueness) ? "[PASS]" : "[FAIL]";
    std::cout << res << " word: " << word << '\n';
  }
}

int main(int argc, char* argv[]) {
  std::cout << "Using std::unordered_map\n";
  run_tests();
  std::cout << "Without using std::unordered_map\n";
  run_tests_nomap();
  return EXIT_SUCCESS;
}

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

bool IsApproximatePalindrome(const std::string& s) {
  std::size_t low = 0;
  std::size_t high = s.size() - 1;

  std::vector<std::pair<std::size_t, std::size_t>> restart;
  while (low < high) {
    if (s[low] != s[high]) {
      if (restart.size() > 1)
        return false;
      else if (!restart.empty()) {
        std::tie(low, high) = restart.front();
        restart.push_back(std::make_pair(low, high));
        --high;
        continue;
      } else {
        restart.push_back(std::make_pair(low, high));
        ++low;
        continue;
      }
    }
    ++low;
    --high;
  }
  return true;
}

void RunTests() {
  std::unordered_map<std::string, bool> test_cases = {
      {"racecar", true}, {"racetcar", true}, {"apple", false}};
  for (const auto& test_case : test_cases) {
    auto actual = IsApproximatePalindrome(test_case.first);
    auto expected = test_case.second;
    if (actual != expected) {
      std::cout << "[FAIL] : IsApproximatePalindrome(" << test_case.first << ")"
                << " = " << actual << " expected " << expected << std::endl;
    } else {
      std::cout << "[PASS] : IsApproximatePalindrome(" << test_case.first << ")"
                << " = " << actual << std::endl;
    }
  }
}

int main(int argc, char** argv) {
  RunTests();
  return 0;
}

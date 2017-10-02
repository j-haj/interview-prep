#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

namespace utility {
int ctoi(char c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default:
      std::stringstream ss;
      ss << "Invalid argument (" << c << ") - must be a valid integer";
      throw std::invalid_argument(ss.str());
  }
}

int atoi(const std::string& s) {
  int result {0};
  size_t index = s.size() - 1;
  size_t size = s.size();
  while (index > 0) {
    char c = s[index];
    int scaler = pow(10, size - index - 1);
    int tmp = ctoi(c);
    --index;
    result += scaler * tmp;
  }
  if (s[index] == '-') {
    result *= -1;
  } else {
    result += pow(10, size - index - 1) * ctoi(s[index]);
  }
  return result;
}
}

void run_tests() {

  std::unordered_map<std::string, int> test_cases = {
    {"1", 1},
    {"12", 12},
    {"101", 101},
    {"10101010", 10101010},
    {"-842", -842}
  };

  for (const auto& x : test_cases) {

    std::string test_case = x.first;
    int expected = x.second;
    int actual = utility::atoi(test_case);
    std::string res = actual == expected ? "[PASS]" : "[FAIL]";
    std::cout << res << "  Expected: " << expected << "  Got: " << actual << '\n';
  }

}

int main(int argc, char* argv[]) {
  run_tests();
  return 0;
}

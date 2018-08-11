#include <iostream>
#include <functional>
#include <unordered_set>
#include <string_view>

enum class Type { Odd, Even, All };

bool check_equiv(std::string_view s1, std::string_view s2, Type t) {
  std::unordered_set<char> chars1;
  std::unordered_set<char> chars2;

  auto checker = [&t](std::string_view s, std::unordered_set<char>& cs, std::size_t i) {
    switch (t) {
      case Type::Odd:
        if (i % 2 == 1) cs.insert(s[i]);
        break;
      case Type::Even:
        if (i % 2 == 0) cs.insert(s[i]);
        break;
      default:
        cs.insert(s[i]);
    }
  };

  for (std::size_t i = 0; i < s1.size(); ++i) {
    checker(s1, chars1, i); 
  }
  for (std::size_t i = 0; i < s2.size(); ++i) {
    checker(s2, chars2, i);
  }

  return chars1 == chars2;
}

bool can_swap(std::string_view s1, std::string_view s2) {
  return s1.size() == s2.size() && check_equiv(s1, s2, Type::Even) && check_equiv(s1, s2, Type::Odd);
}

void CHECK(std::string_view s1, std::string_view s2, bool expected) {
  std::cout << (can_swap(s1, s2) == expected ? "[PASS]" : "[FAIL]") << " : for " << s1 << " and " << s2 << std::endl;
}

int main() {
  CHECK("cdab", "abcd", true);
  CHECK("dcba", "abcd", false);
  CHECK("ab", "abs", false);
  CHECK("", "", true);
  CHECK("\0\0\0", "\0\0\0", true);
  return 0;
}

#include <iostream>
#include <string>

bool valid_parens(const std::string& s) {
  int count {0};
  bool went_negative {false};
  for (const auto& c : s) {
    switch (c) {
      case ')':
        --count;
        if (count < 0) went_negative = true;
        break;
      case '(':
        ++count;
        break;
    }
  }
  return !went_negative && count == 0;
}

int main(int argc, char* argv[]) {

  if (!valid_parens(")(")) std::cout << "pass: )(\n";
  if (!valid_parens("(()")) std::cout << "pass: (()\n";
  if (valid_parens("(()())")) std::cout << "pass: (()())\n";
  return 0;
}

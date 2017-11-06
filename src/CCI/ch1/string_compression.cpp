#include <iostream>
#include <string>

/**
 * Compresses the input string by representing repeated characters
 * using the pattern <char><count>
 *
 * @param s input string
 *
 * @return compressed string
 */
std::string compress(const std::string& s) {
  char prior_char {'\0'};
  size_t char_count {0};
  std::string output {""};
  for (auto& c : s) {
    if (c != prior_char && prior_char != '\0') {
      output += prior_char + (char_count > 1 ? std::to_string(char_count) : "");
      char_count = 1;
      prior_char = c;
    } else if (prior_char == '\0') {
      prior_char = c;
      char_count = 1;
    } else {
      ++char_count;
    }
  }
  output += prior_char + std::to_string(char_count);
  return output;
}

int main(int argc, char* argv[]) {
  auto test = "aabbbcdddd";
  std::cout << "Compressing: " << test << '\n';
  std::cout << compress(test) << '\n';
  return EXIT_SUCCESS;
}

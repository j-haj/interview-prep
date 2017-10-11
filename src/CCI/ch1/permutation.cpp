#include <iostream>
#include <string>
#include <unordered_map>

/**
 * Creates a map of characters and frequencies for the given string
 *
 * @param s input string
 *
 * @return a std::unordered_map<char, int> of the characters and frequencies of
 *         `s`
 */
std::unordered_map<char, int> get_frequency_map(const std::string& s) {
  std::unordered_map<char, int> f_map = std::unordered_map<char, int>();
  for (const char& c : s) {
    auto loc = f_map.find(c);
    if (loc != f_map.end()) {
      f_map[c] += 1;
    } else {
      f_map[c] = 1;
    }
  }
  return f_map;
}

/**
 * Determines if the given inputs are permutations of eachother.
 * This is done by counting characters and comparing their
 * frequencies.
 *
 * @param s1 one of the strings being compared
 * @param s2 the other string being compared
 *
 * @return `true` if the strings are permutations of eachother, `false`
 *          otherwise.
 */
bool is_permutation(const std::string& s1, const std::string& s2) {
  auto f1 = get_frequency_map(s1);
  auto f2 = get_frequency_map(s2);
  return f1 == f2;
}



int main(int argc, char* argv[]) {

  std::string s1 = "apple";
  std::string s2 = "paple";
  std::string res = is_permutation(s1, s2) ? "[PASS]" : "[FAIL]";
  std::cout << "Result for 'apple' and 'paple' is " << res << '\n';
  return EXIT_SUCCESS;
}

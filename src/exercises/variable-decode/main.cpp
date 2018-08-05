#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Encode string A -> 1, B -> 2, etc.
std::string encode_string(const std::string_view s) {
  std::vector<char> char_vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::unordered_map<char, int> chars;
  int val = 1;
  for (const auto c : char_vec) chars[c] = val++;
  std::stringstream ss;
  for (const auto c : s) ss << chars[c];
  return ss.str();
}

// Convert a vector of chars to a string
std::string vec_to_string(const std::vector<char>& v) {
  std::stringstream ss;
  std::for_each(v.begin(), v.end(), [&ss](char c) { ss << c; });
  return ss.str();
}

// Convert a char array numbers of type char to their corresponding char based
// on the encoding 1 -> A, 2 -> B, etc.
char num_to_char(const char* c) {
 std::vector<char> char_vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
 int index = std::atoi(c);
 if (index > 26 || index < 1) return '\0';
 return char_vec[index-1];
}

// Helper functioj to find all possible input strings for the given encoded
// string.
void recursive_decoder(const std::string_view s, std::size_t pos,
                       std::vector<char>& current,
                       std::vector<std::string>& results) {
  if (pos >= s.size()) {
    results.push_back(vec_to_string(current));
    return;
  }

  char chars[] = {'0', '0'};
  // single char
  chars[1] = s[pos];
  current.push_back(num_to_char(chars));
  recursive_decoder(s, pos+1, current, results);
  current.pop_back();

  // double char
  if (pos >= s.size() - 1) return;
  chars[0] = s[pos];
  chars[1] = s[pos+1];
  char c = num_to_char(chars);
  if (c != '\0') {
    current.push_back(num_to_char(chars));
    recursive_decoder(s, pos+2, current, results);
    current.pop_back();
  }
}

// Find all possible input strings for the given encoded string in a
// recursive manner.
std::vector<std::string> possible_decodes(const std::string_view s) {
  std::vector<char> current;
  std::vector<std::string> results;
  recursive_decoder(s, 0, current, results);
  return results;
}

int main() {
  auto s = "alphabet";
  std::cout << "Decoded: " << s << std::endl;
  auto s_enc = encode_string(s);
  std::cout << "Encoded: " << s_enc << std::endl;
  auto results = possible_decodes(s_enc);
  for (const auto& d : results) std::cout << d << std::endl;
  return 0;
}

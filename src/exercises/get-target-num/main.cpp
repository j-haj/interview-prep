#include <iostream>
#include <string>
#include <vector>
#include <map>

#define UNUSED(arg) { (arg = arg); }

enum class Op { Add, Sub, Mul, Div, Nop };

bool can_achieve_target(const std::string& s, int target, int current, size_t idx) {
  if (current == target) {
    std::cout << "SUCCESS: " << current << " = " << target << std::endl;
    return true;
  }
  else if (idx == s.size() && current != target) return false;
  
  for (size_t i = 1; i <= s.size() - idx; ++i) {
    // Get current value
    const char* n = s.substr(idx, i).c_str();
    std::cout << "current = " << current << " trying n = " << n << '\n';
    int val = std::atoi(n);

    // Subtract
    current -= val;
    if (can_achieve_target(s, target, current, idx+1)) return true;
    current += val;

    // Divide
    if (val != 0) {
      current /= val;
      if (can_achieve_target(s, target, current, idx+1)) return true;
      current *= val;
    }

    // Addition
    current += val;
    if (can_achieve_target(s, target, current, idx+1)) return true;
    current -= val;

    // Multiplication
    current *= val;
    if (can_achieve_target(s, target, current, idx+1)) return true;
  }
  return false;
}

int main(int argc, char** argv) {
  UNUSED(argc);
  UNUSED(argv);
  if (can_achieve_target("12345", 56, 0, 0)) {
    std::cout << "Target acheived!\n";
  } else {
    std::cout << "Not possible...\n";
  } 
  return 0;
}

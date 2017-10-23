#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void* operator new(std::size_t n) {
  std::cout << "[allocating " << n << " bytes]\n";
  return malloc(n);
}

void iterate_vals(const std::string& s) {
  for (const auto& c : s) {
    std::cout << c << " ";
  }
  std::cout << '\n';
}

void iterate_vals_sv(std::string_view s) {
  std::cout << "[string_view] ";
  for (const auto& c : s) {
    std::cout << c << " ";
  }
  std::cout << '\n';
}

char* create_a_string() {
  return "as;ldhgsdfboiurnalsfgnslibsadflsf";
}

int main(int argc, char* argv[]) {
  std::string ls = "This is a longer string that might not make the SSO";
  iterate_vals(ls);
  iterate_vals("Another test with a much, much longer string to avoid SSO");
  iterate_vals_sv("One last test with a really long string");

  for (int i = 0; i < 5; ++i) {
    auto v = create_a_string();
    iterate_vals_sv(v);
  }
}

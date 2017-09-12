#include <bitset>
#include <iostream>
#include <random>

int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

short parity(int val) {
  short parity_val{0};
  while (val > 0) {
    parity_val ^= 1;
    val &= val - 1;
  }
  return parity_val;
}

int main(int argc, char* argv[]) {
  int test_num = random_int(1, 1000);
  std::bitset<16> bit_rep(test_num);
  std::cout << "The number " << test_num << " (" << bit_rep << ") has "
            << "an " << (parity(test_num) == 1 ? "odd" : "even") << " number of bits\n";
  return 0;
}

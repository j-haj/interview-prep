#include <bitset>
#include <iostream>
#include <random>

int random_number(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(low, high);
  return dist(gen);
}

int count_bits(int num) {
  int bit_count{0};
  while (num > 0) {
    auto bit = num & 1;
    bit_count += bit;
    num = num >> 1;
  }
  return bit_count;
}

int main(int argc, char* argv[]) {
  int test_num = random_number(1, 1000);
  std::bitset<16> bit_rep(test_num);
  std::cout << "The number " << test_num << ", represented as "
            << bit_rep << " has " << count_bits(test_num)
            << " bits set to 1\n";
  return 0;
}

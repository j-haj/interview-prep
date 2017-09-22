#include <bitset>
#include <iostream>
#include <random>

/**
 * Generates a random integer from the range [low, high]
 *
 * @param low the low end of the range (inclusive)
 * @param high the high end of the range (inclusive)
 *
 * @return an integer from the interval [low, high]
 */
int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Takes the input value and propogates its rightmost bit to the right,
 * returning the resulting number
 *
 * @param val number whose rightmost bit will be propogated
 *
 * @return new number resulting from propogating the rightmost bit
 */
int propogate_rightmost(int val) {
  int rightmost_bit = val & ~(val - 1);
  std::bitset<16> bit(rightmost_bit);
  int result {0};
  int count {0};
  while (rightmost_bit > 1) {
    result += 1 << (count);
    rightmost_bit >>= 1;
    ++count;
  }
  std::bitset<16> res(result);
  return result;
}

int main(int argc, char* argv[]) {
  auto val = random_int(1, 1000);
  auto tail = propogate_rightmost(val);
  std::bitset<16> bit_rep(val);
  std::bitset<16> new_bit_rep(val + tail);
  std::cout << "Value " << val << '\n';
  std::cout << "\t" << bit_rep << '\n';
  std::cout << "\t" << new_bit_rep << '\n';
  return 0;
}

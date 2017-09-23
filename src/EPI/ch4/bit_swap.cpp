#include <bitset>
#include <iostream>
#include <random>

/**
 * Returns a random integer from the interval [low, high]
 *
 * @param low left end of the range (inclusive)
 * @param high right end of the range (inclusive)
 *
 * @return random integer from specified interval [low, high]
 */
int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Swaps bits at indices i and j, assuming index 0 is the least significant bit,
 * for the given value
 *
 * @param value number whose bits will be swapped
 * @param i index of bit
 * @param j index of bit
 *
 * @return the result of swapping bits i and j within a given number
 */
int swap_bits(int value, const int i, const int j) {
  if (((value >> i) & 1) != ((value >> j) & 1)) {
    auto bit_mask = (1 << i) | (1 << j);
    value ^= bit_mask;
  }
  return value;
}

int main(int argc, char* argv[]) {
  int val = random_int(1, 1000);
  std::bitset<16> bit_rep(val);
  int i = random_int(1, 15);
  int j = random_int(1, 15);
  int res = swap_bits(val, i, j);
  std::bitset<16> new_bit_rep(res);
  std::cout << "Swapping bits i = " << i << ", j = " << j
            << " in " << val << ":\n"
            << "\told: " << bit_rep << '\n'
            << "\tnew: " << new_bit_rep << '\n';
  return 0;
}

#include <bitset>
#include <iostream>
#include <random>


/**
 * Generate a random integer in the range [low, high]
 *
 * @param low low end of interval
 * @param high high end of interval
 *
 * @return an integer in the interval [low, high]
 */
int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Computes the weight of the given integer. The weight is defined as the sum of
 * all bits whose value is 1. Note we assume 32 bit integers.
 *
 * @param n number whose weight will be computed
 *
 * @return the number of bits equal to 1 in `n`
 */
template <typename T>
T weight(const T n) {
  int result {0};
  const int end = sizeof(T) * 8;
  for (short i = 0; i < end; ++i) {
    T mask = 1 << i;
    result += (mask & n) >> i;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::cout << "Weight of 92 is " << weight(92) << '\n';
  int val = random_int(1, 100000);
  std::bitset<16> val_rep(val);
  std::cout << "Weight of " << val << "(" << val_rep << "): " << weight(val) << '\n';

  return EXIT_SUCCESS;
}

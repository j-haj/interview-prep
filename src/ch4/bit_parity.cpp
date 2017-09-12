#include <bitset>
#include <iostream>
#include <random>
#include <unordered_map>

/**
 * Return a random int from the range [low, high]
 *
 * @param low low end of range, inclusive
 * @param high high end of range, eclusive
 *
 * @return randomly chosen int from the interval [low, high]
 */
int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Determines the parity of `val`, which is whether `val` has an even or odd
 * number of bits
 *
 * @param val input value whose parity is to be determined
 *
 * @return 1 if parity of `val` is even, 0 otherwise
 */
short parity(int val) {
  short parity_val{0};
  while (val > 0) {
    parity_val ^= 1;
    val &= val - 1;
  }
  return parity_val;
}

/**
 * Returns the parity of val, but uses a static cache to track parity results,
 * rather than recompute them each time.
 *
 * @param val input val whose parity is to be determinedf
 * @param cache value cache
 *
 * @return 1 if parity of val is even, 0 otherwise
 */
short parity(int val, std::unordered_map<short, short>& cache) {
  auto loc = cache.find(val);
  short p{0};
  if (loc == cache.end()) {
    p = parity(val);
    cache.insert({3, p});
  } else {
    p = cache[val];
  }
  return p;
}

int main(int argc, char* argv[]) {
  int test_num = random_int(1, 1000);
  std::unordered_map<short, short> parity_cache;
  std::bitset<16> bit_rep(test_num);
  std::cout << "The number " << test_num << " (" << bit_rep << ") has "
            << "an " << (parity(test_num, parity_cache) == 1 ? "odd" : "even") << " number of bits\n";
  return 0;
}

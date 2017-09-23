#include <bitset>
#include <iostream>
#include <random>
#include <limits>
#include <unordered_map>

/**
 * Return a random integer from the interval [low, high]
 *
 * @param low low end of the range
 * @param high high end of the range
 *
 * @return integer from [low, high]
 */
int random_int(const int low, const int high) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

/**
 * Builds a std::unordered_map<short, short> of values to be used as a cache in the
 * function `reverse_bits`.
 */
std::unordered_map<short, short> build_cache() {
	auto cache = std::unordered_map<short, short>();
	auto max_val = std::numeric_limits<short>::max();
	for (short i = 0; i < max_val; ++i) {

		cache[i] = max_val - i;
	}
  return cache;
}

/**
 * Reverses the bits of the input
 * Note: this is different from simply taking the transpose. For example, given
 * the input 10001, we would expect a result of 10001 (although we are assuming
 * 32 bit numbers here).
 *
 * @param value numbers whose bits will be reversed
 * @param cache a std::unordered_map of cached reverse bit patterns
 *
 * @return number equivlaent to the input with its bits reversed
 */
int reverse_bits(const int value, const std::unordered_map<short, short>& cache) {
	int result {0};
	for (int i = 0; i < 32; ++i) {
		auto target_bit = (1 << (32 - i)) & value;
		result |= target_bit;
	}
	return result;
}

int main(int argc, char* argv[]) {
  auto val = random_int(1, 1000);
  std::bitset<32> val_bits(val);
  auto cache = build_cache();

  auto result = reverse_bits(val, cache);
  std::bitset<32> res_bits(result);

  std::cout << "Initial value: " << val << "(" << val_bits << ")\n";
  std::cout << "Result: " << result << "(" << res_bits << ")\n";

	return 0;
}

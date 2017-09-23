#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

/**
 * Prints the vector
 */
template <typename T>
void print_vec(const std::vector<T>& v) {
  std::cout << "[ ";
  for (auto i = std::begin(v); i != std::end(v); ++i) {
    std::cout << *i << " ";
  }
  std::cout << "]\n";
}
/**
 * Generates a random int on the given interval
 *
 * @param low low end of the interval
 * @param high high end of the interval
 *
 * @return random integer on the interval [low , high]
 */
int random_int(const int low, const int high) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(low, high);
  return dist(gen);
}

/**
 * Generate a std::vector<int> of random values
 *
 * @param n number of elements in vector
 * @param low low end of range
 * @param high high end of range, inclusive
 *
 * @return vector of random ints sampled from the distribution U([low, high])
 */
std::vector<int> random_vector(const size_t n, const int low, const int high) {
  std::vector<int> result(n);
  for (size_t i = 0; i < n; ++i) {
    result[i] = random_int(low, high);
  }
  return result;
}

/**
 * Takes a collection and parititions it according the the Dutch
 * National Flag problem, where all elements less than a given partition are at
 * lower indices and all elements greater than the pivot element are at indices
 * greater than the indices of the elements equal to the pivot.
 *
 * Example
 * Input: [5, 3, 2, 2, 3, 1, 8]
 * Pivot: 3
 * Output: [2, 2, 1, 3, 3, 5, 8]
 *
 * @param begin iterator to beginning of collection
 */
template <class Iter>
void dutch_flag_partition(Iter begin, Iter end) {
  auto pivot = begin + random_int(0, end - begin - 1);
  std::cout << "Pivot has value " << *pivot << '\n';
  while (begin != end) {
    if (*begin < *pivot && begin > pivot) {
      std::swap(begin, pivot);
    } else if (*begin > *pivot && begin < pivot) {
      std::swap(begin, pivot);
    }
    ++begin;
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> v = random_vector(10, 0, 10);
  print_vec(v);
  std::cout << "Calling dutch_flag_partition\n";
  dutch_flag_partition(v.begin(), v.end());
  print_vec(v);
  return EXIT_SUCCESS;
}

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/**
 * Generates a vector of size n whose contents are the numbers 1 through n-1.
 *
 * @param n size of the vector
 * @return a vector of size n with elements 1 - (n-1) inclusive.
 */
std::vector<int> generate_random_vector(std::size_t n) {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dist(1, n-1);
  int repeated_num = dist(gen);
  std::vector<int> output(n);
  for (int i = 1; i < n; ++i) {
    output[i-1] = i;
  }
  output[n-1] = repeated_num;
  std::random_shuffle(std::begin(output), std::end(output));
  return output;
}


int find_repeated_num(const std::vector<int>& v) {
  std::vector<int> tracker(v.size()+1, 0);
  for (const auto x : v) {
    if (tracker[x] != 0) return x;
    tracker[x] = 1;
  }
  return -1;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  os << "[ ";
  for (const auto x : v) {
    os << x << ' ';
  }
  os << "]";
  return os;
}

int main() {
  auto v = generate_random_vector(20);
  int r = find_repeated_num(v);
  std::cout << v << " has repeated num " << r << '\n';
}

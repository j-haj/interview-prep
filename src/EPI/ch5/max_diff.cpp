#include <iostream>
#include <limits>
#include <vector>

double max_diff(const std::vector<double>& values) {
  double min = std::numeric_limits<double>::max();
  double diff{0.0};
  for (const auto& x : values) {
    auto cur_diff = x - min;
    diff = std::max(diff, cur_diff);
    min = std::min(x, min);
  }
  return diff;
}

int main(int argc, char* argv[]) {

  std::vector<double> v1 {1.2, 3, 9.8, 0, 10.0};
  std::vector<double> v2 {1.1, 11.3, 0.2, 8.9};
  std::cout << "Max diff for v1 is " << max_diff(v1) << " expected is 10.0\n";
  std::cout << "Max diff for v2 is " << max_diff(v2) << " expected is 10.2\n";
  return EXIT_SUCCESS;
}

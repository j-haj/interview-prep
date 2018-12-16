#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> generate_nums(int n) {
  std::vector<std::vector<int>> nums;
  nums.push_back(std::vector<int>{1, 1});
  for (int i = 1; i < n; ++i) {
    std::vector<int> row;
    // Each row has 2 * i + 1 numbers
    for (int j = 0; j < 2 * i + 1; ++j) {
      if (j == 0 || j == i - 1) {
	row.push_back(1);
	continue;
      }
      row.push_back(nums[i][j - 1] + nums[i][j]);
    }
    nums.push_back(row);
  }
  return nums;
}

std::string whitespace(int i, int max_len) {
  const auto l = static_cast<std::size_t>((max_len - 2 * i - 1)/2);
  return std::string(' ', l);
}

/**
 * Prints Pascal's triangle with n rows.
 */
void print_triangle(int n) {
  const int max_len = 2 * n + 1;
  auto whitespace = [max_len](int i) -> std::string {
		      const auto l = static_cast<std::size_t>((max_len - 2 * i - 1) / 2);
		      return std::string(' ', l);
		    };
  std::cout << "Testing whitespace -> " << whitespace(2) << " done.\n";

  const auto nums = generate_nums(n);
  for (int i = 0; i < n; ++i) {
    const auto row = nums[i];
    std::cout << whitespace(i);
    for (int j = 0; j < row.size(); ++j) {
      if (j == 0 || j == row.size() - 1) {
	std::cout << row[j];
	continue;
      }
      std::cout << " " << row[j];
    }
    // Pad with whitespace and flush
    std::cout << whitespace(i) << std::endl;
  }
}

int main() {
  const auto N = 5;
  print_triangle(N);

  return 0;
}

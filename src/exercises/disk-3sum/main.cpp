#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <unordered_map>
#include <utility>
#include <vector>

struct Triple {
  long long first;
  long long second;
  long long third;
};

std::size_t count_lines(char* f, std::size_t n_bytes) {
  std::size_t num_rows = 0;
  for (std::size_t i = 0; i < n_bytes; ++i) {
    if (f[i] == '\n') ++num_rows;
  }
  return num_rows;
}

int get_num(char* d, std::size_t index, std::size_t line_len) {
  constexpr std::size_t len = 100;
  static char buf[len];
  std::memset(buf, 0, len);
  // Subtract 1 from line_len since the lines end in '\n'
  for (std::size_t i = 0; i < line_len - 1; ++i) {
    buf[i] = d[index + i];
  }
  return std::atoi(buf);
}

Triple find_3sums(const std::string& filename, std::size_t target) {
  struct stat st;
  stat(filename.c_str(), &st);
  std::size_t file_size = st.st_size;
  std::cout << "Filesize: " << file_size << std::endl;

  // Get mem map
  int fd = open(filename.c_str(), O_RDONLY, 0);
  char* data = static_cast<char*>(mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0));
  assert(data != MAP_FAILED);


  // Get line length 
  int tmp_idx = 0;
  while (data[tmp_idx] != '\n') ++tmp_idx;
  const int line_len = tmp_idx;

  // get number of lines 
  const std::size_t line_count = count_lines(data, file_size);
  std::cout << "Num lines: " << line_count << std::endl;

  std::unordered_map<long long, std::pair<long long, long long>> two_sums;
  for (std::size_t i = 0; i < line_count; ++i) {
    const long long i_val = get_num(data, i, line_len);
    for (std::size_t j = i + 1; j < line_count; ++j) {
      const long long j_val = get_num(data, j, line_len);
      const long sum = i_val + j_val;
      two_sums[target - sum] = std::make_pair(i_val, j_val);
    }
  }

  for (std::size_t i = 0; i < line_count; ++i) {
    const long long val = get_num(data, i, line_len);
    if (two_sums.find(val) != two_sums.end()) {
      return Triple{val, two_sums[val].first, two_sums[val].second};
    }
  }

  return Triple{};
}

int main() {
  const long long x = 30503;
  const long long y = 3889803;
  const long long z = 9772478;
  auto c = find_3sums("sorted1k.txt", x+y+z);
  std::cout << "Result: (" << c.first << ", " << c.second << ", " << c.third << ")\n";
  std::cout << "Expected: (" << x << ", " << y << ", " << z << ")\n";

  return 0;
}

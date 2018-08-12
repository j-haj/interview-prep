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

/**
 * Returns the number of lines in the file by counting the occurences of '\n'
 */
std::size_t count_lines(char* f, std::size_t n_bytes) {
  std::size_t num_rows = 0;
  for (std::size_t i = 0; i < n_bytes; ++i) {
    if (f[i] == '\n') ++num_rows;
  }
  return num_rows;
}

/**
 * Returns the number at the given `index` assuming a line length of `line_len`,
 * including the '\n' at the end of the line.
 */
int get_num(char* d, std::size_t index, std::size_t line_len) {
  char buf[line_len];
  std::memset(buf, '\0', line_len);
  // Subtract 1 from line_len since the lines end in '\n'
  for (std::size_t i = 0; i < line_len - 1; ++i) {
    buf[i] = d[index*line_len + i];
  }
  return std::atoll(buf);
}

/**
 * Returns the length of the line (i.e., the number of bytes up to and including
 * the '\n' character).
 */
std::size_t line_length(char* d) {
  std::size_t count = 0;
  while (d[count] != '\n') ++count;
  return count+1;
}

/**
 * Returns the size of the file in bytes.
 */
std::size_t file_nbytes(const std::string& filename) {
  struct stat st;
  stat(filename.c_str(), &st);
  return static_cast<std::size_t>(st.st_size);
}

Triple find_3sums(const std::string& filename, std::size_t target) {
  std::size_t file_size = file_nbytes(filename);
  std::cout << "Filesize: " << file_size << std::endl;

  // Get mem map
  int fd = open(filename.c_str(), O_RDONLY, 0);
  char* data = static_cast<char*>(mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0));
  assert(data != MAP_FAILED);

  // Get line length 
  const int line_len = line_length(data);
  std::cout << "Line length: " << line_len << std::endl;

  // get number of lines 
  const std::size_t line_count = count_lines(data, file_size);
  std::cout << "Num lines: " << line_count << std::endl;

  std::unordered_map<long long, std::pair<long long, long long>> two_sums;
  for (std::size_t i = 0; i < line_count - 1; ++i) {
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
  std::cout << "Expected: (" << x << ", " << y << ", " << z << ") (sums to " << x + y + z << ")\n";

  return 0;
}

#include <fstream>
#include <iomanip>
#include <random>

/**
 * Writes `n` random ints to the given file.
 */
void write_data(const std::string& filename, std::size_t n) {
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<> dist(1, 10000000);

  std::ofstream of(filename);
  for (std::size_t i = 0; i < n; ++i) {
    of << std::setfill('0') << std::setw(8) << dist(gen) << '\n';
  }
}

int main() {
  write_data("1ktest.txt", 1000);
  return 0;
}

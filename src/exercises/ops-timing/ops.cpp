#include <chrono>
#include <iostream>


void perform_ops(const size_t n_ops) {
  long result {0};
  for (size_t i = 0; i < n_ops; ++i) {
    result += static_cast<long>(i);
  }
}

int main(int argc, char* argv[]) {

  const size_t n_ops = static_cast<size_t>(5e8);

  auto start = std::chrono::system_clock::now();

  perform_ops(n_ops);

  auto stop = std::chrono::system_clock::now();
  std::cout << "Performed " << n_ops << " in " << std::chrono::duration<double>(stop - start).count() << " seconds\n";

  return EXIT_SUCCESS;
}

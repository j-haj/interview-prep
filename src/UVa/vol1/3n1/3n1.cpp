#include <iostream>


/**
 * Computes the cycle length for `n` using the following algorithm:
 *
 *  if n == 1 the stop else
 *    if n is odd then n <- 3n + 1
 *    else n <- n/2
 *  end
 *
 * @param n starting number
 *
 * @return the length of the cycle, including the last value 1
 */
size_t cycle_length(int n) {
  size_t cycle{1};
  while (n != 1) {
    ++cycle;
    if (n % 2 == 1) {
      n = 3 * n + 1;
    } else {
      n /= 2;
    }
  }
  return cycle;
}

int main(int argc, char* argv[]) {

  std::cout << "Cycle length for n = 22 is " << cycle_length(22) << '\n';
  return EXIT_SUCCESS;
}

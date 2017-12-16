#include <iostream>
#include <unordered_map>

/**
 * Returns the number of ways to climb `n` stairs taking either one, two, or
 * three stairs at a time.
 *
 * @param n number of stairs to climb
 *
 * @returns number of different ways to climb `n` stairs
 */
int num_ways(int n) {
  std::unordered_map<int, int> n_ways {{1, 1}, {2, 2}, {3, 4}};
  int step {4};
  while (step <= n) {
    if(n_ways.find(step) == n_ways.end()) {
      n_ways[step] = n_ways[step - 1] + n_ways[step - 2] + n_ways[step - 3];
    }
    ++step;
  }
  return n_ways[n];
}

int main(int argc, char* argv[]) {

  std::cout << "Number of ways to climb 4 steps: " << num_ways(4) << '\n';
  return 0;
}

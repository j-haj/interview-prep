#include <cstddef>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

std::size_t random_pivot(std::size_t size) {
  static std::random_device rd;
  static std::mt19937 g(rd());

  std::uniform_int_distribution<> dist(0, size);
  return dist(g);
}

template <class T>
void quicksort(std::vector<T>& v) {
  std::queue<std::pair<size_t, size_t>> index_queue;
  index_queue.emplace({0, v.size() - 1});
  while (!index_queue.empty()) {
    size_t i;
    size_t j;
    std::tie(i, j) = index_queue.front();
    size_t pivot = random_pivot(j - i + 1);
    index_queue.pop();
    while (i < pivot || j > pivot) {
      if (v[i] == v[pivot] && v[j] == v[pivot]) break;
      while (v[i] < v[pivot] && i < pivot) ++i;
      while (v[j] > v[pivot] && j > pivot) --j;
      std::swap(v[i], v[j]);
    }
    // 
  }
}

template <class T>
std::string vec_to_str(const std::vector<T>& v) {
  std::ostringstream ss;
  ss << "[ ";
  for (const auto& x : v) {
    ss << x << ' ';
  }
  ss << "]";
  return ss.str();
}

int main(int argc, char* argv[]) {
  std::vector<int> v1 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Input vector: " << vec_to_str(v1) << '\n';
  quicksort(v1);
  std::cout << "Output vector: " << vec_to_str(v1) << '\n';
  return 0;
}

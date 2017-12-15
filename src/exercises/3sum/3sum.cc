#include <iostream>
#include <vector>
#include <unordered_map>

struct Triple {
  int first;
  int second;
  int third;
  Triple(int x, int y, int z) : first(x), second(y), third(z) {}
}; // struct Triple

namespace {
  Triple NULL_TRIPLE (-1, -1, -1);
};

Triple three_sum(const int target, const std::vector<int>& v) {
  auto map = std::unordered_map<int, int>();
  for (const auto& x : v) {
    map[x] = 1;
  }
  for (const auto& x : v) {
    for (const auto& y : v) {
      const auto z = x + y;
      if (z == target) {
        auto s_idx = map.find(z);
        if (s_idx != map.end()) {
          return Triple(x, y, z);
        }
      }
    }
  }
  return NULL_TRIPLE;
}

void run_tests() {

}

int main(int argc, char* argv[]) {
  run_tests();
  return 0;
}

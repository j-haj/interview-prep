#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Binary search
 *
 * @precondition `v` should be sorted and non-empty
 *
 * @param v input vector
 * @param x element to find
 * @returns index of `x` if found, -1 otherwise
 */
template <class T>
int binary_search(const std::vector<T>& v, T x) {
  if (v.size() == 0) return -1;
  if (v.size() == 1) return v[0] == x ? 0 : -1;

  int search_len = v.size() / 2;
  int cur_idx = search_len;
  while (cur_idx >= 0 && cur_idx < v.size()) {
    search_len = std::max(search_len/2, 1);
    if (v[cur_idx] == x) break;
    else if (v[cur_idx] < x) cur_idx += search_len;
    else cur_idx -= search_len;
  }

  return cur_idx >= 0 && cur_idx < v.size() ? cur_idx : -1;
}

int main(int argc, char* argv[]) {

  std::vector<int> v {0, 1, 2, 3, 4, 5};

  auto idx = binary_search(v, 3);
  std::cout << "idx: " << idx << " val: " << v[idx] << '\n';

  return 0;
}

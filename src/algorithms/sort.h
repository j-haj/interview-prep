#ifndef SORT_H_
#define SORT_H_

#include <algorithm>
#include <cstddef>
#include <iostream>

template <class Iter>
void printer(Iter begin, Iter end) {
  while (begin != end) {
    std::cout << *begin << ' ';
    ++begin;
  }
  std::cout << '\n';
}
template <class Iter>
void mergesort(Iter begin, Iter end) {
  std::cout << "( " << *begin << ", " << *(end - 1) << ")\t";
  printer(begin, end);
  if (end - begin == 1) {
    if (*begin > *end) std::swap(*begin, *end);
    return;
  }
  size_t mid_offset = (end - begin) / 2;
  Iter mid = std::next(begin, mid_offset);
  std::cout << "mid: " << mid_offset << '\n';
  mergesort(begin, mid);
  mergesort(mid, end);
  while (begin != end) {
    if (*begin <= *mid){
      ++begin;
    } else if (*begin > *mid) {
      std::swap(*begin, *mid);
      ++mid;
    }
  }
}

#endif // SORT_H_


#include <bitset>
#include <cctype>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>


std::vector<int> get_idx(unsigned long x) {
  std::vector<int> indices;
  std::size_t counter=0;
  for (unsigned long offset = 0; offset < 56; offset += 8) {
    unsigned long masked = (0xFFul<<offset)&x;
    ++counter;
    if (masked) {
      for (int i = 0; i < 8; ++i) {
        if ((1<<i)&(masked>>offset)) {
          indices.push_back(i+offset);
        }
        ++counter;
      }
    }
  }
  std::cerr << "i: " << x << " loops: " << counter << '\n';
  return indices;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[ ";
  for (const auto& x : v) {
    os << x << ' ';
  }
  os << "]";
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
  os << "{ ";
  for (const auto& x : s) {
    os << x << ' ';
  }
  os << "}";
  return os;
}


void powerset_impl(const std::vector<int>& s, int i, std::set<int>& current, std::set<std::set<int>>& sets) {
  if (i == s.size()) sets.insert(current);
  for (auto it = s.begin() + i; it < s.end(); ++it) {
    current.insert(*it);
    powerset_impl(s, i+1, current, sets);
    current.erase(*it);
    powerset_impl(s, i+1, current, sets);
  }
}

std::set<std::set<int>> powerset(const std::vector<int>& s) {
  std::set<int> current;
  std::set<std::set<int>> result;
  powerset_impl(s, 0, current, result);
  return result;
}

std::set<std::set<int>> powerset_it(const std::vector<int>& s) {
  std::size_t set_size {(1ul<<s.size())};
  std::set<std::set<int>> sets;
  for (std::size_t i = 0; i < set_size; ++i) {
    auto indices = get_idx(i);
    std::set<int> tmp_set;
    for (const auto& idx : indices) {
      tmp_set.insert(s[idx]); 
    }
    sets.insert(tmp_set);
  }
  return sets;
}

int main(int argc, char* argv[]) {
  std::vector<int> s {1, 2, 3, 4, 5};
  std::cout << "Input: " << s << '\n';
  auto ps = powerset(s);
  auto ps2 = powerset_it(s);
  std::cout << "Powerset: " << ps << '\n';
  std::cout << "Powerset (it): " << ps2 << '\n';
  return 0;
}

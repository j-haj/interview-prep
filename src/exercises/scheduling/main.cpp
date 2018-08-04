#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <tuple>
#include <vector>

using Interval = std::pair<int, int>;

Interval MakeInterval(int first, int second) { return std::make_pair(first, second); }

int min_rooms(const std::vector<Interval>& schedule) {
  std::vector<Interval> intervals(schedule);
  std::sort(intervals.begin(), intervals.end(),
            [](const Interval& x, const Interval& y) {
              return x.first < y.first;
            });
  int max_rooms = std::numeric_limits<int>::min();
  int current_count = 0;
  int current_end = intervals.front().second;
  for (const auto& interval : intervals) {
    if (interval.first > current_end) {
      max_rooms = std::max(max_rooms, current_count);
      current_count = 1;
      current_end = interval.second;
    } else {
      ++current_count;
    }
  }
  return max_rooms;
}

void run_tests() {
  std::vector<Interval> test1{{1, 3}, {2, 4}, {5, 6}};
  int expected1 = 2;
  int actual1 = min_rooms(test1);
  std::string result1 = expected1 == actual1 ? "[PASS]" : "[FAIL]";

  std::vector<Interval> test2{{1, 5}, {8, 9}, {3, 4}, {7, 9}, {2, 6}, {4, 6}};
  int expected2 = 4;
  int actual2 = min_rooms(test2);
  std::string result2 = expected2 == actual2 ? "[PASS]" : "[FAIL]";

  std::cout << "Test1: " << result1 << std::endl;
  std::cout << "Test2: " << result2 << std::endl;
}

int main() {
  run_tests();  
  return 0;
}

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

std::size_t to_time(const std::unordered_set<std::size_t>& times) {
  std::size_t t = 0;
  for (const auto x : times) t += (1 << x);
  return t;
}

std::string construct_time(const std::size_t hour, const std::size_t minute) {
  std::stringstream ss;
  ss << hour << ":" << (minute > 9 ? "" : "0") << minute;
  return ss.str();
}

void recursive_searcher(std::size_t n, std::size_t current,
                        std::unordered_set<std::size_t>& hours,
                        std::unordered_set<std::size_t>& minutes,
                        std::unordered_set<std::string>& results) {
  if (current <= 0) {
    if ((hours.size() + minutes.size()) != n) return;
    auto hour = to_time(hours);
    auto minute = to_time(minutes);
    if (hour > 12 || minute >= 60) return;
    results.insert(construct_time(hour, minute));
    return;
  }
  // outer loop handles hours
  for (std::size_t i = 1; i < 4; ++i) {
    // inner loop handles minutes
    for (std::size_t j = 1; j < 6; ++j) {
      hours.insert(i);
      recursive_searcher(n, current - 1, hours, minutes, results);
      minutes.insert(j);
      recursive_searcher(n, current - 1, hours, minutes, results);
      hours.erase(i);
      recursive_searcher(n, current - 1, hours, minutes, results);
      minutes.erase(j);
    }
  }
}

int main() {
  int n = 3;
  std::unordered_set<std::size_t> hours;
  std::unordered_set<std::size_t> minutes;
  std::unordered_set<std::string> results;
  recursive_searcher(n, n, hours, minutes, results);
  for (const auto& s : results) std::cout << s << std::endl;
  return 0;
}

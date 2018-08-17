#include <iostream>

int add_pos(int x, int y) {
  if (x == 0) return y;
  return add_pos(--x, ++y);
}

int add_neg(int x, int y) {
  if (x == 0) return y;
  return add_neg(++x, --y);
}

int add(int x, int y) {
  if (x < 0) return add_neg(x, y);
  return add_pos(x, y);
}


int main() {
  std::cout << "32 + 81 = " << add(32, 81) << std::endl;
  std::cout << "-4 + 10 = " << add(-4, 10) << std::endl;
  std::cout << "-10 - 12 = " << add(-10, -12) << std::endl;
  return 0;
}

#include <iostream>

unsigned int add(unsigned int x, unsigned int y) {
  unsigned int result{0};
  unsigned int carry_in {0};
  unsigned int carry_out {0};
  unsigned int bit_tracker {1};
  while (x || y) {
    unsigned int x_bit = x & bit_tracker;
    unsigned int y_bit = y & bit_tracker;
    x >>= 1;
    y >>= 1;
    carry_in = carry_out << 1;
    carry_out = 0;
    result |= x_bit ^ y_bit ^ carry_in;
    carry_out = x_bit & y_bit;
    bit_tracker <<= 1;
  }
  return result;
}

int main(int argc, char* argv[]) {


  return EXIT_SUCCESS;
}

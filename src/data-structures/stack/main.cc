#include <iostream>

#include "stack.h"

int main(int argc, char* argv[]) {

  Stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << "Stack size: " << s.size() << '\n';
  std::cout << "s.pop() = " << s.pop() << '\n';
  std::cout << "s.pop() = " << s.pop() << '\n';
  std::cout << "s.pop() = " << s.pop() << '\n';

  return 0;
}

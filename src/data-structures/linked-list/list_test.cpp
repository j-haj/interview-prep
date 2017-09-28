#include <iostream>

#include "list.h"

int main(int argc, char* argv[]) {
  Node<int> n = new Node<int>(5);
  std::cout << "Node value: " << n.data() << '\n';
  List<int> test = List<int>();
  test.insert(1);
  test.insert(2);
  test.insert(3);
  test.print_list();
  return EXIT_SUCCESS;
}

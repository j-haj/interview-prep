#include <iostream>

#include "list.h"

int main(int argc, char* argv[]) {
  auto n = Node<int>(5);
  std::cout << "Node value: " << n.data << '\n';
  List<int> test = List<int>();
  test.insert(1);
  test.insert(2);
  test.insert(3);
	test.push_back(9);
	test.push_back(10);
  test.print_list();

	List<double> t2 = List<double>();
	t2.push_back(3.1);
	t2.insert(1.9);
	t2.push_back(9.0);
	t2.print_list();
  return EXIT_SUCCESS;
}

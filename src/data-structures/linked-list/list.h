#include <iostream>
#include <memory>


template <typename T>
struct Node {
  using NodePtr = std::shared_ptr<Node<T>>;
  Node(T d) : data(d) {}

  T data;
  NodePtr next = nullptr;  
}; // struct Node

template <typename T>
struct List {
  using NodePtr = std::shared_ptr<Node<T>>;

  void insert(T v) {
    NodePtr tmp = std::make_shared<Node<T>>(Node<T>(v));
    if (size == 0) {
      head = tmp;
      tail = head;
      ++size;
      return;
    }

    tmp->next = head;
    head = tmp;
    ++size;
  }

  void push_back(T v) {

    NodePtr tmp = std::make_shared<Node<T>>(Node<T>(v));
    if (size == 0) {
      head = tmp;
      tail = head;
      ++size;
      return;
    }

    tail->next = tmp;
    tail = tail->next;
    ++size;
  }

  void print_list() {
    NodePtr tmp = head;
    std::cout << "[ ";
    while (tmp != nullptr) {
      std::cout << tmp->data << ' ';
      tmp = tmp->next;
    }
    std::cout << "]\n";
  }

  NodePtr head = nullptr;
  NodePtr tail = nullptr;
  size_t size = 0;
}; // struct List

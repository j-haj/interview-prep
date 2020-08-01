#include <memory>
#include <iostream>
#include <optional>
#include <sstream>
#include <stack>


template <class T>
class BST {
public:
  BST() : root_() {}

  void insert(T v) {
    if (!root_) {
      root_ = std::make_unique<Node>(v);
      return;
    }

    auto runner = root_.get();
    auto lagger = runner;
    while (runner != nullptr) {
      lagger = runner;
      if (v < runner->value()) runner = runner->left();
      else runner = runner->right();
    }
    if (v < lagger->value()) {
      std::cout << "Inserting " << v
                << " as the left child of parent node "
                << lagger->value()
                << "\n";
      lagger->left_ = std::make_unique<Node>(v);
    }
    else {
      std::cout << "Inserting " << v
                << " as the right child of parent node "
                << lagger->value()
                << "\n";
      lagger->right_ = std::make_unique<Node>(v);
    }
  }

  template <class Callable>
  void preorder_traverse(Callable f) {
    std::stack<Node*> s;
    s.push(root_.get());
    while (!s.empty()) {
      const auto n = s.top();
      s.pop();
      // Process
      f(n->value());

      // Add children to stack
      if (n->right() != nullptr) s.push(n->right());
      if (n->left() != nullptr) s.push(n->left());
    }
  }

  std::optional<T> find(T v) {
    auto runner = root_.get();
    while (runner != nullptr) {
      if (runner->value_ == v) return runner->value_;
      else if (v < runner->value_) runner = runner->left();
      else runner = runner->right();
    }
    return {};
  }

private:
  struct Node {
    Node(T v) : value_(v), left_(), right_() {}

    T value() { return value_; }
    Node* left() { return left_.get(); }
    Node* right() { return right_.get(); }

    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    T value_;
  }; // struct Node

  std::unique_ptr<Node> root_;
};

int main() {

  BST<int> bst;
  bst.insert(3);
  bst.insert(2);
  bst.insert(5);
  bst.insert(1);
  bst.insert(4);
  bst.preorder_traverse([](int x) {
                          std::cout << "value: " << x << "\n";
                        });

  auto v1 = bst.find(5);
  auto v2 = bst.find(11);
  if (v1.has_value()) std::cout << "Found " << v1.value() << "\n";
  if (!v2.has_value()) std::cout << "Did not find 11\n";
  return 0;
}

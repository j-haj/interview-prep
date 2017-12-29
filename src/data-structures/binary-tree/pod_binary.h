#ifndef POD_BINARY_H_
#define POD_BINARY_H_

#include <ostream>

template <class T>
struct TreeNode {
  T data;
  TreeNode* parent = nullptr;
  TreeNode* l_child = nullptr;
  TreeNode* r_child = nullptr;
}; // struct TreeNode

template <class T>
class BinaryTree {
 
  void insert(T val) noexcept {
    auto tmp = new TreeNode<T>{val};
    if (root_ == nullptr) {
      root_ = tmp;
      ++size_;
      return;
    }

    auto crawler = root_;
    while (true) {
      if (crawler->data < val && crawler->r_child != nullptr) crawler = crawler->r_child;
      else if (crawler->l_child != nullptr) crawler = crawler->l_child;
      else break;
    }

    if (crawler->data < val) crawler->r_child = tmp;
    else crawler->l_child = tmp;
    tmp->parent = crawler;
    ++size;
  }


  private:
    TreeNode* root_ = nullptr;
    int size_;
}; // class BinaryTree

#endif // POD_BINARY_H_

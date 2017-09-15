#ifndef __LIST_H
#define __LIST_H

#include <memory>
#include <sstream>
#include <stdexcept>

template <typename T>
class Node {
 public:
  Node(const T val) : val_(std::make_unique(val)) {}

  ~Node() = default;

  /**
   * Getter for the data stored in the node
   */
  T data() { return *val_; }

  /**
   * Set the next node
   */
  void set_next(const Node<T>& n) { next_ = std::make_unique<Node<T>>(n); }

  /**
   * Get reference to the next node
   */
  T& next() const {
    return *next_;
  }

 private:
  /// Stores data for the node
  std::unique_ptr<T> val_;

  /// Points to the next node
  std::unique_ptr<Node> next_;

};  // class Node

template <typename T>
class List {
 public:
  // Constructor/Destructors

  /**
   * Add element to the linked list.
   *
   * @param val value to add
   */
  void push_back(const T val) {
    tail_.set_next(std::make_unique(Node<T>(val)));
  }

  /**
   * Get the number of elements in the list.
   */
  size_t size() const noexcept { return size_; }

  /**
   * Return a reference to the nth element in the list. Has O(n) runtime
   * complexity.
   *
   * @param n index of the element to be returned
   *
   * @return Reference to element at the nth index
   */
  T& operator[](size_t n) const {
    if (n >= size_) {
      std::string_stream err_msg = "Attempted to access index "
                                   << n << " but list only has " << size_
                                   << " elements.";
      throw std::out_of_range(err_msg);
    }
    // Traverse the list until we hit the desired index
    size_t current_index{0};
    auto tmp = head_; // can't do this if head_ is unique_ptr
    while (current_index < n) {
      tmp = temp.next();
      ++current_index;
    }
    return tmp;
  }

 private:
  /// Reference to the head of the list
  std::unique_ptr<Node<T>> head_;

  /// Reference to the tail of the list
  std::unique_ptr<Node<T>> tail_;

  /// Number of elements in the list
  size_t size{0};

}  // class List
#endif  // __LIST_H

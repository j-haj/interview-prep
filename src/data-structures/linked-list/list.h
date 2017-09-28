#ifndef __LIST_H
#define __LIST_H

#include <memory>
#include <sstream>
#include <stdexcept>
#include <iostream>

template <typename T>
class Node {
 public:
  Node(const T val) : val_(std::move(val)) {}

  ~Node() = default;

  /**
   * Getter for the data stored in the node
   */
  T data() { return val_.get(); }

  /**
   * Set the next node
   */
  void set_next(Node<T>& n) { next_ = std::make_shared<Node<T>>(n); }

  /**
   * Get reference to the next node
   */
  Node& next() const { return *next_; }

  /**
   * Copy assignment
   */

 private:
  /// Stores data for the node
  std::unique_ptr<T> val_;

  /// Points to the next node
  std::shared_ptr<Node<T>> next_ = std::shared_ptr<Node<T>>();

};  // class Node

template <typename T>
class List {
 public:
  // Constructor/Destructors
  List() : head_(nullptr), tail_(nullptr), size_(0) {}

  ~List() {
    ~head_;
    ~tail_;
  }

  /**
   * Add element to the linked list.
   *
   * @param val value to add
   */
  void push_back(const T val) {
    tail_->set_next(std::make_shared(new Node<T>(val)));
    tail_ = tail_->next();
    if (head_ == nullptr) {
      head_ = tail_;
    }
    ++size;
  }

  /**
   * Add element to beginning of list
   *
   * @param val value of data to be inserted to head of list
   */
  void insert(const T val) {
    auto tmp = new Node<T>(val);
    tmp.set_next(head_);
    head_ = std::make_shared(tmp);
    if (tail_ == nullptr) {
      tail_ = head_;
    }
    ++size;
  }

  void print_list() {
    auto tmp = head_;
    std::cout << "[ ";
    while (tmp != nullptr) {
      std::cout << tmp->data() << " ";
      tmp = tmp->next();
    }
    std::cout << "]\n";
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
      std::stringstream err_msg;
      err_msg << "Attempted to access index " << n << " but list only has "
              << size_ << " elements.";
      throw std::out_of_range(err_msg.str());
    }
    // Traverse the list until we hit the desired index
    size_t current_index{0};
    auto tmp = head_;  // can't do this if head_ is unique_ptr
    while (current_index < n) {
      tmp = tmp.next();
      ++current_index;
    }
    return tmp;
  }

 private:
  /// Reference to the head of the list
  std::shared_ptr<Node<T>> head_;

  /// Reference to the tail of the list
  std::shared_ptr<Node<T>> tail_;

  /// Number of elements in the list
  size_t size_{0};

};      // class List
#endif  // __LIST_H

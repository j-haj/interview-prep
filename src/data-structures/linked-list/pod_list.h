#ifndef POD_LIST_H_
#define POD_LIST_H_
#include <sstream>
#include <ostream>

template <class T>
struct ListNode {
  T data;
  ListNode* next = nullptr;
};  // struct ListNode

template <class T>
class LinkedList {
 public:
  void insert(T val) noexcept {
    auto tmp = new ListNode<T>;
    tmp->data = val;

    if (size_ == 0) {
      head_ = tmp;
      tail_ = tmp;
      ++size_;
      return;
    }
    tail_->next = tmp;
    tail_ = tmp;
    ++size_;
  }

  void remove(T val) noexcept {
    auto tmp = head_;
    while (tmp != nullptr) {
      if(tmp->next->data == val) {
        tmp->next = tmp->next->next;
        --size_;
        return;
      }
      tmp = tmp->next;
    }
  }

  int size() const noexcept { return size_; }

  ListNode<T>* head() const noexcept { return head_; }
 private:
  int size_{0};
  ListNode<T>* head_;
  ListNode<T>* tail_;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ListNode<T>* o) {
  std::ostringstream ss;
  if (o->next == nullptr) ss << "null";
  else ss << &o->next;
  os << "Node<" << o->data << "," << ss.str() << ">";
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& o) {
  auto tmp {o.head()};
  int count {0};
  while (tmp != nullptr) {
    if (count > 5) {
      os << '\n';
      count = 0;
    } 
    os << tmp;
    if (tmp->next != nullptr) os << " --> ";
    tmp = tmp->next;
    ++count;
  }
  return os;
}
#endif  // POD_LIST_H_

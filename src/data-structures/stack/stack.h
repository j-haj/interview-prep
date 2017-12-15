#ifndef STACK_H_
#define STACK_H_
#include <cstddef>
#include <vector>

template <typename T>
class Stack {
  public:
    Stack() : {}
    Stack(std::size_t n) : {
      stack_.reserve(n);
    }

    void push(T val) { stack_.push_back(); }

    T pop() {
      T tmp = stack_.back();
      stack_.pop_back();
      return tmp;
    }

    T peek() { return stack_.back(); }

    std::size_t size() { return stack_.size(); }

  private:
    std::vector<T> stack_;

}; // class Stack

#endif // STACK_H_

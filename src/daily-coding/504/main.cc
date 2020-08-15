#include <vector>

class OrderBuffer {
public:
  OrderBuffer(std::size_t n) : orders_(std::vector<int>(n, 0)), n_(n) {}

  /**
   * Add a new order id to the buffer.
   */
  void record(int order_id) {
    orders_[end_] = order_id;
    printf("Added order id %d\n", order_id);
    ++end_;
    end_ %= n_;
    if (size_ == n_) {
      ++start_;
      start_ %= n_;
    } else ++size_;
  }

  /**
   * Fetch the i-th last order.
   * Note: since we are appending, the i-th last order is actually the
   * (n_ - i)-th order from the beginning.
   */
  int get_last(std::size_t i) {
    return orders_[(n_ - 1 - i + start_) % n_];
  }

private:
  std::vector<int> orders_;
  std::size_t start_ = 0;
  std::size_t end_ = 0;
  std::size_t n_;
  std::size_t size_ = 0;
};


int main() {
  OrderBuffer b(5);

  for (int i = 0; i < 5; ++i) b.record(i);
  printf("Recorded orders.\n");
  for (std::size_t i = 0; i < 5; ++i) {
    printf("b.get_last(%lu) = %d\n", i, b.get_last(i));
  }
  for (int i = 6; i < 8; ++i) b.record(i);
  for (std::size_t i = 0; i < 5; ++i) {
    printf("b.get_last(%lu) = %d\n", i, b.get_last(i));
  }
  return 0;
}

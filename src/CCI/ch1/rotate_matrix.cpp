#include <iostream>
#include <random>

template <typename T>
class Matrix {
 public:
  using matrix_t = std::vector<std::vector<T>>;

  Matrix(size_t m, size_t n) : m_(m), n_(n), data_(matrix_t(m)) {
    for (size_t i = 0; i < m; ++i) {
      data_[i] = std::vector<T>(n);
    }
  }

  void T() {
    for (size_t i = 0; i < m_; ++i) {
      for (size_t j = 0; j < n_; ++j) {
        std::swap(data_[i][j], data_[j][i]);
      }
    }
  }

  std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (size_t i = 0; i < m.rows(); ++i) {
      for (size_t j = 0; j < m.cols(); ++j) {
        os << m(i, j) << " ";
      }
      os << '\n';
    }
    return os;
  }

  T operator()(const size_t i, const size_t j) { return data_[i][j]; }

  size_t rows() const noexcept { return m_; }
  size_t cols() const noexcept { return n_; }

 private:
  /// Num rows
  size_t m_;

  /// Num cols
  size_t n_;

  /// Matrix data
  matrix_t data_;
};  // class Matrix

int main(int argc, char* argv[]) { return EXIT_SUCCESS; }

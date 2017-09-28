#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <sstream>

/**
 * Creates a vector of random shorts from the range [0, 9]
 *
 * @param size number of elements in the vector
 *
 * @return vector of length `size`
 */
std::vector<short> create_random_vector(size_t size) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<short> dist(0, 9);
  std::vector<short> v(size);
  for (size_t i = 0; i < size; ++i) {
    v[i] = static_cast<short>(dist(gen));
  }
  return v;
}

/**
 * Returns a string representation of the given fector
 *
 * @param v vector
 *
 * @return string showing the vectors elements
 */
template <typename T>
std::string vec_to_str(const std::vector<T>& v) {
  std::stringstream ss;
  ss << "[ ";
  for (const auto& x : v) {
    ss << x << " ";
  }
  ss << "]\n";
  return ss.str();
}

class ArbitraryPrecisionInt {
  public:
    ArbitraryPrecisionInt(const std::vector<short>& v) : vals_(v) {}

    ArbitraryPrecisionInt add(const ArbitraryPrecisionInt& aRhs) const noexcept {
      std::vector<short> output(std::max(aRhs.size(), vals_.size()));
      short carry {0};
      auto out_size = output.size();
      for (size_t i = 0; i < out_size; ++i) {
        auto tmp = (i < aRhs.size() ? aRhs.vals_[aRhs.size() - i - 1] : 0) +
          (i < vals_.size() ? vals_[vals_.size() - i - 1] : 0) + carry;
        carry = 0;
        if (tmp > 10) {
          carry = 1;
          tmp %= 10;
        }
        output[out_size - i - 1] = tmp;
      }
      if (carry > 0) {
        output.insert(output.begin(), carry);
      }
      return ArbitraryPrecisionInt(output);
    }

    ArbitraryPrecisionInt multiply(const ArbitraryPrecisionInt& aRhs) const noexcept {
      std::vector<short> output(aRhs.size() + vals_.size());
      const short sign = vals_[0] < 0 ^ aRhs.vals_[0] < 0 ? -1 : 1;
      short carry {0};
      auto out_size = output.size();
      for (size_t i = aRhs.size() - 1; i >= 0; --i) {
        for (size_t j = vals_.size() - 1; j >= 0; --j) {
          output[i + j + 1] += aRhs.vals_[i] * vals_[j];
          carry = (output[i + j + 1] - (output[i + j +1] % 10)) / 10;
          output[i + j] += carry;
          output[i + j + 1] %= 10;
        }
      }

      auto first_non_zero = std::find_if_not(std::begin(output), std::end(output),
          [](short x) { return x == 0; });
      output = std::vector<short>(first_non_zero, std::end(output));
      output[0] *= sign;
      return output;
    }

    size_t size() const noexcept {
      return vals_.size();
    }

    std::string str() const noexcept {
      std::stringstream ss;
      for (const auto& x : vals_) {
        ss << x;
      }
      return ss.str();
    }

  private:
    std::vector<short> vals_;

}; // class ArbitraryPrecisionInt
int main(int argc, char* argv[]) {

  auto v1 = ArbitraryPrecisionInt(create_random_vector(5));
  auto v2 = ArbitraryPrecisionInt(create_random_vector(5));

  std::cout << "First arbitrary int: " << v1.str() << '\n';
  std::cout << "Second arbitrary int: " << v2.str() << '\n';

  auto result = v1.add(v2);
  std::cout << "Result of sum: " << result.str() << '\n';

  auto mult_res = v1.multiply(v2);
  std::cout << "Result of multiplication: " << mult_res.str() << '\n';

  return EXIT_SUCCESS;
}

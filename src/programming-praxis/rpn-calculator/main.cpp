#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <string_view>

enum class Ops { Plus, Minus, Divide, Multiply };

double evaluate(double x, double y, Ops op) {
  switch (op) {
    case Ops::Plus:
      return x + y;
    case Ops::Minus:
      return x - y;
    case Ops::Multiply:
      return x * y;
    case Ops::Divide:
      return x / y;
    default:
      throw std::runtime_error("unrecognized operator");
  }
}

/**
 * Evaluates the given expression and returns the computed result or throws and
 * error if the expression is invalid.
 */
double eval(std::string_view expr) {
  std::stack<double> nums;
  std::stack<Ops> operations;
  constexpr std::size_t buf_len = 100;
  char buf[buf_len];
  std::memset(buf, '\0', buf_len);
  int idx = 0;
  for (char c : expr) {
    switch (c) {
      case '(':
        break;
      case ' ': {
        if (idx > 0) {
          auto f = std::atof(buf);
          std::memset(buf, '\0', buf_len);
          idx = 0;
          nums.push(f);
        }
        break;
      }
      case ')': {
        auto x = nums.top(); nums.pop();
        auto y = nums.top(); nums.pop();
        Ops op = operations.top(); operations.pop();
        nums.push(evaluate(y, x, op));
        break;
      }
      case '+':
        operations.push(Ops::Plus);
        break;
      case '-':
        operations.push(Ops::Minus);
        break;
      case '*':
        operations.push(Ops::Multiply);
        break;
      case '/':
        operations.push(Ops::Divide);
        break;
      default: {
        buf[idx] = c;
        ++idx;
      }
    }
  }
  return nums.top();
}

void check(std::string_view expr, double expected) {
  double actual = eval(expr);
  const double eps = 1e-9;
  auto prefix = std::abs(actual - expected) < eps ? "[PASS]" : "[FAIL]";
  std::cout << prefix << " : expected " << expected << " got " << actual << std::endl;
}

int main() {
  check("(1.2 3.1 *)", 1.2 * 3.1);
  check("(3 (4 2.1 /) *)", (4 / 2.1 * 3));
  check("((3 (4 2.1 /) *) (1.2 3.1 *) +)", (4 / 2.1 * 3) + 1.2 * 3.1);
  return 0;
}

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string_view>

enum class TokenType {
  Add,
  Subtract,
  Multiply,
  Divide,
  LParen,
  RParen,
  Num,
};

struct Token {
  Token(TokenType t) : type(t) {};
  Token(int v) : type(TokenType::Num), val(v) {} 
  TokenType type;
  bool is_value() const noexcept { return type == TokenType::Num; }
  int val;  
};

std::ostream& operator<<(std::ostream& os, const Token& t) {
  os << "Token(";
  switch (t.type) {
    case TokenType::Add:
      os << "Op(+))";
      return os;
    case TokenType::Subtract:
      os << "Op(-))";
      return os;
    case TokenType::LParen:
      os << "LParen)";
      return os;
    case TokenType::RParen:
      os << "RParen)";
      return os;
    case TokenType::Divide:
      os << "Op(/))";
      return os;
    case TokenType::Multiply:
      os << "Op(*))";
      return os;
    case TokenType::Num:
      os << "Value(" << t.val << "))";
      return os;
    default:
      os << "UNKNOWN)";
      return os;
  }
}

int evaluate(int x, int y, const Token& op) {
  switch (op.type) {
    case TokenType::Add:
      return x + y;
    case TokenType::Subtract:
      return x - y;
    case TokenType::Multiply:
      return x * y;
    case TokenType::Divide:
      return x / y;
    default:
      throw std::invalid_argument("unkown TokenType");
  }
}


int eval(std::string_view expr) {
  std::size_t current_index = 0;
  std::stack<Token> tokens;
  while (current_index < expr.size()) {
    while (std::isspace(expr[current_index])) ++current_index;
    if (current_index >= expr.size()) break;
    char c = expr[current_index];
    switch (c) {
      case '(':
        tokens.push(Token(TokenType::LParen));
        ++current_index;
        break;
      case ')': {
        auto arg2 = tokens.top();
        tokens.pop();
        auto arg1 = tokens.top();
        tokens.pop();
        auto op = tokens.top();
        tokens.pop();
        if (tokens.top().type == TokenType::LParen) tokens.pop(); // pop lparen
        if (!arg1.is_value() || !arg2.is_value()) {
          throw std::invalid_argument("invalid input expression");
        }
        tokens.push(Token(evaluate(arg1.val, arg2.val, op)));
        ++current_index;
        break;
      }
      case '+':
        tokens.push(Token(TokenType::Add));
        ++current_index;
        break;
      case '-':
        tokens.push(Token(TokenType::Subtract));
        ++current_index;
        break;
      case '/':
        tokens.push(Token(TokenType::Subtract));
        ++current_index;
        break;
      case '*': 
        tokens.push(Token(TokenType::Multiply));
        ++current_index;
        break;
      default: {
        if (!std::isdigit(c)) {
          throw std::invalid_argument("bad expression");
        }
        std::stringstream ss;
        while (current_index < expr.size() - 1 && std::isdigit(expr[current_index])) {
          ss << expr[current_index];
          ++current_index;
        }
        const int val = std::atoi(ss.str().c_str());
        tokens.push(Token(val));
      }
    }
  }
  return tokens.top().val;
}

int main() {
  auto e1 = "(* (+ 113 2) (- 2 91))";
  std::cout << e1 << " = " << eval(e1) << std::endl;
  return 0;
}

package parser;

import java.util.Stack;

public class Parser {
    public int evaluate(Token op, Token arg1, Token arg2) throws IllegalArgumentException {
        switch (op.type()) {
            case ADD:
                return arg1.value() + arg2.value();
            case SUB:
                return arg1.value() - arg2.value();
            case MUL:
                return arg1.value() * arg2.value();
            case DIV:
                return arg1.value() / arg2.value();
            default:
                throw new IllegalArgumentException("Unrecognized op type");
        }
    }

    public int eval(String expr) throws IllegalArgumentException {
        if (expr.isEmpty()) {
            throw new IllegalArgumentException();
        }
        var exprStack = new Stack<Token>();
        for (int i = 0; i < expr.length(); i++) {
            var c = expr.charAt(i);
            if (c == ' ') continue;

            switch (c) {
            case '(':
                exprStack.push(new Token(TokenType.LPAREN));
                break;
            case ')':
                var rVal = exprStack.pop();
                var lVal = exprStack.pop();
                var op = exprStack.pop();
                exprStack.pop();
                var newVal = evaluate(op, rVal, lVal);
                exprStack.push(new Token(newVal));
                break;
            case '+':
                exprStack.push(new Token(TokenType.ADD));
                break;
            case '-':
                if (i < (expr.length() - 1) && !(expr.charAt(i+1) == ' ')) {
                    var strBuilder = new StringBuilder(c);
                    i++;
                    c = expr.charAt(i);
                    while (Character.isDigit(c)) {
                        strBuilder.append(c);
                        i++;
                        c = expr.charAt(i);
                    }
                    break;
                }
                exprStack.push(new Token(TokenType.SUB));
                break;
            case '*':
                exprStack.push(new Token(TokenType.MUL));
                break;
            case '/':
                exprStack.push(new Token(TokenType.DIV));
                break;
            default:
                if (Character.isDigit(c)) {
                    var strBuilder = new StringBuilder(c);
                    i++;
                    c = expr.charAt(i);
                    while (Character.isDigit(c)) {
                        strBuilder.append(c);
                        i++;
                        c = expr.charAt(i);
                    }
                    var num = Integer.parseInt(strBuilder.toString());
                    exprStack.push(new Token(num));
                    break;
                }
                throw new IllegalArgumentException("unrecognized token");
            }
        }
        return exprStack.pop().value();
    }
}

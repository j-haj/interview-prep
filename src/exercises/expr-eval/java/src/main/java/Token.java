
/**
 * Tokens represent each part of the tokenized espression. They consist of left
 * parens, right parens, binary math ops, and numbers.
 */
public class Token {
    private Integer value;
    private TokenType type;

    public Token(TokenType t) {
        type = t;
        value = -1;
    }

    public Token(int v) {
        type = TokenType.VAL;
        value = v;
    }

    public boolean isValue() { return type == TokenType.VAL; }
    public int value() { return value; }
    public TokenType type() { return type; }
}

import parser.Parser;

import org.junit.jupiter.api.Test;

class ParserTest {

    @Test
    void AddTest() {
        var expr = "(+ 1 2)";
        var p = new Parser();
        int actual = p.eval(expr);
        int expected = 3;
        assert(expected == actual);
    }
}

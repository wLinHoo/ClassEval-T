package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BalancedBracketsTest {

    @Test
    public void testClearExpr() {
        BalancedBrackets b = new BalancedBrackets("a(b)c");
        b.clearExpr();
        assertEquals("()", b.getExpr());
    }

    @Test
    public void testClearExpr2() {
        BalancedBrackets b = new BalancedBrackets("a(b){c}");
        b.clearExpr();
        assertEquals("(){}", b.getExpr());
    }

    @Test
    public void testClearExpr3() {
        BalancedBrackets b = new BalancedBrackets("[a](b){c}");
        b.clearExpr();
        assertEquals("[](){}", b.getExpr());
    }

    @Test
    public void testClearExpr4() {
        BalancedBrackets b = new BalancedBrackets("[a(b){c}");
        b.clearExpr();
        assertEquals("[(){}", b.getExpr());
    }

    @Test
    public void testClearExpr5() {
        BalancedBrackets b = new BalancedBrackets("a(b){c}]");
        b.clearExpr();
        assertEquals("(){}]", b.getExpr());
    }

    @Test
    public void testCheckBalancedBrackets() {
        BalancedBrackets b = new BalancedBrackets("a(b)c");
        assertTrue(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets2() {
        BalancedBrackets b = new BalancedBrackets("a(b){c}");
        assertTrue(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets3() {
        BalancedBrackets b = new BalancedBrackets("[a](b){c}");
        assertTrue(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets4() {
        BalancedBrackets b = new BalancedBrackets("[a(b){c}");
        assertFalse(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets5() {
        BalancedBrackets b = new BalancedBrackets("a(b{c}]");
        assertFalse(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets6() {
        BalancedBrackets b = new BalancedBrackets("a(b{c]]");
        assertFalse(b.checkBalancedBrackets());
    }

    @Test
    public void testCheckBalancedBrackets7() {
        BalancedBrackets b = new BalancedBrackets("[a)(b){c}");
        assertFalse(b.checkBalancedBrackets());
    }

    @Test
    public void testMain() {
        BalancedBrackets b = new BalancedBrackets("a(b)c");
        b.clearExpr();
        assertEquals("()", b.getExpr());
        assertTrue(b.checkBalancedBrackets());
    }

    @Test
    public void testMain2() {
        BalancedBrackets b = new BalancedBrackets("[a(b){c}");
        b.clearExpr();
        assertEquals("[(){}", b.getExpr());
        assertFalse(b.checkBalancedBrackets());
    }

    @Test
    public void testMain3() {
        BalancedBrackets b = new BalancedBrackets("a(b{c}]");
        b.clearExpr();
        assertEquals("({}]", b.getExpr());
        assertFalse(b.checkBalancedBrackets());
    }
}
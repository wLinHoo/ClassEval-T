package test_cases;
import to_be_tested.CurrencyConverter;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Set;

import static org.junit.jupiter.api.Assertions.*;

public class CurrencyConverterTest {
    private CurrencyConverter cc;

    @BeforeEach
    void setUp() {
        cc = new CurrencyConverter();
    }

    @Test
    void testConvert_1() {
        double res = cc.convert(64, "CNY", "USD");
        assertEquals(10.0, res, 0.0001);
    }

    @Test
    void testConvert_2() {
        double res = cc.convert(64, "USD", "USD");
        assertEquals(64, res, 0.0001);
    }

    @Test
    void testConvert_3() {
        double res = cc.convert(64, "CNY", "GBP");
        assertEquals(7.1999999999999, res, 0.0001);
    }

    @Test
    void testConvert_4() {
        double res = cc.convert(64, "USD", "GBP");
        assertEquals(46.08, res, 0.0001);
    }

    @Test
    void testConvert_5() {
        double res = cc.convert(64, "USD", "CAD");
        assertEquals(78.72, res, 0.0001);
    }

    @Test
    void testConvert_6() {
        double res = cc.convert(64, "???", "USD");
        assertEquals(-1, res, 0.0001);
    }

    @Test
    void testGetSupportedCurrencies_1() {
        Set<String> res = cc.getSupportedCurrencies();
        assertTrue(res.containsAll(Set.of("USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY")));
    }

    @Test
    void testGetSupportedCurrencies_2() {
        Set<String> res = cc.getSupportedCurrencies();
        assertTrue(res.containsAll(Set.of("USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY")));
    }

    @Test
    void testGetSupportedCurrencies_3() {
        Set<String> res = cc.getSupportedCurrencies();
        assertTrue(res.containsAll(Set.of("USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY")));
    }

    @Test
    void testGetSupportedCurrencies_4() {
        Set<String> res = cc.getSupportedCurrencies();
        assertTrue(res.containsAll(Set.of("USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY")));
    }

    @Test
    void testGetSupportedCurrencies_5() {
        Set<String> res = cc.getSupportedCurrencies();
        assertTrue(res.containsAll(Set.of("USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY")));
    }

    @Test
    void testAddCurrencyRate_1() {
        boolean res = cc.addCurrencyRate("KRW", 1308.84);
        assertTrue(res);
        assertEquals(1308.84, cc.getRates().get("KRW"), 0.0001);
    }

    @Test
    void testAddCurrencyRate_2() {
        boolean res = cc.addCurrencyRate("aaa", 1.0);
        assertTrue(res);
        assertEquals(1.0, cc.getRates().get("aaa"), 0.0001);
    }

    @Test
    void testAddCurrencyRate_3() {
        boolean res = cc.addCurrencyRate("bbb", 2.0);
        assertTrue(res);
        assertEquals(2.0, cc.getRates().get("bbb"), 0.0001);
    }

    @Test
    void testAddCurrencyRate_4() {
        boolean res = cc.addCurrencyRate("ccc", 3.0);
        assertTrue(res);
        assertEquals(3.0, cc.getRates().get("ccc"), 0.0001);
    }

    @Test
    void testAddCurrencyRate_5() {
        boolean res = cc.addCurrencyRate("ddd", 4.0);
        assertTrue(res);
        assertEquals(4.0, cc.getRates().get("ddd"), 0.0001);
    }

    @Test
    void testAddCurrencyRate_6() {
        boolean res = cc.addCurrencyRate("USD", 1.0);
        assertFalse(res);
    }

    @Test
    void testUpdateCurrencyRate_1() {
        boolean res = cc.updateCurrencyRate("CNY", 7.18);
        assertTrue(res);
        assertEquals(7.18, cc.getRates().get("CNY"), 0.0001);
    }

    @Test
    void testUpdateCurrencyRate_2() {
        boolean res = cc.updateCurrencyRate("CNY", 1.0);
        assertTrue(res);
        assertEquals(1.0, cc.getRates().get("CNY"), 0.0001);
    }

    @Test
    void testUpdateCurrencyRate_3() {
        boolean res = cc.updateCurrencyRate("CNY", 2.0);
        assertTrue(res);
        assertEquals(2.0, cc.getRates().get("CNY"), 0.0001);
    }

    @Test
    void testUpdateCurrencyRate_4() {
        boolean res = cc.updateCurrencyRate("CNY", 3.0);
        assertTrue(res);
        assertEquals(3.0, cc.getRates().get("CNY"), 0.0001);
    }

    @Test
    void testUpdateCurrencyRate_5() {
        boolean res = cc.updateCurrencyRate("CNY", 4.0);
        assertTrue(res);
        assertEquals(4.0, cc.getRates().get("CNY"), 0.0001);
    }

    @Test
    void testUpdateCurrencyRate_6() {
        boolean res = cc.updateCurrencyRate("???", 7.18);
        assertFalse(res);
    }
}
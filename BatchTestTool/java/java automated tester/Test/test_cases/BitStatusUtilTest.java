package test_cases;
import to_be_tested.BitStatusUtil;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BitStatusUtilTest {

    @org.junit.Test
    @Test
    public void testAdd() {
        assertEquals(6, BitStatusUtil.add(2, 4));
    }

    @Test
    public void testAdd2() {
        assertEquals(2, BitStatusUtil.add(2, 0));
    }

    @Test
    public void testAdd3() {
        assertEquals(0, BitStatusUtil.add(0, 0));
    }

    @Test
    public void testAdd4() {
        assertEquals(2, BitStatusUtil.add(0, 2));
    }

    @Test
    public void testAdd5() {
        assertEquals(2, BitStatusUtil.add(2, 2));
    }

    @Test
    public void testHas() {
        assertTrue(BitStatusUtil.has(6, 2));
    }

    @Test
    public void testHas2() {
        assertFalse(BitStatusUtil.has(8, 2));
    }

    @Test
    public void testHas3() {
        assertTrue(BitStatusUtil.has(6, 4));
    }

    @Test
    public void testHas4() {
        assertFalse(BitStatusUtil.has(8, 6));
    }

    @Test
    public void testHas5() {
        assertTrue(BitStatusUtil.has(6, 6));
    }

    @Test
    public void testRemove() {
        assertEquals(4, BitStatusUtil.remove(6, 2));
    }

    @Test
    public void testRemove2() {
        assertEquals(8, BitStatusUtil.remove(8, 2));
    }

    @Test
    public void testRemove3() {
        assertEquals(2, BitStatusUtil.remove(6, 4));
    }

    @Test
    public void testRemove4() {
        assertEquals(8, BitStatusUtil.remove(8, 6));
    }

    @Test
    public void testRemove5() {
        assertEquals(0, BitStatusUtil.remove(6, 6));
    }

    @Test
    public void testCheck() {
        assertDoesNotThrow(() -> BitStatusUtil.check(2));
    }

    @Test
    public void testCheck2() {
        assertThrows(IllegalArgumentException.class, () -> BitStatusUtil.check(3));
    }

    @Test
    public void testCheck3() {
        assertThrows(IllegalArgumentException.class, () -> BitStatusUtil.check(-1));
    }

    @Test
    public void testCheck4() {
        assertThrows(IllegalArgumentException.class, () -> BitStatusUtil.check(2, 3, 4));
    }

    @Test
    public void testCheck5() {
        assertThrows(IllegalArgumentException.class, () -> BitStatusUtil.check(2, 3, 4, 5));
    }

    @Test
    public void testMain() {
        assertEquals(6, BitStatusUtil.add(2, 4));
        assertTrue(BitStatusUtil.has(6, 2));
        assertEquals(4, BitStatusUtil.remove(6, 2));
        assertThrows(IllegalArgumentException.class, () -> BitStatusUtil.check(2, 3, 4));
    }
}
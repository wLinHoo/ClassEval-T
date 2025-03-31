package test_cases;
import to_be_tested.CamelCaseMap;

import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNull;

public class CamelCaseMapTest {
    @Nested
class a {

        @Test
        public void testGetitem1() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            assertEquals("John", camelizeMap.get("first_name"));
        }

        @Test
        public void testGetitem2() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("last_name", "Doe");
            assertEquals("Doe", camelizeMap.get("last_name"));
        }

        @Test
        public void testGetitem3() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("age", 30);
            assertEquals(30, camelizeMap.get("age"));
        }

        @Test
        public void testGetitem4() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            assertEquals("John", camelizeMap.get("first_Name"));
        }

        @Test
        public void testGetitem5() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            assertEquals("John", camelizeMap.get("firstName"));
        }

        @Test
        public void testSetitem1() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("first_name", "newname");
            assertEquals("newname", camelizeMap.get("first_name"));
        }

        @Test
        public void testSetitem2() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("first_name", "John");
            assertEquals("John", camelizeMap.get("first_name"));
        }

        @Test
        public void testSetitem3() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("first_Name", "newname");
            assertEquals("newname", camelizeMap.get("first_name"));
        }

        @Test
        public void testSetitem4() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("firstName", "newname");
            assertEquals("newname", camelizeMap.get("first_name"));
        }

        @Test
        public void testSetitem5() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("first_name", "");
            assertEquals("", camelizeMap.get("first_name"));
        }

        @Test
        public void testDelitem1() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("last_name", "Doe");
            camelizeMap.remove("first_name");
            assertEquals("Doe", camelizeMap.get("last_name"));
        }

        @Test
        public void testDelitem2() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.remove("first_name");
            assertNull(camelizeMap.get("first_name"));
        }

        @Test
        public void testDelitem3() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.remove("first_Name");
            assertNull(camelizeMap.get("first_name"));
        }

        @Test
        public void testDelitem4() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.remove("firstName");
            assertNull(camelizeMap.get("first_name"));
        }

        @Test
        public void testDelitem5() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "");
            camelizeMap.remove("first_name");
            assertNull(camelizeMap.get("first_name"));
        }

        @Test
        public void testIter1() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("first_name", "John");
            camelizeMap.put("last_name", "Doe");
            camelizeMap.put("age", 30);
            String[] expectedKeys = {"firstName", "lastName", "age"};
            int i = 0;
            for (String key : camelizeMap.keySet()) {
                assertEquals(expectedKeys[i], key);
                i++;
            }
        }

        @Test
        public void testIter2() {
            CamelCaseMap camelizeMap = new CamelCaseMap();
            camelizeMap.put("firstname", "John");
            camelizeMap.put("lastname", "Doe");
            camelizeMap.put("age", 30);
            String[] expectedKeys = {"firstname", "lastname", "age"};
            int i = 0;
            for (String key : camelizeMap.keySet()) {
                assertEquals(expectedKeys[i], key);
                i++;
            }
        }

    }

    @Test
    public void testIter3() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_Name", "John");
        camelizeMap.put("last_Name", "Doe");
        camelizeMap.put("age", 30);
        String[] expectedKeys = {"firstName", "lastName", "age"};
        int i = 0;
        for (String key : camelizeMap.keySet()) {
            assertEquals(expectedKeys[i], key);
            i++;
        }
    }

    @Test
    public void testIter4() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_Name", "John");
        camelizeMap.put("last_Name", "Doe");
        String[] expectedKeys = {"firstName", "lastName"};
        int i = 0;
        for (String key : camelizeMap.keySet()) {
            assertEquals(expectedKeys[i], key);
            i++;
        }
    }

    @Test
    public void testIter5() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_Name", "John");
        String[] expectedKeys = {"firstName"};
        int i = 0;
        for (String key : camelizeMap.keySet()) {
            assertEquals(expectedKeys[i], key);
            i++;
        }
    }

    @Test
    public void testLen1() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_name", "John");
        assertEquals(1, camelizeMap.size());
    }

    @Test
    public void testLen2() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("last_name", "Doe");
        assertEquals(1, camelizeMap.size());
    }

    @Test
    public void testLen3() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("age", 30);
        assertEquals(1, camelizeMap.size());
    }

    @Test
    public void testLen4() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_name", "John");
        camelizeMap.put("last_Name", "Doe");
        camelizeMap.put("age", 30);
        assertEquals(3, camelizeMap.size());
    }

    @Test
    public void testLen5() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals(0, camelizeMap.size());
    }

    @Test
    public void testConvertKey1() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("aaaBbb", camelizeMap._convertKey("aaa_bbb"));
    }

    @Test
    public void testConvertKey2() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("firstName", camelizeMap._convertKey("first_name"));
    }

    @Test
    public void testConvertKey3() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("lastName", camelizeMap._convertKey("last_name"));
    }

    @Test
    public void testConvertKey4() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("cccDdd", camelizeMap._convertKey("ccc_ddd"));
    }

    @Test
    public void testConvertKey5() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("eeeFff", camelizeMap._convertKey("eee_fff"));
    }

    @Test
    public void testConvertKey6() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        assertEquals("1234", camelizeMap._convertKey(String.valueOf(1234)));
    }


    @Test
    public void testToCamelCase1() {
        assertEquals("aaaBbb", CamelCaseMap._toCamelCase("aaa_bbb"));
    }

    @Test
    public void testToCamelCase2() {
        assertEquals("firstName", CamelCaseMap._toCamelCase("first_name"));
    }

    @Test
    public void testToCamelCase3() {
        assertEquals("lastName", CamelCaseMap._toCamelCase("last_name"));
    }

    @Test
    public void testToCamelCase4() {
        assertEquals("cccDdd", CamelCaseMap._toCamelCase("ccc_ddd"));
    }

    @Test
    public void testToCamelCase5() {
        assertEquals("eeeFff", CamelCaseMap._toCamelCase("eee_fff"));
    }

    @Test
    public void testCamelCaseMap() {
        CamelCaseMap camelizeMap = new CamelCaseMap();
        camelizeMap.put("first_name", "John");
        assertEquals("John", camelizeMap.get("first_name"));

        camelizeMap.put("first_name", "John");
        camelizeMap.put("first_name", "newname");
        assertEquals("newname", camelizeMap.get("first_name"));
    }
}


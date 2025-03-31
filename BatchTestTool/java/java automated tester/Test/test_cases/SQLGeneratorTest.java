package test_cases;
import to_be_tested.SQLGenerator;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class SQLGeneratorTestSelect {

    @Test
    void testSelect1() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1"}, "field2 = value1");
        assertEquals("SELECT field1 FROM table1 WHERE field2 = value1;", result);
    }

    @Test
    void testSelect2() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1", "field2"}, "field3 = value1");
        assertEquals("SELECT field1, field2 FROM table1 WHERE field3 = value1;", result);
    }

    @Test
    void testSelect3() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1, field2"}, "field3 = value1");
        assertEquals("SELECT field1, field2 FROM table1 WHERE field3 = value1;", result);
    }

    @Test
    void testSelect4() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1, field2"}, "field3 = value1, field4 = value2");
        assertEquals("SELECT field1, field2 FROM table1 WHERE field3 = value1, field4 = value2;", result);
    }

    @Test
    void testSelect5() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1"}, "field2 = value1, field3 = value2");
        assertEquals("SELECT field1 FROM table1 WHERE field2 = value1, field3 = value2;", result);
    }

    @Test
    void testSelect6() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.select(new String[]{"field1"}, null);
        assertEquals("SELECT field1 FROM table1;", result);
    }
}

class SQLGeneratorTestInsert {

    @Test
    void testInsert() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.insert(new java.util.HashMap<String, String>() {{
            put("field1", "value1");
            put("field2", "value2");
        }});
        assertEquals("INSERT INTO table1 (field1, field2) VALUES ('value1', 'value2');", result);
    }

    @Test
    void testInsert2() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.insert(new java.util.HashMap<String, String>() {{
            put("field1", "value1");
            put("field2", "value2");
            put("field3", "value3");
        }});
        assertEquals("INSERT INTO table1 (field1, field2, field3) VALUES ('value1', 'value2', 'value3');", result);
    }

    @Test
    void testInsert3() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.insert(new java.util.HashMap<String, String>() {{
            put("field1", "value1");
            put("field2", "value2");
            put("field3", "value3");
            put("field4", "value4");
        }});
        assertEquals("INSERT INTO table1 (field1, field2, field3, field4) VALUES ('value1', 'value2', 'value3', 'value4');", result);
    }

    @Test
    void testInsert4() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.insert(new java.util.HashMap<String, String>() {{
            put("field1", "value1");
            put("field2", "value2");
            put("field3", "value3");
            put("field4", "value4");
            put("field5", "value5");
        }});
        assertEquals("INSERT INTO table1 (field1, field2, field3, field4, field5) VALUES ('value1', 'value2', 'value3', 'value4', 'value5');", result);
    }

    @Test
    void testInsert5() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.insert(new java.util.HashMap<String, String>() {{
            put("field1", "value1");
            put("field2", "value2");
            put("field3", "value3");
            put("field4", "value4");
            put("field5", "value5");
            put("field6", "value6");
        }});
        assertEquals("INSERT INTO table1 (field1, field2, field3, field4, field5, field6) VALUES ('value1', 'value2', 'value3', 'value4', 'value5', 'value6');", result);
    }
}

class SQLGeneratorTestUpdate {

    @Test
    void testUpdate() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.update(new java.util.HashMap<String, String>() {{
            put("field1", "new_value1");
            put("field2", "new_value2");
        }}, "field3 = value1");
        assertEquals("UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2' WHERE field3 = value1;", result);
    }

    @Test
    void testUpdate2() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.update(new java.util.HashMap<String, String>() {{
            put("field1", "new_value1");
            put("field2", "new_value2");
            put("field3", "new_value3");
        }}, "field4 = value1");
        assertEquals("UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3' WHERE field4 = value1;", result);
    }

    @Test
    void testUpdate3() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.update(new java.util.HashMap<String, String>() {{
            put("field1", "new_value1");
            put("field2", "new_value2");
            put("field3", "new_value3");
            put("field4", "new_value4");
        }}, "field5 = value1");
        assertEquals("UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4' WHERE field5 = value1;", result);
    }

    @Test
    void testUpdate4() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.update(new java.util.HashMap<String, String>() {{
            put("field1", "new_value1");
            put("field2", "new_value2");
            put("field3", "new_value3");
            put("field4", "new_value4");
            put("field5", "new_value5");
        }}, "field6 = value1");
        assertEquals("UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4', field5 = 'new_value5' WHERE field6 = value1;", result);
    }

    @Test
    void testUpdate5() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.update(new java.util.HashMap<String, String>() {{
            put("field1", "new_value1");
            put("field2", "new_value2");
            put("field3", "new_value3");
            put("field4", "new_value4");
            put("field5", "new_value5");
            put("field6", "new_value6");
        }}, "field7 = value1");
        assertEquals("UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4', field5 = 'new_value5', field6 = 'new_value6' WHERE field7 = value1;", result);
    }
}

class SQLGeneratorTestDelete {

    @Test
    void testDelete() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.delete("field1 = value1");
        assertEquals("DELETE FROM table1 WHERE field1 = value1;", result);
    }

    @Test
    void testDelete2() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.delete("field1 = value1 AND field2 = value2");
        assertEquals("DELETE FROM table1 WHERE field1 = value1 AND field2 = value2;", result);
    }

    @Test
    void testDelete3() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.delete("field1 = value1 AND field2 = value2 AND field3 = value3");
        assertEquals("DELETE FROM table1 WHERE field1 = value1 AND field2 = value2 AND field3 = value3;", result);
    }

    @Test
    void testDelete4() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.delete("field1 = value1 OR field2 = value2");
        assertEquals("DELETE FROM table1 WHERE field1 = value1 OR field2 = value2;", result);
    }

    @Test
    void testDelete5() {
        SQLGenerator sql = new SQLGenerator("table1");
        String result = sql.delete("field1 = value1 OR field2 = value2 OR field3 = value3");
        assertEquals("DELETE FROM table1 WHERE field1 = value1 OR field2 = value2 OR field3 = value3;", result);
    }
}

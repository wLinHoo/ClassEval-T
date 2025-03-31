package test_cases;
import to_be_tested.SQLQueryBuilder;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class SQLQueryBuilderTest {

    @Test
    public void testSelect1() {
        String[] columns = {"id", "name"};
        Map<String, String> where = new HashMap<>();
        where.put("age", "30");
        String result = SQLQueryBuilder.select("users", columns, where);
        assertEquals("SELECT id, name FROM users WHERE age='30'", result);
    }

    @Test
    public void testSelect2() {
        String[] columns = {"id", "name"};
        Map<String, String> where = new HashMap<>();
        where.put("age", "18");
        String result = SQLQueryBuilder.select("students", columns, where);
        assertEquals("SELECT id, name FROM students WHERE age='18'", result);
    }

    @Test
    public void testSelect3() {
        String[] columns = {"id", "name"};
        Map<String, String> where = new HashMap<>();
        where.put("price", "1.0");
        String result = SQLQueryBuilder.select("items", columns, where);
        assertEquals("SELECT id, name FROM items WHERE price='1.0'", result);
    }

    @Test
    public void testSelect4() {
        String[] columns = {"id"};
        Map<String, String> where = new HashMap<>();
        where.put("age", "30");
        String result = SQLQueryBuilder.select("users", columns, where);
        assertEquals("SELECT id FROM users WHERE age='30'", result);
    }

    @Test
    public void testSelect5() {
        String[] columns = {"name"};
        Map<String, String> where = new HashMap<>();
        where.put("age", "30");
        String result = SQLQueryBuilder.select("users", columns, where);
        assertEquals("SELECT name FROM users WHERE age='30'", result);
    }

    @Test
    public void testSelect6() {
        String[] columns = {"name"};
        String result = SQLQueryBuilder.select("users", columns, null);
        assertEquals("SELECT name FROM users", result);
    }

    @Test
    public void testSelect7() {
        String result = SQLQueryBuilder.select("users", "*", null);
        assertEquals("SELECT * FROM users", result);
    }

    @Test
    public void testInsert1() {
        Map<String, String> data = new HashMap<>();
        data.put("name", "Tom");
        data.put("age", "30");
        String result = SQLQueryBuilder.insert("users", data);
        assertEquals("INSERT INTO users (name, age) VALUES ('Tom', '30')", result);
    }

    @Test
    public void testInsert2() {
        Map<String, String> data = new HashMap<>();
        data.put("name", "Tom");
        data.put("age", "18");
        String result = SQLQueryBuilder.insert("students", data);
        assertEquals("INSERT INTO students (name, age) VALUES ('Tom', '18')", result);
    }

    @Test
    public void testInsert3() {
        Map<String, String> data = new LinkedHashMap<>();
        data.put("name", "apple");
        data.put("price", "1.0");
        String result = SQLQueryBuilder.insert("items", data);
        assertEquals("INSERT INTO items (name, price) VALUES ('apple', '1.0')", result);
    }

    @Test
    public void testInsert4() {
        Map<String, String> data = new HashMap<>();
        data.put("name", "Tom");
        String result = SQLQueryBuilder.insert("users", data);
        assertEquals("INSERT INTO users (name) VALUES ('Tom')", result);
    }


    @Test
    public void testInsert5() {
        Map<String, String> data = new LinkedHashMap<>();
        data.put("name", "Tom");
        data.put("age", "30");
        data.put("region", "USA");
        String result = SQLQueryBuilder.insert("users", data);
        assertEquals("INSERT INTO users (name, age, region) VALUES ('Tom', '30', 'USA')", result);
    }

    @Test
    public void testDelete1() {
        Map<String, String> where = new HashMap<>();
        where.put("name", "Tom");
        String result = SQLQueryBuilder.delete("users", where);
        assertEquals("DELETE FROM users WHERE name='Tom'", result);
    }

    @Test
    public void testDelete2() {
        Map<String, String> where = new HashMap<>();
        where.put("name", "Tom");
        String result = SQLQueryBuilder.delete("students", where);
        assertEquals("DELETE FROM students WHERE name='Tom'", result);
    }

    @Test
    public void testDelete3() {
        Map<String, String> where = new HashMap<>();
        where.put("name", "apple");
        String result = SQLQueryBuilder.delete("items", where);
        assertEquals("DELETE FROM items WHERE name='apple'", result);
    }

    @Test
    public void testDelete4() {
        Map<String, String> where = new HashMap<>();
        where.put("name", "aaa");
        String result = SQLQueryBuilder.delete("items", where);
        assertEquals("DELETE FROM items WHERE name='aaa'", result);
    }

    @Test
    public void testDelete5() {
        Map<String, String> where = new HashMap<>();
        where.put("name", "bbb");
        String result = SQLQueryBuilder.delete("items", where);
        assertEquals("DELETE FROM items WHERE name='bbb'", result);
    }

    @Test
    public void testDelete6() {
        String result = SQLQueryBuilder.delete("items", null);
        assertEquals("DELETE FROM items", result);
    }

    @Test
    public void testUpdate1() {
        Map<String, String> data = new HashMap<>();
        data.put("age", "35");
        Map<String, String> where = new HashMap<>();
        where.put("name", "Tom");
        String result = SQLQueryBuilder.update("users", data, where);
        assertEquals("UPDATE users SET age='35' WHERE name='Tom'", result);
    }

    @Test
    public void testUpdate2() {
        Map<String, String> data = new HashMap<>();
        data.put("age", "18");
        Map<String, String> where = new HashMap<>();
        where.put("name", "Tom");
        String result = SQLQueryBuilder.update("students", data, where);
        assertEquals("UPDATE students SET age='18' WHERE name='Tom'", result);
    }

    @Test
    public void testUpdate3() {
        Map<String, String> data = new HashMap<>();
        data.put("price", "1.0");
        Map<String, String> where = new HashMap<>();
        where.put("name", "apple");
        String result = SQLQueryBuilder.update("items", data, where);
        assertEquals("UPDATE items SET price='1.0' WHERE name='apple'", result);
    }

    @Test
    public void testUpdate4() {
        Map<String, String> data = new HashMap<>();
        data.put("price", "1.0");
        Map<String, String> where = new HashMap<>();
        where.put("name", "aaa");
        String result = SQLQueryBuilder.update("items", data, where);
        assertEquals("UPDATE items SET price='1.0' WHERE name='aaa'", result);
    }

    @Test
    public void testUpdate5() {
        Map<String, String> data = new HashMap<>();
        data.put("price", "1.0");
        Map<String, String> where = new HashMap<>();
        where.put("name", "bbb");
        String result = SQLQueryBuilder.update("items", data, where);
        assertEquals("UPDATE items SET price='1.0' WHERE name='bbb'", result);
    }

    @Test
    public void testUpdate6() {
        Map<String, String> data = new HashMap<>();
        data.put("price", "1.0");
        String result = SQLQueryBuilder.update("items", data, null);
        assertEquals("UPDATE items SET price='1.0'", result);
    }

    @Test
    public void testMain() {
        String[] columns = {"id", "name"};
        Map<String, String> where = new HashMap<>();
        where.put("age", "30");
        assertEquals("SELECT id, name FROM users WHERE age='30'", SQLQueryBuilder.select("users", columns, where));
        assertEquals("INSERT INTO users (name, age) VALUES ('Tom', '30')", SQLQueryBuilder.insert("users", Map.of("name", "Tom", "age", "30")));
        assertEquals("DELETE FROM users WHERE name='Tom'", SQLQueryBuilder.delete("users", Map.of("name", "Tom")));
        assertEquals("UPDATE users SET age='35' WHERE name='Tom'", SQLQueryBuilder.update("users", Map.of("age", "35"), Map.of("name", "Tom")));
    }
}

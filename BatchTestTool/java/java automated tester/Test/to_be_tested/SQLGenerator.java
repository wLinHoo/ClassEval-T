package to_be_tested;

import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

public class SQLGenerator {

    public String tableName;

    public SQLGenerator(String tableName) {
        this.tableName = tableName;
    }

    public String insert(Map<String, String> data) {
        String fields = String.join(", ", data.keySet().stream().toArray(String[]::new));
        String values = String.join(", ", data.values().stream().map(Object::toString).toArray(String[]::new));
        String sql = "INSERT INTO " + tableName + " (" + fields + ") VALUES (" + values + ")";
        return sql + ";";
    }

    public String update(Map<String, String> data, String condition) {
        StringBuilder setClause = new StringBuilder();
        for (Map.Entry<String, String> entry : data.entrySet()) {
            setClause.append(entry.getKey()).append(" = '").append(entry.getValue()).append("', ");
        }
        String setClauseStr = setClause.toString().trim().replaceAll(", $", "");
        String sql = "UPDATE " + tableName + " SET " + setClauseStr + " WHERE " + condition;
        return sql + ";";
    }

    public String select(String[] fields, String condition) {
        if (fields == null) {
            fields = new String[] { "*" };
        } else {
            StringBuilder sb = new StringBuilder();
            for (String field : fields) {
                sb.append(field);
                sb.append(", ");
            }
            fields = sb.toString().split(", ");
        }
        StringBuilder sql = new StringBuilder("SELECT ");
        for (String field : fields) {
            sql.append(field);
            sql.append(" ");
        }
        sql.append("FROM ");
        sql.append(tableName);
        if (condition != null) {
            sql.append(" WHERE ");
            sql.append(condition);
        }
        return sql.toString() + ";";
    }

    public String selectFemaleUnderAge(int age) {
        return select(new String[] { "*" }, "age < " + age + " AND gender = 'female'");
    }

    public String selectByAgeRange(int minAge, int maxAge) {
        return select(new String[] { "*" }, "age BETWEEN " + minAge + " AND " + maxAge);
    }

    public String delete(String condition) {
        return "DELETE FROM " + tableName + " WHERE " + condition + ";";
    }
}

import java.util.Map;

public class SQLQueryBuilder {

    public static String insert(String table, Map<String, String> data) {
        StringBuilder keys = new StringBuilder();
        StringBuilder values = new StringBuilder();

        for (Map.Entry<String, String> entry : data.entrySet()) {
            keys.append(entry.getKey()).append(",");
            values.append("'").append(entry.getValue()).append("'");
        }

        keys.deleteCharAt(keys.length() - 1);
        values.deleteCharAt(values.length() - 1);

        return "INSERT INTO " + table + " (" + keys + ") VALUES (" + values + ")";
    }

    public static String delete(String table, Map<String, String> where) {
        StringBuilder query = new StringBuilder("DELETE FROM ").append(table);
        if (where != null) {
            query.append(" WHERE ").append(String.join(" AND ", where.entrySet().stream()
                    .map(entry -> entry.getKey() + "='" + entry.getValue() + "'")
                    .toArray(String[]::new)));
        }
        return query.toString();
    }

    public static String update(String table, Map<String, Object> data, Map<String, Object> where) {
        StringBuilder updateStr = new StringBuilder();
        for (Map.Entry<String, Object> entry : data.entrySet()) {
            updateStr.append(entry.getKey()).append("=").append("'").append(entry.getValue()).append("'").append(",");
        }
        updateStr.deleteCharAt(updateStr.length() - 1);
        String query = "UPDATE " + table + " SET " + updateStr;
        if (where != null) {
            StringBuilder whereStr = new StringBuilder();
            for (Map.Entry<String, Object> entry : where.entrySet()) {
                whereStr.append(entry.getKey()).append("=").append("'").append(entry.getValue()).append("'").append(" AND ");
            }
            whereStr.deleteCharAt(whereStr.length() - 3);
            query += " WHERE " + whereStr;
        }
        return query;
    }

    public static String select(String table, String columns, Map<String, String> where) {
        StringBuilder query = new StringBuilder("SELECT ");
        if (!columns.equals("*")) {
            query.append(String.join(", ", columns));
        } else {
            query.append("*");
        }
        query.append(" FROM ").append(table);
        if (where != null) {
            query.append(" WHERE ").append(String.join(" AND ", where.entrySet().stream()
                    .map(entry -> entry.getKey() + "='" + entry.getValue() + "'")
                    .toArray(String[]::new)));
        }
        return query.toString();
    }
}
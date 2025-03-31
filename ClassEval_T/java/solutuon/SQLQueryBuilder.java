package org.example;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

public class SQLQueryBuilder {

    public static String select(String table, String columns, Map<String, String> where) {
        if (columns == null) {
            columns = "*";
        }
        return select(table, columns.split(",\\s*"), where);
    }

    public static String select(String table, String[] columns, Map<String, String> where) {
        StringBuilder query = new StringBuilder("SELECT ");
        if (columns.length > 0) {
            query.append(String.join(", ", columns));
        } else {
            query.append("*");
        }
        query.append(" FROM ").append(table);

        if (where != null && !where.isEmpty()) {
            query.append(" WHERE ");
            Set<Map.Entry<String, String>> entrySet = where.entrySet();
            boolean first = true;
            for (Map.Entry<String, String> entry : entrySet) {
                if (!first) {
                    query.append(" AND ");
                }
                query.append(entry.getKey()).append("='").append(entry.getValue()).append("'");
                first = false;
            }
        }
        return query.toString();
    }

    public static String insert(String table, Map<String, String> data) {
        StringBuilder query = new StringBuilder("INSERT INTO ").append(table).append(" (");
        StringBuilder values = new StringBuilder(" VALUES (");

        boolean first = true;
        for (Map.Entry<String, String> entry : data.entrySet()) {
            if (!first) {
                query.append(", ");
                values.append(", ");
            }
            query.append(entry.getKey());
            values.append("'").append(entry.getValue()).append("'");
            first = false;
        }

        query.append(")");
        values.append(")");

        return query.append(values).toString();
    }

    public static String delete(String table, Map<String, String> where) {
        StringBuilder query = new StringBuilder("DELETE FROM ").append(table);

        if (where != null && !where.isEmpty()) {
            query.append(" WHERE ");
            Set<Map.Entry<String, String>> entrySet = where.entrySet();
            boolean first = true;
            for (Map.Entry<String, String> entry : entrySet) {
                if (!first) {
                    query.append(" AND ");
                }
                query.append(entry.getKey()).append("='").append(entry.getValue()).append("'");
                first = false;
            }
        }
        return query.toString();
    }

    public static String update(String table, Map<String, String> data, Map<String, String> where) {
        StringBuilder query = new StringBuilder("UPDATE ").append(table).append(" SET ");

        boolean first = true;
        for (Map.Entry<String, String> entry : data.entrySet()) {
            if (!first) {
                query.append(", ");
            }
            query.append(entry.getKey()).append("='").append(entry.getValue()).append("'");
            first = false;
        }

        if (where != null && !where.isEmpty()) {
            query.append(" WHERE ");
            Set<Map.Entry<String, String>> entrySet = where.entrySet();
            boolean firstWhere = true;
            for (Map.Entry<String, String> entry : entrySet) {
                if (!firstWhere) {
                    query.append(" AND ");
                }
                query.append(entry.getKey()).append("='").append(entry.getValue()).append("'");
                firstWhere = false;
            }
        }
        return query.toString();
    }
}

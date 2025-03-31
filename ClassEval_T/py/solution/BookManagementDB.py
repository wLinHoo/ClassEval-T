import sqlite3

class BookManagementDB:
    def __init__(self, db_name):
        self.connection = sqlite3.connect(db_name)
        self.cursor = self.connection.cursor()
        self.create_table()

    def create_table(self):
        self.cursor.execute('''
            CREATE TABLE IF NOT EXISTS books (
                id INTEGER PRIMARY KEY,
                title TEXT,
                author TEXT,
                available INTEGER
            )
            INSERT INTO books (title, author, available)
            VALUES (?, ?, 1)
            DELETE FROM books WHERE id = ?
            UPDATE books SET available = 0 WHERE id = ?
            UPDATE books SET available = 1 WHERE id = ?
            SELECT * FROM books
        ''')
        books = self.cursor.fetchall()
        return books

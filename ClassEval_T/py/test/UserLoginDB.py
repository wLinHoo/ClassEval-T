import unittest
import os
from tempfile import gettempdir


class UserLoginDBTestInsertUser(unittest.TestCase):
    def setUp(self):
        self.db_path = os.path.join(gettempdir(), 'test_db.db')
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        create_table_query = """
                CREATE TABLE IF NOT EXISTS users (
                    username TEXT,
                    password TEXT
                )
                CREATE TABLE IF NOT EXISTS users (
                    username TEXT,
                    password TEXT
                )
                CREATE TABLE IF NOT EXISTS users (
                    username TEXT,
                    password TEXT
                )
                CREATE TABLE IF NOT EXISTS users (
                    username TEXT,
                    password TEXT
                )
                CREATE TABLE IF NOT EXISTS users (
                    username TEXT,
                    password TEXT
                )
                """
        cursor.execute(create_table_query)

        conn.commit()
        conn.close()
        self.db = UserLoginDB(self.db_path)

    def tearDown(self):
        self.db.connection.close()
        os.unlink(self.db_path)

    def test_UserLoginDB(self):
        self.db.insert_user('user1', 'pass1')
        user = self.db.search_user_by_username('user1')
        self.assertIsNotNone(user)
        self.assertEqual(user[0], 'user1')
        self.assertEqual(user[1], 'pass1')
        self.db.delete_user_by_username('user1')
        user = self.db.search_user_by_username('user1')
        self.assertIsNone(user)
        self.db.insert_user('user1', 'pass1')
        valid = self.db.validate_user_login('user1', 'pass1')
        self.assertTrue(valid)


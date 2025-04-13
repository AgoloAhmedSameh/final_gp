import sqlite3
import random

# Define technical positions
technical_positions = [
    "Software Engineer", "Data Scientist", "Cybersecurity Analyst", "Network Engineer",
    "System Administrator", "Cloud Engineer", "AI Engineer", "Embedded Systems Engineer",
    "DevOps Engineer", "Database Administrator"
]

# Example first and last names
first_names = ["John", "Jane", "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Henry","Ahmed" , "Amjad" , "Abdelrahman" , "Jannah" , "Rawan" , "Mohamed" , "Menatullah" , "Marwa" , "Zainab"]
last_names = ["Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez" , "Mohamed" , "Sameh" , "Mahmoud" , "Feras" , "Wael" , "Eslam"]

def generate_email(first, last):
    return f"{first.lower()}.{last.lower()}@siemens.com"

def generate_phone():
    return f"+49 {random.randint(100,999)}-{random.randint(1000,9999)}-{random.randint(100,999)}"



def create_database():
    conn = sqlite3.connect("employees.db")
    cursor = conn.cursor()
    
    # Create table
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS employees (
            email TEXT PRIMARY KEY,
            password TEXT NOT NULL,
            first_name TEXT NOT NULL,
            last_name TEXT NOT NULL,
            phone_number TEXT NOT NULL,
            position TEXT NOT NULL
        )
    ''')
    
    # Insert 100 sample records
    employees = []
    for _ in range(1000):
        first = random.choice(first_names)
        last = random.choice(last_names)
        email = generate_email(first, last)
        password = "1234"
        phone_number = generate_phone()
        position = random.choice(technical_positions)
        
        employees.append((email, password, first, last, phone_number, position))
    
    cursor.executemany("""
        INSERT OR IGNORE INTO employees (email, password, first_name, last_name, phone_number, position)
        VALUES (?, ?, ?, ?, ?, ?)""", employees)
    
    conn.commit()
    conn.close()
    print("Database and table created with 1000 employees.")

if __name__ == "__main__":
    create_database()

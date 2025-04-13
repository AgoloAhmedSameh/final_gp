from fastapi import FastAPI, HTTPException, Depends
import sqlite3
from pydantic import BaseModel

db_path = "app/authentication/employees.db"
app = FastAPI()

class AuthRequest(BaseModel):
    email: str
    password: str

def get_user(email: str):
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    cursor.execute("SELECT first_name, last_name, email, phone_number, position, password FROM employees WHERE email = ?", (email,))
    user = cursor.fetchone()
    conn.close()
    return user

@app.post("/api/authenticate")
def authenticate(auth: AuthRequest):
    user = get_user(auth.email)
    
    if not user:
        return {"available": False, "user_info": None}
    
    first_name, last_name, email, phone_number, position, stored_password = user
    
    if stored_password != auth.password:
        return {"available": False, "user_info": None}
    
    return {
        "available": True,
        "user_info": {
            "first_name": first_name,
            "last_name": last_name,
            "email": email,
            "phone_number": phone_number,
            "position": position
        }
    }

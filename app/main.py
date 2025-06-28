import uvicorn

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

from app.analyze_code import analyze_api
from app.authentication import auth
from app.generate_testcases import generate_api

import os

app = FastAPI()

# include your route files
app.include_router(analyze_api.router)
app.include_router(auth.router)
app.include_router(generate_api.router)

app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:4200"],  # Allow frontend URL
    # allow_origins=["*"], 
    allow_credentials=True,
    allow_methods=["*"],  # Allow all HTTP methods (GET, POST, etc.)
    allow_headers=["*"],  # Allow all headers
)

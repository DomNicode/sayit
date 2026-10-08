import os
from fastapi import FastAPI 

app = FastAPI(title="Sayit Agent")
APP_VERSION = os.getenv("APP_VERSION", "dev")

@app.get("/health")
def health():
    return{"status": "ok", "version": APP_VERSION}
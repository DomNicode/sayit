from fastapi import FastAPI
from dotenv import load_dotenv
import os
from groq import AsyncGroq
from pydantic import BaseModel
from fastapi.middleware.cors import CORSMiddleware

class ChatRequest(BaseModel):
    message: str

load_dotenv()
api_key = os.getenv("GROQ_API_KEY")
client = AsyncGroq(api_key=api_key)

origins = os.getenv("CORS_ORIGINS", "").split(",")

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_methods=["GET", "POST"],
    allow_headers=["Content-Type"],
)

@app.get("/")
async def main():
    return{"Hello Here is Ai-based web app SayIt"}
@app.get("/api/health")
async def health():
    return{"status":"ok"}

@app.post("/api/chat")
async def inference(msg: ChatRequest):
    response = await client.chat.completions.create(
        model="openai/gpt-oss-120b",
        messages=[
            {"role": "system", "content": "Antworte dem Nutzer immer Höflich"},
            {"role": "user", "content": msg.message},
        ],
    )
    text = response.choices[0].message.content
    return{"reply": text}
from fastapi import FastAPI
from dotenv import load_dotenv
import os
from groq import AsyncGroq
from pydantic import BaseModel

class ChatRequest(BaseModel):
    message: str

load_dotenv()
api_key = os.getenv("GROQ_API_KEY")
client = AsyncGroq(api_key=api_key)
app = FastAPI()

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
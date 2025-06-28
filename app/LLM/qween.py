from transformers import AutoTokenizer, AutoModel
import torch
import random
from transformers import AutoModelForCausalLM

#Qween code (Amjad Notebook)
# model_qween_n = "Qwen/Qwen2.5-Coder-7B-Instruct"
# model_qween = AutoModelForCausalLM.from_pretrained(
#     model_qween_n,
#     torch_dtype="auto",
#     device_map="auto"
# )
# tokenizer_qween = AutoTokenizer.from_pretrained(model_qween_n)


import os
from langchain_groq import ChatGroq
from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain.chains import LLMChain
import pandas as pd

# Set your Groq API Key
os.environ["GROQ_API_KEY"] = "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"

# Initialize Groq LLM
llm = ChatGroq(model="llama-3.1-8b-instant")
LLM = llm | StrOutputParser()

# Wrapper function to generate responses from Groq
def generate_response(system_prompt, user_prompt):
    full_prompt = f"<|system|>\n{system_prompt}\n<|user|>\n{user_prompt}"
    response = LLM.invoke(full_prompt)
    return response
def Qwen(system_prompt, user_prompt):
    return generate_response(system_prompt, user_prompt)

# def Qwen(system_prompt , user_prompt):
#     messages = [
#         {"role": "system", "content": system_prompt},
#         {"role": "user", "content": user_prompt}
#     ]

#     # Apply chat template for tokenization
#     text = tokenizer_qween.apply_chat_template(
#         messages,
#         tokenize=False,
#         add_generation_prompt=True
#     )

#     # Prepare model inputs
#     model_inputs = tokenizer_qween([text], return_tensors="pt").to(model_qween.device)

#     # Generate responses from the model
#     generated_ids = model_qween.generate(
#         **model_inputs,
#         max_new_tokens=8000
#     )

#     # Trim the generated output to exclude input prompt
#     generated_ids = [
#         output_ids[len(input_ids):] for input_ids, output_ids in zip(model_inputs.input_ids, generated_ids)
#     ]

#     # Decode the generated output
#     response = tokenizer_qween.batch_decode(generated_ids, skip_special_tokens=True)[0]

#     return response
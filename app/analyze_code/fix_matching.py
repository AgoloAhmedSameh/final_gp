from app.LLM.qween import Qwen
from app.LLM.prompts import get_prompt_for_generate_function_from_description, DEFAULT_SYSTEM_PROMPT

def create_function_basedOn_descdescription(description, language):
    code = Qwen(DEFAULT_SYSTEM_PROMPT, get_prompt_for_generate_function_from_description(description, language))
    return code 
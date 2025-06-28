
from app.LLM.prompts import get_prompt_of_matching_judge, DEFAULT_SYSTEM_PROMPT
from app.LLM.qween import Qwen
def matching_judge(code , description ):
    usr_prompt = get_prompt_of_matching_judge(code , description)
    response = Qwen(DEFAULT_SYSTEM_PROMPT , usr_prompt) 
    cleaned_response = response.replace("<OUTPUT>", "").replace("</OUTPUT>", "").strip().split("\n")[0] 
    if cleaned_response == "Logical Bug Detected":
        return False 
    return True

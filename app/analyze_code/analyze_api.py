
from fastapi import FastAPI,APIRouter, HTTPException

from pydantic import BaseModel
from typing import List

# # Import your logic
from app.analyze_code.matchingJudge import matching_judge
from app.analyze_code.syntaxJudge import check_syntax
from app.analyze_code.fix_syntax import fix_syntax_error
from app.LLM.prompts import FEEDBACK_BOTH_BUG, FEEDBACK_MATCHING_BUG, FEEDBACK_NO_BUGS, FEEDBACK_SYNTAX_BUG
from app.analyze_code.fix_matching import create_function_basedOn_descdescription

router = APIRouter()

# Define the input model
class CodeInput(BaseModel):
    code: str
    description: str
    language: str
    dependencies: List[str]

# Define the output model
class CodeOutput(BaseModel):
    syntax_flag: bool
    matching_flag: bool
    feedback_message: str
    enhanced_code: str

@router.post("/api/analyze_code", response_model=CodeOutput)
def analyze_code(input_data: CodeInput):
    try:
        code = input_data.code
        description = input_data.description
        language = input_data.language
        dependices = input_data.dependices

        # Apply logic
        matching_flag = matching_judge(code, description)
        syntax_flag = check_syntax(language, code)

        if matching_flag == False and syntax_flag == True:
            feedback_message = FEEDBACK_MATCHING_BUG
            enhanced_code = create_function_basedOn_descdescription(description, language)
        elif matching_flag == True and syntax_flag == False:
            feedback_message = FEEDBACK_SYNTAX_BUG
            enhanced_code = fix_syntax_error(code, language)
        elif matching_flag == True and syntax_flag == True:
            feedback_message = FEEDBACK_NO_BUGS
            enhanced_code = ""
        else:
            feedback_message = FEEDBACK_BOTH_BUG
            enhanced_code = create_function_basedOn_descdescription(description, language)


        return CodeOutput(
            syntax_flag=syntax_flag,
            matching_flag=matching_flag,
            feedback_message=feedback_message,
            enhanced_code=enhanced_code
        )

    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))


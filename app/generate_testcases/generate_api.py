from fastapi import FastAPI,APIRouter, HTTPException
from app.InegretationTestClient.Integration_Testing.Integration_tester import Tester
from pydantic import BaseModel
from app.LLM.qween import Qwen
from app.LLM.prompts import (
    DEFAULT_SYSTEM_PROMPT,
    get_prompt_generate_description,
    get_generate_unit_test_cases_prompts,
    generate_prompt_feedback_correctness,
    generate_prompt_feedback_coverage,
)
from app.generate_testcases.correctness import calculate_correctness
from app.generate_testcases.coverage import calculate_coverage
from app.generate_testcases.parsing import (
    extract_code_and_asserts,
    extract_asserts_only,
    parse_llm_response,
)

router = APIRouter()

class TestCodeRequest(BaseModel):
    code: str
    description: str
    language: str
    type_of_testing: str

class TestCodeResponse(BaseModel):
    asserts: list[str]
    description: str
    coverage: float
    correctness: float
    failed_asserts: list[str]

@router.post("/api/test_code", response_model=TestCodeResponse)
def test_code(request: TestCodeRequest):
    code = request.code
    description = request.description
    language = request.language
    type_of_testing = request.type_of_testing

    # print("are you here?")
    
    # print(code)
    # print(description)
    # print(language)
    # print(type_of_testing)

    # Check if code is empty
    # Generate description if not provided
    if description == "":
        description = Qwen(DEFAULT_SYSTEM_PROMPT, get_prompt_generate_description(code, language))

    asserts = []
    failed_asserts = []
    corr = 0.0
    cov = 0.0

    if type_of_testing == "unit":
        result_llm = Qwen(DEFAULT_SYSTEM_PROMPT, get_generate_unit_test_cases_prompts(language, description, code))
        result = parse_llm_response(language, result_llm, code)
        if result is None:
            print("LLM output:", result_llm)  # For debugging
            raise HTTPException(status_code=500, detail="Failed to parse LLM response. Please check your input or LLM output format.")
        asserts, code = result

        corr, failed_asserts = calculate_correctness(code, asserts, language)
        cov = calculate_coverage(code, asserts, language)

        if corr < 0.5:
            feedback_code, feedback_asserts = extract_code_and_asserts(
                Qwen(DEFAULT_SYSTEM_PROMPT, generate_prompt_feedback_correctness(code, failed_asserts))
            )
            corr, failed_asserts = calculate_correctness(feedback_code, feedback_asserts, language)
            cov = calculate_coverage(feedback_code, feedback_asserts, language)
            code = feedback_code
            asserts = feedback_asserts

        if cov < 0.5:
            feedback_asserts = extract_asserts_only(
                Qwen(DEFAULT_SYSTEM_PROMPT, generate_prompt_feedback_coverage(asserts))
            )
            corr, failed_asserts = calculate_correctness(code, feedback_asserts, language)
            cov = calculate_coverage(code, feedback_asserts, language)
            asserts = feedback_asserts

    elif type_of_testing == "integration":
      tester=Tester(Qwen)
      code = request.code
      language = request.language
      codes,asserts=tester.test(code,language)
      Final_asserts=[]
      final_corr=[]
      final_cov=[]
      for i in range(len(asserts)):
        Final_five_asserts,code=parse_llm_response(language, asserts[i], code[i])
        Final_asserts.append((Final_five_asserts,codes[i]))
      for i in Final_asserts:
        corr, failed_asserts = calculate_correctness(i[1], i[0], language)
        cov = calculate_coverage(i[1], i[0], language)
        final_corr.append(corr)
        final_cov.append(cov)
      corr=sum(final_corr)/len(final_corr) if final_corr else 0.0
      cov=sum(final_cov)/len(final_cov) if final_cov else 0.0
    else:
        raise HTTPException(status_code=400, detail="Invalid type_of_testing. Must be 'unit' or 'integration'.")




    return TestCodeResponse(
        asserts=asserts,
        description=description,
        coverage=cov,
        correctness=corr,
        failed_asserts=failed_asserts,
    )

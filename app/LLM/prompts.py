
DEFAULT_SYSTEM_PROMPT = "You are Qwen, created by Alibaba Cloud."
FEEDBACK_NO_BUGS = """The code provided is a perfect match to the description, ensuring that all functionalities align precisely with the intended purpose.\n\nAdditionally, it has been thoroughly reviewed to be free from any syntax errors or bugs, guaranteeing smooth execution.\n\nPlease press "Continue" to start testing."""
FEEDBACK_SYNTAX_BUG = """Your code is a perfect match for the description you provided, ensuring it aligns well with the intended functionality. However, it contains some syntax errors that may prevent it from running correctly. \n \n Below is the suggested code after applying fixes. \n \n Please choose whether you would like to continue with your original code or proceed with the corrected version."""
FEEDBACK_MATCHING_BUG =  """Your code does not fully match the description you provided, but it is free from syntax errors.\n\nTo better align it with your requirements, I have made some adjustments and prepared a suggested version.\n\nPlease review the suggested code and choose whether you would like to continue with your original code or proceed with the corrected version."""
FEEDBACK_BOTH_BUG = """Your code does not match the description you provided, and contains syntax errors.\nBelow is a suggested version of your code with fixes.\n\nPlease review the changes and choose whether you would like to continue with your original code or proceed with the corrected version."""


def get_prompt_of_matching_judge(code , description):
    
    prompt = f"""You are a software debugging expert specializing in *Logical Bug Detection*. 
    Your task is to analyze the given code and its description ensure that this code satisfy its description requirements.
    
    ### *Classification Criteria:*    
       - The code does not function as intended according to the provided description.    
       - The code correctly implements the described functionality.  
       - It produces the expected output .  
    
    ### *Output Requirements:*  
    1. Clearly classify the code using *one of the two categories*.  
    2. Enclose your classification in ⁠ <OUTPUT> ⁠ tags using one of the following formats without any additional context or explanation:  
       - ⁠ <OUTPUT> Logical Bug Detected <OUTPUT> ⁠  
       - ⁠ <OUTPUT> No Logical Bug <OUTPUT> ⁠  
    
    ### *Description:*  
    {description}  
    
    ### *Code:*  
    {code}  
    
    """
    return prompt



def get_prompt_for_syntax_fix(code, error_message, language):

   prompt = f"""You are a coding assistant specializing in fixing syntax errors in {language}.
           Your task is to analyze the given code, identify the syntax error, and provide a corrected version.

### *Error Details:*
{error_message}

### *Code Before Fix:*
⁠ {language}
{code}
 ⁠

Provide the corrected code enclosed within ⁠ <OUTPUT></OUTPUT> ⁠ tags without any additional context or programming language just new function.
like this example : 

        <OUTPUT>
        def calculate_area(radius):
            return 3.14 * radius * radius
        </OUTPUT>
        
**IN  ##JAVA language don't generate classes or any thing just write same function with modification.
        
"""

    
   return prompt

def get_prompt_for_generate_function_from_description(description, language):
    prompt_desc = """
        Generate a function based understanding correctly the logic and purpose of it using the given description.
        * important note * : Only return the function without explanations or additional text or programming language type .
        """
    prompt = f"{prompt_desc}\nLanguage: {language}\nDescription:\n{description}"
    return prompt

def get_generate_unit_test_cases_prompts(language, description, code):
    prompt = ""

    if language == "cpp":
        prompt = f"""
As a {language} tester, your task is to create comprehensive test cases for the function given the
function body. These test cases should encompass Basic and Edge scenarios to ensure the
code's robustness and reliability.
First, carefully understand the purpose and logic of the function based on its description and code.
Generate test cases directly without any additional explanation or context. Do not include comments or extra text.
Create exactly 7 comprehensive test cases for the provided function and make sure that each test case is in correct format and really tests the function and gives the correct output.

**Important note**: Format of generated test cases should be like this example to make it runnable directly:
[assert(min_cost(vector<vector<int>>{ {1, 2, 3}, {4, 8, 2}, {1, 5, 3}}, 2, 2).first == 8);, assert(min_cost(vector<vector<int>>{ {2, 3, 4}, {5, 9, 3}, {2, 6, 4}}, 2, 2).first == 12);, assert(min_cost(vector<vector<int>>{ {3, 4, 5}, {6, 10, 4}, {3, 7, 5}}, 2, 2).first == 16);]

Function:
{code}

Description of code:
{description}

Test Cases:
"""
        return prompt

    elif language == "javascript":
        prompt = f"""
As a {language} tester, your task is to create comprehensive test cases for the function given the
function body.These test cases should encompass Basic and Edge scenarios to ensure the
code's robustness and reliability.
First, carefully understand the purpose and logic of the function based on its description and code
Generate test cases directly without any additional explanation or context. Do not include comments or extra text.
create exactly 5 comprehensive test cases for the provided function and make sure that each test case is correct format and really test the function and give correct output.

*important note* : format of generated test cases make formatting like this example to can run it directly:
[console.assert(smallNNum([10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100], 2).toString() === [10, 20].toString()), console.assert(smallNNum([10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100], 5).toString() === [10, 20, 20, 40, 50].toString()), console.assert(smallNNum([10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100], 3).toString() === [10, 20, 20].toString())]


Function :
{code}

Description of code:
{description}

Test Cases :
"""
        return prompt

    elif language == "python":
        prompt = f"""
    As a {language} tester, your task is to create comprehensive test cases for the function given the
    function body.These test cases should encompass Basic and Edge scenarios to ensure the
    code's robustness and reliability.
    First, carefully understand the purpose and logic of the function based on its description and code
    Generate test cases directly without any additional explanation or context. Do not include comments or extra text.
    create exactly 5 comprehensive test cases for the provided function and make sure that each test case is correct format and really test the function and give correct output.
    *important note* : format of generated test cases make formatting like this example to can run it directly:
    ["assert count_ways(2) == 3", "assert count_ways(8) == 153", "assert count_ways(12) == 2131"]



    Function
    {code}

    Description of code:
    {description}

    Test Cases :

    """
        return prompt

    elif language == "java":
        prompt = f"""
As a Java tester, your task is to create exactly *five* comprehensive test cases for the given function.
These test cases should cover both *basic* and *edge* scenarios to ensure the function's robustness and reliability.

### Instructions:
1. *Understand the Function:* Carefully analyze its purpose and logic based on the provided code and description.
2. *Create Valid Test Cases:* Ensure each test case thoroughly tests the function with correct input-output pairs.
3. *Use the Correct Format:*
   - The test cases *must be executable Java assertions*.
   - Follow the example format below to ensure correctness.


<ASSERTS>
[
assert Arrays.equals(new int[]{1, 2, 3}, new int[]{1, 2, 3});
,
assert power(-2, 3) == -8;
,
assert sum(new int[]{1, 2, 3, 4})== 10;
]
</ASSERTS>


Function :
{code}

Description of code:
{description}

the OutPut Structer must be List of Asserts like that:


asserts :
"""
        return prompt

def get_prompt_generate_description(code , language):
    # Define a basic prompt for each language
    prompt_templates = {
        "python": "Generate a detailed description for the following Python code in accurate way:\n\n",
        "java": "Generate a detailed description for the following Java code in accurate way:\n\n",
        "c++": "Generate a detailed description for the following C++ code in accurate way:\n\n",
        "javascript": "Generate a detailed description for the following JavaScript code in accurate way:\n\n",
    }
    
    # Check if the language is supported
    if language.lower() in prompt_templates:
        # Return the appropriate prompt with the code inserted
        return prompt_templates[language.lower()] + code
    else:
        return "Sorry, the language is not supported. Please provide a valid programming language."

def generate_prompt_feedback_correctness(code, list_of_asserts):

    prompt = f"""
I want you to regenerate the test cases for a function that I will provide. The goal is to improve its correctness.

Correctness is measured as follows:
- Each function has 5 test cases.
- Each test case is run with the function.
- If the test passes (no "failed" or "Error" in the result), it counts as a success.
- success_rate = number of successful tests / 5.

There are two reasons to modify the inputs:
1. Some assertions are incorrect.
2. The function does not handle certain cases.

You must:
- Fix the function code if necessary to handle all unhandled cases.
- Fix or regenerate the test assertions to improve accuracy .

*Important Instructions:*
- Return ONLY the corrected function between <OUTPUTCODE> and </OUTPUTCODE>.
- Do NOT include any explanations, comments, or language declarations.
- Return ONLY the corrected list of asserts between <OUTPUTASSERTS> and </OUTPUTASSERTS>, as same format like below :
Here is the function:
<INPUTCODE>
{code}
</INPUTCODE>

Here are the asserts:
<INPUTASSERTS>
{list_of_asserts}
</INPUTASSERTS>
"""
    return prompt
def generate_prompt_feedback_coverage(asserts: str) -> str:
    prompt = f"""
I want you to regenerate the test cases to optimize **assert coverage** for a function.
The goal is to ensure that a wide variety of inputs — including edge cases, boundary values, and different input types — are thoroughly tested.

Instructions (follow all strictly):
- Cover a diverse set of inputs, especially edge and boundary cases.
- Ensure all regenerated test cases are logically correct.
- ONLY return the new assertions inside the <OUTPUTASSERTS> and </OUTPUTASSERTS> tags.
- Format the assertions as a list of strings: square brackets `[]`, with each `assert` as a string, and each string enclosed in double quotes `""`, separated by commas.
- Do not include any explanation, comments, or extra content outside the tags.
- Limit the total number of test cases to a maximum of 10.
-- Return ONLY the corrected list of asserts between <OUTPUTASSERTS> and </OUTPUTASSERTS>, as same format like below :

Here are the asserts:
{asserts}
"""
    return prompt



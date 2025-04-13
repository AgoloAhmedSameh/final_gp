
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
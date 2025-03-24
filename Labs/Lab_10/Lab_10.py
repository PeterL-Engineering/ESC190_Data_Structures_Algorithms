# Question 1 (See client.py ie pasted API code)

# Question 2
from notopenai import NotOpenAI
import json

# Input the API key obtained for the lab
API_KEY = "8Jxd6C2CrJEvbcZyFtRn"
CLIENT = NotOpenAI(api_key=API_KEY)

def get_response(prompt):
    chat_completion = CLIENT.chat.completions.create(
    messages=[
        {
            "role": "user",
            "content": prompt,
        }
    ],
    model="gpt-3.5-turbo", # the GPT model to use
)

    response_str = chat_completion.choices[0].message.content
    return response_str

#print(get_response("What is Engineering Science?"))

# Question 3

#print(get_response("Generate a Python function that outputs the factorial of the input n. Only give me code"))

# Question 4

def check_result(generated_code, test_cases):
    """
    Check which test cases failed from the generated code
    generated_code - str
    test_cases - list of dicts

    e.g., if the generated_code is:
    def fun(x):
        return x
    """

    passed = 0
    failed = 0

    # Create a local execution environment to avoid polluting globals
    local_env = {}

    # Execute the generated code
    exec(generated_code, local_env)

    # Extract function name dynamically
    func_name = list(local_env.keys())[-1]  # Assumes only one function is defined
    func = local_env[func_name]  # Retrieve the function object

    for case in test_cases:
        input_value = case["input"] 
        expected_output = case["expected_output"]
        try:
            if func(input_value) == expected_output:
                passed += 1
            else:
                failed += 1
        except Exception as e:
            print(f"Error for input {input_value}: {e}")
            failed += 1

    return f"Passed: {passed}\nFailed: {failed}"

# Fixing syntax error in function definition
generated_code = """def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
"""

test_cases = [
    {"input": 3, "expected_output": 6},  # Fixed typo from "intput" to "input"
    {"input": 4, "expected_output": 24},
]

print(check_result(generated_code, test_cases))

# Question 5


import re

def ClearStrings(line_of_code):
    pattern = r"(['\"])(.*?)\1"
    matches = re.findall(pattern, line_of_code)
    filtered = [match[1] for match in matches]
    filtered_line_of_code = re.sub(
        pattern,
        lambda match: "" if match[2] in filtered else match.group(0),
        line_of_code,
    )
    return filtered_line_of_code
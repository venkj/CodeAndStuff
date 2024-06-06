def remove_invalid_parentheses(s: str) -> str:
    stack = []
    s = list(s)
    for i in range(len(s)):
        if s[i] == "(":
            stack.append(i)
        elif s[i] == ")" and stack:
            stack.pop()
        elif s[i] == ")" and not stack:
            s[i] = ""
    for i in stack:
        s[i] = ""
    return "".join(s)


# Example usage:
s = "a)b(c)d"
print(remove_invalid_parentheses(s))  # Output: "ab(c)d"

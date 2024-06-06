def remove_invalid_parentheses(s: str) -> str:

    # First pass to remove invalid closing parentheses
    res = []
    cnt = 0
    for c in s:
        if c == "(":
            res.append(c)
            cnt += 1
        elif c == ")" and cnt > 0:
            res.append(c)
            cnt -= 1
        elif c != ")":
            res.append(c)

    # Second pass to remove invalid opening parentheses
    filtered = []
    for c in res[::-1]:
        if c == "(" and cnt > 0:
            cnt -= 1
        else:
            filtered.append(c)

    return "".join(filtered[::-1])


# Example usage:
s = "a)b(c)d"
print(remove_invalid_parentheses(s))  # Output: "ab(c)d"

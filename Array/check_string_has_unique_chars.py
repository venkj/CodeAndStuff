def has_unique_chars(s: str) -> bool:
    MAX_CHARS = 256
    n = len(s)

    if n > MAX_CHARS:
        return False

    chars = [False] * MAX_CHARS

    for i in range(len(s)):
        indx = ord(s[i])

        if chars[indx]:
            return False

        chars[indx] = True

    return True


if __name__ == "__main__":
    assert has_unique_chars("abbabba") is False
    assert has_unique_chars("abc") is True

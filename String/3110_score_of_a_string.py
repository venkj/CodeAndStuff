def scoreOfString(s: str) -> int:
    score = 0
    for i in range(1, len(s)):
        score += abs(ord(s[i - 1]) - ord(s[i]))
    return score


if __name__ == "__main__":
    assert scoreOfString("hello") == 13
    assert scoreOfString("zaz") == 50

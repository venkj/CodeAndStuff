from collections import Counter
from typing import List


def commonChars(words: List[str]) -> List[str]:
    base_count = Counter(words[0])

    for w in words:
        cur_count = Counter(w)
        for c in base_count:
            base_count[c] = min(cur_count[c], base_count[c])

    res = []
    for c in base_count:
        for _ in range(base_count[c]):
            res.append(c)

    return res


if __name__ == "__main__":
    words = ["bella", "label", "roller"]
    print(commonChars(words=words))

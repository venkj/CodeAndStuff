from typing import List


def replaceWords(dictionary: List[str], sentence: str) -> str:
    words = sentence.split()
    dictSet = set(dictionary)

    def shortestWord(word):
        for i in range(len(word)):
            rootWord = word[0:i]
            if rootWord in dictSet:
                return rootWord
        return word

    for i in range(len(words)):
        words[i] = shortestWord(words[i])

    return " ".join(words)


if __name__ == "__main__":
    assert (
        replaceWords(
            ["cat", "bat", "rat"],
            "the cattle was rattled by the battery",
        )
        == "the cat was rat by the bat"
    )
    assert replaceWords(["a", "b", "c"], "aadsfasf absbs bbab cadsfafs") == "a a b c"

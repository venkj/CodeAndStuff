def validWordAbbreviation(word: str, abbr: str) -> bool:
    i, j = 0, 0
    while i < len(word) and j < len(abbr):
        if abbr[j].isdigit():
            # Handle leading zeros which are not valid in the abbreviation number
            if abbr[j] == "0":
                return False

            cur = 0
            while j < len(abbr) and abbr[j].isdigit():
                cur = cur * 10 + int(abbr[j])
                j += 1
            i += cur
        else:
            if word[i] != abbr[j]:
                return False
            i += 1
            j += 1

    return i == len(word) and j == len(abbr)


if __name__ == "__main__":
    assert validWordAbbreviation(word="internationalization", abbr="i12iz4n") is True
    assert validWordAbbreviation(word="apple", abbr="a2e") is False

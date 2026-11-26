from yogi import tokens


def longest_prefix(words: list[str]) -> str:
    """Return the longest common prefix of a list of strings. Prec: words is not empty."""

    return longest_prefix_rec(words, 0, len(words) - 1)


def longest_prefix_rec(words: list[str], left: int, right: int) -> str:
    """Return the longest common prefix of a list of strings. Prec: 0 <= left <= right < len(words)."""

    if left == right:
        return words[left]
    else:
        mid = (left + right) // 2
        left_prefix = longest_prefix_rec(words, left, mid)
        right_prefix = longest_prefix_rec(words, mid + 1, right)
        return common_prefix(left_prefix, right_prefix)


def common_prefix(word1: str, word2: str) -> str:
    """Return the longest common prefix of two words."""

    min_len = min(len(word1), len(word2))
    for i in range(min_len):
        if word1[i] != word2[i]:
            return word1[:i]
    return word1[:min_len]


if __name__ == "__main__":
    print(f'"{longest_prefix(list(tokens(str)))}"')

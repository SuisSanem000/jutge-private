import sys
import random
import string


def generate_random_test_cases(num_cases: int) -> None:
    """
    Generates random test cases for the 'Filtre' problem.

    Each test case consists of:
    - An integer k (≥ 1) indicating every k-th occurrence to keep.
    - A sequence of words (strings without spaces).

    The test cases fall into the following categories:
    1. Small sequences with k=1 (all occurrences kept).
    2. Small sequences with random k > 1.
    3. Large sequences with many repeated words and moderate k.
    4. Sequences with unique words and large k (only first occurrences kept).
    5. Sequences with few distinct words repeated many times and small k.
    6. Edge cases with k=1 and sequence length = 1.
    7. Edge cases with k equal to the max occurrence count for some word.

    The generated words are lowercase alphabetic strings of length 1 to 8.
    Output format for each test case:
    k
    n  (number of words)
    word_1 word_2 ... word_n
    """
    MAX_LENGTH = 1000  # maximum length of sequence
    MAX_WORD_LENGTH = 8
    ALPHABET = string.ascii_lowercase

    def random_word(min_len=1, max_len=MAX_WORD_LENGTH) -> str:
        length = random.randint(min_len, max_len)
        return ''.join(random.choices(ALPHABET, k=length))

    for _ in range(num_cases):
        category = random.randint(1, 7)

        if category == 1:
            # Small sequences with k=1, all occurrences kept
            k = 1
            n = random.randint(1, 20)
            words = [random_word() for _ in range(n)]

        elif category == 2:
            # Small sequences with random k > 1
            n = random.randint(5, 30)
            k = random.randint(2, max(2, n // 5))
            words = [random_word() for _ in range(n)]

        elif category == 3:
            # Large sequences with many repeated words and moderate k
            n = random.randint(500, MAX_LENGTH)
            k = random.randint(2, 10)
            # choose a small set of words to repeat
            distinct_words = [random_word() for _ in range(random.randint(3, 10))]
            words = [random.choice(distinct_words) for _ in range(n)]

        elif category == 4:
            # Sequences with unique words and large k (only first occurrences kept)
            n = random.randint(20, 50)
            words = list({random_word() for _ in range(n)})
            k = random.randint(n+1, n+10)  # k larger than any count
            # If number of words changed due to set, remake words list
            if len(words) < n:
                words += [random_word() for _ in range(n - len(words))]

        elif category == 5:
            # Few distinct words repeated many times and small k
            distinct_count = random.randint(2, 5)
            distinct_words = [random_word() for _ in range(distinct_count)]
            n = random.randint(100, MAX_LENGTH)
            words = []
            for _ in range(n):
                words.append(random.choice(distinct_words))
            k = random.randint(1, 3)

        elif category == 6:
            # Edge cases with k=1 and sequence length = 1
            k = 1
            n = 1
            words = [random_word()]

        else:
            # Edge cases with k equal to the max occurrence count for some word
            distinct_count = random.randint(3, 7)
            distinct_words = [random_word() for _ in range(distinct_count)]
            n = random.randint(50, MAX_LENGTH)
            words = []
            counts = {w: 0 for w in distinct_words}
            for _ in range(n):
                w = random.choice(distinct_words)
                counts[w] += 1
                words.append(w)
            # pick a word and set k to its total occurrences
            w_for_k = random.choice(distinct_words)
            k = counts[w_for_k]

        # Output test case
        print(k)
        print(' '.join(words))


if __name__ == "__main__":
    num_cases = int(sys.argv[1])
    seed = int(sys.argv[2]) if len(sys.argv) > 2 else 42
    random.seed(seed)
    generate_random_test_cases(num_cases)
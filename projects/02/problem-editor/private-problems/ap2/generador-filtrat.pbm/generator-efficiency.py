import sys


def generate_efficiency_test_cases(num_cases: int) -> None:
    """
    Generate efficiency test cases to benchmark and stress test the filtering
    algorithm for selecting every k-th occurrence of words in a sequence.

    The program outputs test cases directly to standard output, each consisting of
    the integer k followed by a sequence of words. Each test case is designed to push
    the algorithm's performance with large input sizes and varying repetition patterns.

    Test cases categories:
    1. Single word repeated many times with k=2:
       Tests the algorithm's efficiency with very high repetition count of a
       single word where the output will have every second occurrence.
    2. Many unique words (no repetitions) with k=1:
       Tests the scenario where every word is output since k=1, with maximum number
       of unique words to stress memory and iteration.
    3. Many unique words repeated in clusters with k=3:
       Tests handling of multiple words repeated exactly multiple times before moving
       to the next word.
    4. Alternating two words with large length and k=5:
       Tests the algorithm's capability to count occurrences for multiple words
       interleaved and output only every 5th occurrence.
    The program cycles through these categories for num_cases.

    All test cases respect typical problem constraints and aim to maximize input size
    and processing complexity to test efficiency.
    """

    # Constants for test sizes, chosen to be large but reasonable for efficiency testing.
    MAX_WORDS = 100000
    MAX_DISTINCT = 10000

    # Predefined simple long word for generating large words.
    LONG_WORD = "word" * 10

    for i in range(num_cases):
        # Cycle through categories based on i mod 4
        test_type = i % 4

        if test_type == 0:
            # Category 1: Single word repeated many times with k=2
            k = 2
            word = "a"
            sequence_length = MAX_WORDS
            sequence = [word] * sequence_length
            print(k)
            print(*sequence)

        elif test_type == 1:
            # Category 2: Many unique words with k=1 (every occurrence passed)
            k = 1
            # Generate MAX_DISTINCT unique words: word0, word1, ...
            sequence = [f"w{i}" for i in range(MAX_DISTINCT)]
            print(k)
            print(*sequence)

        elif test_type == 2:
            # Category 3: Many unique words repeated in clusters with k=3
            k = 3
            repeats = 3  # each appears exactly 3 times
            distinct = MAX_DISTINCT // 3
            sequence = []
            for j in range(distinct):
                sequence.extend([f"v{j}"] * repeats)
            print(k)
            print(*sequence)

        else:
            # Category 4: Alternating two words (long) with k=5
            k = 5
            word1 = LONG_WORD + "1"
            word2 = LONG_WORD + "2"
            repeats = MAX_WORDS // 2
            sequence = []
            # Alternate word1 and word2 repeats times each
            for _ in range(repeats):
                sequence.append(word1)
                sequence.append(word2)
            print(k)
            print(*sequence)


if __name__ == "__main__":
    num_cases = int(sys.argv[1])
    generate_efficiency_test_cases(num_cases)
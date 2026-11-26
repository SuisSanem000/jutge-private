# Generate "small" test cases
# python3 gen_small.py  > small.inp
import itertools
import random
import string

def canonical_form(sequence):
    """
    Convert a sequence into its canonical form by greedily relabeling symbols
    in order of first appearance, starting with 0.
    """
    mapping = {}  # Maps original symbols to canonical ones
    result = []
    next_symbol = 0
    
    for x in sequence:
        if x not in mapping:
            mapping[x] = next_symbol
            next_symbol += 1
        result.append(mapping[x])
    
    return tuple(result)

def generate_necklaces(k, n):
    """
    Generate all k-ary necklaces of length n up to symbol relabeling.
    k: number of symbols (0 to k-1)
    n: length of sequences
    """
    from itertools import product
    
    seen = set()
    necklaces = []
    
    for seq in product(range(k), repeat=n):
        canon = canonical_form(seq)
        if canon not in seen:
            seen.add(canon)
            necklaces.append(list(seq))
    
    return necklaces

def print_necklaces(k, n):
    print(f"\nAll {k}-ary necklaces of length {n}:")
    necklaces = generate_necklaces(k, n)
    for i, necklace in enumerate(necklaces, 1):
        print(f"{i}. {necklace}")
    print(f"Total count: {len(necklaces)}")


def random_canonical(sigma, length):    
    return canonical_form(random.choices(range(sigma), k=length))

print("aaabb")
print("aaaaa")
print("a")
print("ab")
print("abcdef")
print("abcdefdabcghi")
# print("")

alphabet = ''.join([ chr(ord('a') + i) for i in range(26) ])
alphabet += alphabet.upper()

def generate_cases_exhaustive():
    for length in range(1, 6):
        seq = generate_necklaces(length, length)
        for x in seq:
            yield x

#    seq = generate_necklaces(5, 10)
    seq = generate_necklaces(5, 9)
    for x in seq:
        yield x

def generate_random_cases(max_length=100, repeat=50):
    for sigma in range(5, len(alphabet) + 1):    
        for _ in range(repeat):
            length = random.randint(1, max_length)
            yield random_canonical(sigma, length) 

cases = list(generate_cases_exhaustive())

# print(len(cases))
for s in cases:
    distinct = max(s) + 1
    if distinct >= 2:
        perm = list(alphabet.swapcase()[1:-1])         # ugly hack to ensure A is first and z last
        random.shuffle(perm)
        perm = perm[:(distinct - 2)] + [ 'A', 'z' ]
    else:
        perm = list(alphabet)
    random.shuffle(perm)
    print( ''.join(alphabet[x] for x in s) )
    print( ''.join(perm[x] for x in s) )

for s in generate_random_cases():
    perm = list(alphabet)
    random.shuffle(perm)
    print( ''.join(alphabet[x] for x in s) )

# Generate large test cases
# python3 gen_large.py > large.inp; time python3 solution.py < large.inp > large.out
import random
import string

def random_rotation(s):
    rotation = random.randrange(len(s))
    return s[rotation:] + s[:rotation]

def close_call(k=2500, start=2500, rand=True):
    # Max-distinct close calls
    #   Force strings that contain all 52 frequently but never allow a substring of length 52
    #   (e.g. whenever about to complete all 52 distinct letters, force a repeat).
    s3_parts = []
    used = set()
    if rand: 
        order = random.sample(alphabet, len(alphabet))
    else:
        order = alphabet
    for _ in range(k):
        for c in order:
            if len(used) == 51:
                # Force a repeat to never quite reach 52
                s3_parts.append(list(used)[0])
                used.clear()
            else:
                s3_parts.append(c)
                used.add(c)
    s3 = ''.join(s3_parts)
    s3 = ''.join(random.sample(alphabet, len(alphabet)-2)*start) + s3
    if rand:
        return random_rotation(s3)
    else:
        return s3

if __name__ == "__main__":
    alphabet = ''.join([ chr(ord('a') + i) for i in range(26) ])
    alphabet += alphabet.upper()

    print(close_call(rand=False))
    for _ in range(10):
        print(close_call())

    pattern = ''.join(random.sample(alphabet, len(alphabet)))
    print(pattern * 5000)

    bigs = ''.join(alphabet[:26] * 10000)
    print(bigs)

    # A solution with 52
    print( ''.join(alphabet[:26] * 5000) + pattern + ''.join(alphabet[:26] * 5000) )

    for _ in range(2):
        print(''.join(random.choices(alphabet, k=100000)))

    for a in [ 2000 ]:# + [ random.randint(2000, 5000) for _ in range(5) ]:
        concat = ''
        for i in range(5000):
            chunk = list(alphabet)
            random.shuffle(chunk)
            if i == a:
                chunk = chunk[:-10]
            else:
                chunk = chunk[:-2]
            chunk = ''.join(chunk)
            concat += chunk
        print(concat)        
        
    s4_parts = []
    for _ in range(10):
        s4_parts.append('A' * 20000)  # huge chunk of A’s
        s4_parts.append('B')         # a single 'B'
    s4 = ''.join(s4_parts)
    print(s4)

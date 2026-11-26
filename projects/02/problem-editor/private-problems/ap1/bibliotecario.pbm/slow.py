from yogi import tokens

def racha_slow(s:str) -> tuple[int, int]:
    numbers = [ position[ord(c)] for c in s ]
    mejor_long, mejor_pos = (0, -1)
    n = len(s)

    for i in range(n):
        seen = [ False ] * 52
        valid = True
        for l in range( 1, 1 + min(n - i, 52) ):
            c = numbers[i + l - 1]
            if seen[c]:
                valid = False
                break
            seen[c] = True

            if valid:
                if l > mejor_long:
                    mejor_long, mejor_pos = l, i
                    if mejor_long == 52: return (mejor_long, mejor_pos)
            else:
                break

    return (mejor_long, mejor_pos)

if __name__ == "__main__":
    alphabet = ''.join([ chr(ord('a') + i) for i in range(26) ])
    alphabet += alphabet.upper()
    position = [-1] * 256
    for (i, c) in enumerate(alphabet):
        position[ord(c)] = i

    for s in tokens(str):
        long, pos = racha_slow(s)
        print(s[pos:pos+long], pos)

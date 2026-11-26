import random
import string
digs = string.digits + string.ascii_letters


def int2base(x, base):
    # https://stackoverflow.com/questions/2267362/how-to-convert-an-integer-to-a-string-in-any-base
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits).upper()


for i in range(10000):
    b = random.randint(2, 36)
    x = random.randint(0, 1000000000000)
    y = random.randint(0, 1000000000000)
    print(b, int2base(x, b), int2base(y, b))

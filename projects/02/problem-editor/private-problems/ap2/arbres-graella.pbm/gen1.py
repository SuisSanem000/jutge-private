import random


def gen(h):
    if h == 0:
        return '-'
    else:
        l = '-'
        r = '-'
        if random.random() > 0.5:
            l = gen(h-1)
        if random.random() > 0.5:
            r = gen(h-1)
        c = random.choice('ABCDE')
        return c + l + r


def main():
    print(100)
    for n in range(100):
        print(gen(10))


main()

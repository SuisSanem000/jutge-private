import yogi


def is_prime(p1: int) -> bool:
    i = 2
    while i*i <= p1:
        if p1 % i == 0:
            return False
        i += 1
    return True


def enesim_parell(n: int) -> tuple[int, int]:
    x1, x2 = 3, 5
    count = 1

    while count < n:
        x1 += 2
        x2 += 2
        if is_prime(x1) and is_prime(x2):
            count += 1

    return x1, x2


def main():
    n = yogi.scan(int)
    while n is not None:
        print(enesim_parell(n))
        n = yogi.scan(int)


if __name__ == "__main__":
    main()

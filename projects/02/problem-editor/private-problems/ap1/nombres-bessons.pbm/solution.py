import yogi


def son_primers(p1: int, p2: int) -> bool:
    """Indica si p1 i p2 són nombres primers. Prec: n1, n2 >= 2."""

    i = 2
    while i*i <= max(p1, p2):
        if p1 % i == 0 and p1 != i or p2 % i == 0 and p2 != i:
            return False
        i += 1
    return True


def nth_twin_primes(n: int) -> tuple[int, int]:
    """Retorna l'n-èsim parell de nombres bessons, per n >= 1."""

    x = 3
    c = 1
    while c < n:
        x += 2
        if son_primers(x, x + 2):
            c += 1
    return x, x + 2


def main():
    """Programa principal"""
    for n in yogi.tokens(int):
        p, q = nth_twin_primes(n)
        print(p, q)


if __name__ == "__main__":
    main()

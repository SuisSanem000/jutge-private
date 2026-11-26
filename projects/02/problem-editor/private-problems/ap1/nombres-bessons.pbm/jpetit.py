import yogi


def es_primer(n: int) -> bool:
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def nth_twin_primes(n: int) -> tuple[int, int]:
    """Retorna l'n-èsim parell de nombres bessons, per n >= 1."""

    p, q = 3, 5
    pp, pq = True, True
    c = 1
    while c < n:
        p, q = q, q + 2
        pp, pq = pq, es_primer(q)
        if pp and pq:
            c += 1
    return p, q


def main():
    """Programa principal"""
    for n in yogi.tokens(int):
        p, q = nth_twin_primes(n)
        print(p, q)


if __name__ == "__main__":
    main()

import yogi


def es_unidigit(n: int, b: int) -> int:
    """
    Indica si un nombre n >= 0 pot ser representat amb només un dígit
    en base b. Per exemple, 777 és unidigit en base 10 i 15 és unidigit en
    base 2. En canvi, 123 no és unidigit en base 10. La funció retorna
    el dígit amb el que es pot representar el nombre. En cas que no sigui
    unidigit, retorna -1.
    """

    digit = n % b
    n = n // b
    while n > 0:
        if n % b != digit:
            return -1
        n //= b
    return digit


def base_petita_unidigit(n: int) -> tuple[int, int]:
    """Retorna la base més petita i el dígit amb la qual n és pot representar com un nombre unidigit."""

    for b in range(2, n + 2):
        d = es_unidigit(n, b)
        if d >= 0:
            return b, d
    return 2, 0  # type: ignore


def main() -> None:
    for n in yogi.tokens(int):
        b, d = base_petita_unidigit(n)
        print(b, d)


if __name__ == "__main__":
    main()

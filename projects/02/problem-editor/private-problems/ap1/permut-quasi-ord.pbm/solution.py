import yogi


def gen_permutacions_rec(
    n: int, L: list[int], i: int, k: int, usats: list[bool]
) -> None:
    """
    Escriu totes les permutacions quasi-ordenades de {1..n}
    que tenen L[:i] com a prefix. k és el nombre d'elements
    que encara poden ser diferents de la seva posició a partir
    de la posició i. usats[x] indica si l'element x ja està
    utilitzat en L[:i].
    """

    if k < 0:
        return

    if i == n:
        print(" ".join(str(x) for x in L))
        return

    for x in range(1, n + 1):
        if not usats[x]:
            L[i] = x
            usats[x] = True
            nou_k = k - 1 if x != i + 1 else k
            gen_permutacions_rec(n, L, i + 1, nou_k, usats)
            usats[x] = False


def gen_permutacions_quasi_ordenades(n: int, k: int) -> None:
    """Escriu totes les permutacions quasi-ordenades de {1..n}, per a n > 0.
    k és el nombre màxim d'elements que poden ser diferents de la seva
    posició natural."""

    L = [0] * n  # llista on es guaradarà la permutació
    usats = [False for _ in range(n + 1)]  # la posició 0 no s'utilitza
    gen_permutacions_rec(n, L, 0, k, usats)


if __name__ == "__main__":
    n = yogi.read(int)
    k = yogi.read(int)
    gen_permutacions_quasi_ordenades(n, k)

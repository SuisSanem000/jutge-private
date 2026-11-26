import yogi


def es_primer(n: int) -> bool:
    if n <= 1:
        return False

    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True


def seq_semiprimer() -> int:
    max_semiprimer = 0
    anterior = 0
    for actual in yogi.tokens(int):
        if anterior == 2 or actual == 2:
            semiprimer = anterior * actual
            if es_primer(semiprimer // 2):
                max_semiprimer = max(max_semiprimer, semiprimer)
        anterior = actual
    return max_semiprimer


if __name__ == "__main__":
    print(seq_semiprimer())

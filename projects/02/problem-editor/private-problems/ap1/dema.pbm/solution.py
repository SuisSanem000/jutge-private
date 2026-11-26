
def es_any_de_traspas(a: int) -> bool:
    return a % 4 == 0 and (a % 100 != 0 or a % 400 == 0)


def dia_seguent(d: int, m: str, a: int) -> tuple[int, str, int]:
    d = d + 1
    if (d, m) == (32, 'gener'):
        d, m = 1, 'febrer'
    elif m == 'febrer' and (d == 30 or d == 29 and not es_any_de_traspas(a)):
        d, m = 1, 'marc'
    elif (d, m) == (32, 'marc'):
        d, m = 1, 'abril'
    elif (d, m) == (31, 'abril'):
        d, m = 1, 'maig'
    elif (d, m) == (32, 'maig'):
        d, m = 1, 'juny'
    elif (d, m) == (31, 'juny'):
        d, m = 1, 'juliol'
    elif (d, m) == (32, 'juliol'):
        d, m = 1, 'agost'
    elif (d, m) == (32, 'agost'):
        d, m = 1, 'setembre'
    elif (d, m) == (31, 'setembre'):
        d, m = 1, 'octubre'
    elif (d, m) == (32, 'octubre'):
        d, m = 1, 'novembre'
    elif (d, m) == (31, 'novembre'):
        d, m = 1, 'desembre'
    elif (d, m) == (32, 'desembre'):
        d, m, a = 1, 'gener', a + 1

    return d, m, a

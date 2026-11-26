from yogi import read, tokens


def d_espaiat(b: int, d: int, n: int) -> bool:
    """
    Pre: 2 <= b; 0 <= d < b; n >= 0
    Post: retorna True/False en función de si n es o no d-espaciado en base b
    """
    while n >= b:
        act = n % b
        n = n // b
        if act != d and n % b != d:
            return False
    return True


def resoldre_cas(b: int, d: int, n: int) -> None:
    """Resol un cas de l'entrada, per valors b, d i n tal com es descriuen a l'enunciat."""
    count = 0
    for _ in range(n):
        x = read(int)
        if d_espaiat(b, d, x):
            count += 1
    print(count)


def main() -> None:
    for b in tokens(int):
        resoldre_cas(b, read(int), read(int))


if __name__ == "__main__":
    main()

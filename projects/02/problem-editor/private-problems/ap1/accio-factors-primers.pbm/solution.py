
def escriure_factors_primers(n: int) -> None:
    b = False
    d = 2
    while n != 1:
        if n % d == 0:
            if b:
                print(',', end='')
            else:
                b = True
            print(d, end='')
            while n % d == 0:
                n = n // d
        d = d + 1
    print()

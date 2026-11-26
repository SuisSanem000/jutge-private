# xavier azkargorta

from yogi import tokens

def es_primer(n: int)-> bool:
    if n < 2: return False
    d = 2
    while d * d <= n:
        if n % d == 0: return False
        d = d + 1
    return True

def semiprimalitat(n: int) -> None:
    i = 1
    found = False
    while i * i <= n and not found:
        i += 1
        if n % i == 0 and es_primer(n // i):
            found = True
    
    print(f"{n}: yes ({i},{n // i})" if found else f"{n}: no")
    
def main() -> None:
    for x in tokens(int):
        semiprimalitat(x)

main()

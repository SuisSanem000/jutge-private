from yogi import read

def impar(x: int) -> int:
    '''
    Pre: x > 0
    Post: los dígitos pares de x están cambiados por el siguiente dígito impar
    '''
    imp_x = 0   # impar del x de entrada
    v_pos = 1   # valor posicional
    while x > 0:
        d = x%10
        if d%2 == 0: d += 1
        imp_x = d*v_pos + imp_x
        v_pos *= 10
        x = x//10
    return imp_x

def main() -> None:
    x = read(int)
    while x != 0:
        print(impar(x))
        x = read(int)

if __name__ == "__main__":
    main()
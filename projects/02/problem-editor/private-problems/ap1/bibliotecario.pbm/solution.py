from yogi import tokens

def racha(s: str) -> tuple[int, int]:
    """
    Devuelve una tupla con la longitud de la máxima racha de caracteres distintos consecutivos, y la posición de la primera letra de esa racha.
    En caso de empate, devuelve la posición más a la izquierda posible.
    """

    ultima_pos = [ -1 ] * (ord('z') - ord('A') + 1)           # última posición donde apareció cada letra, o -1 si no está todavía

    mejor_long, mejor_pos = (0, -1)
    inicio = 0                          # inicio de la racha actual
    for i in range(len(s)):
        c = ord(s[i]) - ord('A')        # transforma el carácter en un número

        # Si la letra 'c' ha aparecido antes (ultima_pos[c] >= 0), pero después del inicio, la nueva racha empieza después de la aparición anterior de 'c'
        if ultima_pos[c] >= inicio:
            inicio = ultima_pos[c] + 1
        ultima_pos[c] = i

        # Actualiza la mejor longitud si procede
        longitud = i - inicio + 1
        if longitud > mejor_long:
            mejor_long, mejor_pos = longitud, inicio

    return (mejor_long, mejor_pos)


def main() -> None:
    for s in tokens(str):
        long, pos = racha(s)
        print(s[pos:pos+long], pos)


if __name__ == "__main__":
    main()
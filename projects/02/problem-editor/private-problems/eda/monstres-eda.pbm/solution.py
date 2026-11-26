# xavier azkargorta

from yogi import read, tokens

def dfs(mapa: list[list[str]], x: int, y: int, protip: list[bool]) -> None:
    if coords_in_map(mapa, x, y) and mapa[x][y] != "X" and not protip[0]:
        if mapa[x][y] == "F":
            protip[0] = True
            return
        mapa[x][y] = "X"
        dfs(mapa, x, y - 1, protip)
        dfs(mapa, x, y + 1, protip)
        dfs(mapa, x - 1, y, protip)
        dfs(mapa, x + 1, y, protip)

def coords_in_map(mapa: list[list[str]], x: int, y: int) -> bool:
    return 0 <= x < len(mapa) and 0 <= y < len(mapa[0])

def can_reach(mapa: list[list[str]], x: int, y: int) -> bool:
    """retorna si es pot arriba al final desde la posicio inicial x, y, sense problemes amb els monstres"""
    protip = [False]
    dfs(mapa, x, y, protip)
    return protip[0]

def main() -> None:
    for n in tokens(int):
        m = read(int)
        mapa = [[c for c in read(str)] for _ in range(n)]
        assert len(mapa[0]) == m
        for x, fila in enumerate(mapa):
            for y, element in enumerate(fila):
                if element == "I":
                    xini, yini = x, y
                if element == "M":
                    for dx, dy in [(1, 0), (0, 1), (0, -1), (-1, 0)]:
                        i, j = x + dx, y + dy
                        if coords_in_map(mapa, i, j) and mapa[i][j] == ".":
                            mapa[i][j] = "X"
        print("SI" if can_reach(mapa, xini, yini) else "NO")

main()

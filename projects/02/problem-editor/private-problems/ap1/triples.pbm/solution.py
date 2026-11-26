from dataclasses import dataclass
from functools import cmp_to_key
from yogi import read

@dataclass
class Player:
    name: str
    dtd: int      # número de doble triple-dobles
    td: int       # número de triple-dobles (queno són doble triple-doble)

def read_player(p: int) -> Player:
    '''
    Pre: p >= 0; a l'entrada hi ha un nom seguit de les seves estadístiques a p partits
    Post: retorna la informació d'una jugadora segons les dades que hi havia a l'entrada
    '''
    N = 5    # nb of statistics
    player = Player(read(str), 0, 0)
    for _ in range(p):
        n_dtd = 0
        n_td = 0
        for _ in range(N):
            v = read(int)
            if v >= 10:
                n_td += 1
                if v >= 20:
                    n_dtd += 1
        if n_dtd >= 3:
            player.dtd += 1
        elif n_td >= 3:
            player.td += 1
    return player

def cmp(a: Player, b: Player) -> int:
    '''
    Criterios:
    (a) más doble triple-dobles
    (b) más triple-dobles (que no son doble triples-dobles)
    (c) nombre pequeño lexicográficamente
    '''
    if a.dtd != b.dtd: return b.dtd - a.dtd; # < 0 iff a better than b
    if a.td != b.td: return b.td - a.td
    if a.name < b.name: return -1
    if a.name > b.name: return 1
    return 0

def main() -> None:
    p = read(int)
    n = read(int)
    lst = [read_player(p) for _ in range(n)]
    lst.sort(key = cmp_to_key(cmp))
    for player in lst:
        print(player.name, player.dtd, player.td)

main()
from typing import Iterator
from heapq import heappush, heappop


def fusio_generadors(generadors: list[Iterator[int]]) -> Iterator[int]:
    """Fusiona k generadors infinits que generen naturals en ordre creixent en un sol generador infinit que genere naturals en ordre creixent i sense repetir elements."""

    # La cua de prioritats és una llista de tuples (valor, índex del generador)
    pq: list[tuple[int, int]] = []

    # Conjunt de valors generats
    generats: set[int] = set()
    
    # Inicialització: Agafem el primer element de cada generador
    for i in range(len(generadors)):
        valor = next(generadors[i])
        heappush(pq, (valor, i))

    # Bucle principal de processament: treiem el valor mínim de la cua de prioritats i afegim el següent element del mateix iterador
    while pq:
        valor_minim, i = heappop(pq)
        heappush(pq, (next(generadors[i]), i))

        if valor_minim not in generats:
            generats.add(valor_minim)
            yield valor_minim        



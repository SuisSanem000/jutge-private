
# venia de https://jutge.org/problems/X39443
# però hem hagit de canviar-lo pels arrodoniments

# david garcia soriano


from yogi import read
from dataclasses import dataclass
from typing import TypeAlias

Respuesta: TypeAlias = list[int]  # lista de valoraciones de una asignatura hecha por un alumno
Matriz: TypeAlias = list[Respuesta]


@dataclass
class InfoAsignatura:
    codigo: int
    respuestas: Matriz  # cada fila contiene los resultados de una encuesta


def lee_encuesta(num_preguntas: int) -> tuple[int, Respuesta]:
    """Lee una sola encuesta con un número dado de preguntas y devuelve su código y respuesta (lista de valoraciones)."""
    codigo = read(int)
    return (codigo, [read(int) for _ in range(num_preguntas)])


def elimina_extremos(A: Matriz) -> Matriz:
    """Elimina las filas de A con menor y mayor suma total, si hay al menos 5 elementos."""
    return A if len(A) < 5 else sorted(A, key=sum)[1:-1]


def media(v: list[int]) -> float:
    """Devuelve la media de un vector."""
    return sum(v) / len(v)


def transpuesta(A: Matriz) -> Matriz:
    """Devuelve la transpuesta de una matriz."""
    ly, lx = len(A), len(A[0])
    return [[A[j][i] for j in range(ly)] for i in range(lx)]


def medias_por_posicion(A: Matriz) -> list[float]:
    """Dada la lista de encuestas de una asignatura, devuelve la media de cada pregunta (i.e., la media de cada columna de A)."""
    return [media(x) for x in transpuesta(A)]


def agrega_resultados(encuestas: list[tuple[int, Respuesta]]) -> list[InfoAsignatura]:
    """Agrupa las encuestas por código. Devuelve una lista de InfoAsignaturas."""

    # Primero ordenamos las encuestas por código, de manera que las encuestas con el mismo código aparecerán en posiciones consecutivas.
    v = sorted(encuestas)

    codigo, listas = v[0][0], [v[0][1]]  # codigo, [ primera respuesta ]
    ret: list[InfoAsignatura] = []
    for i in range(1, len(v)):
        if v[i][0] != codigo:
            # Fin de la racha de encuestas con el mismo código
            ret.append(InfoAsignatura(codigo, listas))
            listas = []
            codigo = v[i][0]
        listas.append(v[i][1])

    # Añade la última racha
    ret.append(InfoAsignatura(codigo, listas))
    return ret


def main():
    num_preguntas, num_encuestas = read(int), read(int)
    asignaturas = agrega_resultados([lee_encuesta(num_preguntas) for _ in range(num_encuestas)])

    for asignatura in asignaturas:
        print(asignatura.codigo, end=" ")
        medias = medias_por_posicion(elimina_extremos(asignatura.respuestas))
        print(*[f"{num:.2f}" for num in medias])


if __name__ == "__main__":
    main()

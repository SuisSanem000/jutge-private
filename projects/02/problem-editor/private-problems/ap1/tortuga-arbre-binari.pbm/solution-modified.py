from turtle import *
import yogi


def dibuixar_arbre(n: int, esq: float, dre: float, y: float, inc_y: float) -> None:
    """
    Dibuixa un arbre binari d'n nivells recursivament.
    L'arbre comença on es troba la tortuga i es mostra entre la posició
    esq i dre en l'eix x. La variable y indica la posició actual en l'eix y.
    Cada nivell de l'arbre es dibuixa a una alçada inc_y per sota de l'actual.
    La tortuga es manté al mateix lloc i amb la mateixa orientació.

    Precondició: la tortuga mira a la dreta de la pantalla.
    """
    dot(5)
    if n > 1:
        dist = dre - esq
        seg_y = y - inc_y
        goto(esq + dist / 4, seg_y)
        dibuixar_arbre(n - 1, esq, esq + dist / 2, seg_y, inc_y)
        goto(esq + dist / 2, y)
        goto(dre - dist / 4, seg_y)
        dibuixar_arbre(n - 1, dre - dist / 2, dre, seg_y, inc_y)
        goto(esq + dist / 2, y)


def main() -> None:
    nivells = yogi.read(int)
    amplada = yogi.read(float)
    alcada = yogi.read(float)
    dibuixar_arbre(nivells, -amplada / 2, amplada / 2, 0, alcada / nivells)
    done()


if __name__ == "__main__":
    main()

from yogi import tokens, read
from typing import Optional


class CuaSupermercat:

    def __init__(self):
        ...

    def arribar(self, client) -> None:
        ...

    def atendre(self) -> Optional[str]:
        ...

    def escriure_cua(self) -> None:
        ...

    def escriure_clients(self):
        ...


def main() -> None:
    q = CuaSupermercat()
    for ordre in tokens(str):
        if ordre == "arribar":
            client = read(str)
            q.arribar(client)
            print("arribar", client)
        elif ordre == "atendre":
            client = q.atendre()
            if client is None:
                print("cua buida")
            else:
                print("atendre", client)
        elif ordre == "escriure_cua":
            q.escriure_cua()
        elif ordre == "escriure_clients":
            q.escriure_clients()
        else:
            print("Ordre no reconeguda")


if __name__ == "__main__":
    main()
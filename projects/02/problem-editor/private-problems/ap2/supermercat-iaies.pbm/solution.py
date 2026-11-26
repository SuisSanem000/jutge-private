from collections import deque
from yogi import tokens, read
from typing import Optional


class CuaSupermercat:

    _cua: deque[str]
    _comptadors: dict[str, int]

    def __init__(self):
        self._cua = deque[str]()
        self._comptadors = {}

    def _es_iaia(self, nom: str) -> bool:
        return nom.startswith("Iaia")

    def arribar(self, client) -> None:
        if self._es_iaia(client) and len(self._cua) != 0:
            ultim = self._cua.popleft()
            self._cua.appendleft(client)
            self._cua.appendleft(ultim)
        else:
            self._cua.appendleft(client)

    def atendre(self) -> Optional[str]:
        if len(self._cua) == 0:
            return None
        client = self._cua.pop()
        if client in self._comptadors:
            self._comptadors[client] += 1
        else:
            self._comptadors[client] = 1
        return client

    def escriure_cua(self) -> None:
        clients = []
        for client in self._cua:
            clients.append(client)
        print("cua:", *reversed(clients))

    def escriure_clients(self):
        for client in sorted(self._comptadors.keys()):
            print(client, self._comptadors[client])


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
import yogi
from typing import Optional


def processa_factura(k: int) -> str:
    item = yogi.scan(str)
    total_sum = 0.0
    selected_item = ""
    while item is not None and item != "---":
        item_cost = yogi.read(float)
        total_sum += item_cost
        if selected_item == "" and total_sum >= k:
            selected_item = item
        item = yogi.scan(str)
    return selected_item


def main():
    k = yogi.read(int)
    n = yogi.read(int)

    for _ in range(k):
        nom = yogi.read(str)
        item = processa_factura(n)
        if item != "":
            print(f"A la factura {nom} l'euro {n} s'ha gastat en {item}.")
        else:
            print(f"A la factura {nom} no s'ha gastat l'euro {n}.")


if __name__ == "__main__":
    main()

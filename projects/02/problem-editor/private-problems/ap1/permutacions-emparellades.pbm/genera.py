import yogi


def possible(i: int, j: int, L: list[int]) -> bool:
    if i == 0:
        return True
    if i % 2 == 0:
        return j % 2 == L[i - 2] % 2
    if i > 1:
        return j > L[i - 2]
    return True


def genera(i: int, n: int, L: list[int], u: list[bool]) -> None:
    if i == n:
        print(*L)
    else:
        for j in range(n):
            if not u[j]:
                if possible(i, j, L):
                    L[i] = j
                    u[j] = True
                    genera(i + 1, n, L, u)
                    u[j] = False


def main():
    n = yogi.read(int)
    L = [0 for _ in range(n)]
    u = [False for _ in range(n)]
    genera(0, n, L, u)


main()

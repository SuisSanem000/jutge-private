from yogi import read, scan


def main() -> None:
    x, y = read(int), read(int)  # tresor
    i, j = 0, 0  # pos actual
    instruccions, passes = 0, 0
    trobat = False
    paraula = scan(str)
    while not trobat and paraula is not None:
        p = read(int)
        passes = passes + p  # pressuposo que les faig totes
        while not trobat and p > 0:
            if paraula == "up":
                j += 1
            elif paraula == "down":
                j -= 1
            elif paraula == "right":
                i += 1
            else:
                i -= 1

            p -= 1
            if x == i and y == j:
                trobat = True
        passes, instruccions = passes - p, instruccions + 1
        paraula = scan(str)

    if not trobat:
        print("not found ", end="")
    print(instruccions, passes)


if __name__ == "__main__":
    main()

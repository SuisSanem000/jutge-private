import yogi

info = dict[str, int]()  # diccionari amb els diners donats per cada nif
max_nif: str | None = None

for command in yogi.tokens(str):
    if command == "N":
        print("number:", len(info))
    elif command == "D":
        n, m = yogi.read(str), yogi.read(int)
        info[n] = info.get(n, 0) + m
        if max_nif is None or n > max_nif:
            max_nif = n
    elif command == "L":
        if max_nif is None:
            print(None)
        else:
            print(max_nif, info[max_nif])
    elif command == "P":
        print(*sorted(n for n in info if n[-2] in "02468"))
    elif command == "Q":
        print(info.get(yogi.read(str), -1))
    else:
        assert False

def main() -> None:
    N = 300
    for b in range(2, 20):  # b in [2, ..., 19]
        for d in range(b):  # d in [0, ..., b - 1]
            print(b, d, N, end='')
            for i in range(N):  # n elems
                print(f' {i}', end='')
            print()
        
main()


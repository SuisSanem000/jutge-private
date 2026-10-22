import sys

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        n = int(line)
        total = sum(i for i in range(2, n + 1) if is_prime(i))
        print(total)

if __name__ == "__main__":
    main()

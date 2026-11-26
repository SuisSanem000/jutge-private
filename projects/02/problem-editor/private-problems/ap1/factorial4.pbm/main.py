from yogi import scan

n = scan(int)
while n is not None:
    print(factorial(n))
    n = scan(int)

from yogi import scan

x = scan(int)
while x is not None:
    escriure_factors_primers(x)
    x = scan(int)

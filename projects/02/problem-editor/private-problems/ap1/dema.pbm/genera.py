from solution import *

d, m, a = 1, 'gener', 1999
for _ in range(365*50):
    print(d, m, a)
    d, m, a = dia_seguent(d, m, a)

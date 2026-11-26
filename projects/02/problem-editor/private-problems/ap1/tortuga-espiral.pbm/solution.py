from turtle_pil import *
from yogi import *


n = read(int)
m = read(int)

for i in range(1, n+1):
    fd(m * i)
    lt(90)
    fd(m * i)
    lt(90)

done()

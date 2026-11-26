# uso bucles per anar per feina encara que no els coneguin en aquest punt

from turtle_pil import *
from yogi import *

forma = read(str)
if forma == 'cercle':
    radi = read(int)
    circle(radi)
elif forma == 'quadrat':
    mida = read(int)
    for _ in range(4):
        fd(mida)
        lt(90)
elif forma == 'rectangle':
    amplada = read(int)
    alçada = read(int)
    for _ in range(2):
        fd(amplada)
        lt(90)
        fd(alçada)
        lt(90)

done()

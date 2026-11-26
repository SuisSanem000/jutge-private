from yogi import *


def my_main() -> None:
    more = read(int)
    while more == 1:
        m1 = Movie('t1', read(int), read(int), read(float))
        m2 = Movie('t2', read(int), read(int), read(float))
        print(compare_movies(m1, m2))
        more = read(int)


my_main()

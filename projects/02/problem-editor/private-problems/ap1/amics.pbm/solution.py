from yogi import *


n, m = read(int), read(int)
friends: list[set[int]] = [set() for _ in range(n)]
for _ in range(m):
    x, y = read(int), read(int)
    friends[x].add(y)
    friends[y].add(x)
p = scan(int)
while p is not None:
    s = friends[p]
    for x in friends[p]:
        s = s | friends[x]
    s.discard(p)
    print(len(s))
    p = scan(int)

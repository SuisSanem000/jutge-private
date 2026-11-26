from yogi import scan

d = {}
w = scan(str)
while w is not None:
    w = w.lower()
    if w in d:
        d[w] += 1
    else:
        d[w] = 1
    w = scan(str)

pairs = [(c, w) for w, c in d.items()]
for c, w in sorted(pairs):
    print(c, w)

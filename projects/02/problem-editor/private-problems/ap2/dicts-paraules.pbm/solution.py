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
for w in sorted(d.keys()):
    print(w, d[w])

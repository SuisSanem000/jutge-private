from yogi import scan

s = set()
w = scan(str)
while w is not None:
    s.add(w.lower())
    w = scan(str)
for w in sorted(s):
    print(w)

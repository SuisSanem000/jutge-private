from yogi import read


class Point:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y


class Skyline:
    def __init__(self) -> None:
        self.n = 1
        self.curr = 0
        self.p = [Point(0, 0)]

    def add(self, q: Point) -> None:
        if self.p[-1].y != q.y:
            self.p.append(q)
            self.n += 1

    def read(self) -> None:
        k = read(int)
        for _ in range(k):
            x, y = read(int), read(int)
            self.add(Point(x, y))

    def current(self) -> Point:
        return self.p[self.curr]

    def advance(self) -> None:
        self.curr += 1

    def finished(self) -> int:
        return self.curr == self.n-1

    def next(self) -> Point:
        return self.p[self.curr+1]


def skyline_superposition(a: Skyline, b: Skyline) -> Skyline:
    merged = Skyline()

    # loop invariant: a is the active "visible" skyline
    while not a.finished() and not b.finished():
        if a.next().x == b.next().x:
            if b.next().y > a.next().y:
                a, b = b, a
            merged.add(a.next())
            b.advance()
            a.advance()
        elif a.next().x < b.next().x:
            if a.next().y < b.current().y:
                merged.add(Point(a.next().x, b.current().y))
                a.advance()
                a, b = b, a
            else:
                merged.add(a.next())
                a.advance()
        else:  # b.next().x < a.next().x
            if b.next().y > a.current().y:
                merged.add(b.next())
                b.advance()
                a, b = b, a
            else:
                b.advance()

    if not b.finished():
        a = b

    while not a.finished():
        merged.add(a.next())
        a.advance()

    return merged


def merge_many(skylines: list[Skyline], l: int, r: int) -> Skyline:
    if l == r:
        return skylines[l]
    m = (l+r)//2
    left = merge_many(skylines, l, m)
    right = merge_many(skylines, m+1, r)
    return skyline_superposition(left, right)


def main() -> None:
    skylines = []
    s = read(int)
    for _ in range(s):
        a = Skyline()
        a.read()
        skylines.append(a)
    merged = merge_many(skylines, 0, len(skylines)-1)
    print(merged.n-1, end='')
    for i in range(1, merged.n):
        print('', merged.p[i].x, merged.p[i].y, end='')
    print()


main()

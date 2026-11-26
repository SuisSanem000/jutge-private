from yogi import *

# returns whether v has a max-sum in m parts ≤ x | O(n)


def has_max_sum(v: list[int], m: int, x: int) -> bool:
    curr = 0
    for z in v:
        if curr+z <= x:
            curr += z
        else:
            m -= 1
            if m == 0:
                return False
            curr = z
    return True


# returns the min-max-sum of a vector for m parts | O(n log sum(v))
def min_max_sum(v: list[int], m: int) -> int:
    l = max(v)
    r = sum(v)
    ans = l
    while l <= r:
        x = (l+r)//2
        if has_max_sum(v, m, x):
            ans = x
            r = x-1
        else:
            l = x+1
    return ans


# main program
def main() -> None:
    for m in tokens(int):
        n = read(int)
        v = [read(int) for _ in range(n)]
        print(min_max_sum(v, m))


main()

"""This program reads a non-empty sequence of closed intervals as pairs
[a, b] of integers such that a <= b. It writes the union of the intervals
as a sequence of closed intervals. The output intervals are disjoint and
maximal, and are sorted by their start.
"""
import yogi

def read_intervals() -> tuple[list[int], list[int]]:
    """Reads a sequence of closed intervals [a, b] and returns two sorted lists:
    - the list of the start points a
    - the list of the end points b
    """
    starts = list[int]()
    ends = list[int]()
    start = yogi.scan(int)
    while start is not None:
        starts.append(start)
        ends.append(yogi.read(int))
        start = yogi.scan(int)
    return sorted(starts), sorted(ends)

def write_intervals(starts: list[int], ends: list[int]) -> None:
    """Writes the union of the intervals defined by the sorted lists of start
    and end points.
    """
    i, j = 0, 0
    opened = 0
    while i < len(starts):
        if starts[i] <= ends[j]:
            if opened == 0:
                print(starts[i], end = ' ')
            opened += 1
            i += 1
        else:
            opened -= 1
            if opened == 0:
                print(ends[j])
            j += 1
    print(ends[-1])
    
def main() -> None:
    """Main function according to the statement of the problem."""
    starts, ends = read_intervals()
    write_intervals(starts, ends)
    
if __name__ == "__main__":
    main()
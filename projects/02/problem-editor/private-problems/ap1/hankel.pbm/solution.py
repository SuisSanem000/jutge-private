from typing import TypeAlias
from yogi import read

Matrix: TypeAlias = list[list[int]]

def is_constant(mat: Matrix, i: int, j: int) -> bool:
    '''
    Pre: len(mat) > 0
    Post: returns True if diagonal starting at i, j going up-right is constant; False otherwise
    '''
    n = len(mat)
    while 0 < i and j < n - 1:
        if mat[i][j] != mat[i - 1][j + 1]:
            return False
        i -= 1
        j += 1
    return True

def is_hankel(mat: Matrix) -> bool:
    '''
    Pre: len(mat) > 0
    '''
    n = len(mat)
    for i in range(1, n):
        if not is_constant(mat, i, 0):
            return False
    for j in range(0, n - 1):
        if not is_constant(mat, n - 1, j):
            return False
    return True



def main() -> None:
    n = read(int)
    for _ in range(n):
        m = read(int)
        mat = [[read(int) for _ in range(m)] for _ in range(m)]
        if (is_hankel(mat)):
            print("yes")
        else:
            print("no")

main() 

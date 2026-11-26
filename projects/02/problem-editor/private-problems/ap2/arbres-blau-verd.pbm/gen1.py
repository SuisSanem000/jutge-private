
def green_blue_trees(n):
    if n == 0:
        return ['-']
    else:
        result = []
        for i in range(n):
            for t1 in green_blue_trees(i):
                for t2 in green_blue_trees(n - i - 1):
                    result.append('G' + t1 + t2)
                    result.append('B' + t1 + t2)
        return result


def main():
    for n in range(9):
        for t in green_blue_trees(n):
            print(t)


main()

# do not forget to add number of lines at the beginning of the output

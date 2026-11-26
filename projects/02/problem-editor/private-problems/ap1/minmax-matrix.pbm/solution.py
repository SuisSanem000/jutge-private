def min_Max(M):
    n = len(M)
    mM = []
    for i in range(n):
        mM.append([min(M[i]), max([row[i] for row in M])])
    return mM

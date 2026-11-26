def zeros_o_uns(n):
    q0 = 0
    q1 = 0
    while n > 0:
        if n % 2 == 0:
            q0 += 1
        else:
            q1 += 1
        n = n // 2
    if q0 > q1:
        return 0
    elif q0 < q1:
        return 1
    else:
        return 2

while True:
    b = random.randint(1, 15)
    c = random.randint(1, 10)
    a = random.randint(1, 10)

    s1 = a + b * c
    s2 = (a + b) * c
    s3 = a + b * c-1
    s4 = a * b + c
    s5 = a + b-1 * c
    if all_different(s1, s2, s3, s4, s5):
        break

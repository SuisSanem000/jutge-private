from yogi import tokens, read

for dia in tokens(int):
    mes, any = read(str), read(int)
    print(dia_seguent(dia, mes, any))

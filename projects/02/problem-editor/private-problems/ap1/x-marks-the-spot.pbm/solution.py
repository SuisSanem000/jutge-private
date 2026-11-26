rows_cols = int(input())

if rows_cols == 1:
    print("X")
elif (rows_cols % 2) == 0:
    for i in range(rows_cols//2):
        print(" " * i + "\\" + " " * 2*(rows_cols//2-(i+1)) + "/")
    for i in range(rows_cols//2):
        print(" " * (rows_cols//2-(i+1)) + "/" + " " * 2*i + "\\")
elif (rows_cols % 2) == 1:
    for i in range(rows_cols//2):
        print(" " * i + "\\" + " " * (2*(rows_cols//2-(i+1))+1) + "/")
    print(" " * ((rows_cols//2)) + "X")
    for i in range(rows_cols//2):
        print(" " * (rows_cols//2-(i+1)) + "/" + " " * ((2*i)+1) + "\\")

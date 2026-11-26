# jordi delgado


from yogi import read
import sys
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    
def main():
    M = dict()
    s = read(str)
    while s is not None:
        if s == "affair":
            x = read(str)
            if x not in M:
                M.update({x : ""})
            y = read(str)
            if y not in M:
                M.update({y : ""})
            if M[x] == y:
                eprint("ERROR: ",x," i ",y," ja estan liats")
            else:
                if M[x] != "":
                    M[M[x]] = ""
                if M[y] != "":
                    M[M[y]] = ""
                M[x] = y
                M[y] = x
        else:            
              print("COUPLES:")
              for k in sorted(M):
                  if k < M[k]:
                      print(k,' ',M[k],sep='')
              print("ALONE:")
              for k in sorted(M):
                  if M[k]=="":
                      print(k)
              print("----------")
        s = read(str)

main()

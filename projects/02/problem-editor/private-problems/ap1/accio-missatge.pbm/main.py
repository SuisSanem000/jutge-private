from yogi import read, tokens

for qui in tokens(str):
    verb, cops, fem = read(str), read(int), read(int)
    missatge(qui, verb, cops, bool(fem))
    

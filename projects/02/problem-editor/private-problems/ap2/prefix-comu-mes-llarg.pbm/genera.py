import random
import sys

pref = "foo"
for i in range(int(sys.argv[1])):
    print(pref + str(random.randint(0, 1000)))

#!/usr/bin/env python3

import sys


n = int(sys.argv[1])

print(*[i for i in range(n)], end=" ")
print(*[-1 for _ in range(n + 1)])

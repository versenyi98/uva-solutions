import sys
input = sys.stdin.read().splitlines()

idx = 0
cases = int(input[idx])

for i in range (0, cases):
    idx += 1
    N, M = input[idx].split()
    print(int(str(int(N[::-1]) + int(M[::-1]))[::-1]))
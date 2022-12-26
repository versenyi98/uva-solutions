import sys

input = sys.stdin.read().splitlines()

length = len(input)

for i in range(0, length):
    N, A = map(int, input[i].split())
    sum = 0
    for j in range(1, N + 1):
        sum += j * pow(A, j)
    print(sum)
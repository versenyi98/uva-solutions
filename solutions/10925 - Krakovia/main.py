import sys

input = sys.stdin.read().splitlines()

idx = 0
test_case = 0

while True:
    N, F = map(int, input[idx].split())

    if N == 0 and F == 0:
        break

    idx += 1
    sum = 0

    for i in range(0, N):
        sum = sum + int(input[idx])
        idx += 1
    test_case += 1
    print("Bill #%d costs %d: each friend should pay %d\n" % (test_case, sum, sum//F))

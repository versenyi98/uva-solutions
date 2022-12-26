import sys
input = sys.stdin.read().splitlines()

idx = 0

while input[idx] != "0":
    num = int(input[idx])
    rem = num % 10
    num = num // 10 - 5 * rem
    print(1 if num % 17 == 0 else 0)
    idx += 1
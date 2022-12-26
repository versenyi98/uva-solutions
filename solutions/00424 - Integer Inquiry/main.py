import sys

def main():
    sum = 0
    for temp in sys.stdin: 
        sum = sum + int(temp)
        if temp == 0:
            break
    print(sum)


if __name__ == "__main__":
    main()
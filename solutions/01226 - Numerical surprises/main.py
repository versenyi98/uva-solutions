def main():

    tc = input()
    tc = int(tc)
    while tc > 0:
        tc = tc - 1

        N = int(input())
        P = int(input())
        print(P % N)

if __name__ == "__main__":
    main()
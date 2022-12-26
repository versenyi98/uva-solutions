import sys

def main():

    i = 0
    a = 0
    b = 1

    fib = []
    fib.append(0)
    fib.append(1)

    while i < 5000:
        fib.append(a + b)
        b = a + b
        a = b - a
        i = i + 1

    for temp in sys.stdin: 
        print("The Fibonacci number for " + temp.strip('\n') + " is " +  str(fib[int(temp)]))


if __name__ == "__main__" :
    main()
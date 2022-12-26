import sys
import math

def main() :

    for line in sys.stdin:
        nums = line.strip('\n').split(' ')
        
        first = nums[0].split('.')

        if len(first) == 1:
            print(int(nums[0]) ** int(nums[len(nums) - 1]))
        else:
            f = (int(first[0]) * (10 ** int(len(first[1]))) + int(first[1])) ** int(nums[len(nums) - 1])
            length = int(math.log10(float(nums[0]) ** int(nums[len(nums) - 1])))
            
            line = str(f)
            endl = 0

            for i in reversed(line):
                if i == '0':
                    endl = endl + 1
                else :
                    break

            if length < 0:
                prefix = "."

                while length < 0:
                    prefix = prefix + "0"
                    length = length + 1

                print(prefix + line[0:max(0, len(line) - endl)])
            else:
                length = length + 1                
                print(line[0:length] + "." + line[length:max(0, len(line) - endl)])


if __name__ == "__main__":
    main()
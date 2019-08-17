import sys
import math
def divideland(num):
    list1 = []
    list2 = []
    for i in sorted(num, reverse=True):
        if sum(list1) < sum(list2):
           list1.append(i)
        else:
           list2.append(i)
    return (max(sum(list1),sum(list2)))

# read first line: length of vector
first_line = sys.stdin.readline()
n = int(first_line)

numbers = []

# read numbers
for line in sys.stdin:
    numbers.append(int(line))

print(divideland(numbers))

import sys
import re

# read first line: length of vector
t = sys.stdin.readline()
t=int(t)
string=[]
# read numbers
for line in sys.stdin:
    string.append((line.split()))


def reverse(s):
  return s[::-1]

clean = re.compile(r'[^A-Za-z0-9]+')
for i in range (0,t):
    string[i]=''.join(list(filter(bool, (clean.sub('', w) for w in string[i]))))
    #print (string[i])

    if string[i].upper()==reverse(string[i].upper()):
      print('true')
    else:
      print('false')

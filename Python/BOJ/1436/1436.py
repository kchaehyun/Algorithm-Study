import sys
input = sys.stdin.readline

n = int(input())
idx = 0
num = 666

while True:
    if '666' in str(num):
        idx += 1
    if idx == n :
        break
    num += 1

print(num)
import sys

input = sys.stdin.readline
num = int(input())
num = int(1000 - num)
answer=0

while num>0:
    if num >= 500 :
        answer += num//500
        num %= 500
    elif num >= 100 :
        answer += num//100
        num %= 100
    elif num >= 50 :
        answer += num//50
        num %= 50
    elif num >= 10 :    
        answer += num//10
        num %= 10
    elif num >= 5 :    
        answer += num//5
        num %= 5
    else:
        answer += num
        num = 0

print(answer)
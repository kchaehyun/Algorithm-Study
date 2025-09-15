import sys
input = sys.stdin.readline

N = int(input())
ans = N
if N >= 100:
    ans = 99
    idx = 100
    while idx <= N:
        hundred = idx//100
        ten = (idx//10) % 10
        one = idx % 10
        if hundred - ten == ten - one :
            ans += 1
        idx += 1
print(ans)
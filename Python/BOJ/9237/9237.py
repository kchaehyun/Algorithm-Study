import sys

input = sys.stdin.readline

num = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
ans = arr[0] + 2

for i in range(num):
    if i+1 + arr[i] > arr[0]:
        day = i + arr[i] + 2
    ans = max(ans, day)

print(ans)
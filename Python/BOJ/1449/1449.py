import sys
input = sys.stdin.readline

N, L = map(int, input().split())

arr = list(map(int, input().split()))
arr.sort()
i, ans = 0, 0

while i < N:
    target = arr[i] + L - 1
    ans += 1
    while i < N and arr[i] <= target:
        i += 1

print(ans)
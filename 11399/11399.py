import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
arr2 = [0 for _ in range(N)]
sum = 0

for i in range(N):
    for j in range(i+1):
        arr2[i] += arr[j]

for i in range(N):
    sum += arr2[i]
print(sum)
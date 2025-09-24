import sys
input = sys.stdin.readline

N = int(input())
first = int(input())
arr = []
for _ in range(N-1):
    arr.append(int(input()))
people = 0

if arr:
    while True:
        if first <= max(arr):
            arr[arr.index(max(arr))] -= 1
            first += 1
            people += 1
        else:
            break
    print(people)
else:
    print(0)
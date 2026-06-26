import sys

input = sys.stdin.readline

while True:
    arr = list(map(int,input().split()))
    arr.sort(reverse=True)
    if arr[0] + arr[1] + arr[2] == 0:
        break
    if arr[1] + arr[2] <= arr[0]:
        print("Invalid")
        continue
    if arr[0] == arr[1] == arr[2]:
        print("Equilateral")
    elif arr[0] == arr[1] or arr[1] == arr[2]:
        print("Isosceles")
    else:
        print("Scalene")
'''
### 풀이 1
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
'''

### 풀이 2
import sys
import heapq
input = sys.stdin.readline

N = int(input())
dasom = int(input())
heap = []
ans = 0
if N > 1 :
    for _ in range(N-1) :
        v = int(input())
        heapq.heappush(heap, -v)
    while True :
        max_val = heapq.heappop(heap)
        if -(max_val) >= dasom :
            max_val += 1
            dasom += 1
            ans += 1
            heapq.heappush(heap, max_val)
        else : 
            break
print(ans)
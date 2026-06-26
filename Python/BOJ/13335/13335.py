import sys
from collections import deque
input = sys.stdin.readline

n, w, L = map(int, input().split())
trucks = deque(list(map(int, input().split())))
queue = deque([0] * w)
time = 0
weights = 0
while trucks or weights > 0:
    time += 1
    weights -= queue.popleft()
    if trucks and weights + trucks[0] <= L :
        queue.append(trucks[0])
        weights += trucks[0]
        trucks.popleft()
    else :
        queue.append(0)

print(time)
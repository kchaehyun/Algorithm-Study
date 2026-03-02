import sys
from collections import deque
input = sys.stdin.readline

N = int(input())

# cards = []
# for i in range(N):
#     cards.append(i+1)
# queue = deque(cards)
queue = deque(range(1,N+1))

while len(queue) > 1:
    queue.popleft()
    queue.append(queue.popleft())

print(queue[0])
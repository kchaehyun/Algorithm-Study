import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T) :
    N, M = map(int, input().split())
    prior = list(map(int,input().split()))
    q = deque([(p,i) for i, p in enumerate(prior)])
    num = 0
    while q :
        now, idx = q.popleft()
        if q and now < max(p for p,_ in q) :
            q.append((now,idx))
        else :
            num += 1
            if idx == M :
                break
    print(num)
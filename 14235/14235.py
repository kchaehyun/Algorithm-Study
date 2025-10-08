import sys, heapq
input = sys.stdin.readline

n = int(input())
heap = []

for i in range(n) :
    a = list(map(int, input().split()))
    if a == [0] :
        if heap :
            print(-heapq.heappop(heap))
        else :
            print(-1)
    else :
        gift = a[1:]
        for g in gift:
            heapq.heappush(heap, -g)
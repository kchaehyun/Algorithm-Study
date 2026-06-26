import sys
from collections import deque
input = sys.stdin.readline

def bfs(row, col) :
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    house = 1
    visited[row][col] = True
    queue = deque([(row, col)])
    while queue :
        x, y = queue.popleft()
        for i in range(4):
            next_x = x+dx[i]
            next_y = y+dy[i]
            if 0 <= next_x < N and 0 <= next_y < N:
                if graph[next_x][next_y] == 1 and not visited[next_x][next_y]:
                    house += 1
                    queue.append((next_x, next_y))
                    visited[next_x][next_y] = True
    return house
        
        

N = int(input())
graph = [list(map(int, input().strip())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
house = []
town = 0

for row in range(N):
    for col in range(N) :
        if graph[row][col] == 1 and not visited[row][col]:
            town +=1
            house.append(bfs(row, col))

house.sort()
print(town)
print(*house, sep="\n")
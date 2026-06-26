import sys
input = sys.stdin.readline

R, C, N = map(int, input().split())
graph = [input().strip() for _ in range(R)]

def status(original_graph) :
    result = [['O']*C for _ in range(R)] # 나머지 3
    for r in range(R) :
        for c in range(C) :
            if original_graph[r][c] == 'O' :
                result[r][c] = '.'
                for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)] :
                    nr = r + dr
                    nc = c + dc
                    if 0 <= nr < R and 0 <= nc < C :
                        result[nr][nc] = '.'
    return result   


if N == 1 :
    print('\n'.join(graph))
elif N % 2 == 0 :
    print('\n'.join(['O'*C for _ in range(R)]))
elif N % 4 == 3 :
    graph = status(graph)
    for g in graph :
        print(''.join(g))
elif N % 4 == 1 :
    graph = status(status(graph))
    for g in graph :
        print(''.join(g))

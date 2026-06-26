import sys
input = sys.stdin.readline

N, M = map(int, input().split())
listen = set(input().strip() for _ in range(N))
seen = set(input().strip() for _ in range(M))

ans = sorted(listen & seen)

print(len(ans))
print('\n'.join(ans))
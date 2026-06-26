import sys
input = sys.stdin.readline

N = str(input().strip())
print(''.join(sorted(N, key=lambda x:-int(x))))
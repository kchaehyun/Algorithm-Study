import sys
input = sys.stdin.readline

N = int(input())
words = [input().strip() for _ in range(N)]
words = list(set(words))
words = sorted(words,key=lambda x:(len(x), x))
for word in words:
    print(word)
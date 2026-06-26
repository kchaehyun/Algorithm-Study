import sys
from itertools import permutations
input = sys.stdin.readline

n = int(input())
k = int(input())
cards = [int(input()) for _ in range(n)]
comb = set()
    
for i in permutations(cards,k):
    comb.add(''.join(map(str, i)))
    
print(len(comb))
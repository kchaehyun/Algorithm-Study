import sys
from collections import Counter
input = sys.stdin.readline

N = input().strip()
c = Counter(N)

six_nine = c['6'] + c['9']

c['6'] = (six_nine + 1) // 2
c['9'] = 0

print(max(c.values()))
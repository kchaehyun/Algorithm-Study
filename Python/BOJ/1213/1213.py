import sys
from collections import Counter
input = sys.stdin.readline

name = str(input()).rstrip()
counter = Counter(name)
half = []
possible = True

if len(name) % 2 == 0: 
    for k in sorted(counter.keys()):
        if counter[k] % 2 == 1:
            possible = False
            break
        half.append(k * (counter[k]//2))
    if possible :
        half = ''.join(half)
        print(half + half[::-1])
    else :
        print("I'm Sorry Hansoo")
else:
    odd = 0
    for k in sorted(counter.keys()):
        if counter[k] % 2 == 1:
            odd += 1
            middle = k
        if odd > 1:
            possible = False
            break
        half.append(k * (counter[k]//2))
    if possible :
        half = ''.join(half)
        print(half + middle + half[::-1])
    else :
        print("I'm Sorry Hansoo")
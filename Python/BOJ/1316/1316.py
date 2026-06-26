import sys
input = sys.stdin.readline

N = int(input())
ans = 0

for _ in range(N) :
    word = input().strip()
    s = set()
    s.add(word[0])
    p = True
    for i in range(1,len(word)) :
        if word[i] in s :
            if word[i] != word[i-1] :
                p = False
                break
        else :
            s.add(word[i])
    if p :
        ans += 1
    else :
        continue
            
print(ans)
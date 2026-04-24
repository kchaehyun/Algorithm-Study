import sys
input = sys.stdin.readline

N = int(input())

key = set()
for _ in range(N) :
    words = list(map(str, input().strip().split(' ')))

    word = -1
    idx = -1
    
    for i in range(len(words)) :
        if words[i][0].upper() not in key :
            key.add(words[i][0].upper())
            word = i
            idx = 0
            break
    if word == -1:
        for i in range(len(words)) :
            for j in range(len(words[i])) :
                if words[i][j].upper() not in key :
                    key.add(words[i][j].upper())
                    word = i
                    idx = j
                    break
            if word != -1 :
                break
    for i in range(len(words)) :
        if i == word :
            w = words[i]
            words[i] = w[0:idx] + '[' + w[idx:idx+1] + ']' + w[idx+1:]
    print(*words)
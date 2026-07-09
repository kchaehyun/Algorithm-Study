from collections import Counter

def solution(weights):
    answer = 0
    weights = Counter(weights)
    for w,v in weights.items() :
        if v > 1:
            answer += v*(v-1)//2
        if w*3/2 in weights :
            answer += v*weights[w*3/2]
        if w*2 in weights :
            answer += v*weights[w*2]
        if w*4/3 in weights :
            answer += v*weights[w*4/3] 
    return answer
def solution(brown, yellow):
    answer = []
    total = brown+yellow
    h = 3
    while True :
        w = total // h
        if (w-2)*(h-2) == yellow :
            answer = [w,h]
            break
        else :
            h += 1
        
    return answer
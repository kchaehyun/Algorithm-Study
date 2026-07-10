def solution(picks, minerals):
    answer = 0
    power = [[1,1,1],[5,1,1],[25,5,1]]
    minerals = minerals[:sum(picks)*5]
    
    cnts = []
    for i in range(0, len(minerals), 5) :
        region = minerals[i:i+5]
        d = region.count("diamond")
        iron = region.count("iron")
        s = region.count("stone")
        cnts.append((d,iron,s))
    cnts.sort(reverse=True)
    
    for d,i,s in cnts :
        if picks[0] != 0 :
            picks[0] -= 1
            answer += d*power[0][0]+i*power[0][1]+s*power[0][2]
        elif picks[1] != 0 :
            picks[1] -= 1
            answer += d*power[1][0]+i*power[1][1]+s*power[1][2]
        elif picks[2] != 0 :
            picks[2] -= 1
            answer += d*power[2][0]+i*power[2][1]+s*power[2][2]
    return answer
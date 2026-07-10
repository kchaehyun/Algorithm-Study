def solution(plans):
    answer = []
    plans.sort(key=lambda x:x[1])
    
    for i,(name,start,playtime) in enumerate(plans) :
        h = int(start[0:2])
        m = int(start[3:])
        plans[i][1] = h*60+m
        plans[i][2] = int(playtime)
        
    s = []
    for i in range(len(plans)-1) :
        if plans[i][1]+plans[i][2] > plans[i+1][1] :
            s.append((plans[i][0],plans[i][1]+plans[i][2]-plans[i+1][1]))
        elif plans[i][1]+plans[i][2] == plans[i+1][1] :
            answer.append(plans[i][0])
        else :
            answer.append(plans[i][0])
            res_time = plans[i+1][1]-plans[i][1]-plans[i][2]
            while s and res_time > 0:
                name, time = s.pop()
                if time - res_time <= 0 :
                    answer.append(name)
                    res_time -= time
                else :
                    s.append((name,time-res_time))
                    break 
    answer.append(plans[-1][0])
    while s:
        name, time = s.pop()
        answer.append(name)
                
    return answer
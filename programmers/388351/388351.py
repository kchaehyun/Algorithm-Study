def num2time(num) :
    h = num // 100
    m = num % 100
    if m >= 60 :
        m -= 60
        h += 1
    if m < 10 :
        return int(str(h)+'0'+str(m))
    return int(str(h)+str(m))

def solution(schedules, timelogs, startday):
    answer = 0
    for i in range(len(schedules)) :
        s = startday
        ok = True
        s_time = num2time(schedules[i]+10)
        for j in range(len(timelogs[i])) :
            if s < 6 and s_time < timelogs[i][j] :
                ok = False
                break
            if s == 7 :
                s = 0
            s += 1
        if ok :
            answer += 1
            
    return answer

print(solution([700, 800, 1100],[[710, 2359, 1050, 700, 650, 631, 659], [800, 801, 805, 800, 759, 810, 809], [1105, 1001, 1002, 600, 1059, 1001, 1100]],5))
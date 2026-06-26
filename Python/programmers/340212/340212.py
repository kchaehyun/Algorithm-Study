def check(d,t,level,lim) :
    total_time = t[0]
    for i in range(1,len(d)) :
        if d[i] <= level :
            total_time += t[i]
        else :
            total_time += ((d[i]-level) * (t[i-1]+t[i]) + t[i])
    if total_time <= lim :
        return True
    else :
        return False

def solution(diffs, times, limit):
    answer = 0
    left = 1
    right = max(diffs)
    while left <= right :
        mid = (left + right) // 2
        if check(diffs,times,mid,limit) :
            answer = mid
            right = mid - 1
        else :
            left = mid + 1
        
    return answer

print(solution([1, 5, 3],[2, 4, 7],30))
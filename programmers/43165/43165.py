def solution(numbers, target):
    answer = 0
    def dfs(start,idx) :
        nonlocal answer
        if idx == len(numbers) :
            if start == target :
                answer += 1
            return
        dfs(start-numbers[idx],idx+1)
        dfs(start+numbers[idx],idx+1) 
    dfs(0,0)
    return answer
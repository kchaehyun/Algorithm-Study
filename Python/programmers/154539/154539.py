def solution(numbers):
    answer = [-1] * len(numbers)
    s = []
    for i,n in enumerate(numbers) :
        while s and numbers[s[-1]] < n: # 스택에 아직 답을 못 찾은 인덱스가 있고, 그 인덱스의 숫자가 현재 숫자보다 작으면, 현재 숫자가 그 인덱스의 뒤 큰 수
            idx = s.pop()
            answer[idx] = n
        s.append(i)            
            
    return answer
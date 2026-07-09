# Programmers 176962 - 과제 진행하기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/176962)
- 과제 정보 `plans`가 주어진다.
- 각 과제는 `[이름, 시작 시각, 걸리는 시간]` 형태이다.
- 새로운 과제를 시작할 시간이 되면 진행 중이던 과제는 멈추고 새 과제를 먼저 진행한다.
- 멈춘 과제는 가장 최근에 멈춘 과제부터 다시 시작한다.
- 과제를 끝낸 순서대로 이름을 담아 반환한다.

## 아이디어
- 과제를 시작 시각 기준으로 정렬한다.
- 시작 시각을 분 단위 정수로 바꾸면 시간 계산이 쉬워진다.
- 현재 과제가 다음 과제 시작 전까지 끝나지 못하면 남은 시간을 스택에 저장한다.
- 시간이 남으면 스택에서 최근에 멈춘 과제를 꺼내 이어서 진행한다.
- 스택은 가장 최근에 멈춘 과제를 먼저 처리해야 하므로 LIFO 구조와 잘 맞는다.

## 시간복잡도
- 과제 정렬이 지배적이므로 O(N log N)이다.

## 풀이 과정
1. `plans`를 시작 시각 기준으로 정렬한다.
2. 시작 시각 문자열을 분 단위 정수로 변환하고, 걸리는 시간도 정수로 바꾼다.
3. 현재 과제와 다음 과제의 시작 시각을 비교한다.
4. 현재 과제가 끝나기 전에 다음 과제가 시작하면 남은 시간을 스택에 넣는다.
5. 현재 과제가 다음 과제 시작 전 또는 정확히 시작 시간에 끝나면 정답에 추가한다.
6. 남은 시간이 있다면 멈춘 과제를 스택에서 꺼내 가능한 만큼 처리한다.
7. 마지막 과제를 정답에 넣고, 스택에 남은 과제를 차례로 꺼내 정답에 추가한다.

## 코드 설명
```python
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
```
- `plans.sort(key=lambda x:x[1])`로 과제를 시작 시각 순서대로 정렬한다.
- `s`는 멈춘 과제와 남은 시간을 저장하는 스택이다.
- 다음 과제 시작 전까지 시간이 부족하면 현재 과제의 남은 시간을 스택에 넣는다.
- 시간이 남으면 스택에서 과제를 꺼내 최근에 멈춘 과제부터 이어서 처리한다.
- 모든 새 과제 시작이 끝난 뒤에는 마지막 과제와 스택에 남은 과제를 순서대로 완료 처리한다.

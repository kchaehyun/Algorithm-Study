# Programmers 388351 - [PCCP 기출문제] 1번 / 유연근무제

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/388351)
- 직원들이 정해진 출근 희망 시각에 맞춰 5일(평일) 동안 지각하지 않고 출근하면 상품을 준다.
- 지각 기준은 "출근 희망 시각 + 10분"이다.
- 주말(토요일, 일요일)은 출근 기록을 확인하지 않는다.

## 아이디어
- 시간 계산 시 60분이 넘어가면 시(hour) 단위를 올림 처리해야 한다 (HHMM 형식).
- `startday`를 기준으로 각 출근 기록이 평일인지 주말인지 판별한다.
- 각 직원에 대해 모든 평일 출근 기록이 기준 시각 이내인지 확인한다.

## 시간복잡도
- O(N * 7), 여기서 N은 직원의 수이다.

## 풀이 과정
1. 시간을 HHMM 형식으로 더해주는 `num2time` 함수를 정의한다. (분 단위에 10을 더하고 60이 넘으면 시간으로 올림)
2. 각 직원에 대해 반복:
    - 출근 희망 시각에 10분을 더한 `s_time`을 구한다.
    - 7일간의 기록을 순회하며, 요일을 계산한다 (1: 월, 2: 화, 3: 수, 4: 목, 5: 금, 6: 토, 7: 일).
    - 평일(1~5)일 때만 실제 출근 시각이 `s_time` 이하인지 확인한다.
    - 한 번이라도 지각하면 해당 직원은 제외한다.
3. 모든 조건을 만족하는 직원의 수를 카운트한다.

## 코드 설명
```python
def num2time(num) :
    h = num // 100
    m = num % 100
    if m >= 60 :
        m -= 60
        h += 1
    # HHMM 형식을 맞추기 위해 정수형으로 반환
    if m < 10 :
        return int(str(h)+'0'+str(m))
    return int(str(h)+str(m))

def solution(schedules, timelogs, startday):
    answer = 0
    for i in range(len(schedules)) :
        s = startday # 첫째 날 요일
        ok = True
        s_time = num2time(schedules[i]+10)
        for j in range(len(timelogs[i])) :
            # 평일(1~5)인 경우만 확인
            if s < 6 and s_time < timelogs[i][j] :
                ok = False
                break
            # 요일 순환 처리
            if s == 7 :
                s = 0
            s += 1
        if ok :
            answer += 1
            
    return answer
```
- `num2time` 함수로 시간 가산 연산을 정확하게 처리한다.
- `startday` 변수를 활용해 매일의 요일을 추적한다.

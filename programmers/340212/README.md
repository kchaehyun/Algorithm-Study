# Programmers 340212 - [PCCP 기출문제] 2번 / 퍼즐 게임 챌린지

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/340212)
- n개의 퍼즐을 제한 시간 내에 풀어야 한다.
- 각 퍼즐은 난이도(`diff`)와 소요 시간(`time_cur`)이 있으며, 이전 퍼즐의 소요 시간(`time_prev`)도 영향을 준다.
- 숙련도(`level`)에 따라 퍼즐을 푸는 방식이 달라진다:
    - `diff <= level`: `time_cur` 만큼 걸린다.
    - `diff > level`: `(diff - level)`번 틀리고, 틀릴 때마다 `(time_cur + time_prev)` 만큼 시간이 추가로 소요되며 마지막에 `time_cur` 만큼 더 써서 해결한다.
- 제한 시간 내에 모든 퍼즐을 풀기 위한 최소 숙련도 `level`을 구한다.

## 아이디어
- 숙련도 `level`이 높아질수록 전체 소요 시간은 줄어든다 (결정 문제).
- 따라서 이분 탐색(Binary Search)을 사용하여 조건을 만족하는 최소 `level`을 찾는다.
- 탐색 범위는 1부터 `max(diffs)`까지로 설정한다.

## 시간복잡도
- O(N * log(max_diff)), 여기서 N은 퍼즐의 개수이다.

## 풀이 과정
1. 이분 탐색의 범위를 `left = 1`, `right = max(diffs)`로 설정한다.
2. `mid` 값을 숙련도로 가정하고, 해당 숙련도로 모든 퍼즐을 풀었을 때의 총 시간을 계산하는 `check` 함수를 구현한다.
3. `check` 결과가 제한 시간 이하이면 `answer`를 업데이트하고 더 작은 `level`을 찾기 위해 `right = mid - 1`로 범위를 좁힌다.
4. 제한 시간을 초과하면 `left = mid + 1`로 범위를 좁힌다.

## 코드 설명
```python
def check(d,t,level,lim) :
    total_time = t[0]
    for i in range(1,len(d)) :
        if d[i] <= level :
            total_time += t[i]
        else :
            # 틀린 횟수 * (이전 시간 + 현재 시간) + 현재 시간
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
```
- 이분 탐색을 통해 최적의 숙련도를 효율적으로 찾아낸다.
- `check` 함수 내에서 문제에 주어진 수식에 맞춰 시간을 합산한다.
